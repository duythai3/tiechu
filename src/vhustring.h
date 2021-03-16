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
#ifndef __VH_U_STRING__
#define __VH_U_STRING__

#include <glib.h>

typedef struct _VHUString VHUString;

struct _VHUString {
    gunichar* str;
    gsize len;
    gsize allocated_len;
};

VHUString* vh_ustring_new();
void vh_ustring_free(VHUString* vhustr);

void vh_ustring_append(VHUString *s, guint keyval);
guint vh_ustring_get(VHUString *s, gsize index);
void vh_ustring_set(VHUString *s, gsize index, guint keyval);
void vh_ustring_clear(VHUString *s);
gchar* vh_ustring_to_utf8(VHUString *s);
void vh_ustring_insert(VHUString *s, guint index, guint keyval); 
void vh_ustring_delete(VHUString *s, guint index); 
void vh_ustring_replace(VHUString *s, guint index, guint len, gunichar* str, guint str_len);

#endif
