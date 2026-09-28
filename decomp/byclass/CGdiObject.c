/* CGdiObject -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CGdiObject[1] */
/* 00416330  FUN_00416330  65 bytes, 0 callers */

undefined4 FUN_00416330(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00416100();
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




/* vtable slots: CGdiObject[0] */
/* 0079eb38  FUN_0079eb38  6 bytes, 0 callers */

undefined ** FUN_0079eb38(void)

{
  return &PTR_s_CGdiObject_0097df3c;
}



