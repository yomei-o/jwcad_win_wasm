/* CStdioFile -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CStdioFile[1] */
/* 007bfb11  FUN_007bfb11  48 bytes, 0 callers */

void FUN_007bfb11(byte param_1)

{
  FUN_007bf9cf();
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




/* vtable slots: CStdioFile[18] */
/* 007bfb41  Abort  42 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CStdioFile::Abort(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CStdioFile::Abort(CStdioFile *this)

{
  if ((*(int *)(this + 0x14) != 0) && (*(int *)(this + 8) != 0)) {
    _fclose(*(FILE **)(this + 0x14));
  }
  *(undefined4 *)(this + 0x14) = 0;
  *(undefined4 *)(this + 8) = 0;
  *(undefined4 *)(this + 4) = 0xffffffff;
  return;
}




/* vtable slots: CStdioFile[20] */
/* 007bfb80  FUN_007bfb80  67 bytes, 2 callers */

void FUN_007bfb80(void)

{
  int iVar1;
  undefined4 uVar2;
  ulong *puVar3;
  int in_ECX;
  
  iVar1 = 0;
  if (*(int *)(in_ECX + 0x14) != 0) {
    iVar1 = _fclose(*(FILE **)(in_ECX + 0x14));
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  if (iVar1 == 0) {
    return;
  }
  uVar2 = FUN_00404920();
  puVar3 = ___doserrno();
                    /* WARNING: Subroutine does not return */
  FUN_007a6c8a(0xd,*puVar3,uVar2);
}




/* vtable slots: CStdioFile[19] */
/* 007bfc45  FUN_007bfc45  49 bytes, 0 callers */

void FUN_007bfc45(void)

{
  int iVar1;
  undefined4 uVar2;
  ulong *puVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) != 0) {
    iVar1 = _fflush(*(FILE **)(in_ECX + 0x14));
    if (iVar1 != 0) {
      uVar2 = FUN_00404920();
      puVar3 = ___doserrno();
                    /* WARNING: Subroutine does not return */
      FUN_007a6c8a(0xd,*puVar3,uVar2);
    }
  }
  return;
}




/* vtable slots: CStdioFile[13] */
/* 007bfc77  FUN_007bfc77  128 bytes, 0 callers */

void FUN_007bfc77(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ulong *puVar4;
  int in_ECX;
  undefined4 uVar5;
  ulong uVar6;
  
  iVar1 = FUN_0090acf5(*(undefined4 *)(in_ECX + 0x14));
  if (iVar1 == -1) {
LAB_007bfcde:
    uVar3 = FUN_00404920();
    puVar4 = ___doserrno();
    uVar6 = *puVar4;
    uVar5 = 6;
  }
  else {
    iVar2 = _fseek(*(FILE **)(in_ECX + 0x14),0,2);
    if (iVar2 == 0) {
      iVar2 = FUN_0090acf5(*(undefined4 *)(in_ECX + 0x14));
      if (iVar2 == -1) goto LAB_007bfcde;
      iVar1 = _fseek(*(FILE **)(in_ECX + 0x14),iVar1,0);
      if (iVar1 == 0) {
        return;
      }
    }
    uVar3 = FUN_00404920();
    puVar4 = ___doserrno();
    uVar6 = *puVar4;
    uVar5 = 9;
  }
                    /* WARNING: Subroutine does not return */
  FUN_007a6c8a(uVar5,uVar6,uVar3);
}




/* vtable slots: CStdioFile[3] */
/* 007bfcf8  FUN_007bfcf8  45 bytes, 0 callers */

void FUN_007bfcf8(void)

{
  int iVar1;
  undefined4 uVar2;
  ulong *puVar3;
  int in_ECX;
  
  iVar1 = FUN_0090acf5(*(undefined4 *)(in_ECX + 0x14));
  if (iVar1 != -1) {
    return;
  }
  uVar2 = FUN_00404920();
  puVar3 = ___doserrno();
                    /* WARNING: Subroutine does not return */
  FUN_007a6c8a(6,*puVar3,uVar2);
}




/* vtable slots: CStdioFile[0] */
/* 007bfd26  FUN_007bfd26  6 bytes, 0 callers */

undefined ** FUN_007bfd26(void)

{
  return &PTR_s_CStdioFile_00982588;
}




/* vtable slots: CStdioFile[9] */
/* 007bfd2c  FUN_007bfd2c  307 bytes, 0 callers */

undefined4 FUN_007bfd2c(int param_1,uint param_2,int param_3)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  ulong *puVar4;
  CFile *in_ECX;
  uint _Flags;
  undefined4 local_8;
  
  if (param_1 == 0) {
    return 0;
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  local_8 = in_ECX;
  iVar2 = FUN_007a7cf7(param_1,param_2 & 0xffffbfff,param_3);
  if (iVar2 == 0) {
    return 0;
  }
  if ((param_2 & 0x1000) == 0) {
    if ((param_2 & 1) != 0) {
      local_8 = (CFile *)CONCAT31(local_8._1_3_,0x61);
      iVar2 = 1;
      goto LAB_007bfdba;
    }
    cVar1 = 'r';
    local_8 = (CFile *)CONCAT31(local_8._1_3_,0x72);
    if ((param_2 & 2) == 0) goto LAB_007bfda8;
  }
  else {
    local_8 = (CFile *)CONCAT31(local_8._1_3_,(((param_2 & 0x2000) == 0) - 1U & 0xea) + 0x77);
    cVar1 = (((param_2 & 0x2000) != 0) - 1U & 0x16) + 0x61;
LAB_007bfda8:
    iVar2 = 1;
    if ((cVar1 == 'r') || ((param_2 & 1) != 0)) goto LAB_007bfdba;
  }
  local_8._0_2_ = CONCAT11(0x2b,(undefined1)local_8);
  iVar2 = 2;
LAB_007bfdba:
  _Flags = (-(uint)((param_2 & 0x8000) != 0) & 0xffffc000) + 0x4000;
  *(byte *)((int)&local_8 + iVar2) = (((param_2 & 0x8000) != 0) - 1U & 0x12) + 0x62;
  if (3 < iVar2 + 1U) {
                    /* WARNING: Subroutine does not return */
    FUN_008d927f();
  }
  *(undefined1 *)((int)&local_8 + iVar2 + 1) = 0;
  if ((param_2 & 0x400) != 0) {
    _Flags = _Flags ^ 0x4000 | 0x10000;
  }
  iVar2 = __open_osfhandle(*(intptr_t *)(in_ECX + 4),_Flags);
  if (iVar2 != -1) {
    uVar3 = FUN_0090a006(iVar2,&local_8);
    *(undefined4 *)(in_ECX + 0x14) = uVar3;
  }
  if (*(int *)(in_ECX + 0x14) == 0) {
    if (param_3 != 0) {
      puVar4 = ___doserrno();
      *(ulong *)(param_3 + 0xc) = *puVar4;
      puVar4 = ___doserrno();
      uVar3 = FUN_007a6d8e(*puVar4);
      *(undefined4 *)(param_3 + 8) = uVar3;
    }
    CFile::Abort(in_ECX);
    return 0;
  }
  return 1;
}




/* vtable slots: CStdioFile[14] */
/* 007bfe60  FUN_007bfe60  123 bytes, 0 callers */

size_t FUN_007bfe60(void *param_1,size_t param_2)

{
  size_t sVar1;
  int iVar2;
  undefined4 uVar3;
  ulong *puVar4;
  int in_ECX;
  
  if (param_2 == 0) {
    return 0;
  }
  if (param_1 != (void *)0x0) {
    sVar1 = _fread(param_1,1,param_2,*(FILE **)(in_ECX + 0x14));
    if ((sVar1 != 0) || (iVar2 = _feof(*(FILE **)(in_ECX + 0x14)), iVar2 != 0)) {
      iVar2 = _ferror(*(FILE **)(in_ECX + 0x14));
      if (iVar2 == 0) {
        return sVar1;
      }
      FUN_007bfb6b(*(undefined4 *)(in_ECX + 0x14));
    }
    uVar3 = FUN_00404920();
    puVar4 = ___doserrno();
                    /* WARNING: Subroutine does not return */
    FUN_007a6c8a(1,*puVar4,uVar3);
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CStdioFile[23] */
/* 007bfedc  FUN_007bfedc  240 bytes, 0 callers */

bool FUN_007bfedc(CSimpleStringT<wchar_t,0> *param_1)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  ulong *puVar4;
  int in_ECX;
  
  iVar1 = FUN_008f899d(&DAT_00956338);
  ATL::CSimpleStringT<wchar_t,0>::SetString(param_1,L"",iVar1);
  pcVar2 = ATL::CSimpleStringT<char,0>::PrepareWrite((CSimpleStringT<char,0> *)param_1,0x80);
  while( true ) {
    iVar1 = FUN_009045cf(pcVar2,0x81,*(undefined4 *)(in_ECX + 0x14));
    ReleaseBuffer(0xffffffff);
    if (iVar1 == 0) break;
    if (pcVar2 == (char *)0x0) goto LAB_007bff75;
    iVar1 = FUN_008f899d(pcVar2);
    if ((iVar1 < 0x80) || (*(short *)(pcVar2 + iVar1 * 2 + -2) == 10)) goto LAB_007bff75;
    iVar1 = *(int *)(*(int *)param_1 + -0xc);
    pcVar2 = ATL::CSimpleStringT<char,0>::PrepareWrite
                       ((CSimpleStringT<char,0> *)param_1,iVar1 + 0x80);
    pcVar2 = pcVar2 + iVar1 * 2;
  }
  iVar1 = _feof(*(FILE **)(in_ECX + 0x14));
  if (iVar1 == 0) {
    FUN_007bfb6b(*(undefined4 *)(in_ECX + 0x14));
    uVar3 = FUN_00404920();
    puVar4 = ___doserrno();
                    /* WARNING: Subroutine does not return */
    FUN_007a6c8a(1,*puVar4,uVar3);
  }
LAB_007bff75:
  pcVar2 = ATL::CSimpleStringT<char,0>::PrepareWrite((CSimpleStringT<char,0> *)param_1,0);
  iVar1 = *(int *)(*(int *)param_1 + -0xc);
  if ((iVar1 != 0) && (*(short *)(pcVar2 + iVar1 * 2 + -2) == 10)) {
    ATL::CSimpleStringT<wchar_t,0>::GetBufferSetLength(param_1,iVar1 + -1);
  }
  return iVar1 != 0;
}




/* vtable slots: CStdioFile[24] */
/* 007bffcd  FUN_007bffcd  96 bytes, 0 callers */

int FUN_007bffcd(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  ulong *puVar4;
  int in_ECX;
  
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  iVar1 = FUN_009045cf(param_1,param_2,*(undefined4 *)(in_ECX + 0x14));
  if (iVar1 == 0) {
    iVar2 = _feof(*(FILE **)(in_ECX + 0x14));
    if (iVar2 == 0) {
      FUN_007bfb6b(*(undefined4 *)(in_ECX + 0x14));
      uVar3 = FUN_00404920();
      puVar4 = ___doserrno();
                    /* WARNING: Subroutine does not return */
      FUN_007a6c8a(1,*puVar4,uVar3);
    }
  }
  return iVar1;
}




/* vtable slots: CStdioFile[11] */
/* 007c002e  FUN_007c002e  114 bytes, 0 callers */

void FUN_007c002e(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  ulong *puVar3;
  int in_ECX;
  ulong uVar4;
  
  if ((((int)param_2 < -1) ||
      (((0x7fffffff < param_2 && (param_1 < 0x80000000)) || (0 < (int)param_2)))) ||
     ((-1 < (int)param_2 && (0x7fffffff < param_1)))) {
    uVar2 = FUN_00404920();
    uVar4 = 0xffffffff;
  }
  else {
    iVar1 = _fseek(*(FILE **)(in_ECX + 0x14),param_1,param_3);
    if (iVar1 == 0) {
      FUN_0090acf5(*(undefined4 *)(in_ECX + 0x14));
      return;
    }
    uVar2 = FUN_00404920();
    puVar3 = ___doserrno();
    uVar4 = *puVar3;
  }
                    /* WARNING: Subroutine does not return */
  FUN_007a6c8a(9,uVar4,uVar2);
}




/* vtable slots: CStdioFile[15] */
/* 007c00a1  FUN_007c00a1  71 bytes, 0 callers */

void FUN_007c00a1(void *param_1,size_t param_2)

{
  size_t sVar1;
  undefined4 uVar2;
  ulong *puVar3;
  int in_ECX;
  
  if (param_1 == (void *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  sVar1 = _fwrite(param_1,1,param_2,*(FILE **)(in_ECX + 0x14));
  if (sVar1 == param_2) {
    return;
  }
  uVar2 = FUN_00404920();
  puVar3 = ___doserrno();
                    /* WARNING: Subroutine does not return */
  FUN_007a6c8a(1,*puVar3,uVar2);
}




/* vtable slots: CStdioFile[22] */
/* 007c00e9  FUN_007c00e9  67 bytes, 0 callers */

void FUN_007c00e9(wchar_t *param_1)

{
  int iVar1;
  undefined4 uVar2;
  ulong *puVar3;
  int in_ECX;
  
  if (param_1 == (wchar_t *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  iVar1 = _fputws(param_1,*(FILE **)(in_ECX + 0x14));
  if (iVar1 != 0xffff) {
    return;
  }
  uVar2 = FUN_00404920();
  puVar3 = ___doserrno();
                    /* WARNING: Subroutine does not return */
  FUN_007a6c8a(0xd,*puVar3,uVar2);
}



