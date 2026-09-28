/* CMFCRibbonCmdUI -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonCmdUI[0] */
/* 008b2d25  FUN_008b2d25  166 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b2d25(int param_1)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(in_ECX + 0x18) = 1;
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x28) + 0xdc);
  guard_check_icall();
  uVar3 = (*pcVar1)();
  if (uVar3 != (param_1 == 0)) {
    *(uint *)(*(int *)(in_ECX + 0x28) + 0xd4) = (uint)(param_1 == 0);
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x28) + 0x238);
    guard_check_icall(param_1 != 0);
    (*pcVar1)();
    iVar2 = *(int *)(in_ECX + 0x28);
    local_18.left = *(LONG *)(iVar2 + 0x74);
    local_18.top = *(LONG *)(iVar2 + 0x78);
    local_18.right = *(LONG *)(iVar2 + 0x7c);
    local_18.bottom = *(LONG *)(iVar2 + 0x80);
    RedrawWindow(*(HWND *)(*(int *)(in_ECX + 0x14) + 0x20),&local_18,(HRGN)0x0,0x105);
  }
  return;
}




/* vtable slots: CMFCRibbonCmdUI[1] */
/* 008b41d1  FUN_008b41d1  137 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b41d1(int param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x28) + 0xe0);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 != param_1) {
    *(int *)(*(int *)(in_ECX + 0x28) + 0xd8) = param_1;
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x28) + 0x23c);
    guard_check_icall(param_1);
    (*pcVar1)();
    iVar2 = *(int *)(in_ECX + 0x28);
    local_18.left = *(LONG *)(iVar2 + 0x74);
    local_18.top = *(LONG *)(iVar2 + 0x78);
    local_18.right = *(LONG *)(iVar2 + 0x7c);
    local_18.bottom = *(LONG *)(iVar2 + 0x80);
    RedrawWindow(*(HWND *)(*(int *)(in_ECX + 0x14) + 0x20),&local_18,(HRGN)0x0,0x105);
  }
  return;
}




/* vtable slots: CMFCRibbonCmdUI[2] */
/* 008b4a19  FUN_008b4a19  49 bytes, 0 callers */

void FUN_008b4a19(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  *(int *)(in_ECX[10] + 0xdc) = param_1;
  iVar1 = *in_ECX;
  guard_check_icall(param_1 != 0);
  (**(code **)(iVar1 + 4))();
  return;
}




/* vtable slots: CMFCRibbonCmdUI[3] */
/* 008b4a4a  FUN_008b4a4a  127 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b4a4a(LPCWSTR param_1)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1 != (LPCWSTR)0x0) {
    iVar2 = lstrcmpW(*(LPCWSTR *)(*(int *)(in_ECX + 0x28) + 0x60),param_1);
    if (iVar2 != 0) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x28) + 0xb4);
      guard_check_icall(param_1);
      (*pcVar1)();
      iVar2 = *(int *)(in_ECX + 0x28);
      local_18.left = *(LONG *)(iVar2 + 0x74);
      local_18.top = *(LONG *)(iVar2 + 0x78);
      local_18.right = *(LONG *)(iVar2 + 0x7c);
      local_18.bottom = *(LONG *)(iVar2 + 0x80);
      RedrawWindow(*(HWND *)(*(int *)(in_ECX + 0x14) + 0x20),&local_18,(HRGN)0x0,0x105);
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



