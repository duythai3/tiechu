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

#include "APinyinTable.h"

struct _PINYIN_CN_CLUTTER{
	// ascii a_clutter
    gchar* ascii_clutter;
	// pinyin a_clutter
    gchar* pinyin_clutter;
};

// A table used to convert a telex a_clutter into vietnamese characters

static struct _PINYIN_CN_CLUTTER _clutters[] = {
	// a
    {"a1", "ā"},
    {"a2", "á"},
    {"a3", "ǎ"},
    {"a4", "à"},

	{"o1", "ō"},
   	{"o2", "ó"},
   	{"o3", "ǒ"},
   	{"o4", "ò"},

	
	{"e1", "ē"},
	{"e2", "é"},
	{"e3", "ě"},
	{"e4", "è"},

   	{"i1", "ī"},
   	{"i2", "í"},
   	{"i3", "ǐ"},
   	{"i4", "ì"},


   	{"u1", "ū"},
   	{"u2", "ú"},
   	{"u3", "ǔ"},
   	{"u4", "ù"},

   	{"ü1", "ǖ"},
   	{"ü2", "ǘ"},
   	{"ü3", "ǚ"},
   	{"ü4", "ǜ"},

    /////////
    {"ā2", "á"},
    {"ā3", "ǎ"},
    {"ā4", "à"},

	{"á1", "ā"},
	{"á3", "ǎ"},
	{"á4", "à"},

	{"ǎ1", "ā"},
	{"ǎ2", "á"},
	{"ǎ4", "à"},

	{"à1", "ā"},
	{"à2", "á"},
	{"à3", "ǎ"},

    /////////
    {"ō2", "ó"},
    {"ō3", "ǒ"},
    {"ō4", "ò"},

	{"ó1", "ō"},
	{"ó3", "ǒ"},
	{"ó4", "ò"},

	{"ǒ1", "ō"},
	{"ǒ2", "ó"},
	{"ǒ4", "ò"},

	{"ò1", "ō"},
	{"ò2", "ó"},
	{"ò3", "ǒ"},

    /////////
    {"ē2", "é"},
    {"ē3", "ě"},
    {"ē4", "è"},

	{"é1", "ē"},
	{"é3", "ě"},
	{"é4", "è"},

	{"ě1", "ē"},
	{"ě2", "é"},
	{"ě4", "è"},

	{"è1", "ē"},
	{"è2", "é"},
	{"è3", "ě"},

    /////////
    {"ī2", "í"},
    {"ī3", "ǐ"},
    {"ī4", "ì"},

	{"í1", "ī"},
	{"í3", "ǐ"},
	{"í4", "ì"},

	{"ǐ1", "ī"},
	{"ǐ2", "í"},
	{"ǐ4", "ì"},

	{"ì1", "ī"},
	{"ì2", "í"},
	{"ì3", "ǐ"},

    /////////
    {"ū2", "ú"},
    {"ū3", "ǔ"},
    {"ū4", "ù"},

	{"ú1", "ū"},
	{"ú3", "ǔ"},
	{"ú4", "ù"},

	{"ǔ1", "ū"},
	{"ǔ2", "ú"},
	{"ǔ4", "ù"},

	{"ù1", "ū"},
	{"ù2", "ú"},
	{"ù3", "ǔ"},

    /////////
    {"ǖ2", "ǘ"},
    {"ǖ3", "ǚ"},
    {"ǖ4", "ǜ"},

	{"ǘ1", "ǖ"},
	{"ǘ3", "ǚ"},
	{"ǘ4", "ǜ"},

	{"ǚ1", "ǖ"},
	{"ǚ2", "ǘ"},
	{"ǚ4", "ǜ"},

	{"ǜ1", "ǖ"},
	{"ǜ2", "ǘ"},
	{"ǜ3", "ǚ"},
};

static GHashTable* _pinyin_hash_table = NULL;

void a_pinyin_table_init(){
	if (_pinyin_hash_table) {
		return;
	}

	//
    int i = 0;
	_pinyin_hash_table = g_hash_table_new(g_str_hash, g_str_equal);
	for(i = 0; i < sizeof(_clutters)/sizeof(_clutters[0]); i++){
		g_hash_table_insert(
			_pinyin_hash_table,
			_clutters[i].ascii_clutter,
			_clutters[i].pinyin_clutter
		);
	}
}

void a_pinyin_table_destroy(){
	if (!_pinyin_hash_table) {
		return;
	}

	//
	g_hash_table_remove_all(_pinyin_hash_table);
	g_hash_table_destroy(_pinyin_hash_table);
	_pinyin_hash_table = NULL;
}

/**
 * Convert a telex a_clutter into a vietnamese a_clutter
 * len: (out), length of vietnamese a_clutter
 */
const gchar * a_pinyin_table_convert_to_pinyin(const gchar* ascii_clutter){
    glong written = 0;
    const gchar* pinyin_clutter = (gchar*)g_hash_table_lookup(_pinyin_hash_table, ascii_clutter);
    return pinyin_clutter;
}


