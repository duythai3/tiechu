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
#include <ibus.h>
#include "Logger.h"
#include "UString.h"
#include "PinyinEditor.h"
#include "VNLetters.h"
#include "Preedit.h"
#include "LTelexTable.h"

#define CN_LETTER_a     0x0061
#define CN_LETTER_a1    0x0101
#define CN_LETTER_a2    0x00e1
#define CN_LETTER_a3    0x01ce
#define CN_LETTER_a4    0x00e0

#define CN_LETTER_e     0x0065
#define CN_LETTER_e1    0x0113
#define CN_LETTER_e2    0x00e9
#define CN_LETTER_e3    0x011b
#define CN_LETTER_e4    0x00e8

#define CN_LETTER_i     0x0069
#define CN_LETTER_i1    0x012b
#define CN_LETTER_i2    0x00ed
#define CN_LETTER_i3    0x01d0
#define CN_LETTER_i4    0x00ec

#define CN_LETTER_o     0x006F
#define CN_LETTER_o1    0x014d
#define CN_LETTER_o2    0x00f3
#define CN_LETTER_o3    0x01d2
#define CN_LETTER_o4    0x00f2

#define CN_LETTER_u     0x0075
#define CN_LETTER_u1    0x016b
#define CN_LETTER_u2    0x00fa
#define CN_LETTER_u3    0x01d4
#define CN_LETTER_u4    0x00f9

#define CN_LETTER_v     0x00fc
#define CN_LETTER_v1    0x01d6
#define CN_LETTER_v2    0x01d8
#define CN_LETTER_v3    0x01da
#define CN_LETTER_v4    0x01dc

//
gboolean pinyin_editor_is_signal_letter(guint keyval){
    switch(keyval){
        case IBUS_l:
        case IBUS_z:
        case IBUS_x:
        case IBUS_f:
            return TRUE;
        default:
            return FALSE;
    }
}


static void correct_letter_case(gunichar* clutter_vn, gchar* clutter_telex, guint len)  {
    int i = 0;
    gunichar* tmp_str = g_utf8_to_ucs4(clutter_telex, -1, NULL, NULL, NULL);
    for(i = 0; i < len; i++){
        if(!g_unichar_islower(tmp_str[i])){
            clutter_vn[i] = g_unichar_toupper(clutter_vn[i]);
        }
    }
    g_free(tmp_str);
}


//
static gboolean is_cn_vowel(gunichar ch){
    ch = g_unichar_tolower(ch);
    //a_logger_log("ch=%x", (int)ch);
	switch(ch){
		case CN_LETTER_a:
		case CN_LETTER_a1:
		case CN_LETTER_a2:
		case CN_LETTER_a3:
		case CN_LETTER_a4:

		case CN_LETTER_e:
		case CN_LETTER_e1:
		case CN_LETTER_e2:
		case CN_LETTER_e3:
		case CN_LETTER_e4:

		case CN_LETTER_i:
		case CN_LETTER_i1:
		case CN_LETTER_i2:
		case CN_LETTER_i3:
		case CN_LETTER_i4:

		case CN_LETTER_o:
		case CN_LETTER_o1:
		case CN_LETTER_o2:
		case CN_LETTER_o3:
		case CN_LETTER_o4:

		case CN_LETTER_u:
		case CN_LETTER_u1:
		case CN_LETTER_u2:
		case CN_LETTER_u3:
		case CN_LETTER_u4:

		case CN_LETTER_v:
		case CN_LETTER_v1:
		case CN_LETTER_v2:
		case CN_LETTER_v3:
		case CN_LETTER_v4:
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
    gint len =preedit_get_length();
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
        ch =preedit_get_char(index);
		if(is_cn_vowel(ch)){
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


static gint get_open_degree(gunichar ch) {
	gint c = (gint)ch;
	//a_logger_log("char code=%x, e1: %x", c, CN_LETTER_e1);
	switch(c) {
	case CN_LETTER_a:
	case CN_LETTER_a1:
	case CN_LETTER_a2:
	case CN_LETTER_a3:
	case CN_LETTER_a4:
		return 1;
	case CN_LETTER_o:
	case CN_LETTER_o1:
	case CN_LETTER_o2:
	case CN_LETTER_o3:
	case CN_LETTER_o4:
		return 2;
	case CN_LETTER_e:
	case CN_LETTER_e1:
	case CN_LETTER_e2:
	case CN_LETTER_e3:
	case CN_LETTER_e4:
		return 3;
	case CN_LETTER_i:
	case CN_LETTER_i1:
	case CN_LETTER_i2:
	case CN_LETTER_i3:
	case CN_LETTER_i4:
		return 4;
	case CN_LETTER_u:
	case CN_LETTER_u1:
	case CN_LETTER_u2:
	case CN_LETTER_u3:
	case CN_LETTER_u4:
		return 5;
	case CN_LETTER_v:
	case CN_LETTER_v1:
	case CN_LETTER_v2:
	case CN_LETTER_v3:
	case CN_LETTER_v4:
		return 6;
	default:
		return 7;
	}
}

static gchar* calc_ascii_clutter(gint keyval, glong* clutter_len, glong* start_pos){

	//
    gint preedit_len =preedit_get_length();
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
       gunichar ch =preedit_get_char(index);
       if (len > 18) {
            return NULL;
       }
	   if(is_cn_vowel(ch)){
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
	/*
	gchar* p1 = g_ucs4_to_utf8(buff, len, NULL, NULL, NULL);
	a_logger_log("p1:%s", p1);
	g_free(p1);
	*/


	//
	gunichar buff2[4];
	gint min_open_degree = 100;
	gint target_index = 0;
	gint degree = 0;
	gunichar ch = 0;
	for(int i = 0; i < len; i++) {
		ch = buff[i];
		degree = get_open_degree(ch);
		//a_logger_log("char=%x, degree=%d", (int)ch, degree);
		if (degree < min_open_degree) {
			min_open_degree = degree;
			target_index = i;
		}
	}

	//
	buff2[0] = buff[target_index];
	buff2[1] = keyval;
	buff2[2] = 0;
	*start_pos = begin_find_index + target_index;
	*clutter_len = 1;

	//
	gchar* p2 = g_ucs4_to_utf8(buff2, 2, NULL, NULL, NULL);
	return p2;



}

//

static gboolean process_pinyin(guint keyval){

    glong clutter_len = 0;
    glong start_pos = 0;
    guint pinyin_len = 0;
    gchar* ascii_clutter = NULL;

    //
    if (!pinyin_editor_is_signal_letter(keyval)) {
    	//a_logger_log("not signal letter: %d", keyval);
    	return FALSE;
    }

    //a_logger_log("signal letter: %d", keyval);

    //
	ascii_clutter =  calc_ascii_clutter(keyval, &clutter_len, &start_pos);
    logger_log("ascii a_clutter: %s", ascii_clutter);
	if (!ascii_clutter) {
		return FALSE;
	}


	// convert pinyin a_clutter to lower case
	gchar *down_asscii_clutter = g_utf8_strdown(ascii_clutter, -1);

	//a_logger_log("down ascii a_clutter: %s, len: %d", down_asscii_clutter, clutter_len);

	//
	const gchar *pinyin_clutter =ltelex_table_convert_to_pinyin(down_asscii_clutter);
    logger_log("pinyin_clutter:%s", pinyin_clutter);
	g_free(down_asscii_clutter);


	//
	if (!pinyin_clutter) {
		g_free(ascii_clutter);
		return FALSE;
	}

	glong written = 0;
	gunichar *unichar_pinyin_clutter = g_utf8_to_ucs4_fast(pinyin_clutter, -1, &written);
	pinyin_len = (guint)written;
	//

	correct_letter_case(unichar_pinyin_clutter, ascii_clutter, clutter_len);
    preedit_replace(start_pos, clutter_len, unichar_pinyin_clutter, pinyin_len);
	g_free(ascii_clutter);
	g_free(unichar_pinyin_clutter);
	return TRUE;
}

/////////////////////////
gboolean pinyin_editor_process(IBusTiechuEngine* tiechu, guint keyval, guint keycode, guint modifiers){
    guint len =preedit_get_text_len();
    //a_logger_log("preedit len: %d", len);
    if(len > 0){
        return process_pinyin(keyval);
    }else{
        return FALSE;
    }
}
