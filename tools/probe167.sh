#!/bin/sh
# 多角形 (32894) の 2辺 (1689)。箱は 1412（「横 , 縦」）。
#   sh tools/probe167.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "cmd:32894;pb:1689;dlgoff;$2saveas:p167_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
run abc    '400,350;600,450;500,420;'
run abcd   '400,350;600,450;500,420;300,300;'
run abcd2  '400,350;600,450;300,500;300,300;'
run b700   'ch:1412,700,500;400,350;600,450;500,420;'
run b700d  'ch:1412,700,500;400,350;600,450;500,420;300,300;'
run b0     'ch:1412,0;400,350;600,450;500,420;300,300;'
run ab     '400,350;600,450;'
idle
