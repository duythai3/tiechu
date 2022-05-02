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
#include <glib.h>
#include <ibus.h>
#include "engine.h"
#include "AConfiguration.h"
#include "ACandidateTable.h"
#include "ACandidateArray.h"
#include "ALogger.h"
#include "AHanvietTable.h"


static IBusLookupTable *a_candidate_table = NULL;
static gboolean a_is_candidate_table_showing = FALSE;

static gboolean a_command_mode = FALSE;
void a_candidate_table_set_command_text(IBusAbacusEngine* abacus, const gchar* text) {
    //
    IBusText* lb;

    //
    if (text == NULL) {
        lb = ibus_text_new_from_string("");
        ibus_engine_update_auxiliary_text((IBusEngine*)abacus, lb, FALSE);
        a_command_mode = FALSE;
    } else {
        lb = ibus_text_new_from_string(text);
        ibus_engine_update_auxiliary_text((IBusEngine*)abacus, lb, TRUE);
        a_command_mode = TRUE;
    }
}

gboolean a_candidate_table_is_command_mode() {
    return a_command_mode;
}


// add a candidate to the lookup table
static void a_add_candidate(const gchar *candidate){
    if (!a_candidate_table) {
        return;
    }
    IBusText *ibus_candidate = ibus_text_new_from_string(candidate);
    ibus_lookup_table_append_candidate(a_candidate_table, ibus_candidate);
}

// initialize the lookup table
gboolean a_candidate_table_init(){
	//
    if (a_candidate_table) {
		return TRUE;
	}

	//
    a_candidate_table = ibus_lookup_table_new(__CANDIDATE_TABLE_PAGE_SIZE__, 0, TRUE, FALSE);
    if (!a_candidate_table) {
        a_logger_log("Creating Lookup table failed");
		return FALSE;
	}

	//
    ibus_lookup_table_set_orientation(a_candidate_table, 0);
    guint direction = ibus_lookup_table_get_orientation(a_candidate_table);
    a_logger_log("Lookup Table Orientation: %d", direction);
    g_object_ref_sink(a_candidate_table);

	//
    a_logger_log("Lookup table created");
	return TRUE;
}


// destroy the lookup table
void a_candidate_table_destroy(){
	//
    if (!a_candidate_table) {
		return;
	}

	//
    ibus_lookup_table_clear(a_candidate_table);
    g_object_unref(a_candidate_table);
    a_candidate_table = NULL;
    a_logger_log("Lookup table destroyed");
}

// show the lookup table
void a_candidate_table_show(IBusAbacusEngine *abacus){
	//
    if (!a_candidate_table) {
		return;
	}

	//
    if(a_is_candidate_table_showing){
        a_candidate_table_hide(abacus);
	}else{
        ibus_lookup_table_clear(a_candidate_table);
	}

	//
	gint candidate_count=a_candidate_array_get_size();
    a_logger_log("number of found candidates: %d", candidate_count);

	//
	if (candidate_count < 1) {
		return;
	}

	//
	for(gint index = 0; index<candidate_count; index++){
		const gchar *candidate =a_candidate_array_get_candidate(index);
		if(candidate){
            a_add_candidate(candidate);
		}
	}

	//
    ibus_engine_update_lookup_table((IBusEngine*)abacus, a_candidate_table, TRUE);
    a_is_candidate_table_showing = TRUE;
}

// update the lookup table
void a_candidate_table_update(IBusAbacusEngine *abacus, gboolean is_show_up){
    a_candidate_table_show(abacus);
}

// hide the lookup table
void a_candidate_table_hide(IBusAbacusEngine *abacus){
	//
    if (!a_candidate_table) {
		return;
	}

	//
    if(a_is_candidate_table_showing){
		ibus_engine_hide_lookup_table((IBusEngine*)abacus);
		// clear lookup table
        ibus_lookup_table_clear(a_candidate_table);
        a_is_candidate_table_showing = FALSE;
        a_candidate_table_set_command_text(abacus, NULL);
	}
}

// check if the lookup table is showing
gboolean a_candidate_table_showing(){
    return a_is_candidate_table_showing;
}

// get candidate at an index
IBusText* a_candidate_table_get_candidate(guint index){
    if (!a_candidate_table) {
		return NULL;
	}
    return ibus_lookup_table_get_candidate(a_candidate_table, index);
}

// get page size
guint a_candidate_table_get_page_size(){
    if (!a_candidate_table) {
		return 0;
	}
    return ibus_lookup_table_get_page_size(a_candidate_table);
}

gboolean a_candidate_table_page_down(IBusAbacusEngine* abacus) {
    if (!a_candidate_table) {
        return FALSE;
    }

	//
    ibus_lookup_table_page_down(a_candidate_table);
    ibus_engine_update_lookup_table((IBusEngine*)abacus, a_candidate_table, TRUE);
    return TRUE;
}

gboolean a_candidate_table_page_up(IBusAbacusEngine *abacus) {
	//
    if (!a_candidate_table) {
		return FALSE;
	}

	//
    ibus_lookup_table_page_up(a_candidate_table);
    ibus_engine_update_lookup_table((IBusEngine*)abacus, a_candidate_table, TRUE);
	return TRUE;
}

guint a_candidate_table_get_cursor_pos() {
    if (!a_candidate_table) {
        return 0;
	}
    return ibus_lookup_table_get_cursor_pos(a_candidate_table);
}

gboolean a_candidate_table_cursor_up(IBusAbacusEngine *abacus) {
	//
    if (!a_candidate_table) {
		return FALSE;
	}

	//
    gboolean ret = ibus_lookup_table_cursor_up(a_candidate_table);
    ibus_engine_update_lookup_table((IBusEngine*)abacus, a_candidate_table, TRUE);
	return ret;
}

gboolean a_candidate_table_cursor_down(IBusAbacusEngine *abacus) {
	//
    if (!a_candidate_table) {
		return FALSE;
	}

	//
    gboolean ret = ibus_lookup_table_cursor_down(a_candidate_table);
    ibus_engine_update_lookup_table((IBusEngine*)abacus, a_candidate_table, TRUE);
	return ret;
}