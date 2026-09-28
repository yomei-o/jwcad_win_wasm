/* CObArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CObArray[1] */
/* 007c598b  FUN_007c598b  58 bytes, 0 callers */

void FUN_007c598b(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = CObArray::vftable;
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




/* vtable slots: CObArray[0], PAVCBitmap::VCObArray::?$CTypedPtrArray[0], PAVCMFCCaptionButton::VCObArray::?$CTypedPtrArray[0] */
/* 007c59e4  FUN_007c59e4  6 bytes, 0 callers */

undefined ** FUN_007c59e4(void)

{
  return &PTR_s_CObArray_00a0049c;
}




/* vtable slots: CObArray[2], PAVCBitmap::VCObArray::?$CTypedPtrArray[2], PAVCMFCCaptionButton::VCObArray::?$CTypedPtrArray[2] */
/* 007c59ea  FUN_007c59ea  118 bytes, 0 callers */

void FUN_007c59ea(CArchive *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  int local_8;
  
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    uVar1 = FUN_007a6ad2();
    FUN_007b011a(uVar1,0xffffffff);
    local_8 = 0;
    if (0 < *(int *)(in_ECX + 8)) {
      do {
        iVar2 = *(int *)(in_ECX + 4);
        uVar1 = FUN_007a5d50(0);
        *(undefined4 *)(iVar2 + local_8 * 4) = uVar1;
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)(in_ECX + 8));
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 8));
    iVar2 = 0;
    if (0 < *(int *)(in_ECX + 8)) {
      do {
        FUN_007a619a(*(undefined4 *)(*(int *)(in_ECX + 4) + iVar2 * 4));
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(in_ECX + 8));
    }
  }
  return;
}



