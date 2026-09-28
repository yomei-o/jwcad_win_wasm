/* COleCntrFrameWnd -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COleCntrFrameWnd[1] */
/* 007cfb88  FUN_007cfb88  51 bytes, 0 callers */

void FUN_007cfb88(byte param_1)

{
  FUN_007cf996();
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




/* vtable slots: COleCntrFrameWnd[3], COleCntrFrameWndEx[3] */
/* 007cfe62  FUN_007cfe62  82 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007cfe62(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  CFrameWnd *in_ECX;
  CPushRoutingFrame local_1c [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x7cfe6e;
  CPushRoutingFrame::CPushRoutingFrame(local_1c,in_ECX);
  local_8 = 0;
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x120) + 0xc);
  guard_check_icall(param_1,param_2,param_3,param_4);
  uVar2 = (*pcVar1)();
  FUN_007996a0();
  return uVar2;
}




/* vtable slots: COleCntrFrameWnd[94] */
/* 007d036b  FUN_007d036b  187 bytes, 0 callers */

void FUN_007d036b(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  if (*(int *)(in_ECX + 0xf4) == 0) {
    *(uint *)(in_ECX + 0x118) = *(uint *)(in_ECX + 0x118) & 0xfffffff3;
    *(undefined4 *)(in_ECX + 0xf4) = 1;
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x120) + 0x16c);
    guard_check_icall();
    piVar2 = (int *)(*pcVar1)();
    iVar3 = FUN_0079d18b();
    if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    if ((piVar2 != (int *)0x0) &&
       (iVar4 = *(int *)(in_ECX + 0x120), *(int *)(iVar3 + 0x24) == iVar4)) {
      if (in_ECX == *(int *)(iVar4 + 0x140)) {
        pcVar1 = *(code **)(*piVar2 + 0x18c);
        guard_check_icall(0,*(undefined4 *)(iVar4 + 0x138),1);
        (*pcVar1)();
        iVar4 = *(int *)(in_ECX + 0x120);
      }
      if (in_ECX == *(int *)(iVar4 + 0x144)) {
        pcVar1 = *(code **)(*piVar2 + 0x18c);
        guard_check_icall(0,*(undefined4 *)(iVar4 + 0x13c),0);
        (*pcVar1)();
      }
    }
    *(undefined4 *)(in_ECX + 0xf4) = 0;
  }
  return;
}



