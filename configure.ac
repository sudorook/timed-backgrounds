AC_PREREQ([2.68])

AC_INIT([timed-backgrounds],
        [0.5.0],
        [https://github.com/sudorook/timed-backgrounds/issues],
        [timed-backgrounds])

AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE([enable])
AC_PREFIX_DEFAULT(/usr)
AM_SILENT_RULES([yes])

AC_PROG_CC_C99
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
