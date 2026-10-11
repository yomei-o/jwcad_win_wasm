#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S a15_def A 15 '' '500,450;wait:900;700,300;wait:900;'
$S a16_def A 16 '' '500,450;wait:900;700,300;wait:900;'
$S a16_ty A 16 '' '500,450;wait:900;type::AB;wait:600;700,300;wait:900;'
$S a16_nl A 16 '' '500,450;wait:900;set:1422,;wait:600;700,300;wait:900;'
$S a16_rr A 16 '' '500,450;wait:900;r700,300;wait:900;read:59393;'
echo done
