# SPDX-FileCopyrightText: 2019 sudorook <daemon@nullcodon.com>
#
# SPDX-License-Identifier: GPL-3.0-or-later
#
# This program is free software: you can redistribute it and/or modify it
# under the terms of the GNU General Public License as published by the Free
# Software Foundation, either version 3 of the License, or (at your option)
# any later version.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
# or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
# for more details.
#
# You should have received a copy of the GNU General Public License along
# with this program. If not, see <https://www.gnu.org/licenses/>.

noinst_PROGRAMS = settime

settime_SOURCES = main.c main.h \
                  solar.c solar.h \
                  config-ini.c config-ini.h \
                  location-geoclue2.c location-geoclue2.h \
                  location-manual.c location-manual.h \
                  pipeutils.c pipeutils.h \
                  systemtime.c systemtime.h

AM_CFLAGS = -g -Wall \
            $(shell pkg-config --cflags \
              glib-2.0 gobject-2.0 gio-2.0 geoclue-2.0 libxml-2.0)

LIBS = -lm \
       $(shell pkg-config --libs \
         glib-2.0 gobject-2.0 gio-2.0 geoclue-2.0 libxml-2.0)

DISTCLEANFILES =  Makefile.in
