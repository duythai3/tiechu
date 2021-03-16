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
#ifndef __VHINTERCHANGEMODE_H__
#define __VHINTERCHANGEMODE_H__
#include <glib.h>

//Length of interchange mode in microsecond
#define __INTERCHANGE_MODE_PERIOD__ 2000000

void vh_interchange_mode_turn_shift_pressed_on();
void vh_interchange_mode_turn_shift_pressed_off();
gboolean vh_interchange_mode_is_shift_pressed_on();
void vh_interchange_mode_save_begin_interchange_mode_time();
gboolean vh_interchange_mode_is_in_interchange_mode();

#endif // VHINTERCHANGEMODE_H
