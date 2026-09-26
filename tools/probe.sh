#!/bin/sh
cd "$(dirname "$0")/.."
sh tools/score.sh 2>&1 | tail -3
