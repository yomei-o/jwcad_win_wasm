#!/bin/sh
# A scratch script for one-off questions on the build box.
#
#   sh sync.sh 'sh tools/probe.sh'
#
# Its contents change from one question to the next and nothing depends on
# it.  It exists because sync.sh hands its argument to `bash -lc "..."` on
# the far side, so anything with quotes, pipes or $ in it has to survive two
# shells; writing the commands to a file instead and running that removes
# the whole class of mistake.
cd "$(dirname "$0")/.."
case ":$PATH:" in
    *:/c/prog/tools/w64devkit/bin:*) ;;
    *) PATH="$PATH:/c/prog/tools/w64devkit/bin" ;;
esac

sh tools/score.sh > /dev/null 2>&1 || { echo "build failed"; exit 1; }
gcc -O2 -w -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || { echo "gdiarc failed"; exit 1; }

for n in d14 d08; do
    echo "=== $n"
    JW_SHOT_ELEMS=1 ./tests/shot.exe "tmp/$n.out.png" "tmp/$n.jww" >/dev/null
    python tools/boxask.py "tmp/refs/$n.png" "tmp/$n.out.png" >/dev/null || continue
    tmp/gdiarc.exe < tmp/boxes.txt > tmp/gdibox.out
    BOXASK_MIN=20 python tools/boxask.py "tmp/refs/$n.png" "tmp/$n.out.png" tmp/gdibox.out
done
