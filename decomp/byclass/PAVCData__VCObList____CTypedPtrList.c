/* PAVCData::VCObList::?$CTypedPtrList -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: PAVCData::VCObList::?$CTypedPtrList[1], PAVCDataBlock::VCObList::?$CTypedPtrList[1], PAVCDataHensuu::VCObList::?$CTypedPtrList[1], PAVCDataList::VCObList::?$CTypedPtrList[1] */
/* 00499d90  FUN_00499d90  65 bytes, 0 callers */

undefined4 FUN_00499d90(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004997c0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1c);
    }
  }
  return in_ECX;
}



