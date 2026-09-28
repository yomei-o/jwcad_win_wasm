/* std::D::?$ctype -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::D::?$ctype[0] */
/* 008db6b5  `scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void * __thiscall std::ctype<char>::`scalar deleting destructor'(unsigned
   int)
   
   Libraries: Visual Studio 2015 Release, Visual Studio 2017 Release, Visual Studio 2019 Release */

void * __thiscall std::ctype<char>::_scalar_deleting_destructor_(ctype<char> *this,uint param_1)

{
  *(undefined ***)this = vftable;
  _Tidy(this);
  *(undefined ***)this = _Facet_base::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0x18);
  }
  return this;
}




/* vtable slots: std::D::?$ctype[10] */
/* 008de0ee  FUN_008de0ee  10 bytes, 0 callers */

undefined1 FUN_008de0ee(undefined1 param_1)

{
  return param_1;
}




/* vtable slots: std::D::?$ctype[9] */
/* 008de0f8  do_narrow  31 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual char const * __thiscall std::ctype<char>::do_narrow(char const *,char const
   *,char,char *)const 
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

char * __thiscall
std::ctype<char>::do_narrow
          (ctype<char> *this,char *param_1,char *param_2,char param_3,char *param_4)

{
  FUN_008f09e0(param_4,param_1,(int)param_2 - (int)param_1);
  return param_2;
}




/* vtable slots: std::D::?$ctype[4] */
/* 008de78d  do_tolower  23 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual char __thiscall std::ctype<char>::do_tolower(char)const 
   
   Library: Visual Studio 2019 Release */

char __thiscall std::ctype<char>::do_tolower(ctype<char> *this,char param_1)

{
  int iVar1;
  
  iVar1 = __Tolower((uint)(byte)param_1,(_Ctypevec *)(this + 8));
  return (char)iVar1;
}




/* vtable slots: std::D::?$ctype[3] */
/* 008de7a4  do_tolower  44 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual char const * __thiscall std::ctype<char>::do_tolower(char *,char const
   *)const 
   
   Library: Visual Studio 2019 Release */

char * __thiscall std::ctype<char>::do_tolower(ctype<char> *this,char *param_1,char *param_2)

{
  int iVar1;
  
  if (param_1 != param_2) {
    do {
      iVar1 = __Tolower((uint)(byte)*param_1,(_Ctypevec *)(this + 8));
      *param_1 = (byte)iVar1;
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return (char *)(byte *)param_1;
}




/* vtable slots: std::D::?$ctype[6] */
/* 008de7d0  do_toupper  23 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual char __thiscall std::ctype<char>::do_toupper(char)const 
   
   Library: Visual Studio 2019 Release */

char __thiscall std::ctype<char>::do_toupper(ctype<char> *this,char param_1)

{
  int iVar1;
  
  iVar1 = __Toupper((uint)(byte)param_1,(_Ctypevec *)(this + 8));
  return (char)iVar1;
}




/* vtable slots: std::D::?$ctype[5] */
/* 008de7e7  do_toupper  44 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual char const * __thiscall std::ctype<char>::do_toupper(char *,char const
   *)const 
   
   Library: Visual Studio 2019 Release */

char * __thiscall std::ctype<char>::do_toupper(ctype<char> *this,char *param_1,char *param_2)

{
  int iVar1;
  
  if (param_1 != param_2) {
    do {
      iVar1 = __Toupper((uint)(byte)*param_1,(_Ctypevec *)(this + 8));
      *param_1 = (byte)iVar1;
      param_1 = param_1 + 1;
    } while (param_1 != param_2);
  }
  return (char *)(byte *)param_1;
}




/* vtable slots: std::D::?$ctype[8] */
/* 008de83a  FUN_008de83a  10 bytes, 0 callers */

undefined1 FUN_008de83a(undefined1 param_1)

{
  return param_1;
}




/* vtable slots: std::D::?$ctype[7] */
/* 008de844  do_widen  31 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual char const * __thiscall std::ctype<char>::do_widen(char const *,char const
   *,char *)const 
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release, Visual Studio 2017 Release,
   Visual Studio 2019 Release */

char * __thiscall
std::ctype<char>::do_widen(ctype<char> *this,char *param_1,char *param_2,char *param_3)

{
  FUN_008f09e0(param_3,param_1,(int)param_2 - (int)param_1);
  return param_2;
}



