/* CSingleDocTemplate -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSingleDocTemplate[1] */
/* 007b31be  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CSingleDocTemplate::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CSingleDocTemplate::_scalar_deleting_destructor_(CSingleDocTemplate *this,uint param_1)

{
  *(undefined ***)this = vftable;
  FUN_007c6471();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x8c);
    }
  }
  return this;
}




/* vtable slots: CSingleDocTemplate[23] */
/* 007b31f7  AddDocument  28 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CSingleDocTemplate::AddDocument(class CDocument *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CSingleDocTemplate::AddDocument(CSingleDocTemplate *this,CDocument *param_1)

{
  CDocTemplate::AddDocument((CDocTemplate *)this,param_1);
  *(CDocument **)(this + 0x88) = param_1;
  return;
}




/* vtable slots: CSingleDocTemplate[21] */
/* 007b3213  FUN_007b3213  11 bytes, 0 callers */

int FUN_007b3213(void)

{
  int in_ECX;
  
  return -(uint)(*(int *)(in_ECX + 0x88) != 0);
}




/* vtable slots: CSingleDocTemplate[22] */
/* 007b321e  FUN_007b321e  26 bytes, 0 callers */

undefined4 FUN_007b321e(int *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if (*param_1 == -1) {
    uVar1 = *(undefined4 *)(in_ECX + 0x88);
  }
  *param_1 = 0;
  return uVar1;
}




/* vtable slots: CSingleDocTemplate[0] */
/* 007b3238  FUN_007b3238  6 bytes, 0 callers */

undefined ** FUN_007b3238(void)

{
  return &PTR_s_CSingleDocTemplate_0098099c;
}




/* vtable slots: CSingleDocTemplate[33] */
/* 007b323e  FUN_007b323e  41 bytes, 0 callers */

void FUN_007b323e(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x80);
  guard_check_icall(param_1,1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CSingleDocTemplate[32] */
/* 007b3267  FUN_007b3267  626 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_007b3267(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  code *pcVar6;
  int *piVar7;
  int *local_18;
  
  bVar1 = false;
  piVar3 = (int *)in_ECX[0x22];
  if (piVar3 == (int *)0x0) {
    pcVar6 = *(code **)(*in_ECX + 0x6c);
    guard_check_icall();
    piVar3 = (int *)(*pcVar6)();
    bVar1 = true;
    if (piVar3 == (int *)0x0) {
      AfxMessageBox(0xf104,0,0xffffffff);
      return (int *)0x0;
    }
LAB_007b32bf:
    iVar2 = piVar3[0x27];
    piVar3[0x27] = 0;
    pcVar6 = *(code **)(*in_ECX + 0x70);
    guard_check_icall(piVar3,0);
    local_18 = (int *)(*pcVar6)();
    piVar3[0x27] = iVar2;
    if (local_18 == (int *)0x0) {
      AfxMessageBox(0xf104,0,0xffffffff);
      pcVar6 = *(code **)(*piVar3 + 4);
      guard_check_icall(1);
      (*pcVar6)();
      return (int *)0x0;
    }
  }
  else {
    pcVar6 = *(code **)(*piVar3 + 0xd8);
    guard_check_icall();
    iVar2 = (*pcVar6)();
    if (iVar2 == 0) {
      DAT_00a12178 = 0;
      return (int *)0x0;
    }
    local_18 = (int *)FUN_00404c80();
    if (local_18 == (int *)0x0) goto LAB_007b32bf;
  }
  if (param_1 == 0) {
    pcVar6 = *(code **)(*in_ECX + 0x88);
    piVar7 = piVar3;
    guard_check_icall(piVar3);
    (*pcVar6)();
    if (param_3 == 0) {
      piVar3[0x28] = 1;
    }
    pcVar6 = *(code **)(*piVar3 + 0x78);
    guard_check_icall(piVar7);
    iVar2 = (*pcVar6)();
    if (iVar2 == 0) {
      if (!bVar1) {
        return (int *)0x0;
      }
      pcVar6 = *(code **)(*local_18 + 0x60);
      guard_check_icall();
      (*pcVar6)();
      return (int *)0x0;
    }
LAB_007b34a2:
    iVar2 = FUN_0079d18b();
    if ((bVar1) && (*(int *)(iVar2 + 0x20) == 0)) {
      *(int **)(iVar2 + 0x20) = local_18;
    }
    pcVar6 = *(code **)(*in_ECX + 0x74);
    guard_check_icall(local_18,piVar3,param_3);
    (*pcVar6)();
    return piVar3;
  }
  FUN_0079dd6d();
  FUN_0078ff40();
  pcVar6 = *(code **)(*piVar3 + 0x60);
  guard_check_icall();
  uVar4 = (*pcVar6)();
  pcVar6 = *(code **)(*piVar3 + 100);
  guard_check_icall(0);
  (*pcVar6)();
  pcVar6 = *(code **)(*piVar3 + 0x7c);
  iVar2 = param_1;
  guard_check_icall(param_1);
  iVar5 = (*pcVar6)();
  if (iVar5 != 0) {
    pcVar6 = *(code **)(*piVar3 + 0x58);
    guard_check_icall(param_1,param_2);
    (*pcVar6)();
    pcVar6 = *(code **)(*piVar3 + 0xd0);
    guard_check_icall(1);
    (*pcVar6)();
    FUN_00408b00();
    goto LAB_007b34a2;
  }
  if (bVar1) {
    pcVar6 = *(code **)(*local_18 + 0x60);
  }
  else {
    pcVar6 = *(code **)(*piVar3 + 0x60);
    guard_check_icall(iVar2);
    iVar5 = (*pcVar6)();
    if (iVar5 == 0) {
      pcVar6 = *(code **)(*piVar3 + 100);
      guard_check_icall(uVar4);
      (*pcVar6)();
      goto LAB_007b345c;
    }
    pcVar6 = *(code **)(*in_ECX + 0x88);
    guard_check_icall(piVar3);
    (*pcVar6)();
    pcVar6 = *(code **)(*piVar3 + 0x78);
  }
  guard_check_icall(iVar2);
  (*pcVar6)();
LAB_007b345c:
  FUN_00408b00();
  return (int *)0x0;
}




/* vtable slots: CSingleDocTemplate[24] */
/* 007b34d9  RemoveDocument  26 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CSingleDocTemplate::RemoveDocument(class CDocument *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CSingleDocTemplate::RemoveDocument(CSingleDocTemplate *this,CDocument *param_1)

{
  CDocTemplate::RemoveDocument((CDocTemplate *)this,param_1);
  *(undefined4 *)(this + 0x88) = 0;
  return;
}




/* vtable slots: CSingleDocTemplate[34] */
/* 007b34f3  FUN_007b34f3  127 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007b34f3(int *param_1)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int *uID;
  LPSTR lpBuffer;
  int in_stack_ffffffdc;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x7b34ff;
  CStringT<>();
  local_8 = 0;
  lpBuffer = (LPSTR)0x1;
  pcVar1 = *(code **)(*in_ECX + 100);
  uID = local_14;
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (((iVar2 == 0) || (*(int *)(local_14[0] + -0xc) == 0)) &&
     (iVar2 = FID_conflict_LoadStringA((HINSTANCE)0xf003,(UINT)uID,lpBuffer,in_stack_ffffffdc),
     iVar2 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pcVar1 = *(code **)(*param_1 + 0x54);
  guard_check_icall(local_14[0]);
  (*pcVar1)();
  FUN_00406b10();
  return;
}




/* vtable slots: CSingleDocTemplate[31] */
/* 007c64cf  FUN_007c64cf  89 bytes, 0 callers */

void FUN_007c64cf(void)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  int local_8;
  
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall();
  local_8 = (*pcVar1)();
  while (local_8 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x58);
    guard_check_icall(&local_8);
    piVar2 = (int *)(*pcVar1)();
    pcVar1 = *(code **)(*piVar2 + 0x84);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CSingleDocTemplate[27] */
/* 007c6528  FUN_007c6528  51 bytes, 0 callers */

int FUN_007c6528(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  
  if ((in_ECX[0x1a] != 0) && (iVar2 = FUN_0079d90c(), iVar2 != 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x5c);
    guard_check_icall(iVar2);
    (*pcVar1)();
    return iVar2;
  }
  return 0;
}




/* vtable slots: CSingleDocTemplate[28] */
/* 007c655b  FUN_007c655b  117 bytes, 0 callers */

int * FUN_007c655b(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  
  _memset(&local_18,0,0x14);
  local_8 = param_2;
  local_14 = param_1;
  local_18 = *(undefined4 *)(in_ECX + 0x70);
  if ((*(int *)(in_ECX + 0x6c) != 0) && (piVar2 = (int *)FUN_0079d90c(), piVar2 != (int *)0x0)) {
    pcVar1 = *(code **)(*piVar2 + 0x168);
    guard_check_icall(*(undefined4 *)(in_ECX + 0x54),0xcf8000,0,&local_18);
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      return piVar2;
    }
  }
  return (int *)0x0;
}




/* vtable slots: CSingleDocTemplate[25] */
/* 007c6718  GetDocString  26 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CDocTemplate::GetDocString(class ATL::CStringT<wchar_t,class
   StrTraitMFC<wchar_t,class ATL::ChTraitsCRT<wchar_t> > > &,enum CDocTemplate::DocStringIndex)const
   
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall
CDocTemplate::GetDocString
          (CDocTemplate *this,
          CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *param_1,
          DocStringIndex param_2)

{
  int iVar1;
  
  iVar1 = AfxExtractSubString(param_1,*(wchar_t **)(this + 0x84),param_2,L'\n');
  return iVar1;
}




/* vtable slots: CSingleDocTemplate[29] */
/* 007c6732  FUN_007c6732  21 bytes, 0 callers */

void FUN_007c6732(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0079a008(param_2,param_3);
  return;
}




/* vtable slots: CSingleDocTemplate[20] */
/* 007c6747  LoadTemplate  176 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CDocTemplate::LoadTemplate(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CDocTemplate::LoadTemplate(CDocTemplate *this)

{
  HINSTANCE pHVar1;
  int iVar2;
  HMENU pHVar3;
  HACCEL pHVar4;
  int unaff_EBX;
  LPSTR unaff_ESI;
  UINT unaff_EDI;
  
  if (*(int *)(*(int *)(this + 0x84) + -0xc) == 0) {
    FID_conflict_LoadStringA(*(HINSTANCE *)(this + 0x54),unaff_EDI,unaff_ESI,unaff_EBX);
  }
  if ((*(int *)(this + 0x5c) != 0) && (*(int *)(this + 0x44) == 0)) {
    iVar2 = FUN_0079dd6d();
    pHVar1 = *(HINSTANCE *)(iVar2 + 0xc);
    pHVar3 = LoadMenuW(pHVar1,(LPCWSTR)(uint)*(ushort *)(this + 0x5c));
    *(HMENU *)(this + 0x44) = pHVar3;
    pHVar4 = LoadAcceleratorsW(pHVar1,(LPCWSTR)(uint)*(ushort *)(this + 0x5c));
    *(HACCEL *)(this + 0x48) = pHVar4;
  }
  if ((*(int *)(this + 0x58) != 0) && (*(int *)(this + 0x4c) == 0)) {
    iVar2 = FUN_0079dd6d();
    pHVar1 = *(HINSTANCE *)(iVar2 + 0xc);
    pHVar3 = LoadMenuW(pHVar1,(LPCWSTR)(uint)*(ushort *)(this + 0x58));
    *(HMENU *)(this + 0x4c) = pHVar3;
    pHVar4 = LoadAcceleratorsW(pHVar1,(LPCWSTR)(uint)*(ushort *)(this + 0x58));
    *(HACCEL *)(this + 0x50) = pHVar4;
  }
  if ((*(int *)(this + 0x60) != 0) && (*(int *)(this + 0x3c) == 0)) {
    iVar2 = FUN_0079dd6d();
    pHVar1 = *(HINSTANCE *)(iVar2 + 0xc);
    pHVar3 = LoadMenuW(pHVar1,(LPCWSTR)(uint)*(ushort *)(this + 0x60));
    *(HMENU *)(this + 0x3c) = pHVar3;
    pHVar4 = LoadAcceleratorsW(pHVar1,(LPCWSTR)(uint)*(ushort *)(this + 0x60));
    *(HACCEL *)(this + 0x40) = pHVar4;
  }
  return;
}




/* vtable slots: CSingleDocTemplate[26] */
/* 007c67f7  FUN_007c67f7  194 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_007c67f7(LPCWSTR param_1,int *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  LPWSTR pWVar4;
  int *in_ECX;
  undefined4 uVar5;
  int local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7c6803;
  *param_2 = 0;
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall();
  local_18 = (*pcVar1)();
  do {
    if (local_18 == 0) {
      CStringT<>();
      local_8 = 0;
      uVar5 = 4;
      pcVar1 = *(code **)(*in_ECX + 100);
      guard_check_icall(local_14,4);
      iVar2 = (*pcVar1)();
      if ((((iVar2 == 0) || (*(int *)(local_14[0] + -0xc) == 0)) ||
          (pWVar4 = PathFindExtensionW(param_1), pWVar4 == (LPWSTR)0x0)) ||
         (iVar2 = FUN_007a7278(pWVar4,local_14[0]), iVar2 == 0)) {
        uVar5 = 3;
      }
      FUN_00406b10();
      return uVar5;
    }
    pcVar1 = *(code **)(*in_ECX + 0x58);
    guard_check_icall(&local_18);
    iVar2 = (*pcVar1)();
    iVar3 = FUN_007a7278(*(undefined4 *)(iVar2 + 0x24),param_1);
  } while (iVar3 == 0);
  *param_2 = iVar2;
  return 5;
}




/* vtable slots: CSingleDocTemplate[3] */
/* 007c68b9  FUN_007c68b9  89 bytes, 0 callers */

void FUN_007c68b9(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  CObject *pCVar2;
  int in_ECX;
  
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CCmdTarget_0097c1f8,
                              *(CObject **)(in_ECX + 0x24));
  if ((param_2 == -4) && (pCVar2 != (CObject *)0x0)) {
    pcVar1 = *(code **)(*(int *)pCVar2 + 0xc);
    guard_check_icall(param_1,0xfffffffc,param_3,param_4);
    (*pcVar1)();
  }
  else {
    FUN_007900e9(param_1,param_2,param_3,param_4);
  }
  return;
}




/* vtable slots: CSingleDocTemplate[35] */
/* 007c6912  FUN_007c6912  87 bytes, 0 callers */

void FUN_007c6912(void)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  int local_8;
  
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall();
  local_8 = (*pcVar1)();
  while (local_8 != 0) {
    pcVar1 = *(code **)(*in_ECX + 0x58);
    guard_check_icall(&local_8);
    piVar2 = (int *)(*pcVar1)();
    pcVar1 = *(code **)(*piVar2 + 0xf4);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CSingleDocTemplate[30] */
/* 007c6977  FUN_007c6977  98 bytes, 0 callers */

undefined4 FUN_007c6977(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  int local_8;
  
  pcVar1 = *(code **)(*in_ECX + 0x54);
  guard_check_icall();
  local_8 = (*pcVar1)();
  do {
    if (local_8 == 0) {
      return 1;
    }
    pcVar1 = *(code **)(*in_ECX + 0x58);
    guard_check_icall(&local_8);
    piVar2 = (int *)(*pcVar1)();
    pcVar1 = *(code **)(*piVar2 + 0xd8);
    guard_check_icall();
    iVar3 = (*pcVar1)();
  } while (iVar3 != 0);
  return 0;
}



