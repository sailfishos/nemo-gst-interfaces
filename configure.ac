dnl required version of autoconf
AC_PREREQ([2.53])

AC_INIT

dnl required versions of gstreamer and plugins-base
GST_REQUIRED=1.0
GSTPB_REQUIRED=1.0

AC_CONFIG_SRCDIR([gst-libs/Makefile.am])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([nemo-gst-interfaces], [$VERSION])

dnl enable mainainer mode by default
AM_MAINTAINER_MODE([enable])

dnl check for tools (compiler etc.)
AC_PROG_CC

dnl required version of libtool
LT_PREREQ([2.2.6])
LT_INIT

dnl give error and exit if we don't have pkgconfig
AC_CHECK_PROG(HAVE_PKGCONFIG, pkg-config, [ ], [
  AC_MSG_ERROR([You need to have pkg-config installed!])
])

dnl Check for the required version of GStreamer core (and gst-plugins-base)
dnl This will export GST_CFLAGS and GST_LIBS variables for use in Makefile.am
PKG_CHECK_MODULES(GST, [
  gstreamer-1.0 >= $GST_REQUIRED
  gstreamer-base-1.0 >= $GST_REQUIRED
  gstreamer-video-1.0 >= $GST_REQUIRED
], [
  AC_SUBST(GST_CFLAGS)
  AC_SUBST(GST_LIBS)
], [
  AC_MSG_ERROR([
      You need to install or upgrade the GStreamer development
      packages on your system.
  ])
])

dnl check if compiler understands -Wall (if yes, add -Wall to GST_CFLAGS)
AC_MSG_CHECKING([to see if compiler understands -Wall])
save_CFLAGS="$CFLAGS"
CFLAGS="$CFLAGS -Wall"
AC_COMPILE_IFELSE([AC_LANG_PROGRAM([ ], [ ])], [
  GST_CFLAGS="$GST_CFLAGS -Wall"
  AC_MSG_RESULT([yes])
], [
  AC_MSG_RESULT([no])
])

GST_MAJORMINOR=1.0
AC_SUBST(GST_MAJORMINOR)

AC_CONFIG_FILES([Makefile
		nemo-gstreamer-interfaces-$GST_MAJORMINOR.pc
		nemo-gstreamer-meta-$GST_MAJORMINOR.pc
		gst-libs/Makefile
		gst-libs/gst/Makefile
		gst-libs/gst/interfaces/Makefile
		gst-libs/gst/meta/Makefile
		])
AC_OUTPUT
