/* CSxfFile -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSxfFile[0] */
/* 005db400  FUN_005db400  49 bytes, 0 callers */

undefined4 FUN_005db400(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005db1b0();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0x4c178);
  }
  return in_ECX;
}



