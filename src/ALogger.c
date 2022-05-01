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
#include "ALogger.h"
#include "AUtil.h"
#include "AConfiguration.h"

#define __LOGGER_FILE__ "Abacus.log"
#define __LOGGER_FILE_2__ "Abacus_2.log"

gboolean create_abacus_directory();
glong get_logger_file_size();

GIOChannel *logger_channel = NULL;

gboolean is_log_file_opened() {
	return logger_channel!=NULL;
}

// open the log file
gboolean a_logger_open(){
	if (is_log_file_opened()) {
		return TRUE;
	}

	//
	if (!create_abacus_directory()) {
		return FALSE;
	}

	// open the log file
	const gchar *user_dir = g_get_home_dir();
	gchar *logger_file = g_strdup_printf("%s/%s/%s", user_dir, __ABACUS_DIRECTORY__, __LOGGER_FILE__);
    logger_channel = g_io_channel_new_file(logger_file, "a", NULL);
	g_free(logger_file);
	if(logger_channel==NULL){
		return FALSE;
	}

	// move log file's pointer to the end
    g_io_channel_seek_position(logger_channel, 0, G_SEEK_END, NULL);
	return TRUE;
}

// close abacus log file
void a_logger_close(){
	//
    if (!is_log_file_opened()){
    	return;
    }

    //
	GError *error = NULL;
	g_io_channel_shutdown(logger_channel, TRUE, &error);
	g_io_channel_unref(logger_channel);
    logger_channel = NULL;
	if(error != NULL){
		g_error_free(error);
	}

}

// write a string to abacus log file
void a_logger_write(const gchar* str){
    // do nothing if the log file is not opened
	if(!is_log_file_opened()){
    	return;
    }

	//
	gsize written = 0;
	GError *error = NULL;

	// write to the file
	g_io_channel_write_chars(logger_channel, str, -1, &written, &error);
	if(error != NULL){
		g_error_free(error);
		error = NULL;
	}

	// flush the buffer
	g_io_channel_flush(logger_channel, &error);
	if(error != NULL){
		g_error_free(error);
	}
}


void a_logger_log(const gchar* format_str, ...){
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

    gchar *timestamp_str =a_util_get_us_timestamp();
    gchar *str_written = g_strdup_printf("%s: %s, %s\n", timestamp_str, "info", str);

    a_logger_write(str_written);

    g_free(str);
    g_free(str_written);
    g_free(timestamp_str);
}

void a_logger_warn(const gchar* format_str, ...){
	if (!is_log_file_opened()) {
		return;
	}

	//
    gchar *str;
    va_list args;

    va_start(args, format_str);
    str = g_strdup_vprintf(format_str, args);
    va_end(args);

    gchar *timestamp_str =a_util_get_us_timestamp();
    gchar *str_written = g_strdup_printf("%s: %s, %s\n", timestamp_str, "warning", str);

    a_logger_write(str_written);

    g_free(str);
    g_free(str_written);
    g_free(timestamp_str);
}

void a_logger_error(const gchar* format_str, ...){
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

    gchar *timestamp_str =a_util_get_us_timestamp();
    gchar *str_written = g_strdup_printf("%s: %s, %s\n", timestamp_str, "error", str);

    a_logger_write(str_written);

    g_free(str);
    g_free(str_written);
    g_free(timestamp_str);
}

gboolean create_abacus_directory(){
    const gchar *user_dir = g_get_home_dir();
    gchar *abacus_dir = g_strdup_printf("%s/%s", user_dir, __ABACUS_DIRECTORY__);

    // do nothing if the .viethoa directory existed
    if(g_file_test(abacus_dir, G_FILE_TEST_EXISTS)){
        g_free(abacus_dir);
        return TRUE;
    }

    //
	if(g_mkdir(abacus_dir, 0755)!=0) {
        g_free(abacus_dir);
		return FALSE;
	}

	//
	g_free(abacus_dir);
	return TRUE;
}

// get size of log file
glong get_logger_file_size(){
    GStatBuf *st = g_new(GStatBuf, 1);
    st->st_size = 0;
    const gchar *user_dir = g_get_home_dir();
    gchar *logger_file = g_strdup_printf("%s/%s/%s", user_dir, __ABACUS_DIRECTORY__, __LOGGER_FILE__);

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
 * 2. Rename the main log file ~/.abacus/abacus.log to ~/.abacus/abacus_2.log
 * 2. Create the main log file
 */
void a_logger_backup(){
    // do nothing if the main log file's size is less than the limit
	if(get_logger_file_size()<__A_MAX_LOGGER_FILE_SIZE__) {
    	return;
    }

	// Close the main log file
    a_logger_close();

	// Rename the main log file to the backup file's name
	const gchar *user_dir = g_get_home_dir();
	gchar *logger_file_2 = g_strdup_printf("%s/%s/%s", user_dir, __ABACUS_DIRECTORY__, __LOGGER_FILE_2__);
	if(g_file_test(logger_file_2, G_FILE_TEST_EXISTS)){
		g_remove(logger_file_2);
	}
	gchar *logger_file = g_strdup_printf("%s/%s/%s", user_dir, __ABACUS_DIRECTORY__, __LOGGER_FILE__);
	g_rename(logger_file, logger_file_2);
	g_free(logger_file);
	g_free(logger_file_2);

	// Create the main log file
    a_logger_open();
}
