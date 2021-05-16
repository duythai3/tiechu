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
#include "VHZTelexTable2.h"
#include "engine.h"
#include "VHCandidateArray.h"
#include "VHLogger.h"
#include "VHCandidateTable.h"
#include "VHViethoaTable.h"
#include "VHTelexEditor.h"
#include "VHConfiguration.h"
#include "VHPropertyList.h"
#include "VHEnglishMode.h"
#include "VHVietnameseMode.h"
#include "VHViethoaMode.h"
#include "VHTeochewMode.h"
#include "VHChineseMode.h"
#include "VHDatabase.h"
#include "VHHelper.h"
#include "VHPreedit.h"
#include "VHLTelexTable.h"
#include "VHETelexTable.h"
#include "VHInterchangeMode.h"


/* functions prototype */
static void	ibus_viethoa_engine_class_init	(IBusViethoaEngineClass	*klass);
static void	ibus_viethoa_engine_init		(IBusViethoaEngine		*viethoa);
static void	ibus_viethoa_engine_destroy		(IBusViethoaEngine		*viethoa);
static gboolean 
			ibus_viethoa_engine_process_key_event
                                            (IBusEngine             *engine,
                                             guint               	 keyval,
                                             guint               	 keycode,
                                             guint               	 modifiers);
static void ibus_viethoa_engine_focus_in    (IBusEngine             *engine);
static void ibus_viethoa_engine_focus_out   (IBusEngine             *engine);
//static void ibus_viethoa_engine_reset       (IBusEngine             *engine);
static void ibus_viethoa_engine_enable      (IBusEngine             *engine);
static void ibus_viethoa_engine_disable     (IBusEngine             *engine);
static void ibus_engine_set_cursor_location (IBusEngine             *engine,
                                             gint                    x,
                                             gint                    y,
                                             gint                    w,
                                             gint                    h);
static void ibus_viethoa_engine_set_capabilities
                                            (IBusEngine             *engine,
                                             guint                   caps);
static void ibus_viethoa_engine_page_up     (IBusEngine             *engine);
static void ibus_viethoa_engine_page_down   (IBusEngine             *engine);
static void ibus_viethoa_engine_cursor_up   (IBusEngine             *engine);
static void ibus_viethoa_engine_cursor_down (IBusEngine             *engine);
static void ibus_viethoa_engine_candidate_clicked (IBusEngine *engine, guint index, guint button, guint state);


static void ibus_viethoa_property_activate  (IBusEngine             *engine,
                                             const gchar            *prop_name,
                                             gint                    prop_state);
static void ibus_viethoa_engine_property_show
											(IBusEngine             *engine,
                                             const gchar            *prop_name);
static void ibus_viethoa_engine_property_hide
											(IBusEngine             *engine,
                                             const gchar            *prop_name);

static void ibus_viethoa_engine_commit_string
                                            (IBusViethoaEngine      *viethoa,
                                             const gchar            *string);

//
static void property_activated(IBusEngine *engine, const gchar *property_ten, guint property_trangthai);

G_DEFINE_TYPE (IBusViethoaEngine, ibus_viethoa_engine, IBUS_TYPE_ENGINE)

//

static void
ibus_viethoa_engine_class_init (IBusViethoaEngineClass *klass)
{
    vh_logger_log("engine class init...\n");
	IBusObjectClass *ibus_object_class = IBUS_OBJECT_CLASS (klass);
	IBusEngineClass *engine_class = IBUS_ENGINE_CLASS (klass);
	
	ibus_object_class->destroy = (IBusObjectDestroyFunc) ibus_viethoa_engine_destroy;

    engine_class->process_key_event = ibus_viethoa_engine_process_key_event;
    engine_class->focus_out = ibus_viethoa_engine_focus_out;
    engine_class->focus_in = ibus_viethoa_engine_focus_in;
    
    engine_class->property_activate = property_activated;

	//
    engine_class->page_up = ibus_viethoa_engine_page_up;
    engine_class->page_down = ibus_viethoa_engine_page_down;

	//
	//engine_class->cursor_up = ibus_viethoa_engine_cursor_up;
	//engine_class->cursor_down = ibus_viethoa_engine_cursor_down;

	//
	engine_class->candidate_clicked = ibus_viethoa_engine_candidate_clicked;
}

void initialize(){
    vh_logger_log("viethoa engine init...\n");
    
    //load configuration
    vh_configuration_load();

    //
    vh_database_init();

	// create property list, and show it
    vh_property_list_init();
    vh_property_list_load();

	// initialize telex-related objects
    vh_z_telex_table_2_init();
    vh_ltelex_table_init();
    vh_etelex_table_init();
    vh_preedit_init();

    // initialize lookup table
    vh_candidate_table_init();
    
    vh_candidate_array_init();
    vh_viethoa_table_init();
}

void uninitialize(){
    vh_logger_log("__viethoa engine destroy...\n");

	// destroy property list
    vh_property_list_destroy();
    
	//telex
	vh_preedit_destroy();
    vh_z_telex_table_2_destroy();
    vh_ltelex_table_destroy();
    vh_etelex_table_destroy();

    vh_candidate_array_destroy();
    vh_viethoa_table_destroy();


    // destroy lookup table
    vh_candidate_table_destroy();

    //
    vh_database_destroy();
}

static void
ibus_viethoa_engine_init (IBusViethoaEngine *viethoa)
{
    initialize();
}

static void
ibus_viethoa_engine_destroy (IBusViethoaEngine *viethoa)
{
    uninitialize();
	((IBusObjectClass *) ibus_viethoa_engine_parent_class)->destroy ((IBusObject *)viethoa);
}

static void ibus_viethoa_engine_focus_out   (IBusEngine *viethoa){
    vh_helper_clear_preedit((IBusViethoaEngine*)viethoa);
}

static void ibus_viethoa_engine_focus_in (IBusEngine *engine){
    vh_logger_log("Bo Go Viethoa received focus_in event");
    vh_logger_backup();
    vh_property_list_register((IBusViethoaEngine*)engine);
}

static void ibus_viethoa_engine_page_up     (IBusEngine  *engine) {
	vh_logger_log("ibus_viethoa_engine_page_up");
    if (vh_candidate_table_showing()) {
        vh_candidate_table_page_up((IBusViethoaEngine*) engine);
	}
}

static void ibus_viethoa_engine_page_down   (IBusEngine *engine) {
	vh_logger_log("ibus_viethoa_engine_page_down");
    if (vh_candidate_table_showing()) {
        vh_candidate_table_page_down((IBusViethoaEngine*) engine);
	}
}

static void ibus_viethoa_engine_cursor_up   (IBusEngine *engine) {
	vh_logger_log("ibus_viethoa_engine_cursor_up");
    if (vh_candidate_table_showing()) {
        vh_candidate_table_cursor_up((IBusViethoaEngine*) engine);
	}
}
static void ibus_viethoa_engine_cursor_down (IBusEngine *engine) {
	vh_logger_log("ibus_viethoa_engine_cursor_down");
    if (vh_candidate_table_showing()) {
        vh_candidate_table_cursor_down((IBusViethoaEngine*) engine);
	}
}

// processing when a candidate is selected using mouse
static void ibus_viethoa_engine_candidate_clicked (IBusEngine *engine, guint index, guint button, guint state) {
	vh_helper_commit_candidate_in_page((IBusViethoaEngine*)engine, index);
}

static void property_activated(IBusEngine *engine, const gchar *property_ten, guint property_trangthai){
    vh_logger_log("Property %s changed to %d",property_ten, property_trangthai);
    if(g_strcmp0(property_ten, __VIETNAMESE_MODE_VALUE__) == 0){
        if(property_trangthai == PROP_STATE_CHECKED){
            vh_configuration_set_selected_mode(__VIETNAMESE_MODE_2__);
            vh_property_list_update_symbol((IBusViethoaEngine*)engine);
            vh_configuration_save();
        }
    }else if(g_strcmp0(property_ten, __VIETHOA_MODE_VALUE__) == 0){
        if(property_trangthai == PROP_STATE_CHECKED){
            vh_configuration_set_selected_mode(__VIETHOA_MODE_2__);
            vh_property_list_update_symbol((IBusViethoaEngine*)engine);
            vh_configuration_save();
        }
    }else if(g_strcmp0(property_ten, __TEOCHEW_MODE_VALUE__) == 0){
        if(property_trangthai == PROP_STATE_CHECKED){
            vh_configuration_set_selected_mode(__TEOCHEW_MODE_2__);
            vh_property_list_update_symbol((IBusViethoaEngine*)engine);
            vh_configuration_save();
        }
    }else if(g_strcmp0(property_ten, __CHINESE_MODE_VALUE__) == 0){
        if(property_trangthai == PROP_STATE_CHECKED){
            vh_configuration_set_selected_mode(__CHINESE_MODE_2__);
            vh_property_list_update_symbol((IBusViethoaEngine*)engine);
            vh_configuration_save();
        }
    }else if(g_strcmp0(property_ten, __ENGLISH_MODE_VALUE__) == 0){
        if(property_trangthai == PROP_STATE_CHECKED){
            vh_configuration_set_selected_mode(__ENGLISH_MODE_2__);
            vh_property_list_update_symbol((IBusViethoaEngine*)engine);
            vh_configuration_save();
        }
    }else if(g_strcmp0(property_ten, __REMEMBER_MODE_VALUE__) == 0){
        vh_configuration_set_remembering_mode(property_trangthai);
        vh_configuration_save();
    }else if(g_strcmp0(property_ten, __AUTO_SHOW_CANDIDATE_TABLE_VALUE__) == 0){
        vh_configuration_set_auto_show_candidate_table(property_trangthai);
        vh_configuration_save();
    }
}

static gboolean _deliver_key(IBusViethoaEngine *viethoa, guint keyval, guint keycode, guint modifiers){
    //
    gint current_mode = vh_configuration_get_current_mode();
    switch(current_mode) {
    case __ENGLISH_MODE_2__:
        return vh_english_mode_process_key_event(viethoa, keyval, keycode, modifiers);
    case __VIETNAMESE_MODE_2__:
        return vh_vietnamese_mode_process_key_event(viethoa, keyval, keycode, modifiers);
    case __VIETHOA_MODE_2__:
        return vh_viethoa_mode_process_key_event(viethoa, keyval, keycode, modifiers);
    case __TEOCHEW_MODE_2__:
        return vh_teochew_mode_process_key_event(viethoa, keyval, keycode, modifiers);
    case __CHINESE_MODE_2__:
        return vh_chinese_mode_process_key_event(viethoa, keyval, keycode, modifiers);
    default:
        return FALSE;
    }
}

static gboolean _manage_mode(IBusViethoaEngine *viethoa, guint keyval, guint keycode, guint modifiers){


    gint current_mode = vh_configuration_get_current_mode(); //current mode
    guint vietnamese_mode_key = (guint)vh_configuration_get_vietnamese_mode_key();
    guint viethoa_mode_key = (guint)vh_configuration_get_viethoa_mode_key();
    guint teochew_mode_key = (guint)vh_configuration_get_teochew_mode_key();
    guint chinese_mode_key = (guint)vh_configuration_get_chinese_mode_key();
    guint english_mode_key = (guint)vh_configuration_get_english_mode_key();

    // vietnamese mode
    if ((vh_helper_is_control_pressed(modifiers)) && (keyval == vietnamese_mode_key)) {
        if (current_mode == __VIETNAMESE_MODE_2__) {
            return TRUE;
        }
        vh_configuration_set_selected_mode(__VIETNAMESE_MODE_2__);
        vh_property_list_update(viethoa);
        vh_configuration_save();
        vh_helper_clear_preedit(viethoa);
        return TRUE;
    }

    // viethoa mode
    if ((vh_helper_is_control_pressed(modifiers)) && (keyval == viethoa_mode_key)) {
        if (current_mode == __VIETHOA_MODE_2__) {
            return TRUE;
        }
        vh_configuration_set_selected_mode(__VIETHOA_MODE_2__);
        vh_property_list_update(viethoa);
        vh_configuration_save();
        vh_helper_clear_preedit(viethoa);
        return TRUE;
    }

    // teochew mode
    if ((vh_helper_is_control_pressed(modifiers)) && (keyval == teochew_mode_key)) {
        if (current_mode == __TEOCHEW_MODE_2__) {
            return TRUE;
        }
        vh_configuration_set_selected_mode(__TEOCHEW_MODE_2__);
        vh_property_list_update(viethoa);
        vh_configuration_save();
        vh_helper_clear_preedit(viethoa);
        return TRUE;
    }

    // chinese mode
    if ((vh_helper_is_control_pressed(modifiers)) && (keyval == chinese_mode_key)) {
        if (current_mode == __CHINESE_MODE_2__) {
            return TRUE;
        }
        vh_configuration_set_selected_mode(__CHINESE_MODE_2__);
        vh_property_list_update(viethoa);
        vh_configuration_save();
        vh_helper_clear_preedit(viethoa);
        return TRUE;
    }

    // english mode
    if ((vh_helper_is_control_pressed(modifiers)) && (keyval == english_mode_key)) {
        if (current_mode == __ENGLISH_MODE_2__) {
            return TRUE;
        }
        vh_configuration_set_selected_mode(__ENGLISH_MODE_2__);
        vh_property_list_update(viethoa);
        vh_configuration_save();
        vh_helper_clear_preedit(viethoa);
        return TRUE;
    }

    //
    if (keyval == IBUS_KEY_Control_L || keyval == IBUS_KEY_Control_R) {
        vh_interchange_mode_save_begin_interchange_mode_time();
        return FALSE;
    }

    //
    if (keyval == IBUS_KEY_Shift_L) {
        vh_interchange_mode_save_begin_interchange_mode_time();
        return FALSE;
    }

    //
    if (vh_interchange_mode_is_in_interchange_mode()) {
        vh_interchange_mode_turn_shift_pressed_off();
        vh_logger_log("Leave interchange mode");
    }
    return _deliver_key(viethoa, keyval, keycode, modifiers);
}


static gboolean
ibus_viethoa_engine_process_key_event (IBusEngine *engine,
                                       guint       keyval,
                                       guint       keycode,
                                       guint       modifiers)
{
    //IBusText *text;
    IBusViethoaEngine *viethoa = (IBusViethoaEngine *)engine;

    //
    if (vh_interchange_mode_is_in_interchange_mode()) {
        if (vh_helper_is_event_released(modifiers)) {
            return FALSE;
        }
        return _manage_mode(viethoa, keyval, keycode, modifiers);
    }

    //
    if (keyval == IBUS_KEY_Shift_L) {
        if (vh_helper_is_event_released(modifiers)) {
            if (!vh_interchange_mode_is_shift_pressed_on()) {
                return FALSE;
            }
            vh_logger_log("Enter interchange mode");
            vh_interchange_mode_save_begin_interchange_mode_time();
            return FALSE;
        } else {
            vh_logger_log("Left Shift pressed");
            vh_interchange_mode_turn_shift_pressed_on();
            return FALSE;
        }
    }

    //
    if (vh_interchange_mode_is_in_interchange_mode()) {
        vh_logger_log("Leave interchange mode");
        vh_interchange_mode_turn_shift_pressed_off();
    }
    return _deliver_key(viethoa, keyval, keycode, modifiers);

}
