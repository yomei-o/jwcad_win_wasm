#!/bin/sh
# 進む (57644) -- the other half of 元に戻る.
#
#   sh tools/probe25.sh
#
# tools/probe24.sh got one answer out of it: three lines, 元に戻る twice,
# 進む twice, and all three lines were there again.  Its second run saved
# nothing, so the question that matters is still open -- once something
# new is drawn, is what was undone still there to come back to?
#
# Every run here saves, and the runs are small so that the count alone
# says what happened.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
U='raw:f,273,57643,0'
R='raw:f,273,57644,0'
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

L='cmd:32771;off:1333;'
A='300,300;500,300;'
B='300,320;500,320;'
C='300,340;500,340;'
# two lines, one undo, one redo -- two back?
run one   "${L}${A}${B}${U};${R};saveas:p25_one"
# two lines, one undo, a third line, then 進む -- is the undone one gone?
run after "${L}${A}${B}${U};${C}${R};saveas:p25_after"
# two lines, two undos, three 進む -- does the extra one do anything?
run extra "${L}${A}${B}${U};${U};${R};${R};${R};saveas:p25_extra"
idle
