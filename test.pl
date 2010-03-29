#!/usr/bin/perl

use strict;
use warnings;

my $i = 0;
while (-e "test/$i.in" && -e "test/$i.out") {
   print "test $i...";
   my $re      = `cat test/$i.in`;
   chomp $re;
   my $compare = `cat test/$i.out | sort`;
   my $result  = `./re2sm '$re' 2>&1 | sort`;
   if ($result eq $compare) {
       print "ok\n";
   } else {
       print "NOT OK\n";
       print "--- expected\n$compare\n---result\n$result\n---\n";
   }
   ++$i;
}
