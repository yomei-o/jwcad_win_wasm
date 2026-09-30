#!/bin/sh
# Make the original draw the block answers again.
#
#   sh tools/refblocks.sh
#
# decomp/res/blkmake.jww in the repository was stale: its title is Test5's
# 「○○な内容図」, its groups are Test5's and its definition holds 88
# members, so it was taken before tools/refanswers.sh was changed to open
# tools/mkgeom.c's twelve-element drawing instead of Test5 itself.  Every
# block answer downstream of it -- blkedit, blkrename, blk2all, blk2one,
# blkattr, blkfree -- was made from that file and is stale in the same way.
# That is what tools/check.sh's fourteen block BADs are: the port and the
# answer are not looking at the same drawing.
#
# This runs just that stretch of tools/refanswers.sh again.  Nothing here
# reads the screen; the window is shown because it has to be.
set -e
cd "$(dirname "$0")/.."
mkdir -p decomp/res tmp

PS='powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1'
CC=${CC:-gcc}

idle() {
    idle_n=0
    while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do
        idle_n=$((idle_n + 1))
        [ $idle_n -gt 90 ] && { echo "Jw_win.exe will not go away" >&2; exit 1; }
        sleep 1
    done
}

run() {                         # run <what> <open> <clicks>
    idle
    sh tools/refenv.sh >/dev/null
    cp "$2" tmp/rect.jww
    echo "=== $1"
    $PS -Open tmp/rect.jww -NoSave -Clicks "$3" 2>&1 | sed 's/^/        /'
}

# the twelve-element drawing over Test5's sheet
$CC -O2 -Isrc -o tmp/mkgeom.exe tools/mkgeom.c src/jww.c src/jwwrite.c \
    src/cp932.c
./tmp/mkgeom.exe orig/Test5.jww tmp/geom.jww

run blkmake tmp/geom.jww \
 'cmd:32787;100,100;r1150,650;dlgin:32853,1827=BLK;saveas:decomp/res/blkmake.jww'

run blkedit decomp/res/blkmake.jww \
 'cmd:32787;100,100;r1150,650;dlgin:32986,2410=!,2410=!;cmd:32771;300,300;500,300;cmd:32985;saveas:decomp/res/blkedit.jww'

run blkrename decomp/res/blkmake.jww \
 'cmd:32787;100,100;r1150,650;dlgin:32986,2359=NEWNAME,3=!;cmd:32985;saveas:decomp/res/blkrename.jww'

$CC -O2 -Isrc -o tmp/mk2blk.exe tools/mk2blk.c src/jww.c src/jwwrite.c \
    src/cp932.c
./tmp/mk2blk.exe decomp/res/blkmake.jww tmp/twoblk.jww

run blk2all tmp/twoblk.jww \
 'cmd:32787;100,100;r850,650;dlgin:32986,2410=!,2410=!;cmd:32771;300,300;500,300;cmd:32985;saveas:decomp/res/blk2all.jww'

run blk2one tmp/twoblk.jww \
 'cmd:32787;100,100;r850,650;dlgin:32986,2411=!;cmd:32771;300,300;500,300;cmd:32985;saveas:decomp/res/blk2one.jww'

run blkattr decomp/res/blkmake.jww \
 'cmd:32787;100,100;r1150,650;dlgin:32970,1323=!;saveas:decomp/res/blkattr.jww'

run blkfree decomp/res/blkmake.jww \
 'cmd:32787;100,100;r1150,650;cmd:32909;saveas:decomp/res/blkfree.jww'

idle
sh tools/refenv.sh >/dev/null
echo "done -- now run tests/blkmake_test.exe and tests/blkedit_test.exe"
