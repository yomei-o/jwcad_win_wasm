/* std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[9] */
/* 008de117  do_put  107 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base
   &,char,long)const 
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base
   &,char,unsigned long)const 
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
     6 names - too many to list
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 do_put(undefined4 param_1)

{
  char *pcVar1;
  num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_> *in_ECX;
  undefined4 in_stack_00000018;
  wchar_t local_50 [32];
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = std::num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::_Ifmt
                     (in_ECX,(char *)in_ECX,local_10,0x969934);
  FID_conflict__swprintf(local_50,(wchar_t *)0x40,pcVar1,in_stack_00000018);
  FUN_008dced9();
  return param_1;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[8] */
/* 008de182  do_put  107 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base
   &,char,long)const 
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base
   &,char,unsigned long)const 
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
     6 names - too many to list
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 do_put(undefined4 param_1)

{
  char *pcVar1;
  num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_> *in_ECX;
  undefined4 in_stack_00000018;
  wchar_t local_50 [32];
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = std::num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::_Ifmt
                     (in_ECX,(char *)in_ECX,local_10,0x969930);
  FID_conflict__swprintf(local_50,(wchar_t *)0x40,pcVar1,in_stack_00000018);
  FUN_008dced9();
  return param_1;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[5] */
/* 008de1ed  FUN_008de1ed  342 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008de1ed(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5,double param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t ***pppwVar4;
  undefined4 uVar5;
  uint uVar6;
  wchar_t **local_3c;
  uint local_38;
  wchar_t **local_34 [4];
  wchar_t *local_24;
  uint local_20;
  undefined1 local_1c [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_24 = (wchar_t *)0x0;
  local_20 = 0xf;
  local_34[0] = (wchar_t **)0x0;
  uVar6 = *(uint *)(param_4 + 0x14) & 0x3000;
  local_8 = 1;
  if (uVar6 == 0x3000) {
    uVar5 = 0xffffffff;
    uVar1 = 0xffffffff;
  }
  else {
    uVar5 = *(undefined4 *)(param_4 + 0x18);
    uVar1 = *(undefined4 *)(param_4 + 0x1c);
  }
  iVar2 = FUN_00551fe0(uVar5,uVar1,uVar6);
  uVar1 = (undefined4)((ulonglong)param_6 >> 0x20);
  if ((uVar6 == 0x2000) && (10000000000.0 < ABS(param_6))) {
    FUN_0090509a(SUB84(param_6,0),uVar1,&local_3c);
    iVar2 = iVar2 + (int)((((uint)local_3c ^ (int)local_3c >> 0x1f) - ((int)local_3c >> 0x1f)) *
                         0x7597) / 100000;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,
             iVar2 + 0x32,'\0');
  uVar3 = Ffmt(local_38,local_1c,0,*(undefined4 *)(param_4 + 0x14));
  pppwVar4 = local_34;
  if (0xf < local_20) {
    pppwVar4 = (wchar_t ***)local_34[0];
  }
  iVar2 = FID_conflict__swprintf((wchar_t *)pppwVar4,local_24,uVar3,uVar5,SUB84(param_6,0),uVar1);
  pppwVar4 = local_34;
  if (0xf < local_20) {
    pppwVar4 = (wchar_t ***)local_34[0];
  }
  FUN_008db7a6(local_38,param_1,param_2,param_3,param_4,param_5,pppwVar4,iVar2);
  if (0xf < local_20) {
    local_38 = local_20 + 1;
    local_3c = local_34[0];
    if (0xfff < local_38) {
      FUN_0048ead0(&local_3c,&local_38);
    }
    FUN_008d8efe(local_3c,local_38);
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[4] */
/* 008de343  FUN_008de343  342 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008de343(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined4 param_5,double param_6)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  wchar_t ***pppwVar4;
  undefined4 uVar5;
  uint uVar6;
  wchar_t **local_3c;
  uint local_38;
  wchar_t **local_34 [4];
  wchar_t *local_24;
  uint local_20;
  undefined1 local_1c [20];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x34;
  local_24 = (wchar_t *)0x0;
  local_20 = 0xf;
  local_34[0] = (wchar_t **)0x0;
  uVar6 = *(uint *)(param_4 + 0x14) & 0x3000;
  local_8 = 1;
  if (uVar6 == 0x3000) {
    uVar5 = 0xffffffff;
    uVar1 = 0xffffffff;
  }
  else {
    uVar5 = *(undefined4 *)(param_4 + 0x18);
    uVar1 = *(undefined4 *)(param_4 + 0x1c);
  }
  iVar2 = FUN_00551fe0(uVar5,uVar1,uVar6);
  uVar1 = (undefined4)((ulonglong)param_6 >> 0x20);
  if ((uVar6 == 0x2000) && (10000000000.0 < ABS(param_6))) {
    FUN_0090509a(SUB84(param_6,0),uVar1,&local_3c);
    iVar2 = iVar2 + (int)((((uint)local_3c ^ (int)local_3c >> 0x1f) - ((int)local_3c >> 0x1f)) *
                         0x7597) / 100000;
  }
  std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::resize
            ((basic_string<char,std::char_traits<char>,std::allocator<char>_> *)local_34,
             iVar2 + 0x32,'\0');
  uVar3 = Ffmt(local_38,local_1c,0x4c,*(undefined4 *)(param_4 + 0x14));
  pppwVar4 = local_34;
  if (0xf < local_20) {
    pppwVar4 = (wchar_t ***)local_34[0];
  }
  iVar2 = FID_conflict__swprintf((wchar_t *)pppwVar4,local_24,uVar3,uVar5,SUB84(param_6,0),uVar1);
  pppwVar4 = local_34;
  if (0xf < local_20) {
    pppwVar4 = (wchar_t ***)local_34[0];
  }
  FUN_008db7a6(local_38,param_1,param_2,param_3,param_4,param_5,pppwVar4,iVar2);
  if (0xf < local_20) {
    local_38 = local_20 + 1;
    local_3c = local_34[0];
    if (0xfff < local_38) {
      FUN_0048ead0(&local_3c,&local_38);
    }
    FUN_008d8efe(local_3c,local_38);
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[3] */
/* 008de499  do_put  91 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base
   &,char,void const *)const 
    protected: virtual class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > __thiscall std::num_put<unsigned short,class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> > >::do_put(class
   std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >,class
   std::ios_base &,unsigned short,void const *)const 
    protected: virtual class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   __thiscall std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::do_put(class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> >,class std::ios_base &,wchar_t,void const *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 do_put(undefined4 param_1)

{
  undefined4 in_stack_00000018;
  wchar_t local_48 [32];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FID_conflict__swprintf(local_48,(wchar_t *)0x40,&DAT_00969924,in_stack_00000018);
  FUN_008dced9();
  return param_1;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[7] */
/* 008de4f4  do_put  110 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base
   &,char,__int64)const 
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base
   &,char,unsigned __int64)const 
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
     6 names - too many to list
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 do_put(undefined4 param_1)

{
  char *pcVar1;
  num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_> *in_ECX;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  wchar_t local_50 [32];
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = std::num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::_Ifmt
                     (in_ECX,(char *)in_ECX,local_10,0x96992c);
  FID_conflict__swprintf(local_50,(wchar_t *)0x40,pcVar1,in_stack_00000018,in_stack_0000001c);
  FUN_008dced9();
  return param_1;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[6] */
/* 008de562  do_put  110 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Multiple Matches With Same Base Name
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base
   &,char,__int64)const 
    protected: virtual class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   __thiscall std::num_put<char,class std::ostreambuf_iterator<char,struct std::char_traits<char> >
   >::do_put(class std::ostreambuf_iterator<char,struct std::char_traits<char> >,class std::ios_base
   &,char,unsigned __int64)const 
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
     6 names - too many to list
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

undefined4 do_put(undefined4 param_1)

{
  char *pcVar1;
  num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_> *in_ECX;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  wchar_t local_50 [32];
  char local_10 [8];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = std::num_put<char,std::ostreambuf_iterator<char,std::char_traits<char>_>_>::_Ifmt
                     (in_ECX,(char *)in_ECX,local_10,0x969928);
  FID_conflict__swprintf(local_50,(wchar_t *)0x40,pcVar1,in_stack_00000018,in_stack_0000001c);
  FUN_008dced9();
  return param_1;
}




/* vtable slots: std::std::std::D::DU?$char_traits::DV?$ostreambuf_iterator::?$num_put[10] */
/* 008de5d0  FUN_008de5d0  441 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008de5d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined1 param_5,char param_6)

{
  int ***pppiVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int ****ppppiVar6;
  int ****in_ECX;
  int iVar7;
  undefined1 local_58 [4];
  uint local_54;
  uint local_50;
  int ***local_4c;
  char local_45;
  basic_string<char,std::char_traits<char>,std::allocator<char>_> local_44 [24];
  int ***local_2c [4];
  uint local_1c;
  uint local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4c;
  local_8 = 0x8de5dc;
  local_50 = CONCAT31(local_50._1_3_,param_5);
  local_4c = (int ***)in_ECX;
  if ((*(uint *)(param_4 + 0x14) & 0x4000) == 0) {
    pppiVar1 = *in_ECX;
    guard_check_icall(param_1,param_2,param_3,param_4,local_50,param_6);
    (*(code *)pppiVar1[9])();
  }
  else {
    FUN_00553da0(*(undefined4 *)(param_4 + 0x30));
    local_8 = 0;
    piVar4 = (int *)FUN_008db54f(local_58);
    FUN_005546e0();
    local_1c = 0;
    local_18 = 0xf;
    local_2c[0] = (int ***)0x0;
    iVar7 = *piVar4;
    local_8 = 2;
    if (param_6 == '\0') {
      guard_check_icall(local_44);
      (**(code **)(iVar7 + 0x18))();
    }
    else {
      guard_check_icall(local_44);
      (**(code **)(iVar7 + 0x1c))();
    }
    local_54 = local_54 & 0xffffff00;
    FUN_008dd530(local_44,local_54);
    std::basic_string<char,std::char_traits<char>,std::allocator<char>_>::_Tidy_deallocate(local_44)
    ;
    if ((*(int *)(param_4 + 0x24) < 0) ||
       (((*(int *)(param_4 + 0x24) < 1 && (*(int *)(param_4 + 0x20) == 0)) ||
        (*(uint *)(param_4 + 0x20) <= local_1c)))) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(uint *)(param_4 + 0x20) - local_1c;
    }
    if ((*(uint *)(param_4 + 0x14) & 0x1c0) != 0x40) {
      puVar5 = (undefined4 *)FUN_008dd5e0(local_4c,local_58,param_2,param_3,local_50,iVar7);
      iVar7 = 0;
      param_2 = *puVar5;
      param_3 = puVar5[1];
    }
    pppiVar1 = local_2c[0];
    local_45 = '\x01' - (local_18 < 0x10);
    ppppiVar6 = (int ****)local_2c[0];
    if (local_18 < 0x10) {
      ppppiVar6 = local_2c;
    }
    puVar5 = (undefined4 *)FUN_008dd5ad(local_4c,local_58,param_2,param_3,ppppiVar6,local_1c);
    uVar2 = *puVar5;
    uVar3 = puVar5[1];
    *(undefined4 *)(param_4 + 0x20) = 0;
    *(undefined4 *)(param_4 + 0x24) = 0;
    FUN_008dd5e0(local_4c,param_1,uVar2,uVar3,local_50,iVar7);
    if (local_45 != '\0') {
      local_50 = local_18 + 1;
      local_4c = pppiVar1;
      if (0xfff < local_50) {
        FUN_0048ead0(&local_4c,&local_50);
      }
      FUN_008d8efe(local_4c,local_50);
    }
  }
  FUN_008d9b68();
  return;
}



