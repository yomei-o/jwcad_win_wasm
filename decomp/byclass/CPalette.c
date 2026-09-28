/* CPalette -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPalette[0] */
/* 0079eb44  FUN_0079eb44  6 bytes, 0 callers */

undefined ** FUN_0079eb44(void)

{
  return &PTR_s_CPalette_0097dfc8;
}




/* vtable slots: CPalette[1] */
/* 007d5d75  FUN_007d5d75  54 bytes, 0 callers */

void FUN_007d5d75(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CPalette::vftable;
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



