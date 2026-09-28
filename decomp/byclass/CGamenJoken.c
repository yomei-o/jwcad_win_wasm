/* CGamenJoken -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CGamenJoken[0] */
/* 004b5030  FUN_004b5030  49 bytes, 0 callers */

undefined4 FUN_004b5030(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004b4d90();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0x84a8);
  }
  return in_ECX;
}



