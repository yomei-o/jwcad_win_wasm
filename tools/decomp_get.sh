#!/bin/sh
# Fetch the build machine's decompilation and sort it by class.
#
#   sh tools/decomp_get.sh
#
# Assumes tools/decomp_box.ps1 has already run there and left decomp.tgz.
set -e
KEY=${KEY:-/c/Users/yomei2/.claude/keys/ort_build_key}
BOX=${BOX:-yomei@192.168.6.14}

mkdir -p decomp/decomp
scp -i "$KEY" "$BOX:C:/prog/jwwin/decomp.tgz" decomp/decomp.tgz
tar -xzf decomp/decomp.tgz -C decomp/decomp
rm -f decomp/decomp.tgz

cat decomp/decomp/index_*.csv | grep -v '^address,' \
    | awk -F, 'BEGIN{ok=0;n=0} {n++; if ($5==1) ok++} END{
        printf "%d functions, %d decompiled (%.1f%%)\n", n, ok, 100*ok/n }'

python tools/byclass.py decomp/decomp decomp/rtti/vftables.csv decomp/byclass
