/* COutlookOptionsDlg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: COutlookOptionsDlg[1] */
/* 00896fb3  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall COutlookOptionsDlg::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
COutlookOptionsDlg::_scalar_deleting_destructor_(COutlookOptionsDlg *this,uint param_1)

{
  ~COutlookOptionsDlg(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x2d0);
    }
  }
  return this;
}




/* vtable slots: COutlookOptionsDlg[64] */
/* 00897470  DoDataExchange  91 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual void __thiscall CMFCImageEditorDialog::DoDataExchange(class CDataExchange *)
    protected: virtual void __thiscall COutlookOptionsDlg::DoDataExchange(class CDataExchange *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void DoDataExchange(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0078fb9c(param_1,0x4281,in_ECX + 0xa8);
  FUN_0078fb9c(param_1,0x4282,in_ECX + 0x128);
  FUN_0078fb9c(param_1,0x421b,in_ECX + 0x228);
  FUN_0078fb9c(param_1,0x40e5,in_ECX + 0x1a8);
  return;
}




/* vtable slots: COutlookOptionsDlg[10] */
/* 008979fc  FUN_008979fc  6 bytes, 0 callers */

undefined ** FUN_008979fc(void)

{
  return &PTR_FUN_0099d710;
}




/* vtable slots: COutlookOptionsDlg[94] */
/* 0089814a  FUN_0089814a  366 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0089814a(void)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  WPARAM wParam;
  undefined4 uVar4;
  HWND pHVar5;
  CWnd *pCVar6;
  CObject *pCVar7;
  COutlookOptionsDlg *in_ECX;
  LPARAM local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x898156;
  FUN_00798993();
  iVar2 = FUN_00404c80();
  if (iVar2 != 0) {
    FUN_00404c80();
    uVar3 = FUN_00797acc();
    if ((uVar3 & 0x400000) != 0) {
      FUN_00797c9f(0,0x400000,0);
    }
  }
  local_14 = 0;
  if (0 < *(int *)(*(int *)(in_ECX + 0x2c8) + 0xbc)) {
    do {
      CStringT<>();
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x2c8) + 0x1bc);
      local_8 = 0;
      guard_check_icall(local_14,&local_18);
      (*pcVar1)();
      wParam = SendMessageW(*(HWND *)(in_ECX + 0x248),0x180,0,local_18);
      SendMessageW(*(HWND *)(in_ECX + 0x248),0x19a,wParam,local_14);
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x2c8) + 0x27c);
      guard_check_icall(local_14);
      uVar4 = (*pcVar1)();
      FUN_008ceb3e(wParam,uVar4);
      local_8 = 0xffffffff;
      FUN_00406b10();
      local_14 = local_14 + 1;
    } while (local_14 < *(int *)(*(int *)(in_ECX + 0x2c8) + 0xbc));
  }
  SendMessageW(*(HWND *)(in_ECX + 0x248),0x186,0,0);
  COutlookOptionsDlg::OnSelchange(in_ECX);
  pHVar5 = GetParent(*(HWND *)(*(int *)(in_ECX + 0x2c8) + 0x20));
  pCVar6 = CWnd::FromHandle(pHVar5);
  pCVar7 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCOutlookBar_00a00680,(CObject *)pCVar6);
  if (pCVar7 == (CObject *)0x0) {
    FUN_007979e8(0);
    FUN_00797f20(0);
  }
  return 1;
}




/* vtable slots: COutlookOptionsDlg[96] */
/* 0089844c  FUN_0089844c  286 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_0089844c(void)

{
  code *pcVar1;
  LRESULT LVar2;
  int iVar3;
  int in_ECX;
  WPARAM wParam;
  undefined **local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  WPARAM local_18;
  LRESULT local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_30 = CArray<int,int>::vftable;
  local_2c = 0;
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  local_8 = 0;
  wParam = 0;
  local_18 = 0;
  LVar2 = SendMessageW(*(HWND *)(in_ECX + 0x248),0x18b,0,0);
  if (0 < LVar2) {
    do {
      local_14 = SendMessageW(*(HWND *)(in_ECX + 0x248),0x199,wParam,0);
      local_1c = FUN_008cdb3f(wParam);
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x2c8) + 0x27c);
      guard_check_icall(local_14);
      iVar3 = (*pcVar1)();
      if (local_1c != iVar3) {
        pcVar1 = *(code **)(**(int **)(in_ECX + 0x2c8) + 0x1a8);
        guard_check_icall(local_14,local_1c,0,0);
        (*pcVar1)();
      }
      FUN_0042f500(local_28,local_14);
      wParam = local_18 + 1;
      local_18 = wParam;
      LVar2 = SendMessageW(*(HWND *)(in_ECX + 0x248),0x18b,0,0);
    } while ((int)wParam < LVar2);
  }
  FUN_0080b2cc(&local_30);
  FUN_00798a09();
  local_30 = CArray<int,int>::vftable;
  if (local_2c != 0) {
    thunk_FUN_008f43b0(local_2c);
  }
  return;
}



