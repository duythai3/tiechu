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
#include "AZTelexTable2.h"
#include "AVNLetters.h"

struct A_TELEX_VN_CLUTTER{
	// telex a_clutter
    gchar* a_telex_clutter;
	// vietnamese a_clutter
    gchar* a_vn_clutter;
};

struct A_CORRECT_CLUTTER{
	// a telex a_clutter that need to be make correct
    gchar* a_clutter;
	// a telex that was made correct
    gchar* a_correct_clutter;
};

// A table used to convert a telex a_clutter into vietnamese characters

static struct A_TELEX_VN_CLUTTER a_clutters[] = {
	// a
    {"az", "á"},
   	{"af", "à"},
   	{"ar", "ả"},
   	{"ax", "ã"},
   	{"aj", "ạ"},
	//
    {"áf", "à"},
   	{"ár", "ả"}, 
	{"áx", "ã"}, 
	{"áj", "ạ"},
	//
    {"àz", "á"}, 
	{"àr", "ả"},
   	{"àx", "ã"}, 
	{"àj", "ạ"},
	//
    {"ảz", "á"}, 
	{"ảf", "à"}, 
	{"ảx", "ã"}, 
	{"ảj", "ạ"},
	//
    {"ãz", "á"}, 
	{"ãf", "à"}, 
	{"ãr", "ả"}, 
	{"ãj", "ạ"},
	//
    {"ạz", "á"}, 
	{"ạf", "à"}, 
	{"ạr", "ả"},
   	{"ạx", "ã"},


	// ă //////////////////////////////////////////////
    {"aw", "ă"}, 
	//
	{"ăz", "ắ"}, 
	{"ăf", "ằ"}, 
	{"ăr", "ẳ"}, 
	{"ăx", "ẵ"}, 
	{"ăj", "ặ"},
	//
    {"ắf", "ằ"}, 
	{"ắr", "ẳ"}, 
	{"ắx", "ẵ"}, 
	{"ắj", "ặ"},
	//
    {"ằz", "ắ"}, 
	{"ằr", "ẳ"}, 
	{"ằx", "ẵ"}, 
	{"ằj", "ặ"},
	//
    {"ẳz", "ắ"}, 
	{"ẳf", "ằ"}, 
	{"ẳx", "ẵ"}, 
	{"ẳj", "ặ"},
	//
    {"ẵz", "ắ"}, 
	{"ẵf", "ằ"}, 
	{"ẵr", "ẳ"}, 
	{"ẵj", "ặ"},
	//
    {"ặz", "ắ"}, 
	{"ặf", "ằ"}, 
	{"ặr", "ẳ"}, 
	{"ặx", "ẵ"},

	// â ////////////////////////////////////////////////////// 	
    {"aa", "â"},
	//
    {"âz", "ấ"},
    {"âf", "ầ"},
    {"âr", "ẩ"},
    {"âx", "ẫ"},
    {"âj", "ậ"},
	//
    {"ấf", "ầ"}, 
	{"ấr", "ẩ"}, 
	{"ấx", "ẫ"}, 
	{"ấj", "ậ"},
	//
    {"ầz", "ấ"}, 
	{"ầr", "ẩ"}, 
	{"ầx", "ẫ"}, 
	{"ầj", "ậ"},
	//
    {"ẩz", "ấ"}, 
	{"ẩf", "ầ"}, 
	{"ẩx", "ẫ"}, 
	{"ẩj", "ậ"},
	//
    {"ẫz", "ấ"}, 
	{"ẫf", "ầ"}, 
	{"ẫr", "ẩ"}, 
	{"ẫj", "ậ"},
	//
    {"ậz", "ấ"}, 
	{"ậf", "ầ"}, 
	{"ậr", "ẩ"}, 
	{"ậx", "ẫ"},

    
	// đ ///////////////////////////////////////////////////
    {"dd", "đ"},

	// e //////////////////////////////////////////////////
    {"ez", "é"},
    {"ef", "è"},
    {"er", "ẻ"},
    {"ex", "ẽ"},
    {"ej", "ẹ"},
    // 
    {"éf", "è"}, 
	{"ér", "ẻ"}, 
	{"éx", "ẽ"}, 
	{"éj", "ẹ"},
	//
    {"èz", "é"}, 
	{"èr", "ẻ"}, 
	{"èx", "ẽ"}, 
	{"èj", "ẹ"},
	//
    {"ẻz", "é"}, 
	{"ẻf", "è"}, 
	{"ẻx", "ẽ"}, 
	{"ẻj", "ẹ"},
	//
    {"ẽz", "é"}, 
	{"ẽf", "è"}, 
	{"ẽr", "ẻ"}, 
	{"ẽj", "ẹ"},
	//
    {"ẹz", "é"}, 
	{"ẹf", "è"}, 
	{"ẹr", "ẻ"}, 
	{"ẹx", "ẽ"},

	// ê ////////////////////////////////////////////////////
	{"ee", "ê"},
	//
    {"êz", "ế"},
    {"êf", "ề"},
    {"êr", "ể"},
    {"êx", "ễ"},
    {"êj", "ệ"},
    // 
	{"ếf", "ề"}, 
	{"ếr", "ể"}, 
	{"ếx", "ễ"}, 
	{"ếj", "ệ"},
	//
    {"ềz", "ế"}, 
	{"ềr", "ể"}, 
	{"ềx", "ễ"}, 
	{"ềj", "ệ"},
	//
    {"ểz", "ế"}, 
	{"ểf", "ề"}, 
	{"ểx", "ễ"}, 
	{"ểj", "ệ"},
	//
    {"ễz", "ế"}, 
	{"ễf", "ề"}, 
	{"ễr", "ể"}, 
	{"ễj", "ệ"},
	//
    {"ệz", "ế"}, 
	{"ệf", "ề"}, 
	{"ệr", "ể"}, 
	{"ệx", "ễ"},
    

	// i ////////////////////////////////////////////////////
    {"iz", "í"},
    {"if", "ì"},
    {"ir", "ỉ"},
    {"ix", "ĩ"},
    {"ij", "ị"},
    // 
    {"íf", "ì"}, 
	{"ír", "ỉ"}, 
	{"ìx", "ĩ"}, 
	{"íj", "ị"},
	//
    {"ìz", "í"}, 
	{"ìr", "ỉ"}, 
	{"ìx", "ĩ"}, 
	{"ìj", "ị"},
	//
    {"ỉz", "í"}, 
	{"ỉf", "ì"}, 
	{"ỉx", "ĩ"}, 
	{"ỉj", "ị"},
	//
    {"ĩz", "í"}, 
	{"ĩf", "ì"}, 
	{"ĩr", "ỉ"}, 
	{"ĩj", "ị"},
	//
    {"ịz", "í"}, 
	{"ịf", "ì"}, 
	{"ịr", "ỉ"}, 
	{"ịx", "ĩ"},


	// o //////////////////////////////////////////////////
    {"oz", "ó"},
    {"of", "ò"},
    {"or", "ỏ"},
    {"ox", "õ"},
    {"oj", "ọ"},
    // 
	{"óf", "ò"}, 
	{"ór", "ỏ"}, 
	{"óx", "õ"}, 
	{"ój", "ọ"},
	//
    {"òz", "ó"}, 
	{"òr", "ỏ"}, 
	{"òx", "õ"}, 
	{"òj", "ọ"},
	//
    {"ỏz", "ó"}, 
	{"ỏf", "ò"}, 
	{"ỏx", "õ"}, 
	{"ỏj", "ọ"},
	//
    {"õz", "ó"}, 
	{"õf", "ò"}, 
	{"õr", "ỏ"}, 
	{"õj", "ọ"},
	//
    {"ọz", "ó"}, 
	{"ọf", "ò"}, 
	{"ọr", "ỏ"}, 
	{"ọx", "õ"},
    

	// ô /////////////////////////////////////////////////////
    {"oo", "ô"},
	//
    {"ôz", "ố"},
    {"ôf", "ồ"},
    {"ôr", "ổ"},
    {"ôx", "ỗ"},
    {"ôj", "ộ"},
    // 
    {"ốf", "ồ"}, 
	{"ốr", "ổ"}, 
	{"ốx", "ỗ"}, 
	{"ốj", "ộ"},
	//
    {"ồz", "ố"}, 
	{"ồr", "ổ"}, 
	{"ồx", "ỗ"}, 
	{"ồj", "ộ"},
	//
    {"ổz", "ố"}, 
	{"ổf", "ồ"}, 
	{"ổx", "ỗ"}, 
	{"ổj", "ộ"},
	//
    {"ỗz", "ố"}, 
	{"ỗf", "ồ"}, 
	{"ỗr", "ổ"}, 
	{"ỗj", "ộ"},
	//
    {"ộz", "ố"}, 
	{"ộf", "ồ"}, 
	{"ộr", "ổ"}, 
	{"ộx", "ỗ"},
    

	// ơ ///////////////////////////////////////////////////////
    {"ow", "ơ"},
    {"ơz", "ớ"},
    {"ơf", "ờ"},
    {"ơr", "ở"},
    {"ơx", "ỡ"},
    {"ơj", "ợ"},
    // 
    {"ớf", "ờ"}, 
	{"ớr", "ở"}, 
	{"ớx", "ỡ"}, 
	{"ớj", "ợ"},
	//
    {"ờz", "ớ"}, 
	{"ờr", "ở"}, 
	{"ờx", "ỡ"}, 
	{"ờj", "ợ"},
	//
    {"ởz", "ớ"}, 
	{"ởf", "ờ"}, 
	{"ởx", "ỡ"}, 
	{"ởj", "ợ"},
	//
    {"ỡz", "ớ"}, 
	{"ỡf", "ờ"}, 
	{"ỡr", "ở"}, 
	{"ỡj", "ợ"},
	//
    {"ợz", "ớ"}, 
	{"ợf", "ờ"}, 
	{"ợr", "ở"}, 
	{"ợx", "ỡ"},
    

	// u /////////////////////////////////////////////////////
    {"uz", "ú"},
    {"uf", "ù"},
    {"ur", "ủ"},
    {"ux", "ũ"},
    {"uj", "ụ"},
    // 
    {"úf", "ù"}, 
	{"úr", "ủ"}, 
	{"úx", "ũ"}, 
	{"új", "ụ"},
	//
    {"ùz", "ú"}, 
	{"ùr", "ủ"}, 
	{"ùx", "ũ"}, 
	{"ùj", "ụ"},
	//
    {"ủz", "ú"}, 
	{"ủf", "ù"}, 
	{"ủx", "ũ"}, 
	{"ủj", "ụ"},
	//
    {"ũz", "ú"}, 
	{"ũf", "ù"}, 
	{"ũr", "ủ"}, 
	{"ũj", "ụ"},
	//
    {"ụz", "ú"}, 
	{"ụf", "ù"}, 
	{"ụr", "ủ"}, 
	{"ụx", "ũ"},


	// ư /////////////////////////////////////////////////////
    {"uw", "ư"},
    {"ưz", "ứ"},
    {"ưf", "ừ"},
    {"ưr", "ử"},
    {"ưx", "ữ"},
    {"ưj", "ự"},
    // 
    {"ứf", "ừ"},
   	{"ứr", "ử"},
   	{"ứx", "ữ"},
   	{"ứj", "ự"},
	//
    {"ừz", "ứ"},
   	{"ừr", "ử"},
   	{"ừx", "ữ"},
   	{"ừj", "ự"},
	//
    {"ửz", "ứ"},
   	{"ửf", "ừ"},
   	{"ửx", "ữ"},
   	{"ửj", "ự"},
	//
    {"ữz", "ứ"},
   	{"ữf", "ừ"},
   	{"ữr", "ử"},
   	{"ữj", "ự"},
	//
    {"ựz", "ứ"},
   	{"ựf", "ừ"},
   	{"ựr", "ử"},
   	{"ựx", "ữ"},

    
	// y ////////////////////////////////////////////////////
    {"yz", "ý"},
    {"yf", "ỳ"},
    {"yr", "ỷ"},
    {"yx", "ỹ"},
    {"yj", "ỵ"},
    // 
    {"ýf", "ỳ"}, 
	{"ýr", "ỷ"}, 
	{"ýx", "ỹ"}, 
	{"ýj", "ỵ"},
	//
    {"ỳz", "ý"}, 
	{"ỳr", "ỷ"}, 
	{"ỳx", "ỹ"}, 
	{"ỳj", "ỵ"},
	//
    {"ỷz", "ý"}, 
	{"ỷf", "ỳ"}, 
	{"ỷx", "ỹ"}, 
	{"ỷj", "ỵ"},
	//
    {"ỹz", "ý"}, 
	{"ỹf", "ỳ"}, 
	{"ỹr", "ỷ"}, 
	{"ỹj", "ỵ"},
	//
    {"ỵz", "ý"}, 
	{"ỵf", "ỳ"}, 
	{"ỵr", "ỷ"}, 
	{"ỵx", "ỹ"},

	

    // extra entries
    {"ôw","ơ"}, {"uôw", "ươ"},{"ôiw", "ơi"},
    {"ơo","ô"}, {"ươo", "uô"},{"ơio", "ôi"},
    {"ăa","â"}, {"âw", "ă"},

    // ố
    {"ốw","ớ"}, {"uốw", "ướ"},{"ốiw", "ới"},

};

/**
 * This table is used to make position of symbol correctly when a a_clutter has final consonant
 */
static struct A_CORRECT_CLUTTER a_correct_clutters[] = {
	// oa
	{"óa", "oá"},
	{"òa", "oà"},
	{"ỏa", "oả"},
	{"õa", "oã"},
	{"ọa", "oạ"},

	//ua
	{"úa", "uá"},
	{"ùa", "uà"},
	{"ủa", "uả"},
	{"ũa", "uã"},
	{"ụa", "uạ"},
	
};

static GHashTable* a_telex_hash_table = NULL;
static GHashTable* a_correct_hash_table = NULL;

void a_z_telex_table_2_init(){
    int i = 0;
    if(!a_telex_hash_table){
        a_telex_hash_table = g_hash_table_new(g_str_hash, g_str_equal);
        for(i = 0; i <sizeof(a_clutters)/sizeof(a_clutters[0]); i++){
            g_hash_table_insert(
                    a_telex_hash_table,
                    a_clutters[i].a_telex_clutter,
                    a_clutters[i].a_vn_clutter
			);
        }
    }
    if(!a_correct_hash_table){
        a_correct_hash_table = g_hash_table_new(g_str_hash, g_str_equal);
        for(i = 0; i <sizeof(a_correct_clutters)/sizeof(a_correct_clutters[0]); i++){
            g_hash_table_insert(
                    a_correct_hash_table,
                    a_correct_clutters[i].a_clutter,
                    a_correct_clutters[i].a_correct_clutter
			);
        }
    }
}

void a_z_telex_table_2_destroy(){
    if(a_telex_hash_table){
        g_hash_table_remove_all(a_telex_hash_table);
        g_hash_table_destroy(a_telex_hash_table);
        a_telex_hash_table = NULL;
    }   
    if(a_correct_hash_table){
        g_hash_table_remove_all(a_correct_hash_table);
        g_hash_table_destroy(a_correct_hash_table);
        a_correct_hash_table = NULL;
    }   
}

/**
 * Convert a telex a_clutter into a vietnamese a_clutter
 * len: (out), length of vietnamese a_clutter
 */
gunichar * a_z_telex_table_2_convert_to_vietnamese(const gchar* telex_clutter, guint* len){
    glong written = 0;
    const gchar* a_vn_clutter = (gchar*)g_hash_table_lookup(a_telex_hash_table, telex_clutter);

    //
    if (!a_vn_clutter) {
    	return NULL;
    }

	//
	gunichar *unichar_vn_clutter = g_utf8_to_ucs4_fast(a_vn_clutter, -1, &written);
	if (!unichar_vn_clutter) {
		return NULL;
	}

	// return result
	if(len){
		*len = written;
	}
	return unichar_vn_clutter;
}