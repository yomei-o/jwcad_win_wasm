#!/bin/sh
cd "$(dirname "$0")/.."
until grep -q '^done' tmp/skall.log; do sleep 10; done
sh tools/skall.sh B A > tmp/skall2.log 2>&1
sh tools/skbatch12.sh > tmp/skbatch12.log 2>&1
echo finished > tmp/skafter.done
