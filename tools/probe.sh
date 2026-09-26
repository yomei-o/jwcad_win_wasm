#!/bin/sh
cd "$(dirname "$0")/.."
PATH="$PATH:/c/prog/tools/w64devkit/bin"
sh tools/build_tests.sh 2>&1 | grep -iE ' error|did not build' | head -5
./tests/coord_test.exe 2>&1 | tail -5
