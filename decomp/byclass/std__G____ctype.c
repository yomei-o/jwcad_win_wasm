/* std::G::?$ctype -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::G::?$ctype[0] */
/* 008e11b4  FUN_008e11b4  34 bytes, 0 callers */

void FUN_008e11b4(byte param_1)

{
  ~ctype<>();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::G::?$ctype[3] */
/* 008eb13b  do_is  28 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned short>::do_is(unsigned
   short const *,unsigned short const *,short *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_is(wchar_t const *,wchar_t
   const *,short *)const 
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void do_is(wchar_t *param_1,wchar_t *param_2,short *param_3)

{
  int in_ECX;
  
  __Getwctypes(param_1,param_2,param_3,(_Ctypevec *)(in_ECX + 8));
  return;
}




/* vtable slots: std::G::?$ctype[4] */
/* 008eb157  do_is  28 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual bool __thiscall std::ctype<unsigned short>::do_is(short,unsigned short)const 
    protected: virtual bool __thiscall std::ctype<wchar_t>::do_is(short,wchar_t)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 do_is(ushort param_1,wchar_t param_2)

{
  ushort uVar1;
  undefined2 extraout_var;
  int in_ECX;
  
  uVar1 = __Getwctype(param_2,(_Ctypevec *)(in_ECX + 8));
  return CONCAT31((int3)(CONCAT22(extraout_var,uVar1) >> 8),(param_1 & uVar1) != 0);
}




/* vtable slots: std::G::?$ctype[14] */
/* 008eb1c9  FUN_008eb1c9  9 bytes, 0 callers */

void FUN_008eb1c9(void)

{
  Donarrow();
  return;
}




/* vtable slots: std::G::?$ctype[13] */
/* 008eb1d2  do_narrow  53 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_narrow(unsigned short const *,unsigned short const *,char,char *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_narrow(wchar_t const
   *,wchar_t const *,char,char *)const 
   
   Library: Visual Studio 2019 Release */

undefined2 *
do_narrow(undefined2 *param_1,undefined2 *param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    uVar1 = Donarrow(*param_1,param_3);
    *param_4 = uVar1;
    param_4 = param_4 + 1;
  }
  return param_1;
}




/* vtable slots: std::G::?$ctype[5] */
/* 008ec15b  do_scan_is  61 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_scan_is(short,unsigned short const *,unsigned short const *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_scan_is(short,wchar_t
   const *,wchar_t const *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined2 * do_scan_is(undefined4 param_1,undefined2 *param_2,undefined2 *param_3)

{
  code *pcVar1;
  char cVar2;
  int *in_ECX;
  
  while( true ) {
    if (param_2 == param_3) {
      return param_2;
    }
    pcVar1 = *(code **)(*in_ECX + 0x10);
    guard_check_icall(param_1,*param_2);
    cVar2 = (*pcVar1)();
    if (cVar2 != '\0') break;
    param_2 = param_2 + 1;
  }
  return param_2;
}




/* vtable slots: std::G::?$ctype[6] */
/* 008ec198  do_scan_not  61 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short const * __thiscall std::ctype<unsigned
   short>::do_scan_not(short,unsigned short const *,unsigned short const *)const 
    protected: virtual wchar_t const * __thiscall std::ctype<wchar_t>::do_scan_not(short,wchar_t
   const *,wchar_t const *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined2 * do_scan_not(undefined4 param_1,undefined2 *param_2,undefined2 *param_3)

{
  code *pcVar1;
  char cVar2;
  int *in_ECX;
  
  while( true ) {
    if (param_2 == param_3) {
      return param_2;
    }
    pcVar1 = *(code **)(*in_ECX + 0x10);
    guard_check_icall(param_1,*param_2);
    cVar2 = (*pcVar1)();
    if (cVar2 == '\0') break;
    param_2 = param_2 + 1;
  }
  return param_2;
}




/* vtable slots: std::G::?$ctype[8] */
/* 008ec1da  do_tolower  21 bytes, 0 callers */

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




/* vtable slots: std::G::?$ctype[7] */
/* 008ec1ef  do_tolower  47 bytes, 0 callers */

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
  
  if (param_1 != param_2) {
    do {
      wVar1 = __Towlower(*param_1,(_Ctypevec *)(in_ECX + 8));
      *param_1 = wVar1;
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return param_1;
}




/* vtable slots: std::G::?$ctype[10] */
/* 008ec21e  do_toupper  21 bytes, 0 callers */

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




/* vtable slots: std::G::?$ctype[9] */
/* 008ec233  do_toupper  47 bytes, 0 callers */

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
  
  if (param_1 != param_2) {
    do {
      wVar1 = __Towupper(*param_1,(_Ctypevec *)(in_ECX + 8));
      *param_1 = wVar1;
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return param_1;
}




/* vtable slots: std::G::?$ctype[12] */
/* 008ec402  FUN_008ec402  9 bytes, 0 callers */

void FUN_008ec402(char param_1)

{
  ctype<unsigned_short> *in_ECX;
  
  std::ctype<unsigned_short>::_Dowiden(in_ECX,param_1);
  return;
}




/* vtable slots: std::G::?$ctype[11] */
/* 008ec40b  do_widen  51 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual char const * __thiscall std::ctype<unsigned short>::do_widen(char const
   *,char const *,unsigned short *)const 
   
   Library: Visual Studio 2019 Release */

char * __thiscall
std::ctype<unsigned_short>::do_widen
          (ctype<unsigned_short> *this,char *param_1,char *param_2,ushort *param_3)

{
  ushort uVar1;
  
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    uVar1 = _Dowiden(this,*param_1);
    *param_3 = uVar1;
    param_3 = param_3 + 1;
  }
  return param_1;
}



