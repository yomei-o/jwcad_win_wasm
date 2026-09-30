#!/bin/sh
# What 印刷 (57607) puts up, and what it wants.
#
#   sh tools/probe29.sh
#
# The homework is to print to PDF and PNG the way jwcad_dos_wasm does, but
# **not** with the DOS version's page rule (the drawn extent plus 10mm):
# this one has a real sheet.  So the first question is what the original
# does -- what the dialog is, and whether the page is the sheet.
#
# Nothing is pressed here that could start a print: the dialog is only
# looked at and then cancelled.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 | sed 's/^/    /'
}

# the print command, posted so a modal does not hold the script
run insatsu 'cmd:32771;off:1333;300,300;700,500;raw:f,273,57607,0;wait:2000;tops;read:59393'
# and the printer setup one
run setup   'raw:f,273,57606,0;wait:2000;tops'
idle
