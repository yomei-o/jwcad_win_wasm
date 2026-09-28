/* CZukeiSeiri -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiSeiri[1] */
/* 006e5d40  FUN_006e5d40  68 bytes, 0 callers */

undefined4 FUN_006e5d40(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006e5ce0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x238);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiSeiri[6] */
/* 006e62c0  FUN_006e62c0  429 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006e62c0(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  int local_63f0;
  int local_63ec;
  int *local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937dcb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (in_ECX[0x7f] == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(local_63e8[1]);
    local_8 = CONCAT31(local_8._1_3_,1);
    local_63f4 = FUN_0040c0e0();
    local_63ec = local_63e8[1];
    if (local_63ec == 0) {
      local_63f0 = 0;
    }
    else {
      local_63f0 = local_63ec + 0x88;
    }
    iVar1 = FUN_0044fcd0(local_63f0);
    if (iVar1 == 0) {
      FUN_004efbb0(0x152c,0,0);
    }
    else {
      FUN_004efbb0(0x14ba,0,0);
    }
    if (*(int *)(local_63e8[1] + 0x8560) < 1) {
      *(undefined4 *)(local_63e8[1] + 0x8560) = 1;
    }
    FUN_0044dd90(local_6408,local_63e8[1]);
    if (0 < *(int *)(local_63e8[1] + 0x8560)) {
      (**(code **)(*local_63e8 + 0x20))();
    }
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_006f7cc0(param_1);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSeiri[16] */
/* 006e6470  FUN_006e6470  366 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_006e6470(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_640c [20];
  undefined4 local_63f8;
  undefined4 local_63f4;
  undefined4 local_63f0;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092999b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044dd90(local_640c,*(undefined4 *)(local_63e8 + 4));
    local_63f0 = FUN_0040c0e0();
    iVar1 = FUN_00572b10();
    if (iVar1 == 0) {
      local_63f8 = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_63f4 = local_63f8;
    }
    else {
      FUN_0044c830(local_640c,*(undefined4 *)(local_63e8 + 4));
      FUN_006e5d90();
      local_63f4 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    local_63f4 = FUN_006f85c0();
  }
  ExceptionList = local_10;
  return local_63f4;
}




/* vtable slots: CZukeiSeiri[0] */
/* 006e65e0  FUN_006e65e0  16 bytes, 0 callers */

undefined ** FUN_006e65e0(void)

{
  return &PTR_s_CZukeiSeiri_0097a2e8;
}




/* vtable slots: CZukeiSeiri[46] */
/* 006e65f0  FUN_006e65f0  485 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_006e65f0(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (DAT_00a0c7c0 == 0) {
    if (in_ECX[0x7f] == 0) {
      if ((*(int *)(in_ECX[1] + 0x9078) == 0) && (param_2 == 4)) {
        if (param_3 == 1) {
          FUN_005168b0(0x141c,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 0x74))();
          FUN_004988c0(local_18,param_4,param_5,param_6,param_7);
          FUN_0040c9d0();
          *(undefined4 *)(in_ECX[2] + 4) = 1;
        }
        uVar1 = 0;
      }
      else {
        uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
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




/* vtable slots: CZukeiSeiri[34] */
/* 006e67e0  FUN_006e67e0  231 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006e67e0(void)

{
  int iVar1;
  int in_ECX;
  int local_63ec;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009309a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  if (*(int *)(in_ECX + 4) == 0) {
    local_63ec = 0;
  }
  else {
    local_63ec = *(int *)(in_ECX + 4) + 0x88;
  }
  iVar1 = FUN_0044fcd0(local_63ec);
  if (iVar1 == 0) {
    DAT_00a0d618 = 0;
    FUN_006e5d90();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSeiri[25] */
/* 006e68d0  FUN_006e68d0  231 bytes, 0 callers */

void FUN_006e68d0(void)

{
  int in_ECX;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  wchar_t *pwStack_2c;
  int iStack_28;
  uint uStack_24;
  undefined1 *local_20;
  int local_1c;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926fad;
  local_10 = ExceptionList;
  uStack_24 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    *(undefined4 *)(in_ECX + 0x1f8) = 0;
    iStack_28 = 0x6e6926;
    local_14 = in_ECX;
    local_1c = FUN_006e78c0();
    iStack_28 = 0x6e6931;
    FUN_006e5d90();
    iStack_28 = 0x6e6939;
    CStringT<>();
    local_8 = 0;
    iStack_28 = -local_1c;
    pwStack_2c = L" %ld ";
    puStack_30 = local_18;
    uStack_34 = 0x6e6954;
    FUN_004059f0();
    iStack_28 = 0;
    pwStack_2c = (wchar_t *)0x0;
    puStack_30 = *(undefined1 **)(*(int *)(local_14 + 4) + 0x8f28);
    uStack_38 = *(undefined4 *)(*(int *)(local_14 + 4) + 0x8f24);
    local_20 = (undefined1 *)&uStack_38;
    uStack_34 = uStack_38;
    FUN_00403dd0(local_18);
    FUN_00516ac0();
    *(undefined4 *)(*(int *)(local_14 + 4) + 0x8578) = 1;
    local_8 = 0xffffffff;
    iStack_28 = 0x6e69a8;
    FUN_00404540();
  }
  else {
    iStack_28 = 0x6e690c;
    FUN_004066b0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSeiri[26] */
/* 006e69c0  FUN_006e69c0  231 bytes, 0 callers */

void FUN_006e69c0(void)

{
  int in_ECX;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 *puStack_30;
  wchar_t *pwStack_2c;
  int iStack_28;
  uint uStack_24;
  undefined1 *local_20;
  int local_1c;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00926fad;
  local_10 = ExceptionList;
  uStack_24 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    *(undefined4 *)(in_ECX + 0x1f8) = 1;
    iStack_28 = 0x6e6a16;
    local_14 = in_ECX;
    local_1c = FUN_006e78c0();
    iStack_28 = 0x6e6a21;
    FUN_006e5d90();
    iStack_28 = 0x6e6a29;
    CStringT<>();
    local_8 = 0;
    iStack_28 = -local_1c;
    pwStack_2c = L" %ld ";
    puStack_30 = local_18;
    uStack_34 = 0x6e6a44;
    FUN_004059f0();
    iStack_28 = 0;
    pwStack_2c = (wchar_t *)0x0;
    puStack_30 = *(undefined1 **)(*(int *)(local_14 + 4) + 0x8f28);
    uStack_38 = *(undefined4 *)(*(int *)(local_14 + 4) + 0x8f24);
    local_20 = (undefined1 *)&uStack_38;
    uStack_34 = uStack_38;
    FUN_00403dd0(local_18);
    FUN_00516ac0();
    *(undefined4 *)(*(int *)(local_14 + 4) + 0x8578) = 1;
    local_8 = 0xffffffff;
    iStack_28 = 0x6e6a98;
    FUN_00404540();
  }
  else {
    iStack_28 = 0x6e69fc;
    FUN_004066b0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSeiri[27] */
/* 006e6ab0  FUN_006e6ab0  167 bytes, 0 callers */

void FUN_006e6ab0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    *(undefined4 *)(in_ECX + 0x204) = DAT_00a0cc6c;
    *(undefined4 *)(in_ECX + 0x208) = DAT_00a0cc74;
    DAT_00a0cc74 = 0;
    DAT_00a0cc6c = 0;
    *(undefined4 *)(in_ECX + 0x200) = 0;
    if ((*(int *)(in_ECX + 0x204) == 0) && (*(int *)(in_ECX + 0x208) == 0)) {
      FUN_006ea5b0();
    }
    else {
      FUN_006eb600();
    }
    FUN_006e5d90();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiSeiri[28] */
/* 006e6b60  FUN_006e6b60  204 bytes, 0 callers */

void FUN_006e6b60(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    *(undefined4 *)(in_ECX + 0x204) = DAT_00a0cc6c;
    *(undefined4 *)(in_ECX + 0x208) = DAT_00a0cc74;
    DAT_00a0cc74 = 0;
    DAT_00a0cc6c = 0;
    *(undefined4 *)(in_ECX + 0x200) = 1;
    if ((*(int *)(in_ECX + 0x204) == 0) && (*(int *)(in_ECX + 0x208) == 0)) {
      FUN_006ea5b0();
    }
    else {
      if ((*(int *)(in_ECX + 0x204) != 0) && (*(int *)(in_ECX + 0x208) != 0)) {
        *(undefined4 *)(in_ECX + 0x208) = 0;
      }
      FUN_006eb600();
    }
    FUN_006e5d90();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiSeiri[29] */
/* 006e6c30  FUN_006e6c30  65 bytes, 0 callers */

void FUN_006e6c30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_006e7190();
    FUN_006e5d90();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
  }
  else {
    FUN_006fb760();
  }
  return;
}




/* vtable slots: CZukeiSeiri[30] */
/* 006e6c80  FUN_006e6c80  65 bytes, 0 callers */

void FUN_006e6c80(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    FUN_006e9df0();
    FUN_006e5d90();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
  }
  else {
    FUN_006fbbb0();
  }
  return;
}




/* vtable slots: CZukeiSeiri[33] */
/* 006e6cd0  FUN_006e6cd0  221 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006e6cd0(void)

{
  int in_ECX;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a53b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    local_63e8 = in_ECX;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
    FUN_006e5d90();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else {
    FUN_006fbf90(local_14);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiSeiri[36] */
/* 006e6db0  FUN_006e6db0  39 bytes, 0 callers */

void FUN_006e6db0(void)

{
  int *in_ECX;
  
  if (in_ECX[0x7f] != 0) {
    (**(code **)(*in_ECX + 0x88))();
  }
  return;
}




/* vtable slots: CZukeiSeiri[10] */
/* 006e6f20  FUN_006e6f20  45 bytes, 0 callers */

void FUN_006e6f20(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b0) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b4) = 0;
  return;
}




/* vtable slots: CZukeiSeiri[9] */
/* 006e6f50  FUN_006e6f50  88 bytes, 0 callers */

undefined4
FUN_006e6f50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiSeiri[11] */
/* 006e6fb0  FUN_006e6fb0  85 bytes, 0 callers */

undefined4
FUN_006e6fb0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_006fda70(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiSeiri[3] */
/* 006e7010  FUN_006e7010  252 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006e7010(void)

{
  int in_ECX;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920cbb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 0) {
    local_63e8 = in_ECX;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    local_63ec = FUN_0040c0e0();
    FUN_00446aa0();
    local_8._0_1_ = 1;
    FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else {
    FUN_006fe2f0(local_14);
  }
  ExceptionList = local_10;
  return;
}



