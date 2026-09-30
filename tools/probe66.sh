#!/bin/sh
# 文字の 行間 (1418) と 範囲選択 (2407)。
#
#   sh tools/probe66.sh
#
# 連 (1068) が「続けて置く」ではなく文字編集だと分かった（probe63〜65）
# ので、行間 が何の間隔なのかも分かっていません。バーの並びは
# 角度(1411) 範囲選択(2407) 基点(1064) **行間(1418)** 縦字(1325) 連(1068)
# 貼付(1065) 文読(1069) 文書(1070) 外部ｴﾃﾞｨﾀ(1067) で、行間 は 基点 と
# 縦字 の間にいます。
#
# いちばんありそうなのは「一度打った文字を続けて置くときの行送り」なので、
# **打ってから二度クリック**してみます。行間 を入れた場合と入れない場合。
# 文読 (1069) が複数行の文書を置くつまみなら、そちらの行送りかもしれず、
# それも押して何が出るか見ます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|^top |=== " | sed 's/^/    /'
}
R='read:59393;'

run rep0  "cmd:32806;type:AB;400,400;400,450;saveas:p66_rep0"
run gyou  "cmd:32806;chr:1418,20;type:AB;400,400;400,450;saveas:p66_gyou"
run hani  "cmd:32806;${R}btn:2407;${R}bar"
run yomi  "cmd:32806;pb:1069;wait:1200;tops"
idle
sh tools/refenv.sh >/dev/null
