/* CCmdUI -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CCmdUI[0] */
/* 0078fff6  FUN_0078fff6  143 bytes, 0 callers */

void FUN_0078fff6(int param_1)

{
  HWND pHVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    if (*(int *)(in_ECX + 0x14) == 0) goto LAB_00790080;
    if (param_1 == 0) {
      pHVar2 = *(HWND *)(*(int *)(in_ECX + 0x14) + 0x20);
      pHVar1 = GetFocus();
      if (pHVar1 == pHVar2) {
        pHVar2 = GetParent(pHVar2);
        pCVar3 = CWnd::FromHandle(pHVar2);
        SendMessageW(*(HWND *)(pCVar3 + 0x20),0x28,0,0);
      }
    }
    FUN_007979e8(param_1);
  }
  else {
    if (*(int *)(in_ECX + 0x10) != 0) {
      return;
    }
    if (*(uint *)(in_ECX + 0x20) <= *(uint *)(in_ECX + 8)) {
LAB_00790080:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    EnableMenuItem(*(HMENU *)(*(int *)(in_ECX + 0xc) + 4),*(uint *)(in_ECX + 8),
                   (-(uint)(param_1 != 0) & 0xfffffffd) + 0x403);
  }
  *(undefined4 *)(in_ECX + 0x18) = 1;
  return;
}




/* vtable slots: CCmdUI[1], CMFCColorBarCmdUI[1] */
/* 007903e1  FUN_007903e1  119 bytes, 0 callers */

void FUN_007903e1(WPARAM param_1)

{
  uint uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    if (*(int *)(in_ECX + 0x14) == 0) {
LAB_00790453:
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    uVar1 = SendMessageW(*(HWND *)(*(int *)(in_ECX + 0x14) + 0x20),0x87,0,0);
    if ((uVar1 & 0x2000) != 0) {
      SendMessageW(*(HWND *)(*(int *)(in_ECX + 0x14) + 0x20),0xf1,param_1,0);
    }
  }
  else if (*(int *)(in_ECX + 0x10) == 0) {
    if (*(uint *)(in_ECX + 0x20) <= *(uint *)(in_ECX + 8)) goto LAB_00790453;
    CheckMenuItem(*(HMENU *)(*(int *)(in_ECX + 0xc) + 4),*(uint *)(in_ECX + 8),
                  (uint)(param_1 != 0) * 8 + 0x400);
  }
  return;
}




/* vtable slots: CCmdUI[2], CMFCColorBarCmdUI[2], CStatusCmdUI[2], CToolCmdUI[2] */
/* 00790459  FUN_00790459  109 bytes, 0 callers */

void FUN_00790459(int param_1)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 4);
  guard_check_icall(param_1 != 0);
  (*pcVar1)();
  if ((in_ECX[3] != 0) && (in_ECX[4] == 0)) {
    if ((uint)in_ECX[8] <= (uint)in_ECX[2]) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    if ((DAT_00a12258 == (HBITMAP)0x0) && (FUN_00790528(), DAT_00a12258 == (HBITMAP)0x0)) {
      return;
    }
    SetMenuItemBitmaps(*(HMENU *)(in_ECX[3] + 4),in_ECX[2],0x400,(HBITMAP)0x0,DAT_00a12258);
  }
  return;
}




/* vtable slots: CCmdUI[3], CMFCColorBarCmdUI[3] */
/* 007904c7  FUN_007904c7  96 bytes, 0 callers */

void FUN_007904c7(LPWSTR param_1)

{
  int in_ECX;
  MENUITEMINFOW local_34;
  
  if (param_1 != (LPWSTR)0x0) {
    if (*(int *)(in_ECX + 0xc) == 0) {
      if (*(int *)(in_ECX + 0x14) == 0) goto LAB_00790522;
      FUN_007c16be(*(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20),param_1);
    }
    else if (*(int *)(in_ECX + 0x10) == 0) {
      if (*(uint *)(in_ECX + 0x20) <= *(uint *)(in_ECX + 8)) goto LAB_00790522;
      local_34.dwTypeData = param_1;
      local_34.cbSize = 0x30;
      local_34.fMask = 0x40;
      SetMenuItemInfoW(*(HMENU *)(*(int *)(in_ECX + 0xc) + 4),*(uint *)(in_ECX + 8),1,&local_34);
    }
    return;
  }
LAB_00790522:
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



