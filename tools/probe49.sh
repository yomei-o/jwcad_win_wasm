#!/bin/sh
# The last two places 間隔取得 (32948) could be going.
#
#   sh tools/probe49.sh
#
# By now it is not: a 長さ (probe44), any box on the 線 or 複線 bar
# (probe46, probe47), 複線's clicked offset (probe47), or 複線's 前回値
# (probe48) -- all of those came out the same with the grab and without.
#
# The two commands left whose whole business is a 間隔 are ２線 (32892)
# and 中心線 (32873).  Each is put up right after the grab and its bar is
# read, and then again with no grab in front of it.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|ComboBox|Edit\|14|throw|no " | sed 's/^/    /'
}

L='cmd:32771;off:1333;300,300;700,500;'
G='cmd:32948;500,400;r300,600;'
R='read:59393;'

run nisen_k  "${L}${G}cmd:32892;${R}bar:32892"
run nisen_0  "${L}cmd:32892;${R}bar:32892"
run chushin_k "${L}${G}cmd:32873;${R}bar:32873"
run chushin_0 "${L}cmd:32873;${R}bar:32873"
idle
sh tools/refenv.sh >/dev/null
