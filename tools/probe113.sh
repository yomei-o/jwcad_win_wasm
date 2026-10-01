#!/bin/sh
# 文字位置･集計 (1071) はいつ生きるのか。
#
#   sh tools/probe113.sh
#
# `decomp/res/bars.txt` の 範囲選択 (32787) の行を見ると
#
#   Button|1071|608|5|88|24|58010000|0|0|文字位置･集計
#
# 最後の 0 は **enabled が 0**、つまり出たときは死んでいます。だから
# `tools/probe104.sh`・`probe112.sh` で押しても何も起きなかったのは
# 当たり前でした。何をすると生きるのかを、バーを並べて見ます。
#
#   none  範囲を取る前
#   box   範囲を取ったあと
#   txt   文字だけを (R) で拾ったあと
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no control|^Button\|(1068|1070|1071|1069)\|" |
        sed 's/^/    /'
}
T='cmd:32806;type:12;400,300;type:34;400,400;type:56;400,500;'

run none "${T}cmd:32787;bar"
run box  "${T}cmd:32787;350,250;600,550;bar"
run txt  "${T}cmd:32787;350,250;600,550;r405,300;bar"
idle
