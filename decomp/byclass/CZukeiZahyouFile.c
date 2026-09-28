/* CZukeiZahyouFile -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiZahyouFile[1] */
/* 00753040  FUN_00753040  68 bytes, 0 callers */

undefined4 FUN_00753040(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00752fd0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x590);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiZahyouFile[6] */
/* 007535c0  FUN_007535c0  412 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007535c0(undefined4 param_1)

{
  int in_ECX;
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
  local_63e8 = in_ECX;
  if (*(int *)(in_ECX + 0x1fc) != *(int *)(in_ECX + 0x200)) {
    *(undefined4 *)(in_ECX + 0x200) = *(undefined4 *)(in_ECX + 0x1fc);
    FUN_00753090(local_14);
  }
  if (*(int *)(local_63e8 + 0x1fc) == 6) {
    FUN_006f7cc0(param_1);
  }
  else if (*(int *)(local_63e8 + 0x204) == 0) {
    if (*(int *)(local_63e8 + 0x568) == 0) {
      FUN_004efbb0(0x151b,0,0);
      *(undefined4 *)(*(int *)(local_63e8 + 4) + 0x8560) = 0;
      FUN_00446aa0();
      local_8 = 0;
      FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
      local_8._0_1_ = 1;
      FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      FUN_004efbb0(0x1615,0,0);
    }
  }
  else {
    (**(code **)(**(int **)(local_63e8 + 0x204) + 0x18))(param_1);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[16] */
/* 00753760  FUN_00753760  575 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00753760(void)

{
  int in_ECX;
  undefined1 local_6410 [20];
  undefined4 local_63fc;
  undefined4 local_63f8;
  undefined4 local_63f4;
  int local_63f0;
  undefined4 local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00939d2b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + 0x8674) + 0x430) = 0;
  local_63e8 = in_ECX;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  if (*(int *)(local_63e8 + 0x568) == 0) {
    if (*(int *)(local_63e8 + 0x1fc) == 6) {
      local_63f0 = FUN_006f85c0();
      if (local_63f0 == 0) {
        *(undefined4 *)(local_63e8 + 0x1fc) = 0;
        FUN_00753090();
        FUN_00404c80();
        FUN_0056d7d0();
      }
      local_63f4 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_63ec = local_63f4;
    }
    else if (*(int *)(local_63e8 + 0x204) == 0) {
      local_63fc = 0;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_63ec = local_63fc;
    }
    else {
      *(undefined4 *)(local_63e8 + 0x1fc) = 0;
      FUN_00753090();
      FUN_00404c80();
      FUN_0056d7d0();
      local_63f8 = 1;
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
      local_63ec = local_63f8;
    }
  }
  else {
    *(undefined4 *)(local_63e8 + 0x568) = 0;
    FUN_0044de00(local_6410,*(undefined4 *)(local_63e8 + 4));
    FUN_0044c830(local_6410,*(undefined4 *)(local_63e8 + 4));
    local_63ec = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_63ec;
}




/* vtable slots: CZukeiZahyouFile[0] */
/* 00753aa0  FUN_00753aa0  16 bytes, 0 callers */

undefined ** FUN_00753aa0(void)

{
  return &PTR_s_CZukeiZahyouFile_0097b4fc;
}




/* vtable slots: CZukeiZahyouFile[23] */
/* 00753dd0  FUN_00753dd0  52 bytes, 0 callers */

undefined4 FUN_00753dd0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x204) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x204) + 0x5c))();
  }
  return uVar1;
}




/* vtable slots: CZukeiZahyouFile[46] */
/* 00753e10  FUN_00753e10  660 bytes, 0 callers */

undefined4
FUN_00753e10(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  int in_ECX;
  undefined4 local_10;
  
  if (DAT_00a0c7c0 == 0) {
    local_10 = 0;
    if (*(int *)(in_ECX + 0x1fc) == 6) {
      local_10 = FUN_006f8f10(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else if (*(int *)(in_ECX + 0x204) == 0) {
      if (*(int *)(*(int *)(in_ECX + 4) + 0x9078) == 0) {
        local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
      }
      else {
        switch(param_2) {
        case 1:
        case 0xc:
          if (param_3 == 1) {
            FUN_005168b0(0x1436,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                         *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_007545b0();
          }
          break;
        case 2:
          if (param_3 == 1) {
            FUN_005168b0(0x1433,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                         *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_007546a0();
          }
          break;
        case 3:
          if (param_3 == 1) {
            FUN_005168b0(0x1434,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                         *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_007548a0();
          }
          break;
        case 4:
          if (param_3 == 1) {
            FUN_005168b0(0x1435,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f50),
                         *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8f54),1,0);
          }
          else if (param_3 == 2) {
            FUN_00754b10();
          }
          break;
        default:
          local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        }
      }
    }
    else {
      local_10 = (**(code **)(**(int **)(in_ECX + 0x204) + 0xb8))
                           (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    local_10 = FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return local_10;
}




/* vtable slots: CZukeiZahyouFile[47] */
/* 007540d0  FUN_007540d0  270 bytes, 0 callers */

void FUN_007540d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int in_ECX;
  
  if (DAT_00a0c7c0 == 0) {
    if (*(int *)(in_ECX + 0x1fc) == 6) {
      FUN_006fa580(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else if (*(int *)(in_ECX + 0x204) == 0) {
      FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
    else {
      (**(code **)(**(int **)(in_ECX + 0x204) + 0xbc))
                (param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  else {
    FUN_0076d330(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}




/* vtable slots: CZukeiZahyouFile[34] */
/* 007541e0  FUN_007541e0  938 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007541e0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_7254 [20];
  undefined4 local_7240;
  undefined4 local_723c;
  undefined4 local_7238;
  undefined4 local_7234;
  undefined4 local_7230;
  int local_722c;
  int local_7228;
  undefined4 local_e48;
  undefined4 local_d48;
  undefined4 local_d44;
  undefined4 local_d40;
  undefined8 local_834 [104];
  undefined8 local_4f4 [104];
  undefined4 local_1b4 [104];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941cd6;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + 0x8674) + 0x430) = 0;
  local_7238 = 0xffffffff;
  local_722c = in_ECX;
  local_14 = uVar1;
  if (*(short *)(in_ECX + 0x208) != 0) {
    FUN_005f9c30();
    local_8 = 0;
    if (DAT_00a0be7c != 0) {
      local_d48 = 1;
    }
    local_7234 = 0;
    for (local_7228 = 0; local_7228 < 0x65; local_7228 = local_7228 + 1) {
      local_1b4[local_7228] = 0;
    }
    for (local_7228 = 0; local_7228 < 0x65; local_7228 = local_7228 + 1) {
      local_834[local_7228] = 0;
    }
    for (local_7228 = 0; local_7228 < 0x65; local_7228 = local_7228 + 1) {
      local_4f4[local_7228] = 0;
    }
    local_7240 = 0;
    local_723c = 0;
    if (DAT_00a0d638 != 0) {
      local_e48 = 1;
    }
    local_d40 = DAT_00a0d63c;
    local_d44 = DAT_00a0d640;
    if ((DAT_00a0cc6c != 0) || (DAT_00a0cc74 != 0)) {
      local_7234 = 1;
    }
    DAT_00a0cc74 = 0;
    DAT_00a0cc6c = 0;
    if (DAT_00a0b458 == 0) {
      local_7230 = 8;
    }
    else {
      local_7230 = 1;
    }
    local_7238 = FUN_005fa070(*(undefined4 *)(local_722c + 4),local_722c + 0x208,0,local_7234,
                              local_1b4,local_834,local_4f4,0,0,local_7230);
    local_8 = 0xffffffff;
    FUN_005f9fb0();
  }
  *(undefined4 *)(local_722c + 0x200) = 0;
  *(undefined4 *)(local_722c + 0x1fc) = 0;
  FUN_00753090(uVar1);
  FUN_00446aa0();
  local_8 = 1;
  FUN_0079dea2();
  local_8._0_1_ = 2;
  FUN_0044de00(local_7254,*(undefined4 *)(local_722c + 4));
  FUN_0044c990(*(undefined4 *)(local_722c + 4),local_7254);
  FUN_00449d60();
  puVar2 = (undefined4 *)FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
  FUN_00517640(*puVar2,puVar2[1],puVar2[2],puVar2[3]);
  FUN_00404c80();
  FUN_0056d7d0();
  FUN_007539a0();
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[35] */
/* 00754590  FUN_00754590  19 bytes, 0 callers */

void FUN_00754590(void)

{
  FUN_00755f40();
  return;
}




/* vtable slots: CZukeiZahyouFile[25] */
/* 007545b0  FUN_007545b0  236 bytes, 1 callers */

void FUN_007545b0(void)

{
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined *puStack_28;
  undefined1 *puStack_24;
  uint uStack_20;
  undefined1 *local_1c;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009200cd;
  local_10 = ExceptionList;
  uStack_20 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puStack_24 = (undefined1 *)0x7545e0;
  FUN_00753ab0();
  puStack_24 = (undefined1 *)0x7545e8;
  CStringT<>();
  local_8 = 0;
  puStack_24 = (undefined1 *)(local_14 + 0x208);
  puStack_28 = &DAT_00955904;
  puStack_2c = local_18;
  uStack_30 = 0x754606;
  FUN_004059f0();
  puStack_24 = (undefined1 *)0x0;
  puStack_28 = (undefined *)0x0;
  uStack_34 = *(undefined4 *)(*(int *)(local_14 + 4) + 0x8f28);
  uStack_30 = *(undefined4 *)(*(int *)(local_14 + 4) + 0x8f24);
  local_1c = (undefined1 *)&uStack_34;
  puStack_2c = (undefined1 *)uStack_34;
  FUN_00403dd0(local_18);
  FUN_00516ac0();
  *(undefined4 *)(local_14 + 0x200) = 0;
  *(undefined4 *)(local_14 + 0x1fc) = 0;
  puStack_24 = (undefined1 *)0x75465d;
  FUN_00753090();
  puStack_24 = local_18;
  puStack_28 = (undefined *)0x754666;
  FUN_00404c80();
  puStack_28 = (undefined *)0x75466d;
  FUN_004fca20();
  puStack_28 = (undefined *)0x75467e;
  FUN_00404860();
  local_8 = 0xffffffff;
  puStack_24 = (undefined1 *)0x75468d;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[27] */
/* 007546a0  FUN_007546a0  501 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007546a0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_644;
  int local_63c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941d1d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_005f9c30(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  *(undefined8 *)(in_ECX + 0x588) = 0;
  *(undefined8 *)(in_ECX + 0x580) = 0;
  local_63c = -1;
  if (*(short *)(in_ECX + 0x208) != 0) {
    local_63c = FUN_00601b90(in_ECX + 0x208,0,0);
  }
  if (local_63c < 0) {
    FUN_007539a0(local_63c);
    local_8 = 0xffffffff;
    FUN_005f9fb0();
  }
  else {
    FUN_004988c0(local_24,local_54,local_50,local_4c,local_48);
    *(undefined4 *)(in_ECX + 0x200) = 3;
    *(undefined4 *)(in_ECX + 0x1fc) = 3;
    FUN_00753090(uVar1);
    iVar2 = FUN_004121b0(0x278);
    local_8._0_1_ = 1;
    if (iVar2 == 0) {
      local_644 = 0;
    }
    else {
      local_644 = FUN_00756a10(*(undefined4 *)(in_ECX + 4),3);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    *(undefined4 *)(in_ECX + 0x204) = local_644;
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = 0xffffffff;
    FUN_005f9fb0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[28] */
/* 007548a0  FUN_007548a0  518 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007548a0(void)

{
  int iVar1;
  int in_ECX;
  undefined4 local_644;
  int local_63c;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941d1d;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x204) == 0) {
    FUN_005f9c30(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    local_63c = -1;
    if (*(short *)(in_ECX + 0x208) != 0) {
      local_63c = FUN_00601b90(in_ECX + 0x208,1,0);
    }
    if (local_63c < 0) {
      FUN_007539a0(local_63c);
      local_8 = 0xffffffff;
      FUN_005f9fb0();
    }
    else {
      FUN_004988c0(local_24,local_54,local_50,local_4c,local_48);
      *(undefined4 *)(in_ECX + 0x200) = 4;
      *(undefined4 *)(in_ECX + 0x1fc) = 4;
      FUN_00753090();
      iVar1 = FUN_004121b0(0x278);
      local_8._0_1_ = 1;
      if (iVar1 == 0) {
        local_644 = 0;
      }
      else {
        local_644 = FUN_00756a10(*(undefined4 *)(in_ECX + 4),3);
      }
      local_8 = (uint)local_8._1_3_ << 8;
      *(undefined4 *)(in_ECX + 0x204) = local_644;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = 0xffffffff;
      FUN_005f9fb0();
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x204) + 0x70))(local_14);
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[29] */
/* 00754ab0  FUN_00754ab0  84 bytes, 0 callers */

void FUN_00754ab0(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_00404c80();
  iVar1 = FUN_004fca20();
  if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8614)) {
    DAT_00a0d638 = (uint)(DAT_00a0d638 == 0);
    FUN_00755f40();
  }
  return;
}




/* vtable slots: CZukeiZahyouFile[30] */
/* 00754b10  FUN_00754b10  503 bytes, 1 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00754b10(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined1 local_640c [20];
  int local_63f8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a30b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x1fc) == 6) {
    FUN_006fbbb0();
  }
  else {
    local_63f8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2();
    local_8._0_1_ = 1;
    FUN_0044de00(local_640c,*(undefined4 *)(local_63f8 + 4));
    FUN_0044c990(*(undefined4 *)(local_63f8 + 4),local_640c);
    FUN_00449d60();
    puVar1 = (undefined4 *)FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
    FUN_00517640(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    *(undefined4 *)(local_63f8 + 0x200) = 6;
    *(undefined4 *)(local_63f8 + 0x1fc) = 6;
    if (DAT_00a0d638 == 0) {
      *(undefined4 *)(*(int *)(*(int *)(local_63f8 + 4) + 0x8674) + 0x430) = 0;
    }
    else {
      *(undefined4 *)(*(int *)(*(int *)(local_63f8 + 4) + 0x8674) + 0x430) = 1;
    }
    FUN_00753090();
    *(undefined4 *)(local_63f8 + 0xc) = 0;
    DAT_00a0cc74 = 0;
    DAT_00a0cc6c = 0;
    FUN_00404c80();
    FUN_0056d7d0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[31] */
/* 00754d10  FUN_00754d10  751 bytes, 0 callers */

void FUN_00754d10(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined1 *puStack_f4;
  undefined *puStack_f0;
  undefined1 *puStack_ec;
  uint uStack_e8;
  undefined1 local_3c [4];
  int local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  undefined1 *local_1c;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941d68;
  local_10 = ExceptionList;
  uStack_e8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  DAT_00a0be7c = 1;
  if ((DAT_00a0be80 < 0) || (6 < DAT_00a0be80)) {
    DAT_00a0be80 = 6;
  }
  if ((DAT_00a0be84 < 0) || (6 < DAT_00a0be84)) {
    DAT_00a0be84 = 6;
  }
  puStack_ec = *(undefined1 **)(in_ECX + 4);
  puStack_f0 = (undefined *)0x754d8f;
  local_14 = in_ECX;
  FUN_00607760();
  local_8 = 0;
  puStack_ec = (undefined1 *)(local_14 + 0x208);
  puStack_f0 = (undefined *)0x754da8;
  FUN_00404900();
  local_38 = DAT_00a0be80;
  local_34 = DAT_00a0be84;
  local_30 = (uint)(DAT_00a0d638 != 0);
  local_2c = (uint)(DAT_00a0d63c != 0);
  local_28 = (uint)(DAT_00a0d640 != 0);
  local_24 = (uint)(DAT_00a0be88 != 0);
  local_20 = (uint)(DAT_00a0be8c != 0);
  puStack_ec = (undefined1 *)0x754e41;
  iVar1 = FUN_0079850d();
  if (iVar1 == 1) {
    puStack_ec = (undefined1 *)0x754e52;
    puStack_ec = (undefined1 *)FUN_00404920();
    puStack_f0 = (undefined *)(local_14 + 0x208);
    puStack_f4 = (undefined1 *)0x754e62;
    FUN_005b0570();
    puStack_ec = (undefined1 *)0x0;
    puStack_f0 = (undefined *)0x754e6f;
    FUN_007539a0();
    puStack_ec = local_3c;
    puStack_f0 = (undefined *)0x754e78;
    FUN_00404c80();
    puStack_f0 = (undefined *)0x754e7f;
    FUN_004fca20();
    puStack_f0 = (undefined *)0x754e90;
    FUN_00404860();
    DAT_00a0be80 = local_38;
    DAT_00a0be84 = local_34;
    DAT_00a0d638 = (uint)(local_30 != 0);
    DAT_00a0d63c = (uint)(local_2c != 0);
    DAT_00a0d640 = (uint)(local_28 != 0);
    DAT_00a0be88 = (uint)(local_24 != 0);
    DAT_00a0be8c = (uint)(local_20 != 0);
    puStack_ec = (undefined1 *)0x754f36;
    FUN_00755f40();
  }
  if ((DAT_00a0be80 < 0) || (5 < DAT_00a0be80)) {
    DAT_00a0be80 = -1;
  }
  if ((DAT_00a0be84 < 0) || (5 < DAT_00a0be84)) {
    DAT_00a0be84 = -1;
  }
  puStack_ec = (undefined1 *)0x754f73;
  FUN_00404c80();
  puStack_ec = (undefined1 *)0x754f7a;
  FUN_0056d7d0();
  puStack_ec = (undefined1 *)0x754f82;
  CStringT<>();
  local_8._0_1_ = 1;
  puStack_ec = (undefined1 *)(local_14 + 0x208);
  puStack_f0 = &DAT_00955904;
  puStack_f4 = local_18;
  uStack_f8 = 0x754f9d;
  FUN_004059f0();
  puStack_ec = (undefined1 *)0x0;
  puStack_f0 = (undefined *)0x0;
  uStack_fc = *(undefined4 *)(*(int *)(local_14 + 4) + 0x8f28);
  uStack_f8 = *(undefined4 *)(*(int *)(local_14 + 4) + 0x8f24);
  local_1c = (undefined1 *)&uStack_fc;
  puStack_f4 = (undefined1 *)uStack_fc;
  FUN_00403dd0(local_18);
  FUN_00516ac0();
  local_8 = (uint)local_8._1_3_ << 8;
  puStack_ec = (undefined1 *)0x754fde;
  FUN_00404540();
  local_8 = 0xffffffff;
  puStack_ec = (undefined1 *)0x754ff0;
  FUN_004aa7a0();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[32] */
/* 00755000  FUN_00755000  662 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x00755097) */
/* WARNING: Removing unreachable block (ram,0x007550e9) */

void FUN_00755000(void)

{
  int iVar1;
  undefined1 local_bfc [4];
  undefined4 local_bf8;
  FILE *local_bf0;
  undefined1 *local_bec;
  undefined1 *puStack_be8;
  undefined4 uStack_be4;
  undefined1 local_bdc [2008];
  undefined1 local_404 [1008];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941da0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0b458 == 0) {
    local_bf8 = 8;
  }
  else {
    local_bf8 = 1;
  }
  local_bf0 = (FILE *)FUN_004f4290();
  if (local_bf0 == (FILE *)0x0) {
    local_bf0 = (FILE *)0x0;
    local_bf0 = (FILE *)FUN_004f4290();
    if (local_bf0 == (FILE *)0x0) {
      local_bf0 = (FILE *)0x0;
      FUN_005168b0();
      ExceptionList = local_10;
      return;
    }
  }
  _fclose(local_bf0);
  local_bf0 = (FILE *)0x0;
  iVar1 = FUN_004f1700();
  if (iVar1 != 0) {
    FUN_00660fa0();
    FUN_00404920();
    FUN_004f7a90();
    local_bec = local_bdc;
    puStack_be8 = local_404;
    uStack_be4 = 0;
    FUN_00404920();
    FUN_00904dec();
    CStringT<>();
    local_8 = 0;
    FUN_004059f0();
    FUN_00403dd0(local_bfc);
    FUN_00516ac0();
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[33] */
/* 007552a0  FUN_007552a0  343 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007552a0(void)

{
  int iVar1;
  int iStack_820;
  undefined4 uStack_81c;
  undefined1 *puStack_818;
  wchar_t *pwStack_814;
  undefined1 **ppuStack_810;
  uint uStack_80c;
  undefined1 *local_808;
  undefined1 local_804 [4];
  int local_800;
  undefined1 *local_7fc;
  undefined4 uStack_7f8;
  undefined4 uStack_7f4;
  undefined1 local_7ec [2008];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941de0;
  local_10 = ExceptionList;
  uStack_80c = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  ppuStack_810 = (undefined1 **)0x1;
  pwStack_814 = L"삅յ\xf8e9";
  local_14 = uStack_80c;
  iVar1 = FUN_004f1700();
  if (iVar1 != 0) {
    ppuStack_810 = (undefined1 **)0x7552f0;
    ppuStack_810 = (undefined1 **)FUN_00404920();
    pwStack_814 = L"\"%s\"";
    puStack_818 = local_7ec;
    uStack_81c = 0x755302;
    FUN_004f7a90();
    local_7fc = local_7ec;
    uStack_7f8 = 0;
    uStack_7f4 = 0;
    ppuStack_810 = &local_7fc;
    pwStack_814 = L"橐\xe801杖\x1a쒃贌\x8d\xfff8\xe8ff\xec8aￊ䗇ü";
    pwStack_814 = (wchar_t *)FUN_00404920();
    puStack_818 = (undefined1 *)0x1;
    uStack_81c = 0x755358;
    FUN_00904dec();
    ppuStack_810 = (undefined1 **)0x755366;
    CStringT<>();
    local_8 = 0;
    ppuStack_810 = (undefined1 **)(local_800 + 0x208);
    pwStack_814 = L"%s";
    puStack_818 = local_804;
    uStack_81c = 0x75538b;
    FUN_004059f0();
    ppuStack_810 = (undefined1 **)0x0;
    pwStack_814 = (wchar_t *)0x0;
    iStack_820 = *(int *)(local_800 + 4);
    puStack_818 = *(undefined1 **)(iStack_820 + 0x8f28);
    uStack_81c = *(undefined4 *)(iStack_820 + 0x8f24);
    local_808 = (undefined1 *)&iStack_820;
    FUN_00403dd0(local_804);
    FUN_00516ac0();
    local_8 = 0xffffffff;
    ppuStack_810 = (undefined1 **)0x7553de;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[36] */
/* 00755400  FUN_00755400  269 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00755400(void)

{
  int iVar1;
  int in_ECX;
  int local_63f0;
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
    local_63f0 = 0;
  }
  else {
    local_63f0 = *(int *)(in_ECX + 4) + 0x88;
  }
  iVar1 = FUN_0044fcd0(local_63f0);
  if (iVar1 == 0) {
    FUN_00404c80();
    iVar1 = FUN_004fca20();
    if (*(int *)(iVar1 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8610)) {
      FUN_005ca990(1,0);
    }
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




/* vtable slots: CZukeiZahyouFile[49] */
/* 00755510  FUN_00755510  80 bytes, 0 callers */

void FUN_00755510(undefined8 param_1)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x1fc) != 6) && (*(int *)(in_ECX + 0x204) != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x204) + 0xc4))(param_1);
  }
  return;
}




/* vtable slots: CZukeiZahyouFile[51] */
/* 00755560  FUN_00755560  231 bytes, 0 callers */

void FUN_00755560(undefined8 param_1,undefined8 param_2,undefined8 param_3,undefined8 param_4,
                 undefined8 param_5)

{
  int in_ECX;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined1 *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093761d;
  local_10 = ExceptionList;
  uStack_1c = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if (*(int *)(in_ECX + 0x1fc) == 6) {
    local_8 = 0xffffffff;
    uStack_20 = 0x7555aa;
    FUN_00404540();
  }
  else {
    if (*(int *)(in_ECX + 0x204) != 0) {
      local_18 = (undefined1 *)&uStack_20;
      local_14 = in_ECX;
      FUN_00403dd0();
      (**(code **)(**(int **)(local_14 + 0x204) + 0xcc))(param_1,param_2,param_3,param_4,param_5);
    }
    local_8 = 0xffffffff;
    uStack_20 = 0x755636;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[15] */
/* 00755650  FUN_00755650  52 bytes, 0 callers */

undefined4 FUN_00755650(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x204) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x204) + 0x3c))();
  }
  return uVar1;
}




/* vtable slots: CZukeiZahyouFile[9] */
/* 00755750  FUN_00755750  446 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00755750(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009309a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (in_ECX[0x7f] == 6) {
    uVar1 = FUN_006fd240(param_1,param_2,param_3,param_4,param_5);
  }
  else if (in_ECX[0x81] == 0) {
    if (in_ECX[0x15a] == 0) {
      (**(code **)(*in_ECX + 0x6c))(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
      uVar1 = 0;
    }
    else {
      FUN_00446aa0();
      local_8 = 0;
      iVar2 = FUN_00451eb0(in_ECX[1],&param_2,1);
      if (iVar2 == 0) {
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
      else {
        FUN_00756050(param_2,param_3,param_4,param_5,1,0);
        in_ECX[0x15a] = 0;
        local_8 = 0xffffffff;
        FUN_00447100();
        uVar1 = 0;
      }
    }
  }
  else {
    uVar1 = (**(code **)(*(int *)in_ECX[0x81] + 0x24))(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return uVar1;
}




/* vtable slots: CZukeiZahyouFile[11] */
/* 00755910  FUN_00755910  948 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_00755910(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  undefined1 local_cd04 [20];
  undefined4 local_ccf0;
  undefined4 local_ccec;
  undefined4 local_cce8;
  undefined4 local_cce4;
  undefined4 local_cce0;
  int local_ccdc;
  int local_ccd8;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00941e81;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_24 = param_2;
  local_20 = param_3;
  local_1c = param_4;
  local_18 = param_5;
  if (*(int *)(in_ECX + 0x1fc) == 6) {
    local_cce0 = FUN_006fda70(param_1,param_2,param_3,param_4,param_5);
  }
  else if (*(int *)(in_ECX + 0x204) == 0) {
    local_ccd8 = in_ECX;
    if (*(int *)(in_ECX + 0x568) == 0) {
      if (DAT_00a0cc6c == 0) {
        local_cce0 = 0;
      }
      else {
        DAT_00a0cc6c = 0;
        DAT_00a0cc74 = 0;
        FUN_00446aa0(local_14);
        local_8 = 1;
        FUN_0079dea2(*(undefined4 *)(local_ccd8 + 4));
        local_8._0_1_ = 2;
        FUN_00408890(*(undefined4 *)(local_ccd8 + 4));
        local_8._0_1_ = 3;
        local_ccdc = FUN_00410380(local_24,local_20,local_1c,local_18,1,0);
        if (local_ccdc == 0) {
          local_cce8 = 0;
          local_8._0_1_ = 2;
          FUN_00408ab0();
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_cce0 = local_cce8;
        }
        else if (local_ccdc == 2) {
          FUN_0044de00(local_cd04,*(undefined4 *)(local_ccd8 + 4));
          FUN_0044c830(local_cd04,*(undefined4 *)(local_ccd8 + 4));
          FUN_005168b0(0x1614,*(undefined4 *)(*(int *)(local_ccd8 + 4) + 0x8f24),
                       *(undefined4 *)(*(int *)(local_ccd8 + 4) + 0x8f28),0,0);
          local_ccec = 0;
          local_8._0_1_ = 2;
          FUN_00408ab0();
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_cce0 = local_ccec;
        }
        else {
          *(undefined4 *)(local_ccd8 + 0x568) = 1;
          local_ccf0 = 0;
          local_8._0_1_ = 2;
          FUN_00408ab0();
          local_8 = CONCAT31(local_8._1_3_,1);
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          local_cce0 = local_ccf0;
        }
      }
    }
    else {
      FUN_00446aa0(local_14);
      local_8 = 0;
      iVar1 = FUN_00451eb0(*(undefined4 *)(local_ccd8 + 4),&local_24,1);
      if (iVar1 == 0) {
        local_cce0 = 0;
        local_8 = 0xffffffff;
        FUN_00447100();
      }
      else {
        FUN_00756050(local_24,local_20,local_1c,local_18,1,1);
        *(undefined4 *)(local_ccd8 + 0x568) = 0;
        local_cce4 = 0;
        local_8 = 0xffffffff;
        FUN_00447100();
        local_cce0 = local_cce4;
      }
    }
  }
  else {
    local_cce0 = (**(code **)(**(int **)(in_ECX + 0x204) + 0x2c))
                           (param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return local_cce0;
}




/* vtable slots: CZukeiZahyouFile[4] */
/* 00755cd0  FUN_00755cd0  316 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00755cd0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_640c [20];
  int local_63f8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092a30b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + 0x8674) + 0x430) = 0;
  local_63f8 = in_ECX;
  local_14 = uVar1;
  puVar2 = (undefined4 *)FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
  FUN_00517640(*puVar2,puVar2[1],puVar2[2],puVar2[3]);
  FUN_00446aa0(uVar1);
  local_8 = 0;
  FUN_0079dea2();
  local_8._0_1_ = 1;
  FUN_0044de00(local_640c,*(undefined4 *)(local_63f8 + 4));
  FUN_0044c830(local_640c,*(undefined4 *)(local_63f8 + 4));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiZahyouFile[3] */
/* 00755e10  FUN_00755e10  298 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00755e10(void)

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
  local_63e8 = in_ECX;
  if (*(int *)(in_ECX + 0x204) == 0) {
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    FUN_00446aa0();
    local_8._0_1_ = 1;
    FUN_0044dd90(local_63fc,*(undefined4 *)(local_63e8 + 4));
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00447100();
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x204) + 0xc))(local_14);
    *(undefined4 *)(local_63e8 + 0x200) = 0;
    *(undefined4 *)(local_63e8 + 0x1fc) = 0;
    FUN_00753090();
    FUN_007539a0(0);
    FUN_00404c80();
    FUN_0056d7d0();
  }
  ExceptionList = local_10;
  return;
}



