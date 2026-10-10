#!/bin/sh
# 寸法図形 (CDataSunpou) の標本を、原典に作らせる。
#   寸法を一つ引き、寸法図形化 (32928) を [寸法線]→【寸法値】の二手で。
#   sh tools/probe169.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
R='read:59393;'
S='300,600;700,600;cmd:32847;ch:1411,0;400,500;400,450;r300,600;r700,600;'
$PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "${S}raw:f,273,32928,0;wait:700;${R}500,450;${R}495,448;${R}saveas:p169_dimfig" 2>&1 |
    grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
idle
