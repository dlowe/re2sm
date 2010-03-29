#!/bin/sh

SENDMAIL=`which sendmail`

if [ "X$SENDMAIL" = "X" ]; then
    echo "Please modify the SENDMAIL variable in this script ($0) to "
    echo "point to your sendmail binary"
    exit
fi

if [ ! -x "$SENDMAIL" ]; then
    echo "Please modify the SENDMAIL variable in this script ($0) to "
    echo "point to your sendmail binary"
    exit
fi

if [ ! -f out.cf ]; then
    echo "You need to run prog first, and direct the output to out.cf"
    exit
fi

(echo <<EOM
Mlocal, P=prog, A=prog -l
O QueueDirectory=.
EOM
cat out.cf) > test.cf

$SENDMAIL -C test.cf -bt -d21.12

rm test.cf
