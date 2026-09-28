/* ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[28] */
/* 007909d0  FUN_007909d0  34 bytes, 0 callers */

void FUN_007909d0(byte param_1)

{
  FUN_007907e4();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[1] */
/* 00790a9c  FUN_00790a9c  17 bytes, 2 callers */

void FUN_00790a9c(int param_1)

{
  *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  return;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[1] */
/* 00790aad  FUN_00790aad  10 bytes, 0 callers */

void FUN_00790aad(void)

{
  FUN_00790a9c();
  return;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[1] */
/* 00790ab7  FUN_00790ab7  10 bytes, 0 callers */

void FUN_00790ab7(void)

{
  FUN_00790a9c();
  return;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[4] */
/* 00791f40  FUN_00791f40  8 bytes, 0 callers */

undefined4 FUN_00791f40(void)

{
  return 0x80004001;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[5] */
/* 007928c8  FUN_007928c8  57 bytes, 0 callers */

undefined4
FUN_007928c8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x14);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[4] */
/* 00792bc0  FUN_00792bc0  51 bytes, 0 callers */

undefined4 FUN_00792bc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x10);
    guard_check_icall(piVar1,param_2,param_3,param_4);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[3] */
/* 00792bfb  FUN_00792bfb  45 bytes, 0 callers */

undefined4 FUN_00792bfb(int param_1,undefined4 param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0xc);
    guard_check_icall(piVar1,param_2);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[3], C25DDialog[80], CAboutDlg[80], CAutoDialog[80], CAutoHideDockSite[80], CAutoPage[80], CBasePane[80], CBaseTabbedPane[80], CBitmapButton[80], CBlkkDlg[80], CBlockEditDialog[80], CBlockSelNameDialog[80], CBlockTreeDialog[80], CBunkatsuDialog[80], CButton[80], CButton9Dlg[80], CButton9Dlg2[80], CCheckListBox[80], CColorButton[80], CColorButton2[80], CColorDialog[80], CComboBox[80], CCommonDialog[80], CDialog[80], CDialogBar[80], CDialogEx[80], CDockBar[80], CDockSite[80], CDockablePane[80], CDockablePaneAdapter[80], CDragDialog[80], CDummyDialog[80], CDummyDockablePane[80], CDxfPage[80], CDxfProgDlg[80], CEdit[80], CEditDialog[80], CEnkoDialog[80], CFileDialog[80], CFontComboBox[80], CFrameWnd[80], CFrameWndEx[80], CFrameWndEx[120], CFrameWndEx[121], CFukusenDialog[80], CFukushaDialog[80], CFukushaZokuseiHenDialog[80], CGaibuDialog[80], CGamenBairitsuDialog[80], CGamenPage[80], CGazouDialog[80], CHachiDialog[80], CHeaderCtrl[80], CHikageJikanDialog[80], CHourakuDialog[80], CIkkatstHenkanDialog[80], CIkktuDialog[80], CJikukakuDialog[80], CJw_winView[80], CKageDialog[80], CKeyPage[80], CKijunTenButton[80], CKjiJunTenDialog[80], CKyokusenDialog[80], CLayerButton[80], CLayerControlBar[80], CLayerControlButton[80], CLayerDialog[80], CListBox[80], CListCtrl[80], CLocalComboBox[80], CMDIChildWnd[80], CMDIChildWndEx[80], CMDIChildWndEx[117], CMDIChildWndEx[126], CMDIChildWndEx[127], CMDIClientAreaWnd[80], CMDIFrameWnd[80], CMDIFrameWndEx[80], CMDIFrameWndEx[125], CMDIFrameWndEx[126], CMDIFrameWndEx[137], CMDITabProxyWnd[80], CMFCAcceleratorKeyAssignCtrl[80], CMFCAutoHideBar[80], CMFCAutoHideBar[185], CMFCBaseAccessibleObject[43], CMFCBaseTabCtrl[80], CMFCBaseToolBar[80], CMFCBaseToolBar[185], CMFCButton[80], CMFCCaptionBar[80], CMFCCaptionBar[185], CMFCColorBar[80], CMFCColorBar[185], CMFCColorBar[235], CMFCColorButton[80], CMFCColorDialog[80], CMFCColorMenuButton[18], CMFCColorPickerCtrl[80], CMFCColorPopupMenu[80], CMFCColorPropertySheet[80], CMFCCustomColorsPropertyPage[80], CMFCCustomizeButton[18], CMFCCustomizeMenuButton[18], CMFCDropDownFrame[80], CMFCDropDownToolBar[80], CMFCDropDownToolBar[185], CMFCDropDownToolbarButton[18], CMFCEditBrowseCtrl[80], CMFCFontComboBox[80], CMFCHeaderCtrl[80], CMFCImageEditorDialog[80], CMFCImageEditorPaletteBar[80], CMFCImageEditorPaletteBar[185], CMFCImagePaintArea[80], CMFCLinkCtrl[80], CMFCListCtrl[80], CMFCMaskedEdit[80], CMFCMenuBar[80], CMFCMenuBar[185], CMFCMenuButton[80], CMFCMousePropertyPage[80], CMFCOutlookBar[80], CMFCOutlookBarPane[80], CMFCOutlookBarPane[185], CMFCOutlookBarPaneAdapter[80], CMFCOutlookBarPaneButton[8], CMFCOutlookBarPaneButton[18], CMFCOutlookBarScrollButton[80], CMFCOutlookBarTabCtrl[80], CMFCOutlookBarToolBar[80], CMFCOutlookBarToolBar[185], CMFCPopupMenu[80], CMFCPopupMenuBar[80], CMFCPopupMenuBar[185], CMFCPopupMenuBar[235], CMFCPrintPreviewToolBar[80], CMFCPrintPreviewToolBar[185], CMFCPropertyGridCtrl[80], CMFCPropertyGridToolTipCtrl[80], CMFCPropertyPage[80], CMFCRibbonBaseElement[140], CMFCRibbonButton[140], CMFCRibbonCaptionButton[140], CMFCRibbonColorButton[140], CMFCRibbonColorMenuButton[140], CMFCRibbonDefaultPanelButton[140], CMFCRibbonEdit[140], CMFCRibbonGallery[140], CMFCRibbonGallery[166], CMFCRibbonGalleryIcon[140], CMFCRibbonKeyTip[80], CMFCRibbonLabel[140], CMFCRibbonLaunchButton[140], CMFCRibbonMiniToolBar[80], CMFCRibbonPanelMenu[80], CMFCRibbonPanelMenuBar[80], CMFCRibbonPanelMenuBar[185], CMFCRibbonPanelMenuBar[235], CMFCRibbonQuickAccessCustomizeButton[140], CMFCRibbonRichEditCtrl[80], CMFCRibbonSeparator[140], CMFCRibbonSpinButtonCtrl[80], CMFCRibbonTab[140], CMFCRibbonUndoButton[140], CMFCShadowRenderer[3], CMFCShadowWnd[80], CMFCShellListCtrl[80], CMFCShellTreeCtrl[80], CMFCShowAllButton[18], CMFCSpinButtonCtrl[80], CMFCStandardColorsPropertyPage[80], CMFCTabButton[80], CMFCTabCtrl[80], CMFCTasksPane[80], CMFCTasksPaneFrameWnd[80], CMFCTasksPaneToolBar[80], CMFCTasksPaneToolBar[185], CMFCToolBar[80], CMFCToolBar[185], CMFCToolBarButton[8], CMFCToolBarButton[18], CMFCToolBarButtonCustomizeDialog[80], CMFCToolBarButtonsListButton[80], CMFCToolBarColorButton[8], CMFCToolBarColorButton[18], CMFCToolBarComboBoxEdit[80], CMFCToolBarEditCtrl[80], CMFCToolBarMenuButton[18], CMFCToolBarMenuButtonsButton[8], CMFCToolBarMenuButtonsButton[18], CMFCToolBarNameDialog[80], CMFCToolBarSystemMenuButton[18], CMFCToolBarsCommandsListBox[80], CMFCToolBarsCommandsPropertyPage[80], CMFCToolBarsCustomizeDialog[80], CMFCToolBarsKeyboardPropertyPage[80], CMFCToolBarsListCheckBox[80], CMFCToolBarsListPropertyPage[80], CMFCToolBarsMenuPropertyPage[80], CMFCToolBarsOptionsPropertyPage[80], CMFCToolBarsToolsPropertyPage[80], CMFCToolTipCtrl[80], CMFCVisualManager[129], CMFCVisualManagerOffice2003[129], CMFCVisualManagerOfficeXP[129], CMainFrame[80], CMentoriDialog[80], CMiniDockFrameWnd[80], CMiniFrameWnd[80], CMojiDialog[80], CMojiDialog2[80], CMojiKensakuNameDialog[80], CMojiPage[80], CMojiSeiriDialog[80], CMojiSelDialog[80], CMojiSizeDialog[80], CMsgDialog[80], CMultiPaneFrameWnd[80], CMy02ComboBox[80], CMy0ComboBox[80], CMy2ComboBox[80], CMy2ComboBox1[80], CMy3Button[80], CMyBWnd[80], CMyButton[80], CMyColorDialog[80], CMyComboBox[80], CMyCtrlBar[80], CMyDialog[80], CMyFileDialog[80], CMyListCtrl[80], CMyPropertySheet[80], CMyStatusBar[80], CMyTabCtrl[80], CMyToolBar[80], CMyTree2Ctrl[80], CMyTreeCtrl[80], CMyWnd[80], CNamaeHenkouDlg[80], CNewFileDlg[80], CNewTypeDlg[80], COffsetDialog[80], COleBusyDialog[80], COleCntrFrameWnd[80], COleCntrFrameWndEx[80], COleDataSource[20], COleDataSource[21], COleDocIPFrameWnd[80], COleDocIPFrameWndEx[80], COleDocIPFrameWndEx[127], COleDocIPFrameWndEx[128], COleIPFrameWnd[80], COleIPFrameWndEx[80], COleIPFrameWndEx[127], COleIPFrameWndEx[128], COutlookCustomizeButton[18], COutlookOptionsDlg[80], CPane[80], CPaneDivider[80], CPaneFrameWnd[80], CPaneTrackingWnd[80], CPreviewView[80], CPreviewViewEx[80], CPrintBairitsuDlg[80], CPrintDialog[80], CPrintKeishikiDialog[80], CPrintingDialog[80], CProgressCtrl[80], CPropertyPage[80], CPropertySheet[80], CProtectLayPassWordDialog[80], CPrtFileDlg[80], CPrtFileWnd[80], CPrtHnDialog[80], CRenzokuSenDailog[80], CRibbonCategoryScroll[140], CRibbonUndoLabel[140], CRichEditCtrl[80], CRitsumenDialog[80], CScaleDialog[80], CScreenWnd[80], CScrollBar[80], CScrollView[80], CSen2Dialog[80], CSenCollControlBar[80], CSenCollControlBar2[80], CSenDialog[80], CSenKigouDialog[80], CSenPage[80], CSenshuButton[80], CSenshuDialog[80], CSenshuDialog2[80], CSentakuDialog[80], CSesenDialog[80], CSmartDockingGroupGuidesWnd[80], CSmartDockingHighlighterWnd[80], CSmartDockingStandaloneGuideWnd[80], CSonotaPage[80], CSonotaPage1[80], CSpinButtonCtrl[80], CStatic[80], CStatusBar[80], CSunpoDialog[80], CSunpoSetteiDialg[80], CSuuchiHyouDialog[80], CTabCtrl[80], CTabbedPane[80], CTakakukeiDialog[80], CTasksPaneHistoryButton[18], CTasksPaneMenuButton[18], CTasksPaneNavigateButton[8], CTasksPaneNavigateButton[18], CTateguDialog[80], CTateguKijuntenDialog[80], CTenkuuZuDialog[80], CToolBar[80], CToolBarDialog[80], CToolTipCtrl[80], CToukaritsDialog[80], CToukashokuDialog[80], CTourokuZuDialog[80], CTreeCtrl[80], CUserDefinedLTypeDialog[80], CUserTBDialog[80], CVSListBox[80], CVSListBoxBase[80], CVSListBoxEditCtrl[80], CVSToolsListBox[80], CWnd[80], CZaFileSetteiDialog[80], CZokuseiSelHenkouDialog[80], _AFX_MOUSEANCHORWND[80] */
/* 00792c45  FUN_00792c45  5 bytes, 0 callers */

undefined4 FUN_00792c45(void)

{
  return 0;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[6] */
/* 00792fd3  FUN_00792fd3  66 bytes, 0 callers */

undefined4
FUN_00792fd3(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x18);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[0] */
/* 00794abd  FUN_00794abd  26 bytes, 2 callers */

void FUN_00794abd(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_00791ab7(param_1,&PTR_DAT_0097c760,param_2,param_3);
  return;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[0] */
/* 00794ad7  FUN_00794ad7  10 bytes, 0 callers */

void FUN_00794ad7(void)

{
  FUN_00794abd();
  return;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[0] */
/* 00794ae1  FUN_00794ae1  10 bytes, 0 callers */

void FUN_00794ae1(void)

{
  FUN_00794abd();
  return;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[2] */
/* 00794d85  FUN_00794d85  50 bytes, 2 callers */

int FUN_00794d85(int *param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  
  piVar1 = param_1 + 5;
  *piVar1 = *piVar1 + -1;
  iVar2 = param_1[5];
  if ((*piVar1 == 0) && (param_1 != (int *)0x0)) {
    pcVar3 = *(code **)(*param_1 + 0x70);
    guard_check_icall(1);
    (*pcVar3)();
  }
  return iVar2;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[2] */
/* 00794db7  FUN_00794db7  10 bytes, 0 callers */

void FUN_00794db7(void)

{
  FUN_00794d85();
  return;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[2] */
/* 00794dc1  FUN_00794dc1  10 bytes, 0 callers */

void FUN_00794dc1(void)

{
  FUN_00794d85();
  return;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[3] */
/* 0079542b  FUN_0079542b  24 bytes, 0 callers */

undefined4 FUN_0079542b(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  *(undefined4 *)(param_1 + 8) = param_3;
  return 0;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[25] */
/* 00795f82  FUN_00795f82  58 bytes, 0 callers */

undefined4
FUN_00795f82(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 100);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[24] */
/* 00796041  FUN_00796041  64 bytes, 0 callers */

undefined4 FUN_00796041(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_4 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x60);
    guard_check_icall(piVar1,param_2,param_3,param_4);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[22] */
/* 007960f7  FUN_007960f7  101 bytes, 0 callers */

undefined4
FUN_007960f7(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            undefined4 param_7,undefined4 param_8,undefined4 param_9)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if ((((param_2 == 0) || (param_3 == 0)) || (param_4 == 0)) || (param_5 == 0)) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x58);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[23] */
/* 007961f9  FUN_007961f9  77 bytes, 0 callers */

undefined4
FUN_007961f9(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,int param_7)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_7 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x5c);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6,param_7);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[21] */
/* 007962d7  FUN_007962d7  61 bytes, 0 callers */

undefined4
FUN_007962d7(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x54);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[9] */
/* 00796412  FUN_00796412  74 bytes, 0 callers */

undefined4
FUN_00796412(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_6 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x24);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[8] */
/* 007964e7  FUN_007964e7  58 bytes, 0 callers */

undefined4 FUN_007964e7(int param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_2 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x20);
    guard_check_icall(piVar1,param_2);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[20] */
/* 0079658b  FUN_0079658b  74 bytes, 0 callers */

undefined4
FUN_0079658b(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_6 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x50);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[12] */
/* 00796660  FUN_00796660  74 bytes, 0 callers */

undefined4
FUN_00796660(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_6 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x30);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[18] */
/* 00796735  FUN_00796735  58 bytes, 0 callers */

undefined4 FUN_00796735(int param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_2 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x48);
    guard_check_icall(piVar1,param_2);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[15] */
/* 007967d9  FUN_007967d9  74 bytes, 0 callers */

undefined4
FUN_007967d9(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_6 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x3c);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[16] */
/* 007968ae  FUN_007968ae  83 bytes, 0 callers */

undefined4
FUN_007968ae(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,int param_7)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if ((param_2 == 0) || (param_7 == 0)) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x40);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6,param_7);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[17] */
/* 00796992  FUN_00796992  74 bytes, 0 callers */

undefined4
FUN_00796992(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_6 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x44);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[10] */
/* 00796a67  FUN_00796a67  74 bytes, 0 callers */

undefined4
FUN_00796a67(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_6 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x28);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[7] */
/* 00796b3c  FUN_00796b3c  58 bytes, 0 callers */

undefined4 FUN_00796b3c(int param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_2 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x1c);
    guard_check_icall(piVar1,param_2);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[13] */
/* 00796be0  FUN_00796be0  74 bytes, 0 callers */

undefined4
FUN_00796be0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_6 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x34);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[19] */
/* 00796cb5  FUN_00796cb5  58 bytes, 0 callers */

undefined4 FUN_00796cb5(int param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_2 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x4c);
    guard_check_icall(piVar1,param_2);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[14] */
/* 00796d59  FUN_00796d59  74 bytes, 0 callers */

undefined4
FUN_00796d59(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_6 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x38);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[11] */
/* 00796e2e  FUN_00796e2e  74 bytes, 0 callers */

undefined4
FUN_00796e2e(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,int param_6)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  piVar1 = *(int **)(param_1 + 8);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80010108;
  }
  else if (param_6 == 0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x2c);
    guard_check_icall(piVar1,param_2,param_3,param_4,param_5,param_6);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[26], ATL::ATL::VCAccessibleProxy::?$CComObjectNoLock[27] */
/* 00796f03  FUN_00796f03  27 bytes, 0 callers */

int FUN_00796f03(int param_1)

{
  return (-(uint)(*(int *)(param_1 + 8) != 0) & 0xffff3ef9) + 0x80010108;
}



