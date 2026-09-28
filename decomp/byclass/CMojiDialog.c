/* CMojiDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMojiDialog[1] */
/* 00580920  FUN_00580920  68 bytes, 0 callers */

undefined4 FUN_00580920(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00580690();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xee8);
    }
  }
  return in_ECX;
}




/* vtable slots: CMojiDialog[24] */
/* 00580c50  FUN_00580c50  231 bytes, 0 callers */

void FUN_00580c50(void)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_20 [4];
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925e7d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00a0b464 = (uint)(*(int *)(*(int *)(in_ECX + 0xbc) + 0x518) != 0);
  local_14 = in_ECX;
  local_1c = FUN_00581270(local_20);
  local_8 = 0;
  local_18 = local_1c;
  FUN_00404860(local_1c);
  local_8 = 0xffffffff;
  FUN_00404540(uVar1);
  (**(code **)(**(int **)(local_14 + 0xbc) + 0x60))();
  DAT_00a0b478 = *(int *)(local_14 + 0x278) * 3 + *(int *)(local_14 + 0x274);
  if ((DAT_00a0b478 < 0) || (8 < DAT_00a0b478)) {
    DAT_00a0b478 = 0;
  }
  FUN_00792313();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CMojiDialog[64] */
/* 00580d40  FUN_00580d40  1316 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00580d40(undefined *param_1)

{
  char cVar1;
  int iVar2;
  undefined *puStack_6428;
  uint uStack_6424;
  undefined4 local_6410;
  undefined1 *local_640c;
  undefined4 local_6408;
  undefined4 local_6404;
  undefined4 local_63fc;
  undefined4 local_63f8;
  undefined *local_63f4;
  undefined1 local_63f0 [4];
  undefined *local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e6c1;
  local_10 = ExceptionList;
  uStack_6424 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puStack_6428 = param_1;
  local_14 = uStack_6424;
  FUN_00405880();
  puStack_6428 = (undefined *)(local_63e8 + 0x280);
  FUN_0078fb9c(param_1,0x58a);
  puStack_6428 = (undefined *)(local_63e8 + 0x468);
  FUN_0078fb9c(param_1,0x428);
  puStack_6428 = (undefined *)(local_63e8 + 0x500);
  FUN_0078fb9c(param_1,0x733);
  puStack_6428 = (undefined *)(local_63e8 + 0x598);
  FUN_0078fb9c(param_1,0x967);
  puStack_6428 = (undefined *)(local_63e8 + 0x630);
  FUN_0078fb9c(param_1,0x583);
  puStack_6428 = (undefined *)(local_63e8 + 0x778);
  FUN_0078fb9c(param_1,0x6d1);
  puStack_6428 = (undefined *)(local_63e8 + 0x7f8);
  FUN_0078fb9c(param_1,0x6d2);
  puStack_6428 = (undefined *)(local_63e8 + 0x878);
  FUN_0078fb9c(param_1,0x52d);
  puStack_6428 = (undefined *)(local_63e8 + 0x8f8);
  FUN_0078fb9c(param_1,0x52c);
  puStack_6428 = (undefined *)(local_63e8 + 0x978);
  FUN_0078fb9c(param_1,0x52b);
  puStack_6428 = (undefined *)(local_63e8 + 0x9f8);
  FUN_0078f6f8(param_1,0x52b);
  puStack_6428 = (undefined *)(local_63e8 + 0x9fc);
  FUN_0078f6f8(param_1,0x52c);
  puStack_6428 = (undefined *)(local_63e8 + 0xa00);
  FUN_0078f6f8(param_1,0x52d);
  puStack_6428 = (undefined *)(local_63e8 + 0xa08);
  FUN_0078fb9c(param_1,0x429);
  puStack_6428 = (undefined *)(local_63e8 + 0xa88);
  FUN_0078fb9c(param_1,0x42b);
  puStack_6428 = (undefined *)(local_63e8 + 0xb20);
  FUN_0078fb9c(param_1,0x42c);
  puStack_6428 = (undefined *)(local_63e8 + 0xba0);
  FUN_0078fb9c(param_1,0x42d);
  puStack_6428 = (undefined *)(local_63e8 + 0xc20);
  FUN_0078fb9c(param_1,0x42e);
  puStack_6428 = (undefined *)(local_63e8 + 0xca0);
  FUN_0078fb9c(param_1,0x444);
  puStack_6428 = (undefined *)(local_63e8 + 0xd20);
  FUN_0078fb9c(param_1,0x9c7);
  puStack_6428 = (undefined *)(local_63e8 + 0xda0);
  FUN_0078fb9c(param_1,0x799);
  puStack_6428 = (undefined *)0x580fbf;
  FUN_00581550();
  puStack_6428 = (undefined *)0x580fca;
  FUN_00581470();
  puStack_6428 = (undefined *)0x580fd5;
  FUN_007b98e9();
  local_8 = 0;
  puStack_6428 = (undefined *)0x580fe7;
  iVar2 = FUN_007b9918();
  if (iVar2 != 0) {
    puStack_6428 = (undefined *)0x0;
    iVar2 = FUN_007b9bc6(1);
    if (iVar2 != 0) {
      local_63ec = (undefined *)0x1;
      goto LAB_00581014;
    }
  }
  local_63ec = (undefined *)0x0;
LAB_00581014:
  local_63f4 = local_63ec;
  puStack_6428 = local_63ec;
  FUN_007979e8();
  puStack_6428 = &DAT_00a0ba80;
  cVar1 = FUN_00447350(&DAT_00956338);
  if (cVar1 == '\0') {
    puStack_6428 = (undefined *)0x5810b0;
    FUN_00446aa0();
    local_8._0_1_ = 2;
    local_640c = (undefined1 *)&puStack_6428;
    FUN_00403dd0(&DAT_00a0ba80);
    local_6410 = FUN_0044f150(local_63f0);
    local_8._0_1_ = 3;
    puStack_6428 = (undefined *)0x5810ee;
    puStack_6428 = (undefined *)FUN_00404920();
    FUN_00797ece();
    local_8._0_1_ = 2;
    puStack_6428 = (undefined *)0x58110f;
    FUN_00404540();
    local_8 = (uint)local_8._1_3_ << 8;
    puStack_6428 = (undefined *)0x58111e;
    FUN_00447100();
  }
  else {
    puStack_6428 = (undefined *)0x1554;
    local_63fc = FUN_005977f0();
    local_8._0_1_ = 1;
    puStack_6428 = (undefined *)0x581082;
    local_63f8 = local_63fc;
    puStack_6428 = (undefined *)FUN_00404920();
    FUN_00797ece();
    local_8 = (uint)local_8._1_3_ << 8;
    puStack_6428 = (undefined *)0x5810a3;
    FUN_00404770();
  }
  puStack_6428 = (undefined *)0x581123;
  FUN_00404c80();
  puStack_6428 = (undefined *)0x58112a;
  local_6404 = FUN_00799e17();
  puStack_6428 = (undefined *)0x58113b;
  local_6408 = FUN_0040c0e0();
  puStack_6428 = (undefined *)0x58114c;
  iVar2 = FUN_00572b10();
  if (iVar2 == 0) {
    puStack_6428 = (undefined *)0x0;
    FUN_007979e8();
    if (*(int *)(local_63e8 + 0xc0) == 0) {
      puStack_6428 = (undefined *)0x1;
      FUN_007979e8();
    }
    else {
      puStack_6428 = (undefined *)0x0;
      FUN_007979e8();
    }
    puStack_6428 = (undefined *)0x0;
    FUN_00797f20();
    puStack_6428 = (undefined *)0x5;
    FUN_00797f20();
    puStack_6428 = (undefined *)0x5;
    FUN_00797f20();
  }
  else {
    puStack_6428 = (undefined *)0x1;
    FUN_007979e8();
    puStack_6428 = (undefined *)0x1;
    FUN_007979e8();
    puStack_6428 = (undefined *)0x5;
    FUN_00797f20();
    puStack_6428 = (undefined *)0x5;
    FUN_00797f20();
    puStack_6428 = (undefined *)0x0;
    FUN_00797f20();
  }
  local_8 = 0xffffffff;
  puStack_6428 = (undefined *)0x581249;
  FUN_004fa910();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CMojiDialog[10] */
/* 00581340  FUN_00581340  16 bytes, 0 callers */

void FUN_00581340(void)

{
  FUN_00581460();
  return;
}




/* vtable slots: CMojiDialog[94] */
/* 00582630  FUN_00582630  1034 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00582630(void)

{
  double *pdVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_18;
  undefined4 local_c;
  
  if (DAT_00a0b464 == 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0xbc) + 0x518) = 0;
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 0xbc) + 0x518) = 1;
  }
  FUN_00798993();
  local_34 = DAT_00a0c188;
  local_30 = DAT_00a0c184;
  FUN_00797f20(0);
  if (DAT_00a0b468 < 0) {
    DAT_00a0b468 = 0;
  }
  if (4 < DAT_00a0b468) {
    DAT_00a0b468 = 0;
  }
  *(int *)(*(int *)(in_ECX + 0xbc) + 0xc0) = DAT_00a0b468;
  local_38 = DAT_00a0b46c;
  if (DAT_00a0b46c < 500) {
    local_38 = 500;
  }
  pdVar1 = (double *)(*(int *)(in_ECX + 0xb8) + 0x1808);
  if (*pdVar1 <= (double)local_38 && (double)local_38 != *pdVar1) {
    local_38 = (int)*(double *)(*(int *)(in_ECX + 0xb8) + 0x1808);
  }
  *(int *)(*(int *)(in_ECX + 0xbc) + 0xb8) = local_38;
  *(undefined4 *)(*(int *)(in_ECX + 0xbc) + 0xbc) = *(undefined4 *)(in_ECX + 0xc4);
  if ((DAT_00a0cc6c == 0) || (DAT_00a0cc74 == 0)) {
    *(undefined4 *)(*(int *)(in_ECX + 0xbc) + 0xc4) = 0;
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 0xbc) + 0xc0) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 0xbc) + 0xc4) = 1;
  }
  uVar2 = FUN_00404c80();
  (**(code **)(**(int **)(in_ECX + 0xbc) + 0x164))(0x11c,uVar2);
  (**(code **)(*(int *)(in_ECX + 0x630) + 0x180))(in_ECX + 0xd8,10);
  if (DAT_00a0bc30 == 0) {
    (**(code **)(*(int *)(in_ECX + 0x630) + 0x188))(0);
  }
  FUN_004146a0();
  if (DAT_00a0c184 < -0x2a87) {
    FUN_00413f30();
    FUN_004146a0();
    local_30 = local_18 + 0x23;
    local_34 = local_c + 10;
    FUN_00413f30();
    FUN_00404c80();
    FUN_004146a0();
    iVar3 = FUN_00416780();
    iVar4 = FUN_004f74b0();
    if (iVar4 < iVar3) {
      local_30 = local_18 + 0x4b;
    }
  }
  else {
    local_30 = local_30 + _DAT_00a0c0d4;
    local_34 = local_34 + _DAT_00a0c0d8;
    if (local_30 < 0) {
      local_30 = 0;
    }
    if (local_34 < 0) {
      local_34 = 0;
    }
    pdVar1 = (double *)(*(int *)(in_ECX + 0xb8) + 0x1808);
    if (*pdVar1 <= (double)(local_30 + 0x28a) && (double)(local_30 + 0x28a) != *pdVar1) {
      local_30 = (int)*(double *)(*(int *)(in_ECX + 0xb8) + 0x1808) + -0x28a;
    }
    pdVar1 = (double *)(*(int *)(in_ECX + 0xb8) + 0x1810);
    if (*pdVar1 <= (double)(local_34 + 100) && (double)(local_34 + 100) != *pdVar1) {
      local_34 = (int)*(double *)(*(int *)(in_ECX + 0xb8) + 0x1810) + -100;
    }
  }
  FUN_00797e71(0,local_30,local_34,0,0,5);
  FUN_00797f20();
  FUN_00583740();
  *(int *)(in_ECX + 0x274) = DAT_00a0b478 % 3;
  *(int *)(in_ECX + 0x278) = DAT_00a0b478 / 3;
  if ((*(int *)(in_ECX + 0x274) < 0) || (2 < *(int *)(in_ECX + 0x274))) {
    *(undefined4 *)(in_ECX + 0x274) = 0;
  }
  if ((*(int *)(in_ECX + 0x278) < 0) || (2 < *(int *)(in_ECX + 0x278))) {
    *(undefined4 *)(in_ECX + 0x278) = 0;
  }
  if (DAT_00a0b458 == 0) {
    FUN_00797ece();
  }
  else {
    FUN_00797ece();
  }
  return 1;
}




/* vtable slots: CMojiDialog[67] */
/* 005830e0  FUN_005830e0  137 bytes, 0 callers */

int FUN_005830e0(tagMSG *param_1)

{
  undefined4 uVar1;
  int iVar2;
  CDialog *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  if ((param_1->message == 0x100) && (param_1->wParam == 0xd)) {
    FUN_005835f0(1);
    FUN_00404c80();
    uVar1 = FUN_00799e17();
    FUN_00406bc0(0x1500,0,0);
    uVar5 = 0;
    uVar4 = 0;
    uVar3 = 0x1408;
    FUN_00404c80(0x1408,0,0,uVar1);
    FUN_00799e17();
    FUN_00406bc0(uVar3,uVar4,uVar5);
    FUN_00404c80();
    FUN_0056d7d0();
    iVar2 = 1;
  }
  else {
    iVar2 = CDialog::PreTranslateMessage(in_ECX,param_1);
  }
  return iVar2;
}



