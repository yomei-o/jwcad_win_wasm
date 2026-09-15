#!/bin/sh
# Read every sample drawing and check the parse lands exactly on the end of
# the file.  Getting one record length wrong shifts everything after it, so
# "+0" for all of them is a strong statement that the format is right.
set -e
cd "$(dirname "$0")/.."
fail=0
for f in orig/*.jww; do
    out=$(python tools/jww.py "$f" 2>&1 | tail -1)
    case "$out" in
        *'(+0)') echo "ok    $(basename "$f")" ;;
        *)       echo "BAD   $(basename "$f"): $out"; fail=1 ;;
    esac
done
exit $fail
