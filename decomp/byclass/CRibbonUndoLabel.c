/* CRibbonUndoLabel -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CRibbonUndoLabel[0] */
/* 008c67a1  FUN_008c67a1  6 bytes, 0 callers */

undefined ** FUN_008c67a1(void)

{
  return &PTR_s_CRibbonUndoLabel_009a4980;
}




/* vtable slots: CRibbonUndoLabel[95] */
/* 008c68ee  FUN_008c68ee  113 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c68ee(undefined4 param_1)

{
  code *pcVar1;
  int *in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = in_ECX[0x1d];
  local_18.top = in_ECX[0x1e];
  local_18.right = in_ECX[0x1f];
  local_18.bottom = in_ECX[0x20];
  InflateRect(&local_18,-5,0);
  pcVar1 = *(code **)(*in_ECX + 0x260);
  guard_check_icall(param_1,in_ECX + 0x18,local_18.left,local_18.top,local_18.right,local_18.bottom,
                    0x24,0xffffffff);
  (*pcVar1)();
  return;
}



