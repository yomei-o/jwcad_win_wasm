#!/bin/sh
# 建具平面 (32848): 反転・何度も置く・2点間 (R)・グループ化。建具 [5] と [3]。
#   sh tools/probe181.sh
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
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;$2cmd:32848;wait:3000;rcd:$(cell $3),d;wait:1500;$4wait:800;saveas:p181_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
H='300,400;800,400;'
run nei  "$H" 5 'pb:1146;wait:500;pb:1324;wait:500;450,400;wait:600;550,400;wait:600;'
run sayu "$H" 5 'pb:1146;wait:500;pb:1325;wait:500;450,400;wait:600;550,400;wait:600;'
run two  "$H" 5 '450,400;wait:600;550,400;wait:600;700,400;wait:600;'
run r2   "$H" 5 '450,400;wait:600;r550,400;wait:600;r700,400;wait:600;'
run grp  "$H" 5 'pb:2865;wait:400;450,400;wait:600;550,400;wait:600;'
run c3   "$H" 3 '450,400;wait:600;550,400;wait:600;'
run c4   "$H" 4 '450,400;wait:600;550,400;wait:600;'
run c9   "$H" 9 '450,400;wait:600;550,400;wait:600;'
idle
