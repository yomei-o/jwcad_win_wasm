#!/bin/sh
# like img1.sh but the steps run BEFORE the image is inserted (no insert).  sh tools/img2.sh <name> "<steps>"
cd "$(dirname "$0")/.."
k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 20 ] && taskkill //F //IM Jw_win.exe >/dev/null 2>&1; sleep 1; done
sh tools/refenv.sh >/dev/null 2>&1
cp decomp/res/new.jww tmp/rect.jww
rm -f tmp/$1.jww
timeout 180 powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1 -Open tmp/rect.jww -NoSave -Clicks "cmd:33013;wait:800;$2;shot:tmp/$1.png;saveas:$1;" 2>&1 | grep -v "^===\|^Static\|^Toolbar\|^#32770" | grep -E "throw|no |saved|read|frame|[0-9]"
