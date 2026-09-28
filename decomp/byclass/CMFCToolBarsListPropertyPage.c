/* CMFCToolBarsListPropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarsListPropertyPage[1] */
/* 008c9e63  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarsListPropertyPage::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarsListPropertyPage::_scalar_deleting_destructor_
          (CMFCToolBarsListPropertyPage *this,uint param_1)

{
  ~CMFCToolBarsListPropertyPage(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x3f0);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarsListPropertyPage[64] */
/* 008c9f3e  DoDataExchange  141 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsListPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCToolBarsListPropertyPage::DoDataExchange
          (CMFCToolBarsListPropertyPage *this,CDataExchange *param_1)

{
  FUN_0078fb9c(param_1,0x40e4,this + 0xc0);
  FUN_0078fb9c(param_1,0x40e8,this + 0x140);
  FUN_0078fb9c(param_1,0x40e7,this + 0x1c0);
  FUN_0078fb9c(param_1,0x40e9,this + 0x240);
  FUN_0078fb9c(param_1,0x40e5,this + 0x2c0);
  FUN_0078fb9c(param_1,0x40e3,this + 0x340);
  FUN_0078f6f8(param_1,0x40e4,this + 0x3e0);
  return;
}




/* vtable slots: CMFCToolBarsListPropertyPage[10] */
/* 008c9fd1  FUN_008c9fd1  6 bytes, 0 callers */

undefined ** FUN_008c9fd1(void)

{
  return &PTR_FUN_009a5e08;
}




/* vtable slots: CMFCToolBarsListPropertyPage[0] */
/* 008c9fdd  FUN_008c9fdd  6 bytes, 0 callers */

undefined ** FUN_008c9fdd(void)

{
  return &PTR_s_CMFCToolBarsListPropertyPage_009a5ac4;
}




/* vtable slots: CMFCToolBarsListPropertyPage[61] */
/* 008ca064  FUN_008ca064  215 bytes, 0 callers */

void FUN_008ca064(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  WPARAM wParam;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if ((((short)((uint)param_1 >> 0x10) == 0x28) && ((short)param_1 == 0x40e3)) &&
     (wParam = SendMessageW(*(HWND *)(in_ECX + 0x360),0x188,0,0), wParam != 0xffffffff)) {
    piVar2 = (int *)SendMessageW(*(HWND *)(in_ECX + 0x360),0x199,wParam,0);
    pcVar1 = *(code **)(*piVar2 + 0x1c8);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 == 0) {
      iVar3 = FUN_008cdb3f(wParam);
      if (iVar3 == 0) {
        FUN_008ceb3e(wParam,1);
        MessageBeep(0xffffffff);
      }
    }
    else {
      pcVar1 = *(code **)(*piVar2 + 0x224);
      uVar4 = FUN_008cdb3f(wParam);
      guard_check_icall(uVar4,0,1);
      (*pcVar1)();
    }
  }
  FUN_00793275(param_1,param_2);
  return;
}




/* vtable slots: CMFCToolBarsListPropertyPage[94] */
/* 008ca327  FUN_008ca327  515 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008ca327(void)

{
  int *lParam;
  undefined4 *puVar1;
  code *pcVar2;
  CWnd *pCVar3;
  int iVar4;
  int iVar5;
  WPARAM wParam;
  uint uVar6;
  undefined4 uVar7;
  HWND pHVar8;
  CObject *pCVar9;
  LRESULT LVar10;
  int in_ECX;
  UINT in_stack_ffffffd4;
  LPSTR in_stack_ffffffd8;
  int in_stack_ffffffdc;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8ca333;
  FUN_00798993();
  puVar1 = DAT_00a127ec;
  if (*(int *)(in_ECX + 1000) == 0) {
    FUN_007979e8(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    puVar1 = DAT_00a127ec;
  }
  while (puVar1 != (undefined4 *)0x0) {
    lParam = (int *)puVar1[2];
    puVar1 = (undefined4 *)*puVar1;
    if (lParam == (int *)0x0) goto LAB_008ca525;
    pCVar3 = CWnd::FromHandlePermanent((HWND__ *)lParam[8]);
    if ((pCVar3 != (CWnd *)0x0) &&
       (iVar4 = FUN_0079d98a(&PTR_s_CMFCDropDownToolBar_00a00b44), iVar4 == 0)) {
      iVar4 = FUN_00792b4c();
      iVar5 = FUN_00792b4c();
      if (iVar4 == iVar5) {
        pcVar2 = *(code **)(*lParam + 0x3f0);
        guard_check_icall();
        iVar4 = (*pcVar2)();
        if ((iVar4 != 0) && (lParam[0x2e0] == 0)) {
          CStringT<>();
          local_8 = 0;
          FUN_00792c64(local_14);
          if ((*(int *)(local_14[0] + -0xc) == 0) &&
             (iVar4 = FID_conflict_LoadStringA
                                ((HINSTANCE)0x3ee8,in_stack_ffffffd4,in_stack_ffffffd8,
                                 in_stack_ffffffdc), iVar4 == 0)) goto LAB_008ca525;
          wParam = SendMessageW(*(HWND *)(in_ECX + 0x360),0x180,0,local_14[0]);
          SendMessageW(*(HWND *)(in_ECX + 0x360),0x19a,wParam,(LPARAM)lParam);
          uVar6 = FUN_00797b3d();
          if ((uVar6 & 0x10000000) != 0) {
            FUN_008ceb3e(wParam,1);
          }
          pcVar2 = *(code **)(*lParam + 0x1c8);
          guard_check_icall();
          uVar7 = (*pcVar2)();
          FUN_008cefd3(wParam,uVar7);
          local_8 = 0xffffffff;
          FUN_00406b10();
        }
      }
    }
  }
  pHVar8 = GetParent(*(HWND *)(in_ECX + 0x20));
  pCVar3 = CWnd::FromHandle(pHVar8);
  pCVar9 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarsCustomizeDialog_0099a930,
                              (CObject *)pCVar3);
  if (pCVar9 != (CObject *)0x0) {
    if (((byte)pCVar9[0x15c] & 2) == 0) {
      FUN_00797f20(0);
    }
    LVar10 = SendMessageW(*(HWND *)(in_ECX + 0x360),0x18b,0,0);
    if (0 < LVar10) {
      SendMessageW(*(HWND *)(in_ECX + 0x360),0x186,0,0);
      FUN_008cabe7();
    }
    return 1;
  }
LAB_008ca525:
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



