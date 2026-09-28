/* CWinApp -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CWinApp[22], CWinThread[22] */
/* 0079d649  FUN_0079d649  16 bytes, 1 callers */

void FUN_0079d649(undefined4 param_1)

{
  FUN_0079d230(param_1);
  return;
}




/* vtable slots: CWinApp[1] */
/* 007b1114  FUN_007b1114  51 bytes, 0 callers */

void FUN_007b1114(byte param_1)

{
  FUN_007b0e22();
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




/* vtable slots: CWinApp[10] */
/* 007b14da  FUN_007b14da  6 bytes, 0 callers */

undefined ** FUN_007b14da(void)

{
  return &PTR_FUN_009804a8;
}




/* vtable slots: CWinApp[20] */
/* 007b158d  FUN_007b158d  193 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007b158d(void)

{
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x7b1599;
  pcVar1 = *(code **)(*in_ECX + 0x94);
  guard_check_icall();
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x108);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  in_ECX[0x20] = iVar3;
  if (iVar3 != 0) {
    iVar4 = FUN_0079dd6d();
    *(int *)(iVar4 + 0xc) = iVar3;
    DAT_00a140c4 = in_ECX[0x20];
    LOCK();
    UNLOCK();
  }
  pcVar1 = *(code **)(*in_ECX + 0xd8);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0xd0);
    CStringT<>(&DAT_00956338);
    local_8 = 0;
    pcVar2 = *(code **)(*in_ECX + 0xdc);
    guard_check_icall();
    uVar5 = (*pcVar2)();
    guard_check_icall(uVar5,local_14);
    (*pcVar1)();
    FUN_00406b10();
  }
  return 1;
}




/* vtable slots: CWinApp[24] */
/* 007b175d  FUN_007b175d  190 bytes, 1 callers */

bool FUN_007b175d(int param_1)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  int local_8;
  
  if (param_1 < 1) {
    FUN_0079d526(param_1);
    local_8 = 0;
    if ((int *)in_ECX[0x17] != (int *)0x0) {
      pcVar1 = *(code **)(*(int *)in_ECX[0x17] + 0x10);
      guard_check_icall();
      local_8 = (*pcVar1)();
      while (local_8 != 0) {
        pcVar1 = *(code **)(*(int *)in_ECX[0x17] + 0x14);
        guard_check_icall(&local_8);
        piVar2 = (int *)(*pcVar1)();
        pcVar1 = *(code **)(*piVar2 + 0x8c);
        guard_check_icall();
        (*pcVar1)();
      }
    }
    pcVar1 = *(code **)(*in_ECX + 0xfc);
    guard_check_icall();
    piVar2 = (int *)(*pcVar1)();
    if (piVar2 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar2 + 0x2c);
      guard_check_icall(0);
      (*pcVar1)();
    }
  }
  else if (param_1 == 1) {
    FUN_0079d526(1);
  }
  return param_1 < 1;
}




/* vtable slots: CWinApp[41] */
/* 007b2bdd  FUN_007b2bdd  43 bytes, 1 callers */

void FUN_007b2bdd(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x5c) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x5c) + 0x20);
    guard_check_icall(param_1);
    (*pcVar1)();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



