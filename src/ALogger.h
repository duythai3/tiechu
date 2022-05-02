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
#ifndef __A_LOGGER_H__
#define __A_LOGGER_H__

// maximum size of the log file
#define __A_MAX_LOGGER_FILE_SIZE__ 7 * 1024 * 1024
#include <glib.h>

// mở tập tin log
gboolean a_logger_open();

// write a string into log file
void a_logger_write(const gchar* str);

// write an info string to opening log file
void a_logger_log(const gchar* format_str, ...);

// write a warning string to opening log file
void a_logger_warn(const gchar* format_str, ...);

// write an error string to opening log file
void a_logger_error(const gchar* format_str, ...);

// close the log file
void a_logger_close();

// reset log file if its size exceeds limit
void a_logger_backup();

#endif
