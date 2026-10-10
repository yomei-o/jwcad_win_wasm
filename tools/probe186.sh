#!/bin/sh
# 建具平面 (32848): 円弧のある建具 [7]・[13] の 反転（左右・内外・両方）。
#   sh tools/probe186.sh
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
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;$2cmd:32848;wait:3000;rcd:$(cell $3);wait:700;rcd:$(cell $3),d;wait:1500;$4wait:800;saveas:p186_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
H='300,400;800,400;'
P='450,400;wait:600;550,400;wait:600;'
for c in 7 13; do
  run s$c  "$H" $c "pb:1146;wait:500;pb:1325;wait:500;$P"
  run n$c  "$H" $c "pb:1146;wait:500;pb:1324;wait:500;$P"
  run sn$c "$H" $c "pb:1146;wait:500;pb:1325;wait:500;pb:1324;wait:500;$P"
done
run v7   '500,200;500,600;' 7 '500,300;wait:600;500,400;wait:600;'
run d7   '300,300;700,500;' 7 '400,350;wait:600;500,400;wait:600;'
idle
