SUBDIRS = src \
          backgrounds

EXTRA_DIST = LICENSE \
             autogen.sh \
             README.md

DISTCLEANFILES = Makefile.in \
                 install-sh \
                 install-sh~ \
                 aclocal.m4 \
                 configure \
                 configure~ \
                 missing

distclean-local:
	rm -rf autom4te.cache \
	rm -f compile \
	rm -f depcomp \
	rm -rf src/.deps/
