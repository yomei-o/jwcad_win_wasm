#!/bin/sh
# 面取 (32859): 交わり方が左右対称でない二本で五つの指定。
#   sh tools/probe174.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {   # name, script
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,300;700,500;350,600;600,300;cmd:32859;$2400,350;400,540;saveas:p174_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
run a1689 'pb:1689;dlgoff;ch:1411,1000;'
run a1690 'pb:1690;dlgoff;ch:1411,1000;'
run a1691 'pb:1691;dlgoff;ch:1411,1000;'
run a1692 'pb:1692;dlgoff;'
run a1693 'pb:1693;dlgoff;ch:1411,1000;'
run l5    'pb:1692;dlgoff;ch:1413,5;'
run r50   'pb:1691;dlgoff;ch:1411,5000;'
run e1413 'pb:1693;dlgoff;ch:1411,1000;ch:1413,5;'
idle
