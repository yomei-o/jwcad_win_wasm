#!/bin/sh
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
mkdir -p tmp
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
python tools/arcbez.py
tmp/gdiarc.exe < tmp/bez.txt > tmp/bez.out
python tools/arcbez.py tmp/bez.out
