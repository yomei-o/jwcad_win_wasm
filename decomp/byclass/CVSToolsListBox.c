/* CVSToolsListBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CVSToolsListBox[1] */
/* 008cb091  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CVSToolsListBox::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CVSToolsListBox::_scalar_deleting_destructor_(CVSToolsListBox *this,uint param_1)

{
  FUN_007e3204();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x200);
    }
  }
  return this;
}




/* vtable slots: CVSToolsListBox[107] */
/* 008cb268  FUN_008cb268  158 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008cb268(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  CSimpleStringT<wchar_t,0> *pCVar3;
  int *in_ECX;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x8cb274;
  iVar2 = FUN_008cb0c4();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*in_ECX + 0x170);
    guard_check_icall();
    (*pcVar1)();
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x180);
    guard_check_icall(local_14,param_1);
    pCVar3 = (CSimpleStringT<wchar_t,0> *)(*pcVar1)();
    local_8 = 0;
    ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)(iVar2 + 4),pCVar3);
    local_8 = 0xffffffff;
    FUN_00406b10();
    pcVar1 = *(code **)(*in_ECX + 0x18c);
    guard_check_icall(param_1,iVar2);
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x1a4);
    guard_check_icall();
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CVSToolsListBox[110] */
/* 008cb306  FUN_008cb306  48 bytes, 0 callers */

void FUN_008cb306(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x188);
  guard_check_icall(param_1);
  uVar2 = (*pcVar1)();
  FUN_00852560(uVar2);
  return;
}




/* vtable slots: CVSToolsListBox[109] */
/* 008cb336  FUN_008cb336  48 bytes, 0 callers */

void FUN_008cb336(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x188);
  guard_check_icall(param_1);
  uVar2 = (*pcVar1)();
  FUN_008525b1(uVar2);
  return;
}




/* vtable slots: CVSToolsListBox[108] */
/* 008cb366  FUN_008cb366  98 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008cb366(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  CSimpleStringT<wchar_t,0> *pCVar3;
  int *in_ECX;
  undefined1 local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x8cb372;
  pcVar1 = *(code **)(*in_ECX + 0x188);
  guard_check_icall(param_1);
  iVar2 = (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x180);
  guard_check_icall(local_14,param_1);
  pCVar3 = (CSimpleStringT<wchar_t,0> *)(*pcVar1)();
  local_8 = 0;
  ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)(iVar2 + 4),pCVar3);
  FUN_00406b10();
  return;
}




/* vtable slots: CVSToolsListBox[106] */
/* 008cb441  FUN_008cb441  64 bytes, 0 callers */

undefined4 FUN_008cb441(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x188);
  guard_check_icall(param_1);
  uVar2 = (*pcVar1)();
  FUN_00852602(uVar2);
  *(undefined4 *)(in_ECX[0x7e] + 0x145c) = 0;
  return 1;
}




/* vtable slots: CVSToolsListBox[105] */
/* 008cb742  FUN_008cb742  296 bytes, 0 callers */

void FUN_008cb742(void)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int local_8;
  
  pcVar1 = *(code **)(*in_ECX + 0x178);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 < 0) {
    local_8 = 0;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x188);
    guard_check_icall(iVar2);
    local_8 = (*pcVar1)();
  }
  if (local_8 == 0) {
    Empty();
    Empty();
    Empty();
  }
  else {
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(in_ECX[0x7e] + 0x1450),
               (CSimpleStringT<wchar_t,0> *)(local_8 + 0x14));
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(in_ECX[0x7e] + 0x1454),
               (CSimpleStringT<wchar_t,0> *)(local_8 + 8));
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(in_ECX[0x7e] + 0x1458),
               (CSimpleStringT<wchar_t,0> *)(local_8 + 0xc));
  }
  pcVar1 = *(code **)(**(int **)(in_ECX[0x7e] + 0x1460) + 0x184);
  guard_check_icall(*(undefined4 *)(in_ECX[0x7e] + 0x145c));
  (*pcVar1)();
  *(int *)(in_ECX[0x7e] + 0x145c) = local_8;
  FUN_007955d2(0);
  FUN_008cb1e7();
  pcVar1 = *(code **)(**(int **)(in_ECX[0x7e] + 0x1460) + 0x188);
  guard_check_icall(*(undefined4 *)(in_ECX[0x7e] + 0x145c));
  (*pcVar1)();
  return;
}



