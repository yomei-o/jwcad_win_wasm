#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S a19_s A 19 '' '500,450;wait:900;700,300;wait:700;'
$S a20_s A 20 '' '500,450;wait:900;700,300;wait:700;700,300;wait:700;'
$S a21_s A 21 '' '500,450;wait:900;700,300;wait:700;700,300;wait:700;700,300;wait:700;'
$S a22_s A 22 '' '500,450;wait:900;700,300;wait:700;700,300;wait:700;700,300;wait:700;'
$S a23_m A 23 '' '500,450;wait:700;580,350;wait:900;'
$S a24_m A 24 '' '500,450;wait:700;580,350;wait:900;'
$S a25_m A 25 '' '500,450;wait:700;580,350;wait:900;'
$S a26_m A 26 '' '500,450;wait:700;580,350;wait:900;'
$S a27_m A 27 '' '500,450;wait:700;580,350;wait:900;'
$S a28_m A 28 '' '500,450;wait:700;580,350;wait:900;'
$S a29_m A 29 '' '500,450;wait:700;580,350;wait:900;'
$S a30_lp A 30 '' '450,400;wait:700;500,470;wait:900;'
echo done
