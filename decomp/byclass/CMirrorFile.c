/* CMirrorFile -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMirrorFile[1] */
/* 007a8fd0  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMirrorFile::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMirrorFile::_scalar_deleting_destructor_(CMirrorFile *this,uint param_1)

{
  ~CMirrorFile(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x18);
    }
  }
  return this;
}




/* vtable slots: CMirrorFile[18] */
/* 007a9000  Abort  27 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMirrorFile::Abort(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMirrorFile::Abort(CMirrorFile *this)

{
  CFile::Abort((CFile *)this);
  if (*(int *)(*(int *)(this + 0x14) + -0xc) != 0) {
    Remove(*(int *)(this + 0x14),0);
  }
  return;
}




/* vtable slots: CMirrorFile[20] */
/* 007a926a  FUN_007a926a  100 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007a926a(void)

{
  LPCWSTR lpReplacedFileName;
  int iVar1;
  BOOL BVar2;
  int in_ECX;
  
  iVar1 = FUN_004054a0(*(int *)(in_ECX + 0xc) + -0x10);
  lpReplacedFileName = (LPCWSTR)(iVar1 + 0x10);
  FUN_007a7834();
  if (*(int *)(*(LPCWSTR *)(in_ECX + 0x14) + -6) != 0) {
    BVar2 = ReplaceFileW(lpReplacedFileName,*(LPCWSTR *)(in_ECX + 0x14),(LPCWSTR)0x0,0,(LPVOID)0x0,
                         (LPVOID)0x0);
    if (BVar2 == 0) {
      Remove(lpReplacedFileName,0);
      Rename(*(undefined4 *)(in_ECX + 0x14),lpReplacedFileName,0);
    }
  }
  FUN_00406b10();
  return;
}




/* vtable slots: CMirrorFile[9] */
/* 007aa4c8  FUN_007aa4c8  628 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007aa4c8(wchar_t *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  BOOL BVar2;
  char *pcVar3;
  PSECURITY_DESCRIPTOR pSecurityDescriptor;
  int in_ECX;
  uint uVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  _FILETIME local_474;
  _FILETIME local_46c;
  DWORD local_464;
  DWORD local_460;
  _FILETIME local_45c;
  undefined4 local_454;
  LPCWSTR local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 local_440;
  undefined4 local_43c;
  undefined4 local_438;
  uint local_434;
  int local_430;
  WCHAR local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x464;
  local_8 = 0x7aa4d7;
  local_454 = param_3;
  Empty();
  local_44c = 0;
  local_448 = 0;
  local_444 = 0;
  local_440 = 0;
  local_43c = 0;
  local_438 = 0;
  if (((param_2 & 0x1000) != 0) && (iVar1 = FUN_007abbe2(param_1,&local_44c,0), iVar1 != 0)) {
    CStringT<>();
    local_8 = 0;
    AfxGetRoot(param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       &local_450);
    puVar5 = (undefined2 *)0x0;
    BVar2 = GetDiskFreeSpaceW(local_450,&local_460,&local_464,&local_46c.dwHighDateTime,
                              &local_474.dwHighDateTime);
    if (BVar2 != 0) {
      puVar5 = (undefined2 *)(local_460 * local_464 * local_46c.dwHighDateTime);
    }
    uVar4 = local_430 << 1 | local_434 >> 0x1f;
    local_45c.dwHighDateTime = local_434 * 2;
    if ((uVar4 <= (uint)((int)puVar5 >> 0x1f)) &&
       ((uVar4 < (uint)((int)puVar5 >> 0x1f) || (local_45c.dwHighDateTime < puVar5)))) {
      GetFullPathNameW(param_1,0x104,local_21c,(LPWSTR *)&local_45c.dwHighDateTime);
      *(undefined2 *)local_45c.dwHighDateTime = 0;
      uVar6 = 0x105;
      pcVar3 = ATL::CSimpleStringT<char,0>::PrepareWrite
                         ((CSimpleStringT<char,0> *)(in_ECX + 0x14),0x105);
      FUN_007a9145(local_21c,&PTR_FUN_0097f838,pcVar3,uVar6);
      ReleaseBuffer(0xffffffff);
    }
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  if ((*(int *)(*(int *)(in_ECX + 0x14) + -0xc) == 0) ||
     (iVar1 = FUN_007a7cf7(*(int *)(in_ECX + 0x14),param_2,local_454), iVar1 == 0)) {
    Empty();
    FUN_007a7cf7(param_1,param_2,local_454);
  }
  else {
    if (param_1 == (wchar_t *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_008f899d(param_1);
    }
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0xc),param_1,iVar1);
    BVar2 = GetFileTime(*(HANDLE *)(in_ECX + 4),&local_474,&local_46c,&local_45c);
    if (BVar2 != 0) {
      FUN_007ab7b4(&local_44c,&local_474);
      SetFileTime(*(HANDLE *)(in_ECX + 4),&local_474,&local_46c,&local_45c);
    }
    local_450 = (LPCWSTR)0x0;
    BVar2 = GetFileSecurityW(param_1,4,(PSECURITY_DESCRIPTOR)0x0,0,(LPDWORD)&local_450);
    if (BVar2 != 0) {
      pSecurityDescriptor = (PSECURITY_DESCRIPTOR)FUN_0078e661(local_450);
      BVar2 = GetFileSecurityW(param_1,4,pSecurityDescriptor,(DWORD)local_450,(LPDWORD)&local_450);
      if (BVar2 != 0) {
        SetFileSecurityW(*(LPCWSTR *)(in_ECX + 0x14),4,pSecurityDescriptor);
      }
      thunk_FUN_008f43b0(pSecurityDescriptor);
    }
  }
  FUN_008d9b68();
  return;
}



