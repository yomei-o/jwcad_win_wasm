/* CIkkatstHenkanDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CIkkatstHenkanDialog[1] */
/* 004caf30  FUN_004caf30  68 bytes, 0 callers */

undefined4 FUN_004caf30(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004caee0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1b8);
    }
  }
  return in_ECX;
}




/* vtable slots: CIkkatstHenkanDialog[64] */
/* 004caf80  FUN_004caf80  167 bytes, 0 callers */

void FUN_004caf80(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x8cc,in_ECX + 0xa8);
  FUN_0078fb9c(param_1,0x8cd,in_ECX + 0x128);
  FUN_0078f6f8(param_1,0x8ce,in_ECX + 0x1a8);
  FUN_0078f75d(param_1,0x699,in_ECX + 0x1ac);
  DDX_Text(param_1,0x8cd,in_ECX + 0x1b0);
  DDX_Text(param_1,0x8cc,in_ECX + 0x1b4);
  return;
}




/* vtable slots: CIkkatstHenkanDialog[10] */
/* 004cb030  FUN_004cb030  16 bytes, 0 callers */

void FUN_004cb030(void)

{
  FUN_004cb040();
  return;
}



