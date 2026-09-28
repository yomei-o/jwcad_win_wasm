/* std::std::_W::_WU?$char_traits::?$basic_ios -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::_W::_WU?$char_traits::?$basic_ios[0] */
/* 00554fa0  FID_conflict:`scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall std::basic_ios<char,struct std::char_traits<char> >::`scalar
   deleting destructor'(unsigned int)
    public: virtual void * __thiscall std::basic_ios<unsigned short,struct std::char_traits<unsigned
   short> >::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall std::basic_ios<wchar_t,struct std::char_traits<wchar_t>
   >::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4 FID_conflict__scalar_deleting_destructor_(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005540e0();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0x48);
  }
  return in_ECX;
}



