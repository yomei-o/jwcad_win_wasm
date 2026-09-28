/* CObList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CObList[1] */
/* 007a1889  FUN_007a1889  100 bytes, 0 callers */

void FUN_007a1889(byte param_1)

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
  *in_ECX = CObList::vftable;
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




/* vtable slots: CObList[0], PAVCData::VCObList::?$CTypedPtrList[0], PAVCData::VCObList::?$_CTypedPtrList[0], PAVCDataBlock::VCObList::?$CTypedPtrList[0], PAVCDataBlock::VCObList::?$_CTypedPtrList[0], PAVCDataHensuu::VCObList::?$CTypedPtrList[0], PAVCDataHensuu::VCObList::?$_CTypedPtrList[0], PAVCDataList::VCObList::?$CTypedPtrList[0], PAVCDataList::VCObList::?$_CTypedPtrList[0] */
/* 007a19fb  FUN_007a19fb  6 bytes, 0 callers */

undefined ** FUN_007a19fb(void)

{
  return &PTR_s_CObList_00a00380;
}




/* vtable slots: CObList[2], PAVCData::VCObList::?$CTypedPtrList[2], PAVCData::VCObList::?$_CTypedPtrList[2], PAVCDataBlock::VCObList::?$CTypedPtrList[2], PAVCDataBlock::VCObList::?$_CTypedPtrList[2], PAVCDataHensuu::VCObList::?$CTypedPtrList[2], PAVCDataHensuu::VCObList::?$_CTypedPtrList[2], PAVCDataList::VCObList::?$CTypedPtrList[2], PAVCDataList::VCObList::?$_CTypedPtrList[2] */
/* 007a1b6d  Serialize  93 bytes, 3 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CObList::Serialize(class CArchive &)
   
   Library: Visual Studio 2015 Release */

void __thiscall CObList::Serialize(CObList *this,CArchive *param_1)

{
  int iVar1;
  CObject *pCVar2;
  undefined4 *puVar3;
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    for (iVar1 = FUN_007a6ad2(); iVar1 != 0; iVar1 = iVar1 + -1) {
      pCVar2 = (CObject *)FUN_007a5d50(0);
      AddTail(this,pCVar2);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(this + 0xc));
    for (puVar3 = *(undefined4 **)(this + 4); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      FUN_007a619a(puVar3[2]);
    }
  }
  return;
}



