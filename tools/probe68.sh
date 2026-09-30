#!/bin/sh
# 行間 (1418) の目盛と、文字基点ダイアログの ずれ の箱に届かない件。
#
#   sh tools/probe68.sh
#
# **行間 は 文読 (1069) の行送りでした**（tools/probe67.sh）。二行の文書を
# 読ませると、空のとき行の間は 10 mm（＝文字の高さ）、20 を入れると
# 40 mm。二点では式が決まらないので 5 と 40 も訊きます。
#
# ずれ のほうは `dlgin:b1064,1689=!,1323=!,…` が「no control 1323 in the
# dialog」で止まりました。1689 は見つかっているので窓は合っています。
# 一つずつ送って、どれが届いてどれが届かないのか確かめます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no control|saved|Button\|1323|Edit\|200" |
        sed 's/^/    /'
}

run g5  "cmd:32806;chr:1418,5;import:b1069,tmp/twolines.txt;400,400;saveas:p68_g5"
run g40 "cmd:32806;chr:1418,40;import:b1069,tmp/twolines.txt;400,400;saveas:p68_g40"
# what the dialog really hands over: press 基点 and dump it while it is up
run dump "cmd:32806;pb:1064;wait:1200;top"
run zure1 "cmd:32806;dlgin:b1064,1323=!;type:ABC;400,400;saveas:p68_zure1"
idle
sh tools/refenv.sh >/dev/null
