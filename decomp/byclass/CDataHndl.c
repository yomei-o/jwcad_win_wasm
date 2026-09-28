/* CDataHndl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataHndl[1] */
/* 00447580  FUN_00447580  68 bytes, 0 callers */

undefined4 FUN_00447580(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00447100();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x63d0);
    }
  }
  return in_ECX;
}



