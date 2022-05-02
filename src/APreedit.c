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

#include "AUString.h"
#include "ATelexEditor.h"
#include "AVNLetters.h"
#include <glib.h>
#include <ibus.h>
#include "ALogger.h"
#include "APreedit.h"

AUString* _preedit = NULL;
guint _cursor_pos = 0;


void a_preedit_init(){
    if(_preedit == NULL){
        _preedit =a_ustring_new();
        _cursor_pos = 0;
    }
}
void a_preedit_destroy(){
    if(_preedit){
        a_ustring_free(_preedit);
        _cursor_pos = 0;
        _preedit = NULL;
    }
}
void a_preedit_clear(){
    if(_preedit){
        _preedit->len = 0;
        _cursor_pos = 0;
    }
}
void a_preedit_insert(guint keyval){
    if(_preedit){
        a_ustring_insert(_preedit, _cursor_pos, keyval);
        _cursor_pos ++;
    }
}

gboolean a_preedit_move_cursor_left(){
    if(_cursor_pos > 0){
        _cursor_pos --;
        return TRUE;
    }else{
        return FALSE;
    }
}
gboolean a_preedit_move_cursor_right(){
    if(_cursor_pos < _preedit->len){
        _cursor_pos ++; 
        return TRUE;
    }else{
        return FALSE;
    }
}
void a_preedit_move_cursor_begin(){
    _cursor_pos = 0;
}

void a_preedit_move_cursor_end(){
    if(_preedit){
       _cursor_pos = _preedit->len;
    }
}

void a_preedit_delete_before_cursor(){
    if(_preedit){
        if(_cursor_pos > 0){
            _cursor_pos --;
            a_ustring_delete(_preedit, _cursor_pos);
        }
    }
}

void a_preedit_delete_after_cursor(){
    if(_preedit){
        if(_cursor_pos < _preedit->len){
            a_ustring_delete(_preedit, _cursor_pos);
        }
    }
}

void vh_preedit_delete_at_cursor(){
    if(_preedit){
        if(_cursor_pos < _preedit->len){
            a_ustring_delete(_preedit, _cursor_pos);
        }
    }
}

gchar *a_preedit_get_utf8_string(){
    if(_preedit){
        return a_ustring_to_utf8(_preedit);
    }else{
        return NULL;
    } 
}

void a_preedit_log() {
	gchar* str =a_preedit_get_utf8_string();
	if (str) {
        a_logger_log("preedit: %s", str);
		g_free(str);
	}
}

guint a_preedit_get_cursor_pos(){
    return _cursor_pos;
}

guint a_preedit_set_cursor_pos(guint cursor_pos){
    _cursor_pos = cursor_pos;
}

guint a_preedit_get_before_cursor_char(){
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

guint a_preedit_set_before_cursor_char(guint keyval){
    if(_preedit){
        if(_cursor_pos > 0){
            _preedit->str[_cursor_pos - 1] = keyval;
        }
    }
}

void a_preedit_replace(guint index, guint len, gunichar* replace_str, guint replace_len){
    if(_preedit){
        a_ustring_replace(_preedit, index, len, replace_str, replace_len);
    }
}
 
// get length of current preedit string
guint a_preedit_get_length(){
    if(_preedit)
        return _preedit->len;
    else
        return 0;
}

guint a_preedit_get_text_len(){
    if(_preedit){
        return _preedit->len;
    }else{
        return 0;
    }
}

// get current preedit string as unicode string
const gunichar *a_preedit_get_preedit_string(){
    if(_preedit)
        return _preedit->str;
    else
        return NULL;
}

// get length of current preedit string
gunichar a_preedit_get_char(gint index){
	if (!_preedit || _preedit->len <= index) {
		return 0;
	}
	return _preedit->str[index];
}