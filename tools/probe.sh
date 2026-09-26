#!/bin/sh
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
mkdir -p tmp
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
python tools/arcswap.py
tmp/gdiarc.exe < tmp/sw.txt > tmp/sw.out 2>/dev/null
python tools/arcswap.py tmp/sw.out
