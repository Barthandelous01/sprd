#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([sprd], [1.1], [])
AM_INIT_AUTOMAKE([foreign])
AC_CONFIG_SRCDIR([src/sprd.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
  Makefile
  src/Makefile
])

# Checks for programs.
AC_PROG_CC

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])
AC_CHECK_HEADERS([signal.h])

# Check for POSIX complience
AC_EGREP_CPP(posix_199309L_supported,
             [#define _POSIX_C_SOURCE 199309L
              #include <unistd.h>
              #ifdef _POSIX_VERSION
              #if _POSIX_VERSION >= 199309L
              posix_199309L_supported
              #endif
              #endif
             ],
             [AC_DEFINE([_POSIX_C_SOURCE], [199309L], [Set POSIX version])],
             []
)

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([mmap])

AC_OUTPUT
