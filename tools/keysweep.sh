#!/bin/sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
c=''
for v in "$@"; do
    c="$c;cmd:32771;wait:120;raw:f,256,$v,0;wait:180;bar"
done
idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/blank.jww
$PS -Open tmp/blank.jww -Cmd 0 -NoSave -Clicks "${c#;}" 2>&1 | tr -d '\r' | grep -E "^=== bar|^Button\||^ComboBox\|"
idle
