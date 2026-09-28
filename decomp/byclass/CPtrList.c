/* CPtrList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPtrList[1] */
/* 007c547a  FUN_007c547a  100 bytes, 0 callers */

void FUN_007c547a(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00944167;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *in_ECX = CPtrList::vftable;
  RemoveAll(uVar1);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CPtrList[0] */
/* 007c54e3  FUN_007c54e3  6 bytes, 0 callers */

undefined ** FUN_007c54e3(void)

{
  return &PTR_s_CPtrList_009850b8;
}



