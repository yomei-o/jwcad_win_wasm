/* CDC -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDC[1] */
/* 0079e17c  FUN_0079e17c  48 bytes, 0 callers */

void FUN_0079e17c(byte param_1)

{
  FUN_0079e053();
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




/* vtable slots: CDC[0] */
/* 0079eb2c  FUN_0079eb2c  6 bytes, 0 callers */

undefined ** FUN_0079eb2c(void)

{
  return &PTR_DAT_0097e000;
}



