/* CImageList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CImageList[1] */
/* 007a4025  FUN_007a4025  48 bytes, 0 callers */

void FUN_007a4025(byte param_1)

{
  FUN_007a3d19();
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




/* vtable slots: CImageList[0] */
/* 007a45c6  FUN_007a45c6  6 bytes, 0 callers */

undefined ** FUN_007a45c6(void)

{
  return &PTR_s_CImageList_0097eaa0;
}



