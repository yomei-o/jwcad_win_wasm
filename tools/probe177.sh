#!/bin/sh
# 面取 (32859) の 実寸 (2096)。
#   sh tools/probe177.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,300;800,300;400,200;700,400;cmd:32859;$2450,300;650,367;saveas:p177_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
run j1000 'pb:2096;dlgoff;ch:1411,1000;'
run j10   'pb:2096;dlgoff;ch:1411,10;'
run n10   'ch:1411,10;'
idle
