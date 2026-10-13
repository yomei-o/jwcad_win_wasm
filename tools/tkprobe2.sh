#!/bin/sh
# tkprobe.sh の続き: 弓形 (1327)・円外側 (1328) は 円・連続線指示 (1083) を
# 押したあとでないと enabled にならない（tkprobe.sh の bar で分かった）ので、
# 1083 → つまみ → 図形 の順で。答えは tmp/tk_<名前>.jww。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
CIR='cmd:32773;600,400;800,400;wait:600;'
ARC='cmd:32773;pb:1318;wait:300;600,400;800,400;600,200;wait:800;'
ARC2='cmd:32773;pb:1318;wait:300;600,400;800,400;400,400;wait:800;'
ARC3='cmd:32773;pb:1318;wait:300;600,400;800,400;500,573;wait:800;'
POL5='cmd:32883;300,300;400,250;500,300;550,400;450,450;450,450;wait:600;'
run() {
    [ -n "$ONLY" ] && ! echo " $ONLY " | grep -q " $1 " && return
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "$3cmd:32894;pb:1070;dlgoff;pb:1323;dlgoff;$2saveas:tk_$1;" 2>&1 \
        | tr -d '\r' | grep -E "throw|no |saved|^Button\|13(2[5-8])|read 59393" | sed 's/^/    /'
}
ONLY="$*"
S='pb:1083;wait:300;'
run b2 "${S}pb:1327;wait:300;bar;800,400;wait:400;pb:1069;wait:400;" "$ARC"
run b3 "${S}pb:1328;wait:300;bar;800,400;wait:400;pb:1069;wait:400;" "$ARC"
run b4 "${S}pb:1327;wait:300;800,400;wait:400;pb:1069;wait:400;" "$ARC2"
run b5 "${S}pb:1328;wait:300;800,400;wait:400;pb:1069;wait:400;" "$ARC2"
run b6 "${S}pb:1328;wait:300;800,400;wait:400;pb:1069;wait:400;" "$ARC3"
run b7 "${S}pb:1327;wait:300;800,400;wait:400;pb:1069;wait:400;" "$ARC3"
run j2 "${S}pb:1327;wait:300;800,400;wait:400;pb:1069;wait:400;" "$CIR"
run j3 "${S}pb:1328;wait:300;800,400;wait:400;pb:1069;wait:400;" "$CIR"
run j5 "${S}pb:1325;wait:300;bar;450,275;wait:400;pb:1069;wait:400;" "$POL5"
run j6 "${S}pb:1325;wait:300;800,400;wait:400;pb:1069;wait:400;" "$CIR"

# 曲線属性化 (1325) を 円外側 の四枚に: (R) と (L)、線形 (1326) の連続線
run j7 "${S}pb:1328;wait:300;pb:1325;wait:300;r800,400;wait:400;pb:1069;wait:400;" "$CIR"
run j8 "${S}pb:1328;wait:300;pb:1325;wait:300;800,400;wait:400;pb:1069;wait:400;" "$CIR"
run j9 "${S}pb:1326;wait:300;pb:1325;wait:300;450,275;wait:400;pb:1069;wait:400;" "$POL5"
idle
