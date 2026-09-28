/* std::std::_W::_WU?$char_traits::?$basic_streambuf -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::_W::_WU?$char_traits::?$basic_streambuf[0] */
/* 00555090  FID_conflict:`scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: virtual void * __thiscall std::basic_streambuf<char,struct std::char_traits<char>
   >::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall std::basic_streambuf<unsigned short,struct
   std::char_traits<unsigned short> >::`scalar deleting destructor'(unsigned int)
    public: virtual void * __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t>
   >::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

basic_streambuf<char,std::char_traits<char>_> *
FID_conflict__scalar_deleting_destructor_(uint param_1)

{
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  
  std::basic_streambuf<char,std::char_traits<char>_>::~basic_streambuf<char,std::char_traits<char>_>
            (in_ECX);
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0x38);
  }
  return in_ECX;
}




/* vtable slots: std::std::_W::_WU?$char_traits::?$basic_streambuf[3], std::std::_W::_WU?$char_traits::?$basic_streambuf[4] */
/* 0055b900  FUN_0055b900  18 bytes, 0 callers */

void FUN_0055b900(void)

{
  int in_ECX;
  
  eof(in_ECX);
  return;
}




/* vtable slots: std::std::_W::_WU?$char_traits::?$basic_streambuf[10] */
/* 0055be70  seekoff  28 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::fpos<struct _Mbstatet> __thiscall std::basic_streambuf<char,struct
   std::char_traits<char> >::seekoff(__int64,int,int)
    protected: virtual class std::fpos<struct _Mbstatet> __thiscall std::basic_streambuf<unsigned
   short,struct std::char_traits<unsigned short> >::seekoff(__int64,int,int)
    protected: virtual class std::fpos<struct _Mbstatet> __thiscall
   std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >::seekoff(__int64,int,int)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

undefined4 seekoff(undefined4 param_1)

{
  FUN_00553510(0xffffffff,0xffffffff);
  return param_1;
}




/* vtable slots: std::std::_W::_WU?$char_traits::?$basic_streambuf[11] */
/* 0055c0b0  seekpos  28 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::fpos<struct _Mbstatet> __thiscall std::basic_streambuf<char,struct
   std::char_traits<char> >::seekpos(class std::fpos<struct _Mbstatet>,int)
    protected: virtual class std::fpos<struct _Mbstatet> __thiscall std::basic_streambuf<unsigned
   short,struct std::char_traits<unsigned short> >::seekpos(class std::fpos<struct _Mbstatet>,int)
    protected: virtual class std::fpos<struct _Mbstatet> __thiscall
   std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t> >::seekpos(class std::fpos<struct
   _Mbstatet>,int)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release, Visual Studio 2019 Debug, Visual
   Studio 2019 Release */

undefined4 seekpos(undefined4 param_1)

{
  FUN_00553510(0xffffffff,0xffffffff);
  return param_1;
}




/* vtable slots: std::std::_W::_WU?$char_traits::?$basic_streambuf[6] */
/* 0055c6e0  FUN_0055c6e0  16 bytes, 0 callers */

void FUN_0055c6e0(void)

{
  int in_ECX;
  
  eof(in_ECX);
  return;
}



