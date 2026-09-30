#!/bin/sh
# What decides the printed size.
#
#   sh tools/probe33.sh
#
# The first PDF the original wrote (tools/probe32.sh) put a 244.898 by
# 122.449 mm line on the paper 194.4 by 97.2 mm -- 0.79375 of full size,
# which is three device units to the millimetre on a 96 dpi printer.  The
# clip rectangle round it is that same box and nothing more, so it is not
# the sheet that is being printed.  Two things could give 0.794:
#
#   a fixed scale, whatever is drawn, or
#   the drawn extent fitted to the paper
#
# and one run tells them apart: draw a line twice as long and print it.
# If the scale is fixed the printed line doubles; if it is a fit, it does
# not grow past the paper.
#
# The third run changes the sheet to A-4 first and saves, to be sure the
# sheet really is changing when 32824 is sent.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
P='raw:f,273,57607,0;wait:2000;pb:1;wait:1500;pb:1065;'
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 | sed 's/^/    /'
}

# a short line and a long one, both printed
run small "cmd:32771;off:1333;500,350;600,400;${P}savedlg:tmp/orig_small.pdf"
run big   "cmd:32771;off:1333;90,50;1090,650;${P}savedlg:tmp/orig_big.pdf"
# and does 32824 really change the sheet?
run a4chk 'cmd:32771;off:1333;300,300;700,500;raw:f,273,32824,0;saveas:p33_a4'
idle
sh tools/refenv.sh >/dev/null
