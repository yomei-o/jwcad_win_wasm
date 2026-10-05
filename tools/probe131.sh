#!/bin/sh
# 目盛基準点 (32912) —— 目盛を出してから訊きます。
#
#   sh tools/probe131.sh
#
# 問いかけは「基準点を指示して下さい  (L)free  (R)Read」
# （`tools/probe120.sh`）。目盛が出ていなければ何も見えないので、まず
# 軸角・目盛・オフセット (32842) で 目盛間隔 (1412) を 10 にして 1/1 を
# 入れます（**間隔を入れないと目盛は出ません** —— 一度目はそれで空振り
# しました） —— その窓の
# 中身は `src/gen/jikkaku.h` にあり、OFF (1835) と 1/1..1/5
# (2541・2542・2543・2544・2418) が並び、基準点設定 (2074) という釦も
# あります（メニューの 32912 と同じものでしょう）。
#
#   base   目盛 1/1 のまま撮る
#   kijun  32912 を出して (300,300) を指してから撮る
#   dlg    窓の 基準点設定 (2074) を押したら何が起きるか
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |wrote|=== dialog" | sed 's/^/    /'
}
R='read:59393;'
G='dlgin:32842,1412=10,2541=!;wait:800;'

run base  "${G}wait:600;shot:tmp/p131_base.png"
run kijun "${G}raw:f,273,32912,0;wait:700;${R}300,300;${R}wait:600;shot:tmp/p131_kijun.png"
run dlg   "raw:f,273,32842,0;wait:900;${R}dlgnow:2074=!;wait:700;${R}"
idle
echo
printf '%-10s ' "目盛基準点の前後"
python tools/cmp.py tmp/p131_base.png tmp/p131_kijun.png 2>&1 | sed -n 1p
