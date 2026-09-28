
/* 140119ed0  NtGdiArcInternal  1698 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int NtGdiArcInternal(uint param_1,HDC__ *param_2,undefined4 param_3,undefined4 param_4,
                    undefined4 param_5,undefined4 param_6,int param_7,int param_8,int param_9,
                    int param_10)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  int iVar9;
  undefined8 *puVar10;
  undefined8 uVar11;
  long lVar12;
  long lVar13;
  undefined1 auStackY_4b8 [32];
  ulong uVar14;
  float local_468;
  float local_464;
  float local_460;
  float local_45c;
  int local_458;
  undefined1 local_454 [4];
  int local_450 [2];
  DC *local_448 [5];
  undefined1 local_420 [32];
  undefined1 local_400 [32];
  char local_3e0;
  EXFORMOBJ local_3d8 [8];
  undefined1 *local_3d0;
  undefined8 local_3c8;
  undefined8 local_3c0;
  undefined2 local_3b8;
  undefined4 local_3b0;
  undefined4 local_3ac;
  undefined4 local_3a8;
  undefined4 local_3a4;
  int local_398;
  int local_394;
  undefined1 local_370 [24];
  long local_358;
  long local_354;
  int local_350;
  int local_34c;
  PATHSTACKOBJ local_348 [8];
  longlong local_340;
  CAutoTGO local_2f8 [64];
  PATH_CORE local_2b8 [560];
  ulonglong local_88;
  
                    /* 0x119ed0  1215  NtGdiArcInternal */
  local_88 = __security_cookie ^ (ulonglong)auStackY_4b8;
  local_3a8 = param_5;
  local_3a4 = param_6;
  local_3b0 = param_3;
  local_3ac = param_4;
  APIDCOBJ::APIDCOBJ((APIDCOBJ *)local_448,param_2);
  iVar9 = 0;
  if ((local_448[0] == (DC *)0x0) || ((*(uint *)(local_448[0] + 0x24) & 0x10000) != 0)) {
    uVar11 = 6;
  }
  else {
    if (param_1 < 4) {
      uVar1 = *(uint *)(*(longlong *)(local_448[0] + 0x3d0) + 0x98);
      if ((uVar1 >> 0xc & 1) != 0) {
        GreDCSelectBrush(local_448[0],*(undefined8 *)(*(longlong *)(local_448[0] + 0x3d0) + 0xa0));
      }
      if ((uVar1 >> 0xd & 1) != 0) {
        GreDCSelectPen(local_448[0],*(undefined8 *)(*(longlong *)(local_448[0] + 0x3d0) + 0xa8));
      }
      PATHSTACKOBJ::PATHSTACKOBJ(local_348,(XDCOBJ *)local_448,(uint)(param_1 == 1));
      if (local_340 == 0) {
        EngSetLastError(8);
        PATHSTACKOBJ::~PATHSTACKOBJ(local_348);
        goto LAB_140119ff2;
      }
      DC::QuickInitXform(local_448[0],(ulong)local_3d8);
      EBOX::EBOX((EBOX *)&local_398,(XDCOBJ *)local_448,(_RECTL *)&local_3b0,
                 (_LINEATTRS *)(local_448[0] + 0xd0),1);
      if (local_394 == 0) {
        if (local_398 != 0) {
          EPATHOBJ::vUnlock((EPATHOBJ *)local_348);
          PATH_CORE::~PATH_CORE(local_2b8);
          CAutoTGO::vUnguard(local_2f8);
          iVar9 = 1;
          if (local_3e0 != '\0') {
            XDCOBJ::vUnlockNoNullSet((XDCOBJ *)local_448);
          }
          goto LAB_14011a3ca;
        }
        lVar12 = local_354;
        iVar8 = local_34c;
        fVar4 = (float)efHalfDiff(local_354,-local_34c);
        fVar5 = (float)efHalfDiff(local_358,-local_350);
        local_450[0] = 0;
        lVar13 = 0;
        local_458 = 0;
        local_45c = 0.0;
        local_460 = 0.0;
        if ((local_358 == local_350) || (lVar12 == iVar8)) {
          local_460 = *(float *)FP_0_0_exref;
          local_45c = local_460;
        }
        else {
          fVar6 = (float)efHalfDiff(local_350,local_358);
          fVar7 = (float)efHalfDiff(lVar12,iVar8);
          local_464 = ((float)param_8 - fVar4) / fVar7;
          local_468 = ((float)param_7 - fVar5) / fVar6;
          vArctan(local_468,local_464,&local_45c,local_450);
          local_464 = ((float)param_10 - fVar4) / fVar7;
          local_468 = ((float)param_9 - fVar5) / fVar6;
          vArctan(local_468,local_464,&local_460,&local_458);
        }
        iVar2 = local_450[0];
        iVar8 = local_458;
        fVar5 = local_45c;
        fVar4 = local_460;
        fVar6 = local_460 - local_45c;
        if (fVar6 < 0.0) {
          fVar6 = -fVar6;
        }
        if ((0.0 <= fVar6 - *(float *)FP_3_0_exref) || (fVar6 == 0.0)) {
          vCosSin(local_45c,&local_458,local_454);
          vCosSin(fVar4,&local_468,&local_464);
        }
        else {
          vCosSinPrecise(local_45c,&local_458,local_454);
          vCosSinPrecise(fVar4,&local_468,&local_464);
        }
        if ((iVar2 != iVar8) || (fVar4 <= fVar5)) {
          lVar13 = 1;
        }
        iVar8 = bPartialArc((param_1 == 1) + 1,(EPATHOBJ *)local_348,(EBOX *)&local_398,
                            (EPOINTFL *)&local_458,iVar2,(EFLOAT *)&local_45c,(EPOINTFL *)&local_468
                            ,iVar8,(EFLOAT *)&local_460,lVar13);
        if (iVar8 != 0) {
          if (param_1 == 1) {
            *(uint *)(*(longlong *)(local_448[0] + 0x3d0) + 0x98) =
                 *(uint *)(*(longlong *)(local_448[0] + 0x3d0) + 0x98) | 0x100;
            *(uint *)(*(longlong *)(local_448[0] + 0x3d0) + 0x98) =
                 *(uint *)(*(longlong *)(local_448[0] + 0x3d0) + 0x98) & 0xfffffdff;
            puVar10 = (undefined8 *)EPATHOBJ::ptfxGetCurrent((EPATHOBJ *)local_348);
            *(undefined8 *)(*(longlong *)(local_448[0] + 0x3d0) + 8) = *puVar10;
          }
          else if (param_1 == 2) {
            bVar3 = EPATHOBJ::bCloseFigure((EPATHOBJ *)local_348);
            if (!bVar3) goto LAB_14011a54f;
          }
          else if (param_1 == 3) {
            local_3c8 = 1;
            local_3b8 = 0;
            local_3d0 = local_370;
            local_3c0 = 0;
            bVar3 = EPATHOBJ::bPolyLineTo
                              ((EPATHOBJ *)local_348,(EXFORMOBJR *)0x0,
                               (umptr_r<_POINTL> *)&local_3d0,1);
            if ((!bVar3) || (bVar3 = EPATHOBJ::bCloseFigure((EPATHOBJ *)local_348), !bVar3))
            goto LAB_14011a390;
          }
          if ((*(uint *)(local_448[0] + 0xf8) & 1) != 0) {
            iVar9 = 1;
LAB_14011a54f:
            PATHSTACKOBJ::~PATHSTACKOBJ(local_348);
            APIDCOBJ::~APIDCOBJ((APIDCOBJ *)local_448);
            return iVar9;
          }
          if ((param_1 == 0) || (param_1 == 1)) {
            uVar14 = 1;
          }
          else {
            if ((param_1 != 2) && (param_1 != 3)) goto LAB_14011a2d6;
            uVar14 = 3;
          }
          iVar9 = EPATHOBJ_bStrokeAndOrFill
                            ((EPATHOBJ *)local_348,(XDCOBJ *)local_448,
                             (_LINEATTRS *)(local_448[0] + 0xd0),local_3d8,uVar14);
LAB_14011a2d6:
          EPATHOBJ::vUnlock((EPATHOBJ *)local_348);
          PATH_CORE::~PATH_CORE(local_2b8);
          CAutoTGO::vUnguard(local_2f8);
          if (local_3e0 != '\0') {
            XDCOBJ::vUnlockNoNullSet((XDCOBJ *)local_448);
          }
          local_448[0] = (DC *)0x0;
          PopThreadGuardedObject(local_400);
          XDCOBJ::vUnlockNoNullSet((XDCOBJ *)local_448);
          PopThreadGuardedObject(local_420);
          return iVar9;
        }
      }
LAB_14011a390:
      EPATHOBJ::vUnlock((EPATHOBJ *)local_348);
      PATH_CORE::~PATH_CORE(local_2b8);
      CAutoTGO::vUnguard(local_2f8);
      if (local_3e0 != '\0') {
        XDCOBJ::vUnlockNoNullSet((XDCOBJ *)local_448);
      }
LAB_14011a3ca:
      local_448[0] = (DC *)0x0;
      PopThreadGuardedObject(local_400);
      XDCOBJ::vUnlockNoNullSet((XDCOBJ *)local_448);
      PopThreadGuardedObject(local_420);
      return iVar9;
    }
    uVar11 = 0x57;
  }
  EngSetLastError(uVar11);
LAB_140119ff2:
  APIDCOBJ::~APIDCOBJ((APIDCOBJ *)local_448);
  return 0;
}



/* 14011bd08  EBOX::EBOX  1448 bytes, 4 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* public: __cdecl EBOX::EBOX(class XDCOBJ & __ptr64,struct _RECTL & __ptr64,struct _LINEATTRS *
   __ptr64,int) __ptr64 */

EBOX * __thiscall
EBOX::EBOX(EBOX *this,XDCOBJ *param_1,_RECTL *param_2,_LINEATTRS *param_3,int param_4)

{
  ERECTL *this_00;
  EBOX *pEVar1;
  _POINTL *p_Var2;
  uint uVar3;
  DC *this_01;
  longlong lVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  bool bVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  EBOX *pEVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  int iVar17;
  EBOX *pEVar18;
  float fVar19;
  undefined1 auStack_b8 [32];
  undefined8 local_80;
  int local_78;
  int local_74;
  undefined8 local_70;
  undefined1 local_68;
  undefined8 local_60;
  _LINEATTRS *local_58;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  ulonglong local_40;
  
  local_40 = __security_cookie ^ (ulonglong)auStack_b8;
  uVar5 = *(undefined8 *)param_2;
  uVar6 = *(undefined8 *)(param_2 + 8);
  *(undefined4 *)this = 0;
  this_00 = (ERECTL *)(this + 0x40);
  *(undefined4 *)(this + 4) = 0;
  pEVar1 = this + 0x48;
  *(undefined8 *)this_00 = uVar5;
  *(undefined8 *)(this + 0x48) = uVar6;
  iVar10 = *(int *)this_00;
  if ((*(uint *)(*(longlong *)(*(longlong *)param_1 + 0x3d0) + 0x6c) & 1) != 0) {
    iVar10 = iVar10 + -1;
    *(int *)pEVar1 = *(int *)pEVar1 + -1;
    *(int *)this_00 = iVar10;
  }
  local_80 = param_1;
  local_58 = param_3;
  if (*(int *)(*(longlong *)(*(longlong *)param_1 + 0x3d0) + 0xd0) == 2) {
    ERECTL::vOrder(this_00);
  }
  else {
    iVar11 = *(int *)pEVar1;
    if ((*(uint *)(*(longlong *)(*(longlong *)param_1 + 0x3d0) + 0x154) & 0x100) == 0) {
      if (iVar11 < iVar10) {
LAB_14011c1aa:
        *(int *)this_00 = iVar11;
        *(int *)pEVar1 = iVar10;
      }
    }
    else if (iVar10 < iVar11) goto LAB_14011c1aa;
    iVar10 = *(int *)(this + 0x4c);
    iVar11 = *(int *)(this + 0x44);
    if ((*(uint *)(*(longlong *)(*(longlong *)param_1 + 0x3d0) + 0x154) & 0x200) == 0) {
      if (iVar10 < iVar11) {
LAB_14011c1b6:
        *(int *)(this + 0x4c) = iVar11;
        *(int *)(this + 0x44) = iVar10;
      }
    }
    else if (iVar11 < iVar10) goto LAB_14011c1b6;
  }
  pEVar18 = this + 0x4c;
  pEVar13 = this + 0x44;
  if ((*(uint *)(*(longlong *)param_1 + 0xf8) & 4) != 0) {
    iVar10 = *(int *)pEVar13;
    *(int *)pEVar13 = *(int *)pEVar18;
    *(int *)pEVar18 = iVar10;
  }
  local_50 = *(uint *)this_00;
  this_01 = *(DC **)param_1;
  local_4c = *(uint *)(this + 0x44);
  local_48 = *(uint *)(this + 0x48);
  local_44 = *(uint *)(this + 0x4c);
  lVar4 = *(longlong *)(this_01 + 0x90);
  iVar10 = *(int *)(*(longlong *)(this_01 + 0x3d0) + 0xd0);
  DC::QuickInitXform(this_01,(ulong)&local_60);
  local_68 = iVar10 != 2;
  local_70 = local_60;
  uVar14 = local_4c;
  uVar15 = local_50;
  uVar16 = local_44;
  if (((*(uint *)(lVar4 + 0x28) & 0x10000) == 0) || (bVar7 = true, (*(uint *)local_58 & 1) == 0)) {
LAB_14011be68:
    bVar7 = false;
  }
  else {
    fVar19 = (float)(*(uint *)(lVar4 + 0xa8) >> 1);
    if ((*(uint *)(lVar4 + 0xa8) & 1) != 0) {
      fVar19 = *(float *)FP_0_5_exref + fVar19;
    }
    fVar8 = (float)efHalfDiff(local_50,local_48);
    fVar9 = (float)efHalfDiff(uVar14,uVar16);
    if (fVar8 < 0.0) {
      fVar8 = -fVar8;
    }
    if (fVar9 < 0.0) {
      fVar9 = -fVar9;
    }
    if ((fVar8 < fVar19) || (fVar9 < fVar19)) {
      *(undefined4 *)(this + 4) = 1;
      goto LAB_14011be68;
    }
  }
  if ((((*(int *)(*(longlong *)(*(longlong *)local_80 + 0x3d0) + 0xd0) == 2) || (bVar7)) ||
      (*(int *)(this + 4) != 0)) ||
     ((*(uint *)(*(longlong *)(*(longlong *)local_80 + 0x3d0) + 0x154) & 0x20) != 0)) {
    p_Var2 = (_POINTL *)(this + 8);
    *(uint *)p_Var2 = local_48;
    *(uint *)(this + 0xc) = uVar14;
    *(uint *)(this + 0x14) = uVar14;
    *(uint *)(this + 0x10) = uVar15;
    *(uint *)(this + 0x18) = uVar15;
    *(uint *)(this + 0x1c) = uVar16;
    EXFORMOBJR::bXformRound((EXFORMOBJR *)&local_70,p_Var2,(_POINTFIX *)p_Var2,3);
    if ((param_4 != 0) && (*(int *)(lVar4 + 0xb0) == 5)) {
      uVar14 = *(uint *)(this + 8);
      uVar15 = *(uint *)(this + 0xc);
      uVar16 = *(uint *)(this + 0x18);
      uVar3 = *(uint *)(this + 0x1c);
      if (((uVar14 | uVar15 | uVar16 | uVar3) & 0xf) == 0) {
        iVar10 = 4;
        if ((int)uVar14 <= (int)uVar16) {
          iVar10 = -4;
        }
        *(int *)(this + 0x10) = *(int *)(this + 0x10) - iVar10;
        *(uint *)(this + 0x18) = uVar16 - iVar10;
        iVar11 = 4;
        if ((int)uVar3 <= (int)uVar15) {
          iVar11 = -4;
        }
        *(uint *)(this + 8) = uVar14 + iVar10;
        *(int *)(this + 0x14) = *(int *)(this + 0x14) - iVar11;
        *(uint *)(this + 0xc) = uVar15 - iVar11;
        *(uint *)(this + 0x1c) = uVar3 + iVar11;
      }
    }
    if (bVar7) {
      local_74 = *(int *)(lVar4 + 0xa8);
      local_78 = local_74;
      if (*(int *)pEVar1 < *(int *)this_00) {
        local_78 = -local_74;
      }
      if (*(int *)pEVar18 < *(int *)pEVar13) {
        local_74 = -local_74;
      }
      local_80._0_4_ = -local_78;
      local_80._4_4_ = local_74;
      EXFORMOBJ::bXform((EXFORMOBJ *)&local_70,(_VECTORL *)&local_80,(_VECTORFX *)&local_80,2,false)
      ;
      iVar11 = (int)local_80 + 1 >> 1;
      *(int *)(this + 8) = *(int *)(this + 8) + iVar11;
      iVar10 = local_80._4_4_ + 1 >> 1;
      *(int *)(this + 0xc) = *(int *)(this + 0xc) + iVar10;
      *(int *)(this + 0x10) = *(int *)(this + 0x10) + (local_78 + 1 >> 1);
      *(int *)(this + 0x14) = *(int *)(this + 0x14) + (local_74 + 1 >> 1);
      *(int *)(this + 0x18) = *(int *)(this + 0x18) - iVar11;
      *(int *)(this + 0x1c) = *(int *)(this + 0x1c) - iVar10;
    }
LAB_14011bf33:
    *(undefined8 *)(this + 0x30) = *(undefined8 *)(this + 8);
    *(int *)(this + 0x30) = *(int *)(this + 0x30) - *(int *)(this + 0x10);
    *(int *)(this + 0x34) = *(int *)(this + 0x34) - *(int *)(this + 0x14);
    *(undefined8 *)(this + 0x38) = *(undefined8 *)(this + 0x10);
    *(int *)(this + 0x38) = *(int *)(this + 0x38) - *(int *)(this + 0x18);
    *(int *)(this + 0x3c) = *(int *)(this + 0x3c) - *(int *)(this + 0x1c);
    *(undefined8 *)(this + 0x20) = *(undefined8 *)(this + 0x18);
    *(int *)(this + 0x20) = *(int *)(this + 0x20) + *(int *)(this + 0x30);
    *(int *)(this + 0x24) = *(int *)(this + 0x24) + *(int *)(this + 0x34);
    *(int *)(this + 0x30) = *(int *)(this + 0x30) + 1 >> 1;
    *(int *)(this + 0x34) = *(int *)(this + 0x34) + 1 >> 1;
    *(int *)(this + 0x38) = *(int *)(this + 0x38) + 1 >> 1;
    *(int *)(this + 0x3c) = *(int *)(this + 0x3c) + 1 >> 1;
    *(undefined8 *)(this + 0x28) = *(undefined8 *)(this + 0x18);
    *(int *)(this + 0x28) = *(int *)(this + 0x28) + *(int *)(this + 0x30);
    *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + *(int *)(this + 0x34);
    *(int *)(this + 0x28) = *(int *)(this + 0x28) + *(int *)(this + 0x38);
    *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + *(int *)(this + 0x3c);
  }
  else {
    EXFORMOBJR::bXformRound((EXFORMOBJR *)&local_70,(_POINTL *)&local_50,(_POINTFIX *)&local_50,2);
    iVar10 = 0x10;
    if (((param_4 != 0) && (*(int *)(lVar4 + 0xb0) == 5)) &&
       (((local_4c | local_44 | local_50 | local_48) & 0xf) == 0)) {
      iVar10 = -4;
      if ((int)local_50 < (int)local_48) {
        iVar10 = 4;
      }
      local_48 = local_48 + iVar10;
      local_50 = local_50 - iVar10;
      iVar10 = -4;
      if ((int)local_4c < (int)local_44) {
        iVar10 = 4;
      }
      local_4c = local_4c - iVar10;
      local_44 = local_44 + iVar10;
      iVar10 = 0x20;
    }
    iVar12 = local_48 - local_50;
    iVar17 = local_44 - local_4c;
    iVar11 = -iVar12;
    if (-iVar12 < 0) {
      iVar11 = iVar12;
    }
    if (iVar10 <= iVar11) {
      iVar11 = -iVar17;
      if (-iVar17 < 0) {
        iVar11 = iVar17;
      }
      if (iVar10 <= iVar11) {
        if (iVar12 < 1) {
          local_50 = local_50 - iVar10;
        }
        else {
          local_48 = local_48 - iVar10;
        }
        if (iVar17 < 1) {
          local_4c = local_4c - iVar10;
        }
        else {
          local_44 = local_44 - iVar10;
        }
        *(uint *)(this + 8) = local_48;
        *(uint *)(this + 0xc) = local_4c;
        *(uint *)(this + 0x10) = local_50;
        *(uint *)(this + 0x14) = local_4c;
        *(uint *)(this + 0x18) = local_50;
        *(uint *)(this + 0x1c) = local_44;
        goto LAB_14011bf33;
      }
    }
    *(undefined4 *)this = 1;
  }
  return this;
}



/* 140161804  EBOX::EBOX  247 bytes, 1 callers */

/* public: __cdecl EBOX::EBOX(class EXFORMOBJR & __ptr64,struct _RECTL & __ptr64) __ptr64 */

EBOX * __thiscall EBOX::EBOX(EBOX *this,EXFORMOBJR *param_1,_RECTL *param_2)

{
  _POINTL *p_Var1;
  undefined8 uVar2;
  undefined8 uVar3;
  
  uVar2 = *(undefined8 *)param_2;
  uVar3 = *(undefined8 *)(param_2 + 8);
  *(undefined4 *)this = 0;
  p_Var1 = (_POINTL *)(this + 8);
  *(undefined4 *)(this + 4) = 0;
  *(undefined8 *)(this + 0x40) = uVar2;
  *(undefined8 *)(this + 0x48) = uVar3;
  *(undefined4 *)p_Var1 = *(undefined4 *)(param_2 + 8);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x10) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x14) = *(undefined4 *)(param_2 + 4);
  *(undefined4 *)(this + 0x18) = *(undefined4 *)param_2;
  *(undefined4 *)(this + 0x1c) = *(undefined4 *)(param_2 + 0xc);
  EXFORMOBJR::bXformRound(param_1,p_Var1,(_POINTFIX *)p_Var1,3);
  *(undefined8 *)(this + 0x30) = *(undefined8 *)p_Var1;
  *(int *)(this + 0x30) = *(int *)(this + 0x30) - *(int *)(this + 0x10);
  *(int *)(this + 0x34) = *(int *)(this + 0x34) - *(int *)(this + 0x14);
  *(undefined8 *)(this + 0x38) = *(undefined8 *)(this + 0x10);
  *(int *)(this + 0x38) = *(int *)(this + 0x38) - *(int *)(this + 0x18);
  *(int *)(this + 0x3c) = *(int *)(this + 0x3c) - *(int *)(this + 0x1c);
  *(undefined8 *)(this + 0x20) = *(undefined8 *)(this + 0x18);
  *(int *)(this + 0x20) = *(int *)(this + 0x20) + *(int *)(this + 0x30);
  *(int *)(this + 0x24) = *(int *)(this + 0x24) + *(int *)(this + 0x34);
  *(int *)(this + 0x30) = *(int *)(this + 0x30) + 1 >> 1;
  *(int *)(this + 0x34) = *(int *)(this + 0x34) + 1 >> 1;
  *(int *)(this + 0x38) = *(int *)(this + 0x38) + 1 >> 1;
  *(int *)(this + 0x3c) = *(int *)(this + 0x3c) + 1 >> 1;
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(this + 0x18);
  *(int *)(this + 0x28) = *(int *)(this + 0x28) + *(int *)(this + 0x30);
  *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + *(int *)(this + 0x34);
  *(int *)(this + 0x28) = *(int *)(this + 0x28) + *(int *)(this + 0x38);
  *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + *(int *)(this + 0x3c);
  return this;
}



/* 1401626ec  EBOX::EBOX  191 bytes, 2 callers */

/* public: __cdecl EBOX::EBOX(class ERECTL & __ptr64,int) __ptr64 */

EBOX * __thiscall EBOX::EBOX(EBOX *this,ERECTL *param_1,int param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  ERECTL *pEVar7;
  
  pEVar7 = param_1;
  ERECTL::vOrder(param_1);
  uVar1 = *(undefined8 *)param_1;
  uVar2 = *(undefined8 *)(param_1 + 8);
  *(undefined8 *)this = 0;
  *(undefined8 *)(this + 0x40) = uVar1;
  *(undefined8 *)(this + 0x48) = uVar2;
  iVar3 = *(int *)(param_1 + 8);
  *(int *)(this + 8) = iVar3 * 0x10 + -0x10;
  iVar6 = iVar3 * 0x10 + -0x1c;
  iVar3 = *(int *)(param_1 + 4);
  *(int *)(this + 0xc) = iVar3 * 0x10;
  iVar5 = iVar3 * 0x10 + -4;
  iVar3 = *(int *)param_1;
  *(int *)(this + 0x18) = iVar3 * 0x10;
  iVar4 = iVar3 * 0x10 + -4;
  iVar3 = *(int *)(pEVar7 + 0xc);
  *(int *)(this + 8) = iVar6;
  *(int *)(this + 0xc) = iVar5;
  *(int *)(this + 0x14) = iVar5;
  *(int *)(this + 0x20) = iVar6;
  *(int *)(this + 0x18) = iVar4;
  *(undefined8 *)(this + 0x34) = 0;
  *(int *)(this + 0x10) = iVar4;
  iVar3 = iVar3 * 0x10 + -0x1c;
  iVar4 = (iVar6 - iVar4) + 1 >> 1;
  *(int *)(this + 0x1c) = iVar3;
  *(int *)(this + 0x24) = iVar3;
  *(int *)(this + 0x30) = iVar4;
  *(int *)(this + 0x3c) = (iVar5 - iVar3) + 1 >> 1;
  *(undefined8 *)(this + 0x28) = *(undefined8 *)(this + 0x18);
  *(int *)(this + 0x28) = *(int *)(this + 0x28) + iVar4;
  *(undefined4 *)(this + 0x2c) = *(undefined4 *)(this + 0x2c);
  *(int *)(this + 0x28) = *(int *)(this + 0x28) + *(int *)(this + 0x38);
  *(int *)(this + 0x2c) = *(int *)(this + 0x2c) + *(int *)(this + 0x3c);
  return this;
}



/* 140163604  EBOX::ptlXform  215 bytes, 1 callers */

/* public: struct _POINTL __cdecl EBOX::ptlXform(class EPOINTFL & __ptr64) __ptr64 */

EPOINTFL * __thiscall EBOX::ptlXform(EBOX *this,EPOINTFL *param_1)

{
  char cVar1;
  ulonglong uVar2;
  longlong lVar3;
  uint uVar4;
  float *in_R8;
  float fVar5;
  int local_res8;
  int iStackX_c;
  
  fVar5 = (float)*(int *)(this + 0x38) * in_R8[1] + (float)*(int *)(this + 0x30) * *in_R8;
  uVar4 = (int)fVar5 >> 0x17 & 0xff;
  if (uVar4 < 0x9f) {
    uVar2 = (ulonglong)((uint)fVar5 & 0x7fffff) | 0x800000;
    cVar1 = (char)((int)fVar5 >> 0x17);
    if (uVar4 < 0x76) {
      lVar3 = (longlong)uVar2 >> (0x76U - cVar1 & 0x3f);
    }
    else {
      lVar3 = uVar2 << (cVar1 + 0x8aU & 0x3f);
    }
    local_res8 = (int)((ulonglong)(lVar3 + 0x80000000) >> 0x20);
    if ((int)fVar5 < 0) {
      local_res8 = -local_res8;
    }
  }
  bFToL((float)*(int *)(this + 0x3c) * in_R8[1] + (float)*(int *)(this + 0x34) * *in_R8,&iStackX_c,6
       );
  *(ulonglong *)param_1 =
       CONCAT44(iStackX_c + *(int *)(this + 0x2c),local_res8 + *(int *)(this + 0x28));
  return param_1;
}


