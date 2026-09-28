/* CKijunTenButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CKijunTenButton[1] */
/* 00550210  FUN_00550210  68 bytes, 0 callers */

undefined4 FUN_00550210(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005501f0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x88);
    }
  }
  return in_ECX;
}




/* vtable slots: CKijunTenButton[10] */
/* 00550260  FUN_00550260  16 bytes, 0 callers */

void FUN_00550260(void)

{
  FUN_00550270();
  return;
}



