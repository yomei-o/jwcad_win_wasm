#!/bin/sh
# 面取 (32859) の Ｌ面 (1692) の 切断間隔 (1413) と、楕円面の鈍角。
#   sh tools/probe175.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {   # name, lines, script
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;$2cmd:32859;$3saveas:p175_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
A='300,300;700,500;350,600;600,300;'
run l2000 "$A" 'pb:1692;dlgoff;ch:1413,2000;400,350;400,540;'
run l0    "$A" 'pb:1692;dlgoff;ch:1413,0;400,350;400,540;'
run l1411 "$A" 'pb:1692;dlgoff;pb:1689;dlgoff;ch:1411,1000;pb:1692;dlgoff;400,350;400,540;'
# 鈍角: 二本の保った側がほとんど逆向き
B='300,300;700,320;350,600;450,300;'
run eobt  "$B" 'pb:1693;dlgoff;ch:1411,1000;350,303;352,500;'
run robt  "$B" 'pb:1691;dlgoff;ch:1411,1000;350,303;352,500;'
run robt2 "$B" 'pb:1691;dlgoff;ch:1411,1000;600,312;352,500;'
idle
