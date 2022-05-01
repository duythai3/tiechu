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
#include "engine.h"
#include "VHHelper.h"
#include "AConfiguration.h"
#include "VHViethoaMode.h"
#include "VHTelexEditor.h"
#include "VHPropertyList.h"
#include "VHCandidateTable.h"
#include "ALogger.h"
#include "VHViethoaTable.h"
#include "VHPreedit.h"
#include "VHChineseTable.h"
#include "VHTeochewTable.h"


void vh_helper_clear_preedit(IBusAbacusEngine* viethoa) {
    a_logger_log("Clear preedit...\n");
	vh_preedit_clear();
	IBusText *text;
	text = ibus_text_new_from_string ("");
	ibus_engine_update_preedit_text_with_mode((IBusEngine *)viethoa, text, 0, FALSE, IBUS_ENGINE_PREEDIT_CLEAR);
    if (vh_candidate_table_showing()) {
        vh_candidate_table_hide(viethoa);
    }
}

void vh_helper_hide_preedit(IBusAbacusEngine* viethoa) {
    // hide the preedit string on screen
    ibus_engine_hide_preedit_text ((IBusEngine*)viethoa);
    vh_candidate_table_hide(viethoa);
}

void vh_helper_commit_preedit(IBusAbacusEngine* viethoa) {
	// commit preedit
    gchar *utf8_preedit = vh_preedit_get_utf8_string();
    IBusText *text;
    text = ibus_text_new_from_string (utf8_preedit);
    ibus_engine_commit_text ((IBusEngine *)viethoa, text);
    g_free(utf8_preedit);

    // hide the preedit string on screen
    ibus_engine_hide_preedit_text ((IBusEngine*)viethoa);

    // clear telex editor's preedit
    vh_preedit_clear();

    //
    if (vh_candidate_table_showing()) {
        vh_candidate_table_hide(viethoa);
	}
}

void vh_helper_update_preedit(IBusAbacusEngine* viethoa) {
	// commit preedit
    gchar *utf8_preedit = vh_preedit_get_utf8_string();
    guint cursor_pos = vh_preedit_get_cursor_pos();
    guint preedit_len = vh_preedit_get_length();
    IBusText *text;
    text = ibus_text_new_from_string (utf8_preedit);
    text->attrs = ibus_attr_list_new ();
    ibus_attr_list_append (text->attrs, ibus_attr_underline_new (IBUS_ATTR_UNDERLINE_SINGLE, 0, preedit_len));
    ibus_engine_update_preedit_text((IBusEngine *)viethoa, text, cursor_pos, TRUE);
    g_free(utf8_preedit);

    //
    gint current_mode =a_configuration_get_current_mode();
    if(current_mode==__A_HANVIET_MODE_2__){
    	//
        if(!vh_viethoa_table_find())
        	return;

        //
        if(vh_candidate_table_showing()){
            vh_candidate_table_update(viethoa, TRUE);
		} else {
			gboolean auto_show_candidate_table =a_configuration_get_auto_show_candidate_table();
			if(auto_show_candidate_table){
                vh_candidate_table_show(viethoa);
			}
		}
    } else if (current_mode==__A_CHINESE_MODE_2__) {
        //
        if(!vh_chinese_table_find())
            return;

        //
        if(vh_candidate_table_showing()){
            vh_candidate_table_update(viethoa, TRUE);
        } else {
            gboolean auto_show_candidate_table =a_configuration_get_auto_show_candidate_table();
            if(auto_show_candidate_table){
                vh_candidate_table_show(viethoa);
            }
        }
    } else if (current_mode==__A_TEOCHEW_MODE_2__) {
        //
        if(!vh_teochew_table_find())
            return;

        //
        if(vh_candidate_table_showing()){
            vh_candidate_table_update(viethoa, TRUE);
        } else {
            gboolean auto_show_candidate_table =a_configuration_get_auto_show_candidate_table();
            if(auto_show_candidate_table){
                vh_candidate_table_show(viethoa);
            }
        }
    }

}

gboolean vh_helper_commit_candidate_in_page(IBusAbacusEngine *viethoa, guint index) {
    if (!vh_candidate_table_showing()) {
		return FALSE;
	}
    guint page_size = vh_candidate_table_get_page_size();
    guint cursor_pos = vh_candidate_table_get_cursor_pos();
	index = (cursor_pos / page_size) * page_size + index;

	//
    IBusText *candidate = vh_candidate_table_get_candidate(index);
	if (!candidate) {
		return FALSE;
	}

	// increase frequency of selected word
    gint current_mode =a_configuration_get_current_mode(); //current mode
    if (current_mode==__A_HANVIET_MODE_2__) {
        vh_viethoa_table_increase_frequency(candidate->text);
    } else if (current_mode==__A_TEOCHEW_MODE_2__) {
        vh_teochew_table_increase_frequency(candidate->text);
    } else if (current_mode==__A_CHINESE_MODE_2__){
        vh_chinese_table_increase_frequency(candidate->text);
    }

	//i
    ibus_engine_commit_text ((IBusEngine *)viethoa, candidate);

    //
    if (vh_preedit_get_length() > 0) {
    	vh_preedit_clear();
    	ibus_engine_hide_preedit_text ((IBusEngine*)viethoa);
    }
    vh_candidate_table_hide(viethoa);

    //
    a_logger_log("Candidate at index %d committed", index);

    //
    return TRUE;
}

gboolean vh_helper_commit_current_candidate(IBusAbacusEngine *viethoa) {
    if (!vh_candidate_table_showing()) {
        return FALSE;
    }
    guint cursor_pos = vh_candidate_table_get_cursor_pos();

    //
    IBusText *candidate = vh_candidate_table_get_candidate(cursor_pos);
    if (!candidate) {
        return FALSE;
    }

    // increase frequency of selected word
    vh_viethoa_table_increase_frequency(candidate->text);

    //i
    ibus_engine_commit_text ((IBusEngine *)viethoa, candidate);

    //
    if (vh_preedit_get_length() > 0) {
        vh_preedit_clear();
        ibus_engine_hide_preedit_text ((IBusEngine*)viethoa);
    }
    vh_candidate_table_hide(viethoa);

    //
    a_logger_log("Current candidate committed", index);

    //
    return TRUE;
}

gboolean vh_helper_process_escape(IBusAbacusEngine* viethoa, guint keyval, guint keycode, guint modifiers) {
    //a_logger_log("Change to English mode using Escape key");
    a_configuration_set_selected_mode(__A_ENGLISH_MODE_2__);
    vh_property_list_update(viethoa);
    a_configuration_save();
    //
    vh_helper_clear_preedit(viethoa);
    //
    ibus_engine_forward_key_event((IBusEngine*)viethoa, keyval, keycode, modifiers);
    ibus_engine_forward_key_event((IBusEngine*)viethoa, keyval, keycode, modifiers);
    return TRUE;
}

gboolean vh_helper_is_control_pressed(guint modifiers) {
    return (modifiers & IBUS_CONTROL_MASK);
}

gboolean vh_helper_is_event_released(guint modifiers) {
    return (modifiers & IBUS_RELEASE_MASK);
}

gboolean vh_helper_is_alt_pressed(guint modifiers) {
    return (modifiers & IBUS_MOD1_MASK & IBUS_MOD2_MASK);
}

gboolean vh_helper_is_escape_pressed(guint keyval) {
    return keyval == IBUS_Escape;
}

gboolean vh_helper_is_ignore_key(guint keyval) {
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
