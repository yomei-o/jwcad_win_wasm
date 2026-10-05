#!/bin/sh
# 距離指定点 の 連続 (1066) と、測定 の ○単独円指定 (1068)。
#
#   sh tools/probe135.sh
#
# 距離指定点 のバーに残っているのは 連続 だけです。押しておくと、点を
# 置いたあとも同じ向きへ続けて置くのでしょうか。測定 の ○単独円指定 は
# 名前のとおりなら円を一つ指すと周長なり面積なりを出すはずです。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 32771 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}
R='read:59393;'
L='off:1333;300,300;700,500;'
# a circle of radius 100 px about (500,400)
C='cmd:32773;500,400;600,400;'

run renzoku "${L}raw:f,273,32930,0;wait:800;pb:1066;wait:400;ch:1412,1000;${R}r300,300;${R}r700,500;${R}r700,500;${R}saveas:p135_ren"
run plain   "${L}raw:f,273,32930,0;wait:800;ch:1412,1000;r300,300;r700,500;r700,500;saveas:p135_plain"
run tandoku "${C}raw:f,273,32897,0;wait:800;pb:1068;wait:500;${R}600,400;${R}500,400;${R}"
idle
echo
echo "--- 連続 を入れたとき / 入れないとき"
python tools/whatdid.py tmp/p135_plain.jww tmp/p135_ren.jww 2>&1 | head -8
