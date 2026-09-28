/* U1::UCMFCRestoredTabInfo::?$CList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: U1::UCMFCRestoredTabInfo::?$CList[1] */
/* 008072b9  FUN_008072b9  100 bytes, 0 callers */

void FUN_008072b9(byte param_1)

{
  CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo> *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00944167;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  *(undefined ***)in_ECX = CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo>::vftable;
  CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo>::RemoveAll(in_ECX);
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




/* vtable slots: U1::UCMFCRestoredTabInfo::?$CList[2] */
/* 0080a8f4  Serialize  167 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CList<struct CMFCRestoredTabInfo,struct
   CMFCRestoredTabInfo>::Serialize(class CArchive &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo>::Serialize
          (CList<CMFCRestoredTabInfo,CMFCRestoredTabInfo> *this,CArchive *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  CArchive *pCVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  undefined1 local_2c [36];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x80a900;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    for (iVar1 = FUN_007a6ad2(); iVar1 != 0; iVar1 = iVar1 + -1) {
      puVar4 = local_2c;
      uVar3 = 0x80a953;
      _eh_vector_constructor_iterator_(puVar4,0x18,1,FUN_00807009,FUN_00807255);
      local_8 = 0;
      puVar7 = local_2c;
      uVar8 = 1;
      uVar5 = 0x80a963;
      pCVar6 = param_1;
      FUN_00806ccc(param_1,puVar7,1);
      FUN_00806fc4(local_2c);
      AddTail(this,uVar3,puVar4,uVar5,pCVar6,puVar7,uVar8);
      local_8 = 0xffffffff;
      _eh_vector_destructor_iterator_(local_2c,0x18,1,FUN_00807255);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(this + 0xc));
    for (puVar2 = *(undefined4 **)(this + 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      FUN_00806ccc(param_1,puVar2 + 2,1);
    }
  }
  return;
}



