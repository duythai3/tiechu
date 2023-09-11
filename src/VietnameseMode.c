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
#include "Configuration.h"
#include "VietnameseMode.h"
#include "TelexEditor2.h"
#include "PropertyList.h"
#include "CandidateTable.h"
#include "Logger.h"
#include "HanvietTable.h"
#include "Helper.h"
#include "Preedit.h"

static void check_modifiers(guint modifiers) {

    if(IBUS_SHIFT_MASK & modifiers) {
        logger_log("IBUS_SHIFT_MASK");
    }
    if(IBUS_LOCK_MASK & modifiers) {
        logger_log("IBUS_LOCK_MASK");

    }

    if(IBUS_CONTROL_MASK & modifiers) {
        logger_log("IBUS_CONTROL_MASK");

    }

    if(IBUS_MOD1_MASK & modifiers) {
        logger_log("IBUS_MOD1_MASK");

    }

    if(IBUS_MOD2_MASK & modifiers) {
        logger_log("IBUS_MOD2_MASK");

    }

    if(IBUS_MOD3_MASK & modifiers) {
        logger_log("IBUS_MOD3_MASK");

    }

    if(IBUS_MOD4_MASK & modifiers) {
        logger_log("IBUS_MOD4_MASK");

    }

    if(IBUS_MOD5_MASK & modifiers) {
        logger_log("IBUS_MOD5_MASK");

    }

    if(IBUS_BUTTON1_MASK & modifiers) {
        logger_log("IBUS_BUTTON1_MASK");

    }

    if(IBUS_BUTTON2_MASK & modifiers) {
        logger_log("IBUS_BUTTON2_MASK");

    }

    if(IBUS_BUTTON3_MASK & modifiers) {
        logger_log("IBUS_BUTTON3_MASK");

    }

    if(IBUS_BUTTON4_MASK & modifiers) {
        logger_log("IBUS_BUTTON4_MASK");

    }

    if(IBUS_BUTTON5_MASK & modifiers) {
        logger_log("IBUS_BUTTON5_MASK");

    }


    if(IBUS_HANDLED_MASK & modifiers) {
        logger_log("IBUS_HANDLED_MASK");

    }

    if(IBUS_FORWARD_MASK & modifiers) {
        logger_log("IBUS_FORWARD_MASK");

    }

    if(IBUS_IGNORED_MASK & modifiers) {
        logger_log("IBUS_IGNORED_MASK");

    }


    if(IBUS_SUPER_MASK & modifiers) {
        logger_log("IBUS_SUPER_MASK");

    }

    if(IBUS_HYPER_MASK & modifiers) {
        logger_log("IBUS_HYPER_MASK");

    }

    if(IBUS_META_MASK & modifiers) {
        logger_log("IBUS_META_MASK");

    }


    if(IBUS_RELEASE_MASK & modifiers) {
        logger_log("IBUS_RELEASE_MASK");

    }


    if(IBUS_MODIFIER_MASK & modifiers) {
        logger_log("IBUS_MODIFIER_MASK");

    }
}

gboolean a_vietnamese_mode_process_key_event(IBusTiechuEngine* abacus, guint keyval, guint keycode, guint modifiers) {

    //check_modifiers(modifiers);
    logger_log("key_event: keyval=%d, keycode=%d, modifiers=%d", keyval, keycode, modifiers);

    // don't process release key events
    if (helper_is_event_released(modifiers)) {
        return FALSE;
    }

    // ctr key pressed
    if (helper_is_control_pressed(modifiers)&&keyval!=IBUS_Left&&keyval!=IBUS_Right) {
        return FALSE;
    }

    // alt pressed
    if (helper_is_alt_pressed(modifiers)) {
        return FALSE;
    }

    //
    if (helper_is_escape_pressed(keyval)) {
        return helper_process_escape(abacus, keyval, keycode, modifiers);
    }

    // get length of current processing string (preedit string)
    guint len =preedit_get_length();
    guint pos =preedit_get_cursor_pos();

    //
    switch (keyval) {
    case IBUS_Left:
        //
        if(modifiers & IBUS_CONTROL_MASK){
            if (pos > 0) {
                preedit_move_cursor_left();
                helper_update_preedit(abacus);
            }
            return TRUE;
        }

        //
        if (len > 0) {
            helper_commit_preedit(abacus);
        }
        return FALSE;
    case IBUS_Right:
        //
        if(modifiers & IBUS_CONTROL_MASK){
            if (pos < len) {
                preedit_move_cursor_right();
                helper_update_preedit(abacus);
            }
            return TRUE;
        }

        //
        if (len > 0) {
            helper_commit_preedit(abacus);
        }
        return FALSE;
    case IBUS_BackSpace:
        //
        if (pos == 0 || len == 0) {
            return FALSE;
        }

        //
            preedit_delete_before_cursor();
        len =preedit_get_length();
        if (len == 0) {
            helper_hide_preedit(abacus);
        } else {
            helper_update_preedit(abacus);
        }
        return TRUE;
    case IBUS_Delete:
        if (len == 0 || pos == len) {
            return FALSE;
        }

        //
            preedit_delete_after_cursor();
        len =preedit_get_length();
        if (len == 0) {
            helper_hide_preedit(abacus);
        } else {
            helper_update_preedit(abacus);
        }
        return TRUE;
    }

    // process letter keys
    if (is_alpha(keyval)) {
        if(telex_2_process(abacus, keyval, keycode, modifiers)){
            helper_update_preedit(abacus);
        }else{
            preedit_insert(keyval);
            helper_update_preedit(abacus);
        }
        return TRUE;
    }

    //
    if(is_kp_digit(keyval)){
        preedit_insert(convert_kp_digit_to_digit(keyval));
        helper_update_preedit(abacus);
        return TRUE;
    }

    //
    if(is_digit(keyval)){
        preedit_insert(keyval);
        helper_update_preedit(abacus);
		return TRUE;
	}

    //
    if (helper_is_ignore_key(keyval)) {
        ibus_engine_forward_key_event((IBusEngine*)abacus, keyval, keycode, modifiers);
        return TRUE;
    }

    //
    if (len > 0) {
        helper_commit_preedit(abacus);
    }
    ibus_engine_forward_key_event((IBusEngine*)abacus, keyval, keycode, modifiers);
    return TRUE;
}
