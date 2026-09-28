/* CPreviewViewEx -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPreviewViewEx[1] */
/* 008c208c  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void * __thiscall CPreviewViewEx::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CPreviewViewEx::_scalar_deleting_destructor_(CPreviewViewEx *this,uint param_1)

{
  FUN_008c1ff7();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xed0);
    }
  }
  return this;
}




/* vtable slots: CPreviewViewEx[10] */
/* 008c20f5  FUN_008c20f5  6 bytes, 0 callers */

undefined ** FUN_008c20f5(void)

{
  return &PTR_FUN_009a38f0;
}




/* vtable slots: CPreviewViewEx[0] */
/* 008c2101  FUN_008c2101  6 bytes, 0 callers */

undefined ** FUN_008c2101(void)

{
  return &PTR_s_CPreviewViewEx_009a3618;
}




/* vtable slots: CPreviewViewEx[112] */
/* 008c23a1  FUN_008c23a1  246 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008c23a1(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_18;
  LPARAM local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8c23ad;
  if (*(int *)(in_ECX + 0x164) != 0) {
    iVar2 = FUN_007e5618();
    CStringT<>();
    local_8 = 0;
    iVar3 = AfxExtractSubString((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
                                 *)&local_18,*(wchar_t **)(*(int *)(in_ECX + 0x164) + 0x1c),
                                (uint)(param_2 != 1),L'\n');
    if (iVar3 != 0) {
      CStringT<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      if (param_2 == 1) {
        FUN_004059f0(local_14,local_18,param_1);
      }
      else {
        FUN_004059f0(local_14,local_18,param_1,param_2 + -1 + param_1);
      }
      if (*(int **)(in_ECX + 0xea8) == (int *)0x0) {
        SendMessageW(*(HWND *)(iVar2 + 0x20),0x362,0,local_14[0]);
      }
      else {
        pcVar1 = *(code **)(**(int **)(in_ECX + 0xea8) + 800);
        guard_check_icall(0xff,local_14[0],1);
        (*pcVar1)();
      }
      FUN_00406b10();
    }
    FUN_00406b10();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



