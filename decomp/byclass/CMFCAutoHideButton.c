/* CMFCAutoHideButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCAutoHideButton[1] */
/* 0087a286  FUN_0087a286  49 bytes, 0 callers */

void FUN_0087a286(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCAutoHideButton::vftable;
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




/* vtable slots: CMFCAutoHideButton[3] */
/* 0087a2b7  FUN_0087a2b7  75 bytes, 0 callers */

void FUN_0087a2b7(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  int local_c;
  int local_8;
  
  *(undefined4 *)(in_ECX + 0x28) = param_1;
  *(undefined4 *)(in_ECX + 0x2c) = param_2;
  *(undefined4 *)(in_ECX + 0x10) = param_3;
  local_c = in_ECX;
  local_8 = in_ECX;
  FUN_008911f9(param_1,in_ECX);
  FUN_0087a328(&local_c);
  SetRect((LPRECT)(in_ECX + 0x18),0,0,local_c,local_8);
  *(undefined4 *)(in_ECX + 8) = 1;
  return;
}




/* vtable slots: CMFCAutoHideButton[0] */
/* 0087a322  FUN_0087a322  6 bytes, 0 callers */

undefined ** FUN_0087a322(void)

{
  return &PTR_s_CMFCAutoHideButton_00999cd8;
}




/* vtable slots: CMFCAutoHideButton[12] */
/* 0087a4fc  FUN_0087a4fc  278 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_0087a4fc(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined1 local_1c [8];
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x87a508;
  *param_1 = 0;
  param_1[1] = 0;
  if ((*(int *)(in_ECX + 0x2c) != 0) && (*(int *)(in_ECX + 0x28) != 0)) {
    CStringT<>();
    local_8 = 0;
    FUN_00792c64(local_14);
    if (*(int *)(local_14[0] + -0xc) != 0) {
      FUN_0079dfaa(*(undefined4 *)(in_ECX + 0x28));
      local_8 = CONCAT31(local_8._1_3_,1);
      if ((*(uint *)(in_ECX + 0x10) & 0xa000) == 0) {
        iVar2 = FUN_007c2511();
        iVar2 = iVar2 + 0x14c;
      }
      else {
        iVar2 = FUN_007c2511();
        iVar2 = iVar2 + 0x11c;
      }
      iVar2 = FUN_0079efbc(iVar2);
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      piVar3 = (int *)FUN_00566800(local_1c,local_14);
      iVar1 = piVar3[1];
      *param_1 = *piVar3;
      param_1[1] = iVar1;
      iVar1 = DAT_00a00a34;
      *param_1 = *param_1 + DAT_00a00a34;
      param_1[1] = param_1[1] + iVar1;
      FUN_0079efbc(iVar2);
      if ((*(uint *)(in_ECX + 0x10) & 0xa000) == 0) {
        iVar2 = param_1[1];
        param_1[1] = *param_1;
        *param_1 = iVar2;
      }
      FUN_0079e0f8();
    }
    if ((*(int *)(*(int *)(in_ECX + 0x28) + 0x11c) == 0) && (DAT_00a00a40 != 0)) {
      if ((*(uint *)(in_ECX + 0x10) & 0xa000) == 0) {
        param_1[1] = 0;
      }
      else {
        *param_1 = 0;
      }
    }
    FUN_00406b10();
  }
  return param_1;
}




/* vtable slots: CMFCAutoHideButton[6] */
/* 0087a613  FUN_0087a613  13 bytes, 0 callers */

void FUN_0087a613(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}




/* vtable slots: CMFCAutoHideButton[7], std::GDU_Mbstatet::?$codecvt[4], std::_WDU_Mbstatet::?$codecvt[4] */
/* 0087a620  FUN_0087a620  4 bytes, 0 callers */

undefined4 FUN_0087a620(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}




/* vtable slots: CMFCAutoHideButton[8] */
/* 0087a633  FUN_0087a633  1329 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0087a633(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  tagRECT *ptVar6;
  int *in_ECX;
  int iVar7;
  HDC hdc;
  LPRECT ptVar8;
  int *piVar9;
  undefined4 uVar10;
  int iVar11;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  LPRECT local_9c;
  int *local_98;
  int *local_94;
  tagTEXTMETRICW local_90;
  tagRECT local_54;
  tagRECT local_44;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xa0;
  local_8 = 0x87a642;
  local_98 = param_1;
  local_94 = in_ECX;
  piVar3 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar3 + 0x1ac);
  guard_check_icall();
  iVar4 = (*pcVar1)();
  if (iVar4 == 0) {
    local_a8 = DAT_00a00a38;
  }
  else {
    local_a8 = (-(uint)((in_ECX[4] & 0xa000U) != 0) & 0xfffffffe) + 7;
  }
  local_a0 = iVar4;
  FUN_0087a328(&local_b0);
  ptVar8 = (LPRECT)(in_ECX + 6);
  local_9c = ptVar8;
  SetRect(ptVar8,0,0,local_b0,local_ac);
  local_30 = 0;
  local_34 = DAT_00a00a30;
  local_2c = DAT_00a00a30;
  local_28 = DAT_00a00a30;
  uVar5 = in_ECX[4] & 0xf000;
  if (uVar5 == 0x1000) {
    uVar10 = 0xffffffa6;
LAB_0087a70a:
    FUN_0085a6d3(&local_34,uVar10);
  }
  else {
    if (uVar5 == 0x4000) {
      uVar10 = 0x5a;
      goto LAB_0087a70a;
    }
    if (uVar5 == 0x8000) {
      uVar10 = 0xb4;
      goto LAB_0087a70a;
    }
  }
  if ((iVar4 != 0) && (*(int *)(in_ECX[10] + 0x114) == 0)) {
    local_44.left = ptVar8->left;
    uVar5 = in_ECX[4] & 0xf000;
    local_44.top = in_ECX[7];
    local_44.right = in_ECX[8];
    local_44.bottom = in_ECX[9];
    if (uVar5 == 0x1000) {
LAB_0087a778:
      iVar11 = local_b0 / 2 - (in_ECX[9] - in_ECX[7]);
      iVar4 = 0;
LAB_0087a78e:
      OffsetRect(&local_44,iVar4,iVar11);
    }
    else {
      if (uVar5 == 0x2000) {
LAB_0087a760:
        iVar4 = local_ac / 2 - (in_ECX[8] - in_ECX[6]);
        iVar11 = 0;
        goto LAB_0087a78e;
      }
      if (uVar5 == 0x4000) goto LAB_0087a778;
      if (uVar5 == 0x8000) goto LAB_0087a760;
    }
    pcVar1 = *(code **)(*in_ECX + 0x24);
    guard_check_icall(local_98,local_44.left,local_44.top,local_44.right,local_44.bottom);
    piVar3 = local_94;
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar3 + 0x28);
    guard_check_icall(local_98,local_44.left,local_44.top,local_44.right,local_44.bottom,local_34,
                      local_30,local_2c,local_28);
    (*pcVar1)();
    in_ECX = local_94;
    ptVar8 = local_9c;
  }
  pcVar1 = *(code **)(*in_ECX + 0x24);
  guard_check_icall(local_98,ptVar8->left,ptVar8->top,ptVar8->right,ptVar8->bottom);
  piVar3 = local_94;
  (*pcVar1)();
  pcVar1 = *(code **)(*piVar3 + 0x28);
  guard_check_icall(local_98,local_9c->left,local_9c->top,local_9c->right,local_9c->bottom,local_34,
                    local_30,local_2c,local_28);
  (*pcVar1)();
  piVar3 = local_94;
  iVar4 = local_a0;
  if (local_94[0xb] == 0) goto LAB_0087ab57;
  local_24.left = local_94[6];
  local_24.top = local_94[7];
  local_24.right = local_94[8];
  local_24.bottom = local_94[9];
  if (local_a0 == 0) {
    local_24.left = local_24.left + local_34;
    local_24.top = local_24.top + local_30;
    local_24.right = local_24.right - local_2c;
    local_24.bottom = local_24.bottom - local_28;
  }
  InflateRect(&local_24,-DAT_00a00a34,-DAT_00a00a34);
  if (iVar4 != 0) {
    if ((piVar3[4] & 0xa000U) == 0) {
      iVar11 = ((local_24.right - local_24.left) * 2) / -3;
      iVar4 = 0;
    }
    else {
      iVar11 = 0;
      iVar4 = ((local_24.bottom - local_24.top) * 2) / -3;
    }
    InflateRect(&local_24,iVar4,iVar11);
  }
  if ((int *)piVar3[0xb] == (int *)0x0) goto LAB_0087ab57;
  pcVar1 = *(code **)(*(int *)piVar3[0xb] + 0x1bc);
  guard_check_icall(0);
  local_9c = (LPRECT)(*pcVar1)();
  if (local_9c == (LPRECT)0x0) {
    iVar4 = DAT_00a00a34;
    piVar9 = local_98;
    if ((piVar3[4] & 0xa000U) == 0) goto LAB_0087a9b6;
    local_24.left = local_24.left + DAT_00a00a34;
  }
  else {
    iVar4 = FUN_007c2511();
    piVar9 = local_98;
    local_a0 = *(int *)(iVar4 + 0x118);
    iVar4 = *(int *)(iVar4 + 0x114);
    if ((piVar3[4] & 0xa000U) == 0) {
      iVar7 = ((local_24.right - local_24.left) - iVar4) / 2;
      iVar11 = 0;
    }
    else {
      iVar11 = ((local_24.bottom - local_24.top) - local_a0) / 2;
      iVar7 = 0;
    }
    if (local_98 == (int *)0x0) {
      hdc = (HDC)0x0;
    }
    else {
      hdc = (HDC)local_98[1];
    }
    DrawIconEx(hdc,local_24.left + iVar7,iVar11 + local_24.top,(HICON)local_9c,iVar4,local_a0,0,
               (HBRUSH)0x0,3);
    if ((piVar3[4] & 0xa000U) == 0) {
      iVar4 = local_a8 + local_a0;
LAB_0087a9b6:
      local_24.top = local_24.top + iVar4;
    }
    else {
      local_24.left = local_24.left + local_a8 + iVar4;
    }
  }
  ptVar8 = local_9c;
  CStringT<>();
  local_8 = 0;
  FUN_00792c64(&local_a4);
  if ((((*(int *)(local_a4 + -0xc) != 0) && (*(int *)(piVar3[10] + 0x11c) != 0)) ||
      (ptVar8 == (LPRECT)0x0)) || (DAT_00a00a40 == 0)) {
    local_9c = (LPRECT)FUN_0079f0b8(1);
    pcVar1 = *(code **)(*piVar9 + 0x28);
    if ((piVar3[4] & 0xa000U) == 0) {
      iVar4 = FUN_007c2511();
      iVar4 = iVar4 + 0x14c;
    }
    else {
      iVar4 = FUN_007c2511();
      iVar4 = iVar4 + 0x11c;
    }
    guard_check_icall(iVar4);
    local_a0 = (*pcVar1)();
    if (local_a0 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    pcVar1 = *(code **)(*piVar9 + 0x30);
    piVar3 = (int *)FUN_007c2574();
    pcVar2 = *(code **)(*piVar3 + 0x1b8);
    guard_check_icall(local_94);
    uVar10 = (*pcVar2)();
    guard_check_icall(uVar10);
    piVar3 = local_98;
    (*pcVar1)();
    if ((local_94[4] & 0xa000U) == 0) {
      GetTextMetricsW((HDC)piVar3[2],&local_90);
      local_54.top = local_24.top;
      local_54.left =
           local_24.right - (((local_24.right - local_90.tmHeight) - local_24.left) + 1) / 2;
      local_54.bottom = local_24.top + local_a8;
      uVar10 = 0x124;
      local_54.right = local_24.right;
      ptVar6 = &local_54;
      piVar3 = local_98;
    }
    else {
      uVar10 = 0x24;
      ptVar6 = &local_24;
    }
    iVar4 = *piVar3;
    guard_check_icall(local_a4,*(undefined4 *)(local_a4 + -0xc),ptVar6,uVar10);
    (**(code **)(iVar4 + 0x68))();
    pcVar1 = *(code **)(*piVar3 + 0x28);
    guard_check_icall(local_a0);
    (*pcVar1)();
    FUN_0079f0b8(local_9c);
  }
  FUN_00406b10();
LAB_0087ab57:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCAutoHideButton[10] */
/* 0087ab65  FUN_0087ab65  70 bytes, 0 callers */

void FUN_0087ab65(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  code *pcVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x1b4);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCAutoHideButton[9] */
/* 0087abab  FUN_0087abab  58 bytes, 0 callers */

void FUN_0087abab(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  code *pcVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x1b0);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCAutoHideButton[11] */
/* 0087ac46  FUN_0087ac46  41 bytes, 0 callers */

void FUN_0087ac46(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x2c) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x2c) + 0x360);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}



