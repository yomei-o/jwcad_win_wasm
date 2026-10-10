#!/bin/sh
# 建具平面 (32848): 建具 [n] を選んで、基準線（壁の線）を指す。
#   sh tools/probe179.sh [cell]
# ファイル選択の窓は自分で絵を描いているので、**実マウス** (jwdraw.ps1 の rcd:) で
# 二度押しする。窓は Folder\TATEGUHEIMEN の鍵が指す orig を開く（起動時に読む）。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
cell() {   # cell number 1..16 -> client coordinates of its middle
    n=$1; r=$(( (n - 1) / 2 )); c=$(( (n - 1) % 2 ))
    echo "$(( 490 + c * 398 )),$(( 92 + r * 72 ))"
}
run() {   # name, cell, script
    idle; sh tools/refenv.sh >/dev/null
    W=$(pwd -W | tr '/' '\')
    powershell -Command "Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Name TATEGUHEIMEN -Value '${W}\orig'"
    cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,400;800,400;cmd:32848;wait:3000;rcd:$(cell $2),d;wait:1500;$3saveas:p179_$1;" 2>&1 | grep -E "throw|no |saved|read 59393" | sed 's/^/    /'
}
run c1a 1 '450,400;'
run c1b 1 '450,400;600,400;'
run c1c 1 '450,400;450,400;'
idle
