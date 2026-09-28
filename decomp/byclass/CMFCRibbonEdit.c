/* CMFCRibbonEdit -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonEdit[1] */
/* 0087e2a1  FUN_0087e2a1  51 bytes, 0 callers */

void FUN_0087e2a1(byte param_1)

{
  FUN_0087e22a();
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




/* vtable slots: CMFCRibbonEdit[90] */
/* 0087e3a9  FUN_0087e3a9  281 bytes, 0 callers */

void FUN_0087e3a9(int param_1)

{
  code *pcVar1;
  int in_ECX;
  
  FUN_0086612f(param_1);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x1ec),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x1ec));
  if (*(int **)(in_ECX + 0x1f0) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x1f0) + 0x60);
    guard_check_icall();
    (*pcVar1)();
    if (*(int **)(in_ECX + 0x1f0) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x1f0) + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    *(undefined4 *)(in_ECX + 0x1f0) = 0;
  }
  if (*(int **)(in_ECX + 500) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 500) + 0x60);
    guard_check_icall();
    (*pcVar1)();
    if (*(int **)(in_ECX + 500) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 500) + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    *(undefined4 *)(in_ECX + 500) = 0;
  }
  *(undefined4 *)(in_ECX + 0x1c4) = *(undefined4 *)(param_1 + 0x1c4);
  *(undefined4 *)(in_ECX + 0x1c8) = *(undefined4 *)(param_1 + 0x1c8);
  *(undefined4 *)(in_ECX + 0x1e0) = *(undefined4 *)(param_1 + 0x1e0);
  *(undefined4 *)(in_ECX + 0x1dc) = *(undefined4 *)(param_1 + 0x1dc);
  *(undefined4 *)(in_ECX + 0x1cc) = *(undefined4 *)(param_1 + 0x1cc);
  *(undefined4 *)(in_ECX + 0x1d0) = *(undefined4 *)(param_1 + 0x1d0);
  *(undefined4 *)(in_ECX + 0x1d4) = *(undefined4 *)(param_1 + 0x1d4);
  *(undefined4 *)(in_ECX + 0x1d8) = *(undefined4 *)(param_1 + 0x1d8);
  return;
}




/* vtable slots: CMFCRibbonEdit[165] */
/* 0087e4c2  FUN_0087e4c2  152 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0087e4c2(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x87e4ce;
  iVar2 = FUN_0078e624(0x98);
  local_8 = 0;
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0087e1ba(in_ECX);
  }
  local_8 = 0xffffffff;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  iVar2 = FUN_008c6c72(param_2,&local_24,param_1,*(undefined4 *)(in_ECX + 0xa4));
  if (iVar2 == 0) {
    if (piVar3 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar3 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  else if (*(int *)(in_ECX + 0x1e0) != 0) {
    FUN_0087e58a(piVar3,param_1);
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonEdit[111] */
/* 0087e66e  FUN_0087e66e  135 bytes, 1 callers */

void FUN_0087e66e(void)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x1f0) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x1f0) + 0x60);
    guard_check_icall();
    (*pcVar1)();
    if (*(int **)(in_ECX + 0x1f0) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x1f0) + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    *(undefined4 *)(in_ECX + 0x1f0) = 0;
  }
  if (*(int **)(in_ECX + 500) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 500) + 0x60);
    guard_check_icall();
    (*pcVar1)();
    if (*(int **)(in_ECX + 500) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 500) + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    *(undefined4 *)(in_ECX + 500) = 0;
  }
  return;
}




/* vtable slots: CMFCRibbonEdit[63] */
/* 0087e70e  FUN_0087e70e  63 bytes, 0 callers */

undefined4 FUN_0087e70e(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  int *in_ECX;
  
  iVar1 = in_ECX[0x43];
  in_ECX[0x43] = 0;
  pcVar2 = *(code **)(*in_ECX + 0x100);
  guard_check_icall(param_1,param_2);
  (*pcVar2)();
  in_ECX[0x43] = iVar1;
  return param_1;
}




/* vtable slots: CMFCRibbonEdit[64] */
/* 0087e74d  FUN_0087e74d  404 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_0087e74d(int *param_1,int param_2)

{
  double dVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  undefined1 local_60 [8];
  int *local_58;
  int local_54;
  int local_50;
  undefined8 local_4c;
  tagTEXTMETRICW local_44;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_58 = param_1;
  local_50 = param_2;
  if (in_ECX[0x30] == 0) {
    iVar4 = in_ECX[0x71];
  }
  else {
    iVar4 = in_ECX[0x72];
  }
  local_4c = (double)CONCAT44(iVar4,(undefined4)local_4c);
  iVar3 = FUN_007c2511();
  if (*(int *)(iVar3 + 0x1e8) == 0) {
    dVar1 = 1.0;
  }
  else {
    dVar1 = *(double *)(iVar3 + 0x1e0);
  }
  if (1.0 < dVar1) {
    FUN_007c2511();
    local_4c = (double)(int)local_4c._4_4_;
    iVar4 = thunk_FUN_008d99f0();
  }
  GetTextMetricsW(*(HDC *)(local_50 + 8),&local_44);
  local_4c._4_4_ = local_44.tmHeight;
  if ((local_44.tmHeight & 1U) != 0) {
    local_4c._4_4_ = local_44.tmHeight + 1;
  }
  if (in_ECX[0x22] == 0) {
    iVar3 = in_ECX[0x48];
  }
  else {
    iVar3 = FUN_008721a4(local_60,0);
    iVar5 = (int)((*(int *)(iVar3 + 4) - local_4c._4_4_) + 6) / 2;
    iVar3 = 2;
    if (1 < iVar5) {
      iVar3 = iVar5;
    }
    in_ECX[0x48] = iVar3;
  }
  local_4c._4_4_ = local_4c._4_4_ + iVar3 * 2;
  in_ECX[0x76] = 0;
  if ((in_ECX[0x31] == 0) && (in_ECX[0x30] == 0)) {
    pcVar2 = *(code **)(*in_ECX + 0x114);
    guard_check_icall(&local_54,1);
    (*pcVar2)();
    if (((local_54 != 0) || (local_50 != 0)) &&
       (in_ECX[0x76] = in_ECX[0x76] + local_54 + in_ECX[0x47] * 2, (int)local_4c._4_4_ <= local_50))
    {
      local_4c._4_4_ = local_50;
    }
    iVar3 = in_ECX[0x76];
    if (0 < in_ECX[0x43]) {
      iVar3 = iVar3 + in_ECX[0x47] * 2 + in_ECX[0x43];
      in_ECX[0x76] = iVar3;
      if ((int)local_4c._4_4_ <= in_ECX[0x44]) {
        local_4c._4_4_ = in_ECX[0x44];
      }
    }
    iVar4 = iVar4 + iVar3;
    param_1 = local_58;
  }
  *param_1 = iVar4;
  param_1[1] = local_4c._4_4_;
  return param_1;
}




/* vtable slots: CMFCRibbonEdit[163] */
/* 0087e8ed  FUN_0087e8ed  7 bytes, 0 callers */

undefined4 FUN_0087e8ed(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1d0);
}




/* vtable slots: CMFCRibbonEdit[162] */
/* 0087e8f4  FUN_0087e8f4  7 bytes, 0 callers */

undefined4 FUN_0087e8f4(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1cc);
}




/* vtable slots: CMFCRibbonEdit[0] */
/* 0087e8fb  FUN_0087e8fb  6 bytes, 0 callers */

undefined ** FUN_0087e8fb(void)

{
  return &PTR_s_CMFCRibbonEdit_00999d90;
}




/* vtable slots: CMFCRibbonEdit[88] */
/* 0087e907  FUN_0087e907  7 bytes, 0 callers */

undefined4 FUN_0087e907(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1e4);
}




/* vtable slots: CMFCRibbonEdit[161] */
/* 0087e90e  FUN_0087e90e  7 bytes, 0 callers */

undefined4 FUN_0087e90e(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1e0);
}




/* vtable slots: CMFCRibbonEdit[52] */
/* 0087e915  FUN_0087e915  22 bytes, 0 callers */

undefined4 FUN_0087e915(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(int *)(in_ECX + 200) != 0) || (*(int *)(in_ECX + 0x1e4) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CMFCRibbonEdit[73] */
/* 0087e92b  FUN_0087e92b  26 bytes, 0 callers */

void FUN_0087e92b(undefined4 param_1)

{
  FUN_00867fa4(param_1);
  FUN_0087ff73();
  return;
}




/* vtable slots: CMFCRibbonEdit[95] */
/* 0087eaa7  FUN_0087eaa7  497 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0087eaa7(undefined4 param_1)

{
  double dVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  code *pcVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  undefined4 uVar15;
  int *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar9 = *(code **)(*in_ECX + 0x290);
  uVar15 = param_1;
  guard_check_icall(param_1);
  (*pcVar9)();
  iVar10 = in_ECX[0x32];
  if (in_ECX[0x33] != 0) {
    in_ECX[0x32] = 1;
  }
  pcVar9 = *(code **)(*in_ECX + 0xdc);
  guard_check_icall(uVar15);
  iVar11 = (*pcVar9)();
  if (iVar11 != 0) {
    in_ECX[0x32] = 0;
  }
  iVar11 = in_ECX[0x1d];
  iVar2 = in_ECX[0x1e];
  iVar3 = in_ECX[0x1f];
  iVar4 = in_ECX[0x20];
  iVar5 = in_ECX[0x4d];
  iVar6 = in_ECX[0x4e];
  iVar7 = in_ECX[0x4f];
  iVar8 = in_ECX[0x50];
  if (in_ECX[0x30] == 0) {
    iVar13 = in_ECX[0x71];
  }
  else {
    iVar13 = in_ECX[0x72];
  }
  iVar12 = FUN_007c2511();
  if (*(int *)(iVar12 + 0x1e8) == 0) {
    dVar1 = 1.0;
  }
  else {
    dVar1 = *(double *)(iVar12 + 0x1e0);
  }
  if (1.0 < dVar1) {
    FUN_007c2511();
    iVar13 = thunk_FUN_008d99f0();
  }
  in_ECX[0x1d] = in_ECX[0x1f] - iVar13;
  in_ECX[0x4d] = in_ECX[0x1f] - iVar13;
  piVar14 = (int *)FUN_007c2574();
  pcVar9 = *(code **)(*piVar14 + 0x238);
  guard_check_icall(param_1);
  (*pcVar9)();
  if ((in_ECX[0x7c] == 0) || (*(int *)(in_ECX[0x7c] + 0x20) == 0)) {
    local_18.left = in_ECX[0x4d];
    local_18.top = in_ECX[0x4e];
    local_18.right = in_ECX[0x4f];
    local_18.bottom = in_ECX[0x50];
    InflateRect(&local_18,-in_ECX[0x47],-in_ECX[0x48]);
    uVar15 = 0x824;
    if (in_ECX[0x75] == 1) {
      uVar15 = 0x825;
    }
    else if (in_ECX[0x75] == 2) {
      uVar15 = 0x826;
    }
    pcVar9 = *(code **)(*in_ECX + 0x260);
    guard_check_icall(param_1,in_ECX + 0x7b,local_18.left,local_18.top,local_18.right,
                      local_18.bottom,uVar15,0xffffffff);
    (*pcVar9)();
  }
  piVar14 = (int *)FUN_007c2574();
  pcVar9 = *(code **)(*piVar14 + 0x240);
  guard_check_icall(param_1,in_ECX);
  (*pcVar9)();
  in_ECX[0x32] = iVar10;
  in_ECX[0x1d] = iVar11;
  in_ECX[0x1e] = iVar2;
  in_ECX[0x1f] = iVar3;
  in_ECX[0x20] = iVar4;
  in_ECX[0x4d] = iVar5;
  in_ECX[0x4e] = iVar6;
  in_ECX[0x4f] = iVar7;
  in_ECX[0x50] = iVar8;
  return;
}




/* vtable slots: CMFCRibbonEdit[164] */
/* 0087ed06  FUN_0087ed06  445 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0087ed06(int *param_1)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  int local_30;
  int local_2c;
  int *local_28;
  int local_24;
  int local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = param_1;
  if ((in_ECX[0x31] == 0) && (in_ECX[0x30] == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x114);
    local_28 = in_ECX;
    guard_check_icall(&local_30,1);
    (*pcVar1)();
    local_20 = in_ECX[0x1d];
    if ((local_30 != 0) || (local_2c != 0)) {
      local_18.top = in_ECX[0x1e];
      local_18.bottom = in_ECX[0x20];
      local_18.left = in_ECX[0x1d] + in_ECX[0x47];
      local_18.right = local_18.left + local_30;
      iVar3 = ((local_18.bottom - local_18.top) - local_2c) / 2;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      OffsetRect(&local_18,0,iVar3);
      param_1 = local_1c;
      pcVar1 = *(code **)(*in_ECX + 0x120);
      guard_check_icall(local_1c,1,local_18.left,local_18.top,local_18.right,local_18.bottom);
      (*pcVar1)();
      local_20 = local_18.right;
    }
    if ((0 < in_ECX[0x43]) && (in_ECX[0x2e] == 0)) {
      local_24 = -1;
      pcVar1 = *(code **)(*in_ECX + 0xdc);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        pcVar1 = *(code **)(*param_1 + 0x30);
        piVar4 = (int *)FUN_007c2574();
        pcVar2 = *(code **)(*piVar4 + 0xc4);
        guard_check_icall();
        uVar5 = (*pcVar2)();
        guard_check_icall(uVar5);
        local_24 = (*pcVar1)();
        in_ECX = local_28;
      }
      piVar4 = local_1c;
      local_18.left = in_ECX[0x47] + local_20;
      uVar5 = 0x824;
      local_18.top = in_ECX[0x1e];
      local_18.right = in_ECX[0x1f];
      local_18.bottom = in_ECX[0x20];
      if (in_ECX[0x75] == 1) {
        uVar5 = 0x825;
      }
      else if (in_ECX[0x75] == 2) {
        uVar5 = 0x826;
      }
      pcVar1 = *(code **)(*in_ECX + 0x260);
      guard_check_icall(local_1c,in_ECX + 0x18,local_18.left,local_18.top,local_18.right,
                        local_18.bottom,uVar5,0xffffffff);
      (*pcVar1)();
      if (local_24 != -1) {
        pcVar1 = *(code **)(*piVar4 + 0x30);
        guard_check_icall(local_24);
        (*pcVar1)();
      }
    }
  }
  return;
}




/* vtable slots: CMFCRibbonEdit[94] */
/* 0087eec3  FUN_0087eec3  948 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_0087eec3(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  code *pcVar10;
  CDC *this;
  int *piVar11;
  int iVar12;
  int *piVar13;
  undefined4 uVar14;
  int *in_ECX;
  int local_164;
  int local_160;
  undefined1 local_15c [4];
  int *local_158;
  code *local_154;
  CDC *local_150;
  int *local_14c;
  undefined1 local_148 [244];
  tagRECT local_54;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x180;
  local_150 = param_1;
  local_8 = 0;
  local_158 = (int *)((param_7 - param_5) * 2);
  local_34.left = param_4;
  iVar9 = in_ECX[0x35];
  in_ECX[0x35] = 0;
  local_34.top = param_5;
  local_34.right = param_4 + param_3;
  local_34.bottom = param_7;
  pcVar10 = *(code **)(*in_ECX + 0x114);
  local_14c = in_ECX;
  guard_check_icall(&local_164,1);
  piVar1 = local_14c;
  (*pcVar10)();
  if ((local_164 != 0) || (local_160 != 0)) {
    InflateRect(&local_34,-1,0);
    if (((local_34.bottom - local_34.top) - local_160) / 2 < 0) {
      iVar12 = 0;
    }
    else {
      iVar12 = ((local_34.bottom - local_34.top) - local_160) / 2;
    }
    local_34.top = local_34.top + iVar12;
    local_34.bottom = local_160 + local_34.top;
    local_154 = *(code **)(*piVar1 + 0x120);
    guard_check_icall(local_150,1,local_34.left,local_34.top,local_34.right,local_34.bottom);
    (*local_154)();
  }
  local_44.left = param_6 - (int)local_158;
  local_44.top = param_5;
  local_44.right = param_6;
  local_44.bottom = param_7;
  InflateRect(&local_44,-1,-1);
  local_54.left = param_4 + param_3;
  local_54.top = param_5;
  local_54.bottom = param_7;
  local_54.right = local_44.left;
  InflateRect(&local_54,-3,0);
  pcVar10 = *(code **)(*(int *)local_150 + 0x68);
  guard_check_icall(param_2,*(undefined4 *)(param_2 + -0xc),&local_54,0x824);
  (*pcVar10)();
  piVar11 = local_14c;
  local_154 = (code *)(local_14c + 0x1d);
  piVar1 = local_14c + 0x4d;
  iVar12 = *(int *)local_154;
  iVar2 = local_14c[0x1e];
  iVar3 = local_14c[0x1f];
  iVar4 = local_14c[0x20];
  iVar5 = *piVar1;
  iVar6 = local_14c[0x4e];
  iVar7 = local_14c[0x4f];
  iVar8 = local_14c[0x50];
  *(LONG *)local_154 = local_44.left;
  local_14c[0x1e] = local_44.top;
  local_14c[0x1f] = local_44.right;
  local_14c[0x20] = local_44.bottom;
  *piVar1 = local_44.left;
  local_14c[0x4e] = local_44.top;
  local_14c[0x4f] = local_44.right;
  local_14c[0x50] = local_44.bottom;
  local_14c[0x4f] = local_14c[0x4f] + -0xf;
  piVar13 = (int *)FUN_007c2574();
  pcVar10 = *(code **)(*piVar13 + 0x238);
  guard_check_icall(local_150,local_14c);
  (*pcVar10)();
  piVar13 = (int *)FUN_007c2574();
  pcVar10 = *(code **)(*piVar13 + 0x240);
  guard_check_icall(local_150,local_14c);
  (*pcVar10)();
  if (local_14c[0x77] == 0) {
    local_24.left = local_44.left;
    local_24.top = local_44.top;
    local_24.right = local_44.right;
    local_24.bottom = local_44.bottom;
    InflateRect(&local_24,-3,-3);
    this = local_150;
    local_24.right = local_24.left + 7;
    local_24.bottom = local_24.bottom + -1;
    pcVar10 = *(code **)(*(int *)local_150 + 0x24);
    guard_check_icall(7);
    uVar14 = (*pcVar10)();
    FUN_0079ec58(local_15c,local_24.left,local_24.top);
    CDC::LineTo(this,local_24.right,local_24.top);
    FUN_0079ec58(local_15c,(local_24.right + local_24.left) / 2,local_24.top);
    CDC::LineTo(this,(local_24.right + local_24.left) / 2,local_24.bottom);
    FUN_0079ec58(local_15c,local_24.left,local_24.bottom);
    CDC::LineTo(this,local_24.right,local_24.bottom);
    FUN_0079efbc(uVar14);
  }
  else {
    FUN_008253cd();
    local_8 = CONCAT31(local_8._1_3_,1);
    local_24.left = local_14c[0x4f];
    local_24.top = local_44.top;
    local_24.right = local_44.right;
    local_24.bottom = local_44.bottom;
    InflateRect(&local_24,-2,-2);
    local_158 = (int *)FUN_007c2574();
    pcVar10 = *(code **)(*local_158 + 0x6c);
    guard_check_icall(local_150,local_24.left,local_24.top,local_24.right,local_24.bottom,0,0,0,
                      local_148);
    (*pcVar10)();
    FUN_00825493();
  }
  *(int *)local_154 = iVar12;
  local_14c[0x35] = iVar9;
  *(int *)((int)local_154 + 4) = iVar2;
  *(int *)((int)local_154 + 8) = iVar3;
  *(int *)((int)local_154 + 0xc) = iVar4;
  *piVar1 = iVar5;
  piVar11[0x4e] = iVar6;
  piVar11[0x4f] = iVar7;
  piVar11[0x50] = iVar8;
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonEdit[142] */
/* 0087f277  OnEnable  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonEdit::OnEnable(int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCRibbonEdit::OnEnable(CMFCRibbonEdit *this,int param_1)

{
  if ((*(int *)(this + 0x1f0) != 0) && (*(int *)(*(int *)(this + 0x1f0) + 0x20) != 0)) {
    FUN_007979e8(param_1);
  }
  if ((*(int *)(this + 500) != 0) && (*(int *)(*(int *)(this + 500) + 0x20) != 0)) {
    FUN_007979e8();
    return;
  }
  return;
}




/* vtable slots: CMFCRibbonEdit[136] */
/* 0087f2b0  OnHighlight  79 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonEdit::OnHighlight(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCRibbonEdit::OnHighlight(CMFCRibbonEdit *this,int param_1)

{
  int iVar1;
  BOOL BVar2;
  
  iVar1 = *(int *)(this + 0x1f0);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    BVar2 = IsWindowVisible(*(HWND *)(iVar1 + 0x20));
    if (BVar2 != 0) {
      *(int *)(*(int *)(this + 0x1f0) + 0x88) = param_1;
      RedrawWindow(*(HWND *)(*(int *)(this + 0x1f0) + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
    }
  }
  return;
}




/* vtable slots: CMFCRibbonEdit[119] */
/* 0087f2ff  FUN_0087f2ff  144 bytes, 0 callers */

undefined4 FUN_0087f2ff(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  BOOL BVar3;
  CMFCRibbonBar *this;
  CMFCRibbonBaseElement *in_ECX;
  
  if (*(int *)(in_ECX + 0xd4) == 0) {
    BVar3 = IsRectEmpty((RECT *)(in_ECX + 0x74));
    if (BVar3 == 0) {
      this = CMFCRibbonBaseElement::GetTopLevelRibbonBar(in_ECX);
      if (this != (CMFCRibbonBar *)0x0) {
        CMFCRibbonBar::HideKeyTips(this);
      }
      if (((param_1 == 0) && (*(int *)(in_ECX + 0x1f0) != 0)) &&
         (*(int *)(*(int *)(in_ECX + 0x1f0) + 0x20) != 0)) {
        FUN_00797df8();
        if (*(int *)(*(int *)(in_ECX + 0x1ec) + -0xc) != 0) {
          CRichEditCtrl::SetSel(*(CRichEditCtrl **)(in_ECX + 0x1f0),0,-1);
        }
      }
      else {
        pcVar1 = *(code **)(*(int *)in_ECX + 0x298);
        guard_check_icall();
        (*pcVar1)();
      }
      uVar2 = 1;
    }
    else {
      uVar2 = FUN_00864399(param_1);
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCRibbonEdit[132] */
/* 0087f443  FUN_0087f443  18 bytes, 0 callers */

void FUN_0087f443(undefined4 param_1,undefined4 param_2)

{
  FUN_008644c5(param_1,param_2);
  return;
}




/* vtable slots: CMFCRibbonEdit[125] */
/* 0087f664  FUN_0087f664  156 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0087f664(void)

{
  int iVar1;
  code *pcVar2;
  BOOL BVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined1 local_24 [28];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x87f670;
  SetRectEmpty((LPRECT)(in_ECX + 0x4d));
  SetRectEmpty((LPRECT)(in_ECX + 0x49));
  BVar3 = IsRectEmpty((RECT *)(in_ECX + 0x1d));
  if (((BVar3 == 0) && (iVar1 = in_ECX[0x7c], iVar1 != 0)) && (*(int *)(iVar1 + 0x20) != 0)) {
    BVar3 = IsWindowVisible(*(HWND *)(iVar1 + 0x20));
    if (BVar3 != 0) {
      pcVar2 = *(code **)(*in_ECX + 0xa4);
      guard_check_icall();
      uVar4 = (*pcVar2)();
      FUN_0079dea2(uVar4);
      local_8 = 0;
      pcVar2 = *(code **)(*in_ECX + 0x124);
      guard_check_icall(local_24);
      (*pcVar2)();
      FUN_0079dfff();
    }
  }
  return;
}




/* vtable slots: CMFCRibbonEdit[137] */
/* 0087f700  FUN_0087f700  372 bytes, 0 callers */

void FUN_0087f700(int param_1)

{
  int iVar1;
  code *pcVar2;
  BOOL BVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  CObject *pCVar6;
  CWnd *pCVar7;
  int *in_ECX;
  
  iVar1 = in_ECX[0x7c];
  if (((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) &&
     (BVar3 = IsWindowVisible(*(HWND *)(iVar1 + 0x20)), BVar3 != 0)) {
    if (param_1 == 0) {
      pHVar4 = GetParent(*(HWND *)(in_ECX[0x7c] + 0x20));
      pCVar5 = CWnd::FromHandle(pHVar4);
      pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonBar_009a1608,(CObject *)pCVar5);
      if (pCVar6 == (CObject *)0x0) {
        pHVar4 = GetParent(*(HWND *)(in_ECX[0x7c] + 0x20));
        pCVar5 = CWnd::FromHandle(pHVar4);
        pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonPanelMenuBar_009a1a6c,
                                    (CObject *)pCVar5);
        if (pCVar6 != (CObject *)0x0) {
          pHVar4 = GetParent(*(HWND *)(pCVar6 + 0x20));
          pCVar5 = CWnd::FromHandle(pHVar4);
          if (pCVar5 != (CWnd *)0x0) {
            pHVar4 = GetParent(*(HWND *)(pCVar6 + 0x20));
            pCVar5 = CWnd::FromHandle(pHVar4);
            pHVar4 = GetFocus();
            pCVar7 = CWnd::FromHandle(pHVar4);
            if (pCVar5 != pCVar7) {
              pHVar4 = GetParent(*(HWND *)(pCVar6 + 0x20));
              CWnd::FromHandle(pHVar4);
              FUN_00797df8();
            }
          }
        }
        in_ECX[0x79] = 0;
        CRichEditCtrl::SetSel((CRichEditCtrl *)in_ECX[0x7c],0,0);
        pcVar2 = *(code **)(*in_ECX + 0x1b8);
        guard_check_icall();
        (*pcVar2)();
      }
      else {
        pHVar4 = GetFocus();
        pCVar5 = CWnd::FromHandle(pHVar4);
        if (pCVar6 != (CObject *)pCVar5) {
          *(undefined4 *)(pCVar6 + 800) = 1;
          FUN_00797df8();
        }
      }
    }
    else {
      pHVar4 = GetFocus();
      pCVar5 = CWnd::FromHandle(pHVar4);
      if ((CWnd *)in_ECX[0x7c] == pCVar5) {
        return;
      }
      FUN_00797df8();
      CRichEditCtrl::SetSel((CRichEditCtrl *)in_ECX[0x7c],0,-1);
    }
    RedrawWindow(*(HWND *)(in_ECX[0x7c] + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
  }
  return;
}




/* vtable slots: CMFCRibbonEdit[74] */
/* 0087f8e9  OnShow  76 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonEdit::OnShow(int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCRibbonEdit::OnShow(CMFCRibbonEdit *this,int param_1)

{
  if ((*(int *)(this + 0x1f0) != 0) && (*(int *)(*(int *)(this + 0x1f0) + 0x20) != 0)) {
    FUN_00797f20(-(param_1 != 0) & 4);
  }
  if ((*(int *)(this + 500) != 0) && (*(int *)(*(int *)(this + 500) + 0x20) != 0)) {
    FUN_00797f20(-(param_1 != 0) & 4);
  }
  return;
}




/* vtable slots: CMFCRibbonEdit[160] */
/* 0087f935  FUN_0087f935  79 bytes, 0 callers */

undefined4 FUN_0087f935(LONG param_1,LONG param_2)

{
  code *pcVar1;
  POINT pt;
  BOOL BVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  pt.y = param_2;
  pt.x = param_1;
  BVar2 = PtInRect((RECT *)(in_ECX + 0x1d),pt);
  if (((BVar2 == 0) && (in_ECX[0x79] != 0)) && (in_ECX[0x33] == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x224);
    guard_check_icall(0);
    (*pcVar1)();
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonEdit[110] */
/* 0087ff02  Redraw  113 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonEdit::Redraw(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCRibbonEdit::Redraw(CMFCRibbonEdit *this)

{
  int iVar1;
  BOOL BVar2;
  
  FUN_0086468b();
  iVar1 = *(int *)(this + 0x1f0);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    BVar2 = IsWindowVisible(*(HWND *)(iVar1 + 0x20));
    if (BVar2 != 0) {
      RedrawWindow(*(HWND *)(*(int *)(this + 0x1f0) + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
    }
  }
  iVar1 = *(int *)(this + 500);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x20) != 0)) {
    BVar2 = IsWindowVisible(*(HWND *)(iVar1 + 0x20));
    if (BVar2 != 0) {
      RedrawWindow(*(HWND *)(*(int *)(this + 500) + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
    }
  }
  return;
}




/* vtable slots: CMFCRibbonEdit[43] */
/* 0088021f  FUN_0088021f  111 bytes, 0 callers */

undefined4 FUN_0088021f(undefined4 param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  FUN_00869cab(param_1,param_2);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(param_2 + 4),(CSimpleStringT<wchar_t,0> *)(in_ECX + 0x7b)
            );
  pcVar1 = *(code **)(*in_ECX + 600);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    uVar3 = 0x2a;
  }
  else {
    *(undefined4 *)(param_2 + 0x1c) = 0;
    uVar3 = 0x2b;
  }
  *(undefined4 *)(param_2 + 0x18) = uVar3;
  pcVar1 = *(code **)(*in_ECX + 0xd4);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != 0) {
    *(uint *)(param_2 + 0x1c) = *(uint *)(param_2 + 0x1c) | 4;
  }
  return 1;
}



