/* CMyButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyButton[1] */
/* 00404ae0  FUN_00404ae0  68 bytes, 0 callers */

undefined4 FUN_00404ae0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00404720();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x80);
    }
  }
  return in_ECX;
}



