/* CRecentDockSiteInfo -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CRecentDockSiteInfo[1] */
/* 0085f1ae  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CRecentDockSiteInfo::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CRecentDockSiteInfo::_scalar_deleting_destructor_(CRecentDockSiteInfo *this,uint param_1)

{
  FUN_0085f095();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xb4);
    }
  }
  return this;
}




/* vtable slots: CRecentDockSiteInfo[4] */
/* 0085f342  FUN_0085f342  85 bytes, 0 callers */

void FUN_0085f342(int param_1,int param_2)

{
  code *pcVar1;
  int in_ECX;
  int *piVar2;
  
  if (param_1 == 0) {
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_2 + 4);
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_2 + 8);
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(param_2 + 0xc);
    *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_2 + 0x10);
    piVar2 = (int *)(in_ECX + 0x70);
    *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_2 + 0x2c);
    param_2 = param_2 + 0x70;
  }
  else {
    piVar2 = (int *)(in_ECX + 0x30);
    *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_2 + 0x14);
    *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_2 + 0x28);
    param_2 = param_2 + 0x30;
  }
  pcVar1 = *(code **)(*piVar2 + 0x10);
  guard_check_icall(param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CRecentDockSiteInfo[3] */
/* 0085f40e  FUN_0085f40e  327 bytes, 0 callers */

void FUN_0085f40e(undefined4 param_1,CDockablePane *param_2)

{
  code *pcVar1;
  CObject *pCVar2;
  CPaneDivider *pCVar3;
  CWnd *pCVar4;
  CWnd *pCVar5;
  CObject *pCVar6;
  undefined4 uVar7;
  int in_ECX;
  CDockablePane *this;
  
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CDockablePane_00a00b9c,
                              *(CObject **)(in_ECX + 0xb0));
  this = param_2;
  if (param_2 == (CDockablePane *)0x0) {
    this = (CDockablePane *)pCVar2;
  }
  pCVar3 = CDockablePane::GetDefaultPaneDivider(this);
  pcVar1 = *(code **)(*(int *)pCVar2 + 0x228);
  guard_check_icall(0);
  pCVar4 = (CWnd *)(*pcVar1)();
  if (pCVar4 == (CWnd *)0x0) {
    if (pCVar3 == (CPaneDivider *)0x0) {
      *(undefined4 *)(in_ECX + 0x2c) = 0;
      pcVar1 = *(code **)(*(int *)(in_ECX + 0x70) + 0xc);
      guard_check_icall(0,pCVar2,0);
      (*pcVar1)();
    }
    else {
      pcVar1 = *(code **)(*(int *)(in_ECX + 0x30) + 0xc);
      guard_check_icall(param_1,pCVar2,param_2);
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x19c);
      guard_check_icall();
      pCVar4 = (CWnd *)(*pcVar1)();
      CWnd::ScreenToClient(pCVar4,(tagRECT *)(in_ECX + 0x34));
      *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(pCVar3 + 0x20);
      pcVar1 = *(code **)(*(int *)pCVar3 + 0x194);
      guard_check_icall();
      uVar7 = (*pcVar1)();
      *(undefined4 *)(in_ECX + 0x14) = uVar7;
    }
  }
  else {
    pCVar5 = CWnd::FromHandlePermanent(*(HWND__ **)(in_ECX + 0x2c));
    pCVar6 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CPaneFrameWnd_00a008b0,(CObject *)pCVar5);
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x70) + 0xc);
    *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(pCVar4 + 0x20);
    guard_check_icall(param_1,pCVar2,param_2);
    (*pcVar1)();
    CWnd::ScreenToClient(pCVar4,(tagRECT *)(in_ECX + 0x74));
    GetWindowRect(*(HWND *)(pCVar4 + 0x20),(LPRECT)(in_ECX + 4));
    if (pCVar6 != (CObject *)0x0) {
      PostMessageW(*(HWND *)(pCVar6 + 0x20),DAT_00a13b18,0,0);
    }
  }
  return;
}



