/* CDockablePane -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDockablePane[127], CDockablePaneAdapter[127], CDummyDockablePane[127], CMFCAutoHideBar[127], CMFCBaseToolBar[127], CMFCCaptionBar[127], CMFCColorBar[127], CMFCDropDownToolBar[127], CMFCImageEditorPaletteBar[127], CMFCMenuBar[127], CMFCOutlookBarPane[127], CMFCOutlookBarPaneAdapter[127], CMFCOutlookBarToolBar[127], CMFCPopupMenuBar[127], CMFCPrintPreviewToolBar[127], CMFCRibbonPanelMenuBar[127], CMFCTasksPane[127], CMFCTasksPaneToolBar[127], CMFCToolBar[127], CPane[127] */
/* 007efb9a  FUN_007efb9a  1364 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007efb9a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            ,char param_6)

{
  code *pcVar1;
  int iVar2;
  CWnd *pCVar3;
  int *piVar4;
  undefined4 uVar5;
  HWND pHVar6;
  CWnd *pCVar7;
  uint uVar8;
  int *in_ECX;
  int *piVar9;
  undefined *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  tagPOINT local_58;
  int *local_50;
  tagPOINT local_4c;
  CWnd *local_44;
  tagPOINT local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*in_ECX + 0x168);
  local_44 = (CWnd *)in_ECX;
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x16c);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      return 1;
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0x1cc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    GetWindowRect((HWND)in_ECX[8],&local_28);
    pcVar1 = *(code **)(*in_ECX + 0x19c);
    guard_check_icall();
    pCVar3 = (CWnd *)(*pcVar1)();
    CWnd::ScreenToClient(pCVar3,&local_28);
    local_4c.x = 0;
    local_4c.y = 0;
    GetCursorPos(&local_4c);
    local_40.x = in_ECX[0x5a];
    local_40.y = in_ECX[0x5b];
    ClientToScreen((HWND)in_ECX[8],&local_40);
    pcVar1 = *(code **)(*in_ECX + 0x2c0);
    guard_check_icall(&param_1,param_5);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      local_38 = 0x10;
      local_34 = 0x10;
      local_30 = 0x10;
      local_2c = 0x10;
      FUN_00859dec(&param_1,&local_38);
      pcVar1 = *(code **)(*in_ECX + 0x214);
      guard_check_icall(param_1,param_2,param_3,param_4);
      piVar4 = (int *)(*pcVar1)();
      pCVar3 = local_44;
      if (piVar4 == (int *)0x0) {
        return 0;
      }
      pcVar1 = *(code **)(*(int *)local_44 + 0x19c);
      local_50 = piVar4;
      guard_check_icall();
      uVar5 = (*pcVar1)();
      iVar2 = FUN_0085a847(uVar5);
      if (((param_5 != 1) && (iVar2 != 0)) && (DAT_00a13b28 == 0)) {
        pcVar1 = *(code **)(*(int *)local_44 + 0x31c);
        guard_check_icall();
        (*pcVar1)();
      }
      piVar9 = local_50;
      uVar5 = 0;
      piVar4[0x36] = *(int *)((int)local_44 + 0x1e8);
      piVar4[0x37] = *(int *)((int)local_44 + 0x1ec);
      piVar4[0x38] = *(int *)((int)local_44 + 0x1f0);
      piVar4[0x39] = *(int *)((int)local_44 + 500);
      pcVar1 = *(code **)(*(int *)local_44 + 0x21c);
      piVar4 = local_50;
      guard_check_icall(local_50,0);
      (*pcVar1)();
      local_58.x = local_4c.x;
      local_58.y = local_4c.y;
      ScreenToClient(*(HWND *)((int)local_44 + 0x20),&local_58);
      if (param_5 == 1) {
        SendMessageW(*(HWND *)((int)local_44 + 0x20),0x202,0xffff,
                     CONCAT22((undefined2)local_58.y,(undefined2)local_58.x));
        pcVar1 = *(code **)(*(int *)local_44 + 0x16c);
        guard_check_icall(piVar4,uVar5);
        iVar2 = (*pcVar1)();
        if (iVar2 != 0) {
          pcVar1 = *(code **)(*(int *)local_44 + 0x228);
          guard_check_icall(0);
          iVar2 = (*pcVar1)();
          if (iVar2 != 0) {
            SendMessageW(*(HWND *)(iVar2 + 0x20),0x202,0,
                         CONCAT22((undefined2)local_58.y,(undefined2)local_58.x));
          }
        }
      }
      pHVar6 = GetParent(*(HWND *)((int)local_44 + 0x20));
      pCVar7 = CWnd::FromHandle(pHVar6);
      piVar4 = (int *)((int)local_44 + 0x20);
      local_44 = pCVar7;
      pHVar6 = SetParent((HWND)*piVar4,(HWND)piVar9[8]);
      CWnd::FromHandle(pHVar6);
      iVar2 = *(int *)pCVar3;
      if (*(int *)((int)pCVar3 + 0xb8) == 0) {
        guard_check_icall(local_44);
        (**(code **)(iVar2 + 0x220))();
      }
      else {
        guard_check_icall(*(int *)((int)pCVar3 + 0xb8));
        (**(code **)(iVar2 + 0x220))();
        *(int *)((int)pCVar3 + 0xb8) = 0;
      }
      pcVar1 = *(code **)(*piVar9 + 0x178);
      guard_check_icall(pCVar3);
      (*pcVar1)();
      pcVar1 = *(code **)(*piVar9 + 0x188);
      guard_check_icall();
      (*pcVar1)();
      uVar15 = 0;
      uVar14 = 0x11;
      uVar13 = 0;
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x238);
      uVar12 = 0;
      uVar11 = 0;
      uVar5 = 0;
      puVar10 = &DAT_00a11c68;
      guard_check_icall(&DAT_00a11c68,0,0,0,0,0x11,0);
      (*pcVar1)();
      if (param_5 == 1) {
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x1b8);
        guard_check_icall(puVar10,uVar5,uVar11,uVar12,uVar13,uVar14,uVar15);
        uVar8 = (*pcVar1)();
        if ((uVar8 & 1) != 0) {
          pcVar1 = *(code **)(*piVar9 + 0x210);
          guard_check_icall(0);
          (*pcVar1)();
          *(undefined1 *)(piVar9 + 0x20) = 1;
        }
      }
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x2c4);
      guard_check_icall(puVar10,uVar5,uVar11,uVar12,uVar13,uVar14,uVar15);
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x1c0);
      guard_check_icall();
      uVar8 = (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x1e4);
      guard_check_icall(uVar8 | 1);
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x210);
      guard_check_icall();
      (*pcVar1)();
      if (param_6 != '\0') {
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x228);
        guard_check_icall(0);
        piVar4 = (int *)(*pcVar1)();
        pcVar1 = *(code **)(*piVar4 + 0x1d0);
        guard_check_icall();
        (*pcVar1)();
        piVar9 = local_50;
      }
      if (param_5 == 1) {
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        GetWindowRect((HWND)piVar9[8],&local_18);
        local_40.x = *(int *)((int)pCVar3 + 0x168);
        local_40.y = *(int *)((int)pCVar3 + 0x16c);
        ClientToScreen((HWND)piVar9[8],&local_40);
        if ((local_18.right < local_40.x) || (local_40.x < local_18.left)) {
          local_40.x = (local_18.right - local_18.left) / 2 + local_18.left;
        }
        if ((local_18.bottom < local_40.y) || (local_40.y < local_18.top)) {
          pcVar1 = *(code **)(*piVar9 + 0x170);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          local_40.y = iVar2 / 2 + local_18.top;
        }
        OffsetRect(&local_18,local_4c.x - local_40.x,local_4c.y - local_40.y);
        FUN_00797e71(0,local_18.left,local_18.top,local_18.right - local_18.left,
                     local_18.bottom - local_18.top,0x14);
        piVar9[0x4c] = local_4c.x;
        piVar9[0x4d] = local_4c.y;
      }
      if (param_6 != '\0') {
        FUN_00797f20(8);
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x19c);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        RedrawWindow(*(HWND *)(iVar2 + 0x20),&local_28,(HRGN)0x0,0x5b1);
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x19c);
        guard_check_icall();
        (*pcVar1)();
        iVar2 = FUN_0079d98a(&PTR_s_COleCntrFrameWndEx_00996120);
        if (iVar2 != 0) {
          pcVar1 = *(code **)(*(int *)pCVar3 + 0x19c);
          guard_check_icall();
          piVar4 = (int *)(*pcVar1)();
          pcVar1 = *(code **)(*piVar4 + 0x1c4);
          guard_check_icall(0);
          (*pcVar1)();
        }
        pcVar1 = *(code **)(*(int *)pCVar3 + 0x1d8);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 != 0) {
          FUN_00797df8();
        }
      }
    }
  }
  return 1;
}




/* vtable slots: CDockablePane[156], CDockablePaneAdapter[156], CDummyDockablePane[156], CMFCAutoHideBar[156], CMFCCaptionBar[156], CMFCOutlookBarPaneAdapter[156], CMFCTasksPane[156], CPane[156] */
/* 007f0256  FUN_007f0256  27 bytes, 0 callers */

void FUN_007f0256(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0x164);
  *param_1 = *(undefined4 *)(in_ECX + 0x160);
  param_1[1] = uVar1;
  return;
}




/* vtable slots: CDockablePane[132], CDockablePaneAdapter[132], CDummyDockablePane[132], CMFCAutoHideBar[132], CMFCBaseToolBar[132], CMFCColorBar[132], CMFCDropDownToolBar[132], CMFCImageEditorPaletteBar[132], CMFCMenuBar[132], CMFCOutlookBarPane[132], CMFCOutlookBarPaneAdapter[132], CMFCOutlookBarToolBar[132], CMFCPopupMenuBar[132], CMFCPrintPreviewToolBar[132], CMFCRibbonPanelMenuBar[132], CMFCTasksPane[132], CMFCTasksPaneToolBar[132], CMFCToolBar[132], CPane[132] */
/* 007f1bb9  FUN_007f1bb9  103 bytes, 1 callers */

void FUN_007f1bb9(void)

{
  code *pcVar1;
  int *piVar2;
  HWND pHVar3;
  int iVar4;
  int *in_ECX;
  
  if (in_ECX[0x2f] != 0) {
    FUN_007f2322();
    return;
  }
  pcVar1 = *(code **)(*in_ECX + 0x228);
  guard_check_icall(0);
  piVar2 = (int *)(*pcVar1)();
  pHVar3 = GetParent((HWND)in_ECX[8]);
  CWnd::FromHandle(pHVar3);
  if (piVar2 != (int *)0x0) {
    iVar4 = FUN_0079d98a(&PTR_s_CMFCTabCtrl_0098d8b8);
    if (iVar4 == 0) {
      pcVar1 = *(code **)(*piVar2 + 0x1cc);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CDockablePane[203], CDockablePaneAdapter[203], CDummyDockablePane[203], CMFCOutlookBarPaneAdapter[203], CMFCTasksPane[203] */
/* 0085ec58  FUN_0085ec58  25 bytes, 0 callers */

void FUN_0085ec58(LPRECT param_1,LPRECT param_2)

{
  SetRectEmpty(param_1);
  SetRectEmpty(param_2);
  return;
}




/* vtable slots: CDockablePane[1], CDummyDockablePane[1] */
/* 0085f70c  FUN_0085f70c  51 bytes, 0 callers */

void FUN_0085f70c(byte param_1)

{
  CDockablePane *in_ECX;
  
  CDockablePane::~CDockablePane(in_ECX);
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




/* vtable slots: CDockablePane[184], CDockablePaneAdapter[184], CDummyDockablePane[184], CMFCOutlookBarPaneAdapter[184], CMFCTasksPane[184] */
/* 0088d48f  FUN_0088d48f  176 bytes, 0 callers */

void FUN_0088d48f(undefined4 param_1)

{
  int iVar1;
  CObject *pCVar2;
  int *in_ECX;
  code *pcVar3;
  
  pcVar3 = *(code **)(*in_ECX + 0x1dc);
  guard_check_icall();
  iVar1 = (*pcVar3)();
  if (iVar1 == 0) {
    pcVar3 = *(code **)(*in_ECX + 0x19c);
    guard_check_icall();
    pCVar2 = (CObject *)(*pcVar3)();
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar2);
    if (pCVar2 != (CObject *)0x0) {
      pcVar3 = *(code **)(*in_ECX + 0x16c);
      guard_check_icall();
      iVar1 = (*pcVar3)();
      if (iVar1 == 0) {
        pcVar3 = *(code **)(*(int *)pCVar2 + 0x1d4);
        guard_check_icall();
      }
      else {
        pCVar2 = (CObject *)FUN_007ed94f();
        pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CTabbedPane_00a009a4,pCVar2);
        if (pCVar2 == (CObject *)0x0) {
          return;
        }
        pcVar3 = *(code **)(*(int *)pCVar2 + 0x2e0);
        guard_check_icall(param_1);
      }
      (*pcVar3)();
    }
  }
  return;
}




/* vtable slots: CDockablePane[196], CDockablePaneAdapter[196], CDummyDockablePane[196], CMFCOutlookBarPaneAdapter[196], CMFCTasksPane[196] */
/* 0088d936  FUN_0088d936  818 bytes, 1 callers */

uint FUN_0088d936(CPaneDivider *param_1,CPaneDivider *param_2,int param_3)

{
  CObject *pCVar1;
  int iVar2;
  undefined4 uVar3;
  CPaneDivider *pCVar4;
  uint uVar5;
  CPaneDivider *in_ECX;
  code *pcVar6;
  tagPOINT local_1c;
  CPaneDivider *local_14;
  tagPOINT local_10;
  int local_8;
  
  pCVar1 = (CObject *)FUN_007e5618();
  AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,pCVar1);
  if (param_1 != (CPaneDivider *)0x0) {
    pcVar6 = *(code **)(*(int *)param_1 + 0x184);
    guard_check_icall();
    iVar2 = (*pcVar6)();
    if ((iVar2 == 0) && (param_1 != in_ECX)) {
      return 0;
    }
  }
  if ((param_3 != 4) || (param_2 != (CPaneDivider *)0x0)) {
    in_ECX[0x2c8] = (CPaneDivider)0x0;
    if ((param_3 == 2) || (param_3 == 3)) {
      local_10.y = FUN_0085f286(1);
      FUN_00797f20(0);
      pcVar6 = *(code **)(*(int *)in_ECX + 0x308);
      uVar3 = FUN_007e5618();
      guard_check_icall(uVar3,param_3);
      (*pcVar6)();
      pcVar6 = *(code **)(*(int *)in_ECX + 0x1e0);
      guard_check_icall(*(int *)(in_ECX + 0x1f8));
      (*pcVar6)();
      pCVar4 = CRecentDockSiteInfo::GetRecentDefaultPaneDivider
                         ((CRecentDockSiteInfo *)(in_ECX + 0x1e4));
      local_14 = pCVar4;
      if (pCVar4 != (CPaneDivider *)0x0) {
        FUN_008912c6(*(undefined4 *)(pCVar4 + 0x20));
      }
      if (local_10.y != 0) {
        iVar2 = FUN_0085f2fe(1);
        if (iVar2 == 0) {
          iVar2 = *(int *)(local_10.y + 8);
        }
        else {
          iVar2 = *(int *)(local_10.y + 4);
        }
        if (iVar2 != 0) {
          pcVar6 = *(code **)(*(int *)in_ECX + 0x34c);
          guard_check_icall(iVar2,2,1,0);
          iVar2 = (*pcVar6)();
          local_14 = (CPaneDivider *)(uint)(iVar2 != 0);
          if (iVar2 != 0) {
            pcVar6 = *(code **)(*(int *)in_ECX + 0x224);
            guard_check_icall(1,0,1);
            (*pcVar6)();
          }
          pcVar6 = *(code **)(*(int *)in_ECX + 0x268);
          guard_check_icall(0);
          (*pcVar6)();
          return (uint)local_14;
        }
      }
      if (pCVar4 == (CPaneDivider *)0x0) {
        FUN_00797f20(5);
        pcVar6 = *(code **)(*(int *)in_ECX + 0x200);
        if (param_2 == (CPaneDivider *)0x0) {
          param_2 = in_ECX + 0x218;
        }
        pCVar4 = (CPaneDivider *)0x0;
        iVar2 = *(int *)(in_ECX + 0x1f8);
LAB_0088dc55:
        guard_check_icall(iVar2,param_2,1,0,0xffffffff,pCVar4);
        uVar5 = (*pcVar6)();
        return uVar5;
      }
      pcVar6 = *(code **)(*(int *)in_ECX + 0x1f0);
      guard_check_icall(1);
      (*pcVar6)();
      pcVar6 = *(code **)(*(int *)in_ECX + 900);
      guard_check_icall(local_14);
      (*pcVar6)();
      pCVar4 = local_14;
      FUN_007ed9e1(in_ECX,local_14,0);
      FUN_00797f20(5);
      pcVar6 = *(code **)(*(int *)pCVar4 + 0x274);
      guard_check_icall();
      local_14 = (CPaneDivider *)(*pcVar6)();
      if (local_14 == in_ECX) {
        pcVar6 = *(code **)(*(int *)in_ECX + 0x268);
        guard_check_icall(0);
        (*pcVar6)();
        return 1;
      }
      if (local_14 != (CPaneDivider *)0x0) {
        pcVar6 = *(code **)(*(int *)local_14 + 0x268);
        guard_check_icall(0);
        (*pcVar6)();
      }
    }
    else {
      local_1c.x = 0;
      local_1c.y = 0;
      if ((param_3 == 1) || (param_3 == 5)) {
        GetCursorPos(&local_1c);
      }
      local_8 = 0;
      if (param_1 == (CPaneDivider *)0x0) {
        local_14 = (CPaneDivider *)0x0;
        if ((param_3 == 1) || (param_3 == 5)) {
          local_10.x = 0;
          local_10.y = 0;
          GetCursorPos(&local_10);
          iVar2 = FUN_007edb9f(local_10.x,local_10.y,&local_8,&local_14);
          if (iVar2 != 0) {
            pcVar6 = *(code **)(*(int *)in_ECX + 0x200);
            param_2 = (CPaneDivider *)0x0;
            iVar2 = local_8;
            pCVar4 = local_14;
            goto LAB_0088dc55;
          }
        }
      }
      else if ((param_3 == 1) || (param_3 == 5)) {
        iVar2 = FUN_0085a399(local_1c.x,local_1c.y,param_1,DAT_00a0091c,0,0,&local_8,0xf000,0);
        if (iVar2 != 0) {
          param_2 = (CPaneDivider *)0x0;
          goto LAB_0088da7b;
        }
      }
      else if (param_2 != (CPaneDivider *)0x0) {
LAB_0088da7b:
        pcVar6 = *(code **)(*(int *)in_ECX + 0x354);
        guard_check_icall(param_1,local_8,param_2);
        uVar5 = (*pcVar6)();
        return uVar5;
      }
    }
  }
  return 0;
}




/* vtable slots: CDockablePane[10] */
/* 0088e93b  FUN_0088e93b  6 bytes, 0 callers */

undefined * FUN_0088e93b(void)

{
  return &DAT_0099c528;
}




/* vtable slots: CDockablePane[0], CDummyDockablePane[0] */
/* 0088e941  FUN_0088e941  6 bytes, 0 callers */

undefined ** FUN_0088e941(void)

{
  return &PTR_s_CDockablePane_00a00b9c;
}




/* vtable slots: CDockablePane[139], CDummyDockablePane[139] */
/* 0088ec45  FUN_0088ec45  9 bytes, 3 callers */

void FUN_0088ec45(void)

{
  FUN_007f068a();
  return;
}




/* vtable slots: CDockablePane[140], CDummyDockablePane[140] */
/* 00890e4a  FUN_00890e4a  9 bytes, 3 callers */

void FUN_00890e4a(void)

{
  FUN_007f1cfe();
  return;
}




/* vtable slots: CDockablePane[2], CDockablePaneAdapter[2], CDummyDockablePane[2], CMFCOutlookBarPaneAdapter[2] */
/* 00890e53  FUN_00890e53  209 bytes, 2 callers */

void FUN_00890e53(CArchive *param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  FUN_007ee62d(param_1);
  if (((byte)param_1[0x18] & 1) == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x170);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      FUN_007ef47b();
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x228);
      guard_check_icall(0);
      iVar2 = (*pcVar1)();
      if (iVar2 != 0) {
        GetWindowRect(*(HWND *)(iVar2 + 0x20),(LPRECT)(in_ECX + 0x7a));
      }
    }
    FUN_007a6b47(in_ECX + 0x7a,0x10);
    FUN_007a6b47(in_ECX + 0x86,0x10);
    CArchive::operator<<(param_1,in_ECX[0xaa]);
  }
  else {
    CArchive::EnsureRead(param_1,in_ECX + 0x7a,0x10);
    CArchive::EnsureRead(param_1,in_ECX + 0xa6,0x10);
    in_ECX[0x86] = in_ECX[0xa6];
    in_ECX[0x87] = in_ECX[0xa7];
    in_ECX[0x88] = in_ECX[0xa8];
    in_ECX[0x89] = in_ECX[0xa9];
    CArchive::operator>>(param_1,in_ECX + 0xaa);
  }
  return;
}




/* vtable slots: CDockablePane[218], CDockablePaneAdapter[218], CDummyDockablePane[218], CMFCOutlookBarPaneAdapter[218], CMFCTasksPane[218] */
/* 00890f24  FUN_00890f24  724 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00890f24(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  CWnd *this;
  CPaneDivider *pCVar4;
  int *piVar5;
  uint uVar6;
  UINT_PTR UVar7;
  CObject *pCVar8;
  CDockablePane *in_ECX;
  undefined4 uVar9;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x1dc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (param_1 != iVar2) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x19c);
    guard_check_icall();
    uVar3 = (*pcVar1)();
    FUN_0085a847(uVar3);
    if (param_1 == 0) {
      if (*(int **)(in_ECX + 0x330) != (int *)0x0) {
        pcVar1 = *(code **)(**(int **)(in_ECX + 0x330) + 0x1a0);
        guard_check_icall();
        pCVar8 = (CObject *)(*pcVar1)();
        pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CAutoHideDockSite_009a2e90,pCVar8);
        if (pCVar8 != (CObject *)0x0) {
          FUN_008c1b2a(*(undefined4 *)(in_ECX + 0x330));
        }
      }
    }
    else {
      *(undefined4 *)(in_ECX + 0x2f8) = 1;
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
      pcVar1 = *(code **)(*(int *)in_ECX + 0x19c);
      guard_check_icall();
      this = (CWnd *)(*pcVar1)();
      CWnd::ScreenToClient(this,&local_18);
      pcVar1 = *(code **)(*(int *)in_ECX + 0x31c);
      guard_check_icall();
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)in_ECX + 0x240);
      guard_check_icall(0);
      (*pcVar1)();
      pCVar4 = CDockablePane::GetDefaultPaneDivider(in_ECX);
      if (pCVar4 != (CPaneDivider *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      uVar9 = 0;
      pcVar1 = *(code **)(*(int *)in_ECX + 0x19c);
      guard_check_icall(0);
      uVar3 = (*pcVar1)();
      piVar5 = (int *)FUN_0088d62f(param_2,uVar3,uVar9);
      if (piVar5 == (int *)0x0) {
        pcVar1 = *(code **)(*(int *)in_ECX + 0x1f8);
        guard_check_icall();
        (*pcVar1)();
        param_3 = 0;
      }
      else {
        *(int *)(in_ECX + 0x350) = piVar5[8];
        piVar5[0x4c] = 1;
        pcVar1 = *(code **)(*piVar5 + 0x270);
        guard_check_icall();
        (*pcVar1)();
        pcVar1 = *(code **)(*(int *)in_ECX + 0x1e0);
        guard_check_icall(param_2);
        (*pcVar1)();
        pcVar1 = *(code **)(*piVar5 + 0x1e0);
        guard_check_icall(param_2);
        (*pcVar1)();
        param_3 = FUN_00845d9d(in_ECX,param_3);
        uVar6 = FUN_00797b3d();
        if ((uVar6 & 0x10000000) == 0) {
          FUN_00797f20(5);
        }
        else {
          RedrawWindow((HWND)piVar5[8],(RECT *)0x0,(HRGN)0x0,0x585);
          RedrawWindow(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,(HRGN)0x0,0x585);
          pcVar1 = *(code **)(*(int *)in_ECX + 0x19c);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          RedrawWindow(*(HWND *)(iVar2 + 0x20),&local_18,(HRGN)0x0,0x181);
        }
        if (param_4 == 0) {
          pcVar1 = *(code **)(*(int *)in_ECX + 0x344);
          guard_check_icall(0);
          (*pcVar1)();
        }
        else {
          UVar7 = SetTimer(*(HWND *)(in_ECX + 0x20),0xec03,DAT_00a00bb8,(TIMERPROC)0x0);
          *(UINT_PTR *)(in_ECX + 0x2fc) = UVar7;
          pcVar1 = *(code **)(*(int *)in_ECX + 0x344);
          guard_check_icall(0,1);
          (*pcVar1)();
          pcVar1 = *(code **)(*(int *)in_ECX + 0x19c);
          guard_check_icall();
          (*pcVar1)();
          FUN_00797df8();
        }
        pcVar1 = *(code **)(*(int *)in_ECX + 0x238);
        guard_check_icall(0,0xffffffff,0xffffffff,0xffffffff,0xffffffff,0x2f,0);
        (*pcVar1)();
      }
    }
  }
  return param_3;
}




/* vtable slots: CDockablePane[199], CDockablePaneAdapter[199], CDummyDockablePane[199], CMFCOutlookBarPaneAdapter[199], CMFCTasksPane[199] */
/* 008919f4  FUN_008919f4  165 bytes, 1 callers */

void FUN_008919f4(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  CObject *pCVar6;
  CPaneDivider *pCVar7;
  CObject *in_ECX;
  
  pcVar1 = *(code **)(*(int *)in_ECX + 0x228);
  guard_check_icall(0);
  piVar2 = (int *)(*pcVar1)();
  pcVar1 = *(code **)(*(int *)in_ECX + 0x16c);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    pHVar4 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar5 = CWnd::FromHandle(pHVar4);
    pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCBaseTabCtrl_0098c714,(CObject *)pCVar5);
    if (pCVar6 != (CObject *)0x0) {
      pHVar4 = GetParent(*(HWND *)(pCVar6 + 0x20));
      pCVar5 = CWnd::FromHandle(pHVar4);
      in_ECX = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,(CObject *)pCVar5);
    }
  }
  pCVar7 = CDockablePane::GetDefaultPaneDivider((CDockablePane *)in_ECX);
  if (piVar2 == (int *)0x0) {
    if (pCVar7 != (CPaneDivider *)0x0) {
      FUN_008bf335(in_ECX);
    }
  }
  else {
    pcVar1 = *(code **)(*piVar2 + 0x1e0);
    guard_check_icall(in_ECX);
    (*pcVar1)();
  }
  return;
}



