/* std::D::?$numpunct -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::D::?$numpunct[0] */
/* 008db6e3  FUN_008db6e3  46 bytes, 0 callers */

void FUN_008db6e3(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::numpunct<char>::vftable;
  Tidy();
  *in_ECX = std::_Facet_base::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}



