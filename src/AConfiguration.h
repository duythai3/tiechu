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
#ifndef _A_CONFIGURATION_H_
#define _A_CONFIGURATION_H_

#include <glib.h>

#define __CANDIDATE_TABLE_PAGE_SIZE__ 8

#define __ABACUS_DIRECTORY__ ".Abacus"

#define __A_VIETNAMESE_MODE_LABEL__ "Mode Tiếng Việt"
#define __A_VIETNAMESE_MODE_VALUE__ "InputMode"

#define __A_HANVIET_MODE_LABEL__  "Mode Tiếng Hán Việt"
#define __A_HANVIET_MODE_VALUE__ "a_hanviet_mode"

#define __A_TEOCHEW_MODE_LABEL__  "Mode Tiếng Tiều"
#define __A_TEOCHEW_MODE_VALUE__ "a_teochew_mode"

#define __A_CHINESE_MODE_LABEL__  "Mode Tiếng Trung"
#define __A_CHINESE_MODE_VALUE__ "a_chinese_mode"

#define __A_ENGLISH_MODE_LABEL__  "Mode Tiếng Anh"
#define __A_ENGLISH_MODE_VALUE__ "a_english_mode"

#define __A_REMEMBER_MODE_LABEL__ "Ghi nhớ mode"
#define __A_REMEMBER_MODE_VALUE__ "a_remembering_mode"

#define __A_AUTO_SHOW_CANDIDATE_TABLE_LABEL__ "Tự động hiện bảng lựa chữ"
#define __A_AUTO_SHOW_CANDIDATE_TABLE_VALUE__ "a_auto_show_candidate_table"

#define __A_TRADITIONAL_CHINESE_FORM_LABEL__ "Chữ hoa phồn thể"
#define __A_TRADITIONAL_CHINESE_FORM_VALUE__ "a_traditional_chinese_form"

enum __A_MODE{
    __A_NONE_MODE__ = 0,
    __A_VIETNAMESE_MODE_2__ = 1,
    __A_HANVIET_MODE_2__ = 2,
    __A_TEOCHEW_MODE_2__ = 3,
    __A_CHINESE_MODE_2__ = 4,
    __A_ENGLISH_MODE_2__ = 7
};

enum __A_SUPER_KEY{
    __A_NONE_SUPER_KEY__ = 0,
    __A_CTRL_SUPER_KEY__ = 1,
    __A_SHIFT_SUPER_KEY__ = 2,
};

enum __A_CHINESE_FORM{
    __A_NONE_CHINESE_FORM__ = 0,
    __A_TRADITIONAL_CHINESE_FORM__ = 1,
    __A_SIMPLE_CHINESE_FOMR__ = 2,
};

typedef enum __A_MODE _MODE;
typedef enum __A_SUPER_KEY _SUPER_KEY;
typedef enum __A_CHINESE_FORM _CHINESE_FORM;


// load configuration
gboolean a_configuration_load();

// save configuration
void a_configuration_save();

void a_configuration_destroy();

// get default mode
gint a_configuration_get_default_mode();
// set default mode
void a_configuration_set_default_mode(_MODE mode);
// get selected mode
gint a_configuration_get_selected_mode();
// set selected mode
void a_configuration_set_selected_mode(_MODE mode);
// get remembering mode
gboolean a_configuration_get_remembering_mode();
// set remembering mode
void a_configuration_set_remembering_mode(gboolean remember_mode);
gint a_configuration_get_super_key();
void vh_configuration_set_super_key(_SUPER_KEY key);
gint a_configuration_get_vietnamese_mode_key();
void vh_configuration_set_vietnamese_mode_key(gint key);
gint a_configuration_get_hanviet_mode_key();
void vh_configuration_set_viethoa_mode_key(gint key);
gint a_configuration_get_teochew_mode_key();
void vh_configuration_set_teochew_mode_key(gint key);
gint a_configuration_get_chinese_mode_key();
void vh_configuration_set_chinese_mode_key(gint key);
gint a_configuration_get_english_mode_key();
void a_configuration_set_english_mode_key(gint key);
gint a_configuration_get_candidate_table_key();
void a_configuration_set_candidate_table_key(gint key);

gboolean a_configuration_get_auto_show_candidate_table();
// set remembering mode
void a_configuration_set_auto_show_candidate_table(gboolean show);
gint a_configuration_get_chinese_form();
void a_configuration_set_chinese_form(gint form);
gint a_configuration_get_current_mode();

#endif
