#!/bin/sh
# Make everything src/ is compiled against, from your own copy of the original.
#
#   ./jww10036.exe /VERYSILENT /SUPPRESSMSGBOXES /NORESTART /NOICONS \
#       "/DIR=<this directory>\orig"
#   sh tools/gen.sh
#   sh tools/check.sh
#
# decomp/ and src/gen/ are machine output taken from someone else's program, so
# neither is committed and a new machine makes them again.  README.md lists the
# steps; this is them in an order that works, which matters -- tools/btnmap.py
# needs what tools/rsrc.py writes, tools/mkcmd.py needs what tools/btnmap.py
# writes, and so on.  Everything before "the original has to run" is pure
# computation on the .exe and takes about a minute; the rest drives Jw_cad and
# takes twenty.
#
#   -q   stop before the parts that run the original
set -e
cd "$(dirname "$0")/.."
[ -f orig/Jw_win.exe ] || { echo "expand the installer into orig/ first -- see README.md" >&2; exit 1; }
mkdir -p decomp/res src/gen tmp

say() { echo; echo "--- $*"; }

say 'resources: menus, dialogs, strings, toolbars, bitmaps'
python tools/rsrc.py  orig/Jw_win.exe decomp/res

say 'the frame images and strings the port draws with'
python tools/mkres.py orig/Jw_win.exe src/gen --maxh 21

say 'which toolbar cell is in which button, matched off the reference screen'
python tools/btnmap.py docs/ref_start.png decomp/res/bitmap src/gen/layout.h

say 'what each of those buttons sends'
python tools/mkcmd.py --write

say 'the rest of the tables'
python tools/mkfont.py font src/gen          # 東雲フォント
python tools/mkcp932.py                      # CP932 <-> UTF-16
python tools/mkicon.py orig/Jw_win.exe src/gen
python tools/mkmenu.py
python tools/mkaccel.py                      # the frame's keyboard shortcuts
python tools/mkstr.py >/dev/null             # the prompts in the status line
python tools/mkpen.py                        # the pens a new drawing starts with
python tools/mksunpo.py                      # the dimension settings

say "GDI's own circles, so the port rasterises them the same way"
# Not from the .exe: this asks the GDI on this machine what Ellipse draws.
if [ -z "$CC" ]; then
    for d in /c/prog/w64devkit/bin /c/prog/tools/w64devkit/bin; do
        [ -x "$d/gcc.exe" ] && { PATH="$d:$PATH"; export PATH; break; }
    done
    CC=gcc
fi
$CC -O2 -o tmp/gdicirc.exe tools/gdicirc.c -lgdi32
./tmp/gdicirc.exe > decomp/res/circles.txt
python tools/mkcirc.py

say "and what GDI covers with a wide pen"
$CC -O2 -o tmp/gdiwide.exe tools/gdiwide.c -lgdi32
./tmp/gdiwide.exe > decomp/res/widepen.txt
python tools/mkwide.py

[ "$1" = "-q" ] && { echo; echo "stopped before the parts that run the original"; exit 0; }

say 'the original has to run from here on'
sh tools/refenv.sh

say 'the command bar for each command, read out of the running original'
powershell -ExecutionPolicy Bypass -File tools/bars.ps1 -Out decomp/res/bars.txt >/dev/null
python tools/mkbars.py

say '線属性 dialog, likewise'
# The picture goes to tmp/: docs/ref_zoku.png is the committed reference and
# tests/zoku_test.c scores the port against it.
sh tools/refenv.sh >/dev/null
cp orig/Test5.jww tmp/rect.jww
powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1 \
    -Open tmp/rect.jww -NoSave -Out decomp/res/zoku.txt \
    -Clicks 'dlg:32807,tmp/zoku.png' >/dev/null
python tools/mkzoku.py

say 'what the original puts at the top of a DXF'
# A drawing of one line per pen and per line type, written by the port's own
# writer, exported by the original: the tables in it are the same in every
# DXF, and the colours it gives each pen are in the entities.
$CC -O2 -Isrc -o tmp/mkpens.exe tools/mkpens.c src/jww.c src/jwwrite.c src/cp932.c
./tmp/mkpens.exe orig/Test5.jww tmp/pens.jww
sh tools/refenv.sh >/dev/null
powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1 \
    -Open tmp/pens.jww -NoSave -Clicks 'export:32961,decomp/res/pens.dxf' >/dev/null
sh tools/refenv.sh >/dev/null
python tools/mkdxf.py

say 'the drawings the original itself makes, which the tests are scored against'
sh tools/refanswers.sh
python tools/mknew.py decomp/res/new.jww src/gen

echo
echo "src/gen is complete -- sh tools/check.sh"
