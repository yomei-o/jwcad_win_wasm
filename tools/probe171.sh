#!/bin/sh
# 多角形 任意 のソリッド図形: 点が 4・5・6 のとき。
#   sh tools/probe171.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "cmd:32894;pb:1070;dlgoff;pb:1323;dlgoff;$2pb:1069;saveas:p171_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
run s4 '400,350;600,450;500,420;300,300;'
run s5 '400,350;600,450;500,420;300,300;350,200;'
run s6 '400,350;600,450;500,420;300,300;350,200;450,250;'
run s5c '400,350;600,450;500,300;300,300;350,200;'
idle
