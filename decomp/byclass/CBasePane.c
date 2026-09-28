/* CBasePane -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CBasePane[152], CMFCBaseToolBar[152], CPane[152] */
/* 007abeef  FUN_007abeef  51 bytes, 3 callers */

void FUN_007abeef(undefined4 *param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_2 == 0) || (param_3 == 0)) {
    *param_1 = 0;
    if ((param_2 != 0) && (param_3 == 0)) {
      uVar1 = 0x7fff;
    }
  }
  else {
    *param_1 = 0x7fff;
  }
  param_1[1] = uVar1;
  return;
}




/* vtable slots: CBasePane[96], CBaseTabbedPane[96], CDockablePane[96], CDockablePaneAdapter[96], CDummyDockablePane[96], CMFCAutoHideBar[96], CMFCBaseToolBar[96], CMFCColorBar[96], CMFCDropDownToolBar[96], CMFCImageEditorPaletteBar[96], CMFCMenuBar[96], CMFCOutlookBar[236], CMFCOutlookBarPane[96], CMFCOutlookBarPaneAdapter[96], CMFCOutlookBarToolBar[96], CMFCPopupMenuBar[96], CMFCPrintPreviewToolBar[96], CMFCRibbonPanelMenuBar[96], CMFCTasksPane[96], CMFCTasksPaneToolBar[96], CMFCToolBar[96], CPane[96], CTabbedPane[96] */
/* 007c2351  FUN_007c2351  27 bytes, 0 callers */

void FUN_007c2351(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1cc);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CBasePane[1] */
/* 007ed02f  FUN_007ed02f  51 bytes, 0 callers */

void FUN_007ed02f(byte param_1)

{
  CBasePane *in_ECX;
  
  CBasePane::~CBasePane(in_ECX);
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




/* vtable slots: CBasePane[10] */
/* 007ed861  FUN_007ed861  6 bytes, 0 callers */

undefined ** FUN_007ed861(void)

{
  return &PTR_FUN_0098ab98;
}




/* vtable slots: CBasePane[0] */
/* 007ed9ac  FUN_007ed9ac  6 bytes, 0 callers */

undefined ** FUN_007ed9ac(void)

{
  return &PTR_s_CBasePane_0098a7f8;
}



