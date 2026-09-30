#!/bin/sh
# The number ２点間角度 leaves, read off the box rather than off a line.
#
#   sh tools/probe47.sh
#
# probe28, probe43 and probe46 all read it by drawing a line afterwards
# and measuring that, which only ever gives the angle **modulo 180**:
#
#   θ = -26.565  ->  the line came out at 116.565
#   θ = -14.036  ->  104.036
#   θ = +14.036  ->   75.964
#
# so the rule is 90 - θ, and X軸角度 (32933) in the same place gives θ
# itself.  What the box actually holds -- 75.964 or -104.036, which draw
# the same line -- is still unread.  So this takes the angle and then
# puts the 線 bar up and reads its 傾き box (1412) straight.
#
# And the other half: where 間隔取得 (32948) puts its distance.  probe44
# showed it is not a 長さ, and probe46 showed neither the 線 bar nor the
# 複線 bar has it in a box -- both came up empty with it and without.
# What is left is that it is the 複線's offset without being shown, so
# here 複線 is walked all the way through, with it and without, and the
# status line is read at every step to see where the walk actually goes.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|ComboBox\|141|throw|no |saved" | sed 's/^/    /'
}

# the angle box, three ways
M='cmd:32771;bar:32771'
N='cmd:32771;off:1333;300,300;700,400;'   # -14.036 degrees
P='cmd:32771;off:1333;300,500;700,400;'   # +14.036
run box_k_neg "${N}cmd:32934;r300,300;r700,400;${M}"
run box_k_pos "${P}cmd:32934;r300,500;r700,400;${M}"
run box_x_neg "${N}cmd:32933;r300,300;r700,400;${M}"
run box_none  "${N}${M}"

# 複線, walked with the status line read at every step
L='cmd:32771;off:1333;300,300;700,500;'
G='cmd:32948;500,400;r300,600;'
R='read:59393;'
run fuku_k  "${L}${G}cmd:32800;${R}500,400;${R}500,200;${R}500,200;${R}saveas:p47_fuku_k"
run fuku_0  "${L}cmd:32800;${R}500,400;${R}500,200;${R}500,200;${R}saveas:p47_fuku_0"
idle
sh tools/refenv.sh >/dev/null
