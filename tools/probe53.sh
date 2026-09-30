#!/bin/sh
# Why a second 元に戻る in a row does nothing.
#
#   sh tools/probe53.sh
#
# tools/probe52.sh drew three lines and pressed 元に戻る one, two and
# three times, with 700 ms either side of every press:
#
#   once    two lines left   -- one press took
#   twice   two lines left   -- the second did nothing
#   thrice  one line left    -- so two of the three took
#
# Either the original swallows a press that comes straight after another,
# or the posted message is being lost.  A posted WM_COMMAND cannot be
# coalesced away, but Jw_cad may well want the mouse to have moved.  So:
#
#   m2     the same two presses with a mouse move between them
#   u4/u5  four and five presses, to see whether it is「every other one」
#          (which would leave 1 and 0 lines) or「the last one」(0 and 0)
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

W='wait:700;'
U="${W}raw:f,273,57643,0;${W}"
M='m600,600;'
L3='cmd:32771;off:1333;300,300;500,300;300,320;500,320;300,340;500,340;'

run m2 "${L3}${U}${M}${U}saveas:p53_m2"
run u4 "${L3}${U}${U}${U}${U}saveas:p53_u4"
run u5 "${L3}${U}${U}${U}${U}${U}saveas:p53_u5"
idle
sh tools/refenv.sh >/dev/null
