#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
SQ='400,300;600,300;wait:200;600,300;600,500;wait:200;600,500;400,500;wait:200;400,500;400,300;wait:200;300,650;300,600;wait:200;'
PRE='ch:1491,10;wait:300;405,300;wait:300;595,300;wait:300;595,500;wait:300;405,500;wait:300;pb:1068;wait:500;300,600;wait:700;'
S="sh tools/hkprobe.sh"
$S c8 32943 "$SQ" "${PRE}cbsel:2436,2;wait:500;pb:1064;wait:1200;pb:1066;wait:3000;"
$S c9 32943 "$SQ" "${PRE}pcbsel:2436,3;wait:1000;dlgnow:1001=12;wait:800;pb:1064;wait:1200;pb:1065;wait:2500;"
echo done
