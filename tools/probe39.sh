#!/bin/sh
# What 寸法の一括処理 (1072) draws.
#
#   sh tools/probe39.sh
#
# tools/probe37.sh found what wakes it (a dimension already drawn) and
# probe38.sh read what it asks for:
#
#   ＜　一括処理する始線を指示してください(L)　＞     (R)処理終了
#   【　　一括処理する終線を指示してください(L)　　】     (R)処理終了
#
# so it works along a row of lines.  tools/mkikkatsu.c draws a wall with
# five verticals across it; this puts one dimension on by hand, presses
# 一括処理, picks the first vertical and the last, and saves what comes
# out.
cd "$(dirname "$0")/.."
set +e
CC=${CC:-gcc}
for dd in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$dd/gcc.exe" ] && { CCPATH="$dd"; break; }
done
SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
(PATH="$CCPATH:$PATH"; $CC -O2 -Isrc -o tmp/mkikkatsu.exe tools/mkikkatsu.c $SRC -lm) || exit 1
./tmp/mkikkatsu.exe || exit 1
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp tmp/ikkatsu.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

# The sheet is A-2 and the view puts paper 0,0 at view (554,343) with
# 0.612245 mm to the pixel, so the wall runs x 391..717 at y 343 and the
# five verticals stand at x 391, 464, 521, 619, 717.
R='read:59393;'
# 始線, 終線, and then (R) to settle it -- there is a third stage,
# 「一括処理する追加・除外線をﾏｳｽ(L)で指示してください。 (R)確定」, and
# nothing is drawn until that right click.
run all "cmd:32847;300,250;300,280;r391,343;r464,343;${R}btn:1072;${R}391,320;${R}717,320;${R}r900,320;${R}saveas:p39_all"
idle
sh tools/refenv.sh >/dev/null
