/* CMFCRibbonPanelMenuBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonPanelMenuBar[1] */
/* 008b68a2  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonPanelMenuBar::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonPanelMenuBar::_scalar_deleting_destructor_(CMFCRibbonPanelMenuBar *this,uint param_1)

{
  FUN_008b66d9();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xec0);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonPanelMenuBar[249] */
/* 008b69e7  FUN_008b69e7  338 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008b69e7(void)

{
  code *pcVar1;
  CFont *pCVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_3c [20];
  int local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x8b69f3;
  if (*(int *)(in_ECX + 0xbdc) == 0) {
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetClientRect(*(HWND *)(in_ECX + 0x20),&local_24);
    FUN_0079dea2(in_ECX);
    local_8 = 0;
    pCVar2 = CWnd::GetFont(*(CWnd **)(in_ECX + 0xea0));
    local_28 = FUN_0079efbc(pCVar2);
    if (local_28 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    iVar3 = *(int *)(in_ECX + 0xeb4);
    if (iVar3 == 0) {
      if (*(int *)(in_ECX + 0xea4) != 0) {
        *(undefined4 *)(*(int *)(in_ECX + 0xea4) + 0x94) = *(undefined4 *)(in_ECX + 0xd8c);
        *(undefined4 *)(*(int *)(in_ECX + 0xea4) + 0xb8) = *(undefined4 *)(in_ECX + 0xd4c);
        pcVar1 = *(code **)(**(int **)(in_ECX + 0xea4) + 0xec);
        guard_check_icall(local_3c,&local_24);
        (*pcVar1)();
        pcVar1 = *(code **)(**(int **)(in_ECX + 0xea4) + 0x100);
        guard_check_icall(local_3c);
        (*pcVar1)();
        iVar3 = FUN_008b7533();
        if ((iVar3 != 0) && (*(int *)(iVar3 + 0x848) == *(int *)(in_ECX + 0xea4))) {
          FUN_008b4af4(1);
        }
        *(undefined4 *)(*(int *)(in_ECX + 0xea4) + 0x94) = 0;
      }
    }
    else {
      *(LONG *)(iVar3 + 0x7c) = local_24.left;
      *(LONG *)(iVar3 + 0x80) = local_24.top;
      *(LONG *)(iVar3 + 0x84) = local_24.right;
      *(LONG *)(iVar3 + 0x88) = local_24.bottom;
      pcVar1 = *(code **)(**(int **)(in_ECX + 0xeb4) + 0xb0);
      guard_check_icall(local_3c);
      (*pcVar1)();
    }
    FUN_0079efbc(local_28);
    FUN_0079dfff();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonPanelMenuBar[169] */
/* 008b6b3a  FUN_008b6b3a  1167 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008b6b3a(int *param_1)

{
  CFont *pCVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  CObject *pCVar5;
  int *piVar6;
  CMFCRibbonBaseElement *pCVar7;
  int in_ECX;
  int iVar8;
  code *pcVar9;
  int iVar10;
  int *piVar11;
  undefined1 local_54 [20];
  int local_40;
  int *local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x8b6b46;
  local_38 = param_1;
  local_34 = 0;
  if (*(int *)(in_ECX + 0xeb4) != 0) {
    iVar10 = *(int *)(in_ECX + 0xe04);
    *param_1 = *(int *)(in_ECX + 0xe00);
    param_1[1] = iVar10;
    goto LAB_008b6b6c;
  }
  *(undefined4 *)(*(int *)(in_ECX + 0xea4) + 0x84) = *(undefined4 *)(in_ECX + 0xde0);
  FUN_0079dea2(*(undefined4 *)(in_ECX + 0xea0));
  local_8 = 0;
  pCVar1 = CWnd::GetFont(*(CWnd **)(in_ECX + 0xea0));
  local_2c = FUN_0079efbc(pCVar1);
  if (local_2c == 0) goto LAB_008b6fc4;
  if (*(int *)(in_ECX + 0xdd8) == 0) {
    local_40 = 0x7fff;
    if ((*(int *)(in_ECX + 0xdd4) != 0) && (*(int *)(*(int *)(in_ECX + 0xea4) + 0x4d0) == 0)) {
      FUN_0079dd6d();
      FUN_0078ff40();
      local_8._0_1_ = 1;
      pcVar9 = *(code **)(**(int **)(in_ECX + 0xea4) + 200);
      guard_check_icall(local_54,0x7fff);
      (*pcVar9)();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00408b00();
      param_1 = local_38;
    }
    piVar11 = *(int **)(in_ECX + 0xea4);
    local_28 = piVar11[0x134];
    if (local_28 == 0) {
      FUN_0079efbc(local_2c);
      *param_1 = 10;
      iVar10 = 10;
    }
    else {
      if ((piVar11[0x1c] == 0) || (piVar11[0x20] != 0)) {
LAB_008b6dde:
        piVar11 = *(int **)(in_ECX + 0xea4);
        if (*(int *)(in_ECX + 0xde0) == 0) {
          if (piVar11[0x20] == 0) {
            if (piVar11[0x134] < 1) goto LAB_008b6fc4;
            local_30 = *(int *)piVar11[0x133] + piVar11[0x2c] * 4;
            local_18 = *(int *)(*(int *)(in_ECX + 0xea0) + 700) + piVar11[0x2d] * -2;
          }
          else {
            piVar6 = (int *)FUN_005db5d0(2 < local_28);
            piVar11 = *(int **)(in_ECX + 0xea4);
            local_30 = *piVar6 + piVar11[0x2c] * 4;
            local_18 = 0x7fff;
          }
          pcVar9 = *(code **)(*piVar11 + 0xec);
          local_1c = local_30;
        }
        else {
          if (piVar11[0x134] < 1) {
LAB_008b6fc4:
                    /* WARNING: Subroutine does not return */
            FUN_0078e714();
          }
          local_18 = 0x7fff;
          pcVar9 = *(code **)(*piVar11 + 0xec);
          local_1c = *(int *)piVar11[0x133] + piVar11[0x2c] * 2;
        }
      }
      else {
        pcVar9 = *(code **)(*piVar11 + 0xe4);
        guard_check_icall();
        iVar10 = (*pcVar9)();
        if (iVar10 != 0) goto LAB_008b6dde;
        local_1c = 0x7fff;
        pcVar9 = *(code **)(**(int **)(in_ECX + 0xea4) + 0xec);
        local_18 = *(int *)(*(int *)(in_ECX + 0xea0) + 700) + (*(int **)(in_ECX + 0xea4))[0x2d] * -2
        ;
      }
      local_20 = 0;
      local_24 = 0;
      guard_check_icall(local_54,&local_24);
      (*pcVar9)();
      iVar10 = *(int *)(in_ECX + 0xea4);
      local_28 = *(int *)(iVar10 + 0xd8) - *(int *)(iVar10 + 0xd0);
      iVar2 = *(int *)(iVar10 + 0xd4);
      iVar10 = *(int *)(iVar10 + 0xcc);
      FUN_0079efbc(local_2c);
      if (((*(int *)(in_ECX + 0xdd4) != 0) && (iVar8 = FUN_0086b145(), 0 < iVar8)) &&
         (*(int *)(in_ECX + 0xde0) == 0)) {
        local_2c = 0x7fff;
        iVar8 = 0;
        local_30 = 0;
        local_28 = 0;
        iVar2 = FUN_0086b145();
        iVar10 = 0x7fff;
        if (0 < iVar2) {
          do {
            pCVar7 = CMFCRibbonPanel::GetElement(*(CMFCRibbonPanel **)(in_ECX + 0xea4),iVar8);
            local_24 = *(int *)(pCVar7 + 0x74);
            local_20 = *(int *)(pCVar7 + 0x78);
            local_1c = *(int *)(pCVar7 + 0x7c);
            local_18 = *(int *)(pCVar7 + 0x80);
            if (local_24 <= local_40) {
              local_40 = local_24;
            }
            if (local_20 <= local_2c) {
              local_2c = local_20;
            }
            if (local_34 <= local_1c) {
              local_34 = local_1c;
            }
            if (local_30 <= local_18) {
              local_30 = local_18;
            }
            iVar8 = local_28 + 1;
            local_28 = iVar8;
            iVar2 = FUN_0086b145();
            iVar10 = local_40;
          } while (iVar8 < iVar2);
        }
        iVar10 = (*(int *)(*(int *)(in_ECX + 0xea4) + 0xb0) * 2 - iVar10) + local_34;
        local_38[1] = (*(int *)(*(int *)(in_ECX + 0xea4) + 0xb4) * 2 - local_2c) + local_30;
        goto LAB_008b6cdb;
      }
      *local_38 = iVar2 - iVar10;
      iVar10 = local_28;
      param_1 = local_38;
    }
    param_1[1] = iVar10;
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 0xea4) + 0x78) = 1;
    *(undefined4 *)(*(int *)(in_ECX + 0xea4) + 0x7c) = *(undefined4 *)(in_ECX + 0xddc);
    local_24 = 0;
    local_20 = 0;
    pcVar9 = *(code **)(**(int **)(in_ECX + 0xea4) + 0xec);
    local_1c = *(int *)(in_ECX + 0xdf8);
    local_18 = *(int *)(in_ECX + 0xdfc);
    guard_check_icall(local_54,&local_24);
    (*pcVar9)();
    FUN_0079efbc(local_2c);
    iVar10 = *(int *)(in_ECX + 0xea4);
    local_28 = *(int *)(iVar10 + 0xd8);
    iVar8 = *(int *)(iVar10 + 0xd4) - *(int *)(iVar10 + 0xcc);
    local_30 = *(int *)(iVar10 + 0xd0);
    iVar10 = local_28 - local_30;
    local_34 = iVar8;
    iVar2 = FUN_004208d0(0,0);
    if (iVar2 != 0) {
      if (iVar8 < *(int *)(in_ECX + 0xdf8)) {
        local_34 = *(int *)(in_ECX + 0xdf8);
      }
      iVar2 = *(int *)(in_ECX + 0xdfc);
      if (iVar2 < 1) {
        iVar10 = local_28 - local_30;
      }
      else if (*(int *)(*(int *)(in_ECX + 0xea4) + 0x110) == 0) {
        if (iVar2 < iVar10) {
          pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
          pCVar4 = CWnd::FromHandle(pHVar3);
          pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,
                                      (CObject *)pCVar4);
          if (pCVar5 != (CObject *)0x0) {
            *(undefined4 *)(pCVar5 + 0xf7c) = 1;
          }
        }
        iVar10 = *(int *)(in_ECX + 0xdfc);
      }
      else if (iVar10 <= iVar2) {
        iVar10 = iVar2;
      }
    }
    local_38[1] = iVar10;
    iVar10 = local_34;
LAB_008b6cdb:
    *local_38 = iVar10;
  }
  FUN_0079dfff();
LAB_008b6b6c:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonPanelMenuBar[272] */
/* 008b6fca  FUN_008b6fca  65 bytes, 0 callers */

void FUN_008b6fca(void)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xeac) != 0) {
    KillTimer(*(HWND *)(in_ECX + 0x20),0xec1c);
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xeac) + 0x198);
    guard_check_icall();
    (*pcVar1)();
    *(undefined4 *)(in_ECX + 0xeac) = 0;
  }
  return;
}




/* vtable slots: CMFCRibbonPanelMenuBar[153] */
/* 008b70f8  FUN_008b70f8  739 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008b70f8(int *param_1)

{
  BOOL BVar1;
  HRGN pHVar2;
  CFont *pCVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  code *pcVar6;
  int *piVar7;
  undefined **local_98;
  undefined4 local_94;
  int *local_90;
  int *local_8c;
  int local_88;
  int *local_84;
  int *local_7c;
  int local_78;
  int local_70 [11];
  tagRECT local_44;
  RECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x90;
  local_8 = 0x8b7107;
  local_8c = param_1;
  local_88 = in_ECX;
  FUN_007e522a(param_1,in_ECX);
  local_8 = 0;
  piVar7 = local_70;
  if (local_78 == 0) {
    piVar7 = local_7c;
  }
  local_34.left = 0;
  local_34.top = 0;
  local_34.right = 0;
  local_34.bottom = 0;
  pcVar6 = *(code **)(*param_1 + 0x50);
  local_84 = piVar7;
  guard_check_icall(&local_34);
  (*pcVar6)();
  local_94 = 0;
  local_98 = CRgn::vftable;
  local_8 = CONCAT31(local_8._1_3_,1);
  BVar1 = IsRectEmpty(&local_34);
  if (BVar1 == 0) {
    pHVar2 = CreateRectRgnIndirect(&local_34);
    Attach(pHVar2);
    FUN_0079eeb5(&local_98);
  }
  pcVar6 = *(code **)(*piVar7 + 0x28);
  pCVar3 = CWnd::GetFont(*(CWnd **)(local_88 + 0xea0));
  guard_check_icall(pCVar3);
  iVar4 = (*pcVar6)();
  if (iVar4 != 0) {
    FUN_0079f0b8(1);
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetClientRect(*(HWND *)(local_88 + 0x20),&local_24);
    local_44.left = local_24.left;
    local_44.top = local_24.top;
    local_44.right = local_24.right;
    local_44.bottom = local_24.bottom;
    InflateRect(&local_44,3,3);
    if (*(int *)(local_88 + 0xeb4) == 0) {
      local_8c = *(int **)(*(int *)(local_88 + 0xea4) + 0x108);
      if (local_8c == (int *)0x0) {
        if (*(int *)(local_88 + 0xde0) == 0) {
          local_90 = (int *)FUN_007c2574();
          pcVar6 = *(code **)(*local_90 + 0x34);
          guard_check_icall(local_84,local_88,local_24.left,local_24.top,local_24.right,
                            local_24.bottom,local_24.left,local_24.top,local_24.right,
                            local_24.bottom,0);
          (*pcVar6)();
        }
        else {
          local_90 = (int *)FUN_007c2574();
          pcVar6 = *(code **)(*local_90 + 0x2a4);
          guard_check_icall(local_84,local_88,local_24.left,local_24.top,local_24.right,
                            local_24.bottom);
          (*pcVar6)();
        }
      }
      else {
        local_90 = (int *)local_8c[0x150];
        local_8c[0x150] = local_88;
        piVar5 = (int *)FUN_007c2574();
        piVar7 = local_8c;
        pcVar6 = *(code **)(*piVar5 + 0x214);
        guard_check_icall(local_84,local_8c,local_44.left,local_44.top,local_44.right,
                          local_44.bottom);
        (*pcVar6)();
        piVar7[0x150] = (int)local_90;
      }
      pcVar6 = *(code **)(**(int **)(local_88 + 0xea4) + 0xe8);
    }
    else {
      local_8c = (int *)FUN_007c2574();
      pcVar6 = *(code **)(*local_8c + 0x214);
      guard_check_icall(local_84,*(undefined4 *)(local_88 + 0xeb4),local_44.left,local_44.top,
                        local_44.right,local_44.bottom);
      (*pcVar6)();
      pcVar6 = *(code **)(**(int **)(local_88 + 0xeb4) + 0xb4);
    }
    guard_check_icall(local_84);
    (*pcVar6)();
    pcVar6 = *(code **)(*local_84 + 0x28);
    guard_check_icall(iVar4);
    (*pcVar6)();
    FUN_0079eeb5(0);
    local_98 = CRgn::vftable;
    FUN_00416100();
    FUN_007e54da();
    FUN_008d9b68();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCRibbonPanelMenuBar[10] */
/* 008b74ee  FUN_008b74ee  6 bytes, 0 callers */

undefined ** FUN_008b74ee(void)

{
  return &PTR_FUN_009a2288;
}




/* vtable slots: CMFCRibbonPanelMenuBar[0] */
/* 008b752d  FUN_008b752d  6 bytes, 0 callers */

undefined ** FUN_008b752d(void)

{
  return &PTR_s_CMFCRibbonPanelMenuBar_009a1a6c;
}




/* vtable slots: CMFCRibbonPanelMenuBar[275] */
/* 008b75fd  FUN_008b75fd  25 bytes, 0 callers */

undefined4 FUN_008b75fd(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)(in_ECX + 0xdd8) == 0) {
    iVar1 = FUN_0082f53f();
    if (iVar1 == 0) {
      uVar2 = 1;
    }
  }
  return uVar2;
}




/* vtable slots: CMFCRibbonPanelMenuBar[277] */
/* 008b763a  FUN_008b763a  827 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b763a(CObject *param_1)

{
  code *pcVar1;
  POINT pt;
  LONG LVar2;
  CObject *pCVar3;
  CObject *pCVar4;
  BOOL BVar5;
  int iVar6;
  HWND pHVar7;
  CWnd *pCVar8;
  int *in_ECX;
  tagPOINT local_24;
  CObject *local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX[0x3a9] == 0) {
    return;
  }
  if (*(int *)(in_ECX[0x3a9] + 0x78) == 0) {
    return;
  }
  pCVar3 = (CObject *)FUN_0086b14c();
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonButton_00998478,pCVar3);
  local_24.y = (LONG)pCVar3;
  pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonButton_00998478,param_1);
  if ((pCVar3 != (CObject *)0x0) && (param_1 == (CObject *)0x0)) {
    return;
  }
  local_1c = (CObject *)(uint)(pCVar3 != param_1);
  if ((pCVar4 == (CObject *)0x0) || (pCVar3 != pCVar4)) {
LAB_008b76ef:
    if (local_1c == (CObject *)0x0) {
      if ((pCVar4 != (CObject *)0x0) && (pCVar4 == (CObject *)in_ECX[0x3ab])) {
        *(undefined4 *)((CObject *)in_ECX[0x3ab] + 0x188) = 0;
        in_ECX[0x3ab] = 0;
        KillTimer((HWND)in_ECX[8],0xec1c);
      }
      goto LAB_008b791d;
    }
  }
  else {
    local_18.left = *(LONG *)(pCVar4 + 0x124);
    local_18.top = *(LONG *)(pCVar4 + 0x128);
    local_18.right = *(LONG *)(pCVar4 + 300);
    local_18.bottom = *(LONG *)(pCVar4 + 0x130);
    BVar5 = IsRectEmpty(&local_18);
    if (BVar5 != 0) goto LAB_008b76ef;
    pcVar1 = *(code **)(*(int *)pCVar4 + 600);
    guard_check_icall();
    iVar6 = (*pcVar1)();
    if (iVar6 != 0) goto LAB_008b76ef;
  }
  pHVar7 = GetParent((HWND)in_ECX[8]);
  pCVar8 = CWnd::FromHandle(pHVar7);
  local_1c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonPanelMenu_009a1ee8,
                                (CObject *)pCVar8);
  LVar2 = local_24.y;
  if ((CObject *)local_24.y != (CObject *)0x0) {
    iVar6 = FUN_0079272f();
    if ((DAT_00a127ac == 0) && ((iVar6 == 0 || (*(int *)(iVar6 + 4) != 0x100)))) {
      in_ECX[0x3ab] = LVar2;
      *(int *)(LVar2 + 0x188) = 1;
      SetTimer((HWND)in_ECX[8],0xec1c,DAT_00a00954 - 1,(TIMERPROC)0x0);
      pcVar1 = *(code **)(*(int *)LVar2 + 0x1b8);
      guard_check_icall();
      (*pcVar1)();
    }
    else {
      KillTimer((HWND)in_ECX[8],0xec1c);
      in_ECX[0x3ab] = 0;
      pcVar1 = *(code **)(*(int *)LVar2 + 0x198);
      guard_check_icall();
      (*pcVar1)();
      pCVar3 = local_1c;
      if (local_1c != (CObject *)0x0) {
        iVar6 = DAT_00a13a1c;
        if (DAT_00a13a1c == 0) {
          iVar6 = FUN_00792b4c();
        }
        FUN_0081bab4(iVar6,pCVar3);
      }
    }
  }
  if (pCVar4 != (CObject *)0x0) {
    pcVar1 = *(code **)(*(int *)pCVar4 + 0x138);
    guard_check_icall();
    iVar6 = (*pcVar1)();
    if (iVar6 != 0) {
      if (in_ECX[0x3ac] != 0) {
        KillTimer((HWND)in_ECX[8],0xec1b);
      }
      in_ECX[0x3ac] = (int)pCVar4;
      if (pCVar4 == (CObject *)in_ECX[0x3ab]) {
        local_18.left = *(LONG *)(pCVar4 + 0x124);
        local_18.top = *(LONG *)(pCVar4 + 0x128);
        local_18.right = *(LONG *)(pCVar4 + 300);
        local_18.bottom = *(LONG *)(pCVar4 + 0x130);
        BVar5 = IsRectEmpty(&local_18);
        if (BVar5 == 0) {
          local_24.x = 0;
          local_24.y = 0;
          GetCursorPos(&local_24);
          ScreenToClient((HWND)in_ECX[8],&local_24);
          pt.y = local_24.y;
          pt.x = local_24.x;
          BVar5 = PtInRect(&local_18,pt);
          if (BVar5 == 0) goto LAB_008b787a;
        }
        pcVar1 = *(code **)(*in_ECX + 0x444);
        guard_check_icall();
        (*pcVar1)();
        in_ECX[0x3ac] = 0;
      }
      else {
        SetTimer((HWND)in_ECX[8],0xec1b,DAT_00a00954,(TIMERPROC)0x0);
      }
    }
  }
LAB_008b787a:
  pCVar3 = local_1c;
  if (local_1c != (CObject *)0x0) {
    local_24.y = FUN_008b74f4();
    if (((CObject *)local_24.y != (CObject *)0x0) &&
       (*(int *)(local_24.y + 0xeac) == *(int *)(pCVar3 + 0x116c))) {
      pcVar1 = *(code **)(*(int *)local_24.y + 0x444);
      guard_check_icall();
      (*pcVar1)();
      pCVar3 = local_1c;
    }
    local_1c = *(CObject **)(pCVar3 + 0x116c);
    if (local_1c != (CObject *)0x0) {
      pcVar1 = *(code **)(*(int *)local_1c + 0x1fc);
      guard_check_icall();
      (*pcVar1)();
    }
  }
LAB_008b791d:
  if (param_1 == (CObject *)0x0) {
    pHVar7 = GetParent((HWND)in_ECX[8]);
    pCVar8 = CWnd::FromHandle(pHVar7);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonPanelMenu_009a1ee8,
                                (CObject *)pCVar8);
    if ((pCVar3 != (CObject *)0x0) && (*(int **)(pCVar3 + 0x116c) != (int *)0x0)) {
      pcVar1 = *(code **)(**(int **)(pCVar3 + 0x116c) + 0x1fc);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonPanelMenuBar[276] */
/* 008b7975  FUN_008b7975  283 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b7975(int param_1)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  CObject *pCVar5;
  int *piVar6;
  int in_ECX;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = *(LONG *)(param_1 + 0x74);
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  local_18.top = *(LONG *)(param_1 + 0x78);
  local_18.right = *(LONG *)(param_1 + 0x7c);
  local_18.bottom = *(LONG *)(param_1 + 0x80);
  RedrawWindow(*(HWND *)(in_ECX + 0x20),&local_18,(HRGN)0x0,0x105);
  if ((*(int *)(in_ECX + 0xea4) != 0) &&
     (piVar6 = *(int **)(*(int *)(in_ECX + 0xea4) + 0x110), piVar6 != (int *)0x0)) {
    pcVar1 = *(code **)(*piVar6 + 0x298);
    guard_check_icall(param_1);
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      return;
    }
  }
  iVar2 = FUN_00863dc7(1);
  if (*(int *)(in_ECX + 0xde8) != 0) {
    pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar4 = CWnd::FromHandle(pHVar3);
    pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonMiniToolBar_0099e700,
                                (CObject *)pCVar4);
    if (pCVar5 != (CObject *)0x0) {
      return;
    }
  }
  if (iVar2 != 0) {
    pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar4 = CWnd::FromHandle(pHVar3);
    pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonPanelMenu_009a1ee8,
                                (CObject *)pCVar4);
    if (pCVar5 != (CObject *)0x0) {
      pCVar5 = (CObject *)FUN_0081d529();
      pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonPanelMenu_009a1ee8,pCVar5);
      if (pCVar5 != (CObject *)0x0) {
        *(undefined4 *)(pCVar5 + 0x2038) = 1;
      }
    }
  }
  piVar6 = (int *)FUN_007e5618();
  pcVar1 = *(code **)(*piVar6 + 0x60);
  guard_check_icall();
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonPanelMenuBar[278] */
/* 008b7dea  FUN_008b7dea  61 bytes, 0 callers */

void FUN_008b7dea(undefined4 param_1)

{
  int in_ECX;
  code *pcVar1;
  
  if (*(int **)(in_ECX + 0xeb4) == (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xea4) + 0x10c);
  }
  else {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xeb4) + 0xd8);
  }
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonPanelMenuBar[256] */
/* 008b7e27  FUN_008b7e27  183 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008b7e27(int param_1)

{
  SHORT SVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  code *pcVar4;
  CMFCDisableMenuAnimation local_18 [4];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x8b7e33;
  if (((param_1 == 0x79) && (SVar1 = GetKeyState(0x10), SVar1 < 0)) || (param_1 == 0x5d)) {
    FUN_008b7a90(in_ECX,0xffffffff,0xffffffff);
  }
  else {
    iVar2 = FUN_008b3ef2(param_1);
    if (iVar2 == 0) {
      if (*(int *)(in_ECX + 0xea4) == 0) {
        if (*(int *)(in_ECX + 0xeb4) == 0) {
          return 0;
        }
        CMFCDisableMenuAnimation::CMFCDisableMenuAnimation(local_18);
        local_8 = 1;
        pcVar4 = *(code **)(**(int **)(in_ECX + 0xeb4) + 0xe8);
      }
      else {
        CMFCDisableMenuAnimation::CMFCDisableMenuAnimation(local_18);
        local_8 = 0;
        pcVar4 = *(code **)(**(int **)(in_ECX + 0xea4) + 0xdc);
      }
      guard_check_icall(param_1);
      uVar3 = (*pcVar4)();
      DAT_00a139d8 = local_14;
      return uVar3;
    }
  }
  return 1;
}




/* vtable slots: CMFCRibbonPanelMenuBar[149] */
/* 008b87af  FUN_008b87af  104 bytes, 0 callers */

void FUN_008b87af(uint param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  tagPOINT local_10;
  int *local_8;
  
  local_10.x = param_1 & 0xffff;
  local_10.y = param_1 >> 0x10;
  ScreenToClient(*(HWND *)(in_ECX + 0x20),&local_10);
  piVar2 = (int *)FUN_008b7550(local_10.x,local_10.y);
  if (piVar2 != (int *)0x0) {
    local_8 = piVar2;
    FUN_007ed2e1();
    pcVar1 = *(code **)(*piVar2 + 0xac);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCRibbonPanelMenuBar[145] */
/* 008b8ba6  FUN_008b8ba6  176 bytes, 0 callers */

void FUN_008b8ba6(CCmdTarget *param_1,int param_2)

{
  int iVar1;
  CWnd *in_ECX;
  code *pcVar2;
  CMFCRibbonCmdUI local_30 [44];
  
  CMFCRibbonCmdUI::CMFCRibbonCmdUI(local_30);
  if (*(int **)(in_ECX + 0xeb4) == (int *)0x0) {
    pcVar2 = *(code **)(**(int **)(in_ECX + 0xea4) + 0xf8);
  }
  else {
    pcVar2 = *(code **)(**(int **)(in_ECX + 0xeb4) + 200);
  }
  guard_check_icall(local_30,param_1,param_2);
  (*pcVar2)();
  CWnd::UpdateDialogControls(in_ECX,param_1,param_2);
  if (param_2 == 0) {
    return;
  }
  if (*(int *)(in_ECX + 0xdf0) == 0) {
    return;
  }
  if (*(int *)(in_ECX + 0xea4) == 0) {
    iVar1 = *(int *)(in_ECX + 0xeb4);
    if (iVar1 == 0) goto LAB_008b8c43;
  }
  else {
    iVar1 = FUN_0086b14c();
    if (iVar1 != 0) goto LAB_008b8c43;
    iVar1 = *(int *)(in_ECX + 0xea4);
  }
  FUN_008b425a(iVar1,0);
LAB_008b8c43:
  *(undefined4 *)(in_ECX + 0xdf0) = 0;
  FUN_0082174f(0);
  return;
}




/* vtable slots: CMFCRibbonPanelMenuBar[67] */
/* 008b8e9e  FUN_008b8e9e  191 bytes, 0 callers */

undefined4 FUN_008b8e9e(int param_1)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  undefined4 uVar5;
  int *in_ECX;
  tagPOINT local_14;
  CObject *local_c;
  int *local_8;
  
  if ((*(int *)(param_1 + 4) == 0x100) && (*(int *)(param_1 + 8) == 9)) {
    pcVar1 = *(code **)(*in_ECX + 0x400);
    local_8 = in_ECX;
    guard_check_icall(9);
    iVar2 = (*pcVar1)();
    in_ECX = local_8;
    if (iVar2 != 0) {
      return 1;
    }
  }
  if (*(int *)(param_1 + 4) == 0x201) {
    pHVar3 = GetFocus();
    pCVar4 = CWnd::FromHandle(pHVar3);
    local_c = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonRichEditCtrl_0099a04c,
                                 (CObject *)pCVar4);
    if (local_c != (CObject *)0x0) {
      local_14.x = 0;
      local_14.y = 0;
      GetCursorPos(&local_14);
      ScreenToClient((HWND)in_ECX[8],&local_14);
      pcVar1 = *(code **)(**(int **)(local_c + 0x80) + 0x280);
      guard_check_icall(local_14.x,local_14.y);
      (*pcVar1)();
    }
  }
  uVar5 = FUN_008036ce(param_1);
  return uVar5;
}




/* vtable slots: CMFCRibbonPanelMenuBar[273] */
/* 008b8f5d  FUN_008b8f5d  248 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b8f5d(void)

{
  code *pcVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int in_ECX;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(in_ECX + 0xeac) != 0) && (*(int *)(in_ECX + 0xea4) != 0)) {
    *(undefined4 *)(*(int *)(in_ECX + 0xeac) + 0x188) = 0;
    iVar4 = FUN_0086b6f8();
    pcVar1 = *(code **)(**(int **)(in_ECX + 0xea4) + 0x114);
    guard_check_icall(1,*(undefined4 *)(*(int *)(in_ECX + 0xeac) + 0x74),
                      *(undefined4 *)(*(int *)(in_ECX + 0xeac) + 0x78));
    (*pcVar1)();
    bVar3 = false;
    iVar2 = *(int *)(in_ECX + 0xeac);
    if (iVar2 != iVar4) {
      if (iVar2 != 0) {
        local_18.left = *(LONG *)(iVar2 + 0x74);
        local_18.top = *(LONG *)(iVar2 + 0x78);
        local_18.right = *(LONG *)(iVar2 + 0x7c);
        local_18.bottom = *(LONG *)(iVar2 + 0x80);
        InvalidateRect(*(HWND *)(in_ECX + 0x20),&local_18,1);
      }
      if (iVar4 != 0) {
        local_18.left = *(LONG *)(iVar4 + 0x74);
        local_18.top = *(LONG *)(iVar4 + 0x78);
        local_18.right = *(LONG *)(iVar4 + 0x7c);
        local_18.bottom = *(LONG *)(iVar4 + 0x80);
        InvalidateRect(*(HWND *)(in_ECX + 0x20),&local_18,1);
      }
      bVar3 = true;
    }
    *(undefined4 *)(in_ECX + 0xeac) = 0;
    KillTimer(*(HWND *)(in_ECX + 0x20),0xec1c);
    if (bVar3) {
      UpdateWindow(*(HWND *)(in_ECX + 0x20));
    }
  }
  return;
}



