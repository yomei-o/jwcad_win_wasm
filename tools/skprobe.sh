#!/bin/sh
# 線記号変形 (32869) の記号を一つだけ原典に置かせる。
#   sh tools/skprobe.sh <名前> <文字 A〜J> <番号> '<コマンドの前に引く線の steps>' '<コマンドのあとの steps>'
#       → decomp/res/sk_<名前>.jww
# 記号を一つだけ入れた DAT を専用の入れ物に置き、ファイル選択の窓の左上を押して選ぶ。
# 壁は 水平（300,400）→（800,400）が必ず引かれる。
cd "$(dirname "$0")/.."
for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done; }
NAME=$1; L=$2; N=$3; PRE=$4; POST=$5
idle; sh tools/refenv.sh >/dev/null
W=$(pwd -W | tr '/' '\')
mkdir -p tmp/sk1
PYTHONIOENCODING=utf-8 python tools/skitem.py "$L" "$N" tmp/sk1 >/dev/null
powershell -Command "Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Name SENKIGOU -Value '${W}\tmp\sk1'"
cp decomp/res/new.jww tmp/rect.jww
CELL=388,126
$PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,400;800,400;${PRE}cmd:32869;wait:3000;rcd:$CELL;wait:700;rcd:$CELL,d;wait:1500;${POST}saveas:sk_$NAME;" 2>&1 | grep -E "${SKGREP:-throw|no |saved|read}" | sed 's/^/    /'
mv -f tmp/sk_$NAME.jww decomp/res/sk_$NAME.jww 2>/dev/null
idle
