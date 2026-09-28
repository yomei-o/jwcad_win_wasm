/* CMFCRibbonUndoButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonUndoButton[1] */
/* 008c65d2  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonUndoButton::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonUndoButton::_scalar_deleting_destructor_(CMFCRibbonUndoButton *this,uint param_1)

{
  ~CMFCRibbonUndoButton(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x3a8);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonUndoButton[90] */
/* 008c66b8  FUN_008c66b8  103 bytes, 0 callers */

void FUN_008c66b8(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_008af26e(param_1);
  *(undefined4 *)(in_ECX + 0x378) = *(undefined4 *)(param_1 + 0x378);
  FUN_007bf7c0(0,0xffffffff);
  CStringArray::Copy((CStringArray *)(in_ECX + 0x390),(CStringArray *)(param_1 + 0x390));
  *(undefined4 *)(in_ECX + 0x34c) = *(undefined4 *)(param_1 + 0x34c);
  uVar1 = *(undefined4 *)(param_1 + 0x380);
  *(undefined4 *)(in_ECX + 0x37c) = *(undefined4 *)(param_1 + 0x37c);
  *(undefined4 *)(in_ECX + 0x380) = uVar1;
  return;
}




/* vtable slots: CMFCRibbonUndoButton[163] */
/* 008c6780  FUN_008c6780  27 bytes, 0 callers */

void FUN_008c6780(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0x380);
  *param_1 = *(undefined4 *)(in_ECX + 0x37c);
  param_1[1] = uVar1;
  return;
}




/* vtable slots: CMFCRibbonUndoButton[0] */
/* 008c679b  FUN_008c679b  6 bytes, 0 callers */

undefined ** FUN_008c679b(void)

{
  return &PTR_s_CMFCRibbonUndoButton_009a46b8;
}




/* vtable slots: CMFCRibbonUndoButton[128] */
/* 008c67a7  FUN_008c67a7  245 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008c67a7(int param_1)

{
  int iVar1;
  code *pcVar2;
  CObject *pCVar3;
  int *piVar4;
  CMFCRibbonBaseElement *in_ECX;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8c67b3;
  if (*(int *)(in_ECX + 0x9c) != 0) {
    *(int *)(in_ECX + 0x378) = param_1 + 1;
    local_14[0] = FUN_004054a0(*(int *)(in_ECX + 900) + -0x10);
    local_14[0] = local_14[0] + 0x10;
    iVar1 = *(int *)(in_ECX + 0x378);
    local_8 = 0;
    if (0 < iVar1) {
      if (iVar1 == 1) {
        ATL::CSimpleStringT<wchar_t,0>::operator=
                  ((CSimpleStringT<wchar_t,0> *)local_14,
                   (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x388));
      }
      else {
        FUN_004059f0(local_14,*(undefined4 *)(in_ECX + 0x38c),iVar1);
      }
    }
    iVar1 = local_14[0];
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonPanelMenu_009a1ee8,
                                *(CObject **)(in_ECX + 0x9c));
    if (((pCVar3 != (CObject *)0x0) && (*(int *)(pCVar3 + 0x201c) != 0)) &&
       (piVar4 = (int *)FUN_0086b05e(0), piVar4 != (int *)0x0)) {
      pcVar2 = *(code **)(*piVar4 + 0xb4);
      guard_check_icall(iVar1);
      (*pcVar2)();
      pcVar2 = *(code **)(*piVar4 + 0x1b8);
      guard_check_icall();
      (*pcVar2)();
    }
    FUN_008b0dd5();
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  CMFCRibbonBaseElement::NotifyHighlightListItem(in_ECX,param_1);
  return;
}




/* vtable slots: CMFCRibbonUndoButton[153] */
/* 008c689c  FUN_008c689c  25 bytes, 0 callers */

void FUN_008c689c(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x378) = 0xffffffff;
  FUN_008683f7(param_1,param_2);
  return;
}




/* vtable slots: CMFCRibbonUndoButton[166] */
/* 008c68b5  FUN_008c68b5  57 bytes, 0 callers */

bool FUN_008c68b5(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = FUN_0079d98a(&PTR_s_CRibbonUndoLabel_009a4980);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x198);
    guard_check_icall();
    (*pcVar1)();
  }
  return iVar2 != 0;
}




/* vtable slots: CMFCRibbonUndoButton[169] */
/* 008c695f  FUN_008c695f  269 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c695f(int *param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int param_6,
                 int *param_7,int param_8)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 uVar5;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar1 = param_7[0x36];
  param_7[0x36] = 0;
  iVar2 = param_7[0x32];
  param_7[0x32] = (uint)(param_6 < *(int *)(in_ECX + 0x378));
  pcVar3 = *(code **)(*param_7 + 0x270);
  guard_check_icall(param_1);
  (*pcVar3)();
  local_18.left = param_2;
  local_18.top = param_3;
  local_18.right = param_4;
  local_18.bottom = param_5;
  InflateRect(&local_18,-5,0);
  uVar5 = 0xffffffff;
  if (param_8 != -1) {
    pcVar3 = *(code **)(*param_1 + 0x30);
    guard_check_icall(param_8);
    uVar5 = (*pcVar3)();
  }
  uVar4 = FUN_0049a990(param_6);
  FUN_007c2378(uVar4,&local_18,0x24);
  if (param_8 != -1) {
    pcVar3 = *(code **)(*param_1 + 0x30);
    guard_check_icall(uVar5);
    (*pcVar3)();
  }
  pcVar3 = *(code **)(*param_7 + 0x274);
  guard_check_icall(param_1);
  (*pcVar3)();
  param_7[0x36] = iVar1;
  param_7[0x32] = iVar2;
  return;
}




/* vtable slots: CMFCRibbonUndoButton[79] */
/* 008c6a6c  FUN_008c6a6c  348 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008c6a6c(void)

{
  CMFCRibbonBaseElement *pCVar1;
  int iVar2;
  CMFCRibbonBar *this;
  CFont *pCVar3;
  undefined4 uVar4;
  int *piVar5;
  CMFCRibbonBaseElement *in_ECX;
  int iVar6;
  undefined1 local_24 [8];
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x8c6a78;
  CMFCRibbonBaseElement::OnShowPopupMenu(in_ECX);
  iVar6 = 0;
  *(undefined4 *)(in_ECX + 0x358) = 0;
  iVar2 = FUN_00420890(0,0);
  if (iVar2 != 0) {
    this = CMFCRibbonBaseElement::GetTopLevelRibbonBar(in_ECX);
    FUN_0079dea2(this);
    local_8 = 0;
    pCVar3 = CWnd::GetFont((CWnd *)this);
    local_14 = FUN_0079efbc(pCVar3);
    pCVar1 = in_ECX + 0x37c;
    if (0 < *(int *)(in_ECX + 0x398)) {
      do {
        uVar4 = FUN_0049a990(iVar6);
        FUN_00566800(&local_1c,uVar4);
        iVar2 = *(int *)pCVar1;
        if (*(int *)pCVar1 <= local_1c) {
          iVar2 = local_1c;
        }
        *(int *)pCVar1 = iVar2;
        iVar2 = *(int *)(in_ECX + 0x380);
        if (*(int *)(in_ECX + 0x380) <= local_18) {
          iVar2 = local_18;
        }
        *(int *)(in_ECX + 0x380) = iVar2;
        iVar6 = iVar6 + 1;
      } while (iVar6 < *(int *)(in_ECX + 0x398));
    }
    piVar5 = (int *)FUN_00566800(&local_1c,in_ECX + 900);
    iVar2 = *(int *)pCVar1;
    if (iVar2 <= *piVar5) {
      piVar5 = (int *)FUN_00566800(local_24,in_ECX + 900);
      iVar2 = *piVar5;
    }
    *(int *)pCVar1 = iVar2;
    piVar5 = (int *)FUN_00566800(local_24,in_ECX + 0x388);
    iVar2 = *(int *)pCVar1;
    if (iVar2 <= *piVar5) {
      piVar5 = (int *)FUN_00566800(&local_1c,in_ECX + 0x388);
      iVar2 = *piVar5;
    }
    *(int *)pCVar1 = iVar2;
    piVar5 = (int *)FUN_00566800(local_24,in_ECX + 0x38c);
    iVar2 = *(int *)pCVar1;
    if (iVar2 <= *piVar5) {
      piVar5 = (int *)FUN_00566800(&local_1c,in_ECX + 0x38c);
      iVar2 = *piVar5;
    }
    *(int *)pCVar1 = iVar2 + 10;
    FUN_0079efbc(local_14);
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  *(undefined4 *)(in_ECX + 0x378) = 0xffffffff;
  FUN_008b0950();
  return;
}



