/* CMyTreeCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyTreeCtrl[1] */
/* 00597cb0  FUN_00597cb0  68 bytes, 0 callers */

CMFCRibbonRichEditCtrl * FUN_00597cb0(uint param_1)

{
  CMFCRibbonRichEditCtrl *in_ECX;
  
  CMFCRibbonRichEditCtrl::~CMFCRibbonRichEditCtrl(in_ECX);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x88);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyTreeCtrl[10] */
/* 00598e90  FUN_00598e90  16 bytes, 0 callers */

void FUN_00598e90(void)

{
  FUN_005990e0();
  return;
}



