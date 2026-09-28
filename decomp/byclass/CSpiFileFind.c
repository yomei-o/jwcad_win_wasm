/* CSpiFileFind -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSpiFileFind[1] */
/* 005d1b00  FUN_005d1b00  65 bytes, 0 callers */

undefined4 FUN_005d1b00(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005d1ae0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x24);
    }
  }
  return in_ECX;
}



