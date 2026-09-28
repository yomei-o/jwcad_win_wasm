/* HH::?$CList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: HH::?$CList[1] */
/* 004d18c0  FUN_004d18c0  65 bytes, 0 callers */

undefined4 FUN_004d18c0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004d16a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1c);
    }
  }
  return in_ECX;
}




/* vtable slots: HH::?$CList[2] */
/* 004d2760  FUN_004d2760  177 bytes, 0 callers */

void FUN_004d2760(CArchive *param_1)

{
  int iVar1;
  undefined4 local_1c;
  int local_18;
  undefined4 *local_14;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  FUN_00405880(param_1);
  iVar1 = FUN_0042ddc0();
  if (iVar1 == 0) {
    local_10 = FUN_007a6ad2();
    while( true ) {
      local_18 = local_10;
      if (local_10 == 0) break;
      local_10 = local_10 + -1;
      FUN_0041edc0(param_1,&local_1c,1);
      FUN_00447d40(local_1c);
    }
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(local_c + 0xc));
    for (local_8 = *(undefined4 **)(local_c + 4); local_8 != (undefined4 *)0x0;
        local_8 = (undefined4 *)*local_8) {
      local_14 = local_8 + 2;
      FUN_0041edc0(param_1,local_14,1);
    }
  }
  return;
}



