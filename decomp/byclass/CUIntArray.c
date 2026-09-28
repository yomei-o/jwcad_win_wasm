/* CUIntArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CUIntArray[1] */
/* 007d0f2b  FUN_007d0f2b  58 bytes, 0 callers */

void FUN_007d0f2b(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CUIntArray::vftable;
  thunk_FUN_008f43b0(in_ECX[1]);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CUIntArray[0] */
/* 007d0f65  FUN_007d0f65  6 bytes, 0 callers */

undefined ** FUN_007d0f65(void)

{
  return &PTR_s_CUIntArray_00986894;
}



