/* _AFX_MOUSEANCHORWND -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: _AFX_MOUSEANCHORWND[1] */
/* 007cc8e7  FUN_007cc8e7  57 bytes, 0 callers */

void FUN_007cc8e7(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = _AFX_MOUSEANCHORWND::vftable;
  FUN_007908c2();
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




/* vtable slots: _AFX_MOUSEANCHORWND[10] */
/* 007ccf28  FUN_007ccf28  6 bytes, 0 callers */

undefined ** FUN_007ccf28(void)

{
  return &PTR_FUN_00985df0;
}




/* vtable slots: _AFX_MOUSEANCHORWND[69] */
/* 007ce0da  FUN_007ce0da  177 bytes, 0 callers */

void FUN_007ce0da(uint param_1,undefined4 param_2,undefined4 param_3)

{
  POINT pt;
  BOOL BVar1;
  int in_ECX;
  bool bVar2;
  tagPOINT local_c;
  
  local_c.x = in_ECX;
  local_c.y = in_ECX;
  if (param_1 < 0x203) {
    if ((((param_1 != 0x202) && (param_1 != 0x100)) &&
        ((param_1 != 0x101 && ((param_1 != 0x102 && (param_1 != 0x104)))))) && (param_1 != 0x105)) {
      bVar2 = param_1 == 0x201;
LAB_007ce118:
      if (!bVar2) goto LAB_007ce178;
    }
  }
  else if (((param_1 != 0x204) && (param_1 != 0x205)) && (param_1 != 0x207)) {
    if (param_1 != 0x208) {
      bVar2 = param_1 == 0x20a;
      goto LAB_007ce118;
    }
    local_c.x = (LONG)(short)param_3;
    local_c.y = (LONG)(short)((uint)param_3 >> 0x10);
    ClientToScreen(*(HWND *)(in_ECX + 0x20),&local_c);
    pt.y = local_c.y;
    pt.x = local_c.x;
    BVar1 = PtInRect((RECT *)(in_ECX + 0x80),pt);
    if (BVar1 != 0) goto LAB_007ce178;
  }
  *(undefined4 *)(in_ECX + 0x98) = 1;
LAB_007ce178:
  FUN_007958aa(param_1,param_2,param_3);
  return;
}



