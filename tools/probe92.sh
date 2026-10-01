#!/bin/sh
# 間隔取得 (32948) の行き先が割れました —— 複線の間隔です。答えを三つ。
#
#   sh tools/probe92.sh
#
# `tools/probe90.sh` の fuku がそれでした。複線 の途中で 間隔取得 を呼び、
# 線を (L)、**読む点のある所**を (R) で指すと、間隔取得 はそこで終わって
# 複線 に戻り、続くクリックが向きを決めて複写が出ます。その複写は
# **測った垂線のぶん**離れていました（164.27、状態行の 16,428.254 と同じ）。
#
# 前の六回（probe44・46・47・48）が全部外れたのは、二つ目をどれも
# **何も無い所で (R)** していたからです。読む点が無ければ何も取れません。
#
# ここでは点を三つの場所に置いて、三つとも答えに取ります。
#
#   a  点 (300,600)   垂線 164.28 mm
#   b  点 (700,650)   もっと近い
#   c  点 (200,200)   線の反対側
#
# くらべる元として、間隔取得 を通さない同じ歩きも一つ取ります。
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

R='read:59393;'
# $1 where the point goes, $2 the side click, $3 the answer's name
one() {
    B="cmd:32771;off:1333;300,300;700,500;cmd:32785;$1;"
    echo "${B}cmd:32800;500,400;cmd:32948;500,400;r$1;${R}$2;saveas:$3"
}

run a    "$(one 300,600 500,200 decomp/res/kankaku_a.jww)"
run b    "$(one 700,650 500,200 decomp/res/kankaku_b.jww)"
run c    "$(one 200,200 500,600 decomp/res/kankaku_c.jww)"
run none "cmd:32771;off:1333;300,300;700,500;cmd:32785;300,600;cmd:32800;500,400;${R}500,200;saveas:decomp/res/kankaku_none.jww"
idle
