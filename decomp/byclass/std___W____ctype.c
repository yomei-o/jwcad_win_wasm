/* std::_W::?$ctype -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::_W::?$ctype[0] */
/* 00555130  FUN_00555130  46 bytes, 0 callers */

undefined4 FUN_00555130(uint param_1)

{
  undefined4 in_ECX;
  
  ~ctype<>();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,0x44);
  }
  return in_ECX;
}




/* vtable slots: std::_W::?$ctype[3] */
/* 0055a420  do_is  56 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned short>::do_is(unsigned
   short const *,unsigned short const *,short *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_is(wchar_t const *,wchar_t
   const *,short *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void do_is(wchar_t *param_1,wchar_t *param_2,short *param_3)

{
  int in_ECX;
  
  _Adl_verify_range<>(&param_1,&param_2);
  __Getwctypes(param_1,param_2,param_3,(_Ctypevec *)(in_ECX + 8));
  return;
}




/* vtable slots: std::_W::?$ctype[4] */
/* 0055a460  do_is  65 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual bool __thiscall std::ctype<unsigned short>::do_is(short,unsigned short)const 
    protected: virtual bool __thiscall std::ctype<wchar_t>::do_is(short,wchar_t)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 do_is(ushort param_1,wchar_t param_2)

{
  ushort uVar1;
  int in_ECX;
  
  uVar1 = __Getwctype(param_2,(_Ctypevec *)(in_ECX + 8));
  return CONCAT31((int3)(char)(param_1 >> 8),(uVar1 & param_1) != 0);
}




/* vtable slots: std::_W::?$ctype[14] */
/* 0055a4b0  do_narrow  31 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual char __thiscall std::ctype<unsigned short>::do_narrow(unsigned
   short,char)const 
    protected: virtual char __thiscall std::ctype<wchar_t>::do_narrow(wchar_t,char)const 
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void do_narrow(undefined2 param_1,undefined1 param_2)

{
  Donarrow(param_1,param_2);
  return;
}




/* vtable slots: std::_W::?$ctype[13] */
/* 0055a4d0  do_narrow  87 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_narrow(unsigned short const *,unsigned short const *,char,char *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_narrow(wchar_t const
   *,wchar_t const *,char,char *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined2 *
do_narrow(undefined2 *param_1,undefined2 *param_2,undefined1 param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  _Adl_verify_range<>(&param_1,&param_2);
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    uVar1 = Donarrow(*param_1,param_3);
    *param_4 = uVar1;
    param_4 = param_4 + 1;
  }
  return param_1;
}




/* vtable slots: std::_W::?$ctype[5] */
/* 0055ade0  do_scan_is  78 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_scan_is(short,unsigned short const *,unsigned short const *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_scan_is(short,wchar_t
   const *,wchar_t const *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined2 * do_scan_is(undefined2 param_1,undefined2 *param_2,undefined2 *param_3)

{
  char cVar1;
  
  _Adl_verify_range<>(&param_2,&param_3);
  while( true ) {
    if (param_2 == param_3) {
      return param_2;
    }
    cVar1 = is(param_1,*param_2);
    if (cVar1 != '\0') break;
    param_2 = param_2 + 1;
  }
  return param_2;
}




/* vtable slots: std::_W::?$ctype[6] */
/* 0055ae30  do_scan_not  78 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_scan_not(short,unsigned short const *,unsigned short const *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_scan_not(short,wchar_t
   const *,wchar_t const *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined2 * do_scan_not(undefined2 param_1,undefined2 *param_2,undefined2 *param_3)

{
  char cVar1;
  
  _Adl_verify_range<>(&param_2,&param_3);
  while( true ) {
    if (param_2 == param_3) {
      return param_2;
    }
    cVar1 = is(param_1,*param_2);
    if (cVar1 == '\0') break;
    param_2 = param_2 + 1;
  }
  return param_2;
}




/* vtable slots: std::_W::?$ctype[7] */
/* 0055aea0  do_tolower  81 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_tolower(unsigned short *,unsigned short const *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_tolower(wchar_t *,wchar_t
   const *)const 
   
   Library: Visual Studio 2019 Release */

wchar_t * do_tolower(wchar_t *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  int in_ECX;
  
  _Adl_verify_range<>(&param_1,&param_2);
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    wVar1 = __Towlower(*param_1,(_Ctypevec *)(in_ECX + 8));
    *param_1 = wVar1;
  }
  return param_1;
}




/* vtable slots: std::_W::?$ctype[8] */
/* 0055af00  do_tolower  33 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short __thiscall std::ctype<unsigned short>::do_tolower(unsigned
   short)const 
    protected: virtual wchar_t __thiscall std::ctype<wchar_t>::do_tolower(wchar_t)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void do_tolower(wchar_t param_1)

{
  int in_ECX;
  
  __Towlower(param_1,(_Ctypevec *)(in_ECX + 8));
  return;
}




/* vtable slots: std::_W::?$ctype[9] */
/* 0055af30  do_toupper  81 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_toupper(unsigned short *,unsigned short const *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_toupper(wchar_t *,wchar_t
   const *)const 
   
   Library: Visual Studio 2019 Release */

wchar_t * do_toupper(wchar_t *param_1,wchar_t *param_2)

{
  wchar_t wVar1;
  int in_ECX;
  
  _Adl_verify_range<>(&param_1,&param_2);
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    wVar1 = __Towupper(*param_1,(_Ctypevec *)(in_ECX + 8));
    *param_1 = wVar1;
  }
  return param_1;
}




/* vtable slots: std::_W::?$ctype[10] */
/* 0055af90  do_toupper  33 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short __thiscall std::ctype<unsigned short>::do_toupper(unsigned
   short)const 
    protected: virtual wchar_t __thiscall std::ctype<wchar_t>::do_toupper(wchar_t)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void do_toupper(wchar_t param_1)

{
  int in_ECX;
  
  __Towupper(param_1,(_Ctypevec *)(in_ECX + 8));
  return;
}




/* vtable slots: std::_W::?$ctype[11] */
/* 0055b000  do_widen  83 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual char const * __thiscall std::ctype<unsigned short>::do_widen(char const
   *,char const *,unsigned short *)const 
    protected: virtual char const * __thiscall std::ctype<wchar_t>::do_widen(char const *,char const
   *,wchar_t *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined1 * do_widen(undefined1 *param_1,undefined1 *param_2,undefined2 *param_3)

{
  undefined2 uVar1;
  
  _Adl_verify_range<>(&param_1,&param_2);
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    uVar1 = Dowiden(*param_1);
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return param_1;
}




/* vtable slots: std::_W::?$ctype[12] */
/* 0055b060  do_widen  26 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short __thiscall std::ctype<unsigned short>::do_widen(char)const 
    protected: virtual wchar_t __thiscall std::ctype<wchar_t>::do_widen(char)const 
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

void do_widen(undefined1 param_1)

{
  Dowiden(param_1);
  return;
}



