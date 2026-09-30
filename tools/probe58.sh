#!/bin/sh
# 貼り付け (57637): what point of the copy lands on the click.
#
#   sh tools/probe58.sh
#
# tools/probe56.sh settled the shape of it:
#
#   コピー (57634)   wants a range picked first; the bar and the status
#                    line do not change, so nothing is visible
#   貼り付け (57637) puts up **図形読込's own command** -- the prompt is
#                    「【図形】の複写位置を指示してください (L)free
#                    (R)Read」 and the bar carries 作図属性・倍率(1431)・
#                    回転角(1412)・90ﾟ毎・マウス角・グループ化
#   切り取り (57635) takes the selection away
#
# and one paste came out shifted by (0, -110.204) for a click 180 pixels
# below the selection's middle.  That says the base point is the middle
# of what was copied, but one paste cannot tell the middle from, say, the
# first element's start.  So: a selection that is **not** symmetric, and
# three pastes at three different places.
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

# an L shape: a long line low down and a short one high up, so the middle
# of the box is nowhere near any endpoint
L='cmd:32771;off:1333;300,400;700,400;300,400;300,300;'
SEL='cmd:32787;280,280;r720,420;'
C="${SEL}cmd:57634;"

run here  "${L}${C}cmd:57637;400,500;saveas:p58_here"
run right "${L}${C}cmd:57637;800,500;saveas:p58_right"
run up    "${L}${C}cmd:57637;400,200;saveas:p58_up"
# and what 倍率 and 回転角 do to it
run mag2  "${L}${C}cmd:57637;chr:1431,2;400,500;saveas:p58_mag2"
run rot90 "${L}${C}cmd:57637;chr:1412,90;400,500;saveas:p58_rot90"
idle
sh tools/refenv.sh >/dev/null
