/* CMFCDropDownToolbarButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCDropDownToolbarButton[46], CMFCOutlookBarPaneButton[46], CMFCToolBarButton[46], CMFCToolBarColorButton[46], CMFCToolBarMenuButtonsButton[46], CTasksPaneNavigateButton[46] */
/* 00882aa5  FUN_00882aa5  618 bytes, 3 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00882aa5(undefined4 param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  int in_ECX;
  uint uVar6;
  int local_220;
  CSimpleStringT<wchar_t,0> local_21c [4];
  CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> local_218 [4];
  wchar_t local_214 [262];
  uint local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x21c;
  local_8 = 0x882ab4;
  FUN_007ed2e1();
  iVar2 = FUN_004054a0(*(int *)(in_ECX + 0x2c) + -0x10);
  local_220 = iVar2 + 0x10;
  local_8 = 0;
  if (((*(int *)(iVar2 + 4) == 0) && (*(int *)(in_ECX + 0x20) != 0)) &&
     (*(int *)(in_ECX + 0x20) != -1)) {
    CStringT<>();
    local_8 = CONCAT31(local_8._1_3_,1);
    iVar2 = FUN_0078f2e1(*(undefined4 *)(in_ECX + 0x20),local_214,0x100);
    if (iVar2 != 0) {
      iVar2 = AfxExtractSubString(local_218,local_214,1,L'\n');
      if (iVar2 != 0) {
        ATL::CSimpleStringT<wchar_t,0>::operator=
                  ((CSimpleStringT<wchar_t,0> *)&local_220,(CSimpleStringT<wchar_t,0> *)local_218);
      }
    }
    local_8 = local_8 & 0xffffff00;
    FUN_00406b10();
  }
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_2,(CSimpleStringT<wchar_t,0> *)&local_220);
  FUN_007fa476(0x26);
  iVar2 = FUN_008f899d(L"Press");
  ATL::CSimpleStringT<wchar_t,0>::SetString(param_2 + 0x14,L"Press",iVar2);
  piVar3 = (int *)FUN_0079296c();
  if ((piVar3 != (int *)0x0) && (piVar3[8] != 0)) {
    CStringT<>();
    local_8._0_1_ = 2;
    pcVar1 = *(code **)(*piVar3 + 0x174);
    guard_check_icall(*(undefined4 *)(in_ECX + 0x20),local_218);
    (*pcVar1)();
    ATL::CSimpleStringT<wchar_t,0>::operator=(param_2 + 8,(CSimpleStringT<wchar_t,0> *)local_218);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00406b10();
  }
  piVar3 = (int *)FUN_0079296c();
  CStringT<>();
  local_8 = CONCAT31(local_8._1_3_,3);
  if (piVar3 != (int *)0x0) {
    iVar2 = FUN_0082b064(*(undefined4 *)(in_ECX + 0x20),local_21c,piVar3,1);
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*piVar3 + 0x170);
      guard_check_icall();
      uVar4 = (*pcVar1)();
      iVar2 = FUN_0082b064(*(undefined4 *)(in_ECX + 0x20),local_21c,uVar4,0);
      if (iVar2 == 0) goto LAB_00882c82;
    }
    ATL::CSimpleStringT<wchar_t,0>::operator=(param_2 + 0xc,local_21c);
  }
LAB_00882c82:
  *(undefined4 *)(param_2 + 0x18) = 0x2b;
  uVar5 = 0x100000;
  *(undefined4 *)(param_2 + 0x20) = 1;
  *(undefined4 *)(param_2 + 0x1c) = 0x100000;
  uVar6 = *(uint *)(in_ECX + 0x24);
  if ((uVar6 & 0x10000) != 0) {
    uVar5 = 0x100010;
    *(undefined4 *)(param_2 + 0x1c) = 0x100010;
    uVar6 = *(uint *)(in_ECX + 0x24);
  }
  if ((uVar6 & 0x40000) != 0) {
    uVar5 = uVar5 | 1;
    *(uint *)(param_2 + 0x1c) = uVar5;
    uVar6 = *(uint *)(in_ECX + 0x24);
  }
  *(uint *)(param_2 + 0x1c) = (-(uint)((uVar6 & 0x20000) != 0) & 0xffffff84) + 0x80 | uVar5;
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(in_ECX + 0x54);
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(in_ECX + 0x58);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(in_ECX + 0x5c);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(in_ECX + 0x60);
  FUN_0079e8b8(param_2 + 0x24);
  FUN_00406b10();
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCDropDownToolbarButton[1] */
/* 0088a1f5  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCDropDownToolbarButton::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCDropDownToolbarButton::_scalar_deleting_destructor_
          (CMFCDropDownToolbarButton *this,uint param_1)

{
  ~CMFCDropDownToolbarButton(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x8c);
    }
  }
  return this;
}




/* vtable slots: CMFCDropDownToolbarButton[5] */
/* 0088a228  CopyFrom  56 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCDropDownToolbarButton::CopyFrom(class CMFCToolBarButton
   const &)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCDropDownToolbarButton::CopyFrom(CMFCDropDownToolbarButton *this,CMFCToolBarButton *param_1)

{
  undefined4 uVar1;
  
  FUN_00880ee9(param_1);
  *(undefined4 *)(this + 0x70) = *(undefined4 *)(param_1 + 0x70);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(this + 0x74),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x74));
  uVar1 = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(this + 0x1c) = 0;
  *(undefined4 *)(this + 0x80) = uVar1;
  return;
}




/* vtable slots: CMFCDropDownToolbarButton[11] */
/* 0088a48e  FUN_0088a48e  461 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0088a48e(int *param_1)

{
  code *pcVar1;
  int iVar2;
  HMENU pHVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  LPCWSTR lpNewItem;
  UINT in_stack_ffffffc4;
  LPSTR in_stack_ffffffc8;
  int in_stack_ffffffcc;
  undefined **local_2c;
  HMENU local_28;
  int local_24;
  int local_20;
  LPCWSTR local_1c;
  CSimpleStringT<wchar_t,0> local_18 [4];
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x88a49a;
  if ((*(int *)(in_ECX + 0x70) == 0) ||
     (local_24 = in_ECX, iVar2 = FUN_008810bc(param_1), iVar2 == 0)) {
    uVar7 = 0;
  }
  else {
    local_28 = (HMENU)0x0;
    local_2c = CMenu::vftable;
    local_8._0_1_ = 0;
    local_8._1_3_ = 0;
    pHVar3 = CreatePopupMenu();
    CMenu::Attach((CMenu *)&local_2c,pHVar3);
    local_20 = *(int *)(*(int *)(in_ECX + 0x70) + 0xc40);
    while (local_20 != 0) {
      piVar4 = (int *)FUN_0044f2d0(&local_20);
      iVar2 = *piVar4;
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      if ((*(byte *)(iVar2 + 0x24) & 1) == 0) {
        if ((*(int *)(iVar2 + 0x20) != 0) && (*(int *)(iVar2 + 0x20) != -1)) {
          iVar5 = FUN_004054a0(*(int *)(iVar2 + 0x2c) + -0x10);
          lpNewItem = (LPCWSTR)(iVar5 + 0x10);
          local_1c = lpNewItem;
          if (*(int *)(iVar5 + 4) == 0) {
            CStringT<>();
            local_8._0_1_ = 2;
            iVar6 = FID_conflict_LoadStringA
                              (*(HINSTANCE *)(iVar2 + 0x20),in_stack_ffffffc4,in_stack_ffffffc8,
                               in_stack_ffffffcc);
            iVar5 = local_14;
            if ((iVar6 != 0) && (iVar6 = FUN_0044e690(10,0), iVar6 != -1)) {
              FUN_00450000(local_18,iVar6 + 1,*(int *)(iVar5 + -0xc) - (iVar6 + 1));
              local_8._0_1_ = 3;
              ATL::CSimpleStringT<wchar_t,0>::operator=
                        ((CSimpleStringT<wchar_t,0> *)&local_1c,local_18);
              FUN_00406b10();
              lpNewItem = local_1c;
            }
            FUN_00406b10();
          }
          AppendMenuW(local_28,0,*(UINT_PTR *)(iVar2 + 0x20),lpNewItem);
          local_8._0_1_ = 0;
          FUN_00406b10();
          in_ECX = local_24;
        }
      }
      else {
        AppendMenuW(local_28,0x800,0,(LPCWSTR)0x0);
      }
    }
    param_1[8] = 0;
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(param_1 + 0xb),
               (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x74));
    pcVar1 = *(code **)(*param_1 + 0xc0);
    guard_check_icall(0xffffffff);
    (*pcVar1)();
    param_1[3] = 0;
    pcVar1 = *(code **)(*param_1 + 0xd0);
    guard_check_icall(local_28);
    (*pcVar1)();
    CMenu::DestroyMenu((CMenu *)&local_2c);
    local_8 = 4;
    local_2c = CMenu::vftable;
    CMenu::DestroyMenu((CMenu *)&local_2c);
    uVar7 = 1;
  }
  return uVar7;
}




/* vtable slots: CMFCDropDownToolbarButton[0] */
/* 0088a674  FUN_0088a674  6 bytes, 0 callers */

undefined ** FUN_0088a674(void)

{
  return &PTR_s_CMFCDropDownToolbarButton_00a00b7c;
}




/* vtable slots: CMFCDropDownToolbarButton[50] */
/* 0088a67a  FUN_0088a67a  17 bytes, 0 callers */

undefined4 FUN_0088a67a(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(int *)(in_ECX + 0x48) != 0) && (*(int *)(in_ECX + 0x84) == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CMFCDropDownToolbarButton[7] */
/* 0088a6ed  FUN_0088a6ed  215 bytes, 0 callers */

void FUN_0088a6ed(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  double dVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  CMFCDropDownToolbarButton *in_ECX;
  undefined1 local_c [4];
  int local_8;
  
  if (((*(int *)(in_ECX + 0x20) == 0) && (*(int *)(in_ECX + 0x70) != 0)) &&
     (iVar4 = FUN_007fde79(0), iVar4 != 0)) {
    CMFCDropDownToolbarButton::SetDefaultCommand(in_ECX,*(uint *)(iVar4 + 0x20));
  }
  uVar2 = *(undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(in_ECX + 0x80);
  *(undefined4 *)(in_ECX + 0xc) = 1;
  piVar5 = (int *)FUN_00881448(local_c,param_2,param_3,param_4);
  iVar3 = *piVar5;
  local_8 = piVar5[1];
  *(undefined4 *)(in_ECX + 0x34) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  iVar4 = 7;
  iVar6 = FUN_007c2511();
  if (*(int *)(iVar6 + 0x1e8) == 0) {
    dVar1 = 1.0;
  }
  else {
    dVar1 = *(double *)(iVar6 + 0x1e0);
  }
  if (dVar1 != 1.0) {
    FUN_007c2511();
    iVar4 = thunk_FUN_008d99f0();
  }
  if (DAT_00a127b4 == 0) {
    iVar4 = iVar4 / 2 + 1;
  }
  else {
    iVar4 = iVar4 + 2;
  }
  *param_1 = iVar3 + iVar4;
  param_1[1] = local_8;
  return;
}




/* vtable slots: CMFCDropDownToolbarButton[22] */
/* 0088a7c4  OnCancelMode  55 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCDropDownToolbarButton::OnCancelMode(void)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CMFCDropDownToolbarButton::OnCancelMode(CMFCDropDownToolbarButton *this)

{
  BOOL BVar1;
  
  if (*(int *)(this + 0x6c) != 0) {
    BVar1 = IsWindow(*(HWND *)(*(int *)(this + 0x6c) + 0x20));
    if (BVar1 != 0) {
      InvalidateRect(*(HWND *)(*(int *)(this + 0x6c) + 0x20),(RECT *)(this + 0x54),1);
      UpdateWindow(*(HWND *)(*(int *)(this + 0x6c) + 0x20));
    }
  }
  return;
}




/* vtable slots: CMFCDropDownToolbarButton[10] */
/* 0088a7fb  OnChangeParentWnd  35 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCDropDownToolbarButton::OnChangeParentWnd(class CWnd *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CMFCDropDownToolbarButton::OnChangeParentWnd(CMFCDropDownToolbarButton *this,CWnd *param_1)

{
  FUN_00881617(param_1);
  *(undefined4 *)(this + 8) = 0;
  Empty();
  *(undefined4 *)(this + 4) = 0;
  return;
}




/* vtable slots: CMFCDropDownToolbarButton[8] */
/* 0088a81e  FUN_0088a81e  242 bytes, 0 callers */

undefined4 FUN_0088a81e(undefined4 param_1,int param_2)

{
  code *pcVar1;
  UINT_PTR UVar2;
  CObject *pCVar3;
  CObject *pCVar4;
  int in_ECX;
  int iVar5;
  
  iVar5 = *(int *)(in_ECX + 0x6c);
  if (*(int *)(in_ECX + 0x7c) == 0) {
    if (iVar5 == 0) {
      DAT_00a13c38 = in_ECX;
      return 0;
    }
    UVar2 = SetTimer(*(HWND *)(iVar5 + 0x20),0xec11,DAT_00a00b98,FUN_0088b9ed);
    *(UINT_PTR *)(in_ECX + 0x7c) = UVar2;
    DAT_00a13c38 = in_ECX;
    return 0;
  }
  pCVar3 = (CObject *)0x0;
  if (iVar5 != 0) {
    KillTimer(*(HWND *)(iVar5 + 0x20),*(UINT_PTR *)(in_ECX + 0x7c));
    pCVar3 = *(CObject **)(in_ECX + 0x6c);
  }
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  DAT_00a13c38 = 0;
  pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCMenuBar_00a00b00,pCVar3);
  if (*(int *)(in_ECX + 0x78) == 0) {
    pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenuBar_00a00938,
                                *(CObject **)(in_ECX + 0x6c));
    if (((param_2 == 0) || (pCVar4 == (CObject *)0x0)) || (DAT_00a127ac != 0)) {
      FUN_0088a3aa(param_1);
    }
    iVar5 = in_ECX;
    if (pCVar3 == (CObject *)0x0) goto LAB_0088a8f1;
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 0x78) + 0x130) = 0;
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x78) + 0x60);
    guard_check_icall();
    (*pcVar1)();
    *(undefined4 *)(in_ECX + 0x78) = 0;
    if (pCVar3 == (CObject *)0x0) goto LAB_0088a8f1;
    iVar5 = 0;
  }
  FUN_00804f82(iVar5);
LAB_0088a8f1:
  if (*(int *)(in_ECX + 0x6c) != 0) {
    InvalidateRect(*(HWND *)(*(int *)(in_ECX + 0x6c) + 0x20),(RECT *)(in_ECX + 0x54),1);
  }
  return 0;
}




/* vtable slots: CMFCDropDownToolbarButton[9] */
/* 0088a910  FUN_0088a910  129 bytes, 0 callers */

undefined4 FUN_0088a910(void)

{
  code *pcVar1;
  CObject *pCVar2;
  undefined4 uVar3;
  int in_ECX;
  
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCMenuBar_00a00b00,
                              *(CObject **)(in_ECX + 0x6c));
  if (*(int *)(in_ECX + 0x7c) == 0) {
    if (*(int *)(in_ECX + 0x78) != 0) {
      *(undefined4 *)(*(int *)(in_ECX + 0x78) + 0x130) = 0;
      pcVar1 = *(code **)(**(int **)(in_ECX + 0x78) + 0x60);
      guard_check_icall();
      (*pcVar1)();
      *(undefined4 *)(in_ECX + 0x78) = 0;
      if (pCVar2 != (CObject *)0x0) {
        FUN_00804f82(0);
      }
    }
    uVar3 = 1;
  }
  else {
    if (*(int *)(in_ECX + 0x6c) != 0) {
      KillTimer(*(HWND *)(*(int *)(in_ECX + 0x6c) + 0x20),*(UINT_PTR *)(in_ECX + 0x7c));
    }
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    DAT_00a13c38 = 0;
    uVar3 = 0;
  }
  return uVar3;
}




/* vtable slots: CMFCDropDownToolbarButton[26] */
/* 0088abd0  OnCustomizeMenu  94 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCDropDownToolbarButton::OnCustomizeMenu(class CMenu *)
   
   Library: Visual Studio 2015 Release */

int __thiscall
CMFCDropDownToolbarButton::OnCustomizeMenu(CMFCDropDownToolbarButton *this,CMenu *param_1)

{
  EnableMenuItem(*(HMENU *)(param_1 + 4),0x4212,1);
  EnableMenuItem(*(HMENU *)(param_1 + 4),0x4213,1);
  EnableMenuItem(*(HMENU *)(param_1 + 4),0x4214,1);
  EnableMenuItem(*(HMENU *)(param_1 + 4),0x4211,1);
  EnableMenuItem(*(HMENU *)(param_1 + 4),0x420f,1);
  return 1;
}




/* vtable slots: CMFCDropDownToolbarButton[6] */
/* 0088acb5  FUN_0088acb5  1119 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0088acb5(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5
                 ,int param_6,int param_7,undefined4 param_8)

{
  double dVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  code *pcVar7;
  CMFCToolBarImages *this;
  uint uVar8;
  undefined1 local_68 [12];
  undefined8 local_5c;
  undefined4 local_54;
  undefined8 local_50;
  int local_48;
  int local_44;
  int *local_40;
  undefined4 *local_3c;
  int *local_38;
  int *local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  int local_28;
  undefined4 uStack_24;
  POINT local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_34 = param_1;
  local_3c = param_2;
  FUN_0088114d(param_1,param_2,param_6,0);
  iVar5 = 7;
  local_48 = 7;
  iVar4 = FUN_007c2511();
  if (*(int *)(iVar4 + 0x1e8) == 0) {
    dVar1 = 1.0;
  }
  else {
    dVar1 = *(double *)(iVar4 + 0x1e0);
  }
  if (dVar1 != 1.0) {
    FUN_007c2511();
    iVar5 = thunk_FUN_008d99f0();
    local_48 = iVar5;
  }
  piVar2 = local_40;
  if (DAT_00a127b4 == 0) {
    local_48 = iVar5 / 2 + 1;
  }
  else {
    iVar5 = iVar5 * 2;
  }
  local_30 = *param_2;
  uStack_2c = param_2[1];
  uStack_24 = param_2[3];
  local_28 = param_2[2] + (-1 - iVar5 / 2);
  local_44 = iVar5;
  if (local_40[0x1c] != 0) {
    local_38 = (int *)local_40[3];
    local_40[0x21] = 1;
    FUN_007fe0a1(&local_5c);
    iVar5 = FUN_007c2511();
    if (*(int *)(iVar5 + 0x1e8) == 0) {
      dVar1 = 1.0;
    }
    else {
      dVar1 = *(double *)(iVar5 + 0x1e0);
    }
    if (dVar1 == 1.0) {
      local_54 = local_5c._4_4_;
      local_50 = (double)CONCAT44((int)local_5c,(undefined4)local_50);
    }
    else {
      FUN_007c2511();
      local_50 = (double)(int)local_5c;
      uVar6 = thunk_FUN_008d99f0();
      local_5c = (double)local_5c._4_4_;
      local_50 = (double)CONCAT44(uVar6,(undefined4)local_50);
      local_54 = thunk_FUN_008d99f0();
    }
    if ((DAT_00a127b4 == 0) || (*(int *)(piVar2[0x1c] + 0x604) < 1)) {
      this = (CMFCToolBarImages *)(piVar2[0x1c] + 0x2b8);
    }
    else {
      this = (CMFCToolBarImages *)(piVar2[0x1c] + 0x600);
    }
    if (piVar2[0x22] == 0) {
      iVar5 = FUN_007c2511();
      CMFCToolBarImages::SetTransparentColor(this,*(ulong *)(iVar5 + 0x1c));
    }
    else {
      iVar5 = FUN_007c2511();
      CMFCToolBarImages::SetTransparentColor(DAT_00a127a0,*(ulong *)(iVar5 + 0x1c));
    }
    FUN_007eb6ca(local_68,local_50._4_4_,local_54,0);
    piVar2[0xd] = piVar2[0x20];
    piVar2[0xe] = piVar2[0x20];
    local_50 = (double)CONCAT44(piVar2[0x11],(undefined4)local_50);
    piVar2[3] = 1;
    piVar2[0x11] = 1;
    if (piVar2[0x22] == 0) {
      FUN_00881666(local_34,&local_30,this,param_4,param_5,param_6,0,param_8);
    }
    else {
      piVar2[1] = piVar2[0x22];
      FUN_00881666(local_34,local_3c,DAT_00a127a0,param_4,param_5,param_6,0,param_8);
      piVar2[1] = 0;
    }
    piVar2[0xd] = -1;
    piVar2[0xe] = -1;
    piVar2[0x11] = local_50._4_4_;
    piVar2[3] = (int)local_38;
    FUN_007e98b8(local_68);
    piVar2[0x21] = 0;
  }
  piVar3 = local_34;
  uVar8 = (uint)piVar2[9] >> 0x11 & 1;
  local_20.x = (local_3c[2] - local_44) + -1 + uVar8;
  local_18 = (local_3c[2] - local_48) + 1 + uVar8;
  local_20.y = (local_3c[3] - local_48) + 1 + uVar8;
  local_c = (local_3c[3] - local_44) + -1 + uVar8;
  pcVar7 = *(code **)(*local_34 + 0x24);
  local_14 = local_20.y;
  local_10 = local_18;
  guard_check_icall(8);
  local_44 = (*pcVar7)();
  if (local_44 != 0) {
    iVar5 = FUN_007c2511();
    iVar5 = FUN_0079efbc(iVar5 + 0xb0);
    local_50 = (double)CONCAT44(iVar5,(undefined4)local_50);
    if (iVar5 != 0) {
      Polygon((HDC)piVar3[1],&local_20,3);
      piVar2 = local_40;
      if (param_5 == 0) {
        pcVar7 = *(code **)(*local_40 + 0x54);
        guard_check_icall();
        iVar5 = (*pcVar7)();
        if ((iVar5 != 0) && (param_7 != 0)) {
          if ((piVar2[0x1e] == 0) && (uVar8 = piVar2[9], (uVar8 & 0x30000) == 0)) {
            if ((param_6 == 0) || ((uVar8 & 0x150000) != 0)) goto LAB_0088b0e9;
            if ((uVar8 & 0x20000) == 0) {
              local_38 = (int *)FUN_007c2574();
              pcVar7 = *(code **)(*local_38 + 0x88);
              guard_check_icall(local_34,local_40,*local_3c,local_3c[1],local_3c[2],local_3c[3],2);
            }
            else {
              local_38 = (int *)FUN_007c2574();
              pcVar7 = *(code **)(*local_38 + 0x88);
              guard_check_icall(local_34,local_40,*local_3c,local_3c[1],local_3c[2],local_3c[3],1);
            }
          }
          else if ((piVar2[8] == 0) || (piVar2[8] == -1)) {
            local_38 = (int *)FUN_007c2574();
            pcVar7 = *(code **)(*local_38 + 0x88);
            guard_check_icall(local_34,local_40,*local_3c,local_3c[1],local_3c[2],local_3c[3],2);
          }
          else {
            local_38 = (int *)FUN_007c2574();
            pcVar7 = *(code **)(*local_38 + 0x88);
            guard_check_icall(local_34,local_40,*local_3c,local_3c[1],local_3c[2],local_3c[3],1);
          }
          (*pcVar7)();
        }
      }
LAB_0088b0e9:
      FUN_0079efbc(local_44);
      FUN_0079efbc(local_50._4_4_);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCDropDownToolbarButton[27] */
/* 0088b115  FUN_0088b115  97 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_0088b115(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  CSimpleStringT<wchar_t,0> *this;
  undefined4 uVar1;
  int in_ECX;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x88b121;
  this = (CSimpleStringT<wchar_t,0> *)(in_ECX + 0x2c);
  local_14[0] = FUN_004054a0(*(int *)this + -0x10);
  local_14[0] = local_14[0] + 0x10;
  local_8 = 0;
  ATL::CSimpleStringT<wchar_t,0>::operator=(this,(CSimpleStringT<wchar_t,0> *)(in_ECX + 0x74));
  uVar1 = FUN_008822bb(param_1,param_2,param_3);
  ATL::CSimpleStringT<wchar_t,0>::operator=(this,(CSimpleStringT<wchar_t,0> *)local_14);
  FUN_00406b10();
  return uVar1;
}




/* vtable slots: CMFCDropDownToolbarButton[2] */
/* 0088b89c  FUN_0088b89c  195 bytes, 0 callers */

void FUN_0088b89c(CArchive *param_1)

{
  undefined4 *puVar1;
  long lVar2;
  CObject *pCVar3;
  CWnd *pCVar4;
  CMFCDropDownToolbarButton *in_ECX;
  undefined4 *puVar5;
  long local_8;
  
  FUN_008829ae(param_1);
  lVar2 = 0;
  local_8 = 0;
  if (((byte)param_1[0x18] & 1) == 0) {
    if (*(int *)(in_ECX + 0x70) != 0) {
      lVar2 = *(long *)(*(int *)(in_ECX + 0x70) + 0xd18);
    }
    CArchive::operator<<(param_1,lVar2);
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0x74));
    CArchive::operator<<(param_1,*(long *)(in_ECX + 0x80));
  }
  else {
    *(undefined4 *)(in_ECX + 0x70) = 0;
    CArchive::operator>>(param_1,&local_8);
    FUN_0047fc90(in_ECX + 0x74);
    CArchive::operator>>(param_1,(long *)(in_ECX + 0x80));
    puVar5 = DAT_00a127ec;
    do {
      if (puVar5 == (undefined4 *)0x0) goto LAB_0088b91f;
      puVar1 = puVar5 + 2;
      puVar5 = (undefined4 *)*puVar5;
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCDropDownToolBar_00a00b44,
                                  (CObject *)*puVar1);
    } while (((pCVar3 == (CObject *)0x0) ||
             (pCVar4 = CWnd::FromHandlePermanent(*(HWND__ **)(pCVar3 + 0x20)), pCVar4 == (CWnd *)0x0
             )) || (*(int *)(pCVar3 + 0xd18) != local_8));
    *(CObject **)(in_ECX + 0x70) = pCVar3;
LAB_0088b91f:
    CMFCDropDownToolbarButton::SetDefaultCommand(in_ECX,*(uint *)(in_ECX + 0x20));
  }
  return;
}



