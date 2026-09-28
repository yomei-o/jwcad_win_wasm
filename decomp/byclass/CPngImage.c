/* CPngImage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPngImage[1] */
/* 007e728a  FUN_007e728a  54 bytes, 0 callers */

void FUN_007e728a(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CBitmap::vftable;
  FUN_00416100();
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



