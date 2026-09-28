/* CThreadData -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CThreadData[0] */
/* 007c031e  FUN_007c031e  48 bytes, 0 callers */

void FUN_007c031e(byte param_1)

{
  HLOCAL in_ECX;
  
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      if (in_ECX != (HLOCAL)0x0) {
        LocalFree(in_ECX);
      }
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}



