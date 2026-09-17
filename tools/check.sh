#!/bin/sh
# Build everything and check it against the original, pixel for pixel.
#
#   sh tools/check.sh
#
# Needs src/gen/ built first, from your own copy of the installer:
#   python tools/mkres.py  orig/Jw_win.exe src/gen --maxh 21
#   python tools/btnmap.py docs/ref_start.png decomp/res/bitmap src/gen/layout.h
#   python tools/mkfont.py font src/gen
#   python tools/mknew.py  decomp/res/new.jww src/gen
set -e
cd "$(dirname "$0")/.."
[ -f src/gen/jwres.c ]  || { echo "run tools/mkres.py first";  exit 1; }
[ -f src/gen/layout.h ] || { echo "run tools/btnmap.py first"; exit 1; }
[ -f src/gen/jwfont.c ] || { echo "run tools/mkfont.py first"; exit 1; }
[ -f src/gen/newjww.c ] || { echo "run tools/mknew.py first";  exit 1; }

sh tools/build_tests.sh
sh tools/build_native.sh
sh tools/build_wasm.sh

echo
echo "=== the .jww reader: every drawing lands on the end of its file"
printf '    %s of %s\n' "$(./tests/jww_test.exe orig/*.jww | grep -c '^ok')" \
                        "$(ls orig/*.jww | wc -l)"
./tests/jww_test.exe orig/*.jww | grep '^BAD' || true

echo
echo "=== writing a drawing back out: the bytes have to be identical"
./tests/write_test.exe orig/*.jww | grep -c '^ok' | sed 's/^/    /'
./tests/write_test.exe orig/*.jww | grep '^BAD' || true

echo
echo "=== what is under the mouse"
for f in orig/*.jww; do
    ./tests/pick_test.exe "$f" | grep '^BAD' | sed "s|^|    $(basename "$f") |"
done
printf '    %s of %s drawings
'     "$(for f in orig/*.jww; do ./tests/pick_test.exe "$f" | tail -1; done | grep -c '^all ok')"     "$(ls orig/*.jww | wc -l)"

echo
echo "=== the (R) read point, against Jw_cad's own answers"
./tests/read_test.exe orig/Test5.jww | sed 's/^/    /'

echo
echo "=== pressing things"
./tests/click_test.exe orig/Test1.jww | sed 's/^/    /'

echo
echo "=== 線属性のダイアログ"
./tests/zoku_test.exe tests/out/zoku.png | sed 's/^/    /'
python tools/cmp.py docs/ref_zoku.png tests/out/zoku.png     -i docs/zoku_textareas.txt -d tests/out/zoku.diff.png     | head -2 | sed 's/^/    /'

echo
echo "=== 寸法 —— 原典が描いた寸法との突き合わせ"
./tests/sunpo_test.exe | sed 's/^/    /'

echo
echo "=== レイヤとレイヤグループの格子"
./tests/layer_test.exe orig/Test5.jww | sed 's/^/    /'

echo
echo "=== 範囲選択・複写・移動"
./tests/sel_test.exe orig/Test5.jww | sed 's/^/    /'

echo
echo "=== a drawing begun from nothing, drawn on and saved"
./tests/new_test.exe tests/out/new.jww | sed 's/^/    /'

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
    python tools/cmp.py docs/ref_test$n.png tests/out/test$n.png --near \
        -i tests/out/mask$n.txt -d tests/out/test$n.diff.png \
        | sed -n '2p;s/^of those/           --/p'
done
