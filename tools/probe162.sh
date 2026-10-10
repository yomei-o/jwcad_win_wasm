#!/bin/sh
# 連続線 (32883) の 丸面辺寸法 (1411) の細かいところ —— 鋭角・短い辺・一直線。
#   sh tools/probe162.sh
# 直角は tools/probe159.sh（decomp/res/p159_*.jww）で訊いてあります。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {   # name, points (ending with the last click for r)
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "cmd:32883;ch:1411,10;$2r$3;saveas:p162_$1;" 2>&1 |
        grep -E "throw|no |saved" | sed 's/^/    /'
}
run acute  '300,300;600,300;350,450;700,500;'  '700,500'
run short  '300,300;600,300;600,310;900,500;'  '900,500'
run line   '300,300;600,300;900,300;1000,300;' '1000,300'
run five   '300,300;600,300;600,500;900,500;900,300;' '900,300'
idle
for f in acute short line five; do
    echo "--- $f"
    python tools/whatdid.py decomp/res/new.jww "tmp/p162_$f.jww" 2>&1 | head -12
done
