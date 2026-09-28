/* CDocument::XPreviewHandlerVisuals -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDocument::XPreviewHandlerVisuals[1] */
/* 007a90e3  FUN_007a90e3  50 bytes, 0 callers */

undefined4 FUN_007a90e3(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xac));
  uVar1 = FUN_007c0c2e();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XPreviewHandlerVisuals[0] */
/* 007aa864  FUN_007aa864  56 bytes, 0 callers */

undefined4 FUN_007aa864(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xac));
  uVar1 = FUN_007c0c76(param_2,param_3);
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XPreviewHandlerVisuals[2] */
/* 007aa993  FUN_007aa993  50 bytes, 0 callers */

undefined4 FUN_007aa993(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xac));
  uVar1 = FUN_007c0ca1();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XPreviewHandlerVisuals[3] */
/* 007aae16  FUN_007aae16  73 bytes, 0 callers */

undefined4 FUN_007aae16(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xac));
  *(undefined4 *)(param_1 + -0x18) = param_2;
  pcVar1 = *(code **)(*(int *)(param_1 + -200) + 0xa0);
  guard_check_icall();
  (*pcVar1)();
  guard_check_icall();
  return 0;
}




/* vtable slots: CDocument::XPreviewHandlerVisuals[4] */
/* 007aaf26  FUN_007aaf26  127 bytes, 0 callers */

undefined4 FUN_007aaf26(int param_1,LOGFONTW *param_2)

{
  code *pcVar1;
  HFONT pHVar2;
  undefined4 uVar3;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xac));
  if (param_2 == (LOGFONTW *)0x0) {
    uVar3 = 0x80004003;
  }
  else {
    pcVar1 = *(code **)(*(int *)(param_1 + -200) + 0x94);
    guard_check_icall();
    (*pcVar1)();
    CGdiObject::DeleteObject((CGdiObject *)(param_1 + -0x10));
    pHVar2 = CreateFontIndirectW(param_2);
    Attach(pHVar2);
    pcVar1 = *(code **)(*(int *)(param_1 + -200) + 0x98);
    guard_check_icall();
    (*pcVar1)();
    uVar3 = 0;
  }
  guard_check_icall();
  return uVar3;
}




/* vtable slots: CDocument::XPreviewHandlerVisuals[5] */
/* 007ab184  FUN_007ab184  73 bytes, 0 callers */

undefined4 FUN_007ab184(int param_1,undefined4 param_2)

{
  code *pcVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xac));
  *(undefined4 *)(param_1 + -0x14) = param_2;
  pcVar1 = *(code **)(*(int *)(param_1 + -200) + 0x9c);
  guard_check_icall();
  (*pcVar1)();
  guard_check_icall();
  return 0;
}



