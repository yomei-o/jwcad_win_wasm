/* CEdit -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CEdit[1] */
/* 00404a90  FUN_00404a90  68 bytes, 1 callers */

ExternalContextBase * FUN_00404a90(uint param_1)

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




/* vtable slots: CEdit[0], CMFCAcceleratorKeyAssignCtrl[0], CMFCToolBarComboBoxEdit[0] */
/* 00799069  FUN_00799069  6 bytes, 0 callers */

undefined ** FUN_00799069(void)

{
  return &PTR_s_CEdit_0097d3b8;
}



