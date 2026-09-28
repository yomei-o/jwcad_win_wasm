/* II::?$CList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: II::?$CList[2], KK::?$CList[2], PAU1::PAUAFX_DYNAMIC_LAYOUT_ITEM::?$CList[2], PAU1::PAUHINSTANCE__::?$CList[2], PAU1::PAUHWND__::?$CList[2], PAU1::PAU_ITEMIDLIST::?$CList[2], PAV1::PAVCFrameWnd::?$CList[2], PAV1::PAVCMDIChildWndEx::?$CList[2], PAV1::PAVCMFCButton::?$CList[2], PAV1::PAVCMFCPropertyGridProperty::?$CList[2], PAV1::PAVCPropertyPage::?$CList[2] */
/* 0079c821  FUN_0079c821  101 bytes, 0 callers */

void FUN_0079c821(CArchive *param_1)

{
  int iVar1;
  CList<unsigned_int,unsigned_int> *in_ECX;
  undefined4 *puVar2;
  CList<unsigned_int,unsigned_int> *local_8;
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    local_8 = in_ECX;
    for (iVar1 = FUN_007a6ad2(); iVar1 != 0; iVar1 = iVar1 + -1) {
      FUN_00799245(param_1,&local_8,1);
      CList<unsigned_int,unsigned_int>::AddTail(in_ECX,(uint)local_8);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 0xc));
    for (puVar2 = *(undefined4 **)(in_ECX + 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      FUN_00799245(param_1,puVar2 + 2,1);
    }
  }
  return;
}




/* vtable slots: II::?$CList[1] */
/* 007e708b  FUN_007e708b  100 bytes, 0 callers */

void FUN_007e708b(byte param_1)

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
  *in_ECX = CList<unsigned_int,unsigned_int>::vftable;
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



