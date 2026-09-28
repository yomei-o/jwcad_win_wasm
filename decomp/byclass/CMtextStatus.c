/* CMtextStatus -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMtextStatus[0] */
/* 0049d220  FUN_0049d220  46 bytes, 0 callers */

undefined4 FUN_0049d220(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0049cd70();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0x60);
  }
  return in_ECX;
}



