#!/bin/sh
# 条件（季節・緯度・9～15時）の探り。
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
SQ='400,300;600,300;wait:200;600,300;600,500;wait:200;600,500;400,500;wait:200;400,500;400,300;wait:200;300,650;300,600;wait:200;'
PRE='ch:1491,10;wait:300;405,300;wait:300;595,300;wait:300;595,500;wait:300;405,500;wait:300;pb:1068;wait:500;300,600;wait:700;'
S="sh tools/hkprobe.sh"
$S c1 32943 "$SQ" "${PRE}cbsel:2436,1;wait:500;pb:1064;wait:1200;pb:1065;wait:2500;"
$S c2 32943 "$SQ" "${PRE}cbsel:2436,2;wait:500;pb:1064;wait:1200;pb:1065;wait:2500;"
$S c3 32943 "$SQ" "${PRE}pb:1323;wait:500;pb:1064;wait:1200;pb:1065;wait:2500;"
$S c4 32943 "$SQ" "${PRE}ch:1493,40;wait:300;pb:1064;wait:1200;pb:1065;wait:2500;"
$S c5 32943 "$SQ" "${PRE}ch:1493,50;wait:300;pb:1064;wait:1200;pb:1065;wait:2500;"
$S c6 32943 "$SQ" "${PRE}ch:1493,60;wait:300;pb:1064;wait:1200;pb:1065;wait:2500;"
$S c7 32943 "$SQ" "${PRE}cbsel:2436,3;wait:800;read:59393;pb:1064;wait:1200;pb:1065;wait:2500;"
echo done
