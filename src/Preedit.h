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

#ifndef __PREEDIT_H__
#define __PREEDIT_H__

#include "UString.h"

void preedit_init();
void preedit_destroy();
void preedit_clear();
void preedit_insert(guint keyval);
gboolean preedit_move_cursor_left();
gboolean preedit_move_cursor_right();
void preedit_move_cursor_begin();
void preedit_move_cursor_end();
void preedit_delete_before_cursor();
void preedit_delete_after_cursor();
guint preedit_get_cursor_pos();
guint preedit_set_cursor_pos(guint cursor_pos);
guint preedit_get_before_cursor_char();
guint preedit_set_before_cursor_char(guint keyval);
void preedit_replace(guint index, guint len, gunichar* replace_str, guint replace_len);

// get length of current preedit string
guint preedit_get_length();
guint preedit_get_text_len();

// get current preedit string as unicode string
const gunichar *preedit_get_preedit_string();
gchar *preedit_get_utf8_string();

void preedit_log();
gunichar preedit_get_char(gint index);

#endif
