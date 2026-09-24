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
#   python tools/mksunpo.py
#   python tools/mkzoku.py
set -e
cd "$(dirname "$0")/.."
# node comes with emsdk and is not on PATH there.
if ! command -v node >/dev/null 2>&1; then
    for d in "${EMSDK:-/c/prog/emsdk/emsdk}"/node/*/bin; do
        [ -x "$d/node.exe" ] && { PATH="$d:$PATH"; export PATH; break; }
    done
fi
[ -f src/gen/jwres.c ]  || { echo "run tools/mkres.py first";  exit 1; }
[ -f src/gen/layout.h ] || { echo "run tools/btnmap.py first"; exit 1; }
[ -f src/gen/jwfont.c ] || { echo "run tools/mkfont.py first"; exit 1; }
[ -f src/gen/newjww.c ] || { echo "run tools/mknew.py first";  exit 1; }
[ -f src/gen/sunpo.h ]  || { echo "run tools/mksunpo.py first"; exit 1; }
[ -f src/gen/zoku.h ]   || { echo "run tools/mkzoku.py first";  exit 1; }
[ -f src/gen/moji.h ]   || { echo "run tools/mkmoji.py first";  exit 1; }
[ -f src/gen/zokusel.h ] || { echo "run tools/mkzokusel.py first"; exit 1; }
[ -f src/gen/zokuhen.h ] || { echo "run tools/mkzokuhen.py first"; exit 1; }
[ -f src/gen/blkname.h ] || { echo "run tools/mkblkname.py first"; exit 1; }
[ -f src/gen/blkedit.h ] || { echo "run tools/mkblkedit.py first"; exit 1; }
[ -f src/gen/kihon.h ]   || { echo "run tools/mkkihon.py first";   exit 1; }
[ -f src/gen/jikkaku.h ] || { echo "run tools/mkjikkaku.py first"; exit 1; }
[ -f src/gen/sunpodlg.h ] || { echo "run tools/mksunpodlg.py first"; exit 1; }
[ -f src/gen/bairitsu.h ] || { echo "run tools/mkbairitsu.py first"; exit 1; }

sh tools/build_tests.sh
sh tools/build_native.sh
sh tools/build_wasm.sh

# tests/figreg_test.c is scored against a figure the original made out of
# this drawing, so it has to be the same one tools/refanswers.sh drove with.
if [ ! -f tmp/geom.jww ]; then
    mkdir -p tmp
    ${CC:-gcc} -O2 -Isrc -o tmp/mkgeom.exe tools/mkgeom.c src/jww.c         src/jwwrite.c src/cp932.c && ./tmp/mkgeom.exe orig/Test5.jww tmp/geom.jww
fi

echo
echo "=== the .jww reader: every drawing lands on the end of its file"
printf '    %s of %s\n' "$(./tests/jww_test.exe orig/*.jww | grep -c '^ok')" \
                        "$(ls orig/*.jww | wc -l)"
./tests/jww_test.exe orig/*.jww | grep '^BAD' || true

echo
echo "=== writing a drawing back out: the bytes have to be identical"
# decomp/res/sfcin.jww is the one with a 図形 in it (tools/refanswers.sh)
./tests/write_test.exe orig/*.jww decomp/res/sfcin.jww \
    | grep -c '^ok' | sed 's/^/    /'
./tests/write_test.exe orig/*.jww decomp/res/sfcin.jww | grep '^BAD' || true

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
echo "=== 書込み文字種変更 —— 原典が描いたダイアログとの突き合わせ"
./tests/moji_test.exe tests/out/moji.png | sed 's/^/    /'
python tools/cmp.py docs/ref_moji.png tests/out/moji.png \
    -i docs/moji_textareas.txt -d tests/out/moji.diff.png \
    | head -2 | sed 's/^/    /'

echo
echo "=== ブロック化 —— ダイアログと、原典が作った定義との突き合わせ"
./tests/blkmake_test.exe tests/out/blkname.png | sed 's/^/    /'
python tools/cmp.py docs/ref_blkname.png tests/out/blkname.png     -i docs/blkname_textareas.txt -d tests/out/blkname.diff.png     | head -2 | sed 's/^/    /'

echo
echo "=== 寸法設定 —— 原典が描いたダイアログとの突き合わせ"
./tests/sunpodlg_test.exe tests/out/sunpodlg.png | sed 's/^/    /'
python tools/cmp.py docs/ref_sunpodlg.png tests/out/sunpodlg.png     -i docs/sunpodlg_textareas.txt -d tests/out/sunpodlg.diff.png     | head -2 | sed 's/^/    /'

echo
echo "=== 図形登録 —— 原典が書いた .jws とのバイト突き合わせ"
./tests/figreg_test.exe | sed 's/^/    /'

echo
echo "=== 図形読込 —— 原典が置いた図形との突き合わせ"
./tests/figure_test.exe | sed 's/^/    /'

echo
echo "=== 画面倍率・文字表示 —— 原典が描いたダイアログとの突き合わせ"
./tests/bairitsu_test.exe tests/out/bairitsu.png | sed 's/^/    /'
python tools/cmp.py docs/ref_bairitsu.png tests/out/bairitsu.png     -i docs/bairitsu_textareas.txt -d tests/out/bairitsu.diff.png     | head -2 | sed 's/^/    /'

echo
echo "=== 軸角 —— ダイアログと、原典が引いた軸上の線との突き合わせ"
./tests/jikkaku_test.exe tests/out/jikkaku.png | sed 's/^/    /'
python tools/cmp.py docs/ref_jikkaku.png tests/out/jikkaku.png     -i docs/jikkaku_textareas.txt -d tests/out/jikkaku.diff.png     | head -2 | sed 's/^/    /'

echo
echo "=== 基本設定 —— 原典が描いた 8 枚のタブとの突き合わせ"
./tests/kihon_test.exe tests/out/kihon.png | sed 's/^/    /'
for t in 1 2 3 4 5 6 7 8; do
    m=docs/kihon_textareas.txt
    [ $t = 1 ] || m=docs/kihon_textareas$t.txt
    printf '    %s: ' "$t"
    python tools/cmp.py docs/ref_kihon$t.png tests/out/kihon$t.png         -i $m -d tests/out/kihon$t.diff.png | sed -n '2p'
done

echo
echo "=== ブロック編集 —— ダイアログと、原典が変えた定義との突き合わせ"
./tests/blkedit_test.exe tests/out/blkedit.png | sed 's/^/    /'
python tools/cmp.py docs/ref_blkedit.png tests/out/blkedit.png     -i docs/blkedit_textareas.txt -d tests/out/blkedit.diff.png     | head -2 | sed 's/^/    /'

echo
echo "=== 用紙サイズ —— 原典が変えた用紙との突き合わせ"
./tests/paper_test.exe | sed 's/^/    /'

echo
echo "=== データ整理 —— 原典の重複整理・連結整理との突き合わせ"
./tests/seiri_test.exe | sed 's/^/    /'

echo
echo "=== 属性変更（範囲から） —— ダイアログと、原典が変えたものとの突き合わせ"
./tests/zokuhen2_test.exe tests/out/zokuhen.png | sed 's/^/    /'
python tools/cmp.py docs/ref_zokuhen.png tests/out/zokuhen.png     -i docs/zokuhen_textareas.txt -d tests/out/zokuhen.diff.png     | head -2 | sed 's/^/    /'

echo
echo "=== 属性選択 —— ダイアログと、原典の選び方との突き合わせ"
./tests/zokusel_test.exe tests/out/zokusel.png | sed 's/^/    /'
python tools/cmp.py docs/ref_zokusel.png tests/out/zokusel.png     -i docs/zokusel_textareas.txt -d tests/out/zokusel.diff.png     | head -2 | sed 's/^/    /'

echo
echo "=== 接線 —— 原典が引いた 4 本の共通接線との突き合わせ"
./tests/sessen_test.exe | sed 's/^/    /'

echo
echo "=== 接円 —— 原典が描いた 4 つの接円との突き合わせ"
./tests/sekien_test.exe | sed 's/^/    /'

echo
echo "=== 曲線 —— 原典が描いたスプラインとの突き合わせ"
./tests/curve_test.exe | sed 's/^/    /'

echo
echo "=== ハッチ —— 原典が引いたハッチとの突き合わせ"
./tests/hatch_test.exe | sed 's/^/    /'

echo
echo "=== 包絡処理 —— 原典が包絡した 9 通りとの突き合わせ"
./tests/houraku_test.exe | sed 's/^/    /'

echo
echo "=== 中心線 —— 原典が引いた中心線との突き合わせ"
./tests/chushin_test.exe | sed 's/^/    /'

echo
echo "=== 属性変更 —— 原典が変えた要素との突き合わせ"
./tests/zokuhen_test.exe | sed 's/^/    /'

echo
echo "=== 複写・移動の倍率と回転角 —— 原典が置いたものとの突き合わせ"
./tests/xform_test.exe | sed 's/^/    /'

echo
echo "=== DXF 書き出し —— 原典が書いた DXF との突き合わせ"
./tests/dxf_test.exe | sed 's/^/    /'

echo
echo "=== DXF 読み込み —— 原典が同じ DXF を開いた結果との突き合わせ"
./tests/dxfread_test.exe | sed 's/^/    /'

echo
echo "=== SFC 読み込み —— 原典が同じ SFC を開いた結果との突き合わせ"
./tests/sfcread_test.exe | sed 's/^/    /'

echo
echo "=== SFC 書き出し —— 原典が書いた SFC との 1 バイトずつの突き合わせ"
./tests/sfcwrite_test.exe | sed 's/^/    /'

echo
echo "=== JWC 読み込み —— 原典が同じ JWC を開いた結果との突き合わせ"
./tests/jwcread_test.exe | sed 's/^/    /'

echo
echo "=== JWC 書き出し —— 原典が書いた JWC との 1 バイトずつの突き合わせ"
./tests/jwcwrite_test.exe | sed 's/^/    /'

echo
echo "=== 図形 —— 参照が定義をその場所・倍率・回転で描くか"
./tests/block_test.exe | sed 's/^/    /'

echo
echo "=== ２線 —— 原典が引いた 2 本との突き合わせ"
./tests/nisen_test.exe | sed 's/^/    /'

echo
echo "=== 分割 —— 原典が引いた等分線との突き合わせ"
./tests/bunkatsu_test.exe | sed 's/^/    /'

echo
echo "=== 面取 —— 原典が切った角との突き合わせ"
./tests/mentori_test.exe | sed 's/^/    /'

echo
echo "=== 多角形 —— 原典が描いた八角形との突き合わせ"
./tests/poly_test.exe | sed 's/^/    /'

echo
echo "=== 寸法 —— 原典が描いた寸法との突き合わせ"
./tests/sunpo_test.exe | sed 's/^/    /'

echo
echo "=== メニュー —— ブラウザ版が自分で開くポップアップ"
./tests/menu_test.exe tests/out/menu.png | sed 's/^/    /'

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
echo "=== ひと続きの作業 —— 新規から保存まで"
./tests/session_test.exe tests/out/session.jww | sed 's/^/    /'

echo
echo "=== the frame against the original"
python tools/cmp.py docs/ref_start.png tests/out/frame.png \
    -i docs/textareas.txt -d tests/out/diff.png | head -2 | sed 's/^/    /'

echo
echo "=== 別の大きさの枠 —— 右端と下端に付いてくるか"
python tools/mkmask.py docs/textareas.txt 1484 841 tests/out/mask_big.txt >/dev/null
./tests/frame.exe tests/out/frame_big.png 1484 841 >/dev/null
python tools/cmp.py docs/ref_start_big.png tests/out/frame_big.png     -i tests/out/mask_big.txt -d tests/out/big.diff.png     | head -2 | sed 's/^/    /'

echo
echo "=== キャプションとメニューバー（ブラウザ版が自分で描く分）"
node tests/wasm_check.js tests/out/chrome.png 1264 741 --chrome >/dev/null
python -c "from PIL import Image; Image.open('docs/ref_window.png').convert('RGB').crop((8,0,1272,51)).save('tests/out/chrome_ref.png'); Image.open('tests/out/chrome.png').convert('RGB').crop((0,0,1264,51)).save('tests/out/chrome_top.png')"
python tools/cmp.py tests/out/chrome_ref.png tests/out/chrome_top.png     -i docs/chrome_textareas.txt -d tests/out/chrome.diff.png     | head -2 | sed 's/^/    /'

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
