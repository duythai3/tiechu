/*
 * The Tiechu engine for IBus
 *
 * Copyright (c) 2020-2022 Duy Thai,duythaia3@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#include <glib.h>
#include <glib/gprintf.h>
#include <sqlite3.h>
#include "HanvietTable.h"

#include "CandidateArray.h"
#include "Logger.h"
#include "TelexEditor.h"
#include "Database.h"
#include "Preedit.h"

struct _EXPAND_CHAR{
	gchar *ch;
	gchar *chs;
};

static struct _EXPAND_CHAR _expand_chars[] = {
	{"e", "eéèẻẽẹêếềểễệ"},
	{"ê", "êếềểễệ"},
	
	{"u","uúùủũụưứừửự"},
	{"ư","ưứừửự"},

	{"a", "aáàảãạăắằẳẵặâấầẩẫậ"},
	{"ă", "ăắằẳẵặ"},
	{"â", "âấầẩẫậ"},

	{"i", "iíìỉĩị"},
	{"y", "yýỳỷỹỵ"},
	
	{"o", "oóòỏõọơớờởỡợôốồổỗộ"},
	{"ơ", "ơớờởỡợ"},
	{"ô", "ôốồổỗộ"},
	{"d","dđ"},

};

static int _add_word(void *NotUsed, int argc, char **argv, char **azColName);
static int _increase_frequency(void *NotUsed, int argc, char **argv, char **azColName);

static gchar _buff[1022];
static GHashTable* _char_expand_table = NULL;

static void _char_expand_table_init(){
	//
	if (_char_expand_table) {
		return;
	}
	
	//
    int i = 0;
	_char_expand_table = g_hash_table_new(g_str_hash, g_str_equal);
	for(i = 0; i < sizeof(_expand_chars)/sizeof(_expand_chars[0]); i++){
		g_hash_table_insert(_char_expand_table, _expand_chars[i].ch, _expand_chars[i].chs);
	}
}

static void _char_expand_table_destroy(){
	//
	if (!_char_expand_table) {
		return;
	}
	//
	g_hash_table_remove_all(_char_expand_table);
	g_hash_table_destroy(_char_expand_table);
	_char_expand_table = NULL;
}

static gunichar *_char_expand_table_expand(gunichar ch, guint* expand_char_len){
	//
	if (!_char_expand_table) {
		return NULL;
	}
	
	//
	gchar buff[22];
	gint len = g_unichar_to_utf8(ch, buff); 
	buff[len] = 0;
	glong written = 0;
	const gchar* expand_chars = (gchar*)g_hash_table_lookup(_char_expand_table, buff);
	if (!expand_chars) {
		return NULL;
	}
	
	//
	gunichar *unicode_expand_chars = g_utf8_to_ucs4_fast(expand_chars, -1, &written);
	if (!unicode_expand_chars) {
		return NULL;
	}

	//
	if(expand_char_len){
		*expand_char_len = written;
	}
	return unicode_expand_chars;
}

// initialize
gboolean hanviet_table_init(){
	//
	_char_expand_table_init();
    logger_log("hanviet table opened");
	return TRUE;
}

// destroy
void hanviet_table_destroy(){
	//
	_char_expand_table_destroy();
    logger_log("hanviet table destroyed");
}

gboolean hanviet_table_find(){
	//
	sqlite3* cnn =database_get_connection();
	if (!cnn) {
		return FALSE;
	}

	//
    guint preedit_len =preedit_get_length();
	if (preedit_len < 1) {
		// clear candidate list
        candidate_array_clear();
		return FALSE;
	}

	// build SQL command
   guint index = 0;
   guint len = 0;
   guint target_word_len;
   const gunichar *preedit_str =preedit_get_preedit_string();
   if(preedit_len <= 7)
	  target_word_len = preedit_len;
   else
	  target_word_len = 7;
   len = g_sprintf(_buff, "select distinct _char, _frequency from %s where", "hanviet");
   index = len;

   //
   gunichar ch = 0;
   gint ch_expand_len = 0;
   gunichar *expand_chars = NULL;
   for(gint i = 0; i < target_word_len; i++){
	   ch = g_unichar_tolower(preedit_str[i]);
	   ch_expand_len = 0;
	   expand_chars = _char_expand_table_expand(ch, &ch_expand_len);

	   //
	   if(!expand_chars){
		   if(i == 0){
                len = g_sprintf(_buff + index, " _v_%d=%d", i+1, ch);
				index = index + len;
		   }else{
                len = g_sprintf(_buff + index, " and _v_%d=%d", i+1, ch);
				index = index + len;
		   }
		   continue;
	   }

	   //
	   for(gint j = 0; j < ch_expand_len; j++){
		   if(j == 0){
			   if(i == 0){
                    len = g_sprintf(_buff + index, " (_v_%d=%d", i+1, expand_chars[j]);
					index = index + len;
			   }else{
                    len = g_sprintf(_buff + index, " and (_v_%d=%d", i+1, expand_chars[j]);
					index = index + len;
			   }
		   }else{
			   if(j == ch_expand_len - 1){
                    len = g_sprintf(_buff + index, " or _v_%d=%d) ", i+1, expand_chars[j]);
					index = index + len;
			   }else{
                    len = g_sprintf(_buff + index, " or _v_%d=%d", i+1, expand_chars[j]);
					index = index + len;
			   }
		   }
		}
		g_free(expand_chars);
   }
   //
   len = g_sprintf(_buff + index, " order by _frequency desc limit 72");
   index = index + len;
   _buff[index] = 0;
    logger_log(_buff);

   // clear candidate list
    candidate_array_clear();
	//
	gchar *errmsg = NULL;
	gint ret = sqlite3_exec(cnn, _buff, _add_word, 0, &errmsg);
	if (ret != SQLITE_OK) {
		if (errmsg) {
            logger_error("SQLite error: %s", errmsg);
			sqlite3_free(errmsg);
		}
		return FALSE;
	}

	//
	if (errmsg) {
		sqlite3_free(errmsg);
	}
	return TRUE;
}

static int _add_word(void *NotUsed, int argc, char **argv, char **azColName){
	//
	if (argc < 1) {
		return 0;
	}

	//
	gchar *chinese_char = argv[0];
	if(chinese_char){
        candidate_array_add(g_strdup(chinese_char));
    }
    return 0;
}


// increase frequency
void hanviet_table_increase_frequency(const gchar *chinese_char){
	//

	sqlite3* cnn =database_get_connection();
	if (!cnn || !chinese_char) {
		return;
	}

	//
    gint len = g_sprintf(_buff, "update hanviet set _frequency=_frequency+1 where _char='%s'", chinese_char);
	_buff[len] = 0;
    logger_log(_buff);
	gchar *errmsg = NULL;
	gint ret = sqlite3_exec(cnn, _buff, _increase_frequency, 0, &errmsg);
	if(ret != SQLITE_OK){
        logger_error("SQLite error: %s", errmsg);
		sqlite3_free(errmsg);
	}
}

static int _increase_frequency(void *NotUsed, int argc, char **argv, char **azColName){
	return 0;
}

