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
#include "HanvietMode.h"
#include "TelexEditor2.h"
#include "PropertyList.h"
#include "CandidateTable.h"
#include "Logger.h"
#include "HanvietTable.h"
#include "Helper.h"
#include "Preedit.h"

gboolean hanviet_mode_process_key_event(IBusTiechuEngine* tiechu, guint keyval, guint keycode, guint modifiers) {

    // don't process release key events
    if (helper_is_event_released(modifiers)) {
        return FALSE;
    }

    // ctr key pressed
    if (helper_is_control_pressed(modifiers)&&(keyval!=IBUS_Left)&&(keyval!=IBUS_Right)) {
        return FALSE;
    }

    // alt pressed
    if (helper_is_alt_pressed(modifiers)) {
        return FALSE;
    }

    //
    if (helper_is_escape_pressed(keyval)) {
        //return helper_process_escape(tiechu, keyval, keycode, modifiers);
        return FALSE;
    }

    // get length of current processing string (preedit string)
    guint len =preedit_get_text_len();
    guint pos =preedit_get_cursor_pos();
    gboolean ctb_showing =candidate_table_showing();
    gboolean is_control_down = modifiers & IBUS_CONTROL_MASK;

    switch (keyval) {
    case IBUS_Left:
        //
        if (is_control_down) {
            if (pos > 0) {
                preedit_move_cursor_left();
                helper_update_preedit(tiechu);
            }
            return TRUE;
        }

        //
        if (ctb_showing){
            candidate_table_cursor_up(tiechu);
            return TRUE;
        }

        //
            helper_commit_preedit(tiechu);
        return FALSE;
    case IBUS_Right:
        //
        if(is_control_down){
            if (pos < len) {
                preedit_move_cursor_right();
                helper_update_preedit(tiechu);
            }
            return TRUE;
        }
        if (ctb_showing){
            candidate_table_cursor_down(tiechu);
            return TRUE;
        }
            helper_commit_preedit(tiechu);
        return FALSE;
    case IBUS_Return:
    case IBUS_KP_Enter:
        if (ctb_showing) {
            helper_commit_current_candidate(tiechu);
            return TRUE;
        }
            helper_commit_preedit(tiechu);
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
            helper_hide_preedit(tiechu);
        } else {
            helper_update_preedit(tiechu);
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
            helper_hide_preedit(tiechu);
        } else {
            helper_update_preedit(tiechu);
        }
        return TRUE;
    case IBUS_Page_Up:
    case IBUS_KP_Page_Up:
        if (ctb_showing) {
            candidate_table_page_up(tiechu);
            return TRUE;
        }
        return FALSE;
    case IBUS_Page_Down:
    case IBUS_KP_Page_Down:
        if (ctb_showing) {
            candidate_table_page_down(tiechu);
            return TRUE;
        }
        return FALSE;
    }

    // process letter keys
    if (is_alpha(keyval)) {
        if(telex_2_process(tiechu, keyval, keycode, modifiers)){
            helper_update_preedit(tiechu);
        }else{
            preedit_insert(keyval);
            helper_update_preedit(tiechu);
        }
        return TRUE;
    }

    //
    if (is_kp_digit(keyval)) {
        keyval = convert_kp_digit_to_digit(keyval);
    }

    //
    if(is_digit(keyval)){
        if (ctb_showing) {
            guint index = keyval - IBUS_1;
            helper_commit_candidate_in_page(tiechu, index);
        } else {
            preedit_insert(keyval);
            helper_update_preedit(tiechu);
        }
        return TRUE;
    }

    //
    if (helper_is_ignore_key(keyval)) {
        ibus_engine_forward_key_event((IBusEngine*)tiechu, keyval, keycode, modifiers);
        return TRUE;
    }

    //
    if(len > 0){
        helper_commit_preedit(tiechu);
    }
    ibus_engine_forward_key_event((IBusEngine*)tiechu, keyval, keycode, modifiers);
    return TRUE;
}
