/* CStringList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CStringList[1] */
/* 008138db  FUN_008138db  100 bytes, 0 callers */

void FUN_008138db(byte param_1)

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
  *in_ECX = CStringList::vftable;
  FUN_00813b58(uVar1);
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




/* vtable slots: CStringList[0] */
/* 00813a5f  FUN_00813a5f  6 bytes, 0 callers */

undefined ** FUN_00813a5f(void)

{
  return &PTR_s_CStringList_00a006dc;
}




/* vtable slots: CStringList[2] */
/* 00813c03  FUN_00813c03  129 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00813c03(CArchive *param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x813c0f;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    iVar1 = FUN_007a6ad2();
    CStringT<>();
    local_8 = 0;
    for (; iVar1 != 0; iVar1 = iVar1 + -1) {
      FUN_0047fc90(local_14);
      AddTail(local_14);
    }
    FUN_00406b10();
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 0xc));
    for (puVar2 = *(undefined4 **)(in_ECX + 4); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                         (puVar2 + 2));
    }
  }
  return;
}



