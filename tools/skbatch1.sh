#!/bin/sh
# 線記号変形の第一弾: A の 1〜14 を自然な押し方で
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S a01_l A 1 '' '450,400;wait:800;'
$S a01_r A 1 '' '700,400;wait:800;'
$S a02_lp A 2 '' '450,400;wait:600;500,470;wait:800;'
$S a03_pp A 3 '' '500,450;wait:600;560,500;wait:800;'
$S a04_lp A 4 '' '450,400;wait:600;500,470;wait:800;'
$S a07_l A 7 '' '450,400;wait:800;'
$S a08_lp A 8 '' '450,400;wait:600;500,470;wait:800;'
$S a09_lp A 9 '' '450,400;wait:600;500,470;wait:800;'
$S a11_lp A 11 '' '450,400;wait:600;500,470;wait:800;'
$S a12_lp A 12 '' '450,400;wait:600;500,470;wait:800;'
$S a13_lp A 13 '' '450,400;wait:600;500,470;wait:800;'
$S a14_lp A 14 '' '450,400;wait:600;500,470;wait:800;'
echo done
