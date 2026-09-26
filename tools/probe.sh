#!/bin/sh
# Clear anything left over from a detached run, then say what is left.
for n in fuzz_test.exe cmdfuzz_test.exe shot.exe bigcirc_test.exe \
         linewalk_test.exe clipwalk_test.exe pickwalk_test.exe; do
    taskkill //F //IM "$n" > /dev/null 2>&1 || true
done
tasklist 2>/dev/null | grep -icE 'test\.exe|shot\.exe' || true
echo "cleared"
