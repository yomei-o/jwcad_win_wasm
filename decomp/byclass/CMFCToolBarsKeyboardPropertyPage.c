/* CMFCToolBarsKeyboardPropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarsKeyboardPropertyPage[1] */
/* 008cc35f  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarsKeyboardPropertyPage::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarsKeyboardPropertyPage::_scalar_deleting_destructor_
          (CMFCToolBarsKeyboardPropertyPage *this,uint param_1)

{
  ~CMFCToolBarsKeyboardPropertyPage(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x588);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarsKeyboardPropertyPage[64] */
/* 008cc44b  DoDataExchange  214 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual void __thiscall CMFCRibbonKeyboardCustomizeDialog::DoDataExchange(class
   CDataExchange *)
    protected: virtual void __thiscall CMFCToolBarsKeyboardPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2015 Release */

void DoDataExchange(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0078fb9c(param_1,0x4090,in_ECX + 0xc0);
  FUN_0078fb9c(param_1,0x4104,in_ECX + 0x140);
  FUN_0078fb9c(param_1,0x4102,in_ECX + 0x1d8);
  FUN_0078fb9c(param_1,0x408e,in_ECX + 600);
  FUN_0078fb9c(param_1,0x4106,in_ECX + 0x2d8);
  FUN_0078fb9c(param_1,0x4103,in_ECX + 0x358);
  FUN_0078fb9c(param_1,0x4101,in_ECX + 0x3d8);
  FUN_0078fb9c(param_1,0x40d9,in_ECX + 0x458);
  FUN_0078fb9c(param_1,0x4105,in_ECX + 0x4d8);
  DDX_Text(param_1,0x4082,in_ECX + 0x558);
  DDX_Text(param_1,0x408f,in_ECX + 0x55c);
  return;
}




/* vtable slots: CMFCToolBarsKeyboardPropertyPage[10] */
/* 008cc521  FUN_008cc521  6 bytes, 0 callers */

undefined ** FUN_008cc521(void)

{
  return &PTR_FUN_009a6790;
}




/* vtable slots: CMFCToolBarsKeyboardPropertyPage[0] */
/* 008cc527  FUN_008cc527  6 bytes, 0 callers */

undefined ** FUN_008cc527(void)

{
  return &PTR_s_CMFCToolBarsKeyboardPropertyPage_009a64c0;
}




/* vtable slots: CMFCToolBarsKeyboardPropertyPage[94] */
/* 008cc716  FUN_008cc716  616 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008cc716(void)

{
  int *piVar1;
  code *pcVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  int iVar5;
  int *piVar6;
  LRESULT LVar7;
  CObject *pCVar8;
  int in_ECX;
  WPARAM WVar9;
  UINT in_stack_ffffffd4;
  LPSTR in_stack_ffffffd8;
  int in_stack_ffffffdc;
  int local_1c;
  LPARAM local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8cc722;
  FUN_00798993();
  if (DAT_00a13a44 != 0) {
    pHVar3 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar4 = CWnd::FromHandle(pHVar3);
    AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarsCustomizeDialog_0099a930,
                       (CObject *)pCVar4);
    FUN_0088549e(in_ECX + 0x458,0);
    SendMessageW(*(HWND *)(in_ECX + 0x478),0x14e,0,0);
    FUN_008ccb95();
    iVar5 = FUN_0079dd6d();
    piVar1 = *(int **)(*(int *)(iVar5 + 4) + 0x5c);
    if ((*(int *)(in_ECX + 0x570) != 0) && (piVar1 != (int *)0x0)) {
      pcVar2 = *(code **)(*piVar1 + 0x10);
      guard_check_icall();
      local_1c = (*pcVar2)();
joined_r0x008cc7b4:
      if (local_1c != 0) {
        pcVar2 = *(code **)(*piVar1 + 0x14);
        guard_check_icall(&local_1c);
        piVar6 = (int *)(*pcVar2)();
        local_14 = piVar6;
        iVar5 = FUN_0079d98a(&PTR_s_CMultiDocTemplate_0099f534);
        if ((iVar5 != 0) && (piVar6[0x23] != 0)) {
          for (WVar9 = 0; LVar7 = SendMessageW(*(HWND *)(in_ECX + 0x1f8),0x146,0,0),
              (int)WVar9 < LVar7; WVar9 = WVar9 + 1) {
            LVar7 = SendMessageW(*(HWND *)(in_ECX + 0x1f8),0x150,WVar9,0);
            if ((LVar7 != 0) && (*(int *)(LVar7 + 0x54) == local_14[0x15])) goto joined_r0x008cc7b4;
          }
          CStringT<>();
          local_8 = 0;
          pcVar2 = *(code **)(*local_14 + 100);
          guard_check_icall(&local_18,2);
          (*pcVar2)();
          WVar9 = SendMessageW(*(HWND *)(in_ECX + 0x1f8),0x143,0,local_18);
          SendMessageW(*(HWND *)(in_ECX + 0x1f8),0x151,WVar9,(LPARAM)local_14);
          local_8 = 0xffffffff;
          FUN_00406b10();
        }
        goto joined_r0x008cc7b4;
      }
    }
    pCVar8 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CFrameWnd_0097d624,
                                *(CObject **)(in_ECX + 0x57c));
    if ((pCVar8 != (CObject *)0x0) && (*(int *)(pCVar8 + 0x8c) != 0)) {
      CStringT<>();
      local_8 = 1;
      iVar5 = FID_conflict_LoadStringA
                        ((HINSTANCE)0x3ef2,in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc);
      if (iVar5 == 0) goto LAB_008cc979;
      WVar9 = SendMessageW(*(HWND *)(in_ECX + 0x1f8),0x143,0,local_1c);
      SendMessageW(*(HWND *)(in_ECX + 0x1f8),0x151,WVar9,0);
      SendMessageW(*(HWND *)(in_ECX + 0x1f8),0x14e,WVar9,0);
      FUN_008ccf3e();
      local_8 = 0xffffffff;
      FUN_00406b10();
    }
    LVar7 = SendMessageW(*(HWND *)(in_ECX + 0x1f8),0x147,0,0);
    if (LVar7 == -1) {
      SendMessageW(*(HWND *)(in_ECX + 0x1f8),0x14e,0,0);
      FUN_008ccf3e();
    }
    return 1;
  }
LAB_008cc979:
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



