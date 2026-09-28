/* CPtrArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPtrArray[1] */
/* 007aff93  FUN_007aff93  58 bytes, 0 callers */

void FUN_007aff93(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CPtrArray::vftable;
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




/* vtable slots: CPtrArray[0] */
/* 007affcd  FUN_007affcd  6 bytes, 0 callers */

undefined ** FUN_007affcd(void)

{
  return &PTR_s_CPtrArray_009801b0;
}



