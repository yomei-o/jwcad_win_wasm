#!/bin/sh
# 小粒の命令の第一陣、その三 —— 測り方を直した三つ。
#
#   sh tools/probe123.sh
#
# `tools/probe122.sh` で分かった直しどころ:
#
#   軸角 (32962)      `on:` という手は無い。水平･垂直 (1333) は初めから
#                     入っているので、off: で外して pb: で戻す
#   レイヤ非表示化 (32936) 書込レイヤは消せない。レイヤバーの升を w<x>,<y>
#                     の右クリックで書込レイヤにして、別のレイヤに線を
#                     引いてから訊く（升は左グリッド x=1188,y=394、19x21）
#   寸法図形化 (32928) **二手**です。［寸法線］のあと【寸法値】を指す
#                     （問いかけが 5508 から 5510 に変わる）。寸法値は
#                     寸法線のすぐ上に重なっているので、画面では一画素
#                     ちがいの所になります
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
S='300,600;700,600;cmd:32847;ch:1411,0;400,500;400,450;r300,600;r700,600;'
# layer 1 is the second cell down the left grid's first column
L1='w1197,425,r;'
L0='w1197,404,r;'

run jikbase "off:1333;300,300;700,500;pb:1333;wait:400;500,600;800,650;saveas:decomp/res/getjikbase.jww"
run jik     "off:1333;300,300;700,500;raw:f,273,32962,0;wait:700;${R}500,400;${R}pb:1333;wait:400;500,600;800,650;saveas:decomp/res/getjik.jww"
run hidebase "${L1}300,300;700,500;${L0}saveas:p123_hidebase"
run hide     "${L1}300,300;700,500;${L0}raw:f,273,32936,0;wait:700;${R}500,400;${R}saveas:p123_hide"
run dimfig   "${S}raw:f,273,32928,0;wait:700;${R}500,450;${R}495,448;${R}saveas:p123_dimfig"
idle
echo
echo "--- 軸角: 水平･垂直 で引いた線"
python tools/whatdid.py decomp/res/getjikbase.jww decomp/res/getjik.jww 2>&1 | head -6
echo "--- レイヤ非表示化: レイヤの状態"
python tools/laystate.py tmp/p123_hidebase.jww tmp/p123_hide.jww 2>&1 | head -12
echo "--- 寸法図形化"
python tools/whatdid.py tmp/p122_dimbase.jww tmp/p123_dimfig.jww 2>&1 | head -20
