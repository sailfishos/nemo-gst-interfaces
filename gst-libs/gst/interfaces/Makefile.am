lib_LTLIBRARIES = libgstnemointerfaces-@GST_MAJORMINOR@.la
libgstnemointerfacesincludedir = \
        $(includedir)/gstreamer-@GST_MAJORMINOR@/gst/interfaces

libgstnemointerfacesinclude_HEADERS = nemoeglimagememory.h nemovideotexture.h
libgstnemointerfaces_@GST_MAJORMINOR@_la_SOURCES = nemoeglimagememory.c nemovideotexture.c
libgstnemointerfaces_@GST_MAJORMINOR@_la_CFLAGS = $(GST_CFLAGS)
libgstnemointerfaces_@GST_MAJORMINOR@_la_LIBADD = $(GST_LIBS)
libgstnemointerfaces_@GST_MAJORMINOR@_la_LDFLAGS = $(GST_LIB_LDFLAGS) $(GST_LT_LDFLAGS)
