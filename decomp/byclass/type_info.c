/* type_info -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: type_info[0] */
/* 008d954d  FUN_008d954d  35 bytes, 0 callers */

void FUN_008d954d(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = type_info::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}



