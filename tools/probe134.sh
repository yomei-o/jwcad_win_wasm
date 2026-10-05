#!/bin/sh
# ツールバー (59392)・ステータスバー (59393)・ダイアログボックス (32953)
# —— 帯を消したとき、ビューはどれだけ広がるのか。
#
#   sh tools/probe134.sh
#
# `tools/probe127.sh` で「その帯が消える」ことは撮ってあります。入れるには
# **割り付けの数**が要るので、消したあとのビューの矩形を訊きます
# （`viewrect` を足しました）。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "=== view|throw|no " | sed 's/^/    /'
}

run none    "viewrect"
run toolbar "viewrect;raw:f,273,59392,0;wait:900;viewrect"
run status  "viewrect;raw:f,273,59393,0;wait:900;viewrect"
run dlgbox  "viewrect;raw:f,273,32953,0;wait:900;viewrect"
run allthree "raw:f,273,59392,0;wait:600;raw:f,273,59393,0;wait:600;raw:f,273,32953,0;wait:900;viewrect"
idle
