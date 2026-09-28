/* CCommonDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CCommonDialog[1] */
/* 00447530  FUN_00447530  68 bytes, 0 callers */

undefined4 FUN_00447530(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004470e0();
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




/* vtable slots: CCommonDialog[0] */
/* 007ab55b  FUN_007ab55b  6 bytes, 0 callers */

undefined ** FUN_007ab55b(void)

{
  return &PTR_s_CCommonDialog_0097f85c;
}



