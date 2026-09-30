#!/bin/sh
# 円周 (1067) and 寸法値 (1069), asked of the original again.
#
#   sh tools/probe14.sh
#
# tools/probe13.sh read the status line and found what each one wants:
#
#   円周    「円を指示してください。     円周」
#   寸法値  「【寸法値】の始点指示(L)　移動寸法値指示(R)
#             変更寸法値指示(RR) 2点間[Shift]+(RR)」
#
# The first run missed the circle because the clicks are view pixels and
# the radius was typed in millimetres, so here the circle is drawn with
# two clicks instead -- centre and a point on it -- and that same point is
# what 円周 is given.  What comes out lands in tmp/ as a .jww.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |top " | sed 's/^/    /'
}

# the circle on its own, to subtract
run enshu0 'cmd:32773;500,400;620,400;saveas:p14_circle'
# and with 円周: indicate the circle, then whatever it asks for next
run enshu1 'cmd:32773;500,400;620,400;cmd:32847;btn:1067;620,400;read:59393;700,250;read:59393;800,200;read:59393;saveas:p14_enshu'
# 寸法値: a start point, then what?
run chi1 'cmd:32847;btn:1069;300,300;read:59393;700,300;read:59393;800,350;read:59393;saveas:p14_chi'
idle
