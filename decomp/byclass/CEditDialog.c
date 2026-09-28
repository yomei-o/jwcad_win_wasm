/* CEditDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CEditDialog[1] */
/* 004aa7d0  FUN_004aa7d0  68 bytes, 0 callers */

undefined4 FUN_004aa7d0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004aa7a0();
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




/* vtable slots: CEditDialog[64] */
/* 004aa820  DoDataExchange  49 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCWindowsManagerDialog::DoDataExchange(class CDataExchange
   *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCWindowsManagerDialog::DoDataExchange(CMFCWindowsManagerDialog *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  DDX_Text(param_1,0x5d3,this + 0xa8);
  return;
}




/* vtable slots: CEditDialog[10] */
/* 004aa860  FUN_004aa860  16 bytes, 0 callers */

void FUN_004aa860(void)

{
  FUN_004aa870();
  return;
}



