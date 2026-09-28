/* CMFCRibbonSeparator -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonSeparator[1] */
/* 00863134  FUN_00863134  51 bytes, 0 callers */

void FUN_00863134(byte param_1)

{
  FUN_00863031();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonSeparator[93] */
/* 008633c2  FUN_008633c2  150 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

WPARAM FUN_008633c2(int param_1)

{
  int iVar1;
  LPARAM *pLVar2;
  WPARAM wParam;
  LPARAM in_ECX;
  UINT in_stack_ffffffd8;
  LPSTR in_stack_ffffffdc;
  int in_stack_ffffffe0;
  wchar_t local_18 [8];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8633ce;
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    CStringT<>();
    local_8 = 0;
    iVar1 = FID_conflict_LoadStringA
                      ((HINSTANCE)0x42c7,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0);
    if (iVar1 != 0) {
      pLVar2 = (LPARAM *)
               ATL::operator+(local_18,(CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                                        *)&DAT_0095b620);
      wParam = SendMessageW(*(HWND *)(param_1 + 0x20),0x180,0,*pLVar2);
      FUN_00406b10();
      SendMessageW(*(HWND *)(param_1 + 0x20),0x19a,wParam,in_ECX);
      FUN_00406b10();
      return wParam;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCRibbonSeparator[90] */
/* 00863615  CopyFrom  34 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCRibbonSeparator::CopyFrom(class CMFCRibbonBaseElement
   const &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCRibbonSeparator::CopyFrom(CMFCRibbonSeparator *this,CMFCRibbonBaseElement *param_1)

{
  CMFCRibbonBaseElement::CopyFrom((CMFCRibbonBaseElement *)this,param_1);
  *(undefined4 *)(this + 0x10c) = *(undefined4 *)(param_1 + 0x10c);
  return;
}




/* vtable slots: CMFCRibbonSeparator[62] */
/* 00863a03  FUN_00863a03  18 bytes, 0 callers */

void FUN_00863a03(undefined4 *param_1)

{
  *param_1 = 4;
  param_1[1] = 4;
  return;
}




/* vtable slots: CMFCRibbonSeparator[0] */
/* 00863a21  FUN_00863a21  6 bytes, 0 callers */

undefined ** FUN_00863a21(void)

{
  return &PTR_s_CMFCRibbonSeparator_00998170;
}




/* vtable slots: CMFCRibbonSeparator[95] */
/* 00863fd1  FUN_00863fd1  424 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00863fd1(undefined4 param_1)

{
  code *pcVar1;
  BOOL BVar2;
  int *piVar3;
  int iVar4;
  CMFCRibbonBaseElement *in_ECX;
  CMFCRibbonBar *local_24;
  undefined4 local_20;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  BVar2 = IsRectEmpty((RECT *)(in_ECX + 0x74));
  if (BVar2 == 0) {
    local_18.left = ((RECT *)(in_ECX + 0x74))->left;
    local_18.top = *(LONG *)(in_ECX + 0x78);
    local_18.right = *(LONG *)(in_ECX + 0x7c);
    local_18.bottom = *(LONG *)(in_ECX + 0x80);
    if (*(int *)(in_ECX + 0xc4) == 0) {
      if (*(int *)(in_ECX + 0x10c) == 0) {
        local_18.left = (local_18.right + local_18.left) / 2;
        local_18.right = local_18.left + 1;
        InflateRect(&local_18,0,-5);
      }
      else {
        local_18.top = (local_18.bottom + local_18.top) / 2;
        local_18.bottom = local_18.top + 1;
      }
      local_24 = *(CMFCRibbonBar **)(in_ECX + 0x94);
      if ((local_24 == (CMFCRibbonBar *)0x0) &&
         (local_24 = CMFCRibbonBaseElement::GetTopLevelRibbonBar(in_ECX),
         local_24 == (CMFCRibbonBar *)0x0)) {
        return;
      }
      local_20 = 0;
      if ((*(int *)(in_ECX + 0xec) != 0) && (*(int *)(in_ECX + 0x94) != 0)) {
        local_20 = *(undefined4 *)(*(int *)(in_ECX + 0x94) + 0xd40);
        piVar3 = (int *)FUN_007c2574();
        pcVar1 = *(code **)(*piVar3 + 0x2dc);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        local_18.left = local_18.left + 2 + iVar4 * 2;
        *(undefined4 *)(*(int *)(in_ECX + 0x94) + 0xd40) = 0;
      }
      piVar3 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar3 + 0x48);
      guard_check_icall(param_1,local_24,local_18.left,local_18.top,local_18.right,local_18.bottom,
                        *(int *)(in_ECX + 0x10c) == 0);
      (*pcVar1)();
      if (*(int *)(in_ECX + 0x94) != 0) {
        *(undefined4 *)(*(int *)(in_ECX + 0x94) + 0xd40) = local_20;
      }
    }
    else {
      local_18.right = (local_18.right + local_18.left) / 2;
      local_18.left = local_18.right + -1;
      local_18.right = local_18.right + 1;
      InflateRect(&local_18,0,-3);
      piVar3 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar3 + 0x2ac);
      guard_check_icall(param_1,in_ECX,local_18.left,local_18.top,local_18.right,local_18.bottom);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonSeparator[94] */
/* 00864325  FUN_00864325  116 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00864325(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xd4);
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  InflateRect((LPRECT)&param_4,-3,0);
  param_4 = param_4 + param_3;
  iVar2 = *param_1;
  guard_check_icall(param_2,*(undefined4 *)(param_2 + -0xc),&param_4,0x824);
  (**(code **)(iVar2 + 0x68))();
  *(undefined4 *)(in_ECX + 0xd4) = uVar1;
  FUN_00406b10();
  return;
}



