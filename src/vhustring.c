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
#include <gmodule.h>
#include "VHLogger.h"
#include "vhustring.h"

VHUString* vh_ustring_new(){
    VHUString *s = (VHUString*)g_new(VHUString, 1);
    s->str = (gunichar*)g_malloc(1024 * 4);
    s->len = 0;
    s->allocated_len = 1024;
    s->str[0] = 0;
    return s;
}

void vh_ustring_free(VHUString* vhustr){
    if(vhustr != NULL){
        g_free((gpointer)vhustr->str);
        g_free(vhustr);
    }
}

void vh_ustring_append(VHUString *s, guint keyval){
    s->str[s->len] = keyval;
    s->len++;
    s->str[s->len] = 0;
}

guint vh_ustring_get(VHUString *s, gsize index){
    if(index <= s->len){
        return (guint)s->str[index];
    }else{
        return 0;
    }
}

void vh_ustring_set(VHUString *s, gsize index, guint keyval){
    if(index < s->len){
        s->str[index] = (gunichar)keyval;
    }
}

void vh_ustring_clear(VHUString *s){
    if(s){
        s->len = 0;
    }
}

gchar* vh_ustring_to_utf8(VHUString *s){
    return g_ucs4_to_utf8(s->str, s->len, NULL, NULL, NULL);
}

void vh_ustring_insert(VHUString *s, guint index, guint keyval){
    if(s->len < s->allocated_len){
        gunichar *source = s->str + index;
        gunichar *desc = source + 1;
        guint len = s->len - index;
        if(len > 0){
            memmove(desc, source, (s->len - index) * 4);
        }
        s->str[index] = keyval;
        s->len += 1;
        s->str[s->len] = 0;
    }
} 

void vh_ustring_delete(VHUString *s, guint index){
    if(index < s->len){
        gunichar *source = s->str + index + 1;
        gunichar *desc = s->str + index;
        guint len = s->len - index - 1;
        if(len > 0){
            memmove(desc, source, len * 4);
        }
        s->len -= 1;
    }
} 

void vh_ustring_replace(VHUString *s, guint index, guint len, gunichar* str, guint str_len){

    guint j = 0;

    /*
    gchar *t1 = g_ucs4_to_utf8(s->str, -1, NULL, NULL, NULL);
    gchar *t2 = g_ucs4_to_utf8(str, -1, NULL, NULL, NULL);
    vh_logger_write_info("before replace: %s, replace string: %s, index: %d, len: %d, str_len: %d", t1, t2, index, len, str_len);
    g_free(t1);
    g_free(t2);

    */

    if(len == str_len){
        /*
        for(guint i = index; i < index + len; i++){
          s->str[i] = str[j];
          j++;
        } 
        */
        memmove(s->str + index, str, len * 4);
    }else if(len < str_len){
        memmove(s->str + index + str_len, s->str + index + len, (s->len - index - len) * 4);
        memmove(s->str + index, str, str_len * 4);
        s->len = s->len + str_len - len;   
        s->str[s->len] = 0;
    }else if(len > str_len){
        memmove(s->str + index + str_len, s->str + index + len, (s->len - index - len) * 4);
        memmove(s->str + index, str, str_len * 4);
        s->len = s->len - (len - str_len);
        s->str[s->len] = 0;
    }

    /*
    t1 = g_ucs4_to_utf8(s->str, -1, NULL, NULL, NULL);
    vh_logger_write_info("after replace: %s", t1);
    g_free(t1);
    */

}

