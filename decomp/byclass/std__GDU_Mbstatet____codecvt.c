/* std::GDU_Mbstatet::?$codecvt -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::GDU_Mbstatet::?$codecvt[0], std::_WDU_Mbstatet::?$codecvt[0] */
/* 008e114d  FUN_008e114d  35 bytes, 0 callers */

void FUN_008e114d(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = std::_Facet_base::vftable;
  if ((param_1 & 1) != 0) {
    FUN_008d8efe();
  }
  return;
}




/* vtable slots: std::GDU_Mbstatet::?$codecvt[3], std::_WDU_Mbstatet::?$codecvt[3] */
/* 008e8483  FUN_008e8483  3 bytes, 0 callers */

undefined1 FUN_008e8483(void)

{
  return 0;
}




/* vtable slots: std::GDU_Mbstatet::?$codecvt[5], std::_WDU_Mbstatet::?$codecvt[5] */
/* 008e851b  FUN_008e851b  10 bytes, 0 callers */

bool FUN_008e851b(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xc) == 1;
}




/* vtable slots: std::GDU_Mbstatet::?$codecvt[6], std::_WDU_Mbstatet::?$codecvt[6] */
/* 008eb0ca  do_in  113 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall std::codecvt<unsigned short,char,struct
   _Mbstatet>::do_in(struct _Mbstatet &,char const *,char const *,char const * &,unsigned short
   *,unsigned short *,unsigned short * &)const 
    protected: virtual int __thiscall std::codecvt<wchar_t,char,struct _Mbstatet>::do_in(struct
   _Mbstatet &,char const *,char const *,char const * &,wchar_t *,wchar_t *,wchar_t * &)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4
do_in(undefined4 param_1,int param_2,char *param_3,int *param_4,wchar_t *param_5,wchar_t *param_6,
     int *param_7)

{
  char *pcVar1;
  int iVar2;
  int in_ECX;
  mbstate_t local_c [2];
  
  local_c[0] = 0;
  local_c[1] = 0;
  *param_4 = param_2;
  *param_7 = (int)param_5;
  while( true ) {
    pcVar1 = (char *)*param_4;
    if (pcVar1 == param_3) {
      return 0;
    }
    if ((param_5 == param_6) ||
       (iVar2 = __Mbrtowc(param_5,pcVar1,(int)param_3 - (int)pcVar1,local_c,(_Cvtvec *)(in_ECX + 8))
       , iVar2 == -2)) break;
    if (iVar2 == -1) {
      return 2;
    }
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    *param_4 = *param_4 + iVar2;
    *param_7 = *param_7 + 2;
    param_5 = (wchar_t *)*param_7;
  }
  return 1;
}




/* vtable slots: std::GDU_Mbstatet::?$codecvt[9], std::_WDU_Mbstatet::?$codecvt[9] */
/* 008eb173  do_length  86 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall std::codecvt<unsigned short,char,struct
   _Mbstatet>::do_length(struct _Mbstatet &,char const *,char const *,unsigned int)const 
    protected: virtual int __thiscall std::codecvt<wchar_t,char,struct _Mbstatet>::do_length(struct
   _Mbstatet &,char const *,char const *,unsigned int)const 
   
   Library: Visual Studio 2019 Release */

int do_length(mbstate_t *param_1,char *param_2,char *param_3,int param_4)

{
  int iVar1;
  int in_ECX;
  char *pcVar2;
  wchar_t local_8 [2];
  
  for (pcVar2 = param_2; (param_4 != 0 && (pcVar2 != param_3)); pcVar2 = pcVar2 + iVar1) {
    iVar1 = __Mbrtowc(local_8,pcVar2,(int)param_3 - (int)pcVar2,param_1,(_Cvtvec *)(in_ECX + 8));
    if (iVar1 < 0) break;
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    param_4 = param_4 + -1;
  }
  return (int)pcVar2 - (int)param_2;
}




/* vtable slots: std::GDU_Mbstatet::?$codecvt[7], std::_WDU_Mbstatet::?$codecvt[7] */
/* 008eb240  do_out  230 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall std::codecvt<unsigned short,char,struct
   _Mbstatet>::do_out(struct _Mbstatet &,unsigned short const *,unsigned short const *,unsigned
   short const * &,char *,char *,char * &)const 
    protected: virtual int __thiscall std::codecvt<wchar_t,char,struct _Mbstatet>::do_out(struct
   _Mbstatet &,wchar_t const *,wchar_t const *,wchar_t const * &,char *,char *,char * &)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

bool do_out(mbstate_t *param_1,int param_2,wchar_t *param_3,int *param_4,char *param_5,char *param_6
           ,int *param_7)

{
  mbstate_t mVar1;
  mbstate_t mVar2;
  int iVar3;
  int in_ECX;
  wchar_t *pwVar4;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *param_4 = param_2;
  *param_7 = (int)param_5;
  do {
    pwVar4 = (wchar_t *)*param_4;
    if ((pwVar4 == param_3) || (param_5 == param_6)) goto LAB_008eb2fe;
    if ((int)param_6 - (int)param_5 < 5) {
      mVar1 = *param_1;
      mVar2 = param_1[1];
      iVar3 = __Wcrtomb(local_10,*pwVar4,param_1,(_Cvtvec *)(in_ECX + 8));
      if (iVar3 < 0) {
        return (bool)2;
      }
      if ((int)param_6 - *param_7 < iVar3) {
        *param_1 = mVar1;
        param_1[1] = mVar2;
        pwVar4 = (wchar_t *)*param_4;
LAB_008eb2fe:
        return pwVar4 != param_3;
      }
      FUN_008f09e0(*param_7,local_10,iVar3);
    }
    else {
      iVar3 = __Wcrtomb(param_5,*pwVar4,param_1,(_Cvtvec *)(in_ECX + 8));
      if (iVar3 < 0) {
        return (bool)2;
      }
    }
    *param_4 = *param_4 + 2;
    *param_7 = *param_7 + iVar3;
    param_5 = (char *)*param_7;
  } while( true );
}




/* vtable slots: std::GDU_Mbstatet::?$codecvt[8], std::_WDU_Mbstatet::?$codecvt[8] */
/* 008ec372  do_unshift  144 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall std::codecvt<unsigned short,char,struct
   _Mbstatet>::do_unshift(struct _Mbstatet &,char *,char *,char * &)const 
    protected: virtual int __thiscall std::codecvt<wchar_t,char,struct _Mbstatet>::do_unshift(struct
   _Mbstatet &,char *,char *,char * &)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 do_unshift(mbstate_t *param_1,int param_2,int param_3,int *param_4)

{
  mbstate_t mVar1;
  mbstate_t mVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar4 = 0;
  *param_4 = param_2;
  mVar1 = *param_1;
  mVar2 = param_1[1];
  iVar3 = __Wcrtomb(local_10,L'\0',param_1,(_Cvtvec *)(in_ECX + 8));
  if (iVar3 < 1) {
    uVar4 = 2;
  }
  else {
    iVar3 = iVar3 + -1;
    if (param_3 - *param_4 < iVar3) {
      uVar4 = 1;
      *param_1 = mVar1;
      param_1[1] = mVar2;
    }
    else if (0 < iVar3) {
      FUN_008f09e0(*param_4,local_10,iVar3);
      *param_4 = *param_4 + iVar3;
    }
  }
  return uVar4;
}



