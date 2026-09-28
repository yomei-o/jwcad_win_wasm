/* CDockState -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDockState[1] */
/* 007bb633  FUN_007bb633  48 bytes, 0 callers */

void FUN_007bb633(byte param_1)

{
  FUN_007bb5b0();
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




/* vtable slots: CDockState[0] */
/* 007bb91d  FUN_007bb91d  6 bytes, 0 callers */

undefined ** FUN_007bb91d(void)

{
  return &PTR_s_CDockState_00a00444;
}




/* vtable slots: CDockState[2] */
/* 007bc830  FUN_007bc830  321 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CArchive * FUN_007bc830(CArchive *param_1)

{
  CArchive *pCVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  CArchive *local_1c;
  undefined4 local_18;
  uint local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x7bc83c;
  pCVar1 = (CArchive *)(in_ECX + 0x44);
  local_1c = pCVar1;
  if ((~*(uint *)(param_1 + 0x18) & 1) == 0) {
    FUN_007bb663();
    CArchive::operator>>(param_1,(long *)pCVar1);
    if (1 < *(uint *)(in_ECX + 0x44)) {
      local_2c = 0;
      local_28 = 0;
      CArchive::EnsureRead(param_1,&local_2c,8);
      FUN_007bce77(&local_2c);
    }
    CArchive::operator>>(param_1,(ushort *)local_14);
    FUN_007b011a(local_14[0] & 0xffff,0xffffffff);
    local_14[0] = 0;
    if (0 < *(int *)(in_ECX + 0xc)) {
      do {
        local_20 = FUN_0078e624(0x5c);
        local_8 = 0;
        if (local_20 == 0) {
          local_18 = 0;
        }
        else {
          local_18 = FUN_007bb497();
        }
        local_8 = 0xffffffff;
        puVar2 = (undefined4 *)FUN_0049a990(local_14[0]);
        *puVar2 = local_18;
        FUN_0049a990(local_14[0]);
        FUN_007bc637(param_1,in_ECX);
        local_14[0] = local_14[0] + 1;
      } while ((int)local_14[0] < *(int *)(in_ECX + 0xc));
    }
    *(uint *)local_1c = 2;
    pCVar1 = local_1c;
  }
  else {
    CArchive::operator<<(param_1,*(uint *)pCVar1);
    if (1 < *(uint *)pCVar1) {
      local_20 = *(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x20);
      local_24 = *(int *)(in_ECX + 0x24) - *(int *)(in_ECX + 0x1c);
      FUN_007a6b47(&local_24,8);
    }
    pCVar1 = CArchive::operator<<(param_1,*(ushort *)(in_ECX + 0xc));
    iVar3 = 0;
    if (0 < *(int *)(in_ECX + 0xc)) {
      do {
        FUN_0049a990(iVar3);
        FUN_007bc637(param_1,in_ECX);
        iVar3 = iVar3 + 1;
        pCVar1 = (CArchive *)(in_ECX + 4);
      } while (iVar3 < *(int *)(in_ECX + 0xc));
    }
  }
  return pCVar1;
}



