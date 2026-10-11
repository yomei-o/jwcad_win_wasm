#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S a04_s22 A 4 '' 'ch:1431,2 , 2;wait:400;450,400;wait:700;500,470;wait:900;'
$S a04_s1m A 4 '' 'ch:1431,1 , -1;wait:400;450,400;wait:700;500,470;wait:900;'
$S a04_sm1 A 4 '' 'ch:1431,-1 , 1;wait:400;450,400;wait:700;500,470;wait:900;'
$S a04_s32 A 4 '' 'ch:1431,3 , 2;wait:400;450,400;wait:700;500,470;wait:900;'
$S a10_s22 A 10 '' 'ch:1431,2 , 2;wait:400;500,450;wait:900;'
$S a10_s32 A 10 '' 'ch:1431,3 , 2;wait:400;500,450;wait:900;'
$S a02_s22 A 2 '' 'ch:1431,2 , 2;wait:400;450,400;wait:700;500,470;wait:900;'
$S a09_s32 A 9 '' 'ch:1431,3 , 2;wait:400;450,400;wait:700;500,470;wait:900;'
echo done
