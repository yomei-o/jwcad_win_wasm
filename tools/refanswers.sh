#!/bin/sh
# Make the original draw the answers the tests are scored against.
#
#   sh tools/refanswers.sh
#
# decomp/ is not committed -- it is machine output taken from someone else's
# program -- so a new machine has to make these again.  RESUME.md has the table
# this script is the executable form of: each entry is one run of
# tools/jwdraw.ps1 that opens a copy of Test5.jww, draws what is needed, runs
# the command and saves the result under a new name.
#
# The clicks are plain posted messages.  RESUME.md's table moved the real
# cursor first (the `c` steps); that is not needed, and it made the picks miss
# -- the status line stayed on the "指示してください" of the first stage through a
# `c` pick and only moved on at the next plain one.
#
# **Driving the original is not reliable.**  The same run, with the same
# registry and the same clicks, lands the picks most of the time and otherwise
# leaves the command sitting on its first stage with nothing drawn.  So every
# drawing is checked by running the test that scores against it, and made again
# when that disagrees.  A drawing that never converges is then a real
# disagreement with the original rather than a flaky run, and the message says
# which test to look at.
#
# Nothing here reads the screen.  The window is shown -- it has to be -- but
# kept at the back, so the machine stays usable, unlike tools/refshots.sh.
#
# The window has to be the one docs/ref_*.png were taken with, because the
# view's size decides what paper coordinates the clicks land on.
# tools/refenv.sh puts it back, and is run again at the end because a `saveas:`
# step turns the Windows common file dialog on in HKCU.
set -e
cd "$(dirname "$0")/.."
mkdir -p decomp/res tmp

PS='powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1'
TRIES=${TRIES:-5}

# Nothing of the original left running: it writes HKCU on the way out, and a
# refenv.sh that lands before that write is undone by it.
idle() {
    n=0
    while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do
        n=$((n + 1))
        [ $n -gt 60 ] && { echo "Jw_win.exe will not go away" >&2; exit 1; }
        sleep 1
    done
}

drive() {                       # drive <name> <cmd> <clicks>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd "$2" \
        -Clicks "$3;saveas:decomp/res/$1.jww" 2>&1 | sed 's/^/        /'
}

# make <test> <name> <cmd> <clicks> [<name2> <cmd2> <clicks2>]
make() {
    t=$1; shift
    try=1
    while :; do
        echo "=== $1${4:+ + $4}"
        drive "$1" "$2" "$3"
        [ $# -gt 3 ] && drive "$4" "$5" "$6"
        if [ ! -x "tests/${t}_test.exe" ]; then
            echo "    (tests/${t}_test.exe is not built -- not checked)"
            return 0
        fi
        if ./tests/"${t}"_test.exe >tmp/refanswers.out 2>&1; then
            echo "    ok -- tests/${t}_test.exe agrees"
            return 0
        fi
        try=$((try + 1))
        if [ "$try" -gt "$TRIES" ]; then
            echo "    tests/${t}_test.exe still disagrees after $TRIES tries:"
            sed 's/^/        /' tmp/refanswers.out
            return 1
        fi
        echo "    tests/${t}_test.exe disagrees -- drawing it again ($try/$TRIES)"
    done
}

fails=0

# 新規図面のひな型: start with no file and save it as it comes up.  There is no
# test for this one -- it is the template src/gen/newjww.c is baked from.
idle
sh tools/refenv.sh >/dev/null
echo "=== new"
$PS -Open '' -Clicks 'saveas:decomp/res/new.jww' 2>&1 | sed 's/^/        /'

# 寸法 (0x804f).  A line first: the third stage will not take a point there is
# nothing to read at, so an empty drawing never gets past it.
make sunpo sunpo 0 \
    '300,600;700,600;cmd:32847;400,500;400,450;r300,600;r700,600' || fails=$((fails+1))

# 多角形 (0x807e).  角数 8, 寸法 3000, 底辺角度 30, then one click for the
# centre -- the eight vertices follow from those three numbers.
make poly poly 32894 \
    'ch:1413,8;ch:1411,3000;ch:1414,30;500,400' || fails=$((fails+1))

# 面取 (0x805b), 角面・辺寸法 2000.  Two lines that meet at a corner.
make mentori mentori 0 \
    '300,600;700,600;700,600;700,300;cmd:32859;ch:1411,2000;500,600;700,450' || fails=$((fails+1))

# 分割 (0x8063), 3 ways.  Two lines that are neither parallel nor the same
# length, so the k/n rule cannot be confused with anything simpler.
make bunkatsu bunkatsu 0 \
    '300,300;700,300;350,600;900,700;cmd:32867;ch:1411,3;500,300;600,650' || fails=$((fails+1))

# ２線 (0x807c), 間隔 2000,1000.  Once with the base line drawn left to right
# and the two points on it, once drawn right to left with the points above it:
# between them they say the pair follows the line's own direction and not the
# side that was clicked.
make nisen \
    nisen  0 '300,400;900,400;cmd:32892;ch:1412,2000,1000;600,400;500,400;800,400' \
    nisen2 0 '900,400;300,400;cmd:32892;ch:1412,2000,1000;600,400;500,350;800,350' \
    || fails=$((fails+1))

# 中心線 (0x8069).  Two level lines, then two that meet at an angle.
make chushin \
    chushin  0 '300,300;700,300;300,600;700,600;cmd:32873;500,300;500,600;400,450;800,450' \
    chushin2 0 '300,300;700,300;300,600;900,450;cmd:32873;500,300;600,525;400,450;800,450' \
    || fails=$((fails+1))

# 接線 (0x8066), 円→円.  Two circles, then the same pair pointed at four
# different ways: two circles have four common tangents and which one comes
# out is settled by the side each was pointed at.  These do not start from
# Test5's own elements, so they have their own drive.
sessen() {              # sessen <name> <pick on the first> <pick on the second>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 0 \
        -Clicks "cmd:32773;300,300;360,300;700,400;790,400;cmd:32870;$2;$3;saveas:decomp/res/sessen_$1.jww" \
        2>&1 | sed 's/^/        /'
}
# 接線, 点→円 (the bar's 1690).  One circle and a point outside it, which has
# two tangents; the one that comes out touches nearer where the circle was
# pointed at.  The point goes first and the circle second -- the other way
# round draws nothing, whatever the status line asks for.
tensen() {              # tensen <name> <pick on the circle>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32773 \
        -Clicks "500,400;590,400;cmd:32870;btn:1690;200,250;$2;saveas:decomp/res/tensen_$1.jww" \
        2>&1 | sed 's/^/        /'
}
try=1
while :; do
    echo "=== sessen (four tangents over one pair of circles, and four from a point)"
    sessen tt 300,240 700,310
    sessen bb 300,360 700,490
    sessen tb 300,240 700,490
    sessen bt 300,360 700,310
    tensen ur 564,336
    tensen lr 564,464
    tensen ul 436,336
    tensen ll 436,464
    if [ ! -x tests/sessen_test.exe ]; then
        echo "    (tests/sessen_test.exe is not built -- not checked)"
        break
    fi
    if ./tests/sessen_test.exe >tmp/refanswers.out 2>&1; then
        echo "    ok -- tests/sessen_test.exe agrees"
        break
    fi
    try=$((try + 1))
    if [ "$try" -gt "$TRIES" ]; then
        echo "    tests/sessen_test.exe still disagrees after $TRIES tries:"
        sed 's/^/        /' tmp/refanswers.out
        fails=$((fails + 1))
        break
    fi
    echo "    tests/sessen_test.exe disagrees -- drawing it again ($try/$TRIES)"
done

# 接円 (0x8068).  Two crossed lines and a radius leave four circles touching
# both, one in each angle; the third click takes the one nearest it.  Two
# parallel lines have none unless they happen to be 2r apart, which is why
# these are crossed.
sekien() {              # sekien <name> <where the circle goes>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 0 \
        -Clicks "300,250;900,600;300,600;900,250;cmd:32872;ch:1411,2000;400,308;400,542;$2;saveas:decomp/res/sekien_$1.jww" \
        2>&1 | sed 's/^/        /'
}
try=1
while :; do
    echo "=== sekien (four circles of one radius in the angles of two lines)"
    sekien l 400,425
    sekien r 800,425
    sekien t 600,300
    sekien b 600,550
    if [ ! -x tests/sekien_test.exe ]; then
        echo "    (tests/sekien_test.exe is not built -- not checked)"
        break
    fi
    if ./tests/sekien_test.exe >tmp/refanswers.out 2>&1; then
        echo "    ok -- tests/sekien_test.exe agrees"
        break
    fi
    try=$((try + 1))
    if [ "$try" -gt "$TRIES" ]; then
        echo "    tests/sekien_test.exe still disagrees after $TRIES tries:"
        sed 's/^/        /' tmp/refanswers.out
        fails=$((fails + 1))
        break
    fi
    echo "    tests/sekien_test.exe disagrees -- drawing it again ($try/$TRIES)"
done

# 曲線 (0x808c), スプライン.  The same four points at four 分割数, which is
# what says both what the curve is and where it samples it.
curve() {               # curve <分割数>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32908 \
        -Clicks "ch:1411,$1;300,500;500,300;700,500;900,300;btn:1800;saveas:decomp/res/curve_n$1.jww" \
        2>&1 | sed 's/^/        /'
}
# ベジェ曲線 over the same four points.  It does not pass through the middle
# ones, so the test takes the points out of the spline reference above.
bezier() {              # bezier <分割数>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32908         -Clicks "btn:1692;ch:1411,$1;300,500;500,300;700,500;900,300;btn:1800;saveas:decomp/res/bezier_n$1.jww"         2>&1 | sed 's/^/        /'
}
try=1
while :; do
    echo "=== curve (one spline at four 分割数, and the bezier over the same points)"
    curve 3
    curve 4
    curve 7
    curve 10
    bezier 3
    bezier 7
    bezier 10
    if [ ! -x tests/curve_test.exe ]; then
        echo "    (tests/curve_test.exe is not built -- not checked)"
        break
    fi
    if ./tests/curve_test.exe >tmp/refanswers.out 2>&1; then
        echo "    ok -- tests/curve_test.exe agrees"
        break
    fi
    try=$((try + 1))
    if [ "$try" -gt "$TRIES" ]; then
        echo "    tests/curve_test.exe still disagrees after $TRIES tries:"
        sed 's/^/        /' tmp/refanswers.out
        fails=$((fails + 1))
        break
    fi
    echo "    tests/curve_test.exe disagrees -- drawing it again ($try/$TRIES)"
done

idle
sh tools/refenv.sh >/dev/null
echo
ls -l decomp/res/*.jww
[ "$fails" -eq 0 ] || { echo; echo "$fails of them never came out right"; exit 1; }
