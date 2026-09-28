/* PAV1::PAVCMFCRibbonBaseElement::?$CArray -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: PAV1::PAVCMFCRibbonBaseElement::?$CArray[1] */
/* 00865e41  FUN_00865e41  48 bytes, 0 callers */

void FUN_00865e41(byte param_1)

{
  CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*> *in_ECX;
  
  CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::
  ~CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>(in_ECX);
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



