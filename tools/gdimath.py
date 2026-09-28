#!/usr/bin/env python3
u"""GDI's own arithmetic for arcs, function for function.

Everything here is read out of `win32kbase.sys` and `win32kfull.sys` (see
`decomp/gdi/`), with the real tables out of the image -- `gaefArctan`,
`gaefSin`, `gaefAxisCoord`, `gaefAxisAngle` -- in `tools/arctan_table.py`.

GDI does none of this in double precision and none of it with the C
library: angles are **degrees** in a single-precision `EFLOAT`, sine and
arctangent are thirty-three-entry tables it truncates into and
interpolates, and a whole quadrant of a circle is not built from those at
all but from the box's corners with one integer multiply.  Matching Jw_cad
to the pixel means doing the same, so this module is the reference the
port is held against.
"""
import struct

import arctan_table as T


def f32(v):
    """Round to single precision.  On x64 an `EFLOAT` is a plain IEEE
    float -- `EFLOAT::bIsZero` compares `*(float *)this` against 0.0 --
    so every step of GDI's arithmetic lands here."""
    return struct.unpack("<f", struct.pack("<f", v))[0]


ARCTAN = T.TABLE
ARCTAN_SIZE = T.SIZE
SIN = T.SIN
SINE_FACTOR = T.SINE_FACTOR
EPSILON = T.EPSILON
FOUR_THIRDS = T.FOUR_THIRDS
ALPHA_Q = T.ALPHA_Q
AXIS_COORD = T.AXIS_COORD
AXIS_ANGLE = T.AXIS_ANGLE


def varctan(x, y):
    """`vArctan`: the angle of (x, y) in degrees, and its quadrant.

    Fold into the first eighth, divide `lo * 32 / hi`, truncate that to an
    index into `gaefArctan`, interpolate to the next entry, and put the
    eighth back on.
    """
    quad = 2 if x >= 0.0 else 3
    o = 0 if x >= 0.0 else 1
    ax = x if x >= 0.0 else -x
    ay = y
    if y < 0.0:
        o = quad
        ay = -y
    hi, lo = ax, ay
    if ax < ay:
        o |= 4
        hi, lo = ay, ax
    if hi == 0.0:
        return 0.0, 0
    t = f32(f32(lo * float(ARCTAN_SIZE)) / hi)
    i = int(t)
    if i > ARCTAN_SIZE:
        i = ARCTAN_SIZE
    fr = f32(t - i)
    a0 = ARCTAN[i]
    ang = f32(f32(f32(ARCTAN[i + 1] - a0) * fr) + a0)
    if o == 1:
        ang = f32(180.0 - ang)
    elif o == 2:
        ang = f32(360.0 - ang)
    elif o == 3:
        ang = f32(ang + 180.0)
    elif o == 4:
        ang = f32(90.0 - ang)
    elif o == 5:
        ang = f32(ang + 90.0)
    elif o == 6:
        ang = f32(ang + 270.0)
    elif o == 7:
        ang = f32(270.0 - ang)
    # DAT_14036fe50, the octant-to-quadrant byte table
    return ang, (0, 1, 3, 2, 0, 1, 3, 2)[o]


def _sin_pair(deg):
    """The shared front of `efSin` and `vCosSin`: fold, index, fraction."""
    neg = deg < 0.0
    a = -deg if neg else deg
    t = f32(SINE_FACTOR * a)
    k = int(t)
    fr = f32(t - k)
    return neg, k >> 5, k & 0x1f, fr


def _up(i, fr):
    return f32(f32(f32(SIN[i + 1] - SIN[i]) * fr) + SIN[i])


def _down(i, fr):
    return f32(SIN[32 - i] - f32(f32(SIN[32 - i] - SIN[31 - i]) * fr))


def efsin(deg):
    """`efSin`: sine of an angle in degrees, off `gaefSin`."""
    neg, q, i, fr = _sin_pair(deg)
    s = _up(i, fr) if (q & 1) == 0 else _down(i, fr)
    return -s if ((not neg) if (q & 2) else neg) else s


def efcos(deg):
    """`efCos`, which is `efSin(x + 90)` and nothing else."""
    return efsin(f32(deg + 90.0))


def vcossin(deg):
    """`vCosSin`: both at once, each off its own end of `gaefSin`."""
    neg, q, i, fr = _sin_pair(deg)
    s = _up(i, fr) if (q & 1) == 0 else _down(i, fr)
    if (not neg) if (q & 2) else neg:
        s = -s
    c = _up(i, fr) if ((q + 1) & 1) == 0 else _down(i, fr)
    if (q + 1) & 2:
        c = -c
    return c, s


def quadrant_arc(p0, p3, a0, a1):
    """`bPartialQuadrantArc`: the cubic through p0 and p3, on the unit
    circle, for a piece that stays inside one quadrant.

        cross = |p0.x*p3.y - p0.y*p3.x|
        beta  = (4/3 * |cos((a1 - a0)/2)|) / (|cos(...)| + 1)
        c1 = (1-beta)*p0 + beta*((p3.y-p0.y)/cross, (p0.x-p3.x)/cross)
        c2 = (1-beta)*p3 + beta*(   same       )

    For a whole quadrant beta comes out kappa, 0.5523.
    """
    cr = f32(f32(p0[0] * p3[1]) - f32(p0[1] * p3[0]))
    if cr < 0.0:
        cr = -cr
    if not EPSILON < cr:
        return [p0, p0, p3, p3]
    c = efcos(f32(f32(a1 - a0) * 0.5))
    if c < 0.0:
        c = -c
    beta = f32(f32(FOUR_THIRDS * c) / f32(c + 1.0))
    alpha = f32(1.0 - beta)
    tx = f32(beta * f32(f32(p3[1] - p0[1]) / cr))
    ty = f32(beta * f32(f32(p0[0] - p3[0]) / cr))
    c1 = (f32(f32(alpha * p0[0]) + tx), f32(f32(alpha * p0[1]) + ty))
    c2 = (f32(f32(alpha * p3[0]) + tx), f32(f32(alpha * p3[1]) + ty))
    return [p0, c1, c2, p3]


def axis_point(i):
    """`gaefAxisCoord` read the way bPartialArc reads it: the point where
    quadrant i starts, (1,0) (0,1) (-1,0) (0,-1)."""
    return (AXIS_COORD[(i + 1) & 3], AXIS_COORD[i])


def mulhi(v):
    """The one integer step: `(v * 0x729d7775) >> 32`, which is v times
    (1 - kappa) rounded **down**, not to nearest.  A whole quadrant's
    control points come out of this and not out of the float path, so they
    can sit a sixteenth of a pixel off what the float path would give."""
    return (v * ALPHA_Q) >> 32


class Box(object):
    """`EBOX`: the middle and the two half-axes, in POINTFIX.

    For the rect Arc is handed -- (cx-rp, cy-rp) to (cx+rp+1, cy+rp+1) --
    the ellipse is taken with **both edges in**, so the middle is cx, cy
    exactly and the half-axes are rp.  u points along +x, v along -y, which
    puts quadrant 0 between three o'clock and twelve.
    """

    def __init__(self, cx, cy, rp):
        self.m = (cx * 16, cy * 16)
        self.u = (rp * 16, 0)
        self.v = (0, -rp * 16)

    def corner(self, i):
        """C0 = M+u+v, C1 = M-u+v, C2 = M-u-v, C3 = M+u-v."""
        su = 1 if i in (0, 3) else -1
        sv = 1 if i in (0, 1) else -1
        return (self.m[0] + su * self.u[0] + sv * self.v[0],
                self.m[1] + su * self.u[1] + sv * self.v[1])

    def xform(self, p):
        """`EBOX::ptlXform`: onto the ellipse, in POINTFIX, rounded."""
        x = f32(self.m[0] + f32(f32(self.u[0] * p[0]) + f32(self.v[0] * p[1])))
        y = f32(self.m[1] + f32(f32(self.u[1] * p[0]) + f32(self.v[1] * p[1])))
        return (int(x + 0.5) if x >= 0 else -int(-x + 0.5),
                int(y + 0.5) if y >= 0 else -int(-y + 0.5))

    def whole_quadrant(self, i):
        """The four control points of quadrant i, from the corners, the way
        the middle of `bPartialArc` builds them -- all integer."""
        c = self.corner(i)
        au = (mulhi(self.u[0]), mulhi(self.u[1]))
        av = (mulhi(self.v[0]), mulhi(self.v[1]))
        if i == 0:
            return [(c[0] - self.v[0], c[1] - self.v[1]),
                    (c[0] - av[0], c[1] - av[1]),
                    (c[0] - au[0], c[1] - au[1]),
                    (c[0] - self.u[0], c[1] - self.u[1])]
        if i == 1:
            return [(c[0] + self.u[0], c[1] + self.u[1]),
                    (c[0] + au[0], c[1] + au[1]),
                    (c[0] - av[0], c[1] - av[1]),
                    (c[0] - self.v[0], c[1] - self.v[1])]
        if i == 2:
            return [(c[0] + self.v[0], c[1] + self.v[1]),
                    (c[0] + av[0], c[1] + av[1]),
                    (c[0] + au[0], c[1] + au[1]),
                    (c[0] + self.u[0], c[1] + self.u[1])]
        return [(c[0] - self.u[0], c[1] - self.u[1]),
                (c[0] - au[0], c[1] - au[1]),
                (c[0] + av[0], c[1] + av[1]),
                (c[0] + self.v[0], c[1] + self.v[1])]


def partial_arc(box, a0, q0, a1, q1):
    """`bPartialArc`: the whole run of cubics from a0 to a1, counter-
    clockwise, in POINTFIX.

    One piece if both ends sit in the same quadrant and the angle grows;
    otherwise a piece from a0 to the next axis, then whole quadrants off
    the corners, then a piece from the last axis to a1.
    """
    if q0 == q1 and a1 > a0:
        p0 = vcossin(a0)
        p1 = vcossin(a1)
        return [[box.xform(p) for p in quadrant_arc(p0, p1, a0, a1)]]
    out = []
    nxt = (q0 + 1) & 3
    out.append([box.xform(p) for p in
                quadrant_arc(vcossin(a0), axis_point(nxt), a0, AXIS_ANGLE[nxt])])
    q = nxt
    while q != q1:
        out.append(box.whole_quadrant(q))
        q = (q + 1) & 3
    out.append([box.xform(p) for p in
                quadrant_arc(axis_point(q1), vcossin(a1), AXIS_ANGLE[q1], a1)])
    return out
