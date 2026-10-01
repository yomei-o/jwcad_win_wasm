#!/bin/sh
# ハッチの 図形 (1693) —— 敷くのは「選択図形登録」したもの。
#
#   sh tools/probe85.sh
#
# tools/probe84.sh で前の読みが間違っていたことが分かりました。図形読込 で
# 読んだ図形は関係ありません（probe74 で線が増えて見えたのは、figin: の
# あとのクリックが図形を二つ置いていただけでした）。まっさらな紙に矩形
# だけ描いて 図形 モードで 実行 すると、**何も描かれません**。
#
# デコンパイルがそう言っています。実行 の枝（`FUN_00675b10`）は
# `+0x250` が 4 のとき、あるリストを歩いて「文字でも寸法でもないもの」を
# 探し、無ければ文字列 10036 を出して戻ります:
#
#     10036  範囲選択で選択図形登録を行ってください。
#
# ハッチのバーには 範囲選択 (1067) があり、範囲選択のバーには
# 選択図形登録 (1068) があります。つまり歩きはこうのはず:
#
#     ハッチ → 図形 → 範囲選択 → 範囲をとる → 選択図形登録
#            → 角度・縦ピッチ・横ピッチ → 境界 (R) → 実行
#
# 敷くものは矩形の外に描いた L 字（横線と縦線）。どこに何個置かれるかで
# ピッチの意味が分かります。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32772 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

# the boundary, and an L outside it to be the pattern
MK='300,300;800,600;cmd:32771;off:1333;880,180;940,180;880,180;880,210;'
SEL='cmd:32874;pb:1693;wait:800;pb:1067;wait:800;850,150;970,240;'
R='read:59393;'

# what it asks at each step
run ask "${MK}cmd:32874;${R}pb:1693;wait:800;${R}pb:1067;wait:800;${R}850,150;970,240;${R}pb:1068;wait:1000;${R}"
# and the three ways of finishing it
run a "${MK}${SEL}pb:1068;wait:1000;set:1419,0;set:1411,60;set:1412,80;r550,300;btn:1148;saveas:p85_a"
run b "${MK}${SEL}btn:1120;wait:600;pb:1068;wait:1000;set:1419,0;set:1411,60;set:1412,80;r550,300;btn:1148;saveas:p85_b"
run c "${MK}${SEL}pb:1068;wait:1000;880,180;wait:600;set:1419,0;set:1411,60;set:1412,80;r550,300;btn:1148;saveas:p85_c"
idle
sh tools/refenv.sh >/dev/null
