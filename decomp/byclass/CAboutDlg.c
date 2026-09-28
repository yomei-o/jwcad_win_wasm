/* CAboutDlg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CAboutDlg[64], CDummyDialog[64], CMsgDialog[64], CZukeiObject[6] */
/* 0049c090  DoDataExchange  25 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CFindReplaceDialog::DoDataExchange(class CDataExchange *)
   
   Library: Visual Studio 2008 Debug */

void __thiscall CFindReplaceDialog::DoDataExchange(CFindReplaceDialog *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  return;
}




/* vtable slots: CAboutDlg[1] */
/* 004daf90  FUN_004daf90  68 bytes, 0 callers */

undefined4 FUN_004daf90(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004da360();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa8);
    }
  }
  return in_ECX;
}




/* vtable slots: CAboutDlg[10] */
/* 004de200  FUN_004de200  16 bytes, 0 callers */

void FUN_004de200(void)

{
  FUN_004de220();
  return;
}




/* vtable slots: CAboutDlg[97], CBlockSelNameDialog[97], CBlockTreeDialog[97], CDialog[97], CDialogEx[97], CDragDialog[97], CDxfProgDlg[97], CEditDialog[97], CFukushaZokuseiHenDialog[97], CGamenBairitsuDialog[97], CHikageJikanDialog[97], CIkkatstHenkanDialog[97], CKjiJunTenDialog[97], CLayerDialog[97], CMFCColorDialog[97], CMFCImageEditorDialog[97], CMFCToolBarButtonCustomizeDialog[97], CMFCToolBarNameDialog[97], CMojiKensakuNameDialog[97], CMojiSeiriDialog[97], CMojiSelDialog[97], CMojiSizeDialog[97], CMsgDialog[97], CNamaeHenkouDlg[97], CNewFileDlg[97], CNewTypeDlg[97], COutlookOptionsDlg[97], CPrintBairitsuDlg[97], CPrintKeishikiDialog[97], CProtectLayPassWordDialog[97], CScaleDialog[97], CSenshuDialog[97], CSenshuDialog2[97], CSunpoSetteiDialg[97], CSuuchiHyouDialog[97], CTateguKijuntenDialog[97], CToolBarDialog[97], CToukaritsDialog[97], CToukashokuDialog[97], CUserDefinedLTypeDialog[97], CUserTBDialog[97], CZaFileSetteiDialog[97], CZokuseiSelHenkouDialog[97] */
/* 00798826  FUN_00798826  8 bytes, 12 callers */

void FUN_00798826(void)

{
  FUN_007986de(2);
  return;
}




/* vtable slots: CAboutDlg[94], CAutoDialog[94], CAutoPage[94], CColorDialog[94], CCommonDialog[94], CDialog[94], CDialogEx[94], CDummyDialog[94], CDxfProgDlg[94], CEditDialog[94], CFileDialog[94], CGaibuDialog[94], CIkkatstHenkanDialog[94], CKageDialog[94], CKeyPage[94], CMojiPage[94], CMsgDialog[94], CMyColorDialog[94], CMyDialog[94], COleBusyDialog[94], CPrintDialog[94], CPropertyPage[94], CSenKigouDialog[94], CSonotaPage[94], CTenkuuZuDialog[94], CToolBarDialog[94], CToukashokuDialog[94], CTourokuZuDialog[94], CUserTBDialog[94], CZaFileSetteiDialog[94] */
/* 00798993  FUN_00798993  118 bytes, 79 callers */

undefined4 FUN_00798993(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x90) == 0) {
    iVar1 = FUN_00792670(*(undefined4 *)(in_ECX + 0x84));
  }
  else {
    iVar1 = FUN_0078fc5a(*(int *)(in_ECX + 0x90));
  }
  if (iVar1 != 0) {
    FUN_007930d4(*(undefined4 *)(in_ECX + 0x84));
    iVar1 = FUN_007955d2(0);
    if (iVar1 != 0) {
      iVar1 = FUN_00797a56(0xe146);
      if (iVar1 != 0) {
        iVar1 = FUN_007980a3();
        FUN_00797f20(-(iVar1 != 0) & 5);
      }
      return 1;
    }
  }
  FUN_007986de(0xffffffff);
  return 0;
}




/* vtable slots: CAboutDlg[67], CBlkkDlg[67], CBlockEditDialog[67], CBlockSelNameDialog[67], CBlockTreeDialog[67], CColorDialog[67], CCommonDialog[67], CDialog[67], CDragDialog[67], CDxfProgDlg[67], CEditDialog[67], CFileDialog[67], CFukushaZokuseiHenDialog[67], CGamenBairitsuDialog[67], CHikageJikanDialog[67], CIkkatstHenkanDialog[67], CJikukakuDialog[67], CLayerDialog[67], CMFCToolBarButtonCustomizeDialog[67], CMFCToolBarNameDialog[67], CMojiKensakuNameDialog[67], CMojiSeiriDialog[67], CMojiSelDialog[67], CMojiSizeDialog[67], CMsgDialog[67], CMyColorDialog[67], CNamaeHenkouDlg[67], CNewFileDlg[67], CNewTypeDlg[67], COleBusyDialog[67], COutlookOptionsDlg[67], CPrintBairitsuDlg[67], CPrintDialog[67], CPrintKeishikiDialog[67], CPrintingDialog[67], CPrtFileDlg[67], CPrtFileWnd[67], CScaleDialog[67], CSenshuDialog2[67], CSunpoSetteiDialg[67], CSuuchiHyouDialog[67], CTateguKijuntenDialog[67], CToolBarDialog[67], CToukaritsDialog[67], CToukashokuDialog[67], CUserDefinedLTypeDialog[67], CUserTBDialog[67], CZaFileSetteiDialog[67], CZokuseiSelHenkouDialog[67] */
/* 00798b50  PreTranslateMessage  166 bytes, 11 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CDialog::PreTranslateMessage(struct tagMSG *)
   
   Library: Visual Studio 2015 Release */

int __thiscall CDialog::PreTranslateMessage(CDialog *this,tagMSG *param_1)

{
  int iVar1;
  uint uVar2;
  HWND hWnd;
  BOOL BVar3;
  
  iVar1 = FUN_007949fb(param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_00792b4c();
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x94) != 0)) {
      return 0;
    }
    if ((((param_1->message != 0x100) ||
         (((param_1->wParam != 0x1b && (param_1->wParam != 3)) ||
          (uVar2 = GetWindowLongW(param_1->hwnd,-0x10), (uVar2 & 4) == 0)))) ||
        (iVar1 = FUN_007c1890(param_1->hwnd,L"Edit"), iVar1 == 0)) ||
       ((hWnd = GetDlgItem(*(HWND *)(this + 0x20),2), hWnd != (HWND)0x0 &&
        (BVar3 = IsWindowEnabled(hWnd), BVar3 == 0)))) {
      iVar1 = FUN_007949cc(param_1);
      return iVar1;
    }
    SendMessageW(*(HWND *)(this + 0x20),0x111,2,0);
  }
  return 1;
}



