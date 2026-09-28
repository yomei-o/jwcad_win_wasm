/* CFileFind -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFileFind[1] */
/* 007a866f  FUN_007a866f  48 bytes, 0 callers */

void FUN_007a866f(byte param_1)

{
  FUN_007a8621();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CFileFind[18], CSpiFileFind[18] */
/* 007a86ef  FUN_007a86ef  10 bytes, 0 callers */

void FUN_007a86ef(void)

{
  int in_ECX;
  
  FindClose(*(HANDLE *)(in_ECX + 0xc));
  return;
}




/* vtable slots: CFileFind[16], CSpiFileFind[16] */
/* 007a86f9  FUN_007a86f9  328 bytes, 33 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007a86f9(LPCWSTR param_1)

{
  wchar_t *_FullPath;
  int iVar1;
  errno_t eVar2;
  HANDLE pvVar3;
  uint uVar4;
  DWORD dwErrCode;
  wchar_t *pwVar5;
  undefined4 uVar6;
  int in_ECX;
  wchar_t local_210 [256];
  wchar_t *local_10 [2];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_007a869f();
  if (param_1 == (LPCWSTR)0x0) {
    param_1 = L"*.*";
  }
  else {
    uVar4 = FUN_008f899d(param_1);
    if (0x103 < uVar4) {
      dwErrCode = 0xa0;
      goto LAB_007a876a;
    }
  }
  iVar1 = FUN_0078e624(0x250);
  *(int *)(in_ECX + 8) = iVar1;
  eVar2 = _wcscpy_s((wchar_t *)(iVar1 + 0x2c),0x104,param_1);
  FUN_00404bd0(eVar2);
  if (*(int *)(in_ECX + 0x18) == 0) {
    pvVar3 = FindFirstFileW(param_1,*(LPWIN32_FIND_DATAW *)(in_ECX + 8));
  }
  else {
    pvVar3 = (HANDLE)FUN_007a8841(param_1,*(LPWIN32_FIND_DATAW *)(in_ECX + 8));
  }
  *(HANDLE *)(in_ECX + 0xc) = pvVar3;
  if (pvVar3 == (HANDLE)0xffffffff) {
    dwErrCode = GetLastError();
    FUN_007a869f();
  }
  else {
    local_10[0] = (wchar_t *)
                  ATL::CSimpleStringT<char,0>::PrepareWrite
                            ((CSimpleStringT<char,0> *)(in_ECX + 0x10),0x104);
    FUN_00406c20(0x104);
    _FullPath = local_10[0];
    pwVar5 = __wfullpath(local_10[0],param_1,0x104);
    if (pwVar5 != (wchar_t *)0x0) {
      eVar2 = __wsplitpath_s(_FullPath,(wchar_t *)local_10,3,local_210,0x100,(wchar_t *)0x0,0,
                             (wchar_t *)0x0,0);
      FUN_00404bd0(eVar2);
      uVar6 = FUN_00908db3(_FullPath,0x104,local_10,local_210,0,0);
      FUN_00404bd0(uVar6);
      ReleaseBuffer(0xffffffff);
      return 1;
    }
    FUN_00406c20(0);
    FUN_007a869f();
    dwErrCode = 0x7b;
  }
LAB_007a876a:
  SetLastError(dwErrCode);
  return 0;
}




/* vtable slots: CFileFind[17], CSpiFileFind[17] */
/* 007a88a6  FUN_007a88a6  54 bytes, 14 callers */

void FUN_007a88a6(void)

{
  LPWIN32_FIND_DATAW lpFindFileData;
  HANDLE hFindFile;
  int in_ECX;
  
  hFindFile = *(HANDLE *)(in_ECX + 0xc);
  if (hFindFile == (HANDLE)0x0) {
    return;
  }
  lpFindFileData = *(LPWIN32_FIND_DATAW *)(in_ECX + 4);
  if (lpFindFileData == (LPWIN32_FIND_DATAW)0x0) {
    lpFindFileData = (LPWIN32_FIND_DATAW)FUN_0078e624(0x250);
    hFindFile = *(HANDLE *)(in_ECX + 0xc);
  }
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 8);
  *(LPWIN32_FIND_DATAW *)(in_ECX + 8) = lpFindFileData;
  FindNextFileW(hFindFile,lpFindFileData);
  return;
}




/* vtable slots: CFileFind[12], CSpiFileFind[12] */
/* 007a88dc  FUN_007a88dc  76 bytes, 1 callers */

undefined4 FUN_007a88dc(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uVar4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = FUN_007a8c85(*(int *)(in_ECX + 4) + 4);
    if (iVar1 == 0) {
      uVar3 = 0;
      uVar4 = 0;
    }
    else {
      puVar2 = (undefined4 *)FUN_007a84ad(*(int *)(in_ECX + 4) + 4,0xffffffff);
      uVar3 = *puVar2;
      uVar4 = puVar2[1];
    }
    *param_1 = uVar3;
    param_1[1] = uVar4;
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CFileFind[13], CSpiFileFind[13] */
/* 007a8928  FUN_007a8928  39 bytes, 0 callers */

undefined4 FUN_007a8928(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (param_1 == (undefined4 *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 8);
    *param_1 = *(undefined4 *)(iVar1 + 4);
    param_1[1] = uVar2;
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CFileFind[3], CSpiFileFind[3] */
/* 007a894f  FUN_007a894f  79 bytes, 6 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CSimpleStringT<wchar_t,0> * FUN_007a894f(CSimpleStringT<wchar_t,0> *param_1)

{
  int in_ECX;
  wchar_t *pwVar1;
  int iVar2;
  
  iVar2 = 0;
  CStringT<>();
  if (*(int *)(in_ECX + 4) != 0) {
    pwVar1 = (wchar_t *)(*(int *)(in_ECX + 4) + 0x2c);
    if (pwVar1 != (wchar_t *)0x0) {
      iVar2 = FUN_008f899d(pwVar1);
    }
    ATL::CSimpleStringT<wchar_t,0>::SetString(param_1,pwVar1,iVar2);
  }
  return param_1;
}




/* vtable slots: CFileFind[4], CSpiFileFind[4] */
/* 007a899e  FUN_007a899e  162 bytes, 5 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CSimpleStringT<wchar_t,0> * FUN_007a899e(CSimpleStringT<wchar_t,0> *param_1)

{
  uint uVar1;
  uint uVar2;
  short sVar3;
  code *pcVar4;
  int iVar5;
  short *psVar6;
  int *piVar7;
  int *in_ECX;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14 = 0;
  local_8 = 0;
  iVar5 = FUN_004054a0(in_ECX[4] + -0x10);
  uVar1 = iVar5 + 0x10;
  *(uint *)param_1 = uVar1;
  local_8 = 0;
  local_14 = 1;
  uVar2 = uVar1 + *(int *)(iVar5 + 4) * 2;
  psVar6 = (short *)(-(uint)(uVar1 < uVar2) & uVar2 - 2);
  if (psVar6 != (short *)0x0) {
    sVar3 = *psVar6;
    if ((sVar3 != 0x5c) && (sVar3 != 0x2f)) {
      ATL::CSimpleStringT<wchar_t,0>::AppendChar(param_1,*(wchar_t *)(in_ECX + 5));
    }
    pcVar4 = *(code **)(*in_ECX + 0xc);
    guard_check_icall(local_18);
    piVar7 = (int *)(*pcVar4)();
    local_8 = 1;
    FUN_00404cf0(*piVar7,*(undefined4 *)(*piVar7 + -0xc));
    FUN_00406b10();
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CFileFind[5], CSpiFileFind[5] */
/* 007a8a41  FUN_007a8a41  130 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CSimpleStringT<char,0> * FUN_007a8a41(CSimpleStringT<char,0> *param_1)

{
  code *pcVar1;
  wchar_t *_Filename;
  errno_t eVar2;
  int *in_ECX;
  wchar_t *local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0;
  pcVar1 = *(code **)(*in_ECX + 0xc);
  guard_check_icall(local_14);
  (*pcVar1)();
  local_8 = 1;
  CStringT<>();
  _Filename = (wchar_t *)ATL::CSimpleStringT<char,0>::PrepareWrite(param_1,0x100);
  eVar2 = __wsplitpath_s(local_14[0],(wchar_t *)0x0,0,(wchar_t *)0x0,0,_Filename,0x100,
                         (wchar_t *)0x0,0);
  FUN_00404bd0(eVar2);
  ReleaseBuffer(0xffffffff);
  FUN_00406b10();
  return param_1;
}




/* vtable slots: CFileFind[6], CSpiFileFind[6] */
/* 007a8ac3  FUN_007a8ac3  104 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007a8ac3(undefined4 param_1)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  undefined1 local_18 [4];
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_14 = 0;
  local_8 = 0;
  CStringT<>("file://");
  local_8 = 0;
  local_14 = 1;
  pcVar1 = *(code **)(*in_ECX + 0x10);
  guard_check_icall(local_18);
  piVar2 = (int *)(*pcVar1)();
  local_8 = 1;
  FUN_00404cf0(*piVar2,*(undefined4 *)(*piVar2 + -0xc));
  FUN_00406b10();
  return param_1;
}




/* vtable slots: CFileFind[10], CSpiFileFind[10] */
/* 007a8b2b  FUN_007a8b2b  76 bytes, 1 callers */

undefined4 FUN_007a8b2b(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uVar4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = FUN_007a8c85(*(int *)(in_ECX + 4) + 0xc);
    if (iVar1 == 0) {
      uVar3 = 0;
      uVar4 = 0;
    }
    else {
      puVar2 = (undefined4 *)FUN_007a84ad(*(int *)(in_ECX + 4) + 0xc,0xffffffff);
      uVar3 = *puVar2;
      uVar4 = puVar2[1];
    }
    *param_1 = uVar3;
    param_1[1] = uVar4;
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CFileFind[11], CSpiFileFind[11] */
/* 007a8b77  FUN_007a8b77  39 bytes, 0 callers */

undefined4 FUN_007a8b77(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (param_1 == (undefined4 *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
    *param_1 = *(undefined4 *)(iVar1 + 0xc);
    param_1[1] = uVar2;
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CFileFind[8], CSpiFileFind[8] */
/* 007a8b9e  FUN_007a8b9e  76 bytes, 6 callers */

undefined4 FUN_007a8b9e(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 uVar4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = FUN_007a8c85(*(int *)(in_ECX + 4) + 0x14);
    if (iVar1 == 0) {
      uVar3 = 0;
      uVar4 = 0;
    }
    else {
      puVar2 = (undefined4 *)FUN_007a84ad(*(int *)(in_ECX + 4) + 0x14,0xffffffff);
      uVar3 = *puVar2;
      uVar4 = puVar2[1];
    }
    *param_1 = uVar3;
    param_1[1] = uVar4;
    uVar3 = 1;
  }
  return uVar3;
}




/* vtable slots: CFileFind[9], CSpiFileFind[9] */
/* 007a8bea  FUN_007a8bea  39 bytes, 0 callers */

undefined4 FUN_007a8bea(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (param_1 == (undefined4 *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x18);
    *param_1 = *(undefined4 *)(iVar1 + 0x14);
    param_1[1] = uVar2;
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CFileFind[7], CSpiFileFind[7] */
/* 007a8c27  FUN_007a8c27  28 bytes, 1 callers */

void FUN_007a8c27(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004054a0(*(int *)(in_ECX + 0x10) + -0x10);
  *param_1 = iVar1 + 0x10;
  return;
}




/* vtable slots: CFileFind[0], CSpiFileFind[0] */
/* 007a8c43  FUN_007a8c43  6 bytes, 0 callers */

undefined ** FUN_007a8c43(void)

{
  return &PTR_s_CFileFind_0097f5ec;
}




/* vtable slots: CFileFind[15], CSpiFileFind[15] */
/* 007a8c49  IsDots  60 bytes, 2 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CFileFind::IsDots(void)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall CFileFind::IsDots(CFileFind *this)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(this + 4) != 0) {
    iVar1 = FUN_0058f350();
    if (iVar1 != 0) {
      iVar1 = *(int *)(this + 4);
      if ((*(short *)(iVar1 + 0x2c) == 0x2e) &&
         ((*(short *)(iVar1 + 0x2e) == 0 ||
          ((*(short *)(iVar1 + 0x2e) == 0x2e && (*(short *)(iVar1 + 0x30) == 0)))))) {
        iVar2 = 1;
      }
    }
  }
  return iVar2;
}




/* vtable slots: CFileFind[14], CSpiFileFind[14] */
/* 007a8cce  MatchesMask  29 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CFileFind::MatchesMask(unsigned long)const 
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release, Visual Studio 2012 Release,
   Visual Studio 2015 Release */

int __thiscall CFileFind::MatchesMask(CFileFind *this,ulong param_1)

{
  uint uVar1;
  
  if (*(uint **)(this + 4) == (uint *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (uint)((**(uint **)(this + 4) & param_1) != 0);
  }
  return uVar1;
}



