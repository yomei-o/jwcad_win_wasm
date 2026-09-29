#!/bin/sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 60 ] && break; sleep 1; done; }
one() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/blank.jww
    echo "=== $1"
    $PS -Open tmp/blank.jww -Cmd 0 -Clicks "$2;saveas:decomp/res/$1.jww" 2>&1 | grep -E "saved|throw|no control" | sed 's/^/    /'
}
# a slanted line, then a dimension across it -- plain, and with 0/90 pressed
one sun2_plain '300,600;700,500;cmd:32847;ch:1411,0;400,300;400,250;r300,600;r700,500'
one sun2_0_90  '300,600;700,500;cmd:32847;pb:1059;400,300;400,250;r300,600;r700,500'
one sun2_rui   '300,600;700,600;900,600;cmd:32847;ch:1411,0;pb:1070;400,300;400,250;r300,600;r700,600;r900,600'
one sun2_value '300,600;700,600;cmd:32847;ch:1411,0;pb:1069;400,300;400,250;r300,600;r700,600'
idle
