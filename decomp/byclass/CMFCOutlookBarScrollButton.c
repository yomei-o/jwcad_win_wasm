/* CMFCOutlookBarScrollButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCOutlookBarScrollButton[95] */
/* 008980cb  FUN_008980cb  58 bytes, 0 callers */

void FUN_008980cb(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0xe4);
  guard_check_icall(param_1,param_2,*(undefined4 *)(in_ECX + 0xb4),*(undefined4 *)(in_ECX + 0xac));
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCOutlookBarScrollButton[94] */
/* 00898105  FUN_00898105  69 bytes, 0 callers */

void FUN_00898105(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0xe0);
  iVar3 = FUN_007c2511();
  guard_check_icall(param_1,param_2,*(undefined4 *)(in_ECX + 0xb4),*(undefined4 *)(in_ECX + 0xac),
                    iVar3 + 0x68);
  (*pcVar1)();
  return;
}



