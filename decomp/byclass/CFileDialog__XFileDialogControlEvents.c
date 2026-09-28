/* CFileDialog::XFileDialogControlEvents -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFileDialog::XFileDialogControlEvents[1] */
/* 007b3948  FUN_007b3948  50 bytes, 0 callers */

undefined4 FUN_007b3948(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c4));
  uVar1 = FUN_007c0c2e();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CFileDialog::XFileDialogControlEvents[4] */
/* 007b44f0  FUN_007b44f0  70 bytes, 0 callers */

undefined4 FUN_007b44f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c4));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x4e0) + 0x1b0);
  guard_check_icall(param_3);
  (*pcVar1)();
  guard_check_icall();
  return 0;
}




/* vtable slots: CFileDialog::XFileDialogControlEvents[5] */
/* 007b4536  FUN_007b4536  73 bytes, 0 callers */

undefined4 FUN_007b4536(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c4));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x4e0) + 0x1b4);
  guard_check_icall(param_3,param_4);
  (*pcVar1)();
  guard_check_icall();
  return 0;
}




/* vtable slots: CFileDialog::XFileDialogControlEvents[6] */
/* 007b457f  FUN_007b457f  70 bytes, 0 callers */

undefined4 FUN_007b457f(int param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c4));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x4e0) + 0x1b8);
  guard_check_icall(param_3);
  (*pcVar1)();
  guard_check_icall();
  return 0;
}




/* vtable slots: CFileDialog::XFileDialogControlEvents[3] */
/* 007b46cc  FUN_007b46cc  73 bytes, 0 callers */

undefined4 FUN_007b46cc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c4));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x4e0) + 0x1ac);
  guard_check_icall(param_3,param_4);
  (*pcVar1)();
  guard_check_icall();
  return 0;
}




/* vtable slots: CFileDialog::XFileDialogControlEvents[0] */
/* 007b49a2  FUN_007b49a2  67 bytes, 0 callers */

undefined4 FUN_007b49a2(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c4));
  if (param_3 != 0) {
    uVar1 = FUN_007c0c76(param_2,param_3);
    guard_check_icall();
    return uVar1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CFileDialog::XFileDialogControlEvents[2] */
/* 007b4a1e  FUN_007b4a1e  50 bytes, 0 callers */

undefined4 FUN_007b4a1e(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c4));
  uVar1 = FUN_007c0ca1();
  guard_check_icall();
  return uVar1;
}



