#!/bin/sh
# 表示を切り替えるだけの命令 —— 絵で測ります。
#
#   sh tools/probe127.sh
#
# `tests/menusweep_test.exe --list` の dead のうち、窓の中身を出し入れ
# するだけに見えるもの。PrintWindow を前後で撮って差分を見ます。
#
#   59392 ツールバー      59393 ステータスバー   32953 ダイアログボックス
#   33037 Direct2D        33041 ANTIALIAS
#   32835 全体再表示      32836 全体倍率
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1 ($2)"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks \
        "300,300;700,500;wait:400;shot:tmp/p127_$1.png;raw:f,273,$2,0;wait:900;shot:tmp/p127_${1}b.png;tops" \
        2>&1 | grep -E "throw|no |wrote|top .* vis=1" | sed 's/^/    /'
    python tools/cmp.py "tmp/p127_$1.png" "tmp/p127_${1}b.png" 2>&1 | sed -n 1p | sed 's/^/    /'
}

run toolbar 59392
run status  59393
run dlgbox  32953
run d2d     33037
run aa      33041
run zenbu   32835
run zenbai  32836
idle
