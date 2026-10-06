#!/bin/sh
# ２線 (32892) —— 間隔の箱が空のときに原典が何を引くのか。
#
#   sh tools/probe158.sh
#
# 作図コマンドの掃き出し（tools/drawsweep.sh）で、原典は三クリックで
# 2 本引くのに移植は何も引かないと出ました。移植は間隔の箱 (1412) が
# 空だと拾うのを断ります。原典は空のまま 1.0mm 離した 2 本を引いて
# いたので、箱に入れた値と出てくる間隔の関係を訊きます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
BASE='cmd:32771;off:1333;300,300;700,500;300,500;700,300;cmd:32773;500,250;560,250;'
CLICKS='400,350;600,450;500,420;'

run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "${BASE}cmd:32892;$2${CLICKS}saveas:p158_$1;" 2>&1 |
        grep -E "throw|no |saved|read 59393" | sed 's/^/    /'
}

run empty ''
run g100  'ch:1412,100;'
run g50   'ch:1412,50;'
run g0_200 'ch:1412,0,200;'
idle
echo
for f in empty g100 g50 g0_200; do
    echo "--- $f"
    python tools/whatdid.py decomp/res/sweep_base.jww "tmp/p158_$f.jww" 2>&1 | head -4
done
