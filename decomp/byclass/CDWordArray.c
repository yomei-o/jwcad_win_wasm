/* CDWordArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDWordArray[1] */
/* 007bf391  FUN_007bf391  58 bytes, 0 callers */

void FUN_007bf391(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CDWordArray::vftable;
  thunk_FUN_008f43b0(in_ECX[1]);
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




/* vtable slots: CDWordArray[0] */
/* 007bf3cb  FUN_007bf3cb  6 bytes, 0 callers */

undefined ** FUN_007bf3cb(void)

{
  return &PTR_s_CDWordArray_00a00460;
}




/* vtable slots: CDWordArray[2] */
/* 007bf3d1  FUN_007bf3d1  182 bytes, 0 callers */

void FUN_007bf3d1(CArchive *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  uint local_c;
  uint local_8;
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    uVar1 = FUN_007a6ad2();
    FUN_007b011a(uVar1,0xffffffff);
    pvVar3 = *(void **)(in_ECX + 4);
    for (uVar4 = *(uint *)(in_ECX + 8); uVar4 != 0; uVar4 = uVar4 - local_c) {
      local_c = uVar4;
      if (0x1ffffffe < uVar4) {
        local_c = 0x1fffffff;
      }
      CArchive::EnsureRead(param_1,pvVar3,local_c * 4);
      pvVar3 = (void *)((int)pvVar3 + local_c * 4);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 8));
    iVar2 = *(int *)(in_ECX + 4);
    for (uVar4 = *(uint *)(in_ECX + 8); uVar4 != 0; uVar4 = uVar4 - local_8) {
      local_8 = uVar4;
      if (0x1ffffffe < uVar4) {
        local_8 = 0x1fffffff;
      }
      FUN_007a6b47(iVar2,local_8 * 4);
      iVar2 = iVar2 + local_8 * 4;
    }
  }
  return;
}



