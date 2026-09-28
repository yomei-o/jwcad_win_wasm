/* CSesenDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSesenDialog[1] */
/* 005cb5f0  FUN_005cb5f0  68 bytes, 0 callers */

undefined4 FUN_005cb5f0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005cb5b0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x3e0);
    }
  }
  return in_ECX;
}




/* vtable slots: CSesenDialog[64] */
/* 005cb640  DoDataExchange  120 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual void __thiscall CMFCImageEditorDialog::DoDataExchange(class CDataExchange *)
    protected: virtual void __thiscall CMFCMousePropertyPage::DoDataExchange(class CDataExchange *)
    protected: virtual void __thiscall COutlookOptionsDlg::DoDataExchange(class CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void DoDataExchange(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0xb8);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0x200);
  FUN_0078fb9c(param_1,0x6d8,in_ECX + 0x358);
  FUN_0078f75d(param_1,0x699,in_ECX + 0x3d8);
  return;
}




/* vtable slots: CSesenDialog[10] */
/* 005cb6c0  FUN_005cb6c0  16 bytes, 0 callers */

void FUN_005cb6c0(void)

{
  FUN_005cb6d0();
  return;
}




/* vtable slots: CSesenDialog[94] */
/* 005cb6e0  FUN_005cb6e0  102 bytes, 0 callers */

undefined4 FUN_005cb6e0(void)

{
  int in_ECX;
  
  FUN_00798993();
  if (*(int *)(in_ECX + 0x3d8) == 2) {
    FUN_00797f20(5);
    FUN_00797f20(5);
  }
  else {
    FUN_00797f20(0);
    FUN_00797f20(0);
  }
  return 1;
}



