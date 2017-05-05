backgrounddir = $(datadir)/backgrounds/extra
background_DATA = firewatch.jpg \
		  firewatch-day.jpg \
		  firewatch-night.jpg \
		  firewatch-sunset.jpg \
		  firewatch-timed.xml \
		  island-night.jpg \
		  island-day.jpg \
		  island-timed.xml

metadatadir = $(datadir)/gnome-background-properties
#metadatadir = $(datadir)/mate-background-properties
#metadatadir = $(datadir)/cinnamon-background-properties
metadata_DATA = extra-backgrounds.xml

noinst_DATA = extra-backgrounds.xml.in \
	      firewatch-timed.xml.in \
	      island-timed.xml.in

edit = sed -e 's|\@datadir\@|$(datadir)|g'

%.xml: %.xml.in
	$(AM_V_GEN) $(edit) $< >$@
 
# extra-backgrounds.xml: extra-backgrounds.xml.in
#         $(AM_V_GEN) $(edit) $< >$@
# 
# firewatch-timed.xml: firewatch-timed.xml.in
#         $(AM_V_GEN) $(edit) $< >$@
# 
# island-timed.xml: island-timed.xml.in
#         $(AM_V_GEN) $(edit) $< >$@

CLEANFILES = extra-backgrounds.xml \
	     firewatch-timed.xml \
	     island-timed.xml

DISTCLEANFILES = Makefile.in

uninstall-hook:
	-rmdir $(backgrounddir)
