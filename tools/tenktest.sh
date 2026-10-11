#!/bin/sh
# 天空図の作図 (src/tenku.c) の試験。cmd.c など 重い物は 入れずに 作る。
#   sh tools/tenktest.sh
cd "$(dirname "$0")/.."
for d in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$d/gcc.exe" ] && { PATH="$d:$PATH"; export PATH; break; }
done
mkdir -p tmp
gcc -O1 -Wall -Wextra -Wno-unused-parameter -std=c99 -Isrc -o tmp/tenku_test.exe \
    tests/tenku_test.c src/tenku.c src/hikage.c src/jww.c src/cp932.c -lm || exit 1
./tmp/tenku_test.exe "$@"
