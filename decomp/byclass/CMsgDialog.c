/* CMsgDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMsgDialog[1] */
/* 005888e0  FUN_005888e0  68 bytes, 0 callers */

undefined4 FUN_005888e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004da360();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xb0);
    }
  }
  return in_ECX;
}




/* vtable slots: CMsgDialog[10] */
/* 00588950  FUN_00588950  16 bytes, 0 callers */

void FUN_00588950(void)

{
  FUN_00588960();
  return;
}



