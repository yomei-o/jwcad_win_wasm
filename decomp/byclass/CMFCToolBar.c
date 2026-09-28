/* CMFCToolBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBar[269], CPaneTrackingWnd[89] */
/* 00660041  FUN_00660041  1636 bytes, 0 callers */

void FUN_00660041(void)

{
  undefined4 in_ECX;
  int unaff_EBP;
  
  FUN_006568a0(unaff_EBP + -0xe030,in_ECX);
  FUN_004988c0();
  FUN_00660720(unaff_EBP + -0x14700,unaff_EBP + -0x14770,*(undefined4 *)(unaff_EBP + -0xde00),
               *(undefined4 *)(unaff_EBP + -0xddfc),*(undefined4 *)(unaff_EBP + -0xddf8));
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_0041fd70();
  FUN_0065fcf3();
  return;
}



