/* U1::UtagPOINT::?$CList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: U1::UtagPOINT::?$CList[1] */
/* 007f26c9  FUN_007f26c9  100 bytes, 0 callers */

void FUN_007f26c9(byte param_1)

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
  *in_ECX = CList<tagPOINT,tagPOINT>::vftable;
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




/* vtable slots: U1::UtagPOINT::?$CList[2] */
/* 007fa5cf  FUN_007fa5cf  105 bytes, 0 callers */

void FUN_007fa5cf(CArchive *param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  int local_c;
  int local_8;
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    local_c = in_ECX;
    local_8 = in_ECX;
    for (iVar1 = FUN_007a6ad2(); iVar1 != 0; iVar1 = iVar1 + -1) {
      FUN_007f23b8(param_1,&local_c,1);
      FUN_007f27d0(local_c,local_8);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 0xc));
    for (puVar2 = *(undefined4 **)(in_ECX + 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      FUN_007f23b8(param_1,puVar2 + 2,1);
    }
  }
  return;
}



