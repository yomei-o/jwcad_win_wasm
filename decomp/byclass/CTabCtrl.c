/* CTabCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTabCtrl[1] */
/* 00597930  FUN_00597930  68 bytes, 0 callers */

ExternalContextBase * FUN_00597930(uint param_1)

{
  ExternalContextBase *in_ECX;
  
  Concurrency::details::ExternalContextBase::~ExternalContextBase(in_ECX);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x80);
    }
  }
  return in_ECX;
}




/* vtable slots: CTabCtrl[10] */
/* 007a45b4  FUN_007a45b4  6 bytes, 0 callers */

undefined ** FUN_007a45b4(void)

{
  return &PTR_FUN_0097efc8;
}



