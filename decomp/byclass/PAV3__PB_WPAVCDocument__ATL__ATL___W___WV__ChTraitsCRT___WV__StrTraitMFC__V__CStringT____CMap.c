/* PAV3::PB_WPAVCDocument::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: PAV3::PB_WPAVCDocument::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[1] */
/* 007c81cd  FUN_007c81cd  100 bytes, 0 callers */

void FUN_007c81cd(byte param_1)

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
  *in_ECX = CMap<ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>,wchar_t_const*,CDocument*,CDocument*>
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




/* vtable slots: PAV3::PB_WPAVCDocument::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[2], PAV3::PB_WPAVCObList::ATL::ATL::_W::_WV?$ChTraitsCRT::_WV?$StrTraitMFC::V?$CStringT::?$CMap[2] */
/* 007ca37d  Serialize  240 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CMap<class ATL::CStringT<char,class StrTraitMFC<char,class
   ATL::ChTraitsCRT<char> > >,char const *,int,int>::Serialize(class CArchive &)
    public: virtual void __thiscall CMap<class ATL::CStringT<char,class StrTraitMFC<char,class
   ATL::ChTraitsCRT<char> > >,char const *,struct HMENU__ *,struct HMENU__ *>::Serialize(class
   CArchive &)
    public: virtual void __thiscall CMap<class ATL::CStringT<char,class StrTraitMFC<char,class
   ATL::ChTraitsCRT<char> > >,char const *,struct IObjectCollection *,struct IObjectCollection
   *>::Serialize(class CArchive &)
    public: virtual void __thiscall CMap<class ATL::CStringT<char,class StrTraitMFC<char,class
   ATL::ChTraitsCRT<char> > >,char const *,class CDocument *,class CDocument *>::Serialize(class
   CArchive &)
     10 names - too many to list
   
   Library: Visual Studio 2015 Release */

void Serialize(CArchive *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  uint uVar4;
  undefined4 local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x7ca389;
  local_14[0] = in_ECX;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    for (iVar2 = FUN_007a6ad2(); iVar2 != 0; iVar2 = iVar2 + -1) {
      _eh_vector_constructor_iterator_(local_14,4,1,CStringT<>,FUN_00404540);
      local_8 = 0;
      thunk_FUN_0078f3cb(param_1,local_14,1);
      FUN_00799245(param_1,&local_18,1);
      uVar1 = local_18;
      puVar3 = (undefined4 *)FUN_007c8090(local_14[0]);
      local_8 = 0xffffffff;
      *puVar3 = uVar1;
      _eh_vector_destructor_iterator_(local_14,4,1,FUN_00404540);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 0xc));
    uVar4 = 0;
    if (((*(int *)(in_ECX + 0xc) != 0) && (*(int *)(in_ECX + 4) != 0)) &&
       (*(int *)(in_ECX + 8) != 0)) {
      do {
        for (iVar2 = *(int *)(*(int *)(in_ECX + 4) + uVar4 * 4); iVar2 != 0;
            iVar2 = *(int *)(iVar2 + 8)) {
          thunk_FUN_0078f3cb(param_1,iVar2,1);
          FUN_00799245(param_1,iVar2 + 4,1);
          in_ECX = local_14[0];
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 8));
    }
  }
  return;
}



