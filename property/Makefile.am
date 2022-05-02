# The Abacus engine for IBus
#
# Copyright (c) 2020-2022 Duy Thai,duythaiz234@gmail.com
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


libexec_PROGRAMS = Abacus-property

Abacus_property_SOURCES = \
	main.c \
	$(NULL)

Abacus_property_CFLAGS = \
	@LIBJSON_CFLAGS@ \
	@LIBGTK3_CFLAGS@ \
	-DPKGDATADIR=\"$(pkgdatadir)\" \
	$(NULL)

Abacus_property_LDFLAGS = \
	@LIBJSON_LIBS@ \
	@LIBGTK3_LIBS@ \
	$(NULL)
