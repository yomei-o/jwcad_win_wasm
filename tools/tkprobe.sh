#!/bin/sh
# 多角形 任意 (1070) の残り三つの探り（2026-10-13）。答えは tmp/tk_<名前>.jww。
#   sh tools/tkprobe.sh [名前...]
# 円・連続線指示 (1083) で 弓形 (1327)・円外側 (1328) が円弧・円に効くか、
# 曲線属性化 (1325) が 任意 の多角形のソリッドに曲線属性を付けるか、凹んだ
# 多角形・自己交差のソリッドの出す順。各つまみの状態は bar で書き出す
# （checked・enabled を見るため）。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
CIR='cmd:32773;600,400;800,400;wait:600;'
ARC='cmd:32773;pb:1318;wait:300;600,400;800,400;600,200;wait:800;'
POL5='cmd:32883;300,300;400,250;500,300;550,400;450,450;450,450;wait:600;'
run() {
    [ -n "$ONLY" ] && ! echo " $ONLY " | grep -q " $1 " && return
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "$3cmd:32894;pb:1070;dlgoff;pb:1323;dlgoff;$2saveas:tk_$1;" 2>&1 \
        | tr -d '\r' | grep -E "throw|no |saved|^Button\|13(2[3-8])|^Button\|1083|read 59393" | sed 's/^/    /'
}
ONLY="$*"
S='pb:1083;wait:300;'
run a2 "pb:1327;wait:300;bar;${S}bar;800,400;wait:400;pb:1069;wait:400;" "$ARC"
run a3 "pb:1328;wait:300;bar;${S}bar;800,400;wait:400;pb:1069;wait:400;" "$ARC"
run k2 "pb:1327;wait:300;${S}bar;800,400;wait:400;pb:1069;wait:400;" "$CIR"
run k3 "pb:1328;wait:300;${S}bar;800,400;wait:400;pb:1069;wait:400;" "$CIR"
run q4 "pb:1325;wait:300;${S}bar;450,275;wait:400;pb:1069;wait:400;" "$POL5"
run s6c "pb:1325;wait:300;bar;400,350;600,450;500,420;300,300;350,200;450,250;pb:1069;wait:400;"
run s5c "400,350;600,450;500,300;300,300;350,200;pb:1069;wait:400;"
run x5 "300,300;600,300;350,450;450,200;550,450;pb:1069;wait:400;"
run c7 "300,300;500,250;600,400;450,350;400,500;250,450;350,380;pb:1069;wait:400;"
idle
