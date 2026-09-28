/* CSenCollControlBar2 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSenCollControlBar2[1] */
/* 005bb750  FUN_005bb750  68 bytes, 0 callers */

undefined4 FUN_005bb750(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005bb690();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x118);
    }
  }
  return in_ECX;
}




/* vtable slots: CSenCollControlBar2[10] */
/* 005bbcf0  FUN_005bbcf0  16 bytes, 0 callers */

void FUN_005bbcf0(void)

{
  FUN_005bbd10();
  return;
}



