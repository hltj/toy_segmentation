#!/bin/sh
#----------------------------------------------------------------------
# Copyright: 2013   JiaYanwei   <wxmedit@gmail.com>
# License:   LGPLv3
#----------------------------------------------------------------------

# 根據需要設置 wget 代理
# export http_proxy="localhost:8087"
# 根據網絡情況設定 wget 超時和重試參數
WGET_OPT="-T60 -t10 --no-cache"

DATADIR="`dirname $0`/../data"
HTMLDIR="$DATADIR/html"

mkdir -p "$HTMLDIR"

wget $WGET_OPT -O "$HTMLDIR/3guo.html" 'http://zh.wikisource.org/zh-hant/%E4%B8%89%E5%9C%8B%E6%BC%94%E7%BE%A9'
i=001
while [ $i -le 120 ]
do
	wget $WGET_OPT -O "$HTMLDIR/$i.html" 'http://zh.wikisource.org/zh-hant/%E4%B8%89%E5%9C%8B%E6%BC%94%E7%BE%A9/%E7%AC%AC'$i'%E5%9B%9E'
	i=`expr $i + 1`
	i=`printf "%03d" $i`
	sleep 5
done
