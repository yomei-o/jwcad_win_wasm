/* CDataRecoveryHandler -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CDataRecoveryHandler[12], CMFCBaseTabCtrl[131], CMFCOutlookBarTabCtrl[131], CMFCTabCtrl[131] */
/* 007c23a5  FUN_007c23a5  7 bytes, 0 callers */

undefined4 FUN_007c23a5(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc0);
}




/* vtable slots: CDataRecoveryHandler[10], CMFCBaseTabCtrl[107], CMFCOutlookBarTabCtrl[107], CMFCTabCtrl[107] */
/* 007c2730  FUN_007c2730  7 bytes, 0 callers */

undefined4 FUN_007c2730(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xbc);
}




/* vtable slots: CDataRecoveryHandler[1] */
/* 007c8308  FUN_007c8308  51 bytes, 0 callers */

void FUN_007c8308(byte param_1)

{
  FUN_007c7f07();
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




/* vtable slots: CDataRecoveryHandler[17] */
/* 007c837b  FUN_007c837b  207 bytes, 0 callers */

uint FUN_007c837b(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *in_ECX;
  uint uVar6;
  int local_10;
  int local_c;
  int *local_8;
  
  uVar6 = 1;
  if ((*(byte *)(in_ECX + 0x2d) & 0xc) != 0) {
    iVar3 = FUN_0079dd6d();
    if ((*(int *)(iVar3 + 4) != 0) &&
       (piVar1 = *(int **)(*(int *)(iVar3 + 4) + 0x5c), piVar1 != (int *)0x0)) {
      pcVar2 = *(code **)(*piVar1 + 0x10);
      guard_check_icall();
      local_10 = (*pcVar2)();
      iVar3 = local_c;
      while (local_c = iVar3, local_10 != 0) {
        pcVar2 = *(code **)(*piVar1 + 0x14);
        guard_check_icall(&local_10);
        local_8 = (int *)(*pcVar2)();
        pcVar2 = *(code **)(*local_8 + 0x54);
        guard_check_icall();
        local_c = (*pcVar2)();
        while (iVar3 = 0, local_c != 0) {
          pcVar2 = *(code **)(*local_8 + 0x58);
          guard_check_icall(&local_c);
          uVar4 = (*pcVar2)();
          pcVar2 = *(code **)(*in_ECX + 0x40);
          guard_check_icall(uVar4,0);
          uVar5 = (*pcVar2)();
          uVar6 = uVar6 & uVar5;
        }
      }
    }
  }
  return uVar6;
}




/* vtable slots: CDataRecoveryHandler[16] */
/* 007c844a  FUN_007c844a  583 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007c844a(int *param_1,int param_2)

{
  code *pcVar1;
  CSimpleStringT<wchar_t,0> *pCVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  undefined1 local_20 [4];
  wchar_t *local_1c;
  wchar_t *local_18;
  int local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x7c8456;
  if (((*(byte *)(in_ECX + 0x2d) & 0xc) == 0) || (param_1 == (int *)0x0)) {
    return 0;
  }
  CStringT<>();
  local_8 = 0;
  Lookup(param_1,local_14);
  if (*(int *)(local_14[0] + -0xc) == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x68);
    guard_check_icall(&local_1c,param_1);
    pCVar2 = (CSimpleStringT<wchar_t,0> *)(*pcVar1)();
    local_8._0_1_ = 1;
    ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)local_14,pCVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00406b10();
    pCVar2 = (CSimpleStringT<wchar_t,0> *)FUN_007c8026(param_1);
    ATL::CSimpleStringT<wchar_t,0>::operator=(pCVar2,(CSimpleStringT<wchar_t,0> *)local_14);
    if (*(int *)(local_14[0] + -0xc) == 0) goto LAB_007c8670;
  }
  CStringT<>();
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,3);
  pcVar1 = *(code **)(*param_1 + 0x60);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    iVar3 = Lookup(local_14[0],&local_18);
    pCVar2 = (CSimpleStringT<wchar_t,0> *)FUN_007c80fa(local_14[0]);
    iVar4 = FUN_008f899d(&DAT_00956338);
    ATL::CSimpleStringT<wchar_t,0>::SetString(pCVar2,L"",iVar4);
    if (iVar3 != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x54);
      guard_check_icall(&local_18);
      (*pcVar1)();
    }
  }
  else {
    iVar3 = Lookup(local_14[0],&local_18);
    if (iVar3 == 0) {
      pCVar2 = (CSimpleStringT<wchar_t,0> *)FUN_007c80fa(local_14[0]);
      iVar3 = FUN_008f899d(&DAT_00956338);
      ATL::CSimpleStringT<wchar_t,0>::SetString(pCVar2,L"",iVar3);
    }
    if ((*(byte *)(in_ECX + 0x2d) & 0xc) != 0) {
      pcVar1 = *(code **)(*in_ECX + 0x6c);
      guard_check_icall(local_20,local_14);
      pCVar2 = (CSimpleStringT<wchar_t,0> *)(*pcVar1)();
      local_8._0_1_ = 4;
      ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)&local_1c,pCVar2);
      local_8 = CONCAT31(local_8._1_3_,3);
      FUN_00406b10();
      pcVar1 = *(code **)(*param_1 + 0xe0);
      guard_check_icall(local_1c,0);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        pCVar2 = (CSimpleStringT<wchar_t,0> *)FUN_007c80fa(local_14[0]);
        ATL::CSimpleStringT<wchar_t,0>::operator=(pCVar2,(CSimpleStringT<wchar_t,0> *)&local_1c);
        if (local_1c == (wchar_t *)0x0) {
                    /* WARNING: Subroutine does not return */
          FUN_00404e80(0x80004005);
        }
        iVar3 = __wcsicmp(local_18,local_1c);
        if (iVar3 != 0) {
          pcVar1 = *(code **)(*in_ECX + 0x54);
          guard_check_icall(&local_18);
          (*pcVar1)();
        }
        iVar3 = *param_1;
        guard_check_icall(param_2 != 0);
        (**(code **)(iVar3 + 100))();
      }
    }
  }
  FUN_00406b10();
  FUN_00406b10();
LAB_007c8670:
  FUN_00406b10();
  return 1;
}




/* vtable slots: CDataRecoveryHandler[18] */
/* 007c8692  FUN_007c8692  299 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007c8692(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  CSimpleStringT<wchar_t,0> *pCVar3;
  int *in_ECX;
  undefined1 local_18 [4];
  undefined4 local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7c869e;
  if (((*(byte *)(in_ECX + 0x2d) & 0x10) != 0) && (in_ECX[0x31] == 0)) {
    CStringT<>();
    local_8 = 0;
    iVar2 = Lookup(param_1,local_14);
    if (iVar2 != 0) {
      FUN_007c98c3(param_1);
      FUN_007c98c3(param_1);
      FUN_007c992b(local_14[0]);
      CStringT<>();
      local_8._0_1_ = 1;
      Lookup(local_14[0],local_18);
      pcVar1 = *(code **)(*in_ECX + 0x54);
      guard_check_icall(local_18);
      (*pcVar1)();
      FUN_007c9993(local_14[0]);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00406b10();
    }
    pcVar1 = *(code **)(*in_ECX + 0x68);
    guard_check_icall(local_18,param_1);
    pCVar3 = (CSimpleStringT<wchar_t,0> *)(*pcVar1)();
    local_8._0_1_ = 2;
    ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)local_14,pCVar3);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00406b10();
    pCVar3 = (CSimpleStringT<wchar_t,0> *)FUN_007c8026(param_1);
    ATL::CSimpleStringT<wchar_t,0>::operator=(pCVar3,(CSimpleStringT<wchar_t,0> *)local_14);
    pCVar3 = (CSimpleStringT<wchar_t,0> *)FUN_007c80fa(local_14[0]);
    iVar2 = FUN_008f899d(&DAT_00956338);
    ATL::CSimpleStringT<wchar_t,0>::SetString(pCVar3,L"",iVar2);
    FUN_00406b10();
  }
  return 1;
}




/* vtable slots: CDataRecoveryHandler[22] */
/* 007c87bd  FUN_007c87bd  192 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007c87bd(void)

{
  code *pcVar1;
  CSimpleStringT<wchar_t,0> *this;
  int iVar2;
  int *in_ECX;
  int local_1c;
  undefined4 local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x7c87c9;
  local_1c = -(uint)(in_ECX[4] != 0);
  iVar2 = in_ECX[4];
  while (iVar2 != 0) {
    CStringT<>();
    local_8 = 0;
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,1);
    FUN_007c8ce0(&local_1c,&local_18,local_14);
    if (*(int *)(local_14[0] + -0xc) != 0) {
      this = (CSimpleStringT<wchar_t,0> *)FUN_007c80fa(local_18);
      iVar2 = FUN_008f899d(&DAT_00956338);
      ATL::CSimpleStringT<wchar_t,0>::SetString(this,L"",iVar2);
      pcVar1 = *(code **)(*in_ECX + 0x54);
      guard_check_icall(local_14);
      (*pcVar1)();
    }
    FUN_00406b10();
    local_8 = 0xffffffff;
    FUN_00406b10();
    iVar2 = local_1c;
  }
  return 1;
}




/* vtable slots: CDataRecoveryHandler[21] */
/* 007c887d  DeleteAutosavedFile  50 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual int __thiscall CDataRecoveryHandler::DeleteAutosavedFile(class
   ATL::CStringT<char,class StrTraitMFC<char,class ATL::ChTraitsCRT<char> > > const &)
    public: virtual int __thiscall CDataRecoveryHandler::DeleteAutosavedFile(class
   ATL::CStringT<wchar_t,class StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > const &)
   
   Library: Visual Studio 2015 Release */

undefined4 DeleteAutosavedFile(undefined4 *param_1)

{
  BOOL BVar1;
  
  if (*(int *)((LPCWSTR)*param_1 + -6) != 0) {
    BVar1 = DeleteFileW((LPCWSTR)*param_1);
    if (BVar1 == 0) {
      AddTail(param_1);
    }
  }
  return 1;
}




/* vtable slots: CDataRecoveryHandler[27] */
/* 007c89f4  FUN_007c89f4  347 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007c89f4(CSimpleStringT<wchar_t,0> *param_1,
                 CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *param_2)

{
  code *pcVar1;
  CSimpleStringT<wchar_t,0> *pCVar2;
  undefined4 uVar3;
  int local_34 [3];
  int *local_28;
  GUID local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0;
  local_34[1] = 0;
  FUN_008f17a2(*(undefined4 *)param_2,0x5c);
  ATL::CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>::Right
            (param_2,(int)local_34);
  local_8 = 1;
  local_24.Data1 = 0;
  local_24.Data2 = 0;
  local_24.Data3 = 0;
  local_24.Data4[0] = '\0';
  local_24.Data4[1] = '\0';
  local_24.Data4[2] = '\0';
  local_24.Data4[3] = '\0';
  local_24.Data4[4] = '\0';
  local_24.Data4[5] = '\0';
  local_24.Data4[6] = '\0';
  local_24.Data4[7] = '\0';
  CoCreateGuid(&local_24);
  CStringT<>();
  local_8._0_1_ = 2;
  FUN_004059f0(local_34 + 2,L"%08lX%04X%04x%02X%02X%02X%02X%02X%02X%02X%02X",local_24.Data1,
               local_24._4_4_ & 0xffff,(uint)local_24._4_4_ >> 0x10,local_24.Data4._0_4_ & 0xff,
               (uint)local_24.Data4._0_4_ >> 8 & 0xff,(uint)local_24.Data4._0_4_ >> 0x10 & 0xff,
               (uint)local_24.Data4._0_4_ >> 0x18,local_24.Data4._4_4_ & 0xff,
               (uint)local_24.Data4._4_4_ >> 8 & 0xff,(uint)local_24.Data4._4_4_ >> 0x10 & 0xff,
               (uint)local_24.Data4._4_4_ >> 0x18);
  CStringT<>();
  local_34[1] = 1;
  pcVar1 = *(code **)(*local_28 + 0x18);
  guard_check_icall(&local_28);
  pCVar2 = (CSimpleStringT<wchar_t,0> *)(*pcVar1)();
  local_8._0_1_ = 3;
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_1,pCVar2);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_00406b10();
  uVar3 = FUN_008f899d(&DAT_0095c474);
  FUN_00404cf0(&DAT_0095c474,uVar3);
  FUN_00404cf0(local_34[2],*(undefined4 *)(local_34[2] + -0xc));
  uVar3 = FUN_008f899d(&DAT_0095bcc4);
  FUN_00404cf0(&DAT_0095bcc4,uVar3);
  FUN_00404cf0(local_34[0],*(undefined4 *)(local_34[0] + -0xc));
  FUN_00406b10();
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CDataRecoveryHandler[6] */
/* 007c8bf3  FUN_007c8bf3  31 bytes, 0 callers */

void FUN_007c8bf3(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004054a0(*(int *)(in_ECX + 0xac) + -0x10);
  *param_1 = iVar1 + 0x10;
  return;
}




/* vtable slots: CDataRecoveryHandler[26] */
/* 007c8c12  FUN_007c8c12  206 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

CSimpleStringT<wchar_t,0> * FUN_007c8c12(CSimpleStringT<wchar_t,0> *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_20 [4];
  undefined4 local_1c;
  undefined4 local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_18 = 0;
  local_8 = 0;
  iVar2 = FUN_004054a0(*(int *)(param_2 + 0x24) + -0x10);
  *(int *)param_1 = iVar2 + 0x10;
  local_8 = 0;
  local_18 = 1;
  if (*(int *)(iVar2 + 4) == 0) {
    ATL::CSimpleStringT<wchar_t,0>::operator=(param_1,(CSimpleStringT<wchar_t,0> *)(param_2 + 0x20))
    ;
    CStringT<>();
    local_8 = 1;
    if (*(int **)(param_2 + 0x28) != (int *)0x0) {
      pcVar1 = *(code **)(**(int **)(param_2 + 0x28) + 100);
      guard_check_icall(local_14,4);
      iVar2 = (*pcVar1)();
      if ((iVar2 != 0) && (*(int *)(local_14[0] + -0xc) != 0)) {
        local_1c = 0;
        piVar3 = (int *)FUN_007ab24a(local_20,&DAT_0097f7a8,&local_1c);
        local_8 = CONCAT31(local_8._1_3_,2);
        FUN_00404cf0(*piVar3,*(undefined4 *)(*piVar3 + -0xc));
        FUN_00406b10();
      }
    }
    FUN_00406b10();
  }
  return param_1;
}




/* vtable slots: CDataRecoveryHandler[29] */
/* 007c8d6b  FUN_007c8d6b  62 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007c8d6b(undefined4 param_1,undefined4 param_2)

{
  CStringT<>();
  Lookup(param_2,param_1);
  return param_1;
}




/* vtable slots: CDataRecoveryHandler[28] */
/* 007c8da9  FUN_007c8da9  93 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007c8da9(undefined4 param_1,undefined4 *param_2)

{
  UINT in_stack_ffffffd8;
  LPSTR in_stack_ffffffdc;
  int in_stack_ffffffe0;
  undefined4 local_14;
  
  CStringT<>();
  CStringT<>();
  FID_conflict_LoadStringA((HINSTANCE)0xf2ea,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0);
  FUN_004059f0(param_1,local_14,*param_2);
  FUN_00406b10();
  return param_1;
}




/* vtable slots: CDataRecoveryHandler[8] */
/* 007c8e06  FUN_007c8e06  31 bytes, 0 callers */

void FUN_007c8e06(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_004054a0(*(int *)(in_ECX + 0xb0) + -0x10);
  *param_1 = iVar1 + 0x10;
  return;
}




/* vtable slots: CDataRecoveryHandler[3] */
/* 007c8e88  FUN_007c8e88  185 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007c8e88(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  UINT uElapse;
  UINT_PTR UVar4;
  int *in_ECX;
  undefined1 local_18 [4];
  LPVOID local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7c8e94;
  uVar3 = in_ECX[0x2d];
  if ((uVar3 & 0xc) != 0) {
    local_14[0] = (LPVOID)0x0;
    iVar2 = FUN_007c4e78(&DAT_009a9aec,0,0,local_14);
    if (iVar2 != 0) {
      return 0;
    }
    if (local_14[0] == (LPVOID)0x0) {
      return 0;
    }
    pcVar1 = *(code **)(*in_ECX + 0x1c);
    CStringT<>(local_14[0]);
    local_8 = 0;
    guard_check_icall(local_18);
    (*pcVar1)();
    local_8 = 0xffffffff;
    FUN_00406b10();
    CoTaskMemFree(local_14[0]);
    uVar3 = in_ECX[0x2d];
  }
  if ((uVar3 & 8) != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x10);
    guard_check_icall();
    uElapse = (*pcVar1)();
    UVar4 = SetTimer((HWND)0x0,in_ECX[0x32],uElapse,(TIMERPROC)&LAB_007c833b);
    in_ECX[0x32] = UVar4;
  }
  return 1;
}




/* vtable slots: CDataRecoveryHandler[24] */
/* 007c91f2  FUN_007c91f2  648 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007c91f2(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  UINT in_stack_ffffffc8;
  LPSTR in_stack_ffffffcc;
  int in_stack_ffffffd0;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x7c91fe;
  iVar1 = _AfxIsTaskDialogSupported();
  if (iVar1 == 0) {
    CStringT<>();
    local_8 = 5;
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,6);
    FID_conflict_LoadStringA
              ((HINSTANCE)0xf2e4,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0);
    uVar2 = FUN_008f899d(&DAT_009663a0);
    FUN_00404cf0(&DAT_009663a0,uVar2);
    FID_conflict_LoadStringA
              ((HINSTANCE)0xf2e5,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0);
    FUN_00404cf0(local_18,*(undefined4 *)(local_18 + -0xc));
    uVar2 = FUN_008f899d(L"\r\n\r\n");
    FUN_00404cf0(L"\r\n\r\n",uVar2);
    FID_conflict_LoadStringA
              ((HINSTANCE)0xf2e6,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0);
    FUN_00404cf0(local_18,*(undefined4 *)(local_18 + -0xc));
    uVar2 = FUN_008f899d(L"\r\n\r\n");
    FUN_00404cf0(L"\r\n\r\n",uVar2);
    FID_conflict_LoadStringA
              ((HINSTANCE)0xf2e7,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0);
    FUN_00404cf0(local_18,*(undefined4 *)(local_18 + -0xc));
    local_28 = FUN_0079f557(local_14[0],4,0);
    FUN_00406b10();
  }
  else {
    CStringT<>();
    local_8 = 0;
    FID_conflict_LoadStringA
              ((HINSTANCE)0xf2e4,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0);
    CStringT<>();
    local_8._0_1_ = 1;
    FID_conflict_LoadStringA
              ((HINSTANCE)0xf2e5,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0);
    uVar2 = FUN_008f899d(&DAT_009663a0);
    FUN_00404cf0(&DAT_009663a0,uVar2);
    FUN_00404cf0(local_20,*(undefined4 *)(local_20 + -0xc));
    CStringT<>();
    local_8._0_1_ = 2;
    FID_conflict_LoadStringA
              ((HINSTANCE)0xf2e6,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0);
    CStringT<>();
    local_8._0_1_ = 3;
    FID_conflict_LoadStringA
              ((HINSTANCE)0xf2e7,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0);
    iVar1 = FUN_0079dd6d();
    CStringT<>(*(undefined4 *)(*(int *)(iVar1 + 4) + 0x50));
    local_8 = CONCAT31(local_8._1_3_,4);
    iVar1 = CTaskDialog::ShowDialog
                      ((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       &local_1c,
                       (CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       &local_18,
                       (CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       &local_24,0xf2e8,0xf2e9,0,0x10,
                       (CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       local_14);
    FUN_00406b10();
    local_28 = (iVar1 != 0xf2e8) + 6;
    FUN_00406b10();
    FUN_00406b10();
    FUN_00406b10();
  }
  local_8 = 0xffffffff;
  FUN_00406b10();
  local_1c = -(uint)(*(int *)(in_ECX + 0x10) != 0);
  iVar1 = *(int *)(in_ECX + 0x10);
  while (iVar1 != 0) {
    CStringT<>();
    local_8 = 7;
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,8);
    FUN_007c8ce0(&local_1c,&local_20,&local_24);
    if (*(int *)(local_24 + -0xc) != 0) {
      uVar2 = FUN_007c8090(local_20);
      *(bool *)uVar2 = local_28 == 6;
    }
    FUN_00406b10();
    local_8 = 0xffffffff;
    FUN_00406b10();
    iVar1 = local_1c;
  }
  return;
}




/* vtable slots: CDataRecoveryHandler[15] */
/* 007c94ea  FUN_007c94ea  519 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007c94ea(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  CSimpleStringT<wchar_t,0> *this;
  LSTATUS LVar5;
  int *in_ECX;
  DWORD dwIndex;
  HKEY pHVar6;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  HKEY local_440;
  HKEY local_43c;
  undefined4 local_438;
  undefined4 local_434;
  int *local_430;
  undefined4 local_42c;
  DWORD local_428;
  wchar_t local_424 [260];
  WCHAR local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x43c;
  local_8 = 0x7c94f9;
  local_434 = 0;
  local_430 = in_ECX;
  FUN_0079dd6d();
  uVar2 = FUN_007a3485(0);
  local_448 = 0;
  local_444 = 0;
  local_440 = (HKEY)0x0;
  local_43c = (HKEY)0x0;
  local_438 = 0;
  local_8 = 1;
  pcVar1 = *(code **)(*in_ECX + 0x20);
  local_44c = uVar2;
  guard_check_icall(&local_428);
  puVar3 = (undefined4 *)(*pcVar1)();
  iVar4 = FUN_007c916e(uVar2,*puVar3,0x2001f);
  FUN_00406b10();
  pHVar6 = local_440;
  if (iVar4 == 0) {
    _memset(local_21c,0,0x208);
    pHVar6 = local_440;
    local_428 = 0x104;
    dwIndex = 0;
    while( true ) {
      LVar5 = RegEnumValueW(pHVar6,dwIndex,local_21c,&local_428,(LPDWORD)0x0,(LPDWORD)0x0,
                            (LPBYTE)0x0,(LPDWORD)0x0);
      if (LVar5 != 0) break;
      local_428 = 0x104;
      dwIndex = dwIndex + 1;
      _memset(local_424,0,0x208);
      local_42c = 0x104;
      iVar4 = FUN_007c947a(local_21c,local_424,&local_42c);
      if (iVar4 == 0) {
        this = (CSimpleStringT<wchar_t,0> *)FUN_007c80fa(local_21c);
        iVar4 = FUN_008f899d(local_424);
        ATL::CSimpleStringT<wchar_t,0>::SetString(this,local_424,iVar4);
        local_434 = 1;
      }
    }
    if (pHVar6 != (HKEY)0x0) {
      RegCloseKey(pHVar6);
      local_440 = (HKEY)0x0;
    }
    pcVar1 = *(code **)(*local_430 + 0x20);
    local_43c = (HKEY)0x0;
    guard_check_icall(&local_42c);
    puVar3 = (undefined4 *)(*pcVar1)();
    FUN_007c88af(*puVar3);
    FUN_00406b10();
    pHVar6 = (HKEY)0x0;
  }
  if (pHVar6 != (HKEY)0x0) {
    RegCloseKey(pHVar6);
  }
  ATL::CRegKey::Close((CRegKey *)&local_44c);
  FUN_008d9b68();
  return;
}




/* vtable slots: CDataRecoveryHandler[20] */
/* 007c9806  FUN_007c9806  189 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007c9806(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  undefined4 local_18;
  undefined1 local_14 [12];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x7c9812;
  if ((*(byte *)(in_ECX + 0x2d) & 0x10) != 0) {
    CStringT<>();
    local_8 = 0;
    iVar2 = Lookup(param_1,&local_18);
    if (iVar2 != 0) {
      CStringT<>();
      local_8._0_1_ = 1;
      Lookup(local_18,local_14);
      pcVar1 = *(code **)(*in_ECX + 0x54);
      guard_check_icall(local_14);
      (*pcVar1)();
      FUN_007c9993(local_18);
      FUN_007c992b(local_18);
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_00406b10();
    }
    FUN_007c98c3(param_1);
    FUN_007c98c3(param_1);
    FUN_00406b10();
  }
  return 1;
}




/* vtable slots: CDataRecoveryHandler[23] */
/* 007c99fb  FUN_007c99fb  485 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

uint FUN_007c99fb(void)

{
  code *pcVar1;
  wchar_t *pwVar2;
  wchar_t *pwVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  CSimpleStringT<wchar_t,0> *pCVar7;
  undefined4 *puVar8;
  int in_ECX;
  undefined1 local_30 [4];
  int local_2c;
  undefined1 local_28 [4];
  int local_24;
  uint local_20;
  wchar_t *local_1c;
  int *local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x7c9a07;
  local_20 = 0;
  FUN_007c974f();
  *(undefined4 *)(in_ECX + 0xc4) = 1;
  if (((*(byte *)(in_ECX + 0xb4) & 0x10) != 0) &&
     (local_2c = -(uint)(*(int *)(in_ECX + 0x10) != 0), *(int *)(in_ECX + 0x10) != 0)) {
    local_14 = in_ECX + 4;
    do {
      local_18 = (int *)0x0;
      CStringT<>();
      local_8 = 0;
      CStringT<>();
      local_8._0_1_ = 1;
      FUN_007c8ce0(&local_2c,&local_1c,local_28);
      pwVar2 = local_1c;
      pwVar3 = _wcspbrk(local_1c,L":/\\");
      if ((pwVar3 == (wchar_t *)0x0) || ((int)pwVar3 - (int)pwVar2 >> 1 == -1)) {
        iVar4 = FUN_0079dd6d();
        if ((*(int *)(iVar4 + 4) != 0) &&
           (piVar5 = *(int **)(*(int *)(iVar4 + 4) + 0x5c), piVar5 != (int *)0x0)) {
          pcVar1 = *(code **)(*piVar5 + 0x30);
          guard_check_icall(pwVar2);
          piVar5 = (int *)(*pcVar1)();
          if (piVar5 != (int *)0x0) {
            pcVar1 = *(code **)(*piVar5 + 0x80);
            guard_check_icall(0,0,1);
            local_18 = (int *)(*pcVar1)();
            if (local_18 != (int *)0x0) {
              iVar4 = FUN_004054a0(pwVar2 + -8);
              iVar4 = iVar4 + 0x10;
              local_8._0_1_ = 2;
              local_24 = iVar4;
              iVar6 = FUN_008f17a2(pwVar2,0x2e);
              if ((iVar6 != 0) && (iVar6 = iVar6 - (int)pwVar2 >> 1, 0 < iVar6)) {
                pCVar7 = (CSimpleStringT<wchar_t,0> *)Left(local_30,iVar6);
                local_8._0_1_ = 3;
                ATL::CSimpleStringT<wchar_t,0>::operator=
                          ((CSimpleStringT<wchar_t,0> *)&local_24,pCVar7);
                local_8._0_1_ = 2;
                FUN_00406b10();
                iVar4 = local_24;
              }
              pcVar1 = *(code **)(*local_18 + 0x54);
              guard_check_icall(iVar4);
              (*pcVar1)();
              local_8._0_1_ = 1;
              FUN_00406b10();
            }
          }
        }
      }
      else {
        iVar4 = FUN_0079dd6d();
        pcVar1 = *(code **)(**(int **)(iVar4 + 4) + 0xa0);
        guard_check_icall(pwVar2,1);
        local_18 = (int *)(*pcVar1)();
      }
      puVar8 = (undefined4 *)FUN_007c8090(pwVar2);
      *puVar8 = local_18;
      local_20 = local_20 | local_18 != (int *)0x0;
      FUN_00406b10();
      local_8 = 0xffffffff;
      FUN_00406b10();
    } while (local_2c != 0);
  }
  *(undefined4 *)(in_ECX + 0xc4) = 0;
  return local_20;
}




/* vtable slots: CDataRecoveryHandler[25] */
/* 007c9be0  FUN_007c9be0  1447 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007c9be0(void)

{
  code *pcVar1;
  wchar_t *_Str;
  int iVar2;
  int *piVar3;
  wchar_t *pwVar4;
  CSimpleStringT<wchar_t,0> *pCVar5;
  int iVar6;
  int *in_ECX;
  undefined4 uVar7;
  undefined1 local_270 [4];
  undefined4 local_26c;
  int *local_268;
  int *local_264;
  int local_260;
  int local_25c;
  int *local_258;
  undefined4 local_254;
  int *local_250;
  char local_249;
  wchar_t *local_248;
  undefined4 local_244;
  undefined4 local_240;
  undefined4 local_23c;
  undefined4 local_238;
  undefined4 local_234;
  undefined4 local_230;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x264;
  local_8 = 0x7c9bef;
  local_268 = in_ECX;
  FUN_007c974f();
  in_ECX[0x31] = 1;
  if (((byte)in_ECX[0x2d] & 0x30) == 0x30) {
    local_244 = 0;
    local_240 = 0;
    local_260 = -(uint)(in_ECX[4] != 0);
    local_23c = 0;
    local_238 = 0;
    local_234 = 0;
    local_230 = 0;
    iVar2 = in_ECX[4];
    while (iVar2 != 0) {
      CStringT<>();
      local_8 = 0;
      CStringT<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_007c8ce0(&local_260,&local_248,&local_258);
      local_264 = local_258 + -4;
      if ((local_258[-3] != 0) && (iVar2 = FUN_007abbe2(local_258,&local_244,0), iVar2 != 0)) {
        FUN_00406b10();
        local_8 = 0xffffffff;
        FUN_00406b10();
        pcVar1 = *(code **)(*in_ECX + 0x60);
        guard_check_icall();
        (*pcVar1)();
        local_260 = -(uint)(in_ECX[4] != 0);
        iVar2 = in_ECX[4];
        while (iVar2 != 0) {
          CStringT<>();
          local_8 = 2;
          CStringT<>();
          local_8._0_1_ = 3;
          FUN_007c8ce0(&local_260,&local_248,&local_25c);
          _Str = local_248;
          if ((*(int *)(local_25c + -0xc) != 0) &&
             (iVar2 = FUN_007abbe2(local_25c,&local_244,0), iVar2 != 0)) {
            Lookup(_Str,&local_249);
            if (local_249 == '\0') {
              pCVar5 = (CSimpleStringT<wchar_t,0> *)FUN_007c80fa(_Str);
              iVar2 = FUN_008f899d(&DAT_00956338);
              ATL::CSimpleStringT<wchar_t,0>::SetString(pCVar5,L"",iVar2);
              pcVar1 = *(code **)(*in_ECX + 0x54);
              guard_check_icall(&local_25c);
              (*pcVar1)();
            }
            else {
              iVar2 = FUN_0079dd6d();
              pcVar1 = *(code **)(**(int **)(iVar2 + 4) + 0x74);
              guard_check_icall();
              iVar2 = (*pcVar1)();
              SendMessageW(*(HWND *)(iVar2 + 0x20),0xb,0,0);
              iVar2 = FUN_0079dd6d();
              uVar7 = 0;
              pcVar1 = *(code **)(**(int **)(iVar2 + 4) + 0xa0);
              iVar2 = local_25c;
              guard_check_icall(local_25c,0);
              piVar3 = (int *)(*pcVar1)();
              local_250 = piVar3;
              if (piVar3 == (int *)0x0) {
                iVar6 = FUN_0079dd6d();
                pcVar1 = *(code **)(**(int **)(iVar6 + 4) + 0x74);
                guard_check_icall(iVar2,uVar7);
                iVar2 = (*pcVar1)();
                SendMessageW(*(HWND *)(iVar2 + 0x20),0xb,1,0);
                iVar2 = FUN_0079dd6d();
                pcVar1 = *(code **)(**(int **)(iVar2 + 4) + 0x74);
                guard_check_icall();
                iVar2 = (*pcVar1)();
                InvalidateRect(*(HWND *)(iVar2 + 0x20),(RECT *)0x0,1);
                iVar2 = FUN_0079dd6d();
                pcVar1 = *(code **)(**(int **)(iVar2 + 4) + 0x74);
                guard_check_icall();
                iVar2 = (*pcVar1)();
                UpdateWindow(*(HWND *)(iVar2 + 0x20));
                in_ECX = local_268;
              }
              else {
                CStringT<>();
                local_8._0_1_ = 4;
                pwVar4 = _wcspbrk(_Str,L":/\\");
                iVar6 = *piVar3;
                if ((pwVar4 == (wchar_t *)0x0) ||
                   (((int)pwVar4 - (int)_Str & 0xfffffffeU) == 0xfffffffe)) {
                  guard_check_icall(iVar2,uVar7);
                  (**(code **)(iVar6 + 0x5c))();
                  ATL::CSimpleStringT<wchar_t,0>::operator=
                            ((CSimpleStringT<wchar_t,0> *)&local_254,
                             (CSimpleStringT<wchar_t,0> *)&local_248);
                  iVar2 = FUN_008f17a2(_Str,0x2e);
                  if ((iVar2 != 0) && (iVar2 = iVar2 - (int)_Str >> 1, 0 < iVar2)) {
                    pCVar5 = (CSimpleStringT<wchar_t,0> *)Left(local_270,iVar2);
                    local_8._0_1_ = 5;
                    ATL::CSimpleStringT<wchar_t,0>::operator=
                              ((CSimpleStringT<wchar_t,0> *)&local_254,pCVar5);
                    local_8._0_1_ = 4;
                    FUN_00406b10();
                  }
                  pcVar1 = *(code **)(*piVar3 + 0x54);
                  guard_check_icall(local_254);
                  (*pcVar1)();
                }
                else {
                  guard_check_icall(_Str,0);
                  (**(code **)(iVar6 + 0x58))();
                  ATL::CSimpleStringT<wchar_t,0>::operator=
                            ((CSimpleStringT<wchar_t,0> *)&local_254,
                             (CSimpleStringT<wchar_t,0> *)(piVar3 + 8));
                }
                pcVar1 = *(code **)(*local_268 + 0x68);
                guard_check_icall(&local_264,local_250);
                (*pcVar1)();
                local_8 = CONCAT31(local_8._1_3_,6);
                pCVar5 = (CSimpleStringT<wchar_t,0> *)FUN_007c8026(local_250);
                ATL::CSimpleStringT<wchar_t,0>::operator=
                          (pCVar5,(CSimpleStringT<wchar_t,0> *)&local_264);
                local_258 = (int *)0x0;
                Lookup(_Str,&local_258);
                piVar3 = local_250;
                if ((local_258 != (int *)0x0) && (local_258 != local_250)) {
                  pcVar1 = *(code **)(*local_258 + 0x84);
                  guard_check_icall();
                  (*pcVar1)();
                }
                pcVar1 = *(code **)(*piVar3 + 100);
                guard_check_icall(1);
                (*pcVar1)();
                iVar2 = FUN_0079dd6d();
                pcVar1 = *(code **)(**(int **)(iVar2 + 4) + 0x74);
                guard_check_icall();
                iVar2 = (*pcVar1)();
                SendMessageW(*(HWND *)(iVar2 + 0x20),0xb,1,0);
                iVar2 = FUN_0079dd6d();
                pcVar1 = *(code **)(**(int **)(iVar2 + 4) + 0x74);
                guard_check_icall();
                iVar2 = (*pcVar1)();
                InvalidateRect(*(HWND *)(iVar2 + 0x20),(RECT *)0x0,1);
                iVar2 = FUN_0079dd6d();
                pcVar1 = *(code **)(**(int **)(iVar2 + 4) + 0x74);
                guard_check_icall();
                iVar2 = (*pcVar1)();
                UpdateWindow(*(HWND *)(iVar2 + 0x20));
                in_ECX = local_268;
                pCVar5 = (CSimpleStringT<wchar_t,0> *)FUN_007c8026(local_250);
                ATL::CSimpleStringT<wchar_t,0>::operator=
                          (pCVar5,(CSimpleStringT<wchar_t,0> *)&local_254);
                pcVar1 = *(code **)(*in_ECX + 0x70);
                guard_check_icall(&local_26c,&local_254);
                (*pcVar1)();
                local_8._0_1_ = 7;
                pcVar1 = *(code **)(*local_250 + 0x54);
                guard_check_icall(local_26c);
                (*pcVar1)();
                FUN_00406b10();
                FUN_00406b10();
                FUN_00406b10();
              }
            }
          }
          FUN_00406b10();
          local_8 = 0xffffffff;
          FUN_00406b10();
          iVar2 = local_260;
        }
        break;
      }
      FUN_00406b10();
      local_8 = 0xffffffff;
      FUN_00406b10();
      iVar2 = local_260;
    }
  }
  FUN_007c974f();
  FUN_007c974f();
  in_ECX[0x31] = 0;
  FUN_008d9b68();
  return;
}




/* vtable slots: CDataRecoveryHandler[14] */
/* 007ca187  FUN_007ca187  265 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007ca187(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  undefined4 uVar6;
  HKEY local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  int local_1c;
  wchar_t *local_18;
  wchar_t *local_14 [3];
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  uVar6 = 1;
  local_1c = -(uint)(in_ECX[4] != 0);
  if (in_ECX[4] != 0) {
    uVar6 = 0;
    local_2c = (HKEY)0x0;
    local_28 = 0;
    local_24 = 0;
    local_8 = 0;
    pcVar1 = *(code **)(*in_ECX + 0x20);
    guard_check_icall(&local_18);
    puVar3 = (undefined4 *)(*pcVar1)();
    uVar2 = *puVar3;
    local_8._0_1_ = 1;
    FUN_0079dd6d();
    uVar4 = FUN_007a3485(0);
    iVar5 = FUN_007c0b90(uVar4,uVar2,0,0,0x2001f,0,0);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00406b10();
    if (iVar5 == 0) {
      local_20 = in_ECX + 1;
      do {
        CStringT<>();
        CStringT<>();
        local_8._0_1_ = 3;
        FUN_007c8ce0(&local_1c,&local_18,local_14);
        ATL::CRegKey::SetStringValue((CRegKey *)&local_2c,local_18,local_14[0],1);
        FUN_00406b10();
        local_8 = (uint)local_8._1_3_ << 8;
        FUN_00406b10();
      } while (local_1c != 0);
      if (local_2c != (HKEY)0x0) {
        RegCloseKey(local_2c);
      }
      uVar6 = 1;
    }
    else if (local_2c != (HKEY)0x0) {
      RegCloseKey(local_2c);
    }
  }
  return uVar6;
}




/* vtable slots: CDataRecoveryHandler[5] */
/* 007ca6e5  FUN_007ca6e5  65 bytes, 0 callers */

void FUN_007ca6e5(int param_1)

{
  code *pcVar1;
  UINT uElapse;
  UINT_PTR UVar2;
  int *in_ECX;
  
  in_ECX[0x2e] = param_1;
  pcVar1 = *(code **)(*in_ECX + 0x10);
  guard_check_icall();
  uElapse = (*pcVar1)();
  UVar2 = SetTimer((HWND)0x0,in_ECX[0x32],uElapse,(TIMERPROC)&LAB_007c833b);
  in_ECX[0x32] = UVar2;
  return;
}




/* vtable slots: CDataRecoveryHandler[7] */
/* 007ca726  FUN_007ca726  15 bytes, 0 callers */

void FUN_007ca726(CSimpleStringT<wchar_t,0> *param_1)

{
  int in_ECX;
  
  ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)(in_ECX + 0xac),param_1);
  return;
}




/* vtable slots: CDataRecoveryHandler[9] */
/* 007ca735  FUN_007ca735  15 bytes, 0 callers */

void FUN_007ca735(CSimpleStringT<wchar_t,0> *param_1)

{
  int in_ECX;
  
  ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)(in_ECX + 0xb0),param_1);
  return;
}




/* vtable slots: CDataRecoveryHandler[11] */
/* 007ca744  FUN_007ca744  16 bytes, 0 callers */

void FUN_007ca744(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xbc) = param_1;
  return;
}




/* vtable slots: CDataRecoveryHandler[13] */
/* 007ca754  FUN_007ca754  16 bytes, 0 callers */

void FUN_007ca754(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc0) = param_1;
  return;
}




/* vtable slots: CDataRecoveryHandler[19] */
/* 007ca79e  FUN_007ca79e  149 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007ca79e(undefined4 param_1)

{
  code *pcVar1;
  CSimpleStringT<wchar_t,0> *pCVar2;
  int iVar3;
  int *in_ECX;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x7ca7aa;
  if ((*(byte *)(in_ECX + 0x2d) & 0x10) != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x50);
    guard_check_icall(param_1);
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x68);
    guard_check_icall(local_14,param_1);
    (*pcVar1)();
    local_8 = 0;
    pCVar2 = (CSimpleStringT<wchar_t,0> *)FUN_007c8026(param_1);
    ATL::CSimpleStringT<wchar_t,0>::operator=(pCVar2,(CSimpleStringT<wchar_t,0> *)local_14);
    pCVar2 = (CSimpleStringT<wchar_t,0> *)FUN_007c80fa(local_14[0]);
    iVar3 = FUN_008f899d(&DAT_00956338);
    ATL::CSimpleStringT<wchar_t,0>::SetString(pCVar2,L"",iVar3);
    FUN_00406b10();
  }
  return 1;
}



