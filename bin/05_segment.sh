#!/bin/sh
#----------------------------------------------------------------------
# Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
# License:   LGPLv3
#----------------------------------------------------------------------

DATADIR="`dirname $0`/../data"
PHRASINGDIR="$DATADIR/ucs4_phr"
DICTDIR="$DATADIR/ucs4_dict"
SEGDIR="$DATADIR/ucs4_seg"

mkdir "$SEGDIR" 2> /dev/null

i=001
while [ $i -le 120 ]
do
	echo "== $i =="
	./segment "$PHRASINGDIR/$i.txt" "$DICTDIR/txt_all.txt" "$SEGDIR/$i.txt"
	i=`expr $i + 1`
	i=`printf "%03d" $i`
done
echo "== all =="
./segment "$PHRASINGDIR/txt_all.txt" "$DICTDIR/txt_all.txt" "$SEGDIR/txt_all.txt"
