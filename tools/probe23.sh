#!/bin/sh
# One question left over from 長さ取得, and then the block answers again.
#
#   sh tools/probe23.sh
#
# 寸法 alone, with nothing in 傾き: the port has drawn that flat since the
# boxes were made to work, but tools/probe22.sh's nagabox run -- 寸法 50
# typed with a 線長 taken as well -- came out along the way it was
# clicked, not flat.  A grab gives a length and nothing else, so it looks
# as though the port is wrong, and that is worth asking on its own.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no " | sed 's/^/    /'
}

# 寸法 50 and nothing in 傾き, a line clicked up and to the right
run sunonly 'cmd:32771;off:1333;chr:1412,50;300,600;600,650;saveas:p23_sunonly'
# and the same with the click the other way, to see which end it keeps
run sunback 'cmd:32771;off:1333;chr:1412,50;600,650;300,600;saveas:p23_sunback'
idle
