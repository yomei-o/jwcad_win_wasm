/* CDocument::XInitializeWithStream -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDocument::XInitializeWithStream[1] */
/* 007a901b  FUN_007a901b  50 bytes, 0 callers */

undefined4 FUN_007a901b(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa4));
  uVar1 = FUN_007c0c2e();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XInitializeWithStream[3] */
/* 007a99e5  FUN_007a99e5  112 bytes, 0 callers */

undefined4 FUN_007a99e5(int param_1,int *param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa4));
  if (param_2 == (int *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    uVar2 = 0;
    *(undefined4 *)(param_1 + -0x18) = 1;
    *(undefined4 *)(param_1 + -0x24) = 0;
    pcVar1 = *(code **)(*param_2 + 4);
    guard_check_icall(param_2);
    (*pcVar1)();
    *(int **)(param_1 + -0x58) = param_2;
    *(undefined4 *)(param_1 + -0x54) = param_3;
    if (*(int *)(param_1 + -0x70) == 0) {
      FUN_007c37d5();
      *(undefined4 *)(param_1 + -0x70) = 1;
    }
  }
  guard_check_icall();
  return uVar2;
}




/* vtable slots: CDocument::XInitializeWithStream[0] */
/* 007aa784  FUN_007aa784  56 bytes, 0 callers */

undefined4 FUN_007aa784(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa4));
  uVar1 = FUN_007c0c76(param_2,param_3);
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XInitializeWithStream[2] */
/* 007aa8cb  FUN_007aa8cb  50 bytes, 0 callers */

undefined4 FUN_007aa8cb(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xa4));
  uVar1 = FUN_007c0ca1();
  guard_check_icall();
  return uVar1;
}



