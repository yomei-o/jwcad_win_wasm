
/* 14004aee0  EPATHOBJ::bPolyBezierTo  140 bytes, 1 callers */

/* public: bool __cdecl EPATHOBJ::bPolyBezierTo(class EXFORMOBJR const * __ptr64,class
   umptr_r<struct _POINTL> const & __ptr64,unsigned long) __ptr64 */

bool __thiscall
EPATHOBJ::bPolyBezierTo(EPATHOBJ *this,EXFORMOBJR *param_1,umptr_r<_POINTL> *param_2,ulong param_3)

{
  bool bVar1;
  undefined8 local_40;
  undefined8 uStack_38;
  undefined8 local_30;
  undefined2 local_28;
  undefined4 local_20;
  undefined4 uStack_1c;
  
  uStack_1c = (undefined4)param_3;
  if (*(long *)(this + 8) == 0) {
    bVar1 = false;
  }
  else {
    local_40 = *(undefined8 *)param_2;
    uStack_38 = *(undefined8 *)(param_2 + 8);
    local_30 = *(undefined8 *)(param_2 + 0x10);
    local_28 = *(undefined2 *)(param_2 + 0x18);
    local_20 = 0x10;
    bVar1 = PATH_CORE::addpoints
                      ((PATH_CORE *)(*(long *)(this + 8) + 0x18),param_1,(PATHDATAL *)&local_40);
    if (bVar1) {
      *(uint *)this = *(uint *)this & 0xfffffffc | 1;
      *(int *)(this + 4) = *(int *)(this + 4) + (int)((param_3 & 0xffffffff) / 3);
    }
  }
  return bVar1;
}



/* 14004b590  PATHOBJ_bPolyBezierTo  60 bytes, 0 callers */

bool PATHOBJ_bPolyBezierTo(EPATHOBJ *param_1,undefined8 param_2,ulong param_3)

{
  bool bVar1;
  undefined8 local_20;
  ulong uStack_18;
  undefined8 local_10;
  undefined2 local_8;
  
  uStack_18 = param_3 & 0xffffffff;
  local_10 = 0;
  local_8 = 0;
  local_20 = param_2;
  bVar1 = EPATHOBJ::bPolyBezierTo
                    (param_1,(EXFORMOBJR *)0x0,(umptr_r<_POINTL> *)&local_20,param_3 & 0xffffffff);
  return bVar1;
}



/* 14004c190  PATH_CORE::bPolyBezierTo  68 bytes, 0 callers */

/* public: bool __cdecl PATH_CORE::bPolyBezierTo(class EXFORMOBJR const * __ptr64,class
   umptr_r<struct _POINTL> const & __ptr64,unsigned long) __ptr64 */

bool __thiscall
PATH_CORE::bPolyBezierTo
          (PATH_CORE *this,EXFORMOBJR *param_1,umptr_r<_POINTL> *param_2,ulong param_3)

{
  bool bVar1;
  undefined8 local_30;
  undefined8 uStack_28;
  undefined8 local_20;
  undefined2 local_18;
  undefined4 local_10;
  undefined4 uStack_c;
  
                    /* 0x4c190  484
                       ?bPolyBezierTo@PATH_CORE@@QEAA_NPEBVEXFORMOBJR@@AEBV?$umptr_r@U_POINTL@@@@K@Z
                        */
  uStack_c = (undefined4)param_3;
  local_30 = *(undefined8 *)param_2;
  uStack_28 = *(undefined8 *)(param_2 + 8);
  local_20 = *(undefined8 *)(param_2 + 0x10);
  local_18 = *(undefined2 *)(param_2 + 0x18);
  local_10 = 0x10;
  bVar1 = addpoints(this,param_1,(PATHDATAL *)&local_30);
  return bVar1;
}



/* 1400719d0  EPATHOBJ::bFlatten  124 bytes, 1 callers */

/* public: bool __cdecl EPATHOBJ::bFlatten(void) __ptr64 */

bool __thiscall EPATHOBJ::bFlatten(EPATHOBJ *this)

{
  long lVar1;
  bool bVar2;
  long *plVar3;
  
  if (*(long *)(this + 8) == 0) {
LAB_140071a44:
    bVar2 = false;
  }
  else {
    for (plVar3 = *(long **)(*(long *)(this + 8) + 0x20); plVar3 != (long *)0x0;
        plVar3 = (long *)*plVar3) {
      if ((*(uint *)(plVar3 + 2) >> 4 & 1) != 0) {
        lVar1 = 0;
        if (*(long *)(this + 8) != 0) {
          lVar1 = *(long *)(this + 8) + 0x18;
        }
        plVar3 = (long *)pprFlattenRec(this + 4,lVar1,plVar3);
        if (plVar3 == (long *)0x0) goto LAB_140071a44;
      }
    }
    bVar2 = true;
    *(uint *)this = *(uint *)this & 0xfffffffe;
  }
  return bVar2;
}



/* 140071a50  BEZIER32::bInit  728 bytes, 1 callers */

/* public: int __cdecl BEZIER32::bInit(struct _POINTFIX * __ptr64,struct _RECTFX * __ptr64) __ptr64
    */

int __thiscall BEZIER32::bInit(BEZIER32 *this,_POINTFIX *param_1,_RECTFX *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  undefined8 *extraout_x0;
  uint uVar13;
  ulong uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  int *piVar18;
  int *extraout_x10;
  int *piVar19;
  int *extraout_x11;
  int *extraout_x12;
  int *piVar20;
  int *extraout_x12_00;
  
  *(undefined4 *)this = 1;
  uVar14 = 0;
  vBoundBox(param_1,(_RECTFX *)(this + 0x24));
  iVar16 = extraout_x12[9];
  iVar15 = extraout_x12[10];
  uVar13 = (int)*extraout_x0 - iVar16;
  uVar5 = (int)extraout_x0[1] - iVar16;
  uVar6 = (int)extraout_x0[2] - iVar16;
  uVar7 = (int)extraout_x0[3] - iVar16;
  uVar8 = (int)((ulong)*extraout_x0 >> 0x20) - iVar15;
  uVar9 = (int)((ulong)extraout_x0[1] >> 0x20) - iVar15;
  uVar10 = (int)((ulong)extraout_x0[2] >> 0x20) - iVar15;
  uVar11 = (int)((ulong)extraout_x0[3] >> 0x20) - iVar15;
  if (((uVar11 | uVar10 | uVar9 | uVar8 | uVar7 | uVar6 | uVar5 | uVar13) & 0xffffc000) != 0) {
    return 0;
  }
  extraout_x12[1] = uVar13 * 0x400;
  extraout_x12[2] = (uVar7 - uVar13) * 0x400;
  extraout_x12[3] = (uVar5 + uVar6 * -2 + uVar7) * 0x1800;
  extraout_x12[4] = (uVar13 + uVar5 * -2 + uVar6) * 0x1800;
  extraout_x12[5] = uVar8 * 0x400;
  extraout_x12[6] = (uVar11 - uVar8) * 0x400;
  extraout_x12[7] = (uVar9 + uVar10 * -2 + uVar11) * 0x1800;
  extraout_x12[8] = (uVar8 + uVar9 * -2 + uVar10) * 0x1800;
  piVar20 = extraout_x12;
  if (param_2 != (_RECTFX *)0x0) {
    bVar12 = bIntersect((_RECTFX *)(extraout_x12 + 9),param_2);
    uVar13 = (uint)uVar14;
    piVar18 = extraout_x10;
    piVar19 = extraout_x11;
    piVar20 = extraout_x12_00;
    if (!bVar12) goto LAB_140071bb8;
  }
  iVar16 = piVar20[7];
  iVar15 = piVar20[8];
  do {
    iVar2 = piVar20[3];
    iVar3 = piVar20[4];
    uVar13 = (uint)uVar14;
    iVar4 = 0xffc0 << (ulong)(uVar13 & 0x1f);
    iVar17 = -iVar2;
    if (-1 < iVar2) {
      iVar17 = iVar2;
    }
    iVar1 = -iVar3;
    if (-1 < iVar3) {
      iVar1 = iVar3;
    }
    if (iVar1 < iVar17) {
      iVar17 = -iVar2;
      if (-1 < iVar2) {
        iVar17 = iVar2;
      }
    }
    else {
      iVar17 = -iVar3;
      if (-1 < iVar3) {
        iVar17 = iVar3;
      }
    }
    if (iVar17 <= iVar4) {
      iVar17 = -iVar15;
      if (-1 < iVar15) {
        iVar17 = iVar15;
      }
      iVar1 = -iVar16;
      if (-1 < iVar16) {
        iVar1 = iVar16;
      }
      if (iVar17 < iVar1) {
        iVar17 = -iVar16;
        if (-1 < iVar16) {
          iVar17 = iVar16;
        }
      }
      else {
        iVar17 = -iVar15;
        if (-1 < iVar15) {
          iVar17 = iVar15;
        }
      }
      if (iVar17 <= iVar4) break;
    }
    iVar17 = iVar2 + iVar3 >> 1;
    uVar13 = uVar13 + 2;
    uVar14 = (ulong)uVar13;
    piVar20[3] = iVar17;
    iVar16 = iVar15 + iVar16 >> 1;
    piVar20[2] = piVar20[2] - (iVar17 >> (uVar13 & 0x1f)) >> 1;
    piVar20[6] = piVar20[6] - (iVar16 >> (uVar13 & 0x1f)) >> 1;
    piVar20[7] = iVar16;
    *piVar20 = *piVar20 << 1;
  } while( true );
  piVar19 = piVar20 + 1;
  piVar18 = piVar20 + 5;
LAB_140071bb8:
  piVar20[1] = piVar20[1] << 3;
  piVar20[2] = piVar20[2] << 3;
  uVar5 = uVar13 - 3;
  if ((int)uVar5 < 0) {
    iVar16 = piVar20[4] << (ulong)(-uVar5 & 0x1f);
    iVar15 = piVar20[3] << (ulong)(-uVar5 & 0x1f);
  }
  else {
    iVar16 = piVar20[4] >> (uVar5 & 0x1f);
    iVar15 = piVar20[3] >> (uVar5 & 0x1f);
  }
  piVar20[3] = iVar15;
  piVar20[4] = iVar16;
  piVar20[5] = piVar20[5] << 3;
  piVar20[6] = piVar20[6] << 3;
  uVar13 = uVar13 - 3;
  if ((int)uVar13 < 0) {
    iVar16 = piVar20[8] << (ulong)(-uVar13 & 0x1f);
    iVar15 = piVar20[7] << (ulong)(-uVar13 & 0x1f);
  }
  else {
    iVar16 = piVar20[8] >> (uVar13 & 0x1f);
    iVar15 = piVar20[7] >> (uVar13 & 0x1f);
  }
  piVar20[7] = iVar15;
  piVar20[8] = iVar16;
  iVar16 = piVar19[2];
  *piVar19 = piVar19[1] + *piVar19;
  piVar19[1] = piVar19[1] + iVar16;
  piVar19[2] = iVar16 * 2 - piVar19[3];
  piVar19[3] = iVar16;
  iVar16 = piVar18[2];
  *piVar18 = piVar18[1] + *piVar18;
  piVar18[1] = piVar18[1] + iVar16;
  piVar18[2] = iVar16 * 2 - piVar18[3];
  piVar18[3] = iVar16;
  *piVar20 = *piVar20 + -1;
  return 1;
}



/* 140071d30  BEZIER32::bNext  592 bytes, 1 callers */

/* public: int __cdecl BEZIER32::bNext(struct _POINTFIX * __ptr64) __ptr64 */

int __thiscall BEZIER32::bNext(BEZIER32 *this,_POINTFIX *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  long lVar7;
  uint uVar8;
  uint extraout_w1;
  uint extraout_w1_00;
  int iVar9;
  int extraout_w12;
  int extraout_w13;
  int extraout_w13_00;
  int iVar10;
  
  *(int *)param_1 = *(int *)(this + 0x24) + (*(int *)(this + 4) + 0x1000 >> 0xd);
  *(int *)(param_1 + 4) = *(int *)(this + 0x28) + (*(int *)(this + 0x14) + 0x1000 >> 0xd);
  if (*(int *)this == 0) {
    iVar10 = 0;
  }
  else {
    iVar2 = *(int *)(this + 0xc);
    iVar4 = *(int *)(this + 0x10);
    iVar10 = -iVar4;
    if (-1 < iVar4) {
      iVar10 = iVar4;
    }
    iVar9 = -iVar2;
    if (-1 < iVar2) {
      iVar9 = iVar2;
    }
    if (iVar10 < iVar9) {
      iVar10 = -iVar2;
      if (-1 < iVar2) {
        iVar10 = iVar2;
      }
    }
    else {
      iVar10 = -iVar4;
      if (-1 < iVar4) {
        iVar10 = iVar4;
      }
    }
    iVar3 = *(int *)(this + 0x1c);
    iVar5 = *(int *)(this + 0x20);
    iVar9 = -iVar3;
    if (-1 < iVar3) {
      iVar9 = iVar3;
    }
    iVar1 = -iVar5;
    if (-1 < iVar5) {
      iVar1 = iVar5;
    }
    if (iVar1 < iVar9) {
      iVar9 = -iVar3;
      if (-1 < iVar3) {
        iVar9 = iVar3;
      }
    }
    else {
      iVar9 = -iVar5;
      if (-1 < iVar5) {
        iVar9 = iVar5;
      }
    }
    if (iVar9 < iVar10) {
      iVar10 = -iVar2;
      if (-1 < iVar2) {
        iVar10 = iVar2;
      }
      iVar9 = -iVar4;
      if (-1 < iVar4) {
        iVar9 = iVar4;
      }
      if (iVar9 < iVar10) {
        iVar10 = -iVar2;
        if (-1 < iVar2) {
          iVar10 = iVar2;
        }
      }
      else {
        iVar10 = -iVar4;
        if (-1 < iVar4) {
          iVar10 = iVar4;
        }
      }
    }
    else {
      iVar10 = -iVar3;
      if (-1 < iVar3) {
        iVar10 = iVar3;
      }
      iVar9 = -iVar5;
      if (-1 < iVar5) {
        iVar9 = iVar5;
      }
      if (iVar9 < iVar10) {
        iVar10 = -iVar3;
        if (-1 < iVar3) {
          iVar10 = iVar3;
        }
      }
      else {
        iVar10 = -iVar5;
        if (-1 < iVar5) {
          iVar10 = iVar5;
        }
      }
    }
    if (0x7fe00 < iVar10) {
      iVar10 = iVar4 + iVar2 >> 3;
      *(int *)(this + 0xc) = iVar10;
      *(int *)(this + 8) = *(int *)(this + 8) - iVar10 >> 1;
      *(int *)(this + 0x10) = iVar4 >> 2;
      iVar10 = iVar5 + iVar3 >> 3;
      *(int *)(this + 0x18) = *(int *)(this + 0x18) - iVar10 >> 1;
      *(int *)(this + 0x1c) = iVar10;
      *(int *)(this + 0x20) = iVar5 >> 2;
      *(int *)this = *(int *)this << 1;
    }
    uVar8 = *(uint *)this;
    while ((((uVar8 & 1) == 0 &&
            (lVar7 = HFDBASIS32::lParentErrorDividedBy4((HFDBASIS32 *)(this + 4)),
            uVar8 = extraout_w1, (int)lVar7 <= extraout_w13)) &&
           (lVar7 = HFDBASIS32::lParentErrorDividedBy4((HFDBASIS32 *)(this + 0x14)),
           uVar8 = extraout_w1_00, (int)lVar7 <= extraout_w13_00))) {
      uVar8 = extraout_w12 >> 1;
      uVar6 = *(uint *)(this + 0x10);
      *(uint *)(this + 0x10) = uVar6 * 4;
      *(uint *)(this + 8) = *(uint *)(this + 0xc) + *(uint *)(this + 8) * 2;
      *(uint *)(this + 0xc) = *(uint *)(this + 0xc) * 8 + uVar6 * -4;
      uVar6 = *(uint *)(this + 0x20);
      *(uint *)(this + 0x20) = uVar6 * 4;
      *(uint *)(this + 0x18) = *(uint *)(this + 0x1c) + *(uint *)(this + 0x18) * 2;
      *(uint *)(this + 0x1c) = *(uint *)(this + 0x1c) * 8 + uVar6 * -4;
      *(uint *)this = uVar8;
    }
    *(uint *)this = uVar8 - 1;
    iVar10 = 1;
    uVar8 = *(uint *)(this + 0xc);
    *(uint *)(this + 4) = *(uint *)(this + 8) + *(uint *)(this + 4);
    *(uint *)(this + 8) = *(uint *)(this + 8) + uVar8;
    *(uint *)(this + 0xc) = uVar8 * 2 - *(uint *)(this + 0x10);
    *(uint *)(this + 0x10) = uVar8;
    uVar8 = *(uint *)(this + 0x1c);
    *(uint *)(this + 0x14) = *(uint *)(this + 0x18) + *(uint *)(this + 0x14);
    *(uint *)(this + 0x18) = *(uint *)(this + 0x18) + uVar8;
    *(uint *)(this + 0x1c) = uVar8 * 2 - *(uint *)(this + 0x20);
    *(uint *)(this + 0x20) = uVar8;
  }
  return iVar10;
}



/* 140071f80  BEZIER64::bNext  1500 bytes, 1 callers */

/* public: int __cdecl BEZIER64::bNext(struct _POINTFIX * __ptr64) __ptr64 */

int __thiscall BEZIER64::bNext(BEZIER64 *this,_POINTFIX *param_1)

{
  long lVar1;
  uint uVar2;
  bool bVar3;
  HFDBASIS64 *pHVar4;
  HFDBASIS64 *pHVar5;
  HFDBASIS64 *pHVar6;
  HFDBASIS64 *pHVar7;
  HFDBASIS64 *pHVar8;
  long lVar9;
  int iVar10;
  long lVar11;
  _RECTFX *extraout_x12;
  long lVar12;
  long lVar13;
  long lVar14;
  long lVar15;
  long *extraout_x14;
  long *extraout_x14_00;
  long extraout_x15;
  __int64 local_50;
  undefined8 uStack_48;
  undefined1 local_40 [8];
  int local_38;
  int iStack_34;
  int local_30;
  int iStack_2c;
  int local_28;
  int local_24;
  
  uStack_48 = 0;
  local_50 = 0;
  if (*(int *)(this + 0xa4) == 0) {
    HFDBASIS64::vUntransform((HFDBASIS64 *)(this + 0x40),(long *)local_40);
    HFDBASIS64::vUntransform((HFDBASIS64 *)(this + 0x60),(long *)(local_40 + 4));
    lVar13 = (long)(int)local_40._0_4_;
    lVar14 = (long)(int)local_40._4_4_;
    *(long *)this = lVar13 << 0x1c;
    *(long *)(this + 8) = (local_28 - lVar13) * 0x10000000;
    *(long *)(this + 0x10) = ((long)local_28 + (long)local_30 * -2 + (long)local_38) * 0x60000000;
    *(long *)(this + 0x18) = (lVar13 + (long)local_38 * -2 + (long)local_30) * 0x60000000;
    *(long *)(this + 0x20) = lVar14 << 0x1c;
    *(long *)(this + 0x28) = (local_24 - lVar14) * 0x10000000;
    *(long *)(this + 0x30) = ((long)local_24 + (long)iStack_2c * -2 + (long)iStack_34) * 0x60000000;
    *(long *)(this + 0x38) = (lVar14 + (long)iStack_34 * -2 + (long)iStack_2c) * 0x60000000;
    *(undefined4 *)(this + 0xa4) = 1;
    if (*(long *)(this + 0x88) == 0) {
LAB_140072064:
      lVar13 = *(long *)(this + 0x30);
      lVar14 = *(long *)(this + 0x38);
      iVar10 = 1;
      do {
        lVar12 = *(long *)(this + 0x10);
        lVar9 = *(long *)(this + 0x18);
        lVar15 = -lVar12;
        if (-1 < lVar12) {
          lVar15 = lVar12;
        }
        lVar1 = -lVar9;
        if (-1 < lVar9) {
          lVar1 = lVar9;
        }
        if (lVar1 < lVar15) {
          lVar15 = -lVar12;
          if (-1 < lVar12) {
            lVar15 = lVar12;
          }
        }
        else {
          lVar15 = -lVar9;
          if (-1 < lVar9) {
            lVar15 = lVar9;
          }
        }
        if (lVar15 <= *(long *)(this + 0x80)) {
          lVar15 = -lVar14;
          if (-1 < lVar14) {
            lVar15 = lVar14;
          }
          lVar1 = -lVar13;
          if (-1 < lVar13) {
            lVar1 = lVar13;
          }
          if (lVar15 < lVar1) {
            lVar15 = -lVar13;
            if (-1 < lVar13) {
              lVar15 = lVar13;
            }
          }
          else {
            lVar15 = -lVar14;
            if (-1 < lVar14) {
              lVar15 = lVar14;
            }
          }
          if (lVar15 <= *(long *)(this + 0x80)) goto LAB_140072128;
        }
        iVar10 = iVar10 << 1;
        lVar15 = lVar12 + lVar9 >> 3;
        *(int *)(this + 0xa4) = iVar10;
        lVar13 = lVar14 + lVar13 >> 3;
        lVar14 = lVar14 >> 2;
        *(long *)(this + 8) = *(long *)(this + 8) - lVar15 >> 1;
        *(long *)(this + 0x10) = lVar15;
        *(long *)(this + 0x18) = lVar9 >> 2;
        *(long *)(this + 0x28) = *(long *)(this + 0x28) - lVar13 >> 1;
        *(long *)(this + 0x30) = lVar13;
        *(long *)(this + 0x38) = lVar14;
      } while( true );
    }
    vBoundBox((_POINTFIX *)local_40,(_RECTFX *)&local_50);
    bVar3 = bIntersect((_RECTFX *)&local_50,extraout_x12);
    if (bVar3) goto LAB_140072064;
LAB_140072128:
    iVar10 = *(int *)(this + 0xa0);
    *(int *)(this + 0xa0) = iVar10 + -1;
    if (iVar10 + -1 == 0) goto LAB_1400722f0;
    lVar13 = *(long *)(this + 0x50);
    *(long *)(this + 0x40) = *(long *)(this + 0x48) + *(long *)(this + 0x40);
    *(long *)(this + 0x48) = lVar13 + *(long *)(this + 0x48);
    *(long *)(this + 0x50) = lVar13 * 2 - *(long *)(this + 0x58);
    *(long *)(this + 0x58) = lVar13;
    lVar13 = *(long *)(this + 0x70);
    *(long *)(this + 0x60) = *(long *)(this + 0x68) + *(long *)(this + 0x60);
    *(long *)(this + 0x68) = lVar13 + *(long *)(this + 0x68);
    lVar12 = lVar13 * 2 - *(long *)(this + 0x78);
    *(long *)(this + 0x70) = lVar12;
    *(long *)(this + 0x78) = lVar13;
    lVar14 = *(long *)(this + 0x50);
    lVar15 = *(long *)(this + 0x58);
    lVar13 = -lVar15;
    if (-1 < lVar15) {
      lVar13 = lVar15;
    }
    lVar9 = -lVar14;
    if (-1 < lVar14) {
      lVar9 = lVar14;
    }
    if (lVar13 < lVar9) {
      local_50 = -lVar14;
      if (-1 < lVar14) {
        local_50 = lVar14;
      }
    }
    else {
      local_50 = -lVar15;
      if (-1 < lVar15) {
        local_50 = lVar15;
      }
    }
    lVar13 = 0x300000000000;
    if (local_50 < 0x300000000001) {
      lVar9 = -lVar12;
      if (-1 < lVar12) {
        lVar9 = lVar12;
      }
      lVar11 = *(long *)(this + 0x78);
      lVar1 = -lVar11;
      if (-1 < lVar11) {
        lVar1 = lVar11;
      }
      if (lVar1 < lVar9) {
        local_50 = -lVar12;
        if (-1 < lVar12) {
          local_50 = lVar12;
        }
      }
      else {
        local_50 = -lVar11;
        if (-1 < lVar11) {
          local_50 = lVar11;
        }
      }
      if (0x300000000000 < local_50) goto LAB_140072214;
    }
    else {
LAB_140072214:
      *(int *)(this + 0xa0) = *(int *)(this + 0xa0) << 1;
      lVar14 = lVar15 + lVar14 >> 3;
      *(long *)(this + 0x48) = *(long *)(this + 0x48) - lVar14 >> 1;
      *(long *)(this + 0x50) = lVar14;
      *(long *)(this + 0x58) = lVar15 >> 2;
      lVar15 = *(long *)(this + 0x78);
      lVar14 = lVar15 + *(long *)(this + 0x70) >> 3;
      *(long *)(this + 0x68) = *(long *)(this + 0x68) - lVar14 >> 1;
      *(long *)(this + 0x70) = lVar14;
      *(long *)(this + 0x78) = lVar15 >> 2;
    }
    uVar2 = *(uint *)(this + 0xa0);
    while ((((uVar2 & 1) == 0 &&
            (HFDBASIS64::vParentError((HFDBASIS64 *)(this + 0x40),&local_50), local_50 <= lVar13))
           && (HFDBASIS64::vParentError((HFDBASIS64 *)(this + 0x60),&local_50), local_50 <= lVar13))
          ) {
      lVar14 = *(long *)(this + 0x58);
      *(long *)(this + 0x58) = lVar14 * 4;
      *(long *)(this + 0x48) = *(long *)(this + 0x50) + *(long *)(this + 0x48) * 2;
      *(long *)(this + 0x50) = *(long *)(this + 0x50) * 8 + lVar14 * -4;
      lVar14 = *(long *)(this + 0x68);
      lVar15 = *(long *)(this + 0x70);
      lVar12 = *extraout_x14;
      *extraout_x14 = lVar12 * 4;
      *(long *)(this + 0x68) = lVar15 + lVar14 * 2;
      *(long *)(this + 0x70) = lVar15 * 8 + lVar12 * -4;
      uVar2 = *(int *)(this + 0xa0) >> 1;
      *(uint *)(this + 0xa0) = uVar2;
    }
  }
LAB_1400722f0:
  lVar13 = *(long *)(this + 0x10);
  *(long *)this = *(long *)(this + 8) + *(long *)this;
  *(long *)(this + 8) = *(long *)(this + 8) + lVar13;
  *(long *)(this + 0x10) = lVar13 * 2 - *(long *)(this + 0x18);
  *(long *)(this + 0x18) = lVar13;
  lVar13 = *(long *)(this + 0x30);
  *(long *)(this + 0x20) = *(long *)(this + 0x28) + *(long *)(this + 0x20);
  *(long *)(this + 0x28) = lVar13 + *(long *)(this + 0x28);
  *(long *)(this + 0x30) = lVar13 * 2 - *(long *)(this + 0x38);
  *(long *)(this + 0x38) = lVar13;
  *(int *)param_1 = (int)(*(long *)this + 0x8000000 >> 0x1c);
  *(int *)(param_1 + 4) = (int)(*(long *)(this + 0x20) + 0x8000000 >> 0x1c);
  iVar10 = *(int *)(this + 0xa4) + -1;
  *(int *)(this + 0xa4) = iVar10;
  if ((iVar10 == 0) && (*(int *)(this + 0xa0) == 0)) {
    return 0;
  }
  lVar14 = *(long *)(this + 0x10);
  lVar15 = *(long *)(this + 0x18);
  lVar13 = -lVar14;
  if (-1 < lVar14) {
    lVar13 = lVar14;
  }
  lVar12 = -lVar15;
  if (-1 < lVar15) {
    lVar12 = lVar15;
  }
  if (lVar12 < lVar13) {
    local_50 = -lVar14;
    if (-1 < lVar14) {
      local_50 = lVar14;
    }
  }
  else {
    local_50 = -lVar15;
    if (-1 < lVar15) {
      local_50 = lVar15;
    }
  }
  if (local_50 <= *(long *)(this + 0x80)) {
    lVar12 = *(long *)(this + 0x30);
    local_50 = *(__int64 *)(this + 0x38);
    lVar13 = -lVar12;
    if (-1 < lVar12) {
      lVar13 = lVar12;
    }
    lVar9 = -local_50;
    if (-1 < local_50) {
      lVar9 = local_50;
    }
    if (lVar9 < lVar13) {
      local_50 = -lVar12;
      if (-1 < lVar12) {
        local_50 = lVar12;
      }
    }
    else if (local_50 < 0) {
      local_50 = -local_50;
    }
    if (local_50 <= *(long *)(this + 0x80)) goto LAB_1400724ac;
  }
  lVar13 = lVar14 + lVar15 >> 3;
  *(int *)(this + 0xa4) = iVar10 * 2;
  *(long *)(this + 0x10) = lVar13;
  *(long *)(this + 8) = *(long *)(this + 8) - lVar13 >> 1;
  *(long *)(this + 0x18) = lVar15 >> 2;
  lVar14 = *(long *)(this + 0x38);
  lVar13 = lVar14 + *(long *)(this + 0x30) >> 3;
  *(long *)(this + 0x30) = lVar13;
  *(long *)(this + 0x28) = *(long *)(this + 0x28) - lVar13 >> 1;
  *(long *)(this + 0x38) = lVar14 >> 2;
LAB_1400724ac:
  pHVar8 = (HFDBASIS64 *)(this + 0x30);
  pHVar7 = (HFDBASIS64 *)(this + 0x18);
  pHVar6 = (HFDBASIS64 *)(this + 8);
  pHVar5 = (HFDBASIS64 *)(this + 0x10);
  pHVar4 = (HFDBASIS64 *)(this + 0x80);
  uVar2 = *(uint *)(this + 0xa4);
  while ((((uVar2 & 1) == 0 &&
          (HFDBASIS64::vParentError((HFDBASIS64 *)this,&local_50), local_50 <= *(long *)pHVar4)) &&
         (HFDBASIS64::vParentError((HFDBASIS64 *)(this + 0x20),&local_50), local_50 <= extraout_x15)
         )) {
    lVar14 = *(long *)pHVar5;
    *(long *)pHVar6 = lVar14 + *(long *)pHVar6 * 2;
    lVar13 = *(long *)pHVar7;
    *(long *)pHVar7 = lVar13 * 4;
    *(long *)pHVar5 = lVar14 * 8 + lVar13 * -4;
    lVar14 = *(long *)pHVar8;
    *(long *)(this + 0x28) = lVar14 + *(long *)(this + 0x28) * 2;
    lVar13 = *extraout_x14_00;
    *extraout_x14_00 = lVar13 * 4;
    *(long *)pHVar8 = lVar14 * 8 + lVar13 * -4;
    uVar2 = *(int *)(this + 0xa4) >> 1;
    *(uint *)(this + 0xa4) = uVar2;
  }
  return 1;
}



/* 140072a20  BEZIER64::vInit  380 bytes, 1 callers */

/* public: void __cdecl BEZIER64::vInit(struct _POINTFIX * __ptr64,struct _RECTFX * __ptr64,__int64
   const * __ptr64) __ptr64 */

void __thiscall BEZIER64::vInit(BEZIER64 *this,_POINTFIX *param_1,_RECTFX *param_2,__int64 *param_3)

{
  long lVar1;
  long lVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  BEZIER64 *pBVar7;
  long lVar8;
  long lVar9;
  long lVar10;
  undefined8 uVar11;
  
                    /* 0x72a20  903  ?vInit@BEZIER64@@QEAAXPEAU_POINTFIX@@PEAU_RECTFX@@PEB_J@Z */
  *(undefined8 *)(this + 0xa0) = 1;
  iVar6 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0x10);
  iVar5 = *(int *)(param_1 + 8);
  lVar9 = (long)*(int *)param_1;
  *(long *)(this + 0x40) = lVar9 << 0x1c;
  *(long *)(this + 0x48) = (iVar6 - lVar9) * 0x10000000;
  *(long *)(this + 0x50) = ((long)iVar6 + (long)iVar4 * -2 + (long)iVar5) * 0x60000000;
  *(long *)(this + 0x58) = (lVar9 + (long)iVar5 * -2 + (long)iVar4) * 0x60000000;
  iVar4 = *(int *)(param_1 + 0x14);
  iVar6 = *(int *)(param_1 + 0x1c);
  iVar5 = *(int *)(param_1 + 0xc);
  lVar9 = (long)*(int *)(param_1 + 4);
  *(long *)(this + 0x60) = lVar9 << 0x1c;
  *(long *)(this + 0x68) = (iVar6 - lVar9) * 0x10000000;
  *(long *)(this + 0x70) = ((long)iVar6 + (long)iVar4 * -2 + (long)iVar5) * 0x60000000;
  *(long *)(this + 0x78) = (lVar9 + (long)iVar5 * -2 + (long)iVar4) * 0x60000000;
  *(__int64 *)(this + 0x80) = *param_3;
  if (param_2 == (_RECTFX *)0x0) {
    pBVar7 = (BEZIER64 *)0x0;
  }
  else {
    uVar11 = *(undefined8 *)param_2;
    pBVar7 = this + 0x90;
    *(undefined8 *)(this + 0x98) = *(undefined8 *)(param_2 + 8);
    *(undefined8 *)(this + 0x90) = uVar11;
  }
  *(BEZIER64 **)(this + 0x88) = pBVar7;
  lVar9 = *(long *)(this + 0x70);
  lVar8 = *(long *)(this + 0x78);
  do {
    lVar2 = *(long *)(this + 0x50);
    lVar3 = *(long *)(this + 0x58);
    lVar10 = -lVar2;
    if (-1 < lVar2) {
      lVar10 = lVar2;
    }
    lVar1 = -lVar3;
    if (-1 < lVar3) {
      lVar1 = lVar3;
    }
    if (lVar1 < lVar10) {
      lVar10 = -lVar2;
      if (-1 < lVar2) {
        lVar10 = lVar2;
      }
    }
    else {
      lVar10 = -lVar3;
      if (-1 < lVar3) {
        lVar10 = lVar3;
      }
    }
    if (lVar10 < 0x300000000001) {
      lVar10 = -lVar9;
      if (-1 < lVar9) {
        lVar10 = lVar9;
      }
      lVar1 = -lVar8;
      if (-1 < lVar8) {
        lVar1 = lVar8;
      }
      if (lVar1 < lVar10) {
        lVar10 = -lVar9;
        if (-1 < lVar9) {
          lVar10 = lVar9;
        }
      }
      else {
        lVar10 = -lVar8;
        if (-1 < lVar8) {
          lVar10 = lVar8;
        }
      }
      if (lVar10 < 0x300000000001) {
        return;
      }
    }
    lVar9 = lVar9 + lVar8 >> 3;
    lVar8 = lVar8 >> 2;
    *(int *)(this + 0xa0) = *(int *)(this + 0xa0) << 1;
    lVar10 = lVar2 + lVar3 >> 3;
    *(long *)(this + 0x48) = *(long *)(this + 0x48) - lVar10 >> 1;
    *(long *)(this + 0x50) = lVar10;
    *(long *)(this + 0x58) = lVar3 >> 2;
    *(long *)(this + 0x68) = *(long *)(this + 0x68) - lVar9 >> 1;
    *(long *)(this + 0x70) = lVar9;
    *(long *)(this + 0x78) = lVar8;
  } while( true );
}



/* 1402347f8  GrePolyBezier  108 bytes, 1 callers */

undefined8 GrePolyBezier(CCrossChannelParentVisualMarshaler *param_1)

{
  long lVar1;
  undefined8 uVar2;
  code *extraout_x15;
  
  lVar1 = W32GetWin32kBaseApiSetTable();
  if (*(long *)(*(long *)(lVar1 + 0x18) + 0x8b0) == 0) {
    uVar2 = 0;
  }
  else {
    DirectComposition::CCrossChannelParentVisualMarshaler::_guard_check_icall(param_1);
    uVar2 = (*extraout_x15)();
  }
  return uVar2;
}


