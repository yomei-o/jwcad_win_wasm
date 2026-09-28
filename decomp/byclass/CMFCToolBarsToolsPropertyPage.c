/* CMFCToolBarsToolsPropertyPage -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarsToolsPropertyPage[0], CPropertyPage[0] */
/* 007a070e  FUN_007a070e  6 bytes, 0 callers */

undefined ** FUN_007a070e(void)

{
  return &PTR_s_CPropertyPage_0097e390;
}




/* vtable slots: CMFCToolBarsToolsPropertyPage[1] */
/* 008cb05e  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarsToolsPropertyPage::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarsToolsPropertyPage::_scalar_deleting_destructor_
          (CMFCToolBarsToolsPropertyPage *this,uint param_1)

{
  FUN_008caf71();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x1478);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarsToolsPropertyPage[64] */
/* 008cb124  DoDataExchange  195 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsToolsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCToolBarsToolsPropertyPage::DoDataExchange
          (CMFCToolBarsToolsPropertyPage *this,CDataExchange *param_1)

{
  FUN_0078fb9c(param_1,0x4265,this + 0xc0);
  FUN_0078fb9c(param_1,0x425d,this + 0x888);
  FUN_0078fb9c(param_1,0x421c,this + 0x1050);
  FUN_0078fb9c(param_1,0x421d,this + 0x10d0);
  FUN_0078fb9c(param_1,0x421a,this + 0x1150);
  FUN_0078fb9c(param_1,0x421b,this + 0x11d0);
  FUN_0078fb9c(param_1,0x4219,this + 0x1250);
  DDX_Text(param_1,0x421a,this + 0x1450);
  DDX_Text(param_1,0x421c,this + 0x1454);
  DDX_Text(param_1,0x421d,this + 0x1458);
  return;
}




/* vtable slots: CMFCToolBarsToolsPropertyPage[10] */
/* 008cb262  FUN_008cb262  6 bytes, 0 callers */

undefined ** FUN_008cb262(void)

{
  return &PTR_FUN_009a6248;
}




/* vtable slots: CMFCToolBarsToolsPropertyPage[94] */
/* 008cb518  FUN_008cb518  364 bytes, 0 callers */

undefined4 FUN_008cb518(void)

{
  code *pcVar1;
  HWND pHVar2;
  CWnd *pCVar3;
  CObject *pCVar4;
  int iVar5;
  HMENU pHVar6;
  CMenu *pCVar7;
  undefined4 uVar8;
  int in_ECX;
  undefined4 uVar9;
  int local_8;
  
  FUN_00798993();
  if (DAT_00a13bac != 0) {
    pHVar2 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar3 = CWnd::FromHandle(pHVar2);
    pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarsCustomizeDialog_0099a930,
                                (CObject *)pCVar3);
    *(CObject **)(in_ECX + 0x1460) = pCVar4;
    if (pCVar4 != (CObject *)0x0) {
      FUN_007e4eb2(0xf);
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x1460) + 0x180);
      guard_check_icall();
      (*pcVar1)();
      local_8 = *(int *)(DAT_00a13bac + 8);
      if (local_8 != 0) {
        do {
          iVar5 = FUN_0049acb0(&local_8);
          pcVar1 = *(code **)(*(int *)(in_ECX + 0x1250) + 0x16c);
          guard_check_icall(iVar5 + 4,iVar5,0xffffffff);
          (*pcVar1)();
        } while (local_8 != 0);
      }
      iVar5 = *(int *)(DAT_00a13bac + 0x3c);
      uVar9 = 0;
      if (iVar5 != 0) {
        FUN_00797f20(5);
        FUN_004fd4f0(iVar5);
        pHVar6 = GetSubMenu(*(HMENU *)(in_ECX + 0x1470),0);
        pCVar7 = CMenu::FromHandle(pHVar6);
        if (pCVar7 == (CMenu *)0x0) {
          uVar8 = 0;
        }
        else {
          uVar8 = *(undefined4 *)(pCVar7 + 4);
        }
        *(undefined4 *)(in_ECX + 0x86c) = uVar8;
      }
      iVar5 = *(int *)(DAT_00a13bac + 0x38);
      if (iVar5 != 0) {
        FUN_00797f20(5);
        FUN_004fd4f0(iVar5);
        pHVar6 = GetSubMenu(*(HMENU *)(in_ECX + 0x1468),0);
        pCVar7 = CMenu::FromHandle(pHVar6);
        if (pCVar7 != (CMenu *)0x0) {
          uVar9 = *(undefined4 *)(pCVar7 + 4);
        }
        *(undefined4 *)(in_ECX + 0x1034) = uVar9;
      }
      *(undefined4 *)(in_ECX + 0x868) = 1;
      *(undefined4 *)(in_ECX + 0x1030) = 1;
      FUN_008cb1e7();
      return 1;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCToolBarsToolsPropertyPage[102] */
/* 008cb6f8  FUN_008cb6f8  58 bytes, 0 callers */

void FUN_008cb6f8(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  pcVar1 = *(code **)(**(int **)(in_ECX + 0x1460) + 0x18c);
  guard_check_icall(DAT_00a13bac + 4);
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    return;
  }
  FUN_007a0d54();
  return;
}




/* vtable slots: CMFCToolBarsToolsPropertyPage[96] */
/* 008cb732  FUN_008cb732  16 bytes, 0 callers */

void FUN_008cb732(void)

{
  FUN_008cb86a();
  guard_check_icall();
  return;
}



