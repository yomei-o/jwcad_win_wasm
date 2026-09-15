#!/bin/sh
# Build everything and check it against the original, pixel for pixel.
#
#   sh tools/check.sh
#
# Needs src/gen/ built first, from your own copy of the installer:
#   python tools/mkres.py  orig/Jw_win.exe src/gen --maxh 21
#   python tools/btnmap.py docs/ref_start.png decomp/res/bitmap src/gen/layout.h
set -e
cd "$(dirname "$0")/.."
[ -f src/gen/jwres.c ]  || { echo "run tools/mkres.py first";  exit 1; }
[ -f src/gen/layout.h ] || { echo "run tools/btnmap.py first"; exit 1; }

sh tools/build_tests.sh
sh tools/build_native.sh
sh tools/build_wasm.sh

echo
echo "=== the .jww reader: every drawing has to land on the end of its file"
./tests/jww_test.exe orig/*.jww | grep -c '^ok' | sed 's/^/    /'
./tests/jww_test.exe orig/*.jww | grep '^BAD' || true

./tests/frame.exe tests/out/frame.png >/dev/null
node tests/wasm_check.js tests/out/wasm.png >/dev/null
./tests/shot.exe tests/out/test1.png orig/Test1.jww >/dev/null

echo
echo "=== the frame against the original"
python tools/cmp.py docs/ref_start.png tests/out/frame.png \
    -i docs/textareas.txt -d tests/out/diff.png | head -2

echo
echo "=== native against WASM, pixel for pixel"
python tools/cmp.py tests/out/frame.png tests/out/wasm.png \
    -d tests/out/nw.diff.png | head -1

echo
echo "=== a drawing against the original (text is not drawn yet)"
python tools/cmp.py docs/ref_test1.png tests/out/test1.png \
    -d tests/out/test1.diff.png | head -1
