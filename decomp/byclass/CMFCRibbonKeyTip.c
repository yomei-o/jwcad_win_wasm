/* CMFCRibbonKeyTip -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonKeyTip[0], CMyBWnd[0], CMyWnd[0], CPaneTrackingWnd[0], CScreenWnd[0], CSmartDockingGroupGuidesWnd[0], CSmartDockingHighlighterWnd[0], CSmartDockingStandaloneGuideWnd[0], CWnd[0], _AFX_MOUSEANCHORWND[0] */
/* 007929fe  FUN_007929fe  6 bytes, 0 callers */

undefined ** FUN_007929fe(void)

{
  return &PTR_DAT_0097c53c;
}




/* vtable slots: CMFCRibbonKeyTip[1] */
/* 008c5bf2  FUN_008c5bf2  57 bytes, 0 callers */

void FUN_008c5bf2(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCRibbonKeyTip::vftable;
  FUN_007908c2();
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




/* vtable slots: CMFCRibbonKeyTip[10] */
/* 008c5c2b  FUN_008c5c2b  6 bytes, 0 callers */

undefined ** FUN_008c5c2b(void)

{
  return &PTR_FUN_009a4400;
}



