#!/bin/sh
# 仮表示が既存の線と重なるとどうなるか —— ありなしの差分で直に測る。
#
#   sh tools/probe78.sh
#
# デコンパイルは R2_NOTXORPEN (10) だと言っています（tools/probe77.sh の
# 頭に書いた通り）。それなら黒い線の上では水色 00ffff になるはずですが、
# Test5 の上に仮の矩形を出して撮っても **00ffff は一画素も出ません**。
#
# 当て推量をやめて、**同じ図面を仮の図形ありとなしで撮り、差分の画素を
# 一つずつ「元の色 → 変わった色」の形で数えます**。それがラスタ
# オペレータそのものです。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp orig/Test5.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32772 -NoSave -Clicks "$2" 2>&1 |
        grep -E "throw|no |wrote|frame" | sed 's/^/    /'
}

# without: the same view, the command up, nothing placed yet
run without "off:1333;wait:900;shot:tmp/pend_a.png"
# with: one corner down and the cursor across the drawing
run with    "off:1333;250,250;m850,600;wait:900;shot:tmp/pend_b.png"
idle
sh tools/refenv.sh >/dev/null
