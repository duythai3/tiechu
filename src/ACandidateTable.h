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
#ifndef __A_CANDIDATE_TABLE_H__
#define __A_CANDIDATE_TABLE_H__

#include <glib.h>
#include "engine.h"

// initialize the lookup table
gboolean a_candidate_table_init();

// destroy the lookup table
void a_candidate_table_destroy();

// show the lookup table
void a_candidate_table_show(IBusAbacusEngine *abacus);

// update the lookup table
void a_candidate_table_update(IBusAbacusEngine *abacus, gboolean is_show_up);

// hide the lookup table
void a_candidate_table_hide(IBusAbacusEngine *abacus);

// check if the lookup table is showing
gboolean a_candidate_table_showing();

// get candidate at an index
IBusText* a_candidate_table_get_candidate(guint index);

// get page size
guint a_candidate_table_get_page_size();

gboolean a_candidate_table_page_down(IBusAbacusEngine* abacus);

gboolean a_candidate_table_page_up(IBusAbacusEngine* abacus);

guint a_candidate_table_get_cursor_pos();

gboolean a_candidate_table_cursor_up(IBusAbacusEngine *abacus);

gboolean a_candidate_table_cursor_down(IBusAbacusEngine *abacus);

void a_candidate_table_set_command_text(IBusAbacusEngine* abacus, const gchar* text);

gboolean a_candidate_table_is_command_mode();

#endif
