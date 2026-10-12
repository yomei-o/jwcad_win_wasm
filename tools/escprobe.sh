#!/bin/sh
# Esc / right-click in the middle of commands, on the original.  sh tools/escprobe.sh "<cmdid> <cmdid> ..."
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
E='raw:f,256,27,0;raw:f,257,27,0;wait:250;'
R='wait:250;read:59393;'
s=''
for c in $1; do
  s="$s;cmd:$c;${R}"
  s="$s;300,300;${R}"
  s="$s;${E}${R}"
  s="$s;300,300;${R}500,420;${R}"
  s="$s;${E}${R}"
  s="$s;${E}${R}"
  s="$s;300,300;${R}r400,400;${R}"
  s="$s;${E}${R}"
done
idle; sh tools/refenv.sh >/dev/null; cp orig/Test5.jww tmp/esc5.jww
$PS -Open tmp/esc5.jww -Cmd 0 -NoSave -Clicks "${s#;}" 2>&1 | tr -d '\r' | grep -E "===|read 59393|throw|no "
idle
