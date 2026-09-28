/* CMojiSizeDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMojiSizeDialog[1] */
/* 00587040  FUN_00587040  68 bytes, 0 callers */

undefined4 FUN_00587040(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00586f10();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x7b8);
    }
  }
  return in_ECX;
}




/* vtable slots: CMojiSizeDialog[24] */
/* 00587090  FUN_00587090  184 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00587090(void)

{
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_00413f30();
    FUN_004146a0(&local_18);
    FUN_00517510(&DAT_00a0c0f4,local_18,local_14,local_10,local_c);
  }
  if (*(int *)(in_ECX + 0xe0) != 0) {
    if (*(int **)(in_ECX + 0xe0) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0xe0) + 4))(1);
    }
    *(undefined4 *)(in_ECX + 0xe0) = 0;
  }
  FUN_00792313();
  return;
}




/* vtable slots: CMojiSizeDialog[64] */
/* 00587150  FUN_00587150  593 bytes, 0 callers */

void FUN_00587150(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x58f,in_ECX + 0xe8);
  FUN_0078f6f8(param_1,0x53e,in_ECX + 0x188);
  FUN_0078fb9c(param_1,0x53e,in_ECX + 400);
  FUN_0078f6f8(param_1,0x974,in_ECX + 0x210);
  FUN_0078f6f8(param_1,0x96d,in_ECX + 0x214);
  FUN_0078f6f8(param_1,0x52a,in_ECX + 0x218);
  DDX_Text(param_1,0x5d3,in_ECX + 0x21c);
  DDX_Text(param_1,0x5d4,in_ECX + 0x220);
  DDX_Text(param_1,0x5d5,in_ECX + 0x224);
  DDX_Text(param_1,0x5d6,in_ECX + 0x228);
  FUN_0078f75d(param_1,0x75c,in_ECX + 0x22c);
  FUN_0078fb9c(param_1,0x78c,in_ECX + 0x230);
  FUN_0078fb9c(param_1,0x9c8,in_ECX + 0x2b0);
  FUN_0078fb9c(param_1,0x9c9,in_ECX + 0x330);
  FUN_0078fb9c(param_1,0x9ca,in_ECX + 0x3b0);
  FUN_0078fb9c(param_1,0x9cb,in_ECX + 0x430);
  FUN_0078fb9c(param_1,0x9cc,in_ECX + 0x4b0);
  FUN_0078fb9c(param_1,0x9cd,in_ECX + 0x530);
  FUN_0078fb9c(param_1,0x9ce,in_ECX + 0x5b0);
  FUN_0078fb9c(param_1,0x9cf,in_ECX + 0x630);
  FUN_0078fb9c(param_1,0x9d0,in_ECX + 0x6b0);
  FUN_0078fb9c(param_1,0x9d1,in_ECX + 0x730);
  FUN_0078f643(param_1,0x58f,in_ECX + 0x7b0);
  FUN_0078f5ed(param_1,0x936,in_ECX + 0x7b4);
  return;
}




/* vtable slots: CMojiSizeDialog[10] */
/* 005873b0  FUN_005873b0  16 bytes, 0 callers */

void FUN_005873b0(void)

{
  FUN_005873c0();
  return;
}




/* vtable slots: CMojiSizeDialog[94] */
/* 00587480  FUN_00587480  1260 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00587480(void)

{
  LPCWSTR pszFaceName;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_b8 [4];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 local_ac [4];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 local_a0 [4];
  undefined4 local_9c;
  undefined4 local_98;
  undefined1 local_94 [4];
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88 [4];
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7c [4];
  undefined4 local_78;
  undefined1 local_74 [4];
  undefined4 local_70;
  undefined4 local_6c;
  undefined1 local_68 [4];
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_5c [4];
  undefined4 local_58;
  undefined4 local_54;
  undefined1 local_50 [4];
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [4];
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f0c6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  local_2c = FUN_004121b0(8);
  local_8 = 0;
  if (local_2c == 0) {
    local_30 = 0;
  }
  else {
    local_30 = FUN_00480c40();
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(local_28 + 0xe0) = local_30;
  pszFaceName = (LPCWSTR)FUN_00404920();
  FID_conflict_CreateFontW(0,0,0,0,400,0,0,0,0x80,4,0x20,0,5,pszFaceName);
  local_40 = FUN_00587f30(local_44,0);
  local_8 = 1;
  local_3c = local_40;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_4c = FUN_00587f30(local_50,1);
  local_8 = 2;
  local_48 = local_4c;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_58 = FUN_00587f30(local_5c,2);
  local_8 = 3;
  local_54 = local_58;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_64 = FUN_00587f30(local_68,3);
  local_8 = 4;
  local_60 = local_64;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_70 = FUN_00587f30(local_74,4);
  local_8 = 5;
  local_6c = local_70;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_78 = FUN_00587f30(local_7c,5);
  local_8 = 6;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_84 = FUN_00587f30(local_88,6);
  local_8 = 7;
  local_80 = local_84;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_90 = FUN_00587f30(local_94,7);
  local_8 = 8;
  local_8c = local_90;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_9c = FUN_00587f30(local_a0,8);
  local_8 = 9;
  local_98 = local_9c;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_a8 = FUN_00587f30(local_ac,9);
  local_8 = 10;
  local_a4 = local_a8;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_b4 = FUN_00587f30(local_b8,10);
  local_8 = 0xb;
  local_b0 = local_b4;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_24);
  iVar2 = FUN_00517b40(DAT_00a0c0f4,DAT_00a0c0f8,local_24,local_20,local_1c,local_18,&local_38);
  if (iVar2 != 0) {
    FUN_00797e71(0,local_38,local_34,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    iVar2 = FUN_004f72f0(0x28);
    iVar2 = iVar2 + local_34;
    iVar3 = FUN_004f72f0(0x9e);
    FUN_004dbab0(iVar3 + local_38,iVar2);
  }
  if (*(int *)(local_28 + 0xa8) == 0) {
    FUN_00797f20(0);
  }
  else {
    FUN_00797f20(5);
  }
  ExceptionList = local_10;
  return 1;
}



