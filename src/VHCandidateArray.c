/* vim:set et ts=4 sts=4:
 *
 * ibus-viethoa - The Viethoa engine for IBus
 *
 * Copyright (c) 2020-2021 Duy Thai, duyytthai@gmail.com
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
#include <gmodule.h>
#include "VHLogger.h"

GPtrArray *_candidate_array = NULL;

// initialize
void vh_candidate_array_init(){
	//
	if (_candidate_array) {
		return;
	}

	//
	_candidate_array = g_ptr_array_new();
	vh_logger_log("Candidate array initialized");
}

// destroy
void vh_candidate_array_destroy(){
	//
	if (!_candidate_array) {
		return;
	}
	//
	g_ptr_array_unref(_candidate_array);
	_candidate_array = NULL;
	vh_logger_log("Candidate array destroyed");
}

// append
void vh_candidate_array_add(gchar *candidate){
	//
	if (!_candidate_array || !candidate) {
		return;
	}
	//
	g_ptr_array_add(_candidate_array, candidate);
}

// get size
guint vh_candidate_array_get_size(){
	if (!_candidate_array) {
		return 0;
	}
	return _candidate_array->len;
}

// get candidate at an index
const gchar* vh_candidate_array_get_candidate(guint index){
	//
	if (!_candidate_array) {
		return NULL;
	}

	//
	if(_candidate_array->len <= index){
		return NULL;
	}

	//
	return (const gchar*)g_ptr_array_index(_candidate_array, index);
}

// clear the candidate array
void vh_candidate_array_clear(){
	//
	if (!_candidate_array || _candidate_array->len < 1) {
		return;
	}

	//
	guint len = _candidate_array->len;
	g_ptr_array_remove_range(_candidate_array, 0, len);
	vh_logger_log("Candidate list cleared");
}

