
/* 1400f2158  EFLOAT::bIsZero  24 bytes, 15 callers */

/* public: int __cdecl EFLOAT::bIsZero(void)const __ptr64 */

int __thiscall EFLOAT::bIsZero(EFLOAT *this)

{
  if (*(float *)this != 0.0) {
    return 0;
  }
  return 1;
}



/* 14015bae0  EFLOAT::vSqrt  179 bytes, 4 callers */

/* public: void __cdecl EFLOAT::vSqrt(void) __ptr64 */

void __thiscall EFLOAT::vSqrt(EFLOAT *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  ulonglong uVar8;
  
  uVar1 = *(uint *)this >> 0x17 & 0xff;
  uVar7 = *(uint *)this & 0x7fffff | 0x800000;
  uVar6 = 0;
  lVar4 = 0x18;
  uVar5 = uVar1 - 1 & 1;
  uVar8 = (ulonglong)(uVar7 << 8);
  uVar3 = 0;
  if (uVar5 == 0) {
    uVar8 = (ulonglong)(uVar7 << 7);
    uVar3 = 0;
  }
  do {
    uVar7 = uVar6 * 4 + 1;
    uVar2 = (uint)(uVar8 >> 0x1e) | uVar3 * 4;
    uVar8 = (ulonglong)(uint)((int)uVar8 << 2);
    uVar3 = uVar6 * 2;
    uVar6 = uVar3 + 1;
    if (uVar2 < uVar7) {
      uVar6 = uVar3;
    }
    uVar3 = uVar2 - uVar7;
    if (uVar2 < uVar7) {
      uVar3 = uVar2;
    }
    lVar4 = lVar4 + -1;
  } while (lVar4 != 0);
  *(uint *)this = uVar6 & 0x7fffff | (uVar1 + 0x7e + (uVar5 ^ 1) >> 1) << 0x17;
  return;
}



/* 14015bb9c  EFLOAT::bIs1Over16  24 bytes, 1 callers */

/* public: int __cdecl EFLOAT::bIs1Over16(void)const __ptr64 */

int __thiscall EFLOAT::bIs1Over16(EFLOAT *this)

{
  if (*(float *)this != 0.0625) {
    return 0;
  }
  return 1;
}



/* 1401615cc  vArctan  463 bytes, 4 callers */

/* void __cdecl vArctan(class EFLOAT,class EFLOAT,class EFLOAT & __ptr64,long & __ptr64) */

void __cdecl vArctan(float param_1,float param_2,float *param_3,uint *param_4)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  float *pfVar4;
  int iVar5;
  ulonglong uVar6;
  ulonglong uVar7;
  uint uVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  uVar8 = 0;
  bVar1 = 0.0 <= param_1;
  if (bVar1) {
    uVar3 = 2;
  }
  else {
    uVar3 = 3;
    param_1 = -param_1;
  }
  uVar7 = (ulonglong)!bVar1;
  if (param_2 < 0.0) {
    uVar7 = (ulonglong)uVar3;
    param_2 = -param_2;
  }
  fVar11 = param_1;
  if (param_1 < param_2) {
    uVar7 = (ulonglong)((uint)uVar7 | 4);
    fVar11 = param_2;
    param_2 = param_1;
  }
  if (fVar11 == 0.0) {
    *param_3 = *(float *)FP_0_0_exref;
    goto LAB_14016166c;
  }
  fVar11 = (param_2 * *(float *)FP_ARCTAN_TABLE_SIZE_exref) / fVar11;
  uVar3 = (int)fVar11 >> 0x17 & 0xff;
  if (uVar3 < 0x9f) {
    uVar6 = (ulonglong)((uint)fVar11 & 0x7fffff) | 0x800000;
    cVar2 = (char)((int)fVar11 >> 0x17);
    if (uVar3 < 0x76) {
      uVar3 = (uint)((ulonglong)((longlong)uVar6 >> (0x76U - cVar2 & 0x3f)) >> 0x20);
    }
    else {
      uVar3 = (uint)((uVar6 << (cVar2 + 0x8aU & 0x3f)) >> 0x20);
    }
    uVar8 = -uVar3;
    if (-1 < (int)fVar11) {
      uVar8 = uVar3;
    }
  }
  fVar10 = *(float *)(gaefArctan_exref + (longlong)(int)uVar8 * 4);
  *param_3 = *(float *)(gaefArctan_exref + (longlong)(int)uVar8 * 4 + 4);
  fVar9 = *param_3 - fVar10;
  fVar11 = (float)eFraction(fVar11);
  fVar10 = fVar9 * fVar11 + fVar10;
  *param_3 = fVar10;
  iVar5 = (int)uVar7;
  pfVar4 = (float *)FP_180_0_exref;
  if ((iVar5 == 1) || (pfVar4 = (float *)FP_360_0_exref, iVar5 == 2)) {
LAB_140161752:
    *param_3 = *pfVar4 + -fVar10;
  }
  else {
    pfVar4 = (float *)FP_180_0_exref;
    if (iVar5 != 3) {
      pfVar4 = (float *)FP_90_0_exref;
      if (iVar5 == 4) {
        fVar10 = -fVar10;
      }
      else if ((iVar5 != 5) && (pfVar4 = (float *)FP_270_0_exref, iVar5 != 6)) {
        if (iVar5 == 7) goto LAB_140161752;
        goto LAB_14016165d;
      }
    }
    *param_3 = fVar10 + *pfVar4;
  }
LAB_14016165d:
  uVar8 = (uint)(byte)(&DAT_14036fe50)[uVar7 & 0xffffffff];
LAB_14016166c:
  *param_4 = uVar8;
  return;
}



/* 140161904  bPartialArc  735 bytes, 2 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl bPartialArc(enum PARTIALARC,class EPATHOBJ & __ptr64,class EBOX & __ptr64,class
   EPOINTFL & __ptr64,long,class EFLOAT & __ptr64,class EPOINTFL & __ptr64,long,class EFLOAT &
   __ptr64,long) */

int __cdecl
bPartialArc(PARTIALARC param_1,EPATHOBJ *param_2,EBOX *param_3,EPOINTFL *param_4,long param_5,
           EFLOAT *param_6,EPOINTFL *param_7,long param_8,EFLOAT *param_9,long param_10)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  ulonglong uVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined1 auStackY_e8 [32];
  undefined4 local_a0;
  undefined4 local_9c;
  longlong local_98;
  EFLOAT *local_90;
  EPOINTFL *local_88;
  int *local_80;
  undefined8 local_78;
  undefined8 local_70;
  undefined2 local_68;
  int local_60;
  int iStack_5c;
  int local_58;
  int iStack_54;
  int local_50;
  int iStack_4c;
  ulonglong local_48;
  
  local_48 = __security_cookie ^ (ulonglong)auStackY_e8;
  local_88 = param_7;
  local_90 = param_9;
  if (param_10 == 0) {
    uVar7 = bPartialQuadrantArc(param_1,param_2,param_3,param_4,param_6,param_7,param_9);
  }
  else {
    uVar6 = param_5 + 1U & 3;
    uVar11 = (ulonglong)uVar6;
    local_9c = *(undefined4 *)(gaefAxisCoord_exref + uVar11 * 4);
    local_a0 = *(undefined4 *)(gaefAxisCoord_exref + (ulonglong)(uVar6 + 1 & 3) * 4);
    uVar7 = bPartialQuadrantArc(param_1,param_2,param_3,param_4,param_6,(EPOINTFL *)&local_a0,
                                (EFLOAT *)(gaefAxisAngle_exref + uVar11 * 4));
    if (uVar6 != param_8) {
      iVar1 = *(int *)(param_3 + 0x30);
      iVar2 = *(int *)(param_3 + 0x34);
      iVar3 = *(int *)(param_3 + 0x38);
      local_98 = (longlong)*(int *)(param_3 + 0x3c) * 0x729d7775 >> 0x20;
      do {
        iVar10 = (int)uVar11;
        iVar12 = (int)((ulonglong)((longlong)iVar2 * 0x729d7775) >> 0x20);
        iVar14 = (int)((ulonglong)((longlong)iVar1 * 0x729d7775) >> 0x20);
        iVar9 = (int)local_98;
        iVar13 = (int)((ulonglong)((longlong)iVar3 * 0x729d7775) >> 0x20);
        if (iVar10 == 0) {
          iVar8 = (int)*(undefined8 *)(param_3 + 8);
          iStack_5c = (int)((ulonglong)*(undefined8 *)(param_3 + 8) >> 0x20);
          iStack_4c = iStack_5c;
          _local_60 = CONCAT44(iStack_5c - iVar9,iVar8 - iVar13);
          _local_58 = CONCAT44(iStack_4c - iVar12,iVar8 - iVar14);
          iVar12 = *(int *)(param_3 + 0x34);
          iVar8 = iVar8 - *(int *)(param_3 + 0x30);
LAB_140161bad:
          iStack_4c = iStack_4c - iVar12;
LAB_140161afa:
          _local_50 = CONCAT44(iStack_4c,iVar8);
        }
        else {
          if (iVar10 == 1) {
            iStack_5c = (int)((ulonglong)*(undefined8 *)(param_3 + 0x10) >> 0x20);
            iStack_4c = iStack_5c;
            iVar9 = iStack_5c - iVar9;
            iVar4 = (int)*(undefined8 *)(param_3 + 0x10);
            _local_60 = CONCAT44(iStack_5c + iVar12,iVar14 + iVar4);
            iVar8 = iVar4 - *(int *)(param_3 + 0x38);
            _local_58 = CONCAT44(iVar9,iVar4 - iVar13);
            iVar12 = *(int *)(param_3 + 0x3c);
            goto LAB_140161bad;
          }
          if (iVar10 == 2) {
            iStack_5c = (int)((ulonglong)*(undefined8 *)(param_3 + 0x18) >> 0x20);
            iStack_4c = iStack_5c;
            iVar12 = iStack_5c + iVar12;
            iVar8 = (int)*(undefined8 *)(param_3 + 0x18);
            _local_60 = CONCAT44(iStack_5c + iVar9,iVar8 + iVar13);
            _local_58 = CONCAT44(iVar12,iVar14 + iVar8);
            iVar12 = *(int *)(param_3 + 0x34);
            iVar8 = iVar8 + *(int *)(param_3 + 0x30);
LAB_140161af7:
            iStack_4c = iStack_4c + iVar12;
            goto LAB_140161afa;
          }
          if (iVar10 == 3) {
            iVar8 = (int)*(undefined8 *)(param_3 + 0x20);
            iStack_5c = (int)((ulonglong)*(undefined8 *)(param_3 + 0x20) >> 0x20);
            iStack_4c = iStack_5c;
            iVar9 = iStack_5c + iVar9;
            _local_60 = CONCAT44(iStack_5c - iVar12,iVar8 - iVar14);
            _local_58 = CONCAT44(iVar9,iVar8 + iVar13);
            iVar12 = *(int *)(param_3 + 0x3c);
            iVar8 = iVar8 + *(int *)(param_3 + 0x38);
            goto LAB_140161af7;
          }
        }
        local_80 = &local_60;
        local_70 = 0;
        local_68 = 0;
        local_78 = 3;
        bVar5 = EPATHOBJ::bPolyBezierTo(param_2,(EXFORMOBJR *)0x0,(umptr_r<_POINTL> *)&local_80,3);
        uVar7 = uVar7 & bVar5;
        uVar6 = iVar10 + 1U & 3;
        uVar11 = (ulonglong)uVar6;
      } while (uVar6 != param_8);
    }
    local_9c = *(undefined4 *)(gaefAxisCoord_exref + (longlong)param_8 * 4);
    local_a0 = *(undefined4 *)(gaefAxisCoord_exref + (ulonglong)(param_8 + 1U & 3) * 4);
    uVar6 = bPartialQuadrantArc(0,param_2,param_3,(EPOINTFL *)&local_a0,
                                (EFLOAT *)(gaefAxisAngle_exref + (longlong)param_8 * 4),local_88,
                                local_90);
    uVar7 = uVar7 & uVar6;
  }
  return uVar7;
}



/* 1401627b4  bPartialQuadrantArc  761 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* int __cdecl bPartialQuadrantArc(enum PARTIALARC,class EPATHOBJ & __ptr64,class EBOX &
   __ptr64,class EPOINTFL & __ptr64,class EFLOAT & __ptr64,class EPOINTFL & __ptr64,class EFLOAT &
   __ptr64) */

int __cdecl
bPartialQuadrantArc(PARTIALARC param_1,EPATHOBJ *param_2,EBOX *param_3,EPOINTFL *param_4,
                   EFLOAT *param_5,EPOINTFL *param_6,EFLOAT *param_7)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined8 uVar5;
  bool bVar6;
  float fVar7;
  undefined8 *puVar8;
  float fVar9;
  undefined1 auStack_e8 [32];
  EPOINTFL local_c8 [4];
  float local_c4;
  undefined8 local_c0;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  undefined8 local_a8;
  EPOINTFL *local_a0;
  undefined8 local_98;
  undefined8 local_90;
  undefined2 local_88;
  undefined8 local_80;
  undefined8 local_78;
  undefined8 local_70;
  ulonglong local_68;
  
  local_68 = __security_cookie ^ (ulonglong)auStack_e8;
  fVar1 = *(float *)param_4;
  fVar2 = *(float *)(param_4 + 4);
  fVar3 = *(float *)param_6;
  fVar4 = *(float *)(param_6 + 4);
  fVar9 = fVar1 * fVar4 - fVar2 * fVar3;
  if (fVar9 < 0.0) {
    fVar9 = -fVar9;
  }
  if (*(float *)FP_EPSILON_exref < fVar9) {
    local_c4 = fVar1;
    fVar7 = (float)efCos((*(float *)param_7 - *(float *)param_5) * 0.5);
    if (fVar7 < 0.0) {
      fVar7 = -fVar7;
    }
    local_b0 = (*(float *)FP_4DIV3_exref * fVar7) / (fVar7 + *(float *)FP_1_0_exref);
    uVar5 = *(undefined8 *)param_4;
    fVar7 = *(float *)FP_1_0_exref - local_b0;
    local_ac = local_b0 * ((fVar1 - fVar3) / fVar9);
    local_b0 = local_b0 * ((fVar4 - fVar2) / fVar9);
    local_c0._4_4_ = (float)((ulonglong)uVar5 >> 0x20);
    local_c0._0_4_ = (float)uVar5;
    local_b4 = fVar7 * local_c0._4_4_ + local_ac;
    local_b8 = fVar7 * (float)local_c0 + local_b0;
    local_a8 = *(undefined8 *)param_6;
    local_ac = fVar7 * *(float *)(param_6 + 4) + local_ac;
    local_b0 = fVar7 * *(float *)param_6 + local_b0;
    local_c0 = uVar5;
  }
  else {
    uVar5 = *(undefined8 *)param_4;
    local_c0._0_4_ = (float)uVar5;
    local_c0._4_4_ = (float)((ulonglong)uVar5 >> 0x20);
    local_b8 = (float)local_c0;
    local_b0 = *(float *)param_6;
    local_b4 = local_c0._4_4_;
    local_ac = *(float *)(param_6 + 4);
    local_a8 = *(undefined8 *)param_6;
    local_c0 = uVar5;
  }
  if (param_1 != 0) {
    EBOX::ptlXform(param_3,local_c8);
    if (param_1 == 1) {
      local_98 = 1;
      local_88 = 0;
      local_a0 = local_c8;
      local_90 = 0;
      bVar6 = EPATHOBJ::bMoveTo(param_2,(EXFORMOBJR *)0x0,(umptr_r<_POINTL> *)&local_a0);
    }
    else {
      if (param_1 != 2) goto LAB_1401628e7;
      local_98 = 1;
      local_88 = 0;
      local_a0 = local_c8;
      local_90 = 0;
      bVar6 = EPATHOBJ::bPolyLineTo(param_2,(EXFORMOBJR *)0x0,(umptr_r<_POINTL> *)&local_a0,1);
    }
    if (bVar6 == false) {
      return 0;
    }
  }
LAB_1401628e7:
  puVar8 = (undefined8 *)EBOX::ptlXform(param_3,local_c8);
  local_80 = *puVar8;
  puVar8 = (undefined8 *)EBOX::ptlXform(param_3,local_c8);
  local_78 = *puVar8;
  puVar8 = (undefined8 *)EBOX::ptlXform(param_3,local_c8);
  local_90 = 0;
  local_70 = *puVar8;
  local_a0 = (EPOINTFL *)&local_80;
  local_88 = 0;
  local_98 = 3;
  bVar6 = EPATHOBJ::bPolyBezierTo(param_2,(EXFORMOBJR *)0x0,(umptr_r<_POINTL> *)&local_a0,3);
  return (uint)bVar6;
}



/* 1401ad010  EFLOAT::bIs16  24 bytes, 1 callers */

/* public: int __cdecl EFLOAT::bIs16(void)const __ptr64 */

int __thiscall EFLOAT::bIs16(EFLOAT *this)

{
  if (*(float *)this != 16.0) {
    return 0;
  }
  return 1;
}



/* 1401e7034  EFLOAT::vAbs  24 bytes, 2 callers */

/* public: void __cdecl EFLOAT::vAbs(void) __ptr64 */

void __thiscall EFLOAT::vAbs(EFLOAT *this)

{
  if (*(float *)this < 0.0) {
    *(float *)this = -*(float *)this;
  }
  return;
}



/* 14033be70  EngSaveFloatingPointState  20 bytes, 0 callers */

undefined8 EngSaveFloatingPointState(longlong param_1,int param_2)

{
  undefined8 uVar1;
  
                    /* 0x33be70  373  EngSaveFloatingPointState */
  if ((param_1 == 0) || (uVar1 = 1, param_2 == 0)) {
    uVar1 = 8;
  }
  return uVar1;
}


