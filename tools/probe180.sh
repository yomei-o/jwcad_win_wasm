#!/bin/sh
# 建具平面 (32848) の置き方を、壁の向き・二点目の側・数値・反転で。
#   sh tools/probe180.sh
# 建具 [5]（JW_OPT1.DAT の五番目）を選んでから 基準線 → 位置 の二手。
# 壁は下の W で引く（水平・垂直を切った線）。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
cell() { n=$1; r=$(( (n - 1) / 2 )); c=$(( (n - 1) % 2 )); echo "$(( 480 + c * 398 )),$(( 60 + r * 72 ))"; }
run() {   # name, wall, cell, script
    idle; sh tools/refenv.sh >/dev/null
    W=$(pwd -W | tr '/' '\')
    powershell -Command "Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Name TATEGUHEIMEN -Value '${W}\orig'"
    cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;$2cmd:32848;wait:3000;rcd:$(cell $3),d;wait:1500;$4wait:800;saveas:p180_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
H='300,400;800,400;'
V='500,200;500,600;'
D='300,300;700,500;'
run h_r  "$H" 5 '450,400;wait:600;550,400;wait:600;'
run h_l  "$H" 5 '450,400;wait:600;350,400;wait:600;'
run h_off "$H" 5 '450,400;wait:600;550,420;wait:600;'
run h_off2 "$H" 5 '450,400;wait:600;550,380;wait:600;'
run v_d  "$V" 5 '500,300;wait:600;500,400;wait:600;'
run v_u  "$V" 5 '500,300;wait:600;500,200;wait:600;'
run d_r  "$D" 5 '400,350;wait:600;500,400;wait:600;'
run n1000 "$H" 5 'ch:1426,1000;wait:600;450,400;wait:600;550,400;wait:600;'
run m100  "$H" 5 'ch:1424,100;wait:600;450,400;wait:600;550,400;wait:600;'
run w50   "$H" 5 'ch:1425,50;wait:600;450,400;wait:600;550,400;wait:600;'
run z10   "$H" 5 'ch:1427,10;wait:600;450,400;wait:600;550,400;wait:600;'
run zm10  "$H" 5 'ch:1427,-10;wait:600;450,400;wait:600;550,400;wait:600;'
idle
