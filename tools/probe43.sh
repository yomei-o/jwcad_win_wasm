#!/bin/sh
# What ２点間角度 (32934) actually measures.
#
#   sh tools/probe43.sh
#
# tools/probe28.sh did catch it -- the log was filtered so the answers
# went unread.  In its k2 run the two read points were 400 by 200 pixels
# apart, which is -26.565 degrees on the paper, and the line drawn
# afterwards came out at 116.565.  X軸角度 (32933) in the same place
# gives -26.565.
#
# 116.565 is 90 - (-26.565), and it is also 180 - (-26.565 + 90), and it
# is also -(−26.565 + 90) + 180 ... at an angle whose tangent is a half
# far too many things coincide.  So this asks again at an angle that is
# nobody's mirror: 400 by 100 pixels, which is -14.036 degrees.
#
#   X軸角度 should give        -14.036   (the control)
#   90 - θ would give          104.036
#   θ + 90 would give           75.964
#   -θ would give               14.036
#
# The click that follows each one is eaten -- that happened in probe28
# with 軸角 (32962) too, which takes no clicks at all -- so the line to
# read is the one drawn from the second of the four.
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

L='cmd:32771;off:1333;300,300;700,400;'
S='300,600;600,650;300,660;600,680;'
run x2  "${L}cmd:32933;r300,300;r700,400;${S}saveas:p43_x2"
run k2  "${L}cmd:32934;r300,300;r700,400;${S}saveas:p43_k2"
idle
sh tools/refenv.sh >/dev/null
