#!/bin/sh
# run one step string on the original; result tmp/<name>.jww.   sh tools/orig1.sh <name> "<steps>"
cd "$(dirname "$0")/.."
k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 20 ] && taskkill //F //IM Jw_win.exe >/dev/null 2>&1; sleep 1; done
sh tools/refenv.sh >/dev/null 2>&1
cp decomp/res/new.jww tmp/rect.jww
rm -f tmp/$1.jww
timeout 120 powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1 -Open tmp/rect.jww -NoSave -Clicks "$2;saveas:$1;" 2>&1 | grep -E "throw|no |saved" 
