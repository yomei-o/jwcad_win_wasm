#!/bin/bash
# Regenerate the answers tests/image_test.c is held against: the original's own
# files for each 画像編集 operation, into decomp/res/img_<name>.jww.
# The picture is tmp/img/t1.bmp (python tools/mkbmp.py tmp/img/t1.bmp 40 30).  Needs the original,
# which it takes for itself: never run it beside another driver.
cd "$(dirname "$0")/.."
mkdir -p tmp/img
[ -f tmp/img/t1.bmp ] || python tools/mkbmp.py tmp/img/t1.bmp 40 30
[ -f tmp/img/s200x100.bmp ] || python tools/mkbmp.py tmp/img/s200x100.bmp 200 100
run() {   # name pre post
    sh tools/img3.sh "iref_$1" "$2" "$3" >/dev/null 2>&1
    mv -f "tmp/iref_$1.jww" "decomp/res/img_$1.jww" 2>/dev/null
    mv -f "tmp/iref_$1.png" "decomp/res/img_$1.png" 2>/dev/null
    echo "done $1"
}
run ins     ""  "400,300"
run move    ""  "300,400;330,380;500,200"
run trim    ""  "300,400;btn:1335;330,380;430,300"
run untrim  ""  "300,400;btn:1335;330,380;430,300;btn:1336;380,340"
run fitx    ""  "300,400;btn:1345;330,380;430,300;100,150;300,50"
run fity    ""  "300,400;btn:1345;330,300;380,390;100,100;250,300"
run rot1    "btn:1345;btn:1346" "300,400;310,390;410,390;200,200;300,300"
run rot2    "btn:1345;btn:1346" "300,400;310,390;410,390;300,200;200,200"
run rot3    "btn:1345;btn:1346" "300,400;310,390;410,390;300,300;200,400"
run rtrim   "btn:1345;btn:1346" "300,400;310,390;410,390;200,200;300,300;btn:1345;btn:1335;250,200;300,250"
run trans   ""  "300,400;btn:1339;380,340;wait:1000;dlgnow:2579=255,2580=0,2581=128;wait:800"
run rel     "btn:1338" "300,400"
run embed   ""  "300,400;pb:2559;wait:1500;dlgnow:1=!;wait:1500;dlgnow:2=!;wait:1500"
run two     ""  "300,400;pb:2557;wait:1500;opendlg:tmp/img/s200x100.bmp;wait:1500;350,420;400,380;600,300"
run sep     ""  "300,400;pb:2559;wait:1500;dlgnow:1=!;wait:1500;dlgnow:2=!;wait:1500;saveas:iref_x;wait:1500;pb:2561;wait:1500;dlgnow:1=!;wait:2000;dlgnow:2=!;wait:1000"
run lines   "cmd:32771;250,340;500,340;cmd:33013" "300,400"
run ghost   ""  "300,400;330,380;m500,250;wait:600;m510,260;wait:800"
echo finished > tmp/imgref.done
