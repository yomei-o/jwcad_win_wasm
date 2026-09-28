/* CSenKigouDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSenKigouDialog[1] */
/* 005cbd00  FUN_005cbd00  68 bytes, 0 callers */

undefined4 FUN_005cbd00(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005cbc70();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x8a8);
    }
  }
  return in_ECX;
}




/* vtable slots: CSenKigouDialog[64] */
/* 005cbed0  DoDataExchange  238 bytes, 0 callers */

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
  FUN_0078fb9c(param_1,0x597,in_ECX + 0x268);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x440);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x4c0);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x540);
  FUN_0078fb9c(param_1,0x6d8,in_ECX + 0x5c0);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x640);
  FUN_0078fb9c(param_1,0x42b,in_ECX + 0x788);
  FUN_0078fb9c(param_1,0x42c,in_ECX + 0x820);
  FUN_0078f6f8(param_1,0xb2e,in_ECX + 0x8a0);
  return;
}




/* vtable slots: CSenKigouDialog[10] */
/* 005cbfc0  FUN_005cbfc0  16 bytes, 0 callers */

void FUN_005cbfc0(void)

{
  FUN_005cbfd0();
  return;
}




/* vtable slots: CSenKigouDialog[100] */
/* 005cc600  FUN_005cc600  83 bytes, 0 callers */

void FUN_005cc600(void)

{
  BOOL BVar1;
  int in_ECX;
  
  BVar1 = IsWindow(*(HWND *)(in_ECX + 0x288));
  if (BVar1 != 0) {
    FUN_005895a0(*(undefined8 *)(in_ECX + 0xc0),*(undefined8 *)(in_ECX + 200));
  }
  return;
}



