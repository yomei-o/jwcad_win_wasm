/* CMapWordToOb -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMapWordToOb[1] */
/* 007d32d3  FUN_007d32d3  100 bytes, 0 callers */

void FUN_007d32d3(byte param_1)

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
  *in_ECX = CMapWordToOb::vftable;
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




/* vtable slots: CMapWordToOb[0] */
/* 007d3400  FUN_007d3400  6 bytes, 0 callers */

undefined ** FUN_007d3400(void)

{
  return &PTR_s_CMapWordToOb_00a00524;
}




/* vtable slots: CMapWordToOb[2] */
/* 007d347b  FUN_007d347b  166 bytes, 0 callers */

void FUN_007d347b(CArchive *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  uint uVar3;
  int local_c;
  undefined4 *local_8;
  
  local_c = in_ECX;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    local_8 = (undefined4 *)FUN_007a6ad2();
    while (local_8 != (undefined4 *)0x0) {
      local_8 = (undefined4 *)((int)local_8 + -1);
      CArchive::operator>>(param_1,(ushort *)&local_c);
      uVar1 = FUN_007a5d50(0);
      puVar2 = (undefined4 *)FUN_007d327b(local_c);
      *puVar2 = uVar1;
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 0xc));
    uVar3 = 0;
    if ((*(int *)(in_ECX + 0xc) != 0) && (*(int *)(in_ECX + 8) != 0)) {
      do {
        puVar2 = *(undefined4 **)(*(int *)(in_ECX + 4) + uVar3 * 4);
        local_8 = puVar2;
        for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
          CArchive::operator<<(param_1,*(ushort *)(puVar2 + 2));
          FUN_007a619a(puVar2[1]);
          in_ECX = local_c;
        }
        uVar3 = uVar3 + 1;
      } while (uVar3 < *(uint *)(in_ECX + 8));
    }
  }
  return;
}



