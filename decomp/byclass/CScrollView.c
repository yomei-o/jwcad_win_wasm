/* CScrollView -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CScrollView[100] */
/* 007b684c  FUN_007b684c  33 bytes, 1 callers */

void FUN_007b684c(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = FUN_00793065();
    if (iVar1 != 0) {
      FUN_00797df8();
    }
  }
  return;
}




/* vtable slots: CScrollView[1] */
/* 007cc8b4  FUN_007cc8b4  51 bytes, 0 callers */

void FUN_007cc8b4(byte param_1)

{
  FUN_007cc811();
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




/* vtable slots: CScrollView[10] */
/* 007ccf22  FUN_007ccf22  6 bytes, 0 callers */

undefined ** FUN_007ccf22(void)

{
  return &PTR_LAB_00985c38;
}




/* vtable slots: CScrollView[0] */
/* 007ccf2e  FUN_007ccf2e  6 bytes, 0 callers */

undefined ** FUN_007ccf2e(void)

{
  return &PTR_s_CScrollView_009859ac;
}




/* vtable slots: CScrollView[98] */
/* 007cd3a4  FUN_007cd3a4  305 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007cd3a4(CDC *param_1,CPrintInfo *param_2)

{
  int *piVar1;
  int iVar2;
  CScrollView *in_ECX;
  int iVar3;
  undefined1 local_20 [4];
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x84) == 0) {
    iVar2 = *(int *)param_1;
    if (*(int *)(in_ECX + 0x8c) == -1) {
      guard_check_icall(8);
      (**(code **)(iVar2 + 0x34))();
      FUN_005176e0(local_20,*(undefined4 *)(in_ECX + 0x90),*(undefined4 *)(in_ECX + 0x94));
      FUN_007cde1e(local_20,*(undefined4 *)(in_ECX + 0x98),*(undefined4 *)(in_ECX + 0x9c));
    }
    else {
      guard_check_icall(*(int *)(in_ECX + 0x8c));
      (**(code **)(iVar2 + 0x34))();
    }
    iVar3 = 0;
    iVar2 = 0;
    if (*(int *)(param_1 + 0xc) == 0) {
      piVar1 = (int *)CScrollView::GetDeviceScrollPosition(in_ECX);
      iVar3 = -*piVar1;
      local_1c = -piVar1[1];
      iVar2 = local_1c;
      if (*(int *)(in_ECX + 0xb0) != 0) {
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        GetClientRect(*(HWND *)(in_ECX + 0x20),&local_18);
        if (*(int *)(in_ECX + 0x98) < local_18.right - local_18.left) {
          iVar3 = ((local_18.right - *(int *)(in_ECX + 0x98)) - local_18.left) / 2;
        }
        iVar2 = local_1c;
        if (*(int *)(in_ECX + 0x9c) < local_18.bottom - local_18.top) {
          iVar2 = ((local_18.bottom - *(int *)(in_ECX + 0x9c)) - local_18.top) / 2;
        }
      }
    }
    FUN_007b987c(local_20,iVar3,iVar2);
    CView::OnPrepareDC((CView *)in_ECX,param_1,param_2);
  }
  return;
}



