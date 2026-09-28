/* CMFCPopupMenuBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCPopupMenuBar[1] */
/* 008528da  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCPopupMenuBar::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCPopupMenuBar::_scalar_deleting_destructor_(CMFCPopupMenuBar *this,uint param_1)

{
  FUN_0085280c();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xdd0);
    }
  }
  return this;
}




/* vtable slots: CMFCPopupMenuBar[249] */
/* 00852989  FUN_00852989  658 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00852989(void)

{
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *in_ECX;
  uint uVar7;
  undefined1 local_7c [8];
  undefined1 local_74 [20];
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  tagPOINT local_4c;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int *local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x852995;
  if ((((in_ECX != (int *)0x0) && (in_ECX[8] != 0)) &&
      (BVar2 = IsWindow((HWND)in_ECX[8]), BVar2 != 0)) && (in_ECX[0x2f7] == 0)) {
    if (in_ECX[0x35e] == 0) {
      if (in_ECX[0x354] == 0) {
        FUN_00876b82(in_ECX + 0x354,in_ECX + 0x355);
      }
      local_24.left = 0;
      local_24.top = 0;
      local_24.right = 0;
      local_24.bottom = 0;
      GetClientRect((HWND)in_ECX[8],&local_24);
      FUN_0079dea2(in_ECX);
      local_8 = 0;
      iVar3 = FUN_007c2511();
      local_60 = FUN_0079efbc(iVar3 + 0x11c);
      if (local_60 == 0) {
LAB_00852c16:
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      pcVar1 = *(code **)(*in_ECX + 0x354);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      local_2c = local_24.left;
      iVar3 = (local_24.top - iVar3 * in_ECX[0x353]) + 1;
      local_3c = iVar3;
      if ((in_ECX[0x368] == 0) || (DAT_00a127ac != 0)) {
        iVar6 = local_24.right - local_24.left;
      }
      else {
        if (in_ECX[0x368] < 1) goto LAB_00852c16;
        iVar6 = *(int *)in_ECX[0x367];
      }
      local_40 = 0;
      local_28 = iVar6;
      FUN_007fe1cf(&local_38);
      local_38 = local_38 + 2;
      local_34 = local_34 + 2;
      iVar4 = FUN_007c2511();
      if (local_34 <= *(int *)(iVar4 + 0x1cc)) {
        iVar4 = FUN_007c2511();
        local_34 = *(int *)(iVar4 + 0x1cc);
      }
      local_44 = in_ECX[0x310];
      while (local_44 != 0) {
        local_30 = (int *)FUN_0044f2d0(&local_44);
        iVar4 = local_3c;
        local_30 = (int *)*local_30;
        if (local_30 == (int *)0x0) goto LAB_00852c16;
        uVar7 = local_30[9];
        if ((((uVar7 & 0x20000000) != 0) && (iVar3 != local_3c)) && (DAT_00a127ac == 0)) {
          local_2c = iVar6 + 1;
          local_40 = local_40 + 1;
          piVar5 = (int *)FUN_00799cf8(local_40);
          iVar6 = *piVar5;
          uVar7 = local_30[9];
          iVar3 = iVar4;
          local_28 = iVar6;
        }
        local_58 = iVar3;
        if ((uVar7 & 1) == 0) {
          pcVar1 = *(code **)(*local_30 + 0x1c);
          guard_check_icall(local_7c,local_74,&local_38,1);
          iVar6 = (*pcVar1)();
          local_5c = local_2c;
          local_54 = local_24.left + local_28;
          local_50 = iVar3 + *(int *)(iVar6 + 4);
        }
        else {
          local_5c = in_ECX[0x354] + local_2c;
          local_54 = (iVar6 - in_ECX[0x355]) + local_24.left;
          local_50 = iVar3 + 8;
        }
        FUN_0080554f(local_5c,local_58,local_54,local_50);
        iVar3 = local_50;
        iVar6 = local_28;
      }
      FUN_0079efbc(local_60);
      FUN_00803951();
      local_4c.x = 0;
      local_4c.y = 0;
      GetCursorPos(&local_4c);
      ScreenToClient((HWND)in_ECX[8],&local_4c);
      pcVar1 = *(code **)(*in_ECX + 0x390);
      guard_check_icall(local_4c.x,local_4c.y);
      iVar3 = (*pcVar1)();
      if (-1 < iVar3) {
        in_ECX[0x35d] = 0;
      }
      FUN_008065ff();
      FUN_0079dfff();
    }
    else {
      FUN_007fb67f();
      FUN_008065ff();
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCPopupMenuBar[169] */
/* 00852c1c  FUN_00852c1c  652 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_00852c1c(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  undefined1 local_58 [20];
  undefined1 local_44 [8];
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x48;
  local_8 = 0x852c28;
  if (*(int *)(in_ECX + 0xd78) == 0) {
    local_24 = 0;
    iVar7 = 0;
    FUN_0079dea2(in_ECX);
    local_8 = 0;
    iVar2 = FUN_007c2511();
    local_34 = FUN_0079efbc(iVar2 + 0x11c);
    if (local_34 == 0) {
LAB_00852ea3:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    if (*(int *)(in_ECX + 0xc48) == 0) {
      iVar2 = 0x32;
      iVar7 = 0x14;
      iVar5 = local_34;
    }
    else {
      local_18 = 0;
      local_20 = 0;
      FUN_007b011a(0,0xffffffff);
      FUN_007fe1cf(&local_3c);
      local_3c = local_3c + 2;
      local_38 = local_38 + 2;
      iVar2 = FUN_007c2511();
      if (local_38 <= *(int *)(iVar2 + 0x1cc)) {
        iVar2 = FUN_007c2511();
        local_38 = *(int *)(iVar2 + 0x1cc);
      }
      local_30 = *(int *)(in_ECX + 0xc40);
      if (local_30 != 0) {
        do {
          piVar3 = (int *)FUN_0044f2d0(&local_30);
          piVar3 = (int *)*piVar3;
          local_14 = piVar3;
          if (piVar3 == (int *)0x0) goto LAB_00852ea3;
          local_2c = 0;
          if ((*(int *)(in_ECX + 0xd48) != 0) && (piVar3[8] == *(int *)(in_ECX + 0xd48))) {
            iVar2 = FUN_007c2511();
            FUN_0079efbc(iVar2 + 300);
            local_2c = 1;
          }
          pcVar1 = *(code **)(*piVar3 + 0x1c);
          guard_check_icall(local_44,local_58,&local_3c,1);
          piVar3 = (int *)(*pcVar1)();
          local_1c = *piVar3;
          local_28 = piVar3[1];
          uVar6 = local_14[9];
          iVar2 = local_20;
          if (((uVar6 & 0x20000000) != 0) && (DAT_00a127ac == 0)) {
            if ((local_18 != 0) && (local_20 != 0)) {
              if (iVar7 < local_20) {
                iVar7 = local_20;
              }
              local_24 = local_24 + 1 + local_18;
              FUN_007b00e7(*(undefined4 *)(in_ECX + 0xda0),local_24);
              uVar6 = local_14[9];
            }
            local_18 = 0;
            iVar2 = 0;
          }
          if ((uVar6 & 1) == 0) {
            iVar5 = local_1c;
            if (((local_14[2] != 0) && (*(int *)(local_14[0xb] + -0xc) != 0)) &&
               (iVar4 = FUN_0044e690(9,0), iVar5 = local_1c, 0 < iVar4)) {
              iVar5 = local_1c + 10;
            }
            if ((*(int *)(in_ECX + 0xd58) < 1) || (iVar5 <= *(int *)(in_ECX + 0xd58) + -2)) {
              iVar4 = 1;
            }
            else {
              iVar4 = 0;
            }
            local_14[5] = iVar4;
            iVar4 = local_28;
            if (local_18 < iVar5) {
              local_18 = iVar5;
            }
          }
          else {
            iVar4 = 8;
          }
          iVar2 = iVar2 + iVar4;
          local_20 = iVar2;
          if (local_2c != 0) {
            iVar5 = FUN_007c2511();
            FUN_0079efbc(iVar5 + 0x11c);
          }
        } while (local_30 != 0);
        if (iVar7 < iVar2) {
          iVar7 = iVar2;
        }
      }
      iVar2 = local_24 + local_18;
      iVar5 = local_34;
    }
    local_34 = iVar7 + 2;
    iVar2 = iVar2 + 2;
    iVar7 = *(int *)(in_ECX + 0xd58);
    if ((0 < iVar7) && (iVar7 < iVar2)) {
      iVar2 = iVar7;
    }
    iVar7 = *(int *)(in_ECX + 0xd5c);
    if ((0 < iVar7) && (iVar2 < iVar7)) {
      iVar2 = iVar7;
    }
    FUN_007b00e7(*(undefined4 *)(in_ECX + 0xda0),iVar2);
    FUN_0079efbc(iVar5);
    *param_1 = iVar2;
    param_1[1] = local_34;
    FUN_0079dfff();
  }
  else {
    FUN_007fc420(param_1,0);
  }
  return param_1;
}




/* vtable slots: CMFCPopupMenuBar[10] */
/* 00853631  FUN_00853631  6 bytes, 0 callers */

undefined ** FUN_00853631(void)

{
  return &PTR_FUN_009960d0;
}




/* vtable slots: CMFCPopupMenuBar[0] */
/* 00853637  FUN_00853637  6 bytes, 0 callers */

undefined ** FUN_00853637(void)

{
  return &PTR_s_CMFCPopupMenuBar_00a00938;
}




/* vtable slots: CMFCPopupMenuBar[236], CMFCRibbonPanelMenuBar[236] */
/* 00853fee  FUN_00853fee  942 bytes, 1 callers */

void FUN_00853fee(uint param_1)

{
  code *pcVar1;
  LONG LVar2;
  HWND pHVar3;
  BOOL BVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  CObject *pCVar8;
  CWnd *pCVar9;
  int *piVar10;
  CObject *pCVar11;
  int *in_ECX;
  uint uVar12;
  uint uVar13;
  tagPOINT local_10;
  CObject *local_8;
  
  pHVar3 = (HWND)0x0;
  if (in_ECX != (int *)0x0) {
    pHVar3 = (HWND)in_ECX[8];
  }
  BVar4 = IsWindow(pHVar3);
  if (BVar4 != 0) {
    if (param_1 == 0xffffffff) {
      local_10.x = 0;
      local_10.y = 0;
      GetCursorPos(&local_10);
      ScreenToClient((HWND)in_ECX[8],&local_10);
      pcVar1 = *(code **)(*in_ECX + 0x390);
      iVar7 = in_ECX[0x2fe];
      guard_check_icall(local_10.x,local_10.y);
      iVar5 = (*pcVar1)();
      if (iVar5 == iVar7) {
        in_ECX[0x2fc] = iVar7;
        return;
      }
    }
    local_10.y = in_ECX[0x310];
    pCVar11 = (CObject *)0x0;
    if ((CObject *)local_10.y != (CObject *)0x0) {
      do {
        puVar6 = (undefined4 *)FUN_0044f2d0(&local_10.y);
        local_8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,
                                     (CObject *)*puVar6);
        if (local_8 != (CObject *)0x0) {
          pcVar1 = *(code **)(*(int *)local_8 + 0x70);
          guard_check_icall();
          iVar7 = (*pcVar1)();
          pCVar11 = local_8;
          if (iVar7 != 0) goto LAB_008540c6;
        }
      } while ((CObject *)local_10.y != (CObject *)0x0);
      pCVar11 = (CObject *)0x0;
    }
LAB_008540c6:
    local_8 = (CObject *)0x0;
    if (-1 < (int)param_1) {
      pCVar8 = (CObject *)FUN_007fde79(param_1);
      if (pCVar8 == (CObject *)0x0) goto LAB_00854397;
      local_8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar8);
    }
    if (local_8 == pCVar11) {
      if ((local_8 != (CObject *)0x0) && (local_8 == (CObject *)in_ECX[0x36c])) {
        *(int *)((CObject *)in_ECX[0x36c] + 0xa4) = 0;
        in_ECX[0x36c] = 0;
        KillTimer((HWND)in_ECX[8],0xec18);
      }
    }
    else {
      pHVar3 = GetParent((HWND)in_ECX[8]);
      pCVar9 = CWnd::FromHandle(pHVar3);
      local_10.y = (LONG)AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,
                                            (CObject *)pCVar9);
      if (pCVar11 != (CObject *)0x0) {
        iVar7 = FUN_0079272f();
        if ((DAT_00a127ac == 0) && ((iVar7 == 0 || (*(int *)(iVar7 + 4) != 0x100)))) {
          in_ECX[0x36c] = (int)pCVar11;
          *(int *)(pCVar11 + 0xa4) = 1;
          SetTimer((HWND)in_ECX[8],0xec18,DAT_00a00954 - 1,(TIMERPROC)0x0);
          InvalidateRect((HWND)in_ECX[8],(RECT *)(pCVar11 + 0x54),1);
          UpdateWindow((HWND)in_ECX[8]);
        }
        else {
          KillTimer((HWND)in_ECX[8],0xec18);
          in_ECX[0x36c] = 0;
          pcVar1 = *(code **)(*(int *)pCVar11 + 0x58);
          guard_check_icall();
          (*pcVar1)();
          LVar2 = local_10.y;
          if ((CObject *)local_10.y != (CObject *)0x0) {
            iVar7 = DAT_00a13a1c;
            if (DAT_00a13a1c == 0) {
              iVar7 = FUN_00792b4c();
            }
            FUN_0081bab4(iVar7,LVar2);
          }
        }
      }
      if ((local_8 != (CObject *)0x0) &&
         ((*(int *)(local_8 + 0x20) == -1 || (*(int *)(local_8 + 0x90) != 0)))) {
        pcVar1 = *(code **)(*(int *)local_8 + 0x20);
        guard_check_icall();
        (*pcVar1)();
      }
      if (((CObject *)local_10.y != (CObject *)0x0) && (iVar7 = FUN_0081d529(), iVar7 != 0)) {
        piVar10 = (int *)FUN_0081d529();
        pcVar1 = *(code **)(*piVar10 + 0x1c8);
        guard_check_icall();
        piVar10 = (int *)(*pcVar1)();
        if ((piVar10 != (int *)0x0) && (piVar10[0x36c] == *(int *)(local_10.y + 0x158))) {
          pcVar1 = *(code **)(*piVar10 + 0x444);
          guard_check_icall();
          (*pcVar1)();
        }
      }
    }
    in_ECX[0x2fe] = param_1;
    if (in_ECX[0x360] != 0) {
      pHVar3 = GetParent((HWND)in_ECX[8]);
      pCVar9 = CWnd::FromHandle(pHVar3);
      pCVar11 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar9)
      ;
      if (pCVar11 != (CObject *)0x0) {
        pcVar1 = *(code **)(*(int *)pCVar11 + 0x204);
        guard_check_icall(in_ECX[0x2fe]);
        (*pcVar1)();
      }
    }
    if (DAT_00a139d4 != 0) {
      iVar7 = DAT_00a13a1c;
      if ((DAT_00a13a1c == 0) && (iVar7 = FUN_00792b4c(), iVar7 == 0)) {
        iVar7 = FUN_00404c80();
      }
      pHVar3 = GetParent((HWND)in_ECX[8]);
      pCVar9 = CWnd::FromHandle(pHVar3);
      pCVar11 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar9)
      ;
      if (((pCVar11 != (CObject *)0x0) &&
          (iVar5 = *(int *)(pCVar11 + 0x134), *(int *)(pCVar11 + 0x134) != 0)) ||
         ((iVar7 != 0 && (iVar5 = iVar7, pCVar11 != (CObject *)0x0)))) {
        uVar12 = 0x80;
        uVar13 = 0;
        if (local_8 != (CObject *)0x0) {
          uVar12 = (*(uint *)(local_8 + 0x24) & 0x40000 | 0x1000000) >> 0x11;
          if ((*(uint *)(local_8 + 0x24) & 0x10000) != 0) {
            uVar12 = uVar12 | 8;
          }
          uVar13 = *(uint *)(local_8 + 0x20);
          if (*(uint *)(local_8 + 0x20) == 0xffffffff) {
            uVar12 = uVar12 | 0x10;
            uVar13 = param_1;
          }
        }
        SendMessageW(*(HWND *)(iVar5 + 0x20),0x11f,uVar12 << 0x10 | uVar13 & 0xffff,
                     *(LPARAM *)(pCVar11 + 0xf34));
      }
    }
    return;
  }
LAB_00854397:
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCPopupMenuBar[256] */
/* 008547cb  FUN_008547cb  1499 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008547cb(CObject *param_1)

{
  int iVar1;
  SHORT SVar2;
  int iVar3;
  int *piVar4;
  BOOL BVar5;
  CWnd *pCVar6;
  CWnd *in_ECX;
  code *pcVar7;
  __POSITION *p_Var8;
  __POSITION *p_Var9;
  CObject *pCVar10;
  CObject *pCVar11;
  int local_40;
  CObject *local_3c;
  CObject *local_38;
  int local_34;
  CObject *local_30;
  __POSITION *local_2c;
  RECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_40 = 0;
  if (*(int *)(in_ECX + 0xbf0) < 0) {
    p_Var8 = (__POSITION *)0x0;
LAB_00854807:
    local_3c = (CObject *)0x0;
  }
  else {
    p_Var8 = CObList::FindIndex((CObList *)(in_ECX + 0xc3c),*(int *)(in_ECX + 0xbf0));
    if (p_Var8 == (__POSITION *)0x0) goto LAB_00854807;
    local_3c = *(CObject **)(p_Var8 + 8);
  }
  local_2c = (__POSITION *)0x0;
  local_34 = *(int *)(in_ECX + 0xbf0);
  p_Var9 = p_Var8;
  if (param_1 != (CObject *)0x9) {
    if (param_1 == (CObject *)0xd) {
      local_40 = 1;
      pCVar11 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,local_3c);
      if (pCVar11 == (CObject *)0x0) {
        return 1;
      }
      pcVar7 = *(code **)(*(int *)pCVar11 + 0xf0);
      guard_check_icall();
      iVar3 = (*pcVar7)();
      if (iVar3 == 0) {
        pcVar7 = *(code **)(*(int *)pCVar11 + 0xcc);
        guard_check_icall(0);
        iVar3 = (*pcVar7)();
        if (iVar3 != 0) {
          return 1;
        }
      }
      pCVar6 = CWnd::GetOwner(in_ECX);
      SendMessageW(*(HWND *)(pCVar6 + 0x20),0x362,0xe001,0);
      pcVar7 = *(code **)(*(int *)in_ECX + 1000);
      goto LAB_00854d81;
    }
    if ((param_1 == (CObject *)0x21) || (param_1 == (CObject *)0x22)) {
      if (*(int *)(in_ECX + 0xd80) == 0) {
        return 0;
      }
      if (0 < *(int *)(in_ECX + 0xd84)) {
        local_30 = *(CObject **)(in_ECX + 0xbf0);
        iVar3 = 0;
        *(undefined4 *)(in_ECX + 0xd88) = 1;
        local_3c = (CObject *)((uint)(param_1 != (CObject *)0x21) * 2 + 0x26);
        do {
          pcVar7 = *(code **)(*(int *)in_ECX + 0x400);
          guard_check_icall(local_3c);
          (*pcVar7)();
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)(in_ECX + 0xd84));
        *(undefined4 *)(in_ECX + 0xd88) = 0;
        if (local_30 == *(CObject **)(in_ECX + 0xbf0)) {
          return 1;
        }
        pcVar7 = *(code **)(*(int *)in_ECX + 0x25c);
        guard_check_icall(*(CObject **)(in_ECX + 0xbf0));
        (*pcVar7)();
        return 1;
      }
      return 0;
    }
    if (param_1 == (CObject *)0x23) {
      p_Var9 = (__POSITION *)0x0;
      goto LAB_00854ba4;
    }
    if (param_1 == (CObject *)0x24) {
      p_Var9 = (__POSITION *)0x0;
LAB_00854ac0:
      if (((*(int *)(in_ECX + 0xd80) != 0) && (p_Var8 == *(__POSITION **)(in_ECX + 0xc44))) &&
         (param_1 != (CObject *)0x24)) {
        return 1;
      }
      if (*(int *)(in_ECX + 0xc48) == 0) {
        return 1;
      }
      if ((p_Var9 == (__POSITION *)0x0) ||
         (local_2c = p_Var9, FUN_0044f2d0(&local_2c), local_2c == (__POSITION *)0x0)) {
        local_2c = *(__POSITION **)(in_ECX + 0xc40);
        local_34 = 0;
      }
      else {
        local_34 = local_34 + 1;
      }
      if (local_2c == p_Var9) {
        return 1;
      }
      do {
        iVar3 = local_34;
        local_38 = (CObject *)local_2c;
        piVar4 = (int *)FUN_0044f2d0(&local_2c);
        local_30 = (CObject *)*piVar4;
        if (((((byte)local_30[0x24] & 1) == 0) &&
            (BVar5 = IsRectEmpty((RECT *)(local_30 + 0x54)), BVar5 == 0)) &&
           (*(int *)(local_30 + 0x20) != -2)) break;
        local_34 = iVar3 + 1;
        if (local_2c == (__POSITION *)0x0) {
          if (*(int *)(in_ECX + 0xd80) != 0) {
            return 1;
          }
          local_2c = *(__POSITION **)(in_ECX + 0xc40);
          local_34 = 0;
        }
      } while (local_2c != p_Var9);
      goto LAB_00854b89;
    }
    if (param_1 == (CObject *)0x26) goto LAB_00854ba4;
    if (param_1 == (CObject *)0x28) goto LAB_00854ac0;
    if (DAT_00a127ac != 0) {
      return 0;
    }
    SVar2 = GetAsyncKeyState(0x11);
    if (SVar2 < 0) {
      return 0;
    }
    iVar3 = FUN_0082b24e(param_1);
    if (iVar3 != 0) {
      param_1 = (CObject *)FUN_0082b498(param_1);
      local_30 = param_1;
      iVar3 = Lookup(&local_30,&local_38);
      pCVar11 = local_38;
      if (iVar3 != 0) {
        local_30 = *(CObject **)(in_ECX + 0xc40);
        iVar3 = 0;
        while (iVar1 = local_34, local_30 != (CObject *)0x0) {
          piVar4 = (int *)FUN_0044f2d0(&local_30);
          if (*piVar4 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_0078e714();
          }
          iVar1 = iVar3;
          if ((CObject *)*piVar4 == pCVar11) break;
          iVar3 = iVar3 + 1;
        }
        local_34 = iVar1;
        local_30 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,pCVar11
                                     );
        p_Var8 = local_2c;
        if (local_30 != (CObject *)0x0) {
          pcVar7 = *(code **)(*(int *)local_30 + 0xcc);
          guard_check_icall(0);
          iVar3 = (*pcVar7)();
          if (iVar3 == 0) {
            if ((*(uint *)(pCVar11 + 0x24) & 0x40000) != 0) {
              pCVar10 = (CObject *)0x0;
              goto LAB_00854a4f;
            }
            pcVar7 = *(code **)(*(int *)in_ECX + 1000);
            guard_check_icall(local_30);
            local_40 = (*pcVar7)();
            p_Var8 = local_2c;
            if (local_40 != 0) {
              return 1;
            }
          }
          else {
            p_Var8 = local_2c;
            if (*(int *)(local_30 + 0x8c) != 0) {
              SendMessageW(*(HWND *)(*(int *)(local_30 + 0x8c) + 0x20),0x100,0x24,0);
              p_Var8 = local_2c;
            }
          }
        }
        goto LAB_00854973;
      }
    }
    if (DAT_00a00b1c == 0) {
      return 0;
    }
    if (*(int *)(in_ECX + 0xd68) != 0) {
      return 0;
    }
    local_3c = (CObject *)0x0;
    iVar3 = CMap<unsigned_int,unsigned_int,int,int>::Lookup
                      ((CMap<unsigned_int,unsigned_int,int,int> *)(in_ECX + 0xdb4),(uint)param_1,
                       (int *)&local_3c);
    if (iVar3 == 0) {
      return 0;
    }
    pCVar11 = (CObject *)0x0;
    pCVar10 = local_3c;
LAB_00854a4f:
    FUN_00853c2d(pCVar10,pCVar11);
    return 1;
  }
  SVar2 = GetKeyState(0x10);
  if (-1 < (char)SVar2) {
    param_1 = (CObject *)0x28;
    goto LAB_00854ac0;
  }
  param_1 = (CObject *)0x26;
LAB_00854ba4:
  if (((*(int *)(in_ECX + 0xd80) != 0) && (p_Var8 == *(__POSITION **)(in_ECX + 0xc40))) &&
     (param_1 != (CObject *)0x23)) {
    return 1;
  }
  if (*(int *)(in_ECX + 0xc48) == 0) {
    return 1;
  }
  if ((p_Var9 == (__POSITION *)0x0) ||
     (local_2c = p_Var9, FUN_0049ad10(&local_2c), local_2c == (__POSITION *)0x0)) {
    local_2c = *(__POSITION **)(in_ECX + 0xc44);
    local_34 = *(int *)(in_ECX + 0xc48);
  }
  local_34 = local_34 + -1;
  if (local_2c == p_Var9) {
    return 1;
  }
  do {
    iVar3 = local_34;
    local_38 = (CObject *)local_2c;
    piVar4 = (int *)FUN_0049ad10(&local_2c);
    local_30 = (CObject *)*piVar4;
    if (((((byte)local_30[0x24] & 1) == 0) &&
        (BVar5 = IsRectEmpty((RECT *)(local_30 + 0x54)), BVar5 == 0)) &&
       (*(int *)(local_30 + 0x20) != -2)) break;
    if (local_2c == (__POSITION *)0x0) {
      if (*(int *)(in_ECX + 0xd80) != 0) {
        return 1;
      }
      iVar3 = *(int *)(in_ECX + 0xc48);
      local_2c = *(__POSITION **)(in_ECX + 0xc44);
    }
    local_34 = iVar3 + -1;
  } while (local_2c != p_Var9);
LAB_00854b89:
  local_40 = 1;
  if (local_38 == (CObject *)0x0) {
    return 1;
  }
  pCVar11 = *(CObject **)(local_38 + 8);
  p_Var8 = (__POSITION *)0x1;
  local_38 = pCVar11;
LAB_00854973:
  iVar3 = local_34;
  if (pCVar11 == local_3c) {
    return local_40;
  }
  if ((p_Var8 != (__POSITION *)0x0) && (*(int *)(in_ECX + 0xd88) == 0)) {
    pcVar7 = *(code **)(*(int *)in_ECX + 0x25c);
    guard_check_icall(local_34);
    (*pcVar7)();
  }
  if (DAT_00a127ac != 0) {
    *(int *)(in_ECX + 0xbf4) = iVar3;
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  *(int *)(in_ECX + 0xbf0) = iVar3;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
  local_28.left = *(LONG *)(local_38 + 0x54);
  local_28.top = *(LONG *)(local_38 + 0x58);
  local_28.right = *(LONG *)(local_38 + 0x5c);
  local_28.bottom = *(LONG *)(local_38 + 0x60);
  if ((local_18.top <= local_28.top) && (local_28.bottom <= local_18.bottom)) {
    if (local_3c != (CObject *)0x0) {
      InvalidateRect(*(HWND *)(in_ECX + 0x20),(RECT *)(local_3c + 0x54),1);
    }
    InvalidateRect(*(HWND *)(in_ECX + 0x20),&local_28,1);
    UpdateWindow(*(HWND *)(in_ECX + 0x20));
  }
  pCVar11 = *(CObject **)(local_38 + 0x20);
  if (pCVar11 == (CObject *)0xffffffff) {
    return local_40;
  }
  pcVar7 = *(code **)(*(int *)in_ECX + 0x418);
LAB_00854d81:
  guard_check_icall(pCVar11);
  (*pcVar7)();
  return local_40;
}




/* vtable slots: CMFCPopupMenuBar[250], CMFCRibbonPanelMenuBar[250] */
/* 008550f3  FUN_008550f3  319 bytes, 0 callers */

undefined4 FUN_008550f3(CObject *param_1)

{
  code *pcVar1;
  POINT pt;
  CObject *pCVar2;
  int iVar3;
  BOOL BVar4;
  tagPOINT local_10;
  int local_8;
  
  if (*(int *)(param_1 + 0x20) == -2) {
    return 1;
  }
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCCustomizeMenuButton_0099e5c8,param_1);
  if (pCVar2 == (CObject *)0x0) {
    if ((*(uint *)(param_1 + 0x24) & 0x40000) != 0) {
      return 0;
    }
  }
  else if ((*(uint *)(param_1 + 0x24) & 0x40000) != 0) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0xe8);
    guard_check_icall();
    (*pcVar1)();
    return 1;
  }
  if (*(int *)(param_1 + 0x20) == -1) {
    return 0;
  }
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,param_1);
  if (pCVar2 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0xf0);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      local_10.x = 0;
      local_10.y = 0;
      GetCursorPos(&local_10);
      ScreenToClient(*(HWND *)(local_8 + 0x20),&local_10);
      pt.y = local_10.y;
      pt.x = local_10.x;
      BVar4 = PtInRect((RECT *)(pCVar2 + 0xd8),pt);
      if (BVar4 != 0) {
        return 1;
      }
      if (*(int *)(pCVar2 + 0x8c) != 0) {
        PostMessageW(*(HWND *)(*(int *)(pCVar2 + 0x8c) + 0x20),0x10,0,0);
        return 0;
      }
    }
    if (*(int *)(pCVar2 + 0x8c) != 0) {
      return 0;
    }
    pcVar1 = *(code **)(*(int *)pCVar2 + 0xe8);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      return 1;
    }
    iVar3 = FUN_0079d98a(&PTR_s_CMFCShowAllButton_0099966c);
    if (iVar3 != 0) {
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x20);
      guard_check_icall(local_8,0);
      (*pcVar1)();
      return 1;
    }
  }
  FUN_00853c2d(*(undefined4 *)(param_1 + 0x20),param_1);
  return 1;
}




/* vtable slots: CMFCPopupMenuBar[262], CMFCRibbonPanelMenuBar[262] */
/* 008558c6  ShowCommandMessageString  48 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCPopupMenuBar::ShowCommandMessageString(unsigned int)
   
   Library: Visual Studio 2010 Release */

void __thiscall CMFCPopupMenuBar::ShowCommandMessageString(CMFCPopupMenuBar *this,uint param_1)

{
  CWnd *pCVar1;
  
  if (*(int *)(this + 0xd80) != 0) {
    pCVar1 = CWnd::GetOwner((CWnd *)this);
    SendMessageW(*(HWND *)(pCVar1 + 0x20),0x362,0xe001,0);
    return;
  }
  FUN_00805b1f();
  return;
}



