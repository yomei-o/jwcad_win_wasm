#!/bin/sh
# 交点 (1066) の 線×円 と 円×円 —— 当たるところを狙い直したもの。
#
#   sh tools/probe155.sh
#
# probe154 は 線 と 円 の両方に近いところを押していて、二度とも線を
# 拾っていました。今度は円の天辺など、片方しか無いところを押します。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }

# 円: 中心 (500,400) 半径 100。線: y=430 を横切る水平線。
#   交点は x = 500 +- sqrt(100^2 - 30^2) = 404.6 と 595.4
CIRC='cmd:32773;500,400;600,400;'
LINE='cmd:32771;off:1333;300,430;700,430;'
# 円二つ: 中心 (450,400) r=70 と (570,400) r=70。交点は x=510, y=400+-sqrt(70^2-60^2)=400+-36.06
TWOC='cmd:32773;450,400;520,400;cmd:32773;570,400;640,400;'

run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "$2" 2>&1 |
        grep -E "throw|no |saved" | sed 's/^/    /'
}

run lc_base  "${CIRC}${LINE}saveas:p155_lc_base;"
# 円の天辺を（Ａ）に、線の左端を【Ｂ】に
run lc_a     "${CIRC}${LINE}cmd:32785;btn:1066;500,300;320,430;saveas:p155_lc_a;"
# 同じく、ただし【Ｂ】を線の右端で
run lc_b     "${CIRC}${LINE}cmd:32785;btn:1066;500,300;680,430;saveas:p155_lc_b;"
run cc_base  "${TWOC}saveas:p155_cc_base;"
# 円の上側どうし / 下側どうし
run cc_up    "${TWOC}cmd:32785;btn:1066;450,330;570,330;saveas:p155_cc_up;"
run cc_down  "${TWOC}cmd:32785;btn:1066;450,470;570,470;saveas:p155_cc_down;"
idle

echo
for f in lc_a lc_b; do
    echo "--- $f vs lc_base"
    python tools/whatdid.py tmp/p155_lc_base.jww "tmp/p155_$f.jww" 2>&1 | head -4
done
for f in cc_up cc_down; do
    echo "--- $f vs cc_base"
    python tools/whatdid.py tmp/p155_cc_base.jww "tmp/p155_$f.jww" 2>&1 | head -4
done
