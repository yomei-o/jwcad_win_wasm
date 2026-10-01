#!/bin/sh
# 分割の 割付距離以下 (1326) —— 最後の一つ。
#
#   sh tools/probe114.sh
#
# `python tools/barcover.py` を三つのファイルを読むように直したら、本当に
# 残っているつまみは九種だけになり、そのうち**訊いていないのはこれだけ**に
# なりました。
#
# 1326 が出るのは 分割 (32867) で 割付 (1324) を押したバー
# （`decomp/res/bars3.txt` の 232867_1324）で、そこには 距離 (1412)・
# 振分 (1325)・割付距離以下 (1326) が並びます。割付 は「この距離で割る」
# 形のはずで、1326 はその距離を**上限**にする印でしょう。
#
# 二本の線のあいだを割ります。距離 30 mm、線の間は probe の
# (300,300)-(700,300) と (350,600)-(900,700) で、どちらでも割り切れない
# 距離を選びます。
#
#   off  割付 のまま
#   on   割付距離以下 を入れて同じこと
#   base くらべる元（等距離分割 3 等分、refanswers と同じ歩き）
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
L='off:1333;300,300;700,300;350,600;900,700;cmd:32867;'

run base "${L}ch:1411,3;500,300;600,650;saveas:p114_base"
run off  "${L}pb:1324;wait:800;${R}ch:1412,30;500,300;600,650;${R}saveas:p114_off"
run on   "${L}pb:1324;wait:800;pb:1326;wait:600;${R}ch:1412,30;500,300;600,650;saveas:p114_on"
idle
