#!/bin/sh
# Run something and put the time in front of every line it prints.
#
#   sh tools/timeline.sh sh tools/check.sh
#
# check.sh takes a quarter of an hour on the build box and it was never
# clear where that went -- the first guess here was "the compiler", which
# turned out to be seventeen seconds of it.  This says instead of guesses.
# Feed the output to tools/timeline.py for the slowest steps.
exec "$@" 2>&1 | while IFS= read -r line; do
    printf '%s %s\n' "$(date +%H:%M:%S)" "$line"
done
