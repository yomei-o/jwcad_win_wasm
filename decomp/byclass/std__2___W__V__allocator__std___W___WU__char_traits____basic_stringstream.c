/* std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringstream -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringstream[0] */
/* 00554f89  FUN_00554f89  8 bytes, 0 callers */

void FUN_00554f89(uint param_1)

{
  int in_ECX;
  
  std::basic_stringstream<char,std::char_traits<char>,std::allocator<char>_>::
  _scalar_deleting_destructor_
            ((basic_stringstream<char,std::char_traits<char>,std::allocator<char>_> *)
             (in_ECX - *(int *)(in_ECX + -4)),param_1);
  return;
}



