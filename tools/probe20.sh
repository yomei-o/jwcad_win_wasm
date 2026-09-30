#!/bin/sh
# What 角度取得 and 長さ取得 actually change.
#
#   sh tools/probe20.sh
#
# tools/probe19.sh walked them through: 線角度 (32932) asks 「基準線を
# 指示してください。」 and takes a line, ２点間角度 (32934) asks for a
# base point and then an angle point, 線長 (32939) and ２点間長 (32940)
# the same for a length.  But **nothing visible changed**: the two combo
# boxes on the command bar stayed empty and the status line went back to
# what it was.
#
# So the value is kept somewhere the port cannot see from outside, and the
# way to find it is the usual one: draw the same second line twice, once
# with the value taken and once without, and let the difference say.
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

# the reference line runs (300,300)->(700,500), which is -26.565 degrees,
# and the second line is drawn between two quite different points
L='cmd:32771;off:1333;300,300;700,500;'
S='300,600;600,650;'
run plain    "${L}${S}saveas:p20_plain"
run sen_kaku "${L}cmd:32932;500,400;${S}saveas:p20_senkaku"
run sen_naga "${L}cmd:32939;500,400;${S}saveas:p20_sennaga"
run x_kaku   "${L}cmd:32933;${S}saveas:p20_xkaku"
idle
