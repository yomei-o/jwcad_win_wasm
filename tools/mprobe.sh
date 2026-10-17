#!/bin/sh
# One run of the original on a blank drawing; steps as in tools/jwdraw.ps1.
#   JW_EXE=<copy of orig/Jw_win.exe> [STEP=ms] sh tools/mprobe.sh <name> '<steps>' [file.jww]
#   -> tmp/<name>.jww
# '<steps>' may be @file, to read the steps from a file.
cd "$(dirname "$0")/.."
mkdir -p tmp
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
idle; sh tools/refenv.sh >/dev/null
cp "${3:-decomp/res/new.jww}" tmp/rect.jww
steps=$2
case $steps in @*) steps=$(cat "${steps#@}") ;; esac
$PS -Open tmp/rect.jww -NoSave -StepMs ${STEP:-450} -Clicks "$steps;saveas:$1;" 2>&1 | grep -v "^$" | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
