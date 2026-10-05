#!/bin/sh
# 測定 (32897) の残り八つの釦。
#
#   sh tools/probe129.sh
#
# 距離測定 (1064) は入りました（`tests/sokutei_test.c`）。並びの残りは
# 面積測定 (1065)・座標測定 (1066)・角度測定 (1067)・○単独円指定 (1068)・
# mm/【ｍ】 (1069)・小数桁 3 (1070)・測定結果書込 (1071)・書込設定 (1072)。
# どれも状態表示の読み出しに出るはずなので、一手ごとに読みます。
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
S='raw:f,273,32897,0;wait:800;'
BOX='300,300;700,300;700,500;300,500;'

run area  "${S}pb:1065;wait:500;${R}${BOX}${R}300,300;${R}"
run coord "${S}pb:1066;wait:500;${R}500,400;${R}"
run angle "${S}pb:1067;wait:500;${R}300,300;${R}700,300;${R}700,500;${R}"
run unit  "${S}pb:1069;wait:500;${R}300,300;${R}700,300;${R}"
run digit "${S}pb:1070;wait:500;${R}300,300;700,300;${R}pb:1070;wait:500;${R}pb:1070;wait:500;${R}"
run write "${S}300,300;700,300;${R}pb:1071;wait:600;${R}500,600;${R}saveas:decomp/res/sokutei_write.jww"
idle
echo
echo "--- 測定結果書込 が置いたもの"
python tools/whatdid.py decomp/res/new.jww decomp/res/sokutei_write.jww 2>&1 | head -6
