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
#ifndef __U_STRING__
#define __U_STRING__

#include <glib.h>

typedef struct _UString UString;

struct _UString {
    gunichar* str;
    gsize len;
    gsize allocated_len;
};

UString* ustring_new();
void ustring_free(UString* ustring);

void ustring_append(UString *s,guint keyval);
guint ustring_get(UString *s,gsize index);
void ustring_set(UString *s,gsize index,guint keyval);
void ustring_clear(UString *s);
gchar* ustring_to_utf8(UString *s);
void ustring_insert(UString *s,guint index,guint keyval);
void ustring_delete(UString *s,guint index);
void ustring_replace(UString *s,guint index,guint len,gunichar* str,guint str_len);

#endif
