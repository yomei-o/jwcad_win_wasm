#!/bin/sh
# 角度取得・長さ取得, third pass: how long the value lasts, and who wins.
#
#   sh tools/probe21.sh
#
# tools/probe20.sh found what they do by drawing the same second line with
# and without.  The reference line runs -26.565 degrees and is 273.804 long:
#
#   線角度 (32932)  the next line comes out at -26.565 degrees, and its
#                   length is the click projected on to that way -- exactly
#                   what typing into the 傾き box does
#   線長   (32939)  the next line keeps the way it was clicked and comes
#                   out 273.804 long -- exactly what the 寸法 box does
#
# So the value is not in the box (the box stays empty) but behaves like it.
# What is left to ask: does it hold for the line after that as well, does
# it survive leaving the command, and what happens when the box has a
# number in it too.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no " | sed 's/^/    /'
}

L='cmd:32771;off:1333;300,300;700,500;'
# two more lines after taking the angle: does the second one keep it?
run twice   "${L}cmd:32932;500,400;300,600;600,650;300,660;600,680;saveas:p21_twice"
# leave 線 for 円 and come back
run leave   "${L}cmd:32932;500,400;cmd:32773;cmd:32771;300,600;600,650;saveas:p21_leave"
# the 傾き box has 60 in it as well
run withbox "${L}cmd:32932;500,400;chr:1411,60;300,600;600,650;saveas:p21_withbox"
# X軸角度 on its own, then a line
run xkaku   "${L}cmd:32933;read:59393;300,600;read:59393;600,650;read:59393;saveas:p21_xkaku"
idle
