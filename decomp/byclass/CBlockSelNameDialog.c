/* CBlockSelNameDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CBlockSelNameDialog[1] */
/* 00414080  FUN_00414080  68 bytes, 0 callers */

undefined4 FUN_00414080(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00413f70();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1b0);
    }
  }
  return in_ECX;
}




/* vtable slots: CBlockSelNameDialog[24] */
/* 00414300  FUN_00414300  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00414300(void)

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
    FUN_00517510(&DAT_00a0c15c,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CBlockSelNameDialog[64] */
/* 00414550  DoDataExchange  72 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCStandardColorsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCStandardColorsPropertyPage::DoDataExchange
          (CMFCStandardColorsPropertyPage *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x983,this + 0xb0);
  FUN_0078fb9c(param_1,0x8d1,this + 0x130);
  return;
}




/* vtable slots: CBlockSelNameDialog[10] */
/* 004145e0  FUN_004145e0  16 bytes, 0 callers */

void FUN_004145e0(void)

{
  FUN_00414680();
  return;
}




/* vtable slots: CBlockSelNameDialog[94] */
/* 004146f0  FUN_004146f0  709 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004146f0(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  undefined1 local_44 [8];
  int *local_3c;
  int *local_38;
  int local_34 [2];
  int local_2c;
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
  puStack_c = &LAB_00920905;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_24);
  iVar2 = FUN_00517b40(DAT_00a0c15c,DAT_00a0c160,local_24,local_20,local_1c,local_18,&local_54);
  if (iVar2 != 0) {
    FUN_00797e71(0,local_54,local_50,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    FUN_004dbab0(local_54 + 0x10e,local_50 + 0x30);
  }
  local_28 = FUN_0040c0e0();
  while (iVar2 = FUN_004146c0(), iVar2 == 0) {
    local_38 = (int *)FUN_00414c00();
    if (local_38 != (int *)0x0) {
      (**(code **)(*local_38 + 4))(1);
    }
  }
  local_34[0] = FUN_00572030();
  while (((local_34[0] != 0 && (local_2c = FUN_00572100(local_34), local_2c != 0)) &&
         (local_2c != 0))) {
    iVar2 = FUN_0079d98a(&PTR_s_CDataBlock_009fe144);
    if (iVar2 != 0) {
      FUN_00414170(local_28,local_2c);
    }
  }
  local_4c = 0;
  CStringT<>(&DAT_0095590a);
  local_8 = 0;
  local_34[0] = FUN_00572a80();
  do {
    local_2c = FUN_00572aa0(local_34);
    if (local_2c == 0) {
LAB_004148df:
      if (local_4c == 0) {
        FUN_00404860(local_44);
      }
      while (iVar2 = FUN_004146c0(), iVar2 == 0) {
        local_3c = (int *)FUN_00414c00();
        if (local_3c != (int *)0x0) {
          (**(code **)(*local_3c + 4))(1);
        }
      }
      CStringT<>();
      local_8._0_1_ = 1;
      FUN_00404860(&DAT_00a0cc18);
      uVar3 = FUN_00404920();
      FUN_00797ece(uVar3);
      FUN_00797df8();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00404540();
      local_8 = 0xffffffff;
      FUN_00404540();
      ExceptionList = local_10;
      return 0;
    }
    local_48 = local_2c;
    cVar1 = FUN_00414010(local_2c + 0xb0,&DAT_00a0cc18);
    if (cVar1 != '\0') {
      local_4c = 1;
      goto LAB_004148df;
    }
    FUN_00404860(local_48 + 0xb0);
  } while( true );
}




/* vtable slots: CBlockSelNameDialog[96] */
/* 00414b70  FUN_00414b70  72 bytes, 0 callers */

void FUN_00414b70(void)

{
  int in_ECX;
  
  FUN_007955d2(1);
  FUN_00792c64(in_ECX + 0xa8);
  FUN_00404860(in_ECX + 0xa8);
  FUN_00798a09();
  return;
}



