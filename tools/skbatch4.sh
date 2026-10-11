#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S e01_f E 1 '' 'shot:tmp/f0.png;450,400;wait:600;shot:tmp/f1.png;500,470;wait:600;shot:tmp/f2.png;'
$S g07_f G 7 '' '450,400;wait:600;shot:tmp/f3.png;500,470;wait:600;shot:tmp/f4.png;'
$S a11_f A 11 '800,400;800,200;' '700,400;wait:600;shot:tmp/f5.png;800,300;wait:600;shot:tmp/f6.png;'
$S a15_f A 15 '' '500,450;wait:900;shot:tmp/f7.png;'
echo done
