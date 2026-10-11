#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S a18_e3 A 18 '' '500,450;wait:900;700,300;wait:700;read:59393;700,300;wait:700;read:59393;700,300;wait:700;read:59393;'
$S a18_abc A 18 '' '500,450;wait:900;type::A;wait:400;700,300;wait:700;type::B;wait:400;700,300;wait:700;type::C;wait:400;700,300;wait:700;read:59393;'
$S a18_aee A 18 '' '500,450;wait:900;type::A;wait:400;700,300;wait:700;700,300;wait:700;700,300;wait:700;read:59393;'
$S a18_ea A 18 '' '500,450;wait:900;700,300;wait:700;type::B;wait:400;700,300;wait:700;read:59393;'
$S a15_u A 15 '' '500,450;wait:900;type::AB;wait:400;700,300;wait:700;1,1;'
echo done
