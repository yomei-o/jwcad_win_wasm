/* CMyPropertySheet -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyPropertySheet[1] */
/* 00596ab0  FUN_00596ab0  68 bytes, 0 callers */

undefined4 FUN_00596ab0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00596a90();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xe0);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyPropertySheet[10] */
/* 00596b00  FUN_00596b00  16 bytes, 0 callers */

void FUN_00596b00(void)

{
  FUN_00596b20();
  return;
}




/* vtable slots: CMyPropertySheet[0] */
/* 00596b10  FUN_00596b10  16 bytes, 0 callers */

undefined ** FUN_00596b10(void)

{
  return &PTR_s_CMyPropertySheet_0096e480;
}




/* vtable slots: CMyPropertySheet[91] */
/* 00596b60  FUN_00596b60  27 bytes, 0 callers */

undefined4 FUN_00596b60(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_007a0b0c();
  return uVar1;
}



