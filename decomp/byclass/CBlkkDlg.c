/* CBlkkDlg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CBlkkDlg[1] */
/* 00415540  FUN_00415540  68 bytes, 0 callers */

undefined4 FUN_00415540(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004154d0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x240);
    }
  }
  return in_ECX;
}




/* vtable slots: CBlkkDlg[24], CNamaeHenkouDlg[24] */
/* 00415590  FUN_00415590  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00415590(void)

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
    FUN_00517510(&DAT_00a0c154,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CBlkkDlg[64] */
/* 00415610  FUN_00415610  167 bytes, 0 callers */

void FUN_00415610(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0xb8);
  FUN_0078fb9c(param_1,0x780,in_ECX + 0x138);
  FUN_0078fb9c(param_1,0x723,in_ECX + 0x1b8);
  DDX_Text(param_1,0x723,in_ECX + 0x238);
  FUN_0078f500(param_1,in_ECX + 0x238,0xfa);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x23c);
  return;
}




/* vtable slots: CBlkkDlg[10] */
/* 004156c0  FUN_004156c0  16 bytes, 0 callers */

void FUN_004156c0(void)

{
  FUN_00415700();
  return;
}




/* vtable slots: CBlkkDlg[97] */
/* 00415710  FUN_00415710  232 bytes, 0 callers */

void FUN_00415710(void)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920a5d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  cVar1 = FUN_00414010(in_ECX + 0x238,in_ECX + 0xa8,DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  if (cVar1 == '\0') {
    FUN_00798826();
  }
  else {
    ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::operator=
              ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
               (in_ECX + 0x238),"");
    ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::operator=
              ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)(in_ECX + 0xa8)
               ,"BlockTempName");
    FUN_007955d2(0);
    FUN_005977f0(0x1546);
    local_8 = 0;
    uVar2 = FUN_00404920();
    FUN_00797ece(uVar2);
    local_8 = 0xffffffff;
    FUN_00404770();
    FUN_00797df8();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CBlkkDlg[94] */
/* 00415800  FUN_00415800  748 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00415800(void)

{
  int iVar1;
  undefined4 uVar2;
  int local_34;
  int local_30;
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
  puStack_c = &LAB_00920aad;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_24);
  iVar1 = FUN_00517b40(DAT_00a0c154,DAT_00a0c158,local_24,local_20,local_1c,local_18,&local_34);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_34,local_30,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    FUN_004dbab0(local_34 + 0x113,local_30 + 0x3c);
  }
  if (*(int *)(local_28 + 0xac) == 1) {
    if (*(int *)(local_28 + 0xb0) == 3) {
      FUN_00415e60(6,1);
    }
    local_2c = *(int *)(local_28 + 0xb0);
    if (local_2c == 1) {
      FUN_00415e90(0);
    }
    else if (local_2c == 2) {
      FUN_00415e90(1);
    }
    else if (local_2c == 3) {
      FUN_00415e90(2);
    }
    FUN_007979e8(0);
    FUN_005977f0(0x164a);
    local_8 = 0;
    uVar2 = FUN_00404920();
    FUN_00797ece(uVar2);
    local_8 = 0xffffffff;
    FUN_00404770();
    FUN_005977f0(0x164b);
    local_8 = 1;
    uVar2 = FUN_00404920();
    FUN_00797ece(uVar2);
    local_8 = 0xffffffff;
    FUN_00404770();
  }
  else if (*(int *)(local_28 + 0xac) == 2) {
    FUN_005977f0(0x279d);
    local_8 = 2;
    uVar2 = FUN_00404920();
    FUN_00797ece(uVar2);
    local_8 = 0xffffffff;
    FUN_00404770();
    FUN_005977f0(0x279d);
    local_8 = 3;
    uVar2 = FUN_00404920();
    FUN_00797ece(uVar2);
    local_8 = 0xffffffff;
    FUN_00404770();
    FUN_007979e8(0);
  }
  else {
    FUN_005977f0(0x1546);
    local_8 = 4;
    uVar2 = FUN_00404920();
    FUN_00797ece(uVar2);
    local_8 = 0xffffffff;
    FUN_00404770();
  }
  FUN_00797df8();
  ExceptionList = local_10;
  return 0;
}




/* vtable slots: CBlkkDlg[96] */
/* 00415bd0  FUN_00415bd0  429 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00415bd0(void)

{
  uint auStack_6400 [3];
  undefined1 *local_63f4;
  int local_63f0;
  uint local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920b30;
  local_10 = ExceptionList;
  auStack_6400[2] = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  auStack_6400[1] = 1;
  auStack_6400[0] = 0x415c12;
  local_14 = auStack_6400[2];
  FUN_007955d2();
  auStack_6400[0] = 0x415c1d;
  FUN_00446aa0();
  local_8 = 0;
  if ((*(int *)(local_63e8 + 0xac) == 0) || (*(int *)(local_63e8 + 0xac) == 2)) {
    auStack_6400[0] = local_63e8 + 0xa8;
    auStack_6400[0] = FUN_00408c80(local_63e8 + 0x238);
    auStack_6400[0] = auStack_6400[0] & 0xff;
    if (auStack_6400[0] != 0) {
      local_63f4 = (undefined1 *)auStack_6400;
      FUN_00403dd0(local_63e8 + 0x238);
      local_63f0 = FUN_0045c670();
      if (local_63f0 != 0) {
        auStack_6400[0] = 0xffffffff;
        FUN_004f60a0(0x1547,0);
        local_8 = 0xffffffff;
        auStack_6400[0] = 0x415cc8;
        FUN_00447100();
        ExceptionList = local_10;
        return;
      }
    }
  }
  auStack_6400[0] = local_63e8 + 0x238;
  FUN_00404860();
  auStack_6400[0] = 0x415cf4;
  local_63ec = FUN_004156d0();
  local_63ec = local_63ec & 3;
  if (local_63ec == 0) {
    *(undefined4 *)(local_63e8 + 0xb0) = 1;
  }
  else if (local_63ec == 1) {
    *(undefined4 *)(local_63e8 + 0xb0) = 2;
  }
  else if (local_63ec == 2) {
    *(undefined4 *)(local_63e8 + 0xb0) = 3;
  }
  auStack_6400[0] = 0x415d52;
  FUN_00798a09();
  local_8 = 0xffffffff;
  auStack_6400[0] = 0x415d64;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



