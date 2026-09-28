/* AAU12::CMFCDynamicLayoutData::UItem::?$CList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: AAU12::CMFCDynamicLayoutData::UItem::?$CList[1] */
/* 007c3acc  FUN_007c3acc  100 bytes, 0 callers */

void FUN_007c3acc(byte param_1)

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
  *in_ECX = CList<CMFCDynamicLayoutData::Item,CMFCDynamicLayoutData::Item&>::vftable;
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




/* vtable slots: AAU12::CMFCDynamicLayoutData::UItem::?$CList[2] */
/* 007c44a4  FUN_007c44a4  120 bytes, 0 callers */

void FUN_007c44a4(CArchive *param_1)

{
  int iVar1;
  CList<CMFCDynamicLayoutData::Item,CMFCDynamicLayoutData::Item&> *in_ECX;
  undefined4 *puVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    for (iVar1 = FUN_007a6ad2(); iVar1 != 0; iVar1 = iVar1 + -1) {
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      local_8 = 0;
      FUN_007c3865(param_1,&local_14,1);
      CList<CMFCDynamicLayoutData::Item,CMFCDynamicLayoutData::Item&>::AddTail
                (in_ECX,(Item *)&local_14);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 0xc));
    for (puVar2 = *(undefined4 **)(in_ECX + 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      FUN_007c3865(param_1,puVar2 + 2,1);
    }
  }
  return;
}



