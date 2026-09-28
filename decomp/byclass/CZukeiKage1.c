/* CZukeiKage1 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiKage1[1] */
/* 00694170  FUN_00694170  68 bytes, 0 callers */

undefined4 FUN_00694170(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00694050();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,400);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiKage1[6] */
/* 00694750  FUN_00694750  146 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00694750(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_74 [108];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0xb4) < 6) {
    if (*(int *)(in_ECX + 0xa8) == 0) {
      FUN_004efbb0(0x151b,0,0);
    }
  }
  else {
    FUN_005977f0(0x16b6);
    uVar1 = FUN_00404920();
    FUN_00693680(local_74,uVar1);
    FUN_00404770();
    FUN_004efbb0(0x15b8,local_74,0);
  }
  return;
}




/* vtable slots: CZukeiKage1[16] */
/* 006947f0  FUN_006947f0  53 bytes, 0 callers */

bool FUN_006947f0(void)

{
  bool bVar1;
  int in_ECX;
  
  bVar1 = 5 < *(int *)(in_ECX + 0xb4);
  if (bVar1) {
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    FUN_006941c0();
  }
  return bVar1;
}




/* vtable slots: CZukeiKage1[0] */
/* 00694830  FUN_00694830  16 bytes, 0 callers */

undefined ** FUN_00694830(void)

{
  return &PTR_s_CZukeiKage1_00979160;
}




/* vtable slots: CZukeiKage1[26] */
/* 00697720  FUN_00697720  56 bytes, 0 callers */

void FUN_00697720(void)

{
  int *in_ECX;
  
  in_ECX[0x2d] = 2;
  in_ECX[0x4c] = 0;
  in_ECX[0x4d] = 0x3ff00000;
  (**(code **)(*in_ECX + 0xc))();
  return;
}




/* vtable slots: CZukeiKage1[27] */
/* 00697760  FUN_00697760  56 bytes, 0 callers */

void FUN_00697760(void)

{
  int *in_ECX;
  
  in_ECX[0x2d] = 3;
  in_ECX[0x4c] = 0;
  in_ECX[0x4d] = -0x40100000;
  (**(code **)(*in_ECX + 0xc))();
  return;
}




/* vtable slots: CZukeiKage1[28] */
/* 006977a0  FUN_006977a0  1251 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006977a0(void)

{
  int iVar1;
  float10 fVar2;
  undefined8 local_368;
  undefined8 local_360;
  undefined8 local_358;
  undefined8 local_350;
  undefined8 local_348;
  undefined8 local_340;
  undefined8 local_338;
  undefined1 local_330 [4];
  int local_32c;
  double local_328;
  int *local_320;
  double local_26c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b83b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(local_14);
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(local_320[1] + 0x8614)) {
    local_320[0x2d] = 4;
    local_328 = 4.0;
    if (*(int *)(local_320[1] + 0x83d0) != 0) {
      local_328 = 3.0;
    }
    if ((((DAT_00a08adc & 1) != 0) || (DAT_00a0cc6c != 0)) || (DAT_00a0cc74 != 0)) {
      local_368 = 0;
      local_360 = 0;
      local_358 = 0;
      local_350 = 0;
      local_348 = 0;
      local_338 = 0;
      local_340 = 0;
      local_328 = 10800.0;
      FUN_00542070((int)*(undefined8 *)(local_320[1] + 0x83c0),
                   (int)((ulonglong)*(undefined8 *)(local_320[1] + 0x83c0) >> 0x20),
                   (int)*(undefined8 *)(local_320[1] + 0x83c8),
                   (int)((ulonglong)*(undefined8 *)(local_320[1] + 0x83c8) >> 0x20),&local_368,
                   &local_360,&local_358,&local_350,&local_348);
      for (local_32c = 0x2a30; local_32c < 0x4e21; local_32c = local_32c + 0x3c) {
        FUN_00542180(local_32c,local_368,(int)local_360,(int)((ulonglong)local_360 >> 0x20),
                     (int)local_358,(int)((ulonglong)local_358 >> 0x20),(int)local_350,
                     (int)((ulonglong)local_350 >> 0x20),local_348,&local_338,&local_340);
        fVar2 = (float10)FUN_008f8d10();
        if (20.0 < (double)fVar2) break;
        local_328 = (double)local_32c;
      }
      local_328 = (double)(int)((local_328 / 3600.0) * 10.0) / 10.0;
      if (*(int *)(local_320[1] + 0x83d0) == 0) {
        if (local_328 < 4.0) {
          local_328 = 4.0;
        }
      }
      else if (local_328 < 3.0) {
        local_328 = 3.0;
      }
    }
    DAT_00a0cc74 = 0;
    DAT_00a0cc6c = 0;
    CStringT<>();
    local_8 = 0;
    FUN_004059f0(local_330,L"%lg - %lg",12.0 - local_328,local_328 + 12.0);
    FUN_0054fd30();
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    local_26c = *(double *)(*(int *)(iVar1 + 0x1a0) + 0xe8);
    FUN_00404860();
    iVar1 = FUN_0079850d();
    if (((iVar1 == 1) && ((12.0 - local_328) - 1e-07 <= local_26c)) &&
       (local_26c <= local_328 + 12.0 + 1e-07)) {
      *(double *)(local_320 + 0x4c) = local_26c;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      *(undefined8 *)(*(int *)(iVar1 + 0x1a0) + 0xe8) = *(undefined8 *)(local_320 + 0x4c);
      (**(code **)(*local_320 + 0xc))();
    }
    local_8 = local_8 & 0xffffff00;
    FUN_0054fe40();
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKage1[29] */
/* 00697c90  FUN_00697c90  58 bytes, 0 callers */

void FUN_00697c90(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
    *(undefined4 *)(in_ECX + 0xb4) = 5;
  }
  return;
}




/* vtable slots: CZukeiKage1[30] */
/* 00697cd0  FUN_00697cd0  78 bytes, 0 callers */

void FUN_00697cd0(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
    *(undefined4 *)(in_ECX + 0xb4) = 6;
    FUN_00698630();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiKage1[31] */
/* 00697d20  FUN_00697d20  108 bytes, 0 callers */

void FUN_00697d20(void)

{
  int iVar1;
  int *in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if ((*(int *)(iVar1 + 0x1a0) == *(int *)(in_ECX[1] + 0x8614)) &&
     ((**(code **)(*in_ECX + 0x84))(), in_ECX[0x2d] != 0)) {
    in_ECX[0x2d] = 7;
    FUN_00698630();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukeiKage1[32] */
/* 00697d90  FUN_00697d90  362 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00697d90(void)

{
  double dVar1;
  int iVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b880;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(in_ECX[1] + 0x8614)) {
    in_ECX[0x2d] = 8;
    FUN_00698630();
    FUN_0054fd30(0);
    local_8 = 0;
    FUN_00404860(in_ECX + 0x5f);
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    dVar1 = *(double *)(*(int *)(iVar2 + 0x1a0) + 0xf0);
    FUN_00404860(in_ECX + 0x60);
    iVar2 = FUN_0079850d();
    if (iVar2 == 1) {
      if (10.0 <= dVar1) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        *(double *)(*(int *)(iVar2 + 0x1a0) + 0xf0) = dVar1;
      }
    }
    else {
      (**(code **)(*in_ECX + 0x40))();
    }
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = 0xffffffff;
    FUN_0054fe40();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKage1[33] */
/* 00697f00  FUN_00697f00  752 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00697f00(void)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  double local_328;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093b8e1;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(uVar2);
  iVar3 = FUN_004fca20();
  if (*(int *)(iVar3 + 0x1a0) == *(int *)(in_ECX[1] + 0x8614)) {
    in_ECX[0x2d] = 9;
    FUN_00698630();
    FUN_00404c80(uVar2);
    iVar3 = FUN_004fca20();
    dVar1 = *(double *)(*(int *)(iVar3 + 0x1a0) + 0xf8);
    local_328 = 10.0;
    while( true ) {
      FUN_0054fd30(0);
      local_8 = 0;
      FUN_00404860(in_ECX + 0x62);
      if (local_328 < 0.0) {
        uVar4 = FUN_005977f0(0x1679);
        local_8._0_1_ = 1;
        FUN_00404860(uVar4);
        local_8._0_1_ = 0;
        FUN_00404770();
        uVar4 = FUN_005977f0(0x1599);
        local_8._0_1_ = 2;
        FUN_00404950(uVar4);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00404770();
      }
      FUN_00404860(in_ECX + 0x61);
      uVar4 = FUN_005977f0(0x14b4);
      local_8._0_1_ = 3;
      FUN_00404950(uVar4);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00404770();
      FUN_00404950(in_ECX + 0x52);
      iVar3 = FUN_0079850d();
      if (iVar3 != 1) {
        (**(code **)(*in_ECX + 0x40))();
        FUN_00404c80();
        FUN_0056d7d0();
        local_8 = 0xffffffff;
        FUN_0054fe40();
        ExceptionList = local_10;
        return;
      }
      local_8 = 0xffffffff;
      FUN_0054fe40();
      if (*(double *)(in_ECX[1] + 0x83b0) + 0.1 < dVar1) break;
      local_328 = -10.0;
    }
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(double *)(*(int *)(iVar3 + 0x1a0) + 0xf8) = dVar1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKage1[9] */
/* 00698380  FUN_00698380  325 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00698380(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 local_6418 [20];
  undefined4 local_6404;
  undefined4 local_6400;
  undefined4 local_63fc;
  int local_63f8;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092cf8b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
  local_8._0_1_ = 1;
  local_6404 = 0;
  FUN_0044dd90(local_6418,*(undefined4 *)(local_63f8 + 4));
  if (*(int *)(local_63f8 + 0xb4) < 6) {
    local_6400 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_63fc = local_6400;
  }
  else {
    FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
    local_63fc = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_63fc;
}




/* vtable slots: CZukeiKage1[11] */
/* 006984d0  FUN_006984d0  285 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006984d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938a20;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  if ((5 < in_ECX[0x2d]) && (iVar1 = FUN_00451eb0(in_ECX[1],&local_24,1), iVar1 == 0)) {
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return 0;
  }
  uVar2 = (**(code **)(*in_ECX + 0x24))(param_1,local_24,local_20,local_1c,local_18);
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiKage1[3] */
/* 00698780  FUN_00698780  518 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00698845) */

void FUN_00698780(void)

{
  int in_ECX;
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 local_44;
  undefined8 local_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  undefined2 local_1c [10];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = in_ECX;
  if (*(int *)(in_ECX + 0xb4) < 6) {
    local_30 = 0;
    local_2c = 0;
    local_44 = 0x3ff0000000000000;
    local_24 = 0;
    local_28 = 0;
    local_1c[0] = 0;
    local_3c = *(undefined8 *)(*(int *)(in_ECX + 4) + 0x83b0);
    if (*(int *)(in_ECX + 0xc0) != 0) {
      local_3c = *(undefined8 *)(*(int *)(in_ECX + 4) + 0x83b8);
    }
    uVar1 = *(undefined8 *)(*(int *)(in_ECX + 4) + 0x83c0);
    uVar2 = *(undefined8 *)(*(int *)(in_ECX + 4) + 0x83c8);
    local_34 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0x83d0);
    *(undefined4 *)(*(int *)(in_ECX + 0xbc) + 0x4a524) =
         *(undefined4 *)(*(int *)(in_ECX + 4) + 0x83d8);
    local_24 = FUN_00542310(&local_30,&local_2c,(int)local_3c,(int)((ulonglong)local_3c >> 0x20),
                            &local_44,*(undefined4 *)(in_ECX + 0xc0),local_1c,uVar1,uVar2);
    if (0 < local_24) {
      FUN_0053edd0(*(undefined8 *)(local_20 + 0x130),local_30,local_2c,uVar1,uVar2,local_24,
                   (int)local_44,(int)((ulonglong)local_44 >> 0x20),local_34,
                   *(undefined4 *)(local_20 + 0xc0));
    }
  }
  else {
    *(undefined4 *)(in_ECX + 0xb8) = 0;
    if ((DAT_00a0cc6c != 0) || (DAT_00a0cc74 != 0)) {
      DAT_00a0cc74 = 0;
      DAT_00a0cc6c = 0;
      *(undefined4 *)(in_ECX + 0xb8) = 1;
    }
    FUN_00694840();
    *(undefined4 *)(local_20 + 0xb4) = 0;
    FUN_006941c0();
    *(undefined4 *)(local_20 + 0xb8) = 0;
  }
  return;
}



