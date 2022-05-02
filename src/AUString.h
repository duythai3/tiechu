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
#ifndef __A_U_STRING__
#define __A_U_STRING__

#include <glib.h>

typedef struct _AUString AUString;

struct _AUString {
    gunichar* str;
    gsize len;
    gsize allocated_len;
};

AUString* a_ustring_new();
void a_ustring_free(AUString* ustring);

void a_ustring_append(AUString *s,guint keyval);
guint a_ustring_get(AUString *s,gsize index);
void a_ustring_set(AUString *s,gsize index,guint keyval);
void a_ustring_clear(AUString *s);
gchar* a_ustring_to_utf8(AUString *s);
void a_ustring_insert(AUString *s,guint index,guint keyval);
void a_ustring_delete(AUString *s,guint index);
void a_ustring_replace(AUString *s,guint index,guint len,gunichar* str,guint str_len);

#endif
