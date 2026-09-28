/* CPen -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPen[1] */
/* 0041c9b0  FUN_0041c9b0  65 bytes, 0 callers */

undefined4 FUN_0041c9b0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041c990();
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




/* vtable slots: CPen[0] */
/* 0079eb4a  FUN_0079eb4a  6 bytes, 0 callers */

undefined ** FUN_0079eb4a(void)

{
  return &PTR_DAT_0097df58;
}



