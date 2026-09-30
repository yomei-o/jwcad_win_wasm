#!/bin/sh
# The angle and length the original shows on the status line.
#
#   sh tools/probe26.sh
#
# Every read of 59393 in the probes so far has carried a tail the port
# does not draw:
#
#   始点を指示してください  (L)free  (R)Read   [ -26.565°]   27,380.424
#   始点を指示してください  (L)free  (R)Read   [ 0.000°]   24,489.795
#
# -- the angle and the real length of the line just drawn.  This asks
# when it appears, what it says for the other commands, and what it does
# before anything has been drawn at all.
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

# nothing drawn yet, then one point of a line, then the whole line
run sen 'read:59393;cmd:32771;off:1333;read:59393;300,300;read:59393;700,500;read:59393;300,600;read:59393'
# a rectangle, a circle and an arc
run kukei 'cmd:32772;read:59393;300,300;700,500;read:59393'
run enko  'cmd:32773;read:59393;400,400;500,400;read:59393'
# and after leaving the command
run leave 'cmd:32771;off:1333;300,300;700,500;read:59393;cmd:32785;read:59393'
idle
