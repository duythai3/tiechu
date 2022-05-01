/*
 * ibus-viethoa - The Viethoa engine for IBus
 *
 * Copyright (c) 2020-2021 Duy Thai, ngocduy.thai@yahoo.com
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
#include <ibus.h>
#include "VHLogger.h"
#include "vhustring.h"
#include "VHPinyinEditor.h"
#include "VHVNLetters.h"
#include "VHPreedit.h"
#include "VHETelexTable.h"
#include "VHHelper.h"

#define TC_LETTER_e     0x0065

//
gboolean vh_teochew_editor_is_signal_letter(guint keyval){
    switch(keyval){
        case IBUS_e:
            return TRUE;
        default:
            return FALSE;
    }
}

static void correct_letter_case(gunichar* vn_clutter, gchar* telex_clutter, guint len)  {
    int i = 0;
    gunichar* tmp_str = g_utf8_to_ucs4(telex_clutter, -1, NULL, NULL, NULL);
    for(i = 0; i < len; i++){
        if(!g_unichar_islower(tmp_str[i])){
            vn_clutter[i] = g_unichar_toupper(vn_clutter[i]);
        }
    }
    g_free(tmp_str);
}


//
static gboolean is_teochew_vowel(gunichar ch){
    ch = g_unichar_tolower(ch);
    //vh_logger_log("ch=%x", (int)ch);
	switch(ch){
        case TC_LETTER_e:
            return TRUE;
        default:
            return FALSE;    
    }
}

/**
 * Find begin index of pinyin vowel phrase
 * scan the preedit buffer from the right to left to find a phrase of vowel that need to to translate to pinyin
 * */
static guint find_begin_index(){
	gint len = vh_preedit_get_length();
    gint index = 0;
    gint found_index = 0;
    gint status = 0;
    gunichar ch = 0;

    //
    if (len < 1) {
    	return found_index;
    }

    //
	for(index = len - 1; index >= 0; index--){
		ch = vh_preedit_get_char(index);
        if(is_teochew_vowel(ch)){
			if(status == 0){
				status = 1;
				found_index = index;
			}else if(status == 1){
				found_index = index;
			}
		}else{
			if(status == 1){
				break;
			}
		}
	}

	//
    return found_index;
}

static gchar* calc_ascii_clutter(gint keyval, glong* clutter_len, glong* start_pos){

	//
	gint preedit_len = vh_preedit_get_length();
	if (preedit_len < 1) {
		return NULL;
	}

	//

	guint status = 0; // 0 for not found, 1 for found
	gunichar buff[20];

	//
	gint index = 0;
	gint len = 0;
	gint max_index = 0;
	gint begin_find_index = 0;
	gint begin_char = 0;
	gint begin_index = find_begin_index();

	//
	for(index = begin_index; index < preedit_len; index++){
	   gunichar ch = vh_preedit_get_char(index);
       if (len > 18) {
            return NULL;
       }
       if(is_teochew_vowel(ch)){
			if(status == 0){
				status = 1;
				begin_find_index = index;
				buff[len] = ch;
				begin_char = ch;
				len++;
				max_index = index;
			}else if(status ==1){
				buff[len] = ch;
				len++;
				max_index = index;
			}
	   }else{
		   if(status == 1) break;
	   }
	}

	//
	if (len < 1) {
		return NULL;
	}
	//
	buff[len] = 0;

	//
	gunichar buff2[4];
    buff2[0] = buff[0];
	buff2[1] = keyval;
	buff2[2] = 0;
    *start_pos = begin_find_index;
	*clutter_len = 1;

	//
	gchar* p2 = g_ucs4_to_utf8(buff2, 2, NULL, NULL, NULL);
	return p2;
}

//

static gboolean process_teochew(guint keyval){

    glong clutter_len = 0;
    glong start_pos = 0;
    guint teochew_len = 0;
    gchar* ascii_clutter = NULL;

    //
    if (!vh_teochew_editor_is_signal_letter(keyval)) {
    	//vh_logger_log("not signal letter: %d", keyval);
    	return FALSE;
    }

    //vh_logger_log("signal letter: %d", keyval);

    //
	ascii_clutter =  calc_ascii_clutter(keyval, &clutter_len, &start_pos);
	vh_logger_log("ascii clutter: %s", ascii_clutter);
	if (!ascii_clutter) {
		return FALSE;
	}


	// convert pinyin clutter to lower case
	gchar *down_asscii_clutter = g_utf8_strdown(ascii_clutter, -1);

	//vh_logger_log("down ascii clutter: %s, len: %d", down_asscii_clutter, clutter_len);

	//
    const gchar *teochew_clutter = vh_etelex_table_convert_to_pinyin(down_asscii_clutter);
    vh_logger_log("teochew_clutter:%s", teochew_clutter);
	g_free(down_asscii_clutter);


	//
    if (!teochew_clutter) {
		g_free(ascii_clutter);
		return FALSE;
	}

	glong written = 0;
    gunichar *unichar_teochew_clutter = g_utf8_to_ucs4_fast(teochew_clutter, -1, &written);
    teochew_len = (guint)written;
	//

    correct_letter_case(unichar_teochew_clutter, ascii_clutter, clutter_len);
    vh_preedit_replace(start_pos, clutter_len, unichar_teochew_clutter, teochew_len);
	g_free(ascii_clutter);
    g_free(unichar_teochew_clutter);
	return TRUE;
}

/////////////////////////
gboolean vh_teochew_editor_process(IBusAbacusEngine* viethoa, guint keyval, guint keycode, guint modifiers){
    guint len = vh_preedit_get_text_len();
    //vh_logger_log("preedit len: %d", len);
    if(len > 0){
        return process_teochew(keyval);
    }else{
        return FALSE;
    }
}

gboolean vh_teochew_editor_is_preedit_containing_tone() {
    gint preedit_len = vh_preedit_get_length();
    if (preedit_len < 1) {
        return FALSE;
    }
    for (gint i = 0; i < preedit_len; i++) {
        guint c = (uint)vh_preedit_get_char(i);
        if (is_teochew_tone_digit(c)) {
            return TRUE;
        }
    }
    return FALSE;
}
