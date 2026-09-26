#!/bin/sh
# Break one thing on purpose and see whether the score notices.
#
#   sh tools/mutate.sh
#
# The fifteen-drawing score (814 pixels) is the number this port is steered
# by, so it is worth knowing what it can see.  Each mutation below is a
# change that *must* show up; if one of them scores the same as the tree
# does, the score is blind to that part and the number means less than it
# looks.  The tree is put back after each one (the copy on the build box is
# overwritten by the next sync anyway).
#
# This is not part of check.sh -- it is a thing to run when the harness
# itself is in question, the way tools/asanone.sh is for a single test.
#
# Run on whatever box holds tmp/refs.
cd "$(dirname "$0")/.."
set -e

total() {
    sh tools/score.sh 2>/dev/null | tail -1 |
        sed 's/.*total //'
}

try() {   # $1 = name, $2 = file, $3 = sed script
    cp "$2" "$2.keep"
    sed -i "$3" "$2"
    if cmp -s "$2" "$2.keep"; then
        echo "SKIP $1 -- the pattern did not match, so nothing was changed"
        mv "$2.keep" "$2"
        return
    fi
    printf '%-40s %s\n' "$1" "$(total)"
    mv "$2.keep" "$2"
}

printf '%-40s %s\n' "the tree as it stands" "$(total)"

try "every pixel one to the right" src/view.h \
    's@return v->bx + jw_px_round((x - v->ox) / v->mmpp + jw_round_x);@return v->bx + 1 + jw_px_round((x - v->ox) / v->mmpp + jw_round_x);@'

try "every pixel one down" src/view.h \
    's@return v->by - jw_px_round((y - v->oy) / v->mmpp + jw_round_y);@return v->by - 1 - jw_px_round((y - v->oy) / v->mmpp + jw_round_y);@'

try "the arc paints its far pixel" src/draw.c \
    's@endi = (endi - step + one_end \* step) % n;@endi = (endi + one_end * step) % n;@'

try "every pen one pixel wide" src/draw.c \
    's@    return w >= 1 \&\& w <= JW_WIDE_MAX ? w : 1;@    return 1;@'

try "a whole circle in the arc box" src/draw.c \
    's@        int oddbox = odd;@        int oddbox = 1;@'

try "the grey layers drawn last" src/draw.c \
    's@        if ((state == 1) != grey_pass)@        if ((state == 1) == grey_pass)@'

try "line types all solid" src/draw.c \
    's@    return t >= 1 \&\& t <= 9 ? t : 1;@    return 1;@'

try "every 仮点 a single pixel" src/draw.c     's@            } else if (o->flags \& 0x400) {@            } else if (0) {@'

try "the solid fill takes its far edge in" src/draw.c     's@            int a = xs\[i\], b = xs\[i + 1\];@            int a = xs[i], b = xs[i + 1] + 1;@'

try "no text drawn at all" src/draw.c     's@        case JW_MOJI:@        case JW_MOJI: break;@'

echo MUTATEDONE
