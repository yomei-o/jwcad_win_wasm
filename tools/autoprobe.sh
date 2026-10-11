#!/bin/sh
# AUTO モード (32915) の探り。壁（300,400）→（800,400）を引き、pre の線を引いて AUTO に入り、post を押す。
#   sh tools/autoprobe.sh <名前> '<pre>' '<post>'   → decomp/res/au_<名前>.jww
cd "$(dirname "$0")/.."
for d in orig/20??????-??????-???; do rmdir "$d" 2>/dev/null; done
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
sh tools/refenv.sh >/dev/null
cp decomp/res/new.jww tmp/rect.jww
$PS -Open tmp/rect.jww -NoSave -Clicks "off:1333;300,400;800,400;$2cmd:32915;wait:1500;$3saveas:au_$1;" 2>&1 | grep -E "throw|no |saved|read" | sed 's/^/    /'
mv -f tmp/au_$1.jww decomp/res/au_$1.jww 2>/dev/null
