#!/bin/sh
# hkprobe.sh の UTF-8 版: 手順を tmp/hku_<名前>.txt（UTF-8）に書いて PowerShell に読ませる（日本語の字を打つため）
#   sh tools/hkprobeu.sh <名前> <コマンド> '<pre>' '<post>'   → decomp/res/hk_<名前>.jww
cd "$(dirname "$0")/.."
set +e
sh tools/refenv.sh >/dev/null
cp decomp/res/new.jww tmp/rect.jww
printf '%s' "off:1333;$3cmd:$2;wait:1500;$4saveas:hk_$1;" > tmp/hku_$1.txt
powershell -ExecutionPolicy Bypass -Command "\$c = [System.IO.File]::ReadAllText('tmp/hku_$1.txt', [System.Text.Encoding]::UTF8); & 'tools/jwdraw.ps1' -Open tmp/rect.jww -NoSave -Clicks \$c" 2>&1 | grep -E "${HKGREP:-throw|no |saved|read}" | sed 's/^/    /'
mv -f tmp/hk_$1.jww decomp/res/hk_$1.jww 2>/dev/null
