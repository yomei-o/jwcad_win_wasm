#!/bin/sh
# 答え（sk_*.jww）の中身だけを短く見る
for f in "$@"; do echo "== $f"; ./tmp/dj.exe decomp/res/sk_$f.jww | grep -v "Printer_\|View_Direct\|Draw_Bmp" | sed 's/ cls\([0-9]\) sub0 lt\([0-9]*\) col\([0-9]*\) w\([0-9]*\) lay\([0-9]*\) fl\([0-9a-f]*\) n\([0-9]*\) d=/ c\1 lt\2 col\3 w\4 ly\5 fl\6 n\7 /; s/ mark0 turn0.00 size0.00 list0,0,0//; s/0\.000 0\.000 0\.000 0\.000//'; done
