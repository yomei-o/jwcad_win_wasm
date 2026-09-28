/* NN::?$CArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: NN::?$CArray[1] */
/* 00420990  FUN_00420990  65 bytes, 0 callers */

undefined4 FUN_00420990(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0041fcb0();
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




/* vtable slots: NN::?$CArray[2] */
/* 0042e620  FUN_0042e620  104 bytes, 0 callers */

void FUN_0042e620(CArchive *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_00405880(param_1);
  iVar1 = FUN_0042ddc0();
  if (iVar1 == 0) {
    uVar2 = FUN_007a6ad2();
    FUN_0042fea0(uVar2,0xffffffff);
  }
  else {
    CArchive::WriteCount(param_1,*(ulong *)(in_ECX + 8));
  }
  FUN_0041eec0(param_1,*(undefined4 *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  return;
}



