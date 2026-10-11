#!/bin/sh
# 建具平面 (32848) の 基準点変更 (1065)・芯反転 (1323)・グループ化 (2865)。
#   sh tools/probe193.sh <名前> <建具の番号> '<設定の steps>'   → tmp/p193_<名前>.jww
# 壁は 水平（300,400）→（800,400）、位置は（450,400）→（550,400）。
cd "$(dirname "$0")/.."
# 原典は建具の窓を閉じるたびに orig/ に空の 20…-…-… を作り、木の行が一つずつずれていく
for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done; }
NAME=$1; N=$2; SET=$3; F=${4:-A}   # A〜D: JW_OPT1<F>.DAT
if [ -n "$COLS6" ]; then   # 列の ▲ を 4 回押して 6 列にすると 24 件が一度に見える
    r=$(( (N - 1) / 6 )); c=$(( (N - 1) % 6 ))
    CELL="$(( 356 + c * 136 )),$(( 60 + r * 72 ))"
else
    r=$(( (N - 1) / 2 )); c=$(( (N - 1) % 2 ))
    CELL="$(( 480 + c * 398 )),$(( 60 + r * 72 ))"
fi
idle; sh tools/refenv.sh >/dev/null
W=$(pwd -W | tr '/' '\')
# 木の行は押す前の状態で動くので押さない。.DAT を一つだけ置いた
# 専用の入れ物を指して、それが初めから選ばれている形にする
case $F in A) SRC=orig/JW_OPT1.DAT;; *) SRC=orig/JW_OPT1$F.DAT;; esac
mkdir -p tmp/opt1_$F; cp $SRC tmp/opt1_$F/JW_OPT1.DAT
powershell -Command "Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Name TATEGUHEIMEN -Value '${W}\tmp\opt1_$F'"
cp decomp/res/new.jww tmp/rect.jww
ROW=""
[ -n "$COLS6" ] && ROW="rcd:123,5;wait:400;rcd:123,5;wait:400;rcd:123,5;wait:400;rcd:123,5;wait:600;"
$PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,400;800,400;cmd:32848;wait:3000;${ROW}rcd:$CELL;wait:700;rcd:$CELL,d;wait:1500;${SET}450,400;wait:600;550,400;wait:700;saveas:p193_$NAME;" 2>&1 | grep -E "throw|no |saved|read" | sed 's/^/    /'
idle
