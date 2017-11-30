# Must init the autoconf setup
# The first parameter is project name
# second is version number
# third is bug report address
AC_INIT([cluesc], [1.0])

# Safety checks in case user overwritten --srcdir
AC_CONFIG_SRCDIR([cluesc.c])

# Init automake, and specify this program use relaxed structures.
# i.e. this program doesn't follow the gnu coding standards, and doesn't have
# ChangeLog, COPYING, AUTHORS, INSTALL, README etc. files.
AM_INIT_AUTOMAKE([-Wall -Werror foreign])

# Check for C compiler
AC_PROG_CC
AC_CHECK_HEADERS([stdio.h])
AC_CHECK_LIB([ncurses],[initscr])
AC_CHECK_LIB([ncurses],[raw])
AC_CHECK_LIB([ncurses],[keypad])
AC_CHECK_LIB([ncurses],[noecho])
AC_CHECK_LIB([ncurses],[printw])
AC_CHECK_LIB([ncurses],[refresh])
AC_CHECK_LIB([ncurses],[getch])
AC_CHECK_LIB([ncurses],[endwin])
# We can add more checks in this section

# Tells automake to create a Makefile
# See https://www.gnu.org/software/automake/manual/html_node/Requirements.html
AC_CONFIG_FILES([Makefile])

# Generate the output
AC_OUTPUT
