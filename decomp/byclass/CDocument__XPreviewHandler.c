/* CDocument::XPreviewHandler -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDocument::XPreviewHandler[1] */
/* 007a90b1  FUN_007a90b1  50 bytes, 0 callers */

undefined4 FUN_007a90b1(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa8));
  uVar1 = FUN_007c0c2e();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XPreviewHandler[5] */
/* 007a9351  FUN_007a9351  136 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007a9351(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  
  piVar4 = (int *)(param_1 + -0xc4);
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa8));
  if (*(int *)(param_1 + -0x5c) != 0) {
    *(undefined4 *)(param_1 + -0x24) = 1;
    pcVar1 = *(code **)(*piVar4 + 0x78);
    guard_check_icall();
    (*pcVar1)();
    pcVar1 = *(code **)(*piVar4 + 0x104);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 != 0) {
      uVar3 = *(undefined4 *)(param_1 + -0x58);
      pcVar1 = *(code **)(*piVar4 + 0xac);
      guard_check_icall(*(undefined4 *)(param_1 + -0x5c),uVar3);
      (*pcVar1)();
      uVar3 = FUN_007a93fa(uVar3);
      return uVar3;
    }
  }
  guard_check_icall();
  return 0x80004005;
}




/* vtable slots: CDocument::XPreviewHandler[8] */
/* 007aa73c  FUN_007aa73c  72 bytes, 0 callers */

undefined4 FUN_007aa73c(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa8));
  pcVar1 = *(code **)(*(int *)(param_1 + -0xc4) + 0xfc);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CDocument::XPreviewHandler[0] */
/* 007aa82c  FUN_007aa82c  56 bytes, 0 callers */

undefined4 FUN_007aa82c(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa8));
  uVar1 = FUN_007c0c76(param_2,param_3);
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XPreviewHandler[2] */
/* 007aa961  FUN_007aa961  50 bytes, 0 callers */

undefined4 FUN_007aa961(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa8));
  uVar1 = FUN_007c0ca1();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XPreviewHandler[7] */
/* 007aaee5  FUN_007aaee5  65 bytes, 0 callers */

undefined4 FUN_007aaee5(int param_1)

{
  BOOL BVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa8));
  if (*(int *)(param_1 + -0x54) != 0) {
    BVar1 = IsWindow(*(HWND *)(*(int *)(param_1 + -0x54) + 0x20));
    if (BVar1 != 0) {
      FUN_00797df8();
    }
  }
  guard_check_icall();
  return 0;
}




/* vtable slots: CDocument::XPreviewHandler[4] */
/* 007ab08e  FUN_007ab08e  112 bytes, 0 callers */

undefined4 FUN_007ab08e(int param_1,RECT *param_2)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa8));
  if (param_2 == (RECT *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    CopyRect((LPRECT)(param_1 + -0x6c),param_2);
    uVar1 = 0;
    if (*(int *)(param_1 + -0x54) != 0) {
      FUN_00797e71(0,0,0,*(int *)(param_1 + -100) - ((LPRECT)(param_1 + -0x6c))->left,
                   *(int *)(param_1 + -0x60) - *(int *)(param_1 + -0x68),0x14);
      FUN_007ab39e(0,0,0);
    }
  }
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XPreviewHandler[3] */
/* 007ab20c  FUN_007ab20c  62 bytes, 0 callers */

undefined4 FUN_007ab20c(int param_1,undefined4 param_2,RECT *param_3)

{
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa8));
  *(undefined4 *)(param_1 + -0x70) = param_2;
  if (param_3 != (RECT *)0x0) {
    CopyRect((LPRECT)(param_1 + -0x6c),param_3);
  }
  guard_check_icall();
  return 0;
}




/* vtable slots: CDocument::XPreviewHandler[9] */
/* 007ab313  FUN_007ab313  72 bytes, 0 callers */

undefined4 FUN_007ab313(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa8));
  pcVar1 = *(code **)(*(int *)(param_1 + -0xc4) + 0x100);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CDocument::XPreviewHandler[6] */
/* 007ab35b  FUN_007ab35b  67 bytes, 0 callers */

undefined4 FUN_007ab35b(int param_1)

{
  code *pcVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa8));
  pcVar1 = *(code **)(*(int *)(param_1 + -0xc4) + 0xa8);
  guard_check_icall();
  (*pcVar1)();
  guard_check_icall();
  return 0;
}



