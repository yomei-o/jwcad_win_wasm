/* CDummyDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDummyDialog[1] */
/* 0049c040  FUN_0049c040  68 bytes, 0 callers */

undefined4 FUN_0049c040(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0049c020();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xb8);
    }
  }
  return in_ECX;
}




/* vtable slots: CDummyDialog[10] */
/* 0049c0b0  FUN_0049c0b0  16 bytes, 0 callers */

void FUN_0049c0b0(void)

{
  FUN_0049c0c0();
  return;
}



