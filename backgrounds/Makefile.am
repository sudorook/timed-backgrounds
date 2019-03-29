backgrounddir = $(datadir)/backgrounds/timed
background_DATA = firewatch.jpg \
                  firewatch-day.jpg \
                  firewatch-night.jpg \
                  firewatch-timed.xml \
                  island-day.jpg \
                  island-night.jpg \
                  island-timed.xml \
                  metropolis-day.jpg \
                  metropolis-dusk.jpg \
                  metropolis-night.jpg \
                  metropolis-timed.xml \
                  mountainside-day.jpg \
                  mountainside-night.jpg \
                  mountainside-timed.xml

gnomepropdir = $(datadir)/gnome-background-properties
gnomeprop_DATA = timed.xml

matepropdir = $(datadir)/mate-background-properties
mateprop_DATA = timed.xml

cinnamonpropdir = $(datadir)/cinnamon-background-properties
cinnamonprop_DATA = timed.xml

noinst_DATA = timed.xml.in \
              firewatch-timed.xml.in \
              island-timed.xml.in \
              metropolis-timed.xml.in \
              mountainside-timed.xml.in

set_time = ../src/settime

edit = sed -i 's|\@datadir\@|$(datadir)|g'

%.xml: %.xml.in $(set_time)
	$(AM_V_GEN) $(set_time) $<
	$(AM_V_GEN) $(edit) $@


CLEANFILES = timed.xml \
             firewatch-timed.xml \
             island-timed.xml \
             metropolis-timed.xml \
             mountainside-timed.xml

DISTCLEANFILES = Makefile.in

uninstall-hook:
	-rmdir $(backgrounddir)
	-rmdir ${datadir}/backgrounds
	-rmdir $(gnomepropdir)
	-rmdir $(matepropdir)
	-rmdir $(cinnamonpropdir)
