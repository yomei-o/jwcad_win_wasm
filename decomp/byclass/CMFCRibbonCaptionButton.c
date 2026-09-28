/* CMFCRibbonCaptionButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonCaptionButton[1], CMFCRibbonLaunchButton[1], CRibbonCategoryScroll[1] */
/* 0086a2e4  FUN_0086a2e4  51 bytes, 0 callers */

void FUN_0086a2e4(byte param_1)

{
  FUN_00865d91();
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




/* vtable slots: CMFCRibbonCaptionButton[93], CMFCRibbonLabel[93], std::D::?$messages[3], std::G::?$messages[3], std::_W::?$messages[3] */
/* 008b2a86  FUN_008b2a86  6 bytes, 0 callers */

undefined4 FUN_008b2a86(void)

{
  return 0xffffffff;
}




/* vtable slots: CMFCRibbonCaptionButton[62] */
/* 008b3489  GetRegularSize  37 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual class CSize __thiscall CMFCRibbonCaptionButton::GetRegularSize(class CDC *)
   
   Library: Visual Studio 2015 Release */

CDC * __thiscall CMFCRibbonCaptionButton::GetRegularSize(CMFCRibbonCaptionButton *this,CDC *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = GetSystemMetrics(0x37);
  iVar2 = GetSystemMetrics(0x36);
  *(int *)param_1 = iVar2;
  *(int *)(param_1 + 4) = iVar1;
  return param_1;
}




/* vtable slots: CMFCRibbonCaptionButton[0] */
/* 008b34ae  FUN_008b34ae  6 bytes, 0 callers */

undefined ** FUN_008b34ae(void)

{
  return &PTR_s_CMFCRibbonCaptionButton_009a1368;
}




/* vtable slots: CMFCRibbonCaptionButton[95] */
/* 008b3669  FUN_008b3669  44 bytes, 0 callers */

void FUN_008b3669(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x260);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonCaptionButton[133] */
/* 008b3a63  FUN_008b3a63  133 bytes, 0 callers */

void FUN_008b3a63(void)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int *in_ECX;
  WPARAM wParam;
  
  pcVar1 = *(code **)(*in_ECX + 0xd8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0xd0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      pHVar3 = (HWND)in_ECX[0x71];
      if (pHVar3 == (HWND)0x0) {
        pHVar3 = GetParent(*(HWND *)(in_ECX[0x21] + 0x20));
        pCVar4 = CWnd::FromHandle(pHVar3);
        wParam = in_ECX[0x29];
        pHVar3 = *(HWND *)(pCVar4 + 0x20);
      }
      else {
        wParam = in_ECX[0x29];
      }
      PostMessageW(pHVar3,0x112,wParam,0);
      in_ECX[0x32] = 0;
    }
  }
  return;
}



