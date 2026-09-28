/* CMFCToolBarDropTarget -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarDropTarget[1] */
/* 00880a15  FUN_00880a15  54 bytes, 0 callers */

void FUN_00880a15(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCToolBarDropTarget::vftable;
  FUN_0088bbef();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CMFCToolBarDropTarget[10] */
/* 00880a4b  FUN_00880a4b  6 bytes, 0 callers */

undefined ** FUN_00880a4b(void)

{
  return &PTR_FUN_0099a50c;
}




/* vtable slots: CMFCToolBarDropTarget[21] */
/* 00880a51  FUN_00880a51  94 bytes, 0 callers */

undefined4
FUN_00880a51(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((DAT_00a127ac != 0) && (iVar2 = FUN_007b9bc6(DAT_00a13be8,0), iVar2 != 0)) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x3d0);
    guard_check_icall(param_2,param_3,param_4,param_5);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  return 0;
}




/* vtable slots: CMFCToolBarDropTarget[25] */
/* 00880ab0  FUN_00880ab0  39 bytes, 0 callers */

void FUN_00880ab0(void)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x38) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x3d4);
    guard_check_icall();
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCToolBarDropTarget[22] */
/* 00880ad8  FUN_00880ad8  94 bytes, 0 callers */

undefined4
FUN_00880ad8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((DAT_00a127ac != 0) && (iVar2 = FUN_007b9bc6(DAT_00a13be8,0), iVar2 != 0)) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x3d8);
    guard_check_icall(param_2,param_3,param_4,param_5);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  return 0;
}




/* vtable slots: CMFCToolBarDropTarget[24] */
/* 00880b37  FUN_00880b37  101 bytes, 0 callers */

uint FUN_00880b37(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  if ((DAT_00a127ac != 0) && (iVar2 = FUN_007b9bc6(DAT_00a13be8,0), iVar2 != 0)) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x38) + 0x3cc);
    guard_check_icall(param_2,param_3,param_5,param_6);
    iVar2 = (*pcVar1)();
    return -(uint)(iVar2 != 0) & param_3;
  }
  return 0;
}



