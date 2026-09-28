#!/bin/sh
# What one control on a command bar does, asked of the original itself.
#
#   sh tools/probectl.sh <name> <cmd> <ctl> '<clicks>'
#
# Draws the same thing twice -- once as the bar comes up, once with <ctl>
# set first -- and prints what changed.  <ctl> may be several of these with
# `+` between them:
#
#   <id>            press it (a checkbox ticks, a button is pressed)
#   -<id>           turn a checkbox off instead
#   <id>=<text>     type into a box, one WM_CHAR at a time
#
# The two drawings stay in tmp/probe/ so they can be looked at again.
#
#   sh tools/probectl.sh sen15   0 1336        '500,400;700,500'
#   sh tools/probectl.sh sen15b  0 1336+1411=7 '500,400;700,500'
#
# Nothing here decides what a control means: the original draws both answers
# and the difference is the answer.
set -e
cd "$(dirname "$0")/.."
mkdir -p tmp/probe

name=$1; cmd=$2; ctl=$3; clicks=$4
PS="powershell -ExecutionPolicy Bypass -File tools/jwdraw.ps1"

idle() {
    n=0
    while tasklist //FI 'IMAGENAME eq Jw_win.exe' 2>/dev/null | grep -q Jw_win.exe; do
        n=$((n + 1))
        [ $n -gt 60 ] && { echo "Jw_win.exe will not go away" >&2; exit 1; }
        sleep 1
    done
}

press=''
for one in $(echo "$ctl" | tr '+' ' '); do
    case $one in
        -*)   press="$press;off:${one#-}" ;;
        *=*)  press="$press;ch:$(echo "$one" | tr '=' ',')" ;;
        *)    press="$press;btn:$one" ;;
    esac
done

draw() {                        # draw <suffix> <steps before the clicks>
    idle
    sh tools/refenv.sh >/dev/null
    cp orig/Test5.jww tmp/rect.jww
    $PS -Open tmp/rect.jww -Cmd "$cmd" \
        -Clicks "$2$clicks;saveas:tmp/probe/$name$1.jww" 2>&1 | sed 's/^/    /'
}

echo "=== $name: $cmd with [$ctl] pressed, against the same without"
draw _off ''
draw _on "${press#;};"
idle
sh tools/refenv.sh >/dev/null
echo
PYTHONIOENCODING=utf-8 python tools/whatdid.py tmp/probe/"$name"_off.jww \
                                               tmp/probe/"$name"_on.jww
