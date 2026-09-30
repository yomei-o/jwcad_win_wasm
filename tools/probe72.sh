#!/bin/sh
# ハッチの 図形 (1693) —— ハッチの最後の一つ。
#
#   sh tools/probe72.sh
#
# 1線・２線・３線・┬┴┬ は入って通っています（tests/hatch_test.c）。
# 残るのが 図形 で、これは押すと Jw_cad 自前の「ファイル選択」が出る
# たぐいのはずです（jwdraw の figin: が相手にする窓のひとつに
# 「ハッチバーの 図形」が挙がっています）。
#
# 手順は tools/refanswers.sh の hatch_rect_base と同じ: Test5 に矩形を
# 一つ引き、ハッチに入り、基点変 (1147) で 300,300、境界を (R) で指して
# 実行 (1148)。ここではその前に 図形 (1693) で図形を読ませます。
# 図形は decomp/res/fig.jws。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp orig/Test5.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32772 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|=== " | sed 's/^/    /'
}
R='read:59393;'

# what the bar and the status line do when 図形 is pressed
run press "300,300;800,600;cmd:32874;${R}btn:1693;${R}bar"
# and the whole walk, with a figure read in
run draw  "300,300;800,600;cmd:32874;figin:b1693,decomp/res/fig.jws;${R}pb:1147;300,300;r550,300;btn:1148;saveas:p72_draw"
idle
sh tools/refenv.sh >/dev/null
