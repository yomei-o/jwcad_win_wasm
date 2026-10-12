#!/bin/sh
# enter, click A, Esc, read, click B, read -- is the first point still held after Esc?
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
E='raw:f,256,27,0;raw:f,257,27,0;wait:250;'
R='wait:250;read:59393;'
s=''
for c in $1; do
  s="$s;cmd:$c;${R}300,300;${R}${E}${R}500,420;${R}"
done
idle; sh tools/refenv.sh >/dev/null; cp orig/Test5.jww tmp/esc5.jww
$PS -Open tmp/esc5.jww -Cmd 0 -NoSave -Clicks "${s#;}" 2>&1 | tr -d '\r' | grep -E "read 59393|throw|no "
idle
