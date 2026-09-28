/* CHelpComboBoxButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CHelpComboBoxButton[34], CMFCColorMenuButton[34], CMFCCustomizeButton[34], CMFCCustomizeMenuButton[34], CMFCDropDownToolbarButton[34], CMFCOutlookBarPaneButton[34], CMFCShowAllButton[34], CMFCToolBarButton[34], CMFCToolBarColorButton[34], CMFCToolBarComboBoxButton[34], CMFCToolBarFontComboBox[34], CMFCToolBarFontSizeComboBox[34], CMFCToolBarMenuButton[34], CMFCToolBarMenuButtonsButton[34], CMFCToolBarSystemMenuButton[34], COutlookCustomizeButton[34], CTasksPaneHistoryButton[34], CTasksPaneMenuButton[34], CTasksPaneNavigateButton[34] */
/* 00823277  GetInvalidateRect  23 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CRect const __thiscall CMFCToolBarButton::GetInvalidateRect(void)const 
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCToolBarButton::GetInvalidateRect(CMFCToolBarButton *this)

{
  undefined4 *in_stack_00000004;
  
  *in_stack_00000004 = *(undefined4 *)(this + 0x54);
  in_stack_00000004[1] = *(undefined4 *)(this + 0x58);
  in_stack_00000004[2] = *(undefined4 *)(this + 0x5c);
  in_stack_00000004[3] = *(undefined4 *)(this + 0x60);
  return;
}




/* vtable slots: CHelpComboBoxButton[50], CMFCColorMenuButton[50], CMFCCustomizeButton[50], CMFCCustomizeMenuButton[50], CMFCOutlookBarPaneButton[50], CMFCShowAllButton[50], CMFCToolBarButton[50], CMFCToolBarColorButton[50], CMFCToolBarComboBoxButton[50], CMFCToolBarEditBoxButton[50], CMFCToolBarFontComboBox[50], CMFCToolBarFontSizeComboBox[50], CMFCToolBarMenuButton[50], CMFCToolBarMenuButtonsButton[50], CMFCToolBarSystemMenuButton[50], COutlookCustomizeButton[50], CTasksPaneHistoryButton[50], CTasksPaneMenuButton[50], CTasksPaneNavigateButton[50] */
/* 008233c0  FUN_008233c0  4 bytes, 0 callers */

undefined4 FUN_008233c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x48);
}




/* vtable slots: CHelpComboBoxButton[51], CMFCToolBarComboBoxButton[51], CMFCToolBarFontComboBox[51], CMFCToolBarFontSizeComboBox[51] */
/* 008255e6  FUN_008255e6  250 bytes, 0 callers */

int FUN_008255e6(wchar_t *param_1,uint param_2)

{
  CSimpleStringT<wchar_t,0> *this;
  int iVar1;
  WPARAM wParam;
  int in_ECX;
  
  if (param_1 != (wchar_t *)0x0) {
    this = (CSimpleStringT<wchar_t,0> *)(in_ECX + 0xb8);
    if (*(int *)(*(int *)this + -0xc) == 0) {
      iVar1 = FUN_008f899d(param_1);
      ATL::CSimpleStringT<wchar_t,0>::SetString(this,param_1,iVar1);
      if (*(int *)(in_ECX + 0xb0) != 0) {
        FUN_00797ece(*(undefined4 *)this);
      }
    }
    iVar1 = FUN_00825d7c(param_1);
    if (iVar1 < 0) {
      AddTail(param_1);
      CList<unsigned_int,unsigned_int>::AddTail
                ((CList<unsigned_int,unsigned_int> *)(in_ECX + 0xd8),param_2);
    }
    iVar1 = *(int *)(in_ECX + 0xb4);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
      wParam = SendMessageW(*(HWND *)(iVar1 + 0x20),0x158,0xffffffff,(LPARAM)param_1);
      if (wParam == 0xffffffff) {
        wParam = SendMessageW(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20),0x143,0,(LPARAM)param_1);
      }
      SendMessageW(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20),0x14e,wParam,0);
      SendMessageW(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20),0x151,wParam,param_2);
      FUN_0057f840(0xffffffff,0);
    }
    return *(int *)(in_ECX + 200) + -1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CHelpComboBoxButton[52], CMFCToolBarComboBoxButton[52], CMFCToolBarFontComboBox[52], CMFCToolBarFontSizeComboBox[52] */
/* 008256e1  FUN_008256e1  433 bytes, 0 callers */

WPARAM FUN_008256e1(wchar_t *param_1,uint param_2)

{
  CSimpleStringT<wchar_t,0> *this;
  code *pcVar1;
  bool bVar2;
  int iVar3;
  __POSITION *p_Var4;
  WPARAM WVar5;
  int *in_ECX;
  UINT Msg;
  WPARAM local_8;
  
  if (param_1 == (wchar_t *)0x0) {
LAB_0082588d:
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  this = (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x2e);
  if (*(int *)(*(int *)this + -0xc) == 0) {
    iVar3 = FUN_008f899d(param_1);
    ATL::CSimpleStringT<wchar_t,0>::SetString(this,param_1,iVar3);
    if (in_ECX[0x2c] != 0) {
      FUN_00797ece(*(undefined4 *)this);
    }
  }
  bVar2 = false;
  iVar3 = FUN_00825d7c(param_1);
  local_8 = 0;
  if (iVar3 < 0) {
    local_8 = 0;
    WVar5 = 0;
    if (0 < in_ECX[0x32]) {
      do {
        p_Var4 = CObList::FindIndex((CObList *)(in_ECX + 0x2f),local_8);
        if (p_Var4 == (__POSITION *)0x0) goto LAB_0082588d;
        pcVar1 = *(code **)(*in_ECX + 0xe8);
        guard_check_icall(param_1,*(undefined4 *)(p_Var4 + 8));
        iVar3 = (*pcVar1)();
        if (iVar3 < 0) {
          InsertBefore(p_Var4,param_1);
          p_Var4 = CObList::FindIndex((CObList *)(in_ECX + 0x36),local_8);
          InsertBefore(p_Var4,param_2);
          bVar2 = true;
          goto LAB_008257a6;
        }
        local_8 = local_8 + 1;
        WVar5 = local_8;
      } while ((int)local_8 < in_ECX[0x32]);
    }
    local_8 = WVar5;
    AddTail(param_1);
    CList<unsigned_int,unsigned_int>::AddTail
              ((CList<unsigned_int,unsigned_int> *)(in_ECX + 0x36),param_2);
  }
LAB_008257a6:
  iVar3 = in_ECX[0x2d];
  if ((iVar3 != 0) && (*(int *)(iVar3 + 0x20) != 0)) {
    WVar5 = SendMessageW(*(HWND *)(iVar3 + 0x20),0x158,0xffffffff,(LPARAM)param_1);
    if (WVar5 == 0xffffffff) {
      if (bVar2) {
        Msg = 0x14a;
        WVar5 = local_8;
      }
      else {
        Msg = 0x143;
        WVar5 = 0;
      }
      WVar5 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),Msg,WVar5,(LPARAM)param_1);
    }
    SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x14e,WVar5,0);
    SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x151,WVar5,param_2);
    FUN_0057f840(0xffffffff,0);
  }
  if (!bVar2) {
    local_8 = in_ECX[0x32] - 1;
  }
  return local_8;
}




/* vtable slots: CHelpComboBoxButton[58], CMFCToolBarComboBoxButton[58], CMFCToolBarFontComboBox[58], CMFCToolBarFontSizeComboBox[58] */
/* 00825ad7  FUN_00825ad7  20 bytes, 0 callers */

void FUN_00825ad7(wchar_t *param_1,wchar_t *param_2)

{
  _wcscmp(param_1,param_2);
  return;
}




/* vtable slots: CHelpComboBoxButton[53], CMFCToolBarComboBoxButton[53] */
/* 00825bcd  FUN_00825bcd  131 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_00825bcd(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)FUN_0078e624(0x80);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_007907c8();
    *piVar2 = (int)CComboBox::vftable;
  }
  pcVar1 = *(code **)(*piVar2 + 0x164);
  guard_check_icall(*(undefined4 *)(in_ECX + 0x8c),param_2,param_1,*(undefined4 *)(in_ECX + 0x20));
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    pcVar1 = *(code **)(*piVar2 + 4);
    guard_check_icall(1);
    (*pcVar1)();
    piVar2 = (int *)0x0;
  }
  return piVar2;
}




/* vtable slots: CHelpComboBoxButton[54], CMFCToolBarComboBoxButton[54], CMFCToolBarFontComboBox[54], CMFCToolBarFontSizeComboBox[54] */
/* 00825c50  FUN_00825c50  111 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_00825c50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  iVar2 = FUN_0078e624(0x88);
  piVar3 = (int *)0x0;
  if (iVar2 != 0) {
    piVar3 = (int *)FUN_00825467(in_ECX);
  }
  iVar2 = FUN_00798f4d(param_3,param_2,param_1,*(undefined4 *)(in_ECX + 0x20));
  if (iVar2 == 0) {
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    piVar3 = (int *)0x0;
  }
  return piVar3;
}




/* vtable slots: CHelpComboBoxButton[38], CMFCToolBarComboBoxButton[38], CMFCToolBarFontComboBox[38], CMFCToolBarFontSizeComboBox[38] */
/* 00825cbf  EnableWindow  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCToolBarComboBoxButton::EnableWindow(int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

void __thiscall CMFCToolBarComboBoxButton::EnableWindow(CMFCToolBarComboBoxButton *this,int param_1)

{
  if ((*(int *)(this + 0xb4) != 0) && (*(int *)(*(int *)(this + 0xb4) + 0x20) != 0)) {
    FUN_007979e8(param_1);
  }
  if ((*(int *)(this + 0xb0) != 0) && (*(int *)(*(int *)(this + 0xb0) + 0x20) != 0)) {
    FUN_007979e8();
    return;
  }
  return;
}




/* vtable slots: CHelpComboBoxButton[11], CMFCToolBarComboBoxButton[11], CMFCToolBarFontComboBox[11], CMFCToolBarFontSizeComboBox[11] */
/* 00825cf8  FUN_00825cf8  132 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00825cf8(int param_1)

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
  local_8 = 0x825d04;
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
  return 1;
}




/* vtable slots: CHelpComboBoxButton[55], CMFCToolBarComboBoxButton[55], CMFCToolBarFontComboBox[55], CMFCToolBarFontSizeComboBox[55] */
/* 00825dd9  FUN_00825dd9  7 bytes, 0 callers */

undefined4 FUN_00825dd9(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb0);
}




/* vtable slots: CHelpComboBoxButton[14], CMFCToolBarComboBoxButton[14], CMFCToolBarFontComboBox[14], CMFCToolBarFontSizeComboBox[14] */
/* 00825de0  FUN_00825de0  15 bytes, 0 callers */

undefined4 FUN_00825de0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) == 0) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 0xb4) + 0x20);
}




/* vtable slots: CHelpComboBoxButton[41], CMFCToolBarComboBoxButton[41], CMFCToolBarFontComboBox[41], CMFCToolBarFontSizeComboBox[41] */
/* 00825edc  FUN_00825edc  143 bytes, 0 callers */

undefined4 FUN_00825edc(void)

{
  CWnd *pCVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  LRESULT LVar4;
  BOOL BVar5;
  undefined4 uVar6;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xb4) == 0) {
LAB_00825f65:
    uVar6 = 0;
  }
  else {
    pHVar2 = GetFocus();
    pCVar3 = CWnd::FromHandle(pHVar2);
    LVar4 = SendMessageW(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20),0x157,0,0);
    if ((LVar4 == 0) && (pCVar3 != *(CWnd **)(in_ECX + 0xb4))) {
      pHVar2 = (HWND)0x0;
      if (pCVar3 != (CWnd *)0x0) {
        pHVar2 = *(HWND *)(pCVar3 + 0x20);
      }
      BVar5 = IsChild(*(HWND *)(*(CWnd **)(in_ECX + 0xb4) + 0x20),pHVar2);
      if (BVar5 == 0) {
        pCVar1 = *(CWnd **)(in_ECX + 0xb0);
        if (pCVar1 != (CWnd *)0x0) {
          if (pCVar3 != pCVar1) {
            pHVar2 = (HWND)0x0;
            if (pCVar3 != (CWnd *)0x0) {
              pHVar2 = *(HWND *)(pCVar3 + 0x20);
            }
            BVar5 = IsChild(*(HWND *)(pCVar1 + 0x20),pHVar2);
            if (BVar5 == 0) {
              return 0;
            }
          }
          return 1;
        }
        goto LAB_00825f65;
      }
    }
    uVar6 = 1;
  }
  return uVar6;
}




/* vtable slots: CHelpComboBoxButton[40], CMFCToolBarComboBoxButton[40], CMFCToolBarFontComboBox[40], CMFCToolBarFontSizeComboBox[40] */
/* 00825fbe  FUN_00825fbe  90 bytes, 0 callers */

undefined4 FUN_00825fbe(HWND param_1)

{
  HWND pHVar1;
  BOOL BVar2;
  int in_ECX;
  
  if ((((*(int *)(in_ECX + 0xb4) == 0) ||
       (pHVar1 = *(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20), pHVar1 == (HWND)0x0)) ||
      ((pHVar1 != param_1 && (BVar2 = IsChild(pHVar1,param_1), BVar2 == 0)))) &&
     (((*(int *)(in_ECX + 0xb0) == 0 ||
       (pHVar1 = *(HWND *)(*(int *)(in_ECX + 0xb0) + 0x20), pHVar1 == (HWND)0x0)) ||
      ((pHVar1 != param_1 && (BVar2 = IsChild(pHVar1,param_1), BVar2 == 0)))))) {
    return 0;
  }
  return 1;
}




/* vtable slots: CHelpComboBoxButton[39], CMFCToolBarComboBoxButton[39], CMFCToolBarFontComboBox[39], CMFCToolBarFontSizeComboBox[39] */
/* 00826018  FUN_00826018  68 bytes, 0 callers */

undefined4 FUN_00826018(void)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0xb4) == 0) || (*(int *)(*(int *)(in_ECX + 0xb4) + 0x20) == 0)) {
LAB_00826037:
    if ((*(int *)(in_ECX + 0xb0) != 0) && (*(int *)(*(int *)(in_ECX + 0xb0) + 0x20) != 0)) {
      uVar1 = FUN_00797b3d();
      if ((uVar1 >> 0x1c & 1) != 0) goto LAB_00826052;
    }
    uVar2 = 0;
  }
  else {
    uVar1 = FUN_00797b3d();
    if ((uVar1 >> 0x1c & 1) == 0) goto LAB_00826037;
LAB_00826052:
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CHelpComboBoxButton[16], CMFCToolBarComboBoxButton[16], CMFCToolBarFontComboBox[16], CMFCToolBarFontSizeComboBox[16] */
/* 0082605c  FUN_0082605c  982 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0082605c(int param_1)

{
  undefined4 *puVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  LRESULT LVar4;
  int iVar5;
  WPARAM wParam;
  CObject *pCVar6;
  CObject *in_ECX;
  undefined4 uVar7;
  CObList local_50 [4];
  undefined4 *local_4c;
  CObList local_34 [4];
  undefined4 *local_30;
  WPARAM local_18;
  CObject *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x40;
  local_8 = 0x826068;
  iVar5 = *(int *)(in_ECX + 0xb4);
  if (iVar5 == 0) {
    return 0;
  }
  if (*(int *)(iVar5 + 0x20) == 0) {
    return 0;
  }
  if (DAT_00a0082c != 0) {
    if (param_1 == 0) {
      return 1;
    }
    pHVar2 = GetParent(*(HWND *)(iVar5 + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    if (pCVar3 != (CWnd *)0x0) {
      pHVar2 = GetParent(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20));
      pCVar3 = CWnd::FromHandle(pHVar2);
      InvalidateRect(*(HWND *)(pCVar3 + 0x20),(RECT *)(in_ECX + 0x90),1);
      pHVar2 = GetParent(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20));
      pCVar3 = CWnd::FromHandle(pHVar2);
      UpdateWindow(*(HWND *)(pCVar3 + 0x20));
    }
  }
  if (param_1 == 1) {
    if (*(int *)(in_ECX + 0xb0) == 0) {
      return 1;
    }
    CStringT<>();
    local_8 = 1;
    LVar4 = SendMessageW(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20),0x147,0,0);
    GetLBText(LVar4,local_14);
    FUN_00797ece(local_14[0]);
    FUN_00406b10();
    return 1;
  }
  if (param_1 != 3) {
    if (param_1 == 4) {
      return 1;
    }
    if (param_1 == 5) {
      FUN_00792c64(in_ECX + 0xb8);
      if ((*(int *)(in_ECX + 0xb0) != 0) && (*(int *)(*(int *)(in_ECX + 0xb0) + 0x20) != 0)) {
        CStringT<>();
        local_8 = 2;
        FUN_00792c64(local_14);
        iVar5 = *(int *)(in_ECX + 0xb4);
        if ((iVar5 != 0) && (*(int *)(iVar5 + 0x20) != 0)) {
          LVar4 = SendMessageW(*(HWND *)(iVar5 + 0x20),0x147,0,0);
          local_18 = LVar4 + 1;
          wParam = SendMessageW(*(HWND *)(iVar5 + 0x20),0x158,local_18,(LPARAM)local_14[0]);
          if ((wParam != 0xffffffff) ||
             (wParam = SendMessageW(*(HWND *)(iVar5 + 0x20),0x14c,local_18,(LPARAM)local_14[0]),
             wParam != 0xffffffff)) {
            SendMessageW(*(HWND *)(iVar5 + 0x20),0x14e,wParam,0);
          }
          FUN_00797ece(local_14[0]);
        }
        local_8 = 0xffffffff;
        FUN_00406b10();
      }
      CObList::CObList(local_50,10);
      local_8 = 3;
      iVar5 = FUN_007fdeef(*(undefined4 *)(in_ECX + 0x20),local_50);
      if (0 < iVar5) {
        while (local_4c != (undefined4 *)0x0) {
          if (local_4c == (undefined4 *)0x0) goto LAB_0082642d;
          puVar1 = (undefined4 *)*local_4c;
          pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarComboBoxButton_00a00810,
                                      (CObject *)local_4c[2]);
          local_4c = puVar1;
          if ((pCVar6 != (CObject *)0x0) && (pCVar6 != in_ECX)) {
            if (*(int *)(pCVar6 + 0xb4) != 0) {
              FUN_00797ece(*(undefined4 *)(in_ECX + 0xb8));
            }
            ATL::CSimpleStringT<wchar_t,0>::operator=
                      ((CSimpleStringT<wchar_t,0> *)(pCVar6 + 0xb8),
                       (CSimpleStringT<wchar_t,0> *)(in_ECX + 0xb8));
          }
        }
      }
      FUN_007a184a();
      return 1;
    }
    if (param_1 == 6) {
      return 1;
    }
    if (param_1 != 9) {
      return 0;
    }
    LVar4 = SendMessageW(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20),0x147,0,0);
    *(LRESULT *)(in_ECX + 0x74) = LVar4;
    if (LVar4 < 0) {
      return 0;
    }
    GetLBText(LVar4,in_ECX + 0xb8);
    if (*(int *)(in_ECX + 0xb0) != 0) {
      FUN_00797ece(*(undefined4 *)(in_ECX + 0xb8));
    }
    CObList::CObList(local_34,10);
    local_8 = 0;
    iVar5 = FUN_007fdeef(*(undefined4 *)(in_ECX + 0x20),local_34);
    if (0 < iVar5) {
      while (local_30 != (undefined4 *)0x0) {
        if (local_30 == (undefined4 *)0x0) {
LAB_0082642d:
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        puVar1 = (undefined4 *)*local_30;
        local_14[0] = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarComboBoxButton_00a00810,
                                         (CObject *)local_30[2]);
        local_30 = puVar1;
        if ((local_14[0] != (CObject *)0x0) && (local_14[0] != in_ECX)) {
          uVar7 = 0;
          LVar4 = SendMessageW(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20),0x147,0,0);
          FUN_008279e7(LVar4,uVar7);
          iVar5 = *(int *)(local_14[0] + 0xb4);
          if ((iVar5 != 0) && (*(int *)(iVar5 + 0x20) != 0)) {
            pHVar2 = GetParent(*(HWND *)(iVar5 + 0x20));
            pCVar3 = CWnd::FromHandle(pHVar2);
            if (pCVar3 != (CWnd *)0x0) {
              pHVar2 = GetParent(*(HWND *)(*(int *)(local_14[0] + 0xb4) + 0x20));
              pCVar3 = CWnd::FromHandle(pHVar2);
              InvalidateRect(*(HWND *)(pCVar3 + 0x20),(RECT *)(local_14[0] + 0x90),1);
              pHVar2 = GetParent(*(HWND *)(*(int *)(local_14[0] + 0xb4) + 0x20));
              pCVar3 = CWnd::FromHandle(pHVar2);
              UpdateWindow(*(HWND *)(pCVar3 + 0x20));
            }
          }
        }
      }
    }
    local_8 = 0xffffffff;
    FUN_007a184a();
  }
  if (*(int *)(in_ECX + 0xb0) != 0) {
    FUN_00797df8();
  }
  return 1;
}




/* vtable slots: CHelpComboBoxButton[17], CMFCToolBarComboBoxButton[17], CMFCToolBarEditBoxButton[17], CMFCToolBarFontComboBox[17], CMFCToolBarFontSizeComboBox[17] */
/* 00826433  FUN_00826433  81 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00826433(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  CObList local_2c [4];
  int local_28;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x82643f;
  CObList::CObList(local_2c,10);
  local_8 = 0;
  iVar2 = FUN_007fdeef(in_ECX[8],local_2c);
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x14);
    guard_check_icall(*(undefined4 *)(local_28 + 8));
    (*pcVar1)();
  }
  FUN_007a184a();
  return;
}




/* vtable slots: CHelpComboBoxButton[7], CMFCToolBarComboBoxButton[7], CMFCToolBarFontComboBox[7], CMFCToolBarFontSizeComboBox[7] */
/* 00826484  FUN_00826484  628 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_00826484(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  tagCOMBOBOXINFO local_4c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(int *)(in_ECX + 0x7c) = param_4;
  if (*(int *)(in_ECX + 0x50) == 0) {
    if (((DAT_00a0082c != 0) && (*(int *)(in_ECX + 0xb0) != 0)) &&
       (*(int *)(*(int *)(in_ECX + 0xb0) + 0x20) != 0)) {
      uVar2 = FUN_00797b3d();
      if ((uVar2 >> 0x1c & 1) != 0) {
        FUN_00797f20(0);
      }
    }
    if ((*(int *)(in_ECX + 0xb4) != 0) && (*(int *)(*(int *)(in_ECX + 0xb4) + 0x20) != 0)) {
      uVar2 = FUN_00797b3d();
      if ((uVar2 >> 0x1c & 1) != 0) {
        FUN_00797f20(0);
      }
    }
    *param_1 = 0;
    param_1[1] = 0;
  }
  else {
    if (((DAT_00a0082c != 0) && (*(int *)(in_ECX + 0xb4) != 0)) &&
       (*(int *)(*(int *)(in_ECX + 0xb4) + 0x20) != 0)) {
      uVar2 = FUN_00797b3d();
      if ((uVar2 >> 0x1c & 1) != 0) {
        FUN_00797f20(0);
      }
    }
    if (param_4 == 0) {
      if ((*(int *)(in_ECX + 0xb4) != 0) && (*(int *)(*(int *)(in_ECX + 0xb4) + 0x20) != 0)) {
        uVar2 = FUN_00797b3d();
        if ((uVar2 >> 0x1c & 1) != 0) {
          FUN_00797f20(0);
        }
      }
      if ((*(int *)(in_ECX + 0xb0) != 0) && (*(int *)(*(int *)(in_ECX + 0xb0) + 0x20) != 0)) {
        uVar2 = FUN_00797b3d();
        if ((uVar2 >> 0x1c & 1) != 0) {
          FUN_00797f20(0);
        }
      }
      FUN_00881448(param_1,param_2,param_3,0);
    }
    else {
      if ((((DAT_00a0082c == 0) && (*(int *)(in_ECX + 0xb4) != 0)) &&
          (*(int *)(*(int *)(in_ECX + 0xb4) + 0x20) != 0)) && (*(int *)(in_ECX + 0x40) == 0)) {
        FUN_00797f20(4);
      }
      if ((*(int *)(in_ECX + 0x18) != 0) && (*(int *)(*(int *)(in_ECX + 0x2c) + -0xc) != 0)) {
        local_18.right = *(int *)(in_ECX + 0x70);
        local_18.bottom = *(int *)(param_3 + 4);
        local_18.left = 0;
        local_18.top = 0;
        FUN_007c2378((int *)(in_ECX + 0x2c),&local_18,0x411);
        *(LONG *)(in_ECX + 100) = local_18.right - local_18.left;
        *(LONG *)(in_ECX + 0x68) = local_18.bottom - local_18.top;
      }
      iVar3 = *(int *)(param_3 + 4);
      if ((*(int *)(in_ECX + 0xb4) != 0) && (*(int *)(*(int *)(in_ECX + 0xb4) + 0x20) != 0)) {
        iVar3 = FUN_007c2511();
        if (*(int *)(iVar3 + 0x17c) == 0) {
          local_18.left = 0;
          local_18.top = 0;
          local_18.right = 0;
          local_18.bottom = 0;
          GetWindowRect(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20),&local_18);
          iVar3 = local_18.bottom - local_18.top;
        }
        else {
          _memset(&local_4c,0,0x34);
          local_4c.cbSize = 0x34;
          GetComboBoxInfo(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20),&local_4c);
          iVar3 = local_4c.rcButton.bottom - local_4c.rcButton.top;
        }
      }
      if (((*(int *)(in_ECX + 0x40) == 0) && (*(int *)(in_ECX + 0xb0) != 0)) &&
         (*(int *)(*(int *)(in_ECX + 0xb0) + 0x20) != 0)) {
        uVar2 = FUN_00797b3d();
        if ((uVar2 & 0x10000000) == 0) {
          FUN_00797f20(4);
        }
      }
      iVar1 = *(int *)(in_ECX + 0x68);
      *param_1 = *(undefined4 *)(in_ECX + 0x70);
      param_1[1] = iVar1 + iVar3;
    }
  }
  return param_1;
}




/* vtable slots: CHelpComboBoxButton[10], CMFCToolBarComboBoxButton[10], CMFCToolBarFontComboBox[10], CMFCToolBarFontSizeComboBox[10] */
/* 00826716  FUN_00826716  1180 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00826716(int param_1)

{
  LPARAM *pLVar1;
  code *pcVar2;
  undefined4 *puVar3;
  byte bVar4;
  HWND pHVar5;
  CWnd *pCVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  LRESULT LVar11;
  int *piVar12;
  int *in_ECX;
  WPARAM WVar13;
  undefined4 local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x826722;
  local_28 = param_1;
  FUN_00881617(param_1);
  iVar9 = in_ECX[0x2d];
  if ((iVar9 != 0) && (*(int *)(iVar9 + 0x20) != 0)) {
    pHVar5 = GetParent(*(HWND *)(iVar9 + 0x20));
    pCVar6 = CWnd::FromHandle(pHVar5);
    if (pCVar6 == (CWnd *)0x0) {
LAB_00826bad:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    if ((param_1 != 0) && (*(int *)(pCVar6 + 0x20) == *(int *)(param_1 + 0x20))) goto LAB_00826ba5;
    pcVar2 = *(code **)(*(int *)in_ECX[0x2d] + 0x60);
    guard_check_icall();
    (*pcVar2)();
    if ((int *)in_ECX[0x2d] != (int *)0x0) {
      pcVar2 = *(code **)(*(int *)in_ECX[0x2d] + 4);
      guard_check_icall(1);
      (*pcVar2)();
    }
    in_ECX[0x2d] = 0;
    param_1 = local_28;
    if ((int *)in_ECX[0x2c] != (int *)0x0) {
      pcVar2 = *(code **)(*(int *)in_ECX[0x2c] + 0x60);
      guard_check_icall();
      (*pcVar2)();
      if ((int *)in_ECX[0x2c] != (int *)0x0) {
        pcVar2 = *(code **)(*(int *)in_ECX[0x2c] + 4);
        guard_check_icall(1);
        (*pcVar2)();
      }
      in_ECX[0x2c] = 0;
      param_1 = local_28;
    }
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    if ((DAT_00a127ac == 0) && ((in_ECX[9] & 0x40000U) == 0)) {
      local_2c = 1;
      local_30 = 1;
    }
    else {
      local_2c = 0;
      local_30 = 0;
    }
    local_24.left = in_ECX[0x15];
    local_24.top = in_ECX[0x16];
    local_24.right = in_ECX[0x17];
    local_24.bottom = in_ECX[0x18];
    InflateRect(&local_24,-2,0);
    iVar9 = local_28;
    local_24.bottom = in_ECX[0x1e] + local_24.top;
    pcVar2 = *(code **)(*in_ECX + 0xd4);
    guard_check_icall(local_28,&local_24);
    iVar7 = (*pcVar2)();
    in_ECX[0x2d] = iVar7;
    if (iVar7 != 0) {
      if (*(int *)(iVar7 + 0x20) != 0) {
        FUN_007979e8(local_30);
        RedrawWindow(*(HWND *)(in_ECX[0x2d] + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
      }
      if ((DAT_00a0082c != 0) && (bVar4 = FUN_00797b3d(), (bVar4 & 3) == 2)) {
        uVar8 = FUN_00797b3d();
        pcVar2 = *(code **)(*in_ECX + 0xd8);
        guard_check_icall(iVar9,&local_24,uVar8 & 0x10000 | 0x50001080);
        iVar9 = (*pcVar2)();
        in_ECX[0x2c] = iVar9;
        if (iVar9 == 0) goto LAB_00826ba5;
        iVar7 = FUN_007c2511();
        WVar13 = 0;
        if (iVar7 != -0x11c) {
          WVar13 = *(WPARAM *)(iVar7 + 0x120);
        }
        SendMessageW(*(HWND *)(iVar9 + 0x20),0x30,WVar13,1);
        iVar9 = in_ECX[0x2c];
        pHVar5 = GetParent(*(HWND *)(in_ECX[0x2d] + 0x20));
        pCVar6 = CWnd::FromHandle(pHVar5);
        pCVar6 = CWnd::GetOwner(pCVar6);
        if (pCVar6 == (CWnd *)0x0) {
          uVar10 = 0;
        }
        else {
          uVar10 = *(undefined4 *)(pCVar6 + 0x20);
        }
        *(undefined4 *)(iVar9 + 0x5c) = uVar10;
        if ((in_ECX[0x2c] != 0) && (*(int *)(in_ECX[0x2c] + 0x20) != 0)) {
          FUN_007979e8(local_2c);
          RedrawWindow(*(HWND *)(in_ECX[0x2c] + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
        }
      }
      FUN_00825893();
      iVar9 = in_ECX[0x2d];
      iVar7 = FUN_007c2511();
      WVar13 = 0;
      if (iVar7 != -0x11c) {
        WVar13 = *(WPARAM *)(iVar7 + 0x120);
      }
      SendMessageW(*(HWND *)(iVar9 + 0x20),0x30,WVar13,1);
      LVar11 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x146,0,0);
      if (LVar11 < 1) {
        SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x14b,0,0);
        local_2c = in_ECX[0x30];
        puVar3 = (undefined4 *)in_ECX[0x37];
        while (local_2c != 0) {
          if (puVar3 == (undefined4 *)0x0) goto LAB_00826bad;
          piVar12 = (int *)FUN_00792938(&local_2c);
          iVar9 = FUN_004054a0(*piVar12 + -0x10);
          WVar13 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x143,0,iVar9 + 0x10);
          pLVar1 = puVar3 + 2;
          puVar3 = (undefined4 *)*puVar3;
          SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x151,WVar13,*pLVar1);
          FUN_00406b10();
        }
        if (in_ECX[0x1d] == 0xffffffff) goto LAB_00826ba5;
        SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x14e,in_ECX[0x1d],0);
      }
      else {
        FUN_00813b58();
        pcVar2 = *(code **)(*in_ECX + 0xe4);
        guard_check_icall();
        (*pcVar2)();
        RemoveAll();
        WVar13 = 0;
        LVar11 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x146,0,0);
        if (0 < LVar11) {
          do {
            CStringT<>();
            local_8 = 0;
            GetLBText(WVar13,&local_28);
            AddTail(&local_28);
            uVar8 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x150,WVar13,0);
            CList<unsigned_int,unsigned_int>::AddTail
                      ((CList<unsigned_int,unsigned_int> *)(in_ECX + 0x36),uVar8);
            local_8 = 0xffffffff;
            FUN_00406b10();
            WVar13 = WVar13 + 1;
            LVar11 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x146,0,0);
          } while ((int)WVar13 < LVar11);
        }
        LVar11 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x147,0,0);
        in_ECX[0x1d] = LVar11;
      }
      if ((in_ECX[0x1d] != -1) &&
         (LVar11 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x146,0,0), in_ECX[0x1d] < LVar11)) {
        piVar12 = in_ECX + 0x2e;
        GetLBText(in_ECX[0x1d],piVar12);
        FUN_00797ece(*piVar12);
        if (in_ECX[0x2c] != 0) {
          FUN_00797ece(*piVar12);
        }
      }
    }
  }
LAB_00826ba5:
  FUN_008d9b68();
  return;
}




/* vtable slots: CHelpComboBoxButton[8], CMFCToolBarComboBoxButton[8], CMFCToolBarFontComboBox[8], CMFCToolBarFontSizeComboBox[8] */
/* 00826bb3  OnClick  115 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCToolBarComboBoxButton::OnClick(class CWnd *,int)
   
   Library: Visual Studio 2012 Release */

int __thiscall
CMFCToolBarComboBoxButton::OnClick(CMFCToolBarComboBoxButton *this,CWnd *param_1,int param_2)

{
  int iVar1;
  
  if (((*(int *)(this + 0xb4) == 0) || (*(int *)(*(int *)(this + 0xb4) + 0x20) == 0)) ||
     (*(int *)(this + 0x7c) == 0)) {
    iVar1 = 0;
  }
  else {
    if (DAT_00a0082c != 0) {
      FUN_00797df8();
      SendMessageW(*(HWND *)(*(int *)(this + 0xb4) + 0x20),0x14f,1,0);
      if (param_1 != (CWnd *)0x0) {
        InvalidateRect(*(HWND *)(param_1 + 0x20),(RECT *)(this + 0x90),1);
      }
    }
    iVar1 = 1;
  }
  return iVar1;
}




/* vtable slots: CHelpComboBoxButton[18], CMFCToolBarComboBoxButton[18], CMFCToolBarEditBoxButton[18], CMFCToolBarFontComboBox[18], CMFCToolBarFontSizeComboBox[18] */
/* 00826ce2  FUN_00826ce2  81 bytes, 0 callers */

undefined4 FUN_00826ce2(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  
  pcVar1 = *(code **)(*param_1 + 0x30);
  iVar2 = FUN_007c2511();
  guard_check_icall(*(undefined4 *)(iVar2 + 0x70));
  (*pcVar1)();
  pcVar1 = *(code **)(*param_1 + 0x2c);
  iVar2 = FUN_007c2511();
  guard_check_icall(*(undefined4 *)(iVar2 + 0x6c));
  (*pcVar1)();
  iVar2 = FUN_007c2511();
  uVar3 = 0;
  if (iVar2 != -200) {
    uVar3 = *(undefined4 *)(iVar2 + 0xcc);
  }
  return uVar3;
}




/* vtable slots: CHelpComboBoxButton[6], CMFCToolBarComboBoxButton[6], CMFCToolBarFontComboBox[6], CMFCToolBarFontSizeComboBox[6] */
/* 00826d33  FUN_00826d33  1048 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00826d33(CDC *param_1,LONG *param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7,undefined4 param_8)

{
  code *pcVar1;
  ulong uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  LRESULT LVar6;
  COLORREF CVar7;
  uint uVar8;
  undefined4 uVar9;
  int *in_ECX;
  int local_7c;
  undefined4 local_68;
  int local_64;
  WPARAM local_60;
  uint local_58;
  undefined4 local_54;
  undefined4 local_50;
  int local_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  LRESULT local_3c;
  tagRECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (((in_ECX[0x2d] == 0) || (*(int *)(in_ECX[0x2d] + 0x20) == 0)) || (param_4 == 0)) {
    FUN_00881666(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    return;
  }
  if (param_5 == 0) {
    if ((in_ECX[9] & 0x40000U) != 0) goto LAB_00826dc9;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x60);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
LAB_00826dc9:
      iVar3 = 1;
      goto LAB_00826da1;
    }
  }
  iVar3 = 0;
LAB_00826da1:
  pcVar1 = *(code **)(*(int *)param_1 + 0x30);
  local_7c = param_6;
  if (iVar3 == 0) {
    if (param_6 == 0) {
      iVar4 = FUN_007c2511();
      uVar9 = *(undefined4 *)(iVar4 + 0x68);
    }
    else {
      uVar9 = FUN_007fe047();
    }
  }
  else {
    iVar4 = FUN_007c2511();
    uVar9 = *(undefined4 *)(iVar4 + 0x38);
  }
  guard_check_icall(uVar9);
  (*pcVar1)();
  if (DAT_00a0082c != 0) {
    if (in_ECX[0x20] != 0) {
      local_7c = 1;
    }
    local_18.left = in_ECX[0x24];
    local_18.top = in_ECX[0x25];
    local_18.right = in_ECX[0x26];
    local_18.bottom = in_ECX[0x27];
    piVar5 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar5 + 0x70);
    LVar6 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x157,0,0);
    guard_check_icall(param_1,local_18.left,local_18.top,local_18.right,local_18.bottom,iVar3,LVar6,
                      local_7c,in_ECX);
    (*pcVar1)();
    InflateRect(&local_18,-2,-2);
    CVar7 = GetTextColor(*(HDC *)(param_1 + 8));
    iVar4 = FUN_007c2511();
    if (iVar3 == 0) {
      uVar9 = *(undefined4 *)(iVar4 + 0x6c);
    }
    else {
      uVar9 = *(undefined4 *)(iVar4 + 0x1c);
    }
    FUN_007a506d(&local_18,uVar9);
    if (iVar3 != 0) {
      iVar4 = FUN_007c2511();
      uVar2 = *(ulong *)(iVar4 + 0x5c);
      iVar4 = FUN_007c2511();
      CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar4 + 0x5c),uVar2);
    }
    local_28.left = in_ECX[0x28];
    local_28.top = in_ECX[0x29];
    local_28.right = in_ECX[0x2a];
    local_28.bottom = in_ECX[0x2b];
    iVar4 = FUN_007c2511();
    if (*(int *)(iVar4 + 0x184) != 0) {
      InflateRect(&local_28,-1,-1);
    }
    if (local_18.left + 1 < local_28.left) {
      piVar5 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar5 + 0x6c);
      LVar6 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x157,0,0);
      guard_check_icall(param_1,local_28.left,local_28.top,local_28.right,local_28.bottom,iVar3,
                        LVar6,local_7c,in_ECX);
      (*pcVar1)();
    }
    pcVar1 = *(code **)(*(int *)param_1 + 0x30);
    guard_check_icall(CVar7);
    (*pcVar1)();
    if (*(int *)(in_ECX[0x2e] + -0xc) != 0) {
      local_38.left = local_18.left;
      local_38.right = in_ECX[0x28];
      local_38.top = local_18.top;
      local_38.bottom = local_18.bottom;
      InflateRect(&local_38,-2,-2);
      if (in_ECX[0x2c] == 0) {
        uVar8 = FUN_00797b3d();
        if ((uVar8 & 0x30) == 0) {
          pcVar1 = *(code **)(*(int *)param_1 + 0x30);
          iVar3 = FUN_007c2511();
          guard_check_icall(*(undefined4 *)(iVar3 + 0x70));
          uVar9 = (*pcVar1)();
          FUN_007c2378(in_ECX + 0x2e,&local_38,0x824);
          pcVar1 = *(code **)(*(int *)param_1 + 0x30);
          guard_check_icall(uVar9);
          (*pcVar1)();
        }
        else {
          _memset(&local_68,0,0x30);
          local_50 = *(undefined4 *)(param_1 + 4);
          local_4c = local_38.left;
          iStack_48 = local_38.top;
          iStack_44 = local_38.right;
          iStack_40 = local_38.bottom;
          local_64 = in_ECX[8];
          local_60 = SendMessageW(*(HWND *)(in_ECX[0x2d] + 0x20),0x147,0,0);
          iVar4 = in_ECX[0x2d];
          if (iVar4 == 0) {
            local_54 = 0;
          }
          else {
            local_54 = *(undefined4 *)(iVar4 + 0x20);
          }
          local_58 = local_58 | 0x1000;
          local_68 = 3;
          local_3c = SendMessageW(*(HWND *)(iVar4 + 0x20),0x150,local_60,0);
          if (iVar3 != 0) {
            local_58 = local_58 | 4;
          }
          pcVar1 = *(code **)(*(int *)in_ECX[0x2d] + 0x168);
          guard_check_icall(&local_68);
          (*pcVar1)();
        }
      }
    }
    pcVar1 = *(code **)(*(int *)param_1 + 0x30);
    guard_check_icall(CVar7);
    (*pcVar1)();
  }
  if ((in_ECX[6] != 0) && (*(int *)(in_ECX[0xb] + -0xc) != 0)) {
    local_28.left = *param_2;
    local_28.top = ((in_ECX[0x27] - in_ECX[0x1a]) + param_2[3]) / 2;
    local_28.right = param_2[2];
    local_28.bottom = param_2[3];
    FUN_007c2378(in_ECX + 0xb,&local_28,0x11);
  }
  return;
}




/* vtable slots: CHelpComboBoxButton[27], CMFCToolBarComboBoxButton[27], CMFCToolBarFontComboBox[27], CMFCToolBarFontSizeComboBox[27] */
/* 0082714b  FUN_0082714b  269 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0082714b(CDC *param_1,int *param_2,undefined4 param_3)

{
  ulong uVar1;
  code *pcVar2;
  int iVar3;
  HBRUSH hbr;
  int *piVar4;
  undefined4 in_ECX;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar3 = FUN_008822bb(param_1,param_2,param_3);
  local_18.top = param_2[1];
  iVar3 = (param_2[2] - *param_2) - (iVar3 + 10);
  local_18.right = param_2[2];
  local_18.bottom = param_2[3];
  local_18.left = 0x14;
  if (0x13 < iVar3) {
    local_18.left = iVar3;
  }
  local_18.left = local_18.right - local_18.left;
  InflateRect(&local_18,-1,-1);
  iVar3 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar3 != -200) {
    hbr = *(HBRUSH *)(iVar3 + 0xcc);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_18,hbr);
  iVar3 = FUN_007c2511();
  uVar1 = *(ulong *)(iVar3 + 0x58);
  iVar3 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar3 + 0x58),uVar1);
  local_28.left = local_18.right + 2 + (local_18.top - local_18.bottom);
  local_28.top = local_18.top;
  local_28.right = local_18.right;
  local_28.bottom = local_18.bottom;
  InflateRect(&local_28,-1,-1);
  piVar4 = (int *)FUN_007c2574();
  pcVar2 = *(code **)(*piVar4 + 0x6c);
  guard_check_icall(param_1,local_28.left,local_28.top,local_28.right,local_28.bottom,0,0,0,in_ECX);
  (*pcVar2)();
  return param_2[2] - *param_2;
}




/* vtable slots: CHelpComboBoxButton[23], CMFCToolBarComboBoxButton[23], CMFCToolBarFontComboBox[23], CMFCToolBarFontSizeComboBox[23] */
/* 00827258  FUN_00827258  103 bytes, 0 callers */

void FUN_00827258(void)

{
  int iVar1;
  int iVar2;
  WPARAM wParam;
  int in_ECX;
  WPARAM wParam_00;
  
  wParam_00 = 0;
  iVar1 = *(int *)(in_ECX + 0xb0);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    iVar2 = FUN_007c2511();
    if (iVar2 == -0x11c) {
      wParam = 0;
    }
    else {
      wParam = *(WPARAM *)(iVar2 + 0x120);
    }
    SendMessageW(*(HWND *)(iVar1 + 0x20),0x30,wParam,1);
  }
  iVar1 = *(int *)(in_ECX + 0xb4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    iVar2 = FUN_007c2511();
    if (iVar2 != -0x11c) {
      wParam_00 = *(WPARAM *)(iVar2 + 0x120);
    }
    SendMessageW(*(HWND *)(iVar1 + 0x20),0x30,wParam_00,1);
  }
  return;
}




/* vtable slots: CHelpComboBoxButton[12], CMFCToolBarComboBoxButton[12], CMFCToolBarFontComboBox[12], CMFCToolBarFontSizeComboBox[12] */
/* 00827391  FUN_00827391  21 bytes, 0 callers */

void FUN_00827391(void)

{
  RECT *lprc;
  tagRECT *lpRect;
  LPRECT lprc_00;
  code *pcVar1;
  BOOL BVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int iVar5;
  int *piVar6;
  CObject *in_ECX;
  undefined1 auStack_c [4];
  CObject *pCStack_8;
  
  if ((*(int *)(in_ECX + 0xb4) == 0) || (*(int *)(*(int *)(in_ECX + 0xb4) + 0x20) == 0)) {
    return;
  }
  pCStack_8 = in_ECX;
  if ((*(int *)(in_ECX + 0xb4) != 0) && (*(int *)(*(int *)(in_ECX + 0xb4) + 0x20) != 0)) {
    lprc = (RECT *)(in_ECX + 0x54);
    BVar2 = IsRectEmpty(lprc);
    if ((BVar2 == 0) && (*(int *)(in_ECX + 0x7c) != 0)) {
      if ((DAT_00a00830 != 0) &&
         ((*(int *)(in_ECX + 0x18) == 0 || (*(int *)(*(int *)(in_ECX + 0x2c) + -0xc) == 0)))) {
        pHVar3 = GetParent(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20));
        pCVar4 = CWnd::FromHandle(pHVar3);
        do {
          if (pCVar4 == (CWnd *)0x0) goto LAB_00825984;
          pCStack_8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,
                                         (CObject *)pCVar4);
          pHVar3 = GetParent(*(HWND *)(pCVar4 + 0x20));
          pCVar4 = CWnd::FromHandle(pHVar3);
        } while (pCStack_8 == (CObject *)0x0);
        pcVar1 = *(code **)(*(int *)pCStack_8 + 0x354);
        guard_check_icall();
        iVar5 = (*pcVar1)();
        iVar5 = (iVar5 + (*(int *)(in_ECX + 0x58) - *(int *)(in_ECX + 0x60))) / 2;
        if (iVar5 < 0) {
          iVar5 = 0;
        }
        OffsetRect((LPRECT)(in_ECX + 0xa0),0,iVar5);
        OffsetRect((LPRECT)(in_ECX + 0x90),0,iVar5);
        OffsetRect(lprc,0,iVar5);
      }
LAB_00825984:
      FUN_00797e71(0,lprc->left + 1,*(int *)(in_ECX + 0x58),
                   (*(int *)(in_ECX + 0x5c) - lprc->left) + -2,*(int *)(in_ECX + 0x78),0x14);
      FUN_0057f840(0xffffffff,0);
      lpRect = (tagRECT *)(in_ECX + 0x90);
      GetWindowRect(*(HWND *)(*(int *)(in_ECX + 0xb4) + 0x20),lpRect);
      CWnd::ScreenToClient(*(CWnd **)(in_ECX + 0xb4),lpRect);
      iVar5 = *(int *)(in_ECX + 0xb4);
      pHVar3 = GetParent(*(HWND *)(iVar5 + 0x20));
      pCVar4 = CWnd::FromHandle(pHVar3);
      pHVar3 = (HWND)0x0;
      if (pCVar4 != (CWnd *)0x0) {
        pHVar3 = *(HWND *)(pCVar4 + 0x20);
      }
      MapWindowPoints(*(HWND *)(iVar5 + 0x20),pHVar3,(LPPOINT)lpRect,2);
      if (DAT_00a0082c != 0) {
        *(LONG *)(in_ECX + 0xa0) = lpRect->left;
        *(int *)(in_ECX + 0xa4) = *(int *)(in_ECX + 0x94);
        *(int *)(in_ECX + 0xa8) = *(int *)(in_ECX + 0x98);
        *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0x9c);
        piVar6 = (int *)FUN_0081507c(auStack_c);
        lprc_00 = (LPRECT)(in_ECX + 0xa0);
        lprc_00->left = *(int *)(in_ECX + 0xa8) + *piVar6 * -2;
        InflateRect(lprc_00,-2,-2);
        iVar5 = *(int *)(in_ECX + 0x90) + -1;
        *(int *)(in_ECX + 0x54) = iVar5;
        *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x98) + 1;
        if ((*(int *)(in_ECX + 0x18) == 0) || (*(int *)(*(int *)(in_ECX + 0x2c) + -0xc) == 0)) {
          *(int *)(in_ECX + 0x58) = *(int *)(in_ECX + 0x94);
          *(int *)(in_ECX + 0x60) = *(int *)(in_ECX + 0x9c);
        }
        if (*(int *)(in_ECX + 0xb0) == 0) {
          return;
        }
        FUN_00797e71(0,*(int *)(in_ECX + 0x90) + 3,*(int *)(in_ECX + 0x58) + 3,
                     lprc_00->left + -8 +
                     ((*(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0xa8)) - iVar5),
                     (*(int *)(in_ECX + 0x9c) - *(int *)(in_ECX + 0x94)) + -6,0x14);
        return;
      }
      goto LAB_00825acb;
    }
  }
  SetRectEmpty((LPRECT)(in_ECX + 0x90));
LAB_00825acb:
  SetRectEmpty((LPRECT)(in_ECX + 0xa0));
  return;
}




/* vtable slots: CHelpComboBoxButton[33], CMFCToolBarComboBoxButton[33], CMFCToolBarFontComboBox[33], CMFCToolBarFontSizeComboBox[33] */
/* 00827581  FUN_00827581  133 bytes, 0 callers */

void FUN_00827581(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  if ((in_ECX[0x2d] != 0) && (*(int *)(in_ECX[0x2d] + 0x20) != 0)) {
    if ((param_1 == 0) || (in_ECX[0x1f] == 0)) {
      FUN_00797f20(0);
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x30);
      guard_check_icall();
      (*pcVar1)();
      FUN_00797f20((-(uint)(DAT_00a0082c != 0) & 0xfffffffc) + 4);
    }
  }
  if ((in_ECX[0x2c] != 0) && (*(int *)(in_ECX[0x2c] + 0x20) != 0)) {
    if ((param_1 == 0) || (in_ECX[0x1f] == 0)) {
      uVar2 = 0;
    }
    else {
      uVar2 = 4;
    }
    FUN_00797f20(uVar2);
  }
  return;
}




/* vtable slots: CHelpComboBoxButton[13], CMFCToolBarComboBoxButton[13], CMFCToolBarFontComboBox[13], CMFCToolBarFontSizeComboBox[13] */
/* 00827606  FUN_00827606  42 bytes, 0 callers */

void FUN_00827606(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x70) = param_1;
  *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x54) + param_1;
  if ((*(int *)(in_ECX + 0xb4) != 0) && (*(int *)(*(int *)(in_ECX + 0xb4) + 0x20) != 0)) {
    FUN_00825893();
  }
  return;
}




/* vtable slots: CHelpComboBoxButton[43], CMFCToolBarComboBoxButton[43], CMFCToolBarFontComboBox[43], CMFCToolBarFontSizeComboBox[43] */
/* 00827630  FUN_00827630  204 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_00827630(int param_1,int param_2,undefined4 param_3,CSimpleStringT<wchar_t,0> *param_4)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uVar4;
  int *piVar5;
  CSimpleStringT<wchar_t,0> local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x82763c;
  if ((in_ECX[0x1f] == 0) || (DAT_00a005ec == 0)) {
    return 0;
  }
  CStringT<>();
  local_8 = 0;
  pcVar1 = *(code **)(*in_ECX + 0xa8);
  guard_check_icall(local_14);
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    ATL::CSimpleStringT<wchar_t,0>::operator=(param_4,local_14);
  }
  iVar3 = in_ECX[0x2d];
  if (DAT_00a0082c == 0) {
LAB_008276bf:
    if (iVar3 == 0) goto LAB_008276d2;
    param_2 = 0;
    piVar5 = (int *)0x0;
    uVar4 = *(undefined4 *)param_4;
    param_1 = iVar3;
  }
  else {
    if ((iVar3 != 0) && (bVar2 = FUN_00797b3d(), (bVar2 & 3) == 2)) {
      pcVar1 = *(code **)(*in_ECX + 0xdc);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      goto LAB_008276bf;
    }
    param_2 = param_2 + 1;
    piVar5 = in_ECX + 0x15;
    uVar4 = *(undefined4 *)param_4;
  }
  FUN_007af3f5(param_1,uVar4,piVar5,param_2);
LAB_008276d2:
  FUN_00406b10();
  return 1;
}




/* vtable slots: CHelpComboBoxButton[46], CMFCToolBarComboBoxButton[46], CMFCToolBarFontComboBox[46], CMFCToolBarFontSizeComboBox[46] */
/* 00827d41  FUN_00827d41  161 bytes, 0 callers */

undefined4 FUN_00827d41(undefined4 param_1,int param_2)

{
  code *pcVar1;
  wchar_t *pwVar2;
  byte bVar3;
  int iVar4;
  int *in_ECX;
  undefined4 uVar5;
  
  iVar4 = FUN_00882aa5(param_1,param_2);
  if (iVar4 != 0) {
    if ((in_ECX[0x2d] == 0) || (bVar3 = FUN_00797b3d(), (bVar3 & 3) != 3)) {
      uVar5 = 0x2e;
    }
    else {
      uVar5 = 0x2f;
    }
    *(undefined4 *)(param_2 + 0x18) = uVar5;
    *(undefined4 *)(param_2 + 0x1c) = 0x100000;
    pcVar1 = *(code **)(*in_ECX + 0xa4);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    if (iVar4 != 0) {
      *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 4;
    }
    iVar4 = FUN_008f899d(L"Open");
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)(param_2 + 0x14),L"Open",iVar4);
    pwVar2 = (wchar_t *)in_ECX[0x2e];
    if (pwVar2 == (wchar_t *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_008f899d(pwVar2);
    }
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)(param_2 + 4),pwVar2,iVar4);
    return 1;
  }
  return 0;
}




/* vtable slots: CHelpComboBoxButton[35], CMFCToolBarComboBoxButton[35], CMFCToolBarFontComboBox[35], CMFCToolBarFontSizeComboBox[35] */
/* 00827e5c  FUN_00827e5c  158 bytes, 0 callers */

void FUN_00827e5c(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  in_ECX[9] = param_1;
  if (DAT_00a127ac == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x60);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((iVar2 != 0) && ((in_ECX[9] & 0x40000U) == 0)) {
      uVar3 = 1;
      goto LAB_00827e9d;
    }
  }
  uVar3 = 0;
LAB_00827e9d:
  if ((in_ECX[0x2d] != 0) && (*(int *)(in_ECX[0x2d] + 0x20) != 0)) {
    FUN_007979e8(uVar3);
    RedrawWindow(*(HWND *)(in_ECX[0x2d] + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
  }
  if ((in_ECX[0x2c] != 0) && (*(int *)(in_ECX[0x2c] + 0x20) != 0)) {
    FUN_007979e8(uVar3);
    RedrawWindow(*(HWND *)(in_ECX[0x2c] + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
  }
  return;
}




/* vtable slots: CHelpComboBoxButton[59] */
/* 0083f9c3  FUN_0083f9c3  31 bytes, 1 callers */

void FUN_0083f9c3(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004054a0(*(int *)(in_ECX + 0xf4) + -0x10);
  *param_1 = iVar1 + 0x10;
  return;
}




/* vtable slots: CHelpComboBoxButton[37], CMFCDropDownToolbarButton[37], CMFCOutlookBarPaneButton[37], CMFCToolBarButton[37], CMFCToolBarColorButton[37], CMFCToolBarComboBoxButton[37], CMFCToolBarEditBoxButton[37], CMFCToolBarFontComboBox[37], CMFCToolBarFontSizeComboBox[37], CMFCToolBarMenuButtonsButton[37], CTasksPaneNavigateButton[37] */
/* 00880ed4  FUN_00880ed4  21 bytes, 0 callers */

bool FUN_00880ed4(int param_1)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x20) == *(int *)(param_1 + 0x20);
}




/* vtable slots: CHelpComboBoxButton[47], CMFCColorMenuButton[47], CMFCCustomizeButton[47], CMFCCustomizeMenuButton[47], CMFCDropDownToolbarButton[47], CMFCOutlookBarPaneButton[47], CMFCShowAllButton[47], CMFCToolBarButton[47], CMFCToolBarColorButton[47], CMFCToolBarComboBoxButton[47], CMFCToolBarEditBoxButton[47], CMFCToolBarFontComboBox[47], CMFCToolBarFontSizeComboBox[47], CMFCToolBarMenuButton[47], CMFCToolBarMenuButtonsButton[47], CMFCToolBarSystemMenuButton[47], COutlookCustomizeButton[47], CTasksPaneHistoryButton[47], CTasksPaneMenuButton[47], CTasksPaneNavigateButton[47] */
/* 008811dd  GetAccCount  36 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCToolBarButton::GetAccCount(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMFCToolBarButton::GetAccCount(CMFCToolBarButton *this)

{
  BOOL BVar1;
  
  if (*(int *)(this + 0x50) != 0) {
    BVar1 = IsRectEmpty((RECT *)(this + 0x54));
    if ((BVar1 == 0) && (((byte)this[0x24] & 1) == 0)) {
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CHelpComboBoxButton[44], CMFCColorMenuButton[44], CMFCCustomizeButton[44], CMFCCustomizeMenuButton[44], CMFCDropDownToolbarButton[44], CMFCOutlookBarPaneButton[44], CMFCShowAllButton[44], CMFCToolBarButton[44], CMFCToolBarColorButton[44], CMFCToolBarComboBoxButton[44], CMFCToolBarEditBoxButton[44], CMFCToolBarFontComboBox[44], CMFCToolBarFontSizeComboBox[44], CMFCToolBarMenuButton[44], CMFCToolBarMenuButtonsButton[44], CMFCToolBarSystemMenuButton[44], COutlookCustomizeButton[44], CTasksPaneHistoryButton[44], CTasksPaneMenuButton[44], CTasksPaneNavigateButton[44] */
/* 00881304  FUN_00881304  151 bytes, 0 callers */

undefined4 FUN_00881304(void)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  undefined4 uVar5;
  int local_8;
  
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,(CObject *)in_ECX[0x1b]);
  if ((pCVar2 != (CObject *)0x0) && (in_ECX != *(int **)(pCVar2 + 0xd14))) {
    local_8 = 0;
    uVar5 = 1;
    iVar3 = FUN_007fdf7c();
    if (0 < iVar3) {
      do {
        piVar4 = (int *)FUN_007fde79(local_8);
        if (piVar4 == in_ECX) {
          return uVar5;
        }
        if (piVar4[0x14] != 0) {
          if ((piVar4[4] == 0) && ((*(byte *)(piVar4 + 9) & 1) == 0)) {
            pcVar1 = *(code **)(*piVar4 + 0x38);
            guard_check_icall();
            iVar3 = (*pcVar1)();
            if (iVar3 == 0) {
              uVar5 = 0;
              goto LAB_0088137e;
            }
          }
          uVar5 = 1;
        }
LAB_0088137e:
        local_8 = local_8 + 1;
        iVar3 = FUN_007fdf7c();
      } while (local_8 < iVar3);
    }
  }
  return 0;
}




/* vtable slots: CHelpComboBoxButton[45], CMFCColorMenuButton[45], CMFCCustomizeButton[45], CMFCCustomizeMenuButton[45], CMFCDropDownToolbarButton[45], CMFCOutlookBarPaneButton[45], CMFCShowAllButton[45], CMFCToolBarButton[45], CMFCToolBarColorButton[45], CMFCToolBarComboBoxButton[45], CMFCToolBarEditBoxButton[45], CMFCToolBarFontComboBox[45], CMFCToolBarFontSizeComboBox[45], CMFCToolBarMenuButton[45], CMFCToolBarMenuButtonsButton[45], CMFCToolBarSystemMenuButton[45], COutlookCustomizeButton[45], CTasksPaneHistoryButton[45], CTasksPaneMenuButton[45], CTasksPaneNavigateButton[45] */
/* 0088139b  FUN_0088139b  173 bytes, 0 callers */

undefined4 FUN_0088139b(void)

{
  code *pcVar1;
  bool bVar2;
  CObject *pCVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *in_ECX;
  
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,(CObject *)in_ECX[0x1b]);
  if ((pCVar3 == (CObject *)0x0) || (piVar5 = *(int **)(pCVar3 + 0xd14), in_ECX == piVar5)) {
    return 0;
  }
  bVar2 = true;
  iVar4 = FUN_007fdf7c();
  if (piVar5 != (int *)0x0) {
    iVar4 = iVar4 + -1;
  }
joined_r0x008813e3:
  do {
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) {
      return 0;
    }
    piVar5 = (int *)FUN_007fde79(iVar4);
    if (piVar5 == in_ECX) {
      if ((!bVar2) && (piVar5[4] == 0)) {
        return 0;
      }
      return 1;
    }
  } while (piVar5[0x14] == 0);
  if ((*(byte *)(piVar5 + 9) & 1) == 0) goto code_r0x00881400;
  goto LAB_00881418;
code_r0x00881400:
  pcVar1 = *(code **)(*piVar5 + 0x38);
  guard_check_icall();
  iVar6 = (*pcVar1)();
  bVar2 = false;
  if (iVar6 != 0) {
LAB_00881418:
    bVar2 = true;
  }
  goto joined_r0x008813e3;
}




/* vtable slots: CHelpComboBoxButton[31], CMFCColorMenuButton[31], CMFCCustomizeButton[31], CMFCCustomizeMenuButton[31], CMFCDropDownToolbarButton[31], CMFCOutlookBarPaneButton[31], CMFCToolBarButton[31], CMFCToolBarComboBoxButton[31], CMFCToolBarEditBoxButton[31], CMFCToolBarFontComboBox[31], CMFCToolBarFontSizeComboBox[31], CMFCToolBarMenuButton[31], CMFCToolBarMenuButtonsButton[31], CMFCToolBarSystemMenuButton[31], COutlookCustomizeButton[31], CTasksPaneHistoryButton[31], CTasksPaneMenuButton[31], CTasksPaneNavigateButton[31] */
/* 00882715  FUN_00882715  169 bytes, 0 callers */

void FUN_00882715(int param_1)

{
  CObject *pCVar1;
  CObject *pCVar2;
  code *pcVar3;
  
  if (param_1 == 0) {
    pCVar1 = (CObject *)FUN_00404c80();
  }
  else {
    pCVar1 = DAT_00a13a1c;
    if (DAT_00a13a1c == (CObject *)0x0) {
      pCVar1 = (CObject *)FUN_00792b4c();
    }
  }
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMDIFrameWndEx_009945d0,pCVar1);
  if (pCVar2 == (CObject *)0x0) {
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWndEx_00994040,pCVar1);
    if (pCVar2 == (CObject *)0x0) {
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_COleIPFrameWndEx_00994be0,(CObject *)0x0);
      if (pCVar2 != (CObject *)0x0) {
        pcVar3 = *(code **)(*(int *)pCVar2 + 0x1fc);
        goto LAB_00882757;
      }
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWndEx_00994040,pCVar1);
      if (pCVar2 == (CObject *)0x0) {
        return;
      }
    }
    pcVar3 = *(code **)(*(int *)pCVar2 + 0x1e0);
  }
  else {
    pcVar3 = *(code **)(*(int *)pCVar2 + 500);
  }
LAB_00882757:
  guard_check_icall();
  (*pcVar3)();
  return;
}




/* vtable slots: CHelpComboBoxButton[3], CMFCColorMenuButton[3], CMFCCustomizeButton[3], CMFCCustomizeMenuButton[3], CMFCDropDownToolbarButton[3], CMFCOutlookBarPaneButton[3], CMFCShowAllButton[3], CMFCToolBarButton[3], CMFCToolBarColorButton[3], CMFCToolBarComboBoxButton[3], CMFCToolBarEditBoxButton[3], CMFCToolBarFontComboBox[3], CMFCToolBarFontSizeComboBox[3], CMFCToolBarMenuButton[3], CMFCToolBarMenuButtonsButton[3], CMFCToolBarSystemMenuButton[3], COutlookCustomizeButton[3], CTasksPaneHistoryButton[3], CTasksPaneMenuButton[3], CTasksPaneNavigateButton[3] */
/* 008827be  FUN_008827be  222 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_008827be(void)

{
  code *pcVar1;
  undefined2 uVar2;
  int iVar3;
  void *pvVar4;
  int *in_ECX;
  undefined1 local_9c [72];
  CSharedFile local_54 [76];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x8c;
  local_8 = 0x8827cd;
  pcVar1 = *(code **)(*in_ECX + 0x50);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    local_8 = 0;
    FUN_007ba754(2,0x1000);
    local_8._0_1_ = 1;
    FUN_007a6256(local_54,0,0x1000,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    pcVar1 = *(code **)*in_ECX;
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    FUN_007a60d2(iVar3);
    pcVar1 = *(code **)(*in_ECX + 8);
    guard_check_icall(local_9c);
    (*pcVar1)();
    FUN_007a664f();
    pvVar4 = CSharedFile::Detach(local_54);
    uVar2 = FUN_00881201();
    FUN_007b9e4b(uVar2,pvVar4,0);
    FUN_007a6389();
    FUN_007ba784();
  }
  FUN_008828b5();
  return;
}




/* vtable slots: CHelpComboBoxButton[36], CMFCDropDownToolbarButton[36], CMFCOutlookBarPaneButton[36], CMFCToolBarButton[36], CMFCToolBarColorButton[36], CMFCToolBarComboBoxButton[36], CMFCToolBarEditBoxButton[36], CMFCToolBarFontComboBox[36], CMFCToolBarFontSizeComboBox[36], CMFCToolBarMenuButtonsButton[36], CTasksPaneNavigateButton[36] */
/* 008828c3  FUN_008828c3  235 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined1 * FUN_008828c3(void)

{
  code *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  int *in_ECX;
  UINT in_stack_ffffffd8;
  LPSTR in_stack_ffffffdc;
  int in_stack_ffffffe0;
  CSimpleStringT<wchar_t,0> local_18 [4];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  puVar2 = &LAB_00944a27;
  local_8 = 0x8828cf;
  if ((in_ECX[1] == 0) && (0 < in_ECX[8])) {
    if ((DAT_00a13bac != 0) &&
       (puVar2 = (undefined1 *)FUN_008524f8(in_ECX[8]), puVar2 != (undefined1 *)0x0)) {
      return puVar2;
    }
    iVar3 = in_ECX[3];
    puVar2 = (undefined1 *)FUN_00881280(in_ECX[8]);
    if ((int)puVar2 < 0) {
      if (iVar3 != 0) {
        puVar2 = (undefined1 *)in_ECX[0xb];
        in_ECX[3] = 0;
        in_ECX[2] = 1;
        if (*(int *)(puVar2 + -0xc) == 0) {
          CStringT<>();
          local_8 = 0;
          iVar3 = FID_conflict_LoadStringA
                            ((HINSTANCE)in_ECX[8],in_stack_ffffffd8,in_stack_ffffffdc,
                             in_stack_ffffffe0);
          if ((iVar3 != 0) && (iVar3 = FUN_0044e690(10,0), iVar3 != -1)) {
            FUN_00450000(local_18,iVar3 + 1,*(int *)(local_14 + -0xc) - (iVar3 + 1));
            local_8 = CONCAT31(local_8._1_3_,1);
            ATL::CSimpleStringT<wchar_t,0>::operator=
                      ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0xb),local_18);
            FUN_00406b10();
          }
          puVar2 = (undefined1 *)FUN_00406b10();
        }
      }
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0xc0);
      guard_check_icall(puVar2);
      puVar2 = (undefined1 *)(*pcVar1)();
    }
  }
  return puVar2;
}




/* vtable slots: CHelpComboBoxButton[48], CMFCColorMenuButton[48], CMFCCustomizeButton[48], CMFCCustomizeMenuButton[48], CMFCDropDownToolbarButton[48], CMFCShowAllButton[48], CMFCToolBarButton[48], CMFCToolBarColorButton[48], CMFCToolBarComboBoxButton[48], CMFCToolBarEditBoxButton[48], CMFCToolBarFontComboBox[48], CMFCToolBarFontSizeComboBox[48], CMFCToolBarMenuButton[48], CMFCToolBarMenuButtonsButton[48], CMFCToolBarSystemMenuButton[48], COutlookCustomizeButton[48], CTasksPaneHistoryButton[48], CTasksPaneMenuButton[48], CTasksPaneNavigateButton[48] */
/* 00882d0f  FUN_00882d0f  181 bytes, 1 callers */

void FUN_00882d0f(int param_1)

{
  int iVar1;
  CCommandManager *this;
  undefined4 uVar2;
  int in_ECX;
  
  if ((*(byte *)(in_ECX + 0x24) & 1) == 0) {
    if (*(int *)(in_ECX + 4) == 0) {
      *(int *)(in_ECX + 0x34) = param_1;
    }
    else {
      *(int *)(in_ECX + 0x38) = param_1;
    }
    if ((*(int *)(in_ECX + 0x3c) == 0) && (*(int *)(in_ECX + 0x20) != 0)) {
      if (param_1 == -1) {
        FUN_0082be6d();
        uVar2 = FUN_0082be37(*(undefined4 *)(in_ECX + 0x20),0);
        *(undefined4 *)(in_ECX + 0x34) = uVar2;
        FUN_0082be6d();
        uVar2 = FUN_0082be37(*(undefined4 *)(in_ECX + 0x20),1);
        *(undefined4 *)(in_ECX + 0x38) = uVar2;
        if (*(int *)(in_ECX + 0x34) == -1) {
          *(uint *)(in_ECX + 4) = (uint)(*(int *)(in_ECX + 4) == 0);
        }
      }
      else if ((DAT_00a00aa0 != 0) || (*(int *)(in_ECX + 4) != 0)) {
        this = (CCommandManager *)FUN_0082be6d();
        CCommandManager::SetCmdImage(this,*(uint *)(in_ECX + 0x20),param_1,*(int *)(in_ECX + 4));
      }
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar1 = *(int *)(in_ECX + 0x34);
    }
    else {
      iVar1 = *(int *)(in_ECX + 0x38);
    }
    if (iVar1 < 0) {
      *(undefined4 *)(in_ECX + 0xc) = 0;
      *(undefined4 *)(in_ECX + 8) = 1;
    }
  }
  else {
    *(int *)(in_ECX + 0x34) = param_1;
  }
  return;
}




/* vtable slots: CHelpComboBoxButton[1] */
/* 0088729c  FUN_0088729c  51 bytes, 0 callers */

void FUN_0088729c(byte param_1)

{
  FUN_0088720b();
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




/* vtable slots: CHelpComboBoxButton[5] */
/* 00887a8e  CopyFrom  40 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CHelpComboBoxButton::CopyFrom(class CMFCToolBarButton const &)
   
   Library: Visual Studio 2012 Release */

void __thiscall CHelpComboBoxButton::CopyFrom(CHelpComboBoxButton *this,CMFCToolBarButton *param_1)

{
  FUN_00825aeb(param_1);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(this + 0xf4),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0xf4));
  return;
}




/* vtable slots: CHelpComboBoxButton[0] */
/* 00888296  FUN_00888296  6 bytes, 0 callers */

undefined ** FUN_00888296(void)

{
  return &PTR_s_CHelpComboBoxButton_00a00ae4;
}




/* vtable slots: CHelpComboBoxButton[2] */
/* 00889661  FUN_00889661  49 bytes, 0 callers */

void FUN_00889661(CArchive *param_1)

{
  int in_ECX;
  
  FUN_00827af5(param_1);
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0xf4));
  }
  else {
    FUN_0047fc90((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                 (in_ECX + 0xf4));
  }
  return;
}



