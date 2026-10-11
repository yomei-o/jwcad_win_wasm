#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S a07_l A 7 '' '450,400;wait:800;'
$S a08_lp A 8 '' '450,400;wait:600;500,470;wait:800;'
$S a09_lp A 9 '' '450,400;wait:600;500,470;wait:800;'
$S a11_lp A 11 '' '450,400;wait:600;500,470;wait:800;'
$S a12_lp A 12 '' '450,400;wait:600;500,470;wait:800;'
$S a13_lp A 13 '' '450,400;wait:600;500,470;wait:800;'
$S a14_lp A 14 '' '450,400;wait:600;500,470;wait:800;'
echo done
