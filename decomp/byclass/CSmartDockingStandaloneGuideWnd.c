/* CSmartDockingStandaloneGuideWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSmartDockingStandaloneGuideWnd[1] */
/* 008c2c37  FUN_008c2c37  57 bytes, 0 callers */

void FUN_008c2c37(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CSmartDockingStandaloneGuideWnd::vftable;
  FUN_007908c2();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CSmartDockingStandaloneGuideWnd[10] */
/* 008c39d1  FUN_008c39d1  6 bytes, 0 callers */

undefined ** FUN_008c39d1(void)

{
  return &PTR_FUN_009a3db8;
}



