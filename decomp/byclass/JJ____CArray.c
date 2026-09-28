/* JJ::?$CArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: JJ::?$CArray[1] */
/* 008a03ac  FUN_008a03ac  48 bytes, 0 callers */

void FUN_008a03ac(byte param_1)

{
  ~CArray<>();
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



