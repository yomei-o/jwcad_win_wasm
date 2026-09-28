/* CMFCCaptionButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCCaptionButton[1] */
/* 008aedd2  FUN_008aedd2  49 bytes, 0 callers */

void FUN_008aedd2(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CMFCCaptionButton::vftable;
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




/* vtable slots: CMFCCaptionButton[5], CMFCCaptionButtonEx[5], CMFCCaptionMenuButton[5] */
/* 008aee38  FUN_008aee38  115 bytes, 0 callers */

int FUN_008aee38(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(in_ECX + 0x1c);
  if (iVar1 == 8) {
    if (param_1 == 0) {
      uStack_8 = (-(uint)(param_2 != 0) & 6) + 7;
    }
    else {
      uStack_8 = (uint)(param_2 != 0) * 8 + 1;
    }
  }
  else if (iVar1 == 9) {
    uStack_8 = 0x10 - (uint)(param_2 != 0);
  }
  else if ((iVar1 == 0x13) || (iVar1 == 0x14)) {
    uStack_8 = 5;
  }
  else if (iVar1 == 0x17) {
    uStack_8 = 0x1b;
  }
  else if (iVar1 == 0x18) {
    uStack_8 = 0x1c;
  }
  else if (iVar1 == 0x19) {
    uStack_8 = 0xd;
  }
  else {
    uStack_8 = -1;
  }
  return uStack_8;
}




/* vtable slots: CMFCCaptionButton[3], CMFCCaptionMenuButton[3] */
/* 008aeeab  FUN_008aeeab  81 bytes, 0 callers */

void FUN_008aeeab(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  undefined1 local_14 [8];
  int local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    local_8 = in_ECX;
    piVar5 = (int *)FUN_0083fb52(local_14);
    in_ECX = local_8;
  }
  else {
    local_c = 0;
    piVar5 = &local_c;
    local_8 = 0;
  }
  iVar1 = *(int *)(in_ECX + 0x24);
  iVar2 = *(int *)(in_ECX + 0x28);
  iVar3 = *piVar5;
  iVar4 = piVar5[1];
  *param_1 = iVar1;
  param_1[2] = iVar1 + iVar3;
  param_1[1] = iVar2;
  param_1[3] = iVar4 + iVar2;
  return;
}




/* vtable slots: CMFCCaptionButton[4], CMFCCaptionButtonEx[4] */
/* 008aef13  FUN_008aef13  79 bytes, 0 callers */

void FUN_008aef13(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    piVar2 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar2 + 0x54);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}



