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
#include "AConfiguration.h"
#include "VHTeochewMode.h"
#include "VHPropertyList.h"
#include "VHCandidateTable.h"
#include "ALogger.h"
#include "VHViethoaTable.h"
#include "VHTeochewEditor.h"
#include "VHPreedit.h"
#include "VHHelper.h"


gboolean vh_teochew_mode_process_key_event(IBusAbacusEngine* viethoa, guint keyval, guint keycode, guint modifiers) {

    // don't process release key events
    if (vh_helper_is_event_released(modifiers)) {
        return FALSE;
    }

    // ctr key pressed
    if (vh_helper_is_control_pressed(modifiers) && (keyval != IBUS_Left) && (keyval != IBUS_Right)) {
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
    guint len = vh_preedit_get_text_len();
    guint pos = vh_preedit_get_cursor_pos();
    gboolean ctb_showing = vh_candidate_table_showing();
    gboolean is_control_down = modifiers & IBUS_CONTROL_MASK;

    switch (keyval) {
    case IBUS_Left:
        //
        if (is_control_down) {
            if (pos > 0) {
                vh_preedit_move_cursor_left();
                vh_helper_update_preedit(viethoa);
            }
            return TRUE;
        }

        //
        if (ctb_showing){
            vh_candidate_table_cursor_up(viethoa);
            return TRUE;
        }

        //
        vh_helper_commit_preedit(viethoa);
        return FALSE;
    case IBUS_Right:
        //
        if(is_control_down){
            if (pos < len) {
                vh_preedit_move_cursor_right();
                vh_helper_update_preedit(viethoa);
            }
            return TRUE;
        }
        if (ctb_showing){
            vh_candidate_table_cursor_down(viethoa);
            return TRUE;
        }
        vh_helper_commit_preedit(viethoa);
        return FALSE;
    case IBUS_Return:
    case IBUS_KP_Enter:
        if (ctb_showing) {
            vh_helper_commit_current_candidate(viethoa);
            return TRUE;
        }
        vh_helper_commit_preedit(viethoa);
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
    case IBUS_Page_Up:
    case IBUS_KP_Page_Up:
        if (ctb_showing) {
            vh_candidate_table_page_up(viethoa);
            return TRUE;
        }
        return FALSE;
    case IBUS_Page_Down:
    case IBUS_KP_Page_Down:
        if (ctb_showing) {
            vh_candidate_table_page_down(viethoa);
            return TRUE;
        }
        return FALSE;
    case IBUS_colon:
        if (ctb_showing) {
            vh_candidate_table_set_command_text(viethoa, ":");
            return TRUE;
        }
    }

    // e
    if (vh_teochew_editor_is_signal_letter(keyval)) {
        if(vh_teochew_editor_process(viethoa, keyval, keycode, modifiers)){
            vh_helper_update_preedit(viethoa);
        }else{
            vh_preedit_insert(keyval);
            vh_helper_update_preedit(viethoa);
        }
        return TRUE;
    }

    //
    if (is_alpha(keyval)) {
        vh_preedit_insert(keyval);
        vh_helper_update_preedit(viethoa);
        return TRUE;
    }

    //
    if (is_kp_digit(keyval)) {
        keyval = convert_kp_digit_to_digit(keyval);
    }

    //
    if (vh_candidate_table_is_command_mode()) {
        if (is_teochew_tone_digit(keyval)) {
            guint index = keyval - IBUS_1;
            vh_helper_commit_candidate_in_page(viethoa, index);
            return TRUE;
        }
    }

    //
    if (is_teochew_tone_digit(keyval)) {
        if (vh_teochew_editor_is_preedit_containing_tone()) {
            guint index = keyval - IBUS_1;
            vh_helper_commit_candidate_in_page(viethoa, index);
        } else {
            vh_preedit_insert(keyval);
            vh_helper_update_preedit(viethoa);
        }
        return TRUE;
    }

    //
    if (vh_helper_is_ignore_key(keyval)) {
        ibus_engine_forward_key_event((IBusEngine*)viethoa, keyval, keycode, modifiers);
        return TRUE;
    }

    //
    if(len > 0){
        vh_helper_commit_preedit(viethoa);
    }
    ibus_engine_forward_key_event((IBusEngine*)viethoa, keyval, keycode, modifiers);
    return TRUE;
}
