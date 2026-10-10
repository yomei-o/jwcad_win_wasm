#!/bin/sh
# 建具平面 (32848): JW_OPT1.DAT の 1〜16 番を、初期値のまま水平な壁に置く。
#   sh tools/probe185.sh [from to]
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
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,400;800,400;cmd:32848;wait:3000;rcd:$(cell $2);wait:700;rcd:$(cell $2),d;wait:1500;read:59393;450,400;wait:600;550,400;wait:600;read:59393;saveas:p185_i$2;" 2>&1 | grep -E "throw|no |saved|read 59393" | sed 's/^/    /'
}
a=${1:-1}; b=${2:-16}
i=$a; while [ $i -le $b ]; do run i$i $i; i=$((i+1)); done
idle
