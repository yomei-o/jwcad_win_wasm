#!/bin/sh
# Build everything and check the frame against the original, pixel for pixel.
#
#   sh tools/check.sh
#
# Needs src/gen/ built first (from your own copy of the installer):
#   python tools/mkres.py  orig/Jw_win.exe src/gen --maxh 21
#   python tools/btnmap.py docs/ref_start.png decomp/res/bitmap src/gen/layout.h
set -e
[ -f src/gen/jwres.c ]  || { echo "run tools/mkres.py first";  exit 1; }
[ -f src/gen/layout.h ] || { echo "run tools/btnmap.py first"; exit 1; }

sh tools/build_tests.sh
./tests/frame.exe tests/out/frame.png
echo
echo "=== the frame against the original"
python tools/cmp.py docs/ref_start.png tests/out/frame.png \
    -i docs/textareas.txt -d tests/out/diff.png
