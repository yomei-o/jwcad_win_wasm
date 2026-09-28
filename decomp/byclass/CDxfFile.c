/* CDxfFile -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDxfFile[0] */
/* 0049d180  FUN_0049d180  49 bytes, 0 callers */

undefined4 FUN_0049d180(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0049cc10();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0x3480);
  }
  return in_ECX;
}



