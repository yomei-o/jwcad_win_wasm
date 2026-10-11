#!/bin/sh
# 多角形 (32894) の 任意 (1070) の 円・連続線指示 (1083) 以下の探り。
#   sh tools/probe173.sh [名前...]   → decomp/res/p173_<名前>.jww
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
CIR='cmd:32773;600,400;800,400;wait:600;'
run() {
    [ -n "$ONLY" ] && ! echo " $ONLY " | grep -q " $1 " && return
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "$CIR$3cmd:32894;pb:1070;dlgoff;$2saveas:p173_$1;" 2>&1 | grep -E "throw|no |saved|Button|stat" | sed 's/^/    /'
}
ONLY="$*"
run c1   'pb:1323;dlgoff;pb:1083;stat;800,400;stat;bar;'
run c2   'pb:1323;dlgoff;pb:1083;800,400;pb:1069;'
run c3   'pb:1323;dlgoff;pb:1083;800,400;350,500;pb:1069;'
run c4   'pb:1323;dlgoff;pb:1325;dlgoff;pb:1083;800,400;pb:1069;'
run c5   'pb:1323;dlgoff;pb:1326;dlgoff;pb:1083;800,400;pb:1069;'
run c6   'pb:1323;dlgoff;pb:1083;800,400;pb:1327;dlgoff;pb:1069;'
run c7   'pb:1323;dlgoff;pb:1083;800,400;pb:1328;dlgoff;pb:1069;'
run c8   'pb:1083;800,400;pb:1069;'
idle
