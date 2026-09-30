#!/bin/sh
# The rest of 角度取得 and 長さ取得, one click at a time.
#
#   sh tools/probe27.sh
#
# 線角度・線鉛直角度・線長・２点間長 are settled (tools/probe20.sh ..
# probe23.sh).  Left over: X軸角度 (32933), ２点間角度 (32934), 軸角
# (32962), 数値角度 (32938), 数値長 (32941) and 間隔取得 (32948).  Two
# read points and two clicks after them drew nothing for 32933 and 32934,
# so this reads the status line after **every** click to see where the
# walk actually goes, and draws a second line at the end so the effect
# shows up in the file.
#
# The reference line runs (300,300) to (700,500) with 水平･垂直 off,
# which is -26.565 degrees and 273.804 long on the paper.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |^top " | sed 's/^/    /'
}

L='cmd:32771;off:1333;300,300;700,500;'
R='read:59393;'
S='300,600;600,650;'
run x2    "${L}cmd:32933;${R}r300,300;${R}r700,500;${R}${S}saveas:p27_x2"
run k2    "${L}cmd:32934;${R}r300,300;${R}r700,500;${R}${S}saveas:p27_k2"
run jiku  "${L}cmd:32962;${R}tops;${S}saveas:p27_jiku"
run num_k "${L}cmd:32938;${R}tops;bar"
run num_n "${L}cmd:32941;${R}tops;bar"
run kan   "${L}cmd:32948;${R}500,400;${R}300,600;${R}"
idle
