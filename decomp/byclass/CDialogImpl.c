/* CDialogImpl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDialogImpl[0] */
/* 007ec7f6  FUN_007ec7f6  35 bytes, 0 callers */

void FUN_007ec7f6(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CDialogImpl::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}



