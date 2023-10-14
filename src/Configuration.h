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
#ifndef TCONFIGURATION_H
#define TCONFIGURATION_H

#include <glib.h>

#define TCANDIDATE_TABLE_PAGE_SIZE 8

#define TTIECHU_DIRECTORY ".Tiechu"

#define TVIETNAMESE_MODE_LABEL "Mode Tiếng Việt"
#define TVIETNAMESE_MODE_VALUE "InputMode"

#define TTEOCHEW_MODE_LABEL  "Mode Tiếng Tiều"
#define TTEOCHEW_MODE_VALUE "Tteochew_mode"

#define THANVIET_MODE_LABEL  "Mode Tiếng Hán Việt"
#define THANVIET_MODE_VALUE "Thanviet_mode"

#define TCHINESE_MODE_LABEL  "Mode Tiếng Trung"
#define TCHINESE_MODE_VALUE "Tchinese_mode"

#define TENGLISH_MODE_LABEL  "Mode Tiếng Anh"
#define TENGLISH_MODE_VALUE "Tenglish_mode"

#define TREMEMBER_MODE_LABEL "Ghi nhớ mode"
#define TREMEMBER_MODE_VALUE "Tremembering_mode"

#define TAUTO_SHOW_CANDIDATE_TABLE_LABEL "Tự động hiện bảng lựa chữ"
#define TAUTO_SHOW_CANDIDATE_TABLE_VALUE "Tauto_show_candidate_table"

#define TTRADITIONAL_CHINESE_FORM_LABEL "Chữ hoa phồn thể"
#define TTRADITIONAL_CHINESE_FORM_VALUE "Ttraditional_chinese_form"

enum TMODE{
    TNONE_MODE = 0,
    TVIETNAMESE_MODE = 2,
    TTEOCHEW_MODE = 3,
    THANVIET_MODE = 4,
    TCHINESE_MODE = 5,
    TENGLISH_MODE = 7
};

enum TSUPER_KEY{
    TNONE_SUPER_KEY = 0,
    TCTRL_SUPER_KEY = 3,
    TSHIFT_SUPER_KEY = 6
};

enum TCHINESE_FORM{
    TNONE_CHINESE_FORM = 0,
    TTRADITIONAL_CHINESE_FORM = 3,
    TSIMPLE_CHINESE_FOMR = 2
};

typedef enum TMODE MODE;
typedef enum TSUPER_KEY SUPER_KEY;
typedef enum TCHINESE_FORM CHINESE_FORM;


// load configuration
gboolean configuration_load();

// save configuration
void configuration_save();

void configuration_destroy();

// get default mode
gint configuration_get_default_mode();
// set default mode
void configuration_set_default_mode(MODE mode);
// get selected mode
gint configuration_get_selected_mode();
// set selected mode
void configuration_set_selected_mode(MODE mode);
// get remembering mode
gboolean configuration_get_remembering_mode();
// set remembering mode
void configuration_set_remembering_mode(gboolean remember_mode);
gint configuration_get_super_key();
void configuration_set_super_key(SUPER_KEY key);
gint configuration_get_vietnamese_mode_key();
void configuration_set_vietnamese_mode_key(gint key);
gint configuration_get_teochew_mode_key();
void configuration_set_teochew_mode_key(gint key);
gint configuration_get_hanviet_mode_key();
void configuration_set_hanviet_mode_key(gint key);
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
