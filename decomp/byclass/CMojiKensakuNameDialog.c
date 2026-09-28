/* CMojiKensakuNameDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMojiKensakuNameDialog[1] */
/* 00414120  FUN_00414120  68 bytes, 0 callers */

undefined4 FUN_00414120(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00413fc0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x130);
    }
  }
  return in_ECX;
}




/* vtable slots: CMojiKensakuNameDialog[24] */
/* 00414380  FUN_00414380  460 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00414380(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009208c5;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_28 = in_ECX;
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_00413f30(local_14);
    FUN_004146a0(&local_24);
    FUN_00517510(&DAT_00a0c15c,local_24,local_20,local_1c,local_18);
  }
  cVar1 = FUN_00414040(&DAT_0095590a,local_28 + 0xa8);
  if (cVar1 == '\0') {
    iVar3 = ATL::CSimpleStringT<wchar_t,0>::GetAllocLength
                      ((CSimpleStringT<wchar_t,0> *)(local_28 + 0xa8));
    if (iVar3 < 0x65) {
      FUN_00403dd0(local_28 + 0xa8);
      local_8 = 0;
      CStringT<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      for (local_2c = 0; local_2c < 10; local_2c = local_2c + 1) {
        FUN_00404860(&DAT_00a0cb98 + local_2c * 4);
        FUN_00404860(local_34);
        cVar1 = FUN_00414010(local_30,local_28 + 0xa8);
        if (cVar1 != '\0') break;
        FUN_00404860(local_30);
      }
      uVar2 = FUN_00792313();
      local_8 = local_8 & 0xffffff00;
      FUN_00404540();
      local_8 = 0xffffffff;
      FUN_00404540();
    }
    else {
      ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::operator=
                ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                 (local_28 + 0xa8),"");
      FUN_005168b0(0x168b,*(undefined4 *)(DAT_00a0b410 + 0x8f24),
                   *(undefined4 *)(DAT_00a0b410 + 0x8f28),0,0);
      uVar2 = FUN_00792313();
    }
  }
  else {
    uVar2 = FUN_00792313();
  }
  ExceptionList = local_10;
  return uVar2;
}




/* vtable slots: CMojiKensakuNameDialog[64] */
/* 004145a0  DoDataExchange  49 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCWindowsManagerDialog::DoDataExchange(class CDataExchange
   *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCWindowsManagerDialog::DoDataExchange(CMFCWindowsManagerDialog *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x983,this + 0xb0);
  return;
}




/* vtable slots: CMojiKensakuNameDialog[10] */
/* 004145f0  FUN_004145f0  16 bytes, 0 callers */

void FUN_004145f0(void)

{
  FUN_00414690();
  return;
}




/* vtable slots: CMojiKensakuNameDialog[94] */
/* 004149c0  FUN_004149c0  418 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004149c0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_38;
  int local_34;
  int local_2c;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092093d;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_24);
  iVar2 = FUN_00517b40(DAT_00a0c15c,DAT_00a0c160,local_24,local_20,local_1c,local_18,&local_38);
  if (iVar2 != 0) {
    FUN_00797e71(0,local_38,local_34,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    FUN_004dbab0(local_38 + 0x10e,local_34 + 0x30);
  }
  for (local_2c = 0; local_2c < 10; local_2c = local_2c + 1) {
    cVar1 = FUN_00414040(&DAT_0095590a,&DAT_00a0cb98 + local_2c * 4);
    if (cVar1 == '\0') {
      uVar3 = FUN_00404920();
      FUN_004142b0(uVar3);
    }
  }
  CStringT<>(&DAT_0095590a);
  local_8 = 0;
  FUN_00404860(&DAT_00a0cb98);
  uVar3 = FUN_00404920();
  FUN_00797ece(uVar3);
  FUN_00797df8();
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CMojiKensakuNameDialog[96] */
/* 00414bc0  FUN_00414bc0  52 bytes, 0 callers */

void FUN_00414bc0(void)

{
  int in_ECX;
  
  FUN_007955d2(1);
  FUN_00792c64(in_ECX + 0xa8);
  FUN_00798a09();
  return;
}



