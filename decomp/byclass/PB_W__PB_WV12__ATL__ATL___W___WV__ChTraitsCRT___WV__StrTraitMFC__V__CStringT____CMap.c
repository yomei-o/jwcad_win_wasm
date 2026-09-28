/* PB_W::PB_WV12::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: PB_W::PB_WV12::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[1] */
/* 007c8236  FUN_007c8236  100 bytes, 0 callers */

void FUN_007c8236(byte param_1)

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
  *in_ECX = CMap<ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>,wchar_t_const*,ATL::CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsCRT<wchar_t>_>_>,wchar_t_const*>
            ::vftable;
  FUN_007c97ac(uVar1);
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




/* vtable slots: PB_W::PB_WV12::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[2] */
/* 007ca46d  FUN_007ca46d  294 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007ca46d(CArchive *param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int local_18;
  undefined4 local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x7ca479;
  local_18 = in_ECX;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    for (iVar1 = FUN_007a6ad2(); iVar1 != 0; iVar1 = iVar1 + -1) {
      _eh_vector_constructor_iterator_(&local_18,4,1,CStringT<>,FUN_00404540);
      local_8 = 0;
      _eh_vector_constructor_iterator_(local_14,4,1,CStringT<>,FUN_00404540);
      local_8._0_1_ = 1;
      thunk_FUN_0078f3cb(param_1,&local_18,1);
      thunk_FUN_0078f3cb(param_1,local_14,1);
      FUN_007ca6b4(local_18,local_14[0]);
      local_8 = (uint)local_8._1_3_ << 8;
      _eh_vector_destructor_iterator_(local_14,4,1,FUN_00404540);
      local_8 = 0xffffffff;
      _eh_vector_destructor_iterator_(&local_18,4,1,FUN_00404540);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 0xc));
    uVar2 = 0;
    if (((*(int *)(in_ECX + 0xc) != 0) && (*(int *)(in_ECX + 4) != 0)) &&
       (*(int *)(in_ECX + 8) != 0)) {
      do {
        for (iVar1 = *(int *)(*(int *)(in_ECX + 4) + uVar2 * 4); iVar1 != 0;
            iVar1 = *(int *)(iVar1 + 8)) {
          thunk_FUN_0078f3cb(param_1,iVar1,1);
          thunk_FUN_0078f3cb(param_1,iVar1 + 4,1);
          in_ECX = local_18;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < *(uint *)(in_ECX + 8));
    }
  }
  return;
}



