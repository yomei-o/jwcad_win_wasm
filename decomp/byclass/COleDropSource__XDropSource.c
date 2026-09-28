/* COleDropSource::XDropSource -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleDropSource::XDropSource[1] */
/* 007d0aa1  FUN_007d0aa1  18 bytes, 0 callers */

void FUN_007d0aa1(void)

{
  FUN_007c0c2e();
  return;
}




/* vtable slots: COleDropSource::XDropSource[4] */
/* 007d0bb8  FUN_007d0bb8  60 bytes, 0 callers */

undefined4 FUN_007d0bb8(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -4));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x20) + 0x54);
  guard_check_icall(param_2);
  uVar2 = (*pcVar1)();
  guard_check_icall();
  return uVar2;
}




/* vtable slots: COleDropSource::XDropSource[3] */
/* 007d0d4a  FUN_007d0d4a  39 bytes, 0 callers */

void FUN_007d0d4a(int param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  
  pcVar1 = *(code **)(*(int *)(param_1 + -0x20) + 0x50);
  guard_check_icall(param_2,param_3);
  (*pcVar1)();
  return;
}




/* vtable slots: COleDropSource::XDropSource[0] */
/* 007d0d71  FUN_007d0d71  24 bytes, 0 callers */

void FUN_007d0d71(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007c0c76(param_2,param_3);
  return;
}




/* vtable slots: COleDropSource::XDropSource[2] */
/* 007d0d89  FUN_007d0d89  18 bytes, 0 callers */

void FUN_007d0d89(void)

{
  FUN_007c0ca1();
  return;
}



