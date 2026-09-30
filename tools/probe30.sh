#!/bin/sh
# The print bar, once the printer setup is past.
#
#   sh tools/probe30.sh
#
# tools/probe29.sh found that 印刷 (57607) puts up the Windows 「プリンター
# の設定」 dialog, and that the printer on this machine is Microsoft Print
# To PDF.  So the original can be made to write a PDF of its own, which is
# the authority for what the page is -- the homework says not to copy the
# DOS version's rule (the drawn extent plus 10mm), because this one has a
# real sheet.
#
# This step only gets as far as the bar: OK the setup and see what the
# command bar turns into and what the status line asks for.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 | sed 's/^/    /'
}

run bar 'cmd:32771;off:1333;300,300;700,500;raw:f,273,57607,0;wait:2000;pb:1;wait:2000;read:59393;bar;tops'
idle
