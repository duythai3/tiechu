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

#ifndef __TEOCHEW_EDITOR__
#define __TEOCHEW_EDITOR__

#include "UString.h"
#include "engine.h"

gboolean teochew_editor_process(IBusTiechuEngine* tiechu, guint keyval, guint keycode, guint modifiers);
gboolean teochew_editor_is_signal_letter(guint keyval);
gboolean teochew_editor_is_preedit_containing_tone();

#endif
