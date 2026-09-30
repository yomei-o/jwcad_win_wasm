#!/bin/sh
# What wakes 実行 (1120) on the 寸法 bar.
#
#   sh tools/probe45.sh
#
# tools/probe37.sh pressed every other button on the bar and 実行 stayed
# dead; tools/probe38.sh watched it through 一括処理 and it stayed dead
# there too -- but that run never got past the **second** prompt (its log
# shows 5392 three times over, so the clicks missed the lines), so the
# third prompt, 「一括処理する追加・除外線を…(R)確定」, was never
# actually reached with the button in view.
#
# tools/probe42.sh found clicks that do walk all three prompts.  This
# runs them again and reads the bar at every step.
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
idle
sh tools/refenv.sh >/dev/null
cp tmp/ikkatsu.jww tmp/rect.jww
B='read:59393;bar:1120;'
echo "=== walk"
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks \
 "cmd:32847;300,250;300,280;r391,343;r464,343;${B}btn:1072;${B}391,330;${B}717,330;${B}r900,330;${B}" \
 2>&1 | grep -E "read 59393|Button\|1120\||=== command|throw|no " | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
