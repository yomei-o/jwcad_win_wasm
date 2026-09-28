/* CMFCColorDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCColorDialog[1] */
/* 0089f6d3  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCColorDialog::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCColorDialog::_scalar_deleting_destructor_(CMFCColorDialog *this,uint param_1)

{
  FUN_0089f663();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x9f0);
    }
  }
  return this;
}




/* vtable slots: CMFCColorDialog[64] */
/* 0089f7f1  DoDataExchange  71 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual void __thiscall CMFCColorDialog::DoDataExchange(class CDataExchange *)
    protected: virtual void __thiscall CMFCToolBarsCommandsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void DoDataExchange(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0078fb9c(param_1,0x4295,in_ECX + 0xf8);
  FUN_0078fb9c(param_1,0x424a,in_ECX + 0x8a0);
  FUN_0078fb9c(param_1,0x4116,in_ECX + 0x920);
  return;
}




/* vtable slots: CMFCColorDialog[10] */
/* 0089f838  FUN_0089f838  6 bytes, 0 callers */

undefined ** FUN_0089f838(void)

{
  return &PTR_FUN_0099ed48;
}




/* vtable slots: CMFCColorDialog[94] */
/* 0089fa36  FUN_0089fa36  888 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0089fa36(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  CMFCCustomColorsPropertyPage *pCVar4;
  undefined4 uVar5;
  HCURSOR pHVar6;
  CWnd *in_ECX;
  undefined **local_128 [45];
  undefined4 local_74;
  CMFCCustomColorsPropertyPage *local_58;
  tagRECT local_54;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x118;
  local_8 = 0x89fa45;
  FUN_00798993();
  iVar2 = FUN_00404c80();
  if (iVar2 != 0) {
    FUN_00404c80();
    uVar3 = FUN_00797acc();
    if ((uVar3 & 0x400000) != 0) {
      FUN_00797c9f(0,0x400000,0);
    }
  }
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0x1ac) < 8) {
    CColorDialog::CColorDialog
              ((CColorDialog *)local_128,*(ulong *)(in_ECX + 0xe0),0x102,(CWnd *)0x0);
    local_8 = 0;
    iVar2 = CColorDialog::DoModal((CColorDialog *)local_128);
    *(undefined4 *)(in_ECX + 0xe4) = local_74;
    FUN_007986de(iVar2);
    local_128[0] = CCommonDialog::vftable;
    FUN_00797fb6();
  }
  else {
    if (*(int *)(in_ECX + 0xdc) == 0) {
      local_58 = (CMFCCustomColorsPropertyPage *)FUN_0078e624(8);
      if (local_58 == (CMFCCustomColorsPropertyPage *)0x0) {
        pCVar4 = (CMFCCustomColorsPropertyPage *)0x0;
      }
      else {
        *(undefined4 *)(local_58 + 4) = 0;
        *(undefined ***)local_58 = CPalette::vftable;
        pCVar4 = local_58;
      }
      *(CMFCCustomColorsPropertyPage **)(in_ECX + 0xdc) = pCVar4;
      FUN_008a00e5();
    }
    FUN_007ad46d(0);
    CMFCColorPickerCtrl::SetPalette
              ((CMFCColorPickerCtrl *)(in_ECX + 0x920),*(CPalette **)(in_ECX + 0xdc));
    FUN_00864b29(*(undefined4 *)(in_ECX + 0xe0));
    CMFCColorPickerCtrl::SetColor((CMFCColorPickerCtrl *)(in_ECX + 0x920),*(ulong *)(in_ECX + 0xe4))
    ;
    local_58 = (CMFCCustomColorsPropertyPage *)FUN_0078e624(0xe8);
    local_8 = 1;
    if (local_58 == (CMFCCustomColorsPropertyPage *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_008d1ed4(&DAT_00956338,in_ECX,0);
    }
    local_8 = 0xffffffff;
    *(int *)(in_ECX + 0xd0) = iVar2;
    if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    local_58 = (CMFCCustomColorsPropertyPage *)FUN_0078e624(0x270);
    local_8 = 2;
    if (local_58 == (CMFCCustomColorsPropertyPage *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = CMFCStandardColorsPropertyPage::CMFCStandardColorsPropertyPage
                        ((CMFCStandardColorsPropertyPage *)local_58);
    }
    local_8 = 0xffffffff;
    *(undefined4 *)(in_ECX + 0xd4) = uVar5;
    local_58 = (CMFCCustomColorsPropertyPage *)FUN_0078e624(0x288);
    local_8 = 3;
    if (local_58 == (CMFCCustomColorsPropertyPage *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = CMFCCustomColorsPropertyPage::CMFCCustomColorsPropertyPage(local_58);
    }
    local_8 = 0xffffffff;
    *(undefined4 *)(in_ECX + 0xd8) = uVar5;
    *(CWnd **)(*(int *)(in_ECX + 0xd4) + 0xc0) = in_ECX;
    *(CWnd **)(*(int *)(in_ECX + 0xd8) + 0xc0) = in_ECX;
    FUN_0079fdd3(*(undefined4 *)(in_ECX + 0xd4));
    FUN_0079fdd3(*(undefined4 *)(in_ECX + 0xd8));
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetWindowRect(*(HWND *)(in_ECX + 0x8c0),&local_24);
    CWnd::ScreenToClient(in_ECX,&local_24);
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xd0) + 0x164);
    guard_check_icall();
    (*pcVar1)();
    CPropertySheet::SetActivePage(*(CPropertySheet **)(in_ECX + 0xd0),0);
    local_54.left = 0;
    local_54.top = 0;
    local_54.right = 0;
    local_54.bottom = 0;
    GetWindowRect(*(HWND *)(*(int *)(in_ECX + 0xd0) + 0x20),&local_54);
    FUN_00797e71(0,local_24.left,local_24.top,local_24.right - local_24.left,
                 local_24.bottom - local_24.top,0x14);
    CMFCColorDialog::SetPageOne
              ((CMFCColorDialog *)in_ECX,(uchar)in_ECX[0xe0],(uchar)in_ECX[0xe1],(uchar)in_ECX[0xe2]
              );
    FUN_008d1dea(in_ECX[0xe0],in_ECX[0xe1],in_ECX[0xe2]);
    CMFCButton::SetImage((CMFCButton *)(in_ECX + 0xf8),0x4296,0,0);
    local_44.left = 0;
    local_44.top = 0;
    local_44.right = 0;
    local_44.bottom = 0;
    GetWindowRect(*(HWND *)(*(int *)(in_ECX + 0xd0) + 0x20),&local_44);
    iVar2 = ((local_44.top - local_44.bottom) - local_54.top) + local_54.bottom;
    if (0 < iVar2) {
      local_34.left = 0;
      local_34.top = 0;
      local_34.right = 0;
      local_34.bottom = 0;
      GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_34);
      FUN_00797e71(0,0xffffffff,0xffffffff,local_34.right - local_34.left,
                   (local_34.bottom - local_34.top) + iVar2,0x16);
      FUN_00797e71(0,0xffffffff,0xffffffff,local_24.right - local_24.left,
                   (local_24.bottom - local_24.top) + iVar2,0x16);
    }
    FUN_0079dd6d();
    iVar2 = FUN_0079dd6d();
    pHVar6 = LoadCursorW(*(HINSTANCE *)(iVar2 + 0xc),(LPCWSTR)0x3f11);
    *(HCURSOR *)(in_ECX + 0xe8) = pHVar6;
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorDialog[67] */
/* 0089fff2  FUN_0089fff2  243 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0089fff2(tagMSG *param_1)

{
  WPARAM WVar1;
  SHORT SVar2;
  BOOL BVar3;
  HGLOBAL hMem;
  LPWSTR lpString1;
  CDialogEx *in_ECX;
  LPCWSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x89fffe;
  if (param_1->message == 0x100) {
    WVar1 = param_1->wParam;
    SVar2 = GetAsyncKeyState(0x11);
    if ((SVar2 < 0) && ((WVar1 == 0x43 || (WVar1 == 0x2d)))) {
      BVar3 = OpenClipboard(*(HWND *)(in_ECX + 0x20));
      if (BVar3 != 0) {
        EmptyClipboard();
        CStringT<>();
        local_8 = 0;
        FUN_004059f0(local_14,L"RGB(%d, %d, %d)",in_ECX[0xe4],in_ECX[0xe5],in_ECX[0xe6]);
        hMem = GlobalAlloc(0x2000,*(int *)(local_14[0] + -6) * 2 + 2);
        lpString1 = GlobalLock(hMem);
        lstrcpyW(lpString1,local_14[0]);
        GlobalUnlock(hMem);
        SetClipboardData(0xd,hMem);
        CloseClipboard();
        local_8 = 0xffffffff;
        FUN_00406b10();
      }
    }
  }
  CDialogEx::PreTranslateMessage(in_ECX,param_1);
  return;
}



