#!/bin/sh
# 文字の 連 (1068) —— 連結・移動・切断。
#
#   sh tools/probe64.sh
#
# tools/probe63.sh で正体が分かりました。連 は「続けて置く」つまみでは
# なく、**文字そのものをいじるモード**です。状態行:
#
#   文字を指示してください。　連結（L)　　移動（LL)　　　　文字切断位置指示(R)
#
# だから押すと入力箱が引っ込みます。ここでは図面に出るところを訊きます:
#
#   join  同じ行に AB と CD を置いてから 連、二つを (L) で指す
#   cut   ABCD を一つ置いてから 連、真ん中あたりを (R) で指す
#
# 画面は 49 画素 = 30 mm、紙の原点がビューの (554, 343)。文字は 文字種10
# （幅 10・高さ 10・字間 1）なので、AB の走りは 10.5 mm = 17 画素です。
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
R='read:59393;'

# AB at 400,400 runs to 417; CD at 440,400 runs to 457.  A click lands on a
# text when it is inside its run, so 405 and 445 are safely on them.
run join "cmd:32806;type:AB;400,400;type:CD;440,400;btn:1068;${R}405,395;${R}445,395;${R}saveas:p64_join"
run cut  "cmd:32806;type:ABCD;400,400;btn:1068;${R}r417,395;${R}saveas:p64_cut"
# the same two texts with nothing done to them, to compare against
run none "cmd:32806;type:AB;400,400;type:CD;440,400;saveas:p64_none"
idle
sh tools/refenv.sh >/dev/null
