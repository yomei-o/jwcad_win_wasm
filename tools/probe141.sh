#!/bin/sh
# 測定の残り —— 座標測定 (1066) と、四択のどれが凹んで見えるか。
#
#   sh tools/probe141.sh
#
# 座標測定 の読み出しは**マウスの今の位置**を映すので、投げたクリックでは
# 測れませんでした（`tools/probe129.sh`）。`m<x>,<y>` で本物のカーソルを
# 動かしてから読みます。
#
# 四つの 〜測定 のうちどれが選ばれているかは、原典が自前で凹ませて描いて
# いて EnumChildWindows には出ません。バーを撮って較べます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |wrote" | sed 's/^/    /'
}
R='read:59393;'
S='raw:f,273,32897,0;wait:800;'

# 座標測定: the origin, then the real cursor at three places
run coord "${S}pb:1066;wait:500;${R}300,300;${R}m500,400;wait:300;${R}m700,300;wait:300;${R}m300,300;wait:300;${R}"
# which of the four looks pressed
run barlen  "${S}wait:400;shot:tmp/p141_len.png"
run bararea "${S}pb:1065;wait:600;shot:tmp/p141_area.png"
run barang  "${S}pb:1067;wait:600;shot:tmp/p141_ang.png"
idle
echo
echo "--- 距離測定 のときと 面積測定 のときで、バーのどこが違うか"
python tools/cmp.py tmp/p141_len.png tmp/p141_area.png 2>&1 | sed -n 1p
