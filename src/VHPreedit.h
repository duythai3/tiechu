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
#ifndef __VH_PREEDIT_H__
#define __VH_PREEDIT_H__

#include "vhustring.h"

void vh_preedit_init();
void vh_preedit_destroy();
void vh_preedit_clear();
void vh_preedit_insert(guint keyval);
gboolean vh_preedit_move_cursor_left();
gboolean vh_preedit_move_cursor_right();
void vh_preedit_move_cursor_begin();
void vh_preedit_move_cursor_end();
void vh_preedit_delete_before_cursor();
void vh_preedit_delete_after_cursor();
guint vh_preedit_get_cursor_pos();
guint vh_preedit_set_cursor_pos(guint cursor_pos);
guint vh_preedit_get_before_cursor_char();
guint vh_preedit_set_before_cursor_char(guint keyval);
void vh_preedit_replace(guint index, guint len, gunichar* replace_str, guint replace_len);

// get length of current preedit string
guint vh_preedit_get_length();
guint vh_preedit_get_text_len();

// get current preedit string as unicode string
const gunichar *vh_preedit_get_preedit_string();
gchar *vh_preedit_get_utf8_string();

void vh_preedit_log();
gunichar vh_preedit_get_char(gint index);

#endif
