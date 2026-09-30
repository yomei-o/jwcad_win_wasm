#!/bin/sh
# 円周 (1067), fourth pass -- with left clicks for the two ends.
#
#   sh tools/probe16.sh
#
# tools/probe15.sh walked 円周 as far as 「寸法の始点を指示して下さい
# （実寸）円周」 and then stopped moving: two right clicks, one on the
# circle and one at the top of it, left the prompt where it was.  A right
# click on a circle reads its centre, which is not on the circle, so this
# tries left clicks (free) instead, and keeps clicking to see whether the
# original ever draws anything.
#
# The circle is centre (500,400) through (620,400), so its radius is 120
# view pixels and (500,280), (380,400), (500,520) are on it.
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

C='cmd:32773;500,400;620,400;cmd:32847;btn:1067;620,400;'
run left  "${C}660,400;700,400;620,400;read:59393;500,280;read:59393;saveas:p16_left"
run onarc "${C}620,400;500,280;read:59393;380,400;read:59393;500,520;read:59393;saveas:p16_onarc"
run many  "${C}660,400;700,400;620,400;500,280;380,400;500,520;620,400;read:59393;saveas:p16_many"
idle
