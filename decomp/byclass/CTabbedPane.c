/* CTabbedPane -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTabbedPane[1] */
/* 008628ee  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CTabbedPane::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CTabbedPane::_scalar_deleting_destructor_(CTabbedPane *this,uint param_1)

{
  *(undefined ***)this = vftable;
  CBaseTabbedPane::~CBaseTabbedPane((CBaseTabbedPane *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x388);
    }
  }
  return this;
}




/* vtable slots: CTabbedPane[239] */
/* 00862927  FUN_00862927  76 bytes, 0 callers */

undefined4 FUN_00862927(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,
                              *(CObject **)(in_ECX + 0x370));
  pcVar1 = *(code **)(*(int *)pCVar2 + 0x1ac);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 < 1) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0085d6e0(param_1,param_2);
  }
  return uVar4;
}




/* vtable slots: CTabbedPane[238] */
/* 00862973  FUN_00862973  83 bytes, 0 callers */

undefined4 FUN_00862973(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  CObject *pCVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,
                              *(CObject **)(in_ECX + 0x370));
  pcVar1 = *(code **)(*(int *)pCVar2 + 0x1ac);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 < 2) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0085dcb5(param_1,param_2,param_3,param_4);
  }
  return uVar4;
}




/* vtable slots: CTabbedPane[10] */
/* 008629c6  FUN_008629c6  6 bytes, 0 callers */

undefined ** FUN_008629c6(void)

{
  return &PTR_FUN_00997da0;
}




/* vtable slots: CTabbedPane[0] */
/* 008629cc  FUN_008629cc  6 bytes, 0 callers */

undefined ** FUN_008629cc(void)

{
  return &PTR_s_CTabbedPane_00a009a4;
}




/* vtable slots: CTabbedPane[203] */
/* 008629d2  FUN_008629d2  173 bytes, 0 callers */

void FUN_008629d2(LPRECT param_1,LPRECT param_2)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int *in_ECX;
  
  SetRectEmpty(param_1);
  SetRectEmpty(param_2);
  pcVar1 = *(code **)(*in_ECX + 0x330);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,(CObject *)in_ECX[0xdc]
                               );
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x180);
    guard_check_icall(param_1);
    (*pcVar1)();
    param_2 = param_1;
  }
  else {
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,(CObject *)in_ECX[0xdc]
                               );
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x180);
    guard_check_icall(param_2);
    (*pcVar1)();
  }
  AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,(CObject *)in_ECX[0xdc]);
  FUN_0079e8b8(param_2);
  return;
}




/* vtable slots: CTabbedPane[204] */
/* 00862a7f  FUN_00862a7f  32 bytes, 0 callers */

bool FUN_00862a7f(void)

{
  CObject *pCVar1;
  int in_ECX;
  
  pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCTabCtrl_0098d8b8,
                              *(CObject **)(in_ECX + 0x370));
  return *(int *)(pCVar1 + 0x90) == 0;
}




/* vtable slots: CTabbedPane[183] */
/* 00862c49  FUN_00862c49  188 bytes, 0 callers */

void FUN_00862c49(void)

{
  code *pcVar1;
  LPARAM lParam;
  CObject *pCVar2;
  LRESULT LVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x370) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x370) + 0x210);
    guard_check_icall();
    lParam = (*pcVar1)();
    pCVar2 = (CObject *)FUN_007e5618();
    pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,pCVar2);
    if ((pCVar2 == (CObject *)0x0) ||
       (LVar3 = SendMessageW(*(HWND *)(pCVar2 + 0x20),DAT_00a13c60,0,lParam), LVar3 == 0)) {
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x370) + 0x1a4);
      guard_check_icall();
      iVar4 = (*pcVar1)();
      if (iVar4 == 1) {
        FUN_008902c3();
      }
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x370) + 0x20c);
      guard_check_icall();
      uVar5 = (*pcVar1)();
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x370) + 0x1a8);
      guard_check_icall(uVar5,0,1,0);
      (*pcVar1)();
    }
  }
  return;
}



