#!/bin/sh
# Build everything and check it against the original, pixel for pixel.
#
#   sh tools/check.sh
#
# Needs src/gen/ built first, from your own copy of the installer:
#   python tools/mkres.py  orig/Jw_win.exe src/gen --maxh 21
#   python tools/btnmap.py docs/ref_start.png decomp/res/bitmap src/gen/layout.h
#   python tools/mkfont.py font src/gen
set -e
cd "$(dirname "$0")/.."
[ -f src/gen/jwres.c ]  || { echo "run tools/mkres.py first";  exit 1; }
[ -f src/gen/layout.h ] || { echo "run tools/btnmap.py first"; exit 1; }
[ -f src/gen/jwfont.c ] || { echo "run tools/mkfont.py first"; exit 1; }

sh tools/build_tests.sh
sh tools/build_native.sh
sh tools/build_wasm.sh

echo
echo "=== the .jww reader: every drawing lands on the end of its file"
printf '    %s of %s\n' "$(./tests/jww_test.exe orig/*.jww | grep -c '^ok')" \
                        "$(ls orig/*.jww | wc -l)"
./tests/jww_test.exe orig/*.jww | grep '^BAD' || true

./tests/frame.exe tests/out/frame.png >/dev/null
node tests/wasm_check.js tests/out/wasm.png >/dev/null

echo
echo "=== the frame against the original"
python tools/cmp.py docs/ref_start.png tests/out/frame.png \
    -i docs/textareas.txt -d tests/out/diff.png | head -2 | sed 's/^/    /'

echo
echo "=== native against WASM, pixel for pixel"
python tools/cmp.py tests/out/frame.png tests/out/wasm.png \
    -d tests/out/nw.diff.png | head -1 | sed 's/^/    /'

echo
echo "=== drawings against the original"
echo "    the glyphs cannot match -- the original draws them with a Windows"
echo "    font -- so the text rectangles are scored separately"
for n in 1 7; do
    ./tests/shot.exe tests/out/test$n.png orig/Test$n.jww >/dev/null
    cat docs/textareas.txt tests/out/test$n.png.mask > tests/out/mask$n.txt
    printf '    Test%s  ' $n
    python tools/cmp.py docs/ref_test$n.png tests/out/test$n.png \
        -i tests/out/mask$n.txt -d tests/out/test$n.diff.png | sed -n '2p'
done
