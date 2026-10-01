#!/bin/sh
# 残りのつまみを四つ —— 複写 (2092)・角 (1071)・グループ化 (2865)・
# 文字位置･集計 (1071)。
#
#   sh tools/probe102.sh
#
# `python tools/barcover.py` が出した「src/cmd.c に名前も出てこない」
# 26 個のうち、作図が変わりそうなものを押して訊きます。
#
#   cp0    図形複写 (32804) そのまま、くらべる元
#   cp1    複写 (2092) を外して同じこと —— 外すと「移動」になるはず
#   cang   角 (1071) を押してから同じこと
#   gz0    図形読込、くらべる元
#   gz1    グループ化 (2865) を入れてから読む
#   shuu   範囲選択 の 文字位置･集計 (1071) を押すと何が出るか
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32772 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|Button" | sed 's/^/    /'
}
R='read:59393;'
C='300,300;500,400;cmd:32804;250,250;550,450;m400,350;btn:1120;'

run cp0  "${C}350,320;700,500;saveas:p102_cp0"
run cp1  "${C}pb:2092;wait:600;${R}350,320;700,500;saveas:p102_cp1"
run cang "${C}pb:1071;wait:600;${R}350,320;700,500;saveas:p102_cang"
run gz0  "figin:32862,decomp/res/fig.jws;500,400;saveas:p102_gz0"
run gz1  "figin:32862,decomp/res/fig.jws;pb:2865;wait:600;500,400;saveas:p102_gz1"
run shuu "300,300;500,400;cmd:32787;250,250;550,450;btn:1120;wait:600;${R}pb:1071;wait:1200;${R}tops"
idle
