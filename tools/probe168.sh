#!/bin/sh
# 多角形 (32894) の 2辺 (1689) の続き。二辺の長さを十分に大きく。
#   sh tools/probe168.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "cmd:32894;pb:1689;dlgoff;$2saveas:p168_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
run big    'ch:1412,10000,10000;400,350;600,450;500,420;'
run bigd   'ch:1412,10000,10000;400,350;600,450;500,420;300,300;'
run uneq   'ch:1412,8000,12000;400,350;600,450;500,420;'
run uneqo  'ch:1412,8000,12000;400,350;600,450;700,200;'
run one    'ch:1412,10000;400,350;600,450;500,420;'
run xonly  'ch:1412,0,10000;400,350;600,450;500,420;'
run zero   'ch:1412,0;400,350;600,450;500,420;'
run zero4  'ch:1412,0;400,350;600,450;500,420;300,300;'
run zeroR  'ch:1412,0;400,350;600,450;500,420;r500,420;'
idle
