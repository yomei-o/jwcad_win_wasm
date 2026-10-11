#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S a19_ty A 19 '' '500,450;wait:900;type::XY;wait:500;700,300;wait:700;700,300;wait:700;'
$S a19_ee A 19 '' '500,450;wait:900;700,300;wait:700;700,300;wait:700;'
$S a19_e2 A 19 '' '500,450;wait:900;700,300;wait:700;type::7;wait:500;700,300;wait:700;'
echo done
