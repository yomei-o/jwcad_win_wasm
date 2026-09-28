/* std::bad_exception -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::bad_exception[0], std::length_error[0], std::logic_error[0], std::out_of_range[0] */
/* 008da5bc  FUN_008da5bc  45 bytes, 0 callers */

void FUN_008da5bc(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::exception::vftable;
  ___std_exception_destroy(in_ECX + 1);
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}



