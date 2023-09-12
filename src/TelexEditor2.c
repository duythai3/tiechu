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
#include "TelexEditor2.h"
#include "VNLetters.h"
#include "Preedit.h"
#include "ZTelexTable2.h"

//
static gboolean is_signal_letter(guint keyval){
    switch(keyval){
        case IBUS_a:
        case IBUS_A:
        case IBUS_o:
        case IBUS_O:
        case IBUS_e:
        case IBUS_E:
        case IBUS_w:
        case IBUS_W:
        case IBUS_d:
        case IBUS_D:
        case IBUS_z:
        case IBUS_Z:
        case IBUS_f:
        case IBUS_F:
        case IBUS_r:
        case IBUS_R:
        case IBUS_x:
        case IBUS_X:
        case IBUS_j:
        case IBUS_J:
            return TRUE;
        default:
            return FALSE;
    }
}

static gboolean is_vowel_signal_letter(guint keyval){
    switch(keyval){
        case IBUS_a:
        case IBUS_A:
        case IBUS_o:
        case IBUS_O:
        case IBUS_e:
        case IBUS_E:
        case IBUS_w:
        case IBUS_W:
            return TRUE;
        default:
            return FALSE;
    }
}

static gboolean is_limit_signal_letter(guint keyval){
    switch(keyval){
        case IBUS_f:
        case IBUS_F:
        case IBUS_r:
        case IBUS_R:
        case IBUS_x:
        case IBUS_X:
            return TRUE;
        default:
            return FALSE;
    }
}

static gboolean is_limit_consonant(gunichar end_consonant){
    switch(end_consonant){
        case IBUS_t:
        case IBUS_T:
        case IBUS_c:
        case IBUS_C:
        case IBUS_p:
        case IBUS_P:
            return TRUE;
        default:
            return FALSE;
    }
}

static void correct_letter_case(gunichar* clutter_vn, gchar* telex_clutter, guint len)  {
    int i = 0;
    gunichar* tmp_str = g_utf8_to_ucs4(telex_clutter, -1, NULL, NULL, NULL);
    for(i = 0; i < len; i++){
        if(!g_unichar_islower(tmp_str[i])){
            clutter_vn[i] = g_unichar_toupper(clutter_vn[i]);
        }
    }
    g_free(tmp_str);
}



//
static gboolean is_vn_vowel(gunichar ch){
    ch = g_unichar_tolower(ch);
    switch(ch){
        case VN_LETTER_a:
        case VN_LETTER_e:
        case VN_LETTER_i:
        case VN_LETTER_o:
        case VN_LETTER_u:
        case VN_LETTER_y:

        case VN_LETTER_as:
        case VN_LETTER_es:
        case VN_LETTER_is:
        case VN_LETTER_os:
        case VN_LETTER_us:
        case VN_LETTER_ys:
        case VN_LETTER_aas:
        case VN_LETTER_aws:
        case VN_LETTER_ees:
        case VN_LETTER_oos:
        case VN_LETTER_ows:
        case VN_LETTER_uws:

    //*f
        case VN_LETTER_af:
        case VN_LETTER_ef:
        case VN_LETTER_if:
        case VN_LETTER_of:
        case VN_LETTER_uf:
        case VN_LETTER_yf:
        case VN_LETTER_aaf:
        case VN_LETTER_awf:
        case VN_LETTER_eef:
        case VN_LETTER_oof:
        case VN_LETTER_owf:
        case VN_LETTER_uwf:


    //*r
        case VN_LETTER_ar:
        case VN_LETTER_er:
        case VN_LETTER_ir:
        case VN_LETTER_or:
        case VN_LETTER_ur:
        case VN_LETTER_yr:
        case VN_LETTER_aar:
        case VN_LETTER_awr:
        case VN_LETTER_eer:
        case VN_LETTER_oor:
        case VN_LETTER_owr:
        case VN_LETTER_uwr:

    //*x
        case VN_LETTER_ax:
        case VN_LETTER_ex:
        case VN_LETTER_ix:
        case VN_LETTER_ox:
        case VN_LETTER_ux:
        case VN_LETTER_yx:
        case VN_LETTER_aax:
        case VN_LETTER_awx:
        case VN_LETTER_eex:
        case VN_LETTER_oox:
        case VN_LETTER_owx:
        case VN_LETTER_uwx:

    //*j
        case VN_LETTER_aj:
        case VN_LETTER_ej:
        case VN_LETTER_ij:
        case VN_LETTER_oj:
        case VN_LETTER_uj:
        case VN_LETTER_yj:
        case VN_LETTER_aaj:
        case VN_LETTER_awj:
        case VN_LETTER_eej:
        case VN_LETTER_ooj:
        case VN_LETTER_owj:
        case VN_LETTER_uwj:

    //
        case VN_LETTER_aa:
        case VN_LETTER_ee:
        case VN_LETTER_oo:
        case VN_LETTER_aw:
        case VN_LETTER_ow:
        case VN_LETTER_uw:
        //case A_VN_LETTER_dd:
            return TRUE;
        default:
            return FALSE;    
    }
}

static gboolean is_priority_vowel(gunichar ch){
    ch = g_unichar_tolower(ch);
    switch(ch){
        case VN_LETTER_ee:
        case VN_LETTER_ow:
        case VN_LETTER_ees:
        case VN_LETTER_ows:
        case VN_LETTER_eef:
        case VN_LETTER_owf:
        case VN_LETTER_eer:
        case VN_LETTER_owr:
        case VN_LETTER_eex:
        case VN_LETTER_owx:
        case VN_LETTER_eej:
        case VN_LETTER_owj:
            return TRUE;
        default:
            return FALSE;
    }
}

static guint find_begin_index(){
	gint len=preedit_get_length();
    gint index=0;
    gint found_index = -1;
    gint status = 0;
    gunichar ch = 0;

    //
    if (len < 1) {
    	return found_index;
    }

    //
	for(index = len - 1; index >= 0; index--){
		ch =preedit_get_char(index);
		if(is_vn_vowel(ch)){
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

static gchar* calc_telex_clutter(guint keyval, glong* start_pos){

	//
	gint len =preedit_get_length();
	if (len < 1) {
		return NULL;
	}

	//

	guint status = 0; // 0 for not found, 1 for found
	gunichar buff[20];

    //
	if(keyval == IBUS_d || keyval == IBUS_D){
		guint before_char =preedit_get_before_cursor_char();
		if(before_char == IBUS_d || before_char == IBUS_D){
			*start_pos =preedit_get_cursor_pos()-1;
			buff[0] = before_char;
			buff[1] = keyval;
			buff[2] = 0;
			return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
		}else{
			return NULL;
		}
    }
    //
    if (is_vowel_signal_letter(keyval)) {
        guint before_char =preedit_get_before_cursor_char();
        if (before_char == 0) {
            return NULL;
        }
        //
        *start_pos =preedit_get_cursor_pos()-1;
        buff[0] = before_char;
        buff[1] = keyval;
        buff[2] = 0;
        return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
    }

	//
	gint begin_index = find_begin_index();
	gint index = 0;
    gint clutter_len = 0;
	gint max_index = 0;
	gint begin_find_index = 0;
	gint left_char = 0;
    gint begin_char = 0;

    if (begin_index < 0) {
        return NULL;
    }

    if(begin_index > 0){
		left_char =preedit_get_char(begin_index-1);
	}

	//
	for(index = begin_index; index < len; index++){
       gunichar ch =preedit_get_char(index);
       if (clutter_len > 18) {
            return NULL;
       }
	   if(is_vn_vowel(ch)){
			if(status == 0){
				status = 1;
				begin_find_index = index;
                buff[clutter_len] = ch;
				begin_char = ch;
                clutter_len++;
				max_index = index;
            }else if(status == 1){
                buff[clutter_len] = ch;
                clutter_len++;
				max_index = index;
			}
	   }else{
		   if(status == 1) break;
	   }
	}

	//
    if (clutter_len < 1) {
		return NULL;
    }

    //
    gint end_consonant = 0;
    if((max_index + 1) < len){
        end_consonant =preedit_get_char(max_index+1);
    }

    //
    if (clutter_len == 1) {
        *start_pos = begin_find_index;
        buff[1] = keyval;
        buff[2] = 0;
        return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
    } else if (clutter_len == 2) {
        //
        if((left_char == IBUS_g || left_char == IBUS_G) && (begin_char == IBUS_i || begin_char == IBUS_I)){
            // case gi*
            *start_pos = begin_find_index + 1;
            buff[0] = buff[1];
            buff[1] = keyval;
            buff[2] = 0;
            return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
        } else if((left_char == IBUS_q || left_char == IBUS_Q) && (begin_char == IBUS_u || begin_char == IBUS_U)){
            // case gi*
            *start_pos = begin_find_index + 1;
            buff[0] = buff[1];
            buff[1] = keyval;
            buff[2] = 0;
            return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
        }

        //
        if (is_priority_vowel(buff[0])) {
            *start_pos = begin_find_index;
            buff[1] = keyval;
            buff[2] = 0;
            return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
        } else if (is_priority_vowel(buff[1])) {
            *start_pos = begin_find_index + 1;
            buff[0] = buff[1];
            buff[1] = keyval;
            buff[2] = 0;
            return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
        }

        //
        if (end_consonant > 0) {
            *start_pos = begin_find_index + 1;
            buff[0] = buff[1];
            buff[1] = keyval;
            buff[2] = 0;
            return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
        } else {
            *start_pos = begin_find_index;
            buff[1] = keyval;
            buff[2] = 0;
            return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
        }
    } else if (clutter_len == 3) {
        //
        if (is_priority_vowel(buff[0])) {
            *start_pos = begin_find_index;
            buff[1] = keyval;
            buff[2] = 0;
            return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
        } else if (is_priority_vowel(buff[1])) {
            *start_pos = begin_find_index + 1;
            buff[0] = buff[1];
            buff[1] = keyval;
            buff[2] = 0;
            return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
        } else if (is_priority_vowel(buff[2])) {
            *start_pos = begin_find_index + 2;
            buff[0] = buff[2];
            buff[1] = keyval;
            buff[2] = 0;
            return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
        } else {
            *start_pos = begin_find_index + 1;
            buff[0] = buff[1];
            buff[1] = keyval;
            buff[2] = 0;
            return g_ucs4_to_utf8(buff, 2, NULL, NULL, NULL);
        }
    } else {
        return NULL;
    }

}

//

static gboolean process_telex(guint keyval){

    glong start_pos = 0;
    guint vn_len = 0;
    gchar* telex_clutter = NULL;

    //
    if (!is_signal_letter(keyval)) {
    	return FALSE;
    }

    //
    telex_clutter =  calc_telex_clutter(keyval, &start_pos);
	if (!telex_clutter) {
		return FALSE;
	}

	// convert telex a_clutter to lower case
	gchar *down_telex_clutter = g_utf8_strdown(telex_clutter, -1);

	//
    gunichar *vn_clutter =z_telex_table_2_convert_to_vietnamese(down_telex_clutter, &vn_len);
	g_free(down_telex_clutter);

	//
	if (!vn_clutter) {
		g_free(telex_clutter);
		return FALSE;
	}

	//
    correct_letter_case(vn_clutter, telex_clutter, 1);
    preedit_replace(start_pos, 1, vn_clutter, vn_len);
	g_free(telex_clutter);
	g_free(vn_clutter);
	return TRUE;
}

/////////////////////////
gboolean telex_2_process(IBusTiechuEngine* tiechu, guint keyval, guint keycode, guint modifiers){
    guint len =preedit_get_text_len();

    if(len > 0){
        return process_telex(keyval);
    }else{
        return FALSE;
    }
}
