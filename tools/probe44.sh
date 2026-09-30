#!/bin/sh
# Where 間隔取得 (32948) puts the distance it shows.
#
#   sh tools/probe44.sh
#
# tools/probe27.sh already had the original say what it measures: point a
# line out, then a point, and the status line shows the length of the
# perpendicular from the point to the line, in real units.  With the line
# (-155.51,26.33)-(89.39,-96.12) and the point (-155.51,-157.35) it said
# 16,428.254, which is 164.28 mm at 1/100.
#
# What it does with it was never asked.  It sits in the 長さ取得 menu, so
# the obvious answer is that it is a 長さ like 線長 and ２点間長 -- but
# that is a guess, and 複線's 間隔 is the other candidate the name points
# at.  So the original is made to answer both:
#
#   len   間隔取得, then 線: if it is a 長さ, the line drawn afterwards
#         comes out 164.28 mm long whatever the second click is.
#   fuku  間隔取得, then 複線 on the same line: if it is the 間隔, the
#         copy lands 164.28 mm off.
#
# The control run has no 間隔取得 in it at all, so the difference is the
# original's own answer and not this file's.
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

# one line to point at, drawn the same way in every run
L='cmd:32771;off:1333;300,300;700,500;'
# 間隔取得: the line, then the point
K='cmd:32948;500,400;r300,600;'
R='read:59393;'

run kan   "${L}${K}${R}saveas:p44_kan"
run len   "${L}${K}cmd:32771;300,600;600,650;saveas:p44_len"
run len0  "${L}cmd:32771;300,600;600,650;saveas:p44_len0"
run fuku  "${L}${K}cmd:32800;500,400;500,200;saveas:p44_fuku"
run fuku0 "${L}cmd:32800;500,400;500,200;saveas:p44_fuku0"
idle
sh tools/refenv.sh >/dev/null
