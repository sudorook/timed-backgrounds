dnl SPDX-FileCopyrightText: 2017 - 2021 sudorook <daemon@nullcodon.com>
dnl
dnl SPDX-License-Identifier: GPL-3.0-or-later
dnl
dnl This program is free software: you can redistribute it and/or modify it
dnl under the terms of the GNU General Public License as published by the Free
dnl Software Foundation, either version 3 of the License, or (at your option)
dnl any later version.
dnl
dnl This program is distributed in the hope that it will be useful, but
dnl WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
dnl or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
dnl for more details.
dnl
dnl You should have received a copy of the GNU General Public License along
dnl with this program. If not, see <https://www.gnu.org/licenses/>.

AC_PREREQ([2.68])

AC_INIT([timed-backgrounds],
        [0.5.2],
        [https://github.com/sudorook/timed-backgrounds/issues],
        [timed-backgrounds])

AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE([enable])
AC_PREFIX_DEFAULT(/usr)
AM_SILENT_RULES([yes])

AC_PROG_CC
AC_LANG([C])

PKG_CHECK_MODULES([GLIB], [glib-2.0 gobject-2.0], [have_glib=yes], [have_glib=no])
PKG_CHECK_MODULES([GEOCLUE2], [geoclue-2.0 gio-2.0], [have_geoclue2=yes], [have_geoclue2=no])
PKG_CHECK_MODULES([XML], [libxml-2.0], [have_xml=yes], [have_xml=no])

# Checks for header files.
AC_CHECK_HEADERS([locale.h stdint.h stdlib.h string.h unistd.h signal.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_UINT16_T

AC_CONFIG_FILES([Makefile backgrounds/Makefile src/Makefile])

AC_OUTPUT
