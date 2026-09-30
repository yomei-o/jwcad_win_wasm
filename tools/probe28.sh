#!/bin/sh
# ２点間角度 (32934) and 軸角 (32962), the last two of the family.
#
#   sh tools/probe28.sh
#
# X軸角度 (32933) is settled: two read points, and the angle between them
# (tools/probe27.sh's x2 run drew its second line at -26.565).  ２点間角度
# shows the same two prompts and takes the same two clicks, but no run has
# caught what it leaves behind -- its second line never finished.  Here it
# gets clicks to spare.
#
# And since X軸角度 already means「二点の間の角」, the two must differ in
# what they measure from.  The likely difference is the axis: one from the
# X axis, one from 軸角.  So each is run again with 軸角 30 set first.
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

L='cmd:32771;off:1333;300,300;700,500;'
S='300,600;600,650;300,660;600,680;'
run k2      "${L}cmd:32934;r300,300;r700,500;${S}saveas:p28_k2"
run jiku    "${L}cmd:32962;${S}saveas:p28_jiku"
# the same two with 軸角 30 in force
J='dlgin:32842,1411=30;'
run x2_30   "cmd:32771;${J}off:1333;300,300;700,500;cmd:32933;r300,300;r700,500;${S}saveas:p28_x2_30"
run k2_30   "cmd:32771;${J}off:1333;300,300;700,500;cmd:32934;r300,300;r700,500;${S}saveas:p28_k2_30"
idle
