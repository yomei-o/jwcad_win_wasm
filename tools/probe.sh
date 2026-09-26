#!/bin/sh
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
mkdir -p tmp
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
python tools/arcsub.py
tmp/gdiarc.exe < tmp/subs.txt > tmp/subs.out
python tools/arcsub.py tmp/subs.out 2>&1 | head -30
