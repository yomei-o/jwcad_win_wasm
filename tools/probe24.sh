#!/bin/sh
# Three more questions for the original.
#
#   sh tools/probe24.sh
#
# 1. 寸法's 設定 (1071) -- which dialog does it put up?  32925's, the one
#    the menu's 寸法設定 opens, is the obvious guess and guessing is not
#    allowed.
# 2. 寸法's ＝ (1060) -- the label says nothing.
# 3. 進む (57644), the other half of 元に戻る.  What does it put back, and
#    does drawing something new throw it away?
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |^top |  kid .* id=(1|2)\] " | sed 's/^/    /'
}

# what 設定 (1071) opens: press it with pb: so the script is not held, then
# list the top level windows
run sun_settei 'cmd:32847;pb:1071;wait:800;tops'
# ＝ (1060): press it and see what the bar and the status line say
run sun_equal  'cmd:32847;btn:1060;read:59393;bar'
# 進む: three lines, two 元に戻る, two 進む
run susumu     'cmd:32771;off:1333;300,300;500,300;300,320;500,320;300,340;500,340;raw:f,273,57643,0;raw:f,273,57643,0;raw:f,273,57644,0;raw:f,273,57644,0;saveas:p24_susumu'
# and: two lines, one 元に戻る, a new line, then 進む -- is the undone one
# still there to come back?
run susumu2    'cmd:32771;off:1333;300,300;500,300;300,320;500,320;raw:f,273,57643,0;300,360;500,360;raw:f,273,57644,0;saveas:p24_susumu2'
idle
