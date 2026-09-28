/* CFileException -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFileException[1] */
/* 004475d0  FUN_004475d0  65 bytes, 0 callers */

undefined4 FUN_004475d0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004472c0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x14);
    }
  }
  return in_ECX;
}




/* vtable slots: CFileException[4] */
/* 007a6ccf  FUN_007a6ccf  185 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007a6ccf(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  UINT in_stack_ffffffd8;
  LPSTR in_stack_ffffffdc;
  int in_stack_ffffffe0;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7a6cdb;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar2 = 0;
  }
  else {
    if (param_3 != (int *)0x0) {
      *param_3 = *(int *)(in_ECX + 8) + 0xf1a0;
    }
    CStringT<>();
    local_8 = 0;
    iVar1 = FUN_004054a0(*(int *)(in_ECX + 0x10) + -0x10);
    local_8 = CONCAT31(local_8._1_3_,1);
    if (*(int *)(iVar1 + 4) == 0) {
      FID_conflict_LoadStringA
                ((HINSTANCE)0xf006,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0);
    }
    FUN_007c1390(local_14,*(int *)(in_ECX + 8) + 0xf1a0,iVar1 + 0x10);
    uVar2 = FUN_008f8e5e(param_1,param_2,local_14[0],0xffffffff);
    FUN_00404bd0(uVar2);
    FUN_00406b10();
    FUN_00406b10();
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CFileException[0] */
/* 007a6d88  FUN_007a6d88  6 bytes, 0 callers */

undefined ** FUN_007a6d88(void)

{
  return &PTR_s_CFileException_0097f380;
}



