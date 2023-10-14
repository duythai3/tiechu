/*
 * The Tiechu engine for IBus
 *
 * Copyright (c) 2020-2022 Duy Thai,duythaia3@yahoo.com
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

#include "LTelexTable.h"

struct _PINYIN_CN_CLUTTER{
	// ascii a_clutter
    gchar* ltelex_clutter;
	// pinyin a_clutter
    gchar* pinyin_clutter;
};

// A table used to convert a telex a_clutter into vietnamese characters

static struct _PINYIN_CN_CLUTTER _clutters[] = {
	// a
    {"al", "ā"},
    {"az", "á"},
    {"ax", "ǎ"},
    {"af", "à"},

    {"ol", "ō"},
    {"oz", "ó"},
    {"ox", "ǒ"},
    {"of", "ò"},

	
    {"el", "ē"},
    {"ez", "é"},
    {"ex", "ě"},
    {"ef", "è"},

    {"il", "ī"},
    {"iz", "í"},
    {"ix", "ǐ"},
    {"if", "ì"},


    {"ul", "ū"},
    {"uz", "ú"},
    {"ux", "ǔ"},
    {"uf", "ù"},

    {"ül", "ǖ"},
    {"üz", "ǘ"},
    {"üx", "ǚ"},
    {"üf", "ǜ"},

    /////////
    {"āz", "á"},
    {"āx", "ǎ"},
    {"āf", "à"},

    {"ál", "ā"},
    {"áx", "ǎ"},
    {"áf", "à"},

    {"ǎl", "ā"},
    {"ǎz", "á"},
    {"ǎf", "à"},

    {"àl", "ā"},
    {"àz", "á"},
    {"àx", "ǎ"},

    /////////
    {"ōz", "ó"},
    {"ōx", "ǒ"},
    {"ōf", "ò"},

    {"ól", "ō"},
    {"óx", "ǒ"},
    {"óf", "ò"},

    {"ǒl", "ō"},
    {"ǒz", "ó"},
    {"ǒf", "ò"},

    {"òl", "ō"},
    {"òz", "ó"},
    {"òx", "ǒ"},

    /////////
    {"ēz", "é"},
    {"ēx", "ě"},
    {"ēf", "è"},

    {"él", "ē"},
    {"éx", "ě"},
    {"éf", "è"},

    {"ěl", "ē"},
    {"ěz", "é"},
    {"ěf", "è"},

    {"èl", "ē"},
    {"èz", "é"},
    {"èx", "ě"},

    /////////
    {"īz", "í"},
    {"īx", "ǐ"},
    {"īf", "ì"},

    {"íl", "ī"},
    {"íx", "ǐ"},
    {"íf", "ì"},

    {"ǐl", "ī"},
    {"ǐz", "í"},
    {"ǐf", "ì"},

    {"ìl", "ī"},
    {"ìz", "í"},
    {"ìx", "ǐ"},

    /////////
    {"ūz", "ú"},
    {"ūx", "ǔ"},
    {"ūf", "ù"},

    {"úl", "ū"},
    {"úx", "ǔ"},
    {"úf", "ù"},

    {"ǔl", "ū"},
    {"ǔz", "ú"},
    {"ǔf", "ù"},

    {"ùl", "ū"},
    {"ùz", "ú"},
    {"ùx", "ǔ"},

    /////////
    {"ǖz", "ǘ"},
    {"ǖx", "ǚ"},
    {"ǖf", "ǜ"},

    {"ǘl", "ǖ"},
    {"ǘx", "ǚ"},
    {"ǘf", "ǜ"},

    {"ǚl", "ǖ"},
    {"ǚz", "ǘ"},
    {"ǚf", "ǜ"},

    {"ǜl", "ǖ"},
    {"ǜz", "ǘ"},
    {"ǜx", "ǚ"},
};

static GHashTable* _ltelex_hash_table = NULL;

void ltelex_table_init(){
    if (_ltelex_hash_table) {
		return;
	}

	//
    int i = 0;
    _ltelex_hash_table = g_hash_table_new(g_str_hash, g_str_equal);
	for(i = 0; i < sizeof(_clutters)/sizeof(_clutters[0]); i++){
		g_hash_table_insert(
            _ltelex_hash_table,
            _clutters[i].ltelex_clutter,
			_clutters[i].pinyin_clutter
		);
	}
}

void ltelex_table_destroy(){
    if (!_ltelex_hash_table) {
		return;
	}

	//
    g_hash_table_remove_all(_ltelex_hash_table);
    g_hash_table_destroy(_ltelex_hash_table);
    _ltelex_hash_table = NULL;
}

/**
 * Convert a telex a_clutter into a vietnamese a_clutter
 * len: (out), length of vietnamese a_clutter
 */
const gchar * ltelex_table_convert_to_pinyin(const gchar* ascii_clutter){
    glong written = 0;
    const gchar* pinyin_clutter = (gchar*)g_hash_table_lookup(_ltelex_hash_table, ascii_clutter);
    return pinyin_clutter;
}


