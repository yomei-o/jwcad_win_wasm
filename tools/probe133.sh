#!/bin/sh
# レイヤ非表示化 (32936) もう一手 —— 今度は図形のある所を指します。
#
#   sh tools/probe133.sh
#
# `probe122`〜`probe124` の空振りは、指した所に図形が無かったせいかも
# しれません。orig/Test5.jww は書込レイヤが 8 で、レイヤ 0 の線がビュー
# 座標の (395,534) を通ります（移植に図面を読ませて出した所。`<x>,<y>`
# は**ビューの**座標です —— `app_press` のフレーム座標とは違います）。
#
#   base  何もせず保存
#   hideL (L) で指す
#   hideR (R) で指す
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp orig/Test5.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}
R='read:59393;'

run base  "saveas:decomp/res/layhide_base.jww"
run hideL "raw:f,273,32936,0;wait:700;${R}395,534;${R}saveas:decomp/res/layhide.jww"
run hideR "raw:f,273,32936,0;wait:700;r395,534;${R}saveas:p133_hideR"
idle
echo
for f in decomp/res/layhide.jww tmp/p133_hideR.jww; do
    echo "--- $f"
    python tools/laystate.py decomp/res/layhide_base.jww "$f" 2>&1 | head -6
done
