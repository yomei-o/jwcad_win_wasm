/* CMFCShellListCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCShellListCtrl[1] */
/* 007e0930  FUN_007e0930  57 bytes, 0 callers */

void FUN_007e0930(byte param_1)

{
  CMFCListCtrl *in_ECX;
  
  *(undefined ***)in_ECX = CMFCShellListCtrl::vftable;
  CMFCListCtrl::~CMFCListCtrl(in_ECX);
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




/* vtable slots: CMFCShellListCtrl[98] */
/* 007e0969  FUN_007e0969  342 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_007e0969(int param_1)

{
  code *pcVar1;
  uint uVar2;
  CMFCShellTreeCtrl *pCVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  CMFCShellListCtrl *in_ECX;
  int iVar6;
  
  iVar6 = -0x7fffbffb;
  if (DAT_00a139e8 != 0) {
    if (param_1 != 0) {
      FUN_007e1e95();
      iVar6 = FUN_007e1264(param_1);
      if (iVar6 < 0) {
        return iVar6;
      }
    }
    SendMessageW(*(HWND *)(in_ECX + 0x20),0x1009,0,0);
    if (*(int *)(in_ECX + 0x154) != 0) {
      FUN_0079dd6d();
      FUN_0078ff40();
      SendMessageW(*(HWND *)(in_ECX + 0x20),0xb,0,0);
      pcVar1 = *(code **)(*(int *)in_ECX + 0x1a8);
      guard_check_icall(*(undefined4 *)(in_ECX + 0x154),*(undefined4 *)(in_ECX + 0x158));
      iVar6 = (*pcVar1)();
      uVar2 = FUN_00797b3d();
      if ((uVar2 & 1) != 0) {
        pcVar1 = *(code **)(*(int *)in_ECX + 0x16c);
        guard_check_icall(0,1,0);
        (*pcVar1)();
      }
      SendMessageW(*(HWND *)(in_ECX + 0x20),0xb,1,0);
      RedrawWindow(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
      FUN_00408b00();
    }
    if ((-1 < iVar6) && (param_1 != 0)) {
      pCVar3 = CMFCShellListCtrl::GetRelatedTree(in_ECX);
      if ((pCVar3 != (CMFCShellTreeCtrl *)0x0) && (*(int *)(in_ECX + 0x16c) == 0)) {
        FUN_007e2d5d(*(undefined4 *)(in_ECX + 0x158),1);
      }
      pHVar4 = GetParent(*(HWND *)(in_ECX + 0x20));
      pCVar5 = CWnd::FromHandle(pHVar4);
      if (pCVar5 != (CWnd *)0x0) {
        pHVar4 = GetParent(*(HWND *)(in_ECX + 0x20));
        pCVar5 = CWnd::FromHandle(pHVar4);
        SendMessageW(*(HWND *)(pCVar5 + 0x20),DAT_00a124f4,0,0);
      }
    }
  }
  return iVar6;
}




/* vtable slots: CMFCShellListCtrl[99] */
/* 007e0abf  FUN_007e0abf  162 bytes, 0 callers */

int FUN_007e0abf(int param_1)

{
  code *pcVar1;
  _func_12949 *p_Var2;
  int iVar3;
  int *in_ECX;
  IShellFolder *local_14;
  undefined4 local_10;
  undefined4 local_c;
  IShellFolder *local_8;
  
  if (DAT_00a139e8 == 0) {
    iVar3 = -0x7fffbffb;
  }
  else {
    if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    local_14 = (IShellFolder *)0x0;
    local_10 = 0;
    local_c = 0;
    iVar3 = FUN_0082524e(param_1,&local_c);
    if (-1 < iVar3) {
      iVar3 = SHGetDesktopFolder(&local_8);
      if (-1 < iVar3) {
        local_14 = local_8;
        local_10 = local_c;
        pcVar1 = *(code **)(*in_ECX + 0x188);
        guard_check_icall(&local_14);
        iVar3 = (*pcVar1)();
        p_Var2 = local_8->lpVtbl->Release;
        guard_check_icall();
        (*p_Var2)(local_8);
      }
      FUN_00825152(local_10);
    }
  }
  return iVar3;
}




/* vtable slots: CMFCShellListCtrl[100] */
/* 007e0b62  FUN_007e0b62  187 bytes, 0 callers */

HRESULT FUN_007e0b62(void)

{
  code *pcVar1;
  _func_12949 *p_Var2;
  int iVar3;
  HRESULT HVar4;
  int *in_ECX;
  IShellFolder *local_14;
  undefined4 local_10;
  undefined4 local_c;
  IShellFolder *local_8;
  
  if (in_ECX[0x56] != 0) {
    local_14 = (IShellFolder *)0x0;
    local_10 = 0;
    local_c = 0;
    iVar3 = FUN_008251d3(in_ECX[0x56],&local_10);
    if (-1 < iVar3) {
      if (iVar3 == 0) {
        pcVar1 = *(code **)(*in_ECX + 0x188);
        guard_check_icall(&local_14);
        HVar4 = (*pcVar1)();
      }
      else {
        HVar4 = SHGetDesktopFolder(&local_8);
        if (-1 < HVar4) {
          local_14 = local_8;
          local_c = local_10;
          pcVar1 = *(code **)(*in_ECX + 0x188);
          guard_check_icall(&local_14);
          HVar4 = (*pcVar1)();
          p_Var2 = local_8->lpVtbl->Release;
          guard_check_icall();
          (*p_Var2)(local_8);
        }
      }
      FUN_00825152(local_10);
      return HVar4;
    }
  }
  return -0x7fffbffb;
}




/* vtable slots: CMFCShellListCtrl[107] */
/* 007e0c1d  FUN_007e0c1d  523 bytes, 0 callers */

void FUN_007e0c1d(undefined4 param_1)

{
  int *piVar1;
  code *pcVar2;
  LRESULT LVar3;
  int iVar4;
  HMENU pHVar5;
  HWND pHVar6;
  CWnd *pCVar7;
  int *in_ECX;
  int **ppiVar8;
  undefined4 local_74;
  undefined4 local_70;
  int *local_54;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  HMENU local_10;
  uint local_c;
  int *local_8;
  
  _memset(&local_74,0,0x3c);
  local_70 = param_1;
  local_74 = 4;
  LVar3 = SendMessageW((HWND)in_ECX[8],0x104b,0,(LPARAM)&local_74);
  if ((((LVar3 != 0) && (local_8 = local_54, local_54 != (int *)0x0)) &&
      (piVar1 = (int *)*local_54, piVar1 != (int *)0x0)) &&
     (local_10 = (HMENU)(local_54 + 2), local_10->unused != 0)) {
    pcVar2 = *(code **)(*piVar1 + 4);
    guard_check_icall(piVar1);
    (*pcVar2)();
    if (piVar1 != (int *)0x0) {
      local_c = 0x20000000;
      iVar4 = *piVar1;
      guard_check_icall(piVar1,1,local_10,&local_c);
      (**(code **)(iVar4 + 0x24))();
      if ((local_c & 0x20000000) == 0) {
        pcVar2 = *(code **)(*piVar1 + 0x28);
        ppiVar8 = &local_8;
        guard_check_icall(piVar1,in_ECX[8],1,local_10,&DAT_009a9abc,0,ppiVar8);
        iVar4 = (*pcVar2)();
        if (-1 < iVar4) {
          local_10 = CreatePopupMenu();
          if (local_10 != (HMENU)0x0) {
            pcVar2 = *(code **)(*local_8 + 0xc);
            guard_check_icall(local_8,local_10,0,1,0x7fff,5,ppiVar8);
            iVar4 = (*pcVar2)();
            if (((-1 < iVar4) &&
                (pHVar5 = (HMENU)GetMenuDefaultItem(local_10,0,0), local_10 = pHVar5,
                pHVar5 != (HMENU)0x0)) && (pHVar5 != (HMENU)0xffffffff)) {
              local_34 = 0;
              local_38 = 0x24;
              pHVar6 = GetParent((HWND)in_ECX[8]);
              pCVar7 = CWnd::FromHandle(pHVar6);
              if (pCVar7 == (CWnd *)0x0) {
                local_30 = 0;
              }
              else {
                local_30 = *(undefined4 *)(pCVar7 + 0x20);
              }
              local_2c = (undefined1 *)((int)&pHVar5[-1].unused + 3);
              local_28 = 0;
              local_24 = 0;
              local_1c = 0;
              local_18 = 0;
              local_20 = 1;
              pcVar2 = *(code **)(*local_8 + 0x10);
              guard_check_icall(local_8,&local_38);
              iVar4 = (*pcVar2)();
              if (-1 < iVar4) {
                pHVar6 = GetParent((HWND)in_ECX[8]);
                pCVar7 = CWnd::FromHandle(pHVar6);
                if (pCVar7 != (CWnd *)0x0) {
                  pHVar6 = GetParent((HWND)in_ECX[8]);
                  pCVar7 = CWnd::FromHandle(pHVar6);
                  SendMessageW(*(HWND *)(pCVar7 + 0x20),DAT_00a139ec,(WPARAM)local_10,0);
                }
              }
            }
          }
          pcVar2 = *(code **)(*local_8 + 8);
          guard_check_icall(local_8);
          (*pcVar2)();
        }
      }
      else {
        pcVar2 = *(code **)(*in_ECX + 0x188);
        guard_check_icall(local_8);
        (*pcVar2)();
      }
      pcVar2 = *(code **)(*piVar1 + 8);
      guard_check_icall(piVar1);
      (*pcVar2)();
    }
  }
  return;
}




/* vtable slots: CMFCShellListCtrl[106] */
/* 007e0e28  FUN_007e0e28  544 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_007e0e28(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  LRESULT LVar3;
  int iVar4;
  CListCtrl *in_ECX;
  code *pcVar5;
  uint local_70 [3];
  uint local_64;
  uint local_60;
  undefined2 *local_5c;
  undefined4 local_54;
  undefined4 *local_50;
  int local_34;
  LRESULT local_30;
  undefined1 local_2c [4];
  LRESULT local_28;
  undefined4 *local_24;
  uint local_20;
  int *local_1c;
  undefined4 local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0x7e0e34;
  local_1c = (int *)0x0;
  pcVar5 = *(code **)(*param_1 + 0x10);
  guard_check_icall(param_1,0,*(undefined4 *)(in_ECX + 0x15c),&local_1c);
  local_34 = (*pcVar5)();
  if ((-1 < local_34) && (local_1c != (int *)0x0)) {
    local_14[0] = 1;
    pcVar5 = *(code **)(*local_1c + 0xc);
    while( true ) {
      guard_check_icall(local_1c,1,&local_18,local_14);
      iVar4 = (*pcVar5)();
      if ((iVar4 != 0) || (local_14[0] == 0)) break;
      _memset(local_70,0,0x3c);
      local_70[0] = 0xf;
      pcVar5 = *(code **)(*param_1 + 4);
      guard_check_icall(param_1);
      (*pcVar5)();
      puVar1 = GlobalAlloc(0x40,0xc);
      puVar1[2] = local_18;
      local_24 = puVar1;
      uVar2 = FUN_0082505a(param_2,local_18);
      puVar1[1] = uVar2;
      *puVar1 = param_1;
      pcVar5 = *(code **)(*(int *)in_ECX + 0x19c);
      local_5c = &DAT_00956338;
      local_50 = puVar1;
      LVar3 = SendMessageW(*(HWND *)(in_ECX + 0x20),0x1004,0,0);
      guard_check_icall(LVar3,local_24);
      local_54 = (*pcVar5)();
      local_20 = 0xfc000;
      pcVar5 = *(code **)(*param_1 + 0x24);
      guard_check_icall(param_1,1,&local_18,&local_20);
      (*pcVar5)();
      if ((local_20 & 0x20000) != 0) {
        local_70[0] = local_70[0] | 8;
        local_60 = local_60 | 0xf00;
        local_64 = local_64 | 0x100;
      }
      if ((local_20 & 0x8000) != 0) {
        local_70[0] = local_70[0] | 8;
        local_60 = local_60 | 4;
        local_64 = local_64 | 4;
      }
      local_28 = SendMessageW(*(HWND *)(in_ECX + 0x20),0x104d,0,(LPARAM)local_70);
      if (-1 < local_28) {
        local_30 = SendMessageW(*(HWND *)(in_ECX + 0xa0),0x1200,0,0);
        iVar4 = 0;
        if (0 < local_30) {
          do {
            pcVar5 = *(code **)(*(int *)in_ECX + 0x198);
            guard_check_icall(local_2c,local_28,iVar4,local_24);
            puVar1 = (undefined4 *)(*pcVar5)();
            local_8 = 0;
            CListCtrl::SetItemText(in_ECX,local_28,iVar4,(wchar_t *)*puVar1);
            local_8 = 0xffffffff;
            FUN_00406b10();
            iVar4 = iVar4 + 1;
          } while (iVar4 < local_30);
        }
      }
      local_14[0] = 0;
      pcVar5 = *(code **)(*local_1c + 0xc);
    }
    pcVar5 = *(code **)(*local_1c + 8);
    guard_check_icall(local_1c);
    (*pcVar5)();
  }
  return local_34;
}




/* vtable slots: CMFCShellListCtrl[10] */
/* 007e10f2  FUN_007e10f2  6 bytes, 0 callers */

undefined ** FUN_007e10f2(void)

{
  return &PTR_FUN_00989978;
}




/* vtable slots: CMFCShellListCtrl[0] */
/* 007e1117  FUN_007e1117  6 bytes, 0 callers */

undefined ** FUN_007e1117(void)

{
  return &PTR_s_CMFCShellListCtrl_009896d0;
}




/* vtable slots: CMFCShellListCtrl[92] */
/* 007e12ef  FUN_007e12ef  577 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007e12ef(undefined4 *param_1,int param_2,int param_3)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  DWORD_PTR DVar4;
  bool bVar5;
  bool bVar6;
  SHFILEINFOW local_de0;
  SHFILEINFOW local_b2c;
  undefined4 local_878;
  undefined4 local_874;
  uint local_870;
  int local_86c;
  undefined4 local_868;
  undefined4 local_864;
  uint local_860;
  uint local_85c;
  byte local_858;
  undefined4 local_648;
  undefined4 local_644;
  uint local_640;
  int local_63c;
  undefined4 local_638;
  undefined4 local_634;
  uint local_630;
  uint local_62c;
  byte local_628;
  WCHAR local_418 [260];
  WCHAR local_210 [260];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((param_1 == (undefined4 *)0x0) || (param_2 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  local_648 = 0;
  local_644 = 0;
  local_640 = 0;
  local_63c = 0;
  local_638 = 0;
  local_634 = 0;
  local_878 = 0;
  local_874 = 0;
  local_870 = 0;
  local_86c = 0;
  local_868 = 0;
  local_864 = 0;
  if (param_3 == 0) {
    pcVar1 = *(code **)(*(int *)*param_1 + 0x1c);
    guard_check_icall((int *)*param_1,0,param_1[2],*(undefined4 *)(param_2 + 8));
    iVar3 = (*pcVar1)();
    if (iVar3 < 0) {
      return 0;
    }
    return (int)(short)iVar3;
  }
  if (param_3 != 1) {
    if (param_3 == 2) {
      DVar4 = SHGetFileInfoW((LPCWSTR)param_1[1],0,&local_de0,0x2b4,0x408);
      if (DVar4 == 0) {
        return 0;
      }
      DVar4 = SHGetFileInfoW(*(LPCWSTR *)(param_2 + 4),0,&local_b2c,0x2b4,0x408);
      if (DVar4 != 0) {
        iVar3 = lstrcmpiW(local_de0.szTypeName,local_b2c.szTypeName);
        return iVar3;
      }
      return 0;
    }
    if (param_3 != 3) {
      return 0;
    }
  }
  BVar2 = SHGetPathFromIDListW((LPCITEMIDLIST)param_1[1],local_210);
  if ((BVar2 == 0) || (iVar3 = FUN_007abbe2(local_210,&local_648,0), iVar3 == 0)) {
    return -1;
  }
  BVar2 = SHGetPathFromIDListW(*(LPCITEMIDLIST *)(param_2 + 4),local_418);
  if ((BVar2 == 0) || (iVar3 = FUN_007abbe2(local_418,&local_878,0), iVar3 == 0)) {
    return 1;
  }
  if (param_3 == 1) {
    if ((local_628 & 0x10) != 0) {
      return -1;
    }
    if ((local_858 & 0x10) != 0) {
      return 1;
    }
    if (local_85c < local_62c) {
      return 1;
    }
    if (local_62c < local_85c) {
      return -1;
    }
    if (local_630 < local_860) {
      return -1;
    }
    if (local_62c < local_85c) {
      return 0;
    }
    if (local_62c != local_85c) {
      return 1;
    }
    bVar5 = local_630 < local_860;
    bVar6 = local_630 == local_860;
  }
  else {
    if (local_86c < local_63c) {
      return 1;
    }
    if (local_63c < local_86c) {
      return -1;
    }
    if (local_640 < local_870) {
      return -1;
    }
    if (local_63c < local_86c) {
      return 0;
    }
    if (local_86c < local_63c) {
      return 1;
    }
    bVar5 = local_640 < local_870;
    bVar6 = local_640 == local_870;
  }
  if (!bVar5 && !bVar6) {
    return 1;
  }
  return 0;
}




/* vtable slots: CMFCShellListCtrl[105] */
/* 007e1a1c  FUN_007e1a1c  98 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007e1a1c(undefined4 *param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  CSimpleStringT<wchar_t,0> *pCVar1;
  undefined4 local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x7e1a28;
  local_18 = *param_1;
  local_14[0] = param_1[1];
  FUN_007e08ac(&local_18);
  pCVar1 = (CSimpleStringT<wchar_t,0> *)FUN_007c1251(local_14,0,0x400);
  local_8 = 0;
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_2,pCVar1);
  FUN_00406b10();
  return;
}




/* vtable slots: CMFCShellListCtrl[104] */
/* 007e1a7e  FUN_007e1a7e  90 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007e1a7e(undefined4 param_1,undefined4 param_2,CSimpleStringT<wchar_t,0> *param_3)

{
  int iVar1;
  WCHAR local_208 [256];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  StrFormatKBSizeW((LONGLONG)CONCAT44(param_2,param_1),local_208,0xff);
  iVar1 = FUN_008f899d(local_208);
  ATL::CSimpleStringT<wchar_t,0>::SetString(param_3,local_208,iVar1);
  return;
}




/* vtable slots: CMFCShellListCtrl[103] */
/* 007e1b02  FUN_007e1b02  90 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007e1b02(undefined4 param_1,int param_2)

{
  DWORD_PTR DVar1;
  int iVar2;
  SHFILEINFOW local_2bc;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_2 == 0) {
    iVar2 = -1;
  }
  else {
    DVar1 = SHGetFileInfoW(*(LPCWSTR *)(param_2 + 4),0,&local_2bc,0x2b4,0xc009);
    iVar2 = -1;
    if (DVar1 != 0) {
      iVar2 = local_2bc.iIcon;
    }
  }
  return iVar2;
}




/* vtable slots: CMFCShellListCtrl[102] */
/* 007e1b5c  FUN_007e1b5c  406 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007e1b5c(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  code *pcVar1;
  DWORD_PTR DVar2;
  BOOL BVar3;
  int iVar4;
  int *in_ECX;
  WCHAR *pWVar5;
  int *local_704;
  SHFILEINFOW local_700;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  byte local_42c;
  WCHAR local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x6f4;
  local_8 = 0x7e1b6b;
  local_704 = param_1;
  if (param_4 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if (param_3 == 0) {
    DVar2 = SHGetFileInfoW(*(LPCWSTR *)(param_4 + 4),0,&local_700,0x2b4,0x208);
    if (DVar2 == 0) goto LAB_007e1b9d;
    pWVar5 = local_700.szDisplayName;
  }
  else {
    if (param_3 == 1) {
LAB_007e1bdb:
      BVar3 = SHGetPathFromIDListW(*(LPCITEMIDLIST *)(param_4 + 4),local_21c);
      if (BVar3 != 0) {
        local_44c = 0;
        local_448 = 0;
        local_444 = 0;
        local_440 = 0;
        local_43c = 0;
        local_438 = 0;
        iVar4 = FUN_007abbe2(local_21c,&local_44c,0);
        if (iVar4 != 0) {
          CStringT<>();
          local_8 = 0;
          if (param_3 == 1) {
            if ((local_42c & 0x18) == 0) {
              pcVar1 = *(code **)(*in_ECX + 0x1a0);
              guard_check_icall(local_434,local_430,&local_704);
              (*pcVar1)();
            }
          }
          else {
            pcVar1 = *(code **)(*in_ECX + 0x1a4);
            guard_check_icall(&local_444,&local_704);
            (*pcVar1)();
          }
          iVar4 = FUN_004054a0(local_704 + -4);
          *param_1 = iVar4 + 0x10;
          FUN_00406b10();
          goto LAB_007e1ba9;
        }
      }
    }
    else if (param_3 == 2) {
      DVar2 = SHGetFileInfoW(*(LPCWSTR *)(param_4 + 4),0,&local_700,0x2b4,0x408);
      if (DVar2 != 0) {
        pWVar5 = local_700.szTypeName;
        goto LAB_007e1ba2;
      }
    }
    else if (param_3 == 3) goto LAB_007e1bdb;
LAB_007e1b9d:
    pWVar5 = L"";
  }
LAB_007e1ba2:
  CStringT<>(pWVar5);
LAB_007e1ba9:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCShellListCtrl[101] */
/* 007e1d9c  FUN_007e1d9c  191 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007e1d9c(void)

{
  code *pcVar1;
  int iVar2;
  LRESULT LVar3;
  int *in_ECX;
  int iVar4;
  UINT in_stack_ffffffc8;
  LPSTR in_stack_ffffffcc;
  int in_stack_ffffffd0;
  undefined4 local_28;
  undefined4 local_24 [7];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x7e1da8;
  pcVar1 = *(code **)(*in_ECX + 0x168);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  iVar4 = 0;
  LVar3 = SendMessageW(*(HWND *)(iVar2 + 0x20),0x1200,0,0);
  if (0 < LVar3) {
    do {
      SendMessageW((HWND)in_ECX[8],0x101c,0,0);
      LVar3 = LVar3 + -1;
    } while (LVar3 != 0);
  }
  local_24[0] = 0x42e8;
  local_24[1] = 0x42e9;
  local_24[2] = 0x42ea;
  local_24[3] = 0x42eb;
  do {
    CStringT<>();
    local_8 = 0;
    FID_conflict_LoadStringA
              ((HINSTANCE)local_24[iVar4],in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0);
    FUN_007a4672(iVar4,local_28,iVar4 == 1,(-(iVar4 != 1) & 0x41U) + 0x4b,iVar4);
    local_8 = 0xffffffff;
    FUN_00406b10();
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCShellListCtrl[20] */
/* 007e1e5b  PreSubclassWindow  29 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCShellListCtrl::PreSubclassWindow(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCShellListCtrl::PreSubclassWindow(CMFCShellListCtrl *this)

{
  _AFX_THREAD_STATE *p_Var1;
  
  CMFCListCtrl::PreSubclassWindow((CMFCListCtrl *)this);
  p_Var1 = AfxGetThreadState();
  if (*(int *)(p_Var1 + 0x14) == 0) {
    FUN_007e117f();
    return;
  }
  return;
}




/* vtable slots: CMFCShellListCtrl[97] */
/* 007e1e78  FUN_007e1e78  29 bytes, 0 callers */

void FUN_007e1e78(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x188);
  guard_check_icall(0);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCShellListCtrl[69] */
/* 007e1ed5  FUN_007e1ed5  70 bytes, 0 callers */

undefined4 FUN_007e1ed5(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_1 == 0x2b) || (param_1 == 0x2c)) || (param_1 == 0x117)) &&
     (DAT_00a124f0 != (int *)0x0)) {
    iVar1 = *DAT_00a124f0;
    guard_check_icall(DAT_00a124f0,param_1,param_2,param_3);
    (**(code **)(iVar1 + 0x18))();
    return 0;
  }
  uVar2 = FUN_007958aa();
  return uVar2;
}



