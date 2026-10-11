#!/bin/sh
cd "$(dirname "$0")/.."
until [ -f tmp/skafter.done ]; do sleep 10; done
sh tools/skall_t.sh > tmp/skall_t.log 2>&1
echo finished > tmp/skafter2.done
