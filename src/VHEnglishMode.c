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
#include <glib.h>
#include <ibus.h>
#include "engine.h"
#include "VHConfiguration.h"
#include "VHEnglishMode.h"
#include "VHPropertyList.h"
#include "VHCandidateTable.h"
#include "VHLogger.h"
#include "VHViethoaTable.h"
#include "VHHelper.h"


gboolean vh_english_mode_process_key_event(IBusViethoaEngine* viethoa, guint keyval, guint keycode, guint modifiers) {
	vh_logger_log("manage_mode: keyval: %d, keycode: %d, modifiers: %d", keyval, keycode, modifiers);
	return FALSE;
}
