/* CZukeiKage3 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiKage3[29], CZukeiKage3[30], CZukeiKage3[33], CZukeiTakakukei[29] */
/* 004b1f30  FUN_004b1f30  23 bytes, 0 callers */

void FUN_004b1f30(void)

{
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiKage3[1] */
/* 0069cbe0  FUN_0069cbe0  68 bytes, 0 callers */

undefined4 FUN_0069cbe0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0069cb60();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x9e0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiKage3[6] */
/* 0069d130  FUN_0069d130  194 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0069d130(void)

{
  int in_ECX;
  undefined1 local_60 [88];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(in_ECX + 0xa8) == 0) && (*(int *)(in_ECX + 0x130) < 99)) {
    FUN_0069c790(local_60,L"    (No.%d)",*(int *)(in_ECX + 300) + *(int *)(in_ECX + 0x130));
    FUN_004efbb0(0x15a5,local_60,0);
  }
  else if ((*(int *)(in_ECX + 0xa8) == 0) && (0x62 < *(int *)(in_ECX + 0x130))) {
    FUN_004efbb0(0x151b,0,0);
  }
  else if (*(int *)(in_ECX + 0xa8) == 3) {
    FUN_004efbb0(0x15b8,0,0);
  }
  return;
}




/* vtable slots: CZukeiKage3[16] */
/* 0069d200  FUN_0069d200  131 bytes, 0 callers */

undefined4 FUN_0069d200(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xa8) == 3) {
    *(undefined4 *)(in_ECX + 0xa8) = 0;
    FUN_0069cc30();
    FUN_00404c80();
    FUN_0056d7d0();
    uVar1 = 1;
  }
  else {
    *(int *)(in_ECX + 0x130) = *(int *)(in_ECX + 0x130) + -1;
    if (*(int *)(in_ECX + 0x130) < 0) {
      *(undefined4 *)(in_ECX + 0x130) = 0;
    }
    FUN_0069cc30();
    FUN_00404c80();
    FUN_0056d7d0();
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CZukeiKage3[0] */
/* 0069d290  FUN_0069d290  16 bytes, 0 callers */

undefined ** FUN_0069d290(void)

{
  return &PTR_s_CZukeiKage3_00979438;
}




/* vtable slots: CZukeiKage3[26] */
/* 0069d2a0  FUN_0069d2a0  46 bytes, 0 callers */

void FUN_0069d2a0(void)

{
  int in_ECX;
  
  if (0 < *(int *)(in_ECX + 0x130)) {
    *(undefined4 *)(in_ECX + 0x128) = 0x3c;
    FUN_0069e850();
  }
  return;
}




/* vtable slots: CZukeiKage3[27] */
/* 0069d2d0  FUN_0069d2d0  46 bytes, 0 callers */

void FUN_0069d2d0(void)

{
  int in_ECX;
  
  if (0 < *(int *)(in_ECX + 0x130)) {
    *(undefined4 *)(in_ECX + 0x128) = 10;
    FUN_0069e850();
  }
  return;
}




/* vtable slots: CZukeiKage3[28] */
/* 0069d300  FUN_0069d300  46 bytes, 0 callers */

void FUN_0069d300(void)

{
  int in_ECX;
  
  if (0 < *(int *)(in_ECX + 0x130)) {
    *(undefined4 *)(in_ECX + 0x128) = 1;
    FUN_0069e850();
  }
  return;
}




/* vtable slots: CZukeiKage3[31] */
/* 0069d330  FUN_0069d330  271 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0069d330(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bd1b;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0054fd30(0);
  local_8 = 0;
  iVar1 = *(int *)(in_ECX + 300);
  uVar3 = FUN_005977f0(0x15b7);
  local_8._0_1_ = 1;
  FUN_00404860(uVar3);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00404770(uVar2);
  iVar4 = FUN_0079850d();
  if ((iVar4 == 1) && (1.0 <= (double)iVar1)) {
    *(int *)(in_ECX + 300) = (int)(double)iVar1;
  }
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = 0xffffffff;
  FUN_0054fe40();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKage3[32] */
/* 0069d440  FUN_0069d440  80 bytes, 0 callers */

void FUN_0069d440(void)

{
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 4) + 0x83dc) == 0) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x83dc) = 1;
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x83dc) = 0;
  }
  FUN_0069cc30();
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiKage3[9] */
/* 0069d490  FUN_0069d490  1118 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0069d490(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined8 *puVar2;
  float10 fVar3;
  undefined1 *local_651c;
  undefined8 local_6518;
  undefined8 local_6510;
  uint uStack_6508;
  double local_64e4;
  double local_64cc;
  double local_64c4;
  double local_64bc;
  undefined1 *local_64b4;
  undefined4 local_64b0;
  undefined1 local_64ac [20];
  undefined4 local_6498;
  undefined4 local_6494;
  undefined4 local_6490;
  undefined1 local_648c [4];
  int local_6488;
  undefined1 local_6484 [25336];
  undefined4 local_18c;
  undefined1 local_b4 [42];
  undefined2 local_8a;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bd81;
  local_10 = ExceptionList;
  uStack_6508 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6510 = CONCAT44(0x69d4d0,(undefined4)local_6510);
  local_14 = uStack_6508;
  FUN_00446aa0();
  local_8 = 0;
  local_6510 = CONCAT44(*(undefined4 *)(local_6488 + 4),0x69d4ec);
  FUN_0079dea2();
  local_8._0_1_ = 1;
  if (*(int *)(local_6488 + 0xa8) == 3) {
    local_6518 = CONCAT44(param_3,param_2);
    local_6510 = CONCAT44(param_5,param_4);
    local_651c = local_24;
    FUN_004988c0();
    local_6490 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    local_6510 = CONCAT44(0x69d549,(undefined4)local_6510);
    FUN_0079dfff();
    local_8 = 0xffffffff;
    local_6510 = CONCAT44(0x69d55b,(undefined4)local_6510);
    FUN_00447100();
    ExceptionList = local_10;
    return local_6490;
  }
  if (*(int *)(local_6488 + 0x130) < 99) {
    if (*(int *)(local_6488 + 0xb8) != 0) {
      iVar1 = *(int *)(local_6488 + 0xb8);
      local_651c = *(undefined1 **)(iVar1 + 0x18);
      local_6518 = *(undefined8 *)(iVar1 + 0x1c);
      local_6510 = (ulonglong)*(uint *)(iVar1 + 0x24);
      iVar1 = *(int *)(local_6488 + 0xb8);
      FUN_005f8940(*(undefined4 *)(iVar1 + 8),*(undefined4 *)(iVar1 + 0xc),
                   *(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14));
      local_6510 = CONCAT44(param_5,param_4);
      local_6518 = CONCAT44(param_3,param_2);
      local_651c = (undefined1 *)0x1;
      fVar3 = (float10)FUN_005f8b60();
      local_64bc = (double)fVar3;
      if (local_64bc < 0.0) {
LAB_0069d6a0:
        local_6510 = 0;
        local_6518 = 0x270f0000270f;
        local_651c = (undefined1 *)0x69d6b9;
        puVar2 = (undefined8 *)FUN_0041c8d0();
        local_6518 = *puVar2;
        local_651c = (undefined1 *)0x15be;
        FUN_005168b0();
        local_6494 = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        local_6510 = CONCAT44(0x69d6ec,(undefined4)local_6510);
        FUN_0079dfff();
        local_8 = 0xffffffff;
        local_6510 = CONCAT44(0x69d6fe,(undefined4)local_6510);
        FUN_00447100();
        ExceptionList = local_10;
        return local_6494;
      }
      local_6510 = CONCAT44(param_5,param_4);
      local_6518 = CONCAT44(param_3,param_2);
      local_651c = (undefined1 *)0x1;
      fVar3 = (float10)FUN_005f8b60();
      local_64c4 = (double)fVar3;
      if (local_64e4 < local_64c4) goto LAB_0069d6a0;
      local_6510 = CONCAT44(param_5,param_4);
      local_6518 = CONCAT44(param_3,param_2);
      local_651c = (undefined1 *)0x1;
      fVar3 = (float10)FUN_005f8c20();
      local_64cc = (double)fVar3;
      if (local_64cc < 0.0) goto LAB_0069d6a0;
    }
    local_6510 = CONCAT44(0x69d714,(undefined4)local_6510);
    FUN_0041fb60();
    local_8._0_1_ = 2;
    local_6518 = CONCAT44(param_3,param_2);
    local_6510 = CONCAT44(param_5,param_4);
    local_651c = local_34;
    FUN_004988c0();
    local_8a = 1;
    local_6510 = 0x100000001;
    local_6518 = CONCAT44(local_b4,*(undefined4 *)(local_6488 + 4));
    local_651c = local_64ac;
    local_64b0 = FUN_00450860();
    local_18c = 1;
    *(int *)(local_6488 + 0x130) = *(int *)(local_6488 + 0x130) + 1;
    *(ulonglong *)(local_6488 + 0x138 + *(int *)(local_6488 + 0x130) * 8) =
         CONCAT44(param_3,param_2);
    *(ulonglong *)(local_6488 + 0x4a8 + *(int *)(local_6488 + 0x130) * 8) =
         CONCAT44(param_5,param_4);
    local_6510 = CONCAT44(0x69d7ec,(undefined4)local_6510);
    CStringT<>();
    local_8._0_1_ = 3;
    local_6510 = CONCAT44(*(int *)(local_6488 + 300) + -1 + *(int *)(local_6488 + 0x130),L"No.%d");
    local_6518 = CONCAT44(local_648c,0x69d81e);
    FUN_004059f0();
    local_651c = (undefined1 *)&local_6518;
    local_6518 = CONCAT44(param_3,param_2);
    local_6510 = CONCAT44(param_5,param_4);
    local_64b4 = (undefined1 *)&local_651c;
    FUN_00403dd0(local_648c);
    FUN_0069e630(local_64ac,local_6484);
    local_8._0_1_ = 2;
    local_6510 = CONCAT44(0x69d87c,(undefined4)local_6510);
    FUN_00404540();
    local_8._0_1_ = 1;
    local_6510 = CONCAT44(0x69d88b,(undefined4)local_6510);
    FUN_0041fe70();
  }
  local_6510 = CONCAT44(0x69d896,(undefined4)local_6510);
  FUN_0069cc30();
  local_6510 = CONCAT44(0x69d89b,(undefined4)local_6510);
  FUN_00404c80();
  local_6510 = CONCAT44(0x69d8a2,(undefined4)local_6510);
  FUN_0056d7d0();
  local_6498 = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  local_6510 = CONCAT44(0x69d8bb,(undefined4)local_6510);
  FUN_0079dfff();
  local_8 = 0xffffffff;
  local_6510 = CONCAT44(0x69d8cd,(undefined4)local_6510);
  FUN_00447100();
  ExceptionList = local_10;
  return local_6498;
}




/* vtable slots: CZukeiKage3[11] */
/* 0069d8f0  FUN_0069d8f0  270 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0069d8f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  iVar1 = FUN_00451eb0(in_ECX[1],&local_24,1);
  if (iVar1 == 0) {
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar2 = 0;
  }
  else {
    uVar2 = (**(code **)(*in_ECX + 0x24))(param_1,local_24,local_20,local_1c,local_18);
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiKage3[3] */
/* 0069da00  FUN_0069da00  3111 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0069da00(void)

{
  int iVar1;
  float10 fVar2;
  undefined1 local_64dc [48];
  double local_64ac;
  undefined8 local_64a4;
  double local_649c;
  double local_6494;
  double local_648c;
  undefined1 local_6484 [20];
  int local_6470;
  int local_646c;
  int local_6468;
  double local_6464;
  double local_645c;
  double local_6454;
  double local_644c;
  double local_6444;
  double local_643c;
  undefined8 local_6434;
  int local_642c;
  int local_6428;
  int local_6424;
  int local_6420;
  undefined4 local_641c;
  int local_6418;
  undefined1 local_6414 [25336];
  undefined4 local_11c;
  double local_34;
  double local_2c;
  double local_24;
  double local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bdcb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2();
  local_8 = CONCAT31(local_8._1_3_,1);
  local_6424 = 1;
  local_642c = 1;
  local_6420 = 1;
  local_24 = *(double *)(local_6418 + 0x9d0);
  local_1c = *(double *)(local_6418 + 0x9d8);
  FUN_00408a60();
  FUN_00408a60();
  local_6468 = *(int *)(*(int *)(local_6418 + 4) + 0x83d0);
  local_6494 = (*(double *)(*(int *)(local_6418 + 4) + 0x17c0) * 3.141592653589793) / 180.0;
  FUN_005f8a10();
  local_6424 = 1;
  do {
    if (*(int *)(local_6418 + 0x130) < local_6424) {
      *(undefined4 *)(local_6418 + 0xa8) = 0;
      *(int *)(local_6418 + 300) = *(int *)(local_6418 + 300) + *(int *)(local_6418 + 0x130);
      *(undefined4 *)(local_6418 + 0x130) = 0;
      FUN_0069cc30();
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = local_8 & 0xffffff00;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    FUN_005f9a30();
    local_6434 = 0x3fe3333333333333;
    local_645c = 0.0;
    local_6454 = 0.0;
    local_644c = 0.0;
    local_6444 = 0.0;
    local_649c = 480.0;
    if (local_6468 != 0) {
      local_649c = 360.0;
    }
    FUN_00403dd0(local_6418 + 0x818 + local_6424 * 4);
    fVar2 = (float10)FUN_0069e630();
    local_6464 = (double)fVar2;
    if (*(int *)(*(int *)(local_6418 + 4) + 0x83dc) != 0) {
      local_64a4 = 0x3ff0000000000000;
      local_643c = 2.0;
      local_641c = 1;
      fVar2 = (float10)FUN_005f8b60();
      local_34 = (double)fVar2;
      fVar2 = (float10)FUN_005f8c20();
      local_2c = (double)fVar2;
      FUN_005f9a30();
      FUN_0069cf20(local_6414,local_6484,local_641c,local_64dc,0,local_649c * 60.0,local_6434);
      local_11c = 1;
      FUN_0069cf20(local_6414,local_6484,local_641c,local_64dc,0,local_649c * 60.0,local_6434);
      local_6428 = 8;
      if (local_6468 != 0) {
        local_6428 = 6;
      }
      for (local_6420 = 0; local_6420 <= local_6428; local_6420 = local_6420 + 1) {
        FUN_0069cf20(local_6414,local_6484,local_641c,local_64dc,(double)(local_6420 * 0xe10),
                     (double)(local_6420 * 0xe10),local_6434);
      }
      local_6428 = local_6428 / 2;
      local_646c = 0;
      if (-30000 < *(int *)(*(int *)(local_6418 + 0xb4) + 0x4a468)) {
        local_646c = 1;
        local_648c = local_643c / 3.0;
        local_641c = 3;
        local_644c = (double)(*(int *)(*(int *)(local_6418 + 0xb4) + 0x4a468) + local_6428 * 0xe10);
        local_6444 = (double)(*(int *)(*(int *)(local_6418 + 0xb4) + 0x4a46c) + local_6428 * 0xe10);
        FUN_0069cf20(local_6414,local_6484,3,local_64dc,local_644c,local_644c,local_6434);
        FUN_0069cf20(local_6414,local_6484,local_641c,local_64dc,local_6444,local_6444,local_6434);
        FUN_0069cf20(local_6414,local_6484,local_641c,local_64dc,local_644c,local_6444,local_6434);
        FUN_0069cf20(local_6414,local_6484,local_641c,local_64dc,local_644c,local_6444,local_6434);
      }
      local_641c = 4;
      for (local_642c = 1;
          local_642c <= *(int *)(*(int *)(local_6418 + 0xb4) + 0x2770c + local_6424 * 4);
          local_642c = local_642c + 1) {
        local_645c = (double)(*(int *)(*(int *)(local_6418 + 0xb4) + 0x280bc +
                                      (local_6424 * 200 + local_642c) * 4) + local_6428 * 0xe10);
        local_6454 = (double)(*(int *)(*(int *)(local_6418 + 0xb4) + 0x280bc +
                                      (local_6424 * 200 + 100 + local_642c) * 4) +
                             local_6428 * 0xe10);
        if (local_646c == 0) {
LAB_0069e307:
          FUN_0069cf20(local_6414,local_6484,local_641c,local_64dc,local_645c,local_645c,local_6434)
          ;
          FUN_0069cf20(local_6414,local_6484,local_641c,local_64dc,local_6454,local_6454,local_6434)
          ;
          local_6470 = 10;
          for (local_6420 = 0; local_6420 <= local_6470; local_6420 = local_6420 + 1) {
            local_64ac = ((double)local_6420 * local_643c) / (double)local_6470;
            iVar1 = FUN_0069cf20(local_6414,local_6484,local_641c,local_64dc,local_645c,local_6454,
                                 local_6434);
            if (iVar1 == 0) break;
          }
        }
        else {
          if ((local_644c <= local_645c) && (local_645c <= local_6444)) {
            local_645c = local_6444;
          }
          if ((local_644c <= local_6454) && (local_6454 <= local_6444)) {
            local_6454 = local_644c;
          }
          if (local_645c < local_6454) goto LAB_0069e307;
        }
      }
      local_6464 = local_6464 + 3.0;
    }
    local_6464 = local_6464 + 2.0;
    fVar2 = (float10)FUN_008f8f00();
    local_24 = (double)fVar2 * local_6464 + local_24;
    fVar2 = (float10)FUN_008f8eb0();
    local_1c = local_1c - (double)fVar2 * local_6464;
    local_6424 = local_6424 + 1;
  } while( true );
}



