/* CButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CButton[1] */
/* 00404a40  FUN_00404a40  68 bytes, 0 callers */

ExternalContextBase * FUN_00404a40(uint param_1)

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




/* vtable slots: CButton[0], CKijunTenButton[0], CMFCColorPickerCtrl[0], CMFCImagePaintArea[0], CMFCToolBarButtonsListButton[0], CMy3Button[0], CMyButton[0] */
/* 0079905d  FUN_0079905d  6 bytes, 0 callers */

undefined ** FUN_0079905d(void)

{
  return &PTR_s_CButton_0097d1e0;
}



