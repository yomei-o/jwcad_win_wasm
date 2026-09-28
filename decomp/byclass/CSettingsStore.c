/* CSettingsStore -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSettingsStore[1] */
/* 00859458  `scalar_deleting_destructor'  48 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CSettingsStore::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CSettingsStore::_scalar_deleting_destructor_(CSettingsStore *this,uint param_1)

{
  ~CSettingsStore(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x20);
    }
  }
  return this;
}




/* vtable slots: CSettingsStore[5] */
/* 00859488  FUN_00859488  8 bytes, 0 callers */

void FUN_00859488(void)

{
  int in_ECX;
  
  ATL::CRegKey::Close((CRegKey *)(in_ECX + 4));
  return;
}




/* vtable slots: CSettingsStore[3] */
/* 00859506  FUN_00859506  76 bytes, 0 callers */

bool FUN_00859506(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  bool bVar3;
  undefined1 local_8 [4];
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    puVar1 = (undefined4 *)FUN_00859630(local_8,param_1);
    iVar2 = FUN_007c0b90(*(undefined4 *)(in_ECX + 4),*puVar1,0,0,0x2001f,0,0);
    bVar3 = iVar2 == 0;
    FUN_00406b10();
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}




/* vtable slots: CSettingsStore[7] */
/* 00859572  FUN_00859572  84 bytes, 0 callers */

bool FUN_00859572(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  bool bVar3;
  undefined1 local_8 [4];
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    ATL::CRegKey::Close((CRegKey *)(in_ECX + 4));
    *(uint *)(in_ECX + 4) = (param_2 != 0) + 0x80000001;
    puVar1 = (undefined4 *)FUN_00859630(local_8,param_1);
    iVar2 = FUN_007d2b8b(*puVar1);
    bVar3 = iVar2 == 0;
    FUN_00406b10();
  }
  else {
    bVar3 = false;
  }
  return bVar3;
}




/* vtable slots: CSettingsStore[6] */
/* 008595c6  FUN_008595c6  24 bytes, 0 callers */

bool FUN_008595c6(LPCWSTR param_1)

{
  LSTATUS LVar1;
  int in_ECX;
  
  LVar1 = RegDeleteValueW(*(HKEY *)(in_ECX + 4),param_1);
  return LVar1 == 0;
}




/* vtable slots: CSettingsStore[0] */
/* 008595de  FUN_008595de  6 bytes, 0 callers */

undefined ** FUN_008595de(void)

{
  return &PTR_s_CSettingsStore_00996438;
}




/* vtable slots: CSettingsStore[4] */
/* 008595e4  FUN_008595e4  76 bytes, 0 callers */

bool FUN_008595e4(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_8 [4];
  
  iVar2 = *(int *)(in_ECX + 0x14);
  puVar1 = (undefined4 *)FUN_00859630(local_8,param_1);
  iVar2 = FUN_007c916e(*(undefined4 *)(in_ECX + 4),*puVar1,
                       (-(uint)(iVar2 != 0) & 0xfff0ffda) + 0xf003f);
  FUN_00406b10();
  return iVar2 == 0;
}




/* vtable slots: CSettingsStore[21] */
/* 00859714  FUN_00859714  36 bytes, 0 callers */

void FUN_00859714(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x50);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CSettingsStore[20] */
/* 00859738  FUN_00859738  26 bytes, 0 callers */

bool FUN_00859738(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_008596db(param_1,param_2);
  return iVar1 == 0;
}




/* vtable slots: CSettingsStore[15] */
/* 00859752  FUN_00859752  175 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00859752(undefined4 param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int *piVar4;
  undefined4 *puVar5;
  undefined1 local_54 [52];
  undefined4 local_20;
  undefined4 local_1c;
  int local_18 [4];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x8c;
  local_8 = 0x859761;
  local_20 = 0;
  local_18[0] = 0;
  pcVar1 = *(code **)(*in_ECX + 0x44);
  puVar5 = &local_1c;
  piVar4 = local_18;
  guard_check_icall(param_1,piVar4,puVar5);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    if (local_18[0] == 0) {
      return;
    }
  }
  else if (local_18[0] != 0) {
    local_8 = 0;
    FUN_007b57de(local_18[0],local_1c,0);
    local_8._0_1_ = 1;
    FUN_007a6256(local_54,1,0x1000,0);
    local_8 = CONCAT31(local_8._1_3_,2);
    uVar3 = FUN_007a5d50(0);
    *param_2 = uVar3;
    FUN_007a6389();
    FUN_007b583b();
    FUN_0085981b(piVar4,puVar5);
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CSettingsStore[19] */
/* 00859834  FUN_00859834  164 bytes, 0 callers */

bool FUN_00859834(int param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  longlong lVar1;
  int iVar2;
  wchar_t *pwVar3;
  int iVar4;
  bool bVar5;
  int local_8;
  
  if (param_1 != 0) {
    Empty();
    iVar4 = 0;
    local_8 = 0;
    iVar2 = FUN_007c947a(param_1,0,&local_8);
    if (iVar2 == 0) {
      if (local_8 == 0) {
        bVar5 = true;
      }
      else {
        lVar1 = (ulonglong)(local_8 + 1) * 2;
        pwVar3 = (wchar_t *)
                 FUN_0078e661(-(uint)((int)((ulonglong)lVar1 >> 0x20) != 0) | (uint)lVar1);
        iVar2 = FUN_007c947a(param_1,pwVar3,&local_8);
        bVar5 = iVar2 == 0;
        if (iVar2 == 0) {
          if (pwVar3 != (wchar_t *)0x0) {
            iVar4 = FUN_008f899d(pwVar3);
          }
          ATL::CSimpleStringT<wchar_t,0>::SetString(param_2,pwVar3,iVar4);
        }
        thunk_FUN_008f43b0(pwVar3);
      }
    }
    else {
      bVar5 = false;
    }
    return bVar5;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CSettingsStore[17] */
/* 00859aa4  FUN_00859aa4  114 bytes, 0 callers */

undefined4 FUN_00859aa4(int param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((param_1 != 0) && (param_2 != (undefined4 *)0x0)) && (param_3 != (int *)0x0)) {
    *param_2 = 0;
    *param_3 = 0;
    iVar1 = FUN_008596ab(param_1,0,param_3);
    if ((iVar1 == 0) && (*param_3 != 0)) {
      uVar2 = FUN_0078e661(*param_3);
      *param_2 = uVar2;
      iVar1 = FUN_008596ab(param_1,uVar2,param_3);
      if (iVar1 == 0) {
        return 1;
      }
      thunk_FUN_008f43b0(*param_2);
      *param_2 = 0;
    }
    return 0;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CSettingsStore[12] */
/* 00859b17  Write  38 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CSettingsStore::Write(wchar_t const *,wchar_t const *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CSettingsStore::Write(CSettingsStore *this,wchar_t *param_1,wchar_t *param_2)

{
  uint uVar1;
  long lVar2;
  
  if (*(int *)(this + 0x14) == 0) {
    lVar2 = ATL::CRegKey::SetStringValue((CRegKey *)(this + 4),param_1,param_2,1);
    uVar1 = (uint)(lVar2 == 0);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CSettingsStore[9] */
/* 00859b3d  FUN_00859b3d  217 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00859b3d(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined8 uVar4;
  int iVar5;
  undefined1 local_9c [76];
  undefined4 local_50;
  undefined1 local_4c [48];
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x8c;
  if (in_ECX[5] == 0) {
    local_1c = 0;
    local_8 = 0;
    FUN_007b57a7(0x400);
    local_8._0_1_ = 1;
    FUN_007a6256(local_4c,0,0x1000,0);
    local_8._0_1_ = 2;
    pcVar1 = *(code **)(*param_2 + 8);
    guard_check_icall(local_9c);
    (*pcVar1)();
    FUN_007a67a4();
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_007a6389();
    uVar4 = FUN_007b5a11();
    local_50 = (undefined4)((ulonglong)uVar4 >> 0x20);
    local_18 = (undefined4)uVar4;
    iVar2 = FUN_007b592a();
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x28);
      iVar5 = iVar2;
      uVar3 = local_18;
      guard_check_icall(param_1,iVar2,local_18);
      (*pcVar1)();
      FUN_008f43b0(iVar2);
      FUN_007b583b();
      uVar3 = FUN_00859c27(iVar5,uVar3);
      return uVar3;
    }
    FUN_007b583b();
  }
  return 0;
}




/* vtable slots: CSettingsStore[11] */
/* 00859c31  FUN_00859c31  203 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_catch replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_00859c31(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined1 local_48 [48];
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x88;
  if (in_ECX[5] == 0) {
    local_8 = 0;
    FUN_007b57a7(0x400);
    local_8._0_1_ = 1;
    FUN_007a6256(local_48,0,0x1000,0);
    local_8._0_1_ = 2;
    FUN_007a6b47(param_2,0x10);
    FUN_007a67a4();
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_007a6389();
    local_18 = FUN_007b5a11();
    iVar2 = FUN_007b592a();
    if (iVar2 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x28);
      guard_check_icall(param_1,iVar2,local_18);
      uVar3 = (*pcVar1)();
      FUN_008f43b0(iVar2);
      FUN_007b583b();
      return uVar3;
    }
    FUN_007b583b();
  }
  return 0;
}




/* vtable slots: CSettingsStore[14] */
/* 00859d0a  FUN_00859d0a  36 bytes, 0 callers */

void FUN_00859d0a(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x34);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CSettingsStore[13] */
/* 00859d2e  FUN_00859d2e  51 bytes, 0 callers */

bool FUN_00859d2e(LPCWSTR param_1,undefined4 param_2)

{
  LSTATUS LVar1;
  int in_ECX;
  bool bVar2;
  undefined4 local_8;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    local_8 = param_2;
    LVar1 = RegSetValueExW(*(HKEY *)(in_ECX + 4),param_1,0,4,(BYTE *)&local_8,4);
    bVar2 = LVar1 == 0;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}




/* vtable slots: CSettingsStore[10] */
/* 00859d61  Write  44 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual int __thiscall CSettingsStore::Write(char const *,unsigned char *,unsigned int)
    public: virtual int __thiscall CSettingsStore::Write(wchar_t const *,unsigned char *,unsigned
   int)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

bool Write(LPCWSTR param_1,BYTE *param_2,DWORD param_3)

{
  LSTATUS LVar1;
  int in_ECX;
  bool bVar2;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    LVar1 = RegSetValueExW(*(HKEY *)(in_ECX + 4),param_1,0,3,param_2,param_3);
    bVar2 = LVar1 == 0;
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}




/* vtable slots: CSettingsStore[8] */
/* 00859d8d  FUN_00859d8d  36 bytes, 0 callers */

void FUN_00859d8d(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x24);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}



