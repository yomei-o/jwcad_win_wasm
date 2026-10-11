#!/bin/sh
cd "$(dirname "$0")/.."
export PATH="$PATH:/c/prog/tools/w64devkit/bin"
S="sh tools/skprobe.sh"
$S a19_x2 A 19 '' '500,450;wait:900;700,300;wait:600;700,300;wait:600;600,500;wait:900;700,300;wait:600;700,300;wait:600;'
$S a19_x3 A 19 '' '500,450;wait:900;700,300;wait:600;type::5;wait:400;700,300;wait:600;600,500;wait:900;700,300;wait:600;700,300;wait:600;'
echo done
