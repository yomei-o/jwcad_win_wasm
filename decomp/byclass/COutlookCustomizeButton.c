/* COutlookCustomizeButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COutlookCustomizeButton[54] */
/* 00897308  FUN_00897308  359 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00897308(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  UINT in_stack_fffffef0;
  LPSTR in_stack_fffffef4;
  int in_stack_fffffef8;
  undefined4 local_100;
  
  piVar2 = (int *)FUN_00886177();
  if (piVar2 == (int *)0x0) {
LAB_00897324:
    FUN_008d9b68();
    return;
  }
  pcVar1 = *(code **)(*piVar2 + 0x1c8);
  guard_check_icall();
  (*pcVar1)();
  uVar3 = FUN_007fc6bf(*(undefined4 *)(in_ECX + 0xe8),0);
  FUN_008209a9(uVar3);
  iVar4 = FUN_0081d494();
  if (0 < iVar4) {
    FUN_0081dee6(0xffffffff);
  }
  CStringT<>();
  iVar4 = FID_conflict_LoadStringA
                    ((HINSTANCE)0x4285,in_stack_fffffef0,in_stack_fffffef4,in_stack_fffffef8);
  if (iVar4 != 0) {
    uVar3 = FUN_00874dc7(0xf200,0,0xffffffff,local_100,0);
    FUN_0081dea9(uVar3,0xffffffff);
    FUN_00874eb0();
    iVar4 = FID_conflict_LoadStringA
                      ((HINSTANCE)0x4286,in_stack_fffffef0,in_stack_fffffef4,in_stack_fffffef8);
    if (iVar4 != 0) {
      uVar3 = FUN_00874dc7(0xf201,0,0xffffffff,local_100,0);
      FUN_0081dea9(uVar3,0xffffffff);
      FUN_00874eb0();
      iVar4 = FID_conflict_LoadStringA
                        ((HINSTANCE)0x4287,in_stack_fffffef0,in_stack_fffffef4,in_stack_fffffef8);
      if (iVar4 != 0) {
        uVar3 = FUN_00874dc7(0xf202,0,0xffffffff,local_100,0);
        FUN_0081dea9(uVar3,0xffffffff);
        FUN_00874eb0();
        FUN_00406b10();
        goto LAB_00897324;
      }
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: COutlookCustomizeButton[0] */
/* 00897a0e  FUN_00897a0e  6 bytes, 0 callers */

undefined ** FUN_00897a0e(void)

{
  return &PTR_s_COutlookCustomizeButton_0099d1f8;
}




/* vtable slots: COutlookCustomizeButton[6] */
/* 00898002  FUN_00898002  201 bytes, 0 callers */

void FUN_00898002(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uVar4;
  int in_stack_00000018;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  uVar4 = 1;
  in_ECX[0x40] = 1;
  if (in_stack_00000018 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x70);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      uVar4 = 0;
    }
  }
  FUN_0088114d(param_1,param_2,uVar4,0);
  FUN_0081507c(&local_c);
  iVar2 = ((param_2[2] - *param_2) - local_c) / 2;
  if (iVar2 < 0) {
    iVar2 = 0;
  }
  iVar2 = *param_2 + iVar2;
  iVar3 = ((param_2[3] + local_8 * -2) - param_2[1]) / 2;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  iVar3 = param_2[1] + iVar3;
  local_14 = 0;
  local_10 = 0;
  local_1c = iVar2;
  local_18 = iVar3;
  FUN_00814c80(param_1,0xb,&local_1c,0,&local_14);
  local_10 = local_8 + iVar3;
  local_1c = 0;
  local_18 = 0;
  local_14 = iVar2;
  FUN_00814c80(param_1,0,&local_14,0,&local_1c);
  return;
}



