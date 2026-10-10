#!/bin/sh
# 分割 (32867) の 等角度分割 (1690)。交わる二本と、平行な二本。
#   sh tools/probe178.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;$2cmd:32867;pb:1690;dlgoff;ch:1411,$3;$4saveas:p178_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
A='300,300;700,500;350,600;600,300;'
run x4  "$A" 4 '400,350;400,540;'
run x3  "$A" 3 '400,350;400,540;'
run x4b "$A" 4 '620,310;400,540;'
run par '300,300;700,300;300,500;700,500;' 4 '400,300;400,500;'
idle
