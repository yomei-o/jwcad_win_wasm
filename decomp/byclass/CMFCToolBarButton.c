/* CMFCToolBarButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarButton[1], CTasksPaneNavigateButton[1] */
/* 00880ea4  FUN_00880ea4  48 bytes, 0 callers */

void FUN_00880ea4(byte param_1)

{
  CMFCToolBarButton *in_ECX;
  
  CMFCToolBarButton::~CMFCToolBarButton(in_ECX);
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




/* vtable slots: CMFCToolBarButton[0] */
/* 008812a5  FUN_008812a5  6 bytes, 0 callers */

undefined ** FUN_008812a5(void)

{
  return &PTR_s_CMFCToolBarButton_00a00a80;
}




/* vtable slots: CMFCToolBarButton[7], CMFCToolBarColorButton[7], CTasksPaneNavigateButton[7] */
/* 00881448  FUN_00881448  463 bytes, 4 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00881448(int *param_1,undefined4 param_2,int *param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  CMFCToolBarButton *in_ECX;
  int iVar5;
  int iVar6;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x881454;
  local_2c = param_2;
  if (*(int *)(in_ECX + 0x50) == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    goto LAB_0088160f;
  }
  iVar5 = *param_3;
  iVar6 = param_3[1];
  local_34 = iVar6;
  local_28 = iVar5;
  if (((byte)in_ECX[0x24] & 1) == 0) {
    local_30 = 1;
    iVar2 = CMFCToolBarButton::IsDrawImage(in_ECX);
    if (iVar2 == 0) {
LAB_008814cd:
      local_30 = 0;
      if (*(int *)(in_ECX + 0x48) == 0) {
        local_38 = 0;
        piVar3 = &local_38;
        local_34 = 0;
      }
      else {
        piVar3 = (int *)FUN_007c2574();
        pcVar1 = *(code **)(*piVar3 + 0x140);
        guard_check_icall(&local_1c);
        piVar3 = (int *)(*pcVar1)();
        iVar5 = local_28;
        iVar6 = local_34;
      }
      if (param_4 == 0) {
        iVar6 = piVar3[1];
      }
      else {
        iVar5 = *piVar3;
      }
    }
    else {
      if (*(int *)(in_ECX + 4) == 0) {
        iVar2 = *(int *)(in_ECX + 0x34);
      }
      else {
        iVar2 = *(int *)(in_ECX + 0x38);
      }
      if (iVar2 < 0) goto LAB_008814cd;
    }
    *(undefined4 *)(in_ECX + 100) = 0;
    iVar2 = *(int *)(in_ECX + 0x2c);
    *(undefined4 *)(in_ECX + 0x68) = 0;
    if (*(int *)(iVar2 + -0xc) != 0) {
      if ((*(int *)(in_ECX + 0x18) == 0) || (param_4 == 0)) {
        if (*(int *)(in_ECX + 8) != 0) {
          local_28 = FUN_004054a0(iVar2 + -0x10);
          local_28 = local_28 + 0x10;
          local_8 = 0;
          FUN_005946a0(&DAT_0098dde8,&DAT_0098dde0);
          FUN_007fa476(0x26);
          FUN_005946a0(&DAT_0098dde0,&DAT_0095bc0c);
          piVar3 = (int *)FUN_00566800(&local_38,&local_28);
          iVar2 = (-(uint)(local_30 != 0) & 0xfffffffd) + 9 + *piVar3;
          if (param_4 == 0) {
            iVar6 = iVar6 + iVar2;
          }
          else {
            iVar5 = iVar5 + iVar2;
          }
          FUN_00406b10();
        }
      }
      else {
        local_24 = 0;
        local_20 = 0;
        local_1c = *param_3 * 3;
        local_18 = param_3[1];
        uVar4 = 0x401;
        if (DAT_00a00a9c != 0) {
          uVar4 = 0x411;
        }
        FUN_007c2378(in_ECX + 0x2c,&local_24,uVar4);
        *(int *)(in_ECX + 100) = local_1c - local_24;
        *(int *)(in_ECX + 100) = *(int *)(in_ECX + 100) + 6;
        *(int *)(in_ECX + 0x68) = local_18 - local_20;
        if (iVar5 <= *(int *)(in_ECX + 100)) {
          iVar5 = *(int *)(in_ECX + 100);
        }
        iVar5 = iVar5 + 0xc;
        iVar6 = iVar6 + (local_18 - local_20) + 1;
      }
    }
  }
  else if (param_4 == 0) {
    iVar6 = 8;
  }
  else {
    iVar5 = *(int *)(in_ECX + 0x34);
    if (*(int *)(in_ECX + 0x34) < 1) {
      iVar5 = 8;
    }
  }
  *param_1 = iVar5;
  param_1[1] = iVar6;
LAB_0088160f:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCToolBarButton[10], CMFCToolBarMenuButtonsButton[10], CTasksPaneNavigateButton[10] */
/* 00881617  FUN_00881617  79 bytes, 8 callers */

void FUN_00881617(CObject *param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(CObject **)(in_ECX + 0x6c) = param_1;
  if ((param_1 != (CObject *)0x0) &&
     (pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,param_1),
     pCVar2 != (CObject *)0x0)) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x35c);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      *(undefined4 *)(in_ECX + 0x48) = 1;
    }
  }
  return;
}




/* vtable slots: CMFCToolBarButton[6], CTasksPaneNavigateButton[6] */
/* 00881666  FUN_00881666  3157 bytes, 5 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00881666(CDC *param_1,int *param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  CDC *pCVar1;
  int *piVar2;
  undefined ***pppuVar3;
  int iVar4;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar5;
  uint uVar6;
  CSimpleStringT<wchar_t,0> *pCVar7;
  COLORREF CVar8;
  CMFCToolBarButton *in_ECX;
  int iVar9;
  code *pcVar10;
  CMFCToolBarButton *pCVar11;
  undefined1 local_d8 [4];
  int local_d4;
  int *local_d0;
  undefined **local_cc;
  int local_c8;
  int local_c4;
  int local_c0;
  int local_bc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  undefined1 local_a8 [4];
  int *local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  CMFCToolBarButton *local_94;
  CDC *local_90;
  int local_8c;
  int local_88;
  int local_84;
  tagTEXTMETRICW local_80;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 200;
  local_8 = 0x881675;
  *(int *)(in_ECX + 0x4c) = param_4;
  local_90 = param_1;
  local_d0 = param_2;
  local_c0 = param_3;
  local_94 = in_ECX;
  FUN_0088114d(param_1,param_2,param_6,0);
  if (param_3 == 0) {
    local_9c = 0;
    local_b8 = 0;
  }
  else {
    local_9c = *(int *)(param_3 + 100);
    local_b8 = *(int *)(param_3 + 0x68);
  }
  local_88 = 0;
  if ((DAT_00a13bac != 0) && (*(int *)(in_ECX + 4) == 0)) {
    local_88 = FUN_008524f8(*(undefined4 *)(in_ECX + 0x20));
  }
  local_24.left = *local_d0;
  local_24.top = local_d0[1];
  local_24.right = local_d0[2];
  local_24.bottom = local_d0[3];
  if (*(int *)(local_94 + 0x48) == 0) {
    local_cc = (undefined **)0x0;
    pppuVar3 = &local_cc;
    local_c8 = 0;
  }
  else {
    piVar2 = (int *)FUN_007c2574();
    pcVar10 = *(code **)(*piVar2 + 0x140);
    guard_check_icall(local_a8);
    pppuVar3 = (undefined ***)(*pcVar10)();
  }
  pCVar11 = local_94;
  InflateRect(&local_24,-((int)*pppuVar3 / 2),-((int)pppuVar3[1] / 2));
  local_b0 = local_24.left;
  local_bc = local_24.top;
  local_8c = 0;
  local_b4 = FUN_004054a0(*(int *)(pCVar11 + 0x2c) + -0x10);
  local_b4 = local_b4 + 0x10;
  local_8 = 0;
  FUN_005946a0(&DAT_0098dde8,&DAT_0098dde0);
  FUN_007fa476(0x26);
  FUN_005946a0(&DAT_0098dde0,&DAT_0095bc0c);
  FUN_00566800(&local_cc,&local_b4);
  local_c4 = *(int *)(pCVar11 + 8);
  if ((local_c4 == 0) || (*(int *)(*(int *)(pCVar11 + 0x2c) + -0xc) == 0)) {
    local_d4 = *(int *)(pCVar11 + 0x18);
  }
  else {
    iVar9 = *(int *)(pCVar11 + 0x18);
    local_d4 = iVar9;
    if ((iVar9 == 0) || (param_4 == 0)) {
      iVar4 = CMFCToolBarButton::IsDrawImage(pCVar11);
      local_8c = (int)local_cc + (-(uint)(iVar4 != 0) & 0xfffffffd) + 3;
      local_c4 = *(int *)(pCVar11 + 8);
      local_d4 = iVar9;
    }
  }
  if (param_4 == 0) {
    iVar9 = local_24.right - local_24.left;
    local_8c = (local_24.bottom - local_24.top) - local_8c;
  }
  else if (local_d4 == 0) {
    iVar9 = (local_24.right - local_24.left) - local_8c;
    local_8c = local_24.bottom - local_24.top;
  }
  else {
    iVar9 = local_24.right - local_24.left;
    local_8c = local_b8 + 6;
  }
  local_98 = (iVar9 - local_9c) / 2;
  local_84 = (local_8c - local_b8) / 2;
  local_ac = 3;
  local_a0 = 3;
  if (((local_c4 != 0) && (*(int *)(*(int *)(pCVar11 + 0x2c) + -0xc) != 0)) &&
     ((local_d4 == 0 || (param_4 == 0)))) {
    GetTextMetricsW(*(HDC *)(local_90 + 8),&local_80);
    if (param_4 == 0) {
      local_84 = local_84 + -3;
      local_ac = ((iVar9 - local_80.tmHeight) + 1) / 2;
    }
    else {
      local_98 = local_98 + -3;
      local_a0 = ((local_8c - local_80.tmHeight) + -1) / 2;
    }
  }
  if ((param_6 == 0) || (param_5 != 0)) {
LAB_00881986:
    local_8c = 0;
    uVar6 = *(uint *)(pCVar11 + 0x24);
  }
  else {
    pcVar10 = *(code **)(*(int *)pCVar11 + 0x70);
    guard_check_icall();
    iVar9 = (*pcVar10)();
    if ((iVar9 != 0) || (iVar9 = FUN_007c2574(), *(int *)(iVar9 + 0x54) == 0)) goto LAB_00881986;
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar9 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if ((iVar9 != 0) || (uVar6 = *(uint *)(pCVar11 + 0x24), (uVar6 & 0x70000) != 0))
    goto LAB_00881986;
    local_8c = 1;
  }
  if ((((uVar6 & 0x30000) != 0) && (param_5 == 0)) &&
     (iVar9 = FUN_007c2574(), *(int *)(iVar9 + 0x54) == 0)) {
    piVar2 = (int *)FUN_007c2574();
    pcVar10 = *(code **)(*piVar2 + 0x2ec);
    guard_check_icall();
    iVar9 = (*pcVar10)();
    pCVar11 = local_94;
    if (iVar9 != 0) {
      local_98 = local_98 + 1;
      local_84 = local_84 + 1;
      local_a0 = local_a0 + 1;
      if (param_4 == 0) {
        local_ac = local_ac + -1;
      }
      else {
        local_ac = local_ac + 1;
      }
    }
  }
  iVar9 = local_84;
  if ((param_6 == 0) && (iVar4 = FUN_007c2574(), *(int *)(iVar4 + 0x5c) != 0)) {
    local_d4 = 1;
  }
  else {
    local_d4 = 0;
  }
  local_c4 = 0;
  if (((*(uint *)(pCVar11 + 0x24) & 0x60000) == 0x40000) && (param_5 == 0)) {
LAB_00881c07:
    if ((*(uint *)(pCVar11 + 0x24) & 0x40000) != 0) goto LAB_00881c14;
LAB_00881b86:
    local_a4 = (int *)0x0;
  }
  else {
    iVar4 = CMFCToolBarButton::IsDrawImage(pCVar11);
    pCVar1 = local_90;
    if ((iVar4 != 0) && (local_c0 != 0)) {
      if (local_88 == 0) {
        iVar4 = local_98;
        local_a4 = (int *)iVar9;
        if (local_8c != 0) {
          if (*(int *)(pCVar11 + 4) == 0) {
            uVar5 = *(undefined4 *)(pCVar11 + 0x34);
          }
          else {
            uVar5 = *(undefined4 *)(pCVar11 + 0x38);
          }
          FUN_007e8cae(local_90,local_b0 + local_98 + 1,local_bc + 1 + iVar9,uVar5,0,0,0,1,0,0xff);
          iVar9 = local_84 + -1;
          iVar4 = local_98 + -1;
        }
        if (*(int *)(pCVar11 + 4) == 0) {
          uVar5 = *(undefined4 *)(pCVar11 + 0x34);
        }
        else {
          uVar5 = *(undefined4 *)(pCVar11 + 0x38);
        }
        FUN_007e8cae(pCVar1,local_b0 + iVar4,local_bc + iVar9,uVar5,0,0,0,0,local_d4,0xff);
      }
      else {
        local_34.left = local_98 + local_b0;
        local_34.top = local_bc + iVar9;
        local_34.right = local_34.left + local_9c;
        local_34.bottom = local_b8 + local_34.top;
        FUN_00880677(local_90,&local_34);
      }
    }
    local_c4 = 1;
    if (param_5 == 0) goto LAB_00881c07;
    pcVar10 = *(code **)(*(int *)pCVar11 + 0x60);
    guard_check_icall();
    iVar9 = (*pcVar10)();
    if (iVar9 != 0) goto LAB_00881b86;
LAB_00881c14:
    local_a4 = (int *)0x1;
  }
  if (((local_c4 == 0) &&
      (iVar9 = CMFCToolBarButton::IsDrawImage(pCVar11), pCVar1 = local_90, iVar9 != 0)) &&
     (local_c0 != 0)) {
    if (local_88 == 0) {
      iVar9 = local_84;
      iVar4 = local_98;
      if (local_8c != 0) {
        local_88 = local_98 + 1;
        local_8c = local_84 + 1;
        if (*(int *)(pCVar11 + 4) == 0) {
          uVar5 = *(undefined4 *)(pCVar11 + 0x34);
        }
        else {
          uVar5 = *(undefined4 *)(pCVar11 + 0x38);
        }
        FUN_007e8cae(local_90,local_b0 + local_88,local_bc + local_8c,uVar5,0,0,0,1,0,0xff);
        iVar9 = local_8c + -2;
        iVar4 = local_88 + -2;
      }
      if ((local_a4 == (int *)0x0) || (param_8 == 0)) {
        local_a4 = (int *)0x0;
      }
      else {
        local_a4 = (int *)0x1;
      }
      if (*(int *)(pCVar11 + 4) == 0) {
        uVar5 = *(undefined4 *)(pCVar11 + 0x34);
      }
      else {
        uVar5 = *(undefined4 *)(pCVar11 + 0x38);
      }
      FUN_007e8cae(pCVar1,local_b0 + iVar4,iVar9 + local_bc,uVar5,0,local_a4,0,0,local_d4,0xff);
    }
    else {
      local_34.left = local_98 + local_b0;
      local_34.top = local_bc + local_84;
      local_34.right = local_34.left + local_9c;
      local_34.bottom = local_b8 + local_34.top;
      FUN_00880677(local_90,&local_34);
    }
  }
  if (((*(int *)(pCVar11 + 0x18) != 0) && (param_4 != 0)) ||
     ((*(int *)(pCVar11 + 8) != 0 && (*(int *)(*(int *)(pCVar11 + 0x2c) + -0xc) != 0)))) {
    local_88 = 0;
    if (param_6 == 0) {
      if ((*(uint *)(pCVar11 + 0x24) & 0x30000) != 0) {
        local_88 = 1;
      }
    }
    else {
      local_88 = 2;
    }
    piVar2 = (int *)FUN_007c2574();
    pcVar10 = *(code **)(*piVar2 + 0xb4);
    guard_check_icall(local_94,local_88);
    uVar5 = (*pcVar10)();
    pcVar10 = *(code **)(*(int *)local_90 + 0x30);
    guard_check_icall(uVar5);
    (*pcVar10)();
    local_84 = FUN_004054a0(*(int *)(local_94 + 0x2c) + -0x10);
    pCVar11 = local_94;
    local_84 = local_84 + 0x10;
    local_8._0_1_ = 1;
    local_44.left = local_24.left;
    local_44.top = local_24.top;
    local_44.right = local_24.right;
    local_44.bottom = local_24.bottom;
    if ((*(int *)(local_94 + 0x18) == 0) || (param_4 == 0)) {
      iVar4 = CMFCToolBarButton::IsDrawImage(local_94);
      iVar9 = local_a0;
      if (iVar4 == 0) {
        local_44.left = local_b0 + 4;
      }
      else {
        uVar6 = -(uint)(DAT_00a127b4 != 0) & 6;
        if (param_4 == 0) {
          iVar9 = local_a0 + uVar6 + local_b8;
          local_44.left = local_ac;
        }
        else {
          local_44.left = local_ac + uVar6 + local_9c;
        }
        local_44.left = local_b0 + 3 + local_44.left;
      }
      iVar4 = 0x20;
      local_88 = 0x20;
      if (param_4 != 0) goto LAB_00881e93;
      local_88 = local_24.top + iVar9;
      local_44.bottom = local_24.bottom;
      local_a4 = (int *)(local_c8 / 2);
      local_44.right = (local_24.right + local_24.left) / 2 - (int)local_a4;
      local_8c = local_44.right + local_c8;
      if (((local_24.bottom - local_88) - (int)local_cc) / 2 < 0) {
        local_44.top = 0;
      }
      else {
        local_44.top = ((local_24.bottom - local_88) - (int)local_cc) / 2;
      }
      local_44.top = local_44.top + local_88;
      local_44.left = local_8c;
      FUN_005946a0(&DAT_0098dde8,&DAT_0098dde0);
      iVar9 = FUN_0044e690(0x26,0);
      FUN_007fa476(0x26);
      FUN_005946a0(&DAT_0098dde0,&DAT_0098dde8);
      if (((iVar9 < 0) || (iVar4 = FUN_007c2511(), *(int *)(iVar4 + 0x1a0) == 0)) ||
         (DAT_00a127ac != 0)) {
        iVar4 = 0x120;
        piVar2 = &local_b4;
        goto LAB_008821c0;
      }
      local_34.left = 0;
      local_34.top = 0;
      local_34.right = 0;
      local_34.bottom = 0;
      SetRectEmpty(&local_34);
      Left(&local_9c,iVar9 + 1);
      pCVar1 = local_90;
      local_8._0_1_ = 2;
      FUN_007c2378(&local_9c,&local_34,0x520);
      local_8c = local_34.right;
      SetRectEmpty(&local_34);
      pCVar7 = (CSimpleStringT<wchar_t,0> *)Left(&local_88,iVar9);
      local_8._0_1_ = 3;
      ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)&local_9c,pCVar7);
      local_8._0_1_ = 2;
      FUN_00406b10();
      FUN_007c2378(&local_9c,&local_34,0x520);
      local_88 = local_34.right;
      FUN_007c2378(&local_b4,&local_44,0x120);
      iVar9 = 0;
      local_a4 = (int *)((local_d0[2] + *local_d0) / 2 - (int)local_a4);
      CVar8 = GetTextColor(*(HDC *)(pCVar1 + 8));
      FUN_0079df60(0,1,CVar8);
      local_8._0_1_ = 4;
      CVar8 = GetTextColor(*(HDC *)(pCVar1 + 8));
      if (CVar8 != 0) {
        iVar9 = FUN_0079efbc(&local_cc);
      }
      FUN_0079ec58(local_d8,local_a4,local_44.top + local_8c);
      CDC::LineTo(pCVar1,(int)local_a4,local_44.top + local_88);
      if (iVar9 != 0) {
        FUN_0079efbc(iVar9);
      }
      local_cc = CPen::vftable;
      FUN_00416100();
      FUN_00406b10();
    }
    else {
      iVar4 = 1;
      iVar9 = local_a0 + 3 + local_b8;
      local_88 = 1;
      if (DAT_00a00a9c != 0) {
        iVar4 = 0x11;
        local_88 = 0x11;
      }
      local_44.left = ((local_24.right - *(int *)(local_94 + 100)) + local_24.left) / 2 + local_ac;
      local_44.right = (*(int *)(local_94 + 100) + local_24.right + local_24.left) / 2;
      local_a0 = iVar9;
LAB_00881e93:
      local_44.top = local_44.top + iVar9;
      if ((*(int *)(pCVar11 + 0x18) != 0) && (*(int *)(pCVar11 + 0x48) != 0)) {
        piVar2 = (int *)FUN_007c2574();
        pcVar10 = *(code **)(*piVar2 + 0x140);
        guard_check_icall(&local_cc);
        iVar9 = (*pcVar10)();
        OffsetRect(&local_44,0,*(int *)(iVar9 + 4) / 2);
        iVar4 = local_88;
      }
      iVar9 = FUN_007c2511();
      if ((*(int *)(iVar9 + 0x1a0) == 0) && (DAT_00a127ac == 0)) {
        iVar9 = FUN_00429b90(&DAT_0098dde8,0);
        if (iVar9 < 0) {
          ATL::CSimpleStringT<wchar_t,0>::operator=
                    ((CSimpleStringT<wchar_t,0> *)&local_84,(CSimpleStringT<wchar_t,0> *)&local_b4);
        }
        else {
          FUN_005946a0(&DAT_0098dde8,&DAT_0098dde0);
          FUN_007fa476(0x26);
          FUN_005946a0(&DAT_0098dde0,&DAT_0098dde8);
        }
      }
      piVar2 = &local_84;
LAB_008821c0:
      FUN_007c2378(piVar2,&local_44,iVar4);
    }
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00406b10();
    pCVar11 = local_94;
  }
  if (param_5 == 0) {
    pcVar10 = *(code **)(*(int *)pCVar11 + 0x54);
    guard_check_icall();
    iVar9 = (*pcVar10)();
    if ((iVar9 != 0) && (param_7 != 0)) {
      if ((*(uint *)(pCVar11 + 0x24) & 0x30000) == 0) {
        if ((param_6 == 0) || ((*(uint *)(pCVar11 + 0x24) & 0x150000) != 0)) goto LAB_008822a5;
        local_a4 = (int *)FUN_007c2574();
        pcVar10 = *(code **)(*local_a4 + 0x88);
        guard_check_icall(local_90,local_94,*local_d0,local_d0[1],local_d0[2],local_d0[3],2);
      }
      else {
        local_a4 = (int *)FUN_007c2574();
        pcVar10 = *(code **)(*local_a4 + 0x88);
        guard_check_icall(local_90,local_94,*local_d0,local_d0[1],local_d0[2],local_d0[3],1);
      }
      (*pcVar10)();
    }
  }
LAB_008822a5:
  FUN_00406b10();
  FUN_008d9b68();
  return;
}



