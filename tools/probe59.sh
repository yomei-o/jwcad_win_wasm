#!/bin/sh
# 円弧: which way round, and what unit 扁平率 is in.
#
#   sh tools/probe59.sh
#
# tools/probe57.sh put the port beside the original for the first time and
# three things came apart (tests/enko_test.c):
#
#   円弧 (1318)  the original swept **-5.3559** where the port sweeps
#                +0.9273 -- the same two ends, the other way round and
#                the long way.  One arc cannot tell「always clockwise」
#                from「the shorter way」, so this asks again with an end
#                for which those two differ: from -0.4636 round to -0.2
#                is -6.02 clockwise and +0.2636 anticlockwise.
#   扁平率 (1412) typed 0.5, the original made the ratio **0.5**.  The
#                port divides by a hundred, on an older note that 50 gave
#                0.5.  Both cannot be a plain reading of one box, so 50,
#                0.5 and 200 all go in.
#   円弧＋扁平率 the original made an ellipse arc; the port ignored the
#                flattening.  One more of those, with a different end, to
#                have two to fit the rule to.
cd "$(dirname "$0")/.."
set +e
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"
idle() { k=0; while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do k=$((k+1)); [ $k -gt 90 ] && break; sleep 1; done; }
run() {
    idle; sh tools/refenv.sh >/dev/null; cp decomp/res/new.jww tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -Cmd 0 -NoSave -Clicks "$2" 2>&1 |
        grep -E "read 59393|throw|no |saved" | sed 's/^/    /'
}

E='cmd:32773;'
run arc_b  "${E}btn:1318;300,300;500,400;496,340;saveas:p59_arc_b"
run arc_c  "${E}btn:1318;300,300;500,400;217,482;saveas:p59_arc_c"
run fl_50  "${E}chr:1412,50;300,300;500,400;saveas:p59_fl_50"
run fl_200 "${E}chr:1412,200;300,300;500,400;saveas:p59_fl_200"
run afl2   "${E}btn:1318;chr:1412,0.5;300,300;500,400;217,482;saveas:p59_afl2"
idle
sh tools/refenv.sh >/dev/null
