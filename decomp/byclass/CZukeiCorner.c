/* CZukeiCorner -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiCorner[1] */
/* 00634170  FUN_00634170  68 bytes, 0 callers */

undefined4 FUN_00634170(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_006340b0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa058);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiCorner[6] */
/* 006341c0  FUN_006341c0  88 bytes, 0 callers */

void FUN_006341c0(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8ebc) = 0;
  if (*(int *)(in_ECX + 0xa038) < 1) {
    FUN_00635ae0();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
  }
  else {
    *(int *)(in_ECX + 0xa038) = *(int *)(in_ECX + 0xa038) + -1;
  }
  return;
}




/* vtable slots: CZukeiCorner[16] */
/* 00634220  FUN_00634220  1093 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00634220(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_6410 [20];
  undefined4 local_63fc;
  undefined4 local_63f8;
  undefined4 local_63f4;
  undefined4 local_63f0;
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009378bb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_63ec = FUN_0040c0e0(local_14);
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = 0;
  FUN_00446aa0();
  local_8._0_1_ = 1;
  iVar2 = FUN_004146c0();
  if (iVar2 == 0) {
    while (0 < *(int *)(local_63e8 + 600)) {
      if (*(int *)(local_63e8 + 0x25c + *(int *)(local_63e8 + 600) * 4) != 2) {
        FUN_00634a40();
        if (*(int *)(local_63e8 + 0x25c + *(int *)(local_63e8 + 600) * 4) == 4) {
          FUN_004546a0(local_6410,*(undefined4 *)(local_63e8 + 4));
          puVar1 = (undefined4 *)(local_63e8 + 0x1228 + *(int *)(local_63e8 + 600) * 0x10);
          FUN_006365d0(4,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
        }
        else {
          FUN_006365d0(0,*(undefined4 *)(local_63e8 + 0x240),*(undefined4 *)(local_63e8 + 0x244),
                       *(undefined4 *)(local_63e8 + 0x248),*(undefined4 *)(local_63e8 + 0x24c));
        }
        FUN_00458a80(local_6410,*(undefined4 *)(local_63e8 + 4),0);
        FUN_006346d0();
        if (0 < *(int *)(local_63e8 + 600)) {
          *(int *)(local_63e8 + 600) = *(int *)(local_63e8 + 600) + -1;
        }
        FUN_00635ae0();
        *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
        local_63fc = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return local_63fc;
      }
      if (*(int *)(local_63e8 + 0x204) == 2) {
        FUN_00634a40();
        *(undefined4 *)(local_63e8 + 0x204) = 0;
        FUN_006346d0();
        puVar1 = (undefined4 *)(local_63e8 + 0x1228 + *(int *)(local_63e8 + 600) * 0x10);
        FUN_006365d0(2,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
        if (0 < *(int *)(local_63e8 + 600)) {
          *(int *)(local_63e8 + 600) = *(int *)(local_63e8 + 600) + -1;
        }
        FUN_00635ae0();
        *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
        local_63f8 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        ExceptionList = local_10;
        return local_63f8;
      }
      if (0 < *(int *)(local_63e8 + 600)) {
        *(int *)(local_63e8 + 600) = *(int *)(local_63e8 + 600) + -1;
      }
    }
    FUN_006365d0(0,*(undefined4 *)(local_63e8 + 0x240),*(undefined4 *)(local_63e8 + 0x244),
                 *(undefined4 *)(local_63e8 + 0x248),*(undefined4 *)(local_63e8 + 0x24c));
    FUN_00635ae0();
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    local_63f4 = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
    local_63f0 = local_63f4;
  }
  else {
    *(undefined4 *)(local_63e8 + 600) = 0;
    FUN_00635ae0();
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    local_63f0 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  ExceptionList = local_10;
  return local_63f0;
}




/* vtable slots: CZukeiCorner[0] */
/* 006346c0  FUN_006346c0  16 bytes, 0 callers */

undefined ** FUN_006346c0(void)

{
  return &PTR_s_CZukeiCorner_00977d0c;
}




/* vtable slots: CZukeiCorner[46] */
/* 00635b60  FUN_00635b60  309 bytes, 0 callers */

undefined4
FUN_00635b60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  int local_8;
  
  if (DAT_00a0c7c0 == 0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_8 + 4) + 0x8648)) {
      if (*(int *)(*(int *)(local_8 + 4) + 0x9078) == 0) {
        local_c = 0xffffffff;
        iVar2 = FUN_00778a40(1,&local_c,*(undefined4 *)(*(int *)(local_8 + 4) + 0x9070),param_1,
                             param_2,param_3,param_4,param_5,param_6,param_7,0xe);
        if (iVar2 != 0) {
          return 0;
        }
      }
      uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    uVar1 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiCorner[47] */
/* 00635ca0  FUN_00635ca0  309 bytes, 0 callers */

undefined4
FUN_00635ca0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_c;
  int local_8;
  
  if (DAT_00a0c7c0 == 0) {
    FUN_00404c80();
    iVar2 = FUN_004fca20();
    if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_8 + 4) + 0x8648)) {
      if (*(int *)(*(int *)(local_8 + 4) + 0x907c) == 0) {
        local_c = 0xffffffff;
        iVar2 = FUN_00778a40(2,&local_c,*(undefined4 *)(*(int *)(local_8 + 4) + 0x9074),param_1,
                             param_2,param_3,param_4,param_5,param_6,param_7,0xe);
        if (iVar2 != 0) {
          return 0;
        }
      }
      uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    uVar1 = FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return uVar1;
}




/* vtable slots: CZukeiCorner[50] */
/* 00635de0  FUN_00635de0  180 bytes, 0 callers */

void FUN_00635de0(undefined8 param_1)

{
  undefined1 *puStack_24;
  uint uStack_20;
  undefined1 *local_1c;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009200cd;
  local_10 = ExceptionList;
  uStack_20 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puStack_24 = &DAT_0095590a;
  CStringT<>();
  local_8 = 0;
  local_1c = (undefined1 *)&puStack_24;
  FUN_00403dd0();
  (**(code **)(*local_14 + 0xcc))(0,param_1,0,0,0);
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiCorner[51] */
/* 00635ea0  FUN_00635ea0  429 bytes, 0 callers */

void FUN_00635ea0(undefined4 param_1,undefined4 param_2,double param_3)

{
  int iVar1;
  int in_ECX;
  undefined8 in_stack_00000024;
  double dVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093761d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(in_ECX + 0xa03c) == 0) {
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  else {
    FUN_00404c80(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8648)) {
      if (1e-07 <= param_3) {
        FUN_00404c80();
        iVar1 = FUN_004fca20();
        switch(*(undefined4 *)(*(int *)(iVar1 + 0x1a0) + 0x548)) {
        case 0:
        case 1:
        case 2:
          FUN_00404c80(param_3);
          FUN_004fca20();
          FUN_0056fc60(param_3);
          break;
        case 3:
          dVar2 = param_3;
          FUN_00404c80(param_3,param_3);
          FUN_004fca20();
          FUN_0056fcd0(param_3,dVar2);
          break;
        case 4:
          FUN_00404c80(param_3);
          FUN_004fca20();
          FUN_0056fc60(param_3);
          *(undefined8 *)(in_ECX + 0xa048) = in_stack_00000024;
          break;
        default:
          FUN_00404c80(param_3);
          FUN_004fca20();
          FUN_0056fc60(param_3);
        }
        local_8 = 0xffffffff;
        FUN_00404540();
      }
      else {
        local_8 = 0xffffffff;
        FUN_00404540();
      }
    }
    else {
      local_8 = 0xffffffff;
      FUN_00404540();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiCorner[15] */
/* 00636070  FUN_00636070  1044 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00636070(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_6428 [20];
  undefined4 local_6414;
  undefined4 local_6410;
  undefined4 local_640c;
  int local_6408;
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009379cb;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_640c = FUN_0040c0e0(local_14);
  iVar2 = FUN_004146c0();
  if (iVar2 == 0) {
    if (*(int *)(local_6408 + 0x5148) < 1) {
      FUN_00636490(0,*(undefined4 *)(local_6408 + 0x240),*(undefined4 *)(local_6408 + 0x244),
                   *(undefined4 *)(local_6408 + 0x248),*(undefined4 *)(local_6408 + 0x24c));
      FUN_00635ae0();
      *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
      local_6410 = 0;
    }
    else {
      FUN_0079dea2(*(undefined4 *)(local_6408 + 4));
      local_8 = 0;
      FUN_00446aa0();
      local_8._0_1_ = 1;
      FUN_00634a40();
      if (*(int *)(local_6408 + 0x514c + *(int *)(local_6408 + 0x5148) * 4) == 2) {
        puVar1 = (undefined4 *)(local_6408 + 0x6118 + *(int *)(local_6408 + 0x5148) * 0x10);
        FUN_004988c0(local_34,*puVar1,puVar1[1],puVar1[2],puVar1[3]);
        *(undefined4 *)(local_6408 + 0x204) = 2;
        FUN_00636490(2,*(undefined4 *)(local_6408 + 0x220),*(undefined4 *)(local_6408 + 0x224),
                     *(undefined4 *)(local_6408 + 0x228),*(undefined4 *)(local_6408 + 0x22c));
        FUN_006346d0();
        if (0 < *(int *)(local_6408 + 0x5148)) {
          *(int *)(local_6408 + 0x5148) = *(int *)(local_6408 + 0x5148) + -1;
        }
        FUN_00635ae0();
        *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
        local_6410 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
      }
      else {
        if (*(int *)(local_6408 + 0x514c + *(int *)(local_6408 + 0x5148) * 4) == 4) {
          puVar1 = (undefined4 *)(local_6408 + 0x6118 + *(int *)(local_6408 + 0x5148) * 0x10);
          local_24 = *puVar1;
          local_20 = puVar1[1];
          local_1c = puVar1[2];
          local_18 = puVar1[3];
          FUN_004509b0(0x10,local_6428,*(undefined4 *)(local_6408 + 4),local_24,local_20,local_1c,
                       local_18);
          FUN_00636490(4,local_24,local_20,local_1c,local_18);
        }
        else {
          FUN_00636490(0,*(undefined4 *)(local_6408 + 0x240),*(undefined4 *)(local_6408 + 0x244),
                       *(undefined4 *)(local_6408 + 0x248),*(undefined4 *)(local_6408 + 0x24c));
        }
        if (0 < *(int *)(local_6408 + 0x5148)) {
          *(int *)(local_6408 + 0x5148) = *(int *)(local_6408 + 0x5148) + -1;
        }
        FUN_00453bd0(local_6428,*(undefined4 *)(local_6408 + 4),0);
        FUN_006346d0();
        FUN_00635ae0();
        *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
        local_6414 = 1;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00447100();
        local_8 = 0xffffffff;
        FUN_0079dfff();
        local_6410 = local_6414;
      }
    }
  }
  else {
    *(undefined4 *)(local_6408 + 0x5148) = 0;
    FUN_00635ae0();
    *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8560) = 0;
    local_6410 = 1;
  }
  ExceptionList = local_10;
  return local_6410;
}




/* vtable slots: CZukeiCorner[10] */
/* 00636760  FUN_00636760  472 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00636760(void)

{
  int iVar1;
  int in_ECX;
  undefined1 local_34 [16];
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937a1b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(*(int *)(in_ECX + 4) + 0x9068) != 0) {
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8._0_1_ = 1;
    iVar1 = *(int *)(in_ECX + 4);
    local_24 = *(undefined4 *)(iVar1 + 0x8f68);
    local_20 = *(undefined4 *)(iVar1 + 0x8f6c);
    local_1c = *(undefined4 *)(iVar1 + 0x8f70);
    local_18 = *(undefined4 *)(iVar1 + 0x8f74);
    if (*(int *)(in_ECX + 0x204) == 0) {
      FUN_004988c0(local_34,local_24,local_20,local_1c,local_18);
      *(undefined4 *)(in_ECX + 0x204) = 2;
      iVar1 = FUN_006346d0();
      if (iVar1 == 0) {
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
      FUN_00636490(2,*(undefined4 *)(in_ECX + 0x220),*(undefined4 *)(in_ECX + 0x224),
                   *(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c));
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b0) = 0;
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x85b4) = 0;
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  FUN_00635ae0();
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiCorner[9] */
/* 00636b10  FUN_00636b10  968 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00636b10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937a9b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xa040) = 0;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8._0_1_ = 1;
  if (*(int *)(in_ECX + 0x204) == 0) {
    FUN_00634a40();
    *(undefined4 *)(in_ECX + 0x204) = 2;
    FUN_004988c0(local_24,param_2,param_3,param_4,param_5);
    iVar2 = FUN_006346d0();
    if (iVar2 == 0) {
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      FUN_00636490(2,*(undefined4 *)(in_ECX + 0x220),*(undefined4 *)(in_ECX + 0x224),
                   *(undefined4 *)(in_ECX + 0x228),*(undefined4 *)(in_ECX + 0x22c));
      FUN_00635ae0();
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  else {
    if (*(int *)(in_ECX + 0x204) == 2) {
      *(undefined4 *)(in_ECX + 0xa040) = 0;
      if ((DAT_00a0cc6c != 0) || (DAT_00a0cc74 != 0)) {
        *(undefined4 *)(in_ECX + 0xa040) = 1;
      }
      uVar1 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0x82bc);
      if (*(int *)(*(int *)(in_ECX + 4) + 0x82bc) == 0) {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x82bc) = 1;
      }
      else {
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x82bc) = 0;
      }
      iVar2 = FUN_0044a270(3,*(undefined4 *)(in_ECX + 4),&param_2,in_ECX + 0x1fc,0);
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0x82bc) = uVar1;
      if (iVar2 != 0) {
        iVar2 = FUN_0063aa60(*(undefined4 *)(in_ECX + 0x1fc));
        if (iVar2 != 0) {
          *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return 0;
        }
        *(undefined4 *)(in_ECX + 0x204) = 3;
        FUN_00635ae0();
        *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_0079dfff();
        local_8 = 0xffffffff;
        FUN_00447100();
        ExceptionList = local_10;
        return 1;
      }
    }
    DAT_00a0cc74 = 0;
    DAT_00a0cc6c = 0;
    FUN_00635ae0();
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 0;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CZukeiCorner[11] */
/* 00636ee0  FUN_00636ee0  1203 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00636ee0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_6444 [20];
  undefined4 local_6430;
  undefined4 local_642c;
  int local_6428;
  undefined1 local_54 [32];
  undefined1 local_34 [32];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937af6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_00464040();
  local_8._0_1_ = 1;
  FUN_0079dea2(*(undefined4 *)(local_6428 + 4));
  local_8._0_1_ = 2;
  iVar1 = FUN_0044a270(3,*(undefined4 *)(local_6428 + 4),&stack0x00000008,local_6428 + 0x200,0);
  if (iVar1 != 0) {
    if (*(int *)(local_6428 + 0x204) == 2) {
      FUN_00634a40();
      puVar2 = (undefined4 *)
               CMFCCaptionButtonEx::GetRect(*(CMFCCaptionButtonEx **)(local_6428 + 0x200));
      FUN_004988c0(local_34,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
      FUN_00470200(*(undefined4 *)(local_6428 + 4),*(undefined4 *)(local_6428 + 0x200),
                   *(undefined4 *)(local_6428 + 0x210),*(undefined4 *)(local_6428 + 0x214),
                   *(undefined4 *)(local_6428 + 0x218),*(undefined4 *)(local_6428 + 0x21c),
                   *(undefined4 *)(local_6428 + 0x210),*(undefined4 *)(local_6428 + 0x214),
                   *(undefined4 *)(local_6428 + 0x218),*(undefined4 *)(local_6428 + 0x21c));
      FUN_00636490(4,*(undefined4 *)(local_6428 + 0x210),*(undefined4 *)(local_6428 + 0x214),
                   *(undefined4 *)(local_6428 + 0x218),*(undefined4 *)(local_6428 + 0x21c));
      FUN_004509b0(0x10,local_6444,*(undefined4 *)(local_6428 + 4),
                   *(undefined4 *)(local_6428 + 0x210),*(undefined4 *)(local_6428 + 0x214),
                   *(undefined4 *)(local_6428 + 0x218),*(undefined4 *)(local_6428 + 0x21c));
      FUN_006346d0();
      FUN_00635ae0();
      *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
      local_642c = 0;
      local_8._0_1_ = 1;
      FUN_0079dfff();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_004640a0();
      local_8 = 0xffffffff;
      FUN_00447100();
      ExceptionList = local_10;
      return local_642c;
    }
    puVar2 = (undefined4 *)
             CMFCCaptionButtonEx::GetRect(*(CMFCCaptionButtonEx **)(local_6428 + 0x200));
    FUN_004988c0(local_54,*puVar2,puVar2[1],puVar2[2],puVar2[3]);
    if (*(int *)(local_6428 + 0xa03c) == 0) {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6428 + 4) + 0x862c)) {
        FUN_00404c80();
        FUN_004fca20();
        FUN_004cacd0();
      }
    }
    else {
      FUN_00404c80();
      iVar1 = FUN_004fca20();
      if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_6428 + 4) + 0x8648)) {
        FUN_00404c80();
        FUN_004fca20();
        FUN_0056fd50();
      }
    }
    FUN_00634a40();
    FUN_00470200(*(undefined4 *)(local_6428 + 4),*(undefined4 *)(local_6428 + 0x200),
                 *(undefined4 *)(local_6428 + 0x210),*(undefined4 *)(local_6428 + 0x214),
                 *(undefined4 *)(local_6428 + 0x218),*(undefined4 *)(local_6428 + 0x21c),
                 *(undefined4 *)(local_6428 + 0x210),*(undefined4 *)(local_6428 + 0x214),
                 *(undefined4 *)(local_6428 + 0x218),*(undefined4 *)(local_6428 + 0x21c));
    FUN_004509b0(0x10,local_6444,*(undefined4 *)(local_6428 + 4),*(undefined4 *)(local_6428 + 0x210)
                 ,*(undefined4 *)(local_6428 + 0x214),*(undefined4 *)(local_6428 + 0x218),
                 *(undefined4 *)(local_6428 + 0x21c));
    FUN_006346d0();
    FUN_00636490(4,*(undefined4 *)(local_6428 + 0x210),*(undefined4 *)(local_6428 + 0x214),
                 *(undefined4 *)(local_6428 + 0x218),*(undefined4 *)(local_6428 + 0x21c));
  }
  DAT_00a0cc74 = 0;
  DAT_00a0cc6c = 0;
  FUN_00635ae0();
  *(undefined4 *)(*(int *)(local_6428 + 4) + 0x8560) = 0;
  local_6430 = 0;
  local_8._0_1_ = 1;
  FUN_0079dfff();
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_004640a0();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return local_6430;
}




/* vtable slots: CZukeiCorner[4] */
/* 006373a0  FUN_006373a0  319 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006373a0(void)

{
  int iVar1;
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
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0044c830(local_63fc,*(undefined4 *)(local_63e8 + 4));
  if (*(int *)(local_63e8 + 0xa03c) == 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x862c)) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_004cacd0();
    }
  }
  else {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(local_63e8 + 4) + 0x8648)) {
      FUN_00404c80();
      FUN_004fca20();
      FUN_0056fd50();
    }
  }
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiCorner[3] */
/* 006374e0  FUN_006374e0  720 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006374e0(void)

{
  uint uVar1;
  int iVar2;
  undefined1 local_6400 [23];
  CWaitCursor local_63e9;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937b51;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_004fb910(0);
  CWaitCursor::CWaitCursor(&local_63e9);
  local_8 = 0;
  if (*(int *)(local_63e8 + 0xa03c) == 0) {
    FUN_00446aa0(uVar1);
    local_8._0_1_ = 1;
    FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
    local_8._0_1_ = 2;
    FUN_00634a40();
    FUN_0044dd90(local_6400,*(undefined4 *)(local_63e8 + 4));
    FUN_0044c830(local_6400,*(undefined4 *)(local_63e8 + 4));
    FUN_00464040();
    local_8._0_1_ = 3;
    FUN_0046abe0(*(undefined4 *)(local_63e8 + 4),*(undefined4 *)(local_63e8 + 0x1f8),
                 *(undefined4 *)(local_63e8 + 0x1fc));
    *(undefined4 *)(local_63e8 + 0x204) = 0;
    FUN_006346d0();
    FUN_00636490(0,*(undefined4 *)(local_63e8 + 0x240),*(undefined4 *)(local_63e8 + 0x244),
                 *(undefined4 *)(local_63e8 + 0x248),*(undefined4 *)(local_63e8 + 0x24c));
    FUN_00635ae0();
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    local_8._0_1_ = 2;
    FUN_004640a0();
    local_8._0_1_ = 1;
    FUN_0079dfff();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_00408b00();
  }
  else {
    FUN_00634a40();
    iVar2 = FUN_00634b70(*(undefined4 *)(local_63e8 + 0x1f8),*(undefined4 *)(local_63e8 + 0x1fc));
    if (iVar2 == 0) {
      *(undefined4 *)(local_63e8 + 0x204) = 2;
      FUN_005168b0(0x1455,*(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f24),
                   *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8f28),0,0);
    }
    else {
      *(undefined4 *)(local_63e8 + 0x204) = 0;
      FUN_00636490(0,*(undefined4 *)(local_63e8 + 0x240),*(undefined4 *)(local_63e8 + 0x244),
                   *(undefined4 *)(local_63e8 + 0x248),*(undefined4 *)(local_63e8 + 0x24c));
    }
    FUN_006346d0();
    FUN_00635ae0();
    *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
    local_8 = 0xffffffff;
    FUN_00408b00();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiCorner[29], CZukeiGazou[29], CZukeiHouraku[29], CZukeiParametric[29], CZukeiSentaku[29], CZukeiShinshuku[29], CZukeiZukeiToroku[29] */
/* 006fb760  FUN_006fb760  1092 bytes, 10 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006fb760(void)

{
  undefined8 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int local_6420;
  int local_641c;
  int local_6418;
  uint local_6414;
  int *local_6410;
  int *local_640c;
  int local_6408;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093f426;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  local_6408 = in_ECX;
  FUN_004fb9f0(local_14);
  FUN_0040c0e0();
  FUN_0079dea2();
  local_8 = 0;
  FUN_00446aa0();
  local_8._0_1_ = 1;
  FUN_004b75a0();
  local_6410 = (int *)0x0;
  local_640c = (int *)0x0;
  local_6418 = *(int *)(local_6408 + 4);
  if (local_6418 == 0) {
    local_641c = 0;
  }
  else {
    local_641c = local_6418 + 0x88;
  }
  iVar4 = FUN_0044fcd0();
  if (iVar4 == 0) {
    FUN_00454900();
    FUN_00464040();
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00408a30(0,0);
    uVar3 = DAT_00a0cb5c;
    uVar2 = DAT_00a0cb58;
    DAT_00a0cb58 = 0;
    DAT_00a0cb5c = 0;
    local_6420 = FUN_00572b10();
    while ((local_6420 != 0 &&
           (local_6410 = (int *)FUN_00572b30(&local_6420,0), local_6410 != (int *)0x0))) {
      local_640c = (int *)FUN_00450d50(*(undefined4 *)(local_6408 + 4),local_6410);
      (**(code **)(*local_6410 + 0x28))();
      FUN_00455380();
      FUN_004631b0();
      FUN_0040db50();
      local_640c[1] = local_6410[1];
      local_6414 = (**(code **)(*local_640c + 0x28))();
      if (0xf < local_6414) {
        local_6414 = *(uint *)(*(int *)(local_6408 + 4) + 0x256c);
        FUN_00455380();
      }
      FUN_0046bdf0(local_34,local_30,local_2c,local_28,local_640c,local_24,local_20,local_1c,
                   local_18,0,0);
      uVar1 = *(undefined8 *)(*(int *)(local_6408 + 4) + 0x2578 + local_6414 * 8);
      FUN_00465c40(0,local_24,local_20,local_1c,local_18,local_640c,uVar1,uVar1);
    }
    DAT_00a0cb58 = uVar2;
    DAT_00a0cb5c = uVar3;
    FUN_005168b0(0x2736,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
                 *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
    local_8._0_1_ = 1;
    FUN_004640a0();
  }
  else {
    FUN_005168b0(0x1451,*(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f24),
                 *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8f28),0,0);
  }
  *(undefined4 *)(*(int *)(local_6408 + 4) + 0x8578) = 1;
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}



