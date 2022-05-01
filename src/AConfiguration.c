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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <glib/gprintf.h>

#include "AConfiguration.h"
#include "ALogger.h"

#define __CONFIG_FILE__ "Abacus.conf"

GKeyFile* a_key_file = NULL;
gint a_default_mode = 1;
gint a_selected_mode = 1;
gboolean a_remember_mode = TRUE;
gint a_super_key = 1;
gint a_vietnamese_mode_shortkey = 1;
gint a_hanviet_mode_shortkey = 2;
gint a_teochew_mode_shortkey = 3;
gint a_chinese_mode_shortkey = 4;
gint a_english_mode_shortkey = 7;
gint a_candidate_table_shortkey = 5;
gint a_auto_show_candidate_table = TRUE;
gint a_chinese_form = 2;
gint a_current_mode = 0;

// check if the configuration file exists in the user configuration directory
gboolean a_is_config_file_existing();

// copy the original configuration file to the user configuration diectory
gboolean a_copy_config_file();

// load user configuration file
gboolean a_load_config_file();


gchar a_buffer[1022];


// check if the configuration file exists in the user configuration directory
gboolean a_is_config_file_existing(){
    const gchar *user_dir = g_get_home_dir();
    gint len = g_sprintf(a_buffer, "%s/%s/%s", user_dir, __ABACUS_DIRECTORY__, __CONFIG_FILE__);
    const gchar *config_file = a_buffer;
    if(g_file_test(config_file, G_FILE_TEST_EXISTS)){
        a_logger_log("Configuration file exists");
        return TRUE;
    }else{
        a_logger_log("Configuration file does not exist");
        return FALSE;
    }
}

gboolean a_copy_config_file(){
    const gchar *user_dir = g_get_home_dir();

    // if configuration directory does not exists, create it
    gint len = g_sprintf(a_buffer, "%s/%s", user_dir, __ABACUS_DIRECTORY__);
    const gchar *config_dir = a_buffer;
    if(!g_file_test(config_dir, G_FILE_TEST_EXISTS)){
         g_mkdir(config_dir, 0744);
        a_logger_log("Created configuration directory");
    }

    // create configuration file
    len = g_sprintf(a_buffer, "%s/%s/%s", user_dir, __ABACUS_DIRECTORY__, __CONFIG_FILE__);
    const gchar *config_file = a_buffer;
    GIOChannel *config_channel = g_io_channel_new_file(config_file, "w", NULL);

    //
    if (!config_channel) {
        a_logger_error("Can't copy configuration file");
    	return FALSE;
    }

	// get content of original configuration file
	gchar *config_file_content = NULL;
	gsize content_len = 0;
	len = g_sprintf(a_buffer, "%s/config/%s", PKGDATADIR, __CONFIG_FILE__);
	const gchar *original_file = a_buffer;
	g_file_get_contents(original_file, &config_file_content, &content_len, NULL);
    a_logger_log("Read original configuration file");

	// put the content into the newly configuration file
	g_io_channel_write_chars(config_channel, config_file_content, content_len, NULL, NULL);
	g_io_channel_shutdown(config_channel, TRUE, NULL);
	g_io_channel_unref(config_channel);
	g_free(config_file_content);
    a_logger_log("Configuration file copied");
	return TRUE;
}


gboolean a_load_config_file(){
	//
	if (a_key_file) {
		return TRUE;
	}

	//
	a_key_file = g_key_file_new();
	if (!a_key_file) {
        a_logger_log("Can't create key file object");
		return FALSE;
	}

	// calculate path to the configuration file
	const gchar *user_dir = g_get_home_dir();
	gint len = g_sprintf(a_buffer, "%s/%s/%s", user_dir, __ABACUS_DIRECTORY__, __CONFIG_FILE__);
	const gchar *config_file = a_buffer;
	GError *error = NULL;
	if (!g_key_file_load_from_file(a_key_file, config_file, G_KEY_FILE_KEEP_COMMENTS , &error)) {
		if (error) {
            a_logger_error("Loading configuration file failed: %s", error->message);
		}
		g_error_free(error);
		return FALSE;
	}

	//
	const gchar *group = "abacus";
	if ((a_default_mode = g_key_file_get_integer(a_key_file, group, "a_default_mode", &error))==0) {
        a_logger_error("Loading a_default_mode failed: %s", error->message);
		g_error_free(error);
	}

	if ((a_selected_mode = g_key_file_get_integer(a_key_file, group, "a_selected_mode", &error))==0) {
        a_logger_error("Loading a_selected_mode failed: %s", error->message);
		g_error_free(error);
	}

	if ((a_remember_mode = g_key_file_get_boolean(a_key_file, group, "a_remember_mode", &error))==0) {
        a_logger_error("Loading a_remember_mode failed: %s", error->message);
		g_error_free(error);
	}

	if ((a_super_key = g_key_file_get_integer(a_key_file, group, "a_super_key", &error))==0) {
        a_logger_error("Loading a_super_key failed: %s", error->message);
		g_error_free(error);
	}

	if ((a_vietnamese_mode_shortkey = g_key_file_get_integer(a_key_file, group, "a_vietnamese_mode_shortkey", &error))==0) {
        a_logger_error("Loading a_vietnamese_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((a_hanviet_mode_shortkey = g_key_file_get_integer(a_key_file, group, "a_hanviet_mode_shortkey", &error))==0) {
        a_logger_error("Loading a_hanviet_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((a_teochew_mode_shortkey = g_key_file_get_integer(a_key_file, group, "a_teochew_mode_shortkey", &error))==0) {
        a_logger_error("Loading a_teochew_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((a_chinese_mode_shortkey = g_key_file_get_integer(a_key_file, group, "a_chinese_mode_shortkey", &error))==0) {
        a_logger_error("Loading a_chinese_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((a_english_mode_shortkey = g_key_file_get_integer(a_key_file, group, "a_english_mode_shortkey", &error))==0) {
        a_logger_error("Loading a_english_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((a_candidate_table_shortkey = g_key_file_get_integer(a_key_file, group, "a_candidate_table_shortkey", &error))==0) {
        a_logger_error("Loading a_english_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((a_auto_show_candidate_table = g_key_file_get_boolean(a_key_file, group, "a_auto_show_candidate_table", &error))==0) {
        a_logger_error("Loading a_auto_show_candidate_table failed: %s", error->message);
		g_error_free(error);
	}


	if ((a_chinese_form = g_key_file_get_integer(a_key_file, group, "a_chinese_form", &error))==0) {
        a_logger_error("Loading a_chinese_form failed: %s", error->message);
		g_error_free(error);
	}

	// calculate current mode
	if (a_remember_mode) {
        a_current_mode = a_selected_mode;
	} else {
        a_current_mode = a_default_mode;
	}

    a_logger_log("Configuration file loaded");
	return TRUE;

}

// load configuration
gboolean a_configuration_load(){
	if (a_key_file) {
		return TRUE;
	}

	//
	if (!a_is_config_file_existing()) {
		if (!a_copy_config_file()) {
			return FALSE;
		}
	}

	//
   return a_load_config_file();
}

// save configuration
void a_configuration_save(){
	if (!a_key_file) {
		return;
	}

	//
	const gchar *group = "abacus";
	g_key_file_set_integer(a_key_file, group, "a_default_mode", a_default_mode);
	g_key_file_set_integer(a_key_file, group, "a_selected_mode", a_selected_mode);
	g_key_file_set_boolean(a_key_file, group, "a_remember_mode", a_remember_mode);
	g_key_file_set_integer(a_key_file, group, "a_super_key", a_super_key);
	g_key_file_set_integer(a_key_file, group, "a_vietnamese_mode_shortkey", a_vietnamese_mode_shortkey);
	g_key_file_set_integer(a_key_file, group, "a_hanviet_mode_shortkey", a_hanviet_mode_shortkey);
	g_key_file_set_integer(a_key_file, group, "a_teochew_mode_shortkey", a_teochew_mode_shortkey);
	g_key_file_set_integer(a_key_file, group, "a_chinese_mode_shortkey", a_chinese_mode_shortkey);
	g_key_file_set_integer(a_key_file, group, "a_english_mode_shortkey", a_english_mode_shortkey);
	g_key_file_set_integer(a_key_file, group, "a_candidate_table_shortkey", a_candidate_table_shortkey);
	g_key_file_set_boolean(a_key_file, group, "a_auto_show_candidate_table", a_auto_show_candidate_table);
	g_key_file_set_integer(a_key_file, group, "a_chinese_form", a_chinese_form);

	//
	const gchar *user_dir = g_get_home_dir();
	gint len = g_sprintf(a_buffer, "%s/%s/%s", user_dir, __ABACUS_DIRECTORY__, __CONFIG_FILE__);
	const gchar *config_file = a_buffer;
	GError *error = NULL;
	if (!g_key_file_save_to_file(a_key_file, config_file, &error)) {
        a_logger_error("Saving configuration failed");
	} else {
        a_logger_log("Configuration saved");
	}

}

void a_configuration_destroy() {
	if (!a_key_file) {
		return;
	}
	g_key_file_free(a_key_file);
    a_key_file = NULL;
}

// get default mode
gint a_configuration_get_default_mode(){
	return a_default_mode;
}


// set default mode
void a_configuration_set_default_mode(_MODE mode){
    a_default_mode = (gint)mode;
}

// get selected mode
gint a_configuration_get_selected_mode(){
	return a_selected_mode;
}

// set selected mode
void a_configuration_set_selected_mode(_MODE mode){
    a_selected_mode = (gint)mode;
    a_current_mode = a_selected_mode;
    a_logger_log("Changed to mode %d", a_current_mode);
}

// get remembering mode
gboolean a_configuration_get_remembering_mode(){
	return a_remember_mode;
}

// set remembering mode
void a_configuration_set_remembering_mode(gboolean remember_mode){
    a_remember_mode = remember_mode;
}

gint a_configuration_get_super_key() {
	return a_super_key;
}

void vh_configuration_set_super_key(_SUPER_KEY key) {
    a_super_key = (gint)key;
}

gint a_configuration_get_vietnamese_mode_key() {
	return a_vietnamese_mode_shortkey;
}
void vh_configuration_set_vietnamese_mode_key(gint key) {
    a_vietnamese_mode_shortkey = key;
}

gint a_configuration_get_hanviet_mode_key() {
	return a_hanviet_mode_shortkey;
}
void vh_configuration_set_viethoa_mode_key(gint key) {
    a_hanviet_mode_shortkey = key;
}

gint a_configuration_get_teochew_mode_key() {
	return a_teochew_mode_shortkey;
}
void vh_configuration_set_teochew_mode_key(gint key) {
    a_teochew_mode_shortkey = key;
}

gint a_configuration_get_chinese_mode_key() {
	return a_chinese_mode_shortkey;
}
void vh_configuration_set_chinese_mode_key(gint key) {
    a_chinese_mode_shortkey = key;
}

gint a_configuration_get_english_mode_key() {
	return a_english_mode_shortkey;
}
void a_configuration_set_english_mode_key(gint key) {
    a_english_mode_shortkey = key;
}

gint a_configuration_get_candidate_table_key() {
	return a_candidate_table_shortkey;
}
void a_configuration_set_candidate_table_key(gint key) {
    a_candidate_table_shortkey = key;
}

gboolean a_configuration_get_auto_show_candidate_table(){
	return a_auto_show_candidate_table;
}

// set remembering mode
void a_configuration_set_auto_show_candidate_table(gboolean show){
    a_auto_show_candidate_table = show;
}

gint a_configuration_get_chinese_form() {
	return a_chinese_form;
}
void a_configuration_set_chinese_form(gint form) {
    a_chinese_form = form;
}

gint a_configuration_get_current_mode () {
	return a_current_mode;
}
