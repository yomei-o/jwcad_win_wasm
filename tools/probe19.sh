#!/bin/sh
# 角度取得 and 長さ取得, second pass -- with the line actually hit.
#
#   sh tools/probe19.sh
#
# tools/probe18.sh found that 線角度 (32932) puts 「基準線を指示して
# ください。」 on the status line, so it wants a line pointed at.  Its
# click missed: 線 comes up with 水平･垂直 ticked, so the line drawn
# between (300,300) and (700,500) came out horizontal at y=300 and the
# pick at (500,400) was a hundred pixels under it.
#
# Here 水平･垂直 is turned off first (off:1333), so the line really does
# run from (300,300) to (700,500) -- four hundred across and two hundred
# down the screen, which is 26.565 degrees up in paper terms -- and the
# pick is on it.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|ComboBox|Edit\||throw|no |top " | sed 's/^/    /'
}

# 線, 水平･垂直 off, a line from (300,300) to (700,500)
L='cmd:32771;off:1333;300,300;700,500;'
run kakudo_sen  "${L}cmd:32932;read:59393;500,400;read:59393;bar"
run kakudo_suic "${L}cmd:32935;read:59393;500,400;read:59393;bar"
run kakudo_2ten "${L}cmd:32934;read:59393;r300,300;read:59393;r700,500;read:59393;bar"
run nagasa_sen  "${L}cmd:32939;read:59393;500,400;read:59393;bar"
run nagasa_2ten "${L}cmd:32940;read:59393;r300,300;read:59393;r700,500;read:59393;bar"
run kankaku     "${L}cmd:32948;read:59393;500,400;read:59393;bar"
idle
