#!/bin/sh
# sh tools/stagecmp.sh name "steps" : run the steps (E N R, clicks, cmd:) on the original and on the port
# over three lines drawn on a blank sheet and print the read lines side by side (needs tools/escprobe_port.sh run once)
cd "$(dirname "$0")/.."
sh tools/stageprobe.sh "$1" "$2" 2>&1 | tail -n +2 > tmp/sr/o_$1.txt
B='cmd:32771;300,300;400,300;300,350;400,350;600,300;700,300;380,250;380,420;'
JWFILE=decomp/res/new.jww ./tmp/q_e2.exe "$1|$B$2" > tmp/sr/p_$1.txt
PYTHONIOENCODING=utf-8 python tmp/sr/cmp.py tmp/sr/o_$1.txt tmp/sr/p_$1.txt
