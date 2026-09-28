/* CMDITabProxyWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMDITabProxyWnd[1] */
/* 0084f8ac  FUN_0084f8ac  57 bytes, 0 callers */

void FUN_0084f8ac(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMDITabProxyWnd::vftable;
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




/* vtable slots: CMDITabProxyWnd[10] */
/* 008502da  FUN_008502da  6 bytes, 0 callers */

undefined ** FUN_008502da(void)

{
  return &PTR_FUN_00995aa0;
}




/* vtable slots: CMDITabProxyWnd[0] */
/* 008502e6  FUN_008502e6  6 bytes, 0 callers */

undefined ** FUN_008502e6(void)

{
  return &PTR_s_CMDITabProxyWnd_0099538c;
}



