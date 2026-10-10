#!/bin/sh
# 多角形 (32894) の 中央 (1068) を k 回押したとき、クリックが多角形のどこに来るか。
# 辺寸法 (1692)、寸法 1000（縮尺 1/100 で十）、角数 5、クリック一つ。
#   sh tools/probe166.sh
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
P=''
for kk in 0 1 2 3 4 5 6 7 8 9 10; do
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    S='cmd:32894;pb:1692;dlgoff;'
    i=0; while [ $i -lt $kk ]; do S="${S}pb:1068;dlgoff;"; i=$((i+1)); done
    echo "=== k$kk"
    $PS -Open tmp/rect.jww -NoSave -Clicks "${S}500,400;saveas:p166_k$kk;" 2>&1 | grep -E "throw|no |saved" | sed 's/^/    /'
done
idle
