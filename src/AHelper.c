/*
 * The Abacus engine for IBus
 *
 * Copyright (c) 2020-2022 Duy Thai,duythaiz234@gmail.com
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
#include "engine.h"
#include "AHelper.h"
#include "AConfiguration.h"
#include "AHanvietMode.h"
#include "ATelexEditor.h"
#include "APropertyList.h"
#include "ACandidateTable.h"
#include "ALogger.h"
#include "AHanvietTable.h"
#include "APreedit.h"
#include "AChineseTable.h"
#include "ATeochewTable.h"


void a_helper_clear_preedit(IBusAbacusEngine* abacus) {
    a_logger_log("Clear preedit...\n");
    a_preedit_clear();
	IBusText *text;
	text = ibus_text_new_from_string ("");
	ibus_engine_update_preedit_text_with_mode((IBusEngine *)abacus, text, 0, FALSE, IBUS_ENGINE_PREEDIT_CLEAR);
    if (a_candidate_table_showing()) {
        a_candidate_table_hide(abacus);
    }
}

void a_helper_hide_preedit(IBusAbacusEngine* abacus) {
    // hide the preedit string on screen
    ibus_engine_hide_preedit_text ((IBusEngine*)abacus);
    a_candidate_table_hide(abacus);
}

void a_helper_commit_preedit(IBusAbacusEngine* abacus) {
	// commit preedit
    gchar *utf8_preedit =a_preedit_get_utf8_string();
    IBusText *text;
    text = ibus_text_new_from_string (utf8_preedit);
    ibus_engine_commit_text ((IBusEngine *)abacus, text);
    g_free(utf8_preedit);

    // hide the preedit string on screen
    ibus_engine_hide_preedit_text ((IBusEngine*)abacus);

    // clear telex editor's preedit
    a_preedit_clear();

    //
    if (a_candidate_table_showing()) {
        a_candidate_table_hide(abacus);
	}
}

void a_helper_update_preedit(IBusAbacusEngine* abacus) {
	// commit preedit
    gchar *utf8_preedit =a_preedit_get_utf8_string();
    guint cursor_pos =a_preedit_get_cursor_pos();
    guint preedit_len =a_preedit_get_length();
    IBusText *text;
    text = ibus_text_new_from_string (utf8_preedit);
    text->attrs = ibus_attr_list_new ();
    ibus_attr_list_append (text->attrs, ibus_attr_underline_new (IBUS_ATTR_UNDERLINE_SINGLE, 0, preedit_len));
    ibus_engine_update_preedit_text((IBusEngine *)abacus, text, cursor_pos, TRUE);
    g_free(utf8_preedit);

    //
    gint current_mode =a_configuration_get_current_mode();
    if(current_mode==__A_HANVIET_MODE_2__){
    	//
        if(!a_hanviet_table_find())
        	return;

        //
        if(a_candidate_table_showing()){
            a_candidate_table_update(abacus, TRUE);
		} else {
			gboolean auto_show_candidate_table =a_configuration_get_auto_show_candidate_table();
			if(auto_show_candidate_table){
                a_candidate_table_show(abacus);
			}
		}
    } else if (current_mode==__A_CHINESE_MODE_2__) {
        //
        if(!a_chinese_table_find())
            return;

        //
        if(a_candidate_table_showing()){
            a_candidate_table_update(abacus, TRUE);
        } else {
            gboolean auto_show_candidate_table =a_configuration_get_auto_show_candidate_table();
            if(auto_show_candidate_table){
                a_candidate_table_show(abacus);
            }
        }
    } else if (current_mode==__A_TEOCHEW_MODE_2__) {
        //
        if(!a_teochew_table_find())
            return;

        //
        if(a_candidate_table_showing()){
            a_candidate_table_update(abacus, TRUE);
        } else {
            gboolean auto_show_candidate_table =a_configuration_get_auto_show_candidate_table();
            if(auto_show_candidate_table){
                a_candidate_table_show(abacus);
            }
        }
    }

}

gboolean a_helper_commit_candidate_in_page(IBusAbacusEngine *abacus, guint index) {
    if (!a_candidate_table_showing()) {
		return FALSE;
	}
    guint page_size =a_candidate_table_get_page_size();
    guint cursor_pos =a_candidate_table_get_cursor_pos();
	index = (cursor_pos / page_size) * page_size + index;

	//
    IBusText *candidate =a_candidate_table_get_candidate(index);
	if (!candidate) {
		return FALSE;
	}

	// increase frequency of selected word
    gint current_mode =a_configuration_get_current_mode(); //current mode
    if (current_mode==__A_HANVIET_MODE_2__) {
        a_hanviet_table_increase_frequency(candidate->text);
    } else if (current_mode==__A_TEOCHEW_MODE_2__) {
        a_teochew_table_increase_frequency(candidate->text);
    } else if (current_mode==__A_CHINESE_MODE_2__){
        a_chinese_table_increase_frequency(candidate->text);
    }

	//i
    ibus_engine_commit_text ((IBusEngine *)abacus, candidate);

    //
    if (a_preedit_get_length()>0) {
        a_preedit_clear();
    	ibus_engine_hide_preedit_text ((IBusEngine*)abacus);
    }
    a_candidate_table_hide(abacus);

    //
    a_logger_log("Candidate at index %d committed", index);

    //
    return TRUE;
}

gboolean a_helper_commit_current_candidate(IBusAbacusEngine *abacus) {
    if (!a_candidate_table_showing()) {
        return FALSE;
    }
    guint cursor_pos =a_candidate_table_get_cursor_pos();

    //
    IBusText *candidate =a_candidate_table_get_candidate(cursor_pos);
    if (!candidate) {
        return FALSE;
    }

    // increase frequency of selected word
    a_hanviet_table_increase_frequency(candidate->text);

    //i
    ibus_engine_commit_text ((IBusEngine *)abacus, candidate);

    //
    if (a_preedit_get_length()>0) {
        a_preedit_clear();
        ibus_engine_hide_preedit_text ((IBusEngine*)abacus);
    }
    a_candidate_table_hide(abacus);

    //
    a_logger_log("Current candidate committed", index);

    //
    return TRUE;
}

gboolean a_helper_process_escape(IBusAbacusEngine* abacus, guint keyval, guint keycode, guint modifiers) {
    //a_logger_log("Change to English mode using Escape key");
    a_configuration_set_selected_mode(__A_ENGLISH_MODE_2__);
    a_property_list_update(abacus);
    a_configuration_save();
    //
    a_helper_clear_preedit(abacus);
    //
    ibus_engine_forward_key_event((IBusEngine*)abacus, keyval, keycode, modifiers);
    ibus_engine_forward_key_event((IBusEngine*)abacus, keyval, keycode, modifiers);
    return TRUE;
}

gboolean a_helper_is_control_pressed(guint modifiers) {
    return (modifiers & IBUS_CONTROL_MASK);
}

gboolean a_helper_is_event_released(guint modifiers) {
    return (modifiers & IBUS_RELEASE_MASK);
}

gboolean a_helper_is_alt_pressed(guint modifiers) {
    return (modifiers & IBUS_MOD1_MASK & IBUS_MOD2_MASK);
}

gboolean a_helper_is_escape_pressed(guint keycode) {
    return keycode==IBUS_Escape;
}

gboolean a_helper_is_ignore_key(guint keyval) {
    switch(keyval) {
    case IBUS_Control_L:
    case IBUS_Control_R:
    case IBUS_Shift_L:
    case IBUS_Shift_R:
    case IBUS_Alt_L:
    case IBUS_Alt_R:
    case IBUS_Caps_Lock:
    case IBUS_Shift_Lock:
    case IBUS_Meta_L:
    case IBUS_Meta_R:
    case IBUS_Super_L:
    case IBUS_Super_R:
    case IBUS_Hyper_L:
    case IBUS_Hyper_R:
    case IBUS_Num_Lock:
    case IBUS_F1:
    case IBUS_F2:
    case IBUS_F3:
    case IBUS_F4:
        return TRUE;
    default:
        return FALSE;
    }
}
