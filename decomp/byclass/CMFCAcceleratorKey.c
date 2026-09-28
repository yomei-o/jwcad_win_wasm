/* CMFCAcceleratorKey -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCAcceleratorKey[1] */
/* 0082ae9a  FUN_0082ae9a  49 bytes, 0 callers */

void FUN_0082ae9a(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCAcceleratorKey::vftable;
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



