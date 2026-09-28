/* CMojiSelDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMojiSelDialog[1] */
/* 0057bbe0  FUN_0057bbe0  68 bytes, 0 callers */

undefined4 FUN_0057bbe0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0057b990();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xf30);
    }
  }
  return in_ECX;
}




/* vtable slots: CMojiSelDialog[24] */
/* 0057bc30  FUN_0057bc30  184 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0057bc30(void)

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
    FUN_00517510(&DAT_00a0c104,local_18,local_14,local_10,local_c);
  }
  if (*(int *)(in_ECX + 0xa8) != 0) {
    if (*(int **)(in_ECX + 0xa8) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0xa8) + 4))(1);
    }
    *(undefined4 *)(in_ECX + 0xa8) = 0;
  }
  FUN_00792313();
  return;
}




/* vtable slots: CMojiSelDialog[64] */
/* 0057bcf0  FUN_0057bcf0  1897 bytes, 0 callers */

void FUN_0057bcf0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 local_8c [4];
  undefined4 local_88;
  undefined4 local_84;
  undefined1 local_80 [4];
  undefined4 local_7c;
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
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20 [4];
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e158;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x58f,local_14 + 0xb8);
  FUN_0078f643(param_1,0x58f,local_14 + 0x358);
  FUN_0078fb9c(param_1,0x974,local_14 + 0x158);
  FUN_0078fb9c(param_1,0x975,local_14 + 0x1d8);
  FUN_0078fb9c(param_1,0x96d,local_14 + 600);
  FUN_0078fb9c(param_1,0x96e,local_14 + 0x2d8);
  FUN_0078f6f8(param_1,0x974,local_14 + 0xee4);
  FUN_0078f6f8(param_1,0x975,local_14 + 0xee8);
  FUN_0078f6f8(param_1,0x96d,local_14 + 0xeec);
  FUN_0078f6f8(param_1,0x96e,local_14 + 0xef0);
  FUN_0078fb9c(param_1,0x5d4,local_14 + 0x360);
  FUN_0078fb9c(param_1,0x5d3,local_14 + 0x3e0);
  FUN_0078fb9c(param_1,0x9c8,local_14 + 0x460);
  FUN_0078fb9c(param_1,0x9c9,local_14 + 0x4e0);
  FUN_0078fb9c(param_1,0x9ca,local_14 + 0x560);
  FUN_0078fb9c(param_1,0x9cb,local_14 + 0x5e0);
  FUN_0078fb9c(param_1,0x9cc,local_14 + 0x660);
  FUN_0078fb9c(param_1,0x9cd,local_14 + 0x6e0);
  FUN_0078fb9c(param_1,0x9ce,local_14 + 0x760);
  FUN_0078fb9c(param_1,0x9cf,local_14 + 0x7e0);
  FUN_0078fb9c(param_1,0x9d0,local_14 + 0x860);
  FUN_0078fb9c(param_1,0x9d1,local_14 + 0x8e0);
  FUN_0078fb9c(param_1,0x52a,local_14 + 0x960);
  FUN_0078fb9c(param_1,0x52b,local_14 + 0x9e0);
  FUN_0078fb9c(param_1,0x52c,local_14 + 0xa60);
  FUN_0078fb9c(param_1,0x52d,local_14 + 0xae0);
  FUN_0078fb9c(param_1,0x52e,local_14 + 0xb60);
  FUN_0078fb9c(param_1,0x52f,local_14 + 0xbe0);
  FUN_0078fb9c(param_1,0x530,local_14 + 0xc60);
  FUN_0078fb9c(param_1,0x841,local_14 + 0xce0);
  FUN_0078fb9c(param_1,0x842,local_14 + 0xd60);
  FUN_0078fb9c(param_1,0x843,local_14 + 0xde0);
  FUN_0078fb9c(param_1,0x77b,local_14 + 0xe60);
  FUN_0078f6f8(param_1,0x96f,local_14 + 0xee0);
  FUN_0078f6f8(param_1,0x52a,local_14 + 0xef4);
  FUN_0078f6f8(param_1,0x52b,local_14 + 0xef8);
  FUN_0078f6f8(param_1,0x52c,local_14 + 0xefc);
  FUN_0078f6f8(param_1,0x52d,local_14 + 0xf00);
  FUN_0078f6f8(param_1,0x52e,local_14 + 0xf04);
  FUN_0078f6f8(param_1,0x52f,local_14 + 0xf08);
  FUN_0078f6f8(param_1,0x530,local_14 + 0xf0c);
  FUN_0078f6f8(param_1,0x841,local_14 + 0xf10);
  FUN_0078f6f8(param_1,0x842,local_14 + 0xf14);
  FUN_0078f6f8(param_1,0x843,local_14 + 0xf18);
  FUN_0078f6f8(param_1,0x77b,local_14 + 0xf1c);
  FUN_0078f75d(param_1,0x6a2,local_14 + 0xf20);
  DDX_Text(param_1,0x5d3,local_14 + 0xf24);
  DDX_Text(param_1,0x5d4,local_14 + 0xf28);
  local_1c = FUN_0057cf00(local_20,1);
  local_8 = 0;
  local_18 = local_1c;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_28 = FUN_0057cf00(local_2c,2);
  local_8 = 1;
  local_24 = local_28;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_34 = FUN_0057cf00(local_38,3);
  local_8 = 2;
  local_30 = local_34;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_40 = FUN_0057cf00(local_44,4);
  local_8 = 3;
  local_3c = local_40;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_4c = FUN_0057cf00(local_50,5);
  local_8 = 4;
  local_48 = local_4c;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_58 = FUN_0057cf00(local_5c,6);
  local_8 = 5;
  local_54 = local_58;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_64 = FUN_0057cf00(local_68,7);
  local_8 = 6;
  local_60 = local_64;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_70 = FUN_0057cf00(local_74,8);
  local_8 = 7;
  local_6c = local_70;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_7c = FUN_0057cf00(local_80,9);
  local_8 = 8;
  local_78 = local_7c;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_88 = FUN_0057cf00(local_8c,10);
  local_8 = 9;
  local_84 = local_88;
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CMojiSelDialog[10] */
/* 0057c460  FUN_0057c460  16 bytes, 0 callers */

void FUN_0057c460(void)

{
  FUN_0057c470();
  return;
}




/* vtable slots: CMojiSelDialog[94] */
/* 0057c880  FUN_0057c880  507 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0057c880(void)

{
  LPCWSTR pszFaceName;
  int iVar1;
  int cWidth;
  int cEscapement;
  int cOrientation;
  int cWeight;
  DWORD bItalic;
  DWORD bUnderline;
  DWORD bStrikeOut;
  DWORD iCharSet;
  DWORD iOutPrecision;
  DWORD iClipPrecision;
  DWORD iQuality;
  DWORD iPitchAndFamily;
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
  puStack_c = &LAB_0092e18f;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  FUN_007979e8(0);
  FUN_007979e8(0);
  FUN_007979e8(0);
  FUN_007979e8(0);
  if (*(int *)(local_28 + 0xef4) == 0) {
    FUN_007979e8(0);
    FUN_007979e8(0);
  }
  else {
    FUN_007979e8(1);
    FUN_007979e8(1);
  }
  local_2c = FUN_004121b0(8);
  local_8 = 0;
  if (local_2c == 0) {
    local_30 = 0;
  }
  else {
    local_30 = FUN_00480c40();
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(local_28 + 0xa8) = local_30;
  pszFaceName = (LPCWSTR)FUN_00404920();
  iPitchAndFamily = 5;
  iQuality = 0;
  iClipPrecision = 0x20;
  iOutPrecision = 4;
  iCharSet = 0x80;
  bStrikeOut = 0;
  bUnderline = 0;
  bItalic = 0;
  cWeight = 400;
  cOrientation = 0;
  cEscapement = 0;
  cWidth = 0;
  iVar1 = FUN_004f74b0(10);
  FID_conflict_CreateFontW
            (iVar1,cWidth,cEscapement,cOrientation,cWeight,bItalic,bUnderline,bStrikeOut,iCharSet,
             iOutPrecision,iClipPrecision,iQuality,iPitchAndFamily,pszFaceName);
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_24);
  iVar1 = FUN_00517b40(DAT_00a0c104,DAT_00a0c108,local_24,local_20,local_1c,local_18,&local_38);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_38,local_34,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    FUN_004dbab0(local_38 + 0x9b,local_34 + 0x23);
  }
  ExceptionList = local_10;
  return 1;
}



