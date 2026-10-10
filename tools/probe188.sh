#!/bin/sh
# 建具平面 (32848): 平面詳細用 (JW_OPT1C) の額出・水切出（ブロック 10001・20001）の置き方。
#   sh tools/probe188.sh   → decomp/res/p188_*.jww
# 見込・枠幅・内法・芯ずれを変えて、同じ建具を水平な壁に置かせる。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
cell() { n=$1; r=$(( (n - 1) / 2 )); c=$(( (n - 1) % 2 )); echo "$(( 480 + c * 398 )),$(( 60 + r * 72 ))"; }
run() {   # 名前 行の y 建具番号 設定
    idle; sh tools/refenv.sh >/dev/null
    W=$(pwd -W | tr '/' '\')
    powershell -Command "Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Name TATEGUHEIMEN -Value '${W}\orig'"
    cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,400;800,400;cmd:32848;wait:3000;rcd:200,$2;wait:1500;rcd:$(cell $3);wait:700;rcd:$(cell $3),d;wait:1500;$4;450,400;wait:600;550,400;wait:600;saveas:p188_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
run i100 208 3 'ch:1428,100;wait:600'
run o50 208 3 'ch:1429,50;wait:600'
run i100o50 208 3 'ch:1428,100;wait:400;ch:1429,50;wait:600'
run i100_6 208 6 'ch:1428,100;wait:600'
run o50_6 208 6 'ch:1429,50;wait:600'
run d_6 208 6 'wait:300'
idle
