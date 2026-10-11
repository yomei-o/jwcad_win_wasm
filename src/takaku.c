/* tk_decompose.c - polygon (arbitrary, button 1070) solid decomposition,
 * a re-implementation of Jw_cad 10.03.6 FUN_007264a0 (CZukeiTakakukei).
 *
 * Call chain: FUN_007232b0 (button 1069 handler) -> FUN_007255f0 -> FUN_007264a0.
 * Every "asm xxxxxx" comment is an address in orig/Jw_win.exe, read with
 *   objdump -d -M intel --start-address=0x7264a0 --stop-address=0x7287b0
 * (Ghidra drops the destination of FUN_004988c0(this=dest point, value), so the
 * destinations were taken from the disassembly).
 *
 *   gcc -O2 -DTK_MAIN -o tk_decompose tk_decompose.c -lm && ./tk_decompose
 *
 * CDataSolid points: A=+0x08 B=+0x18 C=+0x68 D=+0x78 (FUN_004201b0, FUN_007262f0).
 * out[k][0..7] = Ax Ay Bx By Cx Cy Dx Dy, in emission (= registration) order.
 */
#include <math.h>
#include <stdio.h>
#include "takaku.h"
#include <string.h>

#define TK_MAX 1000
#define EPS 1e-7

typedef struct { double x, y; } Pt;

/* FUN_005f97f0: origin, unit direction, length.  Zero length (|dx|+|dy|<1e-7):
 * cos=1 sin=0 len=1. */
typedef struct { double ox, oy, c, s, len; } Frame;

static void frame_set(Frame *f, Pt a, Pt b)
{
    double dx = b.x - a.x, dy = b.y - a.y;
    f->ox = a.x; f->oy = a.y;
    if (fabs(dx) + fabs(dy) >= EPS) {
        f->len = sqrt(dx * dx + dy * dy);
        f->c = dx / f->len;
        f->s = dy / f->len;
    } else {
        f->c = 1.0; f->s = 0.0; f->len = 1.0;
    }
}
/* FUN_005f8c20(1,..): signed distance, positive on the left of the direction */
static double f_cross(const Frame *f, Pt p) { return (p.y - f->oy) * f->c - (p.x - f->ox) * f->s; }
/* FUN_005f8b60(1,..): projection on the direction */
static double f_proj(const Frame *f, Pt p) { return (p.x - f->ox) * f->c + (p.y - f->oy) * f->s; }

/* FUN_00436970: 1 when the two points agree within 1e-7 on both axes */
static int same_pt(Pt a, Pt b) { return fabs(b.y - a.y) < EPS && fabs(b.x - a.x) < EPS; }

/* FUN_004619b0: segments a1a2 / b1b2.  1 = intersect inside both segments,
 * 2 = lines intersect outside a segment, 0 = parallel etc. */
static int seg_inter(Pt a1, Pt a2, Pt b1, Pt b2, Pt *I)
{
    double ex = a2.x - a1.x, ey = a2.y - a1.y, fx = b2.x - b1.x, fy = b2.y - b1.y;
    double d4 = (b1.y - a1.y) * ex - (b1.x - a1.x) * ey;
    double d5 = (b2.y - a1.y) * ex - (b2.x - a1.x) * ey;
    double den = d4 - d5, t;

    I->x = I->y = 9990000000000.0;
    if (!(EPS < fabs(den))) return 0;
    if (fabs(d4) > fabs(den) * 1e10) return 0;
    t = d4 / den;
    I->x = fx * t + b1.x;
    I->y = fy * t + b1.y;
    if (fabs(I->x) + fabs(I->y) > 139778713.93879598) return 0;
    if (a1.x == a2.x) I->x = a1.x;
    if (a1.y == a2.y) I->y = a1.y;
    if (b1.x == b2.x) I->x = b1.x;
    if (b1.y == b2.y) I->y = b1.y;
    if (fabs(ex) <= fabs(ey)) {
        if (I->y < a1.y - EPS && I->y < a2.y - EPS) return 2;
        if (a1.y + EPS < I->y && a2.y + EPS < I->y) return 2;
    } else {
        if (I->x < a1.x - EPS && I->x < a2.x - EPS) return 2;
        if (a1.x + EPS < I->x && a2.x + EPS < I->x) return 2;
    }
    if (fabs(fx) <= fabs(fy)) {
        if (I->y < b1.y - EPS && I->y < b2.y - EPS) return 2;
        if (b1.y + EPS < I->y && b2.y + EPS < I->y) return 2;
    } else {
        if (I->x < b1.x - EPS && I->x < b2.x - EPS) return 2;
        if (b1.x + EPS < I->x && b2.x + EPS < I->x) return 2;
    }
    return 1;
}

typedef struct { double (*out)[8]; int *nout; } Sink;

/* FUN_007262f0: rejects the solid when A==B.  FUN_004201b0 stores it into the
 * 1-based array of 0x3ec temporaries; they are registered in order at the end. */
static void emit(Sink *k, Pt A, Pt B, Pt C, Pt D)
{
    double *o;
    if (same_pt(A, B)) return;
    if (*k->nout >= 1003) return;
    o = k->out[(*k->nout)++];
    o[0] = A.x; o[1] = A.y; o[2] = B.x; o[3] = B.y;
    o[4] = C.x; o[5] = C.y; o[6] = D.x; o[7] = D.y;
}

/* Body of FUN_007264a0 (the this+0x118==0 side).  P[1..n] is the closed point
 * list (P[n]==P[1] when the user gave >=3 points).  Returns 1 on success,
 * 0 on failure (the original then makes nothing). */
static int core(Pt *P, int n, Sink *k)
{
    int i, j;

    if (n < 2) return 0;                                   /* asm 7264da */
    if (same_pt(P[1], P[2])) return 0;                     /* asm 7268bb: silent 0 */
    {   /* all points on the line P1P2? (asm 726941..726bee) */
        Frame f0; int allcol = 1;
        frame_set(&f0, P[1], P[2]);
        for (i = 3; i <= n; i++)
            if (fabs(f_cross(&f0, P[i])) > EPS) { allcol = 0; break; }
        if (allcol) {
            for (i = 3; i <= n; i++) {
                double v = f_proj(&f0, P[i]);
                if (v < f_proj(&f0, P[1])) P[1] = P[i];
                if (f_proj(&f0, P[2]) < v) P[2] = P[i];
            }
            n = 2;
        }
    }
    if (n < 5) {                                           /* asm 726bf1 */
        Pt A = P[1], B = P[2], C = P[2], D = P[2];
        if (n == 3) { C = P[3]; D = P[3]; }
        if (n == 4) { C = P[3]; D = P[4]; }
        emit(k, A, B, C, D);
        return *k->nout > 0;
    }
    /* ---- n >= 5 (closed list of four or more) ---- asm 726ef4 */
    if (same_pt(P[n], P[1])) n--;                          /* drop the closing point */
    P[n + 1] = P[1];                                       /* asm 726f94 */
    P[n + 2] = P[2];                                       /* asm 726fe3 */
    {
        int sgn = 0, mixed = 0, orient = 0;
        double sum = 0.0;
        for (i = 1; i <= n; i++) {
            double cr = (P[i + 1].x - P[i].x) * (P[i + 2].y - P[i].y)
                      - (P[i + 2].x - P[i].x) * (P[i + 1].y - P[i].y);
            Frame f; double xl, yl, ang;
            if (cr > EPS)  { if (sgn == 0) sgn = 1;  if (sgn < 0) mixed = 1; }
            if (cr < -EPS) { if (sgn == 0) sgn = -1; if (sgn > 0) mixed = 1; }
            frame_set(&f, P[i], P[i + 1]);                 /* FUN_005f8940 */
            f.ox = P[i + 1].x; f.oy = P[i + 1].y;          /* origin overwritten with P[i+1] */
            xl = (P[i + 2].x - f.ox) * f.c + (P[i + 2].y - f.oy) * f.s;   /* FUN_005f92e0 */
            yl = (P[i + 2].y - f.oy) * f.c - (P[i + 2].x - f.ox) * f.s;
            if (fabs(xl) < EPS && fabs(yl) < EPS) ang = 0.0; else ang = atan2(yl, xl);
            sum += ang;                                    /* FUN_008f8d00 = atan2(y,x) */
        }
        if (!mixed) {
            /* convex (either orientation): quads from the outside in */
            int kk = (n - 2) / 2, odd = n & 1;
            for (i = 1; i <= kk; i++)
                emit(k, P[i], P[i + 1], P[n - i], P[n - i + 1]);
            if (odd)
                emit(k, P[kk + 1], P[kk + 2], P[kk + 3], P[kk + 3]);
        } else {
            int iter = 0;
            orient = sum <= 0.0 ? -1 : 1;
            /* self intersection test (asm 727745..727bf2) */
            for (i = 1; i <= n - 1; i++) {
                int jmax = (i == 1) ? n - 1 : n;
                for (j = i + 2; j <= jmax; j++) {
                    Pt I; Frame fa; double t;
                    if (seg_inter(P[i], P[i + 1], P[j], P[j + 1], &I) != 1) continue;
                    frame_set(&fa, P[j], P[j + 1]);
                    t = f_proj(&fa, I);
                    if (t < -EPS || t > fa.len + EPS) continue;
                    frame_set(&fa, P[i], P[i + 1]);
                    t = f_proj(&fa, I);
                    if (t < -EPS || t > fa.len + EPS) continue;
                    return 0;                              /* message 0x149e */
                }
            }
            if (orient < 0) {                              /* make it counter-clockwise */
                for (i = 1; i <= n / 2; i++) { Pt t = P[i]; P[i] = P[n - i + 1]; P[n - i + 1] = t; }
                P[n + 1] = P[1];
            }
            /* ear clipping (asm 727cac..728523) */
            for (;;) {
                Frame f; double cr;
                iter++;
                if (iter > 2 * n) return 0;                /* message 0x1455 */
                frame_set(&f, P[1], P[2]);
                cr = f_cross(&f, P[3]);
                if (fabs(cr) <= EPS) {                     /* collinear: drop P2 */
                    n--;
                    for (i = 2; i <= n; i++) P[i] = P[i + 1];
                    P[n + 1] = P[1];
                    if (n < 3) break;
                    iter = 0; continue;
                }
                if (cr < 0) goto rotate;                   /* reflex vertex */
                {   /* convex vertex: validate the diagonal P1P3 */
                    Frame f2; int ok = 1;
                    frame_set(&f2, P[1], P[3]);
                    for (j = 4; j <= n; j++) {
                        Pt I;
                        if (f_cross(&f2, P[j]) > -EPS) continue;
                        if (j >= n) { ok = 0; break; }
                        if (seg_inter(P[1], P[3], P[j], P[j + 1], &I) == 1) { ok = 0; break; }
                    }
                    if (!ok) goto rotate;
                    emit(k, P[1], P[2], P[3], P[3]);       /* triangle [P1 P2 P3 P3] */
                    n--;
                    for (i = 2; i <= n; i++) P[i] = P[i + 1];
                    P[n + 1] = P[1];
                    if (n < 3) break;
                    iter = 0; continue;
                }
            rotate:
                for (i = 1; i <= n; i++) P[i] = P[i + 1];  /* rotate the list left by one */
                P[n + 1] = P[1];
            }
        }
    }
    return *k->nout > 0;                                   /* asm 728523: 0 solids = failure */
}

/* Open vertex list (n points) -> solid point lists.  Includes the closing done by
 * FUN_007255f0 (n>2: P[n+1]=P[1], count n+1).  On failure *nout = 0. */
void tk_decompose(const double *x, const double *y, int n, double out[][8], int *nout)
{
    static Pt P[TK_MAX + 8];
    Sink k;
    int i, m;

    *nout = 0;
    if (n < 1 || n > 1000) return;
    for (i = 0; i < n; i++) { P[i + 1].x = x[i]; P[i + 1].y = y[i]; }
    m = n;
    if (n > 2) { m = n + 1; P[m] = P[1]; }
    k.out = out; k.nout = nout;
    if (!core(P, m, &k)) *nout = 0;
}

