/* std::G::?$numpunct -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::G::?$numpunct[0] */
/* 008e11d6  FUN_008e11d6  46 bytes, 0 callers */

void FUN_008e11d6(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::numpunct<unsigned_short>::vftable;
  Tidy();
  *in_ECX = std::_Facet_base::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}



