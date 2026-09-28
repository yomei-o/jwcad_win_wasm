/* CDataHenkei -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataHenkei[1] */
/* 00464130  FUN_00464130  65 bytes, 0 callers */

undefined4 FUN_00464130(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004640a0();
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



