/* CZukeiJwmKeisan -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiJwmKeisan[1] */
/* 006858f0  FUN_006858f0  68 bytes, 0 callers */

undefined4 FUN_006858f0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006857c0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x6600);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiJwmKeisan[6] */
/* 006862f0  FUN_006862f0  564 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x006863c7) */

void FUN_006862f0(undefined4 param_1)

{
  int in_ECX;
  undefined1 local_6624 [20];
  undefined4 local_6610;
  int local_660c;
  undefined2 local_218 [258];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ab8b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x200) == 0) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    local_660c = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_660c + 4));
    local_8._0_1_ = 1;
    FUN_00408a60();
    FUN_00408a60();
    local_6610 = 0;
    local_218[0] = 0;
    FUN_0044dd90(local_6624,*(undefined4 *)(local_660c + 4));
    if (*(int *)(local_660c + 0x1f8) != *(int *)(local_660c + 0x1fc)) {
      *(undefined4 *)(local_660c + 0x1fc) = *(undefined4 *)(local_660c + 0x1f8);
    }
    if (*(int *)(local_660c + 0x1f8) == 2) {
      FUN_004efbb0(0x14c6,local_218,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else if ((*(int *)(local_660c + 0x1f8) == 0) || (*(int *)(local_660c + 0x1f8) == 1)) {
      FUN_004efbb0(0x151b,local_218,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      FUN_004efbb0(0x14cb,local_218,0);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    **(undefined4 **)(in_ECX + 8) = 8;
    FUN_006f7cc0(param_1);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiJwmKeisan[16] */
/* 00686530  FUN_00686530  196 bytes, 0 callers */

undefined4 FUN_00686530(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_006878b0();
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (*(int *)(in_ECX + 0xd64) < 1) {
      if (*(int *)(in_ECX + 0x1f8) == 2) {
        FUN_00687210();
        uVar2 = 1;
      }
      else if (*(int *)(in_ECX + 0x1f8) == 1) {
        FUN_00687270();
        uVar2 = 1;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      *(int *)(in_ECX + 0xd64) = *(int *)(in_ECX + 0xd64) + -1;
      uVar2 = 0;
    }
  }
  else {
    iVar1 = FUN_006f85c0();
    if (iVar1 == 0) {
      *(undefined4 *)(in_ECX + 0x200) = 0;
      if (*(int *)(in_ECX + 0xb94) == 0) {
        FUN_00687270();
      }
      else {
        FUN_00687210();
      }
      uVar2 = 1;
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}




/* vtable slots: CZukeiJwmKeisan[0] */
/* 006869a0  FUN_006869a0  16 bytes, 0 callers */

undefined ** FUN_006869a0(void)

{
  return &PTR_s_CZukeiJwmKeisan_00978d60;
}




/* vtable slots: CZukeiJwmKeisan[46] */
/* 00686c90  FUN_00686c90  284 bytes, 0 callers */

undefined4
FUN_00686c90(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if (DAT_00a0c7c0 == 0) {
    if (in_ECX[0x80] == 0) {
      uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else if ((*(int *)(in_ECX[1] + 0x9078) == 0) && (param_2 == 0xc)) {
      if (param_3 == 1) {
        FUN_005168b0(0x147c,*(undefined4 *)(in_ECX[1] + 0x8f50),*(undefined4 *)(in_ECX[1] + 0x8f54),
                     1,0);
      }
      else if (param_3 == 2) {
        (**(code **)(*in_ECX + 0x88))();
      }
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_006f8f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiJwmKeisan[47] */
/* 00686db0  FUN_00686db0  182 bytes, 0 callers */

void FUN_00686db0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int in_ECX;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(in_ECX + 0x200) == 0) {
      FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      FUN_006fa580(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[24] */
/* 00686e70  FUN_00686e70  65 bytes, 0 callers */

void FUN_00686e70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (*(int *)(in_ECX + 0x1f8) == 1) {
      FUN_00687270();
    }
    else {
      FUN_006869b0(0);
    }
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[34] */
/* 00686ec0  FUN_00686ec0  226 bytes, 0 callers */

void FUN_00686ec0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xd64) = 0;
  uVar1 = FUN_0040c0e0();
  iVar2 = FUN_00572b10(uVar1);
  if (iVar2 == 0) {
    FUN_005168b0(0x1451,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                 *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
  }
  else {
    *(undefined4 *)(in_ECX + 0x200) = 0;
    FUN_00685940();
    iVar2 = FUN_00687ac0();
    if (iVar2 == 0) {
      *(undefined4 *)(in_ECX + 0x1f8) = 2;
      FUN_00685940();
    }
    else if (iVar2 < 1) {
      if (*(int *)(in_ECX + 0xb94) == 0) {
        FUN_00687270();
      }
      else {
        FUN_00687210();
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x200) = 1;
      FUN_00685940();
    }
  }
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiJwmKeisan[25] */
/* 00686fb0  FUN_00686fb0  87 bytes, 0 callers */

void FUN_00686fb0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (*(int *)(in_ECX + 0x1f8) == 2) {
      if (*(int *)(in_ECX + 0xb94) == 0) {
        FUN_00687270();
      }
      else {
        FUN_00687210();
      }
    }
    else {
      FUN_006869b0(1);
    }
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[26] */
/* 00687010  FUN_00687010  175 bytes, 0 callers */

void FUN_00687010(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (*(int *)(in_ECX + 0x1f8) == 2) {
      FUN_006878b0();
      if (*(int *)(in_ECX + 0xd34) < 1) {
        iVar1 = FUN_00687ac0();
        if (iVar1 == 0) {
          *(undefined4 *)(in_ECX + 0x1f8) = 2;
          FUN_00685940();
        }
        else if (*(int *)(in_ECX + 0xb94) == 0) {
          FUN_00687270();
        }
        else {
          FUN_00687210();
        }
      }
      else {
        *(undefined4 *)(in_ECX + 0x200) = 1;
        FUN_00685940();
      }
    }
    else {
      FUN_006869b0(2);
    }
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[27] */
/* 006870c0  FUN_006870c0  43 bytes, 0 callers */

void FUN_006870c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    FUN_006869b0(3);
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[28] */
/* 006870f0  FUN_006870f0  43 bytes, 0 callers */

void FUN_006870f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    FUN_006869b0(4);
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[29] */
/* 00687120  FUN_00687120  43 bytes, 0 callers */

void FUN_00687120(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    FUN_006869b0(5);
  }
  else {
    FUN_006fb760();
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[30] */
/* 00687150  FUN_00687150  43 bytes, 0 callers */

void FUN_00687150(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    FUN_006869b0(6);
  }
  else {
    FUN_006fbbb0();
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[31] */
/* 00687180  FUN_00687180  43 bytes, 0 callers */

void FUN_00687180(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    FUN_006869b0(7);
  }
  else {
    FUN_006fbbf0();
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[32] */
/* 006871b0  FUN_006871b0  43 bytes, 0 callers */

void FUN_006871b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    FUN_006869b0(8);
  }
  else {
    FUN_006fbc40();
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[33] */
/* 006871e0  FUN_006871e0  43 bytes, 0 callers */

void FUN_006871e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    FUN_006869b0(9);
  }
  else {
    FUN_006fbf90();
  }
  return;
}




/* vtable slots: CZukeiJwmKeisan[9] */
/* 006872f0  FUN_006872f0  156 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006872f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (*(int *)(in_ECX + 0x1f8) == 2) {
      FUN_004988c0(local_18,param_2,param_3,param_4,param_5);
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiJwmKeisan[11] */
/* 00687390  FUN_00687390  355 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00687390(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
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
  if (in_ECX[0x80] == 0) {
    if (in_ECX[0x7e] == 2) {
      FUN_00446aa0(local_14);
      local_8 = 0;
      local_24 = param_2;
      local_20 = param_3;
      local_1c = param_4;
      local_18 = param_5;
      iVar2 = FUN_00451eb0(in_ECX[1],&local_24,1);
      if (iVar2 == 0) {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else {
        uVar1 = (**(code **)(*in_ECX + 0x24))(param_1,local_24,local_20,local_1c,local_18);
        local_8 = 0xffffffff;
        FUN_00447100();
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_006fda70(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiJwmKeisan[4] */
/* 00687500  FUN_00687500  62 bytes, 0 callers */

void FUN_00687500(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x9dc) != 0) {
    _fclose(*(FILE **)(in_ECX + 0x9dc));
    *(undefined4 *)(in_ECX + 0x9dc) = 0;
  }
  FUN_006878b0();
  return;
}




/* vtable slots: CZukeiJwmKeisan[3] */
/* 00687540  FUN_00687540  311 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00687540(void)

{
  int in_ECX;
  int iStack_6418;
  undefined1 *puStack_6414;
  int iStack_6410;
  uint uStack_640c;
  undefined1 local_6408 [20];
  undefined1 *local_63f4;
  undefined4 local_63f0;
  undefined1 *local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093ac96;
  local_10 = ExceptionList;
  uStack_640c = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iStack_6410 = *(undefined4 *)(in_ECX + 4);
  puStack_6414 = (undefined1 *)0x68758a;
  local_63e8 = in_ECX;
  local_14 = uStack_640c;
  FUN_0079dea2();
  local_8 = 0;
  iStack_6410 = 0x68759c;
  FUN_00446aa0();
  local_8._0_1_ = 1;
  iStack_6410 = *(undefined4 *)(local_63e8 + 4);
  puStack_6414 = local_6408;
  iStack_6418 = 0x6875bc;
  FUN_0044dd90();
  iStack_6410 = local_63e8 + 0xd48;
  local_63ec = (undefined1 *)&puStack_6414;
  iStack_6418 = local_63e8 + 0xd40;
  local_63f0 = FUN_00403dd0();
  local_8._0_1_ = 2;
  local_63f4 = (undefined1 *)&iStack_6418;
  FUN_00403dd0(local_63e8 + 0xd3c);
  local_8._0_1_ = 1;
  FUN_0068c340();
  *(int *)(local_63e8 + 0xd64) = *(int *)(local_63e8 + 0xd64) + 1;
  iStack_6410 = 0x68763d;
  FUN_006878b0();
  local_8 = (uint)local_8._1_3_ << 8;
  iStack_6410 = 0x68764c;
  FUN_00447100();
  local_8 = 0xffffffff;
  iStack_6410 = 0x68765e;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiJwmKeisan[14], CZukeiKeisan[14], CZukeiSokutei[14] */
/* 00687a60  FUN_00687a60  86 bytes, 0 callers */

undefined4 FUN_00687a60(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
    FUN_00404c80(param_1);
    FUN_004fca20();
    uVar2 = FUN_0041b190(param_1);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



