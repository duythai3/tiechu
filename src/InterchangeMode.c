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

#include "InterchangeMode.h"
#include <glib/gprintf.h>
#include "Logger.h"

//
static gboolean _shift_pressed = FALSE;
static gint64 _begin_interchange_mode_time = 0;

void interchange_mode_turn_shift_pressed_on() {
    _shift_pressed = TRUE;
}

void interchange_mode_turn_shift_pressed_off() {
    _shift_pressed = FALSE;
}

gboolean interchange_mode_is_shift_pressed_on() {
    return _shift_pressed == TRUE;
}

void interchange_mode_save_begin_interchange_mode_time() {
    _begin_interchange_mode_time = g_get_real_time();
}

gboolean interchange_mode_is_in_interchange_mode() {
    if (!_shift_pressed) {
        return FALSE;
    }
    gint64 current_time = g_get_real_time();
    gint64 diff = current_time - _begin_interchange_mode_time;
    logger_log("diff: %d", diff);
    if (diff > __INTERCHANGE_MODE_PERIOD__ * 1000000) {
        return FALSE;
    }
    return TRUE;
}
