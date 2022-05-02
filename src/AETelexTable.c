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

#include "AETelexTable.h"

struct _PINYIN_CN_CLUTTER{
	// ascii a_clutter
    gchar* etelex_clutter;
	// pinyin a_clutter
    gchar* teochew_clutter;
};

// A table used to convert a telex a_clutter into vietnamese characters

static struct _PINYIN_CN_CLUTTER _clutters[] = {
	// a
    {"ee", "ê"},
};

static GHashTable* _etelex_hash_table = NULL;

void a_etelex_table_init(){
    if (_etelex_hash_table) {
		return;
	}

	//
    int i = 0;
    _etelex_hash_table = g_hash_table_new(g_str_hash, g_str_equal);
	for(i = 0; i < sizeof(_clutters)/sizeof(_clutters[0]); i++){
		g_hash_table_insert(
            _etelex_hash_table,
            _clutters[i].etelex_clutter,
            _clutters[i].teochew_clutter
		);
	}
}

void a_etelex_table_destroy(){
    if (!_etelex_hash_table) {
		return;
	}

	//
    g_hash_table_remove_all(_etelex_hash_table);
    g_hash_table_destroy(_etelex_hash_table);
    _etelex_hash_table = NULL;
}

/**
 * Convert a telex a_clutter into a vietnamese a_clutter
 * len: (out), length of vietnamese a_clutter
 */
const gchar * a_etelex_table_convert_to_pinyin(const gchar* ascii_clutter){
    glong written = 0;
    const gchar* pinyin_clutter = (gchar*)g_hash_table_lookup(_etelex_hash_table, ascii_clutter);
    return pinyin_clutter;
}


