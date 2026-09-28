/* CMenu -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMenu[1] */
/* 004faad0  FUN_004faad0  65 bytes, 0 callers */

undefined4 FUN_004faad0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004fa7b0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,8);
    }
  }
  return in_ECX;
}



