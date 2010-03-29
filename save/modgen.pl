#!/usr/bin/perl -w

@numbers = ( 43, 45, 42, 47, 37, 94, 99, 112, 80, 102, 100, 114, );
$try   = $#numbers;
$found = 0;

while (! $found) {
    $try++;

    @results = ();

    foreach $num (@numbers) {
        push @results, $num % $try;
    }

    @results = sort { $a <=> $b } @results;
    $found = 1;
    $last  = -1;
    foreach $res (@results) {
        if ($res == $last) {
            $found = 0;
            last;
        }
        $last = $res;
    }
}

foreach $num (@numbers) {
    print "$num % $try == " . $num % $try . "\n";
    print "  [" . chr($num) . "] letter = " . chr(($num % $try) + 81) . "\n";
    foreach $character (0..128) {
        if ((chr($character) !~ /\d/) && ($character != $num) && (($character % $try) == ($num % $try))) {
            print "  synonym: " . chr($character) . " [$character]\n";
        }
    }
}
