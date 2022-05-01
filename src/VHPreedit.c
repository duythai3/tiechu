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
#include "vhustring.h"
#include "VHTelexEditor.h"
#include "VHVNLetters.h"
#include <glib.h>
#include <ibus.h>
#include "ALogger.h"

VHUString* _preedit = NULL;
guint _cursor_pos = 0;


void vh_preedit_init(){
    if(_preedit == NULL){
        _preedit = vh_ustring_new();
        _cursor_pos = 0;
    }
}
void vh_preedit_destroy(){
    if(_preedit){
        vh_ustring_free(_preedit);
        _cursor_pos = 0;
        _preedit = NULL;
    }
}
void vh_preedit_clear(){
    if(_preedit){
        _preedit->len = 0;
        _cursor_pos = 0;
    }
}
void vh_preedit_insert(guint keyval){
    if(_preedit){
        vh_ustring_insert(_preedit, _cursor_pos, keyval);
        _cursor_pos ++;
    }
}

gboolean vh_preedit_move_cursor_left(){
    if(_cursor_pos > 0){
        _cursor_pos --;
        return TRUE;
    }else{
        return FALSE;
    }
}
gboolean vh_preedit_move_cursor_right(){
    if(_cursor_pos < _preedit->len){
        _cursor_pos ++; 
        return TRUE;
    }else{
        return FALSE;
    }
}
void vh_preedit_move_cursor_begin(){
    _cursor_pos = 0;
}

void vh_preedit_move_cursor_end(){
    if(_preedit){
       _cursor_pos = _preedit->len;
    }
}

void vh_preedit_delete_before_cursor(){
    if(_preedit){
        if(_cursor_pos > 0){
            _cursor_pos --;
            vh_ustring_delete(_preedit, _cursor_pos);
        }
    }
}

void vh_preedit_delete_after_cursor(){
    if(_preedit){
        if(_cursor_pos < _preedit->len){
            vh_ustring_delete(_preedit, _cursor_pos);
        }
    }
}

void vh_preedit_delete_at_cursor(){
    if(_preedit){
        if(_cursor_pos < _preedit->len){
            vh_ustring_delete(_preedit, _cursor_pos);
        }
    }
}

gchar *vh_preedit_get_utf8_string(){
    if(_preedit){
        return vh_ustring_to_utf8(_preedit);
    }else{
        return NULL;
    } 
}

void vh_preedit_log() {
	gchar* str = vh_preedit_get_utf8_string();
	if (str) {
        a_logger_log("preedit: %s", str);
		g_free(str);
	}
}

guint vh_preedit_get_cursor_pos(){
    return _cursor_pos;
}

guint vh_preedit_set_cursor_pos(guint cursor_pos){
    _cursor_pos = cursor_pos;
}

guint vh_preedit_get_before_cursor_char(){
    if(_preedit){
        if(_cursor_pos > 0){
            return _preedit->str[_cursor_pos - 1];
        }else{
            return 0;
        }       
    }else{
        return 0;
    }
}

guint vh_preedit_set_before_cursor_char(guint keyval){
    if(_preedit){
        if(_cursor_pos > 0){
            _preedit->str[_cursor_pos - 1] = keyval;
        }
    }
}

void vh_preedit_replace(guint index, guint len, gunichar* replace_str, guint replace_len){
    if(_preedit){
        vh_ustring_replace(_preedit, index, len, replace_str, replace_len);
    }
}
 
// get length of current preedit string
guint vh_preedit_get_length(){
    if(_preedit)
        return _preedit->len;
    else
        return 0;
}

guint vh_preedit_get_text_len(){
    if(_preedit){
        return _preedit->len;
    }else{
        return 0;
    }
}

// get current preedit string as unicode string
const gunichar *vh_preedit_get_preedit_string(){
    if(_preedit)
        return _preedit->str;
    else
        return NULL;
}


// get length of current preedit string
gunichar vh_preedit_get_char(gint index){
	if (!_preedit || _preedit->len <= index) {
		return 0;
	}
	return _preedit->str[index];
}
