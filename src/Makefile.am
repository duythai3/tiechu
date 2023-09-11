# The Tiechu engine for IBus
#
# Copyright (c) 2020-2022 Duy Thai, duythaiz234@gmail.com
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


libexec_PROGRAMS = Tiechu

Tiechu_SOURCES = \
	main.c \
	engine.c \
	engine.h \
        Util.h \
        Util.c \
        UString.h \
        UString.c \
    TelexEditor2.h \
    TelexEditor2.c \
        VNLetters.h \
    ZTelexTable2.h \
    ZTelexTable2.c \
        PropertyList.h \
        PropertyList.c \
        Configuration.h \
        Configuration.c \
        Logger.h \
        Logger.c \
    CandidateTable.h \
    CandidateTable.c \
        HanvietTable.h \
        HanvietTable.c \
        CandidateArray.h \
        CandidateArray.c \
        EnglishMode.h \
        EnglishMode.c \
        VietnameseMode.h \
        VietnameseMode.c \
        HanvietMode.h \
        HanvietMode.c \
        TeochewMode.h \
        TeochewMode.c \
        ChineseMode.h \
        ChineseMode.c \
        Helper.h \
        Helper.c \
        Database.h \
        Database.c \
        Preedit.h \
        Preedit.c \
        PinyinTable.h \
        PinyinTable.c \
    PinyinEditor.c \
        PinyinEditor.h \
        ChineseTable.h \
        ChineseTable.c \
    LTelexTable.h \
    LTelexTable.c \
    ETelexTable.h \
    ETelexTable.c \
    TeochewEditor.c \
    TeochewEditor.h \
    TeochewTable.h \
    TeochewTable.c \
    InterchangeMode.h \
    InterchangeMode.c \
    $(NULL)

Tiechu_CFLAGS = \
	@IBUS_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	-DPKGDATADIR=\"$(pkgdatadir)\"\
	$(NULL)

Tiechu_LDFLAGS = \
	@IBUS_LIBS@ \
	@SQLITE_LIBS@ \
	$(NULL)

component_DATA = \
        Tiechu.xml \
	$(NULL)
componentdir = @datadir@/ibus/component

EXTRA_DIST = \
        Tiechu.xml.in \
	$(NULL)

CLEANFILES = \
        Tiechu.xml \
	$(NULL)

Tiechu.xml: Tiechu.xml.in
	$(AM_V_GEN) \
	( \
		libexecdir=${libexecdir}; \
		pkgdatadir=${pkgdatadir}; \
		s=`cat $<`; \
		eval "echo \"$${s}\""; \
	) > $@

test: Tiechu
        $(builddir)/Tiechu
