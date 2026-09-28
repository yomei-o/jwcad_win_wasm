/* CDockContext -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDockContext[3] */
/* 007d16fa  FUN_007d16fa  37 bytes, 0 callers */

void FUN_007d16fa(byte param_1)

{
  FUN_007d15dc();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: CDockContext[0] */
/* 007d1d5a  FUN_007d1d5a  1051 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d1d5a(int param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  uint uVar3;
  undefined4 uVar4;
  int in_ECX;
  int *piVar5;
  LPRECT lprc;
  LONG *pLVar6;
  LPRECT lprc_00;
  int local_60;
  int local_5c;
  int local_58;
  LPRECT local_54;
  int local_50;
  int local_4c;
  LONG *local_48;
  LONG *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  LPRECT local_30;
  int local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(in_ECX + 0x88) = 1;
  local_2c = in_ECX;
  FUN_007d1c03();
  uVar3 = FUN_0079eb10();
  if ((uVar3 & 1) != 0) {
    FUN_0079f128(0);
  }
  iVar1 = *(int *)(in_ECX + 0x68);
  if ((*(uint *)(iVar1 + 0xb0) & 4) == 0) {
    if ((*(uint *)(iVar1 + 0xb0) & 2) == 0) {
      local_28.left = 0;
      local_28.top = 0;
      local_28.right = 0;
      local_28.bottom = 0;
      GetWindowRect(*(HWND *)(iVar1 + 0x20),&local_28);
      *(int *)(in_ECX + 4) = param_1;
      local_30 = (LPRECT)(*(uint *)(in_ECX + 0x78) & 0xa000);
      *(int *)(in_ECX + 8) = param_2;
      pcVar2 = *(code **)(**(int **)(in_ECX + 0x68) + 0x168);
      guard_check_icall(&local_50,0xffffffff,(-(local_30 != (LPRECT)0x0) & 6U) + 10);
      (*pcVar2)();
      local_44 = (LONG *)(local_2c + 0x28);
      local_48 = (LONG *)(local_2c + 0x38);
      if (local_30 == (LPRECT)0x0) {
        *local_48 = local_28.left;
        *(LONG *)(local_2c + 0x3c) = local_28.top;
        *(LONG *)(local_2c + 0x40) = local_28.right;
        *(LONG *)(local_2c + 0x44) = local_28.bottom;
        local_40 = local_28.left;
        local_3c = param_2 - (local_28.right - local_28.left) / 2;
        pLVar6 = local_44;
      }
      else {
        *local_44 = local_28.left;
        *(LONG *)(local_2c + 0x2c) = local_28.top;
        *(LONG *)(local_2c + 0x30) = local_28.right;
        *(LONG *)(local_2c + 0x34) = local_28.bottom;
        local_3c = local_28.top;
        local_40 = param_1 - (local_28.bottom - local_28.top) / 2;
        pLVar6 = local_48;
      }
      local_38 = local_50 + local_40;
      local_34 = local_4c + local_3c;
      *pLVar6 = local_40;
      local_54 = (LPRECT)(local_2c + 0x48);
      local_30 = (LPRECT)(local_2c + 0x58);
      pLVar6[1] = local_3c;
      pLVar6[2] = local_38;
      pLVar6[3] = local_34;
      local_54->left = *local_44;
      *(undefined4 *)(local_2c + 0x4c) = *(undefined4 *)(local_2c + 0x2c);
      *(undefined4 *)(local_2c + 0x50) = *(undefined4 *)(local_2c + 0x30);
      *(undefined4 *)(local_2c + 0x54) = *(undefined4 *)(local_2c + 0x34);
      local_30->left = *local_48;
      *(undefined4 *)(local_2c + 0x5c) = *(undefined4 *)(local_2c + 0x3c);
      *(undefined4 *)(local_2c + 0x60) = *(undefined4 *)(local_2c + 0x40);
      *(undefined4 *)(local_2c + 100) = *(undefined4 *)(local_2c + 0x44);
      FUN_007d1022(local_54,0xc40000,0);
      lprc_00 = local_30;
      FUN_007d1022(local_30,0xc40000,0);
      lprc = local_54;
      goto LAB_007d20e2;
    }
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(iVar1 + 0x20),&local_18);
    *(int *)(in_ECX + 4) = param_1;
    *(int *)(in_ECX + 8) = param_2;
    pcVar2 = *(code **)(**(int **)(in_ECX + 0x68) + 0x168);
    guard_check_icall(&local_28.right,0xffffffff,10);
    (*pcVar2)();
    pcVar2 = *(code **)(**(int **)(local_2c + 0x68) + 0x168);
    guard_check_icall(&local_50,0xffffffff,0x10);
    (*pcVar2)();
    local_44 = (LONG *)(local_2c + 0x28);
    *(LONG *)(local_2c + 0x28) = local_18.left;
    *(LONG *)(local_2c + 0x2c) = local_18.top;
    *(LONG *)(local_2c + 0x30) = local_28.right + local_18.left;
    *(LONG *)(local_2c + 0x34) = local_28.bottom + local_18.top;
    *(LONG *)(local_2c + 0x48) = local_18.left;
    *(LONG *)(local_2c + 0x4c) = local_18.top;
    *(LONG *)(local_2c + 0x50) = local_28.right + local_18.left;
    *(LONG *)(local_2c + 0x54) = local_28.bottom + local_18.top;
    local_58 = local_50 + local_18.left;
    local_5c = local_18.top;
    local_54 = (LPRECT)(local_4c + local_18.top);
    local_60 = local_18.left;
    local_48 = (LONG *)(local_2c + 0x38);
    *(LONG *)(local_2c + 0x38) = local_18.left;
    *(LONG *)(local_2c + 0x3c) = local_18.top;
    *(int *)(local_2c + 0x40) = local_50 + local_18.left;
    *(LPRECT *)(local_2c + 0x44) = (LPRECT)(local_4c + local_18.top);
    piVar5 = &local_60;
  }
  else {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(iVar1 + 0x20),&local_18);
    *(int *)(in_ECX + 8) = param_2;
    *(int *)(in_ECX + 4) = param_1;
    pcVar2 = *(code **)(**(int **)(in_ECX + 0x68) + 0x168);
    guard_check_icall(&local_50,0,10);
    (*pcVar2)();
    pcVar2 = *(code **)(**(int **)(local_2c + 0x68) + 0x168);
    guard_check_icall(&local_58,0,0x10);
    (*pcVar2)();
    pcVar2 = *(code **)(**(int **)(local_2c + 0x68) + 0x168);
    guard_check_icall(&local_28.right,0,6);
    (*pcVar2)();
    local_44 = (LONG *)(local_2c + 0x28);
    *(LONG *)(local_2c + 0x28) = local_18.left;
    *(LONG *)(local_2c + 0x2c) = local_18.top;
    *(int *)(local_2c + 0x30) = local_50 + local_18.left;
    *(int *)(local_2c + 0x34) = local_4c + local_18.top;
    local_48 = (LONG *)(local_2c + 0x38);
    *(LONG *)(local_2c + 0x38) = local_18.left;
    *(LONG *)(local_2c + 0x3c) = local_18.top;
    *(int *)(local_2c + 0x40) = local_58 + local_18.left;
    *(int *)(local_2c + 0x44) = (int)&local_54->left + local_18.top;
    *(LONG *)(local_2c + 0x48) = local_18.left;
    *(LONG *)(local_2c + 0x4c) = local_18.top;
    *(LONG *)(local_2c + 0x50) = local_18.left + local_28.right;
    *(LONG *)(local_2c + 0x54) = local_28.bottom + local_18.top;
    local_40 = local_18.left;
    piVar5 = &local_40;
    local_34 = local_28.bottom + local_18.top;
    local_38 = local_18.left + local_28.right;
    local_3c = local_18.top;
  }
  local_30 = (LPRECT)(local_2c + 0x58);
  ((LPRECT)(local_2c + 0x58))->left = *piVar5;
  *(int *)(local_2c + 0x5c) = piVar5[1];
  *(int *)(local_2c + 0x60) = piVar5[2];
  *(int *)(local_2c + 100) = piVar5[3];
  lprc = (LPRECT)(local_2c + 0x48);
  FUN_007d1022(lprc,0xc40000,0);
  lprc_00 = local_30;
  FUN_007d1022(local_30,0xc40000,0);
LAB_007d20e2:
  InflateRect(lprc,-DAT_00a12218,-DAT_00a1221c);
  InflateRect(lprc_00,-DAT_00a12218,-DAT_00a1221c);
  _AfxAdjustRectangle(local_44,param_1,param_2);
  _AfxAdjustRectangle(local_48,param_1,param_2);
  _AfxAdjustRectangle(lprc,param_1,param_2);
  _AfxAdjustRectangle(lprc_00,param_1,param_2);
  uVar4 = FUN_007d171f();
  *(undefined4 *)(local_2c + 0x74) = uVar4;
  FUN_007d1cbc(param_1,param_2);
  FUN_007d25b9();
  return;
}




/* vtable slots: CDockContext[1] */
/* 007d2175  FUN_007d2175  372 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d2175(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  LPRECT lprc;
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  local_1c = in_ECX;
  FUN_007d1c03();
  uVar3 = FUN_0079eb10();
  if ((uVar3 & 1) != 0) {
    FUN_0079f128(0);
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetWindowRect(*(HWND *)(*(int *)(in_ECX + 0x68) + 0x20),&local_18);
  *(undefined4 *)(in_ECX + 4) = param_2;
  *(undefined4 *)(in_ECX + 8) = param_3;
  *(undefined4 *)(in_ECX + 0x8c) = param_1;
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x68) + 0x168);
  guard_check_icall(&local_34,0,6);
  (*pcVar1)();
  iVar2 = local_1c;
  local_24 = local_34 + local_18.left;
  local_20 = local_30 + local_18.top;
  *(LONG *)(local_1c + 0x28) = local_18.left;
  *(LONG *)(local_1c + 0x2c) = local_18.top;
  *(int *)(local_1c + 0x30) = local_24;
  *(int *)(local_1c + 0x34) = local_20;
  *(LONG *)(local_1c + 0x38) = local_18.left;
  *(LONG *)(local_1c + 0x3c) = local_18.top;
  *(int *)(local_1c + 0x40) = local_24;
  *(int *)(local_1c + 0x44) = local_20;
  local_2c = local_18.left;
  local_28 = local_18.top;
  *(LONG *)(local_1c + 0x48) = local_18.left;
  *(LONG *)(local_1c + 0x4c) = local_18.top;
  *(int *)(local_1c + 0x50) = local_24;
  *(int *)(local_1c + 0x54) = local_20;
  lprc = (LPRECT)(local_1c + 0x48);
  FUN_007d1022(lprc,0xc40000,0);
  InflateRect(lprc,-DAT_00a12218,-DAT_00a1221c);
  local_20 = ((*(int *)(iVar2 + 0x54) - *(int *)(iVar2 + 0x4c)) - *(int *)(local_1c + 0x44)) +
             *(int *)(local_1c + 0x3c);
  local_24 = ((*(int *)(iVar2 + 0x50) - *(int *)(local_1c + 0x40)) - lprc->left) +
             *(int *)(local_1c + 0x38);
  local_2c = 0;
  local_28 = 0;
  *(undefined4 *)(local_1c + 0x74) = 0;
  *(undefined4 *)(local_1c + 0x58) = 0;
  *(undefined4 *)(local_1c + 0x5c) = 0;
  *(int *)(local_1c + 0x60) = local_24;
  *(int *)(local_1c + 100) = local_20;
  FUN_007d22e9(param_2,param_3);
  FUN_007d25b9();
  return;
}




/* vtable slots: CDockContext[2] */
/* 007d24a9  FUN_007d24a9  271 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d24a9(void)

{
  code *pcVar1;
  int iVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int in_ECX;
  int iVar5;
  undefined4 local_18;
  undefined4 uStack_14;
  tagPOINT local_10;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = FUN_0079a105();
  if (iVar2 == 0) {
    local_10.x = *(int *)(in_ECX + 0xa8);
    local_10.y = *(int *)(in_ECX + 0xac);
    if ((local_10.x < 0) || (local_10.y < 0)) {
      local_10.x = *(int *)(in_ECX + 0x94);
      local_10.y = *(int *)(in_ECX + 0x98);
      pHVar3 = GetParent(*(HWND *)(*(int *)(in_ECX + 0x68) + 0x20));
      pCVar4 = CWnd::FromHandle(pHVar3);
      ClientToScreen(*(HWND *)(pCVar4 + 0x20),&local_10);
    }
    FUN_007bb280(*(undefined4 *)(in_ECX + 0x68),local_10.x,local_10.y,*(undefined4 *)(in_ECX + 0xa4)
                );
  }
  else {
    iVar2 = *(int *)(in_ECX + 0x68);
    if ((*(uint *)(iVar2 + 0xb4) & 0xf000) != 0) {
      local_18 = *(undefined4 *)(in_ECX + 0x94);
      uStack_14 = *(undefined4 *)(in_ECX + 0x98);
      local_10.x = *(LONG *)(in_ECX + 0x9c);
      local_10.y = *(LONG *)(in_ECX + 0xa0);
      iVar5 = 0;
      if (*(int *)(in_ECX + 0x90) != 0) {
        iVar5 = FUN_00799e1e(*(int *)(in_ECX + 0x90));
        if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
          FUN_0078e714();
        }
        FUN_0079e8b8(&local_18);
        iVar2 = *(int *)(in_ECX + 0x68);
      }
      FUN_007bb3d1(iVar2,iVar5,&local_18);
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x6c) + 0x178);
      guard_check_icall(1);
      (*pcVar1)();
    }
  }
  return;
}



