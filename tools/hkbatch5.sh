#!/bin/sh
# 等時間 (1065) の探り。水準・季節・精度・9～15時。
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
SQ='400,300;600,300;wait:200;600,300;600,500;wait:200;600,500;400,500;wait:200;400,500;400,300;wait:200;300,650;300,600;wait:200;'
PRE='ch:1491,10;wait:300;405,300;wait:300;595,300;wait:300;595,500;wait:300;405,500;wait:300;pb:1068;wait:500;300,600;wait:700;'
S="sh tools/hkprobe.sh"
$S i3 32943 "$SQ" "${PRE}pb:1065;wait:800;pb:1068;wait:4000;"
$S i4 32943 "$SQ" "${PRE}cbsel:2436,2;wait:500;pb:1065;wait:800;pb:1067;wait:4000;"
$S i5 32943 "$SQ" "${PRE}pb:1065;wait:800;pb:1071;wait:800;pb:1066;wait:9000;read:59393;"
$S i6 32943 "$SQ" "${PRE}pb:1323;wait:500;pb:1065;wait:800;pb:1065;wait:4000;"
echo done
