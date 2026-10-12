#!/bin/sh
# 壁面 (1069)・確認 (1067)・等時間の範囲指定 (1072) の探り。
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
SQ='400,300;600,300;wait:200;600,300;600,500;wait:200;600,500;400,500;wait:200;400,500;400,300;wait:200;300,650;300,600;wait:200;'
PRE='ch:1491,10;wait:300;405,300;wait:300;595,300;wait:300;595,500;wait:300;405,500;wait:300;pb:1068;wait:500;300,600;wait:700;'
S="sh tools/hkprobe.sh"
$S w2 32943 "$SQ" "${PRE}pb:1069;wait:600;read:59393;500,500;wait:600;read:59393;500,560;wait:800;read:59393;pb:1064;wait:1000;pb:1065;wait:2500;read:59393;"
$S v1 32943 "$SQ" "${PRE}pb:1067;wait:1500;read:59393;"
$S i7 32943 "$SQ" "${PRE}pb:1065;wait:800;pb:1072;wait:600;read:59393;450,350;wait:600;read:59393;650,450;wait:800;read:59393;pb:1066;wait:4000;read:59393;"
echo done
