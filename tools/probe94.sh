#!/bin/sh
# 間隔取得 (32948) —— 取った値はいつまで残るのか。
#
#   sh tools/probe94.sh
#
# 行き先と値は割れました（`tools/probe92.sh`、答えは
# decomp/res/kankaku_*.jww）。残りは寿命です。角度取得・長さ取得 は
# **命令を出ると消えます**（probe21）。こちらも同じかどうか。
#
#   keep   一本複写したあと、同じ命令でもう一本複写する。残っていれば
#          二本目もクリック二つで出て、同じ 164.28 離れます。消えていれば
#          二本目は間隔を決めるクリックが要るので何も出ません
#   leave  間隔取得 のあと 円 へ出て 複線 へ戻る。残っていれば同じこと
#
# probe93 の keep は歩きがずれて使い物になりませんでした。ここでは
# 一手ごとに問いかけを読みます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

B='cmd:32771;off:1333;300,300;700,500;cmd:32785;300,600;'
K='cmd:32948;500,400;r300,600;'
R='read:59393;'

run keep  "${B}cmd:32800;500,400;${K}500,200;${R}500,400;${R}500,100;${R}saveas:p94_keep"
run leave "${B}cmd:32800;500,400;${K}cmd:32773;cmd:32800;${R}500,400;${R}500,200;${R}saveas:p94_leave"
idle
