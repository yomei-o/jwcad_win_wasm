#!/bin/sh
# 建具平面 (32848): JW_OPT1B・1C・1D の建具を初期値のまま水平な壁に置く。
#   sh tools/probe187.sh B|C|D [from to]
# ファイル選択の左の木の【建具平面B】…の行を押してから、ますを押す。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
cell() { n=$1; r=$(( (n - 1) / 2 )); c=$(( (n - 1) % 2 )); echo "$(( 480 + c * 398 )),$(( 60 + r * 72 ))"; }
L=$1
case $L in B) ROW=208;; C) ROW=224;; D) ROW=240;; *) ROW=192;; esac
run() {
    idle; sh tools/refenv.sh >/dev/null
    W=$(pwd -W | tr '/' '\')
    powershell -Command "Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Name TATEGUHEIMEN -Value '${W}\orig'"
    cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,400;800,400;cmd:32848;wait:3000;rcd:200,$ROW;wait:1500;rcd:$(cell $2);wait:700;rcd:$(cell $2),d;wait:1500;read:59393;450,400;wait:600;550,400;wait:600;saveas:p187_$L$2;" 2>&1 | grep -E "throw|no |saved|read 59393" | sed 's/^/    /'
}
a=${2:-1}; b=${3:-16}
i=$a; while [ $i -le $b ]; do run $L$i $i; i=$((i+1)); done
idle
