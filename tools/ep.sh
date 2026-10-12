#!/bin/sh
# sh tools/ep.sh "name|steps" ...  : escprobe3 with the output decoded to UTF-8
cd "$(dirname "$0")/.."
sh tools/escprobe3.sh "$@" 2>&1 | tail -n +2 | PYTHONIOENCODING=utf-8 python -c "
import sys;print(sys.stdin.buffer.read().decode('utf8','replace').replace('\r',''))"
