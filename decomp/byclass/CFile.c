/* CFile -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CFile[1] */
/* 007a7229  FUN_007a7229  48 bytes, 0 callers */

void FUN_007a7229(byte param_1)

{
  FUN_007a70db();
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




/* vtable slots: CFile[18] */
/* 007a7259  Abort  31 bytes, 2 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CFile::Abort(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CFile::Abort(CFile *this)

{
  if (*(int *)(this + 4) != -1) {
    CloseHandle(*(HANDLE *)(this + 4));
    *(undefined4 *)(this + 4) = 0xffffffff;
  }
  Empty();
  return;
}




/* vtable slots: CFile[20] */
/* 007a7834  FUN_007a7834  65 bytes, 18 callers */

void FUN_007a7834(void)

{
  undefined4 uVar1;
  BOOL BVar2;
  DWORD DVar3;
  int in_ECX;
  bool bVar4;
  
  bVar4 = false;
  if (*(int *)(in_ECX + 4) != -1) {
    BVar2 = CloseHandle(*(HANDLE *)(in_ECX + 4));
    bVar4 = BVar2 == 0;
  }
  *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  *(undefined4 *)(in_ECX + 8) = 0;
  Empty();
  if (bVar4) {
    uVar1 = *(undefined4 *)(in_ECX + 0xc);
    DVar3 = GetLastError();
    FUN_007a702a(DVar3,uVar1);
  }
  return;
}




/* vtable slots: CFile[10], CMirrorFile[10] */
/* 007a7a3f  FUN_007a7a3f  154 bytes, 0 callers */

int * FUN_007a7a3f(void)

{
  HANDLE hSourceHandle;
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  HANDLE hTargetProcessHandle;
  HANDLE hSourceProcessHandle;
  BOOL BVar5;
  DWORD DVar6;
  int in_ECX;
  HANDLE local_c;
  int local_8;
  
  local_8 = in_ECX;
  iVar3 = FUN_0078e624(0x14);
  if (iVar3 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_007a70b2();
  }
  hTargetProcessHandle = GetCurrentProcess();
  hSourceHandle = *(HANDLE *)(in_ECX + 4);
  hSourceProcessHandle = GetCurrentProcess();
  BVar5 = DuplicateHandle(hSourceProcessHandle,hSourceHandle,hTargetProcessHandle,&local_c,0,0,2);
  if (BVar5 == 0) {
    if (piVar4 != (int *)0x0) {
      pcVar1 = *(code **)(*piVar4 + 4);
      guard_check_icall(1);
      (*pcVar1)();
    }
    uVar2 = *(undefined4 *)(local_8 + 0xc);
    DVar6 = GetLastError();
    FUN_007a702a(DVar6,uVar2);
  }
  piVar4[1] = (int)local_c;
  piVar4[2] = *(int *)(local_8 + 8);
  piVar4[4] = *(int *)(local_8 + 0x10);
  return piVar4;
}




/* vtable slots: CFile[19], CMirrorFile[19] */
/* 007a7ad9  FUN_007a7ad9  40 bytes, 0 callers */

void FUN_007a7ad9(void)

{
  undefined4 uVar1;
  BOOL BVar2;
  DWORD DVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != -1) {
    BVar2 = FlushFileBuffers(*(HANDLE *)(in_ECX + 4));
    if (BVar2 == 0) {
      uVar1 = *(undefined4 *)(in_ECX + 0xc);
      DVar3 = GetLastError();
      FUN_007a702a(DVar3,uVar1);
    }
  }
  return;
}




/* vtable slots: CFile[13], CMirrorFile[13] */
/* 007a7ba6  FUN_007a7ba6  64 bytes, 1 callers */

undefined8 FUN_007a7ba6(void)

{
  undefined4 uVar1;
  DWORD DVar2;
  DWORD DVar3;
  DWORD in_ECX;
  DWORD local_8;
  
  local_8 = in_ECX;
  DVar2 = GetFileSize(*(HANDLE *)(in_ECX + 4),&local_8);
  if ((DVar2 == 0xffffffff) && (DVar3 = GetLastError(), DVar3 != 0)) {
    uVar1 = *(undefined4 *)(in_ECX + 0xc);
    DVar3 = GetLastError();
    FUN_007a702a(DVar3,uVar1);
  }
  return CONCAT44(local_8,DVar2);
}




/* vtable slots: CFile[3], CMirrorFile[3] */
/* 007a7be6  FUN_007a7be6  75 bytes, 0 callers */

undefined8 FUN_007a7be6(void)

{
  undefined4 uVar1;
  DWORD DVar2;
  DWORD DVar3;
  int in_ECX;
  LONG local_8;
  
  local_8 = 0;
  DVar2 = SetFilePointer(*(HANDLE *)(in_ECX + 4),0,&local_8,1);
  if ((DVar2 == 0xffffffff) && (DVar3 = GetLastError(), DVar3 != 0)) {
    uVar1 = *(undefined4 *)(in_ECX + 0xc);
    DVar3 = GetLastError();
    FUN_007a702a(DVar3,uVar1);
  }
  return CONCAT44(local_8,DVar2);
}




/* vtable slots: CFile[0], CMirrorFile[0] */
/* 007a7c31  FUN_007a7c31  6 bytes, 0 callers */

undefined ** FUN_007a7c31(void)

{
  return &PTR_s_CFile_0097f414;
}




/* vtable slots: CFile[16], CMirrorFile[16] */
/* 007a7c37  FUN_007a7c37  52 bytes, 0 callers */

void FUN_007a7c37(DWORD param_1,DWORD param_2,DWORD param_3,DWORD param_4)

{
  undefined4 uVar1;
  BOOL BVar2;
  DWORD DVar3;
  int in_ECX;
  
  BVar2 = LockFile(*(HANDLE *)(in_ECX + 4),param_1,param_2,param_3,param_4);
  if (BVar2 == 0) {
    uVar1 = *(undefined4 *)(in_ECX + 0xc);
    DVar3 = GetLastError();
    FUN_007a702a(DVar3,uVar1);
  }
  return;
}




/* vtable slots: CFile[8], CMemFile[8], CMirrorFile[8], COleStreamFile[8], CSharedFile[8], CStdioFile[8] */
/* 007a7cca  FUN_007a7cca  45 bytes, 0 callers */

void FUN_007a7cca(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  code *pcVar1;
  int *in_ECX;
  
  in_ECX[4] = param_3;
  pcVar1 = *(code **)(*in_ECX + 0x24);
  guard_check_icall(param_1,param_2,param_4);
  (*pcVar1)();
  return;
}




/* vtable slots: CFile[9], CMemFile[9], COleStreamFile[9], CSharedFile[9] */
/* 007a7cf7  FUN_007a7cf7  513 bytes, 20 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007a7cf7(LPCWSTR param_1,uint param_2,int param_3)

{
  CSimpleStringT<wchar_t,0> *this;
  int iVar1;
  uint uVar2;
  DWORD dwFlagsAndAttributes;
  HANDLE pvVar3;
  int in_ECX;
  DWORD dwCreationDisposition;
  DWORD dwShareMode;
  int iVar4;
  _SECURITY_ATTRIBUTES local_228;
  int local_21c;
  int local_218;
  CSimpleStringT<wchar_t,0> *local_214;
  wchar_t local_210 [260];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  iVar4 = 0;
  local_218 = param_3;
  local_214 = (CSimpleStringT<wchar_t,0> *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_21c = in_ECX;
  Empty();
  if ((param_1 == (LPCWSTR)0x0) || (iVar1 = FUN_007a8062(param_1,0x104,0), iVar1 < 0)) {
    if (local_218 == 0) {
      return 0;
    }
    *(undefined4 *)(local_218 + 8) = 3;
    this = (CSimpleStringT<wchar_t,0> *)(local_218 + 0x10);
    if (param_1 != (LPCWSTR)0x0) {
      iVar4 = FUN_008f899d(param_1);
    }
    ATL::CSimpleStringT<wchar_t,0>::SetString(this,param_1,iVar4);
    return 0;
  }
  iVar4 = FUN_007a81b1(local_210,param_1,local_218);
  if (iVar4 == 0) {
    return 0;
  }
  iVar4 = FUN_008f899d(local_210);
  ATL::CSimpleStringT<wchar_t,0>::SetString(local_214,local_210,iVar4);
  local_214 = (CSimpleStringT<wchar_t,0> *)0x0;
  dwCreationDisposition = 3;
  uVar2 = param_2 & 3;
  if (uVar2 == 0) {
    local_214 = (CSimpleStringT<wchar_t,0> *)0x80000000;
  }
  else if (uVar2 == 1) {
    local_214 = (CSimpleStringT<wchar_t,0> *)0x40000000;
  }
  else if (uVar2 == 2) {
    local_214 = (CSimpleStringT<wchar_t,0> *)0xc0000000;
  }
  uVar2 = param_2 & 0x70;
  if ((uVar2 != 0) && (uVar2 != 0x10)) {
    if (uVar2 == 0x20) {
      dwShareMode = 1;
      goto LAB_007a7e00;
    }
    if (uVar2 == 0x30) {
      dwShareMode = 2;
      goto LAB_007a7e00;
    }
    dwShareMode = dwCreationDisposition;
    if (uVar2 == 0x40) goto LAB_007a7e00;
  }
  dwShareMode = 0;
LAB_007a7e00:
  local_228.nLength = 0xc;
  local_228.lpSecurityDescriptor = (LPVOID)0x0;
  local_228.bInheritHandle = ~((param_2 & 0xffff7fff) >> 7) & 1;
  if ((param_2 & 0x1000) != 0) {
    dwCreationDisposition = (-(uint)((param_2 & 0x2000) != 0) & 2) + 2;
  }
  uVar2 = (param_2 & 0x10000) << 0xd;
  dwFlagsAndAttributes = uVar2 | 0x80;
  if ((param_2 & 0x20000) != 0) {
    dwFlagsAndAttributes = uVar2 | 0x80000080;
  }
  if ((param_2 & 0x40000) != 0) {
    dwFlagsAndAttributes = dwFlagsAndAttributes | 0x10000000;
  }
  if ((param_2 & 0x80000) != 0) {
    dwFlagsAndAttributes = dwFlagsAndAttributes | 0x8000000;
  }
  if (*(int *)(local_21c + 0x10) == 0) {
    pvVar3 = CreateFileW(param_1,(DWORD)local_214,dwShareMode,&local_228,dwCreationDisposition,
                         dwFlagsAndAttributes,(HANDLE)0x0);
  }
  else {
    pvVar3 = (HANDLE)FUN_007a78fa(param_1,local_214,dwShareMode,&local_228,dwCreationDisposition,
                                  dwFlagsAndAttributes,0);
  }
  if (pvVar3 == (HANDLE)0xffffffff) {
    FUN_007a816f(local_218,param_1);
    return 0;
  }
  *(HANDLE *)(local_21c + 4) = pvVar3;
  *(undefined4 *)(local_21c + 8) = 1;
  return 1;
}




/* vtable slots: CFile[14], CMirrorFile[14] */
/* 007a7ef8  FUN_007a7ef8  66 bytes, 4 callers */

DWORD FUN_007a7ef8(LPVOID param_1,DWORD param_2)

{
  undefined4 uVar1;
  BOOL BVar2;
  DWORD DVar3;
  DWORD in_ECX;
  DWORD local_8;
  
  if (param_2 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = in_ECX;
    BVar2 = ReadFile(*(HANDLE *)(in_ECX + 4),param_1,param_2,&local_8,(LPOVERLAPPED)0x0);
    if (BVar2 == 0) {
      uVar1 = *(undefined4 *)(in_ECX + 0xc);
      DVar3 = GetLastError();
      FUN_007a702a(DVar3,uVar1);
    }
  }
  return local_8;
}




/* vtable slots: CFile[11], CMirrorFile[11] */
/* 007a7fa1  FUN_007a7fa1  82 bytes, 0 callers */

undefined8 FUN_007a7fa1(LONG param_1,LONG param_2,DWORD param_3)

{
  undefined4 uVar1;
  DWORD DVar2;
  DWORD DVar3;
  int in_ECX;
  LONG local_8;
  
  local_8 = param_2;
  DVar2 = SetFilePointer(*(HANDLE *)(in_ECX + 4),param_1,&local_8,param_3);
  if ((DVar2 == 0xffffffff) && (DVar3 = GetLastError(), DVar3 != 0)) {
    uVar1 = *(undefined4 *)(in_ECX + 0xc);
    DVar3 = GetLastError();
    FUN_007a702a(DVar3,uVar1);
  }
  return CONCAT44(local_8,DVar2);
}




/* vtable slots: CFile[7], CMemFile[7], CMirrorFile[7], COleStreamFile[7], CSharedFile[7], CStdioFile[7] */
/* 007a7ff3  FUN_007a7ff3  43 bytes, 0 callers */

void FUN_007a7ff3(wchar_t *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 != (wchar_t *)0x0) {
    iVar1 = FUN_008f899d(param_1);
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0xc),param_1,iVar1);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CFile[12], CMirrorFile[12], CStdioFile[12] */
/* 007a801f  FUN_007a801f  67 bytes, 0 callers */

void FUN_007a801f(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  DWORD DVar4;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x2c);
  guard_check_icall(param_1,param_2,0);
  (*pcVar1)();
  BVar3 = SetEndOfFile((HANDLE)in_ECX[1]);
  if (BVar3 == 0) {
    iVar2 = in_ECX[3];
    DVar4 = GetLastError();
    FUN_007a702a(DVar4,iVar2);
  }
  return;
}




/* vtable slots: CFile[17], CMirrorFile[17] */
/* 007a80e6  FUN_007a80e6  52 bytes, 0 callers */

void FUN_007a80e6(DWORD param_1,DWORD param_2,DWORD param_3,DWORD param_4)

{
  undefined4 uVar1;
  BOOL BVar2;
  DWORD DVar3;
  int in_ECX;
  
  BVar2 = UnlockFile(*(HANDLE *)(in_ECX + 4),param_1,param_2,param_3,param_4);
  if (BVar2 == 0) {
    uVar1 = *(undefined4 *)(in_ECX + 0xc);
    DVar3 = GetLastError();
    FUN_007a702a(DVar3,uVar1);
  }
  return;
}




/* vtable slots: CFile[15], CMirrorFile[15] */
/* 007a811a  FUN_007a811a  84 bytes, 5 callers */

void FUN_007a811a(LPCVOID param_1,DWORD param_2)

{
  BOOL BVar1;
  DWORD DVar2;
  undefined4 uVar3;
  DWORD in_ECX;
  DWORD local_8;
  
  if (param_2 != 0) {
    local_8 = in_ECX;
    BVar1 = WriteFile(*(HANDLE *)(in_ECX + 4),param_1,param_2,&local_8,(LPOVERLAPPED)0x0);
    if (BVar1 == 0) {
      uVar3 = *(undefined4 *)(in_ECX + 0xc);
      DVar2 = GetLastError();
      FUN_007a702a(DVar2,uVar3);
    }
    if (local_8 != param_2) {
      uVar3 = FUN_00404920();
                    /* WARNING: Subroutine does not return */
      FUN_007a6c8a(0xd,0xffffffff,uVar3);
    }
  }
  return;
}




/* vtable slots: CFile[4], CMemFile[4], CMirrorFile[4], COleStreamFile[4], CSharedFile[4], CStdioFile[4] */
/* 007ab8cc  FUN_007ab8cc  149 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007ab8cc(CSimpleStringT<char,0> *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined1 local_220 [536];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x23c;
  local_8 = 0;
  local_244 = 0;
  local_240 = 0;
  local_23c = 0;
  local_238 = 0;
  local_234 = 0;
  local_230 = 0;
  FUN_007aba64(&local_244);
  CStringT<>();
  local_8 = 0;
  uVar2 = 0x100;
  pcVar1 = ATL::CSimpleStringT<char,0>::PrepareWrite(param_1,0x100);
  FUN_007c60f4(local_220,pcVar1,uVar2);
  ReleaseBuffer(0xffffffff);
  FUN_008d9b68();
  return;
}




/* vtable slots: CFile[6], CMemFile[6], CMirrorFile[6], COleStreamFile[6], CSharedFile[6], CStdioFile[6] */
/* 007ab961  FUN_007ab961  110 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007ab961(undefined4 param_1)

{
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_22c;
  undefined4 local_228;
  undefined4 local_224;
  undefined1 local_214 [524];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_238 = 0;
  local_234 = 0;
  local_230 = 0;
  local_22c = 0;
  local_228 = 0;
  local_224 = 0;
  FUN_007aba64(&local_238);
  CStringT<>(local_214);
  return param_1;
}




/* vtable slots: CFile[5], CMemFile[5], CMirrorFile[5], COleStreamFile[5], CSharedFile[5], CStdioFile[5] */
/* 007ab9cf  FUN_007ab9cf  149 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007ab9cf(CSimpleStringT<char,0> *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined1 local_220 [536];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x23c;
  local_8 = 0;
  local_244 = 0;
  local_240 = 0;
  local_23c = 0;
  local_238 = 0;
  local_234 = 0;
  local_230 = 0;
  FUN_007aba64(&local_244);
  CStringT<>();
  local_8 = 0;
  uVar2 = 0x100;
  pcVar1 = ATL::CSimpleStringT<char,0>::PrepareWrite(param_1,0x100);
  FUN_007a7375(local_220,pcVar1,uVar2);
  ReleaseBuffer(0xffffffff);
  FUN_008d9b68();
  return;
}



