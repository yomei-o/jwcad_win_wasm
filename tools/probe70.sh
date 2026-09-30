#!/bin/sh
# 文字基点設定 の ずれ —— 六つの箱が文字をどこへ動かすか。
#
#   sh tools/probe70.sh
#
# tools/probe67.sh が「no control 1323 in the dialog」で止まったのは
# **順**のせいでした。ずれ使用 (1323) を**先に**押せば届きます
# （tools/probe68.sh の zure1）。しかも六つの箱は ずれ使用 で初めて
# 有効になります —— 押す前は style 58030081（無効）、押すと 50030081。
#
# 箱の並びは、横ずれ 2004=左 2005=中 2006=右、縦ずれ 2009=上 2008=中
# 2007=下。九つの基点それぞれに一組ずつ、のはずです。
#
# 基点だけのときの答えは decomp/res/moji_k*.jww（左上は
# (-94.2857,-44.898)、右下は (-110.286,-34.898)）。同じ場所に ABC を
# 置いて、どれだけずれるかを見ます。
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

run lt "cmd:32806;dlgin:b1064,1323=!,2004=5,2009=3,1689=!;type:ABC;400,400;saveas:p70_lt"
run rb "cmd:32806;dlgin:b1064,1323=!,2006=7,2007=2,1697=!;type:ABC;400,400;saveas:p70_rb"
run off "cmd:32806;dlgin:b1064,2004=5,2009=3,1689=!;type:ABC;400,400;saveas:p70_off"
idle
sh tools/refenv.sh >/dev/null
