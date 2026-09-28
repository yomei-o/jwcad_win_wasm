/* CZoom -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZoom[1] */
/* 0060c520  FUN_0060c520  65 bytes, 0 callers */

undefined4 FUN_0060c520(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0060b110();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x3c);
    }
  }
  return in_ECX;
}



