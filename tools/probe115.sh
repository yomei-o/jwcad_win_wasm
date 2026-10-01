#!/bin/sh
# 分割の 割付 (1324) の歩きを問いかけで追う。
#
#   sh tools/probe115.sh
#
# `tools/probe114.sh` で 割付距離以下 (1326) を訊こうとして歩きを外し
# ました（線を二本と 距離 30 のつもりが 99 本も引かれました）。まず
# **割付 そのものの歩き**を、一手ごとに問いかけとバーを見て押さえます。
#
# 1326 が出るのは `decomp/res/bars3.txt` の `232867_1324`、つまり
# 分割 (32867) で 割付 (1324) を押したバーで、そこには
# 仮点 (1323)・割付 (1324)・距離 (1412)・振分 (1325)・等距離分割 (1689)・
# 等角度分割 (1690)・割付距離以下 (1326) が並びます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|^(Button|ComboBox|Edit)\|" |
        sed 's/^/    /'
}
R='read:59393;'
L='off:1333;300,300;700,300;350,600;900,700;cmd:32867;'

# what the bar looks like before and after 割付, and what it asks at each step
run walk "${L}${R}bar;pb:1324;wait:900;${R}bar;500,300;${R}600,650;${R}"
idle
