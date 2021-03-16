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
#ifndef __VH_CANDIDATE_TABLE_H__
#define __VH_CANDIDATE_TABLE_H__

#include <glib.h>
#include "engine.h"

// initialize the lookup table
gboolean vh_candidate_table_init();

// destroy the lookup table
void vh_candidate_table_destroy();

// show the lookup table
void vh_candidate_table_show(IBusViethoaEngine *viethoa);

// update the lookup table
void vh_candidate_table_update(IBusViethoaEngine *viethoa, gboolean thayduoc);

// hide the lookup table
void vh_candidate_table_hide(IBusViethoaEngine *viethoa);

// check if the lookup table is showing
gboolean vh_candidate_table_showing();

// get candidate at an index
IBusText *vh_candidate_table_get_candidate(guint index);

// get page size
guint vh_candidate_table_get_page_size();

gboolean vh_candidate_table_page_down();

gboolean vh_candidate_table_page_up();

guint vh_candidate_table_get_cursor_pos();

gboolean vh_candidate_table_cursor_up(IBusViethoaEngine *viethoa);

gboolean vh_candidate_table_cursor_down(IBusViethoaEngine *viethoa);

void vh_candidate_table_set_command_text(IBusViethoaEngine* viethoa, const gchar* text);

gboolean vh_candidate_table_is_command_mode();

#endif
