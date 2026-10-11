#!/bin/sh
# Build tmp/replay.exe (tests/replay_test.c).  Same object cache as hktest.sh.
cd "$(dirname "$0")/.."
for d in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$d/gcc.exe" ] && { PATH="$d:$PATH"; export PATH; break; }
done
CFLAGS="-O1 -w -std=c99 -Isrc -Itests"
SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/tategu.c src/senkigou.c src/takaku.c src/hikage.c src/tenku.c src/tenku_sansha.c src/view.c src/draw.c src/text.c src/fontx.c src/plot.c src/png.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
mkdir -p tmp/ob
OBJ=""
for f in $SRC; do
    o="tmp/ob/$(basename "$f" .c).o"
    if [ ! -f "$o" ] || [ "$f" -nt "$o" ] || [ -n "$(find src tests -name '*.h' -newer "$o" | head -1)" ]; then
        gcc $CFLAGS -c -o "$o" "$f" || exit 1 &
    fi
    OBJ="$OBJ $o"
done
wait
gcc $CFLAGS -o tmp/replay.exe tests/replay_test.c $OBJ -lm || exit 1
echo built tmp/replay.exe
