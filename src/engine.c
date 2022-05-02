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

#include "AZTelexTable2.h"
#include "engine.h"
#include "ACandidateArray.h"
#include "ALogger.h"
#include "ACandidateTable.h"
#include "AHanvietTable.h"
#include "ATelexEditor.h"
#include "AConfiguration.h"
#include "APropertyList.h"
#include "AEnglishMode.h"
#include "AVietnameseMode.h"
#include "AHanvietMode.h"
#include "ATeochewMode.h"
#include "AChineseMode.h"
#include "ADatabase.h"
#include "AHelper.h"
#include "APreedit.h"
#include "ALTelexTable.h"
#include "AETelexTable.h"
#include "AInterchangeMode.h"


/* functions prototype */
static void ibus_abacus_engine_class_init(IBusAbacusEngineClass *klass);

static void ibus_abacus_engine_init(IBusAbacusEngine *abacus);

static void ibus_abacus_engine_destroy(IBusAbacusEngine *abacus);

static gboolean ibus_abacus_engine_process_key_event(IBusEngine *engine, guint keyval, guint keycode, guint modifiers);

static void ibus_abacus_engine_focus_in(IBusEngine *engine);

static void ibus_abacus_engine_focus_out(IBusEngine *engine);

//static void ibus_abacus_engine_reset(IBusEngine *engine);
static void ibus_abacus_engine_enable(IBusEngine *engine);

static void ibus_abacus_engine_disable(IBusEngine *engine);

static void ibus_engine_set_cursor_location(IBusEngine *engine, gint x, gint y, gint w, gint h);

static void ibus_abacus_engine_set_capabilities(IBusEngine *engine, guint caps);

static void ibus_abacus_engine_page_up(IBusEngine *engine);

static void ibus_abacus_engine_page_down(IBusEngine *engine);

static void ibus_abacus_engine_cursor_up(IBusEngine *engine);

static void ibus_abacus_engine_cursor_down(IBusEngine *engine);

static void ibus_abacus_engine_candidate_clicked(IBusEngine *engine, guint index, guint button, guint state);

static void ibus_abacus_property_activate(IBusEngine *engine, const gchar *prop_name, gint prop_state);

static void ibus_abacus_engine_property_show(IBusEngine *engine, const gchar *prop_name);

static void ibus_abacus_engine_property_hide(IBusEngine *engine, const gchar *prop_name);

static void ibus_abacus_engine_commit_string(IBusAbacusEngine *abacus, const gchar *string);

//
static void property_activated(IBusEngine *engine, const gchar *property_ten, guint property_status);

G_DEFINE_TYPE (IBusAbacusEngine, ibus_abacus_engine, IBUS_TYPE_ENGINE)

//

static void ibus_abacus_engine_class_init(IBusAbacusEngineClass *klass){
    a_logger_log("engine class init...\n");
    IBusObjectClass *ibus_object_class=IBUS_OBJECT_CLASS (klass);
    IBusEngineClass *engine_class=IBUS_ENGINE_CLASS (klass);

    //
    ibus_object_class->destroy=(IBusObjectDestroyFunc) ibus_abacus_engine_destroy;
    engine_class->process_key_event=ibus_abacus_engine_process_key_event;
    engine_class->focus_out=ibus_abacus_engine_focus_out;
    engine_class->focus_in=ibus_abacus_engine_focus_in;
    engine_class->property_activate=property_activated;

    //
    engine_class->page_up=ibus_abacus_engine_page_up;
    engine_class->page_down=ibus_abacus_engine_page_down;

    //
    //engine_class->cursor_up = ibus_abacus_engine_cursor_up;
    //engine_class->cursor_down = ibus_abacus_engine_cursor_down;

    //
    engine_class->candidate_clicked=ibus_abacus_engine_candidate_clicked;
}

void initialize(){
    a_logger_log("Abacus engine init...\n");

    //load configuration
    a_configuration_load();

    //
    a_database_init();

    // create property list, and show it
    a_property_list_init();
    a_property_list_load();

    // initialize telex-related objects
    a_z_telex_table_2_init();
    a_ltelex_table_init();
    a_etelex_table_init();
    a_preedit_init();

    // initialize lookup table
    a_candidate_table_init();

    a_candidate_array_init();
    a_hanviet_table_init();
}

void uninitialize(){
    a_logger_log("Abacus engine destroy...\n");

    // destroy property list
    a_property_list_destroy();

    //telex
    a_preedit_destroy();
    a_z_telex_table_2_destroy();
    a_ltelex_table_destroy();
    a_etelex_table_destroy();

    a_candidate_array_destroy();
    a_hanviet_table_destroy();


    // destroy lookup table
    a_candidate_table_destroy();

    //
    a_database_destroy();
}

static void ibus_abacus_engine_init(IBusAbacusEngine *abacus){
    initialize();
}

static void ibus_abacus_engine_destroy(IBusAbacusEngine *abacus){
    uninitialize();
    ((IBusObjectClass *) ibus_abacus_engine_parent_class)->destroy((IBusObject *) abacus);
}

static void ibus_abacus_engine_focus_out(IBusEngine *engine){
    a_helper_clear_preedit((IBusAbacusEngine *) engine);
}

static void ibus_abacus_engine_focus_in(IBusEngine *engine){
    a_logger_log("Abacus received focus_in event");
    a_logger_backup();
    a_property_list_register((IBusAbacusEngine *) engine);
}

static void ibus_abacus_engine_page_up(IBusEngine *engine){
    a_logger_log("ibus_abacus_engine_page_up");
    if(a_candidate_table_showing()){
        a_candidate_table_page_up((IBusAbacusEngine *) engine);
    }
}

static void ibus_abacus_engine_page_down(IBusEngine *engine){
    a_logger_log("ibus_abacus_engine_page_down");
    if(a_candidate_table_showing()){
        a_candidate_table_page_down((IBusAbacusEngine *) engine);
    }
}

static void ibus_abacus_engine_cursor_up(IBusEngine *engine){
    a_logger_log("ibus_abacus_engine_cursor_up");
    if(a_candidate_table_showing()){
        a_candidate_table_cursor_up((IBusAbacusEngine *) engine);
    }
}

static void ibus_abacus_engine_cursor_down(IBusEngine *engine){
    a_logger_log("ibus_abacus_engine_cursor_down");
    if(a_candidate_table_showing()){
        a_candidate_table_cursor_down((IBusAbacusEngine *) engine);
    }
}

// processing when a candidate is selected using mouse
static void ibus_abacus_engine_candidate_clicked(IBusEngine *engine, guint index, guint button, guint state){
    a_helper_commit_candidate_in_page((IBusAbacusEngine *) engine, index);
}

static void property_activated(IBusEngine *engine, const gchar *property_ten, guint property_status){
    a_logger_log("Property %s changed to %d", property_ten, property_status);
    if(g_strcmp0(property_ten, __A_VIETNAMESE_MODE_VALUE__)==0){
        if(property_status==PROP_STATE_CHECKED){
            a_configuration_set_selected_mode(__A_VIETNAMESE_MODE_2__);
            a_property_list_update_symbol((IBusAbacusEngine *) engine);
            a_configuration_save();
        }
    }else if(g_strcmp0(property_ten, __A_HANVIET_MODE_VALUE__)==0){
        if(property_status==PROP_STATE_CHECKED){
            a_configuration_set_selected_mode(__A_HANVIET_MODE_2__);
            a_property_list_update_symbol((IBusAbacusEngine *) engine);
            a_configuration_save();
        }
    }else if(g_strcmp0(property_ten, __A_TEOCHEW_MODE_VALUE__)==0){
        if(property_status==PROP_STATE_CHECKED){
            a_configuration_set_selected_mode(__A_TEOCHEW_MODE_2__);
            a_property_list_update_symbol((IBusAbacusEngine *) engine);
            a_configuration_save();
        }
    }else if(g_strcmp0(property_ten, __A_CHINESE_MODE_VALUE__)==0){
        if(property_status==PROP_STATE_CHECKED){
            a_configuration_set_selected_mode(__A_CHINESE_MODE_2__);
            a_property_list_update_symbol((IBusAbacusEngine *) engine);
            a_configuration_save();
        }
    }else if(g_strcmp0(property_ten, __A_ENGLISH_MODE_VALUE__)==0){
        if(property_status==PROP_STATE_CHECKED){
            a_configuration_set_selected_mode(__A_ENGLISH_MODE_2__);
            a_property_list_update_symbol((IBusAbacusEngine *) engine);
            a_configuration_save();
        }
    }else if(g_strcmp0(property_ten, __A_REMEMBER_MODE_VALUE__)==0){
        a_configuration_set_remembering_mode(property_status);
        a_configuration_save();
    }else if(g_strcmp0(property_ten, __A_AUTO_SHOW_CANDIDATE_TABLE_VALUE__)==0){
        a_configuration_set_auto_show_candidate_table(property_status);
        a_configuration_save();
    }
}

static gboolean deliver_key(IBusAbacusEngine *abacus, guint keyval, guint keycode, guint modifiers){
    //
    gint current_mode=a_configuration_get_current_mode();
    switch(current_mode){
        case __A_ENGLISH_MODE_2__:
            return a_english_mode_process_key_event(abacus, keyval, keycode, modifiers);
        case __A_VIETNAMESE_MODE_2__:
            return a_vietnamese_mode_process_key_event(abacus, keyval, keycode, modifiers);
        case __A_HANVIET_MODE_2__:
            return a_hanviet_mode_process_key_event(abacus, keyval, keycode, modifiers);
        case __A_TEOCHEW_MODE_2__:
            return a_teochew_mode_process_key_event(abacus, keyval, keycode, modifiers);
        case __A_CHINESE_MODE_2__:
            return a_chinese_mode_process_key_event(abacus, keyval, keycode, modifiers);
        default:
            return FALSE;
    }
}

static gboolean manage_mode(IBusAbacusEngine *abacus, guint keyval, guint keycode, guint modifiers){


    gint current_mode=a_configuration_get_current_mode(); //current mode
    guint mode_vietnamese_key=(guint) a_configuration_get_vietnamese_mode_key();
    guint hanviet_mode_key=(guint) a_configuration_get_hanviet_mode_key();
    guint teochew_mode_key=(guint) a_configuration_get_teochew_mode_key();
    guint chinese_mode_key=(guint) a_configuration_get_chinese_mode_key();
    guint english_mode_key=(guint) a_configuration_get_english_mode_key();

    // vietnamese mode
    if((a_helper_is_control_pressed(modifiers))&&(keyval==mode_vietnamese_key)){
        if(current_mode==__A_VIETNAMESE_MODE_2__){
            return TRUE;
        }
        a_configuration_set_selected_mode(__A_VIETNAMESE_MODE_2__);
        a_property_list_update(abacus);
        a_configuration_save();
        a_helper_clear_preedit(abacus);
        return TRUE;
    }

    // Han Viet mode
    if((a_helper_is_control_pressed(modifiers))&&(keyval==hanviet_mode_key)){
        if(current_mode==__A_HANVIET_MODE_2__){
            return TRUE;
        }
        a_configuration_set_selected_mode(__A_HANVIET_MODE_2__);
        a_property_list_update(abacus);
        a_configuration_save();
        a_helper_clear_preedit(abacus);
        return TRUE;
    }

    // teochew mode
    if((a_helper_is_control_pressed(modifiers))&&(keyval==teochew_mode_key)){
        if(current_mode==__A_TEOCHEW_MODE_2__){
            return TRUE;
        }
        a_configuration_set_selected_mode(__A_TEOCHEW_MODE_2__);
        a_property_list_update(abacus);
        a_configuration_save();
        a_helper_clear_preedit(abacus);
        return TRUE;
    }

    // chinese mode
    if((a_helper_is_control_pressed(modifiers))&&(keyval==chinese_mode_key)){
        if(current_mode==__A_CHINESE_MODE_2__){
            return TRUE;
        }
        a_configuration_set_selected_mode(__A_CHINESE_MODE_2__);
        a_property_list_update(abacus);
        a_configuration_save();
        a_helper_clear_preedit(abacus);
        return TRUE;
    }

    // english mode
    if((a_helper_is_control_pressed(modifiers))&&(keyval==english_mode_key)){
        if(current_mode==__A_ENGLISH_MODE_2__){
            return TRUE;
        }
        a_configuration_set_selected_mode(__A_ENGLISH_MODE_2__);
        a_property_list_update(abacus);
        a_configuration_save();
        a_helper_clear_preedit(abacus);
        return TRUE;
    }

    //
    if(keyval==IBUS_KEY_Control_L||keyval==IBUS_KEY_Control_R){
        a_interchange_mode_save_begin_interchange_mode_time();
        return FALSE;
    }

    //
    if(keyval==IBUS_KEY_Shift_L){
        a_interchange_mode_save_begin_interchange_mode_time();
        return FALSE;
    }

    //
    if(a_interchange_mode_is_in_interchange_mode()){
        a_interchange_mode_turn_shift_pressed_off();
        a_logger_log("Leave interchange mode");
    }
    return deliver_key(abacus, keyval, keycode, modifiers);
}


static gboolean ibus_abacus_engine_process_key_event(IBusEngine *engine,guint keyval,guint keycode,guint modifiers){
    //IBusText *text;
    IBusAbacusEngine *abacus=(IBusAbacusEngine *) engine;

    //
    if(a_interchange_mode_is_in_interchange_mode()){
        if(a_helper_is_event_released(modifiers)){
            return FALSE;
        }
        return manage_mode(abacus, keyval, keycode, modifiers);
    }

    //
    if(keyval==IBUS_KEY_Shift_L){
        if(a_helper_is_event_released(modifiers)){
            if(!a_interchange_mode_is_shift_pressed_on()){
                return FALSE;
            }
            a_logger_log("Enter interchange mode");
            a_interchange_mode_save_begin_interchange_mode_time();
            return FALSE;
        }else{
            a_logger_log("Left Shift pressed");
            a_interchange_mode_turn_shift_pressed_on();
            return FALSE;
        }
    }

    //
    if(a_interchange_mode_is_in_interchange_mode()){
        a_logger_log("Leave interchange mode");
        a_interchange_mode_turn_shift_pressed_off();
    }
    return deliver_key(abacus, keyval, keycode, modifiers);

}
