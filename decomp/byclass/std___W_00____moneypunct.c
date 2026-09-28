/* std::_W$00::?$moneypunct -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::_W$00::?$moneypunct[0], std::_W$0A::?$moneypunct[0], std::_W::?$_Mpunct[0] */
/* 008e111f  FUN_008e111f  46 bytes, 0 callers */

void FUN_008e111f(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::_Mpunct<wchar_t>::vftable;
  Tidy();
  *in_ECX = std::_Facet_base::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::_W$00::?$moneypunct[6], std::_W$0A::?$moneypunct[6], std::_W::?$_Mpunct[6] */
/* 008e84fd  FUN_008e84fd  21 bytes, 0 callers */

undefined4 FUN_008e84fd(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00553270(*(undefined4 *)(in_ECX + 0x10));
  return param_1;
}




/* vtable slots: std::_W$00::?$moneypunct[8], std::_W$0A::?$moneypunct[8], std::_W::?$_Mpunct[8] */
/* 008eb22b  FUN_008eb22b  21 bytes, 0 callers */

undefined4 FUN_008eb22b(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00553270(*(undefined4 *)(in_ECX + 0x18));
  return param_1;
}




/* vtable slots: std::_W$00::?$moneypunct[7], std::_W$0A::?$moneypunct[7], std::_W::?$_Mpunct[7] */
/* 008eb34a  FUN_008eb34a  21 bytes, 0 callers */

undefined4 FUN_008eb34a(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00553270(*(undefined4 *)(in_ECX + 0x14));
  return param_1;
}



