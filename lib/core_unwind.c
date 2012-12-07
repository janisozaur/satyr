/*
    core_unwind.c

    Copyright (C) 2012  Red Hat, Inc.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/
#include "core_unwind.h"
#include "utils.h"

#if (defined HAVE_LIBELF_H && defined HAVE_GELF_H && defined HAVE_LIBELF && defined HAVE_LIBDW && defined HAVE_ELFUTILS_LIBDWFL_H)
#  define WITH_LIBDWFL
#endif

#if (defined HAVE_LIBUNWIND && defined HAVE_LIBUNWIND_COREDUMP && defined HAVE_LIBUNWIND_GENERIC && defined HAVE_LIBUNWIND_COREDUMP_H && defined HAVE_LIBELF_H && defined HAVE_GELF_H && defined HAVE_LIBELF && defined HAVE_LIBDW && defined HAVE_ELFUTILS_LIBDWFL_H)
#  define WITH_LIBUNWIND
#endif

#if !defined WITH_LIBDWFL && !defined WITH_LIBUNWIND

struct btp_core_stacktrace *
btp_parse_coredump(const char *core_file,
                   const char *exe_file,
                   char **error_msg)
{
    *error_msg = btp_asprintf("Btparser is built without unwind support");
    return NULL;
}

#endif