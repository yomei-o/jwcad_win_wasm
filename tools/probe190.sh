#!/bin/sh
# 建具断面 (32866)・建具立面 (32865): JW_OPT2*・JW_OPT3* の建具を初期値のまま水平な壁に置く。
#   sh tools/probe190.sh 32866 A 1 16     → decomp/res/p190_<cmd>_<file><n>.jww
# file は A（木で選ばない・初めの一枚）か、木の行の y（客領域。B=192 …）。
# 断面は 2×8、立面は 4×4 のますが並ぶ。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
CMD=$1; F=$2
cell() {
    n=$1
    if [ "$CMD" = 32865 ]; then
        r=$(( (n - 1) / 4 )); c=$(( (n - 1) % 4 ))
        echo "$(( 380 + c * 204 )),$(( 120 + r * 144 ))"
    else
        r=$(( (n - 1) / 2 )); c=$(( (n - 1) % 2 ))
        echo "$(( 480 + c * 398 )),$(( 60 + r * 72 ))"
    fi
}
run() {   # 番号 設定
    idle; sh tools/refenv.sh >/dev/null
    W=$(pwd -W | tr '/' '\')
    for k in TATEGUHEIMEN TATEGUDANMEN TATEGURITSUMEN; do
        powershell -Command "Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Name $k -Value '${W}\orig'"
    done
    cp decomp/res/new.jww tmp/rect.jww
    echo "=== $CMD $F$1"
    ROW=""
    [ "$F" != A ] && ROW="rcd:200,208;wait:800;rcd:200,$F;wait:1500;"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,400;800,400;cmd:$CMD;wait:3000;${ROW}rcd:$(cell $1);wait:700;rcd:$(cell $1),d;wait:1500;$2;450,400;wait:600;550,400;wait:600;saveas:p190_${CMD}_$F$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
a=${3:-1}; b=${4:-16}
i=$a; while [ $i -le $b ]; do run $i 'wait:100'; i=$((i+1)); done
idle
