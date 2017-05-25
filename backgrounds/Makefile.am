backgrounddir = $(datadir)/backgrounds/extra
background_DATA = firewatch.jpg \
                  firewatch-day.jpg \
                  firewatch-night.jpg \
                  firewatch-timed.xml \
                  island-day.jpg \
                  island-night.jpg \
                  island-timed.xml

gnomepropdir = $(datadir)/gnome-background-properties
gnomeprop_DATA = extra-backgrounds.xml

matepropdir = $(datadir)/mate-background-properties
mateprop_DATA = extra-backgrounds.xml

cinnamonpropdir = $(datadir)/cinnamon-background-properties
cinnamonprop_DATA = extra-backgrounds.xml

noinst_DATA = extra-backgrounds.xml.in \
              firewatch-timed.xml.in \
              island-timed.xml.in

edit = sed -e 's|\@datadir\@|$(datadir)|g'

%.xml: %.xml.in
	$(AM_V_GEN) $(edit) $< >$@

CLEANFILES = extra-backgrounds.xml \
             firewatch-timed.xml \
             island-timed.xml

DISTCLEANFILES = Makefile.in

uninstall-hook:
	-rmdir $(backgrounddir)
	-rmdir $(gnomepropdir)
	-rmdir $(matepropdir)
	-rmdir $(cinnamonpropdir)
