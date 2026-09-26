#!/bin/sh
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
mkdir -p tmp
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
python - <<'PY'
import io, math
TWO = 2.0 * math.pi
def ray(rp, a):
    return int(rp * math.cos(a)), -int(rp * math.sin(a))
with io.open('tmp/pix.txt', 'w', encoding='ascii') as f:
    for rp in (7, 14, 19, 24, 40, 61):
        for k in range(16):
            a0 = TWO * k / 16.0
            for sw in (math.pi / 2, math.pi / 4, 1.0, 2.6):
                x1, y1 = ray(rp, a0)
                x2, y2 = ray(rp, a0 + sw)
                f.write("%d_%d_%d %d 1 %d %d %d %d\n"
                        % (rp, k, int(sw * 1000), rp, x1, y1, x2, y2))
PY
tmp/gdiarc.exe < tmp/pix.txt > tmp/pix.out
python tools/bezpix.py tol
