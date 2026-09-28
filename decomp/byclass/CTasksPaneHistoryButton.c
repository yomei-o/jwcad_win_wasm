/* CTasksPaneHistoryButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTasksPaneHistoryButton[1] */
/* 008d38bf  FUN_008d38bf  51 bytes, 0 callers */

void FUN_008d38bf(byte param_1)

{
  FUN_008d37f5();
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




/* vtable slots: CTasksPaneHistoryButton[0] */
/* 008d4c0e  FUN_008d4c0e  6 bytes, 0 callers */

undefined ** FUN_008d4c0e(void)

{
  return &PTR_s_CTasksPaneHistoryButton_00a00da4;
}




/* vtable slots: CTasksPaneHistoryButton[10], CTasksPaneMenuButton[10] */
/* 008d5164  OnChangeParentWnd  40 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    public: virtual void __thiscall CTasksPaneHistoryButton::OnChangeParentWnd(class CWnd *)
    public: virtual void __thiscall CTasksPaneMenuButton::OnChangeParentWnd(class CWnd *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

void OnChangeParentWnd(CObject *param_1)

{
  CObject *pCVar1;
  int in_ECX;
  
  FUN_0087713d(param_1);
  pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTasksPane_00a00d6c,param_1);
  *(CObject **)(in_ECX + 0xe8) = pCVar1;
  return;
}



