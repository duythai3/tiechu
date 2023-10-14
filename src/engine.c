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

#include "ZTelexTable2.h"
#include "engine.h"
#include "CandidateArray.h"
#include "Logger.h"
#include "CandidateTable.h"
#include "HanvietTable.h"
#include "TelexEditor.h"
#include "Configuration.h"
#include "PropertyList.h"
#include "EnglishMode.h"
#include "VietnameseMode.h"
#include "HanvietMode.h"
#include "TeochewMode.h"
#include "ChineseMode.h"
#include "Database.h"
#include "Helper.h"
#include "Preedit.h"
#include "LTelexTable.h"
#include "ETelexTable.h"
#include "InterchangeMode.h"


/* functions prototype */
static void ibus_tiechu_engine_class_init(IBusTiechuEngineClass *klass);

static void ibus_tiechu_engine_init(IBusTiechuEngine *tiechu);

static void ibus_tiechu_engine_destroy(IBusTiechuEngine *tiechu);

static gboolean ibus_tiechu_engine_process_key_event(IBusEngine *engine, guint keyval, guint keycode, guint modifiers);

static void ibus_tiechu_engine_focus_in(IBusEngine *engine);

static void ibus_tiechu_engine_focus_out(IBusEngine *engine);

//static void ibus_tiechu_engine_reset(IBusEngine *engine);
static void ibus_tiechu_engine_enable(IBusEngine *engine);

static void ibus_tiechu_engine_disable(IBusEngine *engine);

static void ibus_engine_set_cursor_location(IBusEngine *engine, gint x, gint y, gint w, gint h);

static void ibus_tiechu_engine_set_capabilities(IBusEngine *engine, guint caps);

static void ibus_tiechu_engine_page_up(IBusEngine *engine);

static void ibus_tiechu_engine_page_down(IBusEngine *engine);

static void ibus_tiechu_engine_cursor_up(IBusEngine *engine);

static void ibus_tiechu_engine_cursor_down(IBusEngine *engine);

static void ibus_tiechu_engine_candidate_clicked(IBusEngine *engine, guint index, guint button, guint state);

static void ibus_tiechu_property_activate(IBusEngine *engine, const gchar *prop_name, gint prop_state);

static void ibus_tiechu_engine_property_show(IBusEngine *engine, const gchar *prop_name);

static void ibus_tiechu_engine_property_hide(IBusEngine *engine, const gchar *prop_name);

static void ibus_tiechu_engine_commit_string(IBusTiechuEngine *tiechu, const gchar *string);

//
static void property_activated(IBusEngine *engine, const gchar *property_ten, guint property_status);

G_DEFINE_TYPE (IBusTiechuEngine, ibus_tiechu_engine, IBUS_TYPE_ENGINE)

//

static void ibus_tiechu_engine_class_init(IBusTiechuEngineClass *klass){
    logger_log("engine class init...\n");
    IBusObjectClass *ibus_object_class=IBUS_OBJECT_CLASS (klass);
    IBusEngineClass *engine_class=IBUS_ENGINE_CLASS (klass);

    //
    ibus_object_class->destroy=(IBusObjectDestroyFunc) ibus_tiechu_engine_destroy;
    engine_class->process_key_event=ibus_tiechu_engine_process_key_event;
    engine_class->focus_out=ibus_tiechu_engine_focus_out;
    engine_class->focus_in=ibus_tiechu_engine_focus_in;
    engine_class->property_activate=property_activated;

    //
    engine_class->page_up=ibus_tiechu_engine_page_up;
    engine_class->page_down=ibus_tiechu_engine_page_down;

    //
    //engine_class->cursor_up = ibus_tiechu_engine_cursor_up;
    //engine_class->cursor_down = ibus_tiechu_engine_cursor_down;

    //
    engine_class->candidate_clicked=ibus_tiechu_engine_candidate_clicked;
}

void initialize(){
    logger_log("Tiechu engine init...\n");

    //load configuration
    configuration_load();

    //
    database_open();

    // create property list, and show it
    property_list_init();
    property_list_load();

    // initialize telex-related objects
    z_telex_table_2_init();
    ltelex_table_init();
    etelex_table_init();
    preedit_init();

    // initialize lookup table
    candidate_table_init();

    candidate_array_init();
    hanviet_table_init();
}

void uninitialize(){
    logger_log("Tiechu engine destroy...\n");

    // destroy property list
    property_list_destroy();

    //telex
    preedit_destroy();
    z_telex_table_2_destroy();
    ltelex_table_destroy();
    etelex_table_destroy();

    candidate_array_destroy();
    hanviet_table_destroy();


    // destroy lookup table
    candidate_table_destroy();

    //
    database_close();
}

static void ibus_tiechu_engine_init(IBusTiechuEngine *tiechu){
    initialize();
}

static void ibus_tiechu_engine_destroy(IBusTiechuEngine *tiechu){
    uninitialize();
    ((IBusObjectClass *) ibus_tiechu_engine_parent_class)->destroy((IBusObject *) tiechu);
}

static void ibus_tiechu_engine_focus_out(IBusEngine *engine){
    helper_clear_preedit((IBusTiechuEngine *) engine);
}

static void ibus_tiechu_engine_focus_in(IBusEngine *engine){
    logger_log("Tiechu received focus_in event");
    logger_backup();
    property_list_register((IBusTiechuEngine *) engine);
}

static void ibus_tiechu_engine_page_up(IBusEngine *engine){
    logger_log("ibus_tiechu_engine_page_up");
    if(candidate_table_showing()){
        candidate_table_page_up((IBusTiechuEngine *) engine);
    }
}

static void ibus_tiechu_engine_page_down(IBusEngine *engine){
    logger_log("ibus_tiechu_engine_page_down");
    if(candidate_table_showing()){
        candidate_table_page_down((IBusTiechuEngine *) engine);
    }
}

static void ibus_tiechu_engine_cursor_up(IBusEngine *engine){
    logger_log("ibus_tiechu_engine_cursor_up");
    if(candidate_table_showing()){
        candidate_table_cursor_up((IBusTiechuEngine *) engine);
    }
}

static void ibus_tiechu_engine_cursor_down(IBusEngine *engine){
    logger_log("ibus_tiechu_engine_cursor_down");
    if(candidate_table_showing()){
        candidate_table_cursor_down((IBusTiechuEngine *) engine);
    }
}

// processing when a candidate is selected using mouse
static void ibus_tiechu_engine_candidate_clicked(IBusEngine *engine, guint index, guint button, guint state){
    helper_commit_candidate_in_page((IBusTiechuEngine *) engine, index);
}

static void property_activated(IBusEngine *engine, const gchar *property_ten, guint property_status){
    logger_log("Property %s changed to %d", property_ten, property_status);
    if(g_strcmp0(property_ten, TVIETNAMESE_MODE_VALUE) == 0){
        if(property_status==PROP_STATE_CHECKED){
            configuration_set_selected_mode(TVIETNAMESE_MODE);
            property_list_update_symbol((IBusTiechuEngine *) engine);
            configuration_save();
        }
    }else if(g_strcmp0(property_ten, THANVIET_MODE_VALUE) == 0){
        if(property_status==PROP_STATE_CHECKED){
            configuration_set_selected_mode(THANVIET_MODE);
            property_list_update_symbol((IBusTiechuEngine *) engine);
            configuration_save();
        }
    }else if(g_strcmp0(property_ten, TTEOCHEW_MODE_VALUE) == 0){
        if(property_status==PROP_STATE_CHECKED){
            configuration_set_selected_mode(TTEOCHEW_MODE);
            property_list_update_symbol((IBusTiechuEngine *) engine);
            configuration_save();
        }
    }else if(g_strcmp0(property_ten, TCHINESE_MODE_VALUE) == 0){
        if(property_status==PROP_STATE_CHECKED){
            configuration_set_selected_mode(TCHINESE_MODE);
            property_list_update_symbol((IBusTiechuEngine *) engine);
            configuration_save();
        }
    }else if(g_strcmp0(property_ten, TENGLISH_MODE_VALUE) == 0){
        if(property_status==PROP_STATE_CHECKED){
            configuration_set_selected_mode(TENGLISH_MODE);
            property_list_update_symbol((IBusTiechuEngine *) engine);
            configuration_save();
        }
    }else if(g_strcmp0(property_ten, TREMEMBER_MODE_VALUE) == 0){
        configuration_set_remembering_mode(property_status);
        configuration_save();
    }else if(g_strcmp0(property_ten, TAUTO_SHOW_CANDIDATE_TABLE_VALUE) == 0){
        configuration_set_auto_show_candidate_table(property_status);
        configuration_save();
    }
}

static gboolean deliver_key(IBusTiechuEngine *tiechu, guint keyval, guint keycode, guint modifiers){
    //
    gint current_mode=configuration_get_current_mode();
    switch(current_mode){
        case TVIETNAMESE_MODE:
            return vietnamese_mode_process_key_event(tiechu, keyval, keycode, modifiers);
        case TTEOCHEW_MODE:
            return teochew_mode_process_key_event(tiechu, keyval, keycode, modifiers);
        case THANVIET_MODE:
            return hanviet_mode_process_key_event(tiechu, keyval, keycode, modifiers);
        case TCHINESE_MODE:
            return chinese_mode_process_key_event(tiechu, keyval, keycode, modifiers);
        case TENGLISH_MODE:
            return english_mode_process_key_event(tiechu, keyval, keycode, modifiers);
        default:
            return FALSE;
    }
}

static gboolean manage_mode(IBusTiechuEngine *tiechu, guint keyval, guint keycode, guint modifiers){
    gint current_mode=configuration_get_current_mode(); //current mode
    guint mode_vietnamese_key=(guint) configuration_get_vietnamese_mode_key();
    guint teochew_mode_key=(guint) configuration_get_teochew_mode_key();
    guint hanviet_mode_key=(guint) configuration_get_hanviet_mode_key();
    guint chinese_mode_key=(guint) configuration_get_chinese_mode_key();
    guint english_mode_key=(guint) configuration_get_english_mode_key();

    // vietnamese mode
    if((helper_is_control_pressed(modifiers))&&(keyval==mode_vietnamese_key)){
        if(current_mode == TVIETNAMESE_MODE){
            return TRUE;
        }
        configuration_set_selected_mode(TVIETNAMESE_MODE);
        property_list_update(tiechu);
        configuration_save();
        //helper_clear_preedit(tiechu);
        helper_commit_preedit(tiechu);
        return TRUE;
    }

    // Han Viet mode
    if((helper_is_control_pressed(modifiers))&&(keyval==hanviet_mode_key)){
        if(current_mode == THANVIET_MODE){
            return TRUE;
        }
        configuration_set_selected_mode(THANVIET_MODE);
        property_list_update(tiechu);
        configuration_save();
        //helper_clear_preedit(tiechu);
        helper_commit_preedit(tiechu);
        return TRUE;
    }

    // teochew mode
    if((helper_is_control_pressed(modifiers))&&(keyval==teochew_mode_key)){
        if(current_mode == TTEOCHEW_MODE){
            return TRUE;
        }
        configuration_set_selected_mode(TTEOCHEW_MODE);
        property_list_update(tiechu);
        configuration_save();
        //helper_clear_preedit(tiechu);
        helper_commit_preedit(tiechu);
        return TRUE;
    }

    // chinese mode
    if((helper_is_control_pressed(modifiers))&&(keyval==chinese_mode_key)){
        if(current_mode == TCHINESE_MODE){
            return TRUE;
        }
        configuration_set_selected_mode(TCHINESE_MODE);
        property_list_update(tiechu);
        configuration_save();
        //helper_clear_preedit(tiechu);
        helper_commit_preedit(tiechu);
        return TRUE;
    }

    // english mode
    if((helper_is_control_pressed(modifiers))&&(keyval==english_mode_key)){
        if(current_mode == TENGLISH_MODE){
            return TRUE;
        }
        configuration_set_selected_mode(TENGLISH_MODE);
        property_list_update(tiechu);
        configuration_save();
        //helper_clear_preedit(tiechu);
        helper_commit_preedit(tiechu);
        return TRUE;
    }

    //
    if(keyval==IBUS_KEY_Control_L||keyval==IBUS_KEY_Control_R){
        interchange_mode_save_begin_interchange_mode_time();
        return FALSE;
    }

    //
    if(keyval==IBUS_KEY_Shift_L || keyval==IBUS_KEY_Shift_R){
        interchange_mode_save_begin_interchange_mode_time();
        return FALSE;
    }

    //
    if(interchange_mode_is_in_interchange_mode()){
        interchange_mode_turn_shift_pressed_off();
        logger_log("Leave interchange mode");
    }
    return deliver_key(tiechu, keyval, keycode, modifiers);
}


static gboolean ibus_tiechu_engine_process_key_event(IBusEngine *engine,guint keyval,guint keycode,guint modifiers){
    //IBusText *text;
    IBusTiechuEngine *tiechu=(IBusTiechuEngine *) engine;

    //
    if(interchange_mode_is_in_interchange_mode()){
        if(helper_is_event_released(modifiers)){
            return FALSE;
        }
        return manage_mode(tiechu, keyval, keycode, modifiers);
    }

    //
    if(keyval==IBUS_KEY_Shift_L || keyval==IBUS_KEY_Shift_R){
        if(helper_is_event_released(modifiers)){
            if(!interchange_mode_is_shift_pressed_on()){
                return FALSE;
            }
            logger_log("Enter interchange mode");
            interchange_mode_save_begin_interchange_mode_time();
            return FALSE;
        }else{
            logger_log("Left Shift pressed");
            interchange_mode_turn_shift_pressed_on();
            return FALSE;
        }
    }

    //
    if(interchange_mode_is_in_interchange_mode()){
        logger_log("Leave interchange mode");
        interchange_mode_turn_shift_pressed_off();
    }

    //
    if (!helper_is_escape_pressed(keyval)) {
        return deliver_key(tiechu, keyval, keycode, modifiers);
    } else {
        return FALSE;
    }

}
