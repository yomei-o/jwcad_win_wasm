/* CEnumArray::XEnumVOID -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CEnumArray::XEnumVOID[1] */
/* 007d0705  FUN_007d0705  18 bytes, 0 callers */

void FUN_007d0705(void)

{
  FUN_007c0c2e();
  return;
}




/* vtable slots: CEnumArray::XEnumVOID[6] */
/* 007d0717  FUN_007d0717  93 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */

void FUN_007d0717(int param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x1c));
  *param_2 = 0;
  pcVar1 = *(code **)(*(int *)(param_1 + -0x38) + 0x5c);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  iVar3 = *(int *)(param_1 + -0x14);
  if (iVar3 == 0) {
    iVar3 = param_1 + -0x38;
  }
  *(int *)(iVar2 + 0x24) = iVar3;
  LOCK();
  *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + 1;
  UNLOCK();
  *param_2 = iVar2 + 0x38;
  FUN_007d0785();
  return;
}




/* vtable slots: CEnumArray::XEnumVOID[3] */
/* 007d0797  FUN_007d0797  142 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_007d0797(int param_1,int param_2,int param_3,int *param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x1c));
  iVar3 = param_2;
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  for (; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar1 = *(code **)(*(int *)(param_1 + -0x38) + 0x50);
    guard_check_icall(param_3);
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) break;
    param_3 = param_3 + *(int *)(param_1 + -0x18);
  }
  if (param_4 != (int *)0x0) {
    *param_4 = param_2 - iVar3;
  }
  guard_check_icall();
  return iVar3 != 0;
}




/* vtable slots: CEnumArray::XEnumVOID[0] */
/* 007d08cf  FUN_007d08cf  24 bytes, 0 callers */

void FUN_007d08cf(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007c0c76(param_2,param_3);
  return;
}




/* vtable slots: CEnumArray::XEnumVOID[2] */
/* 007d08e7  FUN_007d08e7  18 bytes, 0 callers */

void FUN_007d08e7(void)

{
  FUN_007c0ca1();
  return;
}




/* vtable slots: CEnumArray::XEnumVOID[5] */
/* 007d08f9  FUN_007d08f9  55 bytes, 0 callers */

undefined4 FUN_007d08f9(int param_1)

{
  code *pcVar1;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x1c));
  pcVar1 = *(code **)(*(int *)(param_1 + -0x38) + 0x58);
  guard_check_icall();
  (*pcVar1)();
  guard_check_icall();
  return 0;
}




/* vtable slots: CEnumArray::XEnumVOID[4] */
/* 007d0930  FUN_007d0930  93 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_007d0930(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  
  FUN_0079d9b9(*(undefined4 *)(param_1 + -0x1c));
  for (; param_2 != 0; param_2 = param_2 + -1) {
    pcVar1 = *(code **)(*(int *)(param_1 + -0x38) + 0x54);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) break;
  }
  guard_check_icall();
  return param_2 != 0;
}



