#!/bin/sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
for v in "$@"; do
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/blank.jww
    echo "=== vk $v"
    $PS -Open tmp/blank.jww -Cmd 32771 -NoSave -Clicks "raw:f,256,$v,0;wait:300;tops" 2>&1 | tr -d '\r' | grep -E "^top " | grep -v "jw_win\]" | head -2
done
idle
