/* CGlobalUtils -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CGlobalUtils[0] */
/* 00859dc9  FUN_00859dc9  35 bytes, 0 callers */

void FUN_00859dc9(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CGlobalUtils::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}



