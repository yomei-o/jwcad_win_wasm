/* CZukeiShoukyo -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiShoukyo[1] */
/* 0070c820  FUN_0070c820  68 bytes, 0 callers */

undefined4 FUN_0070c820(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0070c780();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x268);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiShoukyo[6] */
/* 0070cbd0  FUN_0070cbd0  223 bytes, 0 callers */

void FUN_0070cbd0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    FUN_00404c80();
    FUN_004fca20();
    fVar2 = (float10)FUN_004cacd0();
    FUN_00404c80((double)fVar2);
    FUN_004fca20();
    uVar1 = FUN_00710790();
    *(undefined4 *)(in_ECX + 0x25c) = uVar1;
    if (*(int *)(in_ECX + 0x210) == 0) {
      if (*(int *)(in_ECX + 0x21c) == 0) {
        FUN_0070dc20(1);
      }
    }
    else {
      if (*(int *)(*(int *)(in_ECX + 0x20c) + 0x1c) == 0) {
        uVar1 = 0x15;
        FUN_00404c80(0x15);
        FUN_004fca20();
        FUN_004c9cb0(uVar1);
      }
      else {
        uVar1 = 0x16;
        FUN_00404c80(0x16);
        FUN_004fca20();
        FUN_004c9cb0(uVar1);
      }
      FUN_00562600(param_1);
    }
  }
  else {
    FUN_006f7cc0(param_1);
  }
  return;
}




/* vtable slots: CZukeiShoukyo[16] */
/* 0070ccb0  FUN_0070ccb0  312 bytes, 0 callers */

undefined4 FUN_0070ccb0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_004fb9f0();
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (*(int *)(in_ECX + 0x210) == 0) {
      if (*(int *)(in_ECX + 0x21c) == 0) {
        uVar2 = 0;
      }
      else {
        if (*(int *)(in_ECX + 0x21c) == 1) {
          *(undefined4 *)(in_ECX + 0x21c) = 0;
          *(undefined4 *)(in_ECX + 0x218) = 0;
        }
        if (*(int *)(in_ECX + 0x21c) == 2) {
          *(undefined4 *)(in_ECX + 0x21c) = 1;
        }
        FUN_0070dc20(1);
        uVar2 = 1;
      }
    }
    else {
      iVar1 = FUN_00562880();
      if (iVar1 != 0) {
        uVar2 = 0x14;
        FUN_00404c80(0x14);
        FUN_004fca20();
        FUN_004c9cb0(uVar2);
        *(undefined4 *)(in_ECX + 0x210) = 0;
      }
      uVar2 = 1;
    }
  }
  else {
    iVar1 = FUN_006f85c0();
    if (iVar1 == 0) {
      if (*(int *)(in_ECX + 0x204) < 1) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
        *(undefined4 *)(in_ECX + 0x200) = 0;
        FUN_0070c870();
        uVar2 = 1;
      }
      else {
        *(int *)(in_ECX + 0x204) = *(int *)(in_ECX + 0x204) + -1;
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 1;
    }
  }
  return uVar2;
}




/* vtable slots: CZukeiShoukyo[0] */
/* 0070cdf0  FUN_0070cdf0  16 bytes, 0 callers */

undefined ** FUN_0070cdf0(void)

{
  return &PTR_s_CZukeiShoukyo_0097a948;
}




/* vtable slots: CZukeiShoukyo[23] */
/* 0070e130  FUN_0070e130  91 bytes, 0 callers */

undefined4 FUN_0070e130(void)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if (in_ECX[0x80] == 0) {
    if (in_ECX[0x84] == 0) {
      if (DAT_00a0cc6c == 0) {
        (**(code **)(*in_ECX + 100))();
      }
      else {
        (**(code **)(*in_ECX + 0x74))();
      }
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_006f8be0();
  }
  return uVar1;
}




/* vtable slots: CZukeiShoukyo[46] */
/* 0070e190  FUN_0070e190  607 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0070e190(undefined4 param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (DAT_00a0c7c0 == 0) {
    if (in_ECX[0x80] == 0) {
      if ((*(int *)(in_ECX[1] + 0x9078) == 0) && (param_2 == 4)) {
        if (param_3 == 1) {
          FUN_005168b0(0x141c,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 0x6c))();
          FUN_004988c0(local_18,param_4,param_5,param_6,param_7);
          FUN_0040c9d0();
          *(undefined4 *)(in_ECX[2] + 4) = 1;
        }
        uVar1 = 0;
      }
      else if ((*(int *)(in_ECX[1] + 0x9078) == 0) &&
              (((in_ECX[0x84] != 0 && (param_2 == 0xc)) && (*(int *)(in_ECX[0x83] + 0x1c) != 0)))) {
        if (param_3 == 1) {
          FUN_005168b0(0x18b1,*(undefined4 *)(in_ECX[1] + 0x8f50),
                       *(undefined4 *)(in_ECX[1] + 0x8f54),1,0);
        }
        else if (param_3 == 2) {
          (**(code **)(*in_ECX + 0x68))();
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




/* vtable slots: CZukeiShoukyo[34] */
/* 0070e400  FUN_0070e400  379 bytes, 0 callers */

void FUN_0070e400(void)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX[0x80] != 0) {
    in_ECX[0x86] = 0;
    (**(code **)(*in_ECX + 0xc))();
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) != *(int *)(in_ECX[1] + 0x8610)) {
      return;
    }
    in_ECX[0x81] = in_ECX[0x81] + 1;
    in_ECX[3] = 0;
    in_ECX[0x2d] = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x1e8) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x1ec) = 0;
    FUN_00404c80(0);
    FUN_004fca20();
    FUN_007955d2();
    if (in_ECX[0x80] == 1) {
      *(undefined4 *)(in_ECX[1] + 0x8578) = 1;
      in_ECX[0x80] = 0;
      DAT_00a0d618 = 1;
      FUN_0070c870();
    }
    if ((in_ECX[0x7f] == 0) && (*(int *)(in_ECX[1] + 0x8588) != 0)) {
      *(undefined4 *)(in_ECX[1] + 0x8588) = 0xffffd9bb;
      *(undefined4 *)(in_ECX[1] + 0x906c) = 0;
      FUN_00404c80();
      FUN_0056d200();
      return;
    }
    if (in_ECX[0x80] != 0) {
      FUN_0070c870();
    }
  }
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiShoukyo[25] */
/* 0070e580  FUN_0070e580  283 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0070e580(void)

{
  int in_ECX;
  undefined4 uVar1;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092039b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x200) == 0) {
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
    *(undefined4 *)(local_63e8 + 0x210) = 1;
    uVar1 = 0x15;
    FUN_00404c80(0x15);
    FUN_004fca20();
    FUN_004c9cb0(uVar1);
    FUN_005634f0();
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_004066b0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiShoukyo[26] */
/* 0070e6a0  FUN_0070e6a0  183 bytes, 1 callers */

void FUN_0070e6a0(void)

{
  int in_ECX;
  undefined4 uVar1;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    uVar1 = 0x14;
    FUN_00404c80(0x14);
    FUN_004fca20();
    FUN_004c9cb0(uVar1);
    if ((*(int *)(in_ECX + 0x210) != 0) &&
       (FUN_0070ce00(), *(int *)(*(int *)(in_ECX + 4) + 0x8588) != 0)) {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8588) = 0xffffd9bb;
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x906c) = 0;
      FUN_00404c80();
      FUN_0056d200();
      return;
    }
    *(undefined4 *)(in_ECX + 0x210) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8578) = 1;
    FUN_00404c80();
    FUN_0056d200();
  }
  else {
    FUN_004066b0();
  }
  return;
}




/* vtable slots: CZukeiShoukyo[27] */
/* 0070e760  FUN_0070e760  388 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0070e760(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092039b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x200) == 0) {
    *(undefined4 *)(in_ECX + 0x21c) = 0;
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
    *(undefined4 *)(local_63e8 + 0x200) = 1;
    *(undefined4 *)(local_63e8 + 0x208) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x862c)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x178) != 0) {
        *(undefined4 *)(local_63e8 + 0x208) = 1;
      }
    }
    DAT_00a0d618 = 1;
    *(undefined4 *)(local_63e8 + 0x204) = 0;
    FUN_0070c870();
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_004066b0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiShoukyo[28] */
/* 0070e8f0  FUN_0070e8f0  410 bytes, 2 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0070e8f0(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_63fc [20];
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092039b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x200) == 0) {
    *(undefined4 *)(in_ECX + 0x21c) = 0;
    local_63e8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
    *(undefined4 *)(local_63e8 + 0x200) = 2;
    *(undefined4 *)(local_63e8 + 0x208) = 0;
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x862c)) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0x178) != 0) {
        *(undefined4 *)(local_63e8 + 0x208) = 1;
      }
    }
    DAT_00a0d618 = 1;
    *(undefined4 *)(local_63e8 + 0x204) = 0;
    *(undefined4 *)(*(int *)(local_63e8 + 0x1f8) + 0xc4) = 1;
    FUN_0070c870();
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = local_8 & 0xffffff00;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else {
    FUN_004066b0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiShoukyo[29] */
/* 0070ea90  FUN_0070ea90  169 bytes, 1 callers */

void FUN_0070ea90(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    DAT_00a0cc3c = (uint)(DAT_00a0cc3c == 0);
    FUN_004fb9f0();
    if (DAT_00a0cc3c == 0) {
      FUN_005168b0(0x15fa,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
    }
    else {
      FUN_005168b0(0x15f9,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f28),0,0);
    }
  }
  else {
    FUN_006fb760();
  }
  return;
}




/* vtable slots: CZukeiShoukyo[36] */
/* 0070eb40  FUN_0070eb40  250 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0070eb40(void)

{
  int iVar1;
  int *in_ECX;
  int local_63f0;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009309a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX[0x80] != 0) {
    FUN_00446aa0(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    local_8 = 0;
    if (in_ECX[1] == 0) {
      local_63f0 = 0;
    }
    else {
      local_63f0 = in_ECX[1] + 0x88;
    }
    iVar1 = FUN_0044fcd0(local_63f0);
    if (iVar1 == 0) {
      (**(code **)(*in_ECX + 0x88))();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiShoukyo[15] */
/* 0070ec40  FUN_0070ec40  282 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0070ec40(void)

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
  puStack_c = &LAB_0093365b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (*(int *)(in_ECX + 0x210) == 0) {
      local_63e8 = in_ECX;
      FUN_0070dc20(0);
      FUN_00446aa0();
      local_8 = 0;
      FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
      local_8._0_1_ = 1;
      FUN_00453bd0(local_6400,*(undefined4 *)(local_63e8 + 4),0);
      FUN_0070dc20(1);
      local_63ec = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_63ec = 1;
    }
  }
  else {
    local_63ec = FUN_0042ddf0(local_14);
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiShoukyo[12] */
/* 0070ed60  FUN_0070ed60  428 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0070ed60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_28 [16];
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (*(int *)(in_ECX + 0x210) == 0) {
      if ((*(int *)(in_ECX + 0x218) == 1) && (*(int *)(in_ECX + 0x21c) == 1)) {
        if ((0 < *(int *)(*(int *)(in_ECX + 0x250) + 4)) &&
           (iVar2 = FUN_00712760(&param_2), iVar2 == 0)) {
          return 0;
        }
        FUN_004988c0(local_18,param_2,param_3,param_4,param_5);
        *(undefined4 *)(in_ECX + 0x21c) = 2;
        FUN_0070dc20(1);
        uVar1 = 0;
      }
      else if ((*(int *)(in_ECX + 0x218) == 1) && (*(int *)(in_ECX + 0x21c) == 2)) {
        if ((0 < *(int *)(*(int *)(in_ECX + 0x250) + 4)) &&
           (iVar2 = FUN_00712760(&param_2), iVar2 == 0)) {
          return 0;
        }
        FUN_004988c0(local_28,*(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234),
                     *(undefined4 *)(in_ECX + 0x238),*(undefined4 *)(in_ECX + 0x23c));
        *(undefined4 *)(in_ECX + 0x21c) = 3;
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = FUN_005635b0(param_1,param_2,param_3,param_4,param_5);
    }
  }
  else {
    uVar1 = FUN_006fcae0(param_1,param_2,param_3,param_4,param_5);
  }
  return uVar1;
}




/* vtable slots: CZukeiShoukyo[10] */
/* 0070ef10  FUN_0070ef10  679 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0070ef10(void)

{
  int iVar1;
  int *in_ECX;
  int local_6400;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00938150;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  if (in_ECX[1] == 0) {
    local_6400 = 0;
  }
  else {
    local_6400 = in_ECX[1] + 0x88;
  }
  iVar1 = FUN_0044fcd0(local_6400);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    if (*(int *)(in_ECX[1] + 0x8588) != 0) {
      *(undefined4 *)(in_ECX[1] + 0x8588) = 0xffffd9bb;
      *(undefined4 *)(in_ECX[1] + 0x906c) = 0;
      FUN_00404c80();
      FUN_0056d200();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
  }
  else if (*(int *)(in_ECX[1] + 0x9068) == 0) {
    if (*(int *)(in_ECX[1] + 0x906c) != 0) {
      in_ECX[0x86] = 0;
      in_ECX[0x87] = 0;
      iVar1 = in_ECX[1];
      (**(code **)(*in_ECX + 0x2c))
                (0,*(undefined4 *)(iVar1 + 0x8f68),*(undefined4 *)(iVar1 + 0x8f6c),
                 *(undefined4 *)(iVar1 + 0x8f70),*(undefined4 *)(iVar1 + 0x8f74));
      if (*(int *)(in_ECX[1] + 0x8588) != 0) {
        *(undefined4 *)(in_ECX[1] + 0x8588) = 0xffffd9bb;
        *(undefined4 *)(in_ECX[1] + 0x906c) = 0;
        FUN_00404c80();
        FUN_0056d200();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
    }
  }
  else {
    iVar1 = in_ECX[1];
    FUN_004988c0(local_24,*(undefined4 *)(iVar1 + 0x8f68),*(undefined4 *)(iVar1 + 0x8f6c),
                 *(undefined4 *)(iVar1 + 0x8f70),*(undefined4 *)(iVar1 + 0x8f74));
    in_ECX[0x87] = 1;
  }
  *(undefined4 *)(in_ECX[1] + 0x85b0) = 0;
  *(undefined4 *)(in_ECX[1] + 0x85b4) = 0;
  FUN_0070dc20(1);
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiShoukyo[9] */
/* 0070f1c0  FUN_0070f1c0  1153 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0070f1c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_44 [16];
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093fddb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x260) = 0;
  *(undefined4 *)(in_ECX + 0x214) = 0;
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (*(int *)(in_ECX + 0x210) == 0) {
      FUN_00446aa0(local_14);
      local_8 = 0;
      FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
      local_8._0_1_ = 1;
      if (*(int *)(in_ECX + 0x21c) == 0) {
        if (*(int *)(in_ECX + 0x25c) != 0) {
          *(undefined4 *)(in_ECX + 0x260) = 1;
        }
        FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
        if (*(int *)(in_ECX + 0x260) == 0) {
          *(undefined4 *)(in_ECX + 0x21c) = 1;
          FUN_0070dc20(1);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 1;
        }
      }
      else if (*(int *)(in_ECX + 0x21c) == 1) {
        if ((*(int *)(*(int *)(in_ECX + 0x250) + 4) < 1) ||
           (iVar2 = FUN_00712760(&param_2), iVar2 != 0)) {
          FUN_004988c0(local_34,param_2,param_3,param_4,param_5);
          *(undefined4 *)(in_ECX + 0x21c) = 2;
          FUN_0070dc20(1);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
      }
      else if (*(int *)(in_ECX + 0x21c) == 2) {
        if (*(int *)(*(int *)(in_ECX + 0x250) + 4) < 1) {
          iVar2 = FUN_0045b6c0(0,*(undefined4 *)(in_ECX + 0x250),&param_2);
          if (iVar2 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
        }
        else {
          iVar2 = FUN_00712760(&param_2);
          if (iVar2 == 0) {
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_0079dfff();
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
        }
        FUN_004988c0(local_44,param_2,param_3,param_4,param_5);
        *(undefined4 *)(in_ECX + 0x21c) = 3;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 1;
      }
      else {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
    else {
      FUN_005637b0(param_1,param_2,param_3,param_4,param_5);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiShoukyo[13] */
/* 0070f650  FUN_0070f650  560 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0070f650(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009309e0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (*(int *)(in_ECX + 0x210) == 0) {
      FUN_00446aa0(local_14);
      local_8 = 0;
      if ((*(int *)(in_ECX + 0x218) == 1) && (*(int *)(in_ECX + 0x21c) == 2)) {
        iVar2 = FUN_00451eb0(*(undefined4 *)(in_ECX + 4),&param_2,1);
        if (iVar2 == 0) {
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 0;
        }
        else {
          if ((0 < *(int *)(*(int *)(in_ECX + 0x250) + 4)) &&
             (iVar2 = FUN_00712760(&param_2), iVar2 == 0)) {
            local_8 = 0xffffffff;
            FUN_00447100();
            ExceptionList = local_10;
            return 0;
          }
          FUN_004988c0(local_24,*(undefined4 *)(in_ECX + 0x230),*(undefined4 *)(in_ECX + 0x234),
                       *(undefined4 *)(in_ECX + 0x238),*(undefined4 *)(in_ECX + 0x23c));
          *(undefined4 *)(in_ECX + 0x21c) = 3;
          local_8 = 0xffffffff;
          FUN_00447100();
          uVar1 = 1;
        }
      }
      else {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
    else {
      uVar1 = FUN_0042b7c0(param_1,param_2,param_3,param_4,param_5);
    }
  }
  else {
    uVar1 = FUN_006fda50(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiShoukyo[11] */
/* 0070f880  FUN_0070f880  947 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0070f880(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined1 local_6414 [20];
  int local_6400;
  int local_63fc;
  int local_63f8;
  int local_63f4;
  int local_63f0;
  int local_63ec;
  int *local_63e8;
  undefined1 local_63e4 [25372];
  undefined4 local_c8;
  undefined4 local_bc;
  undefined4 local_b8;
  undefined4 local_ac;
  undefined4 local_a4;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093774b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  in_ECX[0x98] = 0;
  in_ECX[0x85] = 0;
  if (in_ECX[0x80] == 0) {
    local_63e8 = in_ECX;
    if (in_ECX[0x84] == 0) {
      FUN_00446aa0(local_14);
      local_8 = 0;
      FUN_0079dea2(local_63e8[1]);
      local_8._0_1_ = 1;
      local_63ec = 0;
      if (local_63e8[0x86] == 0) {
        FUN_0070dc20(0);
        if (DAT_00a0cc3c != 0) {
          *(undefined4 *)(local_63e8[1] + 0x8f34) = 1;
          iVar1 = FUN_004500e0(1,local_63e8[1],&param_2,&local_63f8,0);
          if (iVar1 != 0) {
            local_63ec = local_63f8;
          }
          *(undefined4 *)(local_63e8[1] + 0x8f34) = 0;
        }
        if (local_63ec == 0) {
          local_c8 = 1;
          local_bc = 1;
          local_b8 = 1;
          local_ac = 1;
          local_a4 = 1;
          iVar1 = FUN_0044a270(0,local_63e8[1],&param_2,&local_63fc,0);
          if (iVar1 != 0) {
            local_63ec = local_63fc;
          }
        }
        if (local_63ec != 0) {
          FUN_0070cad0(local_63e4,local_6414,local_63ec);
          local_63e8[0x85] = 1;
        }
        local_63e8[0x87] = 0;
        FUN_0070dc20(1);
        *(undefined4 *)(local_63e8[1] + 0x8560) = 0;
        local_6400 = local_63e8[0x85];
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_63f0 = local_6400;
      }
      else {
        iVar1 = FUN_00451eb0(local_63e8[1],&param_2,1);
        if (iVar1 == 0) {
          local_63f0 = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
        }
        else {
          local_63f4 = (**(code **)(*local_63e8 + 0x24))(param_1,param_2,param_3,param_4,param_5);
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_63f0 = local_63f4;
        }
      }
    }
    else {
      iVar1 = FUN_00564350(param_1,param_2,param_3,param_4,param_5);
      if (iVar1 != 0) {
        uVar2 = 0x14;
        FUN_00404c80(0x14);
        FUN_004fca20();
        FUN_004c9cb0(uVar2);
        FUN_0070ce00();
        local_63e8[0x84] = 0;
      }
      local_63f0 = 0;
    }
  }
  else {
    local_63f0 = FUN_006fda70(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return local_63f0;
}




/* vtable slots: CZukeiShoukyo[3] */
/* 0070fc60  FUN_0070fc60  2138 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0070fc60(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_6460 [20];
  undefined4 local_644c;
  undefined4 local_6448;
  undefined4 local_6444;
  int local_6440;
  int *local_643c;
  int local_6438;
  int local_6434;
  int *local_6430;
  int local_642c;
  int *local_6428;
  int *local_6424;
  int local_6420;
  undefined4 local_641c;
  int local_6418;
  uint local_6414;
  CWaitCursor local_640d;
  int *local_640c;
  int local_6408;
  undefined1 local_6404 [25336];
  undefined4 local_10c;
  undefined8 local_84;
  undefined8 local_7c;
  undefined8 local_74;
  undefined8 local_6c;
  undefined1 local_34 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093fe4e;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x214) != 0) {
    *(undefined4 *)(in_ECX + 0x214) = 0;
    return;
  }
  ExceptionList = &local_10;
  local_6408 = in_ECX;
  local_14 = uVar1;
  FUN_004fb910(0);
  CWaitCursor::CWaitCursor(&local_640d);
  local_8 = 0;
  FUN_004fb9f0(uVar1);
  FUN_005168b0(0x1456,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
               *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
  local_640c = (int *)0x0;
  local_641c = FUN_0040c0e0();
  local_6414 = FUN_0047c770();
  if (5000 < (int)local_6414) {
    local_642c = FUN_004121b0(0x128);
    local_8._0_1_ = 1;
    if (local_642c == 0) {
      local_6430 = (int *)0x0;
    }
    else {
      local_6430 = (int *)FUN_004aa560(0);
    }
    local_643c = local_6430;
    local_8 = (uint)local_8._1_3_ << 8;
    local_640c = local_6430;
    FUN_00404c80();
    uVar2 = FUN_0046ba20();
    (**(code **)(*local_640c + 0x164))(0x15d,uVar2);
    FUN_00797f20(5);
    FUN_004701c0(0,(int)local_6414 >> 8);
  }
  FUN_00446aa0();
  local_8._0_1_ = 2;
  FUN_00464040();
  local_8._0_1_ = 3;
  FUN_0079dea2(*(undefined4 *)(local_6408 + 4));
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_0044de00(local_6460,*(undefined4 *)(local_6408 + 4));
  local_10c = 0;
  local_6438 = 0;
  local_6434 = 0;
  if (*(int *)(local_6408 + 0x260) == 0) {
    if (*(int *)(local_6408 + 0x218) == 0) {
      if (*(int *)(local_6408 + 0x208) != 0) {
        FUN_0044c990(*(undefined4 *)(local_6408 + 4),local_6460);
        local_6420 = FUN_00572b10();
        while (local_6418 = FUN_00572b30(&local_6420,0), local_6418 != 0) {
          FUN_0040e410(0);
          FUN_0040e450(0);
          FUN_0040db70(0);
        }
      }
      local_6448 = DAT_00a0cae8;
      DAT_00a0cae8 = 0x32;
      if ((*(int *)(*(int *)(local_6408 + 4) + 0x9050) != 0) ||
         (*(int *)(*(int *)(local_6408 + 4) + 0x9054) != 0)) {
        DAT_00a0cae8 = 0;
      }
      local_10c = 0;
      local_7c = 0x487087c797fde41d;
      local_84 = 0x487087c797fde41d;
      local_6c = 0xc87087c797fde41d;
      local_74 = 0xc87087c797fde41d;
      FUN_00478480(0xffffffff,*(undefined4 *)(local_6408 + 4),local_6404,local_6460,1);
      FUN_00574f10();
      if (DAT_00a0cae8 != 0) {
        FUN_0044f4f0(local_6460,*(undefined4 *)(local_6408 + 4));
      }
      DAT_00a0cae8 = local_6448;
    }
    else {
      FUN_0044c990(*(undefined4 *)(local_6408 + 4),local_6460);
      if (*(int *)(*(int *)(local_6408 + 0x250) + 4) < 1) {
        local_6414 = 0;
        local_6420 = FUN_00572b10();
        while (local_6420 != 0) {
          local_6414 = local_6414 + 1;
          if ((local_640c != (int *)0x0) && ((local_6414 & 0xff) == 0)) {
            FUN_00470190((int)local_6414 >> 8);
          }
          local_6440 = local_6420;
          local_6418 = FUN_00572b30(&local_6420,0);
          if (local_6418 == 0) break;
          FUN_00574f40(local_6440);
          FUN_00470200(*(undefined4 *)(local_6408 + 4),local_6418,
                       *(undefined4 *)(local_6408 + 0x230),*(undefined4 *)(local_6408 + 0x234),
                       *(undefined4 *)(local_6408 + 0x238),*(undefined4 *)(local_6408 + 0x23c),
                       *(undefined4 *)(local_6408 + 0x240),*(undefined4 *)(local_6408 + 0x244),
                       *(undefined4 *)(local_6408 + 0x248),*(undefined4 *)(local_6408 + 0x24c));
          local_10c = 1;
        }
      }
      else {
        FUN_00710920();
      }
      if (local_640c != (int *)0x0) {
        (**(code **)(*local_640c + 0x60))();
        local_6424 = local_640c;
        if (local_640c == (int *)0x0) {
          local_6444 = 0;
        }
        else {
          local_6444 = (**(code **)(*local_640c + 4))(1);
        }
        local_640c = (int *)0x0;
      }
      FUN_00449d60(local_6460,*(undefined4 *)(local_6408 + 4),1);
      iVar3 = FUN_00436970(*(undefined4 *)(local_6408 + 0x230),*(undefined4 *)(local_6408 + 0x234),
                           *(undefined4 *)(local_6408 + 0x238),*(undefined4 *)(local_6408 + 0x23c),
                           *(undefined4 *)(local_6408 + 0x240),*(undefined4 *)(local_6408 + 0x244),
                           *(undefined4 *)(local_6408 + 0x248),*(undefined4 *)(local_6408 + 0x24c));
      if (iVar3 != 0) {
        local_6438 = 1;
      }
    }
  }
  else {
    *(undefined4 *)(local_6408 + 0x218) = 0;
    *(undefined4 *)(local_6408 + 0x250) = 0;
    iVar3 = FUN_0044a270(3,*(undefined4 *)(local_6408 + 4),local_6408 + 0x220,local_6408 + 0x250,0);
    if (iVar3 == 0) {
      *(undefined4 *)(local_6408 + 0x21c) = 0;
      FUN_0070dc20(1);
      *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
      goto LAB_00710462;
    }
    puVar4 = (undefined4 *)
             CMFCCaptionButtonEx::GetRect(*(CMFCCaptionButtonEx **)(local_6408 + 0x250));
    FUN_004988c0(local_34,*puVar4,puVar4[1],puVar4[2],puVar4[3]);
    if (*(int *)(local_6408 + 0x250) != 0) {
      uVar1 = FUN_00712f00(local_6404,local_6460);
      if (0x7fffffff < uVar1) {
        local_6434 = 1;
      }
      *(undefined4 *)(local_6408 + 0x214) = 1;
    }
  }
  if (local_6434 == 0) {
    FUN_004fb9f0();
  }
  *(undefined4 *)(local_6408 + 0x218) = 0;
  *(undefined4 *)(local_6408 + 0x21c) = 0;
  FUN_0070dc20(1);
  *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
  if (local_640c != (int *)0x0) {
    (**(code **)(*local_640c + 0x60))();
    local_6428 = local_640c;
    if (local_640c == (int *)0x0) {
      local_644c = 0;
    }
    else {
      local_644c = (**(code **)(*local_640c + 4))(1);
    }
    local_640c = (int *)0x0;
  }
  if (local_6438 != 0) {
    FUN_005168b0(0x2737,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
                 *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
  }
LAB_00710462:
  local_8._0_1_ = 3;
  FUN_0079dfff();
  local_8._0_1_ = 2;
  FUN_004640a0();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_00408b00();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiShoukyo[14] */
/* 00712b70  FUN_00712b70  178 bytes, 0 callers */

undefined4 FUN_00712b70(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x200) == 0) {
    if (DAT_00a0b3b4 == 0) {
      if (*(int *)(in_ECX + 0x210) == 0) {
        if (param_1 == 1) {
          FUN_0070e580();
          uVar1 = 1;
        }
        else if (param_1 == 2) {
          FUN_0070ea90();
          uVar1 = 1;
        }
        else if (param_1 == 3) {
          FUN_0070e760();
          uVar1 = 1;
        }
        else if (param_1 == 4) {
          FUN_0070e8f0();
          uVar1 = 1;
        }
        else {
          uVar1 = 0;
        }
      }
      else if (param_1 == 2) {
        FUN_0070e6a0();
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = FUN_00420d00(param_1);
  }
  return uVar1;
}



