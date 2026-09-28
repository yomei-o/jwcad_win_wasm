/* CRichEditCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CRichEditCtrl[1] */
/* 007a408b  FUN_007a408b  51 bytes, 0 callers */

void FUN_007a408b(byte param_1)

{
  ExternalContextBase *in_ECX;
  
  Concurrency::details::ExternalContextBase::~ExternalContextBase(in_ECX);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CRichEditCtrl[0] */
/* 007a45d8  FUN_007a45d8  6 bytes, 0 callers */

undefined ** FUN_007a45d8(void)

{
  return &PTR_s_CRichEditCtrl_0097ece8;
}



