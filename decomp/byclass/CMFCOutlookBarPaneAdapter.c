/* CMFCOutlookBarPaneAdapter -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCOutlookBarPaneAdapter[1] */
/* 0089a0d5  FUN_0089a0d5  57 bytes, 0 callers */

void FUN_0089a0d5(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCOutlookBarPaneAdapter::vftable;
  FUN_0085ec08();
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




/* vtable slots: CMFCOutlookBarPaneAdapter[10] */
/* 0089a10e  FUN_0089a10e  6 bytes, 0 callers */

undefined ** FUN_0089a10e(void)

{
  return &PTR_FUN_0099db10;
}




/* vtable slots: CMFCOutlookBarPaneAdapter[0] */
/* 0089a114  FUN_0089a114  6 bytes, 0 callers */

undefined ** FUN_0089a114(void)

{
  return &PTR_s_CMFCOutlookBarPaneAdapter_00a00bcc;
}



