/* CPrintBairitsuDlg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPrintBairitsuDlg[1] */
/* 005ac9c0  FUN_005ac9c0  68 bytes, 0 callers */

undefined4 FUN_005ac9c0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005ac980();
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




/* vtable slots: CPrintBairitsuDlg[24] */
/* 005aca10  FUN_005aca10  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005aca10(void)

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
    FUN_00517510(&DAT_00a0c194,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CPrintBairitsuDlg[64] */
/* 005aca90  DoDataExchange  72 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCStandardColorsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCStandardColorsPropertyPage::DoDataExchange
          (CMFCStandardColorsPropertyPage *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x428,this + 0xb0);
  DDX_Text(param_1,0x5d3,(double *)(this + 0xa8));
  return;
}




/* vtable slots: CPrintBairitsuDlg[10] */
/* 005acae0  FUN_005acae0  16 bytes, 0 callers */

void FUN_005acae0(void)

{
  FUN_005acaf0();
  return;
}




/* vtable slots: CPrintBairitsuDlg[94] */
/* 005acc00  FUN_005acc00  158 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005acc00(void)

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
  iVar1 = FUN_00517b40(DAT_00a0c194,DAT_00a0c198,local_18,local_14,local_10,local_c,&local_24);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  return 1;
}



