#!/bin/sh
# Still chasing the swallowed 元に戻る.
#
#   sh tools/probe54.sh
#
# Three lines, then n presses of 元に戻る, 700 ms either side of each:
#
#   n = 1  ->  2 lines left   (1 press took)
#   n = 2  ->  2              (1 took)
#   n = 3  ->  1              (2 took)
#   n = 4  ->  0              (3 took, or more -- the floor is 3)
#   n = 5  ->  0
#
# so one press goes missing as soon as there is more than one, and a
# mouse move between them does not bring it back (tools/probe53.sh).
# Two things left to try before believing the original works that way:
#
#   slow   two seconds either side instead of 0.7
#   menu   the same command sent as `cmd:` rather than a raw WM_COMMAND
#
# If either gets two presses to take, the walk was a timing artefact and
# 進む can be measured properly; if neither does, then the original
# really does ignore the second press and **that** is the thing to match.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

L3='cmd:32771;off:1333;300,300;500,300;300,320;500,320;300,340;500,340;'
SL='wait:2000;raw:f,273,57643,0;wait:2000;'
MN='wait:700;cmd:57643;wait:700;'

run slow "${L3}${SL}${SL}saveas:p54_slow"
run menu "${L3}${MN}${MN}saveas:p54_menu"
idle
sh tools/refenv.sh >/dev/null
