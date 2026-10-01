#!/bin/sh
# 文字バーの残り三つ —— 垂直 (1324)・縦字 (1325)・範囲選択 (2407)。
#
#   sh tools/probe95.sh
#
# RESUME の「駆動はできるが未解明」に挙がっているもののうち、文字の分です。
# 水平 (1323) は入っていますが、その隣の 垂直 と、行間の隣の 縦字、
# それに 範囲選択 は手つかずです。
#
#   plain  くらべる元（素の文字）
#   tate   垂直 (1324) を押してから打つ
#   tategaki 縦字 (1325) を押してから打つ
#   both   両方
#   hani   範囲選択 (2407)。押したあと何を訊かれ、範囲を取ると何が起きるか
#
# 文字は三つ描いておいて、範囲選択 がそのうちどれを取るかを見ます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|Button|Edit|Combo" | sed 's/^/    /'
}
R='read:59393;'

run plain    "cmd:32806;type:ABC;400,300;saveas:p95_plain"
run tate     "cmd:32806;btn:1324;type:ABC;400,300;saveas:p95_tate"
run tategaki "cmd:32806;btn:1325;type:ABC;400,300;saveas:p95_tategaki"
run both     "cmd:32806;btn:1324;btn:1325;type:ABC;400,300;saveas:p95_both"
# three texts, then the range
T='cmd:32806;type:ABC;400,300;type:DEF;400,400;type:GHI;400,500;'
run hani "${T}${R}pb:2407;wait:800;${R}bar:32806;350,250;${R}600,450;${R}tops;saveas:p95_hani"
idle
