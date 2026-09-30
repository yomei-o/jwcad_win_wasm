#!/bin/sh
# 行間 (1418) の係数は「二倍」か「文字の高さ基準」か。
#
#   sh tools/probe69.sh
#
# tools/probe67.sh・probe68.sh で 行間 は **文読 (1069) の行送り**だと
# 分かりました。文字種10（高さ 10 mm）で:
#
#   空    行の間 10 mm
#   5     10
#   20    40
#   40    80
#
# ちょうど**箱の二倍**です。ただ高さも 10 なので「2×」と「高さ/5×」を
# 分けられません。空のときが高さそのもの (10) なのも気になります。
# そこで**文字種を変えて**もう一度: 文字種[ 4] に替えて、空のときと
# 20 のときの行送りを見ます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no control|saved" | sed 's/^/    /'
}

# 文字種[ 4] is 1692 in the 書込み文字種変更 dialog
run k4_0  "cmd:32806;dlgin:b1843,1692=!;import:b1069,tmp/twolines.txt;400,400;saveas:p69_k4_0"
run k4_20 "cmd:32806;dlgin:b1843,1692=!;chr:1418,20;import:b1069,tmp/twolines.txt;400,400;saveas:p69_k4_20"
idle
sh tools/refenv.sh >/dev/null
