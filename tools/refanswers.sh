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
# The 傾き box (1411) keeps what was typed into it, so both of these say
# which angle they want.  0 is a level dimension, 30 a slanted one -- the six
# elements come out in the same order either way.
make sunpo sunpo 0 \
    '300,600;700,600;cmd:32847;ch:1411,0;400,500;400,450;r300,600;r700,600' \
    sunpo30 0 \
    '300,600;700,600;cmd:32847;ch:1411,30;400,500;400,450;r300,600;r700,600' \
    || fails=$((fails+1))

# 複写・移動 の 倍率 と 回転角.  The 基準点 is wherever the cursor is sitting
# when 選択確定 is pressed, so the `m` step puts it somewhere known first --
# no click there, or the selection would change.  Both start from a blank
# sheet so nothing of Test5's own is in the box.
xform() {               # xform <name> <cmd> <倍率> <回転角>
    idle
    sh tools/refenv.sh >/dev/null
    cp decomp/res/new.jww tmp/blank.jww
    $PS -Open tmp/blank.jww -Cmd 32772 \
        -Clicks "300,300;500,400;cmd:$2;250,250;550,450;m400,350;btn:1120;ch:1411,$3;ch:1412,$4;700,500;saveas:decomp/res/$1.jww" \
        2>&1 | sed 's/^/        /'
}
# 反転: the 基準線 is drawn first, then the rectangle; 反転 (1067, which is
# 選択解除's id one stage on) takes the next click as that line.
flip() {                # flip <name> <cmd> <the line's two clicks> <pick>
    idle
    sh tools/refenv.sh >/dev/null
    cp decomp/res/new.jww tmp/blank.jww
    $PS -Open tmp/blank.jww -Cmd 0 \
        -Clicks "$3;cmd:32772;300,300;500,400;cmd:$2;250,250;550,450;m400,350;btn:1120;pb:1067;$4;saveas:decomp/res/$1.jww" \
        2>&1 | sed 's/^/        /'
}
# 基点変更 (1066, 全選択 の id が 1 段目の次では 基点変更 になります): 押した
# 次のクリックが基準点で、その次が複写先。カーソルの位置は使われません。
# 任意方向 (1151): the button cycles 任意方向 / X 方向 / Y 方向 / XY方向, and
# each squares the move off.  <presses> is the `pb:` steps that get there.
dir() {                 # dir <name> <presses> <where to put it>
    idle
    sh tools/refenv.sh >/dev/null
    cp decomp/res/new.jww tmp/blank.jww
    $PS -Open tmp/blank.jww -Cmd 32772         -Clicks "300,300;500,400;cmd:32804;250,250;550,450;m400,350;btn:1120$2;$3;saveas:decomp/res/$1.jww"         2>&1 | sed 's/^/        /'
}
basept() {
    idle
    sh tools/refenv.sh >/dev/null
    cp decomp/res/new.jww tmp/blank.jww
    $PS -Open tmp/blank.jww -Cmd 32772         -Clicks "300,300;500,400;cmd:32804;250,250;550,450;m400,350;btn:1120;pb:1066;350,320;700,500;saveas:decomp/res/basept.jww"         2>&1 | sed 's/^/        /'
}
try=1
while :; do
    echo "=== 複写・移動 の 倍率・回転角・反転・基点変更"
    xform copyxf 32804 2 30
    xform movexf 32918 0.5 -45
    flip flip 32804 "600,250;600,550" 600,400
    flip flipmv 32918 "600,250;700,550" 650,400
    basept
    dir dirx ";pb:1151" 700,500
    dir diry ";pb:1151;pb:1151" 700,500
    dir dirxy1 ";pb:1151;pb:1151;pb:1151" 700,500
    dir dirxy2 ";pb:1151;pb:1151;pb:1151" 500,650
    if [ ! -x tests/xform_test.exe ]; then
        echo "    (tests/xform_test.exe is not built -- not checked)"
        break
    fi
    if ./tests/xform_test.exe >tmp/refanswers.out 2>&1; then
        echo "    ok -- tests/xform_test.exe agrees"
        break
    fi
    try=$((try + 1))
    if [ "$try" -gt "$TRIES" ]; then
        echo "    tests/xform_test.exe still disagrees after $TRIES tries:"
        sed 's/^/        /' tmp/refanswers.out
        fails=$((fails + 1))
        break
    fi
    echo "    tests/xform_test.exe disagrees -- drawing it again ($try/$TRIES)"
done

# 属性変更 (0x80b8).  One click on one element -- no range, no button.  It
# gives Test5's first line the write layer and moves it to the end of the
# drawing; (394,534) is that line's middle on this view.
make zokuhen zokuhen 32952 '394,534' || fails=$((fails+1))

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
# 接線, 角度指定 (1691) and 円上点指定 (1692).  Both settle on a line touching
# the circle and then take a 始点 and a 終点 along it -- the status line asks
# for them in the 線 command's words, which `read:59393` hands over.  The two
# points are dropped onto the line, so these click well away from it.
sesang() {              # sesang <name> <angle> <pick on the circle>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32773         -Clicks "500,400;590,400;cmd:32870;btn:1691;ch:1412,$2;$3;300,200;800,150;saveas:decomp/res/sesang_$1.jww"         2>&1 | sed 's/^/        /'
}
sescpt() {              # sescpt <name> <pick on the circle>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32773         -Clicks "500,400;590,400;cmd:32870;btn:1692;500,310;$2;300,200;800,150;saveas:decomp/res/sescpt_$1.jww"         2>&1 | sed 's/^/        /'
}
try=1
while :; do
    echo "=== sessen (four tangents over one pair of circles, four from a point, and the other two modes)"
    sessen tt 300,240 700,310
    sessen bb 300,360 700,490
    sessen tb 300,240 700,490
    sessen bt 300,360 700,310
    tensen ur 564,336
    tensen lr 564,464
    tensen ul 436,336
    tensen ll 436,464
    sesang t 30 500,310
    sesang b 30 500,490
    sesang h 0 500,310
    sescpt a 564,336
    sescpt b 436,464
    sescpt c 436,336
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
# 接円 over other elements: a line and a circle, two circles, and three lines
# with the 半径 left empty.  The radius has to be big enough for a circle to
# reach both -- 10 units cannot touch a line and a circle 130 apart, and the
# original then simply refuses the second pick.
seklc() {               # seklc <name> <where the circle goes>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 0         -Clicks "300,250;900,250;cmd:32773;600,500;700,500;cmd:32872;ch:1411,20000;400,250;700,500;$2;saveas:decomp/res/seklc_$1.jww"         2>&1 | sed 's/^/        /'
}
sekcc() {               # sekcc <name> <where the circle goes>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32773         -Clicks "450,400;530,400;cmd:32773;800,400;860,400;cmd:32872;ch:1411,40000;450,320;800,340;$2;saveas:decomp/res/sekcc_$1.jww"         2>&1 | sed 's/^/        /'
}
# 多重円 (the box next to it, 1417): that many circles sharing the centre,
# the radius divided up.
sekmul() {              # sekmul <name> <the rest of the clicks>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 0 \
        -Clicks "$2;saveas:decomp/res/sekmul_$1.jww" \
        2>&1 | sed 's/^/        /'
}
sek3() {
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 0         -Clicks "300,250;900,250;300,250;600,600;900,250;600,600;cmd:32872;600,250;450,425;750,425;saveas:decomp/res/sek3.jww"         2>&1 | sed 's/^/        /'
}
try=1
while :; do
    echo "=== sekien (two lines, a line and a circle, two circles, and three lines)"
    sekien l 400,425
    sekien r 800,425
    sekien t 600,300
    sekien b 600,550
    seklc a 450,350
    seklc b 800,350
    sekcc n 600,150
    sekcc s 600,650
    sekcc e 950,400
    sekcc w 300,400
    sek3
    sekmul a "300,250;900,600;300,600;900,250;cmd:32872;ch:1417,3;ch:1411,2000;400,308;400,542;400,425"
    sekmul b "300,250;900,250;300,250;600,600;900,250;600,600;cmd:32872;ch:1417,3;600,250;450,425;750,425"
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
# サイン曲線 (1689) と ２次曲線 (1690): these take a base line and then
# points, not a string of points, so they have their own drive.  The clicks
# are written down again in tests/curve_test.c, which turns them into the
# drawing's units through the base line the original drew.
curveline() {           # curveline <name> <the clicks>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 0 \
        -Clicks "$2;saveas:decomp/res/curve_$1.jww" \
        2>&1 | sed 's/^/        /'
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
    curveline sin_a "300,400;900,400;cmd:32908;btn:1689;600,400;400,400;500,300;600,400;400,400;800,400"
    curveline sin_b "300,400;900,400;cmd:32908;btn:1689;600,400;400,380;500,300;600,400;450,420;850,400"
    curveline sin_c "300,250;900,550;cmd:32908;btn:1689;600,400;450,300;550,300;700,450;500,350;850,500"
    curveline q_a "300,400;900,400;cmd:32908;btn:1690;600,400;400,370;600,320;450,400;700,400"
    curveline q_b "300,400;900,400;cmd:32908;btn:1690;600,400;400,370;600,320;470,400;700,400"
    curveline q_c "300,250;900,550;cmd:32908;btn:1690;600,400;450,300;650,320;500,350;850,500"
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

# ハッチ (0x806a).  A circle and a rectangle, both settled with the right
# button -- picking a rectangle's sides one at a time with the left leaves
# 実行 greyed and draws nothing.  The same rectangle again in ２線 (1690) and
# ３線 (1691), which draw two and three lines per ピッチ, 線間隔 apart.
hatch_circle() {
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32773         -Clicks "550,450;700,450;cmd:32874;r700,450;btn:1148;saveas:decomp/res/hatch_circle.jww"         2>&1 | sed 's/^/        /'
}
hatch_rect() {
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32772         -Clicks "300,300;800,600;cmd:32874;r550,300;btn:1148;saveas:decomp/res/hatch_rect.jww"         2>&1 | sed 's/^/        /'
}
hatch_rect_mode() {
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32772         -Clicks "300,300;800,600;cmd:32874;btn:$1;r550,300;btn:1148;saveas:decomp/res/hatch_r$1.jww"         2>&1 | sed 's/^/        /'
}
# ┬┴┬ again with the numbers typed in, which is what pins down that the grid
# is anchored at zero and turns with the 角度.
hatch_rect_1692b() {
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32772         -Clicks "300,300;800,600;cmd:32874;btn:1692;set:1419,30;set:1411,20;set:1412,50;r550,300;btn:1148;saveas:decomp/res/hatch_r1692b.jww"         2>&1 | sed 's/^/        /'
}
# 実寸 (1323): with it on the ピッチ is in the drawing's own units, so 2000
# in a 1/200 drawing draws what 10 does with it off -- the same 49 lines.
hatch_rect_jisun() {
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32772 \
        -Clicks "300,300;800,600;cmd:32874;btn:1323;ch:1411,2000;r550,300;btn:1148;saveas:decomp/res/hatch_jisun.jww" \
        2>&1 | sed 's/^/        /'
}
# 基点変 (1147): the next click is the point the pattern counts from.  Both
# of these give it the rectangle's own first corner -- the same pixel that
# drew it -- so the test can point at it exactly.
hatch_rect_base() {
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32772 \
        -Clicks "300,300;800,600;cmd:32874;pb:1147;300,300;r550,300;btn:1148;saveas:decomp/res/hatch_base.jww" \
        2>&1 | sed 's/^/        /'
}
hatch_rect_base92() {
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd 32772 \
        -Clicks "300,300;800,600;cmd:32874;btn:1692;set:1419,30;set:1411,20;set:1412,50;pb:1147;300,300;r550,300;btn:1148;saveas:decomp/res/hatch_base92.jww" \
        2>&1 | sed 's/^/        /'
}
# 範囲選択 (1067): a boxful of closed figures at once.  This one starts from
# a blank sheet -- decomp/res/new.jww, what the original's 新規 makes -- so
# that nothing of Test5's own falls in the box.
hatch_sel() {
    idle
    sh tools/refenv.sh >/dev/null
    cp decomp/res/new.jww tmp/blank.jww
    $PS -Open tmp/blank.jww -Cmd 32772 \
        -Clicks "300,300;500,500;600,300;800,500;cmd:32874;pb:1067;250,250;850,550;btn:1120;btn:1148;saveas:decomp/res/hatch_sel.jww" \
        2>&1 | sed 's/^/        /'
}
try=1
while :; do
    echo "=== hatch (a circle and a rectangle, 1線 2線 3線 ┬┴┬ 実寸 基点変 範囲選択)"
    hatch_circle
    hatch_rect
    hatch_rect_mode 1690
    hatch_rect_mode 1691
    hatch_rect_mode 1692
    hatch_rect_1692b
    hatch_rect_jisun
    hatch_rect_base
    hatch_rect_base92
    hatch_sel
    if [ ! -x tests/hatch_test.exe ]; then
        echo "    (tests/hatch_test.exe is not built -- not checked)"
        break
    fi
    if ./tests/hatch_test.exe >tmp/refanswers.out 2>&1; then
        echo "    ok -- tests/hatch_test.exe agrees"
        break
    fi
    try=$((try + 1))
    if [ "$try" -gt "$TRIES" ]; then
        echo "    tests/hatch_test.exe still disagrees after $TRIES tries:"
        sed 's/^/        /' tmp/refanswers.out
        fails=$((fails + 1))
        break
    fi
    echo "    tests/hatch_test.exe disagrees -- drawing it again ($try/$TRIES)"
done

# DXF: what the original writes for a drawing, which tests/dxf_test.c holds
# the port's own DXF against.  The pens drawing is made by the port itself
# (tools/mkpens.c) and is also what tools/mkdxf.py reads; Ａマンション平面例 is
# copied under an ASCII name so the test can name it.
echo "=== dxf (the original's own DXF for three drawings)"
idle
sh tools/refenv.sh >/dev/null
$CC -O2 -Isrc -o tmp/mkpens.exe tools/mkpens.c src/jww.c src/jwwrite.c src/cp932.c 2>/dev/null \
    || gcc -O2 -Isrc -o tmp/mkpens.exe tools/mkpens.c src/jww.c src/jwwrite.c src/cp932.c
./tmp/mkpens.exe orig/Test5.jww tmp/pens.jww
$PS -Open tmp/pens.jww -NoSave -Clicks 'export:32961,decomp/res/pens.dxf' \
    2>&1 | sed 's/^/        /'
idle
sh tools/refenv.sh >/dev/null
cp orig/Test5.jww tmp/rect.jww
$PS -Open tmp/rect.jww -NoSave -Clicks 'export:32961,decomp/res/test5.dxf' \
    2>&1 | sed 's/^/        /'
idle
sh tools/refenv.sh >/dev/null
cp "orig/Ａマンション平面例.jww" decomp/res/mansion.jww
cp decomp/res/mansion.jww tmp/mansion.jww
$PS -Open tmp/mansion.jww -NoSave -Clicks 'export:32961,decomp/res/mansion.dxf' \
    2>&1 | sed 's/^/        /'
idle
sh tools/refenv.sh >/dev/null

# And the other way: the original opening a DXF.  tests/dxfread_test.c holds
# what src/dxfread.c makes of the same files against these.
#
# geom.dxf is a drawing of everything the reader understands -- lines, arcs
# both ways round, a whole circle, points and solids, and no text, because a
# text is the one thing the comparison cannot line up (the original leaves
# its own memo texts in whatever it saves).  geomext.dxf is the same file
# with its extents halved, which is what settles the scale: the original
# comes out at 1/100 rather than 1/200, so it says that the scale is read
# off $EXTMAX and not $LIMMAX.
echo "=== dxfin, geomin, geomextin (the original opening a DXF)"
idle
sh tools/refenv.sh >/dev/null
cp orig/Test5.jww tmp/rect.jww
$PS -Open tmp/rect.jww -NoSave \
    -Clicks 'import:32960,decomp/res/pens.dxf;saveas:decomp/res/dxfin.jww' \
    2>&1 | sed 's/^/        /'
idle
sh tools/refenv.sh >/dev/null
$CC -O2 -Isrc -o tmp/mkgeom.exe tools/mkgeom.c src/jww.c src/jwwrite.c src/cp932.c 2>/dev/null \
    || gcc -O2 -Isrc -o tmp/mkgeom.exe tools/mkgeom.c src/jww.c src/jwwrite.c src/cp932.c
./tmp/mkgeom.exe orig/Test5.jww tmp/geom.jww
$PS -Open tmp/geom.jww -NoSave -Clicks 'export:32961,decomp/res/geom.dxf' \
    2>&1 | sed 's/^/        /'
idle
sh tools/refenv.sh >/dev/null
python - <<'PY'
import io
b = io.open('decomp/res/geom.dxf', 'rb').read()
old = b'$EXTMAX\r\n 10\r\n168200\r\n 20\r\n118800\r\n'
new = b'$EXTMAX\r\n 10\r\n84100\r\n 20\r\n59400\r\n'
assert old in b, 'the extents are not where they were'
io.open('decomp/res/geomext.dxf', 'wb').write(b.replace(old, new, 1))
PY
cp orig/Test5.jww tmp/rect.jww
$PS -Open tmp/rect.jww -NoSave \
    -Clicks 'import:32960,decomp/res/geom.dxf;saveas:decomp/res/geomin.jww' \
    2>&1 | sed 's/^/        /'
idle
sh tools/refenv.sh >/dev/null
cp orig/Test5.jww tmp/rect.jww
$PS -Open tmp/rect.jww -NoSave \
    -Clicks 'import:32960,decomp/res/geomext.dxf;saveas:decomp/res/geomextin.jww' \
    2>&1 | sed 's/^/        /'
idle
sh tools/refenv.sh >/dev/null

# What the original makes of the 256 colour numbers a DXF can name: 255
# lines, one per number, in two goes because a drawing has room for only so
# many new colours.  tools/mkaci.py turns these into src/gen/aci.h.
echo "=== aci1, aci2 (what a DXF colour number means)"
for n in 1 2; do
    [ $n = 1 ] && lo=1 hi=128 || lo=129 hi=255
    python tools/mkaci.py --dxf decomp/res/aci$n.dxf $lo $hi
    cp orig/Test5.jww tmp/rect.jww
    idle
    sh tools/refenv.sh >/dev/null
    $PS -Open tmp/rect.jww -NoSave \
        -Clicks "import:32960,decomp/res/aci$n.dxf;saveas:decomp/res/aci$n.jww" \
        2>&1 | sed 's/^/        /'
done
idle
sh tools/refenv.sh >/dev/null

idle
sh tools/refenv.sh >/dev/null
echo
ls -l decomp/res/*.jww
[ "$fails" -eq 0 ] || { echo; echo "$fails of them never came out right"; exit 1; }
