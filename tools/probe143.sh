#!/bin/sh
# 測定結果書込 (1071) をどう使うのか。
#
#   sh tools/probe143.sh
#
# 二度とも、押した途端に合計が 0 に戻り、書かれた文字も 0.000ｍ でした
# （投げても送っても同じ。`tools/probe129.sh`・`probe142.sh`）。順番が
# 逆なのかもしれません —— **先に押してから測る**と、一区切りごとに文字を
# 置かせてくれるのでしょうか。
#
# 書込設定 (1072) は窓を出しませんでした。何か別の効き方のはずです。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|^Button\|107" | sed 's/^/    /'
}
R='read:59393;'
S='raw:f,273,32897,0;wait:800;'

# press it first, then measure
run first "${S}btn:1071;${R}300,300;${R}700,300;${R}500,600;${R}saveas:p143_first"
# and what the bar looks like after pressing it
run cap   "${S}btn:1071;wait:400;bar"
# 書込設定 pressed, then the bar
run setup "${S}btn:1072;wait:600;${R}bar"
idle
echo
echo "--- 先に押してから測ったとき"
python tools/whatdid.py decomp/res/new.jww tmp/p143_first.jww 2>&1 | head -5
