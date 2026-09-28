
/* 1401a1778  bPartialArc  684 bytes, 2 callers */

/* int __cdecl bPartialArc(enum PARTIALARC,class EPATHOBJ & __ptr64,class EBOX & __ptr64,class
   EPOINTFL & __ptr64,long,class EFLOAT & __ptr64,class EPOINTFL & __ptr64,long,class EFLOAT &
   __ptr64,long) */

int bPartialArc(PARTIALARC param_1,EPATHOBJ *param_2,EBOX *param_3,EPOINTFL *param_4,long param_5,
               EFLOAT *param_6,EPOINTFL *param_7,long param_8,EFLOAT *param_9,long param_10)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  PARTIALARC PVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  EPATHOBJ *this;
  long lVar11;
  int iVar12;
  int iVar13;
  ulong uVar14;
  int iVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  int iVar19;
  EFLOAT *in_stack_00000010;
  int in_stack_00000018;
  undefined4 local_b0;
  undefined4 uStack_ac;
  uint local_a8;
  EPOINTFL *local_a0;
  EFLOAT *pEStack_98;
  int *local_90;
  undefined8 uStack_88;
  undefined8 local_80;
  undefined2 local_78;
  int local_70;
  int iStack_6c;
  int local_68;
  int local_64;
  
  iVar10 = (int)param_5;
  uVar9 = (uint)param_8;
  PVar7 = __security_push_cookie(param_1);
  if (in_stack_00000018 == 0) {
    uVar9 = bPartialQuadrantArc(PVar7,this,param_3,param_4,param_6,param_7,in_stack_00000010);
  }
  else {
    uVar1 = iVar10 + 1U & 3;
    uVar14 = (ulong)uVar1;
    local_b0 = *(undefined4 *)(gaefAxisCoord_exref + (uVar14 + 1 & 3) * 4);
    uStack_ac = *(undefined4 *)(gaefAxisCoord_exref + uVar14 * 4);
    uVar8 = bPartialQuadrantArc(PVar7,this,param_3,param_4,param_6,(EPOINTFL *)&local_b0,
                                (EFLOAT *)(gaefAxisAngle_exref + uVar14 * 4));
    uVar18 = uVar9;
    if (uVar1 != uVar9) {
      iVar10 = *(int *)(param_3 + 0x30);
      iVar3 = *(int *)(param_3 + 0x34);
      pEStack_98 = in_stack_00000010;
      iVar2 = *(int *)(param_3 + 0x38);
      iVar4 = *(int *)(param_3 + 0x3c);
      local_a8 = uVar9;
      local_a0 = param_7;
      do {
        iVar13 = (int)uVar14;
        iVar19 = (int)((ulong)((long)iVar10 * 0x729d7775) >> 0x20);
        iVar17 = (int)((ulong)((long)iVar3 * 0x729d7775) >> 0x20);
        iVar16 = (int)((ulong)((long)iVar2 * 0x729d7775) >> 0x20);
        iVar15 = (int)((ulong)((long)iVar4 * 0x729d7775) >> 0x20);
        if (iVar13 == 0) {
          iStack_6c = (int)((ulong)*(undefined8 *)(param_3 + 8) >> 0x20);
          iVar5 = iStack_6c;
          iVar12 = (int)*(undefined8 *)(param_3 + 8);
          _local_70 = CONCAT44(iStack_6c - iVar15,iVar12 - iVar16);
          _local_68 = CONCAT44(iVar5 - iVar17,iVar12 - iVar19);
        }
        else if (iVar13 == 2) {
          iStack_6c = (int)((ulong)*(undefined8 *)(param_3 + 0x18) >> 0x20);
          iVar5 = iStack_6c;
          iVar12 = (int)*(undefined8 *)(param_3 + 0x18);
          _local_70 = CONCAT44(iStack_6c + iVar15,iVar12 + iVar16);
          _local_68 = CONCAT44(iVar5 + iVar17,iVar12 + iVar19);
        }
        else if (iVar13 == 1) {
          iStack_6c = (int)((ulong)*(undefined8 *)(param_3 + 0x10) >> 0x20);
          iVar5 = iStack_6c;
          iVar12 = (int)*(undefined8 *)(param_3 + 0x10);
          _local_70 = CONCAT44(iStack_6c + iVar17,iVar12 + iVar19);
          _local_68 = CONCAT44(iVar5 - iVar15,iVar12 - iVar16);
        }
        else if (iVar13 == 3) {
          iStack_6c = (int)((ulong)*(undefined8 *)(param_3 + 0x20) >> 0x20);
          iVar5 = iStack_6c;
          iVar12 = (int)*(undefined8 *)(param_3 + 0x20);
          _local_70 = CONCAT44(iStack_6c - iVar17,iVar12 - iVar19);
          _local_68 = CONCAT44(iVar5 + iVar15,iVar12 + iVar16);
        }
        local_90 = &local_70;
        local_80 = 0;
        local_78 = 0;
        uStack_88 = 3;
        bVar6 = EPATHOBJ::bPolyBezierTo(this,(EXFORMOBJR *)0x0,(umptr_r<_POINTL> *)&local_90,3);
        uVar8 = bVar6 & uVar8;
        uVar1 = iVar13 + 1U & 3;
        uVar14 = (ulong)uVar1;
        in_stack_00000010 = pEStack_98;
        param_7 = local_a0;
        uVar18 = local_a8;
      } while (uVar1 != uVar9);
    }
    lVar11 = (long)(int)uVar18;
    local_b0 = *(undefined4 *)(gaefAxisCoord_exref + (lVar11 + 1U & 3) * 4);
    uStack_ac = *(undefined4 *)(gaefAxisCoord_exref + lVar11 * 4);
    uVar9 = bPartialQuadrantArc(0,this,param_3,(EPOINTFL *)&local_b0,
                                (EFLOAT *)(gaefAxisAngle_exref + lVar11 * 4),param_7,
                                in_stack_00000010);
    uVar9 = uVar9 & uVar8;
  }
  iVar10 = __security_pop_cookie(uVar9);
  return iVar10;
}



/* 1401a1cb0  bPolyBezierTo  60 bytes, 1 callers */

/* public: bool __cdecl EPATHOBJ::bPolyBezierTo(class EXFORMOBJR const * __ptr64,struct _POINTL
   const * __ptr64,unsigned long) __ptr64 */

bool __thiscall
EPATHOBJ::bPolyBezierTo(EPATHOBJ *this,EXFORMOBJR *param_1,_POINTL *param_2,ulong param_3)

{
  bool bVar1;
  _POINTL *local_20;
  ulong uStack_18;
  undefined8 local_10;
  undefined2 local_8;
  
  uStack_18 = param_3 & 0xffffffff;
  local_10 = 0;
  local_8 = 0;
  local_20 = param_2;
  bVar1 = EPATHOBJ::bPolyBezierTo(this,param_1,(umptr_r<_POINTL> *)&local_20,param_3);
  return bVar1;
}



/* 1401a2338  vArctan  448 bytes, 4 callers */

/* void __cdecl vArctan(class EFLOAT,class EFLOAT,class EFLOAT & __ptr64,long & __ptr64) */

void vArctan(float param_1,float param_2,undefined4 *param_3,uint *param_4)

{
  float *pfVar1;
  uint *extraout_x1;
  uint uVar2;
  float *pfVar3;
  int iVar4;
  ulong extraout_x11;
  long extraout_x12;
  long extraout_x13;
  float extraout_s0;
  float extraout_s17;
  float fVar5;
  
  if (param_1 < 0.0) {
    param_1 = -param_1;
  }
  if (param_2 < 0.0) {
    param_2 = -param_2;
  }
  if (param_1 < param_2) {
    param_1 = param_2;
  }
  if (param_1 == 0.0) {
    uVar2 = 0;
    *param_3 = *(undefined4 *)FP_0_0_exref;
    goto LAB_1401a23c0;
  }
  pfVar1 = (float *)eFraction();
  iVar4 = (int)extraout_x11;
  fVar5 = extraout_s0 * (*(float *)(extraout_x12 + (extraout_x13 + 1) * 4) - extraout_s17) +
          extraout_s17;
  *pfVar1 = fVar5;
  pfVar3 = (float *)FP_90_0_exref;
  if (iVar4 == 4) {
LAB_1401a23a8:
    fVar5 = *pfVar3 - fVar5;
LAB_1401a23b0:
    *pfVar1 = fVar5;
  }
  else {
    pfVar3 = (float *)FP_180_0_exref;
    if (iVar4 == 3) {
LAB_1401a24a4:
      fVar5 = fVar5 + *pfVar3;
      goto LAB_1401a23b0;
    }
    pfVar3 = (float *)FP_360_0_exref;
    if (iVar4 == 2) goto LAB_1401a23a8;
    if (iVar4 == 6) {
      fVar5 = *(float *)FP_270_0_exref + fVar5;
      goto LAB_1401a23b0;
    }
    pfVar3 = (float *)FP_180_0_exref;
    if (iVar4 == 1) goto LAB_1401a23a8;
    pfVar3 = (float *)FP_90_0_exref;
    if (iVar4 == 5) goto LAB_1401a24a4;
    pfVar3 = (float *)FP_270_0_exref;
    if (iVar4 == 7) goto LAB_1401a23a8;
  }
  uVar2 = (uint)(byte)(&DAT_14034aa78)[extraout_x11 & 0xffffffff];
  param_4 = extraout_x1;
LAB_1401a23c0:
  *param_4 = uVar2;
  return;
}



/* 1401a2660  NtGdiArcInternal  1292 bytes, 0 callers */

void NtGdiArcInternal(undefined8 param_1,undefined8 param_2,undefined4 param_3,undefined4 param_4,
                     undefined4 param_5,undefined4 param_6,int param_7,int param_8,
                     undefined8 param_9,undefined8 param_10,int param_11,int param_12)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  HDC__ *extraout_x1;
  ulong uVar7;
  undefined4 uVar8;
  uint extraout_w9;
  int extraout_w10;
  ulong extraout_x10;
  int extraout_w11;
  ulong extraout_x11;
  PARTIALARC PVar9;
  float fVar10;
  float extraout_s18;
  float extraout_s19;
  float extraout_s19_00;
  float extraout_s20;
  float extraout_s20_00;
  float extraout_s21;
  float extraout_s21_00;
  undefined4 extraout_s24;
  float extraout_s24_00;
  undefined4 extraout_s24_01;
  float extraout_s24_02;
  float extraout_s25;
  float fVar11;
  float extraout_s25_00;
  undefined4 in_stack_fffffffffffffbec;
  float local_410;
  float fStack_40c;
  uint local_408;
  uint uStack_404;
  EPOINTFL aEStack_400 [4];
  undefined1 auStack_3fc [4];
  EPOINTFL aEStack_3f8 [4];
  undefined1 auStack_3f4 [4];
  DC *local_3f0 [5];
  undefined1 auStack_3c8 [32];
  undefined1 auStack_3a8 [32];
  char local_388;
  EXFORMOBJ aEStack_380 [8];
  undefined1 *local_378;
  undefined8 uStack_370;
  undefined8 local_368;
  undefined2 local_360;
  undefined4 local_350;
  undefined4 uStack_34c;
  undefined4 local_348;
  undefined4 uStack_344;
  int local_340;
  int local_33c;
  undefined1 auStack_318 [24];
  uint local_300;
  uint local_2fc;
  int local_2f8;
  int local_2f4;
  PATHSTACKOBJ aPStack_2f0 [8];
  long local_2e8;
  CAutoTGO aCStack_2a0 [64];
  PATH_CORE aPStack_260 [544];
  
  local_350 = param_3;
  uStack_34c = param_4;
  local_348 = param_5;
  uStack_344 = param_6;
  uVar2 = __security_push_cookie();
  APIDCOBJ::APIDCOBJ((APIDCOBJ *)local_3f0,extraout_x1);
  if ((local_3f0[0] == (DC *)0x0) || ((*(uint *)(local_3f0[0] + 0x24) >> 0x10 & 1) != 0)) {
    uVar6 = 6;
LAB_1401a2a3c:
    EngSetLastError(uVar6);
  }
  else {
    if (3 < uVar2) {
      uVar6 = 0x57;
      goto LAB_1401a2a3c;
    }
    uVar3 = *(uint *)(*(long *)(local_3f0[0] + 0x3d0) + 0x98);
    if ((uVar3 >> 0xc & 1) != 0) {
      GreDCSelectBrush(local_3f0[0],*(undefined8 *)(*(long *)(local_3f0[0] + 0x3d0) + 0xa0));
    }
    if ((uVar3 >> 0xd & 1) != 0) {
      GreDCSelectPen(local_3f0[0],*(undefined8 *)(*(long *)(local_3f0[0] + 0x3d0) + 0xa8));
    }
    PATHSTACKOBJ::PATHSTACKOBJ(aPStack_2f0,(XDCOBJ *)local_3f0,(uint)(uVar2 == 1));
    if (local_2e8 != 0) {
      DC::QuickInitXform(local_3f0[0],(ulong)aEStack_380);
      EBOX::EBOX((EBOX *)&local_340,(XDCOBJ *)local_3f0,(_RECTL *)&local_350,
                 (_LINEATTRS *)(local_3f0[0] + 0xd0),1);
      if (local_33c == 0) {
        if (local_340 == 0) {
          efHalfDiff((ulong)local_2fc,(ulong)(uint)-local_2f4);
          uVar3 = efHalfDiff((ulong)local_300,(ulong)(uint)-local_2f8);
          local_410 = 0.0;
          fStack_40c = 0.0;
          uVar7 = 0;
          local_408 = 0;
          uStack_404 = 0;
          if ((uVar3 == extraout_w9) || (extraout_w10 == extraout_w11)) {
            local_410 = *(float *)FP_0_0_exref;
            fStack_40c = local_410;
          }
          else {
            efHalfDiff((ulong)extraout_w9,(ulong)uVar3);
            fVar10 = (float)efHalfDiff(extraout_x10 & 0xffffffff,extraout_x11 & 0xffffffff);
            vArctan(((float)param_7 - extraout_s20) / extraout_s19,
                    ((float)param_8 - extraout_s21) / fVar10,&fStack_40c,&local_408);
            vArctan(((float)param_11 - extraout_s20_00) / extraout_s19_00,
                    ((float)param_12 - extraout_s21_00) / extraout_s18,&local_410,&uStack_404);
            uVar7 = (ulong)local_408;
          }
          fVar10 = local_410 - fStack_40c;
          if (fVar10 < 0.0) {
            fVar10 = -fVar10;
          }
          uVar3 = uStack_404;
          if (fVar10 - *(float *)FP_3_0_exref < 0.0 && fVar10 != 0.0) {
            vCosSinPrecise(fStack_40c,aEStack_3f8,auStack_3f4);
            vCosSinPrecise(extraout_s24_01,aEStack_400,auStack_3fc);
            fVar10 = extraout_s24_02;
            fVar11 = extraout_s25_00;
          }
          else {
            vCosSin();
            vCosSin(extraout_s24,aEStack_400,auStack_3fc);
            fVar10 = extraout_s24_00;
            fVar11 = extraout_s25;
          }
          if (((uint)uVar7 != uVar3) || (uVar8 = 0, fVar10 <= fVar11)) {
            uVar8 = 1;
          }
          PVar9 = 1;
          if (uVar2 == 1) {
            PVar9 = 2;
          }
          iVar4 = bPartialArc(PVar9,(EPATHOBJ *)aPStack_2f0,(EBOX *)&local_340,aEStack_3f8,uVar7,
                              (EFLOAT *)&fStack_40c,aEStack_400,(ulong)uVar3,(EFLOAT *)&local_410,
                              CONCAT44(in_stack_fffffffffffffbec,uVar8));
          if (iVar4 == 0) goto LAB_1401a29d0;
          if (uVar2 == 1) {
            *(uint *)(*(long *)(local_3f0[0] + 0x3d0) + 0x98) =
                 *(uint *)(*(long *)(local_3f0[0] + 0x3d0) + 0x98) | 0x100;
            *(uint *)(*(long *)(local_3f0[0] + 0x3d0) + 0x98) =
                 *(uint *)(*(long *)(local_3f0[0] + 0x3d0) + 0x98) & 0xfffffdff;
            puVar5 = (undefined8 *)EPATHOBJ::ptfxGetCurrent((EPATHOBJ *)aPStack_2f0);
            *(undefined8 *)(*(long *)(local_3f0[0] + 0x3d0) + 8) = *puVar5;
LAB_1401a2904:
            if ((*(uint *)(local_3f0[0] + 0xf8) & 1) == 0) {
              iVar4 = 0;
              if (uVar2 < 2) {
                uVar7 = 1;
LAB_1401a2930:
                iVar4 = EPATHOBJ_bStrokeAndOrFill
                                  ((EPATHOBJ *)aPStack_2f0,(XDCOBJ *)local_3f0,
                                   (_LINEATTRS *)(local_3f0[0] + 0xd0),aEStack_380,uVar7);
              }
              else if (uVar2 == 2 || uVar2 == 3) {
                uVar7 = 3;
                goto LAB_1401a2930;
              }
              EPATHOBJ::vUnlock((EPATHOBJ *)aPStack_2f0);
              PATH_CORE::~PATH_CORE(aPStack_260);
              CAutoTGO::vUnguard(aCStack_2a0);
              if (local_388 != '\0') {
                XDCOBJ::vUnlockNoNullSet((XDCOBJ *)local_3f0);
              }
              goto LAB_1401a2a04;
            }
            iVar4 = 1;
          }
          else {
            if (uVar2 != 2) {
              if (uVar2 == 3) {
                local_378 = auStack_318;
                local_368 = 0;
                uStack_370 = 1;
                local_360 = 0;
                bVar1 = EPATHOBJ::bPolyLineTo
                                  ((EPATHOBJ *)aPStack_2f0,(EXFORMOBJR *)0x0,
                                   (umptr_r<_POINTL> *)&local_378,1);
                if ((!bVar1) || (bVar1 = EPATHOBJ::bCloseFigure((EPATHOBJ *)aPStack_2f0), !bVar1))
                goto LAB_1401a29d0;
              }
              goto LAB_1401a2904;
            }
            bVar1 = EPATHOBJ::bCloseFigure((EPATHOBJ *)aPStack_2f0);
            if (bVar1) goto LAB_1401a2904;
            iVar4 = 0;
          }
          PATHSTACKOBJ::~PATHSTACKOBJ(aPStack_2f0);
          APIDCOBJ::~APIDCOBJ((APIDCOBJ *)local_3f0);
          goto LAB_1401a2730;
        }
        EPATHOBJ::vUnlock((EPATHOBJ *)aPStack_2f0);
        PATH_CORE::~PATH_CORE(aPStack_260);
        CAutoTGO::vUnguard(aCStack_2a0);
        if (local_388 != '\0') {
          XDCOBJ::vUnlockNoNullSet((XDCOBJ *)local_3f0);
        }
        iVar4 = 1;
      }
      else {
LAB_1401a29d0:
        EPATHOBJ::vUnlock((EPATHOBJ *)aPStack_2f0);
        PATH_CORE::~PATH_CORE(aPStack_260);
        CAutoTGO::vUnguard(aCStack_2a0);
        if (local_388 != '\0') {
          XDCOBJ::vUnlockNoNullSet((XDCOBJ *)local_3f0);
        }
        iVar4 = 0;
      }
LAB_1401a2a04:
      local_3f0[0] = (DC *)0x0;
      PopThreadGuardedObject(auStack_3a8);
      XDCOBJ::vUnlockNoNullSet((XDCOBJ *)local_3f0);
      PopThreadGuardedObject(auStack_3c8);
      goto LAB_1401a2730;
    }
    EngSetLastError(8);
    PATHSTACKOBJ::~PATHSTACKOBJ(aPStack_2f0);
  }
  APIDCOBJ::~APIDCOBJ((APIDCOBJ *)local_3f0);
  iVar4 = 0;
LAB_1401a2730:
  __security_pop_cookie(iVar4);
  return;
}



/* 140216460  GrePolyBezierTo  880 bytes, 0 callers */

void GrePolyBezierTo(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  undefined8 *puVar5;
  undefined8 uVar6;
  uint uVar7;
  undefined1 auVar8 [16];
  DC *local_390;
  undefined4 local_388;
  SESSION_GLOBALS *local_380;
  undefined8 uStack_378;
  undefined4 local_370;
  UnexpectedThreadTerminationHandler<DCOBJ> aUStack_368 [32];
  UnexpectedThreadTerminationHandler<APIDCOBJ> aUStack_348 [32];
  char local_328;
  undefined8 local_320;
  undefined8 local_318;
  undefined1 local_310;
  long local_308;
  ulong uStack_300;
  undefined8 local_2f8;
  undefined2 local_2f0;
  PATHSTACKOBJ aPStack_2e8 [8];
  long local_2e0;
  CAutoTGO aCStack_298 [64];
  PATH_CORE aPStack_258 [552];
  
  auVar8 = __security_push_cookie();
  local_380 = Gre::Base::Globals();
  local_390 = (DC *)0x0;
  local_388 = 0;
  uStack_378 = 0;
  local_370 = 0;
  UnexpectedThreadTerminationHandler<DCOBJ>::UnexpectedThreadTerminationHandler<DCOBJ>(aUStack_368);
  XDCOBJ::vLock((XDCOBJ *)&local_390,auVar8._0_8_);
  UnexpectedThreadTerminationHandler<APIDCOBJ>::UnexpectedThreadTerminationHandler<APIDCOBJ>
            (aUStack_348);
  local_328 = '\x01';
  if (local_390 != (DC *)0x0) {
    if (*(short *)(local_390 + 0xc) != 1) {
      MicrosoftTelemetryAssertTriggeredNoArgsKM();
    }
    if (*(short *)(local_390 + 0xc) != 1) {
      XDCOBJ::vUnlockNoNullSet((XDCOBJ *)&local_390);
      local_390 = (DC *)0x0;
    }
  }
  if ((local_390 == (DC *)0x0) || ((*(uint *)(local_390 + 0x24) >> 0x10 & 1) != 0)) {
    EngSetLastError(6);
LAB_1402166e4:
    if (local_328 != '\0') {
      XDCOBJ::vUnlockNoNullSet((XDCOBJ *)&local_390);
    }
    local_390 = (DC *)0x0;
    PopThreadGuardedObject(aUStack_348);
    XDCOBJ::vUnlockNoNullSet((XDCOBJ *)&local_390);
    PopThreadGuardedObject(aUStack_368);
  }
  else {
    uVar7 = (uint)param_3;
    if ((2 < uVar7) &&
       (uVar7 == ((uint)((param_3 & 0xffffffff) * 0xaaaaaaab >> 0x20) & 0xfffffffe) +
                 (int)((param_3 & 0xffffffff) / 3))) {
      uVar2 = *(uint *)(*(long *)(local_390 + 0x3d0) + 0x98);
      if ((uVar2 >> 0xc & 1) != 0) {
        GreDCSelectBrush(local_390,*(undefined8 *)(*(long *)(local_390 + 0x3d0) + 0xa0));
      }
      if ((uVar2 >> 0xd & 1) != 0) {
        GreDCSelectPen(local_390,*(undefined8 *)(*(long *)(local_390 + 0x3d0) + 0xa8));
      }
      iVar4 = *(int *)(*(long *)(local_390 + 0x3d0) + 0xd0);
      DC::QuickInitXform(local_390,(ulong)&local_320);
      local_310 = iVar4 != 2;
      local_318 = local_320;
      PATHSTACKOBJ::PATHSTACKOBJ(aPStack_2e8,(XDCOBJ *)&local_390,1);
      if (local_2e0 == 0) {
        EngSetLastError(8);
      }
      else {
        local_2f8 = 0;
        local_2f0 = 0;
        local_308 = auVar8._8_8_;
        uStack_300 = param_3 & 0xffffffff;
        bVar3 = EPATHOBJ::bPolyBezierTo
                          ((EPATHOBJ *)aPStack_2e8,(EXFORMOBJR *)&local_318,
                           (umptr_r<_POINTL> *)&local_308,param_3 & 0xffffffff);
        if (bVar3) {
          if ((*(uint *)(local_2e0 + 0x48) & 1) == 0) {
            puVar5 = (undefined8 *)
                     (*(long *)(local_2e0 + 0x28) +
                     ((ulong)(*(int *)(*(long *)(local_2e0 + 0x28) + 0x14) - 1) + 3) * 8);
          }
          else {
            puVar5 = (undefined8 *)(local_2e0 + 0x40);
          }
          uVar6 = *puVar5;
          puVar1 = (undefined4 *)(auVar8._8_8_ + (ulong)(uVar7 - 1) * 8);
          *(uint *)(*(long *)(local_390 + 0x3d0) + 0x98) =
               *(uint *)(*(long *)(local_390 + 0x3d0) + 0x98) & 0xfffffcff;
          *(undefined4 *)(*(long *)(local_390 + 0x3d0) + 0xd8) = *puVar1;
          *(undefined4 *)(*(long *)(local_390 + 0x3d0) + 0xdc) = puVar1[1];
          *(int *)(*(long *)(local_390 + 0x3d0) + 8) = (int)uVar6;
          *(int *)(*(long *)(local_390 + 0x3d0) + 0xc) = (int)((ulong)uVar6 >> 0x20);
          if (((*(uint *)(local_390 + 0xf8) & 1) == 0) &&
             (iVar4 = EPATHOBJ_bStrokeAndOrFill
                                ((EPATHOBJ *)aPStack_2e8,(XDCOBJ *)&local_390,
                                 (_LINEATTRS *)(local_390 + 0xd0),(EXFORMOBJ *)&local_318,1),
             iVar4 == 0)) {
            uVar6 = 0;
          }
          else {
            uVar6 = 1;
          }
          EPATHOBJ::vUnlock((EPATHOBJ *)aPStack_2e8);
          PATH_CORE::~PATH_CORE(aPStack_258);
          CAutoTGO::vUnguard(aCStack_298);
          if (local_328 != '\0') {
            XDCOBJ::vUnlockNoNullSet((XDCOBJ *)&local_390);
          }
          local_390 = (DC *)0x0;
          PopThreadGuardedObject(aUStack_348);
          XDCOBJ::vUnlockNoNullSet((XDCOBJ *)&local_390);
          PopThreadGuardedObject(aUStack_368);
          goto LAB_140216690;
        }
      }
      EPATHOBJ::vUnlock((EPATHOBJ *)aPStack_2e8);
      PATH_CORE::~PATH_CORE(aPStack_258);
      CAutoTGO::vUnguard(aCStack_298);
      goto LAB_1402166e4;
    }
    EngSetLastError(0x57);
    APIDCOBJ::~APIDCOBJ((APIDCOBJ *)&local_390);
  }
  uVar6 = 0;
LAB_140216690:
  __security_pop_cookie(uVar6);
  return;
}



/* 140313ac8  GrepPolyBezier  428 bytes, 1 callers */

/* int __cdecl GrepPolyBezier(class XDCOBJ & __ptr64,struct tagPOINT * __ptr64,unsigned long) */

int GrepPolyBezier(XDCOBJ *param_1,tagPOINT *param_2,ulong param_3)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  XDCOBJ *pXVar5;
  long lVar6;
  undefined8 uVar7;
  undefined1 auVar8 [16];
  undefined8 local_300;
  undefined1 local_2f8;
  undefined8 local_2f0;
  PATHSTACKOBJ aPStack_2e8 [8];
  long local_2e0;
  
  auVar8 = __security_push_cookie();
  pXVar5 = auVar8._0_8_;
  lVar6 = *(long *)pXVar5;
  uVar2 = (uint)param_3;
  if ((*(uint *)(lVar6 + 0x24) >> 0x10 & 1) == 0) {
    if ((uVar2 < 4) ||
       (uVar2 - (((uint)((param_3 & 0xffffffff) * 0xaaaaaaab >> 0x20) & 0xfffffffe) +
                (int)((param_3 & 0xffffffff) / 3)) != 1)) {
      uVar7 = 0x57;
      goto LAB_140313c48;
    }
    uVar1 = *(uint *)(*(long *)(lVar6 + 0x3d0) + 0x98);
    if ((uVar1 >> 0xc & 1) != 0) {
      GreDCSelectBrush(lVar6,*(undefined8 *)(*(long *)(lVar6 + 0x3d0) + 0xa0));
    }
    if ((uVar1 >> 0xd & 1) != 0) {
      GreDCSelectPen(*(long *)pXVar5,*(undefined8 *)(*(long *)(*(long *)pXVar5 + 0x3d0) + 0xa8));
    }
    iVar4 = *(int *)(*(long *)(*(DC **)pXVar5 + 0x3d0) + 0xd0);
    DC::QuickInitXform(*(DC **)pXVar5,(ulong)&local_2f0);
    local_2f8 = iVar4 != 2;
    local_300 = local_2f0;
    PATHSTACKOBJ::PATHSTACKOBJ(aPStack_2e8,pXVar5,1);
    if (local_2e0 == 0) {
      EngSetLastError(8);
    }
    else {
      bVar3 = EPATHOBJ::bMoveTo((EPATHOBJ *)aPStack_2e8,(EXFORMOBJR *)&local_300,auVar8._8_8_);
      if ((bVar3) &&
         (bVar3 = EPATHOBJ::bPolyBezierTo
                            ((EPATHOBJ *)aPStack_2e8,(EXFORMOBJR *)&local_300,auVar8._8_8_ + 8,
                             (ulong)(uVar2 - 1)), bVar3)) {
        if (((*(uint *)(*(long *)pXVar5 + 0xf8) & 1) == 0) &&
           (iVar4 = EPATHOBJ_bStrokeAndOrFill
                              ((EPATHOBJ *)aPStack_2e8,pXVar5,(_LINEATTRS *)(*(long *)pXVar5 + 0xd0)
                               ,(EXFORMOBJ *)&local_300,1), iVar4 == 0)) {
          uVar7 = 0;
        }
        else {
          uVar7 = 1;
        }
        PATHSTACKOBJ::~PATHSTACKOBJ(aPStack_2e8);
        goto LAB_140313c58;
      }
    }
    PATHSTACKOBJ::~PATHSTACKOBJ(aPStack_2e8);
  }
  else {
    uVar7 = 6;
LAB_140313c48:
    EngSetLastError(uVar7);
  }
  uVar7 = 0;
LAB_140313c58:
  iVar4 = __security_pop_cookie(uVar7);
  return iVar4;
}



/* 140313c80  GrePolyBezier  252 bytes, 0 callers */

void GrePolyBezier(undefined8 param_1,undefined8 param_2,ulong param_3)

{
  int iVar1;
  int iVar2;
  undefined1 auVar3 [16];
  long local_e0 [14];
  DWMSCREENREADMODIFYWRITEASSIST aDStack_70 [24];
  undefined1 *local_58;
  
  auVar3 = __security_push_cookie();
  iVar2 = 0;
  APIDCOBJ::APIDCOBJ((APIDCOBJ *)local_e0,auVar3._0_8_);
  if (local_e0[0] == 0) {
    EngSetLastError(6);
    iVar1 = 0;
  }
  else {
    local_58 = (undefined1 *)local_e0;
    iVar1 = DWMSCREENREADMODIFYWRITEASSIST::bDWMDesktop(aDStack_70);
    if ((iVar1 != 0) &&
       (iVar1 = DWMSCREENREADMODIFYWRITEASSIST::bInPathBracket(aDStack_70), iVar1 == 0)) {
      DWMSCREENREADMODIFYWRITEASSIST::vSaveAccumBoundsAndDisableSpriteUpdates(aDStack_70);
      iVar1 = GrepPolyBezier((XDCOBJ *)local_e0,auVar3._8_8_,param_3 & 0xffffffff);
      iVar2 = 0;
      if (iVar1 != 0) {
        iVar2 = DWMSCREENREADMODIFYWRITEASSIST::bReadFromAccumulatedBounds(aDStack_70);
      }
      DWMSCREENREADMODIFYWRITEASSIST::vRestoreAccumBoundsAndEnableSpriteUpdates(aDStack_70);
    }
    iVar1 = GrepPolyBezier((XDCOBJ *)local_e0,auVar3._8_8_,param_3 & 0xffffffff);
    if (iVar2 != 0) {
      UserReferenceDwmApiPort();
      DwmSyncFlushAndWaitForBatch();
    }
  }
  APIDCOBJ::~APIDCOBJ((APIDCOBJ *)local_e0);
  __security_pop_cookie(iVar1);
  return;
}


