/* CMFCFontComboBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCFontComboBox[1] */
/* 007d7a80  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCFontComboBox::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCFontComboBox::_scalar_deleting_destructor_(CMFCFontComboBox *this,uint param_1)

{
  FUN_007d7a4a();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x90);
    }
  }
  return this;
}




/* vtable slots: CMFCFontComboBox[92] */
/* 007d7b76  FUN_007d7b76  120 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_007d7b76(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  wchar_t *local_18;
  wchar_t *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7d7b82;
  uVar1 = *(undefined2 *)(param_1 + 0xc);
  CStringT<>();
  local_8 = 0;
  GetLBText(uVar1,&local_18);
  uVar1 = *(undefined2 *)(param_1 + 0x14);
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  GetLBText(uVar1,local_14);
  iVar2 = _wcscoll(local_18,local_14[0]);
  FUN_00406b10();
  FUN_00406b10();
  return iVar2;
}




/* vtable slots: CMFCFontComboBox[90] */
/* 007d7bee  FUN_007d7bee  703 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007d7bee(int param_1)

{
  code *pcVar1;
  int iVar2;
  CDC *pCVar3;
  undefined4 uVar4;
  int iVar5;
  HBRUSH pHVar6;
  COLORREF color;
  int iVar7;
  HFONT pHVar8;
  int in_ECX;
  undefined **local_9c;
  undefined4 local_98;
  int local_94;
  int local_90;
  undefined **local_8c;
  HBRUSH local_88;
  int local_84;
  LOGFONTW local_80;
  tagRECT local_24;
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94;
  local_8 = 0x7d7bfd;
  local_84 = param_1;
  local_90 = in_ECX;
  if ((in_ECX == -0x80) || (*(int *)(in_ECX + 0x84) == 0)) {
    Create(17000,0x10,0,0xffffff);
  }
  pCVar3 = CDC::FromHandle(*(HDC__ **)(param_1 + 0x18));
  CopyRect(&local_24,(RECT *)(param_1 + 0x1c));
  if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
    DrawFocusRect(*(HDC *)(pCVar3 + 4),&local_24);
  }
  pcVar1 = *(code **)(*(int *)pCVar3 + 0x1c);
  guard_check_icall();
  uVar4 = (*pcVar1)();
  local_88 = (HBRUSH)0x0;
  local_8c = CBrush::vftable;
  local_8 = 0;
  if ((*(byte *)(local_84 + 0x10) & 1) == 0) {
    color = GetBkColor(*(HDC *)(pCVar3 + 8));
    pHVar6 = CreateSolidBrush(color);
    Attach(pHVar6);
  }
  else {
    iVar5 = FUN_007c2511();
    pHVar6 = CreateSolidBrush(*(COLORREF *)(iVar5 + 0x3c));
    Attach(pHVar6);
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x30);
    iVar5 = FUN_007c2511();
    guard_check_icall(*(undefined4 *)(iVar5 + 0x40));
    (*pcVar1)();
  }
  FUN_0079f0b8(1);
  FillRect(*(HDC *)(pCVar3 + 4),&local_24,local_88);
  iVar5 = *(int *)(local_84 + 8);
  if (-1 < iVar5) {
    local_98 = 0;
    local_9c = CFont::vftable;
    local_94 = 0;
    iVar2 = *(int *)(local_84 + 0x2c);
    local_8._0_1_ = 1;
    if (iVar2 != 0) {
      if ((*(uint *)(iVar2 + 0x10) & 6) != 0) {
        FUN_0079cf15(*(undefined4 *)(local_90 + 0x84),~(*(uint *)(iVar2 + 0x10) >> 1) & 1,
                     *(undefined4 *)(pCVar3 + 4),local_24.left,
                     ((local_24.bottom - local_24.top) + -0x10) / 2 + local_24.top,0);
      }
      local_24.left = local_24.left + 0x16;
      if ((DAT_00a124e4 != 0) && (*(char *)(iVar2 + 0xc) != '\x02')) {
        iVar7 = FUN_007c2511();
        GetObjectW(*(HANDLE *)(iVar7 + 0x120),0x5c,&local_80);
        lstrcpyW(local_80.lfFaceName,*(LPCWSTR *)(iVar2 + 4));
        if (*(BYTE *)(iVar2 + 0xc) != '\x01') {
          local_80.lfCharSet = *(BYTE *)(iVar2 + 0xc);
        }
        if (local_80.lfHeight < 0) {
          local_80.lfHeight = local_80.lfHeight + -4;
        }
        else {
          local_80.lfHeight = local_80.lfHeight + 4;
        }
        pHVar8 = CreateFontIndirectW(&local_80);
        Attach(pHVar8);
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x28);
        guard_check_icall(&local_9c);
        local_94 = (*pcVar1)();
      }
    }
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,2);
    GetLBText(iVar5,&local_84);
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x68);
    guard_check_icall(local_84,*(undefined4 *)(local_84 + -0xc),&local_24,0x24);
    (*pcVar1)();
    if (local_94 != 0) {
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x28);
      guard_check_icall(local_94);
      (*pcVar1)();
    }
    FUN_00406b10();
    local_8 = local_8 & 0xffffff00;
    local_9c = CFont::vftable;
    FUN_00416100();
  }
  pcVar1 = *(code **)(*(int *)pCVar3 + 0x20);
  guard_check_icall(uVar4);
  (*pcVar1)();
  local_8c = CBrush::vftable;
  FUN_00416100();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCFontComboBox[10] */
/* 007d7ead  FUN_007d7ead  6 bytes, 0 callers */

undefined ** FUN_007d7ead(void)

{
  return &PTR_FUN_00988338;
}




/* vtable slots: CMFCFontComboBox[91] */
/* 007d7ee9  MeasureItem  113 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCFontComboBox::MeasureItem(struct tagMEASUREITEMSTRUCT *)
   
   Library: Visual Studio 2012 Release */

void __thiscall CMFCFontComboBox::MeasureItem(CMFCFontComboBox *this,tagMEASUREITEMSTRUCT *param_1)

{
  int iVar1;
  int iVar2;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect(*(HWND *)(this + 0x20),&local_18);
  *(LONG *)(param_1 + 0xc) = local_18.right - local_18.left;
  iVar1 = FUN_007c2511();
  iVar2 = DAT_00a139f4;
  if (DAT_00a139f4 < *(int *)(iVar1 + 0x1cc)) {
    iVar2 = FUN_007c2511();
    iVar2 = *(int *)(iVar2 + 0x1cc);
  }
  iVar1 = 0x10;
  if (0xf < iVar2) {
    iVar1 = iVar2;
  }
  *(int *)(param_1 + 0x10) = iVar1;
  return;
}




/* vtable slots: CMFCFontComboBox[20] */
/* 007d8065  PreSubclassWindow  29 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCFontComboBox::PreSubclassWindow(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCFontComboBox::PreSubclassWindow(CMFCFontComboBox *this)

{
  _AFX_THREAD_STATE *p_Var1;
  
  guard_check_icall();
  p_Var1 = AfxGetThreadState();
  if (*(int *)(p_Var1 + 0x14) == 0) {
    Init(this);
    return;
  }
  return;
}




/* vtable slots: CMFCFontComboBox[67] */
/* 007d8082  FUN_007d8082  260 bytes, 0 callers */

undefined4 FUN_007d8082(int param_1)

{
  SHORT SVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  LRESULT LVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x88) != 0) && (*(int *)(param_1 + 4) == 0x100)) && (DAT_00a0082c == 0)) {
    pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    iVar5 = *(int *)(param_1 + 8);
    if (iVar5 == 9) {
      if (pCVar3 == (CWnd *)0x0) {
        return 1;
      }
      pHVar2 = GetNextDlgTabItem(*(HWND *)(pCVar3 + 0x20),*(HWND *)(in_ECX + 0x20),0);
      CWnd::FromHandle(pHVar2);
    }
    else {
      if (iVar5 != 0x1b) {
        if (((iVar5 == 0x26) || (iVar5 == 0x28)) &&
           ((SVar1 = GetKeyState(0x12), -1 < SVar1 &&
            ((SVar1 = GetKeyState(0x11), -1 < SVar1 &&
             (LVar4 = SendMessageW(*(HWND *)(in_ECX + 0x20),0x157,0,0), LVar4 == 0)))))) {
          SendMessageW(*(HWND *)(in_ECX + 0x20),0x14f,1,0);
          return 1;
        }
        goto LAB_007d8177;
      }
      iVar5 = DAT_00a13a1c;
      if (DAT_00a13a1c == 0) {
        iVar5 = FUN_00792b4c();
      }
      if (iVar5 == 0) {
        return 1;
      }
      if (DAT_00a13a1c == 0) {
        FUN_00792b4c();
      }
    }
    FUN_00797df8();
    return 1;
  }
LAB_007d8177:
  uVar6 = FUN_007949fb(param_1);
  return uVar6;
}



