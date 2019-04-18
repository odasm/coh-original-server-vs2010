#! /usr/bin/perl
#
#   This file is part of the WebKit project
#
#   Copyright (C) 1999 Waldo Bastian (bastian@kde.org)
#   Copyright (C) 2007 Apple Inc. All rights reserved.
#   Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies)
#
#   This library is free software; you can redistribute it and/or
#   modify it under the terms of the GNU Library General Public
#   License as published by the Free Software Foundation; either
#   version 2 of the License, or (at your option) any later version.
#
#   This library is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
#   Library General Public License for more details.
#
#   You should have received a copy of the GNU Library General Public License
#   along with this library; see the file COPYING.LIB.  If not, write to
#   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
#   Boston, MA 02110-1301, USA.
use strict;
use warnings;

open NAMES, "<CSSValueKeywords.in" || die "Could not open CSSValueKeywords.in";
my @names = ();
while (<NAMES>) {
  next if (m/(^#)|(^\s*$)/);
  # Input may use a different EOL sequence than $/, so avoid chomp.
  $_ =~ s/[\r\n]+$//g;
  push @names, $_;
}
close(NAMES);

open GPERF, ">CSSValueKeywords.gperf" || die "Could not open CSSValueKeywords.gperf for writing";
print GPERF << "EOF";
%{
/* This file is automatically generated from CSSValueKeywords.in by makevalues, do not edit */

#include \"CSSValueKeywords.h\"
%}
struct css_value {
    const char* name;
    int id;
};
%%
EOF

foreach my $name (@names) {
  my $id = $name;
  $id =~ s/(^[^-])|-(.)/uc($1||$2)/ge;
  print GPERF $name . ", CSSValue" . $id . "\n";
}
print GPERF "%%\n";
close GPERF;

open HEADER, ">CSSValueKeywords.h" || die "Could not open CSSValueKeywords.h for writing";
print HEADER << "EOF";
/* This file is automatically generated from CSSValueKeywords.in by makevalues, do not edit */

#ifndef CSSValues_h
#define CSSValues_h

const int CSSValueInvalid = 0;
EOF

my $i = 1;
my $maxLen = 0;
foreach my $name (@names) {
  my $id = $name;
  $id =~ s/(^[^-])|-(.)/uc($1||$2)/ge;
  print HEADER "const int CSSValue" . $id . " = " . $i . ";\n";
  $i = $i + 1;
  if (length($name) > $maxLen) {
    $maxLen = length($name);
  }
}
print HEADER "const int numCSSValueKeywords = " . $i . ";\n";
print HEADER "const size_t maxCSSValueKeywordLength = " . $maxLen . ";\n";
print HEADER << "EOF";

const char* getValueName(unsigned short id);

#endif
EOF
close HEADER;

system("gperf -L ANSI-C -E -C -n -o -t --key-positions=\"*\" -NfindValue -Hhash_val -Wwordlist_value -D CSSValueKeywords.gperf > CSSValueKeywords.c") == 0 || die "calling gperf failed: $?";

open C, ">>CSSValueKeywords.c" || die "Could not open CSSValueKeywords.c for writing";
print C  "static const char * const valueList[] = {\n";
print C  "\"\",\n";
foreach my $name (@names) {
  print C  "\"" . $name . "\", \n";
}
print C << "EOF";
    0
};
const char* getValueName(unsigned short id)
{
    if (id >= numCSSValueKeywords || id <= 0)
        return 0;
    return valueList[id];
}
EOF

close C;
