/* PB_W::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::KKV?$CStringT::?$CMap -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: PB_W::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::KKV?$CStringT::?$CMap[2], PB_W::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::PAV1::PAVCDocument::?$CMap[2] */
/* 007ca290  FUN_007ca290  237 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007ca290(CArchive *param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x7ca29c;
  local_18 = in_ECX;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    for (iVar1 = FUN_007a6ad2(); iVar1 != 0; iVar1 = iVar1 + -1) {
      _eh_vector_constructor_iterator_(local_14,4,1,CStringT<>,FUN_00404540);
      local_8 = 0;
      FUN_00799245(param_1,&local_18,1);
      thunk_FUN_0078f3cb(param_1,local_14,1);
      FUN_007ca683(local_18,local_14[0]);
      local_8 = 0xffffffff;
      _eh_vector_destructor_iterator_(local_14,4,1,FUN_00404540);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 0xc));
    uVar2 = 0;
    if (((*(int *)(in_ECX + 0xc) != 0) && (*(int *)(in_ECX + 4) != 0)) &&
       (*(int *)(in_ECX + 8) != 0)) {
      do {
        iVar1 = *(int *)(*(int *)(in_ECX + 4) + uVar2 * 4);
        local_14[0] = iVar1;
        for (; iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
          FUN_00799245(param_1,iVar1,1);
          thunk_FUN_0078f3cb(param_1,iVar1 + 4,1);
          in_ECX = local_18;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(in_ECX + 8));
    }
  }
  return;
}




/* vtable slots: PB_W::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::KKV?$CStringT::?$CMap[1] */
/* 00822631  FUN_00822631  100 bytes, 0 callers */

void FUN_00822631(byte param_1)

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
  *in_ECX = CMap<unsigned_long,unsigned_long,ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>,wchar_t_const*>
            ::vftable;
  FUN_007c96f1(uVar1);
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



