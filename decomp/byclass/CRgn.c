/* CRgn -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CRgn[0] */
/* 0079eb56  FUN_0079eb56  6 bytes, 0 callers */

undefined ** FUN_0079eb56(void)

{
  return &PTR_DAT_0097dfe4;
}




/* vtable slots: CRgn[1] */
/* 007a4055  FUN_007a4055  54 bytes, 0 callers */

void FUN_007a4055(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CRgn::vftable;
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



