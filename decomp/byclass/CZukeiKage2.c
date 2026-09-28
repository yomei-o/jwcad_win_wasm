/* CZukeiKage2 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiKage2[1] */
/* 00699100  FUN_00699100  68 bytes, 0 callers */

undefined4 FUN_00699100(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00699090();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x15a0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiKage2[6] */
/* 00699810  FUN_00699810  383 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00699810(undefined4 *param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined1 local_e8 [16];
  undefined1 local_d8 [208];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x2a] == 1) {
    FUN_004efbb0(0x15b3,0,0);
  }
  else if (in_ECX[0x2a] == 2) {
    FUN_004988c0(local_e8,*param_1,param_1[1],param_1[2],param_1[3]);
    (**(code **)(*in_ECX + 0x20))();
    FUN_004efbb0(0x14c9,0,0);
  }
  else if (in_ECX[0x2a] == 0) {
    FUN_005977f0(0x14b4);
    uVar1 = FUN_00404920();
    FUN_005cf710(local_d8,uVar1);
    FUN_00404770();
    FUN_005977f0(0x14b4);
    uVar1 = FUN_00404920();
    FUN_00661050(local_d8,uVar1);
    FUN_00404770();
    FUN_00661050(local_d8,in_ECX + 0x4dc);
    FUN_004efbb0(0x151b,local_d8,0);
  }
  return;
}




/* vtable slots: CZukeiKage2[16] */
/* 00699990  FUN_00699990  521 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00699990(void)

{
  undefined1 local_6408 [20];
  undefined4 local_63f4;
  undefined4 local_63f0;
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937dcb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  if (*(int *)(local_63e8 + 0xa8) == 1) {
    *(undefined4 *)(local_63e8 + 0xb0) = 0x32;
    *(undefined4 *)(local_63e8 + 0xa8) = 0;
    FUN_00699150();
    FUN_00404c80();
    FUN_0056d7d0();
    local_63ec = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else if (*(int *)(local_63e8 + 0xa8) == 2) {
    *(undefined4 *)(local_63e8 + 0xb0) = 0x32;
    *(undefined4 *)(local_63e8 + 0xa8) = 1;
    FUN_0044dd90(local_6408,*(undefined4 *)(local_63e8 + 4));
    FUN_00699150();
    FUN_00404c80();
    FUN_0056d7d0();
    local_63f0 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_63ec = local_63f0;
  }
  else {
    *(int *)(local_63e8 + 0xb4) = *(int *)(local_63e8 + 0xb4) + -1;
    if (*(int *)(local_63e8 + 0xb4) < 0) {
      *(undefined4 *)(local_63e8 + 0xb4) = 0;
      *(undefined4 *)(local_63e8 + 0x1598) = 0;
    }
    local_63f4 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_63ec = local_63f4;
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiKage2[0] */
/* 00699ba0  FUN_00699ba0  16 bytes, 0 callers */

undefined ** FUN_00699ba0(void)

{
  return &PTR_s_CZukeiKage2_00979318;
}




/* vtable slots: CZukeiKage2[26] */
/* 00699bb0  FUN_00699bb0  62 bytes, 0 callers */

void FUN_00699bb0(void)

{
  int *in_ECX;
  
  in_ECX[0x560] = 0;
  in_ECX[0x561] = 0x40000000;
  in_ECX[0x562] = 0;
  in_ECX[0x563] = 0x40000000;
  (**(code **)(*in_ECX + 0xc))();
  return;
}




/* vtable slots: CZukeiKage2[27] */
/* 00699bf0  FUN_00699bf0  62 bytes, 0 callers */

void FUN_00699bf0(void)

{
  int *in_ECX;
  
  in_ECX[0x560] = 0;
  in_ECX[0x561] = 0x40040000;
  in_ECX[0x562] = 0;
  in_ECX[0x563] = 0x40040000;
  (**(code **)(*in_ECX + 0xc))();
  return;
}




/* vtable slots: CZukeiKage2[28] */
/* 00699c30  FUN_00699c30  62 bytes, 0 callers */

void FUN_00699c30(void)

{
  int *in_ECX;
  
  in_ECX[0x560] = 0;
  in_ECX[0x561] = 0x40080000;
  in_ECX[0x562] = 0;
  in_ECX[0x563] = 0x40080000;
  (**(code **)(*in_ECX + 0xc))();
  return;
}




/* vtable slots: CZukeiKage2[29] */
/* 00699c70  FUN_00699c70  62 bytes, 0 callers */

void FUN_00699c70(void)

{
  int *in_ECX;
  
  in_ECX[0x560] = 0;
  in_ECX[0x561] = 0x40100000;
  in_ECX[0x562] = 0;
  in_ECX[0x563] = 0x40100000;
  (**(code **)(*in_ECX + 0xc))();
  return;
}




/* vtable slots: CZukeiKage2[30] */
/* 00699cb0  FUN_00699cb0  62 bytes, 0 callers */

void FUN_00699cb0(void)

{
  int *in_ECX;
  
  in_ECX[0x560] = 0;
  in_ECX[0x561] = 0x40140000;
  in_ECX[0x562] = 0;
  in_ECX[0x563] = 0x40140000;
  (**(code **)(*in_ECX + 0xc))();
  return;
}




/* vtable slots: CZukeiKage2[31] */
/* 00699cf0  FUN_00699cf0  573 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00699cf0(void)

{
  int iVar1;
  int *in_ECX;
  double local_32c;
  undefined1 local_324 [4];
  int *local_320;
  double local_26c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093badb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_32c = 8.0;
  if (*(int *)(in_ECX[1] + 0x83d0) != 0) {
    local_32c = 6.0;
  }
  local_320 = in_ECX;
  CStringT<>(local_14);
  local_8 = 0;
  FUN_004059f0(local_324,L"%lg - %lg",0x3ff0000000000000,local_32c);
  FUN_0054fd30();
  local_8 = CONCAT31(local_8._1_3_,1);
  local_26c = *(double *)(local_320 + 0x564);
  FUN_00404860();
  iVar1 = FUN_0079850d();
  if (iVar1 == 1) {
    if ((local_26c < 0.9999999) || (local_32c + 1e-07 < local_26c)) {
      FUN_005168b0(0x1599,*(undefined4 *)(local_320[1] + 0x8f24),
                   *(undefined4 *)(local_320[1] + 0x8f28),0,0);
    }
    else {
      *(double *)(local_320 + 0x564) = local_26c;
      *(double *)(local_320 + 0x560) = local_26c;
      *(double *)(local_320 + 0x562) = local_26c;
      if (local_32c - 0.01 < *(double *)(local_320 + 0x560)) {
        *(double *)(local_320 + 0x560) = *(double *)(local_320 + 0x560) - 0.01;
      }
      (**(code **)(*local_320 + 0xc))();
    }
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0054fe40();
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKage2[32] */
/* 00699f30  FUN_00699f30  159 bytes, 0 callers */

void FUN_00699f30(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1598) = 0;
  if (*(int *)(in_ECX + 0xb0) == 0x32) {
    if (*(int *)(in_ECX + 0x1144) == 0x3c) {
      *(undefined4 *)(in_ECX + 0x1144) = 10;
    }
    else {
      *(undefined4 *)(in_ECX + 0x1144) = 0x3c;
    }
  }
  else if (*(int *)(in_ECX + 0x1144) == 10) {
    *(undefined4 *)(in_ECX + 0x1144) = 4;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1144) = 10;
  }
  *(undefined2 *)(in_ECX + 0x1370) = 0;
  FUN_00699150();
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiKage2[33] */
/* 00699fd0  FUN_00699fd0  139 bytes, 0 callers */

void FUN_00699fd0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1598) = 0;
  if (*(int *)(in_ECX + 0xb0) == 0x3c) {
    *(undefined4 *)(in_ECX + 0xb0) = 0x32;
    *(undefined4 *)(in_ECX + 0xa8) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0xa8) = 1;
  }
  *(undefined2 *)(in_ECX + 0x1370) = 0;
  *(undefined2 *)(in_ECX + 0x1440) = 0;
  FUN_00699150();
  FUN_00404c80();
  FUN_0056d7d0();
  return;
}




/* vtable slots: CZukeiKage2[15] */
/* 0069a060  FUN_0069a060  26 bytes, 0 callers */

undefined4 FUN_0069a060(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1598) = 0;
  return 0;
}




/* vtable slots: CZukeiKage2[9] */
/* 0069a080  FUN_0069a080  1087 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0069a080(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  float10 fVar4;
  double dVar5;
  undefined1 local_654c [20];
  undefined4 local_6538;
  undefined4 local_6534;
  undefined4 local_6530;
  int local_652c;
  int local_6528;
  undefined1 local_154 [16];
  undefined1 local_144 [16];
  undefined1 local_134 [16];
  undefined1 local_124 [16];
  undefined1 local_114 [16];
  undefined1 local_104 [24];
  double local_ec;
  undefined1 local_dc;
  undefined2 local_da;
  undefined2 local_d8;
  undefined1 local_d6;
  undefined1 local_d5;
  undefined4 local_50;
  undefined8 local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bb36;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00446aa0(uVar1);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6528 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd90(local_654c,*(undefined4 *)(local_6528 + 4));
  if (*(int *)(local_6528 + 0xa8) == 1) {
    puVar2 = (undefined4 *)FUN_004988c0(local_114,param_2,param_3,param_4,param_5);
    FUN_004988c0(local_124,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    *(undefined4 *)(local_6528 + 0xa8) = 2;
    *(undefined4 *)(local_6528 + 0xb0) = 0x3c;
    FUN_00699150();
    FUN_00404c80();
    FUN_0056d7d0();
    local_6530 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  else if (*(int *)(local_6528 + 0xa8) == 2) {
    FUN_004988c0(local_134,param_2,param_3,param_4,param_5);
    *(undefined4 *)(local_6528 + 0xa8) = 0;
    FUN_00699150();
    FUN_00404c80();
    FUN_0056d7d0();
    local_6534 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_6530 = local_6534;
  }
  else {
    if (*(short *)(local_6528 + 0x1370) != 0) {
      FUN_00480a30();
      local_8._0_1_ = 2;
      local_dc = 1;
      local_d8 = 0;
      local_da = (undefined2)DAT_00a0b428;
      local_d6 = *(undefined1 *)
                  (*(int *)(local_6528 + 4) + 0x24ec +
                  *(int *)(*(int *)(local_6528 + 4) + 0x256c) * 4);
      local_d5 = *(undefined1 *)(*(int *)(local_6528 + 4) + 0x256c);
      local_652c = *(int *)(*(int *)(local_6528 + 4) + 0x83ac);
      if ((local_652c < 1) || (10 < local_652c)) {
        local_652c = 2;
      }
      local_50 = 0;
      local_4c = (&DAT_00a0b4f8)[local_652c];
      local_44 = (&DAT_00a0b658)[local_652c];
      local_3c = (&DAT_00a0b7b8)[local_652c];
      local_34 = 0;
      FUN_00404900(local_6528 + 0x1370);
      fVar4 = (float10)FUN_004935b0(1);
      dVar5 = (double)fVar4;
      FUN_004988c0(local_144,param_2,param_3,param_4,param_5);
      FUN_004988c0(local_154,param_2,param_3,param_4,param_5);
      local_ec = (double)CONCAT44(param_3,param_2) + dVar5;
      uVar3 = FUN_00450860(local_654c,*(undefined4 *)(local_6528 + 4),local_104,1,0);
      local_8._0_1_ = 1;
      FUN_00480ef0(uVar1,dVar5,uVar3);
    }
    FUN_00699150();
    FUN_00404c80();
    FUN_0056d7d0();
    local_6538 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
    local_6530 = local_6538;
  }
  ExceptionList = local_10;
  return local_6530;
}




/* vtable slots: CZukeiKage2[11] */
/* 0069a4c0  FUN_0069a4c0  326 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0069a4c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  if (((in_ECX[0x2a] != 0) || ((in_ECX[0x2a] == 0 && ((short)in_ECX[0x4dc] != 0)))) &&
     (iVar1 = FUN_00451eb0(in_ECX[1],&local_24,1), iVar1 == 0)) {
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




/* vtable slots: CZukeiKage2[8] */
/* 0069a610  FUN_0069a610  1557 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0069a610(void)

{
  undefined4 uVar1;
  float10 fVar2;
  double local_64d4;
  double local_64cc;
  undefined1 local_64c4 [20];
  undefined8 local_64b0;
  double local_64a8;
  double local_64a0;
  int local_6498;
  undefined1 local_c4 [16];
  undefined1 local_b4 [16];
  undefined1 local_a4 [16];
  undefined1 local_94 [16];
  undefined1 local_84 [16];
  undefined1 local_74 [16];
  undefined1 local_64 [16];
  undefined1 local_54 [16];
  undefined1 local_44 [16];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined8 local_24;
  undefined8 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bb7b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6498 + 4));
  local_8._0_1_ = 1;
  FUN_0044dd90();
  if (*(int *)(local_6498 + 0xb0) == 0x3c) {
    FUN_004552a0(local_6498 + 0x12e0);
    uVar1 = FUN_00420110(local_6498 + 0x12e0);
    uVar1 = FUN_00420110(uVar1);
    FUN_00420110(uVar1);
    FUN_005f89c0(*(undefined4 *)(local_6498 + 0x1350),*(undefined4 *)(local_6498 + 0x1354),
                 *(undefined4 *)(local_6498 + 0x1358),*(undefined4 *)(local_6498 + 0x135c),
                 *(undefined8 *)(local_6498 + 0x1348),0);
    fVar2 = (float10)FUN_005f8be0(1,*(undefined4 *)(local_6498 + 0x1360),
                                  *(undefined4 *)(local_6498 + 0x1364),
                                  *(undefined4 *)(local_6498 + 0x1368),
                                  *(undefined4 *)(local_6498 + 0x136c));
    local_64a0 = (double)fVar2;
    fVar2 = (float10)FUN_005f8ca0(1,*(undefined4 *)(local_6498 + 0x1360),
                                  *(undefined4 *)(local_6498 + 0x1364),
                                  *(undefined4 *)(local_6498 + 0x1368),
                                  *(undefined4 *)(local_6498 + 0x136c));
    local_64a8 = (double)fVar2;
    local_64b0 = 0x4049000000000000;
    if (local_64a0 <= 0.0) {
      local_64cc = -local_64a0;
    }
    else {
      local_64cc = local_64a0;
    }
    if (local_64cc < 50.0) {
      if (local_64a0 < 0.0) {
        local_64a0 = -50.0;
      }
      else {
        local_64a0 = 50.0;
      }
    }
    local_64d4 = local_64a8;
    if (local_64a8 <= 0.0) {
      local_64d4 = -local_64a8;
    }
    if (local_64d4 < 50.0) {
      if (local_64a8 < 0.0) {
        local_64a8 = -50.0;
      }
      else {
        local_64a8 = 50.0;
      }
    }
    FUN_00408a60();
    FUN_00408a60();
    local_24 = local_64a0;
    local_1c = local_64a8;
    FUN_005f8ce0(&local_24);
    FUN_004988c0(local_44,(undefined4)local_24,local_24._4_4_,(undefined4)local_1c,local_1c._4_4_);
    local_24 = local_64a0;
    local_1c = 0.0;
    FUN_005f8ce0(&local_24);
    FUN_004988c0(local_54,*(undefined4 *)(local_6498 + 0x1350),*(undefined4 *)(local_6498 + 0x1354),
                 *(undefined4 *)(local_6498 + 0x1358),*(undefined4 *)(local_6498 + 0x135c));
    FUN_004988c0(local_64,(undefined4)local_24,local_24._4_4_,(undefined4)local_1c,local_1c._4_4_);
    FUN_00450b70(local_64c4,*(undefined4 *)(local_6498 + 4),local_6498 + 0x11a8);
    FUN_004988c0(local_74,local_34,local_30,local_2c,local_28);
    FUN_004988c0(local_84,(undefined4)local_24,local_24._4_4_,(undefined4)local_1c,local_1c._4_4_);
    FUN_00450b70(local_64c4,*(undefined4 *)(local_6498 + 4),local_6498 + 0x1210);
    local_24 = 0.0;
    local_1c = local_64a8;
    FUN_005f8ce0(&local_24);
    FUN_004988c0(local_94,*(undefined4 *)(local_6498 + 0x1350),*(undefined4 *)(local_6498 + 0x1354),
                 *(undefined4 *)(local_6498 + 0x1358),*(undefined4 *)(local_6498 + 0x135c));
    FUN_004988c0(local_a4,(undefined4)local_24,local_24._4_4_,(undefined4)local_1c,local_1c._4_4_);
    FUN_00450b70(local_64c4,*(undefined4 *)(local_6498 + 4),local_6498 + 0x1278);
    FUN_004988c0(local_b4,(undefined4)local_24,local_24._4_4_,(undefined4)local_1c,local_1c._4_4_);
    FUN_004988c0(local_c4,local_34,local_30,local_2c,local_28);
    FUN_00450b70(local_64c4,*(undefined4 *)(local_6498 + 4),local_6498 + 0x12e0);
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
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKage2[3] */
/* 0069ac30  FUN_0069ac30  2187 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0069acd8) */

void FUN_0069ac30(void)

{
  undefined4 uVar1;
  undefined4 local_6630;
  undefined1 *puStack_662c;
  wchar_t *pwStack_6628;
  undefined8 uStack_6624;
  uint uStack_661c;
  undefined1 local_6614 [20];
  undefined8 local_6600;
  undefined8 local_65f8;
  undefined1 *local_65f0;
  undefined8 local_65ec;
  undefined8 local_65e4;
  double local_65dc;
  undefined4 local_65d0;
  undefined4 local_65c8;
  undefined4 local_65c0;
  undefined4 local_65b8;
  undefined4 local_65b4;
  int local_65b0;
  undefined4 local_65ac;
  undefined4 local_65a8;
  undefined4 local_65a4;
  int local_65a0;
  int local_659c;
  int local_6598;
  int *local_6594;
  undefined1 local_1c0 [408];
  undefined2 local_28 [10];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093bbcb;
  local_10 = ExceptionList;
  uStack_661c = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uStack_6624 = (double)CONCAT44(0x69ac71,(undefined4)uStack_6624);
  local_14 = uStack_661c;
  FUN_00446aa0();
  local_8 = 0;
  uStack_6624 = (double)CONCAT44(local_6594[1],0x69ac8d);
  FUN_0079dea2();
  local_8._0_1_ = 1;
  local_65ac = 0;
  local_65a8 = 0;
  local_65ec = 0x3ff0000000000000;
  local_65a0 = 0;
  local_65a4 = 0;
  local_28[0] = 0;
  local_65e4 = *(undefined8 *)(local_6594[1] + 0x83b0);
  if (local_6594[0x545] != 0) {
    local_65e4 = *(undefined8 *)(local_6594[1] + 0x83b8);
  }
  local_6600 = *(undefined8 *)(local_6594[1] + 0x83c0);
  local_65f8 = *(undefined8 *)(local_6594[1] + 0x83c8);
  local_65b4 = *(undefined4 *)(local_6594[1] + 0x83d0);
  *(undefined4 *)(local_6594[0x544] + 0x4a524) = *(undefined4 *)(local_6594[1] + 0x83d8);
  for (local_6598 = 0; local_6598 < 0x10; local_6598 = local_6598 + 1) {
    if (local_6594[local_6598 + 0x2e] != *(int *)(local_6594[1] + 0x242c + local_6598 * 4)) {
      local_6594[0x566] = 0;
    }
    local_6594[local_6598 + 0x2e] = *(int *)(local_6594[1] + 0x242c + local_6598 * 4);
    for (local_659c = 0; local_659c < 0x10; local_659c = local_659c + 1) {
      if (local_6594[local_6598 * 0x20 + local_659c + 0x4e] !=
          *(int *)(local_6594[1] + 0x182c + local_6598 * 0x40 + local_659c * 4)) {
        local_6594[0x566] = 0;
      }
      local_6594[local_6598 * 0x20 + local_659c + 0x4e] =
           *(int *)(local_6594[1] + 0x182c + local_6598 * 0x40 + local_659c * 4);
    }
  }
  if ((*(double *)(local_6594 + 0x44e) !=
       *(double *)(local_6594[1] + 0x2578 + *(int *)(local_6594[1] + 0x256c) * 8)) ||
     (local_6594[0x450] != *(int *)(local_6594[1] + 0x3020))) {
    local_6594[0x566] = 0;
    *(undefined8 *)(local_6594 + 0x44e) =
         *(undefined8 *)(local_6594[1] + 0x2578 + *(int *)(local_6594[1] + 0x256c) * 8);
    local_6594[0x450] = *(int *)(local_6594[1] + 0x3020);
  }
  if (local_6594[0x566] == 0) {
    local_6594[0x2a] = 10;
    uStack_6624 = (double)CONCAT44(0x69afbf,(undefined4)uStack_6624);
    FUN_00699150();
    local_6594[0x2a] = 0;
    uStack_6624 = 0.0;
    pwStack_6628 = *(wchar_t **)(local_6594[1] + 0x8f28);
    puStack_662c = *(undefined1 **)(local_6594[1] + 0x8f24);
    local_6630 = 0x15a6;
    FUN_005168b0();
    uStack_6624 = (double)CONCAT44(local_28,local_6594[0x545]);
    pwStack_6628 = (wchar_t *)&local_65ec;
    local_6630 = (undefined4)local_65e4;
    puStack_662c = (undefined1 *)((ulonglong)local_65e4 >> 0x20);
    local_65a0 = FUN_00542310();
    if (local_65a0 < 1) {
      local_8 = (uint)local_8._1_3_ << 8;
      uStack_6624 = (double)CONCAT44(0x69b062,(undefined4)uStack_6624);
      FUN_0079dfff();
      local_8 = 0xffffffff;
      uStack_6624 = (double)CONCAT44(0x69b074,(undefined4)uStack_6624);
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    uStack_6624 = (double)CONCAT44(0x69b084,(undefined4)uStack_6624);
    FUN_0069b4c0();
    uStack_6624 = (double)CONCAT44(local_28,local_6594[0x545]);
    pwStack_6628 = (wchar_t *)local_65b4;
    local_6630 = (undefined4)local_65ec;
    puStack_662c = (undefined1 *)((ulonglong)local_65ec >> 0x20);
    local_65b0 = FUN_0054a0b0(local_6594[0x451],local_6594 + 0x452,local_6594 + 0x45e,local_65ac,
                              local_65a8,local_6600,local_65f8,local_65a0);
    uStack_6624 = (double)CONCAT44(0x69b12c,(undefined4)uStack_6624);
    FUN_004fb9f0();
    uStack_6624 = (double)CONCAT44(0x69b137,(undefined4)uStack_6624);
    FUN_00699150();
    if (local_65b0 < 0) {
      uStack_6624 = (double)CONCAT44(0x69b14b,(undefined4)uStack_6624);
      FUN_00699150();
      if (local_65b0 != -100) {
        uStack_6624 = 0.0;
        pwStack_6628 = *(wchar_t **)(local_6594[1] + 0x8f28);
        puStack_662c = *(undefined1 **)(local_6594[1] + 0x8f24);
        local_6630 = 0x1455;
        FUN_005168b0();
      }
      local_8 = (uint)local_8._1_3_ << 8;
      uStack_6624 = (double)CONCAT44(0x69b191,(undefined4)uStack_6624);
      FUN_0079dfff();
      local_8 = 0xffffffff;
      uStack_6624 = (double)CONCAT44(0x69b1a3,(undefined4)uStack_6624);
      FUN_00447100();
      ExceptionList = local_10;
      return;
    }
    local_6594[0x566] = 1;
  }
  uStack_6624 = (double)CONCAT44(local_6594[1],local_6614);
  pwStack_6628 = L"䖍僜趋驰\xffff醋ᔔ";
  FUN_0044dd90();
  uStack_6624 = (double)CONCAT44(local_28,local_6594[0x545]);
  puStack_662c = (undefined1 *)*(undefined8 *)(local_6594 + 0x562);
  pwStack_6628 = (wchar_t *)((ulonglong)*(undefined8 *)(local_6594 + 0x562) >> 0x20);
  local_6630 = (undefined4)((ulonglong)*(undefined8 *)(local_6594 + 0x560) >> 0x20);
  FUN_00546600((int)*(undefined8 *)(local_6594 + 0x560));
  local_6594[0x2d] = local_6594[0x2d] + 1;
  uStack_6624 = (double)CONCAT44(0x69b250,(undefined4)uStack_6624);
  (**(code **)(*local_6594 + 0x20))();
  uStack_6624 = (double)CONCAT44(&DAT_0095bca0,local_6594 + 0x4dc);
  pwStack_6628 = L"쒃栈ᑾ";
  FUN_0058d540();
  uStack_6624 = 1.11319933417817e-310;
  local_65b8 = FUN_005977f0();
  uStack_6624 = (double)CONCAT44(0x69b28b,(undefined4)uStack_6624);
  uVar1 = FUN_00404920();
  uStack_6624 = (double)CONCAT44(uVar1,local_6594 + 0x4dc);
  pwStack_6628 = 
  L"쒃贈䢍ﾚ\xe8ff铄ￖ굨\x18贀䂍ﾚ\xe8ff씴￯薉驄\xffff趋驄\xffff叨횖僿薋驰\xffff瀅\x13倀燨ﱝ菿ࣄ趍驀\xffff菨횔诿炍ﾚ诿႑\x15\xf200ဏ뢂Ҥ\xf200帏\x2005镛\xf200ᄏ⢅ﾚ\xf2ffဏ뀅閦昀⼏⢅ﾚ盿\xf210ဏ뀅閦\xf200ᄏ⢅ﾚ菿࣬࿲蔐騨\xffff࿲Б栤鐔\x97薍﹄\xffff\xe850ꁬ\xfffe쒃贐䒍\xfffe凿開驰\xffff슁፰"
  ;
  FUN_00661050();
  uStack_6624 = (double)CONCAT44(0x69b2ac,(undefined4)uStack_6624);
  FUN_00404770();
  uStack_6624 = 1.34046508339381e-310;
  local_65c0 = FUN_005977f0();
  uStack_6624 = (double)CONCAT44(0x69b2cd,(undefined4)uStack_6624);
  uVar1 = FUN_00404920();
  uStack_6624 = (double)CONCAT44(uVar1,local_6594 + 0x4dc);
  pwStack_6628 = L"쒃贈䂍ﾚ\xe8ff钃ￖ趋驰\xffff醋ᔐ";
  FUN_00661050();
  uStack_6624 = (double)CONCAT44(0x69b2ed,(undefined4)uStack_6624);
  FUN_00404770();
  local_65dc = *(double *)(local_6594[0x544] + 0x4a4b8) / 1000.0;
  if (local_65dc < 0.01) {
    local_65dc = 0.01;
  }
  uStack_6624 = local_65dc;
  pwStack_6628 = L" : %.2lfm ";
  puStack_662c = local_1c0;
  local_6630 = 0x69b354;
  FUN_006853c0();
  uStack_6624 = (double)CONCAT44(local_1c0,local_6594 + 0x4dc);
  pwStack_6628 = L"쒃栈벤\x95薋驰\xffff瀅\x13倀쟨ﱜ菿ࣄ趋驰\xffff솁፰";
  FUN_00661050();
  uStack_6624 = (double)CONCAT44(&DAT_0095bca4,local_6594 + 0x4dc);
  pwStack_6628 = L"쒃謈炍ﾚ臿烁\x13儀開驰\xffff슁ᑀ";
  FUN_00661050();
  uStack_6624 = (double)CONCAT44(local_6594 + 0x4dc,local_6594 + 0x510);
  pwStack_6628 = L"쒃栈ᒴ";
  FUN_0058d540();
  uStack_6624 = 1.12465811146539e-310;
  local_65c8 = FUN_005977f0();
  uStack_6624 = (double)CONCAT44(0x69b3cf,(undefined4)uStack_6624);
  uVar1 = FUN_00404920();
  uStack_6624 = (double)CONCAT44(uVar1,local_6594 + 0x510);
  pwStack_6628 = 
  L"쒃贈㢍ﾚ\xe8ff鎁ￖ왨\x14贀ろﾚ\xe8ff쏱￯薉騴\xffff趋騴\xffffშ횕僿趋驰\xffff솁ᑀ"
  ;
  FUN_00661050();
  uStack_6624 = (double)CONCAT44(0x69b3ef,(undefined4)uStack_6624);
  FUN_00404770();
  uStack_6624 = 1.12847770389234e-310;
  local_65d0 = FUN_005977f0();
  uStack_6624 = (double)CONCAT44(0x69b410,(undefined4)uStack_6624);
  uVar1 = FUN_00404920();
  uStack_6624 = (double)CONCAT44(uVar1,local_6594 + 0x510);
  pwStack_6628 = L"쒃贈ろﾚ\xe8ff錿ￖjj開驰\xffff䊋謄⢈\x8f儀邋輤";
  FUN_00661050();
  uStack_6624 = (double)CONCAT44(0x69b431,(undefined4)uStack_6624);
  FUN_00404770();
  uStack_6624 = 0.0;
  local_6630 = *(undefined4 *)(local_6594[1] + 0x8f28);
  puStack_662c = *(undefined1 **)(local_6594[1] + 0x8f24);
  local_65f0 = (undefined1 *)&local_6630;
  pwStack_6628 = (wchar_t *)local_6630;
  CStringT<>(local_6594 + 0x510);
  FUN_00516ac0();
  uStack_6624 = (double)CONCAT44(0x69b479,(undefined4)uStack_6624);
  FUN_00404c80();
  uStack_6624 = (double)CONCAT44(0x69b480,(undefined4)uStack_6624);
  FUN_0056d7d0();
  local_8 = (uint)local_8._1_3_ << 8;
  uStack_6624 = (double)CONCAT44(0x69b48f,(undefined4)uStack_6624);
  FUN_0079dfff();
  local_8 = 0xffffffff;
  uStack_6624 = (double)CONCAT44(0x69b4a1,(undefined4)uStack_6624);
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



