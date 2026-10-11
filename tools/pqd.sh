#!/bin/sh
# 建具の窓の一つの状態を見る（探りの道具）。
#   sh tools/pqd.sh <コマンド番号> <入れ物> '<窓を開いてからの steps>' '<そのあとの steps>'
# 入れ物は tmp/ の下の、JW_OPT?.DAT を一つだけ置いたフォルダ（木の行を押さずに済む）。
# 壁（300,400）→（800,400）を引いてからコマンドに入る。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
sh tools/refenv.sh >/dev/null
W=$(pwd -W | tr '/' '\\')
FOLDER="${W}\\tmp\\$2"
for k in TATEGUHEIMEN TATEGUDANMEN TATEGURITSUMEN; do
    powershell -Command "Set-ItemProperty -Path 'HKCU:\\Software\\Jw_cad\\jw_win\\Folder' -Name $k -Value '$FOLDER'"
done
cp decomp/res/new.jww tmp/rect.jww
$PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,400;800,400;cmd:$1;wait:3000;$3;wait:1500;$4" 2>&1 | grep -v "^tr\|^Afx" | cut -c1-110
for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done
