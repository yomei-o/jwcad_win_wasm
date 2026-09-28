/* CUserTool -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CUserTool[1] */
/* 00880485  FUN_00880485  48 bytes, 0 callers */

void FUN_00880485(byte param_1)

{
  FUN_00880416();
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




/* vtable slots: CUserTool[6] */
/* 00880651  FUN_00880651  38 bytes, 1 callers */

void FUN_00880651(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) != 0) {
    iVar1 = FUN_007c2511();
    if (*(HICON *)(in_ECX + 0x18) != *(HICON *)(iVar1 + 0x108)) {
      DestroyIcon(*(HICON *)(in_ECX + 0x18));
    }
  }
  *(undefined4 *)(in_ECX + 0x18) = 0;
  return;
}




/* vtable slots: CUserTool[0] */
/* 008806f5  FUN_008806f5  6 bytes, 0 callers */

undefined ** FUN_008806f5(void)

{
  return &PTR_s_CUserTool_00a00a64;
}




/* vtable slots: CUserTool[3] */
/* 008806fb  FUN_008806fb  60 bytes, 0 callers */

undefined4 FUN_008806fb(void)

{
  LPCWSTR lpFile;
  LPCWSTR lpParameters;
  LPCWSTR lpDirectory;
  int iVar1;
  HWND hwnd;
  HINSTANCE pHVar2;
  int in_ECX;
  
  lpFile = *(LPCWSTR *)(in_ECX + 0x14);
  if (*(int *)(lpFile + -6) != 0) {
    lpParameters = *(LPCWSTR *)(in_ECX + 8);
    lpDirectory = *(LPCWSTR *)(in_ECX + 0xc);
    iVar1 = FUN_00404c80();
    hwnd = (HWND)0x0;
    if (iVar1 != 0) {
      hwnd = *(HWND *)(iVar1 + 0x20);
    }
    pHVar2 = ShellExecuteW(hwnd,(LPCWSTR)0x0,lpFile,lpParameters,lpDirectory,1);
    if ((HINSTANCE)0x1f < pHVar2) {
      return 1;
    }
  }
  return 0;
}




/* vtable slots: CUserTool[5] */
/* 00880737  FUN_00880737  94 bytes, 0 callers */

undefined4 FUN_00880737(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  HANDLE pvVar4;
  
  iVar1 = FUN_007c2511();
  if (*(int *)(iVar1 + 0x108) == 0) {
    iVar1 = FUN_007c2511();
    iVar1 = *(int *)(iVar1 + 0x118);
    iVar2 = FUN_007c2511();
    iVar2 = *(int *)(iVar2 + 0x114);
    iVar3 = FUN_0079dd6d();
    pvVar4 = LoadImageW(*(HINSTANCE *)(iVar3 + 0xc),(LPCWSTR)0x4223,1,iVar2,iVar1,0x8000);
    iVar1 = FUN_007c2511();
    *(HANDLE *)(iVar1 + 0x108) = pvVar4;
  }
  iVar1 = FUN_007c2511();
  return *(undefined4 *)(iVar1 + 0x108);
}




/* vtable slots: CUserTool[2] */
/* 00880795  FUN_00880795  167 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_00880795(CArchive *param_1)

{
  int in_ECX;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x8807a1;
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 4));
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0x14));
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 8));
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0xc));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x10));
  }
  else {
    FUN_0047fc90((CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)(in_ECX + 4))
    ;
    CStringT<>();
    local_8 = 0;
    FUN_0047fc90(local_14);
    FUN_0088083c(local_14[0]);
    FUN_0047fc90(in_ECX + 8);
    FUN_0047fc90(in_ECX + 0xc);
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x10));
    FUN_00406b10();
  }
  return;
}




/* vtable slots: CUserTool[4] */
/* 00880897  FUN_00880897  341 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00880897(void)

{
  code *pcVar1;
  int iVar2;
  DWORD DVar3;
  DWORD_PTR DVar4;
  int *in_ECX;
  LPCWSTR pszPath;
  LPCWSTR local_4d4;
  SHFILEINFOW local_4d0;
  WCHAR local_21c [266];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x4cc;
  local_8 = 0x8808a6;
  iVar2 = FUN_004054a0(in_ECX[5] + -0x10);
  pszPath = (LPCWSTR)(iVar2 + 0x10);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  local_4d4 = pszPath;
  iVar2 = FUN_00429b90(&DAT_0095c474,0);
  if (((iVar2 == -1) && (iVar2 = FUN_00429b90(&DAT_009679d8,0), iVar2 == -1)) &&
     (iVar2 = FUN_00429b90(&DAT_0095bad4,0), iVar2 == -1)) {
    iVar2 = FUN_004054a0(in_ECX[5] + -0x10);
    local_8._0_1_ = 1;
    DVar3 = SearchPathW((LPCWSTR)0x0,(LPCWSTR)(iVar2 + 0x10),(LPCWSTR)0x0,0x104,local_21c,
                        (LPWSTR *)0x0);
    if (DVar3 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x14);
      guard_check_icall();
      (*pcVar1)();
      FUN_00406b10();
      goto LAB_008809dc;
    }
    iVar2 = FUN_008f899d(local_21c);
    ATL::CSimpleStringT<wchar_t,0>::SetString
              ((CSimpleStringT<wchar_t,0> *)&local_4d4,local_21c,iVar2);
    local_8._0_1_ = 0;
    FUN_00406b10();
    pszPath = local_4d4;
  }
  DVar4 = SHGetFileInfoW(pszPath,0,&local_4d0,0x2b4,0x105);
  if (DVar4 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x14);
    guard_check_icall();
    (*pcVar1)();
  }
LAB_008809dc:
  FUN_00406b10();
  FUN_008d9b68();
  return;
}



