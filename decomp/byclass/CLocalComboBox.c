/* CLocalComboBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CLocalComboBox[1] */
/* 004b0240  FUN_004b0240  68 bytes, 0 callers */

undefined4 FUN_004b0240(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004b0150();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x98);
    }
  }
  return in_ECX;
}




/* vtable slots: CLocalComboBox[10] */
/* 004b0f50  FUN_004b0f50  16 bytes, 0 callers */

void FUN_004b0f50(void)

{
  FUN_004b0fb0();
  return;
}



