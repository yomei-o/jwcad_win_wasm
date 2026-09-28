/* CMFCListCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCListCtrl[90], CMFCShellListCtrl[90] */
/* 007e10eb  FUN_007e10eb  7 bytes, 0 callers */

int FUN_007e10eb(void)

{
  int in_ECX;
  
  return in_ECX + 0x80;
}




/* vtable slots: CMFCListCtrl[94], CMFCShellListCtrl[94] */
/* 007e1ad8  FUN_007e1ad8  21 bytes, 0 callers */

void FUN_007e1ad8(void)

{
  int in_ECX;
  
  SendMessageW(*(HWND *)(in_ECX + 0x20),0x1000,0,0);
  return;
}




/* vtable slots: CMFCListCtrl[93], CMFCShellListCtrl[93] */
/* 007e1aed  FUN_007e1aed  21 bytes, 0 callers */

void FUN_007e1aed(void)

{
  int in_ECX;
  
  SendMessageW(*(HWND *)(in_ECX + 0x20),0x1023,0,0);
  return;
}




/* vtable slots: CMFCListCtrl[1] */
/* 0082a916  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCListCtrl::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCListCtrl::_scalar_deleting_destructor_(CMFCListCtrl *this,uint param_1)

{
  ~CMFCListCtrl(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x150);
    }
  }
  return this;
}




/* vtable slots: CMFCListCtrl[10] */
/* 0082a982  FUN_0082a982  6 bytes, 0 callers */

undefined ** FUN_0082a982(void)

{
  return &PTR_FUN_009901f8;
}




/* vtable slots: CMFCListCtrl[0] */
/* 0082a988  FUN_0082a988  6 bytes, 0 callers */

undefined ** FUN_0082a988(void)

{
  return &PTR_s_CMFCListCtrl_0098ff80;
}




/* vtable slots: CMFCListCtrl[96], CMFCShellListCtrl[96] */
/* 0082a9c5  FUN_0082a9c5  37 bytes, 0 callers */

void FUN_0082a9c5(void)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x168);
  guard_check_icall();
  (*pcVar1)();
  FUN_0079545d(0,in_ECX);
  return;
}




/* vtable slots: CMFCListCtrl[20] */
/* 0082adec  PreSubclassWindow  29 bytes, 1 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCListCtrl::PreSubclassWindow(void)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCListCtrl::PreSubclassWindow(CMFCListCtrl *this)

{
  _AFX_THREAD_STATE *p_Var1;
  
  guard_check_icall();
  p_Var1 = AfxGetThreadState();
  if (*(int *)(p_Var1 + 0x14) == 0) {
    FUN_0082a9ea();
    return;
  }
  return;
}




/* vtable slots: CMFCListCtrl[91], CMFCShellListCtrl[91] */
/* 0082ae09  FUN_0082ae09  117 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0082ae09(int param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  int *in_ECX;
  
  FUN_0079dd6d();
  FUN_0078ff40();
  pcVar1 = *(code **)(*in_ECX + 0x168);
  guard_check_icall();
  (*pcVar1)();
  FUN_00829b98(param_1,param_2,param_3);
  in_ECX[0x4f] = param_1;
  in_ECX[0x50] = param_2;
  SendMessageW((HWND)in_ECX[8],0x1030,(WPARAM)in_ECX,0x82a949);
  FUN_00408b00();
  return;
}



