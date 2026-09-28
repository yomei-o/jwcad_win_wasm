/* CArchiveException -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CArchiveException[3], CFileException[3], CInvalidArgException[3], CMemoryException[3], CNotSupportedException[3], COleException[3], CResourceException[3], CSimpleException[3], CUserException[3] */
/* 0078e7e3  widen  39 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: char const * __thiscall std::ctype<char>::widen(char const *,char const *,char *)const 
    public: char const * __thiscall std::ctype<unsigned short>::widen(char const *,char const
   *,unsigned short *)const 
    public: char const * __thiscall std::ctype<wchar_t>::widen(char const *,char const *,wchar_t
   *)const 
   
   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */

void widen(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x10);
  guard_check_icall(param_1,param_2,param_3);
  (*pcVar1)();
  return;
}




/* vtable slots: CArchiveException[5], CFileException[5], CInvalidArgException[5], CMemoryException[5], CNotSupportedException[5], COleException[5], CResourceException[5], CSimpleException[5], CUserException[5] */
/* 0078e8a6  FUN_0078e8a6  129 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0078e8a6(uint param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  uint local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*in_ECX + 0xc);
  guard_check_icall(local_408,0x200,&local_40c);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    if (param_2 == 0) {
      param_2 = 0xf020;
    }
    AfxMessageBox(param_2,param_1,local_40c);
  }
  else {
    FUN_0079f557(local_408,param_1,local_40c);
  }
  return;
}




/* vtable slots: CArchiveException[1] */
/* 007a568f  `scalar_deleting_destructor'  60 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CArchiveException::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CArchiveException::_scalar_deleting_destructor_(CArchiveException *this,uint param_1)

{
  *(undefined ***)this = vftable;
  FUN_00406b10();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x10);
    }
  }
  return this;
}




/* vtable slots: CArchiveException[4] */
/* 007a570d  FUN_007a570d  180 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007a570d(int param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  UINT in_stack_ffffffd0;
  LPSTR in_stack_ffffffd4;
  int in_stack_ffffffd8;
  undefined4 local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  if (param_1 == 0) {
    uVar2 = 0;
  }
  else {
    if (param_3 != (int *)0x0) {
      *param_3 = *(int *)(in_ECX + 8) + 0xf1b0;
    }
    local_8 = 0;
    CStringT<>();
    local_8._0_1_ = 1;
    iVar1 = FUN_004054a0(*(int *)(in_ECX + 0xc) + -0x10);
    local_8 = CONCAT31(local_8._1_3_,2);
    if (*(int *)(iVar1 + 4) == 0) {
      FID_conflict_LoadStringA
                ((HINSTANCE)0xf006,in_stack_ffffffd0,in_stack_ffffffd4,in_stack_ffffffd8);
    }
    FUN_007c1390(local_18,*(int *)(in_ECX + 8) + 0xf1b0,iVar1 + 0x10);
    uVar2 = FUN_008f8e5e(param_1,param_2,local_18[0],0xffffffff);
    FUN_00404bd0(uVar2);
    FUN_00406b10();
    FUN_00406b10();
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CArchiveException[0] */
/* 007a57c7  FUN_007a57c7  6 bytes, 0 callers */

undefined ** FUN_007a57c7(void)

{
  return &PTR_s_CArchiveException_0097f324;
}



