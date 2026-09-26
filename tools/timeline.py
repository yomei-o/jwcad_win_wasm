#!/usr/bin/env python3
u"""Which steps of a run took the time?

    sh tools/timeline.sh sh tools/check.sh > tmp/timeline.txt
    python tools/timeline.py tmp/timeline.txt

tools/timeline.sh puts a clock time in front of every line; this turns that
into "how long until the next line came", which is how long the step that
printed the line took.  Nothing here is clever -- it is here so that a guess
about where the time goes can be replaced by a measurement.
"""
import io
import re
import sys


def say(line):
    """Print it whatever the console's encoding is.

    The build box's console is CP932 and check.sh's headings are Japanese
    with an em dash in them, which is not in CP932 -- printing one straight
    out ends the run with a UnicodeEncodeError and no measurement."""
    enc = getattr(sys.stdout, "encoding", None) or "ascii"
    sys.stdout.write(line.encode(enc, "replace").decode(enc, "replace"))
    sys.stdout.write("\n")


def main():
    path = sys.argv[1] if len(sys.argv) > 1 else "-"
    f = sys.stdin if path == "-" else io.open(path, encoding="utf-8",
                                              errors="replace")
    rows = []
    for line in f:
        m = re.match(r"(\d\d):(\d\d):(\d\d) (.*)", line.rstrip("\n"))
        if m:
            t = (int(m.group(1)) * 3600 + int(m.group(2)) * 60
                 + int(m.group(3)))
            rows.append((t, m.group(4)))
    if len(rows) < 2:
        sys.exit("no timestamped lines in %s" % path)
    # midnight, if it happens
    out = []
    base = 0
    prev = rows[0][0]
    for t, txt in rows:
        if t + base < prev:
            base += 24 * 3600
        prev = t + base
        out.append((prev, txt))
    total = out[-1][0] - out[0][0]
    spans = [(out[i + 1][0] - out[i][0], out[i][1])
             for i in range(len(out) - 1)]
    say("%d lines over %d seconds" % (len(out), total))
    spans.sort(reverse=True)
    shown = 0
    for d, txt in spans:
        if d < 2 or shown >= 20:
            break
        say("  %5d s  %s" % (d, txt[:90]))
        shown += 1
    rest = sum(d for d, _ in spans if d < 2)
    say("  %5d s  everything under two seconds" % rest)


if __name__ == "__main__":
    main()
