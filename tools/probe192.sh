#!/bin/sh
# 建具立面 (32865): JW_OPT3* の建具を、設定を変えて置かせる。
#   sh tools/probe192.sh <名前> <木の行 y か A> <建具の番号> '<設定の steps>' '<クリックの steps>'
# 結果は tmp/p192_<名前>.jww。ますは 4×4（客領域の中心 x=389+204c・y=94+144r）。
cd "$(dirname "$0")/.."
# 原典は建具の窓を閉じるたびに orig/ に空の 20…-…-… を作り、木の行が一つずつずれていく
for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done; }
NAME=$1; F=$2; N=$3; SET=$4; CLK=$5
r=$(( (N - 1) / 4 )); c=$(( (N - 1) % 4 ))
CELL="$(( 389 + c * 204 )),$(( 94 + r * 144 ))"
idle; sh tools/refenv.sh >/dev/null
W=$(pwd -W | tr '/' '\')
for k in TATEGUHEIMEN TATEGUDANMEN TATEGURITSUMEN; do
    powershell -Command "Set-ItemProperty -Path 'HKCU:\Software\Jw_cad\jw_win\Folder' -Name $k -Value '${W}\orig'"
done
cp decomp/res/new.jww tmp/rect.jww
ROW=""
[ "$F" != A ] && ROW="rcd:200,208;wait:800;rcd:200,$F;wait:1500;"
$PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;cmd:32865;wait:3000;${ROW}rcd:$CELL;wait:700;rcd:$CELL,d;wait:1500;${SET}${CLK}saveas:p192_$NAME;" 2>&1 | grep -E "throw|no |saved|read" | sed 's/^/    /'
idle
