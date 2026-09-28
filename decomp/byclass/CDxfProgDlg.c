/* CDxfProgDlg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDxfProgDlg[1] */
/* 004aa5f0  FUN_004aa5f0  68 bytes, 0 callers */

undefined4 FUN_004aa5f0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0049cd00();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x128);
    }
  }
  return in_ECX;
}




/* vtable slots: CDxfProgDlg[64] */
/* 004aa690  DoDataExchange  49 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCWindowsManagerDialog::DoDataExchange(class CDataExchange
   *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCWindowsManagerDialog::DoDataExchange(CMFCWindowsManagerDialog *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x9b6,this + 0xa8);
  return;
}




/* vtable slots: CDxfProgDlg[10] */
/* 004aa6d0  FUN_004aa6d0  16 bytes, 0 callers */

void FUN_004aa6d0(void)

{
  FUN_004aa6e0();
  return;
}



