/* CZahyouWritRead -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZahyouWritRead[1] */
/* 005fa020  FUN_005fa020  68 bytes, 0 callers */

undefined4 FUN_005fa020(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005f9fb0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x610);
    }
  }
  return in_ECX;
}



