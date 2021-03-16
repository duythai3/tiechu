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

#include "VHConfiguration.h"
#include "VHLogger.h"

#define __CONFIG_FILE__ "ibus_viethoa.conf"

GKeyFile* _key_file = NULL;
gint _default_mode = 1;
gint _selected_mode = 1;
gboolean _remember_mode = TRUE;
gint _super_key = 1;
gint _vietnamese_mode_shortkey = 1;
gint _viethoa_mode_shortkey = 2;
gint _teochew_mode_shortkey = 3;
gint _chinese_mode_shortkey = 4;
gint _english_mode_shortkey = 7;
gint _candidate_table_shortkey = 5;
gint _auto_show_candidate_table = TRUE;
gint _chinese_form = 2;
gint _current_mode = 0;

// check if the configuration file exists in the user configuration directory
gboolean __is_config_file_existing();

// copy the original configuration file to the user configuration diectory
gboolean __copy_config_file();

// load user configuration file  
gboolean __load_config_file();


gchar _buffer[1022];


// check if the configuration file exists in the user configuration directory
gboolean __is_config_file_existing(){
    const gchar *user_dir = g_get_home_dir();
    gint len = g_sprintf(_buffer, "%s/%s/%s", user_dir, __VIETHOA_DIRECTORY__, __CONFIG_FILE__);
    const gchar *config_file = _buffer;
    if(g_file_test(config_file, G_FILE_TEST_EXISTS)){
        vh_logger_log("Configuration file exists");
        return TRUE;
    }else{
        vh_logger_log("Configuration file does not exist");
        return FALSE;
    }
}

gboolean __copy_config_file(){
    const gchar *user_dir = g_get_home_dir();

    // if configuration directory does not exists, create it
    gint len = g_sprintf(_buffer, "%s/%s", user_dir, __VIETHOA_DIRECTORY__);
    const gchar *config_dir = _buffer;
    if(!g_file_test(config_dir, G_FILE_TEST_EXISTS)){
         g_mkdir(config_dir, 0744);
         vh_logger_log("Created configuration directory");
    }

    // create configuration file
    len = g_sprintf(_buffer, "%s/%s/%s", user_dir, __VIETHOA_DIRECTORY__, __CONFIG_FILE__);
    const gchar *config_file = _buffer;
    GIOChannel *config_channel = g_io_channel_new_file(config_file, "w", NULL);
    
    //
    if (!config_channel) {
		vh_logger_error("Can't copy configuration file");
    	return FALSE;
    }
    
	// get content of original configuration file
	gchar *config_file_content = NULL;
	gsize content_len = 0;
	len = g_sprintf(_buffer, "%s/config/%s", PKGDATADIR, __CONFIG_FILE__);
	const gchar *original_file = _buffer;
	g_file_get_contents(original_file, &config_file_content, &content_len, NULL);
	vh_logger_log("Read original configuration file");

	// put the content into the newly configuration file
	g_io_channel_write_chars(config_channel, config_file_content, content_len, NULL, NULL);
	g_io_channel_shutdown(config_channel, TRUE, NULL);
	g_io_channel_unref(config_channel);
	g_free(config_file_content);
	vh_logger_log("Configuration file copied");
	return TRUE;
}


gboolean __load_config_file(){
	//
	if (_key_file) {
		return TRUE;
	}

	//
	_key_file = g_key_file_new();
	if (!_key_file) {
		vh_logger_log("Can't create key file object");
		return FALSE;
	}

	// calculate path to the configuration file
	const gchar *user_dir = g_get_home_dir();
	gint len = g_sprintf(_buffer, "%s/%s/%s", user_dir, __VIETHOA_DIRECTORY__, __CONFIG_FILE__);
	const gchar *config_file = _buffer;
	GError *error = NULL;
	if (!g_key_file_load_from_file(_key_file, config_file, G_KEY_FILE_KEEP_COMMENTS , &error)) {
		if (error) {
			vh_logger_error("Loading configuration file failed: %s", error->message);
		}
		g_error_free(error);
		return FALSE;
	}

	//
	const gchar *group = "viethoa";
	if ((_default_mode = g_key_file_get_integer(_key_file, group, "_default_mode", &error)) == 0) {
		vh_logger_error("Loading _default_mode failed: %s", error->message);
		g_error_free(error);
	}

	if ((_selected_mode = g_key_file_get_integer(_key_file, group, "_selected_mode", &error)) == 0) {
		vh_logger_error("Loading _selected_mode failed: %s", error->message);
		g_error_free(error);
	}

	if ((_remember_mode = g_key_file_get_boolean(_key_file, group, "_remember_mode", &error)) == 0) {
		vh_logger_error("Loading _remember_mode failed: %s", error->message);
		g_error_free(error);
	}

	if ((_super_key = g_key_file_get_integer(_key_file, group, "_super_key", &error)) == 0) {
		vh_logger_error("Loading _super_key failed: %s", error->message);
		g_error_free(error);
	}

	if ((_vietnamese_mode_shortkey = g_key_file_get_integer(_key_file, group, "_vietnamese_mode_shortkey", &error)) == 0) {
		vh_logger_error("Loading _vietnamese_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((_viethoa_mode_shortkey = g_key_file_get_integer(_key_file, group, "_viethoa_mode_shortkey", &error)) == 0) {
		vh_logger_error("Loading _viethoa_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((_teochew_mode_shortkey = g_key_file_get_integer(_key_file, group, "_teochew_mode_shortkey", &error)) == 0) {
		vh_logger_error("Loading _teochew_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((_chinese_mode_shortkey = g_key_file_get_integer(_key_file, group, "_chinese_mode_shortkey", &error)) == 0) {
		vh_logger_error("Loading _chinese_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((_english_mode_shortkey = g_key_file_get_integer(_key_file, group, "_english_mode_shortkey", &error)) == 0) {
		vh_logger_error("Loading _english_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((_candidate_table_shortkey = g_key_file_get_integer(_key_file, group, "_candidate_table_shortkey", &error)) == 0) {
		vh_logger_error("Loading _english_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((_auto_show_candidate_table = g_key_file_get_boolean(_key_file, group, "_auto_show_candidate_table", &error)) == 0) {
		vh_logger_error("Loading _auto_show_candidate_table failed: %s", error->message);
		g_error_free(error);
	}


	if ((_chinese_form = g_key_file_get_integer(_key_file, group, "_chinese_form", &error)) == 0) {
		vh_logger_error("Loading _chinese_form failed: %s", error->message);
		g_error_free(error);
	}

	// calculate current mode
	if (_remember_mode) {
		_current_mode = _selected_mode;
	} else {
		_current_mode = _default_mode;
	}

	vh_logger_log("Configuration file loaded");
	return TRUE;

}

// load configuration
gboolean vh_configuration_load(){
	if (_key_file) {
		return TRUE;
	}

	//
	if (!__is_config_file_existing()) {
		if (!__copy_config_file()) {
			return FALSE;
		}
	}

	//
   return __load_config_file();
}

// save configuration
void vh_configuration_save(){
	if (!_key_file) {
		return;
	}

	//
	const gchar *group = "viethoa";
	g_key_file_set_integer(_key_file, group, "_default_mode", _default_mode);
	g_key_file_set_integer(_key_file, group, "_selected_mode", _selected_mode);
	g_key_file_set_boolean(_key_file, group, "_remember_mode", _remember_mode);
	g_key_file_set_integer(_key_file, group, "_super_key", _super_key);
	g_key_file_set_integer(_key_file, group, "_vietnamese_mode_shortkey", _vietnamese_mode_shortkey);
	g_key_file_set_integer(_key_file, group, "_viethoa_mode_shortkey", _viethoa_mode_shortkey);
	g_key_file_set_integer(_key_file, group, "_teochew_mode_shortkey", _teochew_mode_shortkey);
	g_key_file_set_integer(_key_file, group, "_chinese_mode_shortkey", _chinese_mode_shortkey);
	g_key_file_set_integer(_key_file, group, "_english_mode_shortkey", _english_mode_shortkey);
	g_key_file_set_integer(_key_file, group, "_candidate_table_shortkey", _candidate_table_shortkey);
	g_key_file_set_boolean(_key_file, group, "_auto_show_candidate_table", _auto_show_candidate_table);
	g_key_file_set_integer(_key_file, group, "_chinese_form", _chinese_form);

	//
	const gchar *user_dir = g_get_home_dir();
	gint len = g_sprintf(_buffer, "%s/%s/%s", user_dir, __VIETHOA_DIRECTORY__, __CONFIG_FILE__);
	const gchar *config_file = _buffer;
	GError *error = NULL;
	if (!g_key_file_save_to_file(_key_file, config_file, &error)) {
		vh_logger_error("Saving configuration failed");
	} else {
		vh_logger_log("Configuration saved");
	}

}

void vh_configuration_destroy() {
	if (!_key_file) {
		return;
	}
	g_key_file_free(_key_file);
	_key_file = NULL;
}

// get default mode
gint vh_configuration_get_default_mode(){
	return _default_mode;
}


// set default mode
void vh_configuration_set_default_mode(_MODE mode){
	_default_mode = (gint)mode;
}

// get selected mode
gint vh_configuration_get_selected_mode(){
	return _selected_mode;
}

// set selected mode
void vh_configuration_set_selected_mode(_MODE mode){
	_selected_mode = (gint)mode;
	_current_mode = _selected_mode;
	vh_logger_log("Changed to mode %d", _current_mode);
}

// get remembering mode
gboolean vh_configuration_get_remembering_mode(){
	return _remember_mode;
}

// set remembering mode
void vh_configuration_set_remembering_mode(gboolean remember_mode){
	_remember_mode = remember_mode;
}

gint vh_configuration_get_super_key() {
	return _super_key;
}

void vh_configuration_set_super_key(_SUPER_KEY key) {
	_super_key = (gint)key;
}

gint vh_configuration_get_vietnamese_mode_key() {
	return _vietnamese_mode_shortkey;
}
void vh_configuration_set_vietnamese_mode_key(gint key) {
	_vietnamese_mode_shortkey = key;
}

gint vh_configuration_get_viethoa_mode_key() {
	return _viethoa_mode_shortkey;
}
void vh_configuration_set_viethoa_mode_key(gint key) {
	_viethoa_mode_shortkey = key;
}

gint vh_configuration_get_teochew_mode_key() {
	return _teochew_mode_shortkey;
}
void vh_configuration_set_teochew_mode_key(gint key) {
	_teochew_mode_shortkey = key;
}

gint vh_configuration_get_chinese_mode_key() {
	return _chinese_mode_shortkey;
}
void vh_configuration_set_chinese_mode_key(gint key) {
	_chinese_mode_shortkey = key;
}

gint vh_configuration_get_english_mode_key() {
	return _english_mode_shortkey;
}
void vh_configuration_set_english_mode_key(gint key) {
	_english_mode_shortkey = key;
}

gint vh_configuration_get_candidate_table_key() {
	return _candidate_table_shortkey;
}
void vh_configuration_set_candidate_table_key(gint key) {
	_candidate_table_shortkey = key;
}

gboolean vh_configuration_get_auto_show_candidate_table(){
	return _auto_show_candidate_table;
}

// set remembering mode
void vh_configuration_set_auto_show_candidate_table(gboolean show){
	_auto_show_candidate_table = show;
}

gint vh_configuration_get_chinese_form() {
	return _chinese_form;
}
void vh_configuration_set_chinese_form(gint form) {
	_chinese_form = form;
}

gint vh_configuration_get_current_mode () {
	return _current_mode;
}
