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
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <glib/gprintf.h>

#include "Configuration.h"
#include "Logger.h"

#define TCONFIG_FILE "Tiechu.conf"

GKeyFile* Tkey_file = NULL;
gint Tdefault_mode = 2;
gint Tselected_mode = 2;
gboolean Tremember_mode = TRUE;
gint Tsuper_key = 3;
gint Tvietnamese_mode_shortkey = 50;
gint Tteochew_mode_shortkey = 51;
gint Thanviet_mode_shortkey = 52;
gint Tchinese_mode_shortkey = 53;
gint Tenglish_mode_shortkey = 55;
gint Tcandidate_table_shortkey = 54;
gint Tauto_show_candidate_table = TRUE;
gint Tchinese_form = 3;
gint Tcurrent_mode = 0;

// check if the configuration file exists in the user configuration directory
gboolean Tis_config_file_existing();

// copy the original configuration file to the user configuration diectory
gboolean Tcopy_config_file();

// load user configuration file
gboolean Tload_config_file();


gchar Tbuffer[993];


// check if the configuration file exists in the user configuration directory
gboolean Tis_config_file_existing(){
    const gchar *user_dir = g_get_home_dir();
    gint len = g_sprintf(Tbuffer, "%s/%s/%s", user_dir, TTIECHU_DIRECTORY, TCONFIG_FILE);
    const gchar *config_file = Tbuffer;
    if(g_file_test(config_file, G_FILE_TEST_EXISTS)){
        logger_log("Configuration file exists");
        return TRUE;
    }else{
        logger_log("Configuration file does not exist");
        return FALSE;
    }
}

gboolean Tcopy_config_file(){
    const gchar *user_dir = g_get_home_dir();

    // if configuration directory does not exists, create it
    gint len = g_sprintf(Tbuffer, "%s/%s", user_dir, TTIECHU_DIRECTORY);
    const gchar *config_dir = Tbuffer;
    if(!g_file_test(config_dir, G_FILE_TEST_EXISTS)){
         g_mkdir(config_dir, 0744);
        logger_log("Created configuration directory");
    }

    // create configuration file
    len = g_sprintf(Tbuffer, "%s/%s/%s", user_dir, TTIECHU_DIRECTORY, TCONFIG_FILE);
    const gchar *config_file = Tbuffer;
    GIOChannel *config_channel = g_io_channel_new_file(config_file, "w", NULL);

    //
    if (!config_channel) {
        logger_error("Can't copy configuration file");
    	return FALSE;
    }

	// get content of original configuration file
	gchar *config_file_content = NULL;
	gsize content_len = 0;
	len = g_sprintf(Tbuffer, "%s/config/%s", PKGDATADIR, TCONFIG_FILE);
	const gchar *original_file = Tbuffer;
	g_file_get_contents(original_file, &config_file_content, &content_len, NULL);
    logger_log("Read original configuration file");

	// put the content into the newly configuration file
	g_io_channel_write_chars(config_channel, config_file_content, content_len, NULL, NULL);
	g_io_channel_shutdown(config_channel, TRUE, NULL);
	g_io_channel_unref(config_channel);
	g_free(config_file_content);
    logger_log("Configuration file copied");
	return TRUE;
}


gboolean Tload_config_file(){
	//
	if (Tkey_file) {
		return TRUE;
	}

	//
	Tkey_file = g_key_file_new();
	if (!Tkey_file) {
        logger_log("Can't create key file object");
		return FALSE;
	}

	// calculate path to the configuration file
	const gchar *user_dir = g_get_home_dir();
    gint len = g_sprintf(Tbuffer, "%s/%s/%s", user_dir, TTIECHU_DIRECTORY, TCONFIG_FILE);
	const gchar *config_file = Tbuffer;
	GError *error = NULL;
	if (!g_key_file_load_from_file(Tkey_file, config_file, G_KEY_FILE_KEEP_COMMENTS , &error)) {
		if (error) {
            logger_error("Loading configuration file failed: %s", error->message);
		}
		g_error_free(error);
		return FALSE;
	}

	//
    const gchar *group = "Tiechu";
	if ((Tdefault_mode = g_key_file_get_integer(Tkey_file, group, "Tdefault_mode", &error)) == 0) {
        logger_error("Loading Tdefault_mode failed: %s", error->message);
		g_error_free(error);
	}

	if ((Tselected_mode = g_key_file_get_integer(Tkey_file, group, "Tselected_mode", &error)) == 0) {
        logger_error("Loading Tselected_mode failed: %s", error->message);
		g_error_free(error);
	}

	if ((Tremember_mode = g_key_file_get_boolean(Tkey_file, group, "Tremember_mode", &error)) == 0) {
        logger_error("Loading Tremember_mode failed: %s", error->message);
		g_error_free(error);
	}

	if ((Tsuper_key = g_key_file_get_integer(Tkey_file, group, "Tsuper_key", &error)) == 0) {
        logger_error("Loading Tsuper_key failed: %s", error->message);
		g_error_free(error);
	}

	if ((Tvietnamese_mode_shortkey = g_key_file_get_integer(Tkey_file, group, "Tvietnamese_mode_shortkey", &error)) == 0) {
        logger_error("Loading Tvietnamese_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

    if ((Tteochew_mode_shortkey = g_key_file_get_integer(Tkey_file, group, "Tteochew_mode_shortkey", &error)) == 0) {
        logger_error("Loading Tteochew_mode_shortkey failed: %s", error->message);
        g_error_free(error);
    }

	if ((Thanviet_mode_shortkey = g_key_file_get_integer(Tkey_file, group, "Thanviet_mode_shortkey", &error)) == 0) {
        logger_error("Loading Thanviet_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((Tchinese_mode_shortkey = g_key_file_get_integer(Tkey_file, group, "Tchinese_mode_shortkey", &error)) == 0) {
        logger_error("Loading Tchinese_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((Tenglish_mode_shortkey = g_key_file_get_integer(Tkey_file, group, "Tenglish_mode_shortkey", &error)) == 0) {
        logger_error("Loading Tenglish_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((Tcandidate_table_shortkey = g_key_file_get_integer(Tkey_file, group, "Tcandidate_table_shortkey", &error)) == 0) {
        logger_error("Loading Tenglish_mode_shortkey failed: %s", error->message);
		g_error_free(error);
	}

	if ((Tauto_show_candidate_table = g_key_file_get_boolean(Tkey_file, group, "Tauto_show_candidate_table", &error)) == 0) {
        logger_error("Loading Tauto_show_candidate_table failed: %s", error->message);
		g_error_free(error);
	}

	if ((Tchinese_form = g_key_file_get_integer(Tkey_file, group, "Tchinese_form", &error)) == 0) {
        logger_error("Loading Tchinese_form failed: %s", error->message);
		g_error_free(error);
	}

	// calculate current mode
	if (Tremember_mode) {
        Tcurrent_mode = Tselected_mode;
	} else {
        Tcurrent_mode = Tdefault_mode;
	}

    logger_log("Configuration file loaded");
	return TRUE;

}

// load configuration
gboolean configuration_load(){
	if (Tkey_file) {
		return TRUE;
	}

	//
	if (!Tis_config_file_existing()) {
		if (!Tcopy_config_file()) {
			return FALSE;
		}
	}

	//
   return Tload_config_file();
}

// save configuration
void configuration_save(){
	if (!Tkey_file) {
		return;
	}

	//
    const gchar *group = "Tiechu";
	g_key_file_set_integer(Tkey_file, group, "Tdefault_mode", Tdefault_mode);
	g_key_file_set_integer(Tkey_file, group, "Tselected_mode", Tselected_mode);
	g_key_file_set_boolean(Tkey_file, group, "Tremember_mode", Tremember_mode);
	g_key_file_set_integer(Tkey_file, group, "Tsuper_key", Tsuper_key);
	g_key_file_set_integer(Tkey_file, group, "Tvietnamese_mode_shortkey", Tvietnamese_mode_shortkey);
    g_key_file_set_integer(Tkey_file, group, "Tteochew_mode_shortkey", Tteochew_mode_shortkey);
	g_key_file_set_integer(Tkey_file, group, "Thanviet_mode_shortkey", Thanviet_mode_shortkey);
	g_key_file_set_integer(Tkey_file, group, "Tchinese_mode_shortkey", Tchinese_mode_shortkey);
	g_key_file_set_integer(Tkey_file, group, "Tenglish_mode_shortkey", Tenglish_mode_shortkey);
	g_key_file_set_integer(Tkey_file, group, "Tcandidate_table_shortkey", Tcandidate_table_shortkey);
	g_key_file_set_boolean(Tkey_file, group, "Tauto_show_candidate_table", Tauto_show_candidate_table);
	g_key_file_set_integer(Tkey_file, group, "Tchinese_form", Tchinese_form);

	//
	const gchar *user_dir = g_get_home_dir();
    gint len = g_sprintf(Tbuffer, "%s/%s/%s", user_dir, TTIECHU_DIRECTORY, TCONFIG_FILE);
	const gchar *config_file = Tbuffer;
	GError *error = NULL;
	if (!g_key_file_save_to_file(Tkey_file, config_file, &error)) {
        logger_error("Saving configuration failed");
	} else {
        logger_log("Configuration saved");
	}

}

void configuration_destroy() {
	if (!Tkey_file) {
		return;
	}
	g_key_file_free(Tkey_file);
    Tkey_file = NULL;
}

// get default mode
gint configuration_get_default_mode(){
	return Tdefault_mode;
}


// set default mode
void configuration_set_default_mode(MODE mode){
    Tdefault_mode = (gint)mode;
}

// get selected mode
gint configuration_get_selected_mode(){
	return Tselected_mode;
}

// set selected mode
void configuration_set_selected_mode(MODE mode){
    Tselected_mode = (gint)mode;
    Tcurrent_mode = Tselected_mode;
    logger_log("Changed to mode %d", Tcurrent_mode);
}

// get remembering mode
gboolean configuration_get_remembering_mode(){
	return Tremember_mode;
}

// set remembering mode
void configuration_set_remembering_mode(gboolean remember_mode){
    Tremember_mode = remember_mode;
}

gint configuration_get_super_key() {
	return Tsuper_key;
}

void configuration_set_super_key(SUPER_KEY key) {
    Tsuper_key = (gint)key;
}

gint configuration_get_vietnamese_mode_key() {
	return Tvietnamese_mode_shortkey;
}
void configuration_set_vietnamese_mode_key(gint key) {
    Tvietnamese_mode_shortkey = key;
}

gint configuration_get_teochew_mode_key() {
    return Tteochew_mode_shortkey;
}
void configuration_set_teochew_mode_key(gint key) {
    Tteochew_mode_shortkey = key;
}

gint configuration_get_hanviet_mode_key() {
	return Thanviet_mode_shortkey;
}
void configuration_set_hanviet_mode_key(gint key) {
    Thanviet_mode_shortkey = key;
}

gint configuration_get_chinese_mode_key() {
	return Tchinese_mode_shortkey;
}
void configuration_set_chinese_mode_key(gint key) {
    Tchinese_mode_shortkey = key;
}

gint configuration_get_english_mode_key() {
	return Tenglish_mode_shortkey;
}
void configuration_set_english_mode_key(gint key) {
    Tenglish_mode_shortkey = key;
}

gint configuration_get_candidate_table_key() {
	return Tcandidate_table_shortkey;
}
void configuration_set_candidate_table_key(gint key) {
    Tcandidate_table_shortkey = key;
}

gboolean configuration_get_auto_show_candidate_table(){
	return Tauto_show_candidate_table;
}

// set remembering mode
void configuration_set_auto_show_candidate_table(gboolean show){
    Tauto_show_candidate_table = show;
}

gint configuration_get_chinese_form() {
	return Tchinese_form;
}
void configuration_set_chinese_form(gint form) {
    Tchinese_form = form;
}

gint configuration_get_current_mode () {
	return Tcurrent_mode;
}
