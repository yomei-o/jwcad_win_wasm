#!/bin/sh
# steps before insert (PRE), insert (the bmp in $IMG), then steps (POST).  sh tools/img3.sh <name> "<pre>" "<post>"
cd "$(dirname "$0")/.."
k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 20 ] && taskkill //F //IM Jw_win.exe >/dev/null 2>&1; sleep 1; done
sh tools/refenv.sh >/dev/null 2>&1
cp ${BASE:-decomp/res/new.jww} tmp/rect.jww
rm -f tmp/$1.jww
timeout 240 powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1 -Open tmp/rect.jww -NoSave -Clicks "cmd:33013;wait:800;$2;pb:2557;wait:1500;opendlg:${IMG:-tmp/img/t1.bmp};wait:1500;$3;shot:tmp/$1.png;saveas:$1;" 2>&1 | grep -v "^===\|^Static\|^Toolbar\|^#32770" | grep -E "throw|no |saved|read|frame|[0-9]"
