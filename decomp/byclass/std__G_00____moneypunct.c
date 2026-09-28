/* std::G$00::?$moneypunct -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::G$00::?$moneypunct[0], std::G$0A::?$moneypunct[0], std::G::?$_Mpunct[0] */
/* 008e10f1  FUN_008e10f1  46 bytes, 0 callers */

void FUN_008e10f1(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::_Mpunct<unsigned_short>::vftable;
  Tidy();
  *in_ECX = std::_Facet_base::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::G$00::?$moneypunct[6], std::G$0A::?$moneypunct[6], std::G::?$_Mpunct[6], std::G::?$numpunct[6] */
/* 008e84e8  FUN_008e84e8  21 bytes, 0 callers */

undefined4 FUN_008e84e8(undefined4 param_1)

{
  int in_ECX;
  
  FUN_008e0d47(*(undefined4 *)(in_ECX + 0x10));
  return param_1;
}




/* vtable slots: std::G$00::?$moneypunct[3], std::G$0A::?$moneypunct[3], std::G::?$_Mpunct[3], std::G::?$numpunct[3], std::_W$00::?$moneypunct[3], std::_W$0A::?$moneypunct[3], std::_W::?$_Mpunct[3] */
/* 008e8516  FUN_008e8516  5 bytes, 0 callers */

undefined2 FUN_008e8516(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0xc);
}




/* vtable slots: std::G$00::?$moneypunct[8], std::G$0A::?$moneypunct[8], std::G::?$_Mpunct[8] */
/* 008eb216  FUN_008eb216  21 bytes, 0 callers */

undefined4 FUN_008eb216(undefined4 param_1)

{
  int in_ECX;
  
  FUN_008e0d47(*(undefined4 *)(in_ECX + 0x18));
  return param_1;
}




/* vtable slots: std::G$00::?$moneypunct[7], std::G$0A::?$moneypunct[7], std::G::?$_Mpunct[7], std::G::?$numpunct[7] */
/* 008eb335  FUN_008eb335  21 bytes, 0 callers */

undefined4 FUN_008eb335(undefined4 param_1)

{
  int in_ECX;
  
  FUN_008e0d47(*(undefined4 *)(in_ECX + 0x14));
  return param_1;
}




/* vtable slots: std::G$00::?$moneypunct[4], std::G$0A::?$moneypunct[4], std::G::?$_Mpunct[4], std::G::?$numpunct[4], std::_W$00::?$moneypunct[4], std::_W$0A::?$moneypunct[4], std::_W::?$_Mpunct[4] */
/* 008ec1d5  FUN_008ec1d5  5 bytes, 0 callers */

undefined2 FUN_008ec1d5(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0xe);
}



