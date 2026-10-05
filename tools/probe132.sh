#!/bin/sh
# 目盛基準点 (32912) —— 図面に残るので、絵でなくファイルで測ります。
#
#   sh tools/probe132.sh
#
# `src/draw.c` の目盛は図面の `mesh_ox`/`mesh_oy` から刻んでいて、それは
# .jww に書かれています（`tools/mesh.exe`）。目盛が見えていようがいまいが
# 原点は残るので、撮り比べるより確かです。
#
#   base    何もせず保存
#   kijun   32912 を出して (300,300) を指してから保存
#   kijun2  同じ命令で別の所 (700,500)
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

run base   "300,300;700,500;saveas:decomp/res/mesh_base.jww"
run kijun  "300,300;700,500;raw:f,273,32912,0;wait:700;${R}300,300;${R}saveas:decomp/res/mesh_a.jww"
run kijun2 "300,300;700,500;raw:f,273,32912,0;wait:700;700,500;saveas:decomp/res/mesh_b.jww"
idle
echo
./tools/mesh.exe decomp/res/mesh_base.jww decomp/res/mesh_a.jww decomp/res/mesh_b.jww
