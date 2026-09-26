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

sh tools/check.sh > tmp/ck.txt 2>&1
echo "check.sh exit code: $?"
echo "lines: $(wc -l < tmp/ck.txt)"
echo "--- the last five"
tail -5 tmp/ck.txt
echo "--- any build failures left behind"
ls tests/out/obj/*.fail 2>/dev/null | head -3 || echo none
