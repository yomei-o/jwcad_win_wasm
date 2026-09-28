/* CTateguKijuntenDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTateguKijuntenDialog[1] */
/* 005f6dd0  FUN_005f6dd0  68 bytes, 0 callers */

undefined4 FUN_005f6dd0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005f6da0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xb0);
    }
  }
  return in_ECX;
}




/* vtable slots: CTateguKijuntenDialog[24] */
/* 005f6e20  FUN_005f6e20  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005f6e20(void)

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
    FUN_00517510(&DAT_00a0c14c,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CTateguKijuntenDialog[64] */
/* 005f6ea0  DoDataExchange  49 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCWindowsManagerDialog::DoDataExchange(class CDataExchange
   *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCWindowsManagerDialog::DoDataExchange(CMFCWindowsManagerDialog *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078f75d(param_1,0x699,this + 0xa8);
  return;
}




/* vtable slots: CTateguKijuntenDialog[10] */
/* 005f6ee0  FUN_005f6ee0  16 bytes, 0 callers */

void FUN_005f6ee0(void)

{
  FUN_005f6ef0();
  return;
}




/* vtable slots: CTateguKijuntenDialog[94] */
/* 005f6f00  FUN_005f6f00  158 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005f6f00(void)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00798993();
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_18);
  iVar1 = FUN_00517b40(DAT_00a0c14c,DAT_00a0c150,local_18,local_14,local_10,local_c,&local_24);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  return 1;
}



