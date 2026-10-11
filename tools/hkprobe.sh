#!/bin/sh
# 日影図 (32943)・２．５D (32937)・天空図 (32971) の探り。
#   sh tools/hkprobe.sh <名前> <コマンド> '<pre: 先に押す点（線）>' '<post>'   → decomp/res/hk_<名前>.jww
cd "$(dirname "$0")/.."
for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
sh tools/refenv.sh >/dev/null
cp decomp/res/new.jww tmp/rect.jww
$PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;$3cmd:$2;wait:1500;$4saveas:hk_$1;" 2>&1 | grep -E "${HKGREP:-throw|no |saved|read}" | sed 's/^/    /'
mv -f tmp/hk_$1.jww decomp/res/hk_$1.jww 2>/dev/null
