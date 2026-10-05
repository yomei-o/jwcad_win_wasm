#!/bin/sh
# 測定 の仮表示を、カーソルの居所まで決めて撮ります。
#
#   sh tools/probe146.sh
#
# `tools/probe145.sh` で「測った線が赤で出る」ことは分かりましたが、
# カーソルを動かしていなかったので、カーソルへ伸びる脚の先が決まって
# いませんでした。`m<x>,<y>` で (900,300) に置いてから撮ります。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "throw|no |wrote" | sed 's/^/    /'
}
S='raw:f,273,32897,0;wait:800;'

run len  "${S}300,300;700,300;700,500;m900,300;wait:600;shot:docs/ref_sokutei_len.png"
run area "${S}pb:1065;wait:400;300,300;700,300;700,500;300,500;m900,300;wait:600;shot:docs/ref_sokutei_area.png"
idle
