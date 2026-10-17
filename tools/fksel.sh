#!/bin/sh
# 複線の 両側複線 (1068)・留線付両側複線 (1069) を 範囲選択のあとに押した原典の答えを録る。
#
#   JW_EXE=<orig/Jw_win.exe の写し> sh tools/fksel.sh <名前> <釦 1068|1069> <間隔> '<留線出 か 空>' '<x1,y1,x2,y2 …>'
#   →  tmp/fk_<名前>.jww   （decomp/res/fksel/<名前>.jww と cases.txt の行にして置く）
#
# 線は 新しい図面（1/100）に 画面の画素で引く（クリックは view の中の座標）。引いたあと cmd:32787 で
# 全部を囲み（確定は要らない）、cmd:32800（複線）、間隔 (1411)・留線出 (1412) を打って 釦を押す。
# 先頭の本数が元の線、あとが 原典の足した線。tests/fksel_test.c が それを写しと比べる。
cd "$(dirname "$0")/.."
name=$1; btn=$2; gap=$3; tome=$4; lines=$5
st='cmd:32771;off:1333;'
for l in $lines; do
    st="$st$(echo "$l" | awk -F, '{printf "%s,%s;%s,%s;", $1, $2, $3, $4}')"
done
st="${st}cmd:32787;250,150;1000,750;cmd:32800;chr:1411,$gap;"
[ -n "$tome" ] && st="${st}chr:1412,$tome;"
st="${st}pb:$btn;wait:800;"
exec sh tools/mprobe.sh "fk_$name" "$st"
