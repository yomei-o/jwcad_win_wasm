/* CMouseManager -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMouseManager[1] */
/* 008a2235  FUN_008a2235  48 bytes, 0 callers */

void FUN_008a2235(byte param_1)

{
  FUN_008a214c();
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




/* vtable slots: CMouseManager[0] */
/* 008a2265  FUN_008a2265  6 bytes, 0 callers */

undefined ** FUN_008a2265(void)

{
  return &PTR_s_CMouseManager_00a00c44;
}




/* vtable slots: CMouseManager[2] */
/* 008a2435  FUN_008a2435  171 bytes, 0 callers */

void FUN_008a2435(CArchive *param_1)

{
  long *plVar1;
  int in_ECX;
  int iVar2;
  long local_10;
  long local_c;
  int local_8;
  
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x2c));
    local_8 = -(uint)(*(int *)(in_ECX + 0x2c) != 0);
    iVar2 = *(int *)(in_ECX + 0x2c);
    while (iVar2 != 0) {
      FUN_007e3ca0(&local_8,&local_c,&local_10);
      CArchive::operator<<(param_1,local_c);
      CArchive::operator<<(param_1,local_10);
      iVar2 = local_8;
    }
  }
  else {
    RemoveAll();
    CArchive::operator>>(param_1,&local_8);
    iVar2 = local_8;
    if (0 < local_8) {
      do {
        CArchive::operator>>(param_1,&local_8);
        CArchive::operator>>(param_1,&local_c);
        plVar1 = (long *)FUN_007e3332(local_8);
        *plVar1 = local_c;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
  }
  return;
}



