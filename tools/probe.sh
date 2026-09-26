#!/bin/sh
# The readers and the drawing changed today (src/coord.c, src/text.c,
# src/draw.c), and the note says to run the sanitisers after that.
cd "$(dirname "$0")/.."
sh tools/asan.sh 2>&1 | tail -40
