/* HHII::?$CMap -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: HHII::?$CMap[1] */
/* 007e3405  FUN_007e3405  100 bytes, 0 callers */

void FUN_007e3405(byte param_1)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00944167;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *in_ECX = CMap<int,int,unsigned_int,unsigned_int>::vftable;
  RemoveAll(uVar1);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: HHII::?$CMap[2] */
/* 007e4dae  FUN_007e4dae  171 bytes, 0 callers */

void FUN_007e4dae(CArchive *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  uint uVar4;
  int local_c;
  int local_8;
  
  local_c = in_ECX;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    for (iVar2 = FUN_007a6ad2(); iVar2 != 0; iVar2 = iVar2 + -1) {
      FUN_0041edc0(param_1,&local_8,1);
      FUN_00799245(param_1,&local_c,1);
      iVar1 = local_c;
      piVar3 = (int *)FUN_007e3332(local_8);
      *piVar3 = iVar1;
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 0xc));
    uVar4 = 0;
    if (((*(int *)(in_ECX + 0xc) != 0) && (*(int *)(in_ECX + 4) != 0)) &&
       (*(int *)(in_ECX + 8) != 0)) {
      do {
        iVar2 = *(int *)(*(int *)(in_ECX + 4) + uVar4 * 4);
        local_8 = iVar2;
        for (; iVar2 != 0; iVar2 = *(int *)(iVar2 + 8)) {
          FUN_0041edc0(param_1,iVar2,1);
          FUN_00799245(param_1,iVar2 + 4,1);
          in_ECX = local_c;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < *(uint *)(in_ECX + 8));
    }
  }
  return;
}



