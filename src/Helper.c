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
#include "engine.h"
#include "Helper.h"
#include "Configuration.h"
#include "HanvietMode.h"
#include "TelexEditor.h"
#include "PropertyList.h"
#include "CandidateTable.h"
#include "Logger.h"
#include "HanvietTable.h"
#include "Preedit.h"
#include "ChineseTable.h"
#include "TeochewTable.h"


void helper_clear_preedit(IBusTiechuEngine* tiechu) {
    logger_log("Clear preedit...\n");
    preedit_clear();
	IBusText *text;
	text = ibus_text_new_from_string ("");
    ibus_engine_update_preedit_text_with_mode((IBusEngine *)tiechu, text, 0, FALSE, IBUS_ENGINE_PREEDIT_CLEAR);
    if (candidate_table_showing()) {
        candidate_table_hide(tiechu);
    }
}

void helper_hide_preedit(IBusTiechuEngine* tiechu) {
    // hide the preedit string on screen
    ibus_engine_hide_preedit_text ((IBusEngine*)tiechu);
    candidate_table_hide(tiechu);
}

void helper_commit_preedit(IBusTiechuEngine* tiechu) {
	// commit preedit
    gchar *utf8_preedit =preedit_get_utf8_string();
    IBusText *text;
    text = ibus_text_new_from_string (utf8_preedit);
    ibus_engine_commit_text ((IBusEngine *)tiechu, text);
    g_free(utf8_preedit);

    // hide the preedit string on screen
    ibus_engine_hide_preedit_text ((IBusEngine*)tiechu);

    // clear telex editor's preedit
    preedit_clear();

    //
    if (candidate_table_showing()) {
        candidate_table_hide(tiechu);
	}
}

void helper_update_preedit(IBusTiechuEngine* tiechu) {
	// commit preedit
    gchar *utf8_preedit =preedit_get_utf8_string();
    guint cursor_pos =preedit_get_cursor_pos();
    guint preedit_len =preedit_get_length();
    IBusText *text;
    text = ibus_text_new_from_string (utf8_preedit);
    text->attrs = ibus_attr_list_new ();
    ibus_attr_list_append (text->attrs, ibus_attr_underline_new (IBUS_ATTR_UNDERLINE_SINGLE, 0, preedit_len));
    ibus_engine_update_preedit_text((IBusEngine *)tiechu, text, cursor_pos, TRUE);
    g_free(utf8_preedit);

    //
    gint current_mode =configuration_get_current_mode();
    if(current_mode==__A_HANVIET_MODE_2__){
    	//
        if(!hanviet_table_find())
        	return;

        //
        if(candidate_table_showing()){
            candidate_table_update(tiechu, TRUE);
		} else {
			gboolean auto_show_candidate_table =configuration_get_auto_show_candidate_table();
			if(auto_show_candidate_table){
                candidate_table_show(tiechu);
			}
		}
    } else if (current_mode==__A_CHINESE_MODE_2__) {
        //
        if(!chinese_table_find())
            return;

        //
        if(candidate_table_showing()){
            candidate_table_update(tiechu, TRUE);
        } else {
            gboolean auto_show_candidate_table =configuration_get_auto_show_candidate_table();
            if(auto_show_candidate_table){
                candidate_table_show(tiechu);
            }
        }
    } else if (current_mode==__A_TEOCHEW_MODE_2__) {
        //
        if(!teochew_table_find())
            return;

        //
        if(candidate_table_showing()){
            candidate_table_update(tiechu, TRUE);
        } else {
            gboolean auto_show_candidate_table =configuration_get_auto_show_candidate_table();
            if(auto_show_candidate_table){
                candidate_table_show(tiechu);
            }
        }
    }

}

gboolean helper_commit_candidate_in_page(IBusTiechuEngine *tiechu, guint index) {
    if (!candidate_table_showing()) {
		return FALSE;
	}
    guint page_size =candidate_table_get_page_size();
    guint cursor_pos =candidate_table_get_cursor_pos();
	index = (cursor_pos / page_size) * page_size + index;

	//
    IBusText *candidate =candidate_table_get_candidate(index);
	if (!candidate) {
		return FALSE;
	}

	// increase frequency of selected word
    gint current_mode =configuration_get_current_mode(); //current mode
    if (current_mode==__A_HANVIET_MODE_2__) {
        hanviet_table_increase_frequency(candidate->text);
    } else if (current_mode==__A_TEOCHEW_MODE_2__) {
        teochew_table_increase_frequency(candidate->text);
    } else if (current_mode==__A_CHINESE_MODE_2__){
        chinese_table_increase_frequency(candidate->text);
    }

	//i
    ibus_engine_commit_text ((IBusEngine *)tiechu, candidate);

    //
    if (preedit_get_length()>0) {
        preedit_clear();
        ibus_engine_hide_preedit_text ((IBusEngine*)tiechu);
    }
    candidate_table_hide(tiechu);

    //
    logger_log("Candidate at index %d committed", index);

    //
    return TRUE;
}

gboolean helper_commit_current_candidate(IBusTiechuEngine *tiechu) {
    if (!candidate_table_showing()) {
        return FALSE;
    }
    guint cursor_pos =candidate_table_get_cursor_pos();

    //
    IBusText *candidate =candidate_table_get_candidate(cursor_pos);
    if (!candidate) {
        return FALSE;
    }

    // increase frequency of selected word
    hanviet_table_increase_frequency(candidate->text);

    //i
    ibus_engine_commit_text ((IBusEngine *)tiechu, candidate);

    //
    if (preedit_get_length()>0) {
        preedit_clear();
        ibus_engine_hide_preedit_text ((IBusEngine*)tiechu);
    }
    candidate_table_hide(tiechu);

    //
    logger_log("Current candidate committed", index);

    //
    return TRUE;
}

gboolean helper_process_escape(IBusTiechuEngine* tiechu, guint keyval, guint keycode, guint modifiers) {
    //a_logger_log("Change to English mode using Escape key");
    configuration_set_selected_mode(__A_ENGLISH_MODE_2__);
    property_list_update(tiechu);
    configuration_save();
    //
    helper_clear_preedit(tiechu);
    //
    ibus_engine_forward_key_event((IBusEngine*)tiechu, keyval, keycode, modifiers);
    ibus_engine_forward_key_event((IBusEngine*)tiechu, keyval, keycode, modifiers);
    return TRUE;
}

gboolean helper_is_control_pressed(guint modifiers) {
    return (modifiers & IBUS_CONTROL_MASK);
}

gboolean helper_is_event_released(guint modifiers) {
    return (modifiers & IBUS_RELEASE_MASK);
}

gboolean helper_is_alt_pressed(guint modifiers) {
    return (modifiers & IBUS_MOD1_MASK & IBUS_MOD2_MASK);
}

gboolean helper_is_escape_pressed(guint keycode) {
    return keycode==IBUS_Escape;
}

gboolean helper_is_ignore_key(guint keyval) {
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
