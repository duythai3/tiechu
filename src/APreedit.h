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

#ifndef __A_PREEDIT_H__
#define __A_PREEDIT_H__

#include "AUString.h"

void a_preedit_init();
void a_preedit_destroy();
void a_preedit_clear();
void a_preedit_insert(guint keyval);
gboolean a_preedit_move_cursor_left();
gboolean a_preedit_move_cursor_right();
void a_preedit_move_cursor_begin();
void a_preedit_move_cursor_end();
void a_preedit_delete_before_cursor();
void a_preedit_delete_after_cursor();
guint a_preedit_get_cursor_pos();
guint a_preedit_set_cursor_pos(guint cursor_pos);
guint a_preedit_get_before_cursor_char();
guint a_preedit_set_before_cursor_char(guint keyval);
void a_preedit_replace(guint index, guint len, gunichar* replace_str, guint replace_len);

// get length of current preedit string
guint a_preedit_get_length();
guint a_preedit_get_text_len();

// get current preedit string as unicode string
const gunichar *a_preedit_get_preedit_string();
gchar *a_preedit_get_utf8_string();

void a_preedit_log();
gunichar a_preedit_get_char(gint index);

#endif
