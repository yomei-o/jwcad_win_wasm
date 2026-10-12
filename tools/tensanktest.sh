#!/bin/sh
# 三斜 の作図 (src/tenku_sansha.c) の試験。cmd.c など 重い物は 入れずに 作る。
#   sh tools/tensanktest.sh
# 原典の答え: orig/天空率表.jww (decomp/res/tenkuhyo.jww に 同じ物の 写し)
cd "$(dirname "$0")/.."
for d in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
    [ -x "$d/gcc.exe" ] && { PATH="$d:$PATH"; export PATH; break; }
done
mkdir -p tmp
gcc -O2 -Wall -Wextra -Wno-unused-parameter -std=c99 -Isrc -o tmp/tenku_sansha_test.exe \
    tests/tenku_sansha_test.c src/tenku_sansha.c src/tenku.c src/hikage.c src/jww.c src/image.c src/imgpic.c src/cp932.c -lm || exit 1
./tmp/tenku_sansha_test.exe "$@"
