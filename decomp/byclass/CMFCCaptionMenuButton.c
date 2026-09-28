/* CMFCCaptionMenuButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCCaptionMenuButton[1] */
/* 008b9148  FUN_008b9148  54 bytes, 0 callers */

void FUN_008b9148(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCCaptionMenuButton::vftable;
  FUN_008aedcb();
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




/* vtable slots: CMFCCaptionMenuButton[4] */
/* 008b917e  FUN_008b917e  62 bytes, 0 callers */

void FUN_008b917e(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    piVar2 = (int *)FUN_007c2574();
    iVar1 = *piVar2;
    guard_check_icall(param_1);
    (**(code **)(iVar1 + 0x54))();
  }
  return;
}



