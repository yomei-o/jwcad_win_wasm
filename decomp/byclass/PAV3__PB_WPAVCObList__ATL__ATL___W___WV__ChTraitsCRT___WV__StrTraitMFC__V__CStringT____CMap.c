/* PAV3::PB_WPAVCObList::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: PAV3::PB_WPAVCObList::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[1] */
/* 008849df  FUN_008849df  100 bytes, 0 callers */

void FUN_008849df(byte param_1)

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
  *in_ECX = CMap<ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>,wchar_t_const*,CObList*,CObList*>
            ::vftable;
  FUN_007c974f(uVar1);
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



