/* CMFCTabButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCTabButton[95] */
/* 00811129  FUN_00811129  81 bytes, 0 callers */

void FUN_00811129(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int in_ECX;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x108);
  pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar4 = CWnd::FromHandle(pHVar3);
  AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,(CObject *)pCVar4);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  return;
}




/* vtable slots: CMFCTabButton[94] */
/* 00811204  FUN_00811204  95 bytes, 0 callers */

void FUN_00811204(undefined4 param_1,undefined4 *param_2)

{
  code *pcVar1;
  int *piVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int in_ECX;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x104);
  pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar4 = CWnd::FromHandle(pHVar3);
  AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,(CObject *)pCVar4);
  guard_check_icall(param_1,*param_2,param_2[1],param_2[2],param_2[3]);
  (*pcVar1)();
  return;
}



