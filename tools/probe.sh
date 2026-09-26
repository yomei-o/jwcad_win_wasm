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

sh tools/sweepenv.sh JW_DASH_ACC 1
