/* CZukeiObject -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiObject[1] */
/* 00769cc0  FUN_00769cc0  68 bytes, 0 callers */

undefined4 FUN_00769cc0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004fa960();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa8);
    }
  }
  return in_ECX;
}



