/* CZukeiSessen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiSessen[1] */
/* 007035d0  FUN_007035d0  68 bytes, 0 callers */

undefined4 FUN_007035d0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00703510();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x198);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiSessen[6] */
/* 00703620  FUN_00703620  764 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00703620(undefined4 *param_1)

{
  int iVar1;
  float10 fVar2;
  undefined1 local_6418 [20];
  double local_6404;
  undefined4 local_63fc;
  int local_63f8;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092cf8b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(local_14);
  iVar1 = FUN_004fca20();
  *(undefined4 *)(local_63f8 + 0xac) = *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x3d8);
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_005cb8c0();
  *(double *)(local_63f8 + 0xb8) = (double)fVar2;
  FUN_00404c80();
  FUN_004fca20();
  fVar2 = (float10)FUN_005cb890();
  local_6404 = (double)fVar2;
  *(double *)(local_63f8 + 0xc0) = local_6404 + *(double *)(*(int *)(local_63f8 + 4) + 0x17c0);
  if (*(int *)(local_63f8 + 0xac) != *(int *)(local_63f8 + 0xb0)) {
    *(undefined4 *)(local_63f8 + 0xb0) = *(undefined4 *)(local_63f8 + 0xac);
    *(undefined4 *)(local_63f8 + 0xb4) = 0;
    if (*(int *)(local_63f8 + 0xac) == 1) {
      *(undefined4 *)(local_63f8 + 0xb4) = 3;
    }
  }
  FUN_00446aa0();
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63f8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044dd90(local_6418,*(undefined4 *)(local_63f8 + 4));
  local_63fc = FUN_0040c0e0();
  if (*(int *)(local_63f8 + 0xb4) == 5) {
    FUN_004efbb0(0x14fb,0,0);
  }
  if (*(int *)(local_63f8 + 0xb4) == 3) {
    if (*(int *)(local_63f8 + 0xac) == 1) {
      FUN_004efbb0(0x14fa,0,0);
    }
    else {
      FUN_004efbb0(0x14c8,0,0);
    }
  }
  if (*(int *)(local_63f8 + 0xb4) == 4) {
    FUN_004988c0(local_24,*param_1,param_1[1],param_1[2],param_1[3]);
    if (*(int *)(local_63f8 + 0xac) == 2) {
      FUN_00705380();
    }
    if (*(int *)(local_63f8 + 0xac) == 3) {
      FUN_00704fa0();
    }
    FUN_004efbb0(0x14c9,0,0);
  }
  if ((*(int *)(local_63f8 + 0xb4) == 0) || (*(int *)(local_63f8 + 0xb4) == 1)) {
    FUN_004efbb0(0x14f7,0,0);
  }
  if (*(int *)(local_63f8 + 0xb4) == 2) {
    FUN_004efbb0(0x14f8,0,0);
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSessen[16] */
/* 00703920  FUN_00703920  310 bytes, 0 callers */

undefined4 FUN_00703920(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) == 5) {
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    FUN_00404c80();
    FUN_0056d7d0();
    return 1;
  }
  if (*(int *)(in_ECX + 0xb4) == 3) {
    if (*(int *)(in_ECX + 0xac) == 2) {
      *(undefined4 *)(in_ECX + 0xb4) = 0;
      FUN_00404c80();
      FUN_0056d7d0();
      return 1;
    }
    if (*(int *)(in_ECX + 0xac) == 3) {
      *(undefined4 *)(in_ECX + 0xb4) = 5;
      FUN_00404c80();
      FUN_0056d7d0();
      return 1;
    }
  }
  if (*(int *)(in_ECX + 0xb4) == 4) {
    *(undefined4 *)(in_ECX + 0xb4) = 3;
    FUN_00404c80();
    FUN_0056d7d0();
    uVar1 = 1;
  }
  else if ((*(int *)(in_ECX + 0xb4) == 1) && (*(int *)(in_ECX + 0xac) == 1)) {
    *(undefined4 *)(in_ECX + 0xb4) = 3;
    FUN_00404c80();
    FUN_0056d7d0();
    uVar1 = 1;
  }
  else if (*(int *)(in_ECX + 0xb4) == 2) {
    *(undefined4 *)(in_ECX + 0xb4) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CZukeiSessen[0] */
/* 00703a60  FUN_00703a60  16 bytes, 0 callers */

undefined ** FUN_00703a60(void)

{
  return &PTR_s_CZukeiSessen_0097a6c8;
}




/* vtable slots: CZukeiSessen[46] */
/* 00703a70  FUN_00703a70  224 bytes, 0 callers */

undefined4
FUN_00703a70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_c [2];
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
      local_c[0] = 0xffffffff;
      iVar2 = FUN_00778a40(1,local_c,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9070),param_1,param_2,
                           param_3,param_4,param_5,param_6,param_7,0x12);
      if (iVar2 != 0) {
        return 0;
      }
    }
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiSessen[47] */
/* 00703b50  FUN_00703b50  224 bytes, 0 callers */

undefined4
FUN_00703b50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_c [2];
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x907c) == 0) {
      local_c[0] = 0xffffffff;
      iVar2 = FUN_00778a40(2,local_c,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x9074),param_1,param_2,
                           param_3,param_4,param_5,param_6,param_7,0x12);
      if (iVar2 != 0) {
        return 0;
      }
    }
    uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiSessen[49] */
/* 00703c30  FUN_00703c30  74 bytes, 0 callers */

void FUN_00703c30(undefined8 param_1)

{
  FUN_00404c80(param_1);
  FUN_004fca20();
  FUN_005cb7d0(param_1);
  FUN_00404c80();
  FUN_004fca20();
  FUN_007955d2();
  return;
}




/* vtable slots: CZukeiSessen[50] */
/* 00703c80  FUN_00703c80  91 bytes, 0 callers */

void FUN_00703c80(double param_1)

{
  if (0.001 <= param_1) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    FUN_005cb820(param_1);
    FUN_00404c80();
    FUN_004fca20();
    FUN_007955d2();
  }
  return;
}




/* vtable slots: CZukeiSessen[51] */
/* 00703ce0  FUN_00703ce0  174 bytes, 0 callers */

void FUN_00703ce0(undefined8 param_1,undefined8 param_2)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093847d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  FUN_00404c80(param_1,DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  FUN_004fca20();
  FUN_005cb7d0(param_1);
  FUN_00404c80(param_2);
  FUN_004fca20();
  FUN_005cb820(param_2);
  FUN_00404c80();
  FUN_004fca20();
  FUN_007955d2();
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSessen[9] */
/* 00703f90  FUN_00703f90  1764 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00703f90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int *local_643c;
  int local_6438;
  undefined4 local_110;
  undefined4 local_10c;
  undefined1 local_64 [16];
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f890;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  if (*(int *)(local_6438 + 0xb4) == 5) {
    FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
    *(undefined4 *)(local_6438 + 0xb4) = 3;
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar2 = 0;
  }
  else if (*(int *)(local_6438 + 0xb4) == 3) {
    FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
    if (*(int *)(local_6438 + 0xac) == 1) {
      *(undefined4 *)(local_6438 + 0xb4) = 1;
    }
    else {
      *(undefined4 *)(local_6438 + 0xb4) = 4;
    }
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar2 = 0;
  }
  else if (*(int *)(local_6438 + 0xb4) == 4) {
    FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
    if (*(int *)(local_6438 + 0xac) == 2) {
      *(undefined4 *)(local_6438 + 0xb4) = 6;
    }
    else {
      *(undefined4 *)(local_6438 + 0xb4) = 6;
    }
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar2 = 1;
  }
  else if ((*(int *)(local_6438 + 0xb4) == 0) || (*(int *)(local_6438 + 0xb4) == 1)) {
    local_110 = 1;
    local_10c = 1;
    iVar1 = FUN_0044a270(3,*(undefined4 *)(local_6438 + 4),&param_2,&local_643c,1);
    if (iVar1 == 0) {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
      if (iVar1 == 0) {
        FUN_005168b0(0x14f9,*(undefined4 *)(*(int *)(local_6438 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6438 + 4) + 0x8f28),0,0);
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 0;
      }
      else {
        if (*(int *)(local_6438 + 0xd8) != 0) {
          if (*(int **)(local_6438 + 0xd8) != (int *)0x0) {
            (**(code **)(**(int **)(local_6438 + 0xd8) + 4))(1);
          }
          *(undefined4 *)(local_6438 + 0xd8) = 0;
        }
        if (local_643c != (int *)0x0) {
          uVar2 = (**(code **)(*local_643c + 0x14))();
          *(undefined4 *)(local_6438 + 0xd8) = uVar2;
        }
        *(undefined4 *)(local_6438 + 0xd0) = *(undefined4 *)(local_6438 + 0xd8);
        FUN_004988c0(local_54,param_2,param_3,param_4,param_5);
        if (*(int *)(local_6438 + 0xac) == 0) {
          *(undefined4 *)(local_6438 + 0xb4) = 2;
        }
        if (*(int *)(local_6438 + 0xac) == 1) {
          *(undefined4 *)(local_6438 + 0xb4) = 6;
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 1;
        }
        else {
          if (*(int *)(local_6438 + 0xac) == 2) {
            *(undefined4 *)(local_6438 + 0xb4) = 3;
          }
          if (*(int *)(local_6438 + 0xac) == 3) {
            *(undefined4 *)(local_6438 + 0xb4) = 5;
          }
          FUN_00404c80();
          FUN_0056d7d0();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar2 = 0;
        }
      }
    }
  }
  else if (*(int *)(local_6438 + 0xb4) == 2) {
    local_110 = 1;
    local_10c = 1;
    iVar1 = FUN_0044a270(3,*(undefined4 *)(local_6438 + 4),&param_2,&local_643c,1);
    if (iVar1 == 0) {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar2 = 0;
    }
    else {
      iVar1 = FUN_0079d98a(&PTR_s_CDataEnko_009fe040);
      if (iVar1 == 0) {
        FUN_005168b0(0x14f9,*(undefined4 *)(*(int *)(local_6438 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_6438 + 4) + 0x8f28),0,0);
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 0;
      }
      else {
        if (*(int *)(local_6438 + 0xdc) != 0) {
          if (*(int **)(local_6438 + 0xdc) != (int *)0x0) {
            (**(code **)(**(int **)(local_6438 + 0xdc) + 4))(1);
          }
          *(undefined4 *)(local_6438 + 0xdc) = 0;
        }
        if (local_643c != (int *)0x0) {
          uVar2 = (**(code **)(*local_643c + 0x14))();
          *(undefined4 *)(local_6438 + 0xdc) = uVar2;
        }
        *(undefined4 *)(local_6438 + 0xd4) = *(undefined4 *)(local_6438 + 0xdc);
        *(undefined4 *)(local_6438 + 0xb4) = 6;
        FUN_004988c0(local_64,param_2,param_3,param_4,param_5);
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar2 = 1;
      }
    }
  }
  else {
    local_8 = 0xffffffff;
    FUN_00447100();
    uVar2 = 0;
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CZukeiSessen[11] */
/* 00704680  FUN_00704680  375 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00704680(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
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
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
  if (((*(int *)(in_ECX + 0xb4) == 0) || (*(int *)(in_ECX + 0xb4) == 1)) ||
     (*(int *)(in_ECX + 0xb4) == 2)) {
    uVar1 = FUN_00703f90(param_1,param_2,param_3,param_4,param_5);
  }
  else {
    FUN_00446aa0(local_14);
    local_8 = 0;
    local_24 = param_2;
    local_20 = param_3;
    local_1c = param_4;
    local_18 = param_5;
    iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
    if (iVar2 == 1) {
      uVar1 = FUN_00703f90(param_1,local_24,local_20,local_1c,local_18);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar1 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiSessen[3] */
/* 00704800  FUN_00704800  401 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00704800(void)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920cbb;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  local_63ec = FUN_0040c0e0(uVar1);
  FUN_00446aa0();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
  if (*(int *)(local_63e8 + 0xac) == 0) {
    FUN_007049a0();
    *(undefined4 *)(local_63e8 + 0xb4) = 1;
  }
  if (*(int *)(local_63e8 + 0xac) == 1) {
    FUN_00705920();
    *(undefined4 *)(local_63e8 + 0xb4) = 3;
  }
  if (*(int *)(local_63e8 + 0xac) == 2) {
    FUN_00705380();
    *(undefined4 *)(local_63e8 + 0xb4) = 1;
  }
  if (*(int *)(local_63e8 + 0xac) == 3) {
    FUN_00704fa0();
    *(undefined4 *)(local_63e8 + 0xb4) = 1;
  }
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = local_8 & 0xffffff00;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}



