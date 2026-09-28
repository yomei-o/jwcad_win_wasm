/* CFont -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFont[1] */
/* 00481360  FUN_00481360  65 bytes, 0 callers */

undefined4 FUN_00481360(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00480fe0();
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




/* vtable slots: CFont[0] */
/* 0079eb32  FUN_0079eb32  6 bytes, 0 callers */

undefined ** FUN_0079eb32(void)

{
  return &PTR_s_CFont_0097df90;
}



