#!/bin/sh
# What control points does GDI give an Arc?  The path holds them as integers
# (GetPath returned PT_MOVETO + PT_BEZIERTO), so if the rule can be worked
# out the rest is deterministic.  Ask for a spread of ends at one radius,
# and for a few radii at one pair of ends.
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
mkdir -p tmp
gcc -O2 -o tmp/gdiarc.exe tools/gdiarc.c -lgdi32 || exit 1
{
  echo "q0 24 7 24 0 0 -24"
  echo "q1 24 7 0 -24 -24 0"
  echo "q2 24 7 -24 0 0 24"
  echo "q3 24 7 0 24 24 0"
  echo "h0 24 7 24 0 -24 0"
  echo "e0 24 7 23 -2 -2 -23"
  echo "e1 24 7 22 -4 -4 -22"
  echo "e2 24 7 20 -8 -8 -20"
  echo "r7 7 7 7 0 0 -7"
  echo "r14 14 7 14 0 0 -14"
  echo "r61 61 7 61 0 0 -61"
} > tmp/cp.txt
tmp/gdiarc.exe < tmp/cp.txt
