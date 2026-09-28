/* CDragDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDragDialog[1] */
/* 00498eb0  FUN_00498eb0  68 bytes, 0 callers */

undefined4 FUN_00498eb0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00498e00();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x400);
    }
  }
  return in_ECX;
}




/* vtable slots: CDragDialog[24] */
/* 00498f00  FUN_00498f00  160 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00498f00(void)

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
    FUN_00517510(&DAT_00a0c144,local_18,local_14,local_10,local_c);
  }
  if (*(int *)(in_ECX + 0xc4) != 0) {
    if (*(int *)(in_ECX + 0x370) == 0) {
      DAT_00a0cac8 = 0;
    }
    else {
      DAT_00a0cac8 = 1;
    }
  }
  FUN_00792313();
  return;
}




/* vtable slots: CDragDialog[64] */
/* 00498fa0  DoDataExchange  238 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual void __thiscall CMFCRibbonCustomizePropertyPage::DoDataExchange(class
   CDataExchange *)
    protected: virtual void __thiscall CMFCToolBarButtonCustomizeDialog::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void DoDataExchange(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x7cb,in_ECX + 0xd0);
  FUN_0078fb9c(param_1,0x5d3,in_ECX + 0x150);
  DDX_Text(param_1,0x5d3,in_ECX + 0x1d0);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x1d8);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x270);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0x2f0);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x370);
  FUN_0078fb9c(param_1,0x52c,in_ECX + 0x378);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0x3f8);
  return;
}




/* vtable slots: CDragDialog[10] */
/* 00499090  FUN_00499090  16 bytes, 0 callers */

void FUN_00499090(void)

{
  FUN_004990a0();
  return;
}




/* vtable slots: CDragDialog[94] */
/* 004990d0  FUN_004990d0  650 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004990d0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_34;
  int local_30;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00924875;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_24);
  iVar2 = FUN_00517b40(DAT_00a0c144,DAT_00a0c148,local_24,local_20,local_1c,local_18,&local_34);
  if (iVar2 != 0) {
    FUN_00797e71(0,local_34,local_30,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    FUN_004dbab0(local_34 + 300,local_30 + 0x3a);
  }
  cVar1 = FUN_00408cb0(&DAT_0095590a,local_28 + 0xa8);
  if (cVar1 != '\0') {
    uVar3 = FUN_00404920();
    FUN_00797ece(uVar3);
  }
  uVar3 = FUN_00404920();
  FUN_00797ece(uVar3);
  if (*(int *)(local_28 + 0xb0) == 0) {
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
  }
  else {
    FUN_007979e8(*(undefined4 *)(local_28 + 0xb4));
  }
  if (*(int *)(local_28 + 0xbc) == 0) {
    FUN_00797f20(0);
  }
  else {
    FUN_007979e8(*(undefined4 *)(local_28 + 0xc0));
  }
  if (*(int *)(local_28 + 0xc4) != 0) {
    FUN_00797f20(5);
    CStringT<>();
    local_8 = 0;
    uVar3 = FUN_005977f0(0x161f);
    local_8._0_1_ = 1;
    FUN_00404860(uVar3);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
    uVar3 = FUN_00404920();
    FUN_00797ece(uVar3);
    if (DAT_00a0cac8 != 0) {
      *(undefined4 *)(local_28 + 0x370) = 1;
    }
    FUN_007955d2(0);
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  if (DAT_00a0cbd8 != 0) {
    FUN_00406bf0(DAT_00a0cbd8,1);
  }
  ExceptionList = local_10;
  return 1;
}



