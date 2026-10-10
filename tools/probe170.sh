#!/bin/sh
# 多角形 (32894) の 任意 (1070): 頂点を積んで 作図 (1069) で閉じる。
#   sh tools/probe170.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "cmd:32894;pb:1070;dlgoff;$2saveas:p170_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
run p3     '400,350;600,450;500,420;pb:1069;'
run p4     '400,350;600,450;500,420;300,300;pb:1069;'
run p3solid 'pb:1323;dlgoff;400,350;600,450;500,420;pb:1069;'
run p3r    '400,350;600,450;500,420;r500,420;'
run p2     '400,350;600,450;pb:1069;'
run p3curve 'pb:1325;dlgoff;400,350;600,450;500,420;pb:1069;'
run p4back '400,350;600,450;500,420;300,300;raw:f,273,57643,0;wait:500;pb:1069;'
idle
