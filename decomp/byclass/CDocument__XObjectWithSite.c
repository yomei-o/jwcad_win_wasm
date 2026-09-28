/* CDocument::XObjectWithSite -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDocument::XObjectWithSite[1] */
/* 007a904d  FUN_007a904d  50 bytes, 0 callers */

undefined4 FUN_007a904d(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xb0));
  uVar1 = FUN_007c0c2e();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XObjectWithSite[4] */
/* 007a9804  FUN_007a9804  89 bytes, 0 callers */

undefined4 FUN_007a9804(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined4 uVar3;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xb0));
  uVar3 = 0x80004003;
  if (param_3 != (undefined4 *)0x0) {
    puVar1 = *(undefined4 **)(param_1 + -0x58);
    if (puVar1 == (undefined4 *)0x0) {
      *param_3 = 0;
      uVar3 = 0x80004005;
    }
    else {
      pcVar2 = *(code **)*puVar1;
      guard_check_icall(puVar1,param_2,param_3);
      uVar3 = (*pcVar2)();
    }
  }
  guard_check_icall();
  return uVar3;
}




/* vtable slots: CDocument::XObjectWithSite[0] */
/* 007aa7bc  FUN_007aa7bc  56 bytes, 0 callers */

undefined4 FUN_007aa7bc(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xb0));
  uVar1 = FUN_007c0c76(param_2,param_3);
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XObjectWithSite[2] */
/* 007aa8fd  FUN_007aa8fd  50 bytes, 0 callers */

undefined4 FUN_007aa8fd(int param_1)

{
  undefined4 uVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xb0));
  uVar1 = FUN_007c0ca1();
  guard_check_icall();
  return uVar1;
}




/* vtable slots: CDocument::XObjectWithSite[3] */
/* 007ab0fe  FUN_007ab0fe  134 bytes, 0 callers */

undefined4 FUN_007ab0fe(int param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  undefined4 *puVar4;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0xb0));
  FUN_007a8f5f(param_2);
  piVar1 = (int *)(param_1 + 8);
  piVar2 = (int *)*piVar1;
  if (piVar2 != (int *)0x0) {
    pcVar3 = *(code **)(*piVar2 + 8);
    guard_check_icall(piVar2);
    (*pcVar3)();
    *piVar1 = 0;
  }
  puVar4 = *(undefined4 **)(param_1 + -0x58);
  if (puVar4 != (undefined4 *)0x0) {
    pcVar3 = *(code **)*puVar4;
    guard_check_icall(puVar4,&DAT_0097f840,piVar1);
    (*pcVar3)();
  }
  pcVar3 = *(code **)(*(int *)(param_1 + -0xcc) + 0xa4);
  guard_check_icall();
  (*pcVar3)();
  guard_check_icall();
  return 0;
}



