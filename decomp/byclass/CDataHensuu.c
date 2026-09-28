/* CDataHensuu -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataHensuu[1] */
/* 0053e440  FUN_0053e440  65 bytes, 0 callers */

undefined4 FUN_0053e440(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0053e400();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x30);
    }
  }
  return in_ECX;
}




/* vtable slots: CDataHensuu[0] */
/* 0053e500  FUN_0053e500  16 bytes, 0 callers */

undefined ** FUN_0053e500(void)

{
  return &PTR_s_CDataHensuu_009fff00;
}



