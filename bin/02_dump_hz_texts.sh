#!/bin/sh
# vim:       fenc=utf-8
#----------------------------------------------------------------------
# Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
# License:   LGPLv3
#----------------------------------------------------------------------
# 注意：本文件須以 UTF-8 編碼保存

DATADIR="`dirname $0`/../data"
HTMLDIR="$DATADIR/html"
HZTEXTDIR="$DATADIR/hz_txt"

mkdir "$HZTEXTDIR" 2> /dev/null

export LC_ALL=C
i=001
while [ $i -le 120 ]
do
	echo == $i ==
	file="$HTMLDIR/$i.html"
	lines=`cat $file | wc -l`
	lastline=`expr $lines - 240`
	sed -n "75,"$lastline"p" $file | tr '\n' '#' | sed 's/<[^>]*>//g' | tr '#' '\n' | egrep -v '返回頁首|^上一回$|^下一回$' > "$HZTEXTDIR/$i.txt"
	i=`expr $i + 1`
	i=`printf "%03d" $i`
done
