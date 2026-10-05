#!/bin/sh
# 数値角度 (32938)・数値長 (32941)・軸角 (32962) —— 取得の残り三つ。
#
#   sh tools/probe121.sh
#
# `tools/probe120.sh` で問いかけだけは分かりました:
#
#   32938 数値角度  「数値を指示してください。」
#   32941 数値長    「数値を指示してください。」
#   32962 軸角      「軸角取得  基準線を指示してください。」
#
# 前の二つは**図面に書いてある数字（文字要素）を指す**のでしょう。
# `tests/getang_test.c` と同じやり方で、取った場合と取らない場合の線を
# 並べて較べます。軸角のほうは状態表示の角度そのものを見ます。
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
# a text reading 30 at (400,400), then back to 線 with 水平･垂直 off
T='cmd:32806;type:30;400,400;cmd:32771;off:1333;'

run base "${T}500,600;800,650;saveas:p121_base"
run ang  "${T}raw:f,273,32938,0;wait:700;${R}405,395;${R}500,600;800,650;saveas:p121_ang"
run len  "${T}raw:f,273,32941,0;wait:700;${R}405,395;${R}500,600;800,650;saveas:p121_len"
run jik  "off:1333;300,300;700,500;${R}raw:f,273,32962,0;wait:700;${R}500,400;${R}500,600;800,650;saveas:p121_jik"
idle
echo
for f in p121_base p121_ang p121_len p121_jik; do
    echo "--- $f"
    python tools/jww.py "tmp/$f.jww" 2>/dev/null | grep -i "CDataSen\|CDataMoji" | sed 's/^/    /'
done
