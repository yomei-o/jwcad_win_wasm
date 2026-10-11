#!/bin/sh
# 線記号変形の細かい探り: 何もないところ・元に戻す・グループ化・(R)
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S x_a01_empty A 1 '' '500,450;wait:900;'
$S x_a07_empty A 7 '' '500,450;wait:900;'
$S x_a05_undo A 5 '600,500;600,300;' '400,400;wait:700;600,350;wait:900;cmd:57643;wait:900;'
$S x_a04_undo A 4 '' '450,400;wait:700;500,470;wait:900;cmd:57643;wait:900;'
$S x_a15_undo A 15 '' '500,450;wait:900;type::XY;wait:400;700,300;wait:900;cmd:57643;wait:900;'
$S x_a15_undo1 A 15 '' '500,450;wait:900;cmd:57643;wait:900;'
$S x_a10_grp A 10 '' 'btn:2862;wait:400;500,450;wait:900;'
$S x_a02_rr A 2 '' '450,400;wait:700;r500,470;wait:900;'
$S x_a10_rr A 10 '' 'r500,450;wait:900;'
echo done
