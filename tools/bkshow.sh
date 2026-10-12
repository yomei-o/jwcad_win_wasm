#!/bin/sh
# sh tools/bkshow.sh name  -- objects after the 5 base ones, compactly
python tools/jww.py tmp/bk_$1.jww -l 2>&1 | grep -v Moji | grep "CData" | sed -n '6,$p' | sed 's/pen=[0-9]* type=[0-9]* width=0 f2e=0 f2f=0 flags=0 //'
