#!/bin/sh
# 多角形 任意 のソリッド図形: 凸の五角形・六角形・七角形（反時計回り・時計回り）。
#   sh tools/probe172.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
while read name pts; do
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $name"
    $PS -Open tmp/rect.jww -NoSave -Clicks "cmd:32894;pb:1070;dlgoff;pb:1323;dlgoff;${pts}pb:1069;saveas:p172_$name;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
done < tmp/polys.txt
idle
