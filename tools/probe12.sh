#!/bin/sh
# The two pictures no capture had: the write layer with nothing drawn on
# it, and the write group with nothing drawn on it.  Every picture so far
# was taken of orig/Test5.jww, whose write layer (8) and write group (0)
# both have plenty on them, and the original draws a different picture for
# an empty one.
#
#   tmp/t5wl5.jww   that drawing with the empty layer 5 made the write
#                   layer
#   tmp/t5wg1.jww   and with the empty group 1 made the write group, which
#                   also moves the tab strip's open cell one along
#
# tools/mkt5variants.py writes both, by patching the longs in the header
# that say who is being written to and nothing else.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
python tools/mkt5variants.py
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 60 ] && break; sleep 1; done; }
shot() {
    idle; sh tools/refenv.sh >/dev/null; cp "$1" tmp/rect.jww
    echo "=== $2"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "dlg:32808,$2" 2>&1 |
        grep -E "throw|no " | sed 's/^/    /'
}
shot tmp/t5wl5.jww docs/ref_layerdlg_emptywrite.png
shot tmp/t5wg1.jww docs/ref_layerdlg_emptygroup.png
idle
