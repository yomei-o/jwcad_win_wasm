#!/bin/sh
# summarise tmp/<name>.jww images and the picture bbox: sh tools/imgres.sh <name>
cd "$(dirname "$0")/.."
PYTHONIOENCODING=utf-8 python tools/imgdump.py tmp/$1.jww | sed 's/.*x0=/x0=/; s/ w=2.*text=.*img.//; s/ w=[0-9.]* h=[0-9.]* sp=[0-9.]*  text=.*img./ /'
python tools/imgbox.py tmp/$1.png
