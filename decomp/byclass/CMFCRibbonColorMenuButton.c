/* CMFCRibbonColorMenuButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonColorMenuButton[1], CMFCRibbonDefaultPanelButton[1] */
/* 0086a2b1  FUN_0086a2b1  51 bytes, 0 callers */

void FUN_0086a2b1(byte param_1)

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




/* vtable slots: CMFCRibbonColorMenuButton[90] */
/* 008a06a7  FUN_008a06a7  74 bytes, 0 callers */

void FUN_008a06a7(int *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_0086612f(param_1);
  pcVar1 = *(code **)(*param_1 + 0xe0);
  guard_check_icall();
  uVar2 = (*pcVar1)();
  *(undefined4 *)(in_ECX + 0xd8) = uVar2;
  *(int *)(in_ECX + 0x1c4) = param_1[0x71];
  *(int *)(in_ECX + 0x1c8) = param_1[0x72];
  return;
}




/* vtable slots: CMFCRibbonColorMenuButton[0] */
/* 008a0a1c  FUN_008a0a1c  6 bytes, 0 callers */

undefined ** FUN_008a0a1c(void)

{
  return &PTR_s_CMFCRibbonColorMenuButton_0099f0cc;
}




/* vtable slots: CMFCRibbonColorMenuButton[95] */
/* 008a0b60  FUN_008a0b60  680 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a0b60(int *param_1)

{
  RECT *lprc;
  BOOL BVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  HANDLE pvVar6;
  int *in_ECX;
  HDC hdc;
  code *pcVar7;
  int iVar8;
  undefined1 local_3c [4];
  HICON local_38;
  code *local_34;
  int *local_30;
  int *local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  lprc = (RECT *)(in_ECX + 0x1d);
  local_30 = param_1;
  local_2c = in_ECX;
  BVar1 = IsRectEmpty(lprc);
  if (BVar1 != 0) {
    return;
  }
  piVar2 = (int *)FUN_007c2574();
  pcVar7 = *(code **)(*piVar2 + 0x2dc);
  guard_check_icall();
  iVar3 = (*pcVar7)();
  piVar4 = (int *)FUN_007fe1cf(local_3c);
  piVar2 = local_30;
  local_38 = (HICON)(*piVar4 + iVar3 * 2 + 2);
  pcVar7 = *(code **)(*local_2c + 0x270);
  guard_check_icall(local_30);
  iVar3 = (*pcVar7)();
  local_34 = (code *)0xffffffff;
  if (local_2c[0x35] == 0) {
    if (iVar3 == -1) goto LAB_008a0c3e;
    pcVar7 = *(code **)(*piVar2 + 0x30);
  }
  else {
    local_34 = *(code **)(*piVar2 + 0x30);
    pcVar7 = local_34;
    if (iVar3 == -1) {
      piVar2 = (int *)FUN_007c2574();
      pcVar7 = *(code **)(*piVar2 + 0xc4);
      guard_check_icall();
      iVar3 = (*pcVar7)();
      pcVar7 = local_34;
    }
  }
  guard_check_icall(iVar3);
  local_34 = (code *)(*pcVar7)();
LAB_008a0c3e:
  piVar4 = local_2c;
  local_28.top = in_ECX[0x1e];
  local_28.right = in_ECX[0x1f];
  local_28.bottom = in_ECX[0x20];
  local_28.left = lprc->left + (int)local_38 + 3;
  InflateRect(&local_28,-local_2c[0x47],-local_2c[0x47]);
  piVar2 = local_30;
  FUN_007c2378(piVar4 + 0x18,&local_28,0x8024);
  if (local_34 != (code *)0xffffffff) {
    pcVar7 = *(code **)(*piVar2 + 0x30);
    guard_check_icall(local_34);
    (*pcVar7)();
  }
  if (local_2c[0x72] == 2) {
    iVar3 = lprc->left;
    local_18.top = in_ECX[0x1e];
    local_18.right = in_ECX[0x1f];
    local_18.bottom = in_ECX[0x20];
    iVar8 = (int)local_38 + iVar3;
    local_18.left = iVar3;
    iVar5 = FUN_007c2511();
    if (*(int *)(iVar5 + 0x110) == 0) {
      iVar3 = FUN_0079dd6d();
      pvVar6 = LoadImageW(*(HINSTANCE *)(iVar3 + 0xc),(LPCWSTR)0x42d1,1,0x10,0x10,0x8000);
      iVar3 = FUN_007c2511();
      *(HANDLE *)(iVar3 + 0x110) = pvVar6;
      iVar3 = local_18.left;
    }
    iVar5 = FUN_007c2511();
    local_38 = *(HICON *)(iVar5 + 0x110);
    hdc = (HDC)0x0;
    if (local_30 != (int *)0x0) {
      hdc = (HDC)local_30[1];
    }
    DrawIconEx(hdc,((iVar8 - iVar3) + -0x10) / 2 + iVar3,
               ((local_18.bottom - local_18.top) + -0x10) / 2 + local_18.top,local_38,0x10,0x10,0,
               (HBRUSH)0x0,3);
  }
  else if (local_2c[0x72] == 1) {
    local_18.left = lprc->left;
    local_18.top = in_ECX[0x1e];
    local_18.bottom = in_ECX[0x20];
    local_18.right = local_18.left + (int)local_38;
    InflateRect(&local_18,-2,-2);
    local_18.bottom = local_18.bottom - local_18.top;
    iVar3 = local_18.right - local_18.left;
    if (local_18.bottom <= local_18.right - local_18.left) {
      iVar3 = local_18.bottom;
    }
    local_18.left = local_18.left + ((local_18.right - iVar3) - local_18.left) / 2;
    local_18.top = local_18.top + (local_18.bottom - iVar3) / 2;
    local_18.right = local_18.left + iVar3;
    local_18.bottom = local_18.top + iVar3;
    local_38 = (HICON)local_2c[0x71];
    pcVar7 = *(code **)(*(int *)local_38 + 0x2a4);
    guard_check_icall(local_30,local_18.left,local_18.top,local_18.right,local_18.bottom,0xffffffff,
                      0,0xffffffff);
    (*pcVar7)();
  }
  return;
}



