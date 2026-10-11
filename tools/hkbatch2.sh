#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
SQ='400,300;600,300;wait:200;600,300;600,500;wait:200;600,500;400,500;wait:200;400,500;400,300;wait:200;300,650;300,600;wait:200;'
PRE='ch:1491,10;wait:300;405,300;wait:300;595,300;wait:300;595,500;wait:300;405,500;wait:300;pb:1068;wait:500;300,600;wait:700;pb:1064;wait:1200;'
S="sh tools/hkprobe.sh"
$S b3 32943 "$SQ" "${PRE}pb:1066;wait:3500;"
$S t1 32943 "$SQ" "${PRE}pb:1069;wait:800;700,650;wait:2500;"
$S t2 32943 "$SQ" "${PRE}pb:1070;wait:800;700,650;wait:2500;"
$S t3 32943 "$SQ" "${PRE}pb:1071;wait:800;700,650;wait:2500;read:59393;"
$S t4 32943 "$SQ" "${PRE}pb:1072;wait:800;700,650;wait:2500;read:59393;"
echo done
