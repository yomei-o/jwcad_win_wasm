/* CZukei25D -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukei25D[1] */
/* 0060de50  FUN_0060de50  68 bytes, 0 callers */

undefined4 FUN_0060de50(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0060de20();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1d9e0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukei25D[6] */
/* 0060dea0  FUN_0060dea0  1949 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0060e271) */

void FUN_0060dea0(double *param_1)

{
  undefined8 uVar1;
  int iVar2;
  double dVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar7;
  double dVar6;
  undefined4 uVar8;
  undefined1 local_6600 [20];
  undefined4 local_65ec;
  double local_65e8;
  undefined4 local_65e0;
  undefined4 local_65dc;
  undefined4 local_65d0;
  undefined4 local_65cc;
  undefined4 local_65c8;
  undefined4 local_65c4;
  undefined4 local_65bc;
  undefined4 local_65b8;
  undefined4 local_65b0;
  undefined4 local_65ac;
  double local_65a8;
  double local_65a0;
  double local_6598;
  undefined4 local_6590;
  undefined4 local_658c;
  int local_6588;
  int *local_6584;
  int local_6580;
  int local_657c;
  undefined2 local_1a8 [202];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009364c7;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_657c + 4));
  local_8._0_1_ = 1;
  local_658c = FUN_0040c0e0();
  FUN_0044dd90(local_6600,*(undefined4 *)(local_657c + 4));
  if (*(int *)(local_657c + 0xb0) != 0) {
    FUN_004efbb0(0x14e9,0,0);
    local_65e0 = *(undefined4 *)(*(int *)(local_657c + 4) + 0x8f40);
    local_65dc = *(undefined4 *)(*(int *)(local_657c + 4) + 0x8f44);
    local_6584 = (int *)0x0;
    local_65ec = 1;
    local_6588 = FUN_00572c50();
    while (((local_6588 != 0 &&
            (local_6584 = (int *)FUN_00572c90(&local_6588,0), local_6584 != (int *)0x0)) &&
           (iVar2 = FUN_004fcab0(local_65e0,local_65dc), iVar2 == 0))) {
      local_6580 = (**(code **)(*local_6584 + 0x14))();
      *(short *)(local_6580 + 0x44) = (short)local_6584[0x11];
      *(double *)(local_6580 + 8) = *(double *)(local_6580 + 8) + *param_1;
      *(double *)(local_6580 + 0x10) = *(double *)(local_6580 + 0x10) + param_1[1];
      *(double *)(local_6580 + 0x18) = *(double *)(local_6580 + 0x18) + *param_1;
      *(double *)(local_6580 + 0x20) = *(double *)(local_6580 + 0x20) + param_1[1];
      FUN_00447cf0(local_6600,*(undefined4 *)(local_657c + 4),local_6580,1);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    ExceptionList = local_10;
    return;
  }
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xb8) == 0) {
    if (*(int *)(local_657c + 0xac) == 0) {
      FUN_004efbb0(0x158f,0,0);
      if (*(int *)(*(int *)(local_657c + 4) + 0x17f0) != 0) {
        *(undefined4 *)(*(int *)(local_657c + 4) + 0x17f0) = 0;
        FUN_00404c80();
        FUN_004fca20();
        FUN_00797df8();
      }
      if (*(int *)(local_657c + 0x328) == DAT_00a0d62c) {
        if (*(double *)(local_657c + 0x330) - DAT_00a0d630 <= 0.0) {
          local_65e8 = -(*(double *)(local_657c + 0x330) - DAT_00a0d630);
        }
        else {
          local_65e8 = *(double *)(local_657c + 0x330) - DAT_00a0d630;
        }
        if (local_65e8 <= 1e-07) goto LAB_0060e601;
      }
      *(int *)(local_657c + 0x328) = DAT_00a0d62c;
      *(double *)(local_657c + 0x330) = DAT_00a0d630;
      uVar7 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_00404f50(uVar7);
    }
    else {
      FUN_004efbb0(0x151b,0,0);
    }
  }
  else {
    local_6590 = 0;
    local_1a8[0] = 0;
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xb8) < 3) {
      local_65a8 = *(double *)
                    (*(int *)(local_657c + 4) + 0x2578 +
                    *(int *)(*(int *)(local_657c + 4) + 0x256c) * 8);
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      local_65a0 = *(double *)(*(int *)(iVar2 + 0x1a0) + 0xe8) * local_65a8;
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      local_6598 = *(double *)(*(int *)(iVar2 + 0x1a0) + 0xf0) * local_65a8;
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xb8) == 2) {
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        local_65a0 = *(double *)(*(int *)(iVar2 + 0x1a0) + 0xf8) * local_65a8;
        FUN_00404c80();
        iVar2 = FUN_004fca20();
        local_6598 = *(double *)(*(int *)(iVar2 + 0x1a0) + 0x100) * local_65a8;
      }
      if (*(int *)(*(int *)(local_657c + 4) + 0x82f0) == 0) {
        local_65a0 = local_65a0 / 1000.0;
        local_6598 = local_6598 / 1000.0;
        dVar6 = local_6598;
        dVar3 = local_65a0;
        local_65b0 = FUN_005977f0(0x1834);
        local_8._0_1_ = 2;
        local_65ac = local_65b0;
        uVar7 = FUN_00404920(dVar3,dVar6);
        FUN_00404c80(uVar7);
        iVar2 = FUN_004fca20();
        uVar1 = *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0xe0);
        FUN_0059f750(local_1a8,L" %.3lf(%s)  %.1lf(m)   %.1lf(m)",(int)uVar1,
                     (int)((ulonglong)uVar1 >> 0x20));
        local_8._0_1_ = 1;
        FUN_00404770();
      }
      else {
        uVar5 = SUB84(local_6598,0);
        uVar8 = (undefined4)((ulonglong)local_6598 >> 0x20);
        uVar7 = SUB84(local_65a0,0);
        uVar4 = (undefined4)((ulonglong)local_65a0 >> 0x20);
        local_65bc = FUN_005977f0(0x1833);
        local_8._0_1_ = 3;
        local_65b8 = local_65bc;
        uVar7 = FUN_00404920(uVar7,uVar4,uVar5,uVar8);
        FUN_00404c80(uVar7);
        iVar2 = FUN_004fca20();
        uVar1 = *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0xe0);
        FUN_0059f750(local_1a8,L" %.3lf(%s)  %.1lf(mm)   %.1lf(mm)",(int)uVar1,
                     (int)((ulonglong)uVar1 >> 0x20));
        local_8._0_1_ = 1;
        FUN_00404770();
      }
    }
    else {
      local_65c8 = FUN_005977f0(0x1833);
      local_8._0_1_ = 4;
      local_65c4 = local_65c8;
      uVar7 = FUN_00404920();
      FUN_00404c80(uVar7);
      iVar2 = FUN_004fca20();
      uVar1 = *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0x108);
      uVar7 = (undefined4)uVar1;
      uVar4 = (undefined4)((ulonglong)uVar1 >> 0x20);
      local_65d0 = FUN_005977f0(0x1833);
      local_8._0_1_ = 5;
      local_65cc = local_65d0;
      uVar7 = FUN_00404920(uVar7,uVar4);
      FUN_00404c80(uVar7);
      iVar2 = FUN_004fca20();
      uVar1 = *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0xe0);
      FUN_0059f750(local_1a8,L" %.3lf(%s)  %.3lf(%s)",(int)uVar1,(int)((ulonglong)uVar1 >> 0x20));
      local_8._0_1_ = 4;
      FUN_00404770();
      local_8._0_1_ = 1;
      FUN_00404770();
    }
    FUN_004efbb0(0x1590,local_1a8,0);
  }
LAB_0060e601:
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukei25D[16] */
/* 0060e640  FUN_0060e640  132 bytes, 0 callers */

undefined4 FUN_0060e640(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) == 4) {
    (**(code **)(*in_ECX + 0x6c))();
    uVar2 = 1;
  }
  else {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 0;
      FUN_00404c80(0);
      FUN_004fca20();
      FUN_00404f50(uVar2);
      (**(code **)(*in_ECX + 0x6c))();
      uVar2 = 1;
    }
  }
  return uVar2;
}




/* vtable slots: CZukei25D[0] */
/* 006109a0  FUN_006109a0  16 bytes, 0 callers */

undefined ** FUN_006109a0(void)

{
  return &PTR_s_CZukei25D_00977888;
}




/* vtable slots: CZukei25D[24] */
/* 006112d0  FUN_006112d0  100 bytes, 0 callers */

void FUN_006112d0(void)

{
  int *in_ECX;
  
  if (*(int *)(in_ECX[1] + 0x82ec) == 1) {
    *(undefined4 *)(in_ECX[1] + 0x8358) = 0;
  }
  else if (*(int *)(in_ECX[1] + 0x82ec) == 2) {
    *(undefined4 *)(in_ECX[1] + 0x835c) = 0;
  }
  (**(code **)(*in_ECX + 100))();
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukei25D[25] */
/* 00611340  FUN_00611340  1649 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00611340(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_6428 [20];
  undefined1 local_6414 [20];
  double local_6400;
  double local_63f8;
  double local_63f0;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009365d6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  if (*(int *)(in_ECX + 0xb0) != 0) {
    *(undefined4 *)(in_ECX + 0xb0) = 0;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 1;
    FUN_0044dd90(local_6414,*(undefined4 *)(local_63e8 + 4));
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  FUN_00404c80();
  FUN_004fca20();
  FUN_00797df8();
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x82ec) =
       *(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0xb8);
  *(undefined4 *)(local_63e8 + 0x338) = 0;
  if (DAT_00a0cc6c != 0) {
    *(undefined4 *)(local_63e8 + 0x338) = 1;
  }
  DAT_00a0cc74 = 0;
  DAT_00a0cc6c = 0;
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x82f0) = 0;
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xc0) != 0) {
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x82f0) = 1;
  }
  FUN_00617f70();
  local_6400 = *(double *)(&DAT_009ffc58 + *(int *)(*(int *)(local_63e8 + 4) + 0x3020) * 8);
  local_63f0 = (double)(int)((local_6400 * 2.0) / 10.0);
  if (local_63f0 < 1.0) {
    local_63f0 = 1.0;
  }
  local_63f0 = local_63f0 * 10.0;
  *(double *)(local_63e8 + 0x348) = local_63f0 / 2.0;
  iVar1 = *(int *)(local_63e8 + 4);
  iVar3 = *(int *)(*(int *)(local_63e8 + 4) + 0x256c);
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0xd8) = *(undefined8 *)(iVar1 + 0x2578 + iVar3 * 8);
  if (*(int *)(*(int *)(local_63e8 + 4) + 0x82ec) == 1) {
    if (*(int *)(*(int *)(local_63e8 + 4) + 0x8358) == 0) {
      *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8358) = 1;
      local_63f8 = 2000.0;
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xc0) != 0) {
        local_63f8 = 2.0;
      }
      local_63f8 = local_63f8 /
                   *(double *)
                    (*(int *)(local_63e8 + 4) + 0x2578 +
                    *(int *)(*(int *)(local_63e8 + 4) + 0x256c) * 8);
      *(double *)(*(int *)(local_63e8 + 4) + 0x8368) = local_63f8;
      *(double *)(*(int *)(local_63e8 + 4) + 0x8370) = -local_63f0;
      *(undefined8 *)(*(int *)(local_63e8 + 4) + 0x8378) = 0xc046800000000000;
    }
    iVar1 = *(int *)(local_63e8 + 4);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined8 *)(*(int *)(iVar3 + 0x1a0) + 0xe8) = *(undefined8 *)(iVar1 + 0x8368);
    iVar1 = *(int *)(local_63e8 + 4);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined8 *)(*(int *)(iVar3 + 0x1a0) + 0xf0) = *(undefined8 *)(iVar1 + 0x8370);
    iVar1 = *(int *)(local_63e8 + 4);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined8 *)(*(int *)(iVar3 + 0x1a0) + 0xe0) = *(undefined8 *)(iVar1 + 0x8378);
  }
  if (*(int *)(*(int *)(local_63e8 + 4) + 0x82ec) == 2) {
    if (*(int *)(*(int *)(local_63e8 + 4) + 0x835c) == 0) {
      *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x835c) = 1;
      *(double *)(*(int *)(local_63e8 + 4) + 0x8380) = local_63f0;
      *(double *)(*(int *)(local_63e8 + 4) + 0x8388) = -local_63f0;
      *(undefined8 *)(*(int *)(local_63e8 + 4) + 0x8390) = 0xc046800000000000;
    }
    iVar1 = *(int *)(local_63e8 + 4);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined8 *)(*(int *)(iVar3 + 0x1a0) + 0xf8) = *(undefined8 *)(iVar1 + 0x8380);
    iVar1 = *(int *)(local_63e8 + 4);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined8 *)(*(int *)(iVar3 + 0x1a0) + 0x100) = *(undefined8 *)(iVar1 + 0x8388);
    iVar1 = *(int *)(local_63e8 + 4);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined8 *)(*(int *)(iVar3 + 0x1a0) + 0xe0) = *(undefined8 *)(iVar1 + 0x8390);
  }
  if (*(int *)(*(int *)(local_63e8 + 4) + 0x82ec) == 3) {
    if (*(int *)(*(int *)(local_63e8 + 4) + 0x8360) == 0) {
      *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8360) = 1;
      *(undefined8 *)(*(int *)(local_63e8 + 4) + 0x8398) =
           *(undefined8 *)(*(int *)(local_63e8 + 4) + 0x82f8);
      *(undefined8 *)(*(int *)(local_63e8 + 4) + 0x83a0) = 0xc046800000000000;
    }
    iVar1 = *(int *)(local_63e8 + 4);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined8 *)(*(int *)(iVar3 + 0x1a0) + 0x108) = *(undefined8 *)(iVar1 + 0x8398);
    iVar1 = *(int *)(local_63e8 + 4);
    FUN_00404c80();
    iVar3 = FUN_004fca20();
    *(undefined8 *)(*(int *)(iVar3 + 0x1a0) + 0xe0) = *(undefined8 *)(iVar1 + 0x83a0);
  }
  *(undefined8 *)(*(int *)(local_63e8 + 4) + 0x8300) = 0;
  *(undefined8 *)(local_63e8 + 0xc0) = 0;
  *(undefined1 *)(*(int *)(local_63e8 + 4) + 0x859c) = 1;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = 2;
  (**(code **)(**(int **)(local_63e8 + 4) + 0x19c))(local_6428);
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukei25D[26] */
/* 006119c0  FUN_006119c0  3053 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006119c0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_6aac [20];
  int local_6a98;
  undefined4 local_6a94;
  undefined4 local_6a90;
  int local_6a8c;
  int local_6a88;
  undefined4 local_6a84;
  int local_6a80;
  int local_6a7c;
  undefined4 local_6a78;
  int local_6a74;
  int local_6a70;
  int local_6a6c;
  int local_6a68;
  int local_6a64;
  int local_6a60;
  int local_6a5c;
  CWaitCursor local_6a55;
  undefined4 local_6a54;
  undefined4 local_6a50;
  int local_6a4c;
  undefined4 local_6a48;
  int local_6a44;
  int local_6a40;
  undefined4 local_744;
  undefined1 local_66c [600];
  undefined1 local_414 [40];
  undefined1 local_3ec;
  undefined2 local_3ea;
  undefined4 local_37c;
  undefined1 local_1bc [104];
  undefined1 local_154 [40];
  undefined1 local_12c;
  undefined2 local_12a;
  undefined1 local_bc [16];
  undefined1 local_ac [16];
  undefined1 local_9c [16];
  undefined1 local_8c [16];
  undefined1 local_7c [40];
  undefined1 local_54;
  undefined2 local_52;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093667d;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0cc74 != 0) {
    *(undefined4 *)(in_ECX + 0xb4) = 1;
  }
  local_6a44 = in_ECX;
  CWaitCursor::CWaitCursor(&local_6a55);
  local_8 = 0;
  local_6a54 = 0;
  if ((DAT_00a0cc6c != 0) && (DAT_00a0cc74 != 0)) {
    local_6a54 = 1;
    *(undefined4 *)(local_6a44 + 0xb4) = 0;
  }
  DAT_00a0cc74 = 0;
  DAT_00a0cc6c = 0;
  if (*(char *)(*(int *)(local_6a44 + 4) + 0x859c) != '\0') {
    local_6a8c = *(int *)(local_6a44 + 4);
    if (local_6a8c == 0) {
      local_6a88 = 0;
    }
    else {
      local_6a88 = local_6a8c + 0x88;
    }
    FUN_0060b020(local_6a88,*(undefined4 *)(local_6a44 + 4),0);
    local_8._0_1_ = 1;
    FUN_004578a0(0);
    *(undefined1 *)(*(int *)(local_6a44 + 4) + 0x859c) = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0060b110();
  }
  FUN_005168b0(0x1456,*(undefined4 *)(*(int *)(local_6a44 + 4) + 0x8f24),
               *(undefined4 *)(*(int *)(local_6a44 + 4) + 0x8f28),0,0);
  FUN_00446aa0();
  local_8._0_1_ = 2;
  local_6a48 = FUN_0040c0e0();
  FUN_0079dea2(*(undefined4 *)(local_6a44 + 4));
  local_8._0_1_ = 3;
  local_6a40 = 0;
  FUN_00464040();
  local_8 = CONCAT31(local_8._1_3_,4);
  local_6a50 = FUN_00572c70();
  while (local_6a40 = FUN_00572cd0(&local_6a50,0), local_6a40 != 0) {
    *(undefined4 *)(local_6a40 + 0x48) = 0;
  }
  do {
    local_6a64 = 0;
    local_6a84 = 0;
    local_6a50 = FUN_00572c70();
    while (local_6a40 = FUN_00572cd0(&local_6a50,0), local_6a40 != 0) {
      if ((*(int *)(local_6a40 + 4) != 0) && (*(int *)(local_6a40 + 0x48) == 0)) {
        if (local_6a64 == 0) {
          local_6a64 = *(int *)(local_6a40 + 4);
          local_6a84 = FUN_00479d80(local_6a48);
        }
        if (*(int *)(local_6a40 + 4) == local_6a64) {
          *(undefined4 *)(local_6a40 + 4) = local_6a84;
          *(undefined4 *)(local_6a40 + 0x48) = 1;
        }
      }
    }
  } while (local_6a64 != 0);
  local_6a68 = 0;
  local_6a50 = FUN_00572c70();
LAB_00611ccc:
  local_6a40 = FUN_00572cd0(&local_6a50,0);
  if (local_6a40 != 0) {
    iVar1 = FUN_00610960();
    if (iVar1 == 0) {
      iVar1 = FUN_00610980();
      if (iVar1 == 0) {
        iVar1 = FUN_0079d98a(&PTR_s_CData3DSolid_009fe0e8);
        if (iVar1 != 0) {
          local_6a4c = local_6a40;
          FUN_0041f780();
          local_8._0_1_ = 5;
          FUN_004552a0(local_414);
          FUN_004988c0(local_bc,*(undefined4 *)(local_6a4c + 8),*(undefined4 *)(local_6a4c + 0xc),
                       *(undefined4 *)(local_6a4c + 0x10),*(undefined4 *)(local_6a4c + 0x14));
          FUN_004988c0(local_ac,*(undefined4 *)(local_6a4c + 0x18),
                       *(undefined4 *)(local_6a4c + 0x1c),*(undefined4 *)(local_6a4c + 0x20),
                       *(undefined4 *)(local_6a4c + 0x24));
          FUN_004988c0(local_9c,*(undefined4 *)(local_6a4c + 0x68),
                       *(undefined4 *)(local_6a4c + 0x6c),*(undefined4 *)(local_6a4c + 0x70),
                       *(undefined4 *)(local_6a4c + 0x74));
          FUN_004988c0(local_8c,*(undefined4 *)(local_6a4c + 0x78),
                       *(undefined4 *)(local_6a4c + 0x7c),*(undefined4 *)(local_6a4c + 0x80),
                       *(undefined4 *)(local_6a4c + 0x84));
          local_3ec = *(undefined1 *)(local_6a4c + 0x28);
          local_3ea = *(undefined2 *)(local_6a4c + 0x2a);
          local_37c = *(undefined4 *)(local_6a4c + 0x98);
          FUN_00615ca0(local_6a54,local_414,local_6a40);
          local_6a5c = FUN_00450860(local_6aac,*(undefined4 *)(local_6a44 + 4),local_414,1,0);
          if (local_6a5c == 0) {
            local_8 = CONCAT31(local_8._1_3_,4);
            FUN_0041fd90();
            goto LAB_00611ccc;
          }
          local_744 = 1;
          *(undefined4 *)(local_6a5c + 4) = *(undefined4 *)(local_6a40 + 4);
          if (*(int *)(local_6a4c + 0x2b8) != 0) {
            FUN_00615ca0(local_6a54,local_6a4c + 0x2c0,local_6a40);
            local_6a80 = FUN_00450860(local_6aac,*(undefined4 *)(local_6a44 + 4),local_6a4c + 0x2c0,
                                      1,0);
            if (local_6a80 == 0) {
              local_8 = CONCAT31(local_8._1_3_,4);
              FUN_0041fd90();
              goto LAB_00611ccc;
            }
            if (*(int *)(local_6a5c + 4) == 0) {
              uVar2 = FUN_00479d80(local_6a48);
              *(undefined4 *)(local_6a5c + 4) = uVar2;
            }
            *(undefined4 *)(local_6a80 + 4) = *(undefined4 *)(local_6a5c + 4);
          }
          local_8 = CONCAT31(local_8._1_3_,4);
          FUN_0041fd90();
        }
      }
      else {
        local_6a68 = 1;
      }
    }
    goto LAB_00611ccc;
  }
  FUN_00454830(*(undefined4 *)(local_6a44 + 4));
  local_6a50 = FUN_00572c70();
LAB_00611fee:
  do {
    while( true ) {
      while( true ) {
        do {
          local_6a40 = FUN_00572cd0(&local_6a50,0);
          if (local_6a40 == 0) {
            local_6a70 = *(int *)(local_6a44 + 4);
            if (local_6a70 == 0) {
              local_6a74 = 0;
            }
            else {
              local_6a74 = local_6a70 + 0x88;
            }
            FUN_00454890(local_6a74);
            if (*(int *)(local_6a44 + 0xac) == 0) {
              FUN_00454830(*(undefined4 *)(local_6a44 + 4));
            }
            else {
              *(undefined4 *)(local_6a44 + 0xb0) = 1;
              FUN_004efbb0(0x14e9,0,0);
            }
            uVar2 = 0;
            FUN_00404c80(0);
            FUN_004fca20();
            FUN_00404f50(uVar2);
            FUN_004fb9f0();
            if (local_6a68 != 0) {
              FUN_005168b0(0x1508,*(undefined4 *)(*(int *)(local_6a44 + 4) + 0x8f24),
                           *(undefined4 *)(*(int *)(local_6a44 + 4) + 0x8f28),0,0);
            }
            local_8._0_1_ = 3;
            FUN_004640a0();
            local_8._0_1_ = 2;
            FUN_0079dfff();
            local_8 = (uint)local_8._1_3_ << 8;
            FUN_00447100();
            local_8 = 0xffffffff;
            FUN_00408b00();
            ExceptionList = local_10;
            return;
          }
          iVar1 = FUN_00610960();
        } while (iVar1 != 0);
        iVar1 = FUN_00610980();
        if (iVar1 == 0) break;
        local_6a68 = 1;
      }
      iVar1 = FUN_0079d98a(&PTR_s_CData3DSen_009fe0b0);
      if (iVar1 != 0) break;
LAB_0061221c:
      iVar1 = FUN_0079d98a(&PTR_s_CData3DEnko_009fe0cc);
      if (iVar1 != 0) {
        local_6a6c = local_6a40;
        local_6a60 = 0;
        if (*(int *)(local_6a40 + 0x4c8) == 0) {
          if (*(int *)(local_6a40 + 0x490) == 0) {
            FUN_0041f490(local_6a40 + 0x390);
            local_8._0_1_ = 9;
            local_12c = *(undefined1 *)(local_6a6c + 0x3b8);
            local_12a = *(undefined2 *)(local_6a6c + 0x3ba);
            FUN_00615ca0(local_6a54,local_154,local_6a40);
            local_6a60 = FUN_00450860(local_6aac,*(undefined4 *)(local_6a44 + 4),local_154,1,0);
            local_8 = CONCAT31(local_8._1_3_,4);
            FUN_0041fd50();
          }
          else {
            FUN_0049c290(local_6a40 + 0x428);
            local_8._0_1_ = 10;
            FUN_00615ca0(local_6a54,local_1bc,local_6a40);
            local_6a60 = FUN_00450860(local_6aac,*(undefined4 *)(local_6a44 + 4),local_1bc,1,0);
            local_8 = CONCAT31(local_8._1_3_,4);
            FUN_0041fd70();
          }
          if (local_6a60 != 0) {
            local_744 = 1;
          }
        }
        else {
          FUN_0041f780();
          local_8._0_1_ = 8;
          FUN_004552a0(local_66c);
          FUN_004201b0(local_6a40 + 0x4d0);
          FUN_00615ca0(local_6a54,local_66c,local_6a40);
          local_6a60 = FUN_00450860(local_6aac,*(undefined4 *)(local_6a44 + 4),local_66c,1,0);
          if (local_6a60 == 0) {
            local_8 = CONCAT31(local_8._1_3_,4);
            FUN_0041fd90();
          }
          else {
            local_744 = 1;
            local_8 = CONCAT31(local_8._1_3_,4);
            FUN_0041fd90();
          }
        }
      }
    }
    FUN_0041f760();
    local_8._0_1_ = 6;
    FUN_004552a0(local_7c);
    FUN_0040da70(*(undefined4 *)(local_6a40 + 8),*(undefined4 *)(local_6a40 + 0xc),
                 *(undefined4 *)(local_6a40 + 0x10),*(undefined4 *)(local_6a40 + 0x14));
    FUN_0040da20(*(undefined4 *)(local_6a40 + 0x18),*(undefined4 *)(local_6a40 + 0x1c),
                 *(undefined4 *)(local_6a40 + 0x20),*(undefined4 *)(local_6a40 + 0x24));
    local_54 = *(undefined1 *)(local_6a40 + 0x28);
    local_52 = *(undefined2 *)(local_6a40 + 0x2a);
    FUN_00615ca0(local_6a54,local_7c,local_6a40);
    if (*(int *)(local_6a44 + 0xb4) == 0) {
      local_6a98 = FUN_00450860(local_6aac,*(undefined4 *)(local_6a44 + 4),local_7c,1,0);
      if (local_6a98 != 0) {
        local_744 = 1;
        local_8 = CONCAT31(local_8._1_3_,4);
        FUN_0041fd70();
        goto LAB_0061221c;
      }
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_0041fd70();
      goto LAB_00611fee;
    }
    iVar1 = FUN_006194a0(local_6a40);
    if (iVar1 == 0) {
      local_6a7c = FUN_004121b0(0x68);
      local_8._0_1_ = 7;
      if (local_6a7c == 0) {
        local_6a78 = 0;
      }
      else {
        local_6a78 = FUN_0041f760();
      }
      local_6a94 = local_6a78;
      local_8._0_1_ = 6;
      local_6a90 = local_6a78;
      FUN_00420110(local_7c);
      FUN_00570940(local_6a90);
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_0041fd70();
    }
    else {
      local_8 = CONCAT31(local_8._1_3_,4);
      FUN_0041fd70();
    }
  } while( true );
}




/* vtable slots: CZukei25D[27] */
/* 006125c0  FUN_006125c0  230 bytes, 0 callers */

void FUN_006125c0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  int local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009366bd;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(char *)(*(int *)(in_ECX + 4) + 0x859c) != '\0') {
    if (*(int *)(in_ECX + 4) == 0) {
      local_1c = 0;
    }
    else {
      local_1c = *(int *)(in_ECX + 4) + 0x88;
    }
    FUN_0060b020(local_1c,*(undefined4 *)(in_ECX + 4),0);
    local_8 = 0;
    FUN_004578a0(0);
    *(undefined1 *)(*(int *)(in_ECX + 4) + 0x859c) = 0;
    local_8 = 0xffffffff;
    FUN_0060b110();
  }
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xb8) == 0) {
    FUN_00404c80(uVar1);
    FUN_004fca20();
    FUN_00797df8();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukei25D[29] */
/* 006126b0  FUN_006126b0  19 bytes, 0 callers */

void FUN_006126b0(void)

{
  FUN_006172c0();
  return;
}




/* vtable slots: CZukei25D[30] */
/* 006126d0  FUN_006126d0  19 bytes, 0 callers */

void FUN_006126d0(void)

{
  FUN_00617640();
  return;
}




/* vtable slots: CZukei25D[40] */
/* 006126f0  FUN_006126f0  135 bytes, 0 callers */

void FUN_006126f0(void)

{
  int iVar1;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) != 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) < 3) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_00407180();
    }
    else {
      FUN_00404c80();
      FUN_004fca20();
      FUN_00406e90();
    }
    FUN_00617640();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukei25D[37] */
/* 00612780  FUN_00612780  83 bytes, 0 callers */

void FUN_00612780(void)

{
  int iVar1;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) != 0) {
    FUN_00404c80();
    FUN_004fca20();
    FUN_00405e10();
    FUN_00617640();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukei25D[42] */
/* 006127e0  FUN_006127e0  83 bytes, 0 callers */

void FUN_006127e0(void)

{
  int iVar1;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) != 0) {
    FUN_00404c80();
    FUN_004fca20();
    FUN_00406e90();
    FUN_00617640();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukei25D[41] */
/* 00612840  FUN_00612840  83 bytes, 0 callers */

void FUN_00612840(void)

{
  int iVar1;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) != 0) {
    FUN_00404c80();
    FUN_004fca20();
    FUN_00407020();
    FUN_00617640();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukei25D[38] */
/* 006128a0  FUN_006128a0  83 bytes, 0 callers */

void FUN_006128a0(void)

{
  int iVar1;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) != 0) {
    FUN_00404c80();
    FUN_004fca20();
    FUN_004060c0();
    FUN_00617640();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukei25D[39] */
/* 00612900  FUN_00612900  160 bytes, 0 callers */

void FUN_00612900(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) != 0) {
    if (DAT_00a0cc74 != 0) {
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x83a8) = 1;
    }
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) < 3) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_00406020();
    }
    else {
      FUN_00404c80();
      FUN_004fca20();
      FUN_00407020();
    }
    FUN_00617640();
    FUN_00404c80();
    FUN_0056d7d0();
  }
  return;
}




/* vtable slots: CZukei25D[12] */
/* 00615520  FUN_00615520  302 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00615520(void)

{
  int iVar1;
  undefined1 local_6400 [20];
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093365b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) == 0) {
    if (*(int *)(local_63e8 + 200) != 0) {
      FUN_0044b2c0(local_6400,*(undefined4 *)(local_63e8 + 4),*(undefined4 *)(local_63e8 + 200),1);
      *(undefined4 *)(local_63e8 + 200) = 0;
    }
    FUN_00404c80();
    FUN_004fca20();
    FUN_00797df8();
  }
  local_63ec = 0;
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukei25D[9] */
/* 00615650  FUN_00615650  789 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00615650(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined1 local_6408 [4];
  undefined4 local_6404;
  undefined4 local_6400;
  undefined4 local_63fc;
  int *local_63f8;
  undefined4 local_cc;
  undefined4 local_bc;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009367d0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  *(undefined4 *)(local_63f8[1] + 0x8560) = 0;
  local_63f8[0x32] = 0;
  FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
  if (local_63f8[0x2c] == 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) == 0) {
      local_63fc = 0;
      local_cc = 1;
      local_bc = 1;
      iVar1 = FUN_0044a270(3,local_63f8[1],&param_2,&local_63fc,0);
      if (iVar1 == 0) {
        local_6404 = 0;
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6400 = local_6404;
      }
      else {
        FUN_00621ee0(local_6408,0,local_63fc,param_2,param_3,param_4,param_5);
        FUN_00404540();
        FUN_00404c80();
        FUN_004fca20();
        FUN_00797df8();
        local_8 = 0xffffffff;
        FUN_00447100();
        local_6400 = 0;
      }
    }
    else {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) == 1) {
        *(double *)(local_63f8[1] + 0x8300) =
             *(double *)(local_63f8[1] + 0x8300) + (double)CONCAT44(param_3,param_2);
      }
      else {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        if (*(int *)(*(int *)(iVar1 + 0x1a0) + 0xb8) == 2) {
          *(double *)(local_63f8[1] + 0x8300) =
               *(double *)(local_63f8[1] + 0x8300) + (double)CONCAT44(param_3,param_2);
          *(ulonglong *)(local_63f8 + 0x30) = CONCAT44(param_5,param_4);
        }
      }
      (**(code **)(*local_63f8 + 0x14))();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_6400 = 1;
    }
  }
  else {
    FUN_0061a550(param_2,param_3,param_4,param_5);
    local_63f8[0x2c] = 0;
    FUN_00454830(local_63f8[1]);
    local_6400 = 1;
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_6400;
}




/* vtable slots: CZukei25D[11] */
/* 00615970  FUN_00615970  800 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00615970(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 local_6400;
  undefined1 local_63fc [4];
  int local_63f8;
  undefined4 local_63f4;
  undefined4 local_63f0;
  undefined4 local_63ec;
  undefined4 local_63e8;
  undefined4 local_bc;
  undefined4 local_ac;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093681b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  *(undefined4 *)(local_63f8 + 200) = 0;
  local_63f4 = param_2;
  local_63f0 = param_3;
  local_63ec = param_4;
  local_63e8 = param_5;
  if (*(int *)(local_63f8 + 0xb0) == 0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar2 + 0x1a0) + 0xb8) == 0) {
      local_6400 = 0;
      local_bc = 1;
      local_ac = 1;
      iVar2 = FUN_0044a270(3,*(undefined4 *)(local_63f8 + 4),&local_63f4,&local_6400,0);
      if (iVar2 == 0) {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar3 = 0;
      }
      else {
        FUN_00621ee0(local_63fc,1,local_6400,local_63f4,local_63f0,local_63ec,local_63e8);
        local_8 = CONCAT31(local_8._1_3_,1);
        cVar1 = FUN_004640c0(&DAT_00956338,local_63fc);
        if (cVar1 != '\0') {
          puVar4 = local_63fc;
          FUN_00404c80(puVar4);
          FUN_004fca20();
          FUN_00404860(puVar4);
          FUN_00404c80(0);
          FUN_004fca20();
          FUN_007955d2();
        }
        FUN_00404c80();
        FUN_004fca20();
        FUN_00797df8();
        local_8 = local_8 & 0xffffff00;
        FUN_00404540();
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar3 = 0;
      }
    }
    else {
      uVar3 = FUN_00615650(param_1,local_63f4,local_63f0,local_63ec,local_63e8);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    iVar2 = FUN_00451eb0(*(undefined4 *)(local_63f8 + 4),&local_63f4,1);
    if (iVar2 == 1) {
      uVar3 = FUN_00615650(param_1,local_63f4,local_63f0,local_63ec,local_63e8);
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_8 = 0xffffffff;
      FUN_00447100();
      uVar3 = 0;
    }
  }
  ExceptionList = local_10;
  return uVar3;
}




/* vtable slots: CZukei25D[4] */
/* 00615d00  FUN_00615d00  430 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00615d00(void)

{
  undefined1 local_640c [20];
  int local_63f8;
  int local_63f4;
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00936876;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  if (*(char *)(*(int *)(local_63e8 + 4) + 0x859c) != '\0') {
    local_63ec = *(int *)(local_63e8 + 4);
    if (local_63ec == 0) {
      local_63f0 = 0;
    }
    else {
      local_63f0 = local_63ec + 0x88;
    }
    FUN_0060b020(local_63f0,*(undefined4 *)(local_63e8 + 4),0);
    local_8._0_1_ = 2;
    FUN_004578a0(0);
    *(undefined1 *)(*(int *)(local_63e8 + 4) + 0x859c) = 0;
    local_8._0_1_ = 1;
    FUN_0060b110();
  }
  FUN_0044dd90(local_640c,*(undefined4 *)(local_63e8 + 4));
  local_63f4 = *(int *)(local_63e8 + 4);
  if (local_63f4 == 0) {
    local_63f8 = 0;
  }
  else {
    local_63f8 = local_63f4 + 0x88;
  }
  FUN_00454890(local_63f8);
  FUN_00454830(*(undefined4 *)(local_63e8 + 4));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukei25D[3] */
/* 00615eb0  FUN_00615eb0  221 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00615eb0(void)

{
  uint uVar1;
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
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63e8 = in_ECX;
  local_14 = uVar1;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  local_63ec = FUN_0040c0e0(uVar1);
  FUN_00446aa0();
  local_8._0_1_ = 1;
  FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
  *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukei25D[5] */
/* 00617640  FUN_00617640  2349 bytes, 7 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00617640(void)

{
  double *pdVar1;
  int iVar2;
  float10 fVar3;
  float10 fVar4;
  undefined1 local_649c [20];
  double local_6488;
  undefined4 local_6480;
  int local_647c;
  int local_6478;
  int local_6474;
  int local_6470;
  int local_646c;
  int local_6468;
  undefined4 local_6464;
  int local_6460;
  int *local_645c;
  int local_6458;
  int local_6454;
  int local_6450;
  undefined8 local_74;
  undefined8 local_6c;
  undefined8 local_64;
  undefined8 local_5c;
  undefined1 local_54;
  undefined2 local_52;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00936a03;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6464 = FUN_0040c0e0(local_14);
  FUN_0079dea2();
  local_8 = 0;
  FUN_00446aa0();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_004fb9f0();
  FUN_004bb680(local_649c,0);
  local_6460 = 0;
  for (local_6454 = 0; local_6454 < 0x10; local_6454 = local_6454 + 1) {
    if (*(int *)(local_6450 + 0x960 + local_6454 * 4) !=
        *(int *)(*(int *)(local_6450 + 4) + 0x242c + local_6454 * 4)) {
      local_6460 = 1;
    }
    for (local_6458 = 0; local_6458 < 0x10; local_6458 = local_6458 + 1) {
      if (*(int *)(local_6450 + 0x9e0 + local_6454 * 0x80 + local_6458 * 4) !=
          *(int *)(*(int *)(local_6450 + 4) + 0x182c + local_6454 * 0x40 + local_6458 * 4)) {
        local_6460 = 1;
      }
    }
  }
  if (local_6460 != 0) {
    FUN_00617f70();
  }
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8318) =
       *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0xe0);
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  if (90.0 < *(double *)(*(int *)(iVar2 + 0x1a0) + 0x108)) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0x108) = 0x4056800000000000;
  }
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  pdVar1 = (double *)(*(int *)(iVar2 + 0x1a0) + 0x108);
  if (*pdVar1 <= -90.0 && *pdVar1 != -90.0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0x108) = 0xc056800000000000;
  }
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8320) =
       *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0x108);
  if (*(int *)(*(int *)(local_6450 + 4) + 0x82ec) == 1) {
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8378) =
         *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8318);
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8368) =
         *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0xe8);
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8310) =
         *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8368);
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8370) =
         *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0xf0);
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8308) =
         *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8370);
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8320) = 0;
  }
  if (*(int *)(*(int *)(local_6450 + 4) + 0x82ec) == 2) {
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8390) =
         *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8318);
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8380) =
         *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0xf8);
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8310) =
         *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8380);
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8388) =
         *(undefined8 *)(*(int *)(iVar2 + 0x1a0) + 0x100);
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8308) =
         *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8388);
    fVar3 = (float10)FUN_008f8d00(*(undefined8 *)(*(int *)(local_6450 + 4) + 0x8310),
                                  *(ulonglong *)(*(int *)(local_6450 + 4) + 0x8308) ^
                                  0x8000000000000000);
    *(double *)(*(int *)(local_6450 + 4) + 0x8320) = ((double)fVar3 * 180.0) / 3.141592653589793;
    *(double *)(*(int *)(local_6450 + 4) + 0x8310) =
         *(double *)(*(int *)(local_6450 + 4) + 0x8310) + *(double *)(local_6450 + 0xc0);
  }
  if (*(int *)(*(int *)(local_6450 + 4) + 0x82ec) == 3) {
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x83a0) =
         *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8318);
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8398) =
         *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8320);
  }
  local_645c = (int *)0x0;
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  if ((*(int *)(*(int *)(iVar2 + 0x1a0) + 0xc10) == 0) ||
     (2 < *(int *)(*(int *)(local_6450 + 4) + 0x82ec))) {
    *(undefined8 *)(*(int *)(local_6450 + 4) + 0x8328) = *(undefined8 *)(local_6450 + 0x348);
  }
  else {
    fVar3 = (float10)FUN_008f8d10(*(double *)(*(int *)(local_6450 + 4) + 0x8308) *
                                  *(double *)(*(int *)(local_6450 + 4) + 0x8308) +
                                  *(double *)(*(int *)(local_6450 + 4) + 0x8310) *
                                  *(double *)(*(int *)(local_6450 + 4) + 0x8310));
    local_6488 = *(double *)(local_6450 + 0x350);
    if (*(int *)(*(int *)(local_6450 + 4) + 0x82ec) == 2) {
      fVar4 = (float10)FUN_008f8d10(*(double *)(local_6450 + 0x350) *
                                    *(double *)(local_6450 + 0x350) +
                                    *(double *)(local_6450 + 0x358) *
                                    *(double *)(local_6450 + 0x358));
      local_6488 = (double)fVar4;
    }
    *(double *)(*(int *)(local_6450 + 4) + 0x8328) = (double)fVar3;
    pdVar1 = (double *)(*(int *)(local_6450 + 4) + 0x8328);
    if (*pdVar1 <= local_6488 * 2.0 && local_6488 * 2.0 != *pdVar1) {
      *(double *)(*(int *)(local_6450 + 4) + 0x8328) = local_6488 * 2.0;
    }
  }
  local_6480 = FUN_00572c70();
  while (local_645c = (int *)FUN_00572cd0(&local_6480,0), local_645c != (int *)0x0) {
    local_6468 = *(int *)(local_6450 + 4);
    if (local_6468 == 0) {
      local_646c = 0;
    }
    else {
      local_646c = local_6468 + 0x88;
    }
    (**(code **)(*local_645c + 0x3c))();
  }
  FUN_0041f760();
  local_8._0_1_ = 2;
  local_54 = 9;
  local_52 = 9;
  if ((0 < *(int *)(*(int *)(local_6450 + 4) + 0x82ec)) &&
     (*(int *)(*(int *)(local_6450 + 4) + 0x82ec) < 3)) {
    local_74 = 0;
    local_64 = 0;
    local_6c = 0xc448650127cc3dc8;
    local_5c = 0x4448650127cc3dc8;
    local_6470 = *(int *)(local_6450 + 4);
    if (local_6470 == 0) {
      local_6474 = 0;
    }
    else {
      local_6474 = local_6470 + 0x88;
    }
    FUN_00425200();
    local_74 = 0xc448650127cc3dc8;
    local_64 = 0x4448650127cc3dc8;
    if (*(int *)(*(int *)(local_6450 + 4) + 0x82ec) == 1) {
      local_6c = 0;
      local_5c = 0;
    }
    else {
      local_6c = *(undefined8 *)(local_6450 + 0xc0);
      local_5c = *(undefined8 *)(local_6450 + 0xc0);
    }
    local_6478 = *(int *)(local_6450 + 4);
    if (local_6478 == 0) {
      local_647c = 0;
    }
    else {
      local_647c = local_6478 + 0x88;
    }
    FUN_00425200();
  }
  local_8._0_1_ = 1;
  FUN_0041fd70();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}



