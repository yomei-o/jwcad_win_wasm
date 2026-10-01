#!/bin/sh
# 文字の 連 (1068) の 移動 (LL) —— ダブルクリックが投げられるようになりました。
#
#   sh tools/probe110.sh
#
# RESUME の「次にやるとよいこと」に「ダブルクリックで、測り手が投げられ
# ません」と残っていた項目です。Windows のダブルクリックは
# down / up / **WM_LBUTTONDBLCLK** / up の四つで、どれも投げられるので、
# `tools/jwdraw.ps1` に `LL<x>,<y>` を足しました。本物のマウスは要りません。
#
# 連 の問いかけ（文字列 5473）はこうです:
#
#   文字を指示してください。  連結（L)　移動（LL)　　文字切断位置指示(R)
#
# 連結 と 切断 は入っていますが、移動 は訊いたことがありません。
#
#   move   文字を二つ置いて、連 → 一つを LL → どこかをクリック
#   move2  同じで、置き先を変える（本当に動くのか、位置はどこで決まるのか）
#   plain  くらべる元（連 を通さない）
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}
R='read:59393;'
T='cmd:32806;type:AB;400,300;type:CD;400,400;'

run plain "${T}saveas:p110_plain"
run move  "${T}btn:1068;wait:800;${R}LL405,300;wait:800;${R}700,500;${R}saveas:p110_move"
run move2 "${T}btn:1068;wait:800;LL405,300;wait:800;600,250;${R}saveas:p110_move2"
idle
