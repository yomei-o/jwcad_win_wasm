/* CDocItem -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDocItem[14], CEnumArray[14], CJw_winApp[14], CSingleDocTemplate[14], CWinApp[14], CWinThread[14] */
/* 007900c6  FUN_007900c6  6 bytes, 0 callers */

undefined * FUN_007900c6(void)

{
  return &DAT_0097c1b4;
}




/* vtable slots: CDocItem[10], CEnumArray[10], CEnumFormatEtc[10], CMFCBaseAccessibleObject[10], CMFCRibbonBaseElement[10], CMFCRibbonButton[10], CMFCRibbonButtonsGroup[10], CMFCRibbonCaptionButton[10], CMFCRibbonCategory[10], CMFCRibbonColorButton[10], CMFCRibbonColorMenuButton[10], CMFCRibbonDefaultPanelButton[10], CMFCRibbonEdit[10], CMFCRibbonGallery[10], CMFCRibbonGalleryIcon[10], CMFCRibbonLabel[10], CMFCRibbonLaunchButton[10], CMFCRibbonMainPanel[10], CMFCRibbonPanel[10], CMFCRibbonQuickAccessCustomizeButton[10], CMFCRibbonQuickAccessToolBar[10], CMFCRibbonRecentFilesList[10], CMFCRibbonSeparator[10], CMFCRibbonTab[10], CMFCRibbonUndoButton[10], CMFCTabDropTarget[10], COleDataSource[10], COleDropSource[10], COleDropTarget[10], COleMessageFilter[10], CRibbonCategoryScroll[10], CRibbonUndoLabel[10], CSingleDocTemplate[10], CWinThread[10] */
/* 007900cc  FUN_007900cc  6 bytes, 0 callers */

undefined * FUN_007900cc(void)

{
  return &DAT_0097c240;
}




/* vtable slots: CDocItem[4], CEnumArray[4], CEnumFormatEtc[4], CJw_winApp[4], CMFCBaseAccessibleObject[4], CMFCRibbonBaseElement[4], CMFCRibbonButton[4], CMFCRibbonButtonsGroup[4], CMFCRibbonCaptionButton[4], CMFCRibbonCategory[4], CMFCRibbonColorButton[4], CMFCRibbonColorMenuButton[4], CMFCRibbonDefaultPanelButton[4], CMFCRibbonEdit[4], CMFCRibbonGallery[4], CMFCRibbonGalleryIcon[4], CMFCRibbonLabel[4], CMFCRibbonLaunchButton[4], CMFCRibbonMainPanel[4], CMFCRibbonPanel[4], CMFCRibbonQuickAccessCustomizeButton[4], CMFCRibbonQuickAccessToolBar[4], CMFCRibbonRecentFilesList[4], CMFCRibbonSeparator[4], CMFCRibbonTab[4], CMFCRibbonUndoButton[4], CMFCTabDropTarget[4], CMFCToolBarDropSource[4], CMFCToolBarDropTarget[4], COleDataSource[4], COleDropSource[4], COleDropTarget[4], COleMessageFilter[4], CRibbonCategoryScroll[4], CRibbonUndoLabel[4], CSingleDocTemplate[4], CWinApp[4], CWinThread[4] */
/* 0079039d  FUN_0079039d  68 bytes, 0 callers */

void FUN_0079039d(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  FUN_007c2e0f(0xd);
  pcVar1 = *(code **)(*in_ECX + 0x20);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    FUN_0079de17();
  }
  FUN_007c2e83(0xd);
  pcVar1 = *(code **)(*in_ECX + 4);
  guard_check_icall(1);
  (*pcVar1)();
  return;
}




/* vtable slots: CDocItem[1] */
/* 007d0de6  `scalar_deleting_destructor'  54 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CDocItem::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CDocItem::_scalar_deleting_destructor_(CDocItem *this,uint param_1)

{
  *(undefined ***)this = vftable;
  FUN_0078feea();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x24);
    }
  }
  return this;
}




/* vtable slots: CDocItem[0] */
/* 007d0e1c  FUN_007d0e1c  6 bytes, 0 callers */

undefined ** FUN_007d0e1c(void)

{
  return &PTR_s_CDocItem_00a004c0;
}




/* vtable slots: CDocItem[2] */
/* 007d0e22  FUN_007d0e22  52 bytes, 0 callers */

void FUN_007d0e22(undefined4 *param_1)

{
  code *pcVar1;
  int in_ECX;
  
  if (((~param_1[6] & 1) == 0) && (*(int *)(in_ECX + 0x20) == 0)) {
    pcVar1 = *(code **)(*(int *)*param_1 + 0x11c);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}



