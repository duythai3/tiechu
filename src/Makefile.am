# vim:set noet ts=4:
#
# ibus-anthy - The template engine for IBus
#
# Copyright (c) 2007-2011 Peng Huang <shawn.p.huang@gmail.com>
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


libexec_PROGRAMS = ibus-engine-viethoa

ibus_engine_viethoa_SOURCES = \
	main.c \
	engine.c \
	engine.h \
	vhutil.h \
	vhutil.c \
	vhustring.h \
	vhustring.c \
    VHTelexEditor2.h \
    VHTelexEditor2.c \
	VHVNLetters.h \
    VHZTelexTable2.h \
    VHZTelexTable2.c \
	VHPropertyList.h \
	VHPropertyList.c \
	VHConfiguration.h \
	VHConfiguration.c \
	VHLogger.h \
	VHLogger.c \
    VHCandidateTable.h \
    VHCandidateTable.c \
	VHViethoaTable.h \
	VHViethoaTable.c \
	VHCandidateArray.h \
	VHCandidateArray.c \
	VHEnglishMode.h \
	VHEnglishMode.c \
	VHVietnameseMode.h \
	VHVietnameseMode.c \
	VHViethoaMode.h \
	VHViethoaMode.c \
	VHTeochewMode.h \
	VHTeochewMode.c \
	VHChineseMode.h \
	VHChineseMode.c \
	VHHelper.h \
	VHHelper.c \
	VHDatabase.h \
	VHDatabase.c \
	VHPreedit.h \
	VHPreedit.c \
	VHPinyinTable.h \
	VHPinyinTable.c \
    VHPinyinEditor.c \
	VHPinyinEditor.h \
	VHChineseTable.h \
	VHChineseTable.c \
    VHLTelexTable.h \
    VHLTelexTable.c \
    VHETelexTable.h \
    VHETelexTable.c \
    VHTeochewEditor.c \
    VHTeochewEditor.h \
    VHTeochewTable.h \
    VHTeochewTable.c \
    VHInterchangeMode.h \
    VHInterchangeMode.c \
    $(NULL)

ibus_engine_viethoa_CFLAGS = \
	@IBUS_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	-DPKGDATADIR=\"$(pkgdatadir)\"\
	$(NULL)
	
ibus_engine_viethoa_LDFLAGS = \
	@IBUS_LIBS@ \
	@SQLITE_LIBS@ \
	$(NULL)

component_DATA = \
	viethoa.xml \
	$(NULL)
componentdir = @datadir@/ibus/component

EXTRA_DIST = \
	viethoa.xml.in \
	$(NULL)

CLEANFILES = \
	viethoa.xml \
	$(NULL)

viethoa.xml: viethoa.xml.in
	$(AM_V_GEN) \
	( \
		libexecdir=${libexecdir}; \
		pkgdatadir=${pkgdatadir}; \
		s=`cat $<`; \
		eval "echo \"$${s}\""; \
	) > $@

test: ibus-engine-viethoa
	$(builddir)/ibus-engine-viethoa
