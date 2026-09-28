/* std::exception -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::exception[0] */
/* 00481410  FUN_00481410  46 bytes, 0 callers */

exception * FUN_00481410(uint param_1)

{
  exception *in_ECX;
  
  std::exception::~exception(in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0xc);
  }
  return in_ECX;
}



