# The Tiechu engine for  IBus
#
# Copyright (c) 2020-2022 Duy Thai,duythaia3@gmail.com
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

SUBDIRS = \
	src \
	icons \
	config \
	csdl \
	m4 \
	$(NULL)

ACLOCAL_AMFLAGS = -I m4

EXTRA_DIST = \
	autogen.sh \
	@PACKAGE_NAME@.spec.in \
	$(NULL)

noinst_DIST = \
	$(NULL)


DISTCLEANFILES = \
	po/stamp-it \
	$(NULL)

install-exec-hook:
	chmod 777 -R $(pkgdatadir)/csdl

rpm: dist @PACKAGE_NAME@.spec
	rpmbuild -bb \
			--define "_sourcedir `pwd`" \
			--define "_builddir `pwd`" \
			--define "_specdir `pwd`" \
			--define "_rpmdir `pwd`" \
			--define "_srcrpmdir `pwd`" \
			@PACKAGE_NAME@.spec
clean-rpm:
	$(RM) -r "`uname -i`"

clean-local: clean-rpm
