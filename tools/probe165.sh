#!/bin/sh
# 多角形 (32894) の四つの指定（2辺 1689・中心→頂点 1690・中心→辺 1691・辺寸法 1692）と
# 中央 (1068) を、箱が埋まっている／空の両方で。クリックは三つ。
#   sh tools/probe165.sh [mode...]
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {   # name, script
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "cmd:32894;$2400,350;600,450;500,420;saveas:p165_$1;" 2>&1 |
        grep -E "throw|no |saved" | sed 's/^/    /'
}
for m in 1689 1690 1691 1692; do
    run ${m}_full  "pb:${m};dlgoff;"
    run ${m}_empty "pb:${m};dlgoff;ch:1411,;"
    run ${m}_c     "pb:${m};dlgoff;pb:1068;dlgoff;"
    run ${m}_c_empty "pb:${m};dlgoff;pb:1068;dlgoff;ch:1411,;"
done
idle
for m in 1689 1690 1691 1692; do for v in full empty c c_empty; do
    echo "--- ${m}_$v"
    python tools/whatdid.py decomp/res/new.jww "tmp/p165_${m}_$v.jww" 2>&1 | cut -c1-150 | head -20
done; done
