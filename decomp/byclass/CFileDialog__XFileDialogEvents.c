/* CFileDialog::XFileDialogEvents -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFileDialog::XFileDialogEvents[1] */
/* 007b397a  FUN_007b397a  50 bytes, 0 callers */

undefined4 FUN_007b397a(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  uVar1 = FUN_007c0c2e();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CFileDialog::XFileDialogEvents[3] */
/* 007b45c5  FUN_007b45c5  101 bytes, 0 callers */

bool FUN_007b45c5(int param_1)

{
  code *pcVar1;
  int iVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x4dc) + 0x18c);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(param_1 + -0x4dc) + 0x194);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  guard_check_icall();
  return iVar2 != 0;
}




/* vtable slots: CFileDialog::XFileDialogEvents[5] */
/* 007b462a  FUN_007b462a  67 bytes, 0 callers */

undefined4 FUN_007b462a(int param_1)

{
  code *pcVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x4dc) + 0x1a4);
  guard_check_icall();
  (*pcVar1)();
  guard_check_icall();
  return 0;
}




/* vtable slots: CFileDialog::XFileDialogEvents[4] */
/* 007b466d  FUN_007b466d  35 bytes, 0 callers */

undefined4 FUN_007b466d(int param_1)

{
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  guard_check_icall();
  return 0;
}




/* vtable slots: CFileDialog::XFileDialogEvents[10] */
/* 007b4690  FUN_007b4690  35 bytes, 0 callers */

undefined4 FUN_007b4690(int param_1)

{
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  guard_check_icall();
  return 0;
}




/* vtable slots: CFileDialog::XFileDialogEvents[9] */
/* 007b4816  FUN_007b4816  35 bytes, 0 callers */

undefined4 FUN_007b4816(int param_1)

{
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  guard_check_icall();
  return 0;
}




/* vtable slots: CFileDialog::XFileDialogEvents[6] */
/* 007b4839  FUN_007b4839  67 bytes, 0 callers */

undefined4 FUN_007b4839(int param_1)

{
  code *pcVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x4dc) + 0x1a0);
  guard_check_icall();
  (*pcVar1)();
  guard_check_icall();
  return 0;
}




/* vtable slots: CFileDialog::XFileDialogEvents[7] */
/* 007b487c  FUN_007b487c  183 bytes, 0 callers */

undefined4 FUN_007b487c(int param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_10;
  LPVOID local_c [2];
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  local_c[0] = (LPVOID)0x0;
  if (param_3 != (int *)0x0) {
    pcVar1 = *(code **)(*param_3 + 0x14);
    guard_check_icall(param_3,0x80058000,local_c);
    iVar2 = (*pcVar1)();
    if (-1 < iVar2) {
      CStringT<>(local_c[0]);
      CoTaskMemFree(local_c[0]);
      pcVar1 = *(code **)(*(int *)(param_1 + -0x4dc) + 400);
      guard_check_icall(local_10);
      iVar2 = (*pcVar1)();
      if (param_4 != (undefined4 *)0x0) {
        if (iVar2 == 0) {
          *param_4 = 0;
        }
        else {
          uVar3 = 1;
          if (iVar2 != 1) {
            uVar3 = 2;
            if (iVar2 != 2) goto LAB_007b4915;
          }
          *param_4 = uVar3;
        }
LAB_007b4915:
        FUN_00406b10();
        guard_check_icall();
        return 0;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CFileDialog::XFileDialogEvents[8] */
/* 007b4934  FUN_007b4934  110 bytes, 0 callers */

undefined4 FUN_007b4934(int param_1)

{
  code *pcVar1;
  undefined4 local_c [2];
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  local_c[0] = 0;
  pcVar1 = *(code **)(**(int **)(param_1 + -0x420) + 0x18);
  guard_check_icall(*(int **)(param_1 + -0x420),local_c);
  (*pcVar1)();
  *(undefined4 *)(*(int *)(param_1 + -0x434) + 0x18) = local_c[0];
  pcVar1 = *(code **)(*(int *)(param_1 + -0x4dc) + 0x1a8);
  guard_check_icall();
  (*pcVar1)();
  guard_check_icall();
  return 0;
}




/* vtable slots: CFileDialog::XFileDialogEvents[0] */
/* 007b49e6  FUN_007b49e6  56 bytes, 0 callers */

undefined4 FUN_007b49e6(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  uVar1 = FUN_007c0c76(param_2,param_3);
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CFileDialog::XFileDialogEvents[2] */
/* 007b4a50  FUN_007b4a50  50 bytes, 0 callers */

undefined4 FUN_007b4a50(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x4c0));
  uVar1 = FUN_007c0ca1();
  guard_check_icall();
  return uVar1;
}



