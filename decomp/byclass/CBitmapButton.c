/* CBitmapButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CBitmapButton[1] */
/* 0041b3f0  FUN_0041b3f0  68 bytes, 0 callers */

undefined4 FUN_0041b3f0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041b380();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa0);
    }
  }
  return in_ECX;
}




/* vtable slots: CBitmapButton[10], CButton[10], CComboBox[10], CEdit[10], CHeaderCtrl[10], CListBox[10], CMyButton[10], CProgressCtrl[10], CRichEditCtrl[10], CScrollBar[10], CSpinButtonCtrl[10], CStatic[10], CWnd[10] */
/* 00792932  FUN_00792932  6 bytes, 0 callers */

undefined ** FUN_00792932(void)

{
  return &PTR_FUN_0097ce00;
}




/* vtable slots: CBitmapButton[67], CButton[67], CCheckListBox[67], CColorButton[67], CColorButton2[67], CComboBox[67], CEdit[67], CHeaderCtrl[67], CJw_winView[67], CKijunTenButton[67], CLayerButton[67], CLayerControlButton[67], CListBox[67], CListCtrl[67], CMDIClientAreaWnd[67], CMDITabProxyWnd[67], CMFCColorPickerCtrl[67], CMFCHeaderCtrl[67], CMFCImagePaintArea[67], CMFCListCtrl[67], CMFCMaskedEdit[67], CMFCRibbonKeyTip[67], CMFCRibbonSpinButtonCtrl[67], CMFCShellListCtrl[67], CMFCShellTreeCtrl[67], CMFCSpinButtonCtrl[67], CMFCToolBarButtonsListButton[67], CMFCToolBarsCommandsListBox[67], CMFCToolBarsListCheckBox[67], CMFCToolTipCtrl[67], CMy3Button[67], CMyBWnd[67], CMyButton[67], CMyTree2Ctrl[67], CMyTreeCtrl[67], CPaneTrackingWnd[67], CPreviewView[67], CPreviewViewEx[67], CProgressCtrl[67], CRichEditCtrl[67], CScreenWnd[67], CScrollBar[67], CScrollView[67], CSenshuButton[67], CSmartDockingGroupGuidesWnd[67], CSmartDockingHighlighterWnd[67], CSmartDockingStandaloneGuideWnd[67], CSpinButtonCtrl[67], CStatic[67], CTabCtrl[67], CToolTipCtrl[67], CTreeCtrl[67], CVSListBoxBase[67], CWnd[67], _AFX_MOUSEANCHORWND[67] */
/* 007949fb  FUN_007949fb  41 bytes, 26 callers */

undefined4 FUN_007949fb(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  
  iVar2 = FUN_0079dd6d();
  pcVar1 = *(code **)(iVar2 + 0x38);
  if (pcVar1 != (code *)0x0) {
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return 0;
}




/* vtable slots: CBitmapButton[89], CButton[89], CColorButton[89], CColorButton2[89], CKijunTenButton[89], CLayerButton[89], CLayerControlButton[89], CMFCButton[89], CMFCColorButton[89], CMFCColorPickerCtrl[89], CMFCImagePaintArea[89], CMFCLinkCtrl[89], CMFCMenuButton[89], CMFCOutlookBarScrollButton[89], CMFCTabButton[89], CMFCToolBarButtonsListButton[89], CMy3Button[89], CMyButton[89], CSenshuButton[89] */
/* 00798ee6  FUN_00798ee6  52 bytes, 0 callers */

void FUN_00798ee6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall(L"BUTTON",param_1,param_2,param_3,param_4,param_5,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CBitmapButton[73], CButton[73], CColorButton[73], CColorButton2[73], CKijunTenButton[73], CLayerButton[73], CLayerControlButton[73], CMFCButton[73], CMFCColorButton[73], CMFCColorPickerCtrl[73], CMFCImagePaintArea[73], CMFCLinkCtrl[73], CMFCMenuButton[73], CMFCOutlookBarScrollButton[73], CMFCTabButton[73], CMFCToolBarButtonsListButton[73], CMy3Button[73], CMyButton[73], CSenshuButton[73], CStatic[73], CVSListBox[73], CVSListBoxBase[73], CVSToolsListBox[73] */
/* 007990c4  FUN_007990c4  64 bytes, 0 callers */

int FUN_007990c4(uint param_1,uint param_2,long param_3,long *param_4)

{
  code *pcVar1;
  int iVar2;
  CWnd *in_ECX;
  
  if (param_1 == 0x2b) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x168);
    guard_check_icall(param_3);
    (*pcVar1)();
    iVar2 = 1;
  }
  else {
    iVar2 = CWnd::OnChildNotify(in_ECX,param_1,param_2,param_3,param_4);
  }
  return iVar2;
}




/* vtable slots: CBitmapButton[90] */
/* 007a5438  DrawItem  258 bytes, 5 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    protected: virtual void __thiscall CBitmapButton::DrawItem(struct tagDRAWITEMSTRUCT *)
   
   Library: Visual Studio 2015 Release */

void __thiscall CBitmapButton::DrawItem(CBitmapButton *this,tagDRAWITEMSTRUCT *param_1)

{
  CDC *pCVar1;
  HDC pHVar2;
  void *pvVar3;
  CGdiObject *pCVar4;
  CBitmapButton *pCVar5;
  CDC local_34 [4];
  HDC__ *local_30;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x7a5444;
  pCVar5 = this + 0x80;
  if ((((byte)param_1[0x10] & 1) == 0) || (*(int *)(this + 0x8c) == 0)) {
    if ((((byte)param_1[0x10] & 0x10) == 0) || (*(int *)(this + 0x94) == 0)) {
      if ((((byte)param_1[0x10] & 4) != 0) && (*(int *)(this + 0x9c) != 0)) {
        pCVar5 = this + 0x98;
      }
    }
    else {
      pCVar5 = this + 0x90;
    }
  }
  else {
    pCVar5 = this + 0x88;
  }
  pCVar1 = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  CDC::CDC(local_34);
  local_8 = 0;
  if (pCVar1 == (CDC *)0x0) {
    pHVar2 = (HDC)0x0;
  }
  else {
    pHVar2 = *(HDC *)(pCVar1 + 4);
  }
  pHVar2 = CreateCompatibleDC(pHVar2);
  FUN_0079e84a(pHVar2);
  if (pCVar5 == (CBitmapButton *)0x0) {
    pvVar3 = (void *)0x0;
  }
  else {
    pvVar3 = *(void **)(pCVar5 + 4);
  }
  pCVar4 = CDC::SelectGdiObject(local_30,pvVar3);
  if (pCVar4 != (CGdiObject *)0x0) {
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    CopyRect(&local_24,(RECT *)(param_1 + 0x1c));
    BitBlt(*(HDC *)(pCVar1 + 4),local_24.left,local_24.top,local_24.right - local_24.left,
           local_24.bottom - local_24.top,local_30,0,0,0xcc0020);
    CDC::SelectGdiObject(local_30,*(void **)(pCVar4 + 4));
  }
  FUN_0079e053();
  FUN_008d9b68();
  return;
}




/* vtable slots: CBitmapButton[0], CColorButton[0], CColorButton2[0], CLayerButton[0], CLayerControlButton[0], CSenshuButton[0] */
/* 007a553a  FUN_007a553a  6 bytes, 0 callers */

undefined ** FUN_007a553a(void)

{
  return &PTR_s_CBitmapButton_0097f2f8;
}



