#!/bin/sh
# 点 (32785) の 交点 (1066) —— 線×円 と 円×円。
#
#   sh tools/probe154.sh
#
# 線×線 は tools/probe151.sh で取れました。残りの二組と、交点が二つ
# ある場合にどちらを採るのかを訊きます（二度目のクリックの位置を
# 変えて、落ちる点が動くかどうか）。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }

# 円: 中心 (500,400) 半径は (600,400) まで。線: 水平に横切らせる。
CIRC='cmd:32773;500,400;600,400;'
LINE='cmd:32771;off:1333;300,430;700,430;'
TWOC='cmd:32773;450,400;550,400;cmd:32773;600,400;700,400;'

run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "$2" 2>&1 |
        grep -E "throw|no |saved|read 59393" | sed 's/^/    /'
}

run lc_base "${CIRC}${LINE}saveas:p154_lc_base;"
# 線×円。二度目のクリックを左寄り / 右寄りにして、どちらの交点か見る
run lc_left  "${CIRC}${LINE}cmd:32785;btn:1066;350,430;420,430;saveas:p154_lc_left;"
run lc_right "${CIRC}${LINE}cmd:32785;btn:1066;350,430;580,430;saveas:p154_lc_right;"
# 円を先に指したら
run lc_circ  "${CIRC}${LINE}cmd:32785;btn:1066;500,330;350,430;saveas:p154_lc_circ;"

run cc_base "${TWOC}saveas:p154_cc_base;"
run cc_up   "${TWOC}cmd:32785;btn:1066;450,330;650,330;saveas:p154_cc_up;"
run cc_down "${TWOC}cmd:32785;btn:1066;450,470;650,470;saveas:p154_cc_down;"
idle

echo
for f in lc_left lc_right lc_circ; do
    echo "--- $f vs lc_base"
    python tools/whatdid.py tmp/p154_lc_base.jww "tmp/p154_$f.jww" 2>&1 | head -5
done
echo
python tools/whatdid.py decomp/res/new.jww tmp/p154_cc_base.jww 2>&1 | head -4
for f in cc_up cc_down; do
    echo "--- $f vs cc_base"
    python tools/whatdid.py tmp/p154_cc_base.jww "tmp/p154_$f.jww" 2>&1 | head -5
done
