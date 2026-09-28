/* CMFCRibbonSpinButtonCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonSpinButtonCtrl[89], CMFCSpinButtonCtrl[89], CSpinButtonCtrl[89] */
/* 007a4249  FUN_007a4249  58 bytes, 0 callers */

void FUN_007a4249(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  FUN_00790c5e(0x40);
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall(L"msctls_updown32",0,param_1,param_2,param_3,param_4,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonSpinButtonCtrl[0], CMFCSpinButtonCtrl[0], CSpinButtonCtrl[0] */
/* 007a45de  FUN_007a45de  6 bytes, 0 callers */

undefined ** FUN_007a45de(void)

{
  return &PTR_s_CSpinButtonCtrl_0097eb04;
}




/* vtable slots: CMFCRibbonSpinButtonCtrl[1] */
/* 0087e307  FUN_0087e307  51 bytes, 0 callers */

void FUN_0087e307(byte param_1)

{
  FUN_0082a451();
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




/* vtable slots: CMFCRibbonSpinButtonCtrl[10] */
/* 0087e8e7  FUN_0087e8e7  6 bytes, 0 callers */

undefined ** FUN_0087e8e7(void)

{
  return &PTR_FUN_0099a374;
}




/* vtable slots: CMFCRibbonSpinButtonCtrl[91] */
/* 0087ec98  OnDraw  110 bytes, 0 callers */

/* Library Function - Single Match
    private: virtual void __thiscall CMFCRibbonSpinButtonCtrl::OnDraw(class CDC *)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCRibbonSpinButtonCtrl::OnDraw(CMFCRibbonSpinButtonCtrl *this,CDC *param_1)

{
  undefined4 uVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  CObject *this_00;
  int iVar4;
  
  uVar1 = DAT_00a12704;
  if (*(int *)(this + 0x98) != 0) {
    pHVar2 = GetParent(*(HWND *)(this + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    this_00 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonBar_009a1608,(CObject *)pCVar3);
    if (((this_00 != (CObject *)0x0) &&
        (iVar4 = CMFCRibbonBar::IsQuickAccessToolbarOnTop((CMFCRibbonBar *)this_00), iVar4 != 0)) &&
       (*(int *)(this_00 + 0x308) != 0)) {
      DAT_00a12704 = 1;
    }
  }
  FUN_0082a4bf(param_1);
  DAT_00a12704 = uVar1;
  return;
}



