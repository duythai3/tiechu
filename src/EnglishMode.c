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

#include <glib.h>
#include <ibus.h>
#include "engine.h"
#include "Configuration.h"
#include "EnglishMode.h"
#include "PropertyList.h"
#include "CandidateTable.h"
#include "Logger.h"
#include "HanvietTable.h"
#include "Helper.h"

gboolean english_mode_process_key_event(IBusTiechuEngine* tiechu, guint keyval, guint keycode, guint modifiers) {
    logger_log("manage_mode: keyval: %d, keycode: %d, modifiers: %d", keyval, keycode, modifiers);
	return FALSE;
}
