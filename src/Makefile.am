# The Abacus engine for IBus
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


libexec_PROGRAMS = Abacus

Abacus_SOURCES = \
	main.c \
	engine.c \
	engine.h \
	AUtil.h \
	AUtil.c \
	AUString.h \
	AUString.c \
    ATelexEditor2.h \
    ATelexEditor2.c \
	AVNLetters.h \
    AZTelexTable2.h \
    AZTelexTable2.c \
	APropertyList.h \
	APropertyList.c \
	AConfiguration.h \
	AConfiguration.c \
	ALogger.h \
	ALogger.c \
    ACandidateTable.h \
    ACandidateTable.c \
	AHanvietTable.h \
	AHanvietTable.c \
	ACandidateArray.h \
	ACandidateArray.c \
	AEnglishMode.h \
	AEnglishMode.c \
	AVietnameseMode.h \
	AVietnameseMode.c \
	AHanvietMode.h \
	AHanvietMode.c \
	ATeochewMode.h \
	ATeochewMode.c \
	AChineseMode.h \
	AChineseMode.c \
	AHelper.h \
	AHelper.c \
	ADatabase.h \
	ADatabase.c \
	APreedit.h \
	APreedit.c \
	APinyinTable.h \
	APinyinTable.c \
    APinyinEditor.c \
	AHPinyinEditor.h \
	AChineseTable.h \
	AChineseTable.c \
    ALTelexTable.h \
    ALTelexTable.c \
    AETelexTable.h \
    AETelexTable.c \
    ATeochewEditor.c \
    ATeochewEditor.h \
    ATeochewTable.h \
    ATeochewTable.c \
    AInterchangeMode.h \
    AInterchangeMode.c \
    $(NULL)

Abacus_CFLAGS = \
	@IBUS_CFLAGS@ \
	@SQLITE_CFLAGS@ \
	-DPKGDATADIR=\"$(pkgdatadir)\"\
	$(NULL)

Abacus_LDFLAGS = \
	@IBUS_LIBS@ \
	@SQLITE_LIBS@ \
	$(NULL)

component_DATA = \
	Abacus.xml \
	$(NULL)
componentdir = @datadir@/ibus/component

EXTRA_DIST = \
	Abacus.xml.in \
	$(NULL)

CLEANFILES = \
	Abacus.xml \
	$(NULL)

Abacus.xml: Abacus.xml.in
	$(AM_V_GEN) \
	( \
		libexecdir=${libexecdir}; \
		pkgdatadir=${pkgdatadir}; \
		s=`cat $<`; \
		eval "echo \"$${s}\""; \
	) > $@

test: Abacus
	$(builddir)/Abacus
