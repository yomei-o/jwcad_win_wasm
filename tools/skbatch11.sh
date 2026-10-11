#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S a19_x4 A 19 '' '500,450;wait:900;700,300;wait:600;700,300;wait:600;600,500;wait:900;700,300;wait:600;700,300;wait:600;400,500;wait:900;700,300;wait:600;700,300;wait:600;300,550;wait:900;700,300;wait:600;700,300;wait:600;'
$S a19_x5 A 19 '' '500,450;wait:900;700,300;wait:600;type::P1;wait:400;700,300;wait:600;600,500;wait:900;700,300;wait:600;700,300;wait:600;400,500;wait:900;700,300;wait:600;700,300;wait:600;'
$S a19_x6 A 19 '' '500,450;wait:900;700,300;wait:600;type::B9;wait:400;700,300;wait:600;600,500;wait:900;700,300;wait:600;type::Z;wait:400;700,300;wait:600;400,500;wait:900;700,300;wait:600;700,300;wait:600;'
echo done
