/* CMy3Button -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMy3Button[1] */
/* 0058b710  FUN_0058b710  68 bytes, 0 callers */

undefined4 FUN_0058b710(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0058b6f0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x98);
    }
  }
  return in_ECX;
}




/* vtable slots: CMy3Button[10] */
/* 0058b760  FUN_0058b760  16 bytes, 0 callers */

void FUN_0058b760(void)

{
  FUN_0058b770();
  return;
}



