#!/bin/sh
# Does the ring depend only on (radius, start), with the end merely cutting
# it short?  If the same start with three different sweeps gives the same
# pixels over the stretch they share, then yes -- and a replacement only has
# to get the walk from the start right, not the pair of ends.
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
mkdir -p tmp
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
python tools/arcsame.py
tmp/gdiarc.exe < tmp/same.txt > tmp/same.out
python tools/arcsame.py tmp/same.out
