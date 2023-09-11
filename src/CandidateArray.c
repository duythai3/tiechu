 /* The Tiechu engine for IBus
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
#include "Logger.h"
#include "CandidateArray.h"

GPtrArray *a_candidate_array = NULL;

// initialize
void candidate_array_init(){
	//
	if (a_candidate_array) {
		return;
	}

	//
	a_candidate_array = g_ptr_array_new();
    logger_log("Candidate array initialized");
}

// destroy
void candidate_array_destroy(){
	//
	if (!a_candidate_array) {
		return;
	}
	//
	g_ptr_array_unref(a_candidate_array);
     a_candidate_array = NULL;
    logger_log("Candidate array destroyed");
}

// append
void candidate_array_add(const gchar *candidate){
	//
	if (!a_candidate_array||!candidate) {
		return;
	}
	//
	g_ptr_array_add(a_candidate_array, candidate);
}

// get size
guint candidate_array_get_size(){
	if (!a_candidate_array) {
		return 0;
	}
	return a_candidate_array->len;
}

// get candidate at an index
const gchar* candidate_array_get_candidate(guint index){
	//
	if (!a_candidate_array) {
		return NULL;
	}

	//
	if(a_candidate_array->len<=index){
		return NULL;
	}

	//
	return (const gchar*)g_ptr_array_index(a_candidate_array, index);
}

// clear the candidate array
void candidate_array_clear(){
	//
	if (!a_candidate_array||a_candidate_array->len<1) {
		return;
	}

	//
	guint len = a_candidate_array->len;
	g_ptr_array_remove_range(a_candidate_array, 0, len);
    logger_log("Candidate list cleared");
}

