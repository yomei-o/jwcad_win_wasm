/* CPrintingDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPrintingDialog[1] */
/* 007b6e9f  FUN_007b6e9f  57 bytes, 0 callers */

void FUN_007b6e9f(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CPrintingDialog::vftable;
  FUN_00797fb6();
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




/* vtable slots: CPrintingDialog[97] */
/* 007b7029  FUN_007b7029  42 bytes, 0 callers */

void FUN_007b7029(void)

{
  int iVar1;
  
  iVar1 = FUN_007c0664(&LAB_007b6f03);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 4) = 1;
    FUN_00798826();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CPrintingDialog[94] */
/* 007b7a35  FUN_007b7a35  36 bytes, 0 callers */

void FUN_007b7a35(void)

{
  int iVar1;
  
  iVar1 = FUN_0079dd6d();
  FUN_00797ece(*(undefined4 *)(iVar1 + 0x10));
  FUN_00791d1f(0);
  FUN_00798993();
  return;
}



