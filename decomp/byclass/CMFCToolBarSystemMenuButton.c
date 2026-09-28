/* CMFCToolBarSystemMenuButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarSystemMenuButton[1] */
/* 00889b88  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CPrintDialog::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CPrintDialog::_scalar_deleting_destructor_(CPrintDialog *this,uint param_1)

{
  *(undefined ***)this = CMFCToolBarSystemMenuButton::vftable;
  FUN_00874eb0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xf0);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarSystemMenuButton[5] */
/* 00889bc1  CopyFrom  46 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCToolBarSystemMenuButton::CopyFrom(class CMFCToolBarButton
   const &)
   
   Library: Visual Studio 2012 Release */

void __thiscall
CMFCToolBarSystemMenuButton::CopyFrom(CMFCToolBarSystemMenuButton *this,CMFCToolBarButton *param_1)

{
  FUN_0087503b(param_1);
  *(undefined4 *)(this + 0xe8) = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(this + 0xec) = *(undefined4 *)(param_1 + 0xec);
  return;
}




/* vtable slots: CMFCToolBarSystemMenuButton[52] */
/* 00889bef  FUN_00889bef  16 bytes, 0 callers */

void FUN_00889bef(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xec) = param_1;
  return;
}




/* vtable slots: CMFCToolBarSystemMenuButton[53] */
/* 00889bff  FUN_00889bff  198 bytes, 0 callers */

HMENU__ * FUN_00889bff(void)

{
  HMENU__ *pHVar1;
  CMenu *pCVar2;
  CMenu *pCVar3;
  int iVar4;
  UINT UVar5;
  UINT uIDCheckItem;
  int in_ECX;
  UINT uId;
  
  uId = 0;
  if (*(int *)(in_ECX + 0xec) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pHVar1 = (HMENU__ *)FUN_00875309();
  if (pHVar1 != (HMENU__ *)0x0) {
    pCVar2 = CMenu::FromHandle(pHVar1);
    pCVar3 = CMenu::FromHandle(*(HMENU__ **)(in_ECX + 0xec));
    iVar4 = GetMenuItemCount(*(HMENU *)(pCVar3 + 4));
    if (0 < iVar4) {
      do {
        UVar5 = GetMenuState(*(HMENU *)(pCVar3 + 4),uId,0x400);
        uIDCheckItem = GetMenuItemID(*(HMENU *)(pCVar3 + 4),uId);
        if ((UVar5 & 8) != 0) {
          CheckMenuItem(*(HMENU *)(pCVar2 + 4),uIDCheckItem,8);
        }
        if ((UVar5 & 2) != 0) {
          EnableMenuItem(*(HMENU *)(pCVar2 + 4),uIDCheckItem,2);
        }
        if ((UVar5 & 1) != 0) {
          EnableMenuItem(*(HMENU *)(pCVar2 + 4),uIDCheckItem,1);
        }
        uId = uId + 1;
      } while ((int)uId < iVar4);
    }
  }
  return pHVar1;
}




/* vtable slots: CMFCToolBarSystemMenuButton[0] */
/* 00889cc6  FUN_00889cc6  6 bytes, 0 callers */

undefined ** FUN_00889cc6(void)

{
  return &PTR_s_CMFCToolBarSystemMenuButton_00a00b28;
}




/* vtable slots: CMFCToolBarSystemMenuButton[55] */
/* 00889ccc  OnAfterCreatePopupMenu  128 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCToolBarSystemMenuButton::OnAfterCreatePopupMenu(void)
   
   Library: Visual Studio 2012 Release */

void __thiscall
CMFCToolBarSystemMenuButton::OnAfterCreatePopupMenu(CMFCToolBarSystemMenuButton *this)

{
  BOOL BVar1;
  CObject *pCVar2;
  int iVar3;
  HWND pHVar4;
  CMDIChildWnd *pCVar5;
  
  if (*(int *)(this + 0x8c) == 0) {
    return;
  }
  BVar1 = IsWindow(*(HWND *)(*(int *)(this + 0x8c) + 0x20));
  if (BVar1 != 0) {
    pCVar2 = DAT_00a13a1c;
    if (((DAT_00a13a1c != (CObject *)0x0) ||
        (pCVar2 = (CObject *)FUN_00792b4c(), pCVar2 != (CObject *)0x0)) &&
       (iVar3 = FUN_0079d98a(&PTR_s_CMiniDockFrameWnd_00981e74), iVar3 != 0)) {
      pHVar4 = GetParent(*(HWND *)(pCVar2 + 0x20));
      pCVar2 = (CObject *)CWnd::FromHandle(pHVar4);
    }
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWnd_0099f564,pCVar2);
    if (pCVar2 != (CObject *)0x0) {
      pCVar5 = CMDIFrameWnd::MDIGetActive((CMDIFrameWnd *)pCVar2,(int *)0x0);
      *(CMDIChildWnd **)(*(int *)(this + 0x8c) + 0x134) = pCVar5;
    }
    return;
  }
  return;
}




/* vtable slots: CMFCToolBarSystemMenuButton[7] */
/* 00889d4c  FUN_00889d4c  33 bytes, 0 callers */

void FUN_00889d4c(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_3 + 4);
  iVar2 = GetSystemMetrics(0x36);
  param_1[1] = iVar1;
  *param_1 = iVar2;
  return;
}




/* vtable slots: CMFCToolBarSystemMenuButton[22] */
/* 00889d6d  FUN_00889d6d  128 bytes, 0 callers */

void FUN_00889d6d(void)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x8c) != 0) &&
     (BVar2 = IsWindow(*(HWND *)(*(int *)(in_ECX + 0x8c) + 0x20)), BVar2 != 0)) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x8c) + 0x1cc);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      return;
    }
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x8c) + 0x1e0);
    guard_check_icall();
    (*pcVar1)();
    *(undefined4 *)(*(int *)(in_ECX + 0x8c) + 0x130) = 0;
    FUN_0081c095(0);
  }
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0xa4) = 0;
  return;
}




/* vtable slots: CMFCToolBarSystemMenuButton[19] */
/* 00889ded  FUN_00889ded  239 bytes, 0 callers */

void FUN_00889ded(int param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  HWND pHVar4;
  CMDIChildWnd *pCVar5;
  HMENU pHVar6;
  CMenu *pCVar7;
  int *in_ECX;
  tagMENUITEMINFOW local_38;
  
  if (DAT_00a127ac == 0) {
    if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    pcVar1 = *(code **)(*in_ECX + 0x58);
    guard_check_icall();
    (*pcVar1)();
    pCVar2 = (CObject *)FUN_007e5618(param_1);
    if ((pCVar2 != (CObject *)0x0) &&
       (iVar3 = FUN_0079d98a(&PTR_s_CMiniDockFrameWnd_00981e74), iVar3 != 0)) {
      pHVar4 = GetParent(*(HWND *)(pCVar2 + 0x20));
      pCVar2 = (CObject *)CWnd::FromHandle(pHVar4);
    }
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWnd_0099f564,pCVar2);
    if (pCVar2 != (CObject *)0x0) {
      pCVar5 = CMDIFrameWnd::MDIGetActive((CMDIFrameWnd *)pCVar2,(int *)0x0);
      pHVar6 = GetSystemMenu(*(HWND *)(pCVar5 + 0x20),0);
      pCVar7 = CMenu::FromHandle(pHVar6);
      if (pCVar7 != (CMenu *)0x0) {
        _memset(&local_38,0,0x30);
        local_38.cbSize = 0x30;
        local_38.fMask = 1;
        GetMenuItemInfoW(*(HMENU *)(pCVar7 + 4),0xf060,0,&local_38);
        if ((local_38.fState & 3) != 0) {
          return;
        }
      }
      SendMessageW(*(HWND *)(pCVar5 + 0x20),0x112,0xf060,0);
    }
  }
  return;
}




/* vtable slots: CMFCToolBarSystemMenuButton[6] */
/* 00889edd  FUN_00889edd  154 bytes, 0 callers */

void FUN_00889edd(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  HDC hdc;
  
  if (*(int *)(in_ECX + 0xe8) != 0) {
    iVar1 = GetSystemMetrics(0x37);
    iVar2 = GetSystemMetrics(0x32);
    if (iVar2 < iVar1) {
      iVar1 = 0x32;
    }
    else {
      iVar1 = 0x37;
    }
    iVar1 = GetSystemMetrics(iVar1);
    iVar2 = GetSystemMetrics(0x36);
    iVar3 = GetSystemMetrics(0x31);
    if (iVar3 < iVar2) {
      iVar2 = 0x31;
    }
    else {
      iVar2 = 0x36;
    }
    iVar2 = GetSystemMetrics(iVar2);
    hdc = (HDC)0x0;
    if (param_1 != 0) {
      hdc = *(HDC *)(param_1 + 4);
    }
    DrawIconEx(hdc,*param_2,((param_2[3] - param_2[1]) - iVar1) / 2 + param_2[1],
               *(HICON *)(in_ECX + 0xe8),iVar2,iVar1,0,(HBRUSH)0x0,3);
  }
  return;
}



