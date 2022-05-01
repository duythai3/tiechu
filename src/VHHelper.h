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
#ifndef SRC_VHHELPER_H_
#define SRC_VHHELPER_H_

#include "engine.h"

#define is_alpha(c) (((c) >= IBUS_a && (c) <= IBUS_z) || ((c) >= IBUS_A && (c) <= IBUS_Z))
#define is_digit(c) ((c) >= IBUS_0 && (c) <= IBUS_9)
#define is_kp_digit(c) ((c) >= IBUS_KP_0 && (c) <= IBUS_KP_9)
#define convert_kp_digit_to_digit(c) (c - IBUS_KP_0 + IBUS_0)

// is teochew tone digit
#define is_teochew_tone_digit(c) ((c) >= IBUS_1 && (c) <= IBUS_8)

void vh_helper_clear_preedit(IBusAbacusEngine* viethoa);

void vh_helper_commit_preedit(IBusAbacusEngine* viethoa);

void vh_helper_update_preedit(IBusAbacusEngine* viethoa);

gboolean vh_helper_commit_candidate_in_page(IBusAbacusEngine *viethoa, guint index);

gboolean vh_helper_commit_current_candidate(IBusAbacusEngine *viethoa);

gboolean vh_helper_process_escape(IBusAbacusEngine* viethoa, guint keyval, guint keycode, guint modifiers);

gboolean vh_helper_is_control_pressed(guint modifiers);

gboolean vh_helper_is_event_released(guint modifiers);

gboolean vh_helper_is_alt_pressed(guint modifiers);

gboolean vh_helper_is_escape_pressed(guint keycode);

void vh_helper_hide_preedit(IBusAbacusEngine* viethoa);

gboolean vh_helper_is_ignore_key(guint keyval);

#endif /* SRC_VHHELPER_H_ */
