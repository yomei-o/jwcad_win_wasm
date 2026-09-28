/* CByteArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CByteArray[1] */
/* 007d2f64  FUN_007d2f64  58 bytes, 0 callers */

void FUN_007d2f64(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CByteArray::vftable;
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




/* vtable slots: CByteArray[0] */
/* 007d2f9e  FUN_007d2f9e  6 bytes, 0 callers */

undefined ** FUN_007d2f9e(void)

{
  return &PTR_s_CByteArray_00a00508;
}




/* vtable slots: CByteArray[2] */
/* 007d2fa4  FUN_007d2fa4  149 bytes, 0 callers */

void FUN_007d2fa4(CArchive *param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    uVar2 = FUN_007a6ad2();
    FUN_007d3039(uVar2,0xffffffff);
    pvVar3 = *(void **)(in_ECX + 4);
    for (uVar5 = *(uint *)(in_ECX + 8); uVar5 != 0; uVar5 = uVar5 - uVar4) {
      uVar4 = uVar5;
      if (0x7ffffffe < uVar5) {
        uVar4 = 0x7fffffff;
      }
      CArchive::EnsureRead(param_1,pvVar3,uVar4);
      pvVar3 = (void *)((int)pvVar3 + uVar4);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 8));
    iVar1 = *(int *)(in_ECX + 4);
    for (uVar5 = *(uint *)(in_ECX + 8); uVar5 != 0; uVar5 = uVar5 - uVar4) {
      uVar4 = uVar5;
      if (0x7ffffffe < uVar5) {
        uVar4 = 0x7fffffff;
      }
      FUN_007a6b47(iVar1,uVar4);
      iVar1 = iVar1 + uVar4;
    }
  }
  return;
}



