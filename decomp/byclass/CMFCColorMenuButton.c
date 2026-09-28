/* CMFCColorMenuButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCColorMenuButton[38], CMFCCustomizeButton[38], CMFCCustomizeMenuButton[38], CMFCDropDownToolbarButton[38], CMFCOutlookBarPaneButton[38], CMFCShowAllButton[38], CMFCToolBarButton[38], CMFCToolBarColorButton[38], CMFCToolBarEditBoxButton[38], CMFCToolBarMenuButton[38], CMFCToolBarMenuButtonsButton[38], CMFCToolBarSystemMenuButton[38], COutlookCustomizeButton[38], CTasksPaneHistoryButton[38], CTasksPaneMenuButton[38], CTasksPaneNavigateButton[38] */
/* 008230ad  FUN_008230ad  61 bytes, 0 callers */

void FUN_008230ad(BOOL param_1)

{
  code *pcVar1;
  int iVar2;
  HWND hWnd;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x38);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x38);
    guard_check_icall();
    hWnd = (HWND)(*pcVar1)();
    EnableWindow(hWnd,param_1);
  }
  return;
}




/* vtable slots: CMFCColorMenuButton[41], CMFCCustomizeButton[41], CMFCCustomizeMenuButton[41], CMFCDropDownToolbarButton[41], CMFCOutlookBarPaneButton[41], CMFCShowAllButton[41], CMFCToolBarButton[41], CMFCToolBarColorButton[41], CMFCToolBarEditBoxButton[41], CMFCToolBarMenuButton[41], CMFCToolBarMenuButtonsButton[41], CMFCToolBarSystemMenuButton[41], COutlookCustomizeButton[41], CTasksPaneHistoryButton[41], CTasksPaneMenuButton[41], CTasksPaneNavigateButton[41] */
/* 008232cc  FUN_008232cc  65 bytes, 0 callers */

undefined4 FUN_008232cc(void)

{
  code *pcVar1;
  HWND hWndParent;
  HWND pHVar2;
  BOOL BVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x38);
  guard_check_icall();
  hWndParent = (HWND)(*pcVar1)();
  if (hWndParent == (HWND)0x0) {
LAB_00823308:
    uVar4 = 0;
  }
  else {
    pHVar2 = GetFocus();
    if (hWndParent != pHVar2) {
      pHVar2 = GetFocus();
      BVar3 = IsChild(hWndParent,pHVar2);
      if (BVar3 == 0) goto LAB_00823308;
    }
    uVar4 = 1;
  }
  return uVar4;
}




/* vtable slots: CMFCColorMenuButton[24], CMFCCustomizeMenuButton[24], CMFCDropDownToolbarButton[24], CMFCOutlookBarPaneButton[24], CMFCShowAllButton[24], CMFCToolBarButton[24], CMFCToolBarColorButton[24], CMFCToolBarComboBoxButton[24], CMFCToolBarEditBoxButton[24], CMFCToolBarFontComboBox[24], CMFCToolBarFontSizeComboBox[24], CMFCToolBarMenuButton[24], CMFCToolBarMenuButtonsButton[24], CMFCToolBarSystemMenuButton[24], CTasksPaneHistoryButton[24], CTasksPaneMenuButton[24], CTasksPaneNavigateButton[24] */
/* 00823398  IsEditable  40 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCToolBarButton::IsEditable(void)const 
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMFCToolBarButton::IsEditable(CMFCToolBarButton *this)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = *(uint *)(this + 0x20);
  iVar2 = IsStandardCommand(uVar1);
  iVar3 = 0;
  if (iVar2 == 0) {
    iVar2 = FUN_007e9a96(uVar1,0);
    if (iVar2 == 0) {
      iVar3 = 1;
    }
  }
  return iVar3;
}




/* vtable slots: CMFCColorMenuButton[40], CMFCCustomizeButton[40], CMFCCustomizeMenuButton[40], CMFCDropDownToolbarButton[40], CMFCOutlookBarPaneButton[40], CMFCShowAllButton[40], CMFCToolBarButton[40], CMFCToolBarColorButton[40], CMFCToolBarEditBoxButton[40], CMFCToolBarMenuButton[40], CMFCToolBarMenuButtonsButton[40], CMFCToolBarSystemMenuButton[40], COutlookCustomizeButton[40], CTasksPaneHistoryButton[40], CTasksPaneMenuButton[40], CTasksPaneNavigateButton[40] */
/* 008233c4  FUN_008233c4  94 bytes, 0 callers */

undefined4 FUN_008233c4(HWND param_1)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  BOOL BVar4;
  undefined4 uVar5;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x38);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
LAB_0082341a:
    uVar5 = 0;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x38);
    guard_check_icall();
    pHVar3 = (HWND)(*pcVar1)();
    if (pHVar3 != param_1) {
      pcVar1 = *(code **)(*in_ECX + 0x38);
      guard_check_icall();
      pHVar3 = (HWND)(*pcVar1)();
      BVar4 = IsChild(pHVar3,param_1);
      if (BVar4 == 0) goto LAB_0082341a;
    }
    uVar5 = 1;
  }
  return uVar5;
}




/* vtable slots: CMFCColorMenuButton[39], CMFCCustomizeButton[39], CMFCCustomizeMenuButton[39], CMFCDropDownToolbarButton[39], CMFCOutlookBarPaneButton[39], CMFCShowAllButton[39], CMFCToolBarButton[39], CMFCToolBarColorButton[39], CMFCToolBarEditBoxButton[39], CMFCToolBarMenuButton[39], CMFCToolBarMenuButtonsButton[39], CMFCToolBarSystemMenuButton[39], COutlookCustomizeButton[39], CTasksPaneHistoryButton[39], CTasksPaneMenuButton[39], CTasksPaneNavigateButton[39] */
/* 00823422  FUN_00823422  76 bytes, 0 callers */

undefined4 FUN_00823422(void)

{
  code *pcVar1;
  int iVar2;
  HWND__ *pHVar3;
  CWnd *pCVar4;
  uint uVar5;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x38);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x38);
    guard_check_icall();
    pHVar3 = (HWND__ *)(*pcVar1)();
    pCVar4 = CWnd::FromHandle(pHVar3);
    if ((pCVar4 != (CWnd *)0x0) && (uVar5 = FUN_00797b3d(), (uVar5 & 0x10000000) != 0)) {
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CMFCColorMenuButton[35], CMFCCustomizeButton[35], CMFCCustomizeMenuButton[35], CMFCDropDownToolbarButton[35], CMFCOutlookBarPaneButton[35], CMFCShowAllButton[35], CMFCToolBarButton[35], CMFCToolBarColorButton[35], CMFCToolBarMenuButton[35], CMFCToolBarMenuButtonsButton[35], CMFCToolBarSystemMenuButton[35], COutlookCustomizeButton[35], CTasksPaneHistoryButton[35], CTasksPaneMenuButton[35], CTasksPaneNavigateButton[35] */
/* 00824c60  FUN_00824c60  13 bytes, 0 callers */

void FUN_00824c60(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  return;
}




/* vtable slots: CMFCColorMenuButton[37], CMFCCustomizeButton[37], CMFCCustomizeMenuButton[37], CMFCShowAllButton[37], CMFCToolBarMenuButton[37], CMFCToolBarSystemMenuButton[37], COutlookCustomizeButton[37], CTasksPaneHistoryButton[37], CTasksPaneMenuButton[37] */
/* 00874f93  FUN_00874f93  168 bytes, 0 callers */

undefined4 FUN_00874f93(int param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  CObject *pCVar3;
  int iVar4;
  int in_ECX;
  int local_c;
  int local_8;
  
  if ((*(int *)(in_ECX + 0x20) == *(int *)(param_1 + 0x20)) &&
     (*(int *)(in_ECX + 0x7c) == *(int *)(param_1 + 0x7c))) {
    local_8 = *(int *)(in_ECX + 0x74);
    local_c = *(int *)(param_1 + 0x74);
    do {
      if (local_8 == 0) {
        return 1;
      }
      if (local_c == 0) {
        return 0;
      }
      pCVar2 = (CObject *)FUN_0049acb0(&local_8);
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar2);
      if (pCVar2 == (CObject *)0x0) {
        return 0;
      }
      pCVar3 = (CObject *)FUN_0049acb0(&local_c);
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar3);
      if (pCVar3 == (CObject *)0x0) {
        return 0;
      }
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x94);
      guard_check_icall(pCVar3);
      iVar4 = (*pcVar1)();
    } while (iVar4 != 0);
  }
  return 0;
}




/* vtable slots: CMFCColorMenuButton[52], CMFCCustomizeButton[52], CMFCCustomizeMenuButton[52], CMFCShowAllButton[52], CMFCToolBarMenuButton[52], COutlookCustomizeButton[52], CTasksPaneHistoryButton[52], CTasksPaneMenuButton[52] */
/* 00875169  FUN_00875169  416 bytes, 0 callers */

void FUN_00875169(HMENU param_1)

{
  code *pcVar1;
  int *piVar2;
  BOOL BVar3;
  CMenu *pCVar4;
  UINT UVar5;
  int iVar6;
  CObject *pCVar7;
  UINT UVar8;
  undefined4 uVar9;
  HMENU pHVar10;
  CMenu *pCVar11;
  undefined4 *in_ECX;
  UINT unaff_ESI;
  int unaff_EDI;
  HMENU local_c;
  
  iVar6 = in_ECX[0x1f];
  while (iVar6 != 0) {
    piVar2 = (int *)FUN_007a1b17();
    if (piVar2 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar2 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    iVar6 = in_ECX[0x1f];
  }
  BVar3 = IsMenu(param_1);
  if ((BVar3 != 0) && (pCVar4 = CMenu::FromHandle(param_1), pCVar4 != (CMenu *)0x0)) {
    UVar5 = GetMenuDefaultItem(param_1,0,1);
    iVar6 = GetMenuItemCount(*(HMENU *)(pCVar4 + 4));
    local_c = (HMENU)0x0;
    if (0 < iVar6) {
      do {
        pcVar1 = *(code **)*in_ECX;
        guard_check_icall();
        (*pcVar1)();
        pCVar7 = (CObject *)FUN_0079d90c();
        UVar8 = GetMenuItemID(*(HMENU *)(pCVar4 + 4),(int)local_c);
        *(UINT *)(pCVar7 + 0x20) = UVar8;
        FID_conflict_GetMenuStringA(local_c,(UINT)(pCVar7 + 0x2c),(LPSTR)0x400,unaff_EDI,unaff_ESI);
        if (*(int *)(pCVar7 + 0x20) == -1) {
          if (DAT_00a13c78 != 0) {
            pcVar1 = *(code **)(*(int *)pCVar7 + 0xf8);
            uVar9 = FUN_0089de66(pCVar7 + 0x2c);
            guard_check_icall(uVar9);
            (*pcVar1)();
          }
          pHVar10 = GetSubMenu(*(HMENU *)(pCVar4 + 4),(int)local_c);
          pCVar11 = CMenu::FromHandle(pHVar10);
          pcVar1 = *(code **)(*(int *)pCVar7 + 0xd0);
          uVar9 = 0;
          if (pCVar11 != (CMenu *)0x0) {
            uVar9 = *(undefined4 *)(pCVar11 + 4);
          }
          guard_check_icall(uVar9);
          (*pcVar1)();
        }
        else if (*(UINT *)(pCVar7 + 0x20) == UVar5) {
          *(undefined4 *)(pCVar7 + 0x98) = 1;
        }
        UVar8 = GetMenuState(*(HMENU *)(pCVar4 + 4),(UINT)local_c,0x400);
        if ((UVar8 & 0x40) != 0) {
          *(uint *)(pCVar7 + 0x24) = *(uint *)(pCVar7 + 0x24) | 0x20000000;
        }
        if ((UVar8 & 3) != 0) {
          *(uint *)(pCVar7 + 0x24) = *(uint *)(pCVar7 + 0x24) | 0x40000;
        }
        if ((UVar8 & 8) != 0) {
          *(uint *)(pCVar7 + 0x24) = *(uint *)(pCVar7 + 0x24) | 0x10000;
        }
        if ((UVar8 & 0x200) != 0) {
          *(undefined4 *)(pCVar7 + 0xac) = 1;
        }
        CObList::AddTail((CObList *)(in_ECX + 0x1c),pCVar7);
        local_c = (HMENU)((int)&local_c->unused + 1);
      } while ((int)local_c < iVar6);
    }
  }
  return;
}




/* vtable slots: CMFCColorMenuButton[53], CMFCCustomizeButton[53], CMFCCustomizeMenuButton[53], CMFCShowAllButton[53], CMFCToolBarMenuButton[53], COutlookCustomizeButton[53], CTasksPaneHistoryButton[53] */
/* 00875309  FUN_00875309  519 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

HMENU__ * FUN_00875309(void)

{
  code *pcVar1;
  HMENU pHVar2;
  int iVar3;
  int *piVar4;
  UINT_PTR UVar5;
  BOOL BVar6;
  HMENU__ *hMenu;
  int in_ECX;
  uint uFlags;
  LPCWSTR lpNewItem;
  undefined **local_28;
  HMENU local_24;
  int local_20;
  UINT_PTR local_1c;
  int local_18;
  LPCWSTR local_14 [3];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  if ((((*(int *)(in_ECX + 0x7c) != 0) || (*(int *)(in_ECX + 0x20) == -1)) ||
      (*(int *)(in_ECX + 0x20) == 0)) || (*(int *)(in_ECX + 0xa8) != 0)) {
    local_24 = (HMENU)0x0;
    local_28 = CMenu::vftable;
    local_8 = 0;
    pHVar2 = CreatePopupMenu();
    iVar3 = CMenu::Attach((CMenu *)&local_28,pHVar2);
    if (iVar3 != 0) {
      local_18 = *(int *)(in_ECX + 0x74);
      local_1c = 0xffffffff;
      if (local_18 != 0) {
        local_20 = in_ECX + 0x70;
        do {
          piVar4 = (int *)FUN_0049acb0(&local_18);
          if (piVar4 == (int *)0x0) {
LAB_0087550b:
                    /* WARNING: Subroutine does not return */
            FUN_0078e714();
          }
          uFlags = (uint)piVar4[9] >> 0x17 & 0x40;
          if ((piVar4[9] & 0x40000U) != 0) {
            uFlags = uFlags | 2;
          }
          if ((piVar4[9] & 0x10000U) != 0) {
            uFlags = uFlags | 8;
          }
          if (piVar4[0x2b] != 0) {
            uFlags = uFlags | 0x200;
          }
          pcVar1 = *(code **)(*piVar4 + 0xf4);
          guard_check_icall();
          iVar3 = (*pcVar1)();
          if (iVar3 != 0) {
            uFlags = uFlags | 0x20;
          }
          UVar5 = piVar4[8];
          if (UVar5 == 0) {
            lpNewItem = (LPCWSTR)0x0;
            UVar5 = 0;
            uFlags = 0x800;
LAB_0087549c:
            BVar6 = AppendMenuW(local_24,uFlags,UVar5,lpNewItem);
            if (BVar6 == 0) {
              GetLastError();
LAB_008754bd:
              local_8 = 3;
              goto LAB_00875363;
            }
          }
          else {
            if (UVar5 != 0xffffffff) {
              if (piVar4[0x26] != 0) {
                local_1c = UVar5;
              }
              lpNewItem = (LPCWSTR)piVar4[0xb];
              goto LAB_0087549c;
            }
            pcVar1 = *(code **)(*piVar4 + 0xd4);
            guard_check_icall();
            UVar5 = (*pcVar1)();
            if (UVar5 == 0) goto LAB_0087550b;
            iVar3 = FUN_004054a0(piVar4[0xb] + -0x10);
            local_14[0] = (LPCWSTR)(iVar3 + 0x10);
            local_8 = CONCAT31(local_8._1_3_,2);
            if ((piVar4[0x2f] != 0) && (DAT_00a13c78 != 0)) {
              FUN_0089ddc3(piVar4[0x2f],local_14);
            }
            BVar6 = AppendMenuW(local_24,uFlags | 0x10,UVar5,local_14[0]);
            if (BVar6 == 0) {
              GetLastError();
            }
            local_8 = local_8 & 0xffffff00;
            FUN_00406b10();
            if (BVar6 == 0) goto LAB_008754bd;
          }
        } while (local_18 != 0);
      }
      UVar5 = local_1c;
      hMenu = CMenu::Detach((CMenu *)&local_28);
      if (UVar5 != 0xffffffff) {
        SetMenuDefaultItem(hMenu,UVar5,0);
      }
      local_8 = 4;
      local_28 = CMenu::vftable;
      CMenu::DestroyMenu((CMenu *)&local_28);
      return hMenu;
    }
    local_8 = 1;
LAB_00875363:
    local_28 = CMenu::vftable;
    CMenu::DestroyMenu((CMenu *)&local_28);
  }
  return (HMENU__ *)0x0;
}




/* vtable slots: CMFCColorMenuButton[28], CMFCCustomizeButton[28], CMFCCustomizeMenuButton[28], CMFCShowAllButton[28], CMFCToolBarMenuButton[28], CMFCToolBarSystemMenuButton[28], COutlookCustomizeButton[28], CTasksPaneHistoryButton[28], CTasksPaneMenuButton[28] */
/* 00876cb8  FUN_00876cb8  12 bytes, 0 callers */

bool FUN_00876cb8(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x8c) != 0;
}




/* vtable slots: CMFCColorMenuButton[61], CMFCCustomizeButton[61], CMFCCustomizeMenuButton[61], CMFCShowAllButton[61], CMFCToolBarMenuButton[61], CMFCToolBarSystemMenuButton[61], COutlookCustomizeButton[61], CTasksPaneHistoryButton[61], CTasksPaneMenuButton[61] */
/* 00876cc4  FUN_00876cc4  12 bytes, 0 callers */

bool FUN_00876cc4(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xbc) != 0;
}




/* vtable slots: CMFCColorMenuButton[29], CMFCCustomizeButton[29], CMFCCustomizeMenuButton[29], CMFCShowAllButton[29], CMFCToolBarMenuButton[29], CMFCToolBarSystemMenuButton[29], COutlookCustomizeButton[29], CTasksPaneHistoryButton[29], CTasksPaneMenuButton[29] */
/* 00876cd0  OnBeforeDrag  44 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCToolBarMenuButton::OnBeforeDrag(void)const 
   
   Library: Visual Studio 2012 Release */

int __thiscall CMFCToolBarMenuButton::OnBeforeDrag(CMFCToolBarMenuButton *this)

{
  if (*(int *)(this + 0x8c) != 0) {
    FUN_0081c13f();
    SendMessageW(*(HWND *)(*(int *)(this + 0x8c) + 0x20),0x10,0,0);
  }
  return 1;
}




/* vtable slots: CMFCColorMenuButton[7], CMFCToolBarMenuButton[7], CTasksPaneHistoryButton[7], CTasksPaneMenuButton[7] */
/* 00876cfc  FUN_00876cfc  772 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00876cfc(int *param_1,int *param_2,int *param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  CSimpleStringT<wchar_t,0> *pCVar3;
  CObject *pCVar4;
  undefined4 uVar5;
  int *piVar6;
  HWND pHVar7;
  CWnd *pCVar8;
  int in_ECX;
  int iVar9;
  undefined1 local_30 [4];
  CObject *local_2c;
  undefined1 local_28 [4];
  int *local_24;
  undefined1 local_20 [4];
  int local_1c;
  undefined1 local_18 [4];
  CObject *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x876d08;
  *(int *)(in_ECX + 0xa0) = param_4;
  if (*(int *)(in_ECX + 0x50) == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    return;
  }
  local_24 = (int *)(in_ECX + 0x94);
  iVar9 = 0;
  if ((*(int *)(in_ECX + 0x90) != 0) || (*local_24 != 0)) {
    if (*local_24 == 0) {
      if (param_4 == 0) {
        iVar9 = FUN_0081507c(local_20);
        iVar9 = *(int *)(iVar9 + 4);
      }
      else {
        piVar6 = (int *)FUN_0081507c(local_30);
        iVar9 = *piVar6;
      }
      if (DAT_00a127b4 != 0) {
        iVar9 = iVar9 * 2;
      }
    }
    else if (param_4 == 0) {
      iVar9 = FUN_007c2511();
      iVar9 = *(int *)(iVar9 + 0x1cc);
    }
    else {
      iVar9 = FUN_007c2511();
      iVar9 = *(int *)(iVar9 + 0x1d4);
    }
    iVar9 = iVar9 + -2;
  }
  if (((DAT_00a13a44 != 0) && (*local_24 != 0)) &&
     ((*(uint *)(in_ECX + 0x20) < 0xf000 || (0xf1ef < *(uint *)(in_ECX + 0x20))))) {
    iVar2 = FUN_0044e690(9,0);
    if (-1 < iVar2) {
      pCVar3 = (CSimpleStringT<wchar_t,0> *)Left(&local_2c,iVar2);
      local_8 = 0;
      ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x2c),pCVar3)
      ;
      FUN_00406b10();
    }
    CStringT<>();
    local_8 = 1;
    if (*(int *)(in_ECX + 0x6c) == 0) {
      pCVar4 = (CObject *)FUN_00404c80();
      local_14 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,pCVar4);
LAB_00876e38:
      if (local_14 != (CObject *)0x0) goto LAB_00876e3c;
    }
    else {
      local_14 = DAT_00a13a1c;
      if (DAT_00a13a1c == (CObject *)0x0) {
        local_14 = (CObject *)FUN_00792b4c();
        goto LAB_00876e38;
      }
LAB_00876e3c:
      pCVar4 = local_14;
      iVar2 = FUN_0082b064(*(undefined4 *)(in_ECX + 0x20),&local_1c,local_14,1);
      if (iVar2 == 0) {
        pcVar1 = *(code **)(*(int *)pCVar4 + 0x170);
        guard_check_icall();
        uVar5 = (*pcVar1)();
        iVar2 = FUN_0082b064(*(undefined4 *)(in_ECX + 0x20),&local_1c,uVar5,0);
        if (iVar2 == 0) goto LAB_00876e90;
      }
      ATL::CSimpleStringT<wchar_t,0>::AppendChar((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x2c),L'\t')
      ;
      FUN_00404cf0(local_1c,*(undefined4 *)(local_1c + -0xc));
    }
LAB_00876e90:
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  local_2c = (CObject *)0x0;
  if (*(int *)(in_ECX + 0x20) == -2) {
    pcVar1 = *(code **)(*param_2 + 0x28);
    iVar2 = FUN_007c2511();
    guard_check_icall(iVar2 + 300);
    local_2c = (CObject *)(*pcVar1)();
  }
  piVar6 = (int *)FUN_00881448(local_18,param_2,param_3,param_4);
  local_1c = *piVar6;
  local_14 = (CObject *)piVar6[1];
  if (local_2c != (CObject *)0x0) {
    pcVar1 = *(code **)(*param_2 + 0x28);
    guard_check_icall(local_2c);
    (*pcVar1)();
  }
  pCVar4 = local_14;
  local_2c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenuBar_00a00938,
                                *(CObject **)(in_ECX + 0x6c));
  if (local_2c != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)local_2c + 0x354);
    guard_check_icall();
    pCVar4 = (CObject *)(*pcVar1)();
    local_14 = pCVar4;
    if (*(int *)(local_2c + 0xd80) != 0) {
      pHVar7 = GetParent(*(HWND *)(local_2c + 0x20));
      pCVar8 = CWnd::FromHandle(pHVar7);
      local_2c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCDropDownListBox_009a4c4c,
                                    (CObject *)pCVar8);
      if (local_2c != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)local_2c + 0x218);
        guard_check_icall(local_28,param_2);
        piVar6 = (int *)(*pcVar1)();
        local_1c = *piVar6;
        param_1[1] = piVar6[1];
        goto LAB_00876ff6;
      }
    }
  }
  if (param_4 == 0) {
    pCVar4 = (CObject *)((int)pCVar4 + iVar9);
    local_14 = pCVar4;
  }
  else {
    local_1c = local_1c + iVar9;
  }
  if (*local_24 == 0) {
    piVar6 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar6 + 0x2dc);
    guard_check_icall();
    iVar9 = (*pcVar1)();
    iVar9 = iVar9 * 2;
    if (param_4 != 0) goto LAB_00876fea;
    local_14 = (CObject *)((int)local_14 + iVar9);
  }
  else {
    iVar9 = *param_3 + 6;
    local_14 = pCVar4;
LAB_00876fea:
    local_1c = local_1c + iVar9;
  }
  param_1[1] = (int)local_14;
LAB_00876ff6:
  *param_1 = local_1c;
  return;
}




/* vtable slots: CMFCColorMenuButton[22], CMFCCustomizeMenuButton[22], CMFCShowAllButton[22], CMFCToolBarMenuButton[22], CTasksPaneHistoryButton[22], CTasksPaneMenuButton[22] */
/* 00877000  FUN_00877000  317 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00877000(void)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(in_ECX + 0x8c) != 0) &&
     (BVar2 = IsWindow(*(HWND *)(*(int *)(in_ECX + 0x8c) + 0x20)), BVar2 != 0)) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x8c) + 0x1cc);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      return;
    }
    iVar5 = 0;
    iVar3 = FUN_0081d494();
    if (0 < iVar3) {
      do {
        piVar4 = (int *)FUN_0081d46f(iVar5);
        if (piVar4 != (int *)0x0) {
          pcVar1 = *(code **)(*piVar4 + 0x58);
          guard_check_icall();
          (*pcVar1)();
        }
        iVar5 = iVar5 + 1;
        iVar3 = FUN_0081d494();
      } while (iVar5 < iVar3);
    }
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x8c) + 0x1e0);
    guard_check_icall();
    (*pcVar1)();
    *(undefined4 *)(*(int *)(in_ECX + 0x8c) + 0x130) = 0;
    FUN_0081c095(0);
  }
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  if ((*(int *)(in_ECX + 0x6c) != 0) &&
     (BVar2 = IsWindow(*(HWND *)(*(int *)(in_ECX + 0x6c) + 0x20)), BVar2 != 0)) {
    local_18.left = *(LONG *)(in_ECX + 0x54);
    local_18.top = *(LONG *)(in_ECX + 0x58);
    local_18.right = *(LONG *)(in_ECX + 0x5c);
    local_18.bottom = *(LONG *)(in_ECX + 0x60);
    iVar3 = FUN_007c2574();
    InflateRect(&local_18,*(int *)(iVar3 + 0x7c),*(int *)(iVar3 + 0x7c));
    InvalidateRect(*(HWND *)(*(int *)(in_ECX + 0x6c) + 0x20),&local_18,1);
    UpdateWindow(*(HWND *)(*(int *)(in_ECX + 0x6c) + 0x20));
  }
  *(undefined4 *)(in_ECX + 0xa4) = 0;
  return;
}




/* vtable slots: CMFCColorMenuButton[8], CMFCCustomizeButton[8], CMFCCustomizeMenuButton[8], CMFCToolBarMenuButton[8], CMFCToolBarSystemMenuButton[8], COutlookCustomizeButton[8], CTasksPaneHistoryButton[8], CTasksPaneMenuButton[8] */
/* 008771ff  FUN_008771ff  558 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008771ff(int param_1,int param_2)

{
  code *pcVar1;
  POINT pt;
  POINT pt_00;
  BOOL BVar2;
  int iVar3;
  CObject *pCVar4;
  CObject *pCVar5;
  int *in_ECX;
  int *piVar6;
  undefined1 local_18 [12];
  CObject *local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  in_ECX[0x27] = 0;
  if (((in_ECX[0x24] != 0) && (param_2 == 0)) && (in_ECX[0x25] == 0)) {
    if ((in_ECX[8] == 0) || (in_ECX[8] == -1)) {
      in_ECX[0x27] = 1;
    }
    else {
      local_18._8_4_ = 0;
      local_c = (CObject *)0x0;
      GetCursorPos((LPPOINT)(local_18 + 8));
      ScreenToClient(*(HWND *)(param_1 + 0x20),(LPPOINT)(local_18 + 8));
      pt.y = (LONG)local_c;
      pt.x = local_18._8_4_;
      BVar2 = PtInRect((RECT *)(in_ECX + 0x32),pt);
      in_ECX[0x27] = BVar2;
      if (BVar2 == 0) {
        return 0;
      }
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0xf0);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if ((iVar3 != 0) && (param_2 == 0)) {
    local_18._8_4_ = 0;
    local_c = (CObject *)0x0;
    GetCursorPos((LPPOINT)(local_18 + 8));
    ScreenToClient(*(HWND *)(param_1 + 0x20),(LPPOINT)(local_18 + 8));
    pt_00.y = (LONG)local_c;
    pt_00.x = local_18._8_4_;
    BVar2 = PtInRect((RECT *)(in_ECX + 0x36),pt_00);
    if (BVar2 != 0) {
      return 0;
    }
  }
  if ((((in_ECX[0x27] == 0) && (in_ECX[8] != 0)) && (in_ECX[8] != -1)) &&
     ((in_ECX[0x24] == 0 && (in_ECX[0x2a] == 0)))) {
    return 0;
  }
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCMenuBar_00a00b00,(CObject *)in_ECX[0x1b]);
  local_c = pCVar4;
  if (in_ECX[0x23] == 0) {
    pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenuBar_00a00938,
                                (CObject *)in_ECX[0x1b]);
    if (((param_2 == 0) || (pCVar5 == (CObject *)0x0)) || (DAT_00a127ac != 0)) {
      if ((pCVar4 != (CObject *)0x0) &&
         (local_c = (CObject *)FUN_007fdf83(0), local_c != (CObject *)0x0)) {
        pcVar1 = *(code **)(*(int *)local_c + 0x58);
        guard_check_icall();
        (*pcVar1)();
      }
      pcVar1 = *(code **)(*in_ECX + 0xcc);
      guard_check_icall(param_1);
      iVar3 = (*pcVar1)();
      if (iVar3 == 0) {
        return 0;
      }
    }
    else {
      FUN_008558f6(in_ECX,1);
    }
    piVar6 = in_ECX;
    if (pCVar4 == (CObject *)0x0) goto LAB_00877395;
  }
  else {
    *(undefined4 *)(in_ECX[0x23] + 0x130) = 0;
    pcVar1 = *(code **)(*(int *)in_ECX[0x23] + 0x60);
    guard_check_icall();
    (*pcVar1)();
    in_ECX[0x23] = 0;
    if (local_c == (CObject *)0x0) goto LAB_00877395;
    piVar6 = (int *)0x0;
  }
  FUN_00804f82(piVar6);
LAB_00877395:
  if (in_ECX[0x1b] != 0) {
    local_18._0_4_ = in_ECX[0x15];
    local_18._4_4_ = in_ECX[0x16];
    local_18._8_4_ = in_ECX[0x17];
    local_c = (CObject *)in_ECX[0x18];
    iVar3 = FUN_007c2574();
    InflateRect((LPRECT)local_18,*(int *)(iVar3 + 0x7c),*(int *)(iVar3 + 0x7c));
    RedrawWindow(*(HWND *)(in_ECX[0x1b] + 0x20),(RECT *)local_18,(HRGN)0x0,0x401);
  }
  return 1;
}




/* vtable slots: CMFCColorMenuButton[25], CMFCCustomizeButton[25], CMFCCustomizeMenuButton[25], CMFCDropDownToolbarButton[25], CMFCShowAllButton[25], CMFCShowAllButton[51], CMFCToolBarMenuButton[25], CMFCToolBarSystemMenuButton[25], COutlookCustomizeButton[25], CTasksPaneHistoryButton[25], CTasksPaneMenuButton[25] */
/* 0087742d  FUN_0087742d  35 bytes, 0 callers */

void FUN_0087742d(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x20);
  guard_check_icall(param_1,0);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCColorMenuButton[51], CMFCCustomizeButton[51], CMFCCustomizeMenuButton[51], CMFCToolBarMenuButton[51], CMFCToolBarSystemMenuButton[51], COutlookCustomizeButton[51], CTasksPaneHistoryButton[51], CTasksPaneMenuButton[51] */
/* 008779a4  FUN_008779a4  704 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008779a4(int param_1)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  CObject *pCVar4;
  int *piVar5;
  uint uVar6;
  HWND pHVar7;
  CWnd *pCVar8;
  int *in_ECX;
  HMENU local_24;
  tagPOINT local_20;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x23] != 0) {
    return 0;
  }
  if ((param_1 == 0) && (param_1 = in_ECX[0x1b], param_1 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pcVar1 = *(code **)(*in_ECX + 0xd4);
  guard_check_icall();
  local_24 = (HMENU)(*pcVar1)();
  if (local_24 == (HMENU)0x0) {
    pcVar1 = *(code **)(*in_ECX + 0xe0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      return 0;
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0xd8);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  in_ECX[0x23] = iVar2;
  if (iVar2 == 0) {
    DestroyMenu(local_24);
    return 0;
  }
  iVar2 = FUN_0081d494();
  if ((0 < iVar2) && (local_24 != (HMENU)0x0)) {
    DestroyMenu(local_24);
    local_24 = (HMENU)0x0;
  }
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenuBar_00a00938,
                              (CObject *)in_ECX[0x1b]);
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCMenuBar_00a00b00,(CObject *)in_ECX[0x1b]);
  if (pCVar3 != (CObject *)0x0) {
    local_20.x = 0;
    local_20.y = in_ECX[0x16] + -2;
    ClientToScreen(*(HWND *)(param_1 + 0x20),&local_20);
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(pCVar3 + 0x20),&local_18);
    piVar5 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar5 + 0x2e0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    uVar6 = FUN_00797acc();
    if ((uVar6 & 0x400000) == 0) {
      local_20.x = local_18.right + iVar2;
    }
    else {
      local_20.x = local_18.left - iVar2;
    }
    iVar2 = ((uVar6 & 0x400000) != 0) + 3;
    goto LAB_00877ba1;
  }
  if (pCVar4 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar4 + 0x164);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      local_20.x = in_ECX[0x17];
      local_20.y = in_ECX[0x16];
      ClientToScreen(*(HWND *)(param_1 + 0x20),&local_20);
      iVar2 = 3;
      goto LAB_00877ba1;
    }
  }
  if (in_ECX[0x2e] == 0) {
    if (*(int *)(in_ECX[0x23] + 0xf44) != 0) {
      local_20.y = in_ECX[0x18] + -1;
      goto LAB_00877b79;
    }
    local_20.x = in_ECX[0x15];
    local_20.y = in_ECX[0x18] + -1;
  }
  else {
    local_20.y = in_ECX[0x16];
LAB_00877b79:
    local_20.x = in_ECX[0x17] + -1;
  }
  iVar2 = 1;
  ClientToScreen(*(HWND *)(param_1 + 0x20),&local_20);
LAB_00877ba1:
  *(int **)(in_ECX[0x23] + 0x158) = in_ECX;
  *(int *)(in_ECX[0x23] + 0xf30) = iVar2;
  pcVar1 = *(code **)(*(int *)in_ECX[0x23] + 0x210);
  guard_check_icall(param_1,local_20.x,local_20.y,local_24,0,0);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    in_ECX[0x23] = 0;
    return 0;
  }
  pcVar1 = *(code **)(*in_ECX + 0xdc);
  guard_check_icall();
  (*pcVar1)();
  if (in_ECX[0x31] == 0) {
    pHVar7 = GetParent(*(HWND *)(param_1 + 0x20));
    pCVar8 = CWnd::FromHandle(pHVar7);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar8);
    if ((pCVar3 != (CObject *)0x0) && (*(int *)(pCVar3 + 0x134) != 0)) {
      *(int *)(in_ECX[0x23] + 0x134) = *(int *)(pCVar3 + 0x134);
    }
  }
  else {
    *(int *)(in_ECX[0x23] + 0x134) = in_ECX[0x31];
  }
  return 1;
}




/* vtable slots: CMFCColorMenuButton[36], CMFCCustomizeButton[36], CMFCCustomizeMenuButton[36], CMFCShowAllButton[36], CMFCToolBarMenuButton[36], CMFCToolBarSystemMenuButton[36], COutlookCustomizeButton[36], CTasksPaneHistoryButton[36], CTasksPaneMenuButton[36] */
/* 00877c65  FUN_00877c65  71 bytes, 0 callers */

void FUN_00877c65(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  int local_8;
  
  FUN_008828c3();
  local_8 = *(int *)(in_ECX + 0x74);
  while (local_8 != 0) {
    puVar2 = (undefined4 *)FUN_0044f2d0(&local_8);
    pcVar1 = *(code **)(*(int *)*puVar2 + 0x90);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCColorMenuButton[32], CMFCCustomizeButton[32], CMFCCustomizeMenuButton[32], CMFCShowAllButton[32], CMFCToolBarMenuButton[32], CMFCToolBarSystemMenuButton[32], COutlookCustomizeButton[32], CTasksPaneHistoryButton[32], CTasksPaneMenuButton[32] */
/* 00877cac  FUN_00877cac  102 bytes, 0 callers */

void FUN_00877cac(void)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  CObject *pCVar4;
  CObject *pCVar5;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x6c) != 0) {
    pHVar2 = GetParent(*(HWND *)(*(int *)(in_ECX + 0x6c) + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar3);
    if (pCVar4 != (CObject *)0x0) {
      pHVar2 = *(HWND *)(pCVar4 + 0x20);
      while( true ) {
        pHVar2 = GetParent(pHVar2);
        pCVar3 = CWnd::FromHandle(pHVar2);
        pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar3
                                   );
        if (pCVar5 == (CObject *)0x0) break;
        pHVar2 = *(HWND *)(pCVar5 + 0x20);
        pCVar4 = pCVar5;
      }
      pcVar1 = *(code **)(*(int *)pCVar4 + 0x1e0);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCColorMenuButton[46], CMFCCustomizeButton[46], CMFCCustomizeMenuButton[46], CMFCShowAllButton[46], CMFCToolBarMenuButton[46], CMFCToolBarSystemMenuButton[46], COutlookCustomizeButton[46], CTasksPaneHistoryButton[46], CTasksPaneMenuButton[46] */
/* 00877dd8  FUN_00877dd8  144 bytes, 0 callers */

undefined4 FUN_00877dd8(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  wchar_t *pwVar5;
  
  iVar1 = FUN_00882aa5(param_1,param_2);
  uVar3 = 0;
  if (iVar1 != 0) {
    uVar2 = 0x100004;
    *(undefined4 *)(param_2 + 0x18) = 0xc;
    *(undefined4 *)(param_2 + 0x1c) = 0x100004;
    uVar4 = *(uint *)(in_ECX + 0x24);
    if ((uVar4 & 0x10000) != 0) {
      uVar2 = 0x100014;
      *(undefined4 *)(param_2 + 0x1c) = 0x100014;
      uVar4 = *(uint *)(in_ECX + 0x24);
    }
    if ((uVar4 & 0x40000) != 0) {
      *(uint *)(param_2 + 0x1c) = uVar2 | 1;
    }
    iVar1 = FUN_008f899d(L"CMFCToolBarMenuButton");
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)(param_2 + 0x10),L"CMFCToolBarMenuButton",iVar1);
    pwVar5 = L"Execute";
    if (*(int *)(in_ECX + 0x94) == 0) {
      pwVar5 = L"Open";
    }
    iVar1 = FUN_008f899d(pwVar5);
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)(param_2 + 0x14),pwVar5,iVar1);
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CMFCColorMenuButton[49], CMFCCustomizeButton[49], CMFCCustomizeMenuButton[49], CMFCShowAllButton[49], CMFCToolBarMenuButton[49], CMFCToolBarSystemMenuButton[49], COutlookCustomizeButton[49], CTasksPaneHistoryButton[49], CTasksPaneMenuButton[49] */
/* 00877e68  SetRadio  100 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCToolBarMenuButton::SetRadio(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

void __thiscall CMFCToolBarMenuButton::SetRadio(CMFCToolBarMenuButton *this)

{
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(this + 0xac) = 1;
  if (*(int *)(this + 0x6c) != 0) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    FUN_00876aea(&local_18);
    InvalidateRect(*(HWND *)(*(int *)(this + 0x6c) + 0x20),&local_18,1);
    UpdateWindow(*(HWND *)(*(int *)(this + 0x6c) + 0x20));
  }
  return;
}




/* vtable slots: CMFCColorMenuButton[62], CMFCCustomizeButton[62], CMFCCustomizeMenuButton[62], CMFCShowAllButton[62], CMFCToolBarMenuButton[62], CMFCToolBarSystemMenuButton[62], COutlookCustomizeButton[62], CTasksPaneHistoryButton[62], CTasksPaneMenuButton[62] */
/* 00877ecc  SetTearOff  72 bytes, 2 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCToolBarMenuButton::SetTearOff(unsigned int)
   
   Library: Visual Studio 2012 Release */

void __thiscall CMFCToolBarMenuButton::SetTearOff(CMFCToolBarMenuButton *this,uint param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(this + 0xbc);
  if (uVar1 != param_1) {
    if (DAT_00a13c78 != (CMenuTearOffManager *)0x0) {
      if (uVar1 != 0) {
        CMenuTearOffManager::SetInUse(DAT_00a13c78,uVar1,0);
      }
      if (param_1 != 0) {
        CMenuTearOffManager::SetInUse(DAT_00a13c78,param_1,1);
      }
    }
    *(uint *)(this + 0xbc) = param_1;
  }
  return;
}




/* vtable slots: CMFCColorMenuButton[11], CMFCCustomizeButton[11], CMFCCustomizeMenuButton[11], CMFCOutlookBarPaneButton[11], CMFCShowAllButton[11], CMFCToolBarButton[11], CMFCToolBarColorButton[11], CMFCToolBarEditBoxButton[11], CMFCToolBarMenuButton[11], CMFCToolBarMenuButtonsButton[11], CMFCToolBarSystemMenuButton[11], COutlookCustomizeButton[11], CTasksPaneHistoryButton[11], CTasksPaneMenuButton[11], CTasksPaneNavigateButton[11] */
/* 008810bc  FUN_008810bc  145 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008810bc(int param_1)

{
  int iVar1;
  int in_ECX;
  UINT in_stack_ffffffd8;
  LPSTR in_stack_ffffffdc;
  int in_stack_ffffffe0;
  CSimpleStringT<wchar_t,0> local_18 [4];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8810c8;
  if ((*(int *)(*(int *)(in_ECX + 0x2c) + -0xc) == 0) && (*(int *)(in_ECX + 0x20) != 0)) {
    CStringT<>();
    local_8 = 0;
    iVar1 = FID_conflict_LoadStringA
                      (*(HINSTANCE *)(in_ECX + 0x20),in_stack_ffffffd8,in_stack_ffffffdc,
                       in_stack_ffffffe0);
    if (iVar1 != 0) {
      iVar1 = FUN_0044e690(10,0);
      if (iVar1 != -1) {
        FUN_00450000(local_18,iVar1 + 1,*(int *)(local_14 + -0xc) - (iVar1 + 1));
        local_8 = CONCAT31(local_8._1_3_,1);
        ATL::CSimpleStringT<wchar_t,0>::operator=
                  ((CSimpleStringT<wchar_t,0> *)(param_1 + 0x2c),local_18);
        FUN_00406b10();
      }
    }
    FUN_00406b10();
  }
  return 1;
}




/* vtable slots: CMFCColorMenuButton[1] */
/* 008a1683  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCColorMenuButton::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCColorMenuButton::_scalar_deleting_destructor_(CMFCColorMenuButton *this,uint param_1)

{
  ~CMFCColorMenuButton(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x134);
    }
  }
  return this;
}




/* vtable slots: CMFCColorMenuButton[5] */
/* 008a16b6  FUN_008a16b6  280 bytes, 0 callers */

void FUN_008a16b6(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  
  FUN_0087503b(param_1);
  uVar1 = *(undefined4 *)(param_1 + 0xe8);
  *(undefined4 *)(in_ECX + 0xe8) = uVar1;
  puVar2 = (undefined4 *)FUN_007e3332(*(undefined4 *)(in_ECX + 0x20));
  *puVar2 = uVar1;
  FUN_0079ca8b(*(undefined4 *)(param_1 + 0xf8),0xffffffff);
  if (0 < *(int *)(in_ECX + 0xf8)) {
    iVar3 = 0;
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar3);
      uVar1 = *puVar2;
      puVar2 = (undefined4 *)FUN_00799cf8(iVar3);
      iVar3 = iVar3 + 1;
      *puVar2 = uVar1;
    } while (iVar3 < *(int *)(in_ECX + 0xf8));
  }
  *(undefined4 *)(in_ECX + 0x118) = *(undefined4 *)(param_1 + 0x118);
  *(undefined4 *)(in_ECX + 0xec) = *(undefined4 *)(param_1 + 0xec);
  *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(param_1 + 0x11c);
  *(undefined4 *)(in_ECX + 0x120) = *(undefined4 *)(param_1 + 0x120);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x124),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x124));
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x128),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x128));
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 300),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 300));
  *(undefined4 *)(in_ECX + 0x10c) = *(undefined4 *)(param_1 + 0x10c);
  *(undefined4 *)(in_ECX + 0x110) = *(undefined4 *)(param_1 + 0x110);
  *(undefined4 *)(in_ECX + 0x114) = *(undefined4 *)(param_1 + 0x114);
  *(undefined4 *)(in_ECX + 0x130) = *(undefined4 *)(param_1 + 0x130);
  return;
}




/* vtable slots: CMFCColorMenuButton[54] */
/* 008a17ce  FUN_008a17ce  244 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008a17ce(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined **local_30 [7];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x8a17da;
  FUN_007d5a59(10);
  uVar4 = 0;
  local_8 = 0;
  if ((*(int *)(in_ECX + 0x120) != 0) && (*(int *)(in_ECX + 0x6c) != 0)) {
    iVar1 = DAT_00a13a1c;
    if (DAT_00a13a1c == 0) {
      iVar1 = FUN_00792b4c();
    }
    SendMessageW(*(HWND *)(iVar1 + 0x20),DAT_00a13c88,*(WPARAM *)(in_ECX + 0x20),(LPARAM)local_30);
  }
  local_14 = FUN_0078e624(0x1fe8);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (local_14 != 0) {
    if (*(int *)(in_ECX + 0x120) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(undefined4 *)(in_ECX + 300);
    }
    if (*(int *)(in_ECX + 0x11c) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(in_ECX + 0x128);
    }
    if (*(int *)(in_ECX + 0x118) != 0) {
      uVar4 = *(undefined4 *)(in_ECX + 0x124);
    }
    uVar4 = CMFCColorPopupMenu(in_ECX + 0xf0,*(undefined4 *)(in_ECX + 0xe8),uVar4,uVar2,uVar3,
                               local_30,*(undefined4 *)(in_ECX + 0x10c),
                               *(undefined4 *)(in_ECX + 0x114),*(undefined4 *)(in_ECX + 0x110),
                               *(undefined4 *)(in_ECX + 0xec),*(undefined4 *)(in_ECX + 0x20),
                               *(undefined4 *)(in_ECX + 0x130));
  }
  local_8 = 2;
  local_30[0] = CList<unsigned_long,unsigned_long>::vftable;
  RemoveAll();
  return uVar4;
}




/* vtable slots: CMFCColorMenuButton[0] */
/* 008a18c2  FUN_008a18c2  6 bytes, 0 callers */

undefined ** FUN_008a18c2(void)

{
  return &PTR_s_CMFCColorMenuButton_00a00c0c;
}




/* vtable slots: CMFCColorMenuButton[10] */
/* 008a1904  OnChangeParentWnd  93 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCColorMenuButton::OnChangeParentWnd(class CWnd *)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCColorMenuButton::OnChangeParentWnd(CMFCColorMenuButton *this,CWnd *param_1)

{
  int iVar1;
  
  FUN_00881617(param_1);
  if (param_1 != (CWnd *)0x0) {
    iVar1 = FUN_0079d98a(&PTR_s_CMFCMenuBar_00a00b00);
    if (iVar1 != 0) {
      *(undefined4 *)(this + 8) = 1;
    }
    iVar1 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938);
    if (iVar1 == 0) {
      *(undefined4 *)(this + 0x94) = 0;
    }
    else {
      *(undefined4 *)(this + 0x94) = 1;
      *(undefined4 *)(this + 8) = 1;
    }
  }
  *(CWnd **)(this + 0x6c) = param_1;
  *(undefined4 *)(this + 0x90) = 1;
  return;
}




/* vtable slots: CMFCColorMenuButton[6] */
/* 008a1961  FUN_008a1961  649 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a1961(CDC *param_1,undefined4 param_2,uint param_3,undefined4 param_4,int param_5,
                 int param_6,undefined4 param_7,undefined4 param_8)

{
  CGdiObject *this;
  code *pcVar1;
  CDC *this_00;
  int iVar2;
  void *ho;
  AFX_GLOBAL_DATA *this_01;
  undefined4 uVar3;
  undefined4 uVar4;
  ulong uVar5;
  CMFCToolBarButton *in_ECX;
  ulong uVar6;
  undefined **local_40 [2];
  undefined **local_38;
  HBRUSH local_34;
  CPalette *local_30;
  CDC *local_2c;
  uint local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x8a196d;
  local_2c = param_1;
  local_28 = param_3;
  FUN_00877450(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  iVar2 = CMFCToolBarButton::IsDrawImage(in_ECX);
  if ((iVar2 == 0) || (param_3 == 0)) goto LAB_008a1bdd;
  this = (CGdiObject *)(in_ECX + 0x104);
  local_30 = (CPalette *)0x0;
  iVar2 = FUN_007c2511();
  if (*(int *)(iVar2 + 0x1ac) == 8) {
    if ((this == (CGdiObject *)0x0) || (*(int *)(in_ECX + 0x108) == 0)) {
      FUN_00822f07(in_ECX + 0xf0,this);
    }
    if ((this == (CGdiObject *)0x0) || (*(int *)(in_ECX + 0x108) == 0)) {
LAB_008a1be5:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    local_30 = CDC::SelectPalette(param_1,(CPalette *)this,0);
    RealizePalette(*(HDC *)(param_1 + 4));
  }
  else if ((this != (CGdiObject *)0x0) && (*(int *)(in_ECX + 0x108) != 0)) {
    ho = CGdiObject::Detach(this);
    DeleteObject(ho);
    if (*(int *)(in_ECX + 0x108) != 0) goto LAB_008a1be5;
  }
  local_24.left = *(int *)(local_28 + 0x6c);
  local_24.right = *(int *)(local_28 + 0x74);
  local_24.bottom = *(int *)(local_28 + 0x78);
  if ((DAT_00a127b4 == 0) || (*(int *)(in_ECX + 0x94) != 0)) {
    local_24.top = 5;
  }
  else {
    local_24.top = 10;
  }
  local_24.top = local_24.bottom - local_24.top;
  OffsetRect(&local_24,0,1);
  if (((param_6 != 0) && (param_5 == 0)) && (iVar2 = FUN_007c2574(), *(int *)(iVar2 + 0x54) != 0)) {
    this_01 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar2 = AFX_GLOBAL_DATA::IsHighContrastMode(this_01);
    if ((iVar2 == 0) && ((*(uint *)(in_ECX + 0x24) & 0x70000) == 0)) {
      iVar2 = FUN_007c2511();
      FUN_0079de5e(*(undefined4 *)(iVar2 + 0x58));
      FillRect(*(HDC *)(local_2c + 4),&local_24,local_34);
      OffsetRect(&local_24,-1,-1);
      local_38 = CBrush::vftable;
      FUN_00416100();
    }
  }
  if ((*(uint *)(in_ECX + 0x24) & 0x40000) == 0) {
    local_28 = *(uint *)(in_ECX + 0xe8);
    if (local_28 == 0xffffffff) {
      local_28 = *(uint *)(in_ECX + 0xec);
    }
  }
  else {
    iVar2 = FUN_007c2511();
    local_28 = *(uint *)(iVar2 + 0x58);
  }
  FUN_0079de5e(((local_28 >> 0x10 & 0xff | 0x200) << 8 | (local_28 & 0xffff) >> 8) << 8 |
               local_28 & 0xff);
  this_00 = local_2c;
  local_8 = 0;
  uVar3 = FUN_0079efbc(local_40);
  pcVar1 = *(code **)(*(int *)this_00 + 0x24);
  guard_check_icall(8);
  uVar4 = (*pcVar1)();
  Rectangle(*(HDC *)(this_00 + 4),local_24.left,local_24.top,local_24.right,local_24.bottom);
  FUN_0079efbc(uVar4);
  FUN_0079efbc(uVar3);
  iVar2 = FUN_007c2574();
  if (*(int *)(iVar2 + 0x50) == 0) {
    iVar2 = FUN_007c2511();
    uVar6 = *(ulong *)(iVar2 + 100);
    iVar2 = FUN_007c2511();
    uVar5 = *(ulong *)(iVar2 + 0x58);
LAB_008a1bb0:
    CDC::Draw3dRect(this_00,&local_24,uVar5,uVar6);
  }
  else {
    iVar2 = FUN_007c2511();
    if (local_28 == *(uint *)(iVar2 + 0x54)) {
      iVar2 = FUN_007c2511();
      uVar6 = *(ulong *)(iVar2 + 0x60);
      iVar2 = FUN_007c2511();
      uVar5 = *(ulong *)(iVar2 + 0x60);
      goto LAB_008a1bb0;
    }
  }
  if (local_30 != (CPalette *)0x0) {
    CDC::SelectPalette(this_00,local_30,0);
  }
  local_40[0] = CBrush::vftable;
  FUN_00416100();
LAB_008a1bdd:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorMenuButton[27] */
/* 008a1beb  FUN_008a1beb  104 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a1beb(undefined4 param_1,LONG *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar1 = *(undefined4 *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x20) = 0;
  local_18.left = *param_2;
  local_18.top = param_2[1];
  local_18.right = param_2[2];
  local_18.bottom = param_2[3];
  InflateRect(&local_18,-1,0);
  FUN_0087792d(param_1,param_2,param_3);
  *(undefined4 *)(in_ECX + 0x20) = uVar1;
  return;
}




/* vtable slots: CMFCColorMenuButton[64] */
/* 008a1c53  OpenColorDialog  169 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    public: virtual int __thiscall CMFCColorMenuButton::OpenColorDialog(unsigned long,unsigned long
   &)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCColorMenuButton::OpenColorDialog(CMFCColorMenuButton *this,ulong param_1,ulong *param_2)

{
  int iVar1;
  undefined **local_ad4 [45];
  ulong local_a20;
  CMFCColorDialog local_a04 [228];
  ulong local_920;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xac4;
  local_8 = 0x8a1c62;
  if (*(int *)(this + 0x130) == 0) {
    CMFCColorDialog::CMFCColorDialog(local_a04,param_1,0,(CWnd *)0x0,(HPALETTE__ *)0x0);
    local_8 = 1;
    iVar1 = FUN_0079850d();
    if (iVar1 == 1) {
      *param_2 = local_920;
    }
    FUN_0089f663();
  }
  else {
    CColorDialog::CColorDialog((CColorDialog *)local_ad4,param_1,0x102,(CWnd *)0x0);
    local_8 = 0;
    iVar1 = CColorDialog::DoModal((CColorDialog *)local_ad4);
    if (iVar1 == 1) {
      *param_2 = local_a20;
    }
    local_ad4[0] = CCommonDialog::vftable;
    FUN_00797fb6();
  }
  iVar1 = FUN_008d9b68();
  return iVar1;
}




/* vtable slots: CMFCColorMenuButton[2] */
/* 008a1cfc  FUN_008a1cfc  588 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008a1cfc(CArchive *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  CObject *pCVar3;
  long *plVar4;
  CObject *in_ECX;
  int iVar5;
  CObList local_3c [4];
  undefined4 *local_38;
  CObject *local_20;
  CObject *local_1c [2];
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x8a1d08;
  local_20 = in_ECX;
  FUN_00877d12(param_1);
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0xf8));
    iVar5 = 0;
    if (0 < *(int *)(in_ECX + 0xf8)) {
      do {
        plVar4 = (long *)FUN_00799cf8(iVar5);
        CArchive::operator<<(param_1,*plVar4);
        iVar5 = iVar5 + 1;
      } while (iVar5 < *(int *)(in_ECX + 0xf8));
    }
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x10c));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x110));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x114));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x118));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x11c));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x120));
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0x124));
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0x128));
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 300));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0xec));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x130));
  }
  else {
    CArchive::operator>>(param_1,local_14);
    local_1c[0] = in_ECX + 0xf0;
    FUN_0079ca8b(local_14[0],0xffffffff);
    iVar5 = 0;
    if (0 < local_14[0]) {
      do {
        CArchive::operator>>(param_1,(long *)local_1c);
        piVar2 = (int *)FUN_00799cf8(iVar5);
        iVar5 = iVar5 + 1;
        *piVar2 = (int)local_1c[0];
        in_ECX = local_20;
      } while (iVar5 < local_14[0]);
    }
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x10c));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x110));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x114));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x118));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x11c));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x120));
    FUN_0047fc90(in_ECX + 0x124);
    FUN_0047fc90(in_ECX + 0x128);
    FUN_0047fc90(in_ECX + 300);
    CArchive::operator>>(param_1,(long *)(in_ECX + 0xec));
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x130));
    CObList::CObList(local_3c,10);
    local_8 = 0;
    iVar5 = FUN_007fdeef(*(undefined4 *)(in_ECX + 0x20),local_3c);
    if (0 < iVar5) {
      while (local_38 != (undefined4 *)0x0) {
        if (local_38 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        puVar1 = (undefined4 *)*local_38;
        pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCColorMenuButton_00a00c0c,
                                    (CObject *)local_38[2]);
        local_38 = puVar1;
        if (((pCVar3 != (CObject *)0x0) && (pCVar3 != in_ECX)) && (*(int *)(pCVar3 + 0xe8) != -1)) {
          *(int *)(in_ECX + 0xe8) = *(int *)(pCVar3 + 0xe8);
        }
      }
    }
    FUN_007a184a();
  }
  return;
}




/* vtable slots: CMFCColorMenuButton[63] */
/* 008a1f49  FUN_008a1f49  274 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008a1f49(undefined4 param_1,int param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  CObject *pCVar4;
  CObject *in_ECX;
  CObList local_30 [4];
  undefined4 *local_2c;
  CObject *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x8a1f55;
  *(undefined4 *)(in_ECX + 0xe8) = param_1;
  puVar2 = (undefined4 *)FUN_007e3332(*(undefined4 *)(in_ECX + 0x20));
  *puVar2 = param_1;
  iVar3 = *(int *)(in_ECX + 0x6c);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0x20) != 0)) {
    InvalidateRect(*(HWND *)(iVar3 + 0x20),(RECT *)(in_ECX + 0x54),1);
  }
  if (param_2 != 0) {
    CObList::CObList(local_30,10);
    local_8 = 0;
    iVar3 = FUN_007fdeef(*(undefined4 *)(in_ECX + 0x20),local_30);
    if (0 < iVar3) {
      while (local_2c != (undefined4 *)0x0) {
        if (local_2c == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        puVar2 = (undefined4 *)*local_2c;
        local_14[0] = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCColorMenuButton_00a00c0c,
                                         (CObject *)local_2c[2]);
        local_2c = puVar2;
        if ((local_14[0] != (CObject *)0x0) && (local_14[0] != in_ECX)) {
          pcVar1 = *(code **)(*(int *)local_14[0] + 0xfc);
          guard_check_icall(param_1,0);
          (*pcVar1)();
        }
      }
    }
    iVar3 = FUN_007fdde4();
    local_14[0] = *(CObject **)(iVar3 + 4);
    while (local_14[0] != (CObject *)0x0) {
      pCVar4 = (CObject *)FUN_0049acb0(local_14);
      pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCColorBar_00a007bc,pCVar4);
      if ((pCVar4 != (CObject *)0x0) && (*(int *)(pCVar4 + 0xe04) == *(int *)(in_ECX + 0x20))) {
        FUN_00824a91(param_1);
      }
    }
    FUN_007a184a();
  }
  return;
}



