/* CMFCColorBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCColorBar[114], CMFCDropDownToolBar[114], CMFCImageEditorPaletteBar[114], CMFCOutlookBarPane[114], CMFCOutlookBarToolBar[114], CMFCPopupMenuBar[114], CMFCPrintPreviewToolBar[114], CMFCRibbonPanelMenuBar[114], CMFCTasksPaneToolBar[114], CMFCToolBar[114] */
/* 007c22d5  FUN_007c22d5  12 bytes, 0 callers */

bool FUN_007c22d5(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xb84) == 0;
}




/* vtable slots: CMFCColorBar[214], CMFCDropDownToolBar[214], CMFCImageEditorPaletteBar[214], CMFCOutlookBarPane[214], CMFCOutlookBarToolBar[214], CMFCPopupMenuBar[214], CMFCPrintPreviewToolBar[214], CMFCRibbonPanelMenuBar[214], CMFCTasksPaneToolBar[214], CMFCToolBar[214] */
/* 007c2463  GetColumnWidth  43 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCToolBar::GetColumnWidth(void)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

int __thiscall CMFCToolBar::GetColumnWidth(CMFCToolBar *this)

{
  int *piVar1;
  int iVar2;
  CMFCToolBar *local_c;
  CMFCToolBar *pCStack_8;
  
  if (*(int *)(this + 0xbac) == 0) {
    local_c = this;
    pCStack_8 = this;
    piVar1 = (int *)FUN_007c23d4(&local_c);
    iVar2 = *piVar1;
  }
  else {
    iVar2 = DAT_00a00620;
    if (DAT_00a00620 < 1) {
      return DAT_00a00610;
    }
  }
  return iVar2;
}




/* vtable slots: CMFCColorBar[92], CMFCDropDownToolBar[92], CMFCImageEditorPaletteBar[92], CMFCMenuBar[92], CMFCOutlookBarPane[92], CMFCOutlookBarToolBar[92], CMFCPopupMenuBar[92], CMFCPrintPreviewToolBar[92], CMFCRibbonPanelMenuBar[92], CMFCTasksPaneToolBar[92], CMFCToolBar[92] */
/* 007c276b  FUN_007c276b  7 bytes, 0 callers */

undefined4 FUN_007c276b(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb98);
}




/* vtable slots: CMFCColorBar[259], CMFCDropDownToolBar[259], CMFCImageEditorPaletteBar[259], CMFCOutlookBarPane[259], CMFCOutlookBarToolBar[259], CMFCPopupMenuBar[259], CMFCPrintPreviewToolBar[259], CMFCRibbonPanelMenuBar[259], CMFCTasksPaneToolBar[259], CMFCToolBar[259] */
/* 007c27ae  FUN_007c27ae  9 bytes, 0 callers */

undefined4 FUN_007c27ae(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xbac);
}




/* vtable slots: CMFCColorBar[218], CMFCDropDownToolBar[218], CMFCImageEditorPaletteBar[218], CMFCMenuBar[218], CMFCOutlookBarPane[218], CMFCOutlookBarToolBar[218], CMFCPopupMenuBar[218], CMFCPrintPreviewToolBar[218], CMFCRibbonPanelMenuBar[218], CMFCTasksPaneToolBar[218], CMFCToolBar[218] */
/* 007c27b7  FUN_007c27b7  7 bytes, 0 callers */

undefined4 FUN_007c27b7(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb90);
}




/* vtable slots: CMFCColorBar[242], CMFCDropDownToolBar[242], CMFCImageEditorPaletteBar[242], CMFCMenuBar[242], CMFCOutlookBarPane[242], CMFCOutlookBarToolBar[242], CMFCPopupMenuBar[242], CMFCPrintPreviewToolBar[242], CMFCRibbonPanelMenuBar[242], CMFCTasksPaneToolBar[242], CMFCToolBar[242] */
/* 007fb224  FUN_007fb224  83 bytes, 0 callers */

int FUN_007fb224(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0xc40);
  iVar4 = 0;
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pcVar1 = *(code **)(*(int *)*puVar2 + 0xbc);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    iVar4 = iVar4 + iVar3;
  }
  return iVar4;
}




/* vtable slots: CMFCColorBar[151], CMFCDropDownToolBar[151], CMFCImageEditorPaletteBar[151], CMFCMenuBar[151], CMFCOutlookBarPane[151], CMFCOutlookBarToolBar[151], CMFCPopupMenuBar[151], CMFCPrintPreviewToolBar[151], CMFCRibbonPanelMenuBar[151], CMFCTasksPaneToolBar[151], CMFCToolBar[151] */
/* 007fb2fb  FUN_007fb2fb  113 bytes, 0 callers */

void FUN_007fb2fb(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  HWND hwnd;
  
  iVar2 = FUN_007c2511();
  hwnd = (HWND)0x0;
  if (*(int *)(iVar2 + 0x19c) != 0) {
    piVar3 = (int *)FUN_007fde79(param_1);
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 0xb8);
      guard_check_icall();
      (*pcVar1)();
      iVar2 = FUN_007fb277(param_1);
      if (0 < iVar2) {
        if (in_ECX != 0) {
          hwnd = *(HWND *)(in_ECX + 0x20);
        }
        NotifyWinEvent(0x8005,hwnd,-4,iVar2);
      }
    }
  }
  return;
}




/* vtable slots: CMFCColorBar[261], CMFCDropDownToolBar[261], CMFCImageEditorPaletteBar[261], CMFCMenuBar[261], CMFCOutlookBarToolBar[261], CMFCPopupMenuBar[261], CMFCPrintPreviewToolBar[261], CMFCRibbonPanelMenuBar[261], CMFCTasksPaneToolBar[261], CMFCToolBar[261] */
/* 007fb3a2  FUN_007fb3a2  207 bytes, 0 callers */

void FUN_007fb3a2(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  int _X;
  code *pcVar5;
  
  iVar1 = FUN_007fc033(param_1);
  if (iVar1 < 1) {
    return;
  }
  pcVar5 = *(code **)(*in_ECX + 0x194);
  guard_check_icall();
  uVar2 = (*pcVar5)();
  if ((uVar2 & 0xa000) == 0) {
    _X = param_3[1] - param_2[1];
  }
  else {
    _X = *param_3 - *param_2;
  }
  iVar3 = _abs(_X);
  if (iVar3 < 6) {
    return;
  }
  iVar3 = iVar1 + -1;
  iVar4 = FUN_007fde79(iVar3);
  if (_X < 1) {
    if ((*(byte *)(iVar4 + 0x24) & 1) == 0) {
      return;
    }
    if (*(int *)(iVar4 + 0x50) == 0) goto LAB_007fb43d;
    pcVar5 = *(code **)(*in_ECX + 0x34c);
  }
  else {
    if ((*(byte *)(iVar4 + 0x24) & 1) != 0) {
      return;
    }
    pcVar5 = *(code **)(*in_ECX + 0x348);
    iVar3 = iVar1;
  }
  guard_check_icall(iVar3);
  (*pcVar5)();
LAB_007fb43d:
  pcVar5 = *(code **)(*in_ECX + 0x20c);
  guard_check_icall();
  (*pcVar5)();
  in_ECX[0x2fd] = -1;
  RedrawWindow((HWND)in_ECX[8],(RECT *)0x0,(HRGN)0x0,0x505);
  return;
}




/* vtable slots: CMFCColorBar[152], CMFCDropDownToolBar[152], CMFCImageEditorPaletteBar[152], CMFCOutlookBarToolBar[152], CMFCPopupMenuBar[152], CMFCPrintPreviewToolBar[152], CMFCRibbonPanelMenuBar[152], CMFCTasksPaneToolBar[152], CMFCToolBar[152] */
/* 007fc07c  FUN_007fc07c  62 bytes, 0 callers */

undefined4 FUN_007fc07c(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x3b8);
  guard_check_icall(param_1,param_2 != 0 | -(param_3 != 0) & 2U,0xffffffff);
  (*pcVar1)();
  return param_1;
}




/* vtable slots: CMFCColorBar[238], CMFCDropDownToolBar[238], CMFCImageEditorPaletteBar[238], CMFCOutlookBarPane[238], CMFCOutlookBarToolBar[238], CMFCPopupMenuBar[238], CMFCPrintPreviewToolBar[238], CMFCRibbonPanelMenuBar[238], CMFCTasksPaneToolBar[238], CMFCToolBar[238] */
/* 007fc0ba  FUN_007fc0ba  542 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_007fc0ba(int *param_1,uint param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  uint uVar6;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x345] != 0) {
    *(undefined4 *)(in_ECX[0x345] + 0xfc) = 0;
  }
  pcVar1 = *(code **)(*in_ECX + 0x41c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  in_ECX[0x2fa] = iVar2;
  uVar6 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  uVar3 = in_ECX[0x27];
  if ((uVar3 & 2) != 0) goto LAB_007fc1a8;
  if ((uVar3 & 4) == 0) {
LAB_007fc18f:
    uVar3 = -(uint)((param_2 & 2) != 0) & 0x7fff;
  }
  else if ((param_2 & 4) == 0) {
    if ((param_2 & 8) == 0) {
      if ((param_2 & 0x10) == 0) {
        if (param_3 == -1) {
          if ((uVar3 & 1) == 0) goto LAB_007fc18f;
          goto LAB_007fc124;
        }
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        SetRectEmpty(&local_18);
        FUN_007ef36a(&local_18,param_2 & 2);
        uVar6 = param_2 & 0x20;
        if (uVar6 == 0) {
          iVar2 = local_18.right - local_18.left;
        }
        else {
          iVar2 = local_18.bottom - local_18.top;
        }
        uVar3 = iVar2 + param_3;
      }
      else {
        uVar6 = 0;
        uVar3 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar3 = 0x7fff;
    }
  }
  else {
LAB_007fc124:
    uVar6 = 0;
    uVar3 = in_ECX[0x4f];
  }
  FUN_00805b89(uVar3,uVar6);
LAB_007fc1a8:
  pcVar1 = *(code **)(*in_ECX + 0x2a4);
  uVar3 = ~(param_2 >> 1) & 1;
  guard_check_icall(&local_18.right,uVar3);
  piVar4 = (int *)(*pcVar1)();
  iVar2 = piVar4[1];
  *param_1 = *piVar4;
  param_1[1] = iVar2;
  iVar2 = in_ECX[0x345];
  if (((iVar2 != 0) && (*(int *)(iVar2 + 0xe8) < 1)) && (*(int *)(iVar2 + 0x11c) == 0)) {
    *(undefined4 *)(iVar2 + 0xfc) = 1;
    pcVar1 = *(code **)(*in_ECX + 0x2a4);
    guard_check_icall(&local_18.right,uVar3);
    piVar4 = (int *)(*pcVar1)();
    iVar2 = piVar4[1];
    *param_1 = *piVar4;
    param_1[1] = iVar2;
  }
  if ((((param_2 & 0x40) != 0) && (((byte)in_ECX[0x27] & 5) == 5)) && ((param_2 & 2) != 0)) {
    in_ECX[0x4f] = *param_1;
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  SetRectEmpty(&local_18);
  FUN_007ef36a(&local_18,param_2 & 2);
  iVar2 = local_18.top + (param_1[1] - local_18.bottom);
  iVar5 = local_18.left + (*param_1 - local_18.right);
  FUN_007abeef(&local_18.right,param_2 & 1,param_2 & 2);
  if (iVar5 <= local_18.right) {
    iVar5 = local_18.right;
  }
  *param_1 = iVar5;
  if (iVar2 <= local_18.bottom) {
    iVar2 = local_18.bottom;
  }
  param_1[1] = iVar2;
  FUN_00803951();
  return param_1;
}




/* vtable slots: CMFCColorBar[263], CMFCDropDownToolBar[263], CMFCImageEditorPaletteBar[263], CMFCOutlookBarPane[263], CMFCOutlookBarToolBar[263], CMFCPopupMenuBar[263], CMFCPrintPreviewToolBar[263], CMFCRibbonPanelMenuBar[263], CMFCTasksPaneToolBar[263], CMFCToolBar[263] */
/* 007fc2d8  FUN_007fc2d8  327 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_007fc2d8(void)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  undefined1 local_4c [20];
  undefined4 local_38 [2];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x7fc2e4;
  pcVar1 = *(code **)(*in_ECX + 0x194);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  local_1c = (uint)((uVar2 & 0xa000) != 0);
  in_ECX[0x2e3] = 0;
  if ((in_ECX[0x2e2] == 0) || ((uVar2 & 0xa000) == 0)) {
    iVar7 = 0;
  }
  else {
    local_14 = 0;
    FUN_0079dea2(in_ECX);
    local_8 = 0;
    local_20 = FUN_0080441a(local_4c);
    if (local_20 == 0) {
LAB_007fc41a:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    local_18 = in_ECX[0x310];
    iVar7 = 0;
    while (local_18 != 0) {
      piVar3 = (int *)FUN_0044f2d0(&local_18);
      piVar3 = (int *)*piVar3;
      if (piVar3 == (int *)0x0) goto LAB_007fc41a;
      if (piVar3[6] != 0) {
        if (*(int *)(piVar3[0xb] + -0xc) == 0) {
          pcVar1 = *(code **)(*in_ECX + 0x3a0);
          guard_check_icall(piVar3);
          (*pcVar1)();
        }
        pcVar1 = *(code **)(*piVar3 + 0x1c);
        uVar4 = FUN_007c23d4(local_28);
        guard_check_icall(local_30,local_4c,uVar4,local_1c);
        puVar5 = (undefined4 *)(*pcVar1)();
        local_38[0] = *puVar5;
        iVar7 = local_14;
        if (local_14 <= (int)puVar5[1]) {
          iVar7 = puVar5[1];
          local_14 = iVar7;
        }
      }
    }
    iVar6 = FUN_007c23d4(local_38);
    in_ECX[0x2e3] = (uint)(*(int *)(iVar6 + 4) < iVar7);
    FUN_0079efbc(local_20);
    FUN_0079dfff();
  }
  return iVar7;
}




/* vtable slots: CMFCColorBar[225], CMFCDropDownToolBar[225], CMFCImageEditorPaletteBar[225], CMFCOutlookBarToolBar[225], CMFCPopupMenuBar[225], CMFCPrintPreviewToolBar[225], CMFCRibbonPanelMenuBar[225], CMFCTasksPaneToolBar[225], CMFCToolBar[225] */
/* 007fc659  FUN_007fc659  12 bytes, 0 callers */

bool FUN_007fc659(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xd18) != 0;
}




/* vtable slots: CMFCColorBar[200], CMFCDropDownToolBar[200], CMFCImageEditorPaletteBar[200], CMFCOutlookBarPane[200], CMFCOutlookBarToolBar[200], CMFCPopupMenuBar[200], CMFCPrintPreviewToolBar[200], CMFCRibbonPanelMenuBar[200], CMFCTasksPaneToolBar[200], CMFCToolBar[200] */
/* 007fc712  FUN_007fc712  60 bytes, 3 callers */

void FUN_007fc712(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007fc878(param_1,0x800,param_2,1,1,1,1,param_3);
  return;
}




/* vtable slots: CMFCColorBar[201], CMFCDropDownToolBar[201], CMFCImageEditorPaletteBar[201], CMFCOutlookBarPane[201], CMFCOutlookBarToolBar[201], CMFCPopupMenuBar[201], CMFCPrintPreviewToolBar[201], CMFCRibbonPanelMenuBar[201], CMFCTasksPaneToolBar[201], CMFCToolBar[201] */
/* 007fc878  FUN_007fc878  230 bytes, 2 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007fc878(undefined4 param_1,uint param_2,uint param_3,int param_4,int param_5,
                 undefined4 param_6,undefined4 param_7,int param_8)

{
  code *pcVar1;
  undefined4 *puVar2;
  CPane *in_ECX;
  uint uVar3;
  undefined1 local_2c [4];
  undefined4 local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x7fc884;
  local_28 = param_1;
  if (param_4 < 1) {
    param_4 = 1;
  }
  if (param_5 < 1) {
    param_5 = 1;
  }
  CPane::SetBorders(in_ECX,(tagRECT *)&param_4);
  uVar3 = param_3 & 0x40ffff | 0x400000;
  *(uint *)(in_ECX + 0x9c) = uVar3;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x1e0);
  guard_check_icall(uVar3);
  (*pcVar1)();
  if (param_8 == 0xe800) {
    *(uint *)(in_ECX + 0x9c) = *(uint *)(in_ECX + 0x9c) | 8;
  }
  FUN_00790c5e(0x10);
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  SetRectEmpty(&local_24);
  FUN_007c2511();
  puVar2 = (undefined4 *)FUN_007e5eba(local_2c,L"Afx:ToolBar");
  local_8 = 0;
  Create(*puVar2,param_3 & 0xffbf0000 | (param_2 | 0x4e) & 0xfffffffd,&local_24,local_28,param_8,0,0
        );
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorBar[216], CMFCDropDownToolBar[216], CMFCImageEditorPaletteBar[216], CMFCMenuBar[216], CMFCOutlookBarPane[216], CMFCOutlookBarToolBar[216], CMFCPopupMenuBar[216], CMFCPrintPreviewToolBar[216], CMFCRibbonPanelMenuBar[216], CMFCTasksPaneToolBar[216], CMFCToolBar[216] */
/* 007fc95e  FUN_007fc95e  102 bytes, 0 callers */

void FUN_007fc95e(void)

{
  int iVar1;
  code *pcVar2;
  CWnd *pCVar3;
  CWnd *in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xbf0);
  if ((-1 < iVar1) && (iVar1 < *(int *)(in_ECX + 0xc48))) {
    *(undefined4 *)(in_ECX + 0xbf8) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0xbf0) = 0xffffffff;
    FUN_007fe655(iVar1);
    UpdateWindow(*(HWND *)(in_ECX + 0x20));
    pCVar3 = CWnd::GetOwner(in_ECX);
    SendMessageW(*(HWND *)(pCVar3 + 0x20),0x362,0xe001,0);
  }
  pcVar2 = *(code **)(*(int *)in_ECX + 0x364);
  guard_check_icall();
  (*pcVar2)();
  return;
}




/* vtable slots: CMFCColorBar[239], CMFCDropDownToolBar[239], CMFCImageEditorPaletteBar[239], CMFCMenuBar[239], CMFCOutlookBarPane[239], CMFCOutlookBarToolBar[239], CMFCPopupMenuBar[239], CMFCPrintPreviewToolBar[239], CMFCRibbonPanelMenuBar[239], CMFCTasksPaneToolBar[239], CMFCToolBar[239] */
/* 007fd389  FUN_007fd389  196 bytes, 0 callers */

undefined4 FUN_007fd389(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  
  uVar5 = 0;
  if ((param_2[0x14] != 0) && (param_2[0x10] == 0)) {
    pcVar1 = *(code **)(*param_1 + 0x58);
    piVar6 = param_2 + 0x15;
    guard_check_icall(piVar6);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x194);
      guard_check_icall(piVar6);
      uVar3 = (*pcVar1)();
      pcVar1 = *(code **)(*param_2 + 0x18);
      if ((in_ECX[0x2f0] == 0) || (param_5 != 0)) {
        uVar4 = 0;
      }
      else {
        uVar4 = 1;
      }
      if (((DAT_00a127ac != 0) && (DAT_00a127b0 == 0)) && (in_ECX[0x2de] == 0)) {
        uVar5 = 1;
      }
      guard_check_icall(param_1,param_2 + 0x15,param_3,(uVar3 & 0xa000) != 0,uVar5,param_4,
                        in_ECX[0x2ef],uVar4);
      (*pcVar1)();
    }
  }
  return 1;
}




/* vtable slots: CMFCColorBar[123], CMFCDropDownToolBar[123], CMFCImageEditorPaletteBar[123], CMFCMenuBar[123], CMFCOutlookBarPane[123], CMFCOutlookBarToolBar[123], CMFCPopupMenuBar[123], CMFCPrintPreviewToolBar[123], CMFCRibbonPanelMenuBar[123], CMFCTasksPaneToolBar[123], CMFCToolBar[123] */
/* 007fd9a8  FUN_007fd9a8  26 bytes, 0 callers */

void FUN_007fd9a8(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0) = 1;
  *(undefined4 *)(in_ECX + 0x98) = param_1;
  return;
}




/* vtable slots: CMFCColorBar[220], CMFCDropDownToolBar[220], CMFCImageEditorPaletteBar[220], CMFCMenuBar[220], CMFCOutlookBarPane[220], CMFCOutlookBarToolBar[220], CMFCPopupMenuBar[220], CMFCPrintPreviewToolBar[220], CMFCRibbonPanelMenuBar[220], CMFCTasksPaneToolBar[220], CMFCToolBar[220] */
/* 007fe0e3  FUN_007fe0e3  106 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007fe0e3(undefined4 param_1,undefined4 *param_2)

{
  code *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined1 local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_2 != (undefined4 *)0x0) {
    piVar2 = (int *)FUN_007fde79(param_1);
    if (piVar2 == (int *)0x0) {
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
    }
    else {
      pcVar1 = *(code **)(*piVar2 + 0x88);
      guard_check_icall(local_18);
      puVar3 = (undefined4 *)(*pcVar1)();
      *param_2 = *puVar3;
      param_2[1] = puVar3[1];
      param_2[2] = puVar3[2];
      param_2[3] = puVar3[3];
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCColorBar[219], CMFCDropDownToolBar[219], CMFCImageEditorPaletteBar[219], CMFCMenuBar[219], CMFCOutlookBarPane[219], CMFCOutlookBarToolBar[219], CMFCPopupMenuBar[219], CMFCPrintPreviewToolBar[219], CMFCRibbonPanelMenuBar[219], CMFCTasksPaneToolBar[219], CMFCToolBar[219] */
/* 007fe164  FUN_007fe164  55 bytes, 0 callers */

void FUN_007fe164(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_2 != (undefined4 *)0x0) {
    iVar1 = FUN_007fde79(param_1);
    if (iVar1 == 0) {
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
    }
    else {
      *param_2 = *(undefined4 *)(iVar1 + 0x54);
      param_2[1] = *(undefined4 *)(iVar1 + 0x58);
      param_2[2] = *(undefined4 *)(iVar1 + 0x5c);
      param_2[3] = *(undefined4 *)(iVar1 + 0x60);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCColorBar[213], CMFCDropDownToolBar[213], CMFCOutlookBarPane[213], CMFCOutlookBarToolBar[213], CMFCPopupMenuBar[213], CMFCPrintPreviewToolBar[213], CMFCRibbonPanelMenuBar[213], CMFCTasksPaneToolBar[213], CMFCToolBar[213] */
/* 007fe2ba  FUN_007fe2ba  180 bytes, 0 callers */

int FUN_007fe2ba(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_14 [8];
  undefined1 local_c [8];
  
  if (*(int *)(in_ECX + 0xb8c) == 0) {
    if (*(int *)(in_ECX + 0xbac) == 0) {
      iVar2 = FUN_007c23d4(local_c);
      iVar2 = *(int *)(iVar2 + 4);
    }
    else {
      iVar2 = DAT_00a00624;
      if (DAT_00a00624 < 1) {
        iVar2 = DAT_00a00614;
      }
    }
    iVar1 = FUN_007c2511();
    if ((*(uint *)(in_ECX + 0x9c) & 0xa000) == 0) {
      iVar1 = *(int *)(iVar1 + 0x1d0);
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x1cc);
    }
    if (iVar2 < iVar1) {
      iVar2 = FUN_007c2511();
      if ((*(uint *)(in_ECX + 0x9c) & 0xa000) == 0) {
        iVar2 = *(int *)(iVar2 + 0x1d0);
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x1cc);
      }
    }
    else if (*(int *)(in_ECX + 0xbac) == 0) {
      iVar2 = FUN_007c23d4(local_14);
      iVar2 = *(int *)(iVar2 + 4);
    }
    else {
      iVar2 = DAT_00a00624;
      if (DAT_00a00624 < 1) {
        iVar2 = DAT_00a00614;
      }
    }
  }
  else {
    iVar2 = *(int *)(in_ECX + 0xbe8);
  }
  return iVar2;
}




/* vtable slots: CMFCColorBar[228], CMFCDropDownToolBar[228], CMFCImageEditorPaletteBar[228], CMFCMenuBar[228], CMFCOutlookBarPane[228], CMFCOutlookBarToolBar[228], CMFCPopupMenuBar[228], CMFCPrintPreviewToolBar[228], CMFCRibbonPanelMenuBar[228], CMFCTasksPaneToolBar[228], CMFCToolBar[228] */
/* 007fe374  FUN_007fe374  113 bytes, 0 callers */

int FUN_007fe374(LONG param_1,LONG param_2)

{
  int iVar1;
  POINT pt;
  int *piVar2;
  BOOL BVar3;
  int in_ECX;
  int iVar4;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0xc40);
  iVar4 = 0;
  while( true ) {
    if (local_8 == 0) {
      return -1;
    }
    piVar2 = (int *)FUN_0044f2d0(&local_8);
    iVar1 = *piVar2;
    if (iVar1 == 0) break;
    pt.y = param_2;
    pt.x = param_1;
    BVar3 = PtInRect((RECT *)(iVar1 + 0x54),pt);
    if ((BVar3 != 0) && (*(int *)(iVar1 + 0x40) == 0)) {
      if ((*(byte *)(iVar1 + 0x24) & 1) == 0) {
        return iVar4;
      }
      return -1;
    }
    iVar4 = iVar4 + 1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCColorBar[208], CMFCDropDownToolBar[208], CMFCImageEditorPaletteBar[208], CMFCMenuBar[208], CMFCOutlookBarPane[208], CMFCOutlookBarToolBar[208], CMFCPopupMenuBar[208], CMFCPrintPreviewToolBar[208], CMFCRibbonPanelMenuBar[208], CMFCTasksPaneToolBar[208], CMFCToolBar[208] */
/* 007fe3e6  FUN_007fe3e6  180 bytes, 0 callers */

int FUN_007fe3e6(CObject *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  __POSITION *p_Var3;
  int in_ECX;
  
  if (param_1 == (CObject *)0x0) goto LAB_007fe495;
  iVar2 = FUN_007fe7b9(*(undefined4 *)(param_1 + 0x20));
  if (iVar2 == 0) {
LAB_007fe490:
    param_2 = -1;
  }
  else {
    if (param_2 == -1) {
LAB_007fe41f:
      if (*(int *)(in_ECX + 0xd14) == 0) {
        CObList::AddTail((CObList *)(in_ECX + 0xc3c),param_1);
        pcVar1 = *(code **)(*(int *)param_1 + 0x28);
        guard_check_icall();
        (*pcVar1)();
        return *(int *)(in_ECX + 0xc48) + -1;
      }
      param_2 = *(int *)(in_ECX + 0xc48) + -1;
    }
    else {
      if ((param_2 < 0) || (*(int *)(in_ECX + 0xc48) < param_2)) goto LAB_007fe490;
      if (param_2 == *(int *)(in_ECX + 0xc48)) goto LAB_007fe41f;
    }
    p_Var3 = CObList::FindIndex((CObList *)(in_ECX + 0xc3c),param_2);
    if (p_Var3 == (__POSITION *)0x0) {
LAB_007fe495:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    InsertBefore(p_Var3,param_1);
    pcVar1 = *(code **)(*(int *)param_1 + 0x28);
    guard_check_icall();
    (*pcVar1)();
  }
  return param_2;
}




/* vtable slots: CMFCColorBar[209], CMFCDropDownToolBar[209], CMFCImageEditorPaletteBar[209], CMFCMenuBar[209], CMFCOutlookBarPane[209], CMFCOutlookBarToolBar[209], CMFCPopupMenuBar[209], CMFCPrintPreviewToolBar[209], CMFCRibbonPanelMenuBar[209], CMFCTasksPaneToolBar[209], CMFCToolBar[209] */
/* 007fe49b  FUN_007fe49b  130 bytes, 0 callers */

int FUN_007fe49b(undefined4 *param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  pcVar1 = *(code **)*param_1;
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    piVar3 = (int *)FUN_0079d90c();
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 0x14);
      guard_check_icall(param_1);
      (*pcVar1)();
      pcVar1 = *(code **)(*in_ECX + 0x340);
      guard_check_icall(piVar3,param_2);
      iVar2 = (*pcVar1)();
      if (iVar2 < 0) {
        pcVar1 = *(code **)(*piVar3 + 4);
        guard_check_icall(1);
        (*pcVar1)();
      }
      return iVar2;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCColorBar[210], CMFCDropDownToolBar[210], CMFCImageEditorPaletteBar[210], CMFCMenuBar[210], CMFCOutlookBarPane[210], CMFCOutlookBarToolBar[210], CMFCPopupMenuBar[210], CMFCPrintPreviewToolBar[210], CMFCRibbonPanelMenuBar[210], CMFCTasksPaneToolBar[210], CMFCToolBar[210] */
/* 007fe5d1  FUN_007fe5d1  132 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_007fe5d1(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  piVar3 = (int *)0x0;
  if ((in_ECX[0x312] == 0) || (param_1 == 0)) {
    iVar2 = -1;
  }
  else {
    iVar2 = FUN_0078e624(0x70);
    if (iVar2 != 0) {
      piVar3 = (int *)FUN_00880e44();
    }
    piVar3[9] = 1;
    pcVar1 = *(code **)(*in_ECX + 0x340);
    guard_check_icall(piVar3,param_1);
    iVar2 = (*pcVar1)();
    if (iVar2 == -1) {
      pcVar1 = *(code **)(*piVar3 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  return iVar2;
}




/* vtable slots: CMFCColorBar[205], CMFCDropDownToolBar[205], CMFCImageEditorPaletteBar[205], CMFCMenuBar[205], CMFCOutlookBarPane[205], CMFCOutlookBarToolBar[205], CMFCPopupMenuBar[205], CMFCPrintPreviewToolBar[205], CMFCRibbonPanelMenuBar[205], CMFCTasksPaneToolBar[205], CMFCToolBar[205] */
/* 007fe912  FUN_007fe912  603 bytes, 0 callers */

undefined4 FUN_007fe912(uint *param_1,int param_2)

{
  int iVar1;
  CMFCToolBarImages *this;
  int in_ECX;
  uint uVar2;
  
  *(int *)(in_ECX + 0xb78) = param_2;
  if (param_2 == 0) {
    iVar1 = CMFCToolBarImages::Load
                      ((CMFCToolBarImages *)&DAT_00a12880,param_1[1],(HINSTANCE__ *)0x0,1);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = CMFCToolBarImages::GetResourceOffset((CMFCToolBarImages *)&DAT_00a12880,param_1[1]);
    *(int *)(in_ECX + 0xc04) = iVar1;
    if (*param_1 == 0) {
      if (DAT_00a12798 != 0) {
        FUN_007e8118(&DAT_00a12998);
        FUN_007e9bc1(DAT_00a1279c);
      }
    }
    else {
      iVar1 = CMFCToolBarImages::Load
                        ((CMFCToolBarImages *)&DAT_00a12998,*param_1,(HINSTANCE__ *)0x0,1);
      if (iVar1 == 0) {
        return 0;
      }
    }
    if ((param_1[6] != 0) &&
       (iVar1 = CMFCToolBarImages::Load
                          ((CMFCToolBarImages *)&DAT_00a12ab0,param_1[6],(HINSTANCE__ *)0x0,1),
       iVar1 == 0)) {
      return 0;
    }
    if ((param_1[2] != 0) &&
       (iVar1 = CMFCToolBarImages::Load
                          ((CMFCToolBarImages *)&DAT_00a12bc8,param_1[2],(HINSTANCE__ *)0x0,1),
       iVar1 == 0)) {
      return 0;
    }
    if ((param_1[7] != 0) &&
       (iVar1 = CMFCToolBarImages::Load
                          ((CMFCToolBarImages *)&DAT_00a12ce0,param_1[7],(HINSTANCE__ *)0x0,1),
       iVar1 == 0)) {
      return 0;
    }
    if ((param_1[4] != 0) &&
       (iVar1 = CMFCToolBarImages::Load
                          ((CMFCToolBarImages *)&DAT_00a12df8,param_1[4],(HINSTANCE__ *)0x0,1),
       iVar1 == 0)) {
      return 0;
    }
    if ((param_1[3] != 0) &&
       (iVar1 = CMFCToolBarImages::Load
                          ((CMFCToolBarImages *)&DAT_00a12f10,param_1[3],(HINSTANCE__ *)0x0,1),
       iVar1 == 0)) {
      return 0;
    }
    if (param_1[5] == 0) {
      return 1;
    }
    uVar2 = param_1[5];
    this = (CMFCToolBarImages *)&DAT_00a13028;
  }
  else {
    iVar1 = CMFCToolBarImages::Load
                      ((CMFCToolBarImages *)(in_ECX + 0x2b8),param_1[1],(HINSTANCE__ *)0x0,1);
    if (iVar1 == 0) {
      return 0;
    }
    if (*param_1 == 0) {
      if (DAT_00a12798 != 0) {
        FUN_007e8118(in_ECX + 0x3d0);
        FUN_007e9bc1(DAT_00a1279c);
      }
    }
    else {
      iVar1 = CMFCToolBarImages::Load
                        ((CMFCToolBarImages *)(in_ECX + 0x3d0),*param_1,(HINSTANCE__ *)0x0,1);
      if (iVar1 == 0) {
        return 0;
      }
    }
    if ((param_1[2] != 0) &&
       (iVar1 = CMFCToolBarImages::Load
                          ((CMFCToolBarImages *)(in_ECX + 0x4e8),param_1[2],(HINSTANCE__ *)0x0,1),
       iVar1 == 0)) {
      return 0;
    }
    if ((param_1[4] != 0) &&
       (iVar1 = CMFCToolBarImages::Load
                          ((CMFCToolBarImages *)(in_ECX + 0x600),param_1[4],(HINSTANCE__ *)0x0,1),
       iVar1 == 0)) {
      return 0;
    }
    if ((param_1[3] != 0) &&
       (iVar1 = CMFCToolBarImages::Load
                          ((CMFCToolBarImages *)(in_ECX + 0x718),param_1[3],(HINSTANCE__ *)0x0,1),
       iVar1 == 0)) {
      return 0;
    }
    if ((param_1[5] != 0) &&
       (iVar1 = CMFCToolBarImages::Load
                          ((CMFCToolBarImages *)(in_ECX + 0x830),param_1[5],(HINSTANCE__ *)0x0,1),
       iVar1 == 0)) {
      return 0;
    }
    this = (CMFCToolBarImages *)(in_ECX + 0x948);
    if ((param_1[6] != 0) &&
       (iVar1 = CMFCToolBarImages::Load(this,param_1[6],(HINSTANCE__ *)0x0,1), iVar1 == 0)) {
      return 0;
    }
    if (param_1[7] == 0) {
      return 1;
    }
    uVar2 = param_1[6];
  }
  iVar1 = CMFCToolBarImages::Load(this,uVar2,(HINSTANCE__ *)0x0,1);
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}




/* vtable slots: CMFCColorBar[203], CMFCImageEditorPaletteBar[203], CMFCMenuBar[203], CMFCOutlookBarPane[203], CMFCOutlookBarToolBar[203], CMFCPopupMenuBar[203], CMFCPrintPreviewToolBar[203], CMFCRibbonPanelMenuBar[203], CMFCTasksPaneToolBar[203], CMFCToolBar[203] */
/* 007feb6d  FUN_007feb6d  81 bytes, 1 callers */

void FUN_007feb6d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  int *in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_007faeef();
  local_24 = param_2;
  local_20 = param_1;
  local_1c = param_5;
  local_c = param_3;
  local_8 = param_6;
  pcVar1 = *(code **)(*in_ECX + 0x334);
  guard_check_icall(&local_24,param_4);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCColorBar[267], CMFCDropDownToolBar[267], CMFCImageEditorPaletteBar[267], CMFCMenuBar[267], CMFCOutlookBarPane[267], CMFCOutlookBarToolBar[267], CMFCPopupMenuBar[267], CMFCPrintPreviewToolBar[267], CMFCRibbonPanelMenuBar[267], CMFCTasksPaneToolBar[267], CMFCToolBar[267] */
/* 007fec8c  FUN_007fec8c  148 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007fec8c(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  CObList local_30 [12];
  int local_24;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x7fec98;
  uVar4 = 0;
  CObList::CObList(local_30,10);
  local_8 = 0;
  pcVar1 = *(code **)(*param_1 + 0x40);
  guard_check_icall(L"OriginalItems",local_30);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*local_14 + 0x430);
    guard_check_icall(local_30);
    uVar4 = (*pcVar1)();
  }
  while (local_24 != 0) {
    piVar3 = (int *)FUN_007a1b17();
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  FUN_007a184a();
  return uVar4;
}




/* vtable slots: CMFCColorBar[139], CMFCDropDownToolBar[139], CMFCImageEditorPaletteBar[139], CMFCOutlookBarPane[139], CMFCPopupMenuBar[139], CMFCPrintPreviewToolBar[139], CMFCRibbonPanelMenuBar[139], CMFCTasksPaneToolBar[139], CMFCToolBar[139] */
/* 007fedee  FUN_007fedee  412 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007fedee(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined1 local_bc [72];
  undefined1 local_74 [60];
  undefined4 local_38;
  int *local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [2];
  undefined4 local_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xac;
  local_8 = 0x7fedfd;
  FUN_008592c1(&local_2c,L"MFCToolBars",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(&local_20,L"%TsMFCToolBar-%d",local_2c,param_2);
  }
  else {
    FUN_004059f0(&local_20,L"%TsMFCToolBar-%d%x",local_2c,param_2,param_3);
  }
  local_28[0] = 0;
  local_34 = (int *)0x0;
  local_30 = 0;
  local_8._0_1_ = 2;
  local_1c = (int *)FUN_00859490(0,1);
  pcVar1 = *(code **)(*local_1c + 0x10);
  guard_check_icall(local_20);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    if (local_34 != (int *)0x0) {
      pcVar1 = *(code **)(*local_34 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    FUN_00406b10();
    FUN_00406b10();
  }
  else {
    pcVar1 = *(code **)(*local_1c + 0x44);
    guard_check_icall(L"Buttons",local_28,&local_38);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      local_8._0_1_ = 3;
      FUN_007b57de(local_28[0],local_38,0);
      local_8._0_1_ = 4;
      FUN_007a6256(local_74,1,0x1000,0);
      local_8 = CONCAT31(local_8._1_3_,5);
      pcVar1 = *(code **)(*in_ECX + 8);
      guard_check_icall(local_bc);
      (*pcVar1)();
      local_18 = 1;
      FUN_007a6389();
      FUN_007b583b();
      uVar3 = FUN_007fefa5(local_20);
      return uVar3;
    }
    if (local_34 != (int *)0x0) {
      pcVar1 = *(code **)(*local_34 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    FUN_00406b10();
    FUN_00406b10();
  }
  return 0;
}




/* vtable slots: CMFCColorBar[204], CMFCImageEditorPaletteBar[204], CMFCMenuBar[204], CMFCOutlookBarPane[204], CMFCOutlookBarToolBar[204], CMFCPopupMenuBar[204], CMFCPrintPreviewToolBar[204], CMFCRibbonPanelMenuBar[204], CMFCTasksPaneToolBar[204], CMFCToolBar[204] */
/* 007ff127  FUN_007ff127  84 bytes, 1 callers */

void FUN_007ff127(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  code *pcVar1;
  int *in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_007faeef();
  local_24 = param_2;
  local_20 = param_7;
  local_1c = param_5;
  local_c = param_3;
  local_8 = param_6;
  pcVar1 = *(code **)(*in_ECX + 0x338);
  guard_check_icall(param_1,&local_24,param_4);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCColorBar[206], CMFCDropDownToolBar[206], CMFCImageEditorPaletteBar[206], CMFCMenuBar[206], CMFCOutlookBarPane[206], CMFCOutlookBarToolBar[206], CMFCPopupMenuBar[206], CMFCPrintPreviewToolBar[206], CMFCRibbonPanelMenuBar[206], CMFCTasksPaneToolBar[206], CMFCToolBar[206] */
/* 007ff17b  FUN_007ff17b  596 bytes, 0 callers */

int FUN_007ff17b(uint param_1,int param_2,int param_3)

{
  double dVar1;
  HMODULE hModule;
  code *pcVar2;
  int iVar3;
  HRSRC hResInfo;
  HGLOBAL hResData;
  LPVOID pvVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *in_ECX;
  uint uVar8;
  ushort *puVar9;
  int iVar10;
  int local_1c;
  int iStack_10;
  int local_8;
  
  if (param_1 == 0) {
LAB_007ff3ca:
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  iVar3 = FUN_0079dd6d();
  hModule = *(HMODULE *)(iVar3 + 0xc);
  hResInfo = FindResourceW(hModule,(LPCWSTR)(param_1 & 0xffff),(LPCWSTR)0xf1);
  if (((hResInfo == (HRSRC)0x0) ||
      (hResData = LoadResource(hModule,hResInfo), hResData == (HGLOBAL)0x0)) ||
     (pvVar4 = LockResource(hResData), pvVar4 == (LPVOID)0x0)) {
    return 0;
  }
  iVar3 = FUN_0078e661((uint)*(ushort *)((int)pvVar4 + 6) * 4);
  if (iVar3 == 0) goto LAB_007ff3ca;
  uVar5 = (uint)*(ushort *)((int)pvVar4 + 2);
  uVar8 = (uint)*(ushort *)((int)pvVar4 + 4);
  local_8 = uVar5 + 6;
  iStack_10 = uVar8 + 6;
  iVar6 = DAT_00a12790;
  if (param_3 != 0) {
    iVar6 = in_ECX[0x30c];
  }
  if (iVar6 == 0) {
    iVar6 = FUN_007c2511();
    if (*(int *)(iVar6 + 0x1e8) == 0) {
      dVar1 = 1.0;
    }
    else {
      dVar1 = *(double *)(iVar6 + 0x1e0);
    }
    if (dVar1 != 1.0) {
      FUN_007c2511();
      local_8 = thunk_FUN_008d99f0();
      iStack_10 = thunk_FUN_008d99f0();
    }
  }
  if (param_3 == 0) {
    iVar6 = FUN_007ea14e();
    if (iVar6 == 0) {
      FUN_00805632(local_8,iStack_10,uVar5,uVar8);
    }
  }
  else {
    FUN_008052eb(local_8,iStack_10,uVar5,uVar8,0);
  }
  local_1c = 1;
  if (*(int *)(param_2 + 4) == 0) {
    *(uint *)(param_2 + 4) = param_1;
  }
  if (in_ECX[0x346] == 0) {
    pcVar2 = *(code **)(*in_ECX + 0x334);
    guard_check_icall(param_2,param_3);
    iVar6 = (*pcVar2)();
    if (iVar6 == 0) goto LAB_007ff3b3;
  }
  local_1c = 0;
  if (*(short *)((int)pvVar4 + 6) != 0) {
    puVar9 = (ushort *)((int)pvVar4 + 8);
    iVar6 = in_ECX[0x301];
    do {
      uVar5 = (uint)*puVar9;
      *(uint *)(iVar3 + local_1c * 4) = uVar5;
      iVar10 = iVar6;
      if ((param_3 == 0) && (uVar5 != 0)) {
        iVar10 = iVar6 + 1;
        piVar7 = (int *)FUN_007e3332(uVar5);
        *piVar7 = iVar6;
      }
      local_1c = local_1c + 1;
      puVar9 = puVar9 + 1;
      iVar6 = iVar10;
    } while (local_1c < (int)(uint)*(ushort *)((int)pvVar4 + 6));
  }
  in_ECX[0x346] = param_1;
  pcVar2 = *(code **)(*in_ECX + 0x33c);
  guard_check_icall(iVar3,*(undefined2 *)((int)pvVar4 + 6),1);
  local_1c = (*pcVar2)();
  if (local_1c == 0) {
    in_ECX[0x346] = 0;
  }
LAB_007ff3b3:
  thunk_FUN_008f43b0(iVar3);
  return local_1c;
}




/* vtable slots: CMFCColorBar[231], CMFCDropDownToolBar[231], CMFCImageEditorPaletteBar[231], CMFCMenuBar[231], CMFCOutlookBarPane[231], CMFCOutlookBarToolBar[231], CMFCPopupMenuBar[231], CMFCPrintPreviewToolBar[231], CMFCRibbonPanelMenuBar[231], CMFCTasksPaneToolBar[231], CMFCToolBar[231] */
/* 007ff473  FUN_007ff473  296 bytes, 0 callers */

undefined4 FUN_007ff473(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  CObject *pCVar5;
  CObject *pCVar6;
  ANIMATION_TYPE AVar7;
  int *in_ECX;
  int local_8;
  
  piVar3 = (int *)FUN_007fdf83(&local_8);
  if (piVar3 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar3 + 0xec);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      iVar2 = in_ECX[0x312];
      iVar4 = local_8 + 1;
      AVar7 = DAT_00a139d8;
      if (iVar4 != local_8) {
        do {
          if (iVar2 <= iVar4) {
            iVar4 = 0;
          }
          pCVar5 = (CObject *)FUN_007fde79(iVar4);
          pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar5)
          ;
        } while (((pCVar6 == (CObject *)0x0) || ((*(uint *)(pCVar5 + 0x24) & 0x40000) != 0)) &&
                (iVar4 = iVar4 + 1, iVar4 != local_8));
        AVar7 = DAT_00a139d8;
        if (iVar4 != local_8) {
          AVar7 = CMFCPopupMenu::GetAnimationType(0);
          DAT_00a139d8 = 0;
          pcVar1 = *(code **)(*in_ECX + 0x3b0);
          guard_check_icall(iVar4);
          (*pcVar1)();
          if (-1 < in_ECX[0x2fe]) {
            pCVar5 = (CObject *)FUN_007fde79(in_ECX[0x2fe]);
            pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,
                                        pCVar5);
            if (pCVar5 != (CObject *)0x0) {
              pcVar1 = *(code **)(*(int *)pCVar5 + 0x70);
              guard_check_icall(iVar4);
              iVar4 = (*pcVar1)();
              if (iVar4 != 0) {
                SendMessageW(*(HWND *)(*(int *)(pCVar5 + 0x8c) + 0x20),0x100,0x24,0);
              }
            }
          }
        }
      }
      DAT_00a139d8 = AVar7;
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCColorBar[247], CMFCDropDownToolBar[247], CMFCImageEditorPaletteBar[247], CMFCMenuBar[247], CMFCOutlookBarPane[247], CMFCOutlookBarToolBar[247], CMFCPopupMenuBar[247], CMFCPrintPreviewToolBar[247], CMFCRibbonPanelMenuBar[247], CMFCTasksPaneToolBar[247], CMFCToolBar[247] */
/* 007ff59b  FUN_007ff59b  96 bytes, 0 callers */

undefined4 FUN_007ff59b(int *param_1,int param_2,int param_3,undefined4 param_4,LPARAM param_5)

{
  code *pcVar1;
  int iVar2;
  CWnd *pCVar3;
  CWnd *in_ECX;
  
  if (param_2 == 0) {
    pcVar1 = *(code **)(*param_1 + 0x40);
    guard_check_icall(param_3);
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      return 0;
    }
  }
  pCVar3 = CWnd::GetOwner(in_ECX);
  PostMessageW(*(HWND *)(pCVar3 + 0x20),0x111,param_3 << 0x10 | (uint)*(ushort *)(param_1 + 8),
               param_5);
  return 1;
}




/* vtable slots: CMFCColorBar[191], CMFCDropDownToolBar[191], CMFCImageEditorPaletteBar[191], CMFCMenuBar[191], CMFCOutlookBarPane[191], CMFCOutlookBarToolBar[191], CMFCPopupMenuBar[191], CMFCPrintPreviewToolBar[191], CMFCRibbonPanelMenuBar[191], CMFCTasksPaneToolBar[191], CMFCToolBar[191] */
/* 007ff644  FUN_007ff644  122 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007ff644(void)

{
  HWND pHVar1;
  CWnd *this;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(in_ECX + 0xb98) = 0;
  pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
  this = CWnd::FromHandle(pHVar1);
  if (this != (CWnd *)0x0) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
    CWnd::ScreenToClient(this,&local_18);
    RedrawWindow(*(HWND *)(this + 0x20),&local_18,(HRGN)0x0,0x105);
  }
  return;
}




/* vtable slots: CMFCColorBar[177], CMFCDropDownToolBar[177], CMFCImageEditorPaletteBar[177], CMFCMenuBar[177], CMFCOutlookBarPane[177], CMFCOutlookBarToolBar[177], CMFCPopupMenuBar[177], CMFCPrintPreviewToolBar[177], CMFCRibbonPanelMenuBar[177], CMFCTasksPaneToolBar[177], CMFCToolBar[177] */
/* 007ff6be  FUN_007ff6be  110 bytes, 0 callers */

void FUN_007ff6be(void)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 uVar3;
  undefined1 local_c [8];
  
  FUN_007f0afc();
  pcVar1 = *(code **)(*in_ECX + 0x208);
  guard_check_icall(local_c,in_ECX[0x4f],0);
  (*pcVar1)();
  uVar3 = 0;
  pcVar1 = *(code **)(*in_ECX + 0x228);
  guard_check_icall(0);
  piVar2 = (int *)(*pcVar1)();
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 0x1b4);
    guard_check_icall(uVar3);
    (*pcVar1)();
  }
  in_ECX[0x2e6] = 1;
  return;
}




/* vtable slots: CMFCColorBar[135], CMFCDropDownToolBar[135], CMFCImageEditorPaletteBar[135], CMFCMenuBar[135], CMFCOutlookBarPane[135], CMFCOutlookBarToolBar[135], CMFCPopupMenuBar[135], CMFCPrintPreviewToolBar[135], CMFCRibbonPanelMenuBar[135], CMFCTasksPaneToolBar[135], CMFCToolBar[135] */
/* 007ff72c  OnBeforeChangeParent  58 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBar::OnBeforeChangeParent(class CWnd *,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCToolBar::OnBeforeChangeParent(CMFCToolBar *this,CWnd *param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_007f0b6a(param_1,param_2);
  if (param_1 != (CWnd *)0x0) {
    iVar1 = FUN_0079d98a(&PTR_s_CPaneFrameWnd_00a008b0);
    if (iVar1 != 0) {
      uVar2 = 1;
      goto LAB_007ff75b;
    }
  }
  uVar2 = 0;
LAB_007ff75b:
  *(undefined4 *)(this + 0xb98) = uVar2;
  return;
}




/* vtable slots: CMFCColorBar[237], CMFCDropDownToolBar[237], CMFCImageEditorPaletteBar[237], CMFCMenuBar[237], CMFCOutlookBarPane[237], CMFCOutlookBarToolBar[237], CMFCPopupMenuBar[237], CMFCPrintPreviewToolBar[237], CMFCRibbonPanelMenuBar[237], CMFCTasksPaneToolBar[237], CMFCToolBar[237] */
/* 007fffe0  FUN_007fffe0  129 bytes, 0 callers */

void FUN_007fffe0(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  CMFCToolBar *in_ECX;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0xbc);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  *(int *)(in_ECX + 0xbd8) = iVar3;
  if (iVar3 == 0) {
    SetWindowRgn(*(HWND *)(in_ECX + 0x20),(HRGN)0x0,0);
  }
  else {
    FUN_00805579();
  }
  if (*(int *)(in_ECX + 0xb78) == 0) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x16c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      pcVar1 = *(code **)(*(int *)in_ECX + 0x2d4);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  CMFCToolBar::UpdateImagesColor(in_ECX);
  return;
}




/* vtable slots: CMFCColorBar[61], CMFCDropDownToolBar[61], CMFCImageEditorPaletteBar[61], CMFCMenuBar[61], CMFCOutlookBarPane[61], CMFCOutlookBarToolBar[61], CMFCPopupMenuBar[61], CMFCPrintPreviewToolBar[61], CMFCRibbonPanelMenuBar[61], CMFCTasksPaneToolBar[61], CMFCToolBar[61] */
/* 00800061  FUN_00800061  263 bytes, 0 callers */

undefined4 FUN_00800061(uint param_1,HWND param_2)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  HWND hWnd;
  undefined4 *puVar4;
  HWND hWndParent;
  BOOL BVar5;
  int iVar6;
  int *in_ECX;
  undefined4 local_10;
  uint local_c;
  int local_8;
  
  if ((DAT_00a127ac != 0) && (in_ECX[0x2de] == 0)) {
    uVar3 = FUN_00793275(param_1,param_2);
    return uVar3;
  }
  local_c = param_1 >> 0x10;
  local_10 = 0;
  hWnd = param_2;
  if (param_2 == (HWND)0x0) {
    if (param_1 == 2) {
      pcVar1 = *(code **)(*in_ECX + 0x364);
      guard_check_icall();
      (*pcVar1)();
      return 1;
    }
    if (param_1 != 1) {
      return 0;
    }
    hWnd = GetFocus();
    if (hWnd == (HWND)0x0) {
      return 0;
    }
    local_10 = 1;
    local_c = 0;
  }
  local_8 = in_ECX[0x310];
  do {
    if (local_8 == 0) {
      return 0;
    }
    puVar4 = (undefined4 *)FUN_0044f2d0(&local_8);
    piVar2 = (int *)*puVar4;
    pcVar1 = *(code **)(*piVar2 + 0x38);
    guard_check_icall();
    hWndParent = (HWND)(*pcVar1)();
  } while ((hWndParent == (HWND)0x0) ||
          ((hWndParent != hWnd && (BVar5 = IsChild(hWndParent,hWnd), BVar5 == 0))));
  pcVar1 = *(code **)(*in_ECX + 0x3dc);
  guard_check_icall(piVar2,local_10,local_c,param_1,param_2);
  iVar6 = (*pcVar1)();
  if (iVar6 != 0) {
    return 1;
  }
  return 0;
}




/* vtable slots: CMFCColorBar[257], CMFCDropDownToolBar[257], CMFCImageEditorPaletteBar[257], CMFCMenuBar[257], CMFCOutlookBarPane[257], CMFCPopupMenuBar[257], CMFCPrintPreviewToolBar[257], CMFCRibbonPanelMenuBar[257], CMFCTasksPaneToolBar[257], CMFCToolBar[257] */
/* 008006cc  FUN_008006cc  137 bytes, 1 callers */

void FUN_008006cc(int param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0xc40);
  *(undefined4 *)(in_ECX + 0xbec) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xbf0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xbf4) = 0xffffffff;
  while( true ) {
    if (local_8 == 0) {
      return;
    }
    piVar2 = (int *)FUN_0044f2d0(&local_8);
    piVar2 = (int *)*piVar2;
    if (piVar2 == (int *)0x0) break;
    pcVar1 = *(code **)(*piVar2 + 0x58);
    guard_check_icall();
    (*pcVar1)();
    if ((piVar2[9] & 0x40000U) == 0) {
      pcVar1 = *(code **)(*piVar2 + 0x98);
      guard_check_icall(param_1 == 0);
      (*pcVar1)();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCColorBar[244], CMFCDropDownToolBar[244], CMFCImageEditorPaletteBar[244], CMFCMenuBar[244], CMFCOutlookBarPane[244], CMFCOutlookBarToolBar[244], CMFCPopupMenuBar[244], CMFCPrintPreviewToolBar[244], CMFCRibbonPanelMenuBar[244], CMFCTasksPaneToolBar[244], CMFCToolBar[244] */
/* 008007d3  FUN_008007d3  72 bytes, 0 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008007d3(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (in_ECX[0x2ee] == 0) {
    in_ECX[0x300] = -1;
    _DAT_00a12868 = 0;
    pcVar1 = *(code **)(*in_ECX + 0x3d8);
    guard_check_icall(param_1,param_2,param_3,param_4);
    uVar2 = (*pcVar1)();
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCColorBar[245], CMFCDropDownToolBar[245], CMFCImageEditorPaletteBar[245], CMFCMenuBar[245], CMFCOutlookBarPane[245], CMFCOutlookBarToolBar[245], CMFCPopupMenuBar[245], CMFCPrintPreviewToolBar[245], CMFCRibbonPanelMenuBar[245], CMFCTasksPaneToolBar[245], CMFCToolBar[245] */
/* 0080081b  FUN_0080081b  133 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0080081b(void)

{
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 3000) == 0) {
    *(undefined4 *)(in_ECX + 0xc00) = 0xffffffff;
    local_18.left = ((LPRECT)(in_ECX + 0xccc))->left;
    local_18.top = *(LONG *)(in_ECX + 0xcd0);
    local_18.right = *(LONG *)(in_ECX + 0xcd4);
    local_18.bottom = *(LONG *)(in_ECX + 0xcd8);
    InflateRect(&local_18,2,2);
    InvalidateRect(*(HWND *)(in_ECX + 0x20),&local_18,1);
    UpdateWindow(*(HWND *)(in_ECX + 0x20));
    SetRectEmpty((LPRECT)(in_ECX + 0xccc));
    *(undefined4 *)(in_ECX + 0xc00) = 0xffffffff;
    _DAT_00a12868 = 1;
  }
  return;
}




/* vtable slots: CMFCColorBar[243], CMFCDropDownToolBar[243], CMFCImageEditorPaletteBar[243], CMFCMenuBar[243], CMFCOutlookBarPane[243], CMFCOutlookBarToolBar[243], CMFCPopupMenuBar[243], CMFCPrintPreviewToolBar[243], CMFCRibbonPanelMenuBar[243], CMFCTasksPaneToolBar[243], CMFCToolBar[243] */
/* 00800a4f  FUN_00800a4f  624 bytes, 0 callers */

undefined4 FUN_00800a4f(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  CObject *pCVar6;
  int *in_ECX;
  int iVar7;
  code *pcVar8;
  int *piVar9;
  
  if (in_ECX[0x2ee] != 0) {
    return 0;
  }
  iVar7 = in_ECX[0x300];
  if (iVar7 < 0) {
    return 0;
  }
  iVar3 = in_ECX[0x343];
  in_ECX[0x343] = 0;
  pcVar8 = *(code **)(*in_ECX + 0x3d4);
  guard_check_icall();
  (*pcVar8)();
  pcVar8 = *(code **)(*in_ECX + 0x390);
  guard_check_icall(param_3,param_4);
  iVar1 = (*pcVar8)();
  if ((-1 < iVar1) && (iVar1 = FUN_007fde79(iVar1), iVar3 == iVar1)) {
    return 0;
  }
  pcVar8 = *(code **)(*in_ECX + 0x3fc);
  guard_check_icall(param_1);
  piVar2 = (int *)(*pcVar8)();
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  pcVar8 = *(code **)(*piVar2 + 0x78);
  guard_check_icall();
  iVar1 = (*pcVar8)();
  if (iVar1 == 0) {
    pcVar8 = *(code **)(*piVar2 + 4);
LAB_00800b09:
    guard_check_icall(1);
    (*pcVar8)();
  }
  else {
    piVar2[7] = 0;
    if ((iVar3 != 0) && (param_2 != 1)) {
      iVar1 = FUN_007fc033(iVar3);
      if ((iVar7 == iVar1) || (iVar7 == iVar1 + 1)) {
        pcVar8 = *(code **)(*in_ECX + 0x414);
        guard_check_icall(iVar3,in_ECX + 0x33d,&param_3);
        (*pcVar8)();
        pcVar8 = *(code **)(*piVar2 + 4);
        goto LAB_00800b09;
      }
      pcVar8 = *(code **)(*in_ECX + 0x34c);
      guard_check_icall(iVar1);
      (*pcVar8)();
      if (iVar1 < iVar7) {
        iVar7 = iVar7 + -1;
      }
      if (in_ECX[0x312] <= iVar7) {
        iVar7 = in_ECX[0x312];
      }
    }
    pcVar8 = *(code **)(*in_ECX + 0x340);
    piVar9 = piVar2;
    guard_check_icall(piVar2,iVar7);
    iVar3 = (*pcVar8)();
    if (iVar3 == -1) {
      pcVar8 = *(code **)(*piVar2 + 4);
      guard_check_icall(1);
      (*pcVar8)();
      return 0;
    }
    pcVar8 = *(code **)(*in_ECX + 0x20c);
    guard_check_icall(piVar9,iVar7);
    (*pcVar8)();
    pHVar4 = GetParent((HWND)in_ECX[8]);
    CWnd::FromHandle(pHVar4);
    iVar7 = FUN_0079d98a(&PTR_s_CMFCTabCtrl_0098d8b8);
    if (iVar7 != 0) {
      pHVar4 = GetParent((HWND)in_ECX[8]);
      pCVar5 = CWnd::FromHandle(pHVar4);
      pHVar4 = GetParent(*(HWND *)(pCVar5 + 0x20));
      pCVar5 = CWnd::FromHandle(pHVar4);
      pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,(CObject *)pCVar5);
      if (pCVar6 != (CObject *)0x0) {
        pcVar8 = *(code **)(*(int *)pCVar6 + 0x210);
        guard_check_icall();
        (*pcVar8)();
      }
    }
    if (DAT_00a127b0 != 0) {
      pcVar8 = *(code **)(*piVar2 + 0x80);
      guard_check_icall();
      (*pcVar8)();
    }
    in_ECX[0x2fd] = -1;
    RedrawWindow((HWND)in_ECX[8],(RECT *)0x0,(HRGN)0x0,0x505);
    pHVar4 = GetParent((HWND)in_ECX[8]);
    pCVar5 = CWnd::FromHandle(pHVar4);
    pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar5);
    if (pCVar6 != (CObject *)0x0) {
      RedrawWindow(*(HWND *)(pCVar6 + 0x20),(RECT *)0x0,(HRGN)0x0,0x505);
    }
  }
  return 1;
}




/* vtable slots: CMFCColorBar[234], CMFCDropDownToolBar[234], CMFCImageEditorPaletteBar[234], CMFCMenuBar[234], CMFCOutlookBarPane[234], CMFCOutlookBarToolBar[234], CMFCPopupMenuBar[234], CMFCPrintPreviewToolBar[234], CMFCRibbonPanelMenuBar[234], CMFCTasksPaneToolBar[234], CMFCToolBar[234] */
/* 00800d6f  FUN_00800d6f  76 bytes, 0 callers */

void FUN_00800d6f(void)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  int local_8;
  
  local_8 = *(int *)(in_ECX + 0xc40);
  while( true ) {
    if (local_8 == 0) {
      return;
    }
    piVar2 = (int *)FUN_0044f2d0(&local_8);
    if ((int *)*piVar2 == (int *)0x0) break;
    pcVar1 = *(code **)(*(int *)*piVar2 + 0x5c);
    guard_check_icall();
    (*pcVar1)();
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCColorBar[149], CMFCDropDownToolBar[149], CMFCImageEditorPaletteBar[149], CMFCMenuBar[149], CMFCOutlookBarPane[149], CMFCOutlookBarToolBar[149], CMFCPopupMenuBar[149], CMFCPrintPreviewToolBar[149], CMFCTasksPaneToolBar[149], CMFCToolBar[149] */
/* 0080265d  FUN_0080265d  73 bytes, 0 callers */

bool FUN_0080265d(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  
  FUN_007ed2e1();
  piVar2 = (int *)FUN_007fb1c0(param_1);
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 0xb8);
    guard_check_icall();
    (*pcVar1)();
  }
  return piVar2 != (int *)0x0;
}




/* vtable slots: CMFCColorBar[230], CMFCDropDownToolBar[230], CMFCImageEditorPaletteBar[230], CMFCMenuBar[230], CMFCOutlookBarPane[230], CMFCOutlookBarToolBar[230], CMFCPopupMenuBar[230], CMFCPrintPreviewToolBar[230], CMFCRibbonPanelMenuBar[230], CMFCTasksPaneToolBar[230], CMFCToolBar[230] */
/* 008037d4  FUN_008037d4  299 bytes, 0 callers */

undefined4 FUN_008037d4(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  CObject *pCVar5;
  CObject *pCVar6;
  ANIMATION_TYPE AVar7;
  int *in_ECX;
  int local_8;
  
  piVar3 = (int *)FUN_007fdf83(&local_8);
  if (piVar3 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar3 + 0xec);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      iVar2 = in_ECX[0x312];
      iVar4 = local_8 + -1;
      AVar7 = DAT_00a139d8;
      if (iVar4 != local_8) {
        do {
          if (iVar4 < 0) {
            iVar4 = iVar2 + -1;
          }
          pCVar5 = (CObject *)FUN_007fde79(iVar4);
          pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar5)
          ;
        } while (((pCVar6 == (CObject *)0x0) || ((*(uint *)(pCVar5 + 0x24) & 0x40000) != 0)) &&
                (iVar4 = iVar4 + -1, iVar4 != local_8));
        AVar7 = DAT_00a139d8;
        if (iVar4 != local_8) {
          AVar7 = CMFCPopupMenu::GetAnimationType(0);
          DAT_00a139d8 = 0;
          pcVar1 = *(code **)(*in_ECX + 0x3b0);
          guard_check_icall(iVar4);
          (*pcVar1)();
          if (-1 < in_ECX[0x2fe]) {
            pCVar5 = (CObject *)FUN_007fde79(in_ECX[0x2fe]);
            pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,
                                        pCVar5);
            if (pCVar5 != (CObject *)0x0) {
              pcVar1 = *(code **)(*(int *)pCVar5 + 0x70);
              guard_check_icall(iVar4);
              iVar4 = (*pcVar1)();
              if (iVar4 != 0) {
                SendMessageW(*(HWND *)(*(int *)(pCVar5 + 0x8c) + 0x20),0x100,0x24,0);
              }
            }
          }
        }
      }
      DAT_00a139d8 = AVar7;
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCColorBar[212], CMFCDropDownToolBar[212], CMFCImageEditorPaletteBar[212], CMFCMenuBar[212], CMFCOutlookBarToolBar[212], CMFCPopupMenuBar[212], CMFCPrintPreviewToolBar[212], CMFCRibbonPanelMenuBar[212], CMFCTasksPaneToolBar[212], CMFCToolBar[212] */
/* 00803b44  FUN_00803b44  116 bytes, 2 callers */

void FUN_00803b44(void)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xbec) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xbf0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xbf4) = 0xffffffff;
  iVar1 = *(int *)(in_ECX + 0xc48);
  while (iVar1 != 0) {
    piVar3 = (int *)FUN_007a1b17();
    if (piVar3 != (int *)0x0) {
      pcVar2 = *(code **)(*piVar3 + 0x58);
      guard_check_icall();
      (*pcVar2)();
      pcVar2 = *(code **)(*piVar3 + 4);
      guard_check_icall(1);
      (*pcVar2)();
    }
    iVar1 = *(int *)(in_ECX + 0xc48);
  }
  *(undefined4 *)(in_ECX + 0xd14) = 0;
  return;
}




/* vtable slots: CMFCColorBar[211], CMFCDropDownToolBar[211], CMFCImageEditorPaletteBar[211], CMFCMenuBar[211], CMFCOutlookBarPane[211], CMFCOutlookBarToolBar[211], CMFCPopupMenuBar[211], CMFCPrintPreviewToolBar[211], CMFCRibbonPanelMenuBar[211], CMFCTasksPaneToolBar[211], CMFCToolBar[211] */
/* 00803bb8  FUN_00803bb8  453 bytes, 0 callers */

undefined4 FUN_00803bb8(int param_1)

{
  code *pcVar1;
  __POSITION *p_Var2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  int iVar5;
  int local_8;
  
  p_Var2 = CObList::FindIndex((CObList *)(in_ECX + 0x30f),param_1);
  if ((p_Var2 == (__POSITION *)0x0) || ((param_1 == in_ECX[0x312] + -1 && (in_ECX[0x345] != 0)))) {
    return 0;
  }
  piVar3 = *(int **)(p_Var2 + 8);
  FUN_007a1ad4(p_Var2);
  pcVar1 = *(code **)(*piVar3 + 0x58);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*piVar3 + 4);
  guard_check_icall(1);
  (*pcVar1)();
  iVar5 = in_ECX[0x2fd];
  if (param_1 == iVar5) {
    in_ECX[0x2fd] = -1;
  }
  else if ((param_1 < iVar5) && (-1 < iVar5)) {
    in_ECX[0x2fd] = iVar5 + -1;
  }
  iVar5 = in_ECX[0x2fb];
  if (param_1 == iVar5) {
    in_ECX[0x2fb] = -1;
  }
  else if ((param_1 < iVar5) && (-1 < iVar5)) {
    in_ECX[0x2fb] = iVar5 + -1;
  }
  iVar5 = in_ECX[0x2fc];
  if (param_1 == iVar5) {
    in_ECX[0x2fc] = -1;
    iVar5 = -1;
  }
  else {
    if ((iVar5 <= param_1) || (iVar5 < 0)) goto LAB_00803ca6;
    iVar5 = iVar5 + -1;
    in_ECX[0x2fc] = iVar5;
  }
  pcVar1 = *(code **)(*in_ECX + 0x3b0);
  guard_check_icall(iVar5);
  (*pcVar1)();
LAB_00803ca6:
  local_8 = in_ECX[0x311];
  if (local_8 != 0) {
    if (in_ECX[0x345] == *(int *)(local_8 + 8)) {
      FUN_0049ad10(&local_8);
    }
    iVar5 = local_8;
    if (local_8 != 0) {
      while( true ) {
        piVar3 = (int *)FUN_0049ad10(&local_8);
        iVar4 = local_8;
        piVar3 = (int *)*piVar3;
        if ((local_8 == 0) || ((*(byte *)(piVar3 + 9) & 1) == 0)) break;
        FUN_007a1ad4(iVar5);
        pcVar1 = *(code **)(*piVar3 + 4);
        guard_check_icall(1);
        (*pcVar1)();
        iVar5 = iVar4;
      }
    }
  }
  if ((0 < param_1) && (param_1 < in_ECX[0x312])) {
    iVar5 = FUN_007fde79(param_1 + -1);
    iVar4 = FUN_007fde79(param_1);
    if (((*(byte *)(iVar5 + 0x24) & 1) != 0) && ((*(byte *)(iVar4 + 0x24) & 1) != 0)) {
      pcVar1 = *(code **)(*in_ECX + 0x34c);
      guard_check_icall(param_1);
      (*pcVar1)();
    }
  }
  FUN_00803951();
  return 1;
}




/* vtable slots: CMFCColorBar[224], CMFCDropDownToolBar[224], CMFCImageEditorPaletteBar[224], CMFCMenuBar[224], CMFCOutlookBarPane[224], CMFCOutlookBarToolBar[224], CMFCPopupMenuBar[224], CMFCPrintPreviewToolBar[224], CMFCRibbonPanelMenuBar[224], CMFCTasksPaneToolBar[224], CMFCToolBar[224] */
/* 00803def  FUN_00803def  222 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x00803e9c) */

undefined4 FUN_00803def(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int *piVar2;
  undefined4 local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x803dfb;
  FUN_008592c1(&local_18,L"MFCToolBars",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(local_14,L"%TsMFCToolBar-%d",local_18,param_2);
  }
  else {
    FUN_004059f0(local_14,L"%TsMFCToolBar-%d%x",local_18,param_2,param_3);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar2 = (int *)FUN_00859490(0,0);
  pcVar1 = *(code **)(*piVar2 + 0x1c);
  guard_check_icall(local_14[0],0);
  local_14[0] = (*pcVar1)();
  FUN_00406b10();
  FUN_00406b10();
  return local_14[0];
}




/* vtable slots: CMFCColorBar[202], CMFCDropDownToolBar[202], CMFCImageEditorPaletteBar[202], CMFCOutlookBarPane[202], CMFCOutlookBarToolBar[202], CMFCPopupMenuBar[202], CMFCPrintPreviewToolBar[202], CMFCRibbonPanelMenuBar[202], CMFCTasksPaneToolBar[202], CMFCToolBar[202] */
/* 00803ecd  FUN_00803ecd  135 bytes, 1 callers */

void FUN_00803ecd(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int *in_ECX;
  int local_8;
  
  if (in_ECX[0x2de] == 0) {
    local_8 = in_ECX[0x310];
    while (local_8 != 0) {
      puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x90);
      guard_check_icall();
      (*pcVar1)();
    }
    pcVar1 = *(code **)(*in_ECX + 0x170);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x20c);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCColorBar[217], CMFCDropDownToolBar[217], CMFCImageEditorPaletteBar[217], CMFCMenuBar[217], CMFCOutlookBarPane[217], CMFCOutlookBarToolBar[217], CMFCPopupMenuBar[217], CMFCPrintPreviewToolBar[217], CMFCRibbonPanelMenuBar[217], CMFCTasksPaneToolBar[217], CMFCToolBar[217] */
/* 00803f54  RestoreFocus  95 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCToolBar::RestoreFocus(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCToolBar::RestoreFocus(CMFCToolBar *this)

{
  BOOL BVar1;
  int iVar2;
  
  BVar1 = IsWindow(*(HWND *)(this + 0xd1c));
  if (BVar1 != 0) {
    SetFocus(*(HWND *)(this + 0xd1c));
  }
  *(undefined4 *)(this + 0xd1c) = 0;
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0x1a0) != 0) {
    iVar2 = FUN_007c2511();
    if ((*(int *)(iVar2 + 0x1a4) == 0) && (DAT_00a127ac == 0)) {
      iVar2 = FUN_007c2511();
      *(undefined4 *)(iVar2 + 0x1a0) = 0;
      FUN_00803a81();
      return;
    }
  }
  return;
}




/* vtable slots: CMFCColorBar[226], CMFCDropDownToolBar[226], CMFCImageEditorPaletteBar[226], CMFCOutlookBarToolBar[226], CMFCPopupMenuBar[226], CMFCPrintPreviewToolBar[226], CMFCRibbonPanelMenuBar[226], CMFCTasksPaneToolBar[226], CMFCToolBar[226] */
/* 00803fb3  FUN_00803fb3  404 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00803fb3(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x346] == 0) {
    uVar2 = 0;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x330);
    local_1c = in_ECX;
    guard_check_icall(in_ECX[0x346],0,0,0,0,0,0);
    uVar2 = (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x20c);
    guard_check_icall();
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x170);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      if (in_ECX[0x2e] != 0) {
        iVar3 = *in_ECX;
        pcVar1 = *(code **)(iVar3 + 0x164);
        guard_check_icall();
        uVar4 = (*pcVar1)();
        pcVar1 = *(code **)(iVar3 + 0x260);
        guard_check_icall(&local_24,0,uVar4);
        piVar5 = local_1c;
        (*pcVar1)();
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        GetWindowRect((HWND)piVar5[8],&local_18);
        iVar3 = FUN_004208d0(local_24,local_20);
        if (iVar3 != 0) {
          pcVar1 = *(code **)(*piVar5 + 0x238);
          guard_check_icall(0,0,0,local_24,local_20,0x16,0);
          (*pcVar1)();
          FUN_007f2322();
        }
        pcVar1 = *(code **)(*(int *)piVar5[0x2f] + 0x28);
        guard_check_icall(local_1c);
        (*pcVar1)();
        piVar5 = (int *)FUN_007e5618(local_1c);
        pcVar1 = *(code **)(*piVar5 + 0x178);
        guard_check_icall(1);
        (*pcVar1)();
        in_ECX = local_1c;
      }
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x210);
      guard_check_icall();
      (*pcVar1)();
    }
    RedrawWindow((HWND)in_ECX[8],(RECT *)0x0,(HRGN)0x0,0x505);
  }
  return uVar2;
}




/* vtable slots: CMFCColorBar[266], CMFCDropDownToolBar[266], CMFCImageEditorPaletteBar[266], CMFCMenuBar[266], CMFCOutlookBarPane[266], CMFCOutlookBarToolBar[266], CMFCPopupMenuBar[266], CMFCPrintPreviewToolBar[266], CMFCRibbonPanelMenuBar[266], CMFCTasksPaneToolBar[266], CMFCToolBar[266] */
/* 00804147  FUN_00804147  52 bytes, 0 callers */

void FUN_00804147(int *param_1)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc64) != 0) {
    pcVar1 = *(code **)(*param_1 + 0x24);
    guard_check_icall(L"OriginalItems",in_ECX + 0xc58);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCColorBar[140], CMFCDropDownToolBar[140], CMFCImageEditorPaletteBar[140], CMFCOutlookBarPane[140], CMFCPopupMenuBar[140], CMFCPrintPreviewToolBar[140], CMFCRibbonPanelMenuBar[140], CMFCTasksPaneToolBar[140], CMFCToolBar[140] */
/* 008041af  FUN_008041af  544 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_008041af(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  int iVar4;
  CObject *pCVar5;
  int *in_ECX;
  undefined8 uVar6;
  undefined1 local_b0 [72];
  undefined1 local_68 [52];
  undefined4 local_34;
  int *local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa0;
  local_8 = 0x8041be;
  FUN_008592c1(&local_24,L"MFCToolBars",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(&local_1c,L"%TsMFCToolBar-%d",local_24,param_2);
  }
  else {
    FUN_004059f0(&local_1c,L"%TsMFCToolBar-%d%x",local_24,param_2,param_3);
  }
  local_8._0_1_ = 2;
  FUN_007b57a7(0x400);
  local_8._0_1_ = 3;
  FUN_007a6256(local_68,0,0x1000,0);
  local_8._0_1_ = 4;
  pcVar1 = *(code **)(*in_ECX + 8);
  guard_check_icall(local_b0);
  (*pcVar1)();
  FUN_007a67a4();
  local_8._0_1_ = 3;
  FUN_007a6389();
  uVar6 = FUN_007b5a11();
  local_2c = (undefined4)((ulonglong)uVar6 >> 0x20);
  local_34 = (undefined4)uVar6;
  local_28 = FUN_007b592a();
  if (local_28 != 0) {
    local_30 = (int *)0x0;
    local_2c = 0;
    local_8._0_1_ = 5;
    local_18 = (int *)FUN_00859490(0,0);
    pcVar1 = *(code **)(*local_18 + 0xc);
    guard_check_icall(local_1c);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      BVar3 = IsWindow((HWND)in_ECX[8]);
      if (BVar3 != 0) {
        CStringT<>();
        local_8._0_1_ = 6;
        FUN_00792c64(&local_20);
        pcVar1 = *(code **)(*local_18 + 0x30);
        guard_check_icall(L"Name",local_20);
        (*pcVar1)();
        local_8._0_1_ = 5;
        FUN_00406b10();
      }
      pcVar1 = *(code **)(*local_18 + 0x28);
      guard_check_icall(L"Buttons",local_28,local_34);
      iVar2 = (*pcVar1)();
      iVar4 = FUN_0079dd6d();
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CWinAppEx_0098fd18,
                                  *(CObject **)(iVar4 + 4));
      if (((iVar2 != 0) && (pCVar5 != (CObject *)0x0)) && (*(int *)(pCVar5 + 0x10c) != 0)) {
        pcVar1 = *(code **)(*in_ECX + 0x428);
        guard_check_icall(local_18);
        (*pcVar1)();
      }
      FUN_0080417b(local_18);
    }
    FUN_008f43b0(local_28);
    if (local_30 != (int *)0x0) {
      pcVar1 = *(code **)(*local_30 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  FUN_007b583b();
  FUN_008043e3();
  return;
}




/* vtable slots: CMFCColorBar[207], CMFCDropDownToolBar[207], CMFCImageEditorPaletteBar[207], CMFCMenuBar[207], CMFCOutlookBarPane[207], CMFCOutlookBarToolBar[207], CMFCPopupMenuBar[207], CMFCPrintPreviewToolBar[207], CMFCRibbonPanelMenuBar[207], CMFCTasksPaneToolBar[207], CMFCToolBar[207] */
/* 008048b6  FUN_008048b6  1087 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008048b6(undefined4 *param_1,int param_2,int param_3)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  CObject *pCVar4;
  undefined4 uVar5;
  HWND pHVar6;
  CWnd *pCVar7;
  int *piVar8;
  int *in_ECX;
  CObject *local_98;
  int local_94;
  int local_90;
  int *local_8c;
  char local_85;
  CMFCToolBarButton local_84 [124];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x94;
  local_8 = 0x8048c5;
  local_94 = 0;
  if ((param_1 != (undefined4 *)0x0) && (iVar3 = FUN_007c10fe(param_1,param_2 << 2,0), iVar3 == 0))
  {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  local_8c = (int *)in_ECX[0x345];
  local_98 = (CObject *)0x0;
  if (local_8c != (int *)0x0) {
    pcVar1 = *(code **)*local_8c;
    guard_check_icall();
    (*pcVar1)();
    pCVar4 = (CObject *)FUN_0079d90c();
    local_98 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeButton_00a00ac4,pCVar4);
    pcVar1 = *(code **)(*(int *)local_98 + 0x14);
    guard_check_icall(in_ECX[0x345]);
    (*pcVar1)();
  }
  pcVar1 = *(code **)(*in_ECX + 0x350);
  guard_check_icall();
  (*pcVar1)();
  while (in_ECX[0x319] != 0) {
    local_8c = (int *)FUN_007a1b17();
    if (local_8c != (int *)0x0) {
      pcVar1 = *(code **)(*local_8c + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  if (param_1 == (undefined4 *)0x0) {
    for (; 0 < param_2; param_2 = param_2 + -1) {
      pcVar1 = *(code **)(*in_ECX + 0x348);
      guard_check_icall(0xffffffff);
      (*pcVar1)();
    }
  }
  else {
    local_94 = in_ECX[0x301];
    local_90 = local_94;
    if (0 < param_2) {
      do {
        piVar8 = (int *)*param_1;
        param_1 = param_1 + 1;
        local_8c = piVar8;
        iVar3 = FUN_0078e624(0x70);
        local_8 = 0;
        if (iVar3 == 0) {
          pCVar4 = (CObject *)0x0;
        }
        else {
          pCVar4 = (CObject *)FUN_00880d51(piVar8,0xffffffff,0,0,0);
        }
        local_8 = 0xffffffff;
        CObList::AddTail((CObList *)(in_ECX + 0x316),pCVar4);
        if (piVar8 == (int *)0x0) {
          pcVar1 = *(code **)(*in_ECX + 0x348);
          guard_check_icall(0xffffffff);
          (*pcVar1)();
        }
        else if (param_3 == 0) {
          iVar3 = CMap<unsigned_int,unsigned_int,int,int>::Lookup
                            ((CMap<unsigned_int,unsigned_int,int,int> *)&PTR_vftable_00a005f4,
                             (uint)piVar8,&local_94);
          if (iVar3 == 0) {
            local_90 = local_94;
          }
          else {
            pcVar1 = *(code **)(*in_ECX + 0x344);
            local_90 = local_94;
            uVar5 = FUN_00880d51(local_8c,local_94,0,0,in_ECX[0x2de]);
            local_8 = 2;
            guard_check_icall(uVar5,0xffffffff);
            (*pcVar1)();
            local_8 = 0xffffffff;
            CMFCToolBarButton::~CMFCToolBarButton(local_84);
          }
        }
        else {
          pcVar1 = *(code **)(*in_ECX + 0x344);
          uVar5 = FUN_00880d51(local_8c,local_90,0,0,in_ECX[0x2de]);
          local_94 = 1;
          local_8 = 1;
          guard_check_icall(uVar5,0xffffffff);
          iVar3 = (*pcVar1)();
          if ((iVar3 < 0) || (local_85 = '\x01', in_ECX[0x2de] != 0)) {
            local_85 = '\0';
          }
          local_8 = 0xffffffff;
          CMFCToolBarButton::~CMFCToolBarButton(local_84);
          if (local_85 != '\0') {
            piVar8 = (int *)FUN_007e3332(local_8c);
            *piVar8 = local_90;
          }
          local_94 = local_90 + 1;
          local_90 = local_94;
        }
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
    pCVar4 = local_98;
    if (local_98 != (CObject *)0x0) {
      pcVar1 = *(code **)(*in_ECX + 0x340);
      guard_check_icall(local_98,0xffffffff);
      (*pcVar1)();
      in_ECX[0x345] = (int)pCVar4;
    }
    if (in_ECX[8] != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x38c);
      guard_check_icall();
      (*pcVar1)();
      pCVar7 = (CWnd *)in_ECX[0x29];
      if (pCVar7 == (CWnd *)0x0) {
        pHVar6 = GetParent((HWND)in_ECX[8]);
        pCVar7 = CWnd::FromHandle(pHVar6);
        if (pCVar7 == (CWnd *)0x0) goto LAB_00804ce5;
      }
      SendMessageW(*(HWND *)(pCVar7 + 0x20),DAT_00a127d0,in_ECX[0x346],0);
      iVar3 = in_ECX[800];
      while (iVar3 != 0) {
        piVar8 = (int *)FUN_007a1b17();
        if (piVar8 != (int *)0x0) {
          pcVar1 = *(code **)(*piVar8 + 4);
          guard_check_icall(1);
          (*pcVar1)();
        }
        iVar3 = in_ECX[800];
      }
      local_98 = (CObject *)in_ECX[0x310];
      while (local_98 != (CObject *)0x0) {
        piVar8 = (int *)FUN_0044f2d0(&local_98);
        puVar2 = (undefined4 *)*piVar8;
        if ((puVar2 != (undefined4 *)0x0) &&
           (iVar3 = FUN_0079d98a(&PTR_s_CMFCToolBarButton_00a00a80), iVar3 != 0)) {
          pcVar1 = *(code **)*puVar2;
          guard_check_icall();
          (*pcVar1)();
          pCVar4 = (CObject *)FUN_0079d90c();
          pcVar1 = *(code **)(*(int *)pCVar4 + 0x14);
          guard_check_icall(puVar2);
          (*pcVar1)();
          CObList::AddTail((CObList *)(in_ECX + 0x31d),pCVar4);
        }
      }
    }
  }
LAB_00804ce5:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorBar[268], CMFCDropDownToolBar[268], CMFCImageEditorPaletteBar[268], CMFCMenuBar[268], CMFCOutlookBarToolBar[268], CMFCPopupMenuBar[268], CMFCPrintPreviewToolBar[268], CMFCRibbonPanelMenuBar[268], CMFCTasksPaneToolBar[268], CMFCToolBar[268] */
/* 00805d7f  FUN_00805d7f  940 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00805d7f(int param_1)

{
  code *pcVar1;
  uint uVar2;
  CObject *pCVar3;
  undefined4 *puVar4;
  int iVar5;
  CObject *pCVar6;
  undefined4 uVar7;
  int *in_ECX;
  CObject *local_104;
  CObject *local_100;
  CObject *local_fc;
  int local_f8;
  CMFCToolBarButton local_f4 [112];
  CMFCToolBarButton local_84 [124];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xf8;
  local_8 = 0x805d8e;
  in_ECX[0x2e4] = 0;
  local_f8 = *(int *)(param_1 + 4);
joined_r0x00805da5:
  if (local_f8 != 0) {
    pCVar3 = (CObject *)FUN_0049acb0(&local_f8);
    local_fc = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarButton_00a00a80,pCVar3);
    if (local_fc != (CObject *)0x0) {
      local_104 = (CObject *)in_ECX[0x317];
      do {
        do {
          if (local_104 == (CObject *)0x0) {
            in_ECX[0x2e4] = 1;
            iVar5 = FUN_007fc6bf(*(undefined4 *)(local_fc + 0x20),0);
            if (-1 < iVar5) {
              pcVar1 = *(code **)(*in_ECX + 0x34c);
              guard_check_icall(iVar5);
              (*pcVar1)();
              if (in_ECX[0x2f2] != 0) {
                FUN_00803d7d(*(undefined4 *)(local_fc + 0x20));
              }
            }
            goto joined_r0x00805da5;
          }
          puVar4 = (undefined4 *)FUN_0044f2d0(&local_104);
          pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarButton_00a00a80,
                                      (CObject *)*puVar4);
        } while (pCVar3 == (CObject *)0x0);
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x94);
        guard_check_icall(local_fc);
        iVar5 = (*pcVar1)();
      } while (iVar5 == 0);
    }
    goto joined_r0x00805da5;
  }
  local_fc = (CObject *)in_ECX[0x317];
  local_104 = (CObject *)0x0;
  local_f8 = 0;
  while (local_fc != (CObject *)0x0) {
    puVar4 = (undefined4 *)FUN_0044f2d0(&local_fc);
    local_100 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarButton_00a00a80,
                                   (CObject *)*puVar4);
    if (local_100 != (CObject *)0x0) {
      local_f8 = *(int *)(param_1 + 4);
      pCVar3 = local_100;
      do {
        do {
          if (local_f8 == 0) {
            in_ECX[0x2e4] = 1;
            uVar2 = *(uint *)(pCVar3 + 0x20);
            local_100 = (CObject *)in_ECX[0x312];
            if ((int)local_104 <= in_ECX[0x312]) {
              local_100 = local_104;
            }
            if (uVar2 == 0) {
              pcVar1 = *(code **)(*in_ECX + 0x348);
              guard_check_icall(local_100);
              (*pcVar1)();
            }
            else {
              local_f8 = -1;
              CMap<unsigned_int,unsigned_int,int,int>::Lookup
                        ((CMap<unsigned_int,unsigned_int,int,int> *)&PTR_vftable_00a005f4,uVar2,
                         &local_f8);
              pcVar1 = *(code **)(*in_ECX + 0x344);
              uVar7 = FUN_00880d51(uVar2,local_f8,0,0,in_ECX[0x2de]);
              local_8 = 0;
              guard_check_icall(uVar7,local_100);
              (*pcVar1)();
              local_8 = 0xffffffff;
              CMFCToolBarButton::~CMFCToolBarButton(local_84);
              if (in_ECX[0x2f2] != 0) {
                uVar7 = FUN_00880d51(uVar2,local_f8,0,0,in_ECX[0x2de]);
                local_8 = 1;
                FUN_007fe51e(uVar7,local_100);
                local_8 = 0xffffffff;
                CMFCToolBarButton::~CMFCToolBarButton(local_f4);
              }
            }
            goto LAB_00806045;
          }
          pCVar6 = (CObject *)FUN_0049acb0(&local_f8);
          pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarButton_00a00a80,pCVar6);
        } while (pCVar6 == (CObject *)0x0);
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x94);
        guard_check_icall(pCVar6);
        iVar5 = (*pcVar1)();
        pCVar3 = local_100;
      } while (iVar5 == 0);
    }
LAB_00806045:
    local_104 = local_104 + 1;
  }
  local_fc = (CObject *)0x0;
  if (*(int *)(param_1 + 0xc) == in_ECX[0x319]) {
    local_fc = (CObject *)in_ECX[0x317];
    local_f8 = *(int *)(param_1 + 4);
    do {
      do {
        if (local_fc == (CObject *)0x0) goto LAB_00806118;
        if (local_f8 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        puVar4 = (undefined4 *)FUN_0044f2d0(&local_fc);
        pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarButton_00a00a80,
                                    (CObject *)*puVar4);
        pCVar6 = (CObject *)FUN_0049acb0(&local_f8);
        pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarButton_00a00a80,pCVar6);
      } while ((pCVar3 == (CObject *)0x0) || (pCVar6 == (CObject *)0x0));
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x94);
      guard_check_icall(pCVar6);
      iVar5 = (*pcVar1)();
    } while (iVar5 != 0);
  }
  in_ECX[0x2e4] = 1;
LAB_00806118:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorBar[130], CMFCDropDownToolBar[130], CMFCImageEditorPaletteBar[130], CMFCMenuBar[130], CMFCOutlookBarPane[130], CMFCOutlookBarToolBar[130], CMFCPopupMenuBar[130], CMFCPrintPreviewToolBar[130], CMFCRibbonPanelMenuBar[130], CMFCTasksPaneToolBar[130], CMFCToolBar[130] */
/* 0080612c  FUN_0080612c  279 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_0080612c(int *param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 local_24 [8];
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = param_1;
  if (in_ECX[0x345] != 0) {
    *(undefined4 *)(in_ECX[0x345] + 0xfc) = 0;
  }
  pcVar1 = *(code **)(*in_ECX + 0x41c);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  in_ECX[0x2fa] = iVar3;
  *param_1 = 0;
  param_1[1] = 0;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  SetRectEmpty(&local_18);
  pcVar1 = *(code **)(*in_ECX + 0x164);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    iVar3 = local_18.right - local_18.left;
  }
  else {
    iVar3 = local_18.bottom - local_18.top;
  }
  FUN_00805b89(param_2 + iVar3,param_3);
  iVar3 = *in_ECX;
  pcVar1 = *(code **)(iVar3 + 0x164);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  pcVar1 = *(code **)(iVar3 + 0x2a4);
  uVar7 = (uint)(iVar4 == 0);
  puVar6 = local_24;
  guard_check_icall(puVar6,uVar7);
  piVar5 = (int *)(*pcVar1)();
  piVar2 = local_1c;
  iVar3 = piVar5[1];
  *local_1c = *piVar5;
  local_1c[1] = iVar3;
  if (in_ECX[0x2e] == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x164);
    guard_check_icall(puVar6,uVar7);
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      iVar3 = piVar2[1];
    }
    else {
      iVar3 = *piVar2;
    }
    in_ECX[0x4f] = iVar3;
  }
  return piVar2;
}




/* vtable slots: CMFCColorBar[56], CMFCDropDownToolBar[56], CMFCImageEditorPaletteBar[56], CMFCMenuBar[56], CMFCOutlookBarPane[56], CMFCOutlookBarToolBar[56], CMFCPopupMenuBar[56], CMFCPrintPreviewToolBar[56], CMFCRibbonPanelMenuBar[56], CMFCTasksPaneToolBar[56], CMFCToolBar[56] */
/* 00806a26  FUN_00806a26  132 bytes, 0 callers */

undefined4 FUN_00806a26(short param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  CWnd *pCVar5;
  CWnd *in_ECX;
  
  if (param_1 == 3) {
    piVar3 = (int *)FUN_007fb1c0(param_3);
    if ((param_3 != 0) && (piVar3 != (int *)0x0)) {
      if ((piVar3[8] == 0) || (piVar3[8] == -1)) {
        pcVar1 = *(code **)(*piVar3 + 0x20);
        guard_check_icall();
        (*pcVar1)();
      }
      else {
        pcVar1 = *(code **)(*piVar3 + 0x24);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (iVar4 == 0) {
          pCVar5 = CWnd::GetOwner(in_ECX);
          SendMessageW(*(HWND *)(pCVar5 + 0x20),0x111,piVar3[8],0);
        }
      }
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0x80070057;
  }
  return uVar2;
}




/* vtable slots: CMFCColorBar[55], CMFCDropDownToolBar[55], CMFCImageEditorPaletteBar[55], CMFCMenuBar[55], CMFCOutlookBarPane[55], CMFCOutlookBarToolBar[55], CMFCPopupMenuBar[55], CMFCPrintPreviewToolBar[55], CMFCRibbonPanelMenuBar[55], CMFCTasksPaneToolBar[55], CMFCToolBar[55] */
/* 00806aaa  FUN_00806aaa  208 bytes, 0 callers */

undefined4 FUN_00806aaa(LONG param_1,LONG param_2,undefined2 *param_3)

{
  code *pcVar1;
  POINT pt;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  BOOL BVar6;
  int in_ECX;
  tagPOINT local_18;
  int local_10;
  int *local_c;
  int local_8;
  
  if (param_3 == (undefined2 *)0x0) {
    uVar3 = 0x80070057;
  }
  else {
    *(undefined4 *)(param_3 + 4) = 0;
    *param_3 = 3;
    local_18.x = param_1;
    local_18.y = param_2;
    ScreenToClient(*(HWND *)(in_ECX + 0x20),&local_18);
    local_10 = *(int *)(in_ECX + 0xc40);
    local_8 = 1;
    while (local_10 != 0) {
      puVar4 = (undefined4 *)FUN_0044f2d0(&local_10);
      local_c = (int *)*puVar4;
      pcVar1 = *(code **)(*local_c + 0xbc);
      guard_check_icall();
      iVar5 = (*pcVar1)();
      piVar2 = local_c;
      if (0 < iVar5) {
        pt.y = local_18.y;
        pt.x = local_18.x;
        BVar6 = PtInRect((RECT *)(local_c + 0x15),pt);
        if (BVar6 != 0) {
          *(int *)(param_3 + 4) = local_8;
          pcVar1 = *(code **)(*piVar2 + 0xb8);
          guard_check_icall();
          (*pcVar1)();
          break;
        }
        local_8 = local_8 + 1;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}




/* vtable slots: CMFCColorBar[54], CMFCDropDownToolBar[54], CMFCImageEditorPaletteBar[54], CMFCMenuBar[54], CMFCOutlookBarPane[54], CMFCOutlookBarToolBar[54], CMFCPopupMenuBar[54], CMFCPrintPreviewToolBar[54], CMFCRibbonPanelMenuBar[54], CMFCTasksPaneToolBar[54], CMFCToolBar[54] */
/* 00806b7a  FUN_00806b7a  184 bytes, 0 callers */

undefined4
FUN_00806b7a(int param_1,short param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined2 *param_6)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if ((param_6 == (undefined2 *)0x0) || (*param_6 = 0, param_2 != 3)) {
    return 0x80070057;
  }
  pcVar1 = *(code **)(*in_ECX + 0x3c8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (param_1 == 3) {
LAB_00806c0b:
    if (param_4 != 0) {
      *param_6 = 3;
      *(int *)(param_6 + 4) = param_4 + -1;
      if (0 < param_4 + -1) goto LAB_00806bf3;
LAB_00806c1d:
      *param_6 = 0;
    }
LAB_00806c22:
    uVar3 = 1;
  }
  else {
    if ((param_1 == 4) || (param_1 == 5)) {
      if (param_4 == 0) goto LAB_00806c22;
      *param_6 = 3;
      *(int *)(param_6 + 4) = param_4 + 1;
      if (iVar2 < param_4 + 1) goto LAB_00806c1d;
    }
    else {
      if (param_1 == 6) goto LAB_00806c0b;
      if (param_1 == 7) {
        if (param_4 != 0) goto LAB_00806c22;
        *(undefined4 *)(param_6 + 4) = 1;
      }
      else {
        if ((param_1 != 8) || (param_4 != 0)) goto LAB_00806c22;
        *(int *)(param_6 + 4) = iVar2;
      }
      *param_6 = 3;
    }
LAB_00806bf3:
    uVar3 = 0;
  }
  return uVar3;
}




/* vtable slots: CMFCColorBar[40], CMFCDropDownToolBar[40], CMFCImageEditorPaletteBar[40], CMFCMenuBar[40], CMFCOutlookBarPane[40], CMFCOutlookBarToolBar[40], CMFCPopupMenuBar[40], CMFCPrintPreviewToolBar[40], CMFCRibbonPanelMenuBar[40], CMFCTasksPaneToolBar[40], CMFCToolBar[40] */
/* 00806c32  FUN_00806c32  101 bytes, 0 callers */

HRESULT FUN_00806c32(short param_1,undefined4 param_2,int param_3,undefined4 param_4,void **param_5)

{
  int iVar1;
  HRESULT HVar2;
  CObject *pCVar3;
  
  if (param_5 == (void **)0x0) {
    HVar2 = -0x7ff8ffa9;
  }
  else {
    *param_5 = (void *)0x0;
    if ((param_1 == 3) && (param_3 != 0)) {
      pCVar3 = (CObject *)FUN_007fb1c0(param_3);
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar3);
      if ((pCVar3 != (CObject *)0x0) &&
         ((iVar1 = *(int *)(pCVar3 + 0x8c), iVar1 != 0 && (*(int *)(iVar1 + 0x20) != 0)))) {
        HVar2 = AccessibleObjectFromWindow
                          (*(HWND *)(iVar1 + 0x20),0xfffffffc,(IID *)&DAT_009a9c2c,param_5);
        return HVar2;
      }
    }
    HVar2 = 1;
  }
  return HVar2;
}




/* vtable slots: CMFCColorBar[39], CMFCDropDownToolBar[39], CMFCImageEditorPaletteBar[39], CMFCMenuBar[39], CMFCOutlookBarPane[39], CMFCOutlookBarToolBar[39], CMFCPopupMenuBar[39], CMFCPrintPreviewToolBar[39], CMFCRibbonPanelMenuBar[39], CMFCTasksPaneToolBar[39], CMFCToolBar[39] */
/* 00806c97  FUN_00806c97  53 bytes, 0 callers */

undefined4 FUN_00806c97(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x3c8);
    guard_check_icall();
    uVar2 = (*pcVar1)();
    *param_1 = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCColorBar[1] */
/* 0082269a  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCColorBar::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCColorBar::_scalar_deleting_destructor_(CMFCColorBar *this,uint param_1)

{
  FUN_00822591();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xe68);
    }
  }
  return this;
}




/* vtable slots: CMFCColorBar[249] */
/* 00822700  FUN_00822700  935 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00822700(void)

{
  code *pcVar1;
  BOOL BVar2;
  undefined4 *puVar3;
  int iVar4;
  int *in_ECX;
  int iVar5;
  int local_44;
  int *local_40;
  int local_3c;
  CObject *local_38;
  int local_34;
  int local_30;
  int local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((((in_ECX != (int *)0x0) && (in_ECX[8] != 0)) &&
      (local_40 = in_ECX, BVar2 = IsWindow((HWND)in_ECX[8]), BVar2 != 0)) && (in_ECX[0x2f7] == 0)) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetClientRect((HWND)in_ECX[8],&local_18);
    InflateRect(&local_18,-(in_ECX[0x377] + in_ECX[0x37b]),-(in_ECX[0x378] + in_ECX[0x37a]));
    local_3c = 0;
    if ((*(int *)(in_ECX[0x394] + -0xc) == 0) || (local_34 = 0, in_ECX[0x392] != -1)) {
      local_34 = 1;
    }
    local_44 = in_ECX[0x310];
    local_2c = local_18.top;
    local_30 = local_18.left;
    iVar5 = local_18.left;
joined_r0x008227c6:
    if (local_44 != 0) {
      local_28.left = 0;
      local_28.top = local_28.left;
      local_28.right = local_28.left;
      local_28.bottom = local_28.left;
      puVar3 = (undefined4 *)FUN_0044f2d0(&local_44);
      if (((byte)((CObject *)*puVar3)[0x24] & 1) == 0) goto LAB_00822855;
      if (local_3c == 0) {
        local_28.left = iVar5;
        if (local_18.left < iVar5) {
          local_2c = local_2c + in_ECX[0x38f] + in_ECX[0x37a];
          local_28.left = local_18.left;
        }
        local_28.right = (local_18.right - local_18.left) + local_28.left;
        local_28.bottom = local_2c + 2;
        local_30 = local_18.left;
        iVar5 = local_2c + 4;
        local_28.top = local_2c;
      }
      else {
        SetRectEmpty(&local_28);
        iVar5 = local_2c;
      }
      local_2c = iVar5;
      local_3c = 1;
      goto LAB_00822a65;
    }
    FUN_008065ff();
  }
  return;
LAB_00822855:
  local_38 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarColorButton_00a007d8,
                                (CObject *)*puVar3);
  if (local_38 == (CObject *)0x0) goto joined_r0x008227c6;
  if ((*(int *)(local_38 + 0x84) != 0) && (in_ECX[0x37f] == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x170);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    iVar5 = local_30;
    if (iVar4 == 0) {
      SetRectEmpty(&local_28);
      goto LAB_00822a65;
    }
  }
  if (((*(int *)(local_38 + 0x78) == 0) && (*(int *)(local_38 + 0x7c) == 0)) &&
     (*(int *)(local_38 + 0x80) == 0)) {
    if (local_18.right < in_ECX[0x38e] + iVar5) {
      local_2c = local_2c + in_ECX[0x38f];
      local_30 = local_18.left;
      iVar5 = local_18.left;
    }
    if ((*(int *)(local_38 + 0x88) == 0) || (local_34 != 0)) {
      local_28.right = in_ECX[0x38e] + iVar5;
      local_28.bottom = in_ECX[0x38f] + local_2c;
      local_30 = local_30 + in_ECX[0x38e];
      local_3c = 0;
      in_ECX = local_40;
      local_28.left = iVar5;
      local_28.top = local_2c;
    }
    else {
      SetRectEmpty(&local_28);
    }
    if ((*(int *)(local_38 + 0x70) == in_ECX[0x392]) && (*(int *)(local_38 + 0x88) == 0)) {
      local_34 = 0;
    }
  }
  else {
    local_28.left = iVar5;
    if (local_18.left < iVar5) {
      local_2c = local_2c + in_ECX[0x38f] + in_ECX[0x37a];
      local_28.left = local_18.left;
    }
    if ((*(int *)(local_38 + 0x7c) == 0) || (local_34 == 0)) {
      iVar5 = in_ECX[0x379] - in_ECX[0x37a] / 2;
      local_28.right = (local_28.left - local_18.left) + local_18.right;
      local_28.bottom = local_2c + iVar5;
      local_30 = local_18.left;
    }
    else {
      local_30 = ((local_28.left - in_ECX[0x38e]) - local_18.left) + local_18.right;
      local_28.bottom = (in_ECX[0x379] - in_ECX[0x37a] / 2) + local_2c;
      iVar5 = ((local_28.bottom - local_40[0x38f]) - local_2c) / 2;
      local_28.right = local_30;
    }
    iVar4 = local_2c + iVar5;
    local_28.top = local_2c;
    if (*(int *)(local_38 + 0x7c) != 0) {
      local_2c = local_2c + iVar5;
      InflateRect(&local_28,-(local_40[0x37b] / 2),-(local_40[0x37a] / 2));
      iVar4 = local_2c;
    }
    local_2c = iVar4;
    local_3c = 0;
  }
LAB_00822a65:
  FUN_0080554f(local_28.left,local_28.top,local_28.right,local_28.bottom);
  in_ECX = local_40;
  iVar5 = local_30;
  goto joined_r0x008227c6;
}




/* vtable slots: CMFCColorBar[251], CMFCPopupMenuBar[251], CMFCRibbonPanelMenuBar[251] */
/* 00822aa7  FUN_00822aa7  6 bytes, 0 callers */

undefined4 FUN_00822aa7(void)

{
  return DAT_00a13c28;
}




/* vtable slots: CMFCColorBar[169] */
/* 00822aad  FUN_00822aad  83 bytes, 0 callers */

void FUN_00822aad(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int local_c;
  int local_8;
  
  local_c = in_ECX;
  local_8 = in_ECX;
  FUN_008230ea(&local_c,param_2);
  iVar3 = FUN_008231d7(local_c);
  iVar1 = *(int *)(in_ECX + 0xe3c);
  iVar2 = *(int *)(in_ECX + 0xdec);
  *param_1 = *(int *)(in_ECX + 0xe38) * local_c + *(int *)(in_ECX + 0xde8) * 2;
  param_1[1] = iVar1 * local_8 + iVar3 + iVar2 * 2;
  return;
}




/* vtable slots: CMFCColorBar[276] */
/* 00822d2d  Create  78 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCColorBar::Create(class CWnd *,unsigned long,unsigned
   int,class CPalette *,int,int,int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall
CMFCColorBar::Create
          (CMFCColorBar *this,CWnd *param_1,ulong param_2,uint param_3,CPalette *param_4,int param_5
          ,int param_6,int param_7)

{
  int iVar1;
  
  if (*(int *)(this + 0xe10) == 0) {
    *(int *)(this + 0xdd0) = param_5;
    *(int *)(this + 0xdd8) = param_7;
    *(int *)(this + 0xdd4) = param_6;
    FUN_0082330d(param_4,this + 0xe08);
  }
  iVar1 = FUN_007fc712(param_1,param_2,param_3);
  return iVar1;
}




/* vtable slots: CMFCColorBar[277] */
/* 00822d7b  FUN_00822d7b  396 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00822d7b(int param_1,int *param_2,int param_3,int param_4,int param_5)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint local_20;
  int local_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_007fd9c2(0);
  if (0 < param_4) goto LAB_00822e23;
  if (param_5 == 0) {
    local_20 = 0x14;
LAB_00822dcf:
    uVar6 = local_20;
    do {
      iVar2 = ((param_2[2] + in_ECX[0x37b] * -2) - *param_2) / (int)uVar6;
      if ((iVar2 != 0) &&
         (iVar2 = (local_20 / uVar6) * iVar2, iVar5 = (param_2[3] + in_ECX[0x37a] * -2) - param_2[1]
         , iVar2 - iVar5 != 0 && iVar5 <= iVar2)) {
        param_4 = uVar6 + 1;
        if (0 < param_4) goto LAB_00822e23;
        break;
      }
      uVar6 = uVar6 - 1;
    } while (0 < (int)uVar6);
  }
  else {
    local_20 = FUN_007d5e76();
    if (0 < (int)local_20) goto LAB_00822dcf;
  }
  param_4 = -1;
LAB_00822e23:
  uVar9 = 0;
  uVar8 = 0;
  pcVar1 = *(code **)(*in_ECX + 0x450);
  uVar7 = 0x50002000;
  iVar2 = param_1;
  iVar5 = param_3;
  guard_check_icall(param_1,0x50002000,param_3,param_5,param_4,0,0);
  iVar3 = (*pcVar1)();
  uVar4 = 0;
  if (iVar3 != 0) {
    iVar3 = *in_ECX;
    pcVar1 = *(code **)(iVar3 + 0x1c0);
    guard_check_icall(iVar2,uVar7,iVar5,param_5,param_4,uVar8,uVar9);
    uVar6 = (*pcVar1)();
    pcVar1 = *(code **)(iVar3 + 0x1e4);
    guard_check_icall(uVar6 & 0xffbff0ff);
    (*pcVar1)();
    local_18 = *param_2;
    iStack_14 = param_2[1];
    iStack_10 = param_2[2];
    iStack_c = param_2[3];
    pcVar1 = *(code **)(*in_ECX + 0x234);
    guard_check_icall(&local_18,1,0);
    (*pcVar1)();
    FUN_00822b00(1,1);
    pcVar1 = *(code **)(*in_ECX + 0x238);
    guard_check_icall(&DAT_00a11c68,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x13,0);
    (*pcVar1)();
    if (param_1 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(param_1 + 0x20);
    }
    in_ECX[0x17] = iVar2;
    in_ECX[0x381] = param_3;
    in_ECX[0x2ed] = 0;
    uVar4 = 1;
  }
  return uVar4;
}




/* vtable slots: CMFCColorBar[153] */
/* 00823010  DoPaint  48 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCColorBar::DoPaint(class CDC *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCColorBar::DoPaint(CMFCColorBar *this,CDC *param_1)

{
  CPalette *pCVar1;
  
  pCVar1 = (CPalette *)FUN_0082481a(param_1);
  FUN_007fc9c4(param_1);
  if (pCVar1 != (CPalette *)0x0) {
    CDC::SelectPalette(param_1,pCVar1,0);
  }
  return;
}




/* vtable slots: CMFCColorBar[269], CMFCPopupMenuBar[269], CMFCRibbonPanelMenuBar[269] */
/* 008231a8  GetCurrentMenuImageSize  47 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CSize __thiscall CMFCPopupMenuBar::GetCurrentMenuImageSize(void)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

undefined4 __thiscall CMFCPopupMenuBar::GetCurrentMenuImageSize(CMFCPopupMenuBar *this)

{
  undefined4 in_stack_00000004;
  
  if ((*(int *)(this + 0xd44) == 0) || (*(int *)(*(int *)(this + 0xd44) + 0xb78) == 0)) {
    FUN_007fe1cf(in_stack_00000004);
  }
  else {
    FUN_0082328e(in_stack_00000004);
  }
  return in_stack_00000004;
}




/* vtable slots: CMFCColorBar[10] */
/* 008232ba  FUN_008232ba  6 bytes, 0 callers */

undefined ** FUN_008232ba(void)

{
  return &PTR_FUN_0098f218;
}




/* vtable slots: CMFCColorBar[0] */
/* 008232c0  FUN_008232c0  6 bytes, 0 callers */

undefined ** FUN_008232c0(void)

{
  return &PTR_s_CMFCColorBar_00a007bc;
}




/* vtable slots: CMFCColorBar[236] */
/* 0082346e  FUN_0082346e  101 bytes, 0 callers */

void FUN_0082346e(undefined4 param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  int in_ECX;
  
  FUN_00853fee(param_1);
  if (*(int *)(in_ECX + 0xe64) != 0) {
    pCVar2 = (CObject *)FUN_007fde79(param_1);
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarColorButton_00a007d8,pCVar2);
    if (((pCVar2 == (CObject *)0x0) || (*(int *)(pCVar2 + 0x7c) != 0)) ||
       (*(int *)(pCVar2 + 0x80) != 0)) {
      param_1 = 0xffffffff;
    }
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xe64) + 0x200);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCColorBar[256] */
/* 00823afd  FUN_00823afd  120 bytes, 0 callers */

undefined4 FUN_00823afd(int param_1)

{
  code *pcVar1;
  __POSITION *p_Var2;
  CWnd *pCVar3;
  undefined4 uVar4;
  CWnd *in_ECX;
  int iVar5;
  
  if (-1 < *(int *)(in_ECX + 0xbf0)) {
    p_Var2 = CObList::FindIndex((CObList *)(in_ECX + 0xc3c),*(int *)(in_ECX + 0xbf0));
    if (p_Var2 != (__POSITION *)0x0) {
      iVar5 = *(int *)(p_Var2 + 8);
      goto LAB_00823b25;
    }
  }
  iVar5 = 0;
LAB_00823b25:
  if ((param_1 == 0xd) && (iVar5 != 0)) {
    pCVar3 = CWnd::GetOwner(in_ECX);
    SendMessageW(*(HWND *)(pCVar3 + 0x20),0x362,0xe001,0);
    pcVar1 = *(code **)(*(int *)in_ECX + 1000);
    guard_check_icall(iVar5);
    (*pcVar1)();
    uVar4 = 1;
  }
  else {
    uVar4 = FUN_008547cb(param_1);
  }
  return uVar4;
}




/* vtable slots: CMFCColorBar[250] */
/* 00823dc1  FUN_00823dc1  859 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00823dc1(CObject *param_1)

{
  undefined4 uVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  CObject *pCVar4;
  CObject *pCVar5;
  int iVar6;
  BOOL BVar7;
  undefined4 *puVar8;
  CWnd *in_ECX;
  CObject *pCVar9;
  code *pcVar10;
  CObList local_34 [4];
  undefined4 *local_30;
  CObject *local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x823dcd;
  if ((*(int *)(in_ECX + 0xe5c) != 0) || (*(int *)(in_ECX + 0xe60) != 0)) {
    ReleaseCapture();
  }
  local_14[0] = 0xffffffff;
  pCVar9 = (CObject *)0x0;
  pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar3);
  if (pCVar4 != (CObject *)0x0) {
    pCVar9 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCColorMenuButton_00a00c0c,
                                *(CObject **)(pCVar4 + 0x158));
  }
  pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarColorButton_00a007d8,param_1);
  if (pCVar5 != (CObject *)0x0) {
    if (*(int *)(pCVar5 + 0x80) != 0) {
      return 0;
    }
    if (*(int *)(pCVar5 + 0x7c) == 0) {
      if (*(int *)(pCVar5 + 0x78) == 0) {
        local_14[0] = *(undefined4 *)(pCVar5 + 0x70);
      }
    }
    else {
      FUN_00855856(1);
      if (pCVar4 != (CObject *)0x0) {
        FUN_00797f20(0);
        iVar6 = DAT_00a13a1c;
        if (DAT_00a13a1c == 0) {
          iVar6 = FUN_00792b4c();
        }
        if (iVar6 != 0) {
          iVar6 = DAT_00a13a1c;
          if (DAT_00a13a1c == 0) {
            iVar6 = FUN_00792b4c();
          }
          FUN_0081bab4(iVar6,0);
        }
      }
      pHVar2 = *(HWND *)(in_ECX + 0x20);
      InvalidateRect(pHVar2,(RECT *)(param_1 + 0x54),1);
      UpdateWindow(*(HWND *)(in_ECX + 0x20));
      local_18 = *(CObject **)(*(int *)in_ECX + 0x458);
      iVar6 = *(int *)(in_ECX + 0xe48);
      if (iVar6 == -1) {
        iVar6 = *(int *)(in_ECX + 0xe4c);
      }
      guard_check_icall(iVar6,local_14);
      iVar6 = (*(code *)local_18)();
      if (iVar6 == 0) {
        BVar7 = IsWindow(pHVar2);
        if (BVar7 == 0) {
          return 1;
        }
        FUN_00855856(0);
        if (((*(int *)(in_ECX + 0xe5c) == 0) && (*(int *)(in_ECX + 0xe60) == 0)) &&
           (*(int *)(in_ECX + 0xe64) == 0)) {
          if (pCVar9 == (CObject *)0x0) {
            iVar6 = DAT_00a13a1c;
            if (DAT_00a13a1c == 0) {
              iVar6 = FUN_00792b4c();
            }
            if (iVar6 == 0) {
              return 1;
            }
            if (DAT_00a13a1c == 0) {
              FUN_00792b4c();
            }
            FUN_00797df8();
            return 1;
          }
          iVar6 = 0;
          goto LAB_00823fb1;
        }
        pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
        pCVar3 = CWnd::FromHandle(pHVar2);
        goto LAB_00824024;
      }
      BVar7 = IsWindow(pHVar2);
      if (BVar7 == 0) {
        return 1;
      }
      FUN_00855856(0);
    }
  }
  if (pCVar9 != (CObject *)0x0) {
    pcVar10 = *(code **)(*(int *)pCVar9 + 0xfc);
    guard_check_icall(local_14[0],1);
    (*pcVar10)();
    iVar6 = *(int *)(pCVar9 + 0x20);
LAB_00823fb1:
    FUN_00853c2d(iVar6,pCVar9);
    return 1;
  }
  if (*(int **)(in_ECX + 0xe5c) == (int *)0x0) {
    if (*(int *)(in_ECX + 0xe64) == 0) {
      if (*(int **)(in_ECX + 0xe60) == (int *)0x0) {
        FUN_00824a91(local_14[0]);
        CObList::CObList(local_34,10);
        local_8 = 0;
        iVar6 = FUN_007fdeef(*(undefined4 *)(in_ECX + 0xe04),local_34);
        if (0 < iVar6) {
          while (local_30 != (undefined4 *)0x0) {
            if (local_30 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
              FUN_0078e714();
            }
            puVar8 = (undefined4 *)*local_30;
            local_18 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCColorMenuButton_00a00c0c,
                                          (CObject *)local_30[2]);
            local_30 = puVar8;
            if (local_18 != (CObject *)0x0) {
              pcVar10 = *(code **)(*(int *)local_18 + 0xfc);
              guard_check_icall(local_14[0],0);
              (*pcVar10)();
            }
          }
        }
        uVar1 = local_14[0];
        puVar8 = (undefined4 *)FUN_007e3332(*(undefined4 *)(in_ECX + 0xe04));
        *puVar8 = uVar1;
        pCVar3 = CWnd::GetOwner(in_ECX);
        SendMessageW(*(HWND *)(pCVar3 + 0x20),0x111,*(WPARAM *)(in_ECX + 0xe04),0);
        iVar6 = DAT_00a13a1c;
        if (DAT_00a13a1c == 0) {
          iVar6 = FUN_00792b4c();
        }
        if (iVar6 != 0) {
          if (DAT_00a13a1c == 0) {
            FUN_00792b4c();
          }
          FUN_00797df8();
        }
        FUN_007a184a();
        return 1;
      }
      pcVar10 = *(code **)(**(int **)(in_ECX + 0xe60) + 0x16c);
      goto LAB_00824005;
    }
    FUN_008a13a4(local_14[0]);
  }
  else {
    pcVar10 = *(code **)(**(int **)(in_ECX + 0xe5c) + 0x198);
LAB_00824005:
    guard_check_icall();
    (*pcVar10)();
  }
  pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
LAB_00824024:
  SendMessageW(*(HWND *)(pCVar3 + 0x20),0x10,0,0);
  return 1;
}




/* vtable slots: CMFCColorBar[145] */
/* 008241ea  FUN_008241ea  285 bytes, 0 callers */

void FUN_008241ea(int *param_1,int param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  CObject *pCVar6;
  int in_ECX;
  undefined1 local_38 [4];
  undefined4 local_34;
  int local_20;
  undefined4 local_18;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  if ((*(int *)(in_ECX + 0xe04) != 0) && (*(int *)(in_ECX + 0xe04) != -1)) {
    FUN_00822476();
    local_34 = *(undefined4 *)(in_ECX + 0xe04);
    local_18 = 1;
    pcVar1 = *(code **)(*param_1 + 0xc);
    guard_check_icall(local_34,0xffffffff,local_38,0);
    iVar3 = (*pcVar1)();
    iVar4 = local_10;
    if ((iVar3 == 0) && ((iVar4 = 0, param_2 != 0 && (local_20 == 0)))) {
      local_c = 0;
      pcVar1 = *(code **)(*param_1 + 0xc);
      guard_check_icall(*(undefined4 *)(in_ECX + 0xe04),0,local_38,&local_c);
      iVar4 = (*pcVar1)();
    }
    if (iVar4 != *(int *)(in_ECX + 0xdf4)) {
      local_8 = *(int *)(in_ECX + 0xc40);
      *(int *)(in_ECX + 0xdf4) = iVar4;
      while (local_8 != 0) {
        puVar5 = (undefined4 *)FUN_0044f2d0(&local_8);
        pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarColorButton_00a007d8,
                                    (CObject *)*puVar5);
        if (pCVar6 != (CObject *)0x0) {
          uVar2 = *(uint *)(pCVar6 + 0x24);
          *(uint *)(pCVar6 + 0x24) = uVar2 & 0xfffbffff;
          if (iVar4 == 0) {
            *(uint *)(pCVar6 + 0x24) = uVar2 & 0xfffbffff | 0x40000;
          }
        }
      }
      InvalidateRect(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,1);
      UpdateWindow(*(HWND *)(in_ECX + 0x20));
    }
  }
  FUN_0080345e(param_1,param_2);
  return;
}




/* vtable slots: CMFCColorBar[278] */
/* 00824307  FUN_00824307  283 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00824307(ulong param_1,undefined4 *param_2)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  CObject *pCVar4;
  int iVar5;
  int in_ECX;
  undefined **local_adc [45];
  undefined4 local_a28;
  int local_a0c;
  ulong local_a08;
  CMFCColorDialog local_a04 [228];
  undefined4 local_920;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xacc;
  local_8 = 0x824316;
  local_a08 = param_1;
  local_a0c = in_ECX;
  pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar3);
  if ((pCVar4 == (CObject *)0x0) ||
     (pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCColorMenuButton_00a00c0c,
                                  *(CObject **)(pCVar4 + 0x158)), param_1 = local_a08,
     pCVar4 == (CObject *)0x0)) {
    if (*(int *)(local_a0c + 0xdf0) == 0) {
      CMFCColorDialog::CMFCColorDialog(local_a04,param_1,0,(CWnd *)0x0,(HPALETTE__ *)0x0);
      local_8 = 1;
      iVar5 = FUN_0079850d();
      if (iVar5 == 1) {
        *param_2 = local_920;
      }
      FUN_0089f663();
    }
    else {
      CColorDialog::CColorDialog((CColorDialog *)local_adc,param_1,0x102,(CWnd *)0x0);
      local_8 = 0;
      iVar5 = CColorDialog::DoModal((CColorDialog *)local_adc);
      if (iVar5 == 1) {
        *param_2 = local_a28;
      }
      local_adc[0] = CCommonDialog::vftable;
      FUN_00797fb6();
    }
  }
  else {
    pcVar1 = *(code **)(*(int *)pCVar4 + 0x100);
    guard_check_icall(local_a08,param_2);
    (*pcVar1)();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorBar[67] */
/* 00824422  FUN_00824422  212 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00824422(int param_1)

{
  POINT pt;
  int iVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  undefined4 uVar4;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((((*(int *)(in_ECX + 0xe5c) == 0) && (*(int *)(in_ECX + 0xe60) == 0)) &&
      (*(int *)(in_ECX + 0xe64) == 0)) || (*(int *)(in_ECX + 0xd6c) != 0)) {
LAB_008244dd:
    uVar4 = FUN_008036ce(param_1);
  }
  else {
    iVar1 = *(int *)(param_1 + 4);
    if (iVar1 != 0x7b) {
      if (iVar1 == 0x100) {
        iVar1 = *(int *)(param_1 + 8) + -0x1b;
      }
      else {
        if (iVar1 == 0x104) goto LAB_008244b6;
        if (((iVar1 != 0x201) && (iVar1 != 0x204)) && (iVar1 != 0x207)) goto LAB_008244dd;
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
        pt.y = (int)*(short *)(param_1 + 0xe);
        pt.x = (int)*(short *)(param_1 + 0xc);
        iVar1 = PtInRect(&local_18,pt);
      }
      if (iVar1 != 0) goto LAB_008244dd;
    }
LAB_008244b6:
    pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    SendMessageW(*(HWND *)(pCVar3 + 0x20),0x10,0,0);
    uVar4 = 1;
  }
  return uVar4;
}




/* vtable slots: CMFCColorBar[279] */
/* 008244f6  FUN_008244f6  804 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_008244f6(void)

{
  code *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int iVar8;
  int *in_ECX;
  bool bVar9;
  int local_18;
  
  puVar2 = &LAB_0094a591;
  if ((in_ECX != (int *)0x0) && (in_ECX[8] != 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x350);
    guard_check_icall();
    (*pcVar1)();
    bVar9 = false;
    if (*(int *)(in_ECX[0x394] + -0xc) != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x340);
      iVar3 = FUN_0078e624(0x90);
      if (iVar3 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_0082248f(in_ECX[0x393],1,0,in_ECX[0x394],in_ECX[0x392] == -1,0,0);
      }
      guard_check_icall(uVar4,0xffffffff);
      (*pcVar1)();
      bVar9 = in_ECX[0x392] == -1;
    }
    local_18 = 0;
    if (0 < in_ECX[900]) {
      do {
        uVar4 = 0;
        pcVar1 = *(code **)(*in_ECX + 0x340);
        iVar3 = FUN_0078e624(0x90);
        if (iVar3 != 0) {
          piVar5 = (int *)FUN_00799cf8(local_18);
          iVar3 = in_ECX[0x392];
          iVar8 = *piVar5;
          puVar6 = (undefined4 *)FUN_00799cf8(local_18);
          uVar4 = FUN_0082248f(*puVar6,0,0,0,iVar3 == iVar8,0,0);
        }
        guard_check_icall(uVar4,0xffffffff);
        (*pcVar1)();
        if (!bVar9) {
          piVar5 = (int *)FUN_00799cf8(local_18);
          bVar9 = in_ECX[0x392] == *piVar5;
        }
        local_18 = local_18 + 1;
      } while (local_18 < in_ECX[900]);
    }
    uVar4 = 0;
    if ((*(int *)(in_ECX[0x396] + -0xc) != 0) && (in_ECX[0x38a] != 0)) {
      pcVar1 = *(code **)(*in_ECX + 0x348);
      guard_check_icall(0xffffffff);
      (*pcVar1)();
      pcVar1 = *(code **)(*in_ECX + 0x340);
      iVar3 = FUN_0078e624(0x90);
      if (iVar3 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = FUN_00822515(in_ECX[0x396],1);
      }
      guard_check_icall(uVar7,0xffffffff);
      (*pcVar1)();
      puVar6 = (undefined4 *)in_ECX[0x388];
      while (puVar6 != (undefined4 *)0x0) {
        iVar3 = puVar6[2];
        puVar6 = (undefined4 *)*puVar6;
        pcVar1 = *(code **)(*in_ECX + 0x340);
        iVar8 = FUN_0078e624(0x90);
        if (iVar8 == 0) {
          uVar7 = 0;
        }
        else {
          if ((bVar9) || (in_ECX[0x392] != iVar3)) {
            uVar7 = 0;
          }
          else {
            uVar7 = 1;
          }
          uVar7 = FUN_0082248f(iVar3,0,0,0,uVar7,1,0);
        }
        guard_check_icall(uVar7,0xffffffff);
        (*pcVar1)();
      }
    }
    puVar2 = (undefined1 *)in_ECX[0x395];
    if (*(int *)(puVar2 + -0xc) != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x348);
      guard_check_icall(0xffffffff);
      (*pcVar1)();
      pcVar1 = *(code **)(*in_ECX + 0x340);
      iVar3 = FUN_0078e624(0x90);
      if (iVar3 == 0) {
        uVar7 = 0;
      }
      else {
        uVar7 = FUN_0082248f(0xffffffff,0,1,in_ECX[0x395],0,0,0);
      }
      guard_check_icall(uVar7,0xffffffff);
      (*pcVar1)();
      pcVar1 = *(code **)(*in_ECX + 0x340);
      iVar3 = FUN_0078e624(0x90);
      if (iVar3 != 0) {
        uVar4 = FUN_0082248f(in_ECX[0x392],0,0,0,!bVar9,0,1);
      }
      guard_check_icall(uVar4,0xffffffff);
      puVar2 = (undefined1 *)(*pcVar1)();
    }
  }
  return puVar2;
}




/* vtable slots: CMFCColorBar[2] */
/* 008248aa  FUN_008248aa  487 bytes, 0 callers */

CArchive * FUN_008248aa(CArchive *param_1)

{
  code *pcVar1;
  int *piVar2;
  CArchive *pCVar3;
  long *plVar4;
  int *in_ECX;
  int iVar5;
  int *local_c;
  long local_8;
  
  FUN_0080450a(param_1);
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,in_ECX[0x374]);
    CArchive::operator<<(param_1,in_ECX[0x375]);
    CArchive::operator<<(param_1,in_ECX[0x376]);
    CArchive::operator<<(param_1,in_ECX[0x393]);
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0x394));
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0x395));
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0x396));
    CArchive::operator<<(param_1,in_ECX[0x37e]);
    CArchive::operator<<(param_1,in_ECX[0x381]);
    CArchive::operator<<(param_1,in_ECX[0x37c]);
    pCVar3 = CArchive::operator<<(param_1,in_ECX[900]);
    iVar5 = 0;
    if (0 < in_ECX[900]) {
      do {
        plVar4 = (long *)FUN_00799cf8(iVar5);
        CArchive::operator<<(param_1,*plVar4);
        iVar5 = iVar5 + 1;
        pCVar3 = (CArchive *)(in_ECX + 0x382);
      } while (iVar5 < in_ECX[900]);
    }
  }
  else {
    CArchive::operator>>(param_1,in_ECX + 0x374);
    CArchive::operator>>(param_1,in_ECX + 0x375);
    CArchive::operator>>(param_1,in_ECX + 0x376);
    CArchive::operator>>(param_1,in_ECX + 0x393);
    FUN_0047fc90(in_ECX + 0x394);
    FUN_0047fc90(in_ECX + 0x395);
    FUN_0047fc90(in_ECX + 0x396);
    CArchive::operator>>(param_1,in_ECX + 0x37e);
    CArchive::operator>>(param_1,in_ECX + 0x381);
    CArchive::operator>>(param_1,in_ECX + 0x37c);
    iVar5 = 0;
    local_8 = 0;
    CArchive::operator>>(param_1,&local_8);
    local_c = in_ECX + 0x382;
    FUN_0079ca8b(local_8,0xffffffff);
    if (0 < local_8) {
      do {
        CArchive::operator>>(param_1,(long *)&local_c);
        piVar2 = (int *)FUN_00799cf8(iVar5);
        iVar5 = iVar5 + 1;
        *piVar2 = (int)local_c;
      } while (iVar5 < local_8);
    }
    pcVar1 = *(code **)(*in_ECX + 0x45c);
    guard_check_icall();
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x3e4);
    guard_check_icall();
    pCVar3 = (CArchive *)(*pcVar1)();
  }
  return pCVar3;
}




/* vtable slots: CMFCColorBar[262] */
/* 00824c97  FUN_00824c97  45 bytes, 0 callers */

void FUN_00824c97(void)

{
  CWnd *pCVar1;
  CWnd *in_ECX;
  WPARAM wParam;
  
  pCVar1 = CWnd::GetOwner(in_ECX);
  wParam = *(WPARAM *)(in_ECX + 0xe04);
  if (wParam == 0xffffffff) {
    wParam = 0xe001;
  }
  SendMessageW(*(HWND *)(pCVar1 + 0x20),0x362,wParam,0);
  return;
}




/* vtable slots: CMFCColorBar[131], CMFCPopupMenuBar[131], CMFCRibbonPanelMenuBar[131] */
/* 0085290d  FUN_0085290d  124 bytes, 0 callers */

void FUN_0085290d(void)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  CObject *pCVar4;
  int *in_ECX;
  
  if ((in_ECX != (int *)0x0) && (in_ECX[8] != 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x3e4);
    guard_check_icall();
    (*pcVar1)();
    InvalidateRect((HWND)in_ECX[8],(RECT *)0x0,1);
    UpdateWindow((HWND)in_ECX[8]);
    if (DAT_00a127ac != 0) {
      pHVar2 = GetParent((HWND)in_ECX[8]);
      pCVar3 = CWnd::FromHandle(pHVar2);
      pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar3);
      if (pCVar4 != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)pCVar4 + 0x178);
        guard_check_icall(0);
        (*pcVar1)();
      }
    }
  }
  return;
}




/* vtable slots: CMFCColorBar[272], CMFCPopupMenuBar[272] */
/* 00852ea9  FUN_00852ea9  62 bytes, 0 callers */

void FUN_00852ea9(void)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xdb0) != 0) {
    KillTimer(*(HWND *)(in_ECX + 0x20),0xec18);
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xdb0) + 0x58);
    guard_check_icall();
    (*pcVar1)();
    *(undefined4 *)(in_ECX + 0xdb0) = 0;
  }
  return;
}




/* vtable slots: CMFCColorBar[255], CMFCPopupMenuBar[255], CMFCRibbonPanelMenuBar[255] */
/* 00852ee7  FUN_00852ee7  246 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CObject * FUN_00852ee7(undefined4 param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  CObject *pCVar3;
  int iVar4;
  undefined4 uVar5;
  
  pCVar2 = (CObject *)FUN_00880f70(param_1);
  if (pCVar2 != (CObject *)0x0) {
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar2);
    if (pCVar3 == (CObject *)0x0) {
      iVar4 = FUN_0078e624(0xe8);
      if (iVar4 == 0) {
        pCVar3 = (CObject *)0x0;
      }
      else {
        if (*(int *)(pCVar2 + 0x3c) == 0) {
          if (*(int *)(pCVar2 + 4) == 0) {
            uVar5 = *(undefined4 *)(pCVar2 + 0x34);
          }
          else {
            uVar5 = *(undefined4 *)(pCVar2 + 0x38);
          }
        }
        else {
          uVar5 = 0xffffffff;
        }
        pCVar3 = (CObject *)
                 FUN_00874dc7(*(undefined4 *)(pCVar2 + 0x20),0,uVar5,*(undefined4 *)(pCVar2 + 0x2c),
                              *(undefined4 *)(pCVar2 + 4));
      }
      if (pCVar3 == (CObject *)0x0) goto LAB_00852fd8;
      *(int *)(pCVar3 + 8) = 1;
      *(uint *)(pCVar3 + 0xc) = (uint)(*(int *)(pCVar2 + 0x3c) == 0);
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x2c);
      guard_check_icall(pCVar3);
      iVar4 = (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar2 + 4);
      guard_check_icall(1);
      (*pcVar1)();
      if ((iVar4 == 0) || (*(int *)(*(int *)(pCVar3 + 0x2c) + -0xc) == 0)) {
        pcVar1 = *(code **)(*(int *)pCVar3 + 4);
        guard_check_icall(1);
        (*pcVar1)();
        pCVar3 = (CObject *)0x0;
      }
    }
    return pCVar3;
  }
LAB_00852fd8:
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCColorBar[240], CMFCPopupMenuBar[240], CMFCRibbonPanelMenuBar[240] */
/* 00852fde  FUN_00852fde  262 bytes, 0 callers */

void FUN_00852fde(CDC *param_1)

{
  int in_ECX;
  int iVar1;
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [8];
  undefined4 local_8;
  
  iVar1 = 0;
  if (*(int *)(in_ECX + 0xd78) == 0) {
    local_8 = FUN_0079efbc(in_ECX + 0xcec);
    do {
      FUN_0079ec58(local_10,*(undefined4 *)(in_ECX + 0xccc),
                   (*(int *)(in_ECX + 0xcd8) - *(int *)(in_ECX + 0xcd0)) / 2 +
                   *(int *)(in_ECX + 0xcd0) + -1 + iVar1);
      CDC::LineTo(param_1,*(int *)(in_ECX + 0xcd4),
                  (*(int *)(in_ECX + 0xcd8) - *(int *)(in_ECX + 0xcd0)) / 2 +
                  *(int *)(in_ECX + 0xcd0) + -1 + iVar1);
      FUN_0079ec58(local_18,*(int *)(in_ECX + 0xccc) + iVar1,*(int *)(in_ECX + 0xcd0) + iVar1);
      CDC::LineTo(param_1,*(int *)(in_ECX + 0xccc) + iVar1,*(int *)(in_ECX + 0xcd8) - iVar1);
      FUN_0079ec58(local_20,(*(int *)(in_ECX + 0xcd4) - iVar1) + -1,*(int *)(in_ECX + 0xcd0) + iVar1
                  );
      CDC::LineTo(param_1,(*(int *)(in_ECX + 0xcd4) - iVar1) + -1,*(int *)(in_ECX + 0xcd8) - iVar1);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 2);
    FUN_0079efbc(local_8);
  }
  return;
}




/* vtable slots: CMFCColorBar[254], CMFCPopupMenuBar[254], CMFCRibbonPanelMenuBar[254] */
/* 008530e4  FUN_008530e4  62 bytes, 0 callers */

void FUN_008530e4(undefined4 param_1,undefined4 *param_2)

{
  code *pcVar1;
  int *piVar2;
  undefined4 in_ECX;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x48);
  guard_check_icall(param_1,in_ECX,*param_2,param_2[1],param_2[2],param_2[3],0);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCColorBar[258], CMFCPopupMenuBar[258], CMFCRibbonPanelMenuBar[258] */
/* 00853122  FUN_00853122  180 bytes, 0 callers */

undefined4 FUN_00853122(int param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uEnable;
  
  if (DAT_00a127ac == 0) {
    uVar1 = 0;
  }
  else {
    *(undefined4 *)(param_1 + 8) = 1;
    FUN_007fd73b(param_1,param_2);
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4212,1);
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4213,0);
    if (*(int *)(param_1 + 4) == 0) {
      iVar2 = *(int *)(param_1 + 0x34);
    }
    else {
      iVar2 = *(int *)(param_1 + 0x38);
    }
    if (iVar2 < 0) {
      uEnable = (uint)(DAT_00a127a0 == 0);
    }
    else {
      uEnable = 0;
    }
    EnableMenuItem(*(HMENU *)(param_2 + 4),0x4214,uEnable);
    FUN_0082be6d();
    iVar2 = FUN_007e9a96(*(undefined4 *)(param_1 + 0x20),0);
    if (iVar2 != 0) {
      CheckMenuItem(*(HMENU *)(param_2 + 4),0x4213,8);
      CheckMenuItem(*(HMENU *)(param_2 + 4),0x4214,0);
    }
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CMFCColorBar[271], CMFCPopupMenuBar[271], CMFCRibbonPanelMenuBar[271] */
/* 008531d6  FUN_008531d6  353 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HMENU__ * FUN_008531d6(void)

{
  code *pcVar1;
  uint uVar2;
  HMENU pHVar3;
  int *piVar4;
  int iVar5;
  HMENU__ *hMenu;
  int in_ECX;
  UINT uFlags;
  UINT_PTR uIDNewItem;
  LPCWSTR lpNewItem;
  undefined **local_24;
  HMENU local_20;
  UINT_PTR local_1c;
  int local_18;
  LPCWSTR local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_20 = (HMENU)0x0;
  local_24 = CMenu::vftable;
  local_8 = 0;
  pHVar3 = CreatePopupMenu();
  CMenu::Attach((CMenu *)&local_24,pHVar3);
  local_18 = *(int *)(in_ECX + 0xc40);
joined_r0x0085320d:
  if (local_18 == 0) {
    hMenu = CMenu::Detach((CMenu *)&local_24);
    SetMenuDefaultItem(hMenu,*(UINT *)(in_ECX + 0xd48),0);
    local_8 = 2;
    local_24 = CMenu::vftable;
    CMenu::DestroyMenu((CMenu *)&local_24);
    return hMenu;
  }
  piVar4 = (int *)FUN_0049acb0(&local_18);
  if (piVar4 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((*(byte *)(piVar4 + 9) & 1) == 0) goto LAB_00853242;
  lpNewItem = (LPCWSTR)0x0;
  uIDNewItem = 0;
  uFlags = 0x800;
  goto LAB_008532e2;
LAB_00853242:
  iVar5 = FUN_0079d98a(&PTR_s_CMFCToolBarMenuButton_00a00a14);
  if (iVar5 != 0) {
    pcVar1 = *(code **)(*piVar4 + 0xd4);
    guard_check_icall();
    local_1c = (*pcVar1)();
    if (local_1c == 0) {
      lpNewItem = (LPCWSTR)piVar4[0xb];
      uIDNewItem = piVar4[8];
      uFlags = 0;
LAB_008532e2:
      AppendMenuW(local_20,uFlags,uIDNewItem,lpNewItem);
    }
    else {
      uVar2 = piVar4[9];
      iVar5 = FUN_004054a0(piVar4[0xb] + -0x10);
      local_14[0] = (LPCWSTR)(iVar5 + 0x10);
      local_8._0_1_ = 1;
      if ((piVar4[0x2f] != 0) && (DAT_00a13c78 != 0)) {
        FUN_0089ddc3(piVar4[0x2f],local_14);
      }
      AppendMenuW(local_20,(uVar2 & 0x20000000 | 0x8000000) >> 0x17,local_1c,local_14[0]);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00406b10();
    }
  }
  goto joined_r0x0085320d;
}




/* vtable slots: CMFCColorBar[248], CMFCPopupMenuBar[248], CMFCRibbonPanelMenuBar[248] */
/* 00853441  FUN_00853441  265 bytes, 0 callers */

int FUN_00853441(undefined4 param_1,int param_2,LPRECT param_3)

{
  LONG LVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int local_10;
  int local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 0xd78) == 0) {
    GetClientRect(*(HWND *)(in_ECX + 0x20),param_3);
    if (*(int *)(in_ECX + 0xc48) == 0) {
      param_3->bottom = param_3->top + 6;
      iVar3 = 0;
    }
    else {
      local_c = param_2;
      if (param_2 < 0) {
        local_c = 0;
      }
      local_10 = *(int *)(in_ECX + 0xc40);
      local_8 = 0;
      while (local_10 != 0) {
        iVar3 = FUN_0049acb0(&local_10);
        if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        iVar4 = *(int *)(iVar3 + 0x58);
        LVar1 = *(LONG *)(iVar3 + 0x5c);
        iVar2 = *(int *)(iVar3 + 0x60);
        if (local_c < iVar4) {
LAB_00853536:
          param_3->top = iVar4;
          iVar3 = local_8;
LAB_0085353b:
          if (iVar3 != -1) {
            iVar4 = param_3->top;
            goto LAB_008534f3;
          }
          break;
        }
        if (local_c <= iVar2) {
          param_3->left = *(LONG *)(iVar3 + 0x54);
          param_3->top = iVar4;
          param_3->right = LVar1;
          param_3->bottom = iVar2;
          if (local_c - iVar4 <= iVar2 - local_c) goto LAB_00853536;
          param_3->top = param_3->bottom;
          iVar3 = local_8 + 1;
          goto LAB_0085353b;
        }
        local_8 = local_8 + 1;
      }
      iVar4 = param_3->bottom + -6;
      param_3->top = iVar4;
      iVar3 = local_8;
LAB_008534f3:
      param_3->bottom = iVar4 + 6;
      OffsetRect(param_3,0,-3);
    }
  }
  else {
    iVar3 = -1;
  }
  return iVar3;
}




/* vtable slots: CMFCColorBar[241], CMFCPopupMenuBar[241], CMFCRibbonPanelMenuBar[241] */
/* 0085354b  GetCommandTarget  65 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual class CWnd * __thiscall CMFCPopupMenuBar::GetCommandTarget(void)const 
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

CWnd * __thiscall CMFCPopupMenuBar::GetCommandTarget(CMFCPopupMenuBar *this)

{
  CWnd *pCVar1;
  HWND pHVar2;
  
  if (*(int *)(this + 0xd70) == 0) {
    pHVar2 = GetParent(*(HWND *)(this + 0x20));
    pCVar1 = CWnd::FromHandle(pHVar2);
    pCVar1 = (CWnd *)AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,
                                        (CObject *)pCVar1);
    if ((pCVar1 == (CWnd *)0x0) || (*(int *)(pCVar1 + 0x134) == 0)) {
      pCVar1 = (CWnd *)FUN_007c248e();
      return pCVar1;
    }
  }
  else {
    pCVar1 = (CWnd *)0x0;
  }
  return pCVar1;
}




/* vtable slots: CMFCColorBar[270], CMFCPopupMenuBar[270], CMFCRibbonPanelMenuBar[270] */
/* 0085363d  FUN_0085363d  1519 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0085363d(HMENU__ *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  undefined4 uVar8;
  CCommandManager *this;
  CObject *pCVar9;
  UINT UVar10;
  int *in_ECX;
  CObject *pCVar11;
  HMENU pHVar12;
  int in_stack_fffffe18;
  UINT in_stack_fffffe1c;
  tagMENUITEMINFOW local_1d8;
  HMENU__ *local_1a8;
  undefined4 local_1a4;
  uint local_1a0;
  int local_19c;
  undefined8 local_198;
  int local_190;
  int local_18c;
  int local_188;
  int local_184;
  WCHAR local_180 [2];
  uint local_17c;
  CMenu *local_178;
  HMENU local_174;
  int local_170;
  undefined1 local_16c [4];
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  int local_134;
  CMFCToolBarButton local_84 [16];
  undefined4 local_74;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c8;
  local_8 = 0x85364c;
  local_1a8 = param_1;
  pcVar1 = *(code **)(*in_ECX + 0x350);
  guard_check_icall();
  (*pcVar1)();
  in_ECX[0x35a] = 1;
  RemoveAll();
  if ((param_1 == (HMENU__ *)0x0) ||
     (local_178 = CMenu::FromHandle(param_1), local_178 == (CMenu *)0x0)) goto LAB_00853c1f;
  iVar2 = DAT_00a13a1c;
  if ((DAT_00a13a1c == 0) && (iVar2 = FUN_00792b4c(), iVar2 == 0)) {
    iVar2 = FUN_00404c80();
  }
  pCVar11 = (CObject *)0x0;
  if (in_ECX[8] == 0) {
LAB_00853713:
    local_19c = param_2;
  }
  else {
    pHVar3 = GetParent((HWND)in_ECX[8]);
    pCVar4 = CWnd::FromHandle(pHVar3);
    pCVar11 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar4);
    if ((pCVar11 != (CObject *)0x0) && (*(int *)(pCVar11 + 0x134) != 0)) {
      iVar2 = *(int *)(pCVar11 + 0x134);
    }
    if (((DAT_00a127a4 == 0) || (pCVar11 == (CObject *)0x0)) || (iVar5 = FUN_0081d529(), iVar5 == 0)
       ) goto LAB_00853713;
    local_19c = 1;
  }
  if (iVar2 != 0) {
    local_17c = 0;
    uVar6 = 0;
    if (((pCVar11 != (CObject *)0x0) && (iVar5 = *(int *)(pCVar11 + 0x158), iVar5 != 0)) &&
       (pCVar11 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,
                                     *(CObject **)(iVar5 + 0x6c)), uVar6 = local_17c,
       pCVar11 != (CObject *)0x0)) {
      uVar6 = FUN_007fc033(iVar5);
    }
    SendMessageW(*(HWND *)(iVar2 + 0x20),0x117,(WPARAM)local_1a8,uVar6 & 0xffff);
  }
  iVar2 = GetMenuItemCount(*(HMENU *)(local_178 + 4));
  local_188 = 0;
  local_18c = 1;
  local_184 = 1;
  local_190 = iVar2;
  if (in_ECX[0x35e] != 0) {
    local_198 = (double)in_ECX[0x35f];
    local_184 = thunk_FUN_008d99f0();
    if (local_184 < 1) {
      local_184 = 1;
    }
  }
  local_174 = (HMENU)0x0;
  if (0 < iVar2) {
    do {
      pHVar12 = local_174;
      local_1a4 = 0;
      CStringT<>();
      local_8 = 0;
      FID_conflict_GetMenuStringA
                (pHVar12,(UINT)&local_170,(LPSTR)0x400,in_stack_fffffe18,in_stack_fffffe1c);
      _memset(&local_1d8,0,0x30);
      local_1d8.cch = 0;
      local_1d8.dwTypeData = (LPWSTR)0x0;
      local_1d8.cbSize = 0x30;
      local_1d8.fMask = 0x37;
      GetMenuItemInfoW(*(HMENU *)(local_178 + 4),(UINT)pHVar12,1,&local_1d8);
      UVar10 = local_1d8.wID;
      local_1a0 = local_1d8.wID;
      local_17c = GetMenuState(*(HMENU *)(local_178 + 4),(UINT)local_174,0x400);
      local_198 = (double)CONCAT44(local_1d8.dwItemData,(undefined4)local_198);
      if (local_1d8.fType == 0x800) {
        if (((local_188 == 0) && (local_18c == 0)) &&
           ((local_174 != (HMENU)(local_190 + -1) && (in_ECX[0x35e] == 0)))) {
          pcVar1 = *(code **)(*in_ECX + 0x348);
          guard_check_icall(0xffffffff);
          (*pcVar1)();
          local_18c = 0;
          local_188 = 1;
        }
      }
      else {
        pHVar12 = (HMENU)0x0;
        if (local_1d8.hSubMenu != (HMENU)0x0) {
          UVar10 = 0xffffffff;
          local_1a0 = 0xffffffff;
          pHVar12 = local_1d8.hSubMenu;
          if (DAT_00a13c78 != 0) {
            local_1a4 = FUN_0089de66(&local_170);
          }
        }
        if (((in_ECX[0x35c] == 0) && (local_19c == 0)) &&
           ((iVar2 = CMFCMenuBar::IsShowAllCommands(), iVar2 == 0 &&
            (iVar2 = CMFCToolBar::IsCommandRarelyUsed(UVar10), iVar2 != 0)))) {
          if (in_ECX[0x35e] == 0) {
            iVar2 = CMFCToolBar::IsCommandRarelyUsed(UVar10);
            if ((iVar2 != 0) && (iVar2 = FUN_007fe7b9(UVar10), iVar2 != 0)) {
              in_ECX[0x35a] = 0;
              iVar2 = FUN_0044e690(0x26,0);
              if ((-1 < iVar2) && (iVar2 < *(int *)(local_170 + -0xc) + -1)) {
                local_180[0] = FUN_004473c0(iVar2 + 1);
                local_180[1] = 0;
                CharUpperW(local_180);
                puVar7 = (uint *)FUN_007e3332(local_180[0]);
                *puVar7 = UVar10;
              }
            }
            goto LAB_00853bd4;
          }
LAB_00853a28:
          iVar2 = local_170;
          FUN_0082be6d();
          uVar8 = FUN_0082be37(UVar10,0);
          FUN_00880d51(UVar10,uVar8,iVar2,0,0);
          local_8._0_1_ = 1;
          if ((local_174 != (HMENU)0x0) && ((int)((int)&local_174->unused + 1) % local_184 == 0)) {
            local_74 = 1;
          }
          pcVar1 = *(code **)(*in_ECX + 0x344);
          guard_check_icall(local_84,0xffffffff);
          iVar2 = (*pcVar1)();
          local_8 = (uint)local_8._1_3_ << 8;
          CMFCToolBarButton::~CMFCToolBarButton(local_84);
        }
        else {
          if (in_ECX[0x35e] != 0) goto LAB_00853a28;
          FUN_00874dc7(UVar10,pHVar12,0xffffffff,local_170,0);
          local_160 = 0;
          local_8._0_1_ = 2;
          local_164 = 1;
          this = (CCommandManager *)FUN_0082be6d();
          local_134 = CCommandManager::GetMenuUserImage(this,UVar10);
          if (local_134 != -1) {
            local_168 = 1;
          }
          pcVar1 = *(code **)(*in_ECX + 0x344);
          guard_check_icall(local_16c,0xffffffff);
          iVar2 = (*pcVar1)();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_00874eb0();
        }
        if (-1 < iVar2) {
          pCVar11 = (CObject *)FUN_007fde79(iVar2);
          if (pCVar11 == (CObject *)0x0) {
                    /* WARNING: Subroutine does not return */
            FUN_0078e714();
          }
          if (*(int *)(pCVar11 + 4) == 0) {
            uVar6 = *(uint *)(pCVar11 + 0x34);
          }
          else {
            uVar6 = *(uint *)(pCVar11 + 0x38);
          }
          *(uint *)(pCVar11 + 0xc) = ~uVar6 >> 0x1f;
          *(undefined4 *)(pCVar11 + 0x28) = local_198._4_4_;
          if ((((DAT_00a13bac == 0) || (local_1a0 < *(uint *)(DAT_00a13bac + 0x24))) ||
              (*(uint *)(DAT_00a13bac + 0x28) < local_1a0)) && ((local_17c & 3) != 0)) {
            *(uint *)(pCVar11 + 0x24) = *(uint *)(pCVar11 + 0x24) | 0x40000;
          }
          pCVar9 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar11
                                     );
          local_198 = (double)CONCAT44(pCVar9,(undefined4)local_198);
          if (pCVar9 != (CObject *)0x0) {
            pcVar1 = *(code **)(*(int *)pCVar9 + 0xf8);
            guard_check_icall(local_1a4);
            (*pcVar1)();
          }
          if ((local_17c & 8) != 0) {
            *(uint *)(pCVar11 + 0x24) = *(uint *)(pCVar11 + 0x24) | 0x10000;
          }
          if ((local_1d8.fType & 0x40) != 0) {
            *(uint *)(pCVar11 + 0x24) = *(uint *)(pCVar11 + 0x24) | 0x20000000;
          }
          local_188 = 0;
          local_18c = 0;
        }
      }
LAB_00853bd4:
      local_8 = 0xffffffff;
      FUN_00406b10();
      local_174 = (HMENU)((int)&local_174->unused + 1);
    } while ((int)local_174 < local_190);
  }
  UVar10 = GetMenuDefaultItem(local_1a8,0,1);
  in_ECX[0x352] = UVar10;
LAB_00853c1f:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorBar[265], CMFCPopupMenuBar[265], CMFCRibbonPanelMenuBar[265] */
/* 00853f44  FUN_00853f44  45 bytes, 0 callers */

void FUN_00853f44(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x20c);
  guard_check_icall();
  (*pcVar1)();
  RedrawWindow((HWND)in_ECX[8],(RECT *)0x0,(HRGN)0x0,0x105);
  return;
}




/* vtable slots: CMFCColorBar[260], CMFCPopupMenuBar[260], CMFCRibbonPanelMenuBar[260] */
/* 00853f71  FUN_00853f71  125 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00853f71(int param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
  *param_2 = *(undefined4 *)(param_1 + 0x54);
  param_2[1] = *(undefined4 *)(param_1 + 0x58);
  param_2[2] = *(undefined4 *)(param_1 + 0x5c);
  param_2[3] = *(undefined4 *)(param_1 + 0x60);
  if (((*(int *)(param_1 + 0x10) != 0) && (param_3 != 0)) && (*(int *)(in_ECX + 0xd78) != 0)) {
    param_2[2] = local_18.right;
    iVar1 = *(int *)(param_1 + 0x60);
    param_2[1] = iVar1;
    param_2[3] = iVar1 + 5;
  }
  return;
}




/* vtable slots: CMFCColorBar[246], CMFCPopupMenuBar[246], CMFCRibbonPanelMenuBar[246] */
/* 0085455f  FUN_0085455f  105 bytes, 0 callers */

undefined4 FUN_0085455f(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  HWND pHVar1;
  CWnd *pCVar2;
  CObject *pCVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  if ((param_2 & 8) == 0) {
    pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar2 = CWnd::FromHandle(pHVar1);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar2);
    if ((((pCVar3 != (CObject *)0x0) && (iVar4 = FUN_0081d584(), iVar4 != 0)) &&
        (*(int *)(pCVar3 + 0x158) != 0)) && (*(int *)(pCVar3 + 0x158) == *(int *)(iVar4 + 0xd0c))) {
      return 0;
    }
  }
  uVar5 = FUN_008008a0(param_1,param_2,param_3,param_4);
  return uVar5;
}




/* vtable slots: CMFCColorBar[233], CMFCPopupMenuBar[233], CMFCRibbonPanelMenuBar[233] */
/* 008545c8  FUN_008545c8  357 bytes, 0 callers */

void FUN_008545c8(undefined4 param_1)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  HWND pHVar5;
  CWnd *pCVar6;
  CObject *pCVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  int in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_8;
  
  if (((DAT_00a127ac == 0) && (DAT_00a00b1c != 0)) && (*(int *)(in_ECX + 0xd78) == 0)) {
    pHVar5 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar6 = CWnd::FromHandle(pHVar5);
    pCVar7 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar6);
    if ((pCVar7 != (CObject *)0x0) && (iVar8 = FUN_0081d604(), iVar8 != 0)) {
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_8 = *(int *)(in_ECX + 0xc40);
      bVar4 = true;
      while (local_8 != 0) {
        piVar9 = (int *)FUN_0044f2d0(&local_8);
        iVar8 = *piVar9;
        if (iVar8 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        if ((((*(byte *)(iVar8 + 0x24) & 1) == 0) || (local_8 == 0)) ||
           (iVar10 = CMFCToolBar::IsCommandRarelyUsed(*(uint *)(*(int *)(local_8 + 8) + 0x20)),
           iVar10 == 0)) {
          bVar2 = false;
          iVar10 = CMFCToolBar::IsCommandRarelyUsed(*(uint *)(iVar8 + 0x20));
          if (iVar10 == 0) {
            bVar2 = !bVar4;
            if (bVar2) {
              local_18 = *(undefined4 *)(iVar8 + 0x58);
            }
            bVar4 = true;
            bVar3 = true;
          }
          else {
            if (bVar4) {
              local_24 = *(undefined4 *)(iVar8 + 0x54);
              local_20 = *(undefined4 *)(iVar8 + 0x58);
              local_1c = *(undefined4 *)(iVar8 + 0x5c);
              local_18 = *(undefined4 *)(iVar8 + 0x60);
            }
            bVar4 = false;
            bVar3 = false;
            if (local_8 == 0) {
              local_18 = *(undefined4 *)(iVar8 + 0x60);
              bVar2 = true;
            }
          }
          if (bVar2) {
            piVar9 = (int *)FUN_007c2574();
            pcVar1 = *(code **)(*piVar9 + 0xa0);
            guard_check_icall(param_1,local_24,local_20,local_1c,local_18);
            (*pcVar1)();
            bVar4 = bVar3;
          }
        }
      }
    }
  }
  return;
}




/* vtable slots: CMFCColorBar[232], CMFCPopupMenuBar[232], CMFCRibbonPanelMenuBar[232] */
/* 00855232  FUN_00855232  102 bytes, 0 callers */

undefined4 FUN_00855232(undefined4 param_1)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  CObject *pCVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  
  pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar2);
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar3);
  if ((pCVar4 != (CObject *)0x0) && (piVar5 = (int *)FUN_0081d584(), piVar5 != (int *)0x0)) {
    pcVar1 = *(code **)(*piVar5 + 0x3a0);
    guard_check_icall(param_1);
    iVar6 = (*pcVar1)();
    if (iVar6 != 0) {
      return 1;
    }
  }
  uVar7 = FUN_008027e8(param_1);
  return uVar7;
}




/* vtable slots: CMFCColorBar[29], CMFCPopupMenuBar[29], CMFCRibbonPanelMenuBar[29] */
/* 008554bf  FUN_008554bf  402 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_008554bf(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  wchar_t *pwVar2;
  int iVar3;
  CObject *pCVar4;
  int *piVar5;
  int *in_ECX;
  int local_20;
  int local_1c;
  CObject *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x8554cb;
  if (in_ECX[0x35e] == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x390);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != -1) {
      local_1c = iVar3;
      pCVar4 = (CObject *)FUN_007fde79();
      local_14 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarButton_00a00a80,pCVar4);
      if (local_14 != (CObject *)0x0) {
        if (param_3 != 0) {
          *(undefined4 *)(param_3 + 0xc) = *(undefined4 *)(local_14 + 0x20);
          *(int *)(param_3 + 8) = in_ECX[8];
          *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(local_14 + 0x54);
          *(undefined4 *)(param_3 + 0x14) = *(undefined4 *)(local_14 + 0x58);
          *(undefined4 *)(param_3 + 0x18) = *(undefined4 *)(local_14 + 0x5c);
          *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(local_14 + 0x60);
        }
        pcVar1 = *(code **)(*(int *)local_14 + 0x7c);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        if (iVar3 == 0) {
          iVar3 = *(int *)(local_14 + 0x20);
        }
        else {
          iVar3 = local_1c;
          if ((param_3 != 0) && (*(int *)(param_3 + 0x24) != 0)) {
            CStringT<>();
            local_8 = 0;
            pwVar2 = *(wchar_t **)(param_3 + 0x24);
            if (pwVar2 != (wchar_t *)0x0) {
              iVar3 = FUN_008f899d();
              ATL::CSimpleStringT<wchar_t,0>::SetString
                        ((CSimpleStringT<wchar_t,0> *)&local_20,pwVar2,iVar3);
              FUN_008f43b0();
            }
            CStringT<>();
            local_8 = CONCAT31(local_8._1_3_,1);
            piVar5 = (int *)FUN_0079296c();
            if (((piVar5 != (int *)0x0) && (piVar5[8] != 0)) && (iVar3 = FUN_0079d98a(), iVar3 == 0)
               ) {
              pcVar1 = *(code **)(*piVar5 + 0x174);
              guard_check_icall();
              (*pcVar1)();
            }
            iVar3 = in_ECX[0x342];
            FUN_004054a0(local_20 + -0x10);
            FUN_008197cb(param_3,iVar3,2);
            FUN_00406b10();
            FUN_00406b10();
            iVar3 = local_1c;
          }
        }
      }
    }
  }
  else {
    iVar3 = FUN_00802ae4(param_1);
  }
  return iVar3;
}




/* vtable slots: CMFCColorBar[273], CMFCPopupMenuBar[273] */
/* 00855700  FUN_00855700  113 bytes, 0 callers */

void FUN_00855700(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xdb0) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0xdb0) + 0xa4) = 0;
    iVar1 = *(int *)(in_ECX + 0xbf0);
    FUN_00804f82(*(undefined4 *)(in_ECX + 0xdb0));
    iVar2 = *(int *)(in_ECX + 0xbf8);
    *(undefined4 *)(in_ECX + 0xdb0) = 0;
    *(int *)(in_ECX + 0xbf0) = iVar2;
    if (iVar1 != iVar2) {
      if (-1 < iVar1) {
        FUN_007fe655(iVar1);
        iVar2 = *(int *)(in_ECX + 0xbf0);
      }
      FUN_007fe655(iVar2);
      UpdateWindow(*(HWND *)(in_ECX + 0x20));
    }
    KillTimer(*(HWND *)(in_ECX + 0x20),0xec18);
  }
  return;
}




/* vtable slots: CMFCColorBar[221], CMFCPopupMenuBar[221], CMFCRibbonPanelMenuBar[221] */
/* 00855771  FUN_00855771  228 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00855771(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  CObject *pCVar3;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_007fde79(param_1);
  if (iVar2 != 0) {
    uVar1 = *(uint *)(iVar2 + 0x24);
    if ((uVar1 != param_2) && (*(uint *)(iVar2 + 0x24) = param_2, (uVar1 & param_2 & 0x20000) == 0))
    {
      pCVar3 = (CObject *)FUN_007fde79(param_1);
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar3);
      if ((pCVar3 == (CObject *)0x0) || (((uVar1 ^ param_2) & 0x10000) == 0)) {
        if ((uVar1 ^ param_2) != 2) {
          FUN_007fe655(param_1);
        }
      }
      else {
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        FUN_00876aea(&local_18);
        InflateRect(&local_18,DAT_00a12218 * 2,DAT_00a1221c * 2);
        InvalidateRect(*(HWND *)(in_ECX + 0x20),&local_18,1);
        UpdateWindow(*(HWND *)(in_ECX + 0x20));
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCColorBar[44], CMFCPopupMenuBar[44], CMFCRibbonPanelMenuBar[44] */
/* 00855964  get_accRole  72 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCPopupMenuBar::get_accRole(struct tagVARIANT,struct
   tagVARIANT *)
   
   Library: Visual Studio 2015 Release */

long __thiscall
CMFCPopupMenuBar::get_accRole(CMFCPopupMenuBar *this,tagVARIANT param_1,tagVARIANT *param_2)

{
  long lVar1;
  
  if (param_2 == (tagVARIANT *)0x0) {
    lVar1 = -0x7ff8ffa9;
  }
  else if ((param_1.n1.n2.vt == 3) && (param_1.n1._8_4_ == 0)) {
    (param_2->n1).n2.vt = 3;
    *(undefined4 *)((int)&param_2->n1 + 8) = 0x16;
    lVar1 = 0;
  }
  else {
    lVar1 = FUN_007eee8d(param_1.n1._0_4_,param_1.n1.decVal.Hi32,param_1.n1._8_4_,param_1.n1._12_4_,
                         param_2);
  }
  return lVar1;
}




/* vtable slots: CMFCColorBar[45], CMFCPopupMenuBar[45], CMFCRibbonPanelMenuBar[45] */
/* 008559ac  get_accState  72 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCPopupMenuBar::get_accState(struct tagVARIANT,struct
   tagVARIANT *)
   
   Library: Visual Studio 2015 Release */

long __thiscall
CMFCPopupMenuBar::get_accState(CMFCPopupMenuBar *this,tagVARIANT param_1,tagVARIANT *param_2)

{
  long lVar1;
  
  if (param_2 == (tagVARIANT *)0x0) {
    lVar1 = -0x7ff8ffa9;
  }
  else if ((param_1.n1.n2.vt == 3) && (param_1.n1._8_4_ == 0)) {
    (param_2->n1).n2.vt = 3;
    *(undefined4 *)((int)&param_2->n1 + 8) = 0x100;
    lVar1 = 0;
  }
  else {
    lVar1 = FUN_007eeef4(param_1.n1._0_4_,param_1.n1.decVal.Hi32,param_1.n1._8_4_,param_1.n1._12_4_,
                         param_2);
  }
  return lVar1;
}



