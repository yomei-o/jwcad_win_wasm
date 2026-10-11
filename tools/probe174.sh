#!/bin/sh
# 多角形 任意 の 円・連続線指示 (1083): 円弧・連続線・各つまみ。 decomp/res/p174_<名前>.jww
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
CIR='cmd:32773;600,400;800,400;wait:600;'
ARC='cmd:32773;pb:1321;wait:300;600,400;800,400;650,200;550,200;wait:800;'
POL='cmd:32883;300,300;400,250;500,300;500,300;wait:600;'
run() {
    [ -n "$ONLY" ] && ! echo " $ONLY " | grep -q " $1 " && return
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "$3cmd:32894;pb:1070;dlgoff;pb:1323;dlgoff;$2saveas:p174_$1;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
    mv -f tmp/p174_$1.jww decomp/res/ 2>/dev/null
}
ONLY="$*"
S='pb:1083;'
run a1   "${S}800,400;pb:1069;" "$ARC"
run a2   "pb:1327;dlgoff;${S}800,400;pb:1069;" "$ARC"
run a3   "pb:1328;dlgoff;${S}800,400;pb:1069;" "$ARC"
run a4   "pb:1326;dlgoff;${S}800,400;pb:1069;" "$ARC"
run a5   "${S}r800,400;pb:1069;" "$ARC"
run p1   "${S}450,275;pb:1069;" "$POL"
run p2   "pb:1325;dlgoff;${S}450,275;pb:1069;" "$POL"
run p3   "pb:1326;dlgoff;${S}450,275;pb:1069;" "$POL"
run p4   "pb:1327;dlgoff;${S}450,275;pb:1069;" "$POL"
run p5   "pb:1328;dlgoff;${S}450,275;pb:1069;" "$POL"
run p6   "${S}r450,275;pb:1069;" "$POL"
run k2   "pb:1327;dlgoff;${S}800,400;pb:1069;" "$CIR"
run k3   "pb:1328;dlgoff;${S}800,400;pb:1069;" "$CIR"
run k5   "${S}r800,400;pb:1069;" "$CIR"
idle
