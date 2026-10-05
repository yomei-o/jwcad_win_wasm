#!/bin/sh
# レイヤ非表示化 (32936) —— 図面には残らないのかどうか。
#
#   sh tools/probe124.sh
#
# `tools/probe123.sh` では、レイヤ 1 に線を引いて書込レイヤを 0 に戻し、
# 32936 を出して線を指しても、保存した .jww のレイヤ状態が 2 のままでした
# （0 なら非表示）。命令は問いかけを戻しているので、クリックは食べて
# います。残る見方は**絵**です —— 非表示になったのなら線は消えます。
#
#   base   32936 を出さずに撮る
#   hideL  (L) で指して撮る
#   hideR  (R) で指して撮る
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|wrote" | sed 's/^/    /'
}
R='read:59393;'
L1='w1197,425,r;'
L0='w1197,404,r;'

run base  "${L1}300,300;700,500;${L0}wait:500;shot:tmp/p124_base.png"
run hideL "${L1}300,300;700,500;${L0}raw:f,273,32936,0;wait:700;500,400;${R}wait:500;shot:tmp/p124_hideL.png"
run hideR "${L1}300,300;700,500;${L0}raw:f,273,32936,0;wait:700;r500,400;${R}wait:500;shot:tmp/p124_hideR.png"
idle
echo
for f in p124_hideL p124_hideR; do
    printf '%-12s ' "$f"
    python tools/cmp.py tmp/p124_base.png "tmp/$f.png" 2>&1 | sed -n 1p
done
