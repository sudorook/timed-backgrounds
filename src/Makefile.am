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

AM_LDFLAGS = -lm \
	     $(shell pkg-config --libs \
	       glib-2.0 gobject-2.0 gio-2.0 geoclue-2.0 libxml-2.0)

DISTCLEANFILES =  Makefile.in
