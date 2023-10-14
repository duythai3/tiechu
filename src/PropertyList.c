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

#include <glib.h>
#include <ibus.h>
#include "Logger.h"
#include "Configuration.h"
#include "PropertyList.h"

static IBusPropList *_property_list = NULL;


const gchar* get_super_key_name() {
	gint super_key =configuration_get_super_key();
	if (super_key == TCTRL_SUPER_KEY) {
		return "Ctrl";
	} else {
		return "Shift";
	}
}

IBusProperty* create_radio_property(const gchar* lb, const gchar* vl, gboolean state, gint hotkey) {
	const gchar* super_key_name = get_super_key_name();
    IBusText* ibus_lb = ibus_text_new_from_printf("%s - Shift, %s+%c", lb, super_key_name, (gchar)hotkey);
	IBusPropState prop_state = state ? PROP_STATE_CHECKED : PROP_STATE_UNCHECKED;
	IBusProperty* prop = ibus_property_new(vl, PROP_TYPE_RADIO, ibus_lb, NULL, NULL, TRUE, TRUE, prop_state, NULL);
	return prop;
}

IBusProperty* create_toggle_property(const gchar* lb, const gchar* vl, gboolean state) {
	IBusText* ibus_lb = ibus_text_new_from_string(lb);
	IBusPropState prop_state = state ? PROP_STATE_CHECKED : PROP_STATE_UNCHECKED;
	IBusProperty* prop = ibus_property_new(vl, PROP_TYPE_TOGGLE, ibus_lb, NULL, NULL, TRUE, TRUE, prop_state, NULL);
	return prop;
}


void update_symbol(IBusProperty* prop) {
    gint current_mode =configuration_get_current_mode();
    IBusText* sm=NULL;
    IBusPropState state = PROP_STATE_UNCHECKED;
    if (current_mode == TVIETNAMESE_MODE) {
    	sm = ibus_text_new_from_static_string("VN");
    	state = PROP_STATE_CHECKED;
    } else if (current_mode == THANVIET_MODE) {
    	sm = ibus_text_new_from_static_string("VH");
    } else if (current_mode == TTEOCHEW_MODE) {
    	sm = ibus_text_new_from_static_string("TC");
    } else if (current_mode == TCHINESE_MODE) {
    	sm = ibus_text_new_from_static_string("CN");
    } else if (current_mode == TENGLISH_MODE) {
    	sm = ibus_text_new_from_static_string("EN");
    }
    ibus_property_set_state(prop, state);
    ibus_property_set_symbol(prop, sm);
}

void update_state(IBusProperty* prop, gboolean state) {
	ibus_property_set_state(prop, state ? PROP_STATE_CHECKED:PROP_STATE_UNCHECKED);
}

void property_list_update_symbol(IBusTiechuEngine* tiechu) {
	IBusProperty* prop = ibus_prop_list_get(_property_list, 0);
	update_symbol(prop);
    ibus_engine_update_property((IBusEngine*)tiechu, prop);
}


void property_list_init(){
	//
	if (_property_list) {
        logger_warn("Property list initialized already");
		return;
	}

	//
	_property_list = ibus_prop_list_new();
	g_object_ref_sink(_property_list);
}

void property_list_destroy(){
	//
	if (!_property_list) {
        logger_warn("Property list was not initialized");
		return;
	}

	//
	g_object_unref(_property_list);
	_property_list = NULL;
}

void property_list_load(){
    IBusText *label;
    IBusProperty * prop;

    if (!_property_list) {
        logger_error("Property list is null");
    	return;
    }

    // calculate initial mode
    gint cm =configuration_get_current_mode();
    gboolean rm =configuration_get_remembering_mode();
    gboolean as =configuration_get_auto_show_candidate_table();

    //
    IBusProperty* vn_prop = create_radio_property(TVIETNAMESE_MODE_LABEL, TVIETNAMESE_MODE_VALUE, cm == TVIETNAMESE_MODE, configuration_get_vietnamese_mode_key());
    IBusProperty* tc_prop = create_radio_property(TTEOCHEW_MODE_LABEL, TTEOCHEW_MODE_VALUE, cm == TTEOCHEW_MODE, configuration_get_teochew_mode_key());
    IBusProperty* vh_prop = create_radio_property(THANVIET_MODE_LABEL, THANVIET_MODE_VALUE, cm == THANVIET_MODE, configuration_get_hanviet_mode_key());
    IBusProperty* cn_prop = create_radio_property(TCHINESE_MODE_LABEL, TCHINESE_MODE_VALUE, cm == TCHINESE_MODE, configuration_get_chinese_mode_key());
    IBusProperty* en_prop = create_radio_property(TENGLISH_MODE_LABEL, TENGLISH_MODE_VALUE, cm == TENGLISH_MODE, configuration_get_english_mode_key());
    IBusProperty* rmm_prop = create_toggle_property(TREMEMBER_MODE_LABEL, TREMEMBER_MODE_VALUE, rm);

    // uncomment to allow not display candidate table
    //IBusProperty* as_prop = create_toggle_property(__A_AUTO_SHOW_CANDIDATE_TABLE_LABEL__, __A_AUTO_SHOW_CANDIDATE_TABLE_VALUE__, as);


    //
    update_symbol(vn_prop);
    
    //
    ibus_prop_list_append(_property_list, vn_prop);
    ibus_prop_list_append(_property_list, tc_prop);
    ibus_prop_list_append(_property_list, vh_prop);
    ibus_prop_list_append(_property_list, cn_prop);
    ibus_prop_list_append(_property_list, en_prop);
    ibus_prop_list_append(_property_list, rmm_prop);

    // uncomment to allow not display candidate table
    //ibus_prop_list_append(_property_list, as_prop);
    
    //
}

void property_list_register(IBusTiechuEngine* tiechu){
	//
    if (!_property_list) {
        logger_error("Property list is null");
    	return;
    }

    //
    ibus_engine_register_properties((IBusEngine*)tiechu, _property_list);
}

void property_list_update(IBusTiechuEngine* tiechu){
    IBusProperty *prop;
    IBusEngine *engine = (IBusEngine*)tiechu;
   
    if (!_property_list) {
        logger_error("Property list is null");
    	return;
    }

	//
	gint cm=configuration_get_current_mode();

	//
    property_list_update_symbol(tiechu);

	//
	prop = ibus_prop_list_get(_property_list, 0);
	update_state(prop, cm == TVIETNAMESE_MODE);
	ibus_engine_update_property(engine, prop);

	//
	prop = ibus_prop_list_get(_property_list, 1);
	update_state(prop, cm == THANVIET_MODE);
	ibus_engine_update_property(engine, prop);

	//
	prop = ibus_prop_list_get(_property_list, 2);
	update_state(prop, cm == TTEOCHEW_MODE);
	ibus_engine_update_property(engine, prop);

	//
	prop = ibus_prop_list_get(_property_list, 3);
	update_state(prop, cm == TCHINESE_MODE);
	ibus_engine_update_property(engine, prop);

	//
	prop = ibus_prop_list_get(_property_list, 4);
	update_state(prop, cm == TENGLISH_MODE);
	ibus_engine_update_property(engine, prop);
}
