/* 多角形 任意 の ソリッド分解（原典 FUN_007264a0 の写し。tmp/spec_takaku の SPEC.md） */
#ifndef JW_TAKAKU_H
#define JW_TAKAKU_H
/* 開いた頂点列 n 点 → ソリッドの点の並び（Ax Ay Bx By Cx Cy Dx Dy）を置く順に。out は 1003 行ぶん */
void tk_decompose(const double *x, const double *y, int n, double out[][8], int *nout);
#endif
