#!/bin/sh
# 文字の 行間 (1418) と 連 (1068)。
#
#   sh tools/probe63.sh
#
# tools/probe60.sh の 連 の走りは「the 文字 box is not up」で止まりました。
# 連 を押すと文字の入力箱が引っ込むからで、jwdraw の `type:` はその箱を
# 探しにいきます。順を変えれば通るはずです —— **先に文字を打ってから**
# 連 を押す、あるいは 連 を押してから最初の一本を置いてみる。
#
# 行間 は 連 で続けて置いたときの行の間隔のはずなので、二本置いて
# 間を測れば分かります。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved|box" | sed 's/^/    /'
}
R='read:59393;'

# 連 pressed after the text is typed, and the status line read all the way
run ren_after "cmd:32806;type::AB;btn:1068;${R}400,400;${R}saveas:p63_ren_after"
# 連 pressed first, then a text placed, then another
run ren_first "cmd:32806;btn:1068;${R}type:AB;400,400;${R}saveas:p63_ren_first"
# and with 行間 set, to see what the gap becomes
run ren_gyou  "cmd:32806;chr:1418,20;btn:1068;${R}type:AB;400,400;${R}saveas:p63_ren_gyou"
# a plain two-text run, to compare against
run two       "cmd:32806;type:AB;400,400;type:CD;400,450;saveas:p63_two"
idle
sh tools/refenv.sh >/dev/null
