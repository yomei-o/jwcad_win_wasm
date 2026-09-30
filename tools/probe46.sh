#!/bin/sh
# Three leftovers, asked of the original.
#
#   sh tools/probe46.sh
#
# 1. ２点間角度 (32934), the sign of it.  probe28 and probe43 both put a
#    negative angle to it -- -26.565 gave 116.565, -14.036 gave 104.036 --
#    and「90 - θ」and「|θ| + 90」fit both.  A positive angle tells them
#    apart: at θ = +14.036 the first says 75.964 and the second 104.036.
#
# 2. 実行 (1120) on the 寸法 bar.  probe45 found it alive at 一括処理's
#    **third** prompt and dead everywhere else -- and that after the (R)
#    there the walk starts over at the 始線 prompt rather than going back
#    to the plain dimension.  So the question is what the button does at
#    that prompt: the same as the (R), or something else.  The answer is
#    the drawing it leaves.  p46_jikko is the button, p46_migi the (R)
#    (that one is probe42's own answer again, to compare against).
#
# 3. 間隔取得 (32948).  probe44 showed it does **not** feed 長さ: the line
#    drawn after it came out exactly as the line drawn without it.  The
#    other reading of the name is 複線's 間隔, so this asks it straight --
#    take a distance, then put the 複線 bar up and read its box (1411).
cd "$(dirname "$0")/.."
set +e
CC=${CC:-gcc}
for dd in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$dd/gcc.exe" ] && { CCPATH="$dd"; break; }
done
SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
(PATH="$CCPATH:$PATH"; $CC -O2 -Isrc -DJW_IKKATSU_BAND -o tmp/mkikkatsu3.exe tools/mkikkatsu.c $SRC -lm) || exit 1
./tmp/mkikkatsu3.exe || exit 1
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp "$3" tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|Combo|Edit|throw|no |saved" | sed 's/^/    /'
}

N=decomp/res/new.jww
K=tmp/ikkatsu.jww

# 1. a positive angle this time: 400 by -100 pixels is +14.036 degrees
P='cmd:32771;off:1333;300,500;700,400;'
S='300,600;600,650;300,660;600,680;'
run k2p "${P}cmd:32934;r300,500;r700,400;${S}saveas:p46_k2p" $N

# 2. 実行 in place of the (R) that confirms
W='cmd:32847;300,250;300,280;r391,343;r464,343;btn:1072;391,330;717,330;'
run jikko "${W}btn:1120;read:59393;saveas:p46_jikko" $K
run migi  "${W}r900,330;saveas:p46_migi" $K

# 3. where the distance goes: every bar that has a number box on it
G='cmd:32948;500,400;r300,600;'
run kan_fuku "cmd:32771;off:1333;300,300;700,500;${G}cmd:32800;bar:32800" $N
run kan_sen  "cmd:32771;off:1333;300,300;700,500;${G}cmd:32771;bar:32771" $N
run fuku0    "cmd:32771;off:1333;300,300;700,500;cmd:32800;bar:32800" $N
run sen0     "cmd:32771;off:1333;300,300;700,500;cmd:32771;bar:32771" $N
idle
sh tools/refenv.sh >/dev/null
