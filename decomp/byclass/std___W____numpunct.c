/* std::_W::?$numpunct -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::_W::?$numpunct[0] */
/* 00555190  `scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall std::basic_stringbuf<char,struct std::char_traits<char>,class
   std::allocator<char> >::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void * __thiscall
std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::
_scalar_deleting_destructor_
          (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *this,uint param_1)

{
  FID_conflict__numpunct<wchar_t>();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0x18);
  }
  return this;
}




/* vtable slots: std::_W::?$numpunct[3] */
/* 0055a380  FUN_0055a380  18 bytes, 0 callers */

undefined2 FUN_0055a380(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0xc);
}




/* vtable slots: std::_W::?$numpunct[6] */
/* 0055a3a0  FUN_0055a3a0  49 bytes, 0 callers */

undefined4 FUN_0055a3a0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00553270(*(undefined4 *)(in_ECX + 0x10));
  return param_1;
}




/* vtable slots: std::_W::?$numpunct[5] */
/* 0055a3e0  do_grouping  49 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > __thiscall std::_Mpunct<char>::do_grouping(void)const 
    protected: virtual class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > __thiscall std::_Mpunct<unsigned short>::do_grouping(void)const 
    protected: virtual class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > __thiscall std::_Mpunct<wchar_t>::do_grouping(void)const 
    protected: virtual class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > __thiscall std::numpunct<char>::do_grouping(void)const 
     6 names - too many to list
   
   Library: Visual Studio */

undefined4 do_grouping(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00552ff0(*(undefined4 *)(in_ECX + 8));
  return param_1;
}




/* vtable slots: std::_W::?$numpunct[4] */
/* 0055ae80  FUN_0055ae80  18 bytes, 0 callers */

undefined2 FUN_0055ae80(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0xe);
}




/* vtable slots: std::_W::?$numpunct[7] */
/* 0055afc0  FUN_0055afc0  49 bytes, 0 callers */

undefined4 FUN_0055afc0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00553270(*(undefined4 *)(in_ECX + 0x14));
  return param_1;
}



