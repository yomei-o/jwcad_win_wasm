#!/bin/sh
# 面取 (32859) の五つの指定を、交わる二本（decomp/res/new.jww の下に二本引く）で。
#   sh tools/probe173.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,300;700,500;300,500;700,300;cmd:32859;pb:$2;dlgoff;ch:1411,$3;400,350;400,450;saveas:p173_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
}
run m1689 1689 1000
run m1690 1690 1000
run m1691 1691 1000
run m1692 1692 1000
run m1693 1693 1000
idle
