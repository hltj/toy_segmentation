#!/bin/sh
#----------------------------------------------------------------------
# Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
# License:   LGPLv3
#----------------------------------------------------------------------

DATADIR="`dirname $0`/../data"
HZTEXTDIR="$DATADIR/hz_txt"
UCS4TEXTDIR="$DATADIR/ucs4_txt"
PHRASINGDIR="$DATADIR/ucs4_phr"

mkdir "$UCS4TEXTDIR" "$PHRASINGDIR" 2> /dev/null

i=001
while [ $i -le 120 ]
do
	echo "== $i =="
	iconv --binary -f utf-8 -t ucs-4-internal "$HZTEXTDIR/$i.txt" > "$UCS4TEXTDIR/$i.txt"
	./phrase "$UCS4TEXTDIR/$i.txt" "$PHRASINGDIR/$i.txt"
	i=`expr $i + 1`
	i=`printf "%03d" $i`
done
cat "$UCS4TEXTDIR/"???.txt > "$UCS4TEXTDIR/txt_all.txt"
echo "== all =="
./phrase "$UCS4TEXTDIR/txt_all.txt" "$PHRASINGDIR/txt_all.txt"
