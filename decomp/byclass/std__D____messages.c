/* std::D::?$messages -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::D::?$messages[0], std::DDU_Mbstatet::?$codecvt[0], std::G::?$messages[0], std::_W::?$messages[0], std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$money_get[0], std::std::std::D::DU?$char_traits::DV?$istreambuf_iterator::?$num_get[0], std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$money_put[0], std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[0], std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$money_get[0], std::std::std::G::GU?$char_traits::GV?$istreambuf_iterator::?$num_get[0], std::std::std::G::GU?$char_traits::GV?$ostreambuf_iterator::?$money_put[0], std::std::std::G::GU?$char_traits::GV?$ostreambuf_iterator::?$num_put[0], std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$money_get[0], std::std::std::_W::_WU?$char_traits::_WV?$istreambuf_iterator::?$num_get[0], std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$money_put[0] */
/* 008db692  FUN_008db692  35 bytes, 0 callers */

void FUN_008db692(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::_Facet_base::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::D::?$messages[4] */
/* 008eec3c  FUN_008eec3c  34 bytes, 0 callers */

undefined4 * FUN_008eec3c(undefined4 *param_1)

{
  undefined4 in_stack_00000014;
  
  *param_1 = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  FUN_00557e70(in_stack_00000014);
  return param_1;
}



