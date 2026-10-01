#!/bin/sh
# 間隔取得 (32948) —— 読む点をちゃんと置いて、もう一度。
#
#   sh tools/probe90.sh
#
# `tools/probe89.sh` で二つ分かりました:
#
#   * 二つ目を**左**クリックにすれば値は取れます（状態行に出ます）。
#     前の六回（probe44・46・47・48）はどれも (R) で、読む点が無い所を
#     指していたので、**値そのものが取れていませんでした**
#   * **間隔取得 は終わりません**。二つ指しても状態行は 【間隔取得】の
#     ままで、続くクリックもそこへ吸い込まれます。だから probe89 の
#     len では二本目の線が引かれませんでした
#
# それと、複線 の問いかけには**もともと数が付いています**
# 「間隔を入力するか、複写する位置 (L)free (R)Readを指定してください
#  13,690.212」。これが 間隔取得 で変わるのかどうかが肝です。
#
# ここでは**読む点を本当に置いて** (R) で取り、
#
#   len   取ってから 線 に戻って引く（寸法と同じ働きか）
#   fuku  複線 に入ってから取って、そのまま写す（複線の間隔になるか）
#   fuku0 くらべる元
#
# を見ます。問いかけは一手ごとに読みます。
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

# a line to point at and a point to read
B='cmd:32771;off:1333;300,300;700,500;cmd:32785;300,600;'
K='cmd:32948;500,400;r300,600;'
S='300,650;600,680;'
R='read:59393;'

run plain "${B}cmd:32771;${S}saveas:p90_plain"
run len   "${B}${K}${R}cmd:32771;${R}${S}saveas:p90_len"
run fuku  "${B}cmd:32800;500,400;${R}${K}${R}500,200;${R}saveas:p90_fuku"
run fuku0 "${B}cmd:32800;500,400;${R}500,200;${R}saveas:p90_fuku0"
idle
