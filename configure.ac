AC_PREREQ([2.68])

AC_INIT([timed-backgrounds],
        [0.2.0],
        [https://github.com/sudorook/timed-backgrounds/issues],
        [timed-backgrounds])

AM_INIT_AUTOMAKE([foreign])
AM_MAINTAINER_MODE([enable])
AC_PREFIX_DEFAULT(/usr)
AM_SILENT_RULES([yes])

AC_CONFIG_FILES([Makefile backgrounds/Makefile])

AC_CHECK_PROG(CURL_CHECK, curl, yes)
if test x"$CURL_CHECK" != x"yes"; then
  AC_MSG_ERROR(["curl" executable is not installed.])
fi
AC_CHECK_PROG(JQ_CHECK, jq, yes)
if test x"$JQ_CHECK" != x"yes"; then
  AC_MSG_ERROR(["jq" executable is not installed.])
fi

AC_OUTPUT
