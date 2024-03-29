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
#include <glib/gprintf.h>
#include "Database.h"
#include "Logger.h"


static sqlite3 *_connection = NULL;


// initialize
gboolean database_open(){
	//
	if (_connection) {
		return TRUE;
	}

	//
    int ret = sqlite3_open(PKGDATADIR"/csdl/Tiechu.db", &_connection);
	if(ret != SQLITE_OK){
        logger_error("Can't open database Tiechu.db: %s", sqlite3_errmsg(_connection));
		if (_connection) {
			sqlite3_close(_connection);
			_connection = NULL;
		}
		return FALSE;
	}

	//
    logger_log("Tiechu database opened");
	return TRUE;
}


// destroy
void database_close(){
	//
	if (!_connection) {
		return;
	}

	//
	sqlite3_close(_connection);
	_connection = NULL;
    logger_log("Tiechu database closed");
}

sqlite3* database_get_connection(){
	return _connection;
}
