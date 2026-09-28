/* CAutoHideDockSite -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CAutoHideDockSite[3], CBasePane[3], CBaseTabbedPane[3], CBitmapButton[3], CButton[3], CCheckListBox[3], CColorButton[3], CColorButton2[3], CComboBox[3], CDialogBar[3], CDocItem[3], CDockBar[3], CDockSite[3], CDockablePane[3], CDockablePaneAdapter[3], CDummyDockablePane[3], CEdit[3], CEnumArray[3], CEnumFormatEtc[3], CFontComboBox[3], CHeaderCtrl[3], CJw_winApp[3], CKijunTenButton[3], CLayerButton[3], CLayerControlBar[3], CLayerControlButton[3], CListBox[3], CListCtrl[3], CLocalComboBox[3], CMDIClientAreaWnd[3], CMDITabProxyWnd[3], CMFCAcceleratorKeyAssignCtrl[3], CMFCAutoHideBar[3], CMFCBaseAccessibleObject[3], CMFCBaseTabCtrl[3], CMFCBaseToolBar[3], CMFCButton[3], CMFCCaptionBar[3], CMFCColorBar[3], CMFCColorButton[3], CMFCColorPickerCtrl[3], CMFCDropDownToolBar[3], CMFCEditBrowseCtrl[3], CMFCFontComboBox[3], CMFCHeaderCtrl[3], CMFCImageEditorPaletteBar[3], CMFCImagePaintArea[3], CMFCLinkCtrl[3], CMFCListCtrl[3], CMFCMaskedEdit[3], CMFCMenuBar[3], CMFCMenuButton[3], CMFCOutlookBar[3], CMFCOutlookBarPane[3], CMFCOutlookBarPaneAdapter[3], CMFCOutlookBarScrollButton[3], CMFCOutlookBarTabCtrl[3], CMFCOutlookBarToolBar[3], CMFCPopupMenuBar[3], CMFCPrintPreviewToolBar[3], CMFCPropertyGridCtrl[3], CMFCPropertyGridToolTipCtrl[3], CMFCRibbonBaseElement[3], CMFCRibbonButton[3], CMFCRibbonButtonsGroup[3], CMFCRibbonCaptionButton[3], CMFCRibbonCategory[3], CMFCRibbonColorButton[3], CMFCRibbonColorMenuButton[3], CMFCRibbonDefaultPanelButton[3], CMFCRibbonEdit[3], CMFCRibbonGallery[3], CMFCRibbonGalleryIcon[3], CMFCRibbonKeyTip[3], CMFCRibbonLabel[3], CMFCRibbonLaunchButton[3], CMFCRibbonMainPanel[3], CMFCRibbonPanel[3], CMFCRibbonPanelMenuBar[3], CMFCRibbonQuickAccessCustomizeButton[3], CMFCRibbonQuickAccessToolBar[3], CMFCRibbonRecentFilesList[3], CMFCRibbonRichEditCtrl[3], CMFCRibbonSeparator[3], CMFCRibbonSpinButtonCtrl[3], CMFCRibbonTab[3], CMFCRibbonUndoButton[3], CMFCShellListCtrl[3], CMFCShellTreeCtrl[3], CMFCSpinButtonCtrl[3], CMFCTabButton[3], CMFCTabCtrl[3], CMFCTabDropTarget[3], CMFCTasksPane[3], CMFCTasksPaneFrameWnd[3], CMFCTasksPaneToolBar[3], CMFCToolBar[3], CMFCToolBarButtonsListButton[3], CMFCToolBarComboBoxEdit[3], CMFCToolBarDropSource[3], CMFCToolBarDropTarget[3], CMFCToolBarEditCtrl[3], CMFCToolBarsCommandsListBox[3], CMFCToolBarsListCheckBox[3], CMFCToolTipCtrl[3], CMultiPaneFrameWnd[3], CMy02ComboBox[3], CMy0ComboBox[3], CMy2ComboBox[3], CMy2ComboBox1[3], CMy3Button[3], CMyBWnd[3], CMyButton[3], CMyComboBox[3], CMyCtrlBar[3], CMyListCtrl[3], CMyStatusBar[3], CMyTabCtrl[3], CMyToolBar[3], CMyTree2Ctrl[3], CMyTreeCtrl[3], CMyWnd[3], COleDataSource[3], COleDropSource[3], COleDropTarget[3], COleMessageFilter[3], CPane[3], CPaneDivider[3], CPaneFrameWnd[3], CPaneTrackingWnd[3], CProgressCtrl[3], CRibbonCategoryScroll[3], CRibbonUndoLabel[3], CRichEditCtrl[3], CScreenWnd[3], CScrollBar[3], CSenCollControlBar[3], CSenCollControlBar2[3], CSenshuButton[3], CSmartDockingGroupGuidesWnd[3], CSmartDockingHighlighterWnd[3], CSmartDockingStandaloneGuideWnd[3], CSpinButtonCtrl[3], CStatic[3], CStatusBar[3], CTabCtrl[3], CTabbedPane[3], CToolBar[3], CToolTipCtrl[3], CTreeCtrl[3], CVSListBox[3], CVSListBoxBase[3], CVSListBoxEditCtrl[3], CVSToolsListBox[3], CWinApp[3], CWinThread[3], CWnd[3], _AFX_MOUSEANCHORWND[3] */
/* 007900e9  FUN_007900e9  637 bytes, 9 callers */

uint FUN_007900e9(undefined4 *param_1,uint param_2,undefined4 *param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int *piVar7;
  AFX_MSGMAP_ENTRY *pAVar8;
  int *in_ECX;
  uint local_8;
  
  if (param_2 == 0xfffffffe) {
    iVar3 = FUN_0079dd6d();
    if (*(int *)(iVar3 + 0x3c) != 0) {
      iVar3 = FUN_0079dd6d();
      pcVar1 = *(code **)(**(int **)(iVar3 + 0x3c) + 4);
      guard_check_icall();
      uVar4 = (*pcVar1)();
      return uVar4;
    }
LAB_00790361:
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if (param_2 == 0xfffffffd) {
    uVar4 = 0;
    if (param_3 != (undefined4 *)0x0) {
      iVar3 = param_3[0xc];
      pcVar1 = *(code **)(*in_ECX + 0x2c);
      guard_check_icall();
      puVar5 = (undefined4 *)(*pcVar1)();
      do {
        if (puVar5 == (undefined4 *)0x0) {
          return uVar4;
        }
        if (uVar4 != 0) {
          return uVar4;
        }
        piVar7 = (int *)puVar5[1];
        puVar2 = (undefined4 *)piVar7[1];
        while (((puVar2 != (undefined4 *)0x0 && (piVar7[2] != 0)) && (uVar4 == 0))) {
          if (param_1 == puVar2) {
            if (iVar3 == 0) {
              if (*piVar7 == 0) {
LAB_007901a6:
                param_3[1] = piVar7[2];
                uVar4 = 1;
              }
            }
            else if ((*piVar7 != 0) && (iVar6 = FUN_0079066d(iVar3,*piVar7), iVar6 != 0))
            goto LAB_007901a6;
          }
          puVar2 = (undefined4 *)piVar7[4];
          piVar7 = piVar7 + 3;
        }
        puVar5 = (undefined4 *)*puVar5;
      } while( true );
    }
    goto LAB_00790361;
  }
  uVar4 = param_2;
  if (param_2 != 0xffffffff) {
    uVar4 = param_2 & 0xffff;
    local_8 = param_2 >> 0x10;
    if (local_8 != 0) goto LAB_007901e4;
  }
  local_8 = 0x111;
LAB_007901e4:
  pcVar1 = *(code **)(*in_ECX + 0x28);
  guard_check_icall();
  piVar7 = (int *)(*pcVar1)();
LAB_00790216:
  if (*piVar7 == 0) {
LAB_0079021f:
    return 0;
  }
  pAVar8 = AfxFindMessageEntry((AFX_MSGMAP_ENTRY *)piVar7[1],local_8,uVar4,(uint)param_1);
  if (pAVar8 == (AFX_MSGMAP_ENTRY *)0x0) goto code_r0x0079020a;
  pcVar1 = *(code **)(pAVar8 + 0x14);
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = in_ECX;
    param_4[1] = pcVar1;
    return 1;
  }
  switch(*(undefined4 *)(pAVar8 + 0x10)) {
  case 0x3a:
    guard_check_icall();
    (*pcVar1)();
    break;
  case 0x3b:
    guard_check_icall();
    uVar4 = (*pcVar1)();
    return uVar4;
  case 0x3c:
    param_3 = param_1;
    goto LAB_0079026e;
  case 0x3d:
    param_3 = param_1;
    goto LAB_00790350;
  case 0x3e:
    if (param_3 == (undefined4 *)0x0) goto LAB_00790361;
    guard_check_icall(param_3[1],*param_3);
    (*pcVar1)();
    break;
  case 0x3f:
    if (param_3 != (undefined4 *)0x0) {
      guard_check_icall(param_3[1],*param_3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    goto LAB_00790361;
  case 0x40:
    if (param_3 == (undefined4 *)0x0) goto LAB_00790361;
    guard_check_icall(param_1,param_3[1],*param_3);
    (*pcVar1)();
    break;
  case 0x41:
    if (param_3 != (undefined4 *)0x0) {
      guard_check_icall(param_1,param_3[1],*param_3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    goto LAB_00790361;
  case 0x42:
    if (param_3 != (undefined4 *)0x0) {
      guard_check_icall(param_3);
      (*pcVar1)();
      goto LAB_0079031b;
    }
    goto LAB_00790361;
  case 0x43:
    if (param_3 != (undefined4 *)0x0) {
      guard_check_icall(param_3,param_1);
      (*pcVar1)();
LAB_0079031b:
      iVar3 = param_3[7];
      param_3[7] = 0;
      return (uint)(iVar3 == 0);
    }
    goto LAB_00790361;
  case 0x44:
LAB_0079026e:
    guard_check_icall(param_3);
    (*pcVar1)();
    break;
  case 0x45:
LAB_00790350:
    guard_check_icall(param_3);
    uVar4 = (*pcVar1)();
    return uVar4;
  default:
    goto LAB_0079021f;
  }
  return 1;
code_r0x0079020a:
  pcVar1 = (code *)*piVar7;
  guard_check_icall();
  piVar7 = (int *)(*pcVar1)();
  goto LAB_00790216;
}




/* vtable slots: CAutoHideDockSite[104], CBasePane[104], CBaseTabbedPane[104], CDataRecoveryHandler[4], CDockSite[104], CDockablePane[104], CDockablePaneAdapter[104], CDummyDockablePane[104], CMFCAutoHideBar[104], CMFCBaseToolBar[104], CMFCCaptionBar[104], CMFCColorBar[104], CMFCDropDownToolBar[104], CMFCImageEditorPaletteBar[104], CMFCMenuBar[104], CMFCOutlookBar[104], CMFCOutlookBarPane[104], CMFCOutlookBarPaneAdapter[104], CMFCOutlookBarToolBar[104], CMFCPopupMenuBar[104], CMFCPrintPreviewToolBar[104], CMFCRibbonPanelMenuBar[104], CMFCTasksPane[104], CMFCTasksPaneToolBar[104], CMFCToolBar[104], CPane[104], CPaneDivider[104], CTabbedPane[104] */
/* 007a393a  FUN_007a393a  7 bytes, 2 callers */

undefined4 FUN_007a393a(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb8);
}




/* vtable slots: CAutoHideDockSite[135], CAutoHideDockSite[145], CBasePane[135], CBasePane[145], CDialogBar[103], CDockBar[91], CDockBar[103], CDockSite[135], CDockSite[145], CFileDialog[107], CFileDialog[109], CJw_winDoc[67], CJw_winView[101], CJw_winView[105], CJw_winView[107], CMDIFrameWndEx[128], CMFCAutoHideBar[145], CMFCAutoHideBar[189], CMFCBaseToolBar[145], CMFCBaseToolBar[189], CMFCCaptionBar[145], CMFCCaptionBar[189], CMFCColorBar[189], CMFCDropDownToolBar[189], CMFCImageEditorPaletteBar[189], CMFCMenuBar[189], CMFCOutlookBarPane[189], CMFCOutlookBarToolBar[189], CMFCPopupMenuBar[189], CMFCPrintPreviewToolBar[189], CMFCPropertyGridCtrl[95], CMFCRibbonBaseElement[127], CMFCRibbonBaseElement[133], CMFCRibbonBaseElement[134], CMFCRibbonBaseElement[135], CMFCRibbonButton[127], CMFCRibbonButton[135], CMFCRibbonButtonsGroup[127], CMFCRibbonButtonsGroup[133], CMFCRibbonButtonsGroup[134], CMFCRibbonButtonsGroup[135], CMFCRibbonCaptionButton[127], CMFCRibbonCaptionButton[135], CMFCRibbonCategory[54], CMFCRibbonColorButton[127], CMFCRibbonColorButton[135], CMFCRibbonColorMenuButton[127], CMFCRibbonColorMenuButton[135], CMFCRibbonDefaultPanelButton[127], CMFCRibbonDefaultPanelButton[135], CMFCRibbonEdit[127], CMFCRibbonEdit[133], CMFCRibbonEdit[135], CMFCRibbonGallery[127], CMFCRibbonGallery[135], CMFCRibbonGalleryIcon[127], CMFCRibbonGalleryIcon[135], CMFCRibbonLabel[127], CMFCRibbonLabel[133], CMFCRibbonLabel[135], CMFCRibbonLaunchButton[127], CMFCRibbonLaunchButton[135], CMFCRibbonPanel[67], CMFCRibbonPanelMenuBar[189], CMFCRibbonQuickAccessCustomizeButton[127], CMFCRibbonQuickAccessCustomizeButton[135], CMFCRibbonQuickAccessToolBar[127], CMFCRibbonQuickAccessToolBar[133], CMFCRibbonQuickAccessToolBar[134], CMFCRibbonQuickAccessToolBar[135], CMFCRibbonRecentFilesList[127], CMFCRibbonRecentFilesList[133], CMFCRibbonRecentFilesList[134], CMFCRibbonRecentFilesList[135], CMFCRibbonSeparator[127], CMFCRibbonSeparator[133], CMFCRibbonSeparator[134], CMFCRibbonSeparator[135], CMFCRibbonTab[127], CMFCRibbonTab[133], CMFCRibbonTab[134], CMFCRibbonUndoButton[127], CMFCRibbonUndoButton[135], CMFCTasksPane[247], CMFCTasksPaneFrameWnd[121], CMFCTasksPaneFrameWnd[122], CMFCTasksPaneToolBar[189], CMFCToolBar[189], CMFCVisualManager[127], CMFCVisualManagerOffice2003[127], CMFCVisualManagerOffice2007[127], CMFCVisualManagerOfficeXP[127], CMiniDoc[67], CPane[145], CPane[189], CPaneDivider[135], CPaneDivider[145], CPaneFrameWnd[121], CPaneFrameWnd[122], CPreviewView[101], CPreviewView[105], CPreviewView[107], CPreviewViewEx[101], CPreviewViewEx[105], CPreviewViewEx[107], CRibbonCategoryScroll[127], CRibbonCategoryScroll[135], CRibbonUndoLabel[127], CRibbonUndoLabel[135], CScrollView[101], CScrollView[105], CScrollView[107], CSmartDockingGroupGuide[3] */
/* 007a9d90  FUN_007a9d90  3 bytes, 1 callers */

void FUN_007a9d90(void)

{
  return;
}




/* vtable slots: CAutoHideDockSite[117], CBasePane[117], CDockSite[117], CMFCAutoHideBar[117], CMFCBaseToolBar[117], CMFCCaptionBar[117], CMFCColorBar[117], CMFCDropDownToolBar[117], CMFCImageEditorPaletteBar[117], CMFCMenuBar[117], CMFCOutlookBarPane[117], CMFCOutlookBarToolBar[117], CMFCPopupMenuBar[117], CMFCPrintPreviewToolBar[117], CMFCRibbonPanelMenuBar[117], CMFCTasksPaneToolBar[117], CMFCToolBar[117], CPane[117], CPaneDivider[117] */
/* 007c22cb  FUN_007c22cb  10 bytes, 0 callers */

uint FUN_007c22cb(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0xa0) & 2;
}




/* vtable slots: CAutoHideDockSite[116], CBasePane[116], CBaseTabbedPane[116], CDockSite[116], CDockablePane[116], CDockablePaneAdapter[116], CDummyDockablePane[116], CMFCAutoHideBar[116], CMFCBaseToolBar[116], CMFCCaptionBar[116], CMFCColorBar[116], CMFCDropDownToolBar[116], CMFCImageEditorPaletteBar[116], CMFCMenuBar[116], CMFCOutlookBar[116], CMFCOutlookBarPane[116], CMFCOutlookBarPaneAdapter[116], CMFCOutlookBarToolBar[116], CMFCPopupMenuBar[116], CMFCPrintPreviewToolBar[116], CMFCRibbonPanelMenuBar[116], CMFCTasksPane[116], CMFCTasksPaneToolBar[116], CMFCToolBar[116], CPane[116], CPaneDivider[116], CTabbedPane[116] */
/* 007c2327  FUN_007c2327  10 bytes, 0 callers */

uint FUN_007c2327(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0xa0) & 4;
}




/* vtable slots: CAutoHideDockSite[127], CAutoHideDockSite[128], CBasePane[127], CBasePane[128], CDockSite[127], CDockSite[128], CMFCAutoHideBar[128], CMFCBaseToolBar[128], CMFCCaptionBar[128], CMFCColorBar[128], CMFCDropDownToolBar[128], CMFCImageEditorPaletteBar[128], CMFCMenuBar[128], CMFCOutlookBarPane[128], CMFCOutlookBarToolBar[128], CMFCPopupMenuBar[128], CMFCPrintPreviewToolBar[128], CMFCRibbonPanelMenuBar[128], CMFCTasksPaneToolBar[128], CMFCToolBar[128], CMFCVisualManager[128], CMFCVisualManagerOffice2003[128], CMFCVisualManagerOfficeXP[128], CPane[128], CPaneDivider[127], CPaneDivider[128] */
/* 007c234c  FUN_007c234c  5 bytes, 1 callers */

undefined4 FUN_007c234c(void)

{
  return 0;
}




/* vtable slots: CAutoHideDockSite[102], CBasePane[102], CBaseTabbedPane[102], CDockSite[102], CDockablePane[102], CDockablePaneAdapter[102], CDummyDockablePane[102], CMFCAutoHideBar[102], CMFCBaseToolBar[102], CMFCCaptionBar[102], CMFCColorBar[102], CMFCDropDownToolBar[102], CMFCImageEditorPaletteBar[102], CMFCMenuBar[102], CMFCOutlookBar[102], CMFCOutlookBarPane[102], CMFCOutlookBarPaneAdapter[102], CMFCOutlookBarToolBar[102], CMFCPopupMenuBar[102], CMFCPrintPreviewToolBar[102], CMFCRibbonPanelMenuBar[102], CMFCTasksPane[102], CMFCTasksPaneToolBar[102], CMFCToolBar[102], CPane[102], CPaneDivider[102], CTabbedPane[102] */
/* 007c24da  FUN_007c24da  7 bytes, 0 callers */

undefined4 FUN_007c24da(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x98);
}




/* vtable slots: CAutoHideDockSite[111], CBasePane[111], CDockSite[111], CDockablePane[111], CDockablePaneAdapter[111], CDummyDockablePane[111], CMFCAutoHideBar[111], CMFCBaseToolBar[111], CMFCCaptionBar[111], CMFCColorBar[111], CMFCDropDownToolBar[111], CMFCImageEditorPaletteBar[111], CMFCMenuBar[111], CMFCOutlookBarPane[111], CMFCOutlookBarPaneAdapter[111], CMFCOutlookBarToolBar[111], CMFCPopupMenuBar[111], CMFCPrintPreviewToolBar[111], CMFCRibbonPanelMenuBar[111], CMFCTasksPane[111], CMFCTasksPaneToolBar[111], CMFCToolBar[111], CPane[111], CPaneDivider[111] */
/* 007c264a  FUN_007c264a  23 bytes, 0 callers */

void FUN_007c264a(WPARAM param_1)

{
  int in_ECX;
  
  SendMessageW(*(HWND *)(in_ECX + 0x20),0x7f,param_1,0);
  return;
}




/* vtable slots: CAutoHideDockSite[112], CBasePane[112], CBaseTabbedPane[112], CDockSite[112], CDockablePane[112], CDockablePaneAdapter[112], CDummyDockablePane[112], CMFCAutoHideBar[112], CMFCBaseToolBar[112], CMFCCaptionBar[112], CMFCColorBar[112], CMFCDropDownToolBar[112], CMFCImageEditorPaletteBar[112], CMFCMenuBar[112], CMFCOutlookBar[112], CMFCOutlookBarPane[112], CMFCOutlookBarPaneAdapter[112], CMFCOutlookBarToolBar[112], CMFCPopupMenuBar[112], CMFCPrintPreviewToolBar[112], CMFCRibbonPanelMenuBar[112], CMFCTasksPane[112], CMFCTasksPaneToolBar[112], CMFCToolBar[112], CPane[112], CPaneDivider[112], CTabbedPane[112] */
/* 007c2661  FUN_007c2661  7 bytes, 0 callers */

undefined4 FUN_007c2661(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x9c);
}




/* vtable slots: CAutoHideDockSite[107], CBasePane[107], CBaseTabbedPane[107], CDockSite[107], CDockablePane[107], CDockablePaneAdapter[107], CDummyDockablePane[107], CMFCAutoHideBar[107], CMFCBaseToolBar[107], CMFCCaptionBar[107], CMFCColorBar[107], CMFCDropDownToolBar[107], CMFCImageEditorPaletteBar[107], CMFCMenuBar[107], CMFCOutlookBar[107], CMFCOutlookBarPane[107], CMFCOutlookBarPaneAdapter[107], CMFCOutlookBarToolBar[107], CMFCPopupMenuBar[107], CMFCPrintPreviewToolBar[107], CMFCRibbonPanelMenuBar[107], CMFCTasksPane[107], CMFCTasksPaneToolBar[107], CMFCToolBar[107], CPane[107], CPaneDivider[107], CTabbedPane[107] */
/* 007c2668  FUN_007c2668  7 bytes, 0 callers */

undefined4 FUN_007c2668(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x84);
}




/* vtable slots: CAutoHideDockSite[89], CBasePane[89], CBaseTabbedPane[89], CDockSite[89], CDockablePane[89], CDockablePaneAdapter[89], CDummyDockablePane[89], CMFCAutoHideBar[89], CMFCBaseToolBar[89], CMFCCaptionBar[89], CMFCColorBar[89], CMFCDropDownToolBar[89], CMFCImageEditorPaletteBar[89], CMFCMenuBar[89], CMFCOutlookBar[89], CMFCOutlookBarPane[89], CMFCOutlookBarPaneAdapter[89], CMFCOutlookBarToolBar[89], CMFCPopupMenuBar[89], CMFCPrintPreviewToolBar[89], CMFCRibbonPanelMenuBar[89], CMFCTasksPane[89], CMFCTasksPaneToolBar[89], CMFCToolBar[89], CPane[89], CTabbedPane[89] */
/* 007c2779  FUN_007c2779  32 bytes, 0 callers */

uint FUN_007c2779(void)

{
  code *pcVar1;
  uint uVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x194);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  return uVar2 & 0xa000;
}




/* vtable slots: CAutoHideDockSite[108], CBasePane[108], CBaseTabbedPane[108], CDockSite[108], CDockablePane[108], CDockablePaneAdapter[108], CDummyDockablePane[108], CMFCAutoHideBar[108], CMFCBaseToolBar[108], CMFCCaptionBar[108], CMFCColorBar[108], CMFCDropDownToolBar[108], CMFCImageEditorPaletteBar[108], CMFCMenuBar[108], CMFCOutlookBar[108], CMFCOutlookBarPane[108], CMFCOutlookBarPaneAdapter[108], CMFCOutlookBarToolBar[108], CMFCPopupMenuBar[108], CMFCPrintPreviewToolBar[108], CMFCRibbonPanelMenuBar[108], CMFCTasksPane[108], CMFCTasksPaneToolBar[108], CMFCToolBar[108], CPane[108], CPaneDivider[108], CTabbedPane[108] */
/* 007c27be  FUN_007c27be  7 bytes, 0 callers */

undefined4 FUN_007c27be(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x88);
}




/* vtable slots: CAutoHideDockSite[122], CBasePane[122], CBaseTabbedPane[122], CDockSite[122], CDockablePane[122], CDockablePaneAdapter[122], CDummyDockablePane[122], CMFCAutoHideBar[122], CMFCBaseToolBar[122], CMFCCaptionBar[122], CMFCColorBar[122], CMFCDropDownToolBar[122], CMFCImageEditorPaletteBar[122], CMFCMenuBar[122], CMFCOutlookBar[122], CMFCOutlookBarPane[122], CMFCOutlookBarPaneAdapter[122], CMFCOutlookBarToolBar[122], CMFCPopupMenuBar[122], CMFCPrintPreviewToolBar[122], CMFCRibbonPanelMenuBar[122], CMFCTasksPane[122], CMFCTasksPaneToolBar[122], CMFCToolBar[122], CPane[122], CPaneDivider[122], CTabbedPane[122] */
/* 007c27cc  FUN_007c27cc  16 bytes, 0 callers */

void FUN_007c27cc(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0) = param_1;
  return;
}




/* vtable slots: CAutoHideDockSite[120], CBasePane[120], CBaseTabbedPane[120], CDockSite[120], CDockablePane[120], CDockablePaneAdapter[120], CDummyDockablePane[120], CMFCAutoHideBar[120], CMFCBaseToolBar[120], CMFCCaptionBar[120], CMFCColorBar[120], CMFCDropDownToolBar[120], CMFCImageEditorPaletteBar[120], CMFCMenuBar[120], CMFCOutlookBar[120], CMFCOutlookBarPane[120], CMFCOutlookBarPaneAdapter[120], CMFCOutlookBarToolBar[120], CMFCPopupMenuBar[120], CMFCPrintPreviewToolBar[120], CMFCRibbonPanelMenuBar[120], CMFCTasksPane[120], CMFCTasksPaneToolBar[120], CMFCToolBar[120], CPane[120], CPaneDivider[120], CTabbedPane[120] */
/* 007c27ec  FUN_007c27ec  27 bytes, 0 callers */

void FUN_007c27ec(uint param_1)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 0x9c) = *(uint *)(in_ECX + 0x9c) & 0xffff0fff | param_1;
  return;
}




/* vtable slots: CAutoHideDockSite[121], CBasePane[121], CBaseTabbedPane[121], CDockSite[121], CDockablePane[121], CDockablePaneAdapter[121], CDummyDockablePane[121], CMFCAutoHideBar[121], CMFCBaseToolBar[121], CMFCCaptionBar[121], CMFCColorBar[121], CMFCDropDownToolBar[121], CMFCImageEditorPaletteBar[121], CMFCMenuBar[121], CMFCOutlookBar[121], CMFCOutlookBarPane[121], CMFCOutlookBarPaneAdapter[121], CMFCOutlookBarToolBar[121], CMFCPopupMenuBar[121], CMFCPrintPreviewToolBar[121], CMFCRibbonPanelMenuBar[121], CMFCTasksPane[121], CMFCTasksPaneToolBar[121], CMFCToolBar[121], CPane[121], CPaneDivider[121], CTabbedPane[121] */
/* 007c2807  FUN_007c2807  16 bytes, 0 callers */

void FUN_007c2807(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x9c) = param_1;
  return;
}




/* vtable slots: CAutoHideDockSite[109], CBasePane[109], CBaseTabbedPane[109], CDockSite[109], CDockablePane[109], CDockablePaneAdapter[109], CDummyDockablePane[109], CMFCAutoHideBar[109], CMFCBaseToolBar[109], CMFCCaptionBar[109], CMFCColorBar[109], CMFCDropDownToolBar[109], CMFCImageEditorPaletteBar[109], CMFCMenuBar[109], CMFCOutlookBar[109], CMFCOutlookBarPane[109], CMFCOutlookBarPaneAdapter[109], CMFCOutlookBarToolBar[109], CMFCPopupMenuBar[109], CMFCPrintPreviewToolBar[109], CMFCRibbonBaseElement[89], CMFCRibbonPanelMenuBar[109], CMFCRibbonSeparator[89], CMFCRibbonTab[89], CMFCTasksPane[109], CMFCTasksPaneToolBar[109], CMFCToolBar[109], CPane[109], CPaneDivider[109], CTabbedPane[109] */
/* 007c2817  FUN_007c2817  16 bytes, 2 callers */

void FUN_007c2817(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x88) = param_1;
  return;
}




/* vtable slots: CAutoHideDockSite[52], CBasePane[52], CBaseTabbedPane[52], CDockSite[52], CDockablePane[52], CDockablePaneAdapter[52], CDummyDockablePane[52], CMFCAutoHideBar[52], CMFCBaseToolBar[52], CMFCCaptionBar[52], CMFCColorBar[52], CMFCDropDownToolBar[52], CMFCImageEditorPaletteBar[52], CMFCMenuBar[52], CMFCOutlookBar[52], CMFCOutlookBarPane[52], CMFCOutlookBarPaneAdapter[52], CMFCOutlookBarToolBar[52], CMFCPopupMenuBar[52], CMFCPrintPreviewToolBar[52], CMFCPropertyGridCtrl[52], CMFCRibbonPanelMenuBar[52], CMFCTasksPane[52], CMFCTasksPaneToolBar[52], CMFCToolBar[52], CPane[52], CPaneDivider[52], CTabbedPane[52] */
/* 007e04bd  FUN_007e04bd  58 bytes, 0 callers */

undefined4
FUN_007e04bd(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x28);
  if (piVar1 == (int *)0x0) {
    uVar3 = 0x80070057;
  }
  else {
    pcVar2 = *(code **)(*piVar1 + 0x54);
    guard_check_icall(piVar1,param_1,param_2,param_3,param_4,param_5);
    uVar3 = (*pcVar2)();
  }
  return uVar3;
}




/* vtable slots: CAutoHideDockSite[39], CBasePane[39], CBaseTabbedPane[39], CDockSite[39], CDockablePane[39], CDockablePaneAdapter[39], CDummyDockablePane[39], CMFCAutoHideBar[39], CMFCBaseAccessibleObject[20], CMFCBaseAccessibleObject[21], CMFCBaseToolBar[39], CMFCCaptionBar[39], CMFCOutlookBar[39], CMFCOutlookBarPaneAdapter[39], CMFCPropertyGridCtrl[39], CMFCRibbonBaseElement[21], CMFCRibbonButton[21], CMFCRibbonButtonsGroup[21], CMFCRibbonCaptionButton[21], CMFCRibbonColorButton[21], CMFCRibbonColorMenuButton[21], CMFCRibbonDefaultPanelButton[21], CMFCRibbonEdit[21], CMFCRibbonGallery[21], CMFCRibbonGalleryIcon[21], CMFCRibbonLabel[21], CMFCRibbonLaunchButton[21], CMFCRibbonQuickAccessCustomizeButton[21], CMFCRibbonRecentFilesList[21], CMFCRibbonSeparator[21], CMFCRibbonTab[21], CMFCRibbonUndoButton[21], CMFCTasksPane[39], CPane[39], CPaneDivider[39], CRibbonCategoryScroll[21], CRibbonUndoLabel[21], CTabbedPane[39] */
/* 007e0514  FUN_007e0514  26 bytes, 0 callers */

undefined4 FUN_007e0514(undefined4 *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_1 = 0;
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CAutoHideDockSite[49], CAutoHideDockSite[50], CBasePane[49], CBasePane[50], CBaseTabbedPane[49], CBaseTabbedPane[50], CDockSite[49], CDockSite[50], CDockablePane[49], CDockablePane[50], CDockablePaneAdapter[49], CDockablePaneAdapter[50], CDummyDockablePane[49], CDummyDockablePane[50], CMFCAutoHideBar[49], CMFCAutoHideBar[50], CMFCBaseToolBar[49], CMFCBaseToolBar[50], CMFCCaptionBar[49], CMFCCaptionBar[50], CMFCColorBar[49], CMFCColorBar[50], CMFCDropDownToolBar[49], CMFCDropDownToolBar[50], CMFCImageEditorPaletteBar[49], CMFCImageEditorPaletteBar[50], CMFCMenuBar[49], CMFCMenuBar[50], CMFCOutlookBar[49], CMFCOutlookBar[50], CMFCOutlookBarPane[49], CMFCOutlookBarPane[50], CMFCOutlookBarPaneAdapter[49], CMFCOutlookBarPaneAdapter[50], CMFCOutlookBarToolBar[49], CMFCOutlookBarToolBar[50], CMFCPopupMenuBar[49], CMFCPopupMenuBar[50], CMFCPrintPreviewToolBar[49], CMFCPrintPreviewToolBar[50], CMFCPropertyGridCtrl[49], CMFCPropertyGridCtrl[50], CMFCRibbonPanelMenuBar[49], CMFCRibbonPanelMenuBar[50], CMFCTasksPane[49], CMFCTasksPane[50], CMFCTasksPaneToolBar[49], CMFCTasksPaneToolBar[50], CMFCToolBar[49], CMFCToolBar[50], CPane[49], CPane[50], CPaneDivider[49], CPaneDivider[50], CTabbedPane[49], CTabbedPane[50] */
/* 007e05c3  FUN_007e05c3  24 bytes, 0 callers */

int FUN_007e05c3(int param_1)

{
  return (-(uint)(param_1 != 0) & 0xfffaffac) + 0x80070057;
}




/* vtable slots: CAutoHideDockSite[47], CBasePane[47], CBaseTabbedPane[47], CDockSite[47], CDockablePane[47], CDockablePaneAdapter[47], CDummyDockablePane[47], CMFCAutoHideBar[47], CMFCBaseAccessibleObject[36], CMFCBaseToolBar[47], CMFCCaptionBar[47], CMFCColorBar[47], CMFCDropDownToolBar[47], CMFCImageEditorPaletteBar[47], CMFCMenuBar[47], CMFCOutlookBar[47], CMFCOutlookBarPane[47], CMFCOutlookBarPaneAdapter[47], CMFCOutlookBarToolBar[47], CMFCPopupMenuBar[47], CMFCPrintPreviewToolBar[47], CMFCPropertyGridCtrl[47], CMFCRibbonPanelMenuBar[47], CMFCTasksPane[47], CMFCTasksPaneToolBar[47], CMFCToolBar[47], CPane[47], CPaneDivider[47], CTabbedPane[47] */
/* 007e05e1  FUN_007e05e1  6 bytes, 0 callers */

undefined4 FUN_007e05e1(void)

{
  return 1;
}




/* vtable slots: CAutoHideDockSite[154], CBasePane[154], CBaseTabbedPane[154], CDockSite[154], CDockablePane[154], CDockablePaneAdapter[154], CDummyDockablePane[154], CMFCAutoHideBar[154], CMFCBaseToolBar[154], CMFCCaptionBar[154], CMFCColorBar[154], CMFCDropDownToolBar[154], CMFCImageEditorPaletteBar[154], CMFCMenuBar[154], CMFCOutlookBar[154], CMFCOutlookBarPane[154], CMFCOutlookBarPaneAdapter[154], CMFCOutlookBarToolBar[154], CMFCPopupMenuBar[154], CMFCPrintPreviewToolBar[154], CMFCRibbonPanelMenuBar[154], CMFCTasksPane[154], CMFCTasksPaneToolBar[154], CMFCToolBar[154], CPane[154], CPaneDivider[154], CTabbedPane[154] */
/* 007ed145  FUN_007ed145  270 bytes, 0 callers */

void FUN_007ed145(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  code *pcVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  pcVar3 = *(code **)(*in_ECX + 0x228);
  guard_check_icall(0);
  piVar1 = (int *)(*pcVar3)();
  if (piVar1 != (int *)0x0) {
    pcVar3 = *(code **)(*piVar1 + 0x1cc);
    guard_check_icall(uVar4);
    (*pcVar3)();
    return;
  }
  pcVar3 = *(code **)(*in_ECX + 0x19c);
  guard_check_icall(uVar4);
  piVar1 = (int *)(*pcVar3)();
  if (DAT_00a00960 == 0) {
    if (piVar1 == (int *)0x0) {
      return;
    }
    iVar2 = FUN_0079d98a(&PTR_s_CFrameWndEx_00994040);
    if (iVar2 == 0) {
      iVar2 = FUN_0079d98a(&PTR_s_CMDIFrameWndEx_009945d0);
      if (iVar2 == 0) {
        iVar2 = FUN_0079d98a(&PTR_s_COleIPFrameWndEx_00994be0);
        if ((iVar2 == 0) && (iVar2 = FUN_0079d98a(&PTR_s_COleDocIPFrameWndEx_00994f98), iVar2 == 0))
        {
          iVar2 = FUN_0079d98a(&PTR_s_CMDIChildWndEx_00995510);
          if (iVar2 == 0) {
            iVar2 = FUN_0079d98a(&PTR_s_COleCntrFrameWndEx_00996120);
            if (iVar2 == 0) {
              return;
            }
            pcVar3 = *(code **)(*piVar1 + 0x1c4);
          }
          else {
            pcVar3 = *(code **)(*piVar1 + 0x1cc);
          }
        }
        else {
          pcVar3 = *(code **)(*piVar1 + 0x1e4);
        }
      }
      else {
        pcVar3 = *(code **)(*piVar1 + 0x1c8);
      }
    }
    else {
      pcVar3 = *(code **)(*piVar1 + 0x1c0);
    }
    guard_check_icall(param_1);
    (*pcVar3)();
    return;
  }
  return;
}




/* vtable slots: CAutoHideDockSite[114], CBasePane[114], CBaseTabbedPane[114], CDockSite[114], CDockablePane[114], CDockablePaneAdapter[114], CDummyDockablePane[114], CMFCAutoHideBar[114], CMFCBaseToolBar[114], CMFCCaptionBar[114], CMFCOutlookBar[114], CMFCOutlookBarPaneAdapter[114], CMFCTasksPane[114], CPane[114], CPaneDivider[114], CTabbedPane[114] */
/* 007ed253  FUN_007ed253  10 bytes, 0 callers */

uint FUN_007ed253(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0xa0) & 8;
}




/* vtable slots: CAutoHideDockSite[115], CBasePane[115], CDockSite[115], CDockablePane[115], CDockablePaneAdapter[115], CDummyDockablePane[115], CMFCAutoHideBar[115], CMFCBaseToolBar[115], CMFCCaptionBar[115], CMFCColorBar[115], CMFCDropDownToolBar[115], CMFCImageEditorPaletteBar[115], CMFCMenuBar[115], CMFCOutlookBarPaneAdapter[115], CMFCOutlookBarToolBar[115], CMFCPopupMenuBar[115], CMFCPrintPreviewToolBar[115], CMFCRibbonPanelMenuBar[115], CMFCTasksPane[115], CMFCTasksPaneToolBar[115], CMFCToolBar[115], CPane[115], CPaneDivider[115] */
/* 007ed25d  FUN_007ed25d  132 bytes, 0 callers */

uint FUN_007ed25d(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *in_ECX;
  undefined4 local_8;
  
  pcVar1 = *(code **)(*in_ECX + 0x16c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    uVar4 = in_ECX[0x28];
  }
  else {
    local_8 = 0;
    piVar3 = (int *)FUN_007ed8bc(&local_8);
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 0x21c);
      guard_check_icall(local_8);
      iVar2 = (*pcVar1)();
      if (iVar2 != -1) {
        pcVar1 = *(code **)(*piVar3 + 0x1f0);
        guard_check_icall(iVar2);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
    }
    uVar4 = in_ECX[0x28];
  }
  return uVar4 & 1;
}




/* vtable slots: CAutoHideDockSite[143], CBasePane[143], CBaseTabbedPane[143], CDockSite[143], CDockablePane[143], CDockablePaneAdapter[143], CDummyDockablePane[143], CMFCAutoHideBar[143], CMFCBaseToolBar[143], CMFCCaptionBar[143], CMFCColorBar[143], CMFCDropDownToolBar[143], CMFCImageEditorPaletteBar[143], CMFCMenuBar[143], CMFCOutlookBar[143], CMFCOutlookBarPane[143], CMFCOutlookBarPaneAdapter[143], CMFCOutlookBarToolBar[143], CMFCPopupMenuBar[143], CMFCPrintPreviewToolBar[143], CMFCRibbonPanelMenuBar[143], CMFCTasksPane[143], CMFCTasksPaneToolBar[143], CMFCToolBar[143], CPane[143], CPaneDivider[143], CTabbedPane[143] */
/* 007ed34c  FUN_007ed34c  209 bytes, 1 callers */

void FUN_007ed34c(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  
  pcVar1 = *(code **)(*param_1 + 0x198);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  *(undefined4 *)(in_ECX + 0x98) = uVar2;
  pcVar1 = *(code **)(*param_1 + 0x1ac);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  *(undefined4 *)(in_ECX + 0x84) = uVar2;
  pcVar1 = *(code **)(*param_1 + 0x1b0);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  *(undefined4 *)(in_ECX + 0x88) = uVar2;
  pcVar1 = *(code **)(*param_1 + 0x19c);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  *(undefined4 *)(in_ECX + 0xa4) = uVar2;
  *(int *)(in_ECX + 0xa8) = param_1[0x2a];
  *(int *)(in_ECX + 0xac) = param_1[0x2b];
  *(int *)(in_ECX + 0xb0) = param_1[0x2c];
  *(int *)(in_ECX + 0xb4) = param_1[0x2d];
  *(int *)(in_ECX + 0x8c) = param_1[0x23];
  pcVar1 = *(code **)(*param_1 + 0x1c0);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  *(undefined4 *)(in_ECX + 0x9c) = uVar2;
  pcVar1 = *(code **)(*param_1 + 0x1c4);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  *(undefined4 *)(in_ECX + 0xa0) = uVar2;
  return;
}




/* vtable slots: CAutoHideDockSite[148], CBasePane[148], CBaseTabbedPane[148], CDockSite[148], CDockablePane[148], CDockablePaneAdapter[148], CDummyDockablePane[148], CMFCAutoHideBar[148], CMFCBaseToolBar[148], CMFCCaptionBar[148], CMFCColorBar[148], CMFCDropDownToolBar[148], CMFCImageEditorPaletteBar[148], CMFCMenuBar[148], CMFCOutlookBar[148], CMFCOutlookBarPane[148], CMFCOutlookBarPaneAdapter[148], CMFCOutlookBarToolBar[148], CMFCPopupMenuBar[148], CMFCPrintPreviewToolBar[148], CMFCRibbonPanelMenuBar[148], CMFCTasksPane[148], CMFCTasksPaneToolBar[148], CMFCToolBar[148], CPane[148], CPaneDivider[148], CTabbedPane[148] */
/* 007ed41d  FUN_007ed41d  549 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007ed41d(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,
                undefined4 param_5,CObject *param_6,undefined4 param_7,int param_8,
                undefined4 param_9)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  HBRUSH dwNewLong;
  int iVar5;
  CObject *pCVar6;
  int *in_ECX;
  undefined1 local_64 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  uint local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_34;
  undefined4 local_30;
  int *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  CObject *local_20;
  undefined4 local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_28 = param_2;
  local_24 = param_3;
  local_34 = param_5;
  local_20 = param_6;
  local_1c = param_7;
  local_30 = param_9;
  iVar2 = FUN_0079d98a(&PTR_s_CDialog_0097cf08);
  in_ECX[0x23] = iVar2;
  if ((in_ECX[0x25] != 0) && (iVar2 = FUN_0085a847(param_6), iVar2 == 0)) {
    uVar3 = FUN_007e5618(param_6);
    local_2c = (int *)FUN_0085a847(uVar3);
    if (local_2c != (int *)0x0) {
      pcVar1 = *(code **)(*local_2c + 0x24);
      guard_check_icall(param_7,1);
      (*pcVar1)();
    }
  }
  iVar2 = *in_ECX;
  in_ECX[0x20] = in_ECX[0x20] & 0x10000000;
  pcVar1 = *(code **)(iVar2 + 0x1c0);
  guard_check_icall();
  uVar4 = (*pcVar1)();
  pcVar1 = *(code **)(iVar2 + 0x1e4);
  guard_check_icall(uVar4 | param_4);
  (*pcVar1)();
  pCVar6 = local_20;
  in_ECX[0x28] = param_8;
  if (in_ECX[0x31] == 0) {
    iVar2 = FUN_007920d9(param_1,local_28,local_24,param_4,local_34,local_20,local_1c,local_30);
    if (iVar2 == 0) {
      return 0;
    }
  }
  else {
    _memset(local_64,0,0x30);
    local_3c = local_28;
    local_40 = local_24;
    local_44 = param_4 | 0x40000000;
    local_5c = local_1c;
    iVar2 = FUN_0079dd6d();
    pCVar6 = local_20;
    local_60 = *(undefined4 *)(iVar2 + 8);
    if (local_20 == (CObject *)0x0) {
      local_58 = 0;
    }
    else {
      local_58 = *(undefined4 *)(local_20 + 0x20);
    }
    pcVar1 = *(code **)(*in_ECX + 100);
    guard_check_icall(local_64);
    iVar2 = (*pcVar1)();
    if ((iVar2 == 0) || (iVar2 = FUN_007981f2(in_ECX[0x31],pCVar6), iVar2 == 0)) {
      return 0;
    }
    dwNewLong = GetSysColorBrush(0xf);
    SetClassLongW((HWND)in_ECX[8],-10,(LONG)dwNewLong);
    FUN_00797d82(local_1c);
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect((HWND)in_ECX[8],&local_18);
    iVar2 = 1;
    in_ECX[0x32] = local_18.right - local_18.left;
    in_ECX[0x33] = local_18.bottom - local_18.top;
  }
  iVar5 = FUN_0079d98a(&PTR_s_CFrameWnd_0097d624);
  if (iVar5 == 0) {
    pCVar6 = (CObject *)FUN_007e5618(pCVar6);
  }
  pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,pCVar6);
  in_ECX[0x29] = (int)pCVar6;
  iVar5 = FUN_0079d98a(&PTR_s_CDialog_0097cf08);
  in_ECX[0x23] = iVar5;
  return iVar2;
}




/* vtable slots: CAutoHideDockSite[153], CBasePane[153], CBaseTabbedPane[153], CDockSite[153], CDockablePane[153], CDockablePaneAdapter[153], CMFCBaseToolBar[153], CMFCCaptionBar[153], CMFCOutlookBar[153], CMFCOutlookBarPaneAdapter[153], CPane[153], CPaneDivider[153], CTabbedPane[153] */
/* 007ed642  FUN_007ed642  165 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007ed642(int *param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  tagRECT local_28;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  pcVar1 = *(code **)(*param_1 + 0x50);
  guard_check_icall(&local_18);
  (*pcVar1)();
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_28);
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x34);
  guard_check_icall(param_1,in_ECX,local_28.left,local_28.top,local_28.right,local_28.bottom,
                    local_18,local_14,local_10,local_c,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CAutoHideDockSite[123], CBasePane[123], CBaseTabbedPane[123], CDockSite[123], CDockablePane[123], CDockablePaneAdapter[123], CDummyDockablePane[123], CMFCAutoHideBar[123], CMFCBaseToolBar[123], CMFCCaptionBar[123], CMFCOutlookBar[123], CMFCOutlookBarPaneAdapter[123], CMFCTasksPane[123], CPane[123], CPaneDivider[123], CTabbedPane[123] */
/* 007ed7cb  FUN_007ed7cb  16 bytes, 0 callers */

void FUN_007ed7cb(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x98) = param_1;
  return;
}




/* vtable slots: CAutoHideDockSite[101], CBasePane[101], CBaseTabbedPane[101], CDockSite[101], CDockablePane[101], CDockablePaneAdapter[101], CDummyDockablePane[101], CMFCAutoHideBar[101], CMFCBaseToolBar[101], CMFCCaptionBar[101], CMFCColorBar[101], CMFCDropDownToolBar[101], CMFCImageEditorPaletteBar[101], CMFCMenuBar[101], CMFCOutlookBar[101], CMFCOutlookBarPaneAdapter[101], CMFCOutlookBarToolBar[101], CMFCPopupMenuBar[101], CMFCPrintPreviewToolBar[101], CMFCRibbonPanelMenuBar[101], CMFCTasksPane[101], CMFCTasksPaneToolBar[101], CMFCToolBar[101], CPane[101], CPaneDivider[101], CTabbedPane[101] */
/* 007ed7db  FUN_007ed7db  12 bytes, 0 callers */

uint FUN_007ed7db(void)

{
  int in_ECX;
  
  return *(uint *)(in_ECX + 0x9c) & 0xf000;
}




/* vtable slots: CAutoHideDockSite[103], CBasePane[103], CBaseTabbedPane[103], CDockSite[103], CDockablePane[103], CDockablePaneAdapter[103], CDummyDockablePane[103], CMFCAutoHideBar[103], CMFCBaseToolBar[103], CMFCCaptionBar[103], CMFCColorBar[103], CMFCDropDownToolBar[103], CMFCImageEditorPaletteBar[103], CMFCMenuBar[103], CMFCOutlookBar[103], CMFCOutlookBarPane[103], CMFCOutlookBarPaneAdapter[103], CMFCOutlookBarToolBar[103], CMFCPopupMenuBar[103], CMFCPrintPreviewToolBar[103], CMFCRibbonPanelMenuBar[103], CMFCTasksPane[103], CMFCTasksPaneToolBar[103], CMFCToolBar[103], CPane[103], CPaneDivider[103], CTabbedPane[103] */
/* 007ed7e7  GetDockSiteFrameWnd  106 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CWnd * __thiscall CBasePane::GetDockSiteFrameWnd(void)const 
   
   Library: Visual Studio 2015 Release */

CWnd * __thiscall CBasePane::GetDockSiteFrameWnd(CBasePane *this)

{
  HWND pHVar1;
  int iVar2;
  CWnd *pCVar3;
  int iVar4;
  int iVar5;
  
  iVar5 = 0;
  if (*(int *)(this + 0xa4) == 0) {
    pHVar1 = GetParent(*(HWND *)(this + 0x20));
    CWnd::FromHandle(pHVar1);
    iVar2 = FUN_0079d98a(&PTR_s_CDialog_0097cf08);
    if (iVar2 != 0) {
      pHVar1 = GetParent(*(HWND *)(this + 0x20));
      pCVar3 = CWnd::FromHandle(pHVar1);
      iVar2 = 0;
      if (pCVar3 != (CWnd *)0x0) {
        iVar2 = *(int *)(pCVar3 + 0x20);
      }
      iVar4 = FUN_00404c80();
      if (iVar4 != 0) {
        iVar5 = *(int *)(iVar4 + 0x20);
      }
      if (iVar2 == iVar5) {
        DAT_00a00960 = 1;
      }
    }
  }
  return *(CWnd **)(this + 0xa4);
}




/* vtable slots: CAutoHideDockSite[110], CBasePane[110], CBaseTabbedPane[110], CDockSite[110], CDockablePane[110], CDockablePaneAdapter[110], CDummyDockablePane[110], CMFCAutoHideBar[110], CMFCCaptionBar[110], CMFCOutlookBar[110], CMFCOutlookBarPaneAdapter[110], CMFCTasksPane[110], CPane[110], CPaneDivider[110], CTabbedPane[110] */
/* 007ed851  FUN_007ed851  16 bytes, 0 callers */

int FUN_007ed851(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc0);
  if (*(int *)(in_ECX + 0xc0) == 0) {
    iVar1 = DAT_00a00928;
  }
  return iVar1;
}




/* vtable slots: CAutoHideDockSite[138], CBasePane[138], CBaseTabbedPane[138], CDockSite[138], CDockablePane[138], CDockablePaneAdapter[138], CDummyDockablePane[138], CMFCAutoHideBar[138], CMFCBaseToolBar[138], CMFCCaptionBar[138], CMFCColorBar[138], CMFCDropDownToolBar[138], CMFCImageEditorPaletteBar[138], CMFCMenuBar[138], CMFCOutlookBar[138], CMFCOutlookBarPane[138], CMFCOutlookBarPaneAdapter[138], CMFCOutlookBarToolBar[138], CMFCPopupMenuBar[138], CMFCPrintPreviewToolBar[138], CMFCRibbonPanelMenuBar[138], CMFCTasksPane[138], CMFCTasksPaneToolBar[138], CMFCToolBar[138], CPane[138], CPaneDivider[138], CTabbedPane[138] */
/* 007ed867  GetParentMiniFrame  85 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CPaneFrameWnd * __thiscall CBasePane::GetParentMiniFrame(int)const 
   
   Library: Visual Studio 2015 Release */

CPaneFrameWnd * __thiscall CBasePane::GetParentMiniFrame(CBasePane *this,int param_1)

{
  HWND pHVar1;
  CObject *pCVar2;
  int iVar3;
  
  pHVar1 = GetParent(*(HWND *)(this + 0x20));
  pCVar2 = (CObject *)CWnd::FromHandle(pHVar1);
  while( true ) {
    if (pCVar2 == (CObject *)0x0) {
      return (CPaneFrameWnd *)0x0;
    }
    iVar3 = FUN_0079d98a(&PTR_s_CPaneFrameWnd_00a008b0);
    if (iVar3 != 0) break;
    pHVar1 = GetParent(*(HWND *)(pCVar2 + 0x20));
    pCVar2 = (CObject *)CWnd::FromHandle(pHVar1);
  }
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,pCVar2);
  return (CPaneFrameWnd *)pCVar2;
}




/* vtable slots: CAutoHideDockSite[90], CBasePane[90], CBaseTabbedPane[90], CDockSite[90], CDockablePane[90], CDockablePaneAdapter[90], CDummyDockablePane[90], CMFCAutoHideBar[90], CMFCBaseToolBar[90], CMFCCaptionBar[90], CMFCColorBar[90], CMFCDropDownToolBar[90], CMFCImageEditorPaletteBar[90], CMFCMenuBar[90], CMFCOutlookBar[90], CMFCOutlookBarPane[90], CMFCOutlookBarPaneAdapter[90], CMFCOutlookBarToolBar[90], CMFCPopupMenuBar[90], CMFCPrintPreviewToolBar[90], CMFCRibbonPanelMenuBar[90], CMFCTasksPane[90], CMFCTasksPaneToolBar[90], CMFCToolBar[90], CPane[90], CPaneDivider[90], CTabbedPane[90] */
/* 007edb35  FUN_007edb35  67 bytes, 0 callers */

undefined4 FUN_007edb35(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uVar4;
  
  uVar4 = 0;
  pcVar1 = *(code **)(*in_ECX + 0x228);
  guard_check_icall(0);
  piVar2 = (int *)(*pcVar1)();
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 0x1a0);
    guard_check_icall(uVar4);
    iVar3 = (*pcVar1)();
    if (iVar3 == 1) {
      return 0;
    }
  }
  return 1;
}




/* vtable slots: CAutoHideDockSite[92], CBasePane[92], CBaseTabbedPane[92], CDockSite[92], CDockablePane[92], CDockablePaneAdapter[92], CDummyDockablePane[92], CMFCAutoHideBar[92], CMFCBaseToolBar[92], CMFCCaptionBar[92], CMFCOutlookBar[92], CMFCOutlookBarPaneAdapter[92], CMFCTasksPane[92], CPane[92], CPaneDivider[92], CTabbedPane[92] */
/* 007edb78  FUN_007edb78  32 bytes, 0 callers */

bool FUN_007edb78(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x168);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  return iVar2 == 0;
}




/* vtable slots: CAutoHideDockSite[93], CBasePane[93], CBaseTabbedPane[93], CDockSite[93], CDockablePane[93], CDockablePaneAdapter[93], CDummyDockablePane[93], CMFCAutoHideBar[93], CMFCBaseToolBar[93], CMFCCaptionBar[93], CMFCColorBar[93], CMFCDropDownToolBar[93], CMFCImageEditorPaletteBar[93], CMFCMenuBar[93], CMFCOutlookBar[93], CMFCOutlookBarPane[93], CMFCOutlookBarPaneAdapter[93], CMFCOutlookBarToolBar[93], CMFCPopupMenuBar[93], CMFCPrintPreviewToolBar[93], CMFCRibbonPanelMenuBar[93], CMFCTasksPane[93], CMFCTasksPaneToolBar[93], CMFCToolBar[93], CPane[93], CPaneDivider[93], CTabbedPane[93] */
/* 007edb98  FUN_007edb98  7 bytes, 0 callers */

undefined4 FUN_007edb98(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x90);
}




/* vtable slots: CAutoHideDockSite[91], CBasePane[91], CDockSite[91], CPaneDivider[91] */
/* 007edcb8  FUN_007edcb8  28 bytes, 0 callers */

void FUN_007edcb8(void)

{
  HWND pHVar1;
  int in_ECX;
  
  pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
  CWnd::FromHandle(pHVar1);
  FUN_0079d98a(&PTR_s_CMFCBaseTabCtrl_0098c714);
  return;
}




/* vtable slots: CAutoHideDockSite[95], CBasePane[95], CDockSite[95], CMFCAutoHideBar[95], CMFCBaseToolBar[95], CMFCCaptionBar[95], CMFCColorBar[95], CMFCDropDownToolBar[95], CMFCImageEditorPaletteBar[95], CMFCMenuBar[95], CMFCOutlookBarPane[95], CMFCOutlookBarToolBar[95], CMFCPopupMenuBar[95], CMFCPrintPreviewToolBar[95], CMFCRibbonPanelMenuBar[95], CMFCTasksPaneToolBar[95], CMFCToolBar[95], CPane[95], CPaneDivider[95] */
/* 007edcd4  FUN_007edcd4  191 bytes, 1 callers */

uint FUN_007edcd4(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  BOOL BVar5;
  int iVar6;
  int *in_ECX;
  undefined4 uVar7;
  undefined4 local_8;
  
  pcVar1 = *(code **)(*in_ECX + 0x16c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    if (DAT_00a13b28 == 0) {
      uVar3 = FUN_00797b3d();
      uVar3 = uVar3 >> 0x1c & 1;
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x1ac);
      guard_check_icall();
      uVar3 = (*pcVar1)();
    }
  }
  else {
    local_8 = 0;
    piVar4 = (int *)FUN_007ed8bc(&local_8);
    BVar5 = IsWindowVisible((HWND)piVar4[8]);
    if (BVar5 != 0) {
      pcVar1 = *(code **)(*piVar4 + 0x21c);
      uVar7 = local_8;
      guard_check_icall(local_8);
      iVar2 = (*pcVar1)();
      if (-1 < iVar2) {
        pcVar1 = *(code **)(*piVar4 + 0x1ac);
        guard_check_icall(uVar7);
        iVar6 = (*pcVar1)();
        if (iVar2 < iVar6) {
          pcVar1 = *(code **)(*piVar4 + 0x27c);
          guard_check_icall(iVar2);
          uVar3 = (*pcVar1)();
          return uVar3;
        }
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}




/* vtable slots: CAutoHideDockSite[139], CBasePane[139], CDockSite[139], CPaneDivider[139] */
/* 007edd93  FUN_007edd93  276 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x007ede76) */

bool FUN_007edd93(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_1c;
  int *local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x7edd9f;
  FUN_008592c1(&local_1c,L"BasePanes",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(local_14,L"%TsBasePane-%d",local_1c,param_2);
  }
  else {
    FUN_004059f0(local_14,L"%TsBasePane-%d%x",local_1c,param_2,param_3);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  local_18 = (int *)FUN_00859490(0,1);
  pcVar1 = *(code **)(*local_18 + 0x10);
  guard_check_icall(local_14[0]);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*local_18 + 0x54);
    guard_check_icall(L"IsVisible",in_ECX + 0x84);
    (*pcVar1)();
    *(undefined4 *)(in_ECX + 0x88) = 1;
  }
  FUN_00406b10();
  FUN_00406b10();
  return iVar2 != 0;
}




/* vtable slots: CAutoHideDockSite[141], CBasePane[141], CBaseTabbedPane[141], CDockSite[141], CDockablePane[141], CDockablePaneAdapter[141], CDummyDockablePane[141], CMFCAutoHideBar[141], CMFCBaseToolBar[141], CMFCCaptionBar[141], CMFCColorBar[141], CMFCDropDownToolBar[141], CMFCImageEditorPaletteBar[141], CMFCMenuBar[141], CMFCOutlookBar[141], CMFCOutlookBarPane[141], CMFCOutlookBarPaneAdapter[141], CMFCOutlookBarToolBar[141], CMFCPopupMenuBar[141], CMFCPrintPreviewToolBar[141], CMFCRibbonPanelMenuBar[141], CMFCTasksPane[141], CMFCTasksPaneToolBar[141], CMFCToolBar[141], CPane[141], CPaneDivider[141], CTabbedPane[141] */
/* 007edea7  FUN_007edea7  221 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

HDWP FUN_007edea7(tagRECT *param_1,int param_2,HDWP param_3)

{
  code *pcVar1;
  int iVar2;
  CWnd *this;
  BOOL BVar3;
  CWnd *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
  pcVar1 = *(code **)(*(int *)in_ECX + 0x170);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    this = *(CWnd **)(in_ECX + 0xa4);
    if (this == (CWnd *)0x0) goto LAB_007edf29;
  }
  else {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x228);
    guard_check_icall(0);
    this = (CWnd *)(*pcVar1)();
  }
  CWnd::ScreenToClient(this,&local_18);
LAB_007edf29:
  BVar3 = EqualRect(&local_18,param_1);
  if (BVar3 == 0) {
    if (param_3 == (HDWP)0x0) {
      CWnd::MoveWindow(in_ECX,param_1,param_2);
      param_3 = (HDWP)0x0;
    }
    else {
      param_3 = DeferWindowPos(param_3,*(HWND *)(in_ECX + 0x20),(HWND)0x0,param_1->left,param_1->top
                               ,param_1->right - param_1->left,param_1->bottom - param_1->top,0x14);
    }
  }
  return param_3;
}




/* vtable slots: CAutoHideDockSite[146], CBasePane[146], CBaseTabbedPane[146], CDockSite[146], CDockablePane[146], CDockablePaneAdapter[146], CDummyDockablePane[146], CMFCAutoHideBar[146], CMFCBaseToolBar[146], CMFCCaptionBar[146], CMFCColorBar[146], CMFCDropDownToolBar[146], CMFCImageEditorPaletteBar[146], CMFCMenuBar[146], CMFCOutlookBar[146], CMFCOutlookBarPane[146], CMFCOutlookBarPaneAdapter[146], CMFCOutlookBarToolBar[146], CMFCPopupMenuBar[146], CMFCPrintPreviewToolBar[146], CMFCRibbonPanelMenuBar[146], CMFCTasksPane[146], CMFCTasksPaneToolBar[146], CMFCToolBar[146], CPane[146], CPaneDivider[146], CTabbedPane[146] */
/* 007ee0b7  OnPaneContextMenu  94 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CBasePane::OnPaneContextMenu(class CWnd *,class CPoint)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CBasePane::OnPaneContextMenu(CBasePane *this,int param_1,undefined4 param_3,undefined4 param_4)

{
  LRESULT LVar1;
  undefined4 uVar2;
  int iVar3;
  WPARAM wParam;
  
  if (this == (CBasePane *)0x0) {
    wParam = 0;
  }
  else {
    wParam = *(WPARAM *)(this + 0x20);
  }
  LVar1 = SendMessageW(*(HWND *)(param_1 + 0x20),DAT_00a127bc,wParam,
                       CONCAT22((undefined2)param_4,(undefined2)param_3));
  if (LVar1 != 0) {
    uVar2 = FUN_0079296c();
    iVar3 = FUN_0085a847(uVar2);
    if (iVar3 != 0) {
      FUN_0084846e(param_3,param_4);
    }
  }
  return;
}




/* vtable slots: CAutoHideDockSite[67], CBasePane[67], CDockSite[67], CMFCAutoHideBar[67], CMFCBaseToolBar[67], CPane[67], CPaneDivider[67] */
/* 007ee372  FUN_007ee372  139 bytes, 4 callers */

undefined4 FUN_007ee372(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  CWnd *pCVar3;
  undefined4 uVar4;
  BOOL BVar5;
  CWnd *in_ECX;
  
  if (*(int *)(in_ECX + 0x20) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  iVar2 = FUN_007949fb(param_1);
  if (iVar2 == 0) {
    pCVar3 = CWnd::GetOwner(in_ECX);
    iVar2 = FUN_00792b4c();
    if ((iVar2 == 0) || (*(int *)(iVar2 + 0x94) == 0)) {
      while (pCVar3 != (CWnd *)0x0) {
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x10c);
        guard_check_icall(param_1);
        iVar2 = (*pcVar1)();
        if (iVar2 != 0) goto LAB_007ee3ee;
        BVar5 = IsWindow(*(HWND *)(pCVar3 + 0x20));
        if (BVar5 == 0) break;
        pCVar3 = (CWnd *)FUN_0079296c();
      }
      uVar4 = FUN_007949cc(param_1);
    }
    else {
      uVar4 = 0;
    }
  }
  else {
LAB_007ee3ee:
    uVar4 = 1;
  }
  return uVar4;
}




/* vtable slots: CAutoHideDockSite[140], CBasePane[140], CDockSite[140], CPaneDivider[140] */
/* 007ee520  FUN_007ee520  269 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x007ee5fc) */

undefined4 FUN_007ee520(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x7ee52c;
  FUN_008592c1(&local_18,L"BasePanes",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(local_14,L"%TsBasePane-%d",local_18,param_2);
  }
  else {
    FUN_004059f0(local_14,L"%TsBasePane-%d%x",local_18,param_2,param_3);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar2 = (int *)FUN_00859490(0,0);
  pcVar1 = *(code **)(*piVar2 + 0xc);
  guard_check_icall(local_14[0]);
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x17c);
    guard_check_icall(local_14[0]);
    uVar4 = (*pcVar1)();
    pcVar1 = *(code **)(*piVar2 + 0x38);
    guard_check_icall(L"IsVisible",uVar4);
    (*pcVar1)();
  }
  FUN_00406b10();
  FUN_00406b10();
  return 1;
}




/* vtable slots: CAutoHideDockSite[2], CBasePane[2], CDockSite[2], CMFCAutoHideBar[2], CMFCBaseToolBar[2], CMFCCaptionBar[2], CPane[2] */
/* 007ee62d  FUN_007ee62d  110 bytes, 3 callers */

void FUN_007ee62d(CArchive *param_1)

{
  code *pcVar1;
  long lVar2;
  int *in_ECX;
  uint local_8;
  
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,in_ECX[0x27] & 0xf000);
    pcVar1 = *(code **)(*in_ECX + 0x17c);
    guard_check_icall();
    lVar2 = (*pcVar1)();
    CArchive::operator<<(param_1,lVar2);
  }
  else {
    local_8 = 0;
    CArchive::operator>>(param_1,(long *)&local_8);
    in_ECX[0x27] = in_ECX[0x27] | local_8;
    CArchive::operator>>(param_1,in_ECX + 0x21);
  }
  return;
}




/* vtable slots: CAutoHideDockSite[142], CBasePane[142], CBaseTabbedPane[142], CDockSite[142], CDockablePane[142], CDockablePaneAdapter[142], CDummyDockablePane[142], CMFCAutoHideBar[142], CMFCBaseToolBar[142], CMFCCaptionBar[142], CMFCColorBar[142], CMFCDropDownToolBar[142], CMFCImageEditorPaletteBar[142], CMFCMenuBar[142], CMFCOutlookBar[142], CMFCOutlookBarPane[142], CMFCOutlookBarPaneAdapter[142], CMFCOutlookBarToolBar[142], CMFCPopupMenuBar[142], CMFCPrintPreviewToolBar[142], CMFCRibbonPanelMenuBar[142], CMFCTasksPane[142], CMFCTasksPaneToolBar[142], CMFCToolBar[142], CPane[142], CPaneDivider[142], CTabbedPane[142] */
/* 007ee69b  FUN_007ee69b  136 bytes, 0 callers */

HDWP FUN_007ee69b(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,UINT param_6,
                 HDWP param_7)

{
  code *pcVar1;
  HWND hWnd;
  HDWP pvVar2;
  int *in_ECX;
  
  if (param_7 == (HDWP)0x0) {
    FUN_00797e71(param_1,param_2,param_3,param_4,param_5,param_6);
    pvVar2 = (HDWP)0x0;
  }
  else {
    if (in_ECX == (int *)0x0) {
      hWnd = (HWND)0x0;
    }
    else {
      hWnd = (HWND)in_ECX[8];
    }
    pvVar2 = DeferWindowPos(param_7,hWnd,(HWND)0x0,param_2,param_3,param_4,param_5,param_6);
    if (pvVar2 == (HDWP)0x0) {
      GetLastError();
      pcVar1 = *(code **)(*in_ECX + 0x238);
      guard_check_icall(0,param_2,param_3,param_4,param_5,param_6,0);
      (*pcVar1)();
      pvVar2 = param_7;
    }
  }
  return pvVar2;
}




/* vtable slots: CAutoHideDockSite[137], CBasePane[137], CDockSite[137], CMFCAutoHideBar[137], CMFCBaseToolBar[137], CMFCCaptionBar[137], CMFCColorBar[137], CMFCDropDownToolBar[137], CMFCImageEditorPaletteBar[137], CMFCMenuBar[137], CMFCOutlookBarPane[137], CMFCOutlookBarToolBar[137], CMFCPopupMenuBar[137], CMFCPrintPreviewToolBar[137], CMFCRibbonPanelMenuBar[137], CMFCTasksPaneToolBar[137], CMFCToolBar[137], CPane[137], CPaneDivider[137] */
/* 007ee723  FUN_007ee723  558 bytes, 1 callers */

void FUN_007ee723(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  CObject *pCVar5;
  uint uVar6;
  undefined4 uVar7;
  int *in_ECX;
  byte bVar8;
  code *pcVar9;
  int *local_8;
  
  bVar8 = -(param_1 != 0) & 4;
  pcVar9 = *(code **)(*in_ECX + 0x170);
  local_8 = in_ECX;
  guard_check_icall();
  iVar2 = (*pcVar9)();
  if (iVar2 != 0) {
    pcVar9 = *(code **)(*in_ECX + 0x16c);
    guard_check_icall();
    iVar2 = (*pcVar9)();
    if (iVar2 == 0) {
      FUN_00797f20(bVar8);
      pHVar3 = GetParent((HWND)in_ECX[8]);
      pCVar4 = CWnd::FromHandle(pHVar3);
      if ((param_2 == 0) || (param_1 == 0)) {
        FUN_00797f20(bVar8);
      }
      PostMessageW(*(HWND *)(pCVar4 + 0x20),DAT_00a13b18,0,0);
      goto LAB_007ee937;
    }
  }
  local_8 = (int *)in_ECX[0x2e];
  if (local_8 == (int *)0x0) {
    pcVar9 = *(code **)(*in_ECX + 0x16c);
    guard_check_icall();
    iVar2 = (*pcVar9)();
    if (iVar2 == 0) {
      FUN_00797f20(bVar8);
      if (param_2 == 0) {
        pcVar9 = *(code **)(*in_ECX + 0x268);
        guard_check_icall(0);
        (*pcVar9)();
      }
      goto LAB_007ee937;
    }
    local_8 = (int *)FUN_007ed8bc(&local_8);
    pHVar3 = GetParent((HWND)local_8[8]);
    pCVar4 = CWnd::FromHandle(pHVar3);
    pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CBaseTabbedPane_00996820,(CObject *)pCVar4);
    piVar1 = local_8;
    if (pCVar5 != (CObject *)0x0) {
      uVar6 = FUN_00797b3d();
      if ((uVar6 & 0x10000000) == 0) {
        pcVar9 = *(code **)(*(int *)pCVar5 + 0x3a4);
        guard_check_icall();
        iVar2 = (*pcVar9)();
        if ((1 < iVar2) && (param_1 != 0)) {
          pcVar9 = *(code **)(*(int *)pCVar5 + 0x3c4);
          guard_check_icall();
          (*pcVar9)();
          return;
        }
      }
      pcVar9 = *(code **)(*(int *)pCVar5 + 0x3c4);
      guard_check_icall();
      (*pcVar9)();
      pcVar9 = *(code **)(*local_8 + 0x1a4);
      guard_check_icall();
      iVar2 = (*pcVar9)();
      if (iVar2 == 0) {
        pcVar9 = *(code **)(*(int *)pCVar5 + 0x224);
        guard_check_icall(param_1,param_2,param_3);
        (*pcVar9)();
      }
      goto LAB_007ee937;
    }
    pcVar9 = *(code **)(*local_8 + 0x21c);
    guard_check_icall(in_ECX[8]);
    uVar7 = (*pcVar9)();
    pcVar9 = *(code **)(*piVar1 + 0x1a8);
    guard_check_icall(uVar7,param_1,param_2 == 0,0);
  }
  else {
    pcVar9 = *(code **)(*local_8 + 0x2a0);
    guard_check_icall();
  }
  (*pcVar9)();
LAB_007ee937:
  if (in_ECX[0x2f] != 0) {
    FUN_008572d1(0,0);
  }
  return;
}




/* vtable slots: CAutoHideDockSite[130], CBasePane[130], CBaseTabbedPane[130], CDockSite[130], CDockablePane[130], CDockablePaneAdapter[130], CDummyDockablePane[130], CMFCBaseToolBar[130], CMFCCaptionBar[130], CMFCOutlookBar[130], CMFCOutlookBarPaneAdapter[130], CMFCTasksPane[130], CPane[130], CPaneDivider[130], CTabbedPane[130] */
/* 007ee951  FUN_007ee951  17 bytes, 0 callers */

void FUN_007ee951(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  return;
}




/* vtable slots: CAutoHideDockSite[69], CBasePane[69], CBaseTabbedPane[69], CDockSite[69], CDockablePane[69], CDockablePaneAdapter[69], CDummyDockablePane[69], CMFCAutoHideBar[69], CMFCBaseToolBar[69], CMFCCaptionBar[69], CMFCColorBar[69], CMFCDropDownToolBar[69], CMFCImageEditorPaletteBar[69], CMFCMenuBar[69], CMFCOutlookBar[69], CMFCOutlookBarPane[69], CMFCOutlookBarPaneAdapter[69], CMFCOutlookBarToolBar[69], CMFCPopupMenuBar[69], CMFCPrintPreviewToolBar[69], CMFCRibbonPanelMenuBar[69], CMFCTasksPane[69], CMFCTasksPaneToolBar[69], CMFCToolBar[69], CPane[69], CPaneDivider[69], CTabbedPane[69] */
/* 007ee962  FUN_007ee962  230 bytes, 0 callers */

CWnd * FUN_007ee962(uint param_1,WPARAM param_2,int param_3)

{
  code *pcVar1;
  CWnd *pCVar2;
  int iVar3;
  CWnd *in_ECX;
  bool bVar4;
  CWnd *local_c;
  CWnd *local_8;
  
  if (param_1 < 0x30) {
    if ((((param_1 != 0x2f) && (param_1 != 0x2b)) && (param_1 != 0x2c)) && (param_1 != 0x2d)) {
      bVar4 = param_1 == 0x2e;
LAB_007ee99b:
      if (!bVar4) {
        pCVar2 = (CWnd *)FUN_007958aa(param_1,param_2,param_3);
        return pCVar2;
      }
    }
  }
  else if ((param_1 != 0x39) && (param_1 != 0x4e)) {
    bVar4 = param_1 == 0x111;
    goto LAB_007ee99b;
  }
  pcVar1 = *(code **)(*(int *)in_ECX + 0x118);
  local_c = in_ECX;
  local_8 = in_ECX;
  guard_check_icall(param_1,param_2,param_3,&local_c);
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    return local_c;
  }
  pCVar2 = CWnd::GetOwner(local_8);
  local_c = (CWnd *)SendMessageW(*(HWND *)(pCVar2 + 0x20),param_1,param_2,param_3);
  if (param_1 != 0x4e) {
    return local_c;
  }
  if (*(int *)(param_3 + 8) == -0x208) {
    if (*(int *)(param_3 + 0x60) != 0) {
      return local_c;
    }
    if (*(char **)(param_3 + 0xc) == (char *)0x0) goto LAB_007eea1d;
    bVar4 = **(char **)(param_3 + 0xc) == '\0';
  }
  else {
    if (*(int *)(param_3 + 8) != -0x212) {
      return local_c;
    }
    if (*(int *)(param_3 + 0xb0) != 0) {
      return local_c;
    }
    if (*(short **)(param_3 + 0xc) == (short *)0x0) goto LAB_007eea1d;
    bVar4 = **(short **)(param_3 + 0xc) == 0;
  }
  if (!bVar4) {
    return local_c;
  }
LAB_007eea1d:
  pCVar2 = (CWnd *)FUN_007958aa(0x4e,param_2,param_3);
  return pCVar2;
}




/* vtable slots: CAutoHideDockSite[55], CBasePane[55], CBaseTabbedPane[55], CDockSite[55], CDockablePane[55], CDockablePaneAdapter[55], CDummyDockablePane[55], CMFCAutoHideBar[55], CMFCBaseToolBar[55], CMFCCaptionBar[55], CMFCOutlookBar[55], CMFCOutlookBarPaneAdapter[55], CMFCTasksPane[55], CPane[55], CPaneDivider[55], CTabbedPane[55] */
/* 007eea48  FUN_007eea48  92 bytes, 0 callers */

undefined4 FUN_007eea48(undefined2 param_1,undefined2 param_2,undefined2 *param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if (param_3 == (undefined2 *)0x0) {
    uVar3 = 0x80070057;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x254);
    guard_check_icall(CONCAT22(param_2,param_1));
    (*pcVar1)();
    iVar2 = in_ECX[0x3c];
    *param_3 = 3;
    *(uint *)(param_3 + 4) = -(uint)(iVar2 != 0) & CONCAT22(param_2,param_1);
    uVar3 = 0;
  }
  return uVar3;
}




/* vtable slots: CAutoHideDockSite[53], CBasePane[53], CBaseTabbedPane[53], CDockSite[53], CDockablePane[53], CDockablePaneAdapter[53], CDummyDockablePane[53], CMFCAutoHideBar[53], CMFCBaseToolBar[53], CMFCCaptionBar[53], CMFCColorBar[53], CMFCDropDownToolBar[53], CMFCImageEditorPaletteBar[53], CMFCMenuBar[53], CMFCOutlookBar[53], CMFCOutlookBarPane[53], CMFCOutlookBarPaneAdapter[53], CMFCOutlookBarToolBar[53], CMFCPopupMenuBar[53], CMFCPrintPreviewToolBar[53], CMFCRibbonPanelMenuBar[53], CMFCTasksPane[53], CMFCTasksPaneToolBar[53], CMFCToolBar[53], CPane[53], CPaneDivider[53], CTabbedPane[53] */
/* 007eeaa4  FUN_007eeaa4  244 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007eeaa4(int *param_1,int *param_2,int *param_3,int *param_4,short param_5,undefined4 param_6,
            int param_7)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) && (param_3 != (int *)0x0)) &&
     (param_4 != (int *)0x0)) {
    if (param_5 == 3) {
      if (param_7 == 0) {
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        GetWindowRect((HWND)in_ECX[8],&local_18);
        *param_1 = local_18.left;
        *param_2 = local_18.top;
        *param_3 = local_18.right - local_18.left;
        iVar2 = local_18.bottom - local_18.top;
      }
      else {
        if (param_7 < 1) {
          return 0;
        }
        pcVar1 = *(code **)(*in_ECX + 0x254);
        guard_check_icall(param_7);
        (*pcVar1)();
        *param_1 = in_ECX[0x3d];
        *param_2 = in_ECX[0x3e];
        *param_3 = in_ECX[0x3f] - in_ECX[0x3d];
        iVar2 = in_ECX[0x40] - in_ECX[0x3e];
      }
      *param_4 = iVar2;
    }
    return 0;
  }
  return 0x80070057;
}




/* vtable slots: CAutoHideDockSite[40], CBasePane[40], CBaseTabbedPane[40], CDockSite[40], CDockablePane[40], CDockablePaneAdapter[40], CDummyDockablePane[40], CMFCAutoHideBar[40], CMFCBaseToolBar[40], CMFCCaptionBar[40], CMFCOutlookBar[40], CMFCOutlookBarPaneAdapter[40], CMFCTasksPane[40], CPane[40], CPaneDivider[40], CTabbedPane[40] */
/* 007eeb98  FUN_007eeb98  42 bytes, 0 callers */

undefined4
FUN_007eeb98(short param_1,undefined4 param_2,int param_3,undefined4 param_4,int *param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*param_5 == 0) || ((param_1 == 3 && (param_3 == 0)))) {
    uVar1 = 0x80070057;
  }
  else {
    *param_5 = *(int *)(in_ECX + 0x28);
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CAutoHideDockSite[51], CBasePane[51], CBaseTabbedPane[51], CDockSite[51], CDockablePane[51], CDockablePaneAdapter[51], CDummyDockablePane[51], CMFCAutoHideBar[51], CMFCBaseToolBar[51], CMFCCaptionBar[51], CMFCColorBar[51], CMFCDropDownToolBar[51], CMFCImageEditorPaletteBar[51], CMFCMenuBar[51], CMFCOutlookBar[51], CMFCOutlookBarPane[51], CMFCOutlookBarPaneAdapter[51], CMFCOutlookBarToolBar[51], CMFCPopupMenuBar[51], CMFCPrintPreviewToolBar[51], CMFCRibbonPanelMenuBar[51], CMFCTasksPane[51], CMFCTasksPaneToolBar[51], CMFCToolBar[51], CPane[51], CPaneDivider[51], CTabbedPane[51] */
/* 007eebc2  FUN_007eebc2  90 bytes, 0 callers */

undefined4
FUN_007eebc2(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (param_1 == 3) {
    if (param_3 == 0) {
      return 1;
    }
  }
  else if (param_3 != 0) {
    return 0x80070057;
  }
  pcVar1 = *(code **)(*in_ECX + 0x254);
  guard_check_icall(param_3);
  (*pcVar1)();
  if (*(int *)(in_ECX[0x39] + -0xc) == 0) {
    return 1;
  }
  uVar2 = FUN_007913e5();
  *param_5 = uVar2;
  return 0;
}




/* vtable slots: CAutoHideDockSite[43], CBasePane[43], CBaseTabbedPane[43], CDockSite[43], CDockablePane[43], CDockablePaneAdapter[43], CDummyDockablePane[43], CMFCAutoHideBar[43], CMFCBaseToolBar[43], CMFCCaptionBar[43], CMFCColorBar[43], CMFCDropDownToolBar[43], CMFCImageEditorPaletteBar[43], CMFCMenuBar[43], CMFCOutlookBar[43], CMFCOutlookBarPane[43], CMFCOutlookBarPaneAdapter[43], CMFCOutlookBarToolBar[43], CMFCPopupMenuBar[43], CMFCPrintPreviewToolBar[43], CMFCRibbonPanelMenuBar[43], CMFCTasksPane[43], CMFCTasksPaneToolBar[43], CMFCToolBar[43], CPane[43], CPaneDivider[43], CTabbedPane[43] */
/* 007eec1c  FUN_007eec1c  155 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_007eec1c(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  code *pcVar1;
  BSTR pOVar2;
  undefined4 uVar3;
  int *in_ECX;
  OLECHAR *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x7eec28;
  if (param_1 == 3) {
    if (param_3 == 0) {
      CStringT<>();
      local_8 = 0;
      FUN_00792c64(local_14);
      pOVar2 = SysAllocStringLen(local_14[0],*(UINT *)(local_14[0] + -6));
      if (pOVar2 != (BSTR)0x0) {
        *param_5 = pOVar2;
        FUN_00406b10();
        return 0;
      }
                    /* WARNING: Subroutine does not return */
      FUN_00407010();
    }
    if (0 < param_3) {
      pcVar1 = *(code **)(*in_ECX + 0x254);
      guard_check_icall(param_3);
      (*pcVar1)();
      if (*(int *)(in_ECX[0x36] + -0xc) != 0) {
        uVar3 = FUN_007913e5();
        *param_5 = uVar3;
        return 0;
      }
    }
  }
  return 1;
}




/* vtable slots: CAutoHideDockSite[46], CBasePane[46], CBaseTabbedPane[46], CDockSite[46], CDockablePane[46], CDockablePaneAdapter[46], CDummyDockablePane[46], CMFCAutoHideBar[46], CMFCBaseToolBar[46], CMFCCaptionBar[46], CMFCColorBar[46], CMFCDropDownToolBar[46], CMFCImageEditorPaletteBar[46], CMFCMenuBar[46], CMFCOutlookBar[46], CMFCOutlookBarPane[46], CMFCOutlookBarPaneAdapter[46], CMFCOutlookBarToolBar[46], CMFCPopupMenuBar[46], CMFCPrintPreviewToolBar[46], CMFCRibbonPanelMenuBar[46], CMFCTasksPane[46], CMFCTasksPaneToolBar[46], CMFCToolBar[46], CPane[46], CPaneDivider[46], CTabbedPane[46] */
/* 007eecb8  FUN_007eecb8  114 bytes, 0 callers */

undefined4
FUN_007eecb8(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  code *pcVar1;
  BSTR pOVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if (param_1 == 3) {
    if (param_3 == 0) {
      pOVar2 = SysAllocString(L"ControlPane");
      *param_5 = pOVar2;
    }
    else {
LAB_007eece5:
      if (param_5 == (undefined4 *)0x0) goto LAB_007eed1f;
      pcVar1 = *(code **)(*in_ECX + 0x254);
      guard_check_icall(param_3);
      (*pcVar1)();
      if (*(int *)(in_ECX[0x38] + -0xc) == 0) {
        return 1;
      }
      uVar3 = FUN_007913e5();
      *param_5 = uVar3;
    }
    uVar3 = 0;
  }
  else {
    if (param_3 == 0) goto LAB_007eece5;
LAB_007eed1f:
    uVar3 = 0x80070057;
  }
  return uVar3;
}




/* vtable slots: CAutoHideDockSite[48], CBasePane[48], CBaseTabbedPane[48], CDockSite[48], CDockablePane[48], CDockablePaneAdapter[48], CDummyDockablePane[48], CMFCAutoHideBar[48], CMFCBaseToolBar[48], CMFCCaptionBar[48], CMFCColorBar[48], CMFCDropDownToolBar[48], CMFCImageEditorPaletteBar[48], CMFCMenuBar[48], CMFCOutlookBar[48], CMFCOutlookBarPane[48], CMFCOutlookBarPaneAdapter[48], CMFCOutlookBarToolBar[48], CMFCPopupMenuBar[48], CMFCPrintPreviewToolBar[48], CMFCRibbonPanelMenuBar[48], CMFCTasksPane[48], CMFCTasksPaneToolBar[48], CMFCToolBar[48], CPane[48], CPaneDivider[48], CTabbedPane[48] */
/* 007eed2a  FUN_007eed2a  132 bytes, 0 callers */

undefined4
FUN_007eed2a(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  code *pcVar1;
  BSTR pOVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if (param_1 == 3) {
    if (param_3 == 0) {
      pOVar2 = SysAllocString(L"");
      *param_5 = pOVar2;
      return 0;
    }
  }
  else if (param_3 != 0) {
    return 0x80070057;
  }
  if (param_5 != (undefined4 *)0x0) {
    if (param_1 == 3) {
      if (0 < param_3) {
        pcVar1 = *(code **)(*in_ECX + 0x254);
        guard_check_icall(param_3);
        (*pcVar1)();
        if (*(int *)(in_ECX[0x37] + -0xc) != 0) {
          uVar3 = FUN_007913e5();
          *param_5 = uVar3;
          return 0;
        }
      }
    }
    else if (param_3 != 0) {
      return 0x80070057;
    }
    return 1;
  }
  return 0x80070057;
}




/* vtable slots: CAutoHideDockSite[41], CBasePane[41], CBaseTabbedPane[41], CDockSite[41], CDockablePane[41], CDockablePaneAdapter[41], CDummyDockablePane[41], CMFCAutoHideBar[41], CMFCBaseToolBar[41], CMFCCaptionBar[41], CMFCColorBar[41], CMFCDropDownToolBar[41], CMFCImageEditorPaletteBar[41], CMFCMenuBar[41], CMFCOutlookBar[41], CMFCOutlookBarPane[41], CMFCOutlookBarPaneAdapter[41], CMFCOutlookBarToolBar[41], CMFCPopupMenuBar[41], CMFCPrintPreviewToolBar[41], CMFCRibbonPanelMenuBar[41], CMFCTasksPane[41], CMFCTasksPaneToolBar[41], CMFCToolBar[41], CPane[41], CPaneDivider[41], CTabbedPane[41] */
/* 007eedae  FUN_007eedae  155 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_007eedae(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  code *pcVar1;
  BSTR pOVar2;
  undefined4 uVar3;
  int *in_ECX;
  OLECHAR *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x7eedba;
  if (param_1 == 3) {
    if (param_3 == 0) {
      CStringT<>();
      local_8 = 0;
      FUN_00792c64(local_14);
      pOVar2 = SysAllocStringLen(local_14[0],*(UINT *)(local_14[0] + -6));
      if (pOVar2 == (BSTR)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_00407010();
      }
      *param_5 = pOVar2;
      FUN_00406b10();
    }
    else if (0 < param_3) {
      pcVar1 = *(code **)(*in_ECX + 0x254);
      guard_check_icall(param_3);
      (*pcVar1)();
      if (*(int *)(in_ECX[0x34] + -0xc) == 0) {
        return 1;
      }
      uVar3 = FUN_007913e5();
      *param_5 = uVar3;
    }
  }
  return 0;
}




/* vtable slots: CAutoHideDockSite[38], CBasePane[38], CBaseTabbedPane[38], CDockSite[38], CDockablePane[38], CDockablePaneAdapter[38], CDummyDockablePane[38], CMFCAutoHideBar[38], CMFCBaseToolBar[38], CMFCCaptionBar[38], CMFCColorBar[38], CMFCDropDownToolBar[38], CMFCImageEditorPaletteBar[38], CMFCMenuBar[38], CMFCOutlookBar[38], CMFCOutlookBarPane[38], CMFCOutlookBarPaneAdapter[38], CMFCOutlookBarToolBar[38], CMFCPopupMenuBar[38], CMFCPrintPreviewToolBar[38], CMFCRibbonPanelMenuBar[38], CMFCTasksPane[38], CMFCTasksPaneToolBar[38], CMFCToolBar[38], CPane[38], CPaneDivider[38], CTabbedPane[38] */
/* 007eee4a  get_accParent  67 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CBasePane::get_accParent(struct IDispatch * *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

long __thiscall CBasePane::get_accParent(CBasePane *this,IDispatch **param_1)

{
  HWND pHVar1;
  CWnd *pCVar2;
  uint uVar3;
  
  uVar3 = 0x80070057;
  if (param_1 != (IDispatch **)0x0) {
    pHVar1 = GetParent(*(HWND *)(this + 0x20));
    pCVar2 = CWnd::FromHandle(pHVar1);
    if (pCVar2 != (CWnd *)0x0) {
      AccessibleObjectFromWindow(*(HWND *)(pCVar2 + 0x20),0xfffffffc,(IID *)&DAT_009a9c2c,param_1);
      uVar3 = (uint)(*param_1 == (IDispatch *)0x0);
    }
  }
  return uVar3;
}




/* vtable slots: CAutoHideDockSite[44], CBasePane[44], CBaseTabbedPane[44], CDockSite[44], CDockablePane[44], CDockablePaneAdapter[44], CDummyDockablePane[44], CMFCAutoHideBar[44], CMFCBaseToolBar[44], CMFCCaptionBar[44], CMFCDropDownToolBar[44], CMFCImageEditorPaletteBar[44], CMFCMenuBar[44], CMFCOutlookBar[44], CMFCOutlookBarPane[44], CMFCOutlookBarPaneAdapter[44], CMFCOutlookBarToolBar[44], CMFCPrintPreviewToolBar[44], CMFCTasksPane[44], CMFCTasksPaneToolBar[44], CMFCToolBar[44], CPane[44], CPaneDivider[44], CTabbedPane[44] */
/* 007eee8d  FUN_007eee8d  103 bytes, 1 callers */

undefined4
FUN_007eee8d(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined2 *param_5)

{
  code *pcVar1;
  int *in_ECX;
  
  if (param_5 == (undefined2 *)0x0) {
    return 0x80070057;
  }
  if (param_1 == 3) {
    if (param_3 == 0) {
      *(undefined4 *)(param_5 + 4) = 10;
      goto LAB_007eeee9;
    }
    if (0 < param_3) {
      *param_5 = 3;
      pcVar1 = *(code **)(*in_ECX + 0x254);
      guard_check_icall(param_3);
      (*pcVar1)();
      *(int *)(param_5 + 4) = in_ECX[0x3a];
      return 0;
    }
  }
  *(undefined4 *)(param_5 + 4) = 0x2b;
LAB_007eeee9:
  *param_5 = 3;
  return 0;
}




/* vtable slots: CAutoHideDockSite[45], CBasePane[45], CBaseTabbedPane[45], CDockSite[45], CDockablePane[45], CDockablePaneAdapter[45], CDummyDockablePane[45], CMFCAutoHideBar[45], CMFCBaseToolBar[45], CMFCCaptionBar[45], CMFCDropDownToolBar[45], CMFCImageEditorPaletteBar[45], CMFCMenuBar[45], CMFCOutlookBar[45], CMFCOutlookBarPane[45], CMFCOutlookBarPaneAdapter[45], CMFCOutlookBarToolBar[45], CMFCPrintPreviewToolBar[45], CMFCTasksPane[45], CMFCTasksPaneToolBar[45], CMFCToolBar[45], CPane[45], CPaneDivider[45], CTabbedPane[45] */
/* 007eeef4  FUN_007eeef4  127 bytes, 1 callers */

undefined4
FUN_007eeef4(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined2 *param_5)

{
  code *pcVar1;
  CObject *pCVar2;
  CObject *in_ECX;
  
  if (param_5 == (undefined2 *)0x0) {
    return 0x80070057;
  }
  if (param_1 == 3) {
    if (param_3 == 0) {
      *param_5 = 3;
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,in_ECX);
      *(uint *)(param_5 + 4) = (-(uint)(pCVar2 != (CObject *)0x0) & 0xffffff00) + 0x100;
      return 0;
    }
    if (0 < param_3) {
      pcVar1 = *(code **)(*(int *)in_ECX + 0x254);
      guard_check_icall(param_3);
      (*pcVar1)();
      *param_5 = 3;
      *(undefined4 *)(param_5 + 4) = *(undefined4 *)(in_ECX + 0xec);
      return 0;
    }
  }
  return 1;
}




/* vtable slots: CAutoHideDockSite[42], CBasePane[42], CBaseTabbedPane[42], CDockSite[42], CDockablePane[42], CDockablePaneAdapter[42], CDummyDockablePane[42], CMFCAutoHideBar[42], CMFCBaseToolBar[42], CMFCCaptionBar[42], CMFCColorBar[42], CMFCDropDownToolBar[42], CMFCImageEditorPaletteBar[42], CMFCMenuBar[42], CMFCOutlookBar[42], CMFCOutlookBarPane[42], CMFCOutlookBarPaneAdapter[42], CMFCOutlookBarToolBar[42], CMFCPopupMenuBar[42], CMFCPrintPreviewToolBar[42], CMFCRibbonPanelMenuBar[42], CMFCTasksPane[42], CMFCTasksPaneToolBar[42], CMFCToolBar[42], CPane[42], CPaneDivider[42], CTabbedPane[42] */
/* 007eef73  FUN_007eef73  80 bytes, 0 callers */

undefined4
FUN_007eef73(short param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if ((param_1 == 3) && (0 < param_3)) {
    pcVar1 = *(code **)(*in_ECX + 0x254);
    guard_check_icall(param_3);
    (*pcVar1)();
    if (*(int *)(in_ECX[0x35] + -0xc) != 0) {
      uVar2 = FUN_007913e5();
      *param_5 = uVar2;
      return 0;
    }
  }
  return 1;
}




/* vtable slots: CAutoHideDockSite[171], CDockSite[171], CMDIFrameWndEx[119] */
/* 0084c625  FUN_0084c625  7 bytes, 0 callers */

undefined4 FUN_0084c625(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x148);
}




/* vtable slots: CAutoHideDockSite[170], CDockSite[170] */
/* 008605cf  FUN_008605cf  237 bytes, 0 callers */

void FUN_008605cf(void)

{
  HWND pHVar1;
  CWnd *pCVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  code *pcVar5;
  int iVar6;
  
  pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar2 = CWnd::FromHandle(pHVar1);
  iVar3 = FUN_0079d98a(&PTR_s_CFrameWndEx_00994040);
  if (iVar3 == 0) {
    iVar3 = FUN_0079d98a(&PTR_s_CMDIFrameWndEx_009945d0);
    if (iVar3 == 0) {
      iVar3 = FUN_0079d98a(&PTR_s_COleIPFrameWndEx_00994be0);
      if ((iVar3 == 0) && (iVar3 = FUN_0079d98a(&PTR_s_COleDocIPFrameWndEx_00994f98), iVar3 == 0)) {
        iVar3 = FUN_0079d98a(&PTR_s_COleCntrFrameWndEx_00996120);
        if (iVar3 == 0) {
          iVar3 = FUN_0079d98a(&PTR_s_CMDIChildWndEx_00995510);
          if (iVar3 == 0) {
            iVar3 = FUN_0079d98a(&PTR_s_CDialog_0097cf08);
            if (iVar3 == 0) {
              return;
            }
            iVar3 = 0;
            if (pCVar2 == (CWnd *)0x0) {
              iVar6 = 0;
            }
            else {
              iVar6 = *(int *)(pCVar2 + 0x20);
            }
            iVar4 = FUN_00404c80();
            if (iVar4 != 0) {
              iVar3 = *(int *)(iVar4 + 0x20);
            }
            if (iVar6 != iVar3) {
              return;
            }
            DAT_00a00960 = 1;
            return;
          }
          pcVar5 = *(code **)(*(int *)pCVar2 + 0x1cc);
        }
        else {
          pcVar5 = *(code **)(*(int *)pCVar2 + 0x1c4);
        }
      }
      else {
        pcVar5 = *(code **)(*(int *)pCVar2 + 0x1e4);
      }
    }
    else {
      pcVar5 = *(code **)(*(int *)pCVar2 + 0x1c8);
    }
  }
  else {
    pcVar5 = *(code **)(*(int *)pCVar2 + 0x1c0);
  }
  guard_check_icall(0);
  (*pcVar5)();
  return;
}




/* vtable slots: CAutoHideDockSite[131], CDockSite[131] */
/* 008606bc  FUN_008606bc  70 bytes, 0 callers */

void FUN_008606bc(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x114);
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pcVar1 = *(code **)(*(int *)*puVar2 + 0x20c);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CAutoHideDockSite[152], CDockSite[152] */
/* 00860702  FUN_00860702  244 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_00860702(int *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int *in_ECX;
  int local_34;
  int local_30;
  int local_28;
  int local_24;
  int local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall();
  local_24 = (*pcVar1)();
  local_20 = in_ECX[0x4c];
  while (local_20 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_20);
    local_1c = (int *)*puVar2;
    pcVar1 = *(code **)(*local_1c + 0x58);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      local_28 = local_1c[3];
      pcVar1 = *(code **)(*local_1c + 0x18);
      guard_check_icall(&local_34,param_2,param_3);
      (*pcVar1)();
      iVar3 = local_30;
      if (local_24 == 0) {
        iVar3 = local_34;
      }
      if ((iVar3 != local_28) && (0 < iVar3)) {
        FUN_00861bb1(local_1c,iVar3,0);
      }
    }
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect((HWND)in_ECX[8],&local_18);
  *param_1 = local_18.right - local_18.left;
  param_1[1] = local_18.bottom - local_18.top;
  return param_1;
}




/* vtable slots: CAutoHideDockSite[26], CDockSite[26] */
/* 008607f6  FUN_008607f6  9 bytes, 0 callers */

void FUN_008607f6(tagRECT *param_1,uint param_2)

{
  CWnd *in_ECX;
  
  CWnd::CalcWindowRect(in_ECX,param_1,param_2);
  return;
}




/* vtable slots: CAutoHideDockSite[173], CDockSite[173] */
/* 0086082f  FUN_0086082f  29 bytes, 0 callers */

void FUN_0086082f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0086084c(0,param_1,param_2,param_3,param_4,param_5);
  return;
}




/* vtable slots: CAutoHideDockSite[174], CDockSite[174] */
/* 0086084c  FUN_0086084c  366 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0086084c(undefined4 param_1,uint param_2,RECT *param_3,int param_4,int param_5,
                 undefined4 param_6)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int *in_ECX;
  undefined1 local_40 [4];
  undefined4 local_3c;
  int local_38;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x860858;
  local_38 = param_4;
  local_3c = param_6;
  pcVar1 = *(code **)(*in_ECX + 0x198);
  guard_check_icall();
  uVar3 = (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x1ec);
  guard_check_icall(uVar3 | param_2);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x1e0);
  guard_check_icall(param_2);
  (*pcVar1)();
  CopyRect(&local_34,param_3);
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  GetClientRect(*(HWND *)(local_38 + 0x20),&local_24);
  local_34.left = local_24.left;
  local_34.top = local_24.top;
  local_34.right = local_24.right;
  local_34.bottom = local_24.bottom;
  pcVar1 = *(code **)(*in_ECX + 0x194);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  iVar2 = local_38;
  if (iVar4 == 0x1000) {
    local_34.right = 0;
    in_ECX[0x52] = 0xe81c;
  }
  else if (iVar4 == 0x2000) {
    local_34.bottom = local_24.top;
    in_ECX[0x52] = 0xe81b;
  }
  else if (iVar4 == 0x4000) {
    local_34.left = local_24.right;
    in_ECX[0x52] = 0xe81d;
  }
  else if (iVar4 == 0x8000) {
    local_34.top = local_24.bottom;
    in_ECX[0x52] = 0xe81e;
  }
  iVar4 = in_ECX[0x52];
  in_ECX[0x28] = param_5;
  in_ECX[0x29] = local_38;
  FUN_007c2511();
  puVar5 = (undefined4 *)FUN_007e5eba(local_40,L"Afx:DockPane");
  local_8 = 0;
  FUN_007920d9(0,*puVar5,0,param_2 | 0x46000000,&local_34,iVar2,iVar4,local_3c);
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CAutoHideDockSite[156], CDockSite[156] */
/* 008609ea  FUN_008609ea  108 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_008609ea(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 in_ECX;
  int *piVar3;
  
  iVar2 = FUN_0078e624(0x48);
  piVar3 = (int *)0x0;
  if (iVar2 != 0) {
    piVar3 = (int *)FUN_00855f7d(in_ECX,param_2,param_3);
  }
  pcVar1 = *(code **)(*piVar3 + 0xc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*piVar3 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    piVar3 = (int *)0x0;
  }
  return piVar3;
}




/* vtable slots: CAutoHideDockSite[158], CDockSite[158] */
/* 00860e10  FUN_00860e10  409 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00860e10(int *param_1,int param_2)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  CWnd *in_ECX;
  LONG yTop;
  int *piVar5;
  int xLeft;
  tagRECT *ptVar6;
  undefined4 uVar7;
  int xRight;
  int local_38;
  int local_34;
  int local_30;
  int *local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_2c = param_1;
  local_30 = param_2;
  piVar2 = (int *)FUN_00861c90(param_2);
  uVar3 = 0;
  if (piVar2 != (int *)0x0) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(param_2 + 0x20),&local_18);
    CWnd::ScreenToClient(in_ECX,&local_18);
    pcVar1 = *(code **)(*(int *)in_ECX + 0x164);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    pcVar1 = *(code **)(*local_2c + 0x260);
    guard_check_icall(&local_38,0,iVar4 != 0);
    (*pcVar1)();
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    pcVar1 = *(code **)(*(int *)in_ECX + 0x164);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      iVar4 = local_18.top + -10;
      yTop = (local_18.top - local_34) + -10;
      xLeft = local_18.left;
      xRight = local_18.right;
    }
    else {
      xLeft = (local_18.left - local_38) + -10;
      yTop = local_18.top;
      xRight = local_18.left + -10;
      iVar4 = local_18.bottom;
    }
    SetRect(&local_28,xLeft,yTop,xRight,iVar4);
    pcVar1 = *(code **)(*local_2c + 0x29c);
    guard_check_icall();
    (*pcVar1)();
    FUN_0079e8b8(&local_28);
    iVar4 = *piVar2;
    ptVar6 = &local_28;
    uVar7 = 0;
    uVar3 = 4;
    piVar2[1] = 1;
    piVar5 = local_2c;
    guard_check_icall(local_2c,4,ptVar6,0);
    (**(code **)(iVar4 + 0x1c))();
    iVar4 = FUN_007a198a(local_30,0);
    if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    InsertBefore(iVar4,local_2c);
    pcVar1 = *(code **)(*(int *)in_ECX + 0x2a8);
    guard_check_icall(piVar5,uVar3,ptVar6,uVar7);
    (*pcVar1)();
    pcVar1 = *(code **)(*(int *)in_ECX + 0x29c);
    guard_check_icall();
    (*pcVar1)();
    piVar2[1] = 0;
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CAutoHideDockSite[167], CDockSite[167] */
/* 0086112e  FUN_0086112e  55 bytes, 0 callers */

void FUN_0086112e(void)

{
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x130);
  while (local_8 != 0) {
    FUN_0044f2d0(&local_8);
    FUN_008572d1(0,0);
  }
  return;
}




/* vtable slots: CAutoHideDockSite[155], CDockSite[155] */
/* 00861171  FUN_00861171  98 bytes, 0 callers */

undefined4 FUN_00861171(void)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0x114);
  do {
    do {
      if (local_8 == 0) {
        return 0;
      }
      pCVar2 = (CObject *)FUN_0049acb0(&local_8);
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,pCVar2);
    } while (pCVar2 == (CObject *)0x0);
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x26c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
  } while (iVar3 == 0);
  return 1;
}




/* vtable slots: CAutoHideDockSite[160], CDockSite[160] */
/* 008611d3  FUN_008611d3  808 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008611d3(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  CDockingPanesRow *this;
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  CDockingPanesRow *pCVar6;
  CDockingPanesRow *pCVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  tagPOINT local_44;
  undefined4 local_3c;
  int *local_38;
  undefined1 local_31;
  int *local_30;
  CDockingPanesRow *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  this = (CDockingPanesRow *)param_1[0x2f];
  local_18.right = 0;
  local_18.bottom = 0;
  local_30 = param_1;
  local_38 = in_ECX;
  FUN_007f028e(&local_18);
  OffsetRect(&local_18,param_3,param_4);
  local_44.x = 0;
  local_44.y = 0;
  GetCursorPos(&local_44);
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  CDockingPanesRow::GetWindowRect(this,(CRect *)&local_28);
  local_3c = 0;
  pcVar1 = *(code **)(*param_1 + 0x2b4);
  puVar9 = &local_3c;
  uVar8 = 0xf;
  guard_check_icall(0xf,puVar9);
  iVar2 = (*pcVar1)();
  piVar5 = local_30;
  if (iVar2 != 0) {
    FUN_007f225e(param_3,param_4);
    FUN_007f028e(&local_18);
    pcVar1 = *(code **)(*piVar5 + 0x1fc);
    guard_check_icall(local_18.left,local_18.top,local_18.right,local_18.bottom,1,1);
    (*pcVar1)();
    return 1;
  }
  local_31 = 0;
  local_2c = (CDockingPanesRow *)
             FUN_00861cd8((local_18.left + local_18.right) / 2,(local_18.top + local_18.bottom) / 2,
                          &local_31);
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall(uVar8,puVar9);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    iVar2 = local_20 - local_18.right;
    if (local_28 - local_18.left <= local_20 - local_18.right) {
      iVar2 = local_28 - local_18.left;
    }
    iVar3 = local_18.right - local_18.left;
  }
  else {
    iVar2 = local_1c - local_18.bottom;
    if (local_24 - local_18.top <= local_1c - local_18.bottom) {
      iVar2 = local_24 - local_18.top;
    }
    iVar3 = local_18.bottom - local_18.top;
  }
  iVar4 = _abs(iVar2);
  if (iVar4 <= (iVar3 * 2) / 3) {
LAB_008614a7:
    iVar3 = local_1c - local_24;
    iVar2 = _abs(iVar2);
    if (iVar3 <= iVar2) {
      return 0;
    }
    local_38 = BeginDeferWindowPos(*(int *)(this + 0x30));
    FUN_00857d3e(local_30,param_3,param_4,1,&local_38);
    EndDeferWindowPos(local_38);
    return 0;
  }
  if ((1 < *(int *)(this + 0x30)) && (iVar2 < *(int *)(this + 0xc))) {
    local_2c = (CDockingPanesRow *)FUN_007a198a(this,0);
    if (local_2c != (CDockingPanesRow *)0x0) {
      if (iVar2 < 0) {
        FUN_00860faa(&local_2c,1);
      }
      pcVar1 = *(code **)(*(int *)this + 0x24);
      guard_check_icall(local_30);
      (*pcVar1)();
      pcVar1 = *(code **)(*local_38 + 0x164);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        iVar2 = local_18.right - local_18.left;
      }
      else {
        iVar2 = local_18.bottom - local_18.top;
      }
      piVar5 = (int *)FUN_00860505(local_2c,iVar2);
      pcVar1 = *(code **)(*piVar5 + 0x20);
      guard_check_icall(local_30,1);
      (*pcVar1)();
      return 0;
    }
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((this == local_2c) || (local_2c == (CDockingPanesRow *)0x0)) goto LAB_008614a7;
  SendMessageW((HWND)local_38[8],0xb,0,0);
  pcVar1 = *(code **)(*(int *)this + 0x60);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  pCVar6 = local_2c;
  pCVar7 = this;
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*(int *)local_2c + 0x60);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    pCVar6 = this;
    pCVar7 = local_2c;
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*(int *)this + 0x24);
      guard_check_icall(local_30);
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)local_2c + 0x20);
      guard_check_icall(local_30,1);
      (*pcVar1)();
      goto LAB_0086147b;
    }
  }
  FUN_00861e6b(pCVar6,pCVar7);
LAB_0086147b:
  *(undefined1 *)(local_30 + 0x44) = 1;
  SendMessageW((HWND)local_38[8],0xb,1,0);
  RedrawWindow((HWND)local_38[8],(RECT *)0x0,(HRGN)0x0,0x185);
  return 0;
}




/* vtable slots: CAutoHideDockSite[161], CDockSite[161] */
/* 008615fe  FUN_008615fe  96 bytes, 0 callers */

void FUN_008615fe(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  if (param_1 != 0) {
    piVar3 = (int *)FUN_0044f2d0(&param_1);
    uVar1 = *(undefined4 *)(*piVar3 + 0xc);
    while (param_1 != 0) {
      puVar4 = (undefined4 *)FUN_0044f2d0(&param_1);
      pcVar2 = *(code **)(*(int *)*puVar4 + 0x38);
      guard_check_icall(uVar1);
      (*pcVar2)();
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CAutoHideDockSite[162], CDockSite[162] */
/* 008616af  FUN_008616af  124 bytes, 0 callers */

void FUN_008616af(int param_1,int param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1 != 0) {
    piVar2 = (int *)FUN_0044f2d0(&param_1);
    piVar2 = (int *)*piVar2;
    pcVar1 = *(code **)(*piVar2 + 0x58);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (((iVar3 != 0) || (param_2 != 0)) && (iVar3 = piVar2[3], param_1 != 0)) {
      do {
        puVar4 = (undefined4 *)FUN_0044f2d0(&param_1);
        pcVar1 = *(code **)(*(int *)*puVar4 + 0x38);
        guard_check_icall(-iVar3);
        (*pcVar1)();
      } while (param_1 != 0);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CAutoHideDockSite[163], CDockSite[163] */
/* 0086172c  FUN_0086172c  138 bytes, 0 callers */

undefined4 FUN_0086172c(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int local_8;
  
  pcVar1 = *(code **)(*param_1 + 0x34);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  pcVar1 = *(code **)(*param_1 + 0x58);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  uVar5 = 0;
  if (iVar3 != 0) {
    local_8 = FUN_007a198a(param_1,0);
    FUN_0044f2d0(&local_8);
    while (uVar5 = uVar2, local_8 != 0) {
      puVar4 = (undefined4 *)FUN_0044f2d0(&local_8);
      pcVar1 = *(code **)(*(int *)*puVar4 + 0x38);
      guard_check_icall(uVar2);
      (*pcVar1)();
    }
  }
  return uVar5;
}




/* vtable slots: CAutoHideDockSite[172], CDockSite[172] */
/* 008617b6  FUN_008617b6  80 bytes, 0 callers */

bool FUN_008617b6(undefined4 param_1,int *param_2,uint param_3)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x238);
  guard_check_icall(param_1,*param_2,param_2[1],param_2[2] - *param_2,param_2[3] - param_2[1],
                    param_3 | 0x10,0);
  iVar2 = (*pcVar1)();
  return iVar2 != 0;
}




/* vtable slots: CAutoHideDockSite[164], CDockSite[164] */
/* 00861806  FUN_00861806  75 bytes, 0 callers */

void FUN_00861806(int param_1,int param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  if (param_1 != 0) {
    if (param_2 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x288);
      guard_check_icall(param_1,1);
      (*pcVar1)();
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x284);
      guard_check_icall(param_1);
      (*pcVar1)();
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CAutoHideDockSite[165], CDockSite[165], CSmartDockingGroupGuide[6] */
/* 00861852  FUN_00861852  3 bytes, 0 callers */

void FUN_00861852(void)

{
  return;
}




/* vtable slots: CAutoHideDockSite[169], CDockSite[169] */
/* 00861855  FUN_00861855  124 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_00861855(LONG param_1,LONG param_2)

{
  int iVar1;
  POINT pt;
  int *piVar2;
  BOOL BVar3;
  int in_ECX;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  local_1c = *(int *)(in_ECX + 0x114);
  do {
    if (local_1c == 0) {
      return 0;
    }
    piVar2 = (int *)FUN_0044f2d0(&local_1c);
    iVar1 = *piVar2;
    GetWindowRect(*(HWND *)(iVar1 + 0x20),&local_18);
    pt.y = param_2;
    pt.x = param_1;
    BVar3 = PtInRect(&local_18,pt);
  } while (BVar3 == 0);
  return iVar1;
}




/* vtable slots: CAutoHideDockSite[159], CDockSite[159] */
/* 008618d1  FUN_008618d1  79 bytes, 0 callers */

void FUN_008618d1(int param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x11c) != 0) && (iVar2 = FUN_007a198a(param_1,0), iVar2 != 0)) {
    FUN_007a1ad4(iVar2);
    if (*(int **)(param_1 + 0xbc) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(param_1 + 0xbc) + 0x24);
      guard_check_icall(param_1);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CAutoHideDockSite[168], CDockSite[168] */
/* 00861dd5  FUN_00861dd5  72 bytes, 0 callers */

undefined4 FUN_00861dd5(CObject *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int *piVar2;
  CObject *pCVar3;
  undefined4 uVar4;
  
  piVar2 = (int *)FUN_00861c90(param_1);
  if ((piVar2 != (int *)0x0) &&
     (pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,param_1),
     pCVar3 != (CObject *)0x0)) {
    pcVar1 = *(code **)(*piVar2 + 0x50);
    guard_check_icall(pCVar3,param_2,param_3);
    uVar4 = (*pcVar1)();
    return uVar4;
  }
  return 0;
}




/* vtable slots: CAutoHideDockSite[1] */
/* 008c18a1  FUN_008c18a1  57 bytes, 0 callers */

void FUN_008c18a1(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CAutoHideDockSite::vftable;
  FUN_00860448();
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




/* vtable slots: CAutoHideDockSite[97] */
/* 008c18da  FUN_008c18da  20 bytes, 0 callers */

void FUN_008c18da(void)

{
  FUN_0079d98a(&PTR_s_CMFCAutoHideBar_009a2344);
  return;
}




/* vtable slots: CAutoHideDockSite[157] */
/* 008c191e  FUN_008c191e  385 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c191e(CObject *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *in_ECX;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int local_28;
  int local_24;
  undefined4 local_20;
  CObject *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = param_1;
  local_20 = param_3;
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  piVar6 = &local_28;
  uVar4 = (uint)(iVar2 != 0);
  pcVar1 = *(code **)(*(int *)local_1c + 0x260);
  uVar7 = 0;
  guard_check_icall(piVar6,0,uVar4);
  (*pcVar1)();
  if (iVar2 == 0) {
    local_24 = local_28;
  }
  iVar5 = DAT_00a00cc8 + local_24;
  iVar2 = FUN_007a198a(local_1c,0);
  if (iVar2 != 0) {
    return;
  }
  if (in_ECX[0x4e] != 0) {
    piVar3 = *(int **)(in_ECX[0x4c] + 8);
    goto LAB_008c1a14;
  }
  piVar3 = (int *)FUN_00860505(0,iVar5);
  pcVar1 = *(code **)(*in_ECX + 0x194);
  guard_check_icall(piVar6,uVar7,uVar4);
  uVar4 = (*pcVar1)();
  if ((uVar4 & 0x1000) == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x194);
    guard_check_icall();
    uVar4 = (*pcVar1)();
    if ((uVar4 & 0x2000) != 0) goto LAB_008c19fc;
    piVar3[7] = DAT_00a00cc8;
    iVar2 = 1;
  }
  else {
LAB_008c19fc:
    piVar3[7] = DAT_00a00cc8;
    iVar2 = 0;
  }
  piVar3[8] = iVar2;
LAB_008c1a14:
  pcVar1 = *(code **)(*piVar3 + 0x1c);
  guard_check_icall(local_1c,4,local_20,1);
  (*pcVar1)();
  FUN_00797f20(5);
  CObList::AddTail((CObList *)(in_ECX + 0x44),local_1c);
  pcVar1 = *(code **)(*in_ECX + 0x2a8);
  guard_check_icall();
  (*pcVar1)();
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect((HWND)in_ECX[8],&local_18);
  pcVar1 = *(code **)(*in_ECX + 0x298);
  guard_check_icall(&local_18);
  (*pcVar1)();
  return;
}




/* vtable slots: CAutoHideDockSite[10] */
/* 008c1a9f  FUN_008c1a9f  6 bytes, 0 callers */

undefined ** FUN_008c1a9f(void)

{
  return &PTR_FUN_009a31b4;
}




/* vtable slots: CAutoHideDockSite[0] */
/* 008c1aa5  FUN_008c1aa5  6 bytes, 0 callers */

undefined ** FUN_008c1aa5(void)

{
  return &PTR_s_CAutoHideDockSite_009a2e90;
}




/* vtable slots: CAutoHideDockSite[166] */
/* 008c1aab  FUN_008c1aab  127 bytes, 0 callers */

void FUN_008c1aab(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x138) != 0) {
    pcVar1 = *(code **)(**(int **)(*(int *)(in_ECX + 0x130) + 8) + 0x2c);
    iVar3 = FUN_007c2511();
    uVar2 = *(undefined4 *)(iVar3 + 0x1b8);
    iVar3 = FUN_007c2511();
    guard_check_icall(*(int *)(in_ECX + 0x150) + *(int *)(iVar3 + 0x1bc),uVar2);
    (*pcVar1)();
    piVar4 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar4 + 0x1ac);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      FUN_008582ac();
    }
  }
  return;
}



