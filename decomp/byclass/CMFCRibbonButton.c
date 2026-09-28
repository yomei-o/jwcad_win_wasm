/* CMFCRibbonButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonButton[1], CRibbonUndoLabel[1] */
/* 00865e71  FUN_00865e71  51 bytes, 0 callers */

void FUN_00865e71(byte param_1)

{
  FUN_00865d91();
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




/* vtable slots: CMFCRibbonButton[93], CMFCRibbonColorButton[93], CMFCRibbonColorMenuButton[93], CMFCRibbonDefaultPanelButton[93], CMFCRibbonEdit[93], CMFCRibbonGallery[93], CMFCRibbonGalleryIcon[93], CMFCRibbonLaunchButton[93], CMFCRibbonQuickAccessCustomizeButton[93], CMFCRibbonUndoButton[93], CRibbonCategoryScroll[93], CRibbonUndoLabel[93] */
/* 00865f1e  FUN_00865f1e  146 bytes, 0 callers */

undefined4 FUN_00865f1e(undefined4 param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int *piVar3;
  undefined4 *puVar4;
  int in_ECX;
  int local_8;
  
  uVar2 = FUN_00863232(param_1,param_2);
  if (((param_2 != 0) && (*(int *)(in_ECX + 0x194) == 0)) &&
     (local_8 = 0, 0 < *(int *)(in_ECX + 0x1b8))) {
    do {
      piVar3 = (int *)FUN_00799cf8(local_8);
      if (*(int *)(*piVar3 + 0xa4) != 0) {
        puVar4 = (undefined4 *)FUN_00799cf8(local_8);
        pcVar1 = *(code **)(*(int *)*puVar4 + 0x174);
        guard_check_icall(param_1,1);
        uVar2 = (*pcVar1)();
      }
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x1b8));
  }
  return uVar2;
}




/* vtable slots: CMFCRibbonButton[65], CMFCRibbonButton[98], CMFCRibbonCaptionButton[65], CMFCRibbonCaptionButton[98], CMFCRibbonColorButton[98], CMFCRibbonColorMenuButton[65], CMFCRibbonColorMenuButton[98], CMFCRibbonDefaultPanelButton[65], CMFCRibbonDefaultPanelButton[98], CMFCRibbonGallery[98], CMFCRibbonGalleryIcon[65], CMFCRibbonGalleryIcon[98], CMFCRibbonLabel[65], CMFCRibbonLabel[98], CMFCRibbonLaunchButton[65], CMFCRibbonLaunchButton[98], CMFCRibbonQuickAccessCustomizeButton[65], CMFCRibbonQuickAccessCustomizeButton[98], CMFCRibbonUndoButton[98], CRibbonCategoryScroll[65], CRibbonCategoryScroll[98], CRibbonUndoLabel[65], CRibbonUndoLabel[98] */
/* 00865fb0  FUN_00865fb0  50 bytes, 1 callers */

void FUN_00865fb0(void)

{
  code *pcVar1;
  int *in_ECX;
  undefined1 local_c [8];
  
  pcVar1 = *(code **)(*in_ECX + 0x114);
  guard_check_icall(local_c,0);
  (*pcVar1)();
  FUN_004208d0(0,0);
  return;
}




/* vtable slots: CMFCRibbonButton[97], CMFCRibbonCaptionButton[97], CMFCRibbonColorButton[97], CMFCRibbonColorMenuButton[97], CMFCRibbonDefaultPanelButton[97], CMFCRibbonEdit[97], CMFCRibbonGallery[97], CMFCRibbonGalleryIcon[97], CMFCRibbonLabel[97], CMFCRibbonLaunchButton[97], CMFCRibbonQuickAccessCustomizeButton[97], CMFCRibbonUndoButton[97], CRibbonCategoryScroll[97], CRibbonUndoLabel[97] */
/* 00865fe2  FUN_00865fe2  27 bytes, 0 callers */

void FUN_00865fe2(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x114) = 0;
  *(undefined4 *)(in_ECX + 0x118) = 0;
  *(undefined4 *)(in_ECX + 0x10c) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  return;
}




/* vtable slots: CMFCRibbonButton[102], CMFCRibbonCaptionButton[102], CMFCRibbonColorButton[102], CMFCRibbonColorMenuButton[102], CMFCRibbonDefaultPanelButton[102], CMFCRibbonEdit[102], CMFCRibbonGallery[102], CMFCRibbonGalleryIcon[102], CMFCRibbonLabel[102], CMFCRibbonLaunchButton[102], CMFCRibbonQuickAccessCustomizeButton[102], CMFCRibbonUndoButton[102], CRibbonCategoryScroll[102], CRibbonUndoLabel[102] */
/* 00865ffd  FUN_00865ffd  89 bytes, 0 callers */

void FUN_00865ffd(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x1b8)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x198);
      guard_check_icall();
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x1b8));
  }
  FUN_008634c7();
  return;
}




/* vtable slots: CMFCRibbonButton[90], CMFCRibbonCaptionButton[90], CMFCRibbonLabel[90], CMFCRibbonLaunchButton[90], CRibbonUndoLabel[90] */
/* 0086612f  FUN_0086612f  521 bytes, 7 callers */

CMFCRibbonBaseElement * FUN_0086612f(CMFCRibbonBaseElement *param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int *piVar4;
  CMFCRibbonBaseElement *pCVar5;
  CMFCRibbonBaseElement *in_ECX;
  int iVar6;
  int local_8;
  
  if ((*(int *)(in_ECX + 0x16c) != 0) && (*(HMENU *)(in_ECX + 0x158) != (HMENU)0x0)) {
    DestroyMenu(*(HMENU *)(in_ECX + 0x158));
  }
  if ((*(int *)(in_ECX + 0x17c) != 0) &&
     (((*(HICON *)(in_ECX + 0x15c) == (HICON)0x0 ||
       (DestroyIcon(*(HICON *)(in_ECX + 0x15c)), *(int *)(in_ECX + 0x17c) != 0)) &&
      (*(HICON *)(in_ECX + 0x160) != (HICON)0x0)))) {
    DestroyIcon(*(HICON *)(in_ECX + 0x160));
  }
  FUN_00869c4e();
  CMFCRibbonBaseElement::CopyFrom(in_ECX,param_1);
  *(undefined4 *)(in_ECX + 0x144) = *(undefined4 *)(param_1 + 0x144);
  *(undefined4 *)(in_ECX + 0x148) = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(in_ECX + 0x158) = *(undefined4 *)(param_1 + 0x158);
  *(undefined4 *)(in_ECX + 0x16c) = 0;
  *(undefined4 *)(in_ECX + 0x164) = *(undefined4 *)(param_1 + 0x164);
  *(undefined4 *)(in_ECX + 0x168) = *(undefined4 *)(param_1 + 0x168);
  uVar1 = *(undefined4 *)(param_1 + 0x11c);
  *(undefined4 *)(in_ECX + 0x120) = *(undefined4 *)(param_1 + 0x120);
  *(undefined4 *)(in_ECX + 0x11c) = uVar1;
  *(undefined4 *)(in_ECX + 0x15c) = *(undefined4 *)(param_1 + 0x15c);
  *(undefined4 *)(in_ECX + 0x160) = *(undefined4 *)(param_1 + 0x160);
  *(undefined4 *)(in_ECX + 0x17c) = 0;
  *(undefined4 *)(in_ECX + 0x180) = *(undefined4 *)(param_1 + 0x180);
  *(undefined4 *)(in_ECX + 0x184) = *(undefined4 *)(param_1 + 0x184);
  *(undefined4 *)(in_ECX + 0x18c) = *(undefined4 *)(param_1 + 0x18c);
  *(undefined4 *)(in_ECX + 0x194) = *(undefined4 *)(param_1 + 0x194);
  *(undefined4 *)(in_ECX + 0x198) = *(undefined4 *)(param_1 + 0x198);
  *(undefined4 *)(in_ECX + 0x150) = *(undefined4 *)(param_1 + 0x150);
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0x1b8)) {
    do {
      puVar3 = (undefined4 *)FUN_00799cf8(local_8);
      puVar3 = (undefined4 *)*puVar3;
      pcVar2 = *(code **)*puVar3;
      guard_check_icall();
      (*pcVar2)();
      piVar4 = (int *)FUN_0079d90c();
      pcVar2 = *(code **)(*piVar4 + 0x168);
      guard_check_icall(puVar3);
      (*pcVar2)();
      FUN_0079c90d(*(undefined4 *)(in_ECX + 0x1b8),piVar4);
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(param_1 + 0x1b8));
  }
  iVar6 = 0;
  *(undefined4 *)(in_ECX + 0x154) = *(undefined4 *)(param_1 + 0x154);
  pCVar5 = (CMFCRibbonBaseElement *)FUN_0042fb40(0,0xffffffff);
  if (0 < *(int *)(param_1 + 0x1a4)) {
    do {
      puVar3 = (undefined4 *)FUN_005db5d0(iVar6);
      FUN_0042f500(*(undefined4 *)(in_ECX + 0x1a4),*puVar3);
      iVar6 = iVar6 + 1;
      pCVar5 = param_1 + 0x19c;
    } while (iVar6 < *(int *)(param_1 + 0x1a4));
  }
  return pCVar5;
}




/* vtable slots: CMFCRibbonButton[72], CMFCRibbonCaptionButton[72], CMFCRibbonColorMenuButton[72], CMFCRibbonEdit[72], CMFCRibbonGallery[72], CMFCRibbonGalleryIcon[72], CMFCRibbonLabel[72], CMFCRibbonLaunchButton[72], CMFCRibbonQuickAccessCustomizeButton[72], CMFCRibbonUndoButton[72], CRibbonCategoryScroll[72], CRibbonUndoLabel[72] */
/* 008668ce  FUN_008668ce  931 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008668ce(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  CObject *pCVar1;
  double dVar2;
  code *pcVar3;
  HICON pHVar4;
  CObject *pCVar5;
  CObject *pCVar6;
  int iVar7;
  uint uVar8;
  HDC hdc;
  HICON in_ECX;
  UINT diFlags;
  undefined1 local_168 [12];
  undefined4 local_15c;
  undefined4 uStack_158;
  undefined8 local_154;
  undefined8 local_14c;
  double local_144;
  int local_13c;
  CObject *local_138;
  CObject *local_134;
  HICON local_130;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x158;
  local_8 = 0x8668dd;
  local_13c = param_1;
  local_130 = in_ECX;
  pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonButton_00998478,
                              (CObject *)in_ECX[0x23].unused);
  local_134 = pCVar6;
  if (pCVar6 == (CObject *)0x0) {
    pHVar4 = (HICON)in_ECX[0x57].unused;
    if (pHVar4 == (HICON)0x0) {
      local_130 = (HICON)in_ECX[0x24].unused;
      if ((local_130 == (HICON)0x0) || (local_130[0x49].unused < 1)) {
        local_130 = (HICON)in_ECX[0x22].unused;
        if ((local_130 != (HICON)0x0) && ((param_5 != param_3 && (param_6 != param_4)))) {
          local_134 = *(CObject **)(local_130->unused + 0xd0);
          guard_check_icall(local_13c,param_3,param_4,param_5,param_6);
          (*(code *)local_134)();
        }
      }
      else {
        pcVar3 = *(code **)(local_130->unused + 0x24c);
        guard_check_icall(local_13c,param_3,param_4,param_5,param_6);
        (*pcVar3)();
      }
    }
    else {
      pCVar6 = (CObject *)0x10;
      if (((param_2 == 0) ||
          (local_130 = (HICON)in_ECX[0x58].unused, (HICON)in_ECX[0x58].unused == (HICON)0x0)) &&
         (local_130 = pHVar4, param_2 == 0)) {
        local_134 = (CObject *)0x20;
        pCVar6 = (CObject *)0x20;
      }
      else {
        local_134 = (CObject *)0x10;
      }
      local_144 = (double)CONCAT44(local_144._4_4_,pCVar6);
      local_154 = (double)CONCAT44(pCVar6,(undefined4)local_154);
      local_138 = pCVar6;
      iVar7 = FUN_007c2511();
      local_14c = 0x3ff0000000000000;
      if (*(int *)(iVar7 + 0x1e8) == 0) {
        dVar2 = 1.0;
      }
      else {
        dVar2 = *(double *)(iVar7 + 0x1e0);
      }
      if (dVar2 != 1.0) {
        FUN_007c2511();
        local_144 = (double)local_144._0_4_;
        pCVar6 = (CObject *)thunk_FUN_008d99f0();
        local_134 = pCVar6;
        iVar7 = FUN_007c2511();
        if (*(int *)(iVar7 + 0x1e8) != 0) {
          local_14c = *(undefined8 *)(iVar7 + 0x1e0);
        }
        local_154 = (double)local_154._4_4_;
        local_138 = (CObject *)thunk_FUN_008d99f0();
      }
      if (in_ECX[0x35].unused == 0) {
        pcVar3 = *(code **)(in_ECX->unused + 0xa4);
        guard_check_icall();
        iVar7 = (*pcVar3)();
        if ((iVar7 == 0) || (uVar8 = FUN_00797acc(), (uVar8 & 0x400000) == 0)) {
          diFlags = 3;
        }
        else {
          diFlags = 0x13;
        }
        if (local_13c == 0) {
          hdc = (HDC)0x0;
        }
        else {
          hdc = *(HDC *)(local_13c + 4);
        }
        DrawIconEx(hdc,param_3,param_4,local_130,(int)local_134,(int)local_138,0,(HBRUSH)0x0,diFlags
                  );
      }
      else {
        FUN_007e6d9d();
        local_8 = 0;
        if (param_2 == 0) {
          local_d8 = 0x20;
        }
        else {
          local_d8 = 0x10;
        }
        local_d4 = local_d8;
        FUN_007e77f4(local_130,in_ECX[0x60].unused);
        FUN_007eb6ca(local_168,pCVar6,local_138,0);
        FUN_007e8cae(local_13c,param_3,param_4,0,0,1,0,0,0,0xff);
        FUN_007e98b8(local_168);
        FUN_007e6f6a();
      }
    }
  }
  else {
    local_138 = *(CObject **)(pCVar6 + 0xd4);
    pCVar1 = pCVar6 + 0x74;
    *(int *)(pCVar6 + 0xd4) = in_ECX[0x35].unused;
    local_15c = *(undefined4 *)pCVar1;
    uStack_158 = *(undefined4 *)(pCVar6 + 0x78);
    local_154 = *(double *)(pCVar6 + 0x7c);
    *(int *)pCVar1 = local_130[0x1d].unused;
    *(int *)(pCVar6 + 0x78) = local_130[0x1e].unused;
    *(int *)(pCVar6 + 0x7c) = local_130[0x1f].unused;
    *(int *)(pCVar6 + 0x80) = local_130[0x20].unused;
    pcVar3 = *(code **)(*(int *)pCVar6 + 0x120);
    guard_check_icall(local_13c,param_2,param_3,param_4,param_5,param_6);
    pCVar5 = local_134;
    (*pcVar3)();
    *(CObject **)(pCVar5 + 0xd4) = local_138;
    *(undefined4 *)pCVar1 = local_15c;
    *(undefined4 *)(pCVar6 + 0x78) = uStack_158;
    *(undefined4 *)(pCVar6 + 0x7c) = (undefined4)local_154;
    *(int *)(pCVar6 + 0x80) = local_154._4_4_;
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonButton[152], CMFCRibbonCaptionButton[152], CMFCRibbonColorButton[152], CMFCRibbonColorMenuButton[152], CMFCRibbonDefaultPanelButton[152], CMFCRibbonEdit[152], CMFCRibbonGallery[152], CMFCRibbonGalleryIcon[152], CMFCRibbonLabel[152], CMFCRibbonLaunchButton[152], CMFCRibbonQuickAccessCustomizeButton[152], CMFCRibbonUndoButton[152], CRibbonCategoryScroll[152], CRibbonUndoLabel[152] */
/* 00866c71  FUN_00866c71  279 bytes, 0 callers */

undefined4
FUN_00866c71(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,int param_8)

{
  code *pcVar1;
  bool bVar2;
  int *piVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  BOOL BVar6;
  int iVar7;
  int in_ECX;
  int local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  int *piStack_30;
  undefined4 *puStack_2c;
  undefined1 local_1c [4];
  undefined1 *local_18;
  int *local_14;
  int *local_10;
  code *local_c;
  int *local_8;
  
  local_14 = param_1;
  local_10 = param_2;
  if (DAT_00a12704 == 0) {
    iVar7 = -1;
    if (param_8 != -1) {
      pcVar1 = *(code **)(*param_1 + 0x30);
      puStack_2c = (undefined4 *)0x866d4d;
      guard_check_icall();
      puStack_2c = (undefined4 *)0x866d51;
      iVar7 = (*pcVar1)();
    }
    puStack_2c = &param_3;
    uStack_34 = 0x866d65;
    piStack_30 = local_10;
    local_8 = (int *)FUN_007c2378();
    if (iVar7 == -1) {
      return local_8;
    }
    pcVar1 = *(code **)(*param_1 + 0x30);
    puStack_2c = (undefined4 *)0x866d7b;
    guard_check_icall();
    puStack_2c = (undefined4 *)0x866d7f;
    (*pcVar1)();
    return local_8;
  }
  iVar7 = *(int *)(in_ECX + 0x84);
  if ((iVar7 != 0) && (*(int *)(iVar7 + 0x20) != 0)) {
    puStack_2c = (undefined4 *)0x866cab;
    pHVar4 = GetParent(*(HWND *)(iVar7 + 0x20));
    puStack_2c = (undefined4 *)0x866cb1;
    pCVar5 = CWnd::FromHandle(pHVar4);
    puStack_2c = (undefined4 *)0x866cba;
    BVar6 = IsZoomed(*(HWND *)(pCVar5 + 0x20));
    if (BVar6 != 0) {
      bVar2 = true;
      goto LAB_00866cc5;
    }
  }
  bVar2 = false;
LAB_00866cc5:
  local_8 = (int *)FUN_007c2574();
  piVar3 = local_10;
  local_c = *(code **)(*local_8 + 0x2cc);
  local_44 = 0xffffff;
  if (!bVar2) {
    local_44 = param_8;
  }
  puStack_2c = (undefined4 *)0x0;
  piStack_30 = (int *)param_7;
  local_18 = (undefined1 *)&local_44;
  uStack_40 = param_3;
  uStack_3c = param_4;
  uStack_38 = param_5;
  uStack_34 = param_6;
  local_44 = FUN_004054a0(*local_10 + -0x10);
  local_44 = local_44 + 0x10;
  guard_check_icall(local_14);
  (*local_c)();
  iVar7 = FUN_00566800(local_1c,piVar3);
  return *(undefined4 *)(iVar7 + 4);
}




/* vtable slots: CMFCRibbonButton[105], CMFCRibbonCaptionButton[105], CMFCRibbonColorButton[105], CMFCRibbonColorMenuButton[105], CMFCRibbonDefaultPanelButton[105], CMFCRibbonEdit[105], CMFCRibbonGallery[105], CMFCRibbonGalleryIcon[105], CMFCRibbonLabel[105], CMFCRibbonLaunchButton[105], CMFCRibbonQuickAccessCustomizeButton[105], CMFCRibbonUndoButton[105], CRibbonCategoryScroll[105], CRibbonUndoLabel[105] */
/* 0086708d  FUN_0086708d  105 bytes, 0 callers */

int FUN_0086708d(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  
  iVar2 = FUN_0086367c(param_1);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (0 < *(int *)(in_ECX + 0x1b8)) {
      do {
        puVar3 = (undefined4 *)FUN_00799cf8(iVar2);
        pcVar1 = *(code **)(*(int *)*puVar3 + 0x1a4);
        guard_check_icall(param_1);
        iVar4 = (*pcVar1)();
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(in_ECX + 0x1b8));
    }
    iVar2 = 0;
  }
  return iVar2;
}




/* vtable slots: CMFCRibbonButton[104], CMFCRibbonCaptionButton[104], CMFCRibbonColorButton[104], CMFCRibbonColorMenuButton[104], CMFCRibbonDefaultPanelButton[104], CMFCRibbonEdit[104], CMFCRibbonGallery[104], CMFCRibbonGalleryIcon[104], CMFCRibbonLabel[104], CMFCRibbonLaunchButton[104], CMFCRibbonQuickAccessCustomizeButton[104], CMFCRibbonUndoButton[104], CRibbonCategoryScroll[104], CRibbonUndoLabel[104] */
/* 008670f6  FUN_008670f6  105 bytes, 0 callers */

int FUN_008670f6(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  
  iVar2 = FUN_00863694(param_1);
  if (iVar2 == 0) {
    iVar2 = 0;
    if (0 < *(int *)(in_ECX + 0x1b8)) {
      do {
        puVar3 = (undefined4 *)FUN_00799cf8(iVar2);
        pcVar1 = *(code **)(*(int *)*puVar3 + 0x1a0);
        guard_check_icall(param_1);
        iVar4 = (*pcVar1)();
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(in_ECX + 0x1b8));
    }
    iVar2 = 0;
  }
  return iVar2;
}




/* vtable slots: CMFCRibbonButton[63], CMFCRibbonColorMenuButton[63], CMFCRibbonDefaultPanelButton[63], CMFCRibbonLaunchButton[63], CRibbonCategoryScroll[63], CRibbonUndoLabel[63] */
/* 0086715f  FUN_0086715f  612 bytes, 2 callers */

void FUN_0086715f(int *param_1)

{
  double dVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  int *in_ECX;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  if (0 < in_ECX[0x6e]) {
    do {
      puVar3 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar2 = *(code **)(*(int *)*puVar3 + 0x164);
      guard_check_icall(in_ECX[0x22]);
      (*pcVar2)();
      local_8 = local_8 + 1;
    } while (local_8 < in_ECX[0x6e]);
  }
  iVar5 = 0;
  piVar6 = &local_18;
  uVar7 = 1;
  pcVar2 = *(code **)(*in_ECX + 0x114);
  guard_check_icall(piVar6,1);
  (*pcVar2)();
  pcVar2 = *(code **)(*in_ECX + 0x250);
  guard_check_icall();
  iVar4 = (*pcVar2)();
  if (iVar4 == 0) {
    pcVar2 = *(code **)(*in_ECX + 0x240);
    guard_check_icall(piVar6,uVar7);
    local_10 = (*pcVar2)();
    local_8 = 0;
    if ((in_ECX[0x31] == 0) && (in_ECX[0x30] == 0)) {
      local_c = 3;
      pcVar2 = *(code **)(*in_ECX + 0x27c);
      local_8 = 3;
      puVar3 = &local_c;
      guard_check_icall(puVar3);
      (*pcVar2)();
      local_8 = FUN_0086748e();
      if (in_ECX[0x3b] != 0) {
        local_8 = local_8 + 6;
      }
    }
    else {
      pcVar2 = *(code **)(*in_ECX + 0x27c);
      iVar4 = FUN_007c2511();
      if (*(int *)(iVar4 + 0x1e8) == 0) {
        dVar1 = 1.0;
      }
      else {
        dVar1 = *(double *)(iVar4 + 0x1e0);
      }
      if (dVar1 == 1.0) {
        local_28 = 3;
        puVar3 = &local_28;
        local_24 = 3;
      }
      else {
        local_20 = 3;
        puVar3 = &local_20;
        local_1c = 2;
      }
      guard_check_icall(puVar3);
      (*pcVar2)();
      if ((local_18 == 0) && (local_14 == 0)) {
        local_18 = 0x10;
        local_14 = 0x10;
        iVar4 = FUN_007c2511();
        if (*(int *)(iVar4 + 0x1e8) == 0) {
          dVar1 = 1.0;
        }
        else {
          dVar1 = *(double *)(iVar4 + 0x1e0);
        }
        if (dVar1 != 1.0) {
          FUN_007c2511();
          local_18 = thunk_FUN_008d99f0();
          FUN_007c2511();
          local_14 = thunk_FUN_008d99f0();
        }
      }
    }
    pcVar2 = *(code **)(*in_ECX + 0x138);
    guard_check_icall(puVar3);
    iVar4 = (*pcVar2)();
    if (iVar4 != 0) {
      if (in_ECX[0x5a] == 0) {
        iVar5 = (local_10 - in_ECX[0x47] / 2) + -1;
      }
      else {
        iVar5 = local_10 + 1 + in_ECX[0x47] / 2;
      }
    }
    iVar4 = in_ECX[0x48];
    *param_1 = iVar5 + in_ECX[0x47] * 2 + local_18 + local_8;
    param_1[1] = local_14 + iVar4 * 2;
  }
  else {
    *param_1 = local_18;
    param_1[1] = local_14;
  }
  return;
}




/* vtable slots: CMFCRibbonButton[123], CMFCRibbonCaptionButton[123], CMFCRibbonColorButton[123], CMFCRibbonColorMenuButton[123], CMFCRibbonDefaultPanelButton[123], CMFCRibbonEdit[123], CMFCRibbonGallery[123], CMFCRibbonGalleryIcon[123], CMFCRibbonLabel[123], CMFCRibbonLaunchButton[123], CMFCRibbonQuickAccessCustomizeButton[123], CMFCRibbonUndoButton[123], CRibbonCategoryScroll[123], CRibbonUndoLabel[123] */
/* 008673c3  FUN_008673c3  102 bytes, 0 callers */

void FUN_008673c3(int param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  FUN_0079c90d(*(undefined4 *)(param_1 + 8),in_ECX);
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x1b8)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1ec);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x1b8));
  }
  return;
}




/* vtable slots: CMFCRibbonButton[122], CMFCRibbonCaptionButton[122], CMFCRibbonColorButton[122], CMFCRibbonColorMenuButton[122], CMFCRibbonDefaultPanelButton[122], CMFCRibbonEdit[122], CMFCRibbonGallery[122], CMFCRibbonGalleryIcon[122], CMFCRibbonLabel[122], CMFCRibbonLaunchButton[122], CMFCRibbonQuickAccessCustomizeButton[122], CMFCRibbonUndoButton[122], CRibbonCategoryScroll[122], CRibbonUndoLabel[122] */
/* 00867429  FUN_00867429  101 bytes, 0 callers */

void FUN_00867429(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  FUN_00863750(param_1,param_2);
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x1b8)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1e8);
      guard_check_icall(param_1,param_2);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x1b8));
  }
  return;
}




/* vtable slots: CMFCRibbonButton[69], CMFCRibbonCaptionButton[69], CMFCRibbonColorButton[69], CMFCRibbonColorMenuButton[69], CMFCRibbonEdit[69], CMFCRibbonGallery[69], CMFCRibbonGalleryIcon[69], CMFCRibbonLabel[69], CMFCRibbonLaunchButton[69], CMFCRibbonUndoButton[69], CRibbonCategoryScroll[69], CRibbonUndoLabel[69] */
/* 008674cb  FUN_008674cb  363 bytes, 0 callers */

undefined4 * FUN_008674cb(undefined4 *param_1,int param_2)

{
  double dVar1;
  code *pcVar2;
  CObject *pCVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  undefined4 uVar7;
  
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonButton_00998478,
                              *(CObject **)(in_ECX + 0x8c));
  if (pCVar3 == (CObject *)0x0) {
    if (*(int *)(in_ECX + 0x15c) == 0) {
      if (param_2 == 0) {
        iVar4 = *(int *)(in_ECX + 0x148);
      }
      else {
        iVar4 = *(int *)(in_ECX + 0x144);
      }
      if (-1 < iVar4) {
        if ((*(int *)(in_ECX + 0x90) != 0) && (0 < *(int *)(*(int *)(in_ECX + 0x90) + 0x124))) {
          FUN_008c4f7d(param_1);
          return param_1;
        }
        iVar6 = *(int *)(in_ECX + 0x88);
        if (iVar6 != 0) {
          if (param_2 == 0) {
            iVar6 = *(int *)(iVar6 + 0x694);
          }
          else {
            iVar6 = *(int *)(iVar6 + 0x57c);
          }
          if (iVar4 < iVar6) {
            FUN_008721a4(param_1,param_2 == 0);
            return param_1;
          }
        }
      }
      *param_1 = 0;
      param_1[1] = 0;
    }
    else {
      if (param_2 == 0) {
        uVar7 = 0x20;
      }
      else {
        uVar7 = 0x10;
      }
      iVar4 = FUN_007c2511();
      if (*(int *)(iVar4 + 0x1e8) == 0) {
        dVar1 = 1.0;
      }
      else {
        dVar1 = *(double *)(iVar4 + 0x1e0);
      }
      uVar5 = uVar7;
      if (dVar1 != 1.0) {
        FUN_007c2511();
        uVar7 = thunk_FUN_008d99f0();
        FUN_007c2511();
        uVar5 = thunk_FUN_008d99f0();
      }
      *param_1 = uVar7;
      param_1[1] = uVar5;
    }
  }
  else {
    pcVar2 = *(code **)(*(int *)pCVar3 + 0x114);
    guard_check_icall(param_1,param_2);
    (*pcVar2)();
  }
  return param_1;
}




/* vtable slots: CMFCRibbonButton[64], CMFCRibbonCaptionButton[64], CMFCRibbonColorButton[64], CMFCRibbonColorMenuButton[64], CMFCRibbonDefaultPanelButton[64], CMFCRibbonGallery[64], CMFCRibbonGalleryIcon[64], CMFCRibbonLaunchButton[64], CMFCRibbonQuickAccessCustomizeButton[64], CMFCRibbonUndoButton[64], CRibbonCategoryScroll[64], CRibbonUndoLabel[64] */
/* 00867636  FUN_00867636  378 bytes, 0 callers */

int * FUN_00867636(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  int *piVar6;
  undefined4 uVar7;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  if (0 < in_ECX[0x6e]) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x164);
      guard_check_icall(in_ECX[0x22]);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < in_ECX[0x6e]);
  }
  if ((in_ECX[0x31] == 0) && (in_ECX[0x30] == 0)) {
    local_c = 3;
    puVar2 = &local_c;
    local_8 = 3;
    pcVar1 = *(code **)(*in_ECX + 0x27c);
    guard_check_icall(puVar2);
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x138);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      iVar3 = 0;
    }
    else {
      pcVar1 = *(code **)(*in_ECX + 0x240);
      guard_check_icall(puVar2);
      iVar3 = (*pcVar1)();
    }
    piVar6 = &local_14;
    uVar7 = 1;
    pcVar1 = *(code **)(*in_ECX + 0x114);
    guard_check_icall(piVar6,1);
    (*pcVar1)();
    if (local_10 < 0x10) {
      local_10 = 0x10;
    }
    local_8 = local_10;
    if (local_10 <= in_ECX[0x44]) {
      local_8 = in_ECX[0x44];
    }
    local_8 = local_8 + in_ECX[0x48] * 2;
    pcVar1 = *(code **)(*in_ECX + 0x278);
    guard_check_icall(piVar6,uVar7);
    iVar4 = (*pcVar1)();
    iVar5 = FUN_0086748e();
    local_14 = in_ECX[0x43] + in_ECX[0x47] * 2 + iVar4 + iVar5 + local_14;
    iVar4 = local_14 + 1;
    if (in_ECX[0x3b] != 0) {
      iVar4 = local_14 + 7;
    }
    *param_1 = iVar4 + iVar3;
    param_1[1] = local_8;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0xfc);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
  }
  return param_1;
}




/* vtable slots: CMFCRibbonButton[118], CMFCRibbonCaptionButton[118], CMFCRibbonColorMenuButton[118], CMFCRibbonDefaultPanelButton[118], CMFCRibbonEdit[118], CMFCRibbonGalleryIcon[118], CMFCRibbonLabel[118], CRibbonCategoryScroll[118], CRibbonUndoLabel[118] */
/* 008677b0  FUN_008677b0  759 bytes, 2 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_008677b0(int *param_1,undefined4 param_2,int param_3)

{
  RECT *lprc;
  code *pcVar1;
  BOOL BVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  int iVar5;
  undefined1 local_30 [4];
  RECT *local_2c;
  int *local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  piVar4 = &local_20;
  local_28 = param_1;
  pcVar1 = *(code **)(*in_ECX + 0x1d4);
  guard_check_icall(piVar4,param_2);
  (*pcVar1)();
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if ((local_20 == 0) && (local_1c == 0)) {
    return param_1;
  }
  lprc = (RECT *)(in_ECX + 0x1d);
  local_2c = lprc;
  BVar2 = IsRectEmpty(lprc);
  if (BVar2 != 0) {
    return param_1;
  }
  if (param_3 == 0) {
    iVar5 = lprc->left + 10;
  }
  else {
    iVar5 = in_ECX[0x1f] - local_20 / 2;
  }
  *param_1 = iVar5;
  param_1[1] = in_ECX[0x20] - local_1c / 2;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  SetRectEmpty(&local_18);
  pcVar1 = *(code **)(*in_ECX + 0x130);
  guard_check_icall(piVar4,param_2);
  local_24 = (*pcVar1)();
  if (((local_24 != 0) && (iVar5 = FUN_00863d99(), iVar5 == 0)) &&
     ((in_ECX[0x31] == 0 || (in_ECX[0x30] == 0)))) {
    pcVar1 = *(code **)(*in_ECX + 0x24c);
    guard_check_icall();
    iVar5 = (*pcVar1)();
    if (iVar5 == 0) {
      local_18.left = *(LONG *)(local_24 + 0xcc);
      local_18.top = *(int *)(local_24 + 0xd0);
      local_18.right = *(LONG *)(local_24 + 0xd4);
      local_18.bottom = *(int *)(local_24 + 0xd8);
      BVar2 = IsRectEmpty(&local_18);
      param_1 = local_28;
      if (BVar2 == 0) {
        local_18.bottom = local_18.bottom + (*(int *)(local_24 + 0xc0) - *(int *)(local_24 + 200));
        local_28[1] = local_18.bottom - local_1c / 2;
      }
    }
  }
  pcVar1 = *(code **)(*in_ECX + 0x24c);
  guard_check_icall();
  iVar5 = (*pcVar1)();
  if (((iVar5 == 0) || (in_ECX[0x31] != 0)) || (in_ECX[0x30] != 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x250);
    guard_check_icall();
    iVar5 = (*pcVar1)();
    if (iVar5 == 0) {
      if ((in_ECX[100] == 0) && (in_ECX[0x30] == 0)) {
        iVar5 = FUN_00863d99();
        if (iVar5 == 0) {
          if (in_ECX[0x31] != 0) {
            *param_1 = (in_ECX[0x1f] + in_ECX[0x1d]) / 2 - local_20 / 2;
            param_1[1] = (in_ECX[0x20] + in_ECX[0x1e]) / 2;
          }
          BVar2 = IsRectEmpty(&local_18);
          if (BVar2 == 0) {
            iVar5 = in_ECX[0x1e];
            iVar3 = (local_18.top + local_18.bottom) / 2;
            if (iVar5 < iVar3) {
              if (iVar3 < in_ECX[0x20]) {
                iVar5 = (in_ECX[0x20] + in_ECX[0x1e]) / 2;
              }
              param_1[1] = iVar5 - local_1c / 2;
            }
          }
          goto LAB_00867a83;
        }
        iVar5 = (local_2c->bottom + local_2c->top) / 2;
      }
      else {
        if (in_ECX[0x2c] == 0) {
          if (param_3 != 0) goto LAB_00867a83;
          goto LAB_00867a6a;
        }
        if (param_3 == 0) {
          pcVar1 = *(code **)(*in_ECX + 0x114);
          guard_check_icall(local_30,0);
          piVar4 = (int *)(*pcVar1)();
          *param_1 = in_ECX[0x1d] + 4 + (*piVar4 - local_20);
        }
        iVar5 = (in_ECX[0x20] - local_1c) + -4;
      }
      param_1[1] = iVar5;
      goto LAB_00867a83;
    }
    param_1[1] = (local_2c->bottom + local_2c->top) / 2 - local_1c / 2;
    iVar5 = local_2c->right + local_2c->left;
  }
  else {
    param_1[1] = in_ECX[0x20];
LAB_00867a6a:
    iVar5 = in_ECX[0x1f] + in_ECX[0x1d];
  }
  *param_1 = iVar5 / 2 - local_20 / 2;
LAB_00867a83:
  param_1[2] = *param_1 + local_20;
  param_1[3] = param_1[1] + local_1c;
  return param_1;
}




/* vtable slots: CMFCRibbonButton[62], CMFCRibbonColorMenuButton[62], CMFCRibbonDefaultPanelButton[62], CMFCRibbonEdit[62], CMFCRibbonQuickAccessCustomizeButton[62], CRibbonCategoryScroll[62], CRibbonUndoLabel[62] */
/* 00867aa7  FUN_00867aa7  781 bytes, 3 callers */

int * FUN_00867aa7(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  code *pcVar4;
  int iVar5;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  if (0 < in_ECX[0x6e]) {
    do {
      puVar1 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar4 = *(code **)(*(int *)*puVar1 + 0x164);
      guard_check_icall(in_ECX[0x22]);
      (*pcVar4)();
      local_8 = local_8 + 1;
    } while (local_8 < in_ECX[0x6e]);
  }
  if ((in_ECX[0x31] != 0) || (in_ECX[0x30] != 0)) {
    pcVar4 = *(code **)(*in_ECX + 0xfc);
LAB_00867d98:
    guard_check_icall(param_1,param_2);
    (*pcVar4)();
    return param_1;
  }
  pcVar4 = *(code **)(*in_ECX + 0x104);
  guard_check_icall();
  iVar2 = (*pcVar4)();
  if (iVar2 == 0) {
    pcVar4 = *(code **)(*in_ECX + 0x100);
    goto LAB_00867d98;
  }
  pcVar4 = *(code **)(*in_ECX + 0x114);
  guard_check_icall(&local_18,0);
  (*pcVar4)();
  pcVar4 = *(code **)(*in_ECX + 0x114);
  guard_check_icall(&local_20,1);
  (*pcVar4)();
  pcVar4 = *(code **)(*in_ECX + 0x250);
  guard_check_icall();
  iVar2 = (*pcVar4)();
  if (iVar2 != 0) {
    *param_1 = local_18;
    param_1[1] = local_14;
    return param_1;
  }
  local_10 = FUN_0086748e();
  if ((local_18 == 0) && (local_14 == 0)) {
    iVar2 = in_ECX[0x2c];
    if (iVar2 != 0) goto LAB_00867bc0;
  }
  else {
    iVar2 = in_ECX[0x2c];
    if (iVar2 == 0) {
      puVar1 = &local_c;
      local_c = 5;
      local_8 = 1;
      pcVar4 = *(code **)(*in_ECX + 0x27c);
      guard_check_icall(puVar1);
      (*pcVar4)();
      pcVar4 = *(code **)(*in_ECX + 0x24c);
      guard_check_icall();
      iVar2 = (*pcVar4)();
      if (iVar2 != 0) {
        local_18 = local_18 + in_ECX[0x47] * 2 + 2;
      }
      iVar2 = local_18 + in_ECX[0x47] * 2;
      if (iVar2 <= in_ECX[0x45] + 5) {
        iVar2 = in_ECX[0x45] + 5;
      }
      pcVar4 = *(code **)(*in_ECX + 0x24c);
      guard_check_icall(puVar1);
      iVar5 = (*pcVar4)();
      if (iVar5 != 0) {
        iVar2 = iVar2 + 2;
      }
      if (in_ECX[0x3b] != 0) {
        iVar2 = iVar2 + 6;
      }
      local_8 = in_ECX[0x46];
      if (in_ECX[0x46] <= local_14 + 1) {
        local_8 = local_14 + 1;
      }
      *param_1 = local_10 + iVar2;
      local_8 = local_14 + 1 + local_8;
      goto LAB_00867d8b;
    }
LAB_00867bc0:
    if ((local_18 != 0) || (local_14 != 0)) {
      local_20 = local_18 + 2;
      in_ECX[0x48] = 5;
      local_1c = local_14 + 2;
    }
  }
  iVar3 = in_ECX[0x47];
  iVar5 = local_20 + iVar3 * 2;
  if (0 < in_ECX[0x43]) {
    iVar5 = iVar5 + iVar3 + in_ECX[0x43];
    if ((local_18 == 0) && (local_14 == 0)) {
      iVar3 = in_ECX[0x47];
    }
    else {
      iVar3 = in_ECX[0x47];
      if (iVar2 != 0) {
        iVar5 = iVar5 + iVar3;
      }
    }
  }
  if (((local_18 != 0) || (local_14 != 0)) && (iVar2 != 0)) {
    iVar5 = iVar5 + iVar3;
  }
  local_8 = in_ECX[0x44];
  if (in_ECX[0x44] < local_1c) {
    local_8 = local_1c;
  }
  local_8 = local_8 + in_ECX[0x48] * 2;
  if (local_1c == 0) {
    local_8 = local_8 + in_ECX[0x48] * 2;
  }
  pcVar4 = *(code **)(*in_ECX + 0x138);
  guard_check_icall();
  iVar2 = (*pcVar4)();
  if (iVar2 != 0) {
    pcVar4 = *(code **)(*in_ECX + 0x240);
    guard_check_icall();
    iVar2 = (*pcVar4)();
    iVar5 = iVar5 + iVar2;
    if (((in_ECX[0x5a] != 0) && (in_ECX[0x29] != -1)) && ((in_ECX[0x29] != 0 && (0 < in_ECX[0x43])))
       ) {
      iVar5 = iVar5 + in_ECX[0x53];
    }
  }
  if ((in_ECX[0x3b] != 0) && (in_ECX[0x31] == 0)) {
    iVar5 = iVar5 + 6;
  }
  *param_1 = local_10 + iVar5;
LAB_00867d8b:
  param_1[1] = local_8;
  return param_1;
}




/* vtable slots: CMFCRibbonButton[0], CRibbonCategoryScroll[0] */
/* 00867db4  FUN_00867db4  6 bytes, 0 callers */

undefined ** FUN_00867db4(void)

{
  return &PTR_s_CMFCRibbonButton_00998478;
}




/* vtable slots: CMFCRibbonButton[158], CMFCRibbonCaptionButton[158], CMFCRibbonColorButton[158], CMFCRibbonColorMenuButton[158], CMFCRibbonDefaultPanelButton[158], CMFCRibbonEdit[158], CMFCRibbonGallery[158], CMFCRibbonGalleryIcon[158], CMFCRibbonLabel[158], CMFCRibbonLaunchButton[158], CMFCRibbonQuickAccessCustomizeButton[158], CMFCRibbonUndoButton[158], CRibbonCategoryScroll[158], CRibbonUndoLabel[158] */
/* 00867dba  FUN_00867dba  7 bytes, 0 callers */

undefined4 FUN_00867dba(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x11c);
}




/* vtable slots: CMFCRibbonButton[48], CMFCRibbonCaptionButton[48], CMFCRibbonColorButton[48], CMFCRibbonColorMenuButton[48], CMFCRibbonEdit[48], CMFCRibbonGallery[48], CMFCRibbonLabel[48], CMFCRibbonLaunchButton[48], CMFCRibbonUndoButton[48], CRibbonCategoryScroll[48], CRibbonUndoLabel[48] */
/* 00867dc1  FUN_00867dc1  59 bytes, 1 callers */

undefined4 FUN_00867dc1(undefined4 param_1)

{
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0xc4) == 0) && (*(int *)(in_ECX + 0x18c) != 0)) &&
     (*(int *)(*(int *)(in_ECX + 0x70) + -0xc) != 0)) {
    CStringT<>(&DAT_00956338);
  }
  else {
    FUN_00863a89(param_1);
  }
  return param_1;
}




/* vtable slots: CMFCRibbonButton[67], CMFCRibbonCaptionButton[67], CMFCRibbonColorButton[67], CMFCRibbonColorMenuButton[67], CMFCRibbonDefaultPanelButton[67], CMFCRibbonGallery[67], CMFCRibbonGalleryIcon[67], CMFCRibbonLabel[67], CMFCRibbonLaunchButton[67], CMFCRibbonQuickAccessCustomizeButton[67], CMFCRibbonUndoButton[67], CRibbonCategoryScroll[67], CRibbonUndoLabel[67] */
/* 00867dfc  FUN_00867dfc  50 bytes, 0 callers */

void FUN_00867dfc(void)

{
  code *pcVar1;
  int *in_ECX;
  undefined1 local_c [8];
  
  pcVar1 = *(code **)(*in_ECX + 0x114);
  guard_check_icall(local_c,1);
  (*pcVar1)();
  FUN_004208d0(0,0);
  return;
}




/* vtable slots: CMFCRibbonButton[66], CMFCRibbonCaptionButton[66], CMFCRibbonColorButton[66], CMFCRibbonColorMenuButton[66], CMFCRibbonDefaultPanelButton[66], CMFCRibbonEdit[66], CMFCRibbonGallery[66], CMFCRibbonGalleryIcon[66], CMFCRibbonLabel[66], CMFCRibbonLaunchButton[66], CMFCRibbonQuickAccessCustomizeButton[66], CMFCRibbonUndoButton[66], CRibbonCategoryScroll[66], CRibbonUndoLabel[66] */
/* 00867e2e  FUN_00867e2e  12 bytes, 0 callers */

bool FUN_00867e2e(void)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x60) + -0xc) != 0;
}




/* vtable slots: CMFCRibbonButton[78], CMFCRibbonCaptionButton[78], CMFCRibbonColorMenuButton[78], CMFCRibbonDefaultPanelButton[78], CMFCRibbonEdit[78], CMFCRibbonGalleryIcon[78], CMFCRibbonLabel[78], CMFCRibbonLaunchButton[78], CRibbonCategoryScroll[78], CRibbonUndoLabel[78] */
/* 00867e3a  FUN_00867e3a  22 bytes, 0 callers */

undefined4 FUN_00867e3a(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(int *)(in_ECX + 0x158) != 0) || (0 < *(int *)(in_ECX + 0x1b8))) {
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CMFCRibbonButton[151], CMFCRibbonCaptionButton[151], CMFCRibbonColorButton[151], CMFCRibbonColorMenuButton[151], CMFCRibbonDefaultPanelButton[151], CMFCRibbonEdit[151], CMFCRibbonGallery[151], CMFCRibbonGalleryIcon[151], CMFCRibbonLabel[151], CMFCRibbonLaunchButton[151], CMFCRibbonQuickAccessCustomizeButton[151], CMFCRibbonUndoButton[151], CRibbonCategoryScroll[151], CRibbonUndoLabel[151] */
/* 00867ee5  FUN_00867ee5  7 bytes, 0 callers */

undefined4 FUN_00867ee5(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x184);
}




/* vtable slots: CMFCRibbonButton[58], CMFCRibbonCaptionButton[58], CMFCRibbonColorButton[58], CMFCRibbonColorMenuButton[58], CMFCRibbonDefaultPanelButton[58], CMFCRibbonEdit[58], CMFCRibbonGallery[58], CMFCRibbonGalleryIcon[58], CMFCRibbonLabel[58], CMFCRibbonLaunchButton[58], CMFCRibbonQuickAccessCustomizeButton[58], CMFCRibbonUndoButton[58], CRibbonCategoryScroll[58], CRibbonUndoLabel[58] */
/* 00867eec  FUN_00867eec  30 bytes, 0 callers */

undefined4 FUN_00867eec(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(int *)(in_ECX + 0xf0) != 0) ||
     ((-1 < *(int *)(in_ECX + 0x148) && (*(int *)(in_ECX + 0x144) < 0)))) {
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CMFCRibbonButton[149], CMFCRibbonCaptionButton[149], CMFCRibbonColorButton[149], CMFCRibbonColorMenuButton[149], CMFCRibbonDefaultPanelButton[149], CMFCRibbonEdit[149], CMFCRibbonGallery[149], CMFCRibbonGalleryIcon[149], CMFCRibbonLabel[149], CMFCRibbonLaunchButton[149], CMFCRibbonQuickAccessCustomizeButton[149], CMFCRibbonUndoButton[149], CRibbonCategoryScroll[149], CRibbonUndoLabel[149] */
/* 00867f0a  FUN_00867f0a  46 bytes, 0 callers */

undefined4 FUN_00867f0a(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (in_ECX[0x5e] != 0) {
    pcVar1 = *(code **)(*in_ECX + 0xd0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      uVar3 = 1;
    }
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonButton[150], CMFCRibbonCaptionButton[150], CMFCRibbonColorButton[150], CMFCRibbonColorMenuButton[150], CMFCRibbonDefaultPanelButton[150], CMFCRibbonEdit[150], CMFCRibbonGallery[150], CMFCRibbonGalleryIcon[150], CMFCRibbonLabel[150], CMFCRibbonLaunchButton[150], CMFCRibbonQuickAccessCustomizeButton[150], CMFCRibbonUndoButton[150], CRibbonCategoryScroll[150], CRibbonUndoLabel[150] */
/* 00867f38  FUN_00867f38  46 bytes, 0 callers */

undefined4 FUN_00867f38(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (in_ECX[0x5d] != 0) {
    pcVar1 = *(code **)(*in_ECX + 0xd0);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      uVar3 = 1;
    }
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonButton[87], CMFCRibbonCaptionButton[87], CMFCRibbonColorButton[87], CMFCRibbonColorMenuButton[87], CMFCRibbonDefaultPanelButton[87], CMFCRibbonEdit[87], CMFCRibbonGallery[87], CMFCRibbonGalleryIcon[87], CMFCRibbonLabel[87], CMFCRibbonLaunchButton[87], CMFCRibbonQuickAccessCustomizeButton[87], CMFCRibbonUndoButton[87], CRibbonCategoryScroll[87], CRibbonUndoLabel[87] */
/* 00867f66  FUN_00867f66  62 bytes, 0 callers */

void FUN_00867f66(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = FUN_00863dc7(1);
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x138);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x13c);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonButton[73], CMFCRibbonCaptionButton[73], CMFCRibbonColorMenuButton[73], CMFCRibbonDefaultPanelButton[73], CMFCRibbonGalleryIcon[73], CMFCRibbonLaunchButton[73], CMFCRibbonQuickAccessCustomizeButton[73], CRibbonCategoryScroll[73], CRibbonUndoLabel[73] */
/* 00867fa4  FUN_00867fa4  474 bytes, 2 callers */

void FUN_00867fa4(undefined4 param_1)

{
  double dVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00863fab(param_1);
  pcVar2 = *(code **)(*in_ECX + 0x250);
  guard_check_icall();
  iVar3 = (*pcVar2)();
  if (iVar3 != 0) {
    in_ECX[100] = 1;
    return;
  }
  in_ECX[100] = 0;
  if (in_ECX[0x31] != 0) {
    return;
  }
  if (in_ECX[0x30] != 0) {
    return;
  }
  pcVar2 = *(code **)(*in_ECX + 0x114);
  guard_check_icall(&local_c,0);
  (*pcVar2)();
  pcVar2 = *(code **)(*in_ECX + 0x114);
  guard_check_icall(&local_14,1);
  (*pcVar2)();
  if ((in_ECX[0x2e] == 0) && (in_ECX[0x2f] == 0)) {
    local_10 = 0;
    if (in_ECX[0x57] != 0) {
      iVar3 = 0x20;
      iVar4 = FUN_007c2511();
      if (*(int *)(iVar4 + 0x1e8) == 0) {
        dVar1 = 1.0;
      }
      else {
        dVar1 = *(double *)(iVar4 + 0x1e0);
      }
      iVar4 = iVar3;
      if (dVar1 != 1.0) {
        FUN_007c2511();
        iVar4 = thunk_FUN_008d99f0();
        FUN_007c2511();
        iVar3 = thunk_FUN_008d99f0();
      }
      if ((in_ECX[0x1f] - in_ECX[0x1d] < iVar4) || (in_ECX[0x20] - in_ECX[0x1e] < iVar3)) {
        local_10 = 1;
      }
      else {
        local_10 = 0;
      }
    }
    if ((local_c == 0) && (local_8 == 0)) goto LAB_0086812b;
  }
  else {
    in_ECX[100] = 0;
    if (((local_c == 0) && (local_8 == 0)) || (local_14 != 0)) goto LAB_0086812b;
  }
  if (local_10 == 0) {
    in_ECX[100] = 1;
  }
LAB_0086812b:
  if (in_ECX[100] == 0) {
    iVar3 = FUN_00420890(5,1);
    if (iVar3 == 0) {
      return;
    }
    local_1c = 3;
    local_18 = 3;
  }
  else {
    local_1c = 5;
    local_18 = 1;
  }
  pcVar2 = *(code **)(*in_ECX + 0x27c);
  guard_check_icall(&local_1c);
  (*pcVar2)();
  return;
}




/* vtable slots: CMFCRibbonButton[96], CMFCRibbonCaptionButton[96], CMFCRibbonColorButton[96], CMFCRibbonColorMenuButton[96], CMFCRibbonDefaultPanelButton[96], CMFCRibbonEdit[96], CMFCRibbonGallery[96], CMFCRibbonGalleryIcon[96], CMFCRibbonLaunchButton[96], CMFCRibbonQuickAccessCustomizeButton[96], CMFCRibbonUndoButton[96], CRibbonCategoryScroll[96], CRibbonUndoLabel[96] */
/* 0086817e  FUN_0086817e  632 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0086817e(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int *in_ECX;
  int iVar6;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int *local_2c;
  int local_28;
  int local_24 [3];
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x86818a;
  local_2c = param_1;
  if (*(int *)(in_ECX[0x18] + -0xc) != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x250);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      piVar5 = in_ECX + 0x43;
      iVar2 = FUN_004208d0(0,0);
      if ((iVar2 == 0) || (iVar2 = FUN_004208d0(0,0), iVar2 == 0)) {
        local_28 = FUN_004054a0(in_ECX[0x18] + -0x10);
        local_28 = local_28 + 0x10;
        local_8 = 0;
        FUN_005946a0(&DAT_0098dde8,&DAT_0098dde0);
        FUN_007fa476(0x26);
        FUN_005946a0(&DAT_0098dde0,&DAT_0095bc0c);
        if ((in_ECX[99] == 0) || (*(int *)(in_ECX[0x1c] + -0xc) == 0)) {
          piVar4 = (int *)FUN_00566800(local_24 + 2,&local_28);
          iVar2 = piVar4[1];
          *piVar5 = *piVar4;
          in_ECX[0x44] = iVar2;
        }
        else {
          pcVar1 = *(code **)(*local_2c + 0x28);
          iVar2 = FUN_007c2511();
          guard_check_icall(iVar2 + 300);
          local_30 = (*pcVar1)();
          piVar4 = local_2c;
          if (local_30 == 0) {
                    /* WARNING: Subroutine does not return */
            FUN_0078e714();
          }
          piVar3 = (int *)FUN_00566800(local_24 + 2,&local_28);
          iVar2 = piVar3[1];
          *piVar5 = *piVar3;
          in_ECX[0x44] = iVar2;
          pcVar1 = *(code **)(*piVar4 + 0x28);
          guard_check_icall(local_30);
          (*pcVar1)();
          local_30 = 0;
          local_18 = 0;
          ATL::CSimpleStringT<wchar_t,0>::operator=
                    ((CSimpleStringT<wchar_t,0> *)&local_28,
                     (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x1c));
          iVar2 = local_28;
          local_34 = *piVar5;
          iVar6 = local_18;
          if (local_34 < local_34 * 10) {
            do {
              local_24[0] = 0;
              local_24[1] = 0;
              local_18 = 10000;
              pcVar1 = *(code **)(*local_2c + 0x68);
              local_24[2] = local_34;
              guard_check_icall(iVar2,*(undefined4 *)(iVar2 + -0xc),local_24,0x410);
              local_30 = (*pcVar1)();
              iVar6 = local_24[2] - local_24[0];
              if (local_30 <= in_ECX[0x44] * 2) break;
              local_34 = local_34 + 10;
            } while (local_34 < in_ECX[0x43] * 10);
          }
          iVar2 = in_ECX[0x43];
          if (iVar2 <= iVar6) {
            iVar2 = iVar6;
          }
          in_ECX[0x43] = iVar2;
          iVar2 = in_ECX[0x44] * 2;
          if (local_30 <= iVar2) {
            iVar2 = local_30;
          }
          in_ECX[0x44] = in_ECX[0x44] + in_ECX[0x48] * 2 + iVar2;
        }
        pcVar1 = *(code **)(*in_ECX + 0x114);
        guard_check_icall(&local_3c,0);
        (*pcVar1)();
        if ((local_3c == 0) && (local_38 == 0)) {
          in_ECX[0x45] = 0;
          in_ECX[0x46] = 0;
        }
        else {
          piVar5 = (int *)FUN_00866368(local_24 + 2,local_2c,1);
          iVar2 = piVar5[1];
          in_ECX[0x45] = *piVar5;
          in_ECX[0x46] = iVar2;
        }
        FUN_00406b10();
      }
      goto LAB_008683e9;
    }
  }
  in_ECX[0x43] = 0;
  in_ECX[0x44] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x46] = 0;
LAB_008683e9:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonButton[153], CMFCRibbonCaptionButton[153], CMFCRibbonColorButton[153], CMFCRibbonColorMenuButton[153], CMFCRibbonEdit[153], CMFCRibbonGallery[153], CMFCRibbonLabel[153], CMFCRibbonQuickAccessCustomizeButton[153], CRibbonUndoLabel[153] */
/* 008683f7  FUN_008683f7  113 bytes, 1 callers */

void FUN_008683f7(void)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  int *in_ECX;
  
  iVar2 = FUN_00863d99();
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x138);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((iVar2 != 0) && (BVar3 = IsRectEmpty((RECT *)(in_ECX + 0x4d)), BVar3 != 0)) {
      return;
    }
  }
  if ((int *)in_ECX[0x25] == (int *)0x0) {
    FUN_00863dc7(0);
  }
  else {
    pcVar1 = *(code **)(*(int *)in_ECX[0x25] + 0x450);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCRibbonButton[95] */
/* 00868468  FUN_00868468  3511 bytes, 2 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00868468(int *param_1)

{
  RECT *lprc;
  double dVar1;
  code *pcVar2;
  BOOL BVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  CMFCRibbonBar *pCVar8;
  CMFCRibbonBaseElement *in_ECX;
  code *pcVar9;
  uint uVar10;
  CMFCRibbonBaseElement *pCVar11;
  CMFCRibbonBaseElement *pCVar12;
  undefined1 local_1a8 [8];
  undefined1 local_1a0 [8];
  undefined1 local_198 [8];
  undefined4 local_190;
  undefined4 local_18c;
  int local_188;
  int local_184;
  int local_180;
  int local_17c;
  int local_178;
  int local_174;
  int local_170;
  undefined4 local_16c;
  RECT *local_168;
  code *local_164;
  int local_160;
  int local_15c;
  undefined8 local_158;
  int local_150;
  int local_14c;
  int local_148;
  CMFCRibbonBaseElement *local_144;
  int *local_140;
  CMFCToolBarMenuButton local_13c [32];
  int local_11c;
  uint local_118;
  CSimpleStringT<wchar_t,0> local_110 [64];
  undefined4 local_d0;
  undefined4 local_ac;
  undefined4 local_a8;
  int local_90;
  tagRECT local_54;
  LONG local_44;
  LONG local_40;
  LONG local_3c;
  LONG LStack_38;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x198;
  local_8 = 0x868477;
  local_140 = param_1;
  local_168 = (RECT *)(in_ECX + 0x74);
  local_144 = in_ECX;
  BVar3 = IsRectEmpty(local_168);
  if (BVar3 != 0) goto LAB_00869212;
  if (((*(int *)(in_ECX + 0xec) != 0) && (*(int *)(in_ECX + 0xc4) == 0)) &&
     (*(int *)(in_ECX + 400) == 0)) {
    CMFCToolBarMenuButton::CMFCToolBarMenuButton(local_13c);
    local_8 = 0;
    ATL::CSimpleStringT<wchar_t,0>::operator=
              (local_110,(CSimpleStringT<wchar_t,0> *)(in_ECX + 0x60));
    local_11c = *(int *)(in_ECX + 0xa4);
    local_a8 = 1;
    pcVar2 = *(code **)(*(int *)in_ECX + 0xa4);
    guard_check_icall();
    local_d0 = (*pcVar2)();
    local_90 = *(int *)(in_ECX + 0xdc);
    pcVar2 = *(code **)(*(int *)in_ECX + 0xe0);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if (iVar4 != 0) {
      local_118 = local_118 | 0x10000;
    }
    pcVar2 = *(code **)(*(int *)in_ECX + 0x138);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if (iVar4 != 0) {
      local_ac = 1;
    }
    local_170 = *(int *)(in_ECX + 200);
    pcVar2 = *(code **)(*(int *)in_ECX + 0xdc);
    guard_check_icall();
    iVar5 = (*pcVar2)();
    iVar4 = local_170;
    if (iVar5 != 0) {
      local_118 = local_118 | 0x40000;
      pcVar2 = *(code **)(*(int *)in_ECX + 0xd4);
      guard_check_icall();
      iVar4 = (*pcVar2)();
    }
    if ((iVar4 != 0) || (uVar6 = 0, *(int *)(in_ECX + 0xcc) != 0)) {
      uVar6 = 1;
    }
    FUN_00877450(local_140,in_ECX + 0x74,0,1,0,uVar6,1,1);
    FUN_00874eb0();
    goto LAB_00869212;
  }
  local_170 = *(int *)(in_ECX + 0xd4);
  local_174 = *(int *)(in_ECX + 0xe0);
  local_178 = *(int *)(in_ECX + 200);
  local_17c = *(int *)(in_ECX + 0x174);
  local_180 = *(int *)(in_ECX + 0x178);
  pcVar2 = *(code **)(*(int *)in_ECX + 0x240);
  guard_check_icall();
  local_15c = (*pcVar2)();
  if (*(int *)(in_ECX + 0xd4) != 0) {
    pcVar2 = *(code **)(*(int *)in_ECX + 0x138);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if (iVar4 != 0) {
      if ((*(int *)(in_ECX + 0x168) == 0) &&
         ((*(int *)(in_ECX + 0xa4) == 0 || (*(int *)(in_ECX + 0xa4) == -1)))) {
        *(int *)(in_ECX + 0xd4) = 0;
      }
      else {
        *(int *)(in_ECX + 200) = 0;
      }
    }
  }
  if (*(int *)(in_ECX + 0x188) != 0) {
    *(int *)(in_ECX + 0xe0) = 0;
  }
  if (*(int *)(in_ECX + 0xcc) != 0) {
    *(int *)(in_ECX + 200) = 1;
    *(int *)(in_ECX + 0x174) = 1;
    *(int *)(in_ECX + 0x178) = 1;
  }
  local_34.left = 0;
  local_34.top = 0;
  local_34.right = 0;
  local_34.bottom = 0;
  SetRectEmpty(&local_34);
  pcVar2 = *(code **)(*(int *)in_ECX + 0x138);
  guard_check_icall();
  iVar4 = (*pcVar2)();
  if (iVar4 != 0) {
    local_34.top = local_168->top;
    local_34.right = local_168->right;
    local_34.left = (local_34.right - *(int *)(local_144 + 0x14c)) - local_15c;
    if ((*(int *)(local_144 + 0x10c) == 0) && (*(int *)(local_144 + 0xc4) == 0)) {
      local_34.left = local_34.left + -2;
    }
    local_34.bottom = local_168->bottom - *(int *)(local_144 + 0x14c);
    in_ECX = local_144;
    if (*(int *)(local_144 + 0x168) != 0) {
      *(LONG *)(local_144 + 0x124) = local_168->left;
      *(LONG *)(local_144 + 0x128) = local_168->top;
      *(LONG *)(local_144 + 300) = local_168->right;
      *(LONG *)(local_144 + 0x130) = local_168->bottom;
      *(int *)(local_144 + 0x134) = *(int *)(local_144 + 0x74);
      iVar4 = ((*(int *)(local_144 + 300) - *(int *)(local_144 + 0x14c)) - local_15c) + -1;
      *(int *)(local_144 + 0x124) = iVar4;
      *(int *)(local_144 + 0x138) = *(int *)(local_144 + 0x78);
      *(int *)(local_144 + 0x13c) = *(int *)(local_144 + 0x7c);
      *(int *)(local_144 + 0x140) = *(int *)(local_144 + 0x80);
      *(int *)(local_144 + 0x170) = 0;
      *(int *)(local_144 + 0x13c) = iVar4;
    }
  }
  pcVar2 = *(code **)(*(int *)in_ECX + 0x114);
  guard_check_icall(&local_188,0);
  (*pcVar2)();
  pcVar2 = *(code **)(*(int *)in_ECX + 0x114);
  guard_check_icall(local_1a0,1);
  (*pcVar2)();
  pCVar12 = local_144;
  local_44 = *(LONG *)(in_ECX + 0x74);
  local_40 = *(LONG *)(in_ECX + 0x78);
  local_3c = *(LONG *)(in_ECX + 0x7c);
  LStack_38 = *(LONG *)(in_ECX + 0x80);
  pcVar2 = *(code **)(*(int *)local_144 + 0x250);
  guard_check_icall();
  iVar4 = (*pcVar2)();
  if ((iVar4 == 0) && (*(int *)(pCVar12 + 0xc4) == 0)) {
    if (*(int *)(pCVar12 + 0xc0) == 0) {
      local_150 = 1;
    }
    else {
LAB_00868803:
      local_150 = 0;
      if (*(int *)(pCVar12 + 0xc0) != 0) goto LAB_0086887a;
    }
    if (*(int *)(pCVar12 + 0xb8) != 0) goto LAB_0086887a;
    if ((((local_188 != 0) || (local_184 != 0)) && (*(int *)(pCVar12 + 0x170) == 0)) &&
       (*(int *)(pCVar12 + 400) != 0)) {
      lprc = (RECT *)(pCVar12 + 0x124);
      BVar3 = IsRectEmpty(lprc);
      if (BVar3 == 0) {
        iVar4 = lprc->left - local_15c;
        lprc->left = iVar4;
        *(int *)(pCVar12 + 0x13c) = iVar4;
      }
      OffsetRect(&local_34,-(local_15c / 2),0);
    }
  }
  else {
    if (*(int *)(pCVar12 + 0xc4) == 0) goto LAB_00868803;
LAB_0086887a:
    local_150 = 0;
  }
  pcVar9 = (code *)(uint)(*(int *)(pCVar12 + 400) == 0);
  piVar7 = &local_14c;
  pcVar2 = *(code **)(*(int *)pCVar12 + 0x114);
  local_164 = pcVar9;
  guard_check_icall(piVar7,pcVar9);
  (*pcVar2)();
  local_160 = 0;
  if (((*(int *)(pCVar12 + 0xc4) != 0) || (*(int *)(pCVar12 + 0xc0) != 0)) &&
     ((local_14c == 0 && (local_148 == 0)))) {
    local_14c = 0x10;
    local_148 = 0x10;
    iVar4 = FUN_007c2511();
    if (*(int *)(iVar4 + 0x1e8) == 0) {
      dVar1 = 1.0;
    }
    else {
      dVar1 = *(double *)(iVar4 + 0x1e0);
    }
    if (dVar1 != 1.0) {
      FUN_007c2511();
      local_158 = (double)local_14c;
      local_14c = thunk_FUN_008d99f0();
      FUN_007c2511();
      local_158 = (double)local_148;
      local_148 = thunk_FUN_008d99f0();
    }
    local_160 = 1;
  }
  pCVar11 = local_144;
  local_24.left = *(LONG *)(pCVar12 + 0x74);
  local_24.top = *(LONG *)(pCVar12 + 0x78);
  local_24.right = *(LONG *)(pCVar12 + 0x7c);
  local_24.bottom = *(LONG *)(pCVar12 + 0x80);
  InflateRect(&local_24,-*(int *)(local_144 + 0x11c),-*(int *)(local_144 + 0x120));
  pcVar2 = *(code **)(*(int *)pCVar11 + 0x250);
  guard_check_icall(piVar7,pcVar9);
  iVar4 = (*pcVar2)();
  if (iVar4 == 0) {
    if ((*(int *)(pCVar11 + 400) != 0) && (*(int *)(pCVar11 + 0xb0) == 0)) {
      local_24.top = local_24.top + 1 + *(int *)(pCVar11 + 0x120);
      local_24.left = (local_24.right + local_24.left) / 2 - local_14c / 2;
      if (local_150 != 0) goto LAB_00868b37;
    }
    local_24.top = (local_24.bottom + local_24.top) / 2 - local_148 / 2;
  }
  else {
    iVar4 = FUN_007c2511();
    if (*(int *)(iVar4 + 0x1e8) == 0) {
      dVar1 = 1.0;
    }
    else {
      dVar1 = *(double *)(iVar4 + 0x1e0);
    }
    if (dVar1 != 1.0) {
      FUN_007c2511();
      local_158 = (double)local_14c;
      local_14c = thunk_FUN_008d99f0();
      FUN_007c2511();
      local_158 = (double)local_148;
      local_148 = thunk_FUN_008d99f0();
    }
    local_24.left = local_24.left + ((local_24.right - local_24.left) - local_14c) / 2;
    local_24.top = local_24.top + ((local_24.bottom - local_24.top) - local_148) / 2;
    iVar4 = FUN_007c2574();
    OffsetRect(&local_24,*(int *)(iVar4 + 0xac),*(int *)(iVar4 + 0xb0));
  }
LAB_00868b37:
  local_24.right = local_24.left + local_14c;
  local_24.bottom = local_148 + local_24.top;
  if ((*(int *)(pCVar11 + 400) != 0) && (*(int *)(pCVar11 + 0xb0) == 0)) {
    pcVar2 = *(code **)(*(int *)pCVar11 + 0x138);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if ((iVar4 != 0) && (*(int *)(pCVar11 + 0x168) != 0)) {
      *(LONG *)(pCVar11 + 0x124) = local_168->left;
      *(LONG *)(pCVar11 + 0x128) = local_168->top;
      *(LONG *)(pCVar11 + 300) = local_168->right;
      *(LONG *)(pCVar11 + 0x130) = local_168->bottom;
      *(LONG *)(local_144 + 0x128) = local_24.bottom + 3;
      *(LONG *)(local_144 + 0x134) = local_168->left;
      *(LONG *)(local_144 + 0x138) = local_168->top;
      *(LONG *)(local_144 + 0x13c) = local_168->right;
      *(LONG *)(local_144 + 0x140) = local_168->bottom;
      *(LONG *)(local_144 + 0x140) = local_24.bottom + 3;
      *(int *)(local_144 + 0x170) = 1;
      pCVar11 = local_144;
    }
  }
  local_15c = -1;
  pcVar2 = *(code **)(*(int *)pCVar11 + 0x250);
  guard_check_icall();
  iVar4 = (*pcVar2)();
  if (iVar4 == 0) {
    pcVar2 = *(code **)(*(int *)pCVar11 + 0x270);
    guard_check_icall(local_140);
    local_15c = (*pcVar2)();
  }
  iVar4 = FUN_00863d99();
  if (iVar4 != 0) {
    pcVar2 = *(code **)(*(int *)pCVar11 + 0xe0);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if ((iVar4 != 0) && ((local_14c != 0 || (local_148 != 0)))) {
      piVar7 = (int *)FUN_007c2574();
      pCVar11 = local_144;
      local_158 = (double)CONCAT44(piVar7,(undefined4)local_158);
      pcVar2 = *(code **)(*piVar7 + 0x244);
      guard_check_icall(local_140,local_144,local_24.left,local_24.top,local_24.right,
                        local_24.bottom);
      (*pcVar2)();
    }
  }
  if (local_160 == 0) {
    iVar4 = FUN_007c2511();
    local_158 = (double)CONCAT44(*(undefined4 *)(iVar4 + 0x1e8),(undefined4)local_158);
    iVar4 = FUN_00863d99();
    if (((iVar4 != 0) && (*(int *)(pCVar11 + 400) == 0)) &&
       ((*(int *)(pCVar11 + 0x94) == 0 || (iVar4 = FUN_0082f53f(), iVar4 == 0)))) {
      iVar4 = FUN_007c2511();
      *(undefined4 *)(iVar4 + 0x1e8) = 0;
    }
    pcVar2 = *(code **)(*(int *)pCVar11 + 0x120);
    guard_check_icall(local_140,local_164,local_24.left,local_24.top,local_24.right,local_24.bottom)
    ;
    (*pcVar2)();
    iVar4 = FUN_007c2511();
    *(int *)(iVar4 + 0x1e8) = local_158._4_4_;
  }
  else {
    piVar7 = (int *)FUN_007c2574();
    local_158 = (double)CONCAT44(piVar7,(undefined4)local_158);
    pcVar2 = *(code **)(*piVar7 + 0x268);
    guard_check_icall(local_140,local_24.left,local_24.top,local_24.right,local_24.bottom,
                      *(int *)(pCVar11 + 0xd4),*(int *)(pCVar11 + 0xd0),*(int *)(pCVar11 + 200));
    (*pcVar2)();
  }
  piVar7 = local_140;
  if (local_150 != 0) {
    local_158 = (double)((ulonglong)local_158 & 0xffffffff);
    local_150 = -1;
    local_44 = local_168->left;
    local_40 = local_168->top;
    local_3c = local_168->right;
    LStack_38 = local_168->bottom;
    if ((local_170 == 0) ||
       ((*(int *)(local_144 + 0x168) == 0 &&
        ((*(int *)(local_144 + 0xa4) == 0 || (*(int *)(local_144 + 0xa4) == -1)))))) {
      if (local_15c != -1) {
        pcVar2 = *(code **)(*local_140 + 0x30);
        guard_check_icall(local_15c);
        local_150 = (*pcVar2)();
      }
    }
    else if (*(int *)(local_144 + 0xc4) == 0) {
      local_164 = *(code **)(*local_140 + 0x30);
      iVar4 = local_15c;
      if (local_15c == -1) {
        piVar7 = (int *)FUN_007c2574();
        pcVar2 = *(code **)(*piVar7 + 0xc4);
        guard_check_icall();
        iVar4 = (*pcVar2)();
      }
      piVar7 = local_140;
      pcVar2 = local_164;
      guard_check_icall(iVar4);
      local_150 = (*pcVar2)();
    }
    else {
      piVar7 = (int *)FUN_007c2574();
      pcVar2 = *(code **)(*piVar7 + 0x25c);
      guard_check_icall(1);
      (*pcVar2)();
      piVar7 = local_140;
    }
    pCVar12 = local_144;
    if ((*(int *)(local_144 + 400) == 0) || (*(int *)(local_144 + 0xb0) != 0)) {
      local_44 = local_24.right;
      if (*(int *)(local_144 + 0xac) < 1) {
        if (local_14c != 0) {
          pcVar2 = *(code **)(*(int *)local_144 + 0x278);
          guard_check_icall();
          iVar4 = (*pcVar2)();
          local_44 = local_44 + iVar4;
        }
      }
      else {
        local_44 = *(int *)(local_144 + 0x11c) * 3 + *(int *)(local_144 + 0xac) + local_168->left;
      }
      local_160 = 0x8020;
      if ((*(int *)(pCVar12 + 0x18c) == 0) || (*(int *)(*(int *)(pCVar12 + 0x70) + -0xc) == 0)) {
        local_160 = 0x8024;
      }
      else {
        pcVar2 = *(code **)(*local_140 + 0x28);
        iVar4 = FUN_007c2511();
        guard_check_icall(iVar4 + 300);
        iVar4 = (*pcVar2)();
        local_158 = (double)CONCAT44(iVar4,(undefined4)local_158);
        if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        iVar4 = ((*(int *)(pCVar12 + 0x80) - *(int *)(pCVar12 + 0x110)) - *(int *)(pCVar12 + 0x78))
                / 2;
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        local_40 = local_40 + iVar4;
      }
      piVar7 = local_140;
      pCVar11 = local_144;
      local_164 = *(code **)(*(int *)pCVar12 + 0x260);
      guard_check_icall(local_140,local_144 + 0x60,local_44,local_40,local_3c,LStack_38,local_160,
                        0xffffffff);
      local_160 = (*local_164)();
      if (local_158._4_4_ != 0) {
        pcVar2 = *(code **)(*piVar7 + 0x28);
        guard_check_icall(local_158._4_4_);
        (*pcVar2)();
        piVar7 = local_140;
      }
      if ((*(int *)(pCVar11 + 0x18c) != 0) && (*(int *)(*(int *)(pCVar11 + 0x70) + -0xc) != 0)) {
        local_40 = local_40 + *(int *)(pCVar11 + 0x120) + local_160;
        local_3c = *(int *)(pCVar11 + 0x7c) - *(int *)(pCVar11 + 0x11c);
        FUN_007c2378(pCVar11 + 0x70,&local_44,0x8010);
      }
      if ((local_160 == *(int *)(pCVar11 + 0x110)) && (*(int *)(pCVar11 + 400) != 0)) {
        pcVar2 = *(code **)(*(int *)pCVar11 + 0x138);
        guard_check_icall();
        iVar4 = (*pcVar2)();
        if (iVar4 != 0) {
          local_34.left = local_168->left;
          local_34.top = local_168->top;
          local_34.right = local_168->right;
          local_34.bottom = local_168->bottom;
          InflateRect(&local_34,-*(int *)(local_144 + 0x14c),*(int *)(local_144 + 0x14c) * -2);
          local_34.right = local_34.right + -2;
          iVar4 = FUN_0081507c(local_198);
          local_34.top = local_34.bottom - *(int *)(iVar4 + 4);
          iVar4 = FUN_0081507c(local_1a8);
          local_34.bottom = *(int *)(iVar4 + 4) + local_34.top;
          piVar7 = local_140;
        }
      }
    }
    else {
      FUN_00866368(local_198,piVar7,0);
      SetRectEmpty(&local_34);
    }
    if (local_150 != -1) {
      pcVar2 = *(code **)(*piVar7 + 0x30);
      guard_check_icall(local_150);
      (*pcVar2)();
    }
  }
  pCVar12 = local_144;
  pcVar2 = *(code **)(*(int *)local_144 + 0x250);
  guard_check_icall();
  iVar4 = (*pcVar2)();
  if (iVar4 == 0) {
    BVar3 = IsRectEmpty(&local_34);
    if (BVar3 == 0) {
      local_158 = (double)((ulonglong)local_158 & 0xffffffff);
      iVar4 = FUN_00863d99();
      if (iVar4 != 0) {
        uVar10 = 0;
        pCVar8 = CMFCRibbonBaseElement::GetTopLevelRibbonBar(pCVar12);
        if ((pCVar8 != (CMFCRibbonBar *)0x0) && (*(int *)(pCVar8 + 0x20) != 0)) {
          uVar10 = FUN_00797acc();
          uVar10 = uVar10 & 0x400000;
        }
        local_158 = (double)CONCAT44((-(uint)(uVar10 != 0) & 3) + 0xe,(undefined4)local_158);
      }
      local_54.left = local_34.left;
      local_54.top = local_34.top;
      local_54.right = local_34.right;
      local_54.bottom = local_34.bottom;
      OffsetRect(&local_54,0,1);
      uVar6 = local_158._4_4_;
      local_16c = 0;
      local_168 = (RECT *)0x0;
      FUN_00814d1c(local_140,local_158._4_4_,&local_54,3,&local_16c);
      local_190 = 0;
      local_18c = 0;
      FUN_00814d1c(local_140,uVar6,&local_34,*(int *)(local_144 + 0xd4) != 0,&local_190);
      pCVar12 = local_144;
    }
    pcVar2 = *(code **)(*(int *)pCVar12 + 0x274);
    guard_check_icall(local_140);
    (*pcVar2)();
  }
  *(int *)(pCVar12 + 0xd4) = local_170;
  *(int *)(pCVar12 + 0xe0) = local_174;
  *(int *)(pCVar12 + 200) = local_178;
  *(int *)(pCVar12 + 0x174) = local_17c;
  *(int *)(pCVar12 + 0x178) = local_180;
LAB_00869212:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonButton[157], CMFCRibbonCaptionButton[157], CMFCRibbonColorButton[157], CMFCRibbonColorMenuButton[157], CMFCRibbonDefaultPanelButton[157], CMFCRibbonEdit[157], CMFCRibbonGallery[157], CMFCRibbonGalleryIcon[157], CMFCRibbonLabel[157], CMFCRibbonLaunchButton[157], CMFCRibbonQuickAccessCustomizeButton[157], CMFCRibbonUndoButton[157], CRibbonCategoryScroll[157], CRibbonUndoLabel[157] */
/* 00869220  FUN_00869220  100 bytes, 0 callers */

void FUN_00869220(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar1 = in_ECX[0x35];
  if (iVar1 != 0) {
    pcVar2 = *(code **)(*in_ECX + 0x138);
    guard_check_icall();
    iVar3 = (*pcVar2)();
    if (iVar3 != 0) {
      in_ECX[0x35] = 0;
    }
  }
  piVar4 = (int *)FUN_007c2574();
  pcVar2 = *(code **)(*piVar4 + 0x240);
  guard_check_icall(param_1);
  (*pcVar2)();
  in_ECX[0x35] = iVar1;
  return;
}




/* vtable slots: CMFCRibbonButton[94], CMFCRibbonCaptionButton[94], CMFCRibbonColorButton[94], CMFCRibbonColorMenuButton[94], CMFCRibbonGallery[94], CMFCRibbonGalleryIcon[94], CMFCRibbonLabel[94], CMFCRibbonLaunchButton[94], CMFCRibbonQuickAccessCustomizeButton[94], CMFCRibbonUndoButton[94], CRibbonCategoryScroll[94], CRibbonUndoLabel[94] */
/* 00869284  FUN_00869284  584 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00869284(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,undefined4 param_8,int param_9)

{
  double dVar1;
  code *pcVar2;
  byte bVar3;
  int iVar4;
  DWORD DVar5;
  int *in_ECX;
  int *piVar6;
  int *piVar7;
  undefined4 uVar8;
  int local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  int *local_60;
  int *local_5c;
  int *local_58;
  tagRECT local_54;
  int local_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_58 = param_1;
  local_68 = in_ECX[0x35];
  in_ECX[0x35] = 0;
  local_8 = 0;
  local_24.left = param_4;
  local_24.right = param_4 + param_3;
  local_24.top = param_5;
  uVar8 = 1;
  local_24.bottom = param_7;
  piVar7 = &local_70;
  pcVar2 = *(code **)(*in_ECX + 0x114);
  local_5c = in_ECX;
  guard_check_icall(piVar7,1);
  piVar6 = local_5c;
  (*pcVar2)();
  if ((local_70 == 0) && (local_6c == 0)) {
    if (piVar6[0x3d] != 0) {
      local_60 = (int *)FUN_007c2574();
      pcVar2 = *(code **)(*local_60 + 0x268);
      guard_check_icall(local_58,local_24.left,local_24.top,local_24.right,local_24.bottom,0,0,0);
      (*pcVar2)();
    }
  }
  else {
    InflateRect(&local_24,-1,0);
    iVar4 = ((local_24.bottom - local_24.top) - local_6c) / 2;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    local_24.top = local_24.top + iVar4;
    local_24.bottom = local_24.top + local_6c;
    pcVar2 = *(code **)(*piVar6 + 0x120);
    guard_check_icall(local_58,1,local_24.left,local_24.top,local_24.right,local_24.bottom);
    (*pcVar2)();
  }
  piVar6 = local_5c;
  local_34.left = param_4;
  local_34.top = param_5;
  local_34.right = param_6;
  local_34.bottom = param_7;
  pcVar2 = *(code **)(*local_5c + 0x138);
  guard_check_icall(piVar7,uVar8);
  iVar4 = (*pcVar2)();
  if (iVar4 != 0) {
    local_54.left = (param_6 - param_7) + param_5;
    iStack_40 = param_5;
    iStack_3c = param_6;
    iStack_38 = param_7;
    local_54.top = param_5;
    local_54.right = param_6;
    local_54.bottom = param_7;
    local_44 = local_54.left;
    OffsetRect(&local_54,0,1);
    bVar3 = 1;
    uVar8 = 0xe;
    if (param_9 != 0) {
      DVar5 = GetSysColor(0xe);
      if ((0x80 < (byte)DVar5) && (0x80 < (byte)(DVar5 >> 8))) {
        bVar3 = ~(0x80 < (byte)(DVar5 >> 0x10)) & 1;
      }
    }
    iVar4 = FUN_007c2511();
    if (*(int *)(iVar4 + 0x1e8) == 0) {
      dVar1 = 1.0;
    }
    else {
      dVar1 = *(double *)(iVar4 + 0x1e0);
    }
    if (dVar1 <= 1.0) {
      uVar8 = 1;
    }
    local_64 = 0;
    local_60 = (int *)0x0;
    FUN_00814d1c(local_58,uVar8,&local_54,-bVar3 & 3,&local_64);
    local_64 = 0;
    local_60 = (int *)0x0;
    FUN_00814d1c(local_58,uVar8,&local_44,(-(uint)bVar3 & 0xfffffffd) + 3,&local_64);
    local_34.right = local_44;
    piVar6 = local_5c;
  }
  local_34.left = local_34.left + param_3;
  InflateRect(&local_34,-3,0);
  pcVar2 = *(code **)(*local_58 + 0x68);
  guard_check_icall(param_2,*(undefined4 *)(param_2 + -0xc),&local_34,0x824);
  (*pcVar2)();
  piVar6[0x35] = local_68;
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonButton[156], CMFCRibbonCaptionButton[156], CMFCRibbonColorButton[156], CMFCRibbonColorMenuButton[156], CMFCRibbonDefaultPanelButton[156], CMFCRibbonEdit[156], CMFCRibbonGallery[156], CMFCRibbonGalleryIcon[156], CMFCRibbonLabel[156], CMFCRibbonLaunchButton[156], CMFCRibbonQuickAccessCustomizeButton[156], CMFCRibbonUndoButton[156], CRibbonCategoryScroll[156], CRibbonUndoLabel[156] */
/* 008694cc  FUN_008694cc  100 bytes, 0 callers */

void FUN_008694cc(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar1 = in_ECX[0x35];
  if (iVar1 != 0) {
    pcVar2 = *(code **)(*in_ECX + 0x138);
    guard_check_icall();
    iVar3 = (*pcVar2)();
    if (iVar3 != 0) {
      in_ECX[0x35] = 0;
    }
  }
  piVar4 = (int *)FUN_007c2574();
  pcVar2 = *(code **)(*piVar4 + 0x238);
  guard_check_icall(param_1);
  (*pcVar2)();
  in_ECX[0x35] = iVar1;
  return;
}




/* vtable slots: CMFCRibbonButton[119], CMFCRibbonCaptionButton[119], CMFCRibbonColorMenuButton[119], CMFCRibbonGalleryIcon[119], CMFCRibbonLabel[119], CMFCRibbonLaunchButton[119], CRibbonCategoryScroll[119], CRibbonUndoLabel[119] */
/* 00869530  FUN_00869530  325 bytes, 1 callers */

uint FUN_00869530(int param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  BOOL BVar4;
  CMFCRibbonBar *this;
  CMFCRibbonBaseElement *in_ECX;
  
  pcVar1 = *(code **)(*(int *)in_ECX + 0xdc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    BVar4 = IsRectEmpty((RECT *)(in_ECX + 0x74));
    if (BVar4 == 0) {
      this = CMFCRibbonBaseElement::GetTopLevelRibbonBar(in_ECX);
      pcVar1 = *(code **)(*(int *)in_ECX + 0x138);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if ((iVar2 == 0) || ((param_1 == 0 && (*(int *)(*(int *)(in_ECX + 0x68) + -0xc) != 0)))) {
        if ((this != (CMFCRibbonBar *)0x0) && (iVar2 = FUN_00792b4c(), iVar2 != 0)) {
          FUN_00792b4c();
          FUN_00797df8();
        }
        pcVar1 = *(code **)(*(int *)in_ECX + 0x264);
        guard_check_icall(*(undefined4 *)(in_ECX + 0x74),*(undefined4 *)(in_ECX + 0x78));
        (*pcVar1)();
      }
      else {
        pcVar1 = *(code **)(*(int *)in_ECX + 0xe4);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 == 0) {
          if (this != (CMFCRibbonBar *)0x0) {
            CMFCRibbonBar::HideKeyTips(this);
          }
          pcVar1 = *(code **)(*(int *)in_ECX + 0x130);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          if (iVar2 != 0) {
            FUN_00870c84(in_ECX);
          }
          pcVar1 = *(code **)(*(int *)in_ECX + 0x13c);
          guard_check_icall();
          (*pcVar1)();
          if (*(int *)(in_ECX + 0x9c) != 0) {
            SendMessageW(*(HWND *)(*(int *)(in_ECX + 0x9c) + 0x20),0x100,0x24,0);
          }
          return (uint)(*(int *)(in_ECX + 0x158) != 0);
        }
      }
      uVar3 = 1;
    }
    else {
      uVar3 = FUN_00864399(param_1);
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonButton[132], CMFCRibbonCaptionButton[132], CMFCRibbonColorButton[132], CMFCRibbonColorMenuButton[132], CMFCRibbonGallery[132], CMFCRibbonLabel[132], CMFCRibbonLaunchButton[132], CMFCRibbonUndoButton[132], CRibbonCategoryScroll[132], CRibbonUndoLabel[132] */
/* 00869675  FUN_00869675  156 bytes, 1 callers */

void FUN_00869675(LONG param_1,LONG param_2)

{
  code *pcVar1;
  POINT pt;
  int iVar2;
  BOOL BVar3;
  int *in_ECX;
  
  FUN_008644c5(param_1,param_2);
  pcVar1 = *(code **)(*in_ECX + 0x138);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if ((iVar2 != 0) && (iVar2 = FUN_00863d99(), iVar2 == 0)) {
    BVar3 = IsRectEmpty((RECT *)(in_ECX + 0x49));
    if ((BVar3 == 0) &&
       (pt.y = param_2, pt.x = param_1, BVar3 = PtInRect((RECT *)(in_ECX + 0x49),pt), BVar3 == 0)) {
      return;
    }
    if ((in_ECX[0x5a] == 0) || (in_ECX[0x35] == 0)) {
      if ((in_ECX[0x35] != 0) && (BVar3 = IsRectEmpty((RECT *)(in_ECX + 0x4d)), BVar3 != 0)) {
        return;
      }
      pcVar1 = *(code **)(*in_ECX + 0x13c);
      guard_check_icall();
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonButton[133], CMFCRibbonColorButton[133], CMFCRibbonColorMenuButton[133], CMFCRibbonDefaultPanelButton[133], CMFCRibbonGallery[133], CMFCRibbonGalleryIcon[133], CMFCRibbonLaunchButton[133], CMFCRibbonQuickAccessCustomizeButton[133], CMFCRibbonUndoButton[133], CRibbonCategoryScroll[133], CRibbonUndoLabel[133] */
/* 00869711  FUN_00869711  165 bytes, 0 callers */

void FUN_00869711(LONG param_1,LONG param_2)

{
  RECT *lprc;
  code *pcVar1;
  POINT pt;
  POINT pt_00;
  bool bVar2;
  int iVar3;
  BOOL BVar4;
  int *in_ECX;
  
  if ((in_ECX[0x34] == 0) && (iVar3 = FUN_00863d99(), iVar3 == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (in_ECX[0x35] != 0) {
    return;
  }
  if (!bVar2) {
    return;
  }
  if (in_ECX[0x32] == 0) {
    return;
  }
  lprc = (RECT *)(in_ECX + 0x4d);
  if (in_ECX[0x38] == 0) {
    BVar4 = IsRectEmpty(lprc);
    if (BVar4 != 0) goto LAB_00869795;
    pt_00.y = param_2;
    pt_00.x = param_1;
    iVar3 = PtInRect(lprc,pt_00);
  }
  else {
    BVar4 = IsRectEmpty(lprc);
    if (BVar4 != 0) {
      return;
    }
    pt.y = param_2;
    pt.x = param_1;
    BVar4 = PtInRect(lprc,pt);
    if (BVar4 == 0) {
      return;
    }
    iVar3 = FUN_00863d99();
  }
  if (iVar3 == 0) {
    return;
  }
LAB_00869795:
  pcVar1 = *(code **)(*in_ECX + 0x264);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCRibbonButton[134], CMFCRibbonCaptionButton[134], CMFCRibbonColorButton[134], CMFCRibbonColorMenuButton[134], CMFCRibbonDefaultPanelButton[134], CMFCRibbonEdit[134], CMFCRibbonGallery[134], CMFCRibbonGalleryIcon[134], CMFCRibbonLabel[134], CMFCRibbonLaunchButton[134], CMFCRibbonQuickAccessCustomizeButton[134], CMFCRibbonUndoButton[134], CRibbonUndoLabel[134] */
/* 008697b6  FUN_008697b6  187 bytes, 0 callers */

void FUN_008697b6(LONG param_1,LONG param_2)

{
  code *pcVar1;
  int iVar2;
  POINT pt;
  POINT pt_00;
  int iVar3;
  BOOL BVar4;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x138);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (((iVar3 != 0) && (in_ECX[0x29] != -1)) && (in_ECX[0x29] != 0)) {
    iVar3 = in_ECX[0x5d];
    iVar2 = in_ECX[0x5e];
    pt.y = param_2;
    pt.x = param_1;
    BVar4 = PtInRect((RECT *)(in_ECX + 0x49),pt);
    in_ECX[0x5d] = BVar4;
    pt_00.y = param_2;
    pt_00.x = param_1;
    BVar4 = PtInRect((RECT *)(in_ECX + 0x4d),pt_00);
    in_ECX[0x5e] = BVar4;
    if ((iVar3 != in_ECX[0x5d]) || (iVar2 != BVar4)) {
      pcVar1 = *(code **)(*in_ECX + 0x1b8);
      guard_check_icall();
      (*pcVar1)();
      if ((int *)in_ECX[0x25] != (int *)0x0) {
        pcVar1 = *(code **)(*(int *)in_ECX[0x25] + 0x454);
        guard_check_icall();
        (*pcVar1)();
      }
    }
  }
  return;
}




/* vtable slots: CMFCRibbonButton[79], CMFCRibbonCaptionButton[79], CMFCRibbonColorMenuButton[79], CMFCRibbonEdit[79], CMFCRibbonGalleryIcon[79], CMFCRibbonLabel[79], CMFCRibbonLaunchButton[79], CRibbonCategoryScroll[79], CRibbonUndoLabel[79] */
/* 00869871  FUN_00869871  989 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00869871(void)

{
  code *pcVar1;
  int iVar2;
  CMFCRibbonBar *pCVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  CMFCRibbonPanelMenu *this;
  uint uVar7;
  int *piVar8;
  int iVar9;
  HWND pHVar10;
  CWnd *pCVar11;
  CMFCRibbonBaseElement *in_ECX;
  undefined4 local_5c;
  int local_50;
  int local_4c;
  int *local_48;
  int local_44;
  undefined4 uStack_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x86987d;
  pcVar1 = *(code **)(*(int *)in_ECX + 0xe4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0xa4);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if ((((iVar2 != 0) && (*(int *)(iVar2 + 0x20) != 0)) &&
        (pCVar3 = CMFCRibbonBaseElement::GetTopLevelRibbonBar(in_ECX),
        pCVar3 != (CMFCRibbonBar *)0x0)) && (*(int *)(pCVar3 + 0x20) != 0)) {
      CMFCRibbonBaseElement::OnShowPopupMenu(in_ECX);
      uVar4 = FUN_00797acc();
      uVar4 = uVar4 & 0x400000;
      local_5c = FUN_00792a04(0,0);
      iVar5 = FUN_0079296c();
      if (iVar5 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(iVar5 + 0x20);
      }
      iVar6 = FUN_00404c80();
      iVar9 = 0;
      if (iVar6 != 0) {
        iVar9 = *(int *)(iVar6 + 0x20);
      }
      if (iVar5 != iVar9) {
        local_5c = FUN_0079296c();
      }
      if (*(int *)(in_ECX + 0x1b8) < 1) {
        iVar5 = *(int *)(in_ECX + 0x158);
        if (iVar5 == 0) goto LAB_00869c48;
        local_44 = *(int *)(in_ECX + 0x74);
        uStack_40 = *(undefined4 *)(in_ECX + 0x78);
        local_3c = *(int *)(in_ECX + 0x7c);
        local_38 = *(int *)(in_ECX + 0x80);
        FUN_0079e8b8(&local_44);
        iVar9 = FUN_0078e624(0x1178);
        local_8 = 1;
        if (iVar9 == 0) {
          local_48 = (int *)0x0;
        }
        else {
          local_48 = (int *)FUN_0081b772();
        }
        iVar9 = 1;
        local_8 = 0xffffffff;
        local_48[0x3ce] = 0;
        if ((*(int *)(in_ECX + 0x164) == 0) || (uVar4 != 0)) {
          iVar9 = 0;
        }
        local_48[0x3d1] = iVar9;
        FUN_00820bbf(in_ECX);
        iVar9 = DAT_00a139c8;
        if (DAT_00a139c8 != 0) {
          iVar6 = *(int *)(DAT_00a139c8 + 0x20);
          pHVar10 = GetParent(*(HWND *)(iVar2 + 0x20));
          pCVar11 = CWnd::FromHandle(pHVar10);
          iVar2 = 0;
          if (pCVar11 != (CWnd *)0x0) {
            iVar2 = *(int *)(pCVar11 + 0x20);
          }
          if (iVar6 != iVar2) {
            SendMessageW(*(HWND *)(iVar9 + 0x20),0x10,0,0);
          }
        }
        local_4c = local_38;
        if ((*(int *)(in_ECX + 0x164) != 0) || (local_50 = local_44, uVar4 != 0)) {
          local_50 = local_3c;
        }
      }
      else {
        if (*(int *)(in_ECX + 0x198) != 0) {
          FUN_00866d88();
        }
        this = (CMFCRibbonPanelMenu *)FUN_0078e624(0x2040);
        local_8 = 0;
        if (this == (CMFCRibbonPanelMenu *)0x0) {
          local_48 = (int *)0x0;
        }
        else {
          local_48 = (int *)CMFCRibbonPanelMenu::CMFCRibbonPanelMenu
                                      (this,pCVar3,
                                       (CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*> *)
                                       (in_ECX + 0x1b0),0);
        }
        local_8 = 0xffffffff;
        FUN_00820bbf(in_ECX);
        local_48[0x7d4] = 1;
        pcVar1 = *(code **)(*(int *)in_ECX + 0x26c);
        guard_check_icall();
        uVar7 = (*pcVar1)();
        if (uVar7 != 0) {
          iVar2 = 0;
          do {
            if (*(int *)(in_ECX + 0x1b8) <= iVar2) break;
            piVar8 = (int *)FUN_00799cf8(iVar2);
            iVar2 = iVar2 + 1;
            uVar7 = uVar7 & -(uint)(*(int *)(*piVar8 + 0xec) != 0);
          } while (uVar7 != 0);
        }
        local_48[0x7d5] = uVar7;
        if (*(int **)(in_ECX + 0x8c) != (int *)0x0) {
          pcVar1 = *(code **)(**(int **)(in_ECX + 0x8c) + 0x130);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          if (iVar2 != 0) {
            pcVar1 = *(code **)(**(int **)(in_ECX + 0x8c) + 0x130);
            guard_check_icall();
            piVar8 = (int *)(*pcVar1)();
            pcVar1 = *(code **)(*piVar8 + 0xb4);
            guard_check_icall();
            iVar2 = (*pcVar1)();
            if (iVar2 != 0) {
              local_48[0x7d5] = 0;
            }
          }
        }
        local_34 = *(int *)(in_ECX + 0x74);
        local_30 = *(int *)(in_ECX + 0x78);
        local_2c = *(int *)(in_ECX + 0x7c);
        local_28 = *(int *)(in_ECX + 0x80);
        FUN_0079e8b8(&local_34);
        if ((*(int *)(in_ECX + 0x164) != 0) || (local_50 = local_34, uVar4 != 0)) {
          local_50 = local_2c;
        }
        local_4c = local_28;
        if (((*(int *)(in_ECX + 0x194) != 0) && (*(int *)(in_ECX + 0x164) != 0)) && (uVar4 == 0)) {
          local_48[0x3d1] = 1;
        }
        iVar2 = FUN_00863d99();
        if (iVar2 != 0) {
          local_50 = local_34;
          if (uVar4 == 0) {
            local_50 = local_2c;
          }
          local_4c = local_30;
        }
        local_24.left = 0;
        local_24.top = 0;
        local_24.right = 0;
        local_24.bottom = 0;
        SetRectEmpty(&local_24);
        pcVar1 = *(code **)(*(int *)in_ECX + 0x130);
        guard_check_icall();
        piVar8 = (int *)(*pcVar1)();
        if (piVar8 != (int *)0x0) {
          pcVar1 = *(code **)(*piVar8 + 0xc4);
          guard_check_icall(&local_24);
          iVar2 = (*pcVar1)();
          if (iVar2 != 0) {
            FUN_0079e8b8(&local_24);
            local_50 = local_24.right;
            if (uVar4 == 0) {
              local_50 = local_24.left;
            }
            local_4c = local_24.top;
            FUN_008b9099(local_24.right - local_24.left,local_24.bottom - local_24.top);
            local_48[0x7d5] = 0;
          }
        }
        iVar5 = 0;
      }
      pcVar1 = *(code **)(*local_48 + 0x210);
      guard_check_icall(local_5c,local_50,local_4c,iVar5,0,0);
      (*pcVar1)();
      FUN_00864a83(local_48);
    }
  }
LAB_00869c48:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonButton[43], CMFCRibbonCaptionButton[43], CMFCRibbonColorMenuButton[43], CMFCRibbonQuickAccessCustomizeButton[43], CRibbonCategoryScroll[43], CRibbonUndoLabel[43] */
/* 00869cab  FUN_00869cab  205 bytes, 5 callers */

undefined4 FUN_00869cab(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar2 = FUN_0086470d(param_1,param_2);
  uVar3 = 0;
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x138);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x254);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      *(uint *)(param_2 + 0x18) = (-(uint)(iVar2 != 0) & 6) + 0x38;
      pcVar1 = *(code **)(*in_ECX + 0x254);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 0x40000000;
        iVar2 = FUN_008f899d(L"Open");
        ATL::CSimpleStringT<wchar_t,0>::SetString
                  ((CSimpleStringT<wchar_t,0> *)(param_2 + 0x14),L"Open",iVar2);
        pcVar1 = *(code **)(*in_ECX + 0xe4);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 != 0) {
          *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 8;
          iVar2 = FUN_008f899d(L"Close");
          ATL::CSimpleStringT<wchar_t,0>::SetString
                    ((CSimpleStringT<wchar_t,0> *)(param_2 + 0x14),L"Close",iVar2);
        }
      }
    }
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonButton[51], CMFCRibbonCaptionButton[51], CMFCRibbonColorButton[51], CMFCRibbonColorMenuButton[51], CMFCRibbonDefaultPanelButton[51], CMFCRibbonEdit[51], CMFCRibbonGallery[51], CMFCRibbonGalleryIcon[51], CMFCRibbonLabel[51], CMFCRibbonLaunchButton[51], CMFCRibbonQuickAccessCustomizeButton[51], CMFCRibbonUndoButton[51], CRibbonCategoryScroll[51], CRibbonUndoLabel[51] */
/* 00869d78  SetDescription  53 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CMFCRibbonButton::SetDescription(char const *)
    public: virtual void __thiscall CMFCRibbonButton::SetDescription(wchar_t const *)
   
   Library: Visual Studio 2015 Release */

void SetDescription(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00864a59(param_1);
  if (*(int *)(in_ECX + 0x18c) != 0) {
    *(undefined4 *)(in_ECX + 0x10c) = 0;
    *(undefined4 *)(in_ECX + 0x110) = 0;
    *(undefined4 *)(in_ECX + 0x114) = 0;
    *(undefined4 *)(in_ECX + 0x118) = 0;
  }
  return;
}




/* vtable slots: CMFCRibbonButton[159], CMFCRibbonCaptionButton[159], CMFCRibbonColorButton[159], CMFCRibbonColorMenuButton[159], CMFCRibbonDefaultPanelButton[159], CMFCRibbonEdit[159], CMFCRibbonGallery[159], CMFCRibbonGalleryIcon[159], CMFCRibbonLabel[159], CMFCRibbonLaunchButton[159], CMFCRibbonQuickAccessCustomizeButton[159], CMFCRibbonUndoButton[159], CRibbonCategoryScroll[159], CRibbonUndoLabel[159] */
/* 00869dad  FUN_00869dad  27 bytes, 0 callers */

void FUN_00869dad(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = param_1[1];
  *(undefined4 *)(in_ECX + 0x11c) = *param_1;
  *(undefined4 *)(in_ECX + 0x120) = uVar1;
  return;
}




/* vtable slots: CMFCRibbonButton[92], CMFCRibbonCaptionButton[92], CMFCRibbonColorButton[92], CMFCRibbonColorMenuButton[92], CMFCRibbonDefaultPanelButton[92], CMFCRibbonEdit[92], CMFCRibbonGallery[92], CMFCRibbonGalleryIcon[92], CMFCRibbonLabel[92], CMFCRibbonLaunchButton[92], CMFCRibbonQuickAccessCustomizeButton[92], CMFCRibbonUndoButton[92], CRibbonCategoryScroll[92], CRibbonUndoLabel[92] */
/* 00869dc8  FUN_00869dc8  143 bytes, 0 callers */

void FUN_00869dc8(CMFCRibbonBaseElement *param_1)

{
  code *pcVar1;
  CObject *pCVar2;
  undefined4 *puVar3;
  CMFCRibbonBaseElement *in_ECX;
  int local_8;
  
  CMFCRibbonBaseElement::SetOriginal(in_ECX,param_1);
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonButton_00998478,(CObject *)param_1);
  if (((pCVar2 != (CObject *)0x0) && (*(int *)(pCVar2 + 0x1b8) == *(int *)(in_ECX + 0x1b8))) &&
     (local_8 = 0, 0 < *(int *)(in_ECX + 0x1b8))) {
    do {
      puVar3 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar3 + 0x170);
      puVar3 = (undefined4 *)FUN_00799cf8(local_8);
      guard_check_icall(*puVar3);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x1b8));
  }
  return;
}




/* vtable slots: CMFCRibbonButton[89], CMFCRibbonCaptionButton[89], CMFCRibbonColorMenuButton[89], CMFCRibbonDefaultPanelButton[89], CMFCRibbonEdit[89], CMFCRibbonGalleryIcon[89], CMFCRibbonLabel[89], CMFCRibbonLaunchButton[89], CMFCRibbonQuickAccessCustomizeButton[89], CRibbonCategoryScroll[89], CRibbonUndoLabel[89] */
/* 00869e57  FUN_00869e57  148 bytes, 1 callers */

int FUN_00869e57(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  
  iVar2 = FUN_007c2817(param_1);
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x1b8)) {
    do {
      piVar3 = (int *)FUN_00799cf8(iVar4);
      piVar3 = (int *)*piVar3;
      pcVar1 = *(code **)(*piVar3 + 0x164);
      guard_check_icall(*(undefined4 *)(in_ECX + 0x88));
      (*pcVar1)();
      if (DAT_00a13bcc == 0) {
        pcVar1 = *(code **)(*piVar3 + 0x104);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 != 0) goto LAB_00869eca;
        iVar2 = 1;
      }
      else {
LAB_00869eca:
        iVar2 = 0;
      }
      iVar4 = iVar4 + 1;
      piVar3[0x3b] = iVar2;
      iVar2 = in_ECX + 0x1b0;
    } while (iVar4 < *(int *)(in_ECX + 0x1b8));
  }
  return iVar2;
}




/* vtable slots: CMFCRibbonButton[77], CMFCRibbonCaptionButton[77], CMFCRibbonColorButton[77], CMFCRibbonColorMenuButton[77], CMFCRibbonDefaultPanelButton[77], CMFCRibbonEdit[77], CMFCRibbonGallery[77], CMFCRibbonGalleryIcon[77], CMFCRibbonLabel[77], CMFCRibbonLaunchButton[77], CMFCRibbonQuickAccessCustomizeButton[77], CMFCRibbonUndoButton[77], CRibbonCategoryScroll[77], CRibbonUndoLabel[77] */
/* 00869eeb  FUN_00869eeb  97 bytes, 0 callers */

void FUN_00869eeb(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  *(undefined4 *)(in_ECX + 0x84) = param_1;
  if (0 < *(int *)(in_ECX + 0x1b8)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x134);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x1b8));
  }
  return;
}




/* vtable slots: CMFCRibbonButton[45], CMFCRibbonCaptionButton[45], CMFCRibbonColorButton[45], CMFCRibbonColorMenuButton[45], CMFCRibbonDefaultPanelButton[45], CMFCRibbonEdit[45], CMFCRibbonGallery[45], CMFCRibbonGalleryIcon[45], CMFCRibbonLabel[45], CMFCRibbonLaunchButton[45], CMFCRibbonQuickAccessCustomizeButton[45], CMFCRibbonUndoButton[45], CRibbonCategoryScroll[45], CRibbonUndoLabel[45] */
/* 00869f4c  SetText  102 bytes, 1 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CMFCRibbonButton::SetText(char const *)
    public: virtual void __thiscall CMFCRibbonButton::SetText(wchar_t const *)
   
   Library: Visual Studio 2015 Release */

void SetText(undefined4 param_1)

{
  int in_ECX;
  int iVar1;
  
  FUN_00864c79(param_1);
  *(undefined4 *)(in_ECX + 0x10c) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  *(undefined4 *)(in_ECX + 0x114) = 0;
  *(undefined4 *)(in_ECX + 0x118) = 0;
  FUN_0042fb40(0,0xffffffff);
  iVar1 = 0;
  while( true ) {
    iVar1 = FUN_0044e690(0x20,iVar1);
    if (iVar1 < 0) break;
    FUN_0042f500(*(undefined4 *)(in_ECX + 0x1a4),iVar1);
    iVar1 = iVar1 + 1;
  }
  return;
}



