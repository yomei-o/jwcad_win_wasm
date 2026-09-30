#!/bin/sh
# The original's own PDF of a drawing -- the authority for what a page is.
#
#   sh tools/probe32.sh
#
# 印刷 (57607) puts up the Windows printer dialog (tools/probe29.sh) and the
# printer here is Microsoft Print To PDF; OK takes the original into its own
# print mode, whose bar has 印刷 (L) on 1065 (tools/probe30.sh); pressing
# that asks 「印刷結果を名前を付けて保存」 for a file name (probe31.sh).
# jwdraw.ps1's savedlg: step fills that in.
#
# Two drawings go through it: one line well inside a sheet, and the same
# line with the sheet changed to A-4, so the page size can be told apart
# from the drawn extent.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
P='raw:f,273,57607,0;wait:2000;pb:1;wait:1500;pb:1065;'
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    rm -f "$3"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 | sed 's/^/    /'
}

run a2 "cmd:32771;off:1333;300,300;700,500;${P}savedlg:tmp/orig_a2.pdf" tmp/orig_a2.pdf
# the same with the sheet set to A-4 (32824 is Ａ-４)
run a4 "cmd:32771;off:1333;300,300;700,500;raw:f,273,32824,0;${P}savedlg:tmp/orig_a4.pdf" tmp/orig_a4.pdf
idle
sh tools/refenv.sh >/dev/null
