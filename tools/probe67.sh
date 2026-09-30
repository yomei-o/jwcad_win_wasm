#!/bin/sh
# 文字基点設定 の ずれ使用 (1323) と六つのずれの箱。
#
#   sh tools/probe67.sh
#
# ダイアログの控え（decomp/res/mojikijun.txt）を見ると、箱は
#
#   横ずれ  2004 (72,105)  2005 (125,105)  2006 (176,105)
#   縦ずれ  2007 (11,74)   2008 (11,51)    2009 (11,29)
#
# で、横の三つは 3×3 の三つの**列**（x=68/120/173）の真下に、縦の三つは
# 三つの**行**（y=75/53/30）の真横に並んでいます。つまり
# 2004=左 2005=中 2006=右、2009=上 2008=中 2007=下。九つの基点それぞれに
# ずれが一組ずつ、ということになります。そのつもりで訊きます。
#
# 基点だけのときの答えは decomp/res/moji_k*.jww（tools/probe62.sh）。
# 同じ場所に ABC を置いて、ずれを入れるとどれだけ動くかを見ます。
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

# 左上 (1689) with ずれ使用 on and 5 across / 3 up
run zure_lt "cmd:32806;dlgin:b1064,1689=!,1323=!,2004=5,2009=3;type:ABC;400,400;saveas:p67_zure_lt"
# ずれ使用 on but the boxes left empty, to see whether the tick alone does
# anything
run zure_on "cmd:32806;dlgin:b1064,1689=!,1323=!;type:ABC;400,400;saveas:p67_zure_on"
# the boxes filled but the tick left off
run zure_no "cmd:32806;dlgin:b1064,1689=!,2004=5,2009=3;type:ABC;400,400;saveas:p67_zure_no"
# and the right column / bottom row pair, to see that each cell has its own
run zure_rb "cmd:32806;dlgin:b1064,1697=!,1323=!,2006=7,2007=2;type:ABC;400,400;saveas:p67_zure_rb"

# 行間 (1418) はどこの間隔なのか。一度打った文字を二度クリックしても
# 二本目は置かれず（tools/probe66.sh）、連 は文字編集でした。残るのは
# **文読 (1069)** —— 文書を読んで置くつまみで、そこの行送りなら辻褄が
# 合います。二行の文書を読ませて、行間 を入れた場合と入れない場合で
# 比べます。
run yomi0 "cmd:32806;import:b1069,tmp/twolines.txt;400,400;saveas:p67_yomi0"
run yomi20 "cmd:32806;chr:1418,20;import:b1069,tmp/twolines.txt;400,400;saveas:p67_yomi20"
idle
sh tools/refenv.sh >/dev/null
