/* AAU1::UAFX_AUTOHIDE_DOCKSITE_SAVE_INFO::?$CList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: AAU1::UAFX_AUTOHIDE_DOCKSITE_SAVE_INFO::?$CList[1] */
/* 00844e50  FUN_00844e50  100 bytes, 0 callers */

void FUN_00844e50(byte param_1)

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
  *in_ECX = CList<AFX_AUTOHIDE_DOCKSITE_SAVE_INFO,AFX_AUTOHIDE_DOCKSITE_SAVE_INFO&>::vftable;
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




/* vtable slots: AAU1::UAFX_AUTOHIDE_DOCKSITE_SAVE_INFO::?$CList[2] */
/* 00848f7b  Serialize  157 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CList<struct AFX_AUTOHIDE_DOCKSITE_SAVE_INFO,struct
   AFX_AUTOHIDE_DOCKSITE_SAVE_INFO &>::Serialize(class CArchive &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CList<AFX_AUTOHIDE_DOCKSITE_SAVE_INFO,AFX_AUTOHIDE_DOCKSITE_SAVE_INFO&>::Serialize
          (CList<AFX_AUTOHIDE_DOCKSITE_SAVE_INFO,AFX_AUTOHIDE_DOCKSITE_SAVE_INFO&> *this,
          CArchive *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  AFX_AUTOHIDE_DOCKSITE_SAVE_INFO local_5c [84];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x848f87;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    for (iVar1 = FUN_007a6ad2(); iVar1 != 0; iVar1 = iVar1 + -1) {
      _eh_vector_constructor_iterator_(local_5c,0x48,1,FUN_00844934,FUN_00844c15);
      local_8 = 0;
      FUN_008447fe(param_1,local_5c,1);
      AddTail(this,local_5c);
      local_8 = 0xffffffff;
      _eh_vector_destructor_iterator_(local_5c,0x48,1,FUN_00844c15);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(this + 0xc));
    for (puVar2 = *(undefined4 **)(this + 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      FUN_008447fe(param_1,puVar2 + 2,1);
    }
  }
  FUN_008d9b68();
  return;
}



