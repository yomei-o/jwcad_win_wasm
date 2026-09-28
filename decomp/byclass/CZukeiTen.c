/* CZukeiTen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiTen[1] */
/* 00731cd0  FUN_00731cd0  68 bytes, 0 callers */

undefined4 FUN_00731cd0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00731c30();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x178);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiTen[6] */
/* 00731d20  FUN_00731d20  657 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00731d20(void)

{
  uint uVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined1 local_63fc [20];
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00940e0b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX[1] + 0x8ebc) = 0;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_00446aa0(uVar1);
  local_8 = 0;
  FUN_0079dea2(local_63e8[1]);
  local_8._0_1_ = 1;
  uVar2 = FUN_0040c0e0();
  FUN_0044dd90(local_63fc,local_63e8[1]);
  FUN_0044de00(local_63fc,local_63e8[1]);
  if (local_63e8[0x50] == 0) {
    if (local_63e8[0x52] == 1) {
      FUN_004efbb0(0x15f7,0,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if (local_63e8[0x52] == 2) {
      FUN_004efbb0(0x15f8,0,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      if (*(int *)(local_63e8[1] + 0x8560) < 1) {
        *(undefined4 *)(local_63e8[1] + 0x8560) = 1;
      }
      if (0 < *(int *)(local_63e8[1] + 0x8560)) {
        *(undefined4 *)(local_63e8[1] + 0x8ebc) = 1;
        FUN_004efbb0(0x1500,0,0);
      }
      if (0 < *(int *)(local_63e8[1] + 0x8560)) {
        (**(code **)(*local_63e8 + 0x20))(uVar1,uVar2);
        FUN_00455c40(1);
        FUN_00450b70(local_63fc,local_63e8[1],local_63e8 + 0x2c);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    FUN_004efbb0(0x157f,0,0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTen[16] */
/* 00731fc0  FUN_00731fc0  57 bytes, 0 callers */

bool FUN_00731fc0(void)

{
  int in_ECX;
  bool bVar1;
  
  bVar1 = *(int *)(in_ECX + 0x148) == 2;
  if (bVar1) {
    *(undefined4 *)(in_ECX + 0x148) = 1;
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return bVar1;
}




/* vtable slots: CZukeiTen[0] */
/* 00732000  FUN_00732000  16 bytes, 0 callers */

undefined ** FUN_00732000(void)

{
  return &PTR_s_CZukeiTen_0097b040;
}




/* vtable slots: CZukeiTen[46] */
/* 007324e0  FUN_007324e0  224 bytes, 0 callers */

undefined4
FUN_007324e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
                           param_3,param_4,param_5,param_6,param_7,6);
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




/* vtable slots: CZukeiTen[25] */
/* 007325c0  FUN_007325c0  76 bytes, 0 callers */

void FUN_007325c0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x148) = 0;
  if (*(int *)(in_ECX + 0x140) == 0) {
    *(undefined4 *)(in_ECX + 0x140) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x140) = 0;
  }
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiTen[26] */
/* 00732610  FUN_00732610  60 bytes, 0 callers */

void FUN_00732610(void)

{
  int in_ECX;
  
  FUN_00732010();
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
  *(undefined4 *)(in_ECX + 0x140) = 0;
  FUN_00404c80();
  FUN_0056d200();
  return;
}




/* vtable slots: CZukeiTen[27] */
/* 00732650  FUN_00732650  109 bytes, 0 callers */

void FUN_00732650(void)

{
  int in_ECX;
  undefined4 uVar1;
  
  *(undefined4 *)(in_ECX + 0x140) = 0;
  if (*(int *)(in_ECX + 0x148) == 0) {
    *(undefined4 *)(in_ECX + 0x148) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x148) = 0;
  }
  uVar1 = *(undefined4 *)(in_ECX + 0x148);
  FUN_00404c80(uVar1);
  FUN_004fca20();
  FUN_00417da0(uVar1);
  FUN_00404c80();
  FUN_0056d200();
  return;
}




/* vtable slots: CZukeiTen[51] */
/* 007326c0  FUN_007326c0  106 bytes, 0 callers */

void FUN_007326c0(void)

{
  undefined4 uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093847d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  uVar1 = DAT_00a0be48;
  FUN_00404c80(DAT_00a0be48,DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  FUN_004fca20();
  FUN_004183a0(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTen[9] */
/* 00732730  FUN_00732730  1001 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00732730(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  int *local_641c;
  int local_6418;
  undefined4 local_f0;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00940ef0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6418 = in_ECX;
  if (*(int *)(in_ECX + 0x140) != 0) {
    uVar1 = FUN_00732200(param_2,param_3,param_4,param_5);
    *(undefined4 *)(local_6418 + 0x144) = uVar1;
    if (*(int *)(local_6418 + 0x144) != 0) {
      ExceptionList = local_10;
      return 1;
    }
    ExceptionList = local_10;
    return 0;
  }
  if (*(int *)(in_ECX + 0x148) != 0) {
    FUN_00446aa0(local_14);
    local_8 = 0;
    local_641c = (int *)0x0;
    local_f0 = 1;
    iVar2 = FUN_0044a270(3,*(undefined4 *)(local_6418 + 4),&param_2,&local_641c,1);
    if (iVar2 == 0) {
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    if (*(int *)(local_6418 + 0x148) == 1) {
      if (*(int *)(local_6418 + 0x14c) != 0) {
        if (*(int **)(local_6418 + 0x14c) != (int *)0x0) {
          (**(code **)(**(int **)(local_6418 + 0x14c) + 4))(1);
        }
        *(undefined4 *)(local_6418 + 0x14c) = 0;
      }
      if (local_641c != (int *)0x0) {
        uVar1 = (**(code **)(*local_641c + 0x14))();
        *(undefined4 *)(local_6418 + 0x14c) = uVar1;
        FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
        *(undefined4 *)(local_6418 + 0x148) = 2;
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 0;
      }
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    if (*(int *)(local_6418 + 0x148) == 2) {
      if (*(int *)(local_6418 + 0x150) != 0) {
        if (*(int **)(local_6418 + 0x150) != (int *)0x0) {
          (**(code **)(**(int **)(local_6418 + 0x150) + 4))(1);
        }
        *(undefined4 *)(local_6418 + 0x150) = 0;
      }
      if (local_641c != (int *)0x0) {
        uVar1 = (**(code **)(*local_641c + 0x14))();
        *(undefined4 *)(local_6418 + 0x150) = uVar1;
        FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
        *(undefined4 *)(local_6418 + 0x148) = 1;
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 1;
      }
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return 0;
    }
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  *(undefined4 *)(*(int *)(local_6418 + 4) + 0x8560) = 0;
  FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
  ExceptionList = local_10;
  return 1;
}




/* vtable slots: CZukeiTen[11] */
/* 00732b20  FUN_00732b20  443 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00732b20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  if (*(int *)(in_ECX + 0x140) == 0) {
    if (*(int *)(in_ECX + 0x148) == 0) {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
      FUN_00446aa0(local_14);
      local_8 = 0;
      local_24 = param_2;
      local_20 = param_3;
      local_1c = param_4;
      local_18 = param_5;
      iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&local_24,1);
      if (iVar2 == 1) {
        uVar1 = FUN_00732730(param_1,local_24,local_20,local_1c,local_18);
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
    else {
      uVar1 = FUN_00732730(param_1,param_2,param_3,param_4,param_5);
    }
  }
  else {
    uVar1 = FUN_00732200(param_2,param_3,param_4,param_5);
    *(undefined4 *)(in_ECX + 0x144) = uVar1;
    if (*(int *)(in_ECX + 0x144) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  ExceptionList = local_10;
  return uVar1;
}



/* vtable slots: CZukeiTen[8] */
/* 00732ce0  FUN_00732ce0  130 bytes, 0 callers */

void FUN_00732ce0(void)

{
  int iVar1;
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 0xb0) + 0x20))(0);
  (**(code **)(*(int *)(in_ECX + 0xb0) + 0x24))(2);
  FUN_0040db50(0);
  iVar1 = *(int *)(in_ECX + 4);
  FUN_0040da70(*(undefined4 *)(iVar1 + 0x8f78),*(undefined4 *)(iVar1 + 0x8f7c),
               *(undefined4 *)(iVar1 + 0x8f80),*(undefined4 *)(iVar1 + 0x8f84));
  return;
}




/* vtable slots: CZukeiTen[4] */
/* 00732d70  FUN_00732d70  525 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00732d70(void)

{
  undefined1 local_6414 [20];
  undefined4 local_6400;
  undefined4 local_63fc;
  int local_63f8;
  int local_63f4;
  int *local_63f0;
  int *local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093774b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044de00(local_6414,*(undefined4 *)(local_63e8 + 4));
  FUN_0044c830(local_6414,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd90(local_6414,*(undefined4 *)(local_63e8 + 4));
  local_63f4 = *(int *)(local_63e8 + 4);
  if (local_63f4 == 0) {
    local_63f8 = 0;
  }
  else {
    local_63f8 = local_63f4 + 0x88;
  }
  FUN_00454890(local_63f8);
  FUN_00454830(*(undefined4 *)(local_63e8 + 4));
  if (*(int *)(local_63e8 + 0x14c) != 0) {
    local_63ec = *(int **)(local_63e8 + 0x14c);
    if (local_63ec == (int *)0x0) {
      local_63fc = 0;
    }
    else {
      local_63fc = (**(code **)(*local_63ec + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0x14c) = 0;
  }
  if (*(int *)(local_63e8 + 0x150) != 0) {
    local_63f0 = *(int **)(local_63e8 + 0x150);
    if (local_63f0 == (int *)0x0) {
      local_6400 = 0;
    }
    else {
      local_6400 = (**(code **)(*local_63f0 + 4))(1);
    }
    *(undefined4 *)(local_63e8 + 0x150) = 0;
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiTen[3] */
/* 00732f80  FUN_00732f80  1116 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00732f80(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_6414 [20];
  int local_6400;
  int local_63fc;
  int local_63f8;
  double local_24;
  double local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00940f3b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63f8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  uVar2 = FUN_0040c0e0(uVar1);
  FUN_00446aa0(uVar1,uVar2);
  local_8._0_1_ = 1;
  if (*(int *)(local_63f8 + 0x140) == 0) {
    if (*(int *)(local_63f8 + 0x148) != 0) {
      *(undefined4 *)(local_63f8 + 0x148) = 1;
      FUN_00408a60();
      local_24 = (*(double *)(local_63f8 + 0x158) + *(double *)(local_63f8 + 0x168)) / 2.0;
      local_1c = (*(double *)(local_63f8 + 0x160) + *(double *)(local_63f8 + 0x170)) / 2.0;
      if ((*(int *)(local_63f8 + 0x14c) == 0) || (*(int *)(local_63f8 + 0x150) == 0)) {
        FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return;
      }
      iVar3 = FUN_0045fa30(*(undefined4 *)(local_63f8 + 0x14c),*(undefined4 *)(local_63f8 + 0x150),
                           local_24,local_1c,local_63f8 + 0x10);
      if (iVar3 == 0) {
        FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f24),
                     *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8f28),0,0);
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return;
      }
    }
    FUN_0040da70(*(undefined4 *)(local_63f8 + 0x10),*(undefined4 *)(local_63f8 + 0x14),
                 *(undefined4 *)(local_63f8 + 0x18),*(undefined4 *)(local_63f8 + 0x1c));
    FUN_0044dd90(local_6414,*(undefined4 *)(local_63f8 + 4));
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0x964) == 0) {
      FUN_00455c40(0);
    }
    else {
      FUN_00455c40(1);
    }
    FUN_004552a0(local_63f8 + 0xb0);
    FUN_00450860(local_6414,*(undefined4 *)(local_63f8 + 4),local_63f8 + 0xb0,1,1);
    *(undefined4 *)(*(int *)(local_63f8 + 4) + 0x8560) = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    ExceptionList = local_10;
    return;
  }
  if (*(int *)(local_63f8 + 0x144) == 0) {
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    ExceptionList = local_10;
    return;
  }
  local_63fc = *(int *)(local_63f8 + 4);
  if (local_63fc == 0) {
    local_6400 = 0;
  }
  else {
    local_6400 = local_63fc + 0x88;
  }
  iVar3 = FUN_0042dcb0(local_6400);
  if (iVar3 != 0) {
    FUN_00516e40(*(undefined4 *)(local_63f8 + 0x144),0,0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    ExceptionList = local_10;
    return;
  }
  FUN_0044b2c0(local_6414,*(undefined4 *)(local_63f8 + 4),*(undefined4 *)(local_63f8 + 0x144),1);
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}



