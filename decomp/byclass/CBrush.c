/* CBrush -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CBrush[1] */
/* 004209e0  FUN_004209e0  65 bytes, 0 callers */

undefined4 FUN_004209e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041fd10();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,8);
    }
  }
  return in_ECX;
}




/* vtable slots: CBrush[0] */
/* 0079eb20  FUN_0079eb20  6 bytes, 0 callers */

undefined ** FUN_0079eb20(void)

{
  return &PTR_s_CBrush_0097df74;
}



