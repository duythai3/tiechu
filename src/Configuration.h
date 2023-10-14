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
#ifndef _CONFIGURATION_H_
#define _CONFIGURATION_H_

#include <glib.h>

#define __CANDIDATE_TABLE_PAGE_SIZE__ 8

#define __TIECHU_DIRECTORY__ ".Tiechu"

#define __VIETNAMESE_MODE_LABEL__ "Mode Tiếng Việt"
#define __VIETNAMESE_MODE_VALUE__ "InputMode"

#define __TEOCHEW_MODE_LABEL__  "Mode Tiếng Tiều"
#define __TEOCHEW_MODE_VALUE__ "a_teochew_mode"

#define __HANVIET_MODE_LABEL__  "Mode Tiếng Hán Việt"
#define __HANVIET_MODE_VALUE__ "a_hanviet_mode"

#define __CHINESE_MODE_LABEL__  "Mode Tiếng Trung"
#define __CHINESE_MODE_VALUE__ "a_chinese_mode"

#define __ENGLISH_MODE_LABEL__  "Mode Tiếng Anh"
#define __ENGLISH_MODE_VALUE__ "a_english_mode"

#define __REMEMBER_MODE_LABEL__ "Ghi nhớ mode"
#define __REMEMBER_MODE_VALUE__ "a_remembering_mode"

#define __AUTO_SHOW_CANDIDATE_TABLE_LABEL__ "Tự động hiện bảng lựa chữ"
#define __AUTO_SHOW_CANDIDATE_TABLE_VALUE__ "a_auto_show_candidate_table"

#define __TRADITIONAL_CHINESE_FORM_LABEL__ "Chữ hoa phồn thể"
#define __TRADITIONAL_CHINESE_FORM_VALUE__ "a_traditional_chinese_form"

enum __MODE{
    __A_NONE_MODE__ = 0,
    __A_VIETNAMESE_MODE_2__ = 1,
    __A_HANVIET_MODE_2__ = 2,
    __A_TEOCHEW_MODE_2__ = 3,
    __A_CHINESE_MODE_2__ = 5,
    __A_ENGLISH_MODE_2__ = 7
};

enum __SUPER_KEY{
    __A_NONE_SUPER_KEY__ = 0,
    __A_CTRL_SUPER_KEY__ = 1,
    __A_SHIFT_SUPER_KEY__ = 2,
};

enum __CHINESE_FORM{
    __A_NONE_CHINESE_FORM__ = 0,
    __A_TRADITIONAL_CHINESE_FORM__ = 1,
    __A_SIMPLE_CHINESE_FOMR__ = 2,
};

typedef enum __MODE _MODE;
typedef enum __SUPER_KEY _SUPER_KEY;
typedef enum __CHINESE_FORM _CHINESE_FORM;


// load configuration
gboolean configuration_load();

// save configuration
void configuration_save();

void configuration_destroy();

// get default mode
gint configuration_get_default_mode();
// set default mode
void configuration_set_default_mode(_MODE mode);
// get selected mode
gint configuration_get_selected_mode();
// set selected mode
void configuration_set_selected_mode(_MODE mode);
// get remembering mode
gboolean configuration_get_remembering_mode();
// set remembering mode
void configuration_set_remembering_mode(gboolean remember_mode);
gint configuration_get_super_key();
void configuration_set_super_key(_SUPER_KEY key);
gint configuration_get_vietnamese_mode_key();
void configuration_set_vietnamese_mode_key(gint key);
gint configuration_get_hanviet_mode_key();
void configuration_set_hanviet_mode_key(gint key);
gint configuration_get_teochew_mode_key();
void configuration_set_teochew_mode_key(gint key);
gint configuration_get_chinese_mode_key();
void configuration_set_chinese_mode_key(gint key);
gint configuration_get_english_mode_key();
void configuration_set_english_mode_key(gint key);
gint configuration_get_candidate_table_key();
void configuration_set_candidate_table_key(gint key);

gboolean configuration_get_auto_show_candidate_table();
// set remembering mode
void configuration_set_auto_show_candidate_table(gboolean show);
gint configuration_get_chinese_form();
void configuration_set_chinese_form(gint form);
gint configuration_get_current_mode();

#endif
