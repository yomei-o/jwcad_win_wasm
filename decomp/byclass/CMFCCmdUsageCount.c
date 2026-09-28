/* CMFCCmdUsageCount -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCCmdUsageCount[1] */
/* 00882e33  FUN_00882e33  48 bytes, 0 callers */

void FUN_00882e33(byte param_1)

{
  FUN_00882de7();
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




/* vtable slots: CMFCCmdUsageCount[2] */
/* 00882f34  FUN_00882f34  62 bytes, 0 callers */

void FUN_00882f34(CArchive *param_1)

{
  code *pcVar1;
  int in_ECX;
  
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x20));
  }
  else {
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x20));
  }
  pcVar1 = *(code **)(*(int *)(in_ECX + 4) + 8);
  guard_check_icall(param_1);
  (*pcVar1)();
  return;
}



