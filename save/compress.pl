#!/usr/bin/perl -w

use strict;

open TMP, "> tsort.$$" or die $!;

while (<>) {
    chomp;
    foreach my $o (0 .. length() - 1) {
        foreach my $l (3 .. length() - $o) {
            print TMP substr($_, $o, $l) . "\n";
        }
    }
}

my $results = `sort tsort.$$ | \
               uniq -c | \
               sort -n`;

unlink "tsort.$$";

my @save;
foreach (split '\n', $results) {
    m/^\s*([0-9]+) (.*)$/;
    next if $2 =~ /^\s/;
    next if $2 =~ /\s$/;
    my $save = ($1 * (length($2) - 2)) - length("#define _a $2\n");
    next if $save < 1;
    push(@save, "$save\t$1\t'$2'\n");
}

foreach (sort { my($n1) = split '\t', $a; my($n2) = split '\t', $b; $n2 <=> $n1 } @save) {
    print $_;
}
