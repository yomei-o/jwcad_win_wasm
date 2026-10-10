#!/bin/sh
# 建具平面 (32848): 壁の向き。逆向きに引いた線、(R) 二点を逆に、斜め。
#   sh tools/probe184.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
cell() { n=$1; r=$(( (n - 1) / 2 )); c=$(( (n - 1) % 2 )); echo "$(( 480 + c * 398 )),$(( 60 + r * 72 ))"; }
run() {
    idle; sh tools/refenv.sh >/dev/null
    W=$(pwd -W | tr '/' '\')
    powershell -Command "Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Name TATEGUHEIMEN -Value '${W}\orig'"
    cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;$2cmd:32848;wait:3000;rcd:$(cell $3),d;wait:1500;$4wait:800;saveas:p184_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
run rev   '800,400;300,400;' 5 '450,400;wait:600;550,400;wait:600;'
run rr    '300,400;800,400;' 5 'r800,400;wait:600;r300,400;wait:600;550,420;wait:600;'
run diag2 '700,500;300,300;' 5 '400,350;wait:600;500,400;wait:600;'
run vdown '500,600;500,200;' 5 '500,300;wait:600;500,400;wait:600;'
run steep '300,500;400,300;' 5 '350,400;wait:600;380,340;wait:600;'
idle
