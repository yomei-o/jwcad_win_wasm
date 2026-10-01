#!/bin/sh
# 仮表示が黒い線の上に乗ったら何色になるか。
#
#   sh tools/probe79.sh
#
# tools/probe78.sh の差分は三通りしか出ませんでした:
#
#   ffffff -> ff0000  1,896 画素（仮の矩形の周、ちょうど周長ぶん）
#   f0f0f0 -> 000000    806 ／ 000000 -> f0f0f0  398（状態行の文字）
#
# つまりあの走りでは、帯が**一画素も既存の線に重なっていません**でした。
# Test5 のその辺りは白かったのです。
#
# そこで狙って重ねます。撮った絵の行 647（＝ビューの y=562）に黒が
# 261 画素続いている所があり、ビューの x でいうと 586..847 です。
# 一隅を (600,400) に置いてカーソルを (800,562) へ持っていけば、
# 矩形の下辺がちょうどその上に乗ります。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle
sh tools/refenv.sh >/dev/null
cp orig/Test5.jww tmp/rect.jww
$PS -Open tmp/rect.jww -Cmd 32772 -NoSave \
  -Clicks 'off:1333;600,400;m800,562;wait:900;shot:tmp/pend_c.png' 2>&1 |
  grep -E "throw|no |wrote|frame" | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
