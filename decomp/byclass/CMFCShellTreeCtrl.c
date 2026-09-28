/* CMFCShellTreeCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCShellTreeCtrl[1] */
/* 007e2025  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCShellTreeCtrl::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCShellTreeCtrl::_scalar_deleting_destructor_(CMFCShellTreeCtrl *this,uint param_1)

{
  *(undefined ***)this = vftable;
  Concurrency::details::ExternalContextBase::~ExternalContextBase((ExternalContextBase *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x90);
    }
  }
  return this;
}




/* vtable slots: CMFCShellTreeCtrl[91] */
/* 007e2090  FUN_007e2090  526 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int FUN_007e2090(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  uint *puVar4;
  code *pcVar5;
  uint *puVar6;
  undefined4 local_98;
  undefined4 local_94;
  uint local_90 [15];
  uint local_54 [4];
  char *local_44;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 *local_30;
  int *local_2c;
  int local_28;
  uint local_24;
  undefined4 *local_20;
  int *local_1c;
  undefined4 local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x88;
  local_8 = 0x7e209f;
  local_1c = (int *)0x0;
  pcVar5 = *(code **)(*param_2 + 0x10);
  local_2c = in_ECX;
  guard_check_icall(param_2,0,in_ECX[0x23],&local_1c);
  iVar1 = (*pcVar5)();
  if ((-1 < iVar1) && (local_1c != (int *)0x0)) {
    local_14[0] = 1;
    pcVar5 = *(code **)(*local_1c + 0xc);
    while( true ) {
      guard_check_icall(local_1c,1,&local_18,local_14);
      iVar1 = (*pcVar5)();
      if ((iVar1 < 0) || (local_14[0] == 0)) break;
      _memset(local_54,0,0x28);
      local_54[0] = 0x67;
      pcVar5 = *(code **)(*param_2 + 4);
      guard_check_icall(param_2);
      (*pcVar5)();
      puVar2 = GlobalAlloc(0x40,0xc);
      local_20 = puVar2;
      if (puVar2 == (undefined4 *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      puVar2[2] = local_18;
      uVar3 = FUN_0082505a(param_3,local_18);
      puVar2[1] = uVar3;
      *puVar2 = param_2;
      pcVar5 = *(code **)(*in_ECX + 0x164);
      local_30 = puVar2;
      guard_check_icall(&local_28,local_20);
      (*pcVar5)();
      local_8 = 0;
      local_44 = ATL::CSimpleStringT<char,0>::PrepareWrite
                           ((CSimpleStringT<char,0> *)&local_28,*(int *)(local_28 + -0xc));
      pcVar5 = *(code **)(*in_ECX + 0x168);
      guard_check_icall(local_20,0);
      local_3c = (*pcVar5)();
      pcVar5 = *(code **)(*in_ECX + 0x168);
      guard_check_icall(local_20,1);
      local_38 = (*pcVar5)();
      local_24 = 0xb00fc010;
      pcVar5 = *(code **)(*param_2 + 0x24);
      guard_check_icall(param_2,1,&local_18,&local_24);
      (*pcVar5)();
      local_34 = local_24 & 0x90000000;
      if ((local_24 & 0x20000) != 0) {
        local_54[0] = local_54[0] | 8;
        local_54[3] = local_54[3] | 0xf00;
        local_54[2] = local_54[2] | 0x100;
      }
      puVar4 = local_54;
      puVar6 = local_90;
      for (iVar1 = 10; in_ECX = local_2c, iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      local_98 = param_1;
      local_94 = 0xffff0002;
      SendMessageW((HWND)local_2c[8],0x1132,0,(LPARAM)&local_98);
      local_14[0] = 0;
      local_8 = 0xffffffff;
      FUN_00406b10();
      pcVar5 = *(code **)(*local_1c + 0xc);
    }
    pcVar5 = *(code **)(*local_1c + 8);
    guard_check_icall(local_1c);
    (*pcVar5)();
    iVar1 = 0;
  }
  return iVar1;
}




/* vtable slots: CMFCShellTreeCtrl[10] */
/* 007e23ec  FUN_007e23ec  6 bytes, 0 callers */

undefined ** FUN_007e23ec(void)

{
  return &PTR_FUN_00989c38;
}




/* vtable slots: CMFCShellTreeCtrl[0] */
/* 007e257f  FUN_007e257f  6 bytes, 0 callers */

undefined ** FUN_007e257f(void)

{
  return &PTR_s_CMFCShellTreeCtrl_009899d0;
}




/* vtable slots: CMFCShellTreeCtrl[73] */
/* 007e2609  FUN_007e2609  172 bytes, 0 callers */

int FUN_007e2609(uint param_1,uint param_2,int param_3,long *param_4)

{
  code *pcVar1;
  CMFCShellListCtrl *pCVar2;
  LRESULT LVar3;
  undefined4 uVar4;
  int iVar5;
  CMFCShellTreeCtrl *in_ECX;
  
  if ((param_1 == 0x4e) && (*(int *)(in_ECX + 0x84) == 0)) {
    if (param_3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    if (((*(int *)(param_3 + 8) == -0x1c3) &&
        (pCVar2 = CMFCShellTreeCtrl::GetRelatedList(in_ECX), pCVar2 != (CMFCShellListCtrl *)0x0)) &&
       (LVar3 = SendMessageW(*(HWND *)(in_ECX + 0x20),0x110a,9,0), LVar3 != 0)) {
      LVar3 = SendMessageW(*(HWND *)(in_ECX + 0x20),0x110a,9,0);
      uVar4 = FUN_007a43df(LVar3);
      *(undefined4 *)(pCVar2 + 0x16c) = 1;
      pcVar1 = *(code **)(*(int *)pCVar2 + 0x188);
      guard_check_icall(uVar4);
      (*pcVar1)();
      *(undefined4 *)(pCVar2 + 0x16c) = 0;
      return 1;
    }
  }
  iVar5 = CWnd::OnChildNotify((CWnd *)in_ECX,param_1,param_2,param_3,param_4);
  return iVar5;
}




/* vtable slots: CMFCShellTreeCtrl[90] */
/* 007e2775  FUN_007e2775  101 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007e2775(int param_1,int param_2)

{
  DWORD_PTR DVar1;
  SHFILEINFOW local_2bc;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  DVar1 = SHGetFileInfoW(*(LPCWSTR *)(param_1 + 4),0,&local_2bc,0x2b4,
                         (-(uint)(param_2 != 0) & 0xffff8002) + 0xc009);
  if (DVar1 == 0) {
    local_2bc.iIcon = -1;
  }
  return local_2bc.iIcon;
}




/* vtable slots: CMFCShellTreeCtrl[89] */
/* 007e27db  FUN_007e27db  111 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007e27db(undefined4 param_1,int param_2)

{
  DWORD_PTR DVar1;
  WCHAR *pWVar2;
  SHFILEINFOW local_2bc;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_2 != 0) {
    DVar1 = SHGetFileInfoW(*(LPCWSTR *)(param_2 + 4),0,&local_2bc,0x2b4,0x208);
    if (DVar1 == 0) {
      pWVar2 = L"???";
    }
    else {
      pWVar2 = local_2bc.szDisplayName;
    }
    CStringT<>(pWVar2);
    return param_1;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCShellTreeCtrl[20] */
/* 007e2d14  FUN_007e2d14  29 bytes, 0 callers */

void FUN_007e2d14(void)

{
  _AFX_THREAD_STATE *p_Var1;
  
  guard_check_icall();
  p_Var1 = AfxGetThreadState();
  if (*(int *)(p_Var1 + 0x14) == 0) {
    FUN_007e2585();
    return;
  }
  return;
}




/* vtable slots: CMFCShellTreeCtrl[69] */
/* 007e2ffc  FUN_007e2ffc  70 bytes, 0 callers */

undefined4 FUN_007e2ffc(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((param_1 == 0x2b) || (param_1 == 0x2c)) || (param_1 == 0x117)) &&
     (DAT_00a124f8 != (int *)0x0)) {
    iVar1 = *DAT_00a124f8;
    guard_check_icall(DAT_00a124f8,param_1,param_2,param_3);
    (**(code **)(iVar1 + 0x18))();
    return 0;
  }
  uVar2 = FUN_007958aa();
  return uVar2;
}



