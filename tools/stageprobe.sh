#!/bin/sh
# sh tools/stageprobe.sh name "steps"   -- three lines drawn on a blank sheet, then steps
#   E=Esc N=Enter R=read status; saveas:<name> as in jwdraw.ps1.  The result file is dumped.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
BASE='cmd:32771;off:1333;300,300;400,300;300,350;400,350;600,300;700,300;380,250;380,420;'
st=$(echo "$2" | sed 's/\bE;/raw:f,256,27,0;raw:f,257,27,0;wait:250;/g; s/\bN;/raw:f,256,13,0;raw:f,257,13,0;wait:400;/g; s/\bR;/wait:250;read:59393;/g')
idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/sp_$1.jww
echo "=== $1"
$PS -Open tmp/sp_$1.jww -NoSave -Clicks "${BASE}${st}saveas:sp_$1;" 2>&1 | tr -d '\r' | grep -E "read 59393|throw|no " | sed 's/read 59393: //'
idle
