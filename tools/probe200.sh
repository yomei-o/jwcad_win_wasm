#!/bin/sh
# 線記号変形 (32869)。記号を選んで線・位置を押す。
#   sh tools/probe200.sh <名前> <記号の番号 1〜16> '<そのあとの steps>'   → tmp/p200_<名前>.jww
# 壁は 水平（300,400）→（800,400）。四角の窓の選び方は tools/probe193.sh と同じ。
cd "$(dirname "$0")/.."
for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done; }
NAME=$1; N=$2; SET=$3
# 4×4 の格子。窓の中の位置は、まず見て決める（既定は左上から 4 列）
r=$(( (N - 1) / 4 )); c=$(( (N - 1) % 4 ))
CELL="$(( ${GX:-300} + c * ${GW:-130} )),$(( ${GY:-100} + r * ${GH:-100} ))"
idle; sh tools/refenv.sh >/dev/null
W=$(pwd -W | tr '/' '\')
mkdir -p tmp/opt4_A
for k in SENKIGOU; do
    powershell -Command "Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Name $k -Value '${W}\tmp\opt4_A'"
done
cp decomp/res/new.jww tmp/rect.jww
$PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,400;800,400;cmd:32869;wait:3000;rcd:$CELL;wait:700;rcd:$CELL,d;wait:1500;${SET}saveas:p200_$NAME;" 2>&1 | grep -E "throw|no |saved|read" | sed 's/^/    /'
idle
