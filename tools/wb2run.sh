#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
SQ='400,300;600,300;wait:200;600,300;600,200;wait:200;600,200;400,200;wait:200;400,200;400,300;wait:200;700,400;300,400;wait:200;'
PRE='ch:1491,10;wait:300;405,300;wait:300;595,300;wait:300;595,200;wait:300;405,200;wait:300;pb:1068;wait:500;405,300;wait:700;pb:1069;wait:600;500,400;wait:700;'
S="sh tools/hkprobe.sh"
$S wb2 32943 "$SQ" "${PRE}pb:1066;wait:600;700,650;wait:500;300,650;wait:500;pb:1071;wait:600;pb:1065;wait:800;900,700;wait:1500;read:59393;"
echo done
