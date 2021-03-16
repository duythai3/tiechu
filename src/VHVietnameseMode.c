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
#include "VHConfiguration.h"
#include "VHVietnameseMode.h"
#include "VHTelexEditor.h"
#include "VHPropertyList.h"
#include "VHCandidateTable.h"
#include "VHLogger.h"
#include "VHViethoaTable.h"
#include "VHHelper.h"
#include "VHPreedit.h"

static void check_modifiers(guint modifiers) {

    if(IBUS_SHIFT_MASK & modifiers) {
       vh_logger_log("IBUS_SHIFT_MASK");
    }
    if(IBUS_LOCK_MASK & modifiers) {
       vh_logger_log("IBUS_LOCK_MASK");

    }

    if(IBUS_CONTROL_MASK & modifiers) {
       vh_logger_log("IBUS_CONTROL_MASK");

    }

    if(IBUS_MOD1_MASK & modifiers) {
       vh_logger_log("IBUS_MOD1_MASK");

    }

    if(IBUS_MOD2_MASK & modifiers) {
       vh_logger_log("IBUS_MOD2_MASK");

    }

    if(IBUS_MOD3_MASK & modifiers) {
       vh_logger_log("IBUS_MOD3_MASK");

    }

    if(IBUS_MOD4_MASK & modifiers) {
       vh_logger_log("IBUS_MOD4_MASK");

    }

    if(IBUS_MOD5_MASK & modifiers) {
       vh_logger_log("IBUS_MOD5_MASK");

    }

    if(IBUS_BUTTON1_MASK & modifiers) {
       vh_logger_log("IBUS_BUTTON1_MASK");

    }

    if(IBUS_BUTTON2_MASK & modifiers) {
       vh_logger_log("IBUS_BUTTON2_MASK");

    }

    if(IBUS_BUTTON3_MASK & modifiers) {
       vh_logger_log("IBUS_BUTTON3_MASK");

    }

    if(IBUS_BUTTON4_MASK & modifiers) {
       vh_logger_log("IBUS_BUTTON4_MASK");

    }

    if(IBUS_BUTTON5_MASK & modifiers) {
       vh_logger_log("IBUS_BUTTON5_MASK");

    }


    if(IBUS_HANDLED_MASK & modifiers) {
       vh_logger_log("IBUS_HANDLED_MASK");

    }

    if(IBUS_FORWARD_MASK & modifiers) {
       vh_logger_log("IBUS_FORWARD_MASK");

    }

    if(IBUS_IGNORED_MASK & modifiers) {
       vh_logger_log("IBUS_IGNORED_MASK");

    }


    if(IBUS_SUPER_MASK & modifiers) {
       vh_logger_log("IBUS_SUPER_MASK");

    }

    if(IBUS_HYPER_MASK & modifiers) {
       vh_logger_log("IBUS_HYPER_MASK");

    }

    if(IBUS_META_MASK & modifiers) {
       vh_logger_log("IBUS_META_MASK");

    }


    if(IBUS_RELEASE_MASK & modifiers) {
       vh_logger_log("IBUS_RELEASE_MASK");

    }


    if(IBUS_MODIFIER_MASK & modifiers) {
       vh_logger_log("IBUS_MODIFIER_MASK");

    }
}

gboolean vh_vietnamese_mode_process_key_event(IBusViethoaEngine* viethoa, guint keyval, guint keycode, guint modifiers) {

    //check_modifiers(modifiers);
    vh_logger_log("key_event: keyval=%d, keycode=%d, modifiers=%d", keyval, keycode, modifiers);

    // don't process release key events
    if (vh_helper_is_event_released(modifiers)) {
        return FALSE;
    }

    // ctr key pressed
    if (vh_helper_is_control_pressed(modifiers) && keyval != IBUS_Left && keyval != IBUS_Right) {
        return FALSE;
    }

    // alt pressed
    if (vh_helper_is_alt_pressed(modifiers)) {
        return FALSE;
    }

    //
    if (vh_helper_is_escape_pressed(keyval)) {
        return vh_helper_process_escape(viethoa, keyval, keycode, modifiers);
    }

    // get length of current processing string (preedit string)
    guint len = vh_preedit_get_length();
    guint pos = vh_preedit_get_cursor_pos();

    //
    switch (keyval) {
    case IBUS_Left:
        //
        if(modifiers & IBUS_CONTROL_MASK){
            if (pos > 0) {
                vh_preedit_move_cursor_left();
                vh_helper_update_preedit(viethoa);
            }
            return TRUE;
        }

        //
        if (len > 0) {
            vh_helper_commit_preedit(viethoa);
        }
        return FALSE;
    case IBUS_Right:
        //
        if(modifiers & IBUS_CONTROL_MASK){
            if (pos < len) {
                vh_preedit_move_cursor_right();
                vh_helper_update_preedit(viethoa);
            }
            return TRUE;
        }

        //
        if (len > 0) {
            vh_helper_commit_preedit(viethoa);
        }
        return FALSE;
    case IBUS_BackSpace:
        //
        if (pos == 0 || len == 0) {
            return FALSE;
        }

        //
        vh_preedit_delete_before_cursor();
        len = vh_preedit_get_length();
        if (len == 0) {
            vh_helper_hide_preedit(viethoa);
        } else {
            vh_helper_update_preedit(viethoa);
        }
        return TRUE;
    case IBUS_Delete:
        if (len == 0 || pos == len) {
            return FALSE;
        }

        //
        vh_preedit_delete_after_cursor();
        len = vh_preedit_get_length();
        if (len == 0) {
            vh_helper_hide_preedit(viethoa);
        } else {
            vh_helper_update_preedit(viethoa);
        }
        return TRUE;
    }

    // process letter keys
    if (is_alpha(keyval)) {
        if(vh_telex_process(viethoa, keyval, keycode, modifiers)){
            vh_helper_update_preedit(viethoa);
        }else{
            vh_preedit_insert(keyval);
            vh_helper_update_preedit (viethoa);
        }
        return TRUE;
    }

    //
    if(is_kp_digit(keyval)){
        vh_preedit_insert(convert_kp_digit_to_digit(keyval));
        vh_helper_update_preedit (viethoa);
        return TRUE;
    }

    //
    if(is_digit(keyval)){
		vh_preedit_insert(keyval);
		vh_helper_update_preedit (viethoa);
		return TRUE;
	}

    //
    if (vh_helper_is_ignore_key(keyval)) {
        return FALSE;
    }

    //
    if (len > 0) {
        vh_helper_commit_preedit(viethoa);
    }
    return FALSE;
}
