#!/bin/sh
# レイヤ非表示化 (32936) もう一手 —— 別のレイヤグループならどうか。
#
#   sh tools/probe126.sh
#
# `probe123`・`probe124` では、同じグループの別レイヤに引いた線を指しても
# 何も起きませんでした。「レイヤ非表示化」が**レイヤグループ**のほうを
# 落とすのなら、書込グループでない所の図形でないと効かないはずです。
#
# レイヤバーは左が 16 レイヤ (x=1188,y=394)、右が 16 レイヤグループ
# (x=1227,y=397)、どちらも升 19x21 で 2 列 8 行。右クリックで書込に
# なります。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}
R='read:59393;'
G1='w1236,418,r;'
G0='w1236,397,r;'

run gbase "${G1}300,300;700,500;${G0}saveas:p126_gbase"
run ghide "${G1}300,300;700,500;${G0}raw:f,273,32936,0;wait:700;${R}500,400;${R}saveas:p126_ghide"
idle
echo
echo "--- 別グループの図形を指したとき"
python tools/laystate.py tmp/p126_gbase.jww tmp/p126_ghide.jww 2>&1 | head -12
