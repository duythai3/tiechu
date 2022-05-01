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
#include <ibus.h>
#include "engine.h"
#include "AConfiguration.h"
#include "VHCandidateTable.h"

#include "VHCandidateArray.h"
#include "ALogger.h"
#include "VHViethoaTable.h"


static IBusLookupTable *_candidate_table = NULL;
static gboolean _is_candidate_table_showing = FALSE;

static gboolean _command_mode = FALSE;
void vh_candidate_table_set_command_text(IBusAbacusEngine* viethoa, const gchar* text) {
    //
    IBusText* lb;

    //
    if (text == NULL) {
        lb = ibus_text_new_from_string("");
        ibus_engine_update_auxiliary_text((IBusEngine*)viethoa, lb, FALSE);
        _command_mode = FALSE;
    } else {
        lb = ibus_text_new_from_string(text);
        ibus_engine_update_auxiliary_text((IBusEngine*)viethoa, lb, TRUE);
        _command_mode = TRUE;
    }
}

gboolean vh_candidate_table_is_command_mode() {
    return _command_mode;
}


// add a candidate to the lookup table
static void _add_candidate(const gchar *candidate){
    if (!_candidate_table) {
        return;
    }
    IBusText *ibus_candidate = ibus_text_new_from_string(candidate);
    ibus_lookup_table_append_candidate(_candidate_table, ibus_candidate);
}

// initialize the lookup table
gboolean vh_candidate_table_init(){
	//
    if (_candidate_table) {
		return TRUE;
	}

	//
    _candidate_table = ibus_lookup_table_new(__CANDIDATE_TABLE_PAGE_SIZE__, 0, TRUE, FALSE);
    if (!_candidate_table) {
        a_logger_log("Creating Lookup table failed");
		return FALSE;
	}

	//
    ibus_lookup_table_set_orientation(_candidate_table, 0);
    guint direction = ibus_lookup_table_get_orientation(_candidate_table);
    a_logger_log("Lookup Table Orientation: %d", direction);
    g_object_ref_sink(_candidate_table);

	//
    a_logger_log("Lookup table created");
	return TRUE;
}


// destroy the lookup table
void vh_candidate_table_destroy(){
	//
    if (!_candidate_table) {
		return;
	}

	//
    ibus_lookup_table_clear(_candidate_table);
    g_object_unref(_candidate_table);
    _candidate_table = NULL;
    a_logger_log("Lookup table destroyed");
}

// show the lookup table
void vh_candidate_table_show(IBusAbacusEngine *viethoa){
	//
    if (!_candidate_table) {
		return;
	}

	//
    if(_is_candidate_table_showing){
        vh_candidate_table_hide(viethoa);
	}else{
        ibus_lookup_table_clear(_candidate_table);
	}

	//
	gint candidate_count = vh_candidate_array_get_size();
    a_logger_log("number of found candidates: %d", candidate_count);

	//
	if (candidate_count < 1) {
		return;
	}

	//
	for(gint chiso = 0; chiso < candidate_count; chiso++){
		const gchar *candidate = vh_candidate_array_get_candidate(chiso);
		if(candidate){
			_add_candidate(candidate);
		}
	}

	//
    ibus_engine_update_lookup_table((IBusEngine*)viethoa, _candidate_table, TRUE);
    _is_candidate_table_showing = TRUE;
}

// update the lookup table
void vh_candidate_table_update(IBusAbacusEngine *viethoa, gboolean visible){
    vh_candidate_table_show(viethoa);
}

// hide the lookup table
void vh_candidate_table_hide(IBusAbacusEngine *viethoa){
	//
    if (!_candidate_table) {
		return;
	}

	//
    if(_is_candidate_table_showing){
		ibus_engine_hide_lookup_table((IBusEngine*)viethoa);
		// clear lookup table
        ibus_lookup_table_clear(_candidate_table);
        _is_candidate_table_showing = FALSE;
        vh_candidate_table_set_command_text(viethoa, NULL);
	}
}

// check if the lookup table is showing
gboolean vh_candidate_table_showing(){
    return _is_candidate_table_showing;
}

// get candidate at an index
IBusText *vh_candidate_table_get_candidate(guint index){
    if (!_candidate_table) {
		return NULL;
	}
    return ibus_lookup_table_get_candidate(_candidate_table, index);
}

// get page size
guint vh_candidate_table_get_page_size(){
    if (!_candidate_table) {
		return 0;
	}
    return ibus_lookup_table_get_page_size(_candidate_table);
}

gboolean vh_candidate_table_page_down(IBusAbacusEngine *viethoa) {
    if (!_candidate_table) {
        return FALSE;
    }

	//
    ibus_lookup_table_page_down(_candidate_table);
    ibus_engine_update_lookup_table((IBusEngine*)viethoa, _candidate_table, TRUE);
    return TRUE;
}

gboolean vh_candidate_table_page_up(IBusAbacusEngine *viethoa) {
	//
    if (!_candidate_table) {
		return FALSE;
	}

	//
    ibus_lookup_table_page_up(_candidate_table);
    ibus_engine_update_lookup_table((IBusEngine*)viethoa, _candidate_table, TRUE);
	return TRUE;
}

guint vh_candidate_table_get_cursor_pos() {
    if (!_candidate_table) {
        return 0;
	}
    return ibus_lookup_table_get_cursor_pos(_candidate_table);
}

gboolean vh_candidate_table_cursor_up(IBusAbacusEngine *viethoa) {
	//
    if (!_candidate_table) {
		return FALSE;
	}

	//
    gboolean ret = ibus_lookup_table_cursor_up(_candidate_table);
    ibus_engine_update_lookup_table((IBusEngine*)viethoa, _candidate_table, TRUE);
	return ret;
}

gboolean vh_candidate_table_cursor_down(IBusAbacusEngine *viethoa) {
	//
    if (!_candidate_table) {
		return FALSE;
	}

	//
    gboolean ret = ibus_lookup_table_cursor_down(_candidate_table);
    ibus_engine_update_lookup_table((IBusEngine*)viethoa, _candidate_table, TRUE);
	return ret;
}
