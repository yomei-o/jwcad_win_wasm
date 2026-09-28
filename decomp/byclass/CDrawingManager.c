/* CDrawingManager -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDrawingManager[1] */
/* 00815112  FUN_00815112  49 bytes, 0 callers */

void FUN_00815112(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CDrawingManager::vftable;
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



