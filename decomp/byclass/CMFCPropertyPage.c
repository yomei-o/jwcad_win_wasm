/* CMFCPropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCPropertyPage[1] */
/* 007c2a24  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCPropertyPage::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCPropertyPage::_scalar_deleting_destructor_(CMFCPropertyPage *this,uint param_1)

{
  ~CMFCPropertyPage(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xd8);
    }
  }
  return this;
}




/* vtable slots: CMFCPropertyPage[10] */
/* 007c2aa4  FUN_007c2aa4  6 bytes, 0 callers */

undefined ** FUN_007c2aa4(void)

{
  return &PTR_FUN_00984c38;
}




/* vtable slots: CMFCPropertyPage[0] */
/* 007c2aaa  FUN_007c2aaa  6 bytes, 0 callers */

undefined ** FUN_007c2aaa(void)

{
  return &PTR_s_CMFCPropertyPage_009849f0;
}




/* vtable slots: CMFCPropertyPage[94] */
/* 007c2c2a  FUN_007c2c2a  193 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007c2c2a(void)

{
  int dy;
  undefined4 uVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  CObject *pCVar4;
  CWnd *in_ECX;
  UINT uCmd;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar1 = FUN_00798993();
  pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPropertySheet_00984998,(CObject *)pCVar3);
  if ((pCVar4 != (CObject *)0x0) && (dy = *(int *)(pCVar4 + 0x4dc0), dy != 0)) {
    uCmd = 5;
    pHVar2 = *(HWND *)(in_ECX + 0x20);
    while( true ) {
      pHVar2 = GetWindow(pHVar2,uCmd);
      pCVar3 = CWnd::FromHandle(pHVar2);
      if (pCVar3 == (CWnd *)0x0) break;
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      GetWindowRect(*(HWND *)(pCVar3 + 0x20),&local_18);
      CWnd::ScreenToClient(in_ECX,&local_18);
      OffsetRect(&local_18,0,dy);
      FUN_00797e71(0,local_18.left,local_18.top,0xffffffff,0xffffffff,0x15);
      uCmd = 2;
      pHVar2 = *(HWND *)(pCVar3 + 0x20);
    }
  }
  return uVar1;
}




/* vtable slots: CMFCPropertyPage[101] */
/* 007c2d25  FUN_007c2d25  70 bytes, 0 callers */

void FUN_007c2d25(void)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  CObject *pCVar4;
  int in_ECX;
  
  pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPropertySheet_00984998,(CObject *)pCVar3);
  if (pCVar4 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar4 + 0x17c);
    guard_check_icall();
    (*pcVar1)();
  }
  FUN_007a0f5c();
  return;
}




/* vtable slots: CMFCPropertyPage[67] */
/* 007c2d6b  PreTranslateMessage  44 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCPropertyPage::PreTranslateMessage(struct tagMSG *)
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCPropertyPage::PreTranslateMessage(CMFCPropertyPage *this,tagMSG *param_1)

{
  int iVar1;
  
  iVar1 = FUN_007ec9f3(param_1);
  if (iVar1 == 0) {
    iVar1 = CPropertyPage::PreTranslateMessage((CPropertyPage *)this,param_1);
  }
  else {
    iVar1 = 1;
  }
  return iVar1;
}



