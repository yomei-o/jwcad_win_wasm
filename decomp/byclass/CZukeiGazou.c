/* CZukeiGazou -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiGazou[1] */
/* 0066a6f0  FUN_0066a6f0  68 bytes, 0 callers */

undefined4 FUN_0066a6f0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0066a6b0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x628);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiGazou[6] */
/* 0066aab0  FUN_0066aab0  6045 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066aab0(undefined8 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  float10 fVar4;
  undefined4 uVar5;
  undefined1 auStack_1945c [8];
  undefined1 auStack_19454 [8];
  undefined1 auStack_1944c [8];
  undefined1 auStack_19444 [8];
  undefined1 auStack_1943c [36];
  undefined4 uStack_19418;
  undefined1 auStack_19414 [8];
  undefined1 auStack_1940c [20];
  undefined1 auStack_193f8 [20];
  undefined4 uStack_193e4;
  undefined4 uStack_193e0;
  undefined4 uStack_193dc;
  undefined4 uStack_193d8;
  undefined1 auStack_193d4 [20];
  int iStack_193c0;
  undefined1 auStack_193bc [4];
  int iStack_193b8;
  undefined1 auStack_193b4 [20];
  int *piStack_193a0;
  int *piStack_1939c;
  int *piStack_19398;
  int iStack_19394;
  int iStack_19390;
  undefined1 local_44c [152];
  undefined1 local_3b4 [16];
  undefined1 local_3a4 [16];
  undefined1 local_394 [16];
  undefined1 local_384 [16];
  undefined1 local_374 [16];
  undefined1 local_364 [16];
  undefined1 local_354 [16];
  undefined1 local_344 [16];
  undefined1 local_334 [16];
  undefined1 local_324 [16];
  undefined1 local_314 [16];
  undefined1 local_304 [16];
  undefined1 local_2f4 [16];
  undefined1 local_2e4 [16];
  undefined1 local_2d4 [16];
  undefined1 local_2c4 [16];
  undefined1 local_2b4 [16];
  undefined1 local_2a4 [16];
  undefined1 local_294 [16];
  undefined1 local_284 [16];
  undefined1 local_274 [16];
  undefined1 local_264 [16];
  undefined1 local_254 [16];
  undefined1 local_244 [16];
  undefined1 local_234 [16];
  undefined1 local_224 [120];
  undefined1 local_1ac [24];
  undefined8 local_194;
  undefined8 local_18c;
  undefined1 local_144 [24];
  undefined8 local_12c;
  undefined8 local_124;
  undefined1 local_dc [24];
  undefined8 local_c4;
  undefined8 local_bc;
  undefined4 local_74;
  undefined4 uStack_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined8 local_64;
  undefined8 uStack_5c;
  undefined8 uStack_54;
  undefined8 uStack_4c;
  undefined8 uStack_44;
  undefined8 uStack_3c;
  undefined8 uStack_34;
  undefined8 uStack_2c;
  undefined8 uStack_24;
  undefined8 uStack_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939a5a;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(local_14);
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) != *(int *)(*(int *)(iStack_19390 + 4) + 0x8664)) {
    ExceptionList = local_10;
    return;
  }
  uVar5 = *(undefined4 *)(iStack_19390 + 0x614);
  FUN_00404c80(uVar5);
  FUN_004fca20();
  FUN_004c5ab0(uVar5);
  if (*(int *)(*(int *)(iStack_19390 + 4) + 0x8560) == 0) {
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(iStack_19390 + 4));
    local_8._0_1_ = 1;
    FUN_0041f760();
    local_8._0_1_ = 2;
    FUN_0044dd90(auStack_1940c,*(undefined4 *)(iStack_19390 + 4));
    if (*(int *)(iStack_19390 + 0x614) != 0) {
      FUN_004efbb0(0x1521,0,0);
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    iVar1 = FUN_00671530();
    if (iVar1 != 0) {
      FUN_004efbb0(0x27a3,0,0);
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    iVar1 = FUN_006713d0();
    if (iVar1 != 0) {
      FUN_004efbb0(0x27a5,0,0);
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    iVar1 = FUN_00671590();
    if (iVar1 != 0) {
      FUN_004efbb0(0x27a9,0,0);
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    iVar1 = FUN_006714d0();
    if (iVar1 != 0) {
      FUN_004efbb0(0x27bb,0,0);
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    iVar1 = FUN_00671430();
    if (iVar1 != 0) {
      FUN_004efbb0(0x27aa,0,0);
      local_8._0_1_ = 1;
      FUN_0041fd70();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    local_8._0_1_ = 1;
    FUN_0041fd70();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  if (*(int *)(*(int *)(iStack_19390 + 4) + 0x8560) != 1) goto LAB_0066b8a8;
  FUN_00446aa0();
  local_8 = 3;
  FUN_0079dea2(*(undefined4 *)(iStack_19390 + 4));
  local_8._0_1_ = 4;
  FUN_00464040();
  local_8._0_1_ = 5;
  FUN_0041f760();
  local_8._0_1_ = 6;
  FUN_0044dd90(auStack_193b4,*(undefined4 *)(iStack_19390 + 4));
  piStack_19398 = (int *)FUN_006715f0();
  if (piStack_19398 == (int *)0x0) {
    *(undefined4 *)(*(int *)(iStack_19390 + 4) + 0x8560) = 0;
    local_8._0_1_ = 5;
    FUN_0041fd70();
    local_8._0_1_ = 4;
    FUN_004640a0();
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  FUN_00450b70(auStack_193b4,*(undefined4 *)(iStack_19390 + 4),piStack_19398);
  iVar1 = FUN_00671430();
  if (iVar1 == 0) {
    iVar1 = FUN_00671530();
    if (iVar1 == 0) {
      iVar1 = FUN_00671490();
      if (iVar1 == 0) {
        puVar3 = (undefined4 *)
                 FUN_004988c0(local_364,*(undefined4 *)(iStack_19390 + 0x10),
                              *(undefined4 *)(iStack_19390 + 0x14),
                              *(undefined4 *)(iStack_19390 + 0x18),
                              *(undefined4 *)(iStack_19390 + 0x1c));
        FUN_004988c0(local_374,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
        local_12c = *param_1;
        FUN_00450b70(auStack_193b4,*(undefined4 *)(iStack_19390 + 4),local_144);
        FUN_004988c0(local_384,(undefined4)local_12c,local_12c._4_4_,(undefined4)local_124,
                     local_124._4_4_);
        local_124 = param_1[1];
        FUN_00450b70(auStack_193b4,*(undefined4 *)(iStack_19390 + 4),local_144);
        FUN_004988c0(local_394,(undefined4)local_12c,local_12c._4_4_,(undefined4)local_124,
                     local_124._4_4_);
        local_12c = *(undefined8 *)(iStack_19390 + 0x10);
        FUN_00450b70(auStack_193b4,*(undefined4 *)(iStack_19390 + 4),local_144);
        FUN_004988c0(local_3a4,(undefined4)local_12c,local_12c._4_4_,(undefined4)local_124,
                     local_124._4_4_);
        local_124 = *(undefined8 *)(iStack_19390 + 0x18);
        FUN_00450b70(auStack_193b4,*(undefined4 *)(iStack_19390 + 4),local_144);
      }
      else {
        FUN_0066a760(*(undefined4 *)(iStack_19390 + 0x10),*(undefined4 *)(iStack_19390 + 0x14),
                     *(undefined4 *)(iStack_19390 + 0x18),*(undefined4 *)(iStack_19390 + 0x1c),
                     *(undefined4 *)param_1,*(undefined4 *)((int)param_1 + 4),
                     *(undefined4 *)(param_1 + 1),*(undefined4 *)((int)param_1 + 0xc));
      }
    }
    else {
      CStringT<>();
      local_8 = CONCAT31(local_8._1_3_,8);
      uStack_193d8 = 0xff;
      uStack_193dc = 0xff;
      uStack_193e0 = 0xff;
      uStack_19418 = FUN_0048efe0(auStack_193bc,auStack_1943c,auStack_19444,auStack_1944c,
                                  auStack_19454,auStack_1945c,auStack_19414,&uStack_193d8,
                                  &uStack_193dc,&uStack_193e0);
      FUN_005f89c0(*(undefined4 *)(iStack_19390 + 0x10),*(undefined4 *)(iStack_19390 + 0x14),
                   *(undefined4 *)(iStack_19390 + 0x18),*(undefined4 *)(iStack_19390 + 0x1c),
                   auStack_19414._0_4_,auStack_19414._4_4_,0);
      local_74 = *(undefined4 *)param_1;
      uStack_70 = *(undefined4 *)((int)param_1 + 4);
      local_6c = *(undefined4 *)(param_1 + 1);
      uStack_68 = *(undefined4 *)((int)param_1 + 0xc);
      FUN_005f92e0(&local_74);
      FUN_00404b80(&local_64,0x10,5,FUN_00408a60);
      local_64 = 0;
      uStack_5c = 0;
      uStack_54 = CONCAT44(uStack_70,local_74);
      uStack_4c = 0;
      uStack_44 = CONCAT44(uStack_70,local_74);
      uStack_3c = CONCAT44(uStack_68,local_6c);
      uStack_34 = 0;
      uStack_2c = CONCAT44(uStack_68,local_6c);
      uStack_24 = 0;
      uStack_1c = 0;
      for (iStack_19394 = 0; iStack_19394 < 5; iStack_19394 = iStack_19394 + 1) {
        FUN_005f8ce0(&local_64 + iStack_19394 * 2);
      }
      for (iStack_19394 = 0; iStack_19394 < 4; iStack_19394 = iStack_19394 + 1) {
        FUN_004988c0(local_344,*(undefined4 *)(&local_64 + iStack_19394 * 2),
                     *(undefined4 *)((int)&local_64 + iStack_19394 * 0x10 + 4),
                     *(undefined4 *)(&uStack_5c + iStack_19394 * 2),
                     *(undefined4 *)((int)&uStack_5c + iStack_19394 * 0x10 + 4));
        iVar1 = iStack_19394 + 1;
        FUN_004988c0(local_354,*(undefined4 *)(&local_64 + iVar1 * 2),
                     *(undefined4 *)((int)&local_64 + iVar1 * 0x10 + 4),
                     *(undefined4 *)(&uStack_5c + iVar1 * 2),
                     *(undefined4 *)((int)&uStack_5c + iVar1 * 0x10 + 4));
        FUN_00450b70(auStack_193b4,*(undefined4 *)(iStack_19390 + 4),local_144);
      }
      local_8._0_1_ = 6;
      FUN_00404540();
    }
  }
  else {
    FUN_0041f5f0();
    local_8 = CONCAT31(local_8._1_3_,7);
    FUN_004988c0(local_304,*(undefined4 *)(iStack_19390 + 0x10),*(undefined4 *)(iStack_19390 + 0x14)
                 ,*(undefined4 *)(iStack_19390 + 0x18),*(undefined4 *)(iStack_19390 + 0x1c));
    fVar4 = (float10)FUN_004b6e50(10);
    FUN_0042f5e0((double)fVar4);
    FUN_00450b70(auStack_193b4,*(undefined4 *)(iStack_19390 + 4),local_44c);
    FUN_004988c0(local_314,*(undefined4 *)param_1,*(undefined4 *)((int)param_1 + 4),
                 *(undefined4 *)(param_1 + 1),*(undefined4 *)((int)param_1 + 0xc));
    fVar4 = (float10)FUN_004b6e50(6);
    FUN_0042f5e0((double)fVar4);
    FUN_00450b70(auStack_193b4,*(undefined4 *)(iStack_19390 + 4),local_44c);
    iVar1 = FUN_004b8250((int)*(undefined8 *)(iStack_19390 + 0x10),
                         (int)((ulonglong)*(undefined8 *)(iStack_19390 + 0x10) >> 0x20));
    iVar2 = FUN_004b8250((int)*param_1,(int)((ulonglong)*param_1 >> 0x20));
    if (iVar1 == iVar2) {
      iVar1 = FUN_004b8250((int)*(undefined8 *)(iStack_19390 + 0x18),
                           (int)((ulonglong)*(undefined8 *)(iStack_19390 + 0x18) >> 0x20));
      iVar2 = FUN_004b8250((int)param_1[1],(int)((ulonglong)param_1[1] >> 0x20));
      if (iVar1 != iVar2) goto LAB_0066b0aa;
    }
    else {
LAB_0066b0aa:
      piStack_193a0 = (int *)(**(code **)(*piStack_19398 + 0x14))();
      FUN_0046bdf0(*(undefined4 *)(iStack_19390 + 0x10),*(undefined4 *)(iStack_19390 + 0x14),
                   *(undefined4 *)(iStack_19390 + 0x18),*(undefined4 *)(iStack_19390 + 0x1c),
                   piStack_193a0,*(undefined4 *)param_1,*(undefined4 *)((int)param_1 + 4),
                   *(undefined4 *)(param_1 + 1),*(undefined4 *)((int)param_1 + 0xc),0,0);
      FUN_00450b70(auStack_193b4,*(undefined4 *)(iStack_19390 + 4),piStack_193a0);
      piStack_1939c = piStack_193a0;
      if (piStack_193a0 == (int *)0x0) {
        uStack_193e4 = 0;
      }
      else {
        uStack_193e4 = (**(code **)(*piStack_193a0 + 4))(1);
      }
      FUN_004988c0(local_324,*(undefined4 *)(iStack_19390 + 0x10),
                   *(undefined4 *)(iStack_19390 + 0x14),*(undefined4 *)(iStack_19390 + 0x18),
                   *(undefined4 *)(iStack_19390 + 0x1c));
      FUN_004988c0(local_334,*(undefined4 *)param_1,*(undefined4 *)((int)param_1 + 4),
                   *(undefined4 *)(param_1 + 1),*(undefined4 *)((int)param_1 + 0xc));
      FUN_00450b70(auStack_193b4,*(undefined4 *)(iStack_19390 + 4),local_144);
    }
    local_8._0_1_ = 6;
    FUN_0041fd50();
  }
  iVar1 = FUN_00671530();
  if (iVar1 != 0) {
    FUN_004efbb0(0x27a4,0,0);
    local_8._0_1_ = 5;
    FUN_0041fd70();
    local_8._0_1_ = 4;
    FUN_004640a0();
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  iVar1 = FUN_006713d0();
  if (iVar1 != 0) {
    FUN_004efbb0(0x27a6,0,0);
    local_8._0_1_ = 5;
    FUN_0041fd70();
    local_8._0_1_ = 4;
    FUN_004640a0();
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  iVar1 = FUN_00671430();
  if (iVar1 != 0) {
    FUN_004efbb0(0x27ab,0,0);
    local_8._0_1_ = 5;
    FUN_0041fd70();
    local_8._0_1_ = 4;
    FUN_004640a0();
    local_8 = CONCAT31(local_8._1_3_,3);
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  local_8._0_1_ = 5;
  FUN_0041fd70();
  local_8._0_1_ = 4;
  FUN_004640a0();
  local_8 = CONCAT31(local_8._1_3_,3);
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
LAB_0066b8a8:
  if (*(int *)(*(int *)(iStack_19390 + 4) + 0x8560) == 2) {
    FUN_00446aa0();
    local_8 = 9;
    FUN_0079dea2(*(undefined4 *)(iStack_19390 + 4));
    local_8._0_1_ = 10;
    FUN_0041f760();
    local_8._0_1_ = 0xb;
    FUN_0044dd90(auStack_193f8,*(undefined4 *)(iStack_19390 + 4));
    iStack_193b8 = FUN_006715f0();
    if (iStack_193b8 == 0) {
      *(undefined4 *)(*(int *)(iStack_19390 + 4) + 0x8560) = 0;
      local_8._0_1_ = 10;
      FUN_0041fd70();
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    FUN_00450b70(auStack_193f8,*(undefined4 *)(iStack_19390 + 4),iStack_193b8);
    iVar1 = FUN_00671490();
    if (iVar1 == 0) {
      puVar3 = (undefined4 *)
               FUN_004988c0(local_234,*(undefined4 *)(iStack_19390 + 0x10),
                            *(undefined4 *)(iStack_19390 + 0x14),
                            *(undefined4 *)(iStack_19390 + 0x18),
                            *(undefined4 *)(iStack_19390 + 0x1c));
      FUN_004988c0(local_2e4,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
      local_194 = *(undefined8 *)(iStack_19390 + 0x20);
      FUN_00450b70(auStack_193f8,*(undefined4 *)(iStack_19390 + 4),local_1ac);
      FUN_004988c0(local_2d4,(undefined4)local_194,local_194._4_4_,(undefined4)local_18c,
                   local_18c._4_4_);
      local_18c = *(undefined8 *)(iStack_19390 + 0x28);
      FUN_00450b70(auStack_193f8,*(undefined4 *)(iStack_19390 + 4),local_1ac);
      FUN_004988c0(local_2c4,(undefined4)local_194,local_194._4_4_,(undefined4)local_18c,
                   local_18c._4_4_);
      local_194 = *(undefined8 *)(iStack_19390 + 0x10);
      FUN_00450b70(auStack_193f8,*(undefined4 *)(iStack_19390 + 4),local_1ac);
      FUN_004988c0(local_2b4,(undefined4)local_194,local_194._4_4_,(undefined4)local_18c,
                   local_18c._4_4_);
      local_18c = *(undefined8 *)(iStack_19390 + 0x18);
      FUN_00450b70(auStack_193f8,*(undefined4 *)(iStack_19390 + 4),local_1ac);
    }
    else {
      FUN_0066a760(*(undefined4 *)(iStack_19390 + 0x10),*(undefined4 *)(iStack_19390 + 0x14),
                   *(undefined4 *)(iStack_19390 + 0x18),*(undefined4 *)(iStack_19390 + 0x1c),
                   *(undefined4 *)(iStack_19390 + 0x20),*(undefined4 *)(iStack_19390 + 0x24),
                   *(undefined4 *)(iStack_19390 + 0x28),*(undefined4 *)(iStack_19390 + 0x2c));
    }
    iVar1 = FUN_006713d0();
    if (iVar1 != 0) {
      FUN_004efbb0(0x27a7,0,0);
      local_8._0_1_ = 10;
      FUN_0041fd70();
      local_8 = CONCAT31(local_8._1_3_,9);
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    local_8._0_1_ = 10;
    FUN_0041fd70();
    local_8 = CONCAT31(local_8._1_3_,9);
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  if (*(int *)(*(int *)(iStack_19390 + 4) + 0x8560) == 3) {
    FUN_00446aa0();
    local_8 = 0xc;
    FUN_0079dea2(*(undefined4 *)(iStack_19390 + 4));
    local_8._0_1_ = 0xd;
    FUN_0041f760();
    local_8._0_1_ = 0xe;
    FUN_0044dd90(auStack_193d4,*(undefined4 *)(iStack_19390 + 4));
    iStack_193c0 = FUN_006715f0();
    if (iStack_193c0 == 0) {
      *(undefined4 *)(*(int *)(iStack_19390 + 4) + 0x8560) = 0;
      local_8._0_1_ = 0xd;
      FUN_0041fd70();
      local_8 = CONCAT31(local_8._1_3_,0xc);
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      FUN_00450b70(auStack_193d4,*(undefined4 *)(iStack_19390 + 4),iStack_193c0);
      iVar1 = FUN_00671490();
      if (iVar1 == 0) {
        puVar3 = (undefined4 *)
                 FUN_004988c0(local_2a4,*(undefined4 *)(iStack_19390 + 0x10),
                              *(undefined4 *)(iStack_19390 + 0x14),
                              *(undefined4 *)(iStack_19390 + 0x18),
                              *(undefined4 *)(iStack_19390 + 0x1c));
        FUN_004988c0(local_294,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
        local_c4 = *(undefined8 *)(iStack_19390 + 0x20);
        FUN_00450b70(auStack_193d4,*(undefined4 *)(iStack_19390 + 4),local_dc);
        FUN_004988c0(local_284,(undefined4)local_c4,local_c4._4_4_,(undefined4)local_bc,
                     local_bc._4_4_);
        local_bc = *(undefined8 *)(iStack_19390 + 0x28);
        FUN_00450b70(auStack_193d4,*(undefined4 *)(iStack_19390 + 4),local_dc);
        FUN_004988c0(local_274,(undefined4)local_c4,local_c4._4_4_,(undefined4)local_bc,
                     local_bc._4_4_);
        local_c4 = *(undefined8 *)(iStack_19390 + 0x10);
        FUN_00450b70(auStack_193d4,*(undefined4 *)(iStack_19390 + 4),local_dc);
        FUN_004988c0(local_264,(undefined4)local_c4,local_c4._4_4_,(undefined4)local_bc,
                     local_bc._4_4_);
        local_bc = *(undefined8 *)(iStack_19390 + 0x18);
        FUN_00450b70(auStack_193d4,*(undefined4 *)(iStack_19390 + 4),local_dc);
        puVar3 = (undefined4 *)
                 FUN_004988c0(local_254,*(undefined4 *)(iStack_19390 + 0x200),
                              *(undefined4 *)(iStack_19390 + 0x204),
                              *(undefined4 *)(iStack_19390 + 0x208),
                              *(undefined4 *)(iStack_19390 + 0x20c));
        FUN_004988c0(local_244,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
        local_c4 = *param_1;
        FUN_00450b70(auStack_193d4,*(undefined4 *)(iStack_19390 + 4),local_dc);
        FUN_004988c0(local_224,(undefined4)local_c4,local_c4._4_4_,(undefined4)local_bc,
                     local_bc._4_4_);
        local_bc = param_1[1];
        FUN_00450b70(auStack_193d4,*(undefined4 *)(iStack_19390 + 4),local_dc);
        FUN_004988c0(local_3b4,(undefined4)local_c4,local_c4._4_4_,(undefined4)local_bc,
                     local_bc._4_4_);
        local_c4 = *(undefined8 *)(iStack_19390 + 0x200);
        FUN_00450b70(auStack_193d4,*(undefined4 *)(iStack_19390 + 4),local_dc);
        FUN_004988c0(local_2f4,(undefined4)local_c4,local_c4._4_4_,(undefined4)local_bc,
                     local_bc._4_4_);
        local_bc = *(undefined8 *)(iStack_19390 + 0x208);
        FUN_00450b70(auStack_193d4,*(undefined4 *)(iStack_19390 + 4),local_dc);
      }
      else {
        FUN_0066a760(*(undefined4 *)(iStack_19390 + 0x10),*(undefined4 *)(iStack_19390 + 0x14),
                     *(undefined4 *)(iStack_19390 + 0x18),*(undefined4 *)(iStack_19390 + 0x1c),
                     *(undefined4 *)(iStack_19390 + 0x20),*(undefined4 *)(iStack_19390 + 0x24),
                     *(undefined4 *)(iStack_19390 + 0x28),*(undefined4 *)(iStack_19390 + 0x2c));
        FUN_0066a760(*(undefined4 *)(iStack_19390 + 0x200),*(undefined4 *)(iStack_19390 + 0x204),
                     *(undefined4 *)(iStack_19390 + 0x208),*(undefined4 *)(iStack_19390 + 0x20c),
                     *(undefined4 *)param_1,*(undefined4 *)((int)param_1 + 4),
                     *(undefined4 *)(param_1 + 1),*(undefined4 *)((int)param_1 + 0xc));
      }
      FUN_004efbb0(0x27a8,0,0);
      local_8._0_1_ = 0xd;
      FUN_0041fd70();
      local_8 = CONCAT31(local_8._1_3_,0xc);
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiGazou[16] */
/* 0066c260  FUN_0066c260  99 bytes, 0 callers */

undefined4 FUN_0066c260(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8664)) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x8560) < 1) {
      uVar2 = 0;
    }
    else {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CZukeiGazou[0] */
/* 0066c2d0  FUN_0066c2d0  16 bytes, 0 callers */

undefined ** FUN_0066c2d0(void)

{
  return &PTR_s_CZukeiGazou_0097862c;
}




/* vtable slots: CZukeiGazou[30] */
/* 0066c550  FUN_0066c550  1245 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066c550(void)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 *puVar5;
  undefined8 uVar6;
  undefined1 local_6470 [8];
  undefined1 *local_6468;
  undefined4 local_6464;
  undefined1 *local_6460;
  undefined4 local_645c;
  double local_6458;
  undefined4 local_6450;
  undefined4 local_644c;
  wchar_t local_6448 [2];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6444 [4];
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6440 [4];
  undefined4 local_643c;
  undefined4 local_6438;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6434;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6430;
  wchar_t *local_642c;
  wchar_t *local_6428;
  undefined1 local_6424 [4];
  undefined4 local_6420;
  undefined4 local_641c;
  double local_6418;
  undefined1 local_6410 [4];
  undefined1 local_640c [4];
  int local_6408;
  int local_6404;
  undefined1 local_6400 [4];
  undefined1 local_63fc [4];
  int local_63f8;
  allocator<char> local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939b38;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(*(int *)(in_ECX + 4) + 0x17d8) == 0x80f5) {
    local_63f8 = in_ECX;
    FUN_00446aa0();
    local_8 = 0;
    local_645c = 0;
    FUN_00660fa0(local_63f8 + 0x220);
    if (0 < DAT_00a0d620) {
      FUN_004044d0();
      FUN_00413f30();
      FUN_004146a0();
      puVar1 = (undefined8 *)FUN_0045d370();
      local_6450 = *(undefined4 *)puVar1;
      local_644c = *(undefined4 *)((int)puVar1 + 4);
      uVar6 = *puVar1;
      puVar5 = local_6470;
      std::allocator<char>::allocator<char>(local_24);
      piVar2 = (int *)FID_conflict_operator_(puVar5,uVar6);
      local_6408 = *piVar2 / 2;
      local_6404 = piVar2[1] / 2;
      FUN_004dbab0(local_6408);
    }
    iVar3 = FUN_006710b0();
    if (iVar3 == 0) {
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      CStringT<>();
      local_8._0_1_ = 1;
      local_6460 = &stack0xffff9b88;
      FUN_00403dd0(local_63fc);
      local_6464 = FUN_0044ef10(local_6410);
      local_8._0_1_ = 2;
      Mid(local_6400);
      local_8._0_1_ = 3;
      if (DAT_00a088f4 != 0) {
        FUN_00404900();
      }
      FUN_0044ff70();
      uVar4 = FUN_00404920();
      iVar3 = FUN_00429b90(uVar4);
      if (iVar3 < 1) {
        local_8._0_1_ = 2;
        FUN_00404540();
        local_8._0_1_ = 1;
        FUN_00404540();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00404540();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        CStringT<>();
        local_8._0_1_ = 4;
        *(undefined8 *)(local_63f8 + 0x620) = 0x4059000000000000;
        if (DAT_00a0ba78 <= 0.0) {
          local_6458 = -DAT_00a0ba78;
        }
        else {
          local_6458 = DAT_00a0ba78;
        }
        local_6418 = local_6458;
        if ((10.0 <= local_6458) && (local_6458 <= 1000.0)) {
          FUN_004059f0(local_640c,&DAT_0095590c,local_6458);
          *(double *)(local_63f8 + 0x620) = local_6418;
        }
        local_6468 = &stack0xffff9b88;
        FUN_00403dd0(local_63fc);
        local_6420 = FUN_00463de0(local_6424);
        local_8._0_1_ = 5;
        local_641c = local_6420;
        FUN_00404860();
        local_8._0_1_ = 4;
        FUN_00404540();
        local_642c = (wchar_t *)
                     ATL::operator+(local_6448,
                                    (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                     *)L"^@BM");
        local_8._0_1_ = 6;
        local_6428 = local_642c;
        local_6434 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                      *)ATL::operator+(local_6444,local_642c);
        local_8._0_1_ = 7;
        local_6430 = local_6434;
        local_643c = ATL::operator+(local_6440,local_6434);
        local_8._0_1_ = 8;
        local_6438 = local_643c;
        FUN_00404860();
        local_8._0_1_ = 7;
        FUN_00404540();
        local_8._0_1_ = 6;
        FUN_00404540();
        local_8._0_1_ = 4;
        FUN_00404540();
        *(undefined4 *)(local_63f8 + 0x614) = 1;
        FUN_00404c80();
        FUN_0056d7d0();
        local_8._0_1_ = 3;
        FUN_00404540();
        local_8._0_1_ = 2;
        FUN_00404540();
        local_8._0_1_ = 1;
        FUN_00404540();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00404540();
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiGazou[31] */
/* 0066ca30  FUN_0066ca30  1715 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066ca30(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined **ppuStack_64d8;
  uint uStack_64d4;
  undefined1 local_64d0 [8];
  undefined1 local_64c8 [8];
  undefined1 local_64c0 [8];
  undefined1 local_64b8 [8];
  undefined1 local_64b0 [8];
  undefined1 local_64a8 [8];
  undefined1 local_64a0 [8];
  undefined1 local_6498 [8];
  undefined1 local_6490 [8];
  undefined1 local_6488 [8];
  undefined1 local_6480 [8];
  undefined1 local_6478 [8];
  undefined1 *local_6470;
  undefined4 local_646c;
  undefined1 local_6468 [4];
  undefined4 local_6464;
  undefined4 local_6460;
  undefined4 local_645c;
  undefined *local_6458;
  undefined4 local_6454;
  undefined1 local_6450 [4];
  undefined4 local_644c;
  undefined4 local_6448;
  undefined4 local_6444;
  undefined *local_6440;
  undefined **local_643c;
  undefined4 local_6438;
  undefined4 local_6434;
  undefined1 local_6430 [4];
  undefined **local_642c;
  undefined **local_6428;
  undefined4 local_6424;
  undefined **local_6420;
  undefined **local_641c;
  undefined1 local_6418 [4];
  undefined1 local_6414 [8];
  int local_640c;
  int *local_6408;
  int *local_6404;
  undefined1 local_6400 [4];
  undefined *local_63fc;
  undefined1 local_63f8 [4];
  undefined **local_63f4;
  undefined **local_63f0;
  char local_63ea;
  char local_63e9;
  undefined4 local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939bb7;
  local_10 = ExceptionList;
  uStack_64d4 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0ef7c == 0) {
    local_63f4 = (undefined **)0x0;
    ppuStack_64d8 = (undefined **)0x66ca88;
    local_14 = uStack_64d4;
    FUN_00446aa0();
    local_8 = 0;
    ppuStack_64d8 = (undefined **)0x66ca9d;
    local_63e8 = FUN_0040c0e0();
    ppuStack_64d8 = (undefined **)0x66caae;
    local_63fc = (undefined *)FUN_00572030();
    ppuStack_64d8 = (undefined **)0x66cabf;
    iVar1 = FUN_00570c90();
    if (iVar1 == 0) {
      local_8 = 0xffffffff;
      ppuStack_64d8 = (undefined **)0x66cad5;
      FUN_00447100();
    }
    else {
      ppuStack_64d8 = (undefined **)0x66cae5;
      iVar1 = FUN_00571720();
      if (iVar1 == 0) {
        ppuStack_64d8 = (undefined **)0xffffffff;
        FUN_004f60a0(0x27b3,0);
        local_8 = 0xffffffff;
        ppuStack_64d8 = (undefined **)0x66cb0e;
        FUN_00447100();
      }
      else {
        ppuStack_64d8 = (undefined **)0xffffffff;
        iVar1 = FUN_004f60a0(0x27b0,1);
        if (iVar1 == 1) {
          while( true ) {
            ppuStack_64d8 = (undefined **)0x66cb53;
            iVar1 = FUN_004146c0();
            if (iVar1 != 0) break;
            ppuStack_64d8 = (undefined **)0x66cb68;
            local_6404 = (int *)FUN_00414c00();
            if (local_6404 == (int *)0x0) {
              local_646c = 0;
            }
            else {
              ppuStack_64d8 = (undefined **)0x1;
              local_646c = (**(code **)(*local_6404 + 4))();
            }
          }
          ppuStack_64d8 = (undefined **)0x66cbb1;
          RemoveAll();
          ppuStack_64d8 = (undefined **)0x66cbc2;
          FUN_00454510();
          while( true ) {
            ppuStack_64d8 = (undefined **)0x66cbd3;
            iVar1 = FUN_004146c0();
            if (iVar1 != 0) break;
            ppuStack_64d8 = (undefined **)0x66cbe8;
            local_6408 = (int *)FUN_00414c00();
            if (local_6408 == (int *)0x0) {
              local_6424 = 0;
            }
            else {
              ppuStack_64d8 = (undefined **)0x1;
              local_6424 = (**(code **)(*local_6408 + 4))();
            }
          }
          ppuStack_64d8 = (undefined **)0x66cc31;
          RemoveAll();
          ppuStack_64d8 = (undefined **)0x66cc42;
          FUN_00454510();
          ppuStack_64d8 = (undefined **)0x66cc4d;
          CStringT<>();
          local_8._0_1_ = 1;
          local_6434 = DAT_00a0b410;
          DAT_00a0ef7c = 1;
          ppuStack_64d8 = (undefined **)0x1;
          ppuStack_64d8 = (undefined **)FUN_0044ea50(local_6430);
          local_8._0_1_ = 2;
          local_642c = ppuStack_64d8;
          local_6428 = ppuStack_64d8;
          FUN_00404860();
          local_8 = CONCAT31(local_8._1_3_,1);
          ppuStack_64d8 = (undefined **)0x66ccb2;
          FUN_00404540();
          local_6438 = DAT_00a0b3e8;
          DAT_00a0b3e8 = 700;
          local_6470 = (undefined1 *)&ppuStack_64d8;
          FUN_00403dd0(local_6418);
          FUN_004dcbf0(local_63e8,local_6434);
          DAT_00a0b3e8 = local_6438;
          DAT_00a0ef7c = 0;
          local_643c = (undefined **)0x0;
          ppuStack_64d8 = (undefined **)0x309;
          FUN_00447d40();
          ppuStack_64d8 = local_643c;
          FUN_004142e0();
          while (local_63fc != (undefined *)0x0) {
            ppuStack_64d8 = &local_63fc;
            local_63f0 = (undefined **)FUN_00572100();
            ppuStack_64d8 = &PTR_s_CDataMoji_009fe108;
            iVar1 = FUN_0079d98a();
            if (iVar1 != 0) {
              local_641c = local_63f0;
              ppuStack_64d8 = (undefined **)0x66cd96;
              CStringT<>();
              local_8._0_1_ = 3;
              local_6448 = 0xff;
              local_6444 = 0xff;
              local_6440 = (undefined *)0xff;
              ppuStack_64d8 = &local_6440;
              iVar1 = FUN_0048efe0(local_63f8,local_6498,local_6490,local_6488,local_6480,local_6478
                                   ,local_64a0,&local_6448,&local_6444);
              if (iVar1 != 0) {
                ppuStack_64d8 = (undefined **)0x96b164;
                local_644c = Left(local_6450,6);
                local_63e9 = FUN_00481230(local_644c);
                ppuStack_64d8 = (undefined **)0x66ce50;
                FUN_00404540();
                if (local_63e9 != '\0') {
                  ppuStack_64d8 = local_641c;
                  iVar1 = FUN_006705d0();
                  if (iVar1 == 0) {
                    local_8 = CONCAT31(local_8._1_3_,1);
                    ppuStack_64d8 = (undefined **)0x66ce80;
                    FUN_00404540();
                    break;
                  }
                  local_63f4 = (undefined **)((int)local_63f4 + 1);
                }
              }
              local_8 = CONCAT31(local_8._1_3_,1);
              ppuStack_64d8 = (undefined **)0x66cea2;
              FUN_00404540();
            }
          }
          ppuStack_64d8 = (undefined **)0x66ceb2;
          local_63fc = (undefined *)FUN_00572050();
LAB_0066ceb8:
          ppuStack_64d8 = &local_63fc;
          local_640c = FUN_005720a0();
          if (local_640c != 0) {
            ppuStack_64d8 = (undefined **)0x66cee8;
            local_6454 = FUN_0049ac10();
            while( true ) {
              ppuStack_64d8 = (undefined **)0x0;
              local_63f0 = (undefined **)FUN_0049ac30(&local_6454);
              if (local_63f0 == (undefined **)0x0) break;
              ppuStack_64d8 = &PTR_s_CDataMoji_009fe108;
              iVar1 = FUN_0079d98a();
              if (iVar1 != 0) {
                local_6420 = local_63f0;
                ppuStack_64d8 = (undefined **)0x66cf44;
                CStringT<>();
                local_8._0_1_ = 4;
                local_6460 = 0xff;
                local_645c = 0xff;
                local_6458 = (undefined *)0xff;
                ppuStack_64d8 = &local_6458;
                iVar1 = FUN_0048efe0(local_6400,local_64c8,local_64c0,local_64b8,local_64b0,
                                     local_64a8,local_64d0,&local_6460,&local_645c);
                if (iVar1 != 0) {
                  ppuStack_64d8 = (undefined **)0x96b164;
                  local_6464 = Left(local_6468,6);
                  local_63ea = FUN_00481230(local_6464);
                  ppuStack_64d8 = (undefined **)0x66cffe;
                  FUN_00404540();
                  if (local_63ea != '\0') {
                    ppuStack_64d8 = local_6420;
                    iVar1 = FUN_006705d0();
                    if (iVar1 == 0) {
                      local_8 = CONCAT31(local_8._1_3_,1);
                      ppuStack_64d8 = (undefined **)0x66d02e;
                      FUN_00404540();
                      break;
                    }
                    local_63f4 = (undefined **)((int)local_63f4 + 1);
                  }
                }
                local_8 = CONCAT31(local_8._1_3_,1);
                ppuStack_64d8 = (undefined **)0x66d050;
                FUN_00404540();
              }
            }
            goto LAB_0066ceb8;
          }
          ppuStack_64d8 = (undefined **)0x66d065;
          CStringT<>();
          local_8._0_1_ = 5;
          ppuStack_64d8 = local_63f4;
          FUN_00571e40(local_6414,0x27b1);
          ppuStack_64d8 = (undefined **)0x0;
          uVar3 = 0;
          uVar2 = FUN_00404920(0);
          FUN_004f6110(uVar2,uVar3);
          local_8._0_1_ = 1;
          ppuStack_64d8 = (undefined **)0x66d0ad;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          ppuStack_64d8 = (undefined **)0x66d0bc;
          FUN_00404540();
          local_8 = 0xffffffff;
          ppuStack_64d8 = (undefined **)0x66d0ce;
          FUN_00447100();
        }
        else {
          local_8 = 0xffffffff;
          ppuStack_64d8 = (undefined **)0x66cb3d;
          FUN_00447100();
        }
      }
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiGazou[32] */
/* 0066d0f0  FUN_0066d0f0  1806 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0066d0f0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined **ppuStack_64d8;
  uint uStack_64d4;
  undefined1 local_64d0 [8];
  undefined1 local_64c8 [8];
  undefined1 local_64c0 [8];
  undefined1 local_64b8 [8];
  undefined1 local_64b0 [8];
  undefined1 local_64a8 [8];
  undefined1 local_64a0 [8];
  undefined1 local_6498 [8];
  undefined1 local_6490 [8];
  undefined1 local_6488 [8];
  undefined1 local_6480 [8];
  undefined1 local_6478 [8];
  undefined1 *local_6470;
  undefined4 local_646c;
  undefined1 local_6468 [4];
  undefined4 local_6464;
  undefined4 local_6460;
  undefined4 local_645c;
  undefined *local_6458;
  undefined4 local_6454;
  undefined1 local_6450 [4];
  undefined4 local_644c;
  undefined4 local_6448;
  undefined4 local_6444;
  undefined *local_6440;
  undefined **local_643c;
  undefined4 local_6438;
  undefined4 local_6434;
  undefined1 local_6430 [4];
  undefined **local_642c;
  undefined **local_6428;
  undefined4 local_6424;
  undefined **local_6420;
  undefined **local_641c;
  undefined1 local_6418 [8];
  int local_6410;
  int *local_640c;
  int *local_6408;
  undefined1 local_6404 [4];
  undefined *local_6400;
  undefined1 local_63fc [4];
  undefined **local_63f8;
  undefined1 local_63f4 [4];
  undefined **local_63f0;
  char local_63ea;
  char local_63e9;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939c37;
  local_10 = ExceptionList;
  uStack_64d4 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0ef7c == 0) {
    local_63f8 = (undefined **)0x0;
    ppuStack_64d8 = (undefined **)0x66d148;
    local_14 = uStack_64d4;
    FUN_00446aa0();
    local_8 = 0;
    ppuStack_64d8 = (undefined **)0x66d15d;
    local_63e8 = FUN_0040c0e0();
    ppuStack_64d8 = (undefined **)0x66d16e;
    local_6400 = (undefined *)FUN_00572030();
    ppuStack_64d8 = (undefined **)0x66d17f;
    ppuStack_64d8 = (undefined **)FUN_0044f310();
    cVar1 = FUN_00447350(&DAT_00956338);
    if (cVar1 == '\0') {
      ppuStack_64d8 = (undefined **)0x66d1c9;
      iVar2 = FUN_00571320();
      if (iVar2 == 0) {
        ppuStack_64d8 = (undefined **)0xffffffff;
        FUN_004f60a0(0x27b6,0);
        local_8 = 0xffffffff;
        ppuStack_64d8 = (undefined **)0x66d1f2;
        FUN_00447100();
      }
      else {
        ppuStack_64d8 = (undefined **)0x66d202;
        CStringT<>();
        local_8._0_1_ = 1;
        ppuStack_64d8 = *(undefined ***)(local_63e8 + 0x1d1c);
        FUN_00571e40(local_63f4,0x27b7);
        ppuStack_64d8 = (undefined **)0x0;
        uVar4 = 1;
        uVar3 = FUN_00404920(1);
        iVar2 = FUN_004f6110(uVar3,uVar4);
        if (iVar2 == 1) {
          while( true ) {
            ppuStack_64d8 = (undefined **)0x66d27d;
            iVar2 = FUN_004146c0();
            if (iVar2 != 0) break;
            ppuStack_64d8 = (undefined **)0x66d292;
            local_6408 = (int *)FUN_00414c00();
            if (local_6408 == (int *)0x0) {
              local_646c = 0;
            }
            else {
              ppuStack_64d8 = (undefined **)0x1;
              local_646c = (**(code **)(*local_6408 + 4))();
            }
          }
          ppuStack_64d8 = (undefined **)0x66d2db;
          RemoveAll();
          ppuStack_64d8 = (undefined **)0x66d2ec;
          FUN_00454510();
          while( true ) {
            ppuStack_64d8 = (undefined **)0x66d2fd;
            iVar2 = FUN_004146c0();
            if (iVar2 != 0) break;
            ppuStack_64d8 = (undefined **)0x66d312;
            local_640c = (int *)FUN_00414c00();
            if (local_640c == (int *)0x0) {
              local_6424 = 0;
            }
            else {
              ppuStack_64d8 = (undefined **)0x1;
              local_6424 = (**(code **)(*local_640c + 4))();
            }
          }
          ppuStack_64d8 = (undefined **)0x66d35b;
          RemoveAll();
          ppuStack_64d8 = (undefined **)0x66d36c;
          FUN_00454510();
          ppuStack_64d8 = (undefined **)0x66d377;
          CStringT<>();
          local_8._0_1_ = 2;
          local_6434 = DAT_00a0b410;
          DAT_00a0ef7c = 1;
          ppuStack_64d8 = (undefined **)0x1;
          ppuStack_64d8 = (undefined **)FUN_0044ea50(local_6430);
          local_8._0_1_ = 3;
          local_642c = ppuStack_64d8;
          local_6428 = ppuStack_64d8;
          FUN_00404860();
          local_8 = CONCAT31(local_8._1_3_,2);
          ppuStack_64d8 = (undefined **)0x66d3dc;
          FUN_00404540();
          local_6438 = DAT_00a0b3e8;
          DAT_00a0b3e8 = 700;
          local_6470 = (undefined1 *)&ppuStack_64d8;
          FUN_00403dd0(local_6418);
          FUN_004dcbf0(local_63e8,local_6434);
          DAT_00a0b3e8 = local_6438;
          DAT_00a0ef7c = 0;
          local_643c = (undefined **)0x0;
          ppuStack_64d8 = (undefined **)0x309;
          FUN_00447d40();
          ppuStack_64d8 = local_643c;
          FUN_004142e0();
          while (local_6400 != (undefined *)0x0) {
            ppuStack_64d8 = &local_6400;
            local_63f0 = (undefined **)FUN_00572100();
            ppuStack_64d8 = &PTR_s_CDataMoji_009fe108;
            iVar2 = FUN_0079d98a();
            if (iVar2 != 0) {
              local_641c = local_63f0;
              ppuStack_64d8 = (undefined **)0x66d4c0;
              CStringT<>();
              local_8._0_1_ = 4;
              local_6448 = 0xff;
              local_6444 = 0xff;
              local_6440 = (undefined *)0xff;
              ppuStack_64d8 = &local_6440;
              iVar2 = FUN_0048efe0(local_63fc,local_6498,local_6490,local_6488,local_6480,local_6478
                                   ,local_64a0,&local_6448,&local_6444);
              if (iVar2 != 0) {
                ppuStack_64d8 = (undefined **)0x96b164;
                local_644c = Left(local_6450,6);
                local_63e9 = FUN_00481200(local_644c);
                ppuStack_64d8 = (undefined **)0x66d57a;
                FUN_00404540();
                if (local_63e9 != '\0') {
                  ppuStack_64d8 = local_641c;
                  iVar2 = FUN_0066f8f0();
                  if (iVar2 == 0) {
                    local_8 = CONCAT31(local_8._1_3_,2);
                    ppuStack_64d8 = (undefined **)0x66d5aa;
                    FUN_00404540();
                    break;
                  }
                  local_63f8 = (undefined **)((int)local_63f8 + 1);
                }
              }
              local_8 = CONCAT31(local_8._1_3_,2);
              ppuStack_64d8 = (undefined **)0x66d5cc;
              FUN_00404540();
            }
          }
          ppuStack_64d8 = (undefined **)0x66d5dc;
          local_6400 = (undefined *)FUN_00572050();
LAB_0066d5e2:
          ppuStack_64d8 = &local_6400;
          local_6410 = FUN_005720a0();
          if (local_6410 != 0) {
            ppuStack_64d8 = (undefined **)0x66d612;
            local_6454 = FUN_0049ac10();
            while( true ) {
              ppuStack_64d8 = (undefined **)0x0;
              local_63f0 = (undefined **)FUN_0049ac30(&local_6454);
              if (local_63f0 == (undefined **)0x0) break;
              ppuStack_64d8 = &PTR_s_CDataMoji_009fe108;
              iVar2 = FUN_0079d98a();
              if (iVar2 != 0) {
                local_6420 = local_63f0;
                ppuStack_64d8 = (undefined **)0x66d66e;
                CStringT<>();
                local_8._0_1_ = 5;
                local_6460 = 0xff;
                local_645c = 0xff;
                local_6458 = (undefined *)0xff;
                ppuStack_64d8 = &local_6458;
                iVar2 = FUN_0048efe0(local_6404,local_64c8,local_64c0,local_64b8,local_64b0,
                                     local_64a8,local_64d0,&local_6460,&local_645c);
                if (iVar2 != 0) {
                  ppuStack_64d8 = (undefined **)0x96b164;
                  local_6464 = Left(local_6468,6);
                  local_63ea = FUN_00481200(local_6464);
                  ppuStack_64d8 = (undefined **)0x66d728;
                  FUN_00404540();
                  if (local_63ea != '\0') {
                    ppuStack_64d8 = local_6420;
                    iVar2 = FUN_0066f8f0();
                    if (iVar2 == 0) {
                      local_8 = CONCAT31(local_8._1_3_,2);
                      ppuStack_64d8 = (undefined **)0x66d758;
                      FUN_00404540();
                      break;
                    }
                    local_63f8 = (undefined **)((int)local_63f8 + 1);
                  }
                }
                local_8 = CONCAT31(local_8._1_3_,2);
                ppuStack_64d8 = (undefined **)0x66d77a;
                FUN_00404540();
              }
            }
            goto LAB_0066d5e2;
          }
          ppuStack_64d8 = local_63f8;
          FUN_00571e40(local_63f4,0x27b9);
          ppuStack_64d8 = (undefined **)0x0;
          uVar4 = 0;
          uVar3 = FUN_00404920(0);
          FUN_004f6110(uVar3,uVar4);
          local_8._0_1_ = 1;
          ppuStack_64d8 = (undefined **)0x66d7c8;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          ppuStack_64d8 = (undefined **)0x66d7d7;
          FUN_00404540();
          local_8 = 0xffffffff;
          ppuStack_64d8 = (undefined **)0x66d7e9;
          FUN_00447100();
        }
        else {
          local_8 = (uint)local_8._1_3_ << 8;
          ppuStack_64d8 = (undefined **)0x66d255;
          FUN_00404540();
          local_8 = 0xffffffff;
          ppuStack_64d8 = (undefined **)0x66d267;
          FUN_00447100();
        }
      }
    }
    else {
      ppuStack_64d8 = (undefined **)0xffffffff;
      FUN_004f60a0(0x27b8,0);
      local_8 = 0xffffffff;
      ppuStack_64d8 = (undefined **)0x66d1b9;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiGazou[9] */
/* 0066d810  FUN_0066d810  7848 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0066d810(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float10 fVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double local_684c;
  double local_6834;
  undefined8 local_6828;
  undefined8 local_6820;
  undefined8 local_6818;
  undefined8 local_6810;
  undefined8 local_6808;
  undefined8 local_6800;
  undefined8 local_67d8;
  double local_67d0;
  double local_67c8;
  double local_67c0;
  double local_67a0;
  undefined8 local_6780;
  undefined8 local_6778;
  undefined8 local_6758;
  double local_6750;
  undefined8 local_6748;
  int local_6740;
  int local_673c;
  undefined8 local_6738;
  undefined4 local_6730;
  undefined4 local_672c;
  undefined4 local_6728;
  undefined4 local_6724;
  undefined4 local_6720;
  undefined4 local_671c;
  undefined4 local_6718;
  undefined4 local_6714;
  double local_6710;
  undefined4 local_6708;
  undefined4 local_6704;
  undefined4 local_6700;
  undefined4 local_66fc;
  undefined4 local_66f8;
  undefined4 local_66f4;
  undefined4 local_66f0;
  undefined4 local_66e8;
  undefined4 local_66e4;
  undefined4 local_66e0;
  HDC local_66dc;
  double local_66d8;
  double local_66d0;
  double local_66c8;
  double local_66c0;
  undefined4 local_66b8;
  undefined4 local_66b4;
  undefined4 local_66b0;
  int local_66ac;
  undefined4 local_66a8;
  undefined4 local_66a4;
  undefined4 local_66a0;
  double local_669c;
  double local_6694;
  undefined4 local_668c;
  undefined4 local_6688;
  undefined4 local_6684;
  undefined4 local_6680;
  undefined4 local_667c;
  COLORREF local_6678;
  undefined4 local_6674;
  double local_6670;
  int *local_6668;
  undefined4 local_6664;
  undefined1 local_6660 [20];
  uint local_664c;
  int local_6648;
  uint local_6644;
  int *local_6640;
  int local_663c;
  int *local_6638;
  int local_6634;
  CWaitCursor local_662d;
  int *local_662c;
  int local_6628;
  undefined4 local_6624;
  int local_6620;
  int *local_661c;
  int local_6618;
  undefined4 local_31c;
  undefined1 local_244 [24];
  double local_22c;
  undefined1 local_154 [16];
  undefined1 local_144 [16];
  undefined1 local_134 [16];
  undefined1 local_124 [16];
  undefined1 local_114 [16];
  undefined1 local_104 [16];
  undefined1 local_f4 [16];
  undefined1 local_e4 [16];
  undefined1 local_d4 [16];
  undefined1 local_c4 [16];
  undefined1 local_b4 [16];
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 uStack_90;
  undefined4 local_8c;
  undefined4 uStack_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 local_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939ce3;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6618 + 4));
  local_8._0_1_ = 1;
  FUN_0040c0e0();
  FUN_00510dc0();
  if (*(int *)(*(int *)(local_6618 + 4) + 0x8560) == 0) {
    *(int *)(*(int *)(local_6618 + 4) + 0x8560) = *(int *)(*(int *)(local_6618 + 4) + 0x8560) + 1;
    puVar3 = (undefined4 *)FUN_004988c0(local_144,param_2,param_3,param_4,param_5);
    FUN_004988c0(local_134,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
    if (*(int *)(local_6618 + 0x614) != 0) {
      *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8560) = 0;
      CWaitCursor::CWaitCursor(&local_662d);
      local_8._0_1_ = 2;
      FUN_004efc30(0x1456,0,0);
      *(undefined4 *)(local_6618 + 0x614) = 0;
      FUN_00480a30();
      local_8._0_1_ = 3;
      FUN_004552a0(local_244);
      puVar3 = (undefined4 *)
               FUN_004988c0(local_154,*(undefined4 *)(local_6618 + 0x10),
                            *(undefined4 *)(local_6618 + 0x14),*(undefined4 *)(local_6618 + 0x18),
                            *(undefined4 *)(local_6618 + 0x1c));
      FUN_004988c0(local_124,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
      local_22c = local_22c + *(double *)(local_6618 + 0x620);
      FUN_00404860(local_6618 + 0x618);
      local_66f4 = FUN_0048c5f0();
      FUN_00447670(local_6660,*(undefined4 *)(local_6618 + 4),local_66f4,1,0);
      FUN_00404c80();
      FUN_0056d7d0();
      local_66f8 = 1;
      local_8._0_1_ = 2;
      FUN_00480ef0();
      local_8._0_1_ = 1;
      FUN_00408b00();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_66f8;
    }
    iVar4 = FUN_00671590();
    if (iVar4 != 0) {
      *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8560) = 0;
      local_6638 = (int *)FUN_006715f0();
      if (local_6638 != (int *)0x0) {
        CStringT<>();
        local_8._0_1_ = 4;
        local_66a8 = 0xff;
        local_66a4 = 0xff;
        local_66a0 = 0xff;
        FUN_0048efe0();
        local_6710 = local_67a0 / local_67c0;
        dVar8 = local_6710 * local_67c8;
        dVar9 = local_6710 * local_67d0;
        local_6620 = (**(code **)(*local_6638 + 0x14))();
        FUN_005f89c0(*(undefined4 *)(local_6620 + 8),*(undefined4 *)(local_6620 + 0xc),
                     *(undefined4 *)(local_6620 + 0x10),*(undefined4 *)(local_6620 + 0x14),
                     (int)local_6748,(int)((ulonglong)local_6748 >> 0x20),0);
        FUN_005f92e0(local_6620 + 8);
        FUN_005f92e0(local_6620 + 0x18);
        FUN_004059f0(local_6620 + 0xb0,L"^@BM%s,%lg,%lg,%lg,%lg,%lg,%lg,%d,%d,%d",local_6674,
                     local_6710,local_67d8,0,0,0x3ff0000000000000,(int)local_6748,
                     (int)((ulonglong)local_6748 >> 0x20),local_66a8,local_66a4,local_66a0);
        *(double *)(local_6620 + 8) = *(double *)(local_6620 + 8) - dVar8;
        *(double *)(local_6620 + 0x10) = *(double *)(local_6620 + 0x10) - dVar9;
        FUN_005f8ce0(local_6620 + 8);
        FUN_005f8ce0(local_6620 + 0x18);
        FUN_0044b2c0(local_6660,*(undefined4 *)(local_6618 + 4),local_6638,1);
        local_31c = 1;
        FUN_00447670(local_6660,*(undefined4 *)(local_6618 + 4),local_6620,1,0);
        local_31c = 0;
        local_66fc = 1;
        local_8._0_1_ = 1;
        FUN_00404540();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_66fc;
      }
    }
    iVar4 = FUN_006714d0();
    if (iVar4 != 0) {
      *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8560) = 0;
      local_6640 = (int *)FUN_006715f0();
      if (local_6640 != (int *)0x0) {
        CStringT<>();
        local_8 = CONCAT31(local_8._1_3_,5);
        local_6644 = 0xff;
        local_6648 = 0xff;
        local_664c = 0xff;
        FUN_0048efe0();
        if (*(int *)(local_6618 + 0x1f8) != 0) {
          FUN_004b6d60(&local_6740,param_2,param_3,param_4,param_5);
          local_6700 = FUN_005665f0();
          local_66dc = (HDC)FID_conflict_GetSafeHdc();
          local_6678 = GetPixel(local_66dc,local_6740,local_673c);
          local_6644 = local_6678 & 0xff;
          local_6648 = (int)(local_6678 & 0xffff) >> 8;
          local_664c = local_6678 >> 0x10 & 0xff;
        }
        FUN_00408010(0);
        uVar2 = local_6644;
        iVar4 = local_6648;
        uVar1 = local_664c;
        local_8._0_1_ = 6;
        iVar5 = FUN_0079850d();
        if (iVar5 == 1) {
          local_664c = uVar1;
          local_6648 = iVar4;
          local_6644 = uVar2;
          local_66ac = (**(code **)(*local_6640 + 0x14))();
          FUN_004059f0(local_66ac + 0xb0,L"^@BM%s,%lg,%lg,%lg,%lg,%lg,%lg,%d,%d,%d",local_6664,
                       local_6828,local_6820,local_6818,local_6810,local_6808,(int)local_6800,
                       (int)((ulonglong)local_6800 >> 0x20),local_6644,local_6648,local_664c);
          FUN_0044b2c0(local_6660,*(undefined4 *)(local_6618 + 4),local_6640,1);
          local_31c = 1;
          FUN_00447670(local_6660,*(undefined4 *)(local_6618 + 4),local_66ac,1,0);
          local_31c = 0;
          local_66e0 = 1;
          local_8._0_1_ = 5;
          FUN_004080c0();
          local_8._0_1_ = 1;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return local_66e0;
        }
        local_66e4 = 1;
        local_8._0_1_ = 5;
        FUN_004080c0();
        local_8._0_1_ = 1;
        FUN_00404540();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_66e4;
      }
    }
    iVar4 = FUN_006715f0();
    if (iVar4 == 0) {
      *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8560) = 0;
      local_66e8 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_66e8;
    }
    FUN_00404c80();
    FUN_0056d7d0();
  }
  else if (*(int *)(*(int *)(local_6618 + 4) + 0x8560) == 1) {
    *(int *)(*(int *)(local_6618 + 4) + 0x8560) = *(int *)(*(int *)(local_6618 + 4) + 0x8560) + 1;
    FUN_004988c0(local_114,param_2,param_3,param_4,param_5);
    iVar4 = FUN_00671430();
    if (iVar4 != 0) {
      *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8560) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      local_24 = *(undefined4 *)(local_6618 + 0x20);
      local_20 = *(undefined4 *)(local_6618 + 0x24);
      local_1c = *(undefined4 *)(local_6618 + 0x28);
      local_18 = *(undefined4 *)(local_6618 + 0x2c);
      FUN_00498b50(*(undefined4 *)(local_6618 + 0x10),*(undefined4 *)(local_6618 + 0x14),
                   *(undefined4 *)(local_6618 + 0x18),*(undefined4 *)(local_6618 + 0x1c));
      FUN_004988c0(local_b4,*(undefined4 *)(local_6618 + 0x10),*(undefined4 *)(local_6618 + 0x14),
                   *(undefined4 *)(local_6618 + 0x18),*(undefined4 *)(local_6618 + 0x1c));
      local_6668 = (int *)FUN_006715f0();
      if (local_6668 != (int *)0x0) {
        CStringT<>();
        local_8._0_1_ = 7;
        local_667c = (**(code **)(*local_6668 + 0x14))();
        FUN_00498ac0(local_24,local_20,local_1c,local_18);
        FUN_00498ac0(local_24,local_20,local_1c,local_18);
        FUN_0044b2c0(local_6660,*(undefined4 *)(local_6618 + 4),local_6668,1);
        local_31c = 1;
        FUN_00447670(local_6660,*(undefined4 *)(local_6618 + 4),local_667c,1,0);
        local_31c = 0;
        local_8._0_1_ = 1;
        FUN_00404540();
      }
      local_6730 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_6730;
    }
    local_661c = (int *)FUN_006715f0();
    if (local_661c == (int *)0x0) {
      *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8560) = 0;
      local_672c = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_672c;
    }
    iVar4 = FUN_00671530();
    if (iVar4 != 0) {
      *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8560) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      if (local_661c != (int *)0x0) {
        CStringT<>();
        local_8._0_1_ = 8;
        local_66b8 = 0xff;
        local_66b4 = 0xff;
        local_66b0 = 0xff;
        FUN_0048efe0();
        FUN_005f89c0(*(undefined4 *)(local_6618 + 0x10),*(undefined4 *)(local_6618 + 0x14),
                     *(undefined4 *)(local_6618 + 0x18),*(undefined4 *)(local_6618 + 0x1c),
                     (int)local_6758,(int)((ulonglong)local_6758 >> 0x20),0);
        FUN_005f92e0(local_6618 + 0x10);
        FUN_005f92e0(local_6618 + 0x20);
        FUN_005f92e0(local_661c + 2);
        FUN_005f92e0(local_661c + 6);
        FUN_0066c2e0();
        local_66d8 = local_66d0 / local_6750;
        dVar10 = (local_66d8 * local_6834 +
                 (*(double *)(local_6618 + 0x10) - *(double *)(local_661c + 2))) / local_66d8;
        dVar11 = (local_66d8 * local_684c +
                 (*(double *)(local_6618 + 0x18) - *(double *)(local_661c + 4))) / local_66d8;
        dVar12 = ((*(double *)(local_6618 + 0x20) - *(double *)(local_6618 + 0x10)) * local_6750) /
                 local_66d0;
        local_66d0 = *(double *)(local_6618 + 0x20) - *(double *)(local_6618 + 0x10);
        dVar8 = *(double *)(local_6618 + 0x28);
        dVar9 = *(double *)(local_6618 + 0x18);
        FUN_005f8ce0(local_6618 + 0x10);
        FUN_005f8ce0(local_6618 + 0x20);
        FUN_005f8ce0(local_661c + 2);
        FUN_005f8ce0(local_661c + 6);
        local_663c = (**(code **)(*local_661c + 0x14))();
        FUN_004059f0(local_663c + 0xb0,L"^@BM%s,%lg,%lg,%lg,%lg,%lg,%lg,%d,%d,%d",local_6680,
                     local_66d0,dVar8 - dVar9,dVar10,dVar11,dVar12,(int)local_6758,
                     (int)((ulonglong)local_6758 >> 0x20),local_66b8,local_66b4,local_66b0);
        puVar3 = (undefined4 *)
                 FUN_004988c0(local_c4,*(undefined4 *)(local_6618 + 0x10),
                              *(undefined4 *)(local_6618 + 0x14),*(undefined4 *)(local_6618 + 0x18),
                              *(undefined4 *)(local_6618 + 0x1c));
        FUN_004988c0(local_d4,*puVar3,puVar3[1],puVar3[2],puVar3[3]);
        *(undefined8 *)(local_663c + 0x18) = *(undefined8 *)(local_6618 + 0x20);
        FUN_0044b2c0(local_6660,*(undefined4 *)(local_6618 + 4),local_661c,1);
        local_31c = 1;
        FUN_00447670(local_6660,*(undefined4 *)(local_6618 + 4),local_663c,1,0);
        local_31c = 0;
        local_6728 = 1;
        local_8._0_1_ = 1;
        FUN_00404540();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_6728;
      }
    }
  }
  else if (*(int *)(*(int *)(local_6618 + 4) + 0x8560) == 2) {
    *(int *)(*(int *)(local_6618 + 4) + 0x8560) = *(int *)(*(int *)(local_6618 + 4) + 0x8560) + 1;
    FUN_004988c0(local_e4,param_2,param_3,param_4,param_5);
  }
  else if (*(int *)(*(int *)(local_6618 + 4) + 0x8560) == 3) {
    *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8560) = 0;
    FUN_004988c0(local_f4,param_2,param_3,param_4,param_5);
    iVar4 = FUN_006713d0();
    if (iVar4 != 0) {
      FUN_00404c80();
      FUN_0056d7d0();
      local_662c = (int *)FUN_006715f0();
      if (local_662c != (int *)0x0) {
        CStringT<>();
        local_8._0_1_ = 9;
        local_668c = 0xff;
        local_6688 = 0xff;
        local_6684 = 0xff;
        FUN_0048efe0();
        iVar4 = FUN_00671490();
        if (iVar4 == 0) {
          FUN_0066c2e0();
          local_84 = *(undefined4 *)(local_6618 + 0x10);
          local_80 = *(undefined4 *)(local_6618 + 0x14);
          local_7c = *(undefined4 *)(local_6618 + 0x18);
          local_78 = *(undefined4 *)(local_6618 + 0x1c);
          local_74 = *(undefined4 *)(local_6618 + 0x200);
          local_70 = *(undefined4 *)(local_6618 + 0x204);
          local_6c = *(undefined4 *)(local_6618 + 0x208);
          local_68 = *(undefined4 *)(local_6618 + 0x20c);
          FUN_00498ac0(*(undefined4 *)(local_6618 + 0x20),*(undefined4 *)(local_6618 + 0x24),
                       *(undefined4 *)(local_6618 + 0x28),*(undefined4 *)(local_6618 + 0x2c));
          FUN_00498bf0(0,0x40000000);
          FUN_00498ac0(*(undefined4 *)(local_6618 + 0x210),*(undefined4 *)(local_6618 + 0x214),
                       *(undefined4 *)(local_6618 + 0x218),*(undefined4 *)(local_6618 + 0x21c));
          FUN_00498bf0(0,0x40000000);
          local_54 = *(undefined4 *)(local_6618 + 0x20);
          uStack_50 = *(undefined4 *)(local_6618 + 0x24);
          local_4c = *(undefined4 *)(local_6618 + 0x28);
          uStack_48 = *(undefined4 *)(local_6618 + 0x2c);
          local_94 = *(undefined4 *)(local_6618 + 0x210);
          uStack_90 = *(undefined4 *)(local_6618 + 0x214);
          local_8c = *(undefined4 *)(local_6618 + 0x218);
          uStack_88 = *(undefined4 *)(local_6618 + 0x21c);
          FUN_00498b50(*(undefined4 *)(local_6618 + 0x10),*(undefined4 *)(local_6618 + 0x14),
                       *(undefined4 *)(local_6618 + 0x18),*(undefined4 *)(local_6618 + 0x1c));
          FUN_00498b50(*(undefined4 *)(local_6618 + 0x200),*(undefined4 *)(local_6618 + 0x204),
                       *(undefined4 *)(local_6618 + 0x208),*(undefined4 *)(local_6618 + 0x20c));
          if (((double)CONCAT44(uStack_50,local_54) <= 1e-07 &&
               (double)CONCAT44(uStack_50,local_54) != 1e-07) &&
             ((double)CONCAT44(uStack_48,local_4c) <= 1e-07 &&
              (double)CONCAT44(uStack_48,local_4c) != 1e-07)) {
            FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6618 + 4) + 0x8f24),
                         *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8f28),0,0);
            local_671c = 0;
            local_8._0_1_ = 1;
            FUN_00404540();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return local_671c;
          }
          if ((double)CONCAT44(uStack_50,local_54) < (double)CONCAT44(uStack_48,local_4c) ||
              (double)CONCAT44(uStack_50,local_54) == (double)CONCAT44(uStack_48,local_4c)) {
            local_6670 = (double)CONCAT44(uStack_88,local_8c) / (double)CONCAT44(uStack_48,local_4c)
            ;
            if ((double)CONCAT44(uStack_88,local_8c) <= 1e-07 &&
                (double)CONCAT44(uStack_88,local_8c) != 1e-07) {
              FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6618 + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8f28),0,0);
              local_6718 = 0;
              local_8._0_1_ = 1;
              FUN_00404540();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return local_6718;
            }
          }
          else {
            local_6670 = (double)CONCAT44(uStack_90,local_94) / (double)CONCAT44(uStack_50,local_54)
            ;
            if ((double)CONCAT44(uStack_90,local_94) <= 1e-07 &&
                (double)CONCAT44(uStack_90,local_94) != 1e-07) {
              FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6618 + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8f28),0,0);
              local_66f0 = 0;
              local_8._0_1_ = 1;
              FUN_00404540();
              local_8 = (uint)local_8._1_3_ << 8;
              FUN_0079dfff();
              local_8 = 0xffffffff;
              FUN_00447100();
              ExceptionList = local_10;
              return local_66f0;
            }
          }
          local_6694 = local_6694 * local_6670;
          local_669c = local_669c * local_6670;
          local_6628 = (**(code **)(*local_662c + 0x14))();
          FUN_004059f0(local_6628 + 0xb0,L"^@BM%s,%lg,%lg,%lg,%lg,%lg,%lg,%d,%d,%d",local_6624,
                       local_6694,local_669c,local_6738,local_6780,local_6778,SUB84(local_66c0,0),
                       (int)((ulonglong)local_66c0 >> 0x20),local_668c,local_6688,local_6684);
          FUN_00498b50(local_84,local_80,local_7c,local_78);
          FUN_00498a30(SUB84(local_6670,0),(int)((ulonglong)local_6670 >> 0x20));
          FUN_00498ac0(local_74,local_70,local_6c,local_68);
          FUN_004988c0(local_104,*(undefined4 *)(local_6628 + 8),*(undefined4 *)(local_6628 + 0xc),
                       *(undefined4 *)(local_6628 + 0x10),*(undefined4 *)(local_6628 + 0x14));
          *(double *)(local_6628 + 0x18) = *(double *)(local_6628 + 0x18) + local_6694;
          FUN_0044b2c0(local_6660,*(undefined4 *)(local_6618 + 4),local_662c,1);
          local_31c = 1;
          FUN_00447670(local_6660,*(undefined4 *)(local_6618 + 4),local_6628,1,0);
          local_31c = 0;
          local_6714 = 1;
          local_8._0_1_ = 1;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return local_6714;
        }
        local_34 = *(undefined4 *)(local_6618 + 0x10);
        local_30 = *(undefined4 *)(local_6618 + 0x14);
        local_2c = *(undefined4 *)(local_6618 + 0x18);
        local_28 = *(undefined4 *)(local_6618 + 0x1c);
        local_a4 = *(undefined4 *)(local_6618 + 0x200);
        local_a0 = *(undefined4 *)(local_6618 + 0x204);
        local_9c = *(undefined4 *)(local_6618 + 0x208);
        local_98 = *(undefined4 *)(local_6618 + 0x20c);
        local_44 = *(undefined4 *)(local_6618 + 0x20);
        uStack_40 = *(undefined4 *)(local_6618 + 0x24);
        local_3c = *(undefined4 *)(local_6618 + 0x28);
        uStack_38 = *(undefined4 *)(local_6618 + 0x2c);
        local_64 = *(undefined4 *)(local_6618 + 0x210);
        uStack_60 = *(undefined4 *)(local_6618 + 0x214);
        local_5c = *(undefined4 *)(local_6618 + 0x218);
        uStack_58 = *(undefined4 *)(local_6618 + 0x21c);
        FUN_00498b50(*(undefined4 *)(local_6618 + 0x10),*(undefined4 *)(local_6618 + 0x14),
                     *(undefined4 *)(local_6618 + 0x18),*(undefined4 *)(local_6618 + 0x1c));
        FUN_00498b50(*(undefined4 *)(local_6618 + 0x200),*(undefined4 *)(local_6618 + 0x204),
                     *(undefined4 *)(local_6618 + 0x208),*(undefined4 *)(local_6618 + 0x20c));
        fVar6 = (float10)FUN_008f8d00(local_5c,uStack_58,local_64,uStack_60);
        fVar7 = (float10)FUN_008f8d00(local_3c,uStack_38,local_44,uStack_40);
        local_66c8 = ((double)fVar6 - (double)fVar7) * 57.29577951308232;
        local_66c0 = local_66c0 + local_66c8;
        fVar6 = (float10)FUN_008f8d10((double)CONCAT44(uStack_40,local_44) *
                                      (double)CONCAT44(uStack_40,local_44) +
                                      (double)CONCAT44(uStack_38,local_3c) *
                                      (double)CONCAT44(uStack_38,local_3c));
        fVar7 = (float10)FUN_008f8d10((double)CONCAT44(uStack_60,local_64) *
                                      (double)CONCAT44(uStack_60,local_64) +
                                      (double)CONCAT44(uStack_58,local_5c) *
                                      (double)CONCAT44(uStack_58,local_5c));
        if ((double)fVar6 < 1e-07) {
          FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6618 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8f28),0,0);
          local_6724 = 0;
          local_8._0_1_ = 1;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return local_6724;
        }
        local_6670 = (double)fVar7 / (double)fVar6;
        if ((double)fVar7 < 1e-07) {
          FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_6618 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_6618 + 4) + 0x8f28),0,0);
          local_6720 = 0;
          local_8._0_1_ = 1;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return local_6720;
        }
        local_6694 = local_6694 * local_6670;
        local_669c = local_669c * local_6670;
        local_6634 = (**(code **)(*local_662c + 0x14))();
        FUN_004059f0(local_6634 + 0xb0,L"^@BM%s,%lg,%lg,%lg,%lg,%lg,%lg,%d,%d,%d",local_6624,
                     local_6694,local_669c,local_6738,local_6780,local_6778,SUB84(local_66c0,0),
                     (int)((ulonglong)local_66c0 >> 0x20),local_668c,local_6688,local_6684);
        FUN_005f89c0(local_a4,local_a0,local_9c,local_98,SUB84(local_66c8,0),
                     (int)((ulonglong)local_66c8 >> 0x20),0);
        FUN_00498b50(local_34,local_30,local_2c,local_28);
        FUN_00498a30(SUB84(local_6670,0),(int)((ulonglong)local_6670 >> 0x20));
        FUN_00498b50(local_34,local_30,local_2c,local_28);
        FUN_00498a30(SUB84(local_6670,0),(int)((ulonglong)local_6670 >> 0x20));
        FUN_005f8d70(local_6634);
        FUN_0044b2c0(local_6660,*(undefined4 *)(local_6618 + 4),local_662c,1);
        local_31c = 1;
        FUN_00447670(local_6660,*(undefined4 *)(local_6618 + 4),local_6634,1,0);
        local_31c = 0;
        local_6704 = 1;
        local_8._0_1_ = 1;
        FUN_00404540();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return local_6704;
      }
    }
  }
  local_6708 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return local_6708;
}




/* vtable slots: CZukeiGazou[11] */
/* 0066f6d0  FUN_0066f6d0  532 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0066f6d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939d2b;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  FUN_0079dea2(in_ECX[1]);
  local_8._0_1_ = 1;
  in_ECX[0x7d] = 0;
  FUN_00510dc0();
  iVar1 = FUN_006714d0();
  if (iVar1 == 0) {
    iVar1 = FUN_00451eb0(in_ECX[1],&param_2,1);
    if (iVar1 == 1) {
      uVar2 = (**(code **)(*in_ECX + 0x24))(param_1,param_2,param_3,param_4,param_5);
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 0;
    }
  }
  else {
    in_ECX[0x7e] = 1;
    uVar2 = (**(code **)(*in_ECX + 0x24))(param_1,param_2,param_3,param_4,param_5);
    in_ECX[0x7e] = 0;
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiGazou[46], CZukeiSentaku[46] */
/* 006f8f10  FUN_006f8f10  5695 bytes, 13 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006f8f10(undefined4 param_1,int param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_6500 [4];
  undefined4 local_64fc;
  undefined4 local_64f8;
  undefined4 local_64f4;
  undefined4 local_64f0;
  undefined4 local_64ec;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_64e8;
  undefined4 local_64e4;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_64d8 [4];
  undefined4 local_64d4;
  undefined4 local_64d0;
  undefined4 local_64cc;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_64c8;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_64c4;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_64c0;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_64bc;
  undefined4 local_64b8;
  undefined4 local_64b4;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> local_64a8 [4];
  undefined4 local_64a4;
  undefined4 local_64a0;
  undefined4 local_649c;
  CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_> *local_6498;
  undefined4 local_6494;
  undefined4 local_6490;
  undefined4 local_6488;
  undefined4 local_6484;
  undefined4 local_647c;
  undefined4 local_6478;
  undefined4 local_6470;
  undefined4 local_646c;
  undefined4 local_6464;
  undefined1 local_6460 [20];
  int local_644c;
  int local_6448;
  undefined1 local_6444 [4];
  undefined4 local_6440;
  int local_6438;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f37a;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (param_3 == 2) {
    *(undefined4 *)(in_ECX + 0xb0) = 0;
  }
  if (DAT_00a0c7c0 != 0) {
    uVar2 = FUN_0076c9c0(param_1,param_2);
    ExceptionList = local_10;
    return uVar2;
  }
  local_6438 = in_ECX;
  FUN_00404c80();
  iVar3 = FUN_004fca20();
  if (*(int *)(iVar3 + 0x1a0) != *(int *)(*(int *)(local_6438 + 4) + 0x8610)) {
    uVar2 = FUN_0076c9c0(param_1,param_2);
    ExceptionList = local_10;
    return uVar2;
  }
  FUN_0079dea2();
  local_8 = 0;
  FUN_00446aa0();
  local_8._0_1_ = 1;
  local_6440 = 0;
  if (*(int *)(*(int *)(local_6438 + 4) + 0x9078) == 0) {
    if (*(int *)(local_6438 + 0xb4) == 0) {
      local_649c = FUN_0076c9c0(param_1,param_2);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      ExceptionList = local_10;
      return local_649c;
    }
    iVar3 = FUN_0079d98a();
    if ((iVar3 == 0) && ((DAT_00a0b3c8 & 4) != 0)) {
      if (param_2 == 1) {
        if (param_3 == 1) {
          FUN_005168b0();
        }
        else if (param_3 == 2) {
          *(undefined4 *)(*(int *)(local_6438 + 4) + 0x9090) = 0x808e;
        }
        local_64d4 = local_6440;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return local_64d4;
      }
      if (param_2 == 2) {
        if (param_3 == 1) {
          FUN_005168b0();
        }
        else if (param_3 == 2) {
          *(undefined4 *)(*(int *)(local_6438 + 4) + 0x9090) = 0x806a;
        }
        local_64ec = local_6440;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return local_64ec;
      }
    }
    if ((param_2 == 8) && ((DAT_00a0b3c8 & 1) != 0)) {
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        FUN_00503c40();
      }
      local_64f0 = local_6440;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      ExceptionList = local_10;
      return local_64f0;
    }
    if ((param_2 == 0xc) && (*(int *)(local_6438 + 0xb4) == 1)) {
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xcc) == 1) {
LAB_006f9315:
        if (param_3 == 1) {
          FUN_005168b0();
        }
        else if (param_3 == 2) {
          FUN_00517640();
          FUN_004988c0();
          *(undefined4 *)(local_6438 + 0xac) = 0;
          FUN_0044de00();
          FUN_004b75a0();
          FUN_004508b0(0x10,local_6460,*(undefined4 *)(local_6438 + 4));
          FUN_00404c80();
          FUN_00799e17();
          FUN_00406bc0();
        }
        local_64f4 = local_6440;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return local_64f4;
      }
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xcc) == 2) goto LAB_006f9315;
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0xcc) == 7) goto LAB_006f9315;
    }
    if ((param_3 == 2) && (((param_2 == 4 || (param_2 == 5)) || (param_2 == 6)))) {
      FUN_004988c0();
      *(undefined4 *)(local_6438 + 0xc) = 1;
      iVar3 = FUN_0040dbb0();
      if (iVar3 != 0) {
        *(undefined4 *)(local_6438 + 0xc) = 0;
      }
      FUN_004988c0();
      FUN_004988c0();
    }
    if (((DAT_00a0b3c8 & 8) != 0) && (param_2 == 4)) {
      param_2 = 5;
    }
    local_644c = param_2;
    if (param_2 == 4) {
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        FUN_0044c830();
        FUN_00653df0();
        FUN_00652e80();
        *(undefined4 *)(local_6438 + 0xc) = 0;
      }
    }
    else if (param_2 == 5) {
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        FUN_00653df0();
        FUN_00652e80();
        *(undefined4 *)(local_6438 + 0xc) = 0;
      }
    }
    else if (param_2 == 6) {
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        FUN_00653df0();
        FUN_00652e80();
        *(undefined4 *)(local_6438 + 0xc) = 0;
      }
    }
    else {
      local_6440 = FUN_0076c9c0(param_1,param_2);
    }
  }
  else {
    *(undefined4 *)(local_6438 + 0xe8) = 0;
    *(undefined4 *)(local_6438 + 0xec) = 0;
    *(undefined4 *)(local_6438 + 0xf0) = 0;
    *(undefined4 *)(local_6438 + 0xf8) = 0;
    *(undefined4 *)(local_6438 + 0xfc) = 0;
    *(undefined4 *)(local_6438 + 0x100) = 0;
    *(undefined4 *)(local_6438 + 0x104) = 0;
    *(undefined4 *)(local_6438 + 0x108) = 0;
    *(undefined4 *)(local_6438 + 0x10c) = 0;
    *(undefined4 *)(local_6438 + 0x110) = 0;
    *(undefined4 *)(local_6438 + 0x118) = 0;
    *(undefined4 *)(local_6438 + 0x11c) = 0;
    *(undefined4 *)(local_6438 + 0x120) = 0;
    *(undefined4 *)(local_6438 + 0x124) = 0;
    *(undefined4 *)(local_6438 + 0x128) = 0;
    *(undefined4 *)(local_6438 + 300) = 0;
    *(undefined4 *)(local_6438 + 0x114) = 0;
    *(undefined4 *)(local_6438 + 0x130) = 0;
    *(undefined4 *)(local_6438 + 0x134) = 0;
    *(undefined4 *)(local_6438 + 0x138) = 0;
    *(undefined4 *)(local_6438 + 0x1dc) = 0;
    *(undefined4 *)(local_6438 + 0x1e0) = 0;
    *(undefined4 *)(local_6438 + 0x1e8) = 0;
    *(undefined4 *)(local_6438 + 0x1ec) = 0;
    if (*(int *)(local_6438 + 0xc) == 0) {
      local_64f8 = FUN_0076c9c0(param_1,param_2);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00447100();
      local_8 = 0xffffffff;
      FUN_0079dfff();
      ExceptionList = local_10;
      return local_64f8;
    }
    local_6448 = param_2 + -1;
    switch(local_6448) {
    case 0:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        *(undefined4 *)(local_6438 + 0x134) = 1;
        *(undefined4 *)(local_6438 + 0x138) = 0;
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    case 1:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        *(undefined4 *)(local_6438 + 0xe8) = 1;
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    case 2:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        *(undefined4 *)(local_6438 + 0xf8) = 1;
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    case 3:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        *(undefined4 *)(local_6438 + 0xfc) = 1;
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    case 4:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        *(undefined4 *)(local_6438 + 0x100) = 1;
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    case 5:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        FUN_007751e0();
      }
      break;
    case 6:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        *(undefined4 *)(local_6438 + 0x108) = 1;
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    case 7:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        *(undefined4 *)(local_6438 + 0x10c) = 1;
        *(undefined4 *)(local_6438 + 0x110) = 0;
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    case 8:
      if (param_3 == 1) {
        CStringT<>();
        local_8._0_1_ = 2;
        CStringT<>();
        local_8._0_1_ = 3;
        FUN_00404900();
        FUN_00404900();
        if ((DAT_00a0b3c0 & 8) != 0) {
          local_64fc = FUN_005977f0();
          local_8._0_1_ = 4;
          local_6464 = local_64fc;
          FUN_00404950();
          local_8._0_1_ = 3;
          FUN_00404770();
          FUN_00464110();
        }
        if ((DAT_00a0b3c0 & 4) != 0) {
          local_6470 = FUN_005977f0();
          local_8._0_1_ = 5;
          local_646c = local_6470;
          FUN_00404950();
          local_8._0_1_ = 3;
          FUN_00404770();
          FUN_00464110();
        }
        if ((DAT_00a0b3c0 & 2) != 0) {
          local_647c = FUN_005977f0();
          local_8._0_1_ = 6;
          local_6478 = local_647c;
          FUN_00404950();
          local_8._0_1_ = 3;
          FUN_00404770();
          FUN_00464110();
        }
        if ((DAT_00a0b3c0 & 1) != 0) {
          local_6488 = FUN_005977f0();
          local_8._0_1_ = 7;
          local_6484 = local_6488;
          FUN_00404950();
          local_8._0_1_ = 3;
          FUN_00404770();
          FUN_00464110();
        }
        cVar1 = FUN_00447350();
        if (cVar1 == '\0') {
          local_64b8 = FUN_005977f0();
          local_8._0_1_ = 0xb;
          local_64b4 = local_64b8;
          local_64c0 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                        *)FUN_005977f0();
          local_8._0_1_ = 0xc;
          local_64bc = local_64c0;
          local_64c8 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                        *)ATL::operator+(local_64d8,local_64c0);
          local_8._0_1_ = 0xd;
          local_64c4 = local_64c8;
          local_64d0 = ATL::operator+(local_6500,local_64c8);
          local_8._0_1_ = 0xe;
          local_64cc = local_64d0;
          FUN_00404860();
          local_8._0_1_ = 0xd;
          FUN_00404540();
          local_8._0_1_ = 0xc;
          FUN_00404540();
          local_8._0_1_ = 0xb;
          FUN_00404770();
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_00404770();
        }
        else {
          local_6494 = FUN_005977f0();
          local_8._0_1_ = 8;
          local_6490 = local_6494;
          local_64e8 = (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                        *)FUN_005977f0();
          local_8._0_1_ = 9;
          local_6498 = local_64e8;
          local_64a4 = ATL::operator+(local_64a8,local_64e8);
          local_8._0_1_ = 10;
          local_64a0 = local_64a4;
          FUN_00404860();
          local_8._0_1_ = 9;
          FUN_00404540();
          local_8._0_1_ = 8;
          FUN_00404770();
          local_8 = CONCAT31(local_8._1_3_,3);
          FUN_00404770();
        }
        FUN_00403dd0(local_6444);
        FUN_00516ac0();
        local_8._0_1_ = 2;
        FUN_00404540();
        local_8._0_1_ = 1;
        FUN_00404540();
      }
      else if (param_3 == 2) {
        if ((DAT_00a0b3c0 & 8) != 0) {
          *(undefined4 *)(local_6438 + 0x130) = 1;
        }
        if ((DAT_00a0b3c0 & 4) != 0) {
          *(undefined4 *)(local_6438 + 0x114) = 1;
        }
        if ((DAT_00a0b3c0 & 2) != 0) {
          *(undefined4 *)(local_6438 + 0x10c) = 1;
        }
        if ((DAT_00a0b3c0 & 1) != 0) {
          *(undefined4 *)(local_6438 + 0x108) = 1;
        }
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    case 9:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        *(undefined4 *)(local_6438 + 0x114) = 1;
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    case 10:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        *(undefined4 *)(local_6438 + 0x130) = 1;
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    case 0xb:
      if (param_3 == 1) {
        FUN_005168b0();
      }
      else if (param_3 == 2) {
        *(undefined4 *)(local_6438 + 0xec) = 1;
        iVar3 = FUN_007021e0();
        if (iVar3 != 0) {
          FUN_005168b0();
        }
      }
      break;
    default:
      local_6440 = FUN_0076c9c0(param_1,param_2);
    }
  }
  local_64e4 = local_6440;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return local_64e4;
}



