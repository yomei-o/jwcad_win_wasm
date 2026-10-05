#!/bin/sh
# 小粒の命令の第一陣を、原典に図面を描かせて測ります。
#
#   sh tools/probe121.sh
#
# `tools/probe120.sh` で問いかけは分かりました。ここでは**何が起きるか**を
# 原典の .jww で取ります。
#
#   32938 数値角度   「数値を指示してください。」—— 図面の数字（文字）を指す？
#   32941 数値長     同じ
#   32962 軸角       「軸角取得 基準線を指示してください。」
#   32936 レイヤ非表示化「非表示にするレイヤの図形を指示してください」
#   32928 寸法図形化 「寸法図形にする［寸法線］を指示してください。」
#   32929 寸法図形解除「解除する寸法図形を指示してください。」
#
# `tests/getang_test.c` と同じで、取った場合と取らない場合を並べます。
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
# a dimension across the top, then back to 線
S='cmd:32847;ch:1411,0;400,250;400,200;r300,300;r700,300;cmd:32771;off:1333;'

run base "${T}500,600;800,650;saveas:decomp/res/getnumplain.jww"
run ang  "${T}raw:f,273,32938,0;wait:700;${R}405,395;${R}500,600;800,650;saveas:decomp/res/getnumang.jww"
run len  "${T}raw:f,273,32941,0;wait:700;${R}405,395;${R}500,600;800,650;saveas:decomp/res/getnumlen.jww"
run jik  "off:1333;300,300;700,500;${R}raw:f,273,32962,0;wait:700;${R}500,400;${R}500,600;800,650;saveas:p121_jik"
run hide "off:1333;300,300;700,500;raw:f,273,32936,0;wait:700;${R}500,400;${R}saveas:p121_hide"
run dim  "${S}saveas:p121_dimbase"
run dimg "${S}raw:f,273,32928,0;wait:700;${R}350,300;${R}saveas:p121_dimfig"
idle
echo
for f in p121_base p121_ang p121_len p121_jik p121_hide p121_dimbase p121_dimfig; do
    echo "--- $f"
    python tools/jww.py "tmp/$f.jww" 2>/dev/null | sed 's/^/    /' | head -24
done
