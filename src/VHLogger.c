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
#include "VHLogger.h"
#include "vhutil.h"
#include "VHConfiguration.h"

#define __LOGGER_FILE__ "ibus_viethoa.log"
#define __LOGGER_FILE_2__ "ibus_viethoa_2.log"

gboolean create_viethoa_directory();
glong get_logger_file_size();

GIOChannel *_logger_channel = NULL;

gboolean is_log_file_opened() {
	return _logger_channel != NULL;
}

// open the log file
gboolean vh_logger_open(){
	if (is_log_file_opened()) {
		return TRUE;
	}

	// create directory ~/.viethoa
	if (!create_viethoa_directory()) {
		return FALSE;
	}

	// open the log file
	const gchar *user_dir = g_get_home_dir();
	gchar *logger_file = g_strdup_printf("%s/%s/%s", user_dir, __VIETHOA_DIRECTORY__, __LOGGER_FILE__);
	_logger_channel = g_io_channel_new_file(logger_file, "a", NULL);
	g_free(logger_file);
	if(_logger_channel == NULL){
		return FALSE;
	}

	// move log file's pointer to the end
    g_io_channel_seek_position(_logger_channel, 0, G_SEEK_END, NULL);
	return TRUE;
}

// close viethoa log file
void vh_logger_close(){
	//
    if (!is_log_file_opened()){
    	return;
    }

    //
	GError *error = NULL;
	g_io_channel_shutdown(_logger_channel, TRUE, &error);
	g_io_channel_unref(_logger_channel);
	_logger_channel = NULL;
	if(error != NULL){
		g_error_free(error);
	}

}

// write a string to viethoa log file
void vh_logger_write(const gchar* str){
    // do nothing if the log file is not opened
	if(!is_log_file_opened()){
    	return;
    }

	//
	gsize written = 0;
	GError *error = NULL;

	// write to the file
	g_io_channel_write_chars(_logger_channel, str, -1, &written, &error);
	if(error != NULL){
		g_error_free(error);
		error = NULL;
	}

	// flush the buffer
	g_io_channel_flush(_logger_channel, &error);
	if(error != NULL){
		g_error_free(error);
	}
}


void vh_logger_log(const gchar* format_str, ...){
	//
	if (!is_log_file_opened()) {
		return;
	}

	//
    gchar *str;
    va_list args;

    va_start(args, format_str);
    str = g_strdup_vprintf(format_str, args);
    va_end(args);

    gchar *timestamp_str = vh_util_get_us_timestamp();
    gchar *str_written = g_strdup_printf("%s: %s, %s\n", timestamp_str, "info", str);

    vh_logger_write(str_written);

    g_free(str);
    g_free(str_written);
    g_free(timestamp_str);
}

void vh_logger_warn(const gchar* format_str, ...){
	if (!is_log_file_opened()) {
		return;
	}

	//
    gchar *str;
    va_list args;

    va_start(args, format_str);
    str = g_strdup_vprintf(format_str, args);
    va_end(args);

    gchar *timestamp_str = vh_util_get_us_timestamp();
    gchar *str_written = g_strdup_printf("%s: %s, %s\n", timestamp_str, "warning", str);

    vh_logger_write(str_written);

    g_free(str);
    g_free(str_written);
    g_free(timestamp_str);
}

void vh_logger_error(const gchar* format_str, ...){
	//
	if (!is_log_file_opened()) {
		return;
	}

	//
    gchar *str;
    va_list args;

    va_start(args, format_str);
    str = g_strdup_vprintf(format_str, args);
    va_end(args);

    gchar *timestamp_str = vh_util_get_us_timestamp();
    gchar *str_written = g_strdup_printf("%s: %s, %s\n", timestamp_str, "error", str);

    vh_logger_write(str_written);

    g_free(str);
    g_free(str_written);
    g_free(timestamp_str);
}

gboolean create_viethoa_directory(){
    const gchar *user_dir = g_get_home_dir();
    gchar *viethoa_dir = g_strdup_printf("%s/%s", user_dir, __VIETHOA_DIRECTORY__);

    // do nothing if the .viethoa directory existed
    if(g_file_test(viethoa_dir, G_FILE_TEST_EXISTS)){
        g_free(viethoa_dir);
        return TRUE;
    }

    //
	if(g_mkdir(viethoa_dir, 0755) != 0) {
        g_free(viethoa_dir);
		return FALSE;
	}

	//
	g_free(viethoa_dir);
	return TRUE;
}

// get size of log file
glong get_logger_file_size(){
    GStatBuf *st = g_new(GStatBuf, 1);
    st->st_size = 0;
    const gchar *user_dir = g_get_home_dir();
    gchar *logger_file = g_strdup_printf("%s/%s/%s", user_dir, __VIETHOA_DIRECTORY__, __LOGGER_FILE__);

    // if the log file does not exist
    if(!g_file_test(logger_file, G_FILE_TEST_EXISTS)){
        g_free(st);
        g_free(logger_file);
        return 0;
    }

    //
    if (g_lstat(logger_file, st) != 0) {
		g_free(st);
		g_free(logger_file);
		return 0;
    }

    //
	glong file_size = st->st_size;
	g_free(logger_file);
	g_free(st);
	return file_size;
}

/**
 * 1. Close the main log file
 * 2. Rename the main log file ~/.viethoa/ibus_viethoa.log to ~/.viethoa/ibus_viethoa_2.log
 * 2. Create the main log file
 */
void vh_logger_backup(){
    // do nothing if the main log file's size is less than the limit
	if(get_logger_file_size() < __VH_MAX_LOGGER_FILE_SIZE__) {
    	return;
    }

	// Close the main log file
	vh_logger_close();

	// Rename the main log file to the backup file's name
	const gchar *user_dir = g_get_home_dir();
	gchar *logger_file_2 = g_strdup_printf("%s/%s/%s", user_dir, __VIETHOA_DIRECTORY__, __LOGGER_FILE_2__);
	if(g_file_test(logger_file_2, G_FILE_TEST_EXISTS)){
		g_remove(logger_file_2);
	}
	gchar *logger_file = g_strdup_printf("%s/%s/%s", user_dir, __VIETHOA_DIRECTORY__, __LOGGER_FILE__);
	g_rename(logger_file, logger_file_2);
	g_free(logger_file);
	g_free(logger_file_2);

	// Create the main log file
	vh_logger_open();
}
