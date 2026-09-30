#!/bin/sh
# 一括処理 (1072) and 実行 (1120), now that what wakes them is known.
#
#   sh tools/probe38.sh
#
# tools/probe37.sh pressed every other button of the 寸法 bar and none of
# them woke the two.  **Drawing a dimension does**: after one is in,
# 一括処理 comes alive (its style goes from 58010f00 to 50010f00) while
# 実行 stays asleep.  So 一括処理 works from a dimension that is already
# there, and 実行 must be waiting on whatever it asks for next.
#
# This draws a dimension, presses 一括処理, and then reads the status line
# and the bar after each click, to see what it wants and when 実行 wakes.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "^=== |Button\|(1072|1120)\||read 59393|throw|no " |
        sed 's/^/    /'
}

# two lines to measure between, a dimension on the first, then 一括処理
L='cmd:32771;off:1333;300,300;700,300;300,400;700,400;cmd:32847;'
D='300,200;300,250;r300,300;r700,300;'
R='read:59393;'
run ikkatsu "${L}${D}${R}btn:1072;${R}bar:1;400,400;${R}bar:2;600,400;${R}bar:3;saveas:p38_ikkatsu"
idle
sh tools/refenv.sh >/dev/null
