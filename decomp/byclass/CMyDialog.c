/* CMyDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyDialog[1] */
/* 0058d310  FUN_0058d310  68 bytes, 0 callers */

undefined4 FUN_0058d310(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00404740();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xb8);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyDialog[10] */
/* 0058d4d0  FUN_0058d4d0  16 bytes, 0 callers */

void FUN_0058d4d0(void)

{
  FUN_0058d4e0();
  return;
}



