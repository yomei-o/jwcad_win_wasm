#!/bin/sh
# Make the original write a PDF of its own.
#
#   sh tools/probe31.sh
#
# The printer on this machine is Microsoft Print To PDF (tools/probe29.sh),
# and the print bar has 印刷 (L) on 1065 (tools/probe30.sh).  Pressing it
# sends the sheet to that printer, which asks for a file name.  What comes
# out is the original's own answer to「印刷とは何を出すことか」 -- the page
# size above all, which is what the port has to match.
#
# The drawing is one line well inside an A-2 sheet, so if the page turns
# out to be the sheet it will be 594 x 420 mm, and if it is the drawn
# extent it will be much smaller.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
rm -f tmp/orig_print.pdf
idle
sh tools/refenv.sh >/dev/null
cp decomp/res/new.jww tmp/rect.jww
echo "=== print"
$PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks \
 'cmd:32771;off:1333;300,300;700,500;raw:f,273,57607,0;wait:2000;pb:1;wait:2000;pb:1065;wait:4000;tops' \
 2>&1 | sed 's/^/    /'
idle
sh tools/refenv.sh >/dev/null
