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
#include "VHLogger.h"
#include "VHConfiguration.h"
#include "VHPropertyList.h"

static IBusPropList *_property_list = NULL;


const gchar* get_super_key_name() {
	gint super_key = vh_configuration_get_super_key();
	if (super_key == __CTRL_SUPER_KEY__) {
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
    gint current_mode = vh_configuration_get_current_mode();
    IBusText* sm;
    IBusPropState state = PROP_STATE_UNCHECKED;
    if (current_mode == __VIETNAMESE_MODE_2__) {
    	sm = ibus_text_new_from_static_string("VN");
    	state = PROP_STATE_CHECKED;
    } else if (current_mode == __VIETHOA_MODE_2__) {
    	sm = ibus_text_new_from_static_string("VH");
    } else if (current_mode == __TEOCHEW_MODE_2__) {
    	sm = ibus_text_new_from_static_string("TC");
    } else if (current_mode == __CHINESE_MODE_2__) {
    	sm = ibus_text_new_from_static_string("CN");
    } else if (current_mode == __ENGLISH_MODE_2__) {
    	sm = ibus_text_new_from_static_string("EN");
    }
    ibus_property_set_state(prop, state);
    ibus_property_set_symbol(prop, sm);
}

void update_state(IBusProperty* prop, gboolean state) {
	ibus_property_set_state(prop, state ? PROP_STATE_CHECKED:PROP_STATE_UNCHECKED);
}

void vh_property_list_update_symbol(IBusAbacusEngine* viethoa) {
	IBusProperty* prop = ibus_prop_list_get(_property_list, 0);
	update_symbol(prop);
	ibus_engine_update_property((IBusEngine*)viethoa, prop);
}


void vh_property_list_init(){
	//
	if (_property_list) {
		vh_logger_warn("Property list initialized already");
		return;
	}

	//
	_property_list = ibus_prop_list_new();
	g_object_ref_sink(_property_list);
}

void vh_property_list_destroy(){
	//
	if (!_property_list) {
		vh_logger_warn("Property list was not initialied");
		return;
	}

	//
	g_object_unref(_property_list);
	_property_list = NULL;
}

void vh_property_list_load(){
    IBusText *label;
    IBusProperty * prop;

    if (!_property_list) {
    	vh_logger_error("Property list is null");
    	return;
    }

    // calculate initial mode
    gint cm = vh_configuration_get_current_mode();
    gboolean rm = vh_configuration_get_remembering_mode();
    gboolean as = vh_configuration_get_auto_show_candidate_table();

    //
    IBusProperty* vn_prop = create_radio_property(__VIETNAMESE_MODE_LABEL__, __VIETNAMESE_MODE_VALUE__, cm == __VIETNAMESE_MODE_2__, vh_configuration_get_vietnamese_mode_key());
    IBusProperty* vh_prop = create_radio_property(__VIETHOA_MODE_LABEL__, __VIETHOA_MODE_VALUE__, cm == __VIETHOA_MODE_2__, vh_configuration_get_viethoa_mode_key());
    IBusProperty* tc_prop = create_radio_property(__TEOCHEW_MODE_LABEL__, __TEOCHEW_MODE_VALUE__, cm == __TEOCHEW_MODE_2__, vh_configuration_get_teochew_mode_key());
    IBusProperty* cn_prop = create_radio_property(__CHINESE_MODE_LABEL__, __CHINESE_MODE_VALUE__, cm == __CHINESE_MODE_2__, vh_configuration_get_chinese_mode_key());
    IBusProperty* en_prop = create_radio_property(__ENGLISH_MODE_LABEL__, __ENGLISH_MODE_VALUE__, cm == __ENGLISH_MODE_2__, vh_configuration_get_english_mode_key());
    IBusProperty* rmm_prop = create_toggle_property(__REMEMBER_MODE_LABEL__, __REMEMBER_MODE_VALUE__, rm);

    // uncomment to allow not display candidate table
    //IBusProperty* as_prop = create_toggle_property(__AUTO_SHOW_CANDIDATE_TABLE_LABEL__, __AUTO_SHOW_CANDIDATE_TABLE_VALUE__, as);


    //
    update_symbol(vn_prop);
    
    //
    ibus_prop_list_append(_property_list, vn_prop);
    ibus_prop_list_append(_property_list, vh_prop);
    ibus_prop_list_append(_property_list, tc_prop);
    ibus_prop_list_append(_property_list, cn_prop);
    ibus_prop_list_append(_property_list, en_prop);
    ibus_prop_list_append(_property_list, rmm_prop);

    // uncomment to allow not display candidate table
    //ibus_prop_list_append(_property_list, as_prop);
    
    //
}

void vh_property_list_register(IBusAbacusEngine* viethoa){
	//
    if (!_property_list) {
    	vh_logger_error("Property list is null");
    	return;
    }

    //
	ibus_engine_register_properties((IBusEngine*)viethoa, _property_list);
}

void vh_property_list_update(IBusAbacusEngine* viethoa){
    IBusProperty *prop;
    IBusEngine *engine = (IBusEngine*)viethoa;
   
    if (!_property_list) {
    	vh_logger_error("Property list is null");
    	return;
    }

	//
	gint cm = vh_configuration_get_current_mode();

	//
	vh_property_list_update_symbol(viethoa);

	//
	prop = ibus_prop_list_get(_property_list, 0);
	update_state(prop, cm == __VIETNAMESE_MODE_2__);
	ibus_engine_update_property(engine, prop);

	//
	prop = ibus_prop_list_get(_property_list, 1);
	update_state(prop, cm == __VIETHOA_MODE_2__);
	ibus_engine_update_property(engine, prop);

	//
	prop = ibus_prop_list_get(_property_list, 2);
	update_state(prop, cm == __TEOCHEW_MODE_2__);
	ibus_engine_update_property(engine, prop);

	//
	prop = ibus_prop_list_get(_property_list, 3);
	update_state(prop, cm == __CHINESE_MODE_2__);
	ibus_engine_update_property(engine, prop);

	//
	prop = ibus_prop_list_get(_property_list, 4);
	update_state(prop, cm == __ENGLISH_MODE_2__);
	ibus_engine_update_property(engine, prop);

}
