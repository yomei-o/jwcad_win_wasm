#!/bin/sh
# sh tools/escprobe3.sh "name|steps" ...   ; steps use  E=Esc  N=Enter  R=read  (plus jwdraw steps)
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
s=''
for sc in "$@"; do
  st=$(echo "${sc#*|}" | sed 's/\bE;/raw:f,256,27,0;raw:f,257,27,0;wait:250;/g; s/\bN;/raw:f,256,13,0;raw:f,257,13,0;wait:400;/g; s/\bR;/wait:250;read:59393;/g')
  s="$s;$st"
done
idle; sh tools/refenv.sh >/dev/null; cp orig/Test5.jww tmp/esc5.jww
$PS -Open tmp/esc5.jww -Cmd 0 -NoSave -Clicks "${s#;}" 2>&1 | tr -d '\r' | grep -E "read 59393|throw|no " | sed 's/read 59393: //'
idle
