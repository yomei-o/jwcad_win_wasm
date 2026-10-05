#!/bin/sh
# 角度測定 の途中の数 —— 本物のカーソルで読みます。
#
#   sh tools/probe144.sh
#
# 移植で合っていないのはここだけです。原典は 基準点 を置いたあと
# **マウスの今の位置まで**の角を映しますが、移植は最後に出した角を
# 出したままです。`m<x>,<y>` でカーソルを動かして読みます。
#
# 原点 (300,300)・基準点 (700,300) なら、基準の向きは 0 度。
# カーソル (700,500) で -26.565 度、(300,500) で -90 度、(700,100) で
# +26.565 度のはずです。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no " | sed 's/^/    /'
}
R='read:59393;'
S='raw:f,273,32897,0;wait:800;'

run angle "${S}pb:1067;wait:500;300,300;700,300;m700,500;wait:300;${R}m300,500;wait:300;${R}m700,100;wait:300;${R}m900,300;wait:300;${R}"
idle
