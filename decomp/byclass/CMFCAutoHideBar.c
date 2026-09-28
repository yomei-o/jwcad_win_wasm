/* CMFCAutoHideBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCAutoHideBar[172], CMFCBaseToolBar[172], CMFCCaptionBar[172], CMFCColorBar[172], CMFCDropDownToolBar[172], CMFCImageEditorPaletteBar[172], CMFCMenuBar[172], CMFCOutlookBarPane[172], CMFCOutlookBarToolBar[172], CMFCPopupMenuBar[172], CMFCPrintPreviewToolBar[172], CMFCRibbonPanelMenuBar[172], CMFCTasksPaneToolBar[172], CMFCToolBar[172], CPane[172] */
/* 007c233d  FUN_007c233d  15 bytes, 0 callers */

void FUN_007c233d(undefined4 *param_1)

{
  *param_1 = 0;
  return;
}




/* vtable slots: CMFCAutoHideBar[196], CMFCBaseToolBar[196], CMFCCaptionBar[196], CMFCColorBar[196], CMFCDropDownToolBar[196], CMFCImageEditorPaletteBar[196], CMFCMenuBar[196], CMFCOutlookBarToolBar[196], CMFCPopupMenuBar[196], CMFCPrintPreviewToolBar[196], CMFCRibbonPanelMenuBar[196], CMFCTasksPaneToolBar[196], CMFCToolBar[196], CPane[196] */
/* 007ef852  FUN_007ef852  430 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007ef852(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((param_3 == 2) && (param_1 = (int *)in_ECX[0x81], param_1 == (int *)0x0)) {
    pcVar2 = *(code **)(*in_ECX + 0x19c);
    guard_check_icall();
    uVar3 = (*pcVar2)();
    FUN_0085a847(uVar3);
    FUN_00846e70(in_ECX,0,0);
LAB_007ef8af:
    uVar3 = 1;
  }
  else {
    pcVar2 = *(code **)(*in_ECX + 0x188);
    guard_check_icall(param_1);
    iVar4 = (*pcVar2)();
    if (iVar4 != 0) {
      pcVar2 = *(code **)(*param_1 + 0x184);
      guard_check_icall();
      iVar4 = (*pcVar2)();
      if (iVar4 != 0) {
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        SetRectEmpty(&local_18);
        GetWindowRect((HWND)in_ECX[8],&local_18);
        cVar1 = '\x01';
        pcVar2 = *(code **)(*in_ECX + 0x228);
        guard_check_icall(0);
        iVar4 = (*pcVar2)();
        if (iVar4 != 0) {
          cVar1 = *(char *)(iVar4 + 0xa5);
        }
        SendMessageW((HWND)param_1[8],0xb,0,0);
        pcVar2 = *(code **)(*in_ECX + 0x29c);
        guard_check_icall(param_1,param_3);
        (*pcVar2)();
        if (param_3 == 1) {
          pcVar2 = *(code **)(*(int *)in_ECX[0x2e] + 0x274);
          guard_check_icall();
          (*pcVar2)();
          if (cVar1 != '\0') {
            pcVar2 = *(code **)(*in_ECX + 0x2f0);
            guard_check_icall();
            (*pcVar2)();
          }
        }
        else if ((param_3 == 4) || (param_3 == 2)) {
          pcVar2 = *(code **)(*(int *)in_ECX[0x2e] + 0x274);
          guard_check_icall();
          (*pcVar2)();
        }
        SendMessageW((HWND)param_1[8],0xb,1,0);
        goto LAB_007ef8af;
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}




/* vtable slots: CMFCAutoHideBar[197], CMFCBaseToolBar[197], CMFCCaptionBar[197], CMFCColorBar[197], CMFCDropDownToolBar[197], CMFCImageEditorPaletteBar[197], CMFCMenuBar[197], CMFCOutlookBarPane[197], CMFCOutlookBarToolBar[197], CMFCPopupMenuBar[197], CMFCPrintPreviewToolBar[197], CMFCRibbonPanelMenuBar[197], CMFCTasksPaneToolBar[197], CMFCToolBar[197], CPane[197] */
/* 007efae2  FUN_007efae2  184 bytes, 1 callers */

void FUN_007efae2(int param_1)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  int *in_ECX;
  tagPOINT local_c;
  
  local_c.x = 0;
  local_c.y = 0;
  GetCursorPos(&local_c);
  FUN_007f2322();
  if (param_1 != 0) {
    pHVar3 = (HWND)in_ECX[8];
    ((LPPOINT)(in_ECX + 0x5a))->x = local_c.x;
    in_ECX[0x5b] = local_c.y;
    ScreenToClient(pHVar3,(LPPOINT)(in_ECX + 0x5a));
  }
  if ((char)in_ECX[0x5c] == '\0') {
    pcVar1 = *(code **)(*in_ECX + 0x168);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      pHVar3 = SetCapture((HWND)in_ECX[8]);
      CWnd::FromHandle(pHVar3);
      in_ECX[100] = local_c.x;
      in_ECX[0x65] = local_c.y;
      *(undefined1 *)(in_ECX + 0x5c) = 1;
      pcVar1 = *(code **)(*in_ECX + 0x30c);
      guard_check_icall(1);
      (*pcVar1)();
      GetWindowRect((HWND)in_ECX[8],(LPRECT)(in_ECX + 0x54));
    }
  }
  return;
}




/* vtable slots: CMFCAutoHideBar[173], CMFCBaseToolBar[173], CMFCCaptionBar[173], CMFCColorBar[173], CMFCDropDownToolBar[173], CMFCImageEditorPaletteBar[173], CMFCMenuBar[173], CMFCOutlookBarToolBar[173], CMFCPopupMenuBar[173], CMFCPrintPreviewToolBar[173], CMFCRibbonPanelMenuBar[173], CMFCTasksPaneToolBar[173], CMFCToolBar[173], CPane[173] */
/* 007f02b9  FUN_007f02b9  714 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007f02b9(int param_1,int *param_2)

{
  code *pcVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  CObject *pCVar5;
  BOOL BVar6;
  int iVar7;
  undefined4 uVar8;
  int *in_ECX;
  tagPOINT local_58;
  int iStack_4c;
  tagRECT local_48;
  RECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iStack_4c = param_1;
  if (param_2 == (int *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  local_58.x = 0;
  local_58.y = 0;
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  local_48.left = 0;
  local_48.top = 0;
  local_48.right = 0;
  local_48.bottom = 0;
  local_38.left = 0;
  local_38.top = 0;
  local_38.right = 0;
  local_38.bottom = 0;
  GetCursorPos(&local_58);
  GetWindowRect((HWND)in_ECX[8],&local_28);
  FUN_007f028e(&local_38);
  pCVar5 = (CObject *)FUN_007ee24c(local_58.x,local_58.y,param_1,0,&PTR_s_CDockSite_00997564);
  pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockSite_00997564,pCVar5);
  *param_2 = (int)pCVar5;
  if (in_ECX[0x2e] == 0) {
    if (pCVar5 != (CObject *)0x0) {
      pcVar1 = *(code **)(*in_ECX + 0x188);
      guard_check_icall(pCVar5);
      iVar7 = (*pcVar1)();
      if (iVar7 != 0) {
        GetWindowRect(*(HWND *)(*param_2 + 0x20),&local_18);
        BVar6 = PtInRect(&local_18,local_58);
        if (BVar6 != 0) goto LAB_007f0566;
        dVar2 = (double)iStack_4c;
        iStack_4c = 0;
        if (local_58.x < local_18.left) {
          dVar3 = (double)(local_28.right - local_58.x) * 100.0;
          dVar4 = (double)(local_28.right - local_28.left);
          iStack_4c = local_18.left - local_58.x;
LAB_007f054d:
          dVar2 = ((dVar3 / dVar4) / 100.0) * dVar2;
        }
        else {
          if (local_18.right < local_58.x) {
            dVar3 = (double)(local_58.x - local_28.left) * 100.0;
            dVar4 = (double)(local_28.right - local_28.left);
            iStack_4c = local_58.x - local_18.right;
            goto LAB_007f054d;
          }
          if (local_58.y < local_18.top) {
            dVar3 = (double)(local_28.bottom - local_58.y) * 100.0;
            dVar4 = (double)(local_28.bottom - local_28.top);
            iStack_4c = local_18.top - local_58.y;
            goto LAB_007f054d;
          }
          if (local_18.bottom < local_58.y) {
            dVar3 = (double)(local_58.y - local_28.top) * 100.0;
            dVar4 = (double)(local_28.bottom - local_28.top);
            iStack_4c = local_58.y - local_18.bottom;
            goto LAB_007f054d;
          }
        }
        iVar7 = (uint)(dVar2 < (double)iStack_4c) << 8;
        goto LAB_007f0564;
      }
    }
LAB_007f056b:
    uVar8 = 0;
  }
  else {
    GetWindowRect(*(HWND *)(in_ECX[0x2e] + 0x20),&local_18);
    BVar6 = IntersectRect(&local_48,&local_18,&local_38);
    if (BVar6 != 0) {
      param_1 = param_1 * 2;
      pcVar1 = *(code **)(*(int *)in_ECX[0x2e] + 0x164);
      guard_check_icall();
      iVar7 = (*pcVar1)();
      if (iVar7 == 0) {
        if ((local_18.top <= local_38.top) || (local_18.top - local_38.top <= param_1)) {
          if (local_18.bottom < local_38.bottom) {
            iVar7 = local_38.bottom - local_18.bottom;
            goto LAB_007f03f3;
          }
          goto LAB_007f056b;
        }
      }
      else if ((local_18.left <= local_38.left) || (local_18.left - local_38.left <= param_1)) {
        if (local_18.right < local_38.right) {
          iVar7 = local_38.right - local_18.right;
LAB_007f03f3:
          if (param_1 < iVar7) goto LAB_007f03fb;
        }
        goto LAB_007f056b;
      }
LAB_007f03fb:
      iVar7 = PtInRect(&local_18,local_58);
LAB_007f0564:
      if (iVar7 != 0) goto LAB_007f056b;
    }
LAB_007f0566:
    uVar8 = 1;
  }
  return uVar8;
}




/* vtable slots: CMFCAutoHideBar[139], CMFCBaseToolBar[139], CMFCCaptionBar[139], CPane[139] */
/* 007f068a  FUN_007f068a  509 bytes, 2 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x007f0856) */

undefined4 FUN_007f068a(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x7f0696;
  FUN_008592c1(&local_1c,L"Panes",param_1);
  uVar5 = 0;
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(local_14,L"%TsPane-%d",local_1c,param_2);
  }
  else {
    FUN_004059f0(local_14,L"%TsPane-%d%x",local_1c,param_2,param_3);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  piVar3 = (int *)FUN_00859490(0,1);
  pcVar1 = *(code **)(*piVar3 + 0x10);
  guard_check_icall(local_14[0]);
  iVar4 = (*pcVar1)();
  iVar2 = local_18;
  if (iVar4 != 0) {
    pcVar1 = *(code **)(*piVar3 + 0x54);
    guard_check_icall(&DAT_0098b0e0,local_18 + 0x180);
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 0x48);
    guard_check_icall(L"RectRecentFloat",iVar2 + 0x1e8);
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 0x48);
    guard_check_icall(L"RectRecentDocked",(undefined4 *)(iVar2 + 0x298));
    (*pcVar1)();
    *(undefined4 *)(local_18 + 0x218) = *(undefined4 *)(iVar2 + 0x298);
    *(undefined4 *)(local_18 + 0x21c) = *(undefined4 *)(iVar2 + 0x29c);
    *(undefined4 *)(local_18 + 0x220) = *(undefined4 *)(iVar2 + 0x2a0);
    *(undefined4 *)(local_18 + 0x224) = *(undefined4 *)(iVar2 + 0x2a4);
    pcVar1 = *(code **)(*piVar3 + 0x50);
    guard_check_icall(L"RecentFrameAlignment",local_18 + 0x1f8);
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 0x54);
    guard_check_icall(L"RecentRowIndex",local_18 + 0x200);
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 0x54);
    guard_check_icall(L"IsFloating",local_18 + 0x2a8);
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 0x54);
    guard_check_icall(L"MRUWidth",local_18 + 0x13c);
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 0x54);
    guard_check_icall(L"PinState",local_18 + 0x17c);
    (*pcVar1)();
    uVar5 = FUN_007edd93(param_1,param_2,param_3);
  }
  FUN_00406b10();
  FUN_00406b10();
  return uVar5;
}




/* vtable slots: CMFCAutoHideBar[136], CMFCCaptionBar[136], CPane[136] */
/* 007f0ac5  OnAfterChangeParent  55 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CPane::OnAfterChangeParent(class CWnd *)
   
   Library: Visual Studio 2015 Release */

void __thiscall CPane::OnAfterChangeParent(CPane *this,CWnd *param_1)

{
  HWND pHVar1;
  int iVar2;
  
  FUN_007f2322();
  pHVar1 = GetParent(*(HWND *)(this + 0x20));
  CWnd::FromHandle(pHVar1);
  iVar2 = FUN_0079d98a(&PTR_s_CDockSite_00997564);
  if (iVar2 == 0) {
    *(undefined4 *)(this + 0xb8) = 0;
    *(undefined4 *)(this + 0xbc) = 0;
  }
  return;
}




/* vtable slots: CMFCAutoHideBar[135], CMFCBaseToolBar[135], CMFCCaptionBar[135], CPane[135] */
/* 007f0b6a  FUN_007f0b6a  40 bytes, 2 callers */

void FUN_007f0b6a(void)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xb8) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xb8) + 0x27c);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCAutoHideBar[188], CMFCBaseToolBar[188], CMFCCaptionBar[188], CMFCColorBar[188], CMFCDropDownToolBar[188], CMFCImageEditorPaletteBar[188], CMFCMenuBar[188], CMFCOutlookBarPane[188], CMFCOutlookBarToolBar[188], CMFCPopupMenuBar[188], CMFCPrintPreviewToolBar[188], CMFCRibbonPanelMenuBar[188], CMFCTasksPaneToolBar[188], CMFCToolBar[188], CPane[188] */
/* 007f0ced  FUN_007f0ced  29 bytes, 0 callers */

void FUN_007f0ced(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x314);
  guard_check_icall(0);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCAutoHideBar[183], CMFCBaseToolBar[183], CMFCCaptionBar[183], CMFCColorBar[183], CMFCDropDownToolBar[183], CMFCImageEditorPaletteBar[183], CMFCMenuBar[183], CMFCOutlookBarPane[183], CMFCOutlookBarToolBar[183], CMFCPopupMenuBar[183], CMFCPrintPreviewToolBar[183], CMFCRibbonPanelMenuBar[183], CMFCTasksPaneToolBar[183], CMFCToolBar[183], CPane[183] */
/* 007f129c  FUN_007f129c  55 bytes, 0 callers */

void FUN_007f129c(void)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  uVar3 = 0;
  pcVar1 = *(code **)(*in_ECX + 0x228);
  guard_check_icall(0);
  piVar2 = (int *)(*pcVar1)();
  if (piVar2 != (int *)0x0) {
    pcVar1 = *(code **)(*piVar2 + 0x224);
    guard_check_icall(uVar3);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCAutoHideBar[140], CMFCBaseToolBar[140], CMFCCaptionBar[140], CPane[140] */
/* 007f1cfe  FUN_007f1cfe  645 bytes, 2 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* WARNING: Removing unreachable block (ram,0x007f1f52) */

undefined4 FUN_007f1cfe(undefined4 param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 local_1c;
  undefined4 local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x7f1d0a;
  FUN_008592c1(&local_1c,L"Panes",param_1);
  local_8 = 0;
  if (param_2 == -1) {
    param_2 = FUN_00797a2b();
  }
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,1);
  if (param_3 == -1) {
    FUN_004059f0(&local_18,L"%TsPane-%d",local_1c,param_2);
  }
  else {
    FUN_004059f0(&local_18,L"%TsPane-%d%x",local_1c,param_2,param_3);
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  local_14 = (int *)FUN_00859490(0,0);
  pcVar1 = *(code **)(*local_14 + 0xc);
  guard_check_icall(local_18);
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x170);
    guard_check_icall(local_18);
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      FUN_007ef47b();
      if ((int *)in_ECX[0x2e] != (int *)0x0) {
        pcVar1 = *(code **)(*(int *)in_ECX[0x2e] + 0x194);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        in_ECX[0x7e] = iVar3;
        iVar3 = FUN_008610e8(in_ECX[0x2f]);
        in_ECX[0x80] = iVar3;
      }
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x228);
      guard_check_icall(0);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        GetWindowRect(*(HWND *)(iVar3 + 0x20),(LPRECT)(in_ECX + 0x7a));
      }
    }
    pcVar1 = *(code **)(*local_14 + 0x38);
    guard_check_icall(&DAT_0098b0e0,in_ECX[0x60]);
    (*pcVar1)();
    pcVar1 = *(code **)(*local_14 + 0x2c);
    guard_check_icall(L"RectRecentFloat",in_ECX + 0x7a);
    (*pcVar1)();
    pcVar1 = *(code **)(*local_14 + 0x2c);
    guard_check_icall(L"RectRecentDocked",in_ECX + 0x86);
    (*pcVar1)();
    pcVar1 = *(code **)(*local_14 + 0x34);
    guard_check_icall(L"RecentFrameAlignment",in_ECX[0x7e]);
    (*pcVar1)();
    pcVar1 = *(code **)(*local_14 + 0x38);
    guard_check_icall(L"RecentRowIndex",in_ECX[0x80]);
    (*pcVar1)();
    pcVar1 = *(code **)(*local_14 + 0x38);
    guard_check_icall(L"IsFloating",iVar2);
    (*pcVar1)();
    pcVar1 = *(code **)(*local_14 + 0x38);
    guard_check_icall(L"MRUWidth",in_ECX[0x4f]);
    (*pcVar1)();
    pcVar1 = *(code **)(*local_14 + 0x38);
    guard_check_icall(L"PinState",in_ECX[0x5f]);
    (*pcVar1)();
  }
  uVar4 = FUN_007ee520(param_1,param_2,param_3);
  FUN_00406b10();
  FUN_00406b10();
  return uVar4;
}




/* vtable slots: CMFCAutoHideBar[199], CMFCBaseToolBar[199], CMFCCaptionBar[199], CMFCColorBar[199], CMFCDropDownToolBar[199], CMFCImageEditorPaletteBar[199], CMFCMenuBar[199], CMFCOutlookBarPane[199], CMFCOutlookBarToolBar[199], CMFCPopupMenuBar[199], CMFCPrintPreviewToolBar[199], CMFCRibbonPanelMenuBar[199], CMFCTasksPaneToolBar[199], CMFCToolBar[199], CPane[199] */
/* 007f20ab  FUN_007f20ab  51 bytes, 0 callers */

void FUN_007f20ab(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x208) = *(undefined4 *)(in_ECX + 0xbc);
  *(int *)(in_ECX + 0x204) = *(int *)(in_ECX + 0xb8);
  if (*(int *)(in_ECX + 0xb8) != 0) {
    uVar1 = FUN_008610e8(*(undefined4 *)(in_ECX + 0xbc));
    *(undefined4 *)(in_ECX + 0x200) = uVar1;
  }
  FUN_007ef47b();
  return;
}




/* vtable slots: CMFCAutoHideBar[144], CMFCBaseToolBar[144], CMFCCaptionBar[144], CMFCColorBar[144], CMFCDropDownToolBar[144], CMFCImageEditorPaletteBar[144], CMFCMenuBar[144], CMFCOutlookBarPane[144], CMFCOutlookBarToolBar[144], CMFCPopupMenuBar[144], CMFCPrintPreviewToolBar[144], CMFCRibbonPanelMenuBar[144], CMFCTasksPaneToolBar[144], CMFCToolBar[144], CPane[144] */
/* 007f2212  FUN_007f2212  76 bytes, 0 callers */

void FUN_007f2212(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  if ((int *)in_ECX[0x2e] != (int *)0x0) {
    pcVar1 = *(code **)(*(int *)in_ECX[0x2e] + 0x27c);
    guard_check_icall();
    (*pcVar1)();
  }
  if (param_1 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x268);
    guard_check_icall(0);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCAutoHideBar[1] */
/* 008b93a7  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCAutoHideBar::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCAutoHideBar::_scalar_deleting_destructor_(CMFCAutoHideBar *this,uint param_1)

{
  FUN_008b933c();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x2e8);
    }
  }
  return this;
}




/* vtable slots: CMFCAutoHideBar[178] */
/* 008b966b  FUN_008b966b  56 bytes, 0 callers */

void FUN_008b966b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = FUN_007e568a(param_4);
  if (iVar1 != 0) {
    Create(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCAutoHideBar[153] */
/* 008b96d4  FUN_008b96d4  233 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008b96d4(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  undefined1 *puVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  int local_54 [2];
  undefined1 *local_4c;
  int local_48;
  undefined1 local_40 [56];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x8b96e0;
  FUN_007e522a(param_1,in_ECX);
  local_8 = 0;
  puVar4 = local_40;
  if (local_48 == 0) {
    puVar4 = local_4c;
  }
  FUN_007ed642(puVar4);
  local_54[0] = *(int *)(in_ECX + 700);
  piVar5 = (int *)0x0;
  if (local_54[0] != 0) {
    do {
      piVar2 = (int *)FUN_0044f2d0(local_54);
      piVar2 = (int *)*piVar2;
      piVar6 = piVar2;
      if (piVar2[1] == 0) {
        pcVar1 = *(code **)(*piVar2 + 0x14);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        piVar6 = piVar5;
        if (iVar3 != 0) {
          pcVar1 = *(code **)(*piVar2 + 0x20);
          puVar4 = local_40;
          if (local_48 == 0) {
            puVar4 = local_4c;
          }
          guard_check_icall(puVar4);
          (*pcVar1)();
        }
      }
      piVar5 = piVar6;
    } while (local_54[0] != 0);
    if (piVar6 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar6 + 0x14);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        pcVar1 = *(code **)(*piVar6 + 0x20);
        puVar4 = local_40;
        if (local_48 == 0) {
          puVar4 = local_4c;
        }
        guard_check_icall(puVar4);
        (*pcVar1)();
      }
    }
  }
  FUN_007e54da();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCAutoHideBar[10] */
/* 008b97da  FUN_008b97da  6 bytes, 0 callers */

undefined ** FUN_008b97da(void)

{
  return &PTR_FUN_009a2740;
}




/* vtable slots: CMFCAutoHideBar[0] */
/* 008b97e0  FUN_008b97e0  6 bytes, 0 callers */

undefined ** FUN_008b97e0(void)

{
  return &PTR_s_CMFCAutoHideBar_009a2344;
}




/* vtable slots: CMFCAutoHideBar[164] */
/* 008b9bef  FUN_008b9bef  199 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008b9bef(int param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  CObject *in_ECX;
  undefined4 *puVar3;
  CObList local_44 [4];
  undefined4 *local_40;
  CObject *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_8 = 0x8b9bfb;
  FUN_007f1f83(param_1);
  if (param_1 != 0) {
    CObList::CObList(local_44,10);
    local_8 = 0;
    FUN_00857673(in_ECX,local_44);
    puVar3 = local_40;
    while (puVar3 != (undefined4 *)0x0) {
      if (puVar3 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      puVar1 = puVar3 + 2;
      puVar3 = (undefined4 *)*puVar3;
      local_28 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPane_0098ac24,(CObject *)*puVar1);
      if (local_28 != in_ECX) {
        pcVar2 = *(code **)(*(int *)local_28 + 0x290);
        guard_check_icall(0);
        (*pcVar2)();
      }
    }
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    SetRectEmpty(&local_24);
    pcVar2 = *(code **)(**(int **)(in_ECX + 0xb8) + 0x298);
    guard_check_icall(&local_24);
    (*pcVar2)();
    FUN_007a184a();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCAutoHideBar[130] */
/* 008b9cf2  FUN_008b9cf2  167 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_008b9cf2(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_24 [8];
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect((HWND)in_ECX[8],&local_18);
  *param_1 = 0;
  uVar3 = 0;
  param_1[1] = 0;
  uVar4 = 0;
  local_1c = in_ECX[0xaf];
  if (local_1c != 0) {
    do {
      FUN_0044f2d0(&local_1c);
      puVar2 = (undefined4 *)FUN_0087a328(local_24);
      uVar3 = puVar2[1];
      *param_1 = *puVar2;
      param_1[1] = uVar3;
    } while (local_1c != 0);
    uVar4 = *param_1;
  }
  pcVar1 = *(code **)(*in_ECX + 0x238);
  guard_check_icall(0,0,0,uVar4,uVar3,6,0);
  (*pcVar1)();
  return param_1;
}



