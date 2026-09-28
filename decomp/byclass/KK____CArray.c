/* KK::?$CArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: KK::?$CArray[1] */
/* 007d5c76  FUN_007d5c76  48 bytes, 0 callers */

void FUN_007d5c76(byte param_1)

{
  CArray<unsigned_long,unsigned_long> *in_ECX;
  
  CArray<unsigned_long,unsigned_long>::~CArray<unsigned_long,unsigned_long>(in_ECX);
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



