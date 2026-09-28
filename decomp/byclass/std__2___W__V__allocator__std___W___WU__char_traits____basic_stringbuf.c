/* std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[0] */
/* 005550c0  `scalar_deleting_destructor'  46 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall std::basic_stringbuf<char,struct std::char_traits<char>,class
   std::allocator<char> >::`scalar deleting destructor'(unsigned int)
   
   Libraries: Visual Studio 2019 Debug, Visual Studio 2019 Release */

void * __thiscall
std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::
_scalar_deleting_destructor_
          (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *this,uint param_1)

{
  ~basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>(this);
  if ((param_1 & 1) != 0) {
    FUN_008d8efe(this,0x44);
  }
  return this;
}




/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[3] */
/* 0055b920  FUN_0055b920  518 bytes, 0 callers */

uint FUN_0055b920(ushort param_1)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  undefined2 *puVar7;
  char *pcVar8;
  undefined4 uVar9;
  int iVar10;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  int unaff_ESI;
  int local_1c;
  uint local_14;
  undefined2 local_6;
  
  if ((*(uint *)(in_ECX + 0x3c) & 2) == 0) {
    iVar4 = eof(unaff_ESI);
    local_6 = (undefined2)iVar4;
    cVar1 = eq_int_type(&local_6,&param_1);
    if (cVar1 == '\0') {
      pcVar5 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(in_ECX);
      pcVar6 = (char *)FUN_0055b100();
      if ((pcVar5 == (char *)0x0) || (pcVar6 <= pcVar5)) {
        local_14 = 0;
        pcVar8 = std::basic_streambuf<char,std::char_traits<char>_>::eback(in_ECX);
        if (pcVar5 != (char *)0x0) {
          local_14 = (int)pcVar6 - (int)pcVar8 >> 1;
        }
        if (local_14 < 0x20) {
          local_1c = 0x20;
        }
        else if (local_14 < 0x3fffffff) {
          local_1c = local_14 << 1;
        }
        else {
          if (0x7ffffffe < local_14) {
            uVar3 = eof(unaff_ESI);
            return uVar3;
          }
          local_1c = 0x7fffffff;
        }
        uVar9 = allocate(local_1c);
        iVar10 = _Unfancy<>(uVar9);
        FUN_0055a300(iVar10,pcVar8,local_14);
        iVar4 = iVar10 + local_14 * 2;
        *(int *)(in_ECX + 0x38) = iVar4 + 2;
        setg(iVar10,iVar4,iVar10 + local_1c * 2);
        if ((*(uint *)(in_ECX + 0x3c) & 4) == 0) {
          uVar9 = *(undefined4 *)(in_ECX + 0x38);
          pcVar5 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(in_ECX);
          setg(iVar10,iVar10 + ((int)pcVar5 - (int)pcVar8 >> 1) * 2,uVar9);
        }
        else {
          setg(iVar10,0,iVar10);
        }
        if ((*(uint *)(in_ECX + 0x3c) & 1) != 0) {
          uVar9 = FUN_0055bc70(pcVar8,local_14);
          deallocate(uVar9,local_14);
        }
        *(uint *)(in_ECX + 0x3c) = *(uint *)(in_ECX + 0x3c) | 1;
        uVar2 = to_int_type(&param_1);
        puVar7 = (undefined2 *)Pninc();
        *puVar7 = uVar2;
        uVar3 = (uint)param_1;
      }
      else {
        uVar2 = to_int_type(&param_1);
        puVar7 = (undefined2 *)Pninc();
        *puVar7 = uVar2;
        *(char **)(in_ECX + 0x38) = pcVar5 + 2;
        uVar3 = (uint)param_1;
      }
    }
    else {
      uVar3 = not_eof(&param_1);
    }
  }
  else {
    uVar3 = eof(unaff_ESI);
  }
  return uVar3;
}




/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[4] */
/* 0055bb30  FUN_0055bb30  224 bytes, 0 callers */

void FUN_0055bb30(void)

{
  char cVar1;
  undefined2 uVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  int unaff_ESI;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(in_ECX);
  if ((pcVar3 != (char *)0x0) &&
     (pcVar4 = std::basic_streambuf<char,std::char_traits<char>_>::eback(in_ECX), pcVar4 < pcVar3))
  {
    iVar5 = eof(unaff_ESI);
    local_6 = (undefined2)iVar5;
    cVar1 = eq_int_type(&local_6,&stack0x00000004);
    if (cVar1 == '\0') {
      local_8 = to_int_type(&stack0x00000004);
      cVar1 = eq_int_type(&local_8,pcVar3 + -2);
      if ((cVar1 == '\0') && ((*(uint *)(in_ECX + 0x3c) & 2) != 0)) goto LAB_0055bbb2;
    }
    gbump(0xffffffff);
    iVar5 = eof(unaff_ESI);
    local_a = (undefined2)iVar5;
    cVar1 = eq_int_type(&local_a,&stack0x00000004);
    if (cVar1 == '\0') {
      uVar2 = to_int_type(&stack0x00000004);
      pcVar3 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(in_ECX);
      *(undefined2 *)pcVar3 = uVar2;
    }
    not_eof(&stack0x00000004);
    return;
  }
LAB_0055bbb2:
  eof(unaff_ESI);
  return;
}




/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[10] */
/* 0055be90  FUN_0055be90  533 bytes, 0 callers */

undefined4 FUN_0055be90(undefined4 param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint local_30;
  uint uStack_2c;
  char *local_1c;
  
  pcVar1 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(in_ECX);
  if ((*(uint *)(in_ECX + 0x3c) & 2) == 0) {
    local_1c = std::basic_streambuf<char,std::char_traits<char>_>::pptr(in_ECX);
  }
  else {
    local_1c = (char *)0x0;
  }
  if ((local_1c != (char *)0x0) && (*(char **)(in_ECX + 0x38) < local_1c)) {
    *(char **)(in_ECX + 0x38) = local_1c;
  }
  pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::eback(in_ECX);
  uVar6 = *(int *)(in_ECX + 0x38) - (int)pcVar2 >> 1;
  uVar7 = *(int *)(in_ECX + 0x38) - (int)pcVar2 >> 0x1f;
  if (param_4 == 0) {
    local_30 = 0;
    uStack_2c = 0;
LAB_0055bf9f:
    uVar9 = param_3 + uStack_2c + (uint)CARRY4(param_2,local_30);
    if ((uVar9 < uVar7) || ((uVar9 == uVar7 && (param_2 + local_30 <= uVar6)))) {
      iVar5 = param_2 + local_30;
      iVar8 = param_3 + uStack_2c + (uint)CARRY4(param_2,local_30);
      if ((iVar5 == 0 && iVar8 == 0) ||
         ((((param_5 & 1) == 0 || (pcVar1 != (char *)0x0)) &&
          (((param_5 & 2) == 0 || (local_1c != (char *)0x0)))))) {
        iVar3 = __allmul(iVar5,iVar8,2,0);
        if (((param_5 & 1) != 0) && (pcVar1 != (char *)0x0)) {
          setg(pcVar2,pcVar2 + iVar3,*(undefined4 *)(in_ECX + 0x38));
        }
        if (((param_5 & 2) != 0) && (local_1c != (char *)0x0)) {
          uVar4 = FUN_0055b100();
          setg(pcVar2,pcVar2 + iVar3,uVar4);
        }
        FUN_00553510(iVar5,iVar8);
      }
      else {
        FUN_00553510(0xffffffff,0xffffffff);
      }
    }
    else {
      FUN_00553510(0xffffffff,0xffffffff);
    }
  }
  else {
    if (param_4 == 1) {
      if ((param_5 & 3) != 3) {
        if ((param_5 & 1) == 0) {
          if (((param_5 & 2) != 0) && ((local_1c != (char *)0x0 || (pcVar2 == (char *)0x0)))) {
            local_30 = (int)local_1c - (int)pcVar2 >> 1;
            uStack_2c = (int)local_1c - (int)pcVar2 >> 0x1f;
            goto LAB_0055bf9f;
          }
        }
        else if ((pcVar1 != (char *)0x0) || (pcVar2 == (char *)0x0)) {
          local_30 = (int)pcVar1 - (int)pcVar2 >> 1;
          uStack_2c = (int)pcVar1 - (int)pcVar2 >> 0x1f;
          goto LAB_0055bf9f;
        }
      }
    }
    else {
      local_30 = uVar6;
      uStack_2c = uVar7;
      if (param_4 == 2) goto LAB_0055bf9f;
    }
    FUN_00553510(0xffffffff,0xffffffff);
  }
  return param_1;
}




/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[11] */
/* 0055c0d0  FUN_0055c0d0  347 bytes, 0 callers */

/* WARNING: Removing unreachable block (ram,0x0055c15e) */

undefined4 FUN_0055c0d0(undefined4 param_1)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  ulonglong uVar5;
  uint in_stack_00000020;
  char *local_14;
  
  uVar5 = FUN_00554bf0();
  pcVar1 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(in_ECX);
  if ((*(uint *)(in_ECX + 0x3c) & 2) == 0) {
    local_14 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(in_ECX);
  }
  else {
    local_14 = (char *)0x0;
  }
  if ((local_14 != (char *)0x0) && (*(char **)(in_ECX + 0x38) < local_14)) {
    *(char **)(in_ECX + 0x38) = local_14;
  }
  pcVar2 = std::basic_streambuf<char,std::char_traits<char>_>::eback(in_ECX);
  if (CONCAT44(*(int *)(in_ECX + 0x38) - (int)pcVar2 >> 0x1f,
               *(int *)(in_ECX + 0x38) - (int)pcVar2 >> 1) < uVar5) {
    FUN_00553510(0xffffffff,0xffffffff);
  }
  else if ((uVar5 == 0) ||
          ((((in_stack_00000020 & 1) == 0 || (pcVar1 != (char *)0x0)) &&
           (((in_stack_00000020 & 2) == 0 || (local_14 != (char *)0x0)))))) {
    iVar3 = __allmul(uVar5,2,0);
    if (((in_stack_00000020 & 1) != 0) && (pcVar1 != (char *)0x0)) {
      setg(pcVar2,pcVar2 + iVar3,*(undefined4 *)(in_ECX + 0x38));
    }
    if (((in_stack_00000020 & 2) != 0) && (local_14 != (char *)0x0)) {
      uVar4 = FUN_0055b100();
      setg(pcVar2,pcVar2 + iVar3,uVar4);
    }
    FUN_00553510(uVar5);
  }
  else {
    FUN_00553510(0xffffffff,0xffffffff);
  }
  return param_1;
}




/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[12], std::std::_W::_WU?$char_traits::?$basic_streambuf[12] */
/* 0055c230  FUN_0055c230  16 bytes, 0 callers */

undefined4 FUN_0055c230(void)

{
  undefined4 in_ECX;
  
  return in_ECX;
}




/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[5], std::std::_W::_WU?$char_traits::?$basic_streambuf[5] */
/* 0055c330  FUN_0055c330  15 bytes, 0 callers */

undefined8 FUN_0055c330(void)

{
  return 0;
}




/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[7], std::std::_W::_WU?$char_traits::?$basic_streambuf[7] */
/* 0055c670  uflow  98 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short __thiscall std::basic_streambuf<unsigned short,struct
   std::char_traits<unsigned short> >::uflow(void)
    protected: virtual unsigned short __thiscall std::basic_streambuf<wchar_t,struct
   std::char_traits<wchar_t> >::uflow(void)
   
   Libraries: Visual Studio 2012 Debug, Visual Studio 2012 Release */

undefined2 uflow(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined2 local_a;
  undefined2 local_8;
  undefined2 local_6;
  
  local_8 = (**(code **)(*in_ECX + 0x18))();
  iVar2 = eof((int)in_ECX);
  local_a = (undefined2)iVar2;
  cVar1 = eq_int_type(&local_a,&local_8);
  if (cVar1 == '\0') {
    uVar3 = Gninc();
    local_6 = to_int_type(uVar3);
  }
  else {
    iVar2 = eof((int)in_ECX);
    local_6 = (undefined2)iVar2;
  }
  return local_6;
}




/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[6] */
/* 0055c6f0  underflow  200 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall std::basic_stringbuf<char,struct std::char_traits<char>,class
   std::allocator<char> >::underflow(void)
   
   Libraries: Visual Studio 2017 Debug, Visual Studio 2017 Release */

int __thiscall
std::basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_>::underflow
          (basic_stringbuf<char,std::char_traits<char>,std::allocator<char>_> *this)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  uint *puVar4;
  char *pcVar5;
  uint in_stack_ffffffec;
  
  pcVar1 = basic_streambuf<char,std::char_traits<char>_>::gptr
                     ((basic_streambuf<char,std::char_traits<char>_> *)this);
  if (pcVar1 == (char *)0x0) {
    iVar2 = eof(in_stack_ffffffec);
  }
  else {
    pcVar3 = (char *)egptr();
    if (pcVar1 < pcVar3) {
      iVar2 = to_int_type(pcVar1);
    }
    else {
      pcVar3 = basic_streambuf<char,std::char_traits<char>_>::pptr
                         ((basic_streambuf<char,std::char_traits<char>_> *)this);
      if ((pcVar3 == (char *)0x0) || ((*(uint *)(this + 0x3c) & 4) != 0)) {
        iVar2 = eof((int)pcVar3);
      }
      else {
        puVar4 = _Max_value<unsigned_int>((uint *)(this + 0x38),(uint *)&stack0xffffffec);
        pcVar5 = (char *)*puVar4;
        if (pcVar1 < pcVar5) {
          *(char **)(this + 0x38) = pcVar5;
          pcVar1 = basic_streambuf<char,std::char_traits<char>_>::gptr
                             ((basic_streambuf<char,std::char_traits<char>_> *)this);
          pcVar3 = basic_streambuf<char,std::char_traits<char>_>::eback
                             ((basic_streambuf<char,std::char_traits<char>_> *)this);
          setg(pcVar3,pcVar1,pcVar5);
          pcVar1 = basic_streambuf<char,std::char_traits<char>_>::gptr
                             ((basic_streambuf<char,std::char_traits<char>_> *)this);
          iVar2 = to_int_type(pcVar1);
        }
        else {
          iVar2 = eof((int)pcVar3);
        }
      }
    }
  }
  return iVar2;
}




/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[8], std::std::_W::_WU?$char_traits::?$basic_streambuf[8] */
/* 0055c900  FUN_0055c900  300 bytes, 0 callers */

/* WARNING: Removing unreachable block (ram,0x0055c941) */
/* WARNING: Removing unreachable block (ram,0x0055c951) */

undefined8 FUN_0055c900(undefined2 *param_1,uint param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  char *pcVar4;
  int iVar5;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  bool bVar6;
  longlong lVar7;
  uint uVar8;
  uint _FileHandle;
  uint local_18;
  int local_14;
  undefined2 local_a;
  undefined2 local_8 [2];
  
  iVar1 = param_3;
  _FileHandle = param_2;
  while ((-1 < param_3 && ((0 < param_3 || (param_2 != 0))))) {
    lVar7 = Gnavail();
    if (lVar7 < 1) {
      local_8[0] = (**(code **)(*(int *)in_ECX + 0x1c))();
      iVar5 = eof(_FileHandle);
      local_a = (undefined2)iVar5;
      cVar2 = eq_int_type(&local_a,local_8);
      if (cVar2 != '\0') break;
      uVar3 = to_int_type(local_8);
      *param_1 = uVar3;
      param_1 = param_1 + 1;
      bVar6 = param_2 == 0;
      param_2 = param_2 - 1;
      param_3 = param_3 - (uint)bVar6;
    }
    else {
      if (CONCAT44(param_3,param_2) < lVar7) {
        lVar7 = CONCAT44(param_3,param_2);
      }
      local_14 = (int)((ulonglong)lVar7 >> 0x20);
      local_18 = (uint)lVar7;
      uVar8 = local_18;
      pcVar4 = std::basic_streambuf<char,std::char_traits<char>_>::gptr(in_ECX);
      FUN_0055a300(param_1,pcVar4,uVar8);
      iVar5 = __allmul(lVar7,2,0);
      param_1 = (undefined2 *)(iVar5 + (int)param_1);
      bVar6 = param_2 < local_18;
      param_2 = param_2 - local_18;
      param_3 = (param_3 - local_14) - (uint)bVar6;
      gbump(local_18);
    }
  }
  return CONCAT44((iVar1 - param_3) - (uint)(_FileHandle < param_2),_FileHandle - param_2);
}




/* vtable slots: std::2::_W::V?$allocator::std::_W::_WU?$char_traits::?$basic_stringbuf[9], std::std::_W::_WU?$char_traits::?$basic_streambuf[9] */
/* 0055ca30  FUN_0055ca30  298 bytes, 0 callers */

/* WARNING: Removing unreachable block (ram,0x0055ca71) */
/* WARNING: Removing unreachable block (ram,0x0055ca81) */

undefined8 FUN_0055ca30(int param_1,uint param_2,int param_3)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  char *pcVar4;
  int iVar5;
  basic_streambuf<char,std::char_traits<char>_> *in_ECX;
  bool bVar6;
  longlong lVar7;
  uint uVar8;
  uint _FileHandle;
  uint local_14;
  int local_10;
  undefined2 local_8;
  undefined2 local_6;
  
  iVar1 = param_3;
  _FileHandle = param_2;
  while ((-1 < param_3 && ((0 < param_3 || (param_2 != 0))))) {
    lVar7 = Pnavail();
    if (lVar7 < 1) {
      uVar3 = to_int_type(param_1);
      local_6 = (**(code **)(*(int *)in_ECX + 0xc))(uVar3);
      iVar5 = eof(_FileHandle);
      local_8 = (undefined2)iVar5;
      cVar2 = eq_int_type(&local_8,&local_6);
      if (cVar2 != '\0') break;
      param_1 = param_1 + 2;
      bVar6 = param_2 == 0;
      param_2 = param_2 - 1;
      param_3 = param_3 - (uint)bVar6;
    }
    else {
      if (CONCAT44(param_3,param_2) < lVar7) {
        lVar7 = CONCAT44(param_3,param_2);
      }
      local_10 = (int)((ulonglong)lVar7 >> 0x20);
      local_14 = (uint)lVar7;
      iVar5 = param_1;
      uVar8 = local_14;
      pcVar4 = std::basic_streambuf<char,std::char_traits<char>_>::pptr(in_ECX);
      FUN_0055a300(pcVar4,iVar5,uVar8);
      iVar5 = __allmul(lVar7,2,0);
      param_1 = iVar5 + param_1;
      bVar6 = param_2 < local_14;
      param_2 = param_2 - local_14;
      param_3 = (param_3 - local_10) - (uint)bVar6;
      FID_conflict_gbump(local_14);
    }
  }
  return CONCAT44((iVar1 - param_3) - (uint)(_FileHandle < param_2),_FileHandle - param_2);
}



