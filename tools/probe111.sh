#!/bin/sh
# 連 の 移動 (LL) —— 基点は効くのか。
#
#   sh tools/probe111.sh
#
# `tools/probe110.sh` で、LL で文字を拾うと問いかけが
# 「移動先の点を指示して下さい (L)free (R)Read」になり、次のクリックに
# **文字の始点**が載ることが分かりました（二通りとも、クリックした紙座標
# そのもの）。移った文字は一覧の**末尾**に行きます。
#
# ただし基点は 左下（出たときのまま）でした。基点を 中中 にしても始点が
# 載るのか、それとも真ん中が載るのかを訊きます。
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
T='cmd:32806;type:AB;400,300;type:CD;400,400;'

run naka "${T}dlgin:b1064,1693=!;wait:600;btn:1068;wait:800;LL405,300;wait:800;700,500;saveas:p111_naka"
idle
