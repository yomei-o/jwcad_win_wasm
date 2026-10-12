#!/bin/bash
# more trims for working out how a trimmed picture's box is sized: decomp/res/img_tr<k>.{jww,png}
cd "$(dirname "$0")/.."
i=0
for r in "320,390;450,290" "305,395;325,385" "310,300;460,395" "350,360;400,320" "301,399;462,279"; do
    i=$((i+1))
    sh tools/img3.sh "iref_tr$i" "" "300,400;btn:1335;$r" >/dev/null 2>&1
    mv -f "tmp/iref_tr$i.jww" "decomp/res/img_tr$i.jww"; mv -f "tmp/iref_tr$i.png" "decomp/res/img_tr$i.png"
    echo "done $i $r"
done
echo finished > tmp/imgtrims.done
