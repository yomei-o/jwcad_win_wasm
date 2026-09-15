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
./tests/frame.exe tests/out/frame.png
node tests/wasm_check.js tests/out/wasm.png

echo
echo "=== the frame against the original"
python tools/cmp.py docs/ref_start.png tests/out/frame.png \
    -i docs/textareas.txt -d tests/out/diff.png

echo
echo "=== native against WASM, pixel for pixel"
python tools/cmp.py tests/out/frame.png tests/out/wasm.png \
    -d tests/out/nw.diff.png
