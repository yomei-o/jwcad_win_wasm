#!/bin/sh
# Build the native test programs.  Nothing here opens a window.
set -e
cd "$(dirname "$0")/.."
# w64devkit's gcc needs its own bin on PATH -- without it gcc cannot find as
# and dies with "cannot execute 'as'".  Set CC to use another compiler.
if [ -z "$CC" ]; then
    for d in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
        [ -x "$d/gcc.exe" ] && { PATH="$d:$PATH"; export PATH; break; }
    done
    CC=gcc
fi
CFLAGS="-O2 -Wall -Wextra -Wno-unused-parameter -std=c99 -Isrc -Itests"
COMMON_SRC="src/cp932.c src/pick.c src/fb.c src/ui.c src/cmd.c src/app.c src/jww.c src/jwwrite.c src/coord.c src/dxf.c src/dxfread.c src/sfcread.c src/sfcwrite.c src/jwcread.c src/jwcwrite.c src/houraku.c src/view.c src/draw.c src/text.c src/fontx.c src/gen/jwres.c src/gen/jwfont.c src/gen/newjww.c"
mkdir -p tests/out tests/out/obj

# The twenty-odd shared sources go into object files first.  Every test below
# links the whole of the port, so compiling them once instead of once per test
# takes the build from a quarter of an hour to a couple of minutes -- which
# matters because the build box is a good deal slower than this machine.  The
# objects are rebuilt every run, so there is nothing to go stale.
# ...and they go in parallel.  The build box has four cores and its gcc is an
# x86 one running under emulation, so this is the whole of the wait: serial
# it is about a quarter of an hour, four at a time about a third of that.
# JW_BUILD_JOBS sets how many; 1 puts it back the way it was.
JOBS="${JW_BUILD_JOBS:-4}"
rm -f tests/out/obj/*.fail
run() {           # run one command in the background, remembering a failure
    ( eval "$@" || touch "tests/out/obj/$$.fail" ) &
    running=$((running + 1))
    if [ "$running" -ge "$JOBS" ]; then
        wait
        running=0
    fi
}
reap() {
    wait
    running=0
    if ls tests/out/obj/*.fail >/dev/null 2>&1; then
        echo "build_tests: something above did not build" >&2
        exit 1
    fi
}
running=0

COMMON=""
for f in $COMMON_SRC; do
    o="tests/out/obj/$(basename "$f" .c).o"
    run "$CC $CFLAGS -c -o '$o' '$f'"
    COMMON="$COMMON $o"
done
reap
run "$CC $CFLAGS -o tests/frame.exe    tests/frame.c    tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/shot.exe     tests/shot.c     tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/jww_test.exe tests/jww_test.c src/jww.c src/cp932.c"
run "$CC $CFLAGS -o tests/jws_test.exe tests/jws_test.c src/jww.c src/jwwrite.c src/cp932.c -lm"
run "$CC $CFLAGS -o tests/write_test.exe tests/write_test.c src/jww.c src/jwwrite.c src/cp932.c"
run "$CC $CFLAGS -o tests/pick_test.exe tests/pick_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/read_test.exe tests/read_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/click_test.exe tests/click_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/new_test.exe   tests/new_test.c   tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/sel_test.exe   tests/sel_test.c   tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/layer_test.exe tests/layer_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/sunpo_test.exe tests/sunpo_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/zoku_test.exe  tests/zoku_test.c  tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/moji_test.exe    tests/moji_test.c    $COMMON tests/png.c -lm"
run "$CC $CFLAGS -o tests/zokusel_test.exe tests/zokusel_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/zokuhen2_test.exe tests/zokuhen2_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/blkmake_test.exe tests/blkmake_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/blkedit_test.exe tests/blkedit_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/kihon_test.exe tests/kihon_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/jikkaku_test.exe tests/jikkaku_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/sunpodlg_test.exe tests/sunpodlg_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/bairitsu_test.exe tests/bairitsu_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/figure_test.exe tests/figure_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/figreg_test.exe tests/figreg_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/zokattr_test.exe tests/zokattr_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/snap_test.exe tests/snap_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/coord_test.exe tests/coord_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/roundtrip_test.exe tests/roundtrip_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/session_test.exe tests/session_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/poly_test.exe  tests/poly_test.c  tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/mentori_test.exe tests/mentori_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/bunkatsu_test.exe tests/bunkatsu_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/nisen_test.exe tests/nisen_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/chushin_test.exe tests/chushin_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/zokuhen_test.exe tests/zokuhen_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/xform_test.exe   tests/xform_test.c   $COMMON -lm"
run "$CC $CFLAGS -o tests/dxf_test.exe     tests/dxf_test.c     $COMMON -lm"
run "$CC $CFLAGS -o tests/dxfread_test.exe tests/dxfread_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/sfcread_test.exe tests/sfcread_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/sfcwrite_test.exe tests/sfcwrite_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/jwcread_test.exe tests/jwcread_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/jwcwrite_test.exe tests/jwcwrite_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/block_test.exe   tests/block_test.c   $COMMON -lm"
run "$CC $CFLAGS -o tests/menu_test.exe tests/menu_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/sessen_test.exe tests/sessen_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/sekien_test.exe tests/sekien_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/curve_test.exe tests/curve_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/houraku_test.exe tests/houraku_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/seiri_test.exe tests/seiri_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/paper_test.exe tests/paper_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/hatch_test.exe tests/hatch_test.c tests/png.c $COMMON -lm"
run "$CC $CFLAGS -o tests/fuzz_test.exe  tests/fuzz_test.c  $COMMON -lm"
run "$CC $CFLAGS -o tests/cmdfuzz_test.exe tests/cmdfuzz_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/seq_test.exe tests/seq_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/bigcirc_test.exe tests/bigcirc_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/linewalk_test.exe tests/linewalk_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/clipwalk_test.exe tests/clipwalk_test.c $COMMON -lm"
run "$CC $CFLAGS -o tests/pickwalk_test.exe tests/pickwalk_test.c $COMMON -lm"
reap
echo "built tests/frame.exe tests/shot.exe tests/jww_test.exe tests/jws_test.exe tests/pick_test.exe tests/read_test.exe tests/click_test.exe tests/write_test.exe tests/new_test.exe tests/sel_test.exe tests/layer_test.exe tests/sunpo_test.exe tests/zoku_test.exe tests/moji_test.exe tests/zokusel_test.exe tests/zokuhen2_test.exe tests/blkmake_test.exe tests/blkedit_test.exe tests/kihon_test.exe tests/jikkaku_test.exe tests/sunpodlg_test.exe tests/bairitsu_test.exe tests/figure_test.exe tests/figreg_test.exe tests/zokattr_test.exe tests/snap_test.exe tests/coord_test.exe tests/roundtrip_test.exe tests/session_test.exe tests/poly_test.exe tests/mentori_test.exe tests/bunkatsu_test.exe tests/nisen_test.exe tests/chushin_test.exe tests/zokuhen_test.exe tests/xform_test.exe tests/dxf_test.exe tests/dxfread_test.exe tests/sfcread_test.exe tests/sfcwrite_test.exe tests/jwcread_test.exe tests/jwcwrite_test.exe tests/block_test.exe tests/menu_test.exe tests/sessen_test.exe tests/sekien_test.exe tests/curve_test.exe tests/hatch_test.exe tests/fuzz_test.exe tests/cmdfuzz_test.exe tests/seq_test.exe tests/bigcirc_test.exe tests/linewalk_test.exe tests/clipwalk_test.exe tests/pickwalk_test.exe tests/houraku_test.exe tests/seiri_test.exe tests/paper_test.exe"
