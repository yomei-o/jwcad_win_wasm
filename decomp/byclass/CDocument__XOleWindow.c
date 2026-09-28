/* CDocument::XOleWindow -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDocument::XOleWindow[1] */
/* 007a907f  FUN_007a907f  50 bytes, 0 callers */

undefined4 FUN_007a907f(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xb4));
  uVar1 = FUN_007c0c2e();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XOleWindow[4] */
/* 007a92ce  FUN_007a92ce  38 bytes, 0 callers */

undefined4 FUN_007a92ce(int param_1)

{
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xb4));
  guard_check_icall();
  return 0x80004001;
}




/* vtable slots: CDocument::XOleWindow[3] */
/* 007a99ab  FUN_007a99ab  58 bytes, 0 callers */

undefined4 FUN_007a99ab(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xb4));
  uVar1 = 0x80070057;
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = 0;
    *param_2 = *(undefined4 *)(param_1 + -0x7c);
  }
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XOleWindow[0] */
/* 007aa7f4  FUN_007aa7f4  56 bytes, 0 callers */

undefined4 FUN_007aa7f4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xb4));
  uVar1 = FUN_007c0c76(param_2,param_3);
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XOleWindow[2] */
/* 007aa92f  FUN_007aa92f  50 bytes, 0 callers */

undefined4 FUN_007aa92f(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xb4));
  uVar1 = FUN_007c0ca1();
  guard_check_icall();
  return uVar1;
}



