#!/bin/sh
# 連続線 (32883) の 丸面辺寸法 (1411) と 実寸 (2096)。
#
#   sh tools/probe159.sh
#
# 移植の連続線はまっすぐな線をつなぐだけで、丸面辺寸法の箱を見ていま
# せん。実寸 はその箱に掛かるつまみ（原典の受け手 FUN_005b8240 は
# +0x528 と +0x6f0 を立てるだけ）なので、まず箱そのものを訊きます。
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }

# 直角に折れる三本。角が二つできます。
PTS='300,300;600,300;600,500;900,500;'

run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "cmd:32883;$2${PTS}r900,500;saveas:p159_$1;" 2>&1 |
        grep -E "throw|no |saved|read 59393" | sed 's/^/    /'
}

run plain  ''
run r10    'ch:1411,10;'
run r10j   'ch:1411,10;btn:2096;'
run r1000j 'ch:1411,1000;btn:2096;'
idle
echo
for f in plain r10 r10j r1000j; do
    echo "--- $f"
    python tools/whatdid.py decomp/res/new.jww "tmp/p159_$f.jww" 2>&1 | head -8
done
