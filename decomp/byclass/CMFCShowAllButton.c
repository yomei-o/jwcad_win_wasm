/* CMFCShowAllButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCShowAllButton[5], CMFCToolBarMenuButton[5], CTasksPaneHistoryButton[5], CTasksPaneMenuButton[5] */
/* 0087503b  FUN_0087503b  301 bytes, 3 callers */

int FUN_0087503b(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  CObject *pCVar3;
  int *in_ECX;
  code *pcVar4;
  int *local_8;
  
  FUN_00880ee9(param_1);
  in_ECX[0x26] = *(int *)(param_1 + 0x98);
  in_ECX[0x2a] = *(int *)(param_1 + 0xa8);
  in_ECX[0x2b] = *(int *)(param_1 + 0xac);
  in_ECX[0x31] = *(int *)(param_1 + 0xc4);
  in_ECX[0x2c] = *(int *)(param_1 + 0xb0);
  in_ECX[0x30] = *(int *)(param_1 + 0xc0);
  in_ECX[0x2d] = *(int *)(param_1 + 0xb4);
  in_ECX[0x2e] = *(int *)(param_1 + 0xb8);
  pcVar4 = *(code **)(*in_ECX + 0xf8);
  guard_check_icall(*(undefined4 *)(param_1 + 0xbc));
  do {
    (*pcVar4)();
    do {
      if (in_ECX[0x1f] == 0) {
        local_8 = *(int **)(param_1 + 0x74);
        if (local_8 == (int *)0x0) {
          return 0;
        }
        goto LAB_00875102;
      }
      local_8 = (int *)FUN_007a1b17();
    } while (local_8 == (int *)0x0);
    pcVar4 = *(code **)(*local_8 + 4);
    guard_check_icall(1);
  } while( true );
LAB_00875102:
  puVar1 = (undefined4 *)FUN_0049acb0(&local_8);
  if (puVar1 == (undefined4 *)0x0) {
LAB_00875163:
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  pcVar4 = *(code **)*puVar1;
  guard_check_icall();
  iVar2 = (*pcVar4)();
  if ((iVar2 == 0) || (pCVar3 = (CObject *)FUN_0079d90c(), pCVar3 == (CObject *)0x0))
  goto LAB_00875163;
  pcVar4 = *(code **)(*(int *)pCVar3 + 0x14);
  guard_check_icall(puVar1);
  (*pcVar4)();
  CObList::AddTail((CObList *)(in_ECX + 0x1c),pCVar3);
  if (local_8 == (int *)0x0) {
    return param_1 + 0x70;
  }
  goto LAB_00875102;
}




/* vtable slots: CMFCShowAllButton[1] */
/* 00877f39  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCColorPropertySheet::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCColorPropertySheet::_scalar_deleting_destructor_(CMFCColorPropertySheet *this,uint param_1)

{
  *(undefined ***)this = CMFCShowAllButton::vftable;
  FUN_00874eb0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xe8);
    }
  }
  return this;
}




/* vtable slots: CMFCShowAllButton[0] */
/* 00877fa2  FUN_00877fa2  6 bytes, 0 callers */

undefined ** FUN_00877fa2(void)

{
  return &PTR_s_CMFCShowAllButton_0099966c;
}




/* vtable slots: CMFCShowAllButton[7] */
/* 00877fa8  FUN_00877fa8  58 bytes, 0 callers */

void FUN_00877fa8(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar2 + 0x2f8);
  guard_check_icall(param_2,param_3);
  uVar3 = (*pcVar1)();
  *param_1 = 0x32;
  param_1[1] = uVar3;
  return;
}




/* vtable slots: CMFCShowAllButton[8] */
/* 00877fe2  FUN_00877fe2  103 bytes, 0 callers */

undefined4 FUN_00877fe2(undefined4 param_1,int param_2)

{
  CObject *pCVar1;
  undefined4 uVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int in_ECX;
  
  pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenuBar_00a00938,
                              *(CObject **)(in_ECX + 0x6c));
  if (pCVar1 == (CObject *)0x0) {
LAB_00878042:
    uVar2 = 0;
  }
  else {
    if (param_2 == 0) {
      pHVar3 = GetParent(*(HWND *)(pCVar1 + 0x20));
      pCVar4 = CWnd::FromHandle(pHVar3);
      pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenu_00a00790,(CObject *)pCVar4);
      if (pCVar1 == (CObject *)0x0) goto LAB_00878042;
      FUN_00820e47();
    }
    else if (DAT_00a00b20 != 0) {
      FUN_008558f6(in_ECX,2);
    }
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMFCShowAllButton[6] */
/* 00878049  FUN_00878049  277 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00878049(undefined4 param_1,LONG *param_2)

{
  int *piVar1;
  int in_ECX;
  undefined4 uVar2;
  code *pcVar3;
  int in_stack_00000018;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = *param_2;
  local_18.top = param_2[1];
  local_18.right = param_2[2];
  local_18.bottom = param_2[3];
  InflateRect(&local_18,-1,-1);
  uVar2 = 0;
  FUN_0088114d(param_1,param_2,in_stack_00000018,0);
  if (in_stack_00000018 == 0) {
    if ((*(uint *)(in_ECX + 0x24) & 0x30000) != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 2;
  }
  piVar1 = (int *)FUN_007c2574();
  pcVar3 = *(code **)(*piVar1 + 0x2fc);
  guard_check_icall(param_1,local_18.left,local_18.top,local_18.right,local_18.bottom,uVar2);
  (*pcVar3)();
  if ((*(uint *)(in_ECX + 0x24) & 0x30000) == 0) {
    if (in_stack_00000018 == 0) {
      return;
    }
    piVar1 = (int *)FUN_007c2574();
    pcVar3 = *(code **)(*piVar1 + 0x88);
    guard_check_icall(param_1,in_ECX,local_18.left,local_18.top,local_18.right,local_18.bottom,2);
  }
  else {
    piVar1 = (int *)FUN_007c2574();
    pcVar3 = *(code **)(*piVar1 + 0x88);
    guard_check_icall(param_1,in_ECX,local_18.left,local_18.top,local_18.right,local_18.bottom,1);
  }
  (*pcVar3)();
  return;
}




/* vtable slots: CMFCShowAllButton[31] */
/* 0087815e  FUN_0087815e  181 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_0087815e(undefined4 param_1,int param_2)

{
  LPWSTR lpString1;
  bool bVar1;
  undefined1 local_20 [2];
  undefined2 local_1e;
  LPCWSTR local_18;
  undefined4 local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x87816a;
  if (param_2 == 0) {
    bVar1 = false;
  }
  else {
    CStringT<>();
    local_1e = 0x28;
    local_20[0] = 9;
    local_8 = 0;
    FUN_0082ae7e(local_20);
    local_8._0_1_ = 1;
    FUN_0082afd5(local_14);
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00571e40(&local_18,0x3e99,local_14[0]);
    lpString1 = (LPWSTR)FUN_00905194(*(int *)(local_18 + -6) + 1,2);
    *(LPWSTR *)(param_2 + 0x24) = lpString1;
    bVar1 = lpString1 != (LPWSTR)0x0;
    if (bVar1) {
      lstrcpyW(lpString1,local_18);
      *(undefined4 *)(param_2 + 0xc) = 0;
    }
    FUN_00406b10();
    FUN_0082ae93();
    FUN_00406b10();
  }
  return bVar1;
}



