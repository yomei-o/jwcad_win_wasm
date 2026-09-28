/* CMFCTasksPaneToolBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCTasksPaneToolBar[1] */
/* 008d388c  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCTasksPaneToolBar::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCTasksPaneToolBar::_scalar_deleting_destructor_(CMFCTasksPaneToolBar *this,uint param_1)

{
  FUN_007faf4a();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xd48);
    }
  }
  return this;
}




/* vtable slots: CMFCTasksPaneToolBar[131] */
/* 008d3986  AdjustLayout  51 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCTasksPaneToolBar::AdjustLayout(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCTasksPaneToolBar::AdjustLayout(CMFCTasksPaneToolBar *this)

{
  HWND pHVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  
  FUN_007fb471();
  pHVar1 = GetParent(*(HWND *)(this + 0x20));
  pCVar2 = CWnd::FromHandle(pHVar1);
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTasksPane_00a00d6c,(CObject *)pCVar2);
  if (pCVar3 != (CObject *)0x0) {
    FUN_008d6c4c(1);
  }
  return;
}




/* vtable slots: CMFCTasksPaneToolBar[249] */
/* 008d39b9  FUN_008d39b9  336 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008d39b9(void)

{
  CObject *pCVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  CObject *pCVar5;
  int local_30;
  CObject *local_24;
  int local_20;
  CObject *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (((in_ECX != 0) && (*(int *)(in_ECX + 0x20) != 0)) &&
     (BVar2 = IsWindow(*(HWND *)(in_ECX + 0x20)), BVar2 != 0)) {
    FUN_007fb67f();
    local_20 = *(int *)(in_ECX + 0xc40);
    pCVar5 = (CObject *)0x0;
    local_24 = (CObject *)0x0;
    local_1c = (CObject *)0x0;
    while (local_20 != 0) {
      puVar3 = (undefined4 *)FUN_0044f2d0(&local_20);
      pCVar1 = (CObject *)*puVar3;
      if (((byte)pCVar1[0x24] & 1) == 0) {
        iVar4 = FUN_0079d98a(&PTR_s_CTasksPaneNavigateButton_00a00d88);
        if (iVar4 == 0) {
          iVar4 = FUN_0079d98a(&PTR_s_CTasksPaneMenuButton_00a00dc0);
          if (iVar4 != 0) {
            pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CTasksPaneMenuButton_00a00dc0,pCVar1
                                       );
          }
        }
        else {
          if (*(int *)(pCVar1 + 4) == 0) {
            iVar4 = *(int *)(pCVar1 + 0x34);
          }
          else {
            iVar4 = *(int *)(pCVar1 + 0x38);
          }
          if (iVar4 == 3) {
            local_24 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CTasksPaneNavigateButton_00a00d88,
                                          pCVar1);
          }
        }
      }
    }
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    local_1c = pCVar5;
    GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
    if (pCVar5 != (CObject *)0x0) {
      local_30 = (*(int *)(pCVar5 + 0x60) - *(int *)(pCVar5 + 0x58)) * 3 + *(int *)(pCVar5 + 0x54);
      if (local_30 <= local_18.right + -1) {
        local_30 = local_18.right + -1;
      }
      FUN_0080554f(*(int *)(pCVar5 + 0x54),*(int *)(pCVar5 + 0x58),local_30,*(int *)(pCVar5 + 0x60))
      ;
      if (local_24 != (CObject *)0x0) {
        FUN_00805aeb(0);
      }
    }
    FUN_008065ff();
  }
  return;
}




/* vtable slots: CMFCTasksPaneToolBar[10] */
/* 008d4b23  FUN_008d4b23  6 bytes, 0 callers */

undefined ** FUN_008d4b23(void)

{
  return &PTR_FUN_009a892c;
}




/* vtable slots: CMFCTasksPaneToolBar[0] */
/* 008d4c08  FUN_008d4c08  6 bytes, 0 callers */

undefined ** FUN_008d4c08(void)

{
  return &PTR_s_CMFCTasksPaneToolBar_00a00d50;
}




/* vtable slots: CMFCTasksPaneToolBar[235] */
/* 008d6998  FUN_008d6998  120 bytes, 0 callers */

undefined4 FUN_008d6998(CObject *param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  int iVar1;
  CObject *pCVar2;
  undefined4 uVar3;
  int unaff_EBP;
  LPSTR unaff_EDI;
  undefined **uID;
  
  uID = &PTR_s_CTasksPaneMenuButton_00a00dc0;
  iVar1 = FUN_0079d98a();
  if (iVar1 == 0) {
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CTasksPaneNavigateButton_00a00d88,param_1);
    if ((pCVar2 == (CObject *)0x0) &&
       (pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CTasksPaneHistoryButton_00a00da4,param_1
                                   ), pCVar2 == (CObject *)0x0)) {
      uVar3 = FUN_00803542(param_1,param_2);
      return uVar3;
    }
    ATL::CSimpleStringT<wchar_t,0>::operator=(param_2,(CSimpleStringT<wchar_t,0> *)(pCVar2 + 0x2c));
  }
  else {
    iVar1 = FID_conflict_LoadStringA((HINSTANCE)0x4280,(UINT)uID,unaff_EDI,unaff_EBP);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
  }
  return 1;
}



