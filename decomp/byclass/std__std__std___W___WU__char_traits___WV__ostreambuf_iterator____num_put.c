/* std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[0] */
/* 00555160  FID_conflict:`scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Multiple Matches With Different Base Names
    public: void * __thiscall std::_Func_impl<bool (__cdecl*)(enum Concurrency::agent_status const
   &),class std::allocator<int>,bool,enum Concurrency::agent_status const &>::`scalar deleting
   destructor'(unsigned int)
    public: void * __thiscall std::_Func_impl<class <lambda_0b644b0099f9cbc573e00435de85ed83>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *>::`scalar deleting
   destructor'(unsigned int)
    public: void * __thiscall std::_Func_impl<class <lambda_4471c1faea23acf00f5de6f001106c5d>,class
   std::allocator<int>,void,class Concurrency::message<enum Concurrency::agent_status> *>::`scalar
   deleting destructor'(unsigned int)
    public: void * __thiscall std::_Func_impl<class <lambda_585d1183dd7288406f8b545e733d6ea7>,class
   std::allocator<int>,void,class Concurrency::message<unsigned int> *>::`scalar deleting
   destructor'(unsigned int)
     6 names - too many to list
   
   Libraries: Visual Studio 2015 Debug, Visual Studio 2015 Release */

undefined4 FID_conflict__scalar_deleting_destructor_(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00554320();
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(in_ECX,8);
  }
  return in_ECX;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[9] */
/* 0055a530  do_put  125 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,long)const 
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,unsigned long)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,long)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,unsigned long)const 
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4
do_put(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
      undefined2 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_ECX;
  wchar_t local_50 [32];
  undefined1 local_10 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar1 = FUN_0055b250(param_6);
  uVar1 = Ifmt(in_ECX,local_10,&DAT_00969934,uVar1);
  iVar2 = FID_conflict__swprintf(local_50,(wchar_t *)0x40,uVar1);
  FUN_00559140(in_ECX,param_1,param_2,param_3,param_4,param_5,local_50,iVar2);
  return param_1;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[8] */
/* 0055a5b0  do_put  125 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,long)const 
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,unsigned long)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,long)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,unsigned long)const 
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4
do_put(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
      undefined2 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_ECX;
  wchar_t local_50 [32];
  undefined1 local_10 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar1 = FUN_0055b250(param_6);
  uVar1 = Ifmt(in_ECX,local_10,&DAT_00969930,uVar1);
  iVar2 = FID_conflict__swprintf(local_50,(wchar_t *)0x40,uVar1);
  FUN_00559140(in_ECX,param_1,param_2,param_3,param_4,param_5,local_50,iVar2);
  return param_1;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[5] */
/* 0055a630  FUN_0055a630  492 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0055a630(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,double param_6)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *_Format;
  wchar_t *_Dest;
  double dVar3;
  int local_5c;
  int local_58;
  undefined8 local_54;
  undefined8 local_4c;
  undefined4 local_44;
  int local_40;
  uint local_3c;
  char local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_34 [24];
  undefined1 local_1c [8];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c78d;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00553110(local_14);
  local_8 = 0;
  local_3c = FUN_0055b250();
  local_3c = local_3c & 0x3000;
  local_38 = local_3c == 0x2000;
  local_37 = local_3c == 0x3000;
  local_36 = local_37;
  local_35 = local_38;
  if ((bool)local_37) {
    local_4c = 0xffffffffffffffff;
  }
  else {
    local_4c = FUN_0055bcb0();
  }
  local_54 = local_4c;
  local_58 = FUN_00551fe0(local_4c,local_3c);
  uVar2 = (undefined4)((ulonglong)param_6 >> 0x20);
  local_40 = local_58;
  if (local_38 != '\0') {
    dVar3 = _fabs(param_6);
    if (10000000000.0 < dVar3) {
      FUN_0090509a(SUB84(param_6,0),uVar2,&local_5c);
      iVar1 = _abs(local_5c);
      local_40 = (iVar1 * 0x7597) / 100000 + local_40;
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize
            (local_34,local_40 + 0x32,'\0');
  uVar2 = FUN_0055b250((undefined4)local_54,SUB84(param_6,0),uVar2);
  uVar2 = Ffmt(local_44,local_1c,0,uVar2);
  _Format = (wchar_t *)FUN_004f7800(uVar2);
  _Dest = (wchar_t *)
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator[]
                    (local_34,0);
  iVar1 = FID_conflict__swprintf(_Dest,_Format);
  uVar2 = FUN_004f1180(iVar1);
  FUN_005581c0(local_44,param_1,param_2,param_3,param_4,param_5,uVar2);
  local_8 = 0xffffffff;
  FUN_004da320();
  ExceptionList = local_10;
  return param_1;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[4] */
/* 0055a820  FUN_0055a820  492 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_0055a820(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined2 param_5,undefined8 param_6)

{
  int iVar1;
  undefined4 uVar2;
  wchar_t *_Format;
  wchar_t *_Dest;
  float10 fVar3;
  undefined4 uVar4;
  int local_5c;
  int local_58;
  undefined8 local_54;
  undefined8 local_4c;
  undefined4 local_44;
  int local_40;
  uint local_3c;
  char local_38;
  undefined1 local_37;
  undefined1 local_36;
  undefined1 local_35;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_34 [24];
  undefined1 local_1c [8];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c78d;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00553110(local_14);
  local_8 = 0;
  local_3c = FUN_0055b250();
  local_3c = local_3c & 0x3000;
  local_38 = local_3c == 0x2000;
  local_37 = local_3c == 0x3000;
  local_36 = local_37;
  local_35 = local_38;
  if ((bool)local_37) {
    local_4c = 0xffffffffffffffff;
  }
  else {
    local_4c = FUN_0055bcb0();
  }
  local_54 = local_4c;
  local_58 = FUN_00551fe0(local_4c,local_3c);
  uVar2 = (undefined4)param_6;
  uVar4 = (undefined4)((ulonglong)param_6 >> 0x20);
  local_40 = local_58;
  if (local_38 != '\0') {
    fVar3 = (float10)FUN_00459780(uVar2,uVar4);
    if (10000000000.0 < (double)fVar3) {
      FUN_0055cb60(uVar2,uVar4,&local_5c);
      iVar1 = _abs(local_5c);
      local_40 = (iVar1 * 0x7597) / 100000 + local_40;
    }
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize
            (local_34,local_40 + 0x32,'\0');
  uVar2 = FUN_0055b250((undefined4)local_54,uVar2,uVar4);
  uVar2 = Ffmt(local_44,local_1c,0x4c,uVar2);
  _Format = (wchar_t *)FUN_004f7800(uVar2);
  _Dest = (wchar_t *)
          std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::operator[]
                    (local_34,0);
  iVar1 = FID_conflict__swprintf(_Dest,_Format);
  uVar2 = FUN_004f1180(iVar1);
  FUN_005581c0(local_44,param_1,param_2,param_3,param_4,param_5,uVar2);
  local_8 = 0xffffffff;
  FUN_004da320();
  ExceptionList = local_10;
  return param_1;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[3] */
/* 0055aa10  do_put  99 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,void const *)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,void const *)const 
   
   Libraries: Visual Studio 2012, Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4
do_put(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
      undefined2 param_5,undefined4 param_6)

{
  int iVar1;
  undefined4 in_ECX;
  wchar_t local_48 [32];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar1 = FID_conflict__swprintf(local_48,(wchar_t *)0x40,&DAT_00969924,param_6);
  FUN_00559140(in_ECX,param_1,param_2,param_3,param_4,param_5,local_48,iVar1);
  return param_1;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[7] */
/* 0055aa80  do_put  129 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,__int64)const 
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,unsigned __int64)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,__int64)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,unsigned __int64)const 
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4
do_put(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
      undefined2 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_ECX;
  wchar_t local_50 [32];
  undefined1 local_10 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar1 = FUN_0055b250(param_6,param_7);
  uVar1 = Ifmt(in_ECX,local_10,&DAT_0096992c,uVar1);
  iVar2 = FID_conflict__swprintf(local_50,(wchar_t *)0x40,uVar1);
  FUN_00559140(in_ECX,param_1,param_2,param_3,param_4,param_5,local_50,iVar2);
  return param_1;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[6] */
/* 0055ab10  do_put  129 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,__int64)const 
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,unsigned __int64)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,__int64)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,unsigned __int64)const 
   
   Libraries: Visual Studio 2015, Visual Studio 2017, Visual Studio 2019 */

undefined4
do_put(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
      undefined2 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_ECX;
  wchar_t local_50 [32];
  undefined1 local_10 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar1 = FUN_0055b250(param_6,param_7);
  uVar1 = Ifmt(in_ECX,local_10,&DAT_00969928,uVar1);
  iVar2 = FID_conflict__swprintf(local_50,(wchar_t *)0x40,uVar1);
  FUN_00559140(in_ECX,param_1,param_2,param_3,param_4,param_5,local_50,iVar2);
  return param_1;
}




/* vtable slots: std::std::std::_W::_WU?$char_traits::_WV?$ostreambuf_iterator::?$num_put[10] */
/* 0055aba0  FUN_0055aba0  569 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0055acc7) */

undefined4
FUN_0055aba0(undefined4 param_1,undefined4 param_2,undefined4 param_3,ios_base *param_4,
            undefined2 param_5,char param_6)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined1 local_98 [8];
  undefined1 local_90 [16];
  longlong local_80;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  int local_64;
  int *local_60;
  undefined1 local_5c [24];
  undefined1 local_44 [48];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092c7d8;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar2 = FUN_0055b250(local_14);
  if ((uVar2 & 0x4000) == 0) {
    (**(code **)(*local_60 + 0x24))(param_1,param_2,param_3,param_4,param_5,param_6);
    ExceptionList = local_10;
    return param_1;
  }
  local_70 = std::ios_base::getloc(param_4);
  local_8 = 0;
  local_6c = local_70;
  local_68 = FUN_00552aa0(local_70);
  local_8 = 0xffffffff;
  FUN_005546e0();
  FUN_00553300();
  local_8 = 1;
  if (param_6 == '\0') {
    local_78 = FUN_0055b1f0(local_5c);
    FID_conflict_assign(local_78);
    ~basic_string<>();
  }
  else {
    local_74 = FUN_0055c630(local_44);
    FID_conflict_assign(local_74);
    ~basic_string<>();
  }
  local_80 = FUN_0055c8e0();
  if (0 < local_80) {
    uVar2 = FUN_0055c8e0();
    uVar3 = FUN_004f7800();
    if (uVar3 < uVar2) {
      iVar4 = FUN_0055c8e0();
      local_64 = FUN_004f7800();
      local_64 = iVar4 - local_64;
      goto LAB_0055ad03;
    }
  }
  local_64 = 0;
LAB_0055ad03:
  uVar2 = FUN_0055b250();
  if ((uVar2 & 0x1c0) != 0x40) {
    puVar5 = (undefined4 *)FUN_005598d0(local_60,local_90,param_2,param_3,param_5,local_64);
    param_2 = *puVar5;
    param_3 = puVar5[1];
    local_64 = 0;
  }
  uVar6 = FUN_004f7800();
  uVar6 = FUN_0055a180(uVar6);
  puVar5 = (undefined4 *)FUN_00559880(local_60,local_98,param_2,param_3,uVar6);
  uVar6 = *puVar5;
  uVar1 = puVar5[1];
  FUN_0055c8a0(0,0);
  FUN_005598d0(local_60,param_1,uVar6,uVar1,param_5,local_64);
  local_8 = 0xffffffff;
  ~basic_string<>();
  ExceptionList = local_10;
  return param_1;
}



