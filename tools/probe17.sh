#!/bin/sh
# 円周 (1067), fifth pass -- with read points that lie on the circle.
#
#   sh tools/probe17.sh
#
# The four passes before got 円周 as far as 「○　寸法の始点を指示して
# 下さい　（左回り）円周」 and no further, with left clicks and with right
# ones, on the circle and off it.
#
# That prompt (5331) is the ordinary dimension's 「寸法の始点」, and there
# the original takes a **read** point only -- there is no (L)free on it.
# A right click on a bare circle reads its centre, which is not on the
# circle, so this puts a chord across it whose two ends are on it, and
# reads those.
#
# The circle is centre (500,400) through (620,400), radius 120 view
# pixels, so (500,280) is the top of it and the chord runs between them.
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

# the circle and the chord on their own, to subtract
run base 'cmd:32773;500,400;620,400;cmd:32771;620,400;500,280;saveas:p17_base'
# and with 円周 on top of it
run enshu 'cmd:32773;500,400;620,400;cmd:32771;620,400;500,280;cmd:32847;btn:1067;620,400;read:59393;660,400;read:59393;700,400;read:59393;r620,400;read:59393;r500,280;read:59393;saveas:p17_enshu'
idle
