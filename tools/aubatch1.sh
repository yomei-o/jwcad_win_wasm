#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
until [ -f tmp/skafter2.done ]; do sleep 10; done
S="sh tools/autoprobe.sh"
V='500,200;500,600;'
$S b8 '' '500,400;wait:600;450,400;wait:600;600,400;wait:800;'
$S b8up '' '500,400;wait:600;550,300;wait:600;450,400;wait:800;'
$S b9 '' '500,400;wait:600;LL450,400;wait:800;'
$S b10 '' '500,400;wait:600;850,400;wait:600;900,400;wait:800;'
$S b10m '' '500,400;wait:600;200,400;wait:600;250,400;wait:800;'
$S b10off '' '500,400;wait:600;850,300;wait:600;900,300;wait:800;'
$S b13 "$V" '350,400;wait:600;500,250;wait:800;'
$S b13r "$V" '650,400;wait:600;500,250;wait:800;'
$S b13nc '900,200;900,600;' '350,400;wait:600;900,250;wait:800;'
$S b15 '' '500,400;wait:600;r650,400;wait:800;'
$S b16 "$V" '350,400;wait:600;r500,250;wait:800;'
$S b17 '' '500,400;wait:600;r700,550;wait:800;'
$S b18 '650,200;650,600;750,200;750,600;' '500,400;wait:600;450,400;wait:600;r700,400;wait:800;'
$S b19 '' '500,400;wait:600;450,400;wait:600;r800,400;wait:800;'
$S r5 '' 'r300,400;wait:600;600,300;wait:800;'
$S p1 '' '400,300;wait:600;600,300;wait:800;'
$S p3 '' '400,300;wait:600;400,300;wait:600;500,300;wait:800;'
echo finished > tmp/aubatch1.done
