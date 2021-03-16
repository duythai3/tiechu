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
#ifndef _VH_CANDIDATE_ARRAY_H_
#define _VH_CANDIDATE_ARRAY_H_

#include <glib.h>
// initialize
void vh_candidate_array_init();

// destroy
void vh_candidate_array_destroy();

// append
void vh_candidate_array_add(const gchar* candidate);

// get size
guint vh_candidate_array_get_size();

// get candidate at an index
const gchar* vh_candidate_array_get_candidate(guint index);

// clear the candidate array
void vh_candidate_array_clear();


#endif

