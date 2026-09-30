#!/bin/sh
# 円周 (1067) and 寸法値 (1069), third pass.
#
#   sh tools/probe15.sh
#
# tools/probe14.sh got 円周 moving: indicating the circle takes it to
# 「引出し線の始点」, then 「寸法線の位置」, and then it asks for
# 「寸法の始点（実寸）円周」 -- so the last two clicks are the two ends of
# the arc it measures.  This walks the whole five.
#
# 寸法値 drew nothing either way so far: two right clicks on the ends of a
# line (probe13) and three left clicks on nothing (probe14).  Here it gets
# a line and left clicks.
#
# The circle is drawn with two clicks, centre (500,400) and (620,400), so
# its radius is 120 view pixels and (500,280) is the top of it.
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

run enshu 'cmd:32773;500,400;620,400;cmd:32847;btn:1067;620,400;read:59393;660,400;read:59393;700,400;read:59393;r620,400;read:59393;r500,280;read:59393;saveas:p15_enshu'
run chi 'cmd:32771;300,300;700,300;cmd:32847;btn:1069;300,300;read:59393;700,300;read:59393;500,350;read:59393;saveas:p15_chi'
run chi2 'cmd:32771;300,300;700,300;cmd:32847;btn:1069;r300,300;read:59393;r700,300;read:59393;500,350;read:59393;saveas:p15_chi2'
idle
