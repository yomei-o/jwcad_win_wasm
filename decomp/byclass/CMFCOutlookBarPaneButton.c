/* CMFCOutlookBarPaneButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCOutlookBarPaneButton[1] */
/* 008746ae  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCOutlookBarPaneButton::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCOutlookBarPaneButton::_scalar_deleting_destructor_(CMFCOutlookBarPaneButton *this,uint param_1)

{
  *(undefined ***)this = vftable;
  CMFCToolBarButton::~CMFCToolBarButton((CMFCToolBarButton *)this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x80);
    }
  }
  return this;
}




/* vtable slots: CMFCOutlookBarPaneButton[4] */
/* 008746e7  FUN_008746e7  20 bytes, 0 callers */

void FUN_008746e7(void)

{
  FUN_0079d98a(&PTR_s_CMFCOutlookBarPane_00a006a0);
  return;
}




/* vtable slots: CMFCOutlookBarPaneButton[0] */
/* 008746fb  FUN_008746fb  6 bytes, 0 callers */

undefined ** FUN_008746fb(void)

{
  return &PTR_s_CMFCOutlookBarPaneButton_00a009f8;
}




/* vtable slots: CMFCOutlookBarPaneButton[7] */
/* 00874701  FUN_00874701  388 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_00874701(int *param_1,undefined4 param_2,int *param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined1 local_30 [4];
  int local_2c;
  int *local_28;
  undefined1 local_24 [4];
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_28 = param_1;
  local_20 = param_2;
  if (param_4 == 0) {
    CStringT<>(&DAT_0096c008);
    piVar1 = (int *)FUN_00566800(local_30,&local_1c);
    iVar2 = *piVar1;
    FUN_00406b10();
    iVar4 = 0;
    local_18 = 0;
    local_14 = 0;
    local_c = 1;
    iVar3 = *param_3;
    local_10 = iVar3 - iVar2;
    if (*(int *)(in_ECX + 0x18) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_007c2378(in_ECX + 0x2c,&local_18,0x410);
      iVar3 = *param_3;
      iVar4 = local_18;
    }
    local_10 = local_10 - iVar4;
    iVar6 = iVar2 + 10 + param_3[1];
    iVar2 = iVar3;
    if (local_10 <= iVar3) {
      iVar2 = local_10;
    }
    iVar4 = *(int *)(in_ECX + 0x74) + 4;
    if ((iVar4 <= iVar2) && (iVar4 = iVar3, local_10 <= iVar3)) {
      iVar4 = local_10;
    }
    uVar5 = (uint)(local_10 <= iVar3);
  }
  else {
    local_10 = 0;
    local_18 = 0;
    local_14 = 0;
    local_c = param_3[1];
    iVar4 = 0;
    iVar2 = local_c;
    if (*(int *)(in_ECX + 0x18) != 0) {
      local_1c = in_ECX + 0x2c;
      local_2c = in_ECX;
      do {
        iVar2 = local_1c;
        local_10 = local_10 + 1;
        iVar3 = FUN_007c2378(local_1c,&local_18,0x410);
        iVar6 = FUN_00566800(local_24,iVar2);
        iVar2 = param_3[1];
        iVar4 = local_18;
        in_ECX = local_2c;
        if (*(int *)(iVar6 + 4) <= iVar3) break;
      } while (iVar2 < local_c - local_14);
    }
    local_c = local_c - local_14;
    iVar4 = (*param_3 - iVar4) + 10 + local_10;
    iVar3 = iVar2;
    if (local_c <= iVar2) {
      iVar3 = local_c;
    }
    iVar6 = *(int *)(in_ECX + 0x78);
    if ((*(int *)(in_ECX + 0x78) <= iVar3) && (iVar6 = iVar2, local_c <= iVar2)) {
      iVar6 = local_c;
    }
    uVar5 = 1;
  }
  *(uint *)(in_ECX + 0x7c) = uVar5;
  *local_28 = iVar4;
  local_28[1] = iVar6;
  return local_28;
}




/* vtable slots: CMFCOutlookBarPaneButton[10] */
/* 00874885  OnChangeParentWnd  37 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCOutlookBarPaneButton::OnChangeParentWnd(class CWnd *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

void __thiscall
CMFCOutlookBarPaneButton::OnChangeParentWnd(CMFCOutlookBarPaneButton *this,CWnd *param_1)

{
  CObject *pCVar1;
  
  FUN_00881617(param_1);
  pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCOutlookBarPane_00a006a0,(CObject *)param_1
                             );
  *(CObject **)(this + 0x70) = pCVar1;
  return;
}




/* vtable slots: CMFCOutlookBarPaneButton[6] */
/* 008748aa  FUN_008748aa  1248 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008748aa(CDC *param_1,int *param_2,code *param_3,int param_4,int param_5,int param_6)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  int iVar6;
  CDC *pCVar7;
  int local_84;
  int local_80;
  int local_6c;
  int *local_68;
  int local_64;
  code *local_60;
  int local_5c;
  CDC *local_58;
  int local_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x74;
  local_8 = 0x8748b6;
  local_84 = 0;
  local_80 = 0;
  local_60 = param_3;
  local_58 = param_1;
  if (((param_5 == 0) && (param_6 != 0)) && ((*(uint *)(in_ECX + 0x24) & 0x20000) != 0)) {
    local_84 = 1;
    local_80 = 1;
  }
  local_34.left = *param_2;
  local_34.top = param_2[1];
  local_34.right = param_2[2];
  local_34.bottom = param_2[3];
  local_24.left = *param_2;
  local_24.top = param_2[1];
  local_24.right = param_2[2];
  local_24.bottom = param_2[3];
  local_5c = in_ECX;
  if (*(int *)(in_ECX + 0x48) != 0) {
    piVar2 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar2 + 0x140);
    guard_check_icall(&local_6c);
    (*pcVar1)();
    if ((local_6c != 0) || (local_68 != (int *)0x0)) {
      InflateRect(&local_34,~(local_6c / 2),~((int)local_68 / 2));
      if (param_4 == 0) {
        iVar4 = 0;
        piVar2 = local_68;
      }
      else {
        piVar2 = (int *)0x0;
        iVar4 = local_6c;
      }
      OffsetRect(&local_24,iVar4,(int)piVar2);
    }
  }
  iVar4 = local_24.top + 5;
  local_44.left = local_34.left;
  local_44.top = local_34.top;
  local_44.right = local_34.right;
  local_44.bottom = local_34.bottom;
  if (local_60 == (code *)0x0) {
LAB_00874bdb:
    iVar3 = local_5c;
    local_24.top = iVar4;
    if ((param_6 == 0) || (*(int *)(*(int *)(local_5c + 0x70) + 0x1dd4) == 0)) goto LAB_00874b67;
    if (param_5 == 0) {
      CDrawingManager::CDrawingManager((CDrawingManager *)&local_6c,local_58);
      local_8 = 1;
      FUN_00818045(local_44.left,local_44.top,local_44.right,local_44.bottom,0x55,0xffffffff,0,
                   0xffffffff);
      local_8 = 0xffffffff;
      FUN_0081510b();
      iVar3 = local_5c;
      goto LAB_00874b84;
    }
  }
  else {
    if (*(int *)(local_5c + 4) == 0) {
      iVar3 = *(int *)(local_5c + 0x34);
    }
    else {
      iVar3 = *(int *)(local_5c + 0x38);
    }
    if (iVar3 < 0) goto LAB_00874bdb;
    iVar3 = *(int *)(local_60 + 0x54);
    local_68 = *(int **)(local_60 + 0x58);
    if (param_4 == 0) {
      iVar6 = local_34.top + 5;
      local_64 = local_34.left + ((local_34.right - local_34.left) - iVar3) / 2;
      local_24.top = local_24.top + 7 + (int)local_68;
    }
    else {
      local_64 = local_34.left + 5;
      local_54 = local_24.left + iVar3 + 10;
      iVar6 = (local_34.bottom + (-(int)local_68 - local_34.top)) / 2 + local_34.top;
      iStack_4c = local_24.right;
      iStack_48 = local_24.bottom;
      iStack_50 = iVar4;
      local_24.left = local_54;
      local_24.top = iVar4;
      iVar4 = FUN_007c2378(local_5c + 0x2c,&local_54,0x410);
      local_24.top = (local_34.bottom + (-iVar4 - local_34.top)) / 2 + local_34.top;
    }
    local_6c = iVar3 + local_64;
    local_68 = (int *)((int)local_68 + iVar6);
    local_44.left = local_64;
    local_44.top = iVar6;
    local_44.right = local_6c;
    local_44.bottom = (LONG)local_68;
    InflateRect(&local_44,2,2);
    if (*(int *)(*(int *)(local_5c + 0x70) + 0x1dd4) == 0) {
      if (*(int *)(local_5c + 0x48) != 0) {
        piVar2 = (int *)FUN_007c2574();
        pcVar1 = *(code **)(*piVar2 + 0x140);
        guard_check_icall(&local_6c);
        (*pcVar1)();
        if ((local_6c != 0) || (local_68 != (int *)0x0)) {
          InflateRect(&local_44,local_6c / 2 + -1,(int)local_68 / 2 + -1);
        }
      }
      pCVar7 = local_58;
      iVar3 = local_5c;
      FUN_0088114d(local_58,&local_44,param_6,0);
    }
    else {
      iVar3 = local_5c;
      pCVar7 = local_58;
      if ((param_6 != 0) && (param_5 == 0)) {
        CDrawingManager::CDrawingManager((CDrawingManager *)&local_6c,local_58);
        local_8 = 0;
        FUN_00818045(local_44.left,local_44.top,local_44.right,local_44.bottom,0x55,0xffffffff,0,
                     0xffffffff);
        local_8 = 0xffffffff;
        FUN_0081510b();
        iVar3 = local_5c;
        pCVar7 = local_58;
      }
    }
    if (*(int *)(iVar3 + 4) == 0) {
      uVar5 = *(undefined4 *)(iVar3 + 0x34);
    }
    else {
      uVar5 = *(undefined4 *)(iVar3 + 0x38);
    }
    FUN_007e8cae(pCVar7,local_84 + local_64,iVar6 + local_80,uVar5,0,
                 *(uint *)(iVar3 + 0x24) & 0x40000,0,0,0,0xff);
LAB_00874b67:
    if ((param_5 == 0) && ((param_6 != 0 || ((*(uint *)(iVar3 + 0x24) & 0x30000) != 0)))) {
LAB_00874b84:
      if ((((*(uint *)(iVar3 + 0x24) & 0x20000) == 0) || (param_6 == 0)) &&
         ((*(uint *)(iVar3 + 0x24) & 0x10000) == 0)) {
        local_68 = (int *)FUN_007c2574();
        iVar3 = local_5c;
        local_60 = *(code **)(*local_68 + 0x88);
        guard_check_icall(local_58,local_5c,local_44.left,local_44.top,local_44.right,
                          local_44.bottom,2);
        (*local_60)();
      }
      else {
        local_68 = (int *)FUN_007c2574();
        iVar3 = local_5c;
        local_60 = *(code **)(*local_68 + 0x88);
        guard_check_icall(local_58,local_5c,local_44.left,local_44.top,local_44.right,
                          local_44.bottom,1);
        (*local_60)();
      }
    }
  }
  if ((*(int *)(iVar3 + 0x18) == 0) ||
     (local_60 = (code *)(iVar3 + 0x2c), *(int *)(*(int *)local_60 + -0xc) == 0)) goto LAB_00874d82;
  local_64 = 0;
  if (param_6 == 0) {
    if ((*(uint *)(iVar3 + 0x24) & 0x30000) != 0) {
      local_64 = 1;
    }
  }
  else {
    local_64 = 2;
  }
  if ((*(uint *)(iVar3 + 0x24) & 0x40000) == 0) {
    iVar4 = *(int *)(*(int *)(iVar3 + 0x70) + 0xd40);
LAB_00874cd0:
    if (iVar4 == -1) goto LAB_00874cd5;
  }
  else {
    if (*(int *)(*(int *)(iVar3 + 0x70) + 0xd54) != 0) {
      iVar4 = FUN_007c2511();
      iVar4 = *(int *)(iVar4 + 0x38);
      goto LAB_00874cd0;
    }
LAB_00874cd5:
    if (*(int *)(*(int *)(iVar3 + 0x70) + 0xd54) == 0) {
      piVar2 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar2 + 0xb4);
      guard_check_icall(local_5c,local_64);
      iVar4 = (*pcVar1)();
    }
    else {
      iVar4 = FUN_007c2511();
      iVar4 = *(int *)(iVar4 + 0x70);
    }
  }
  pCVar7 = local_58;
  pcVar1 = *(code **)(*(int *)local_58 + 0x30);
  guard_check_icall(iVar4);
  (*pcVar1)();
  if (*(int *)(local_5c + 0x7c) == 0) {
    iVar4 = FUN_004054a0(*(int *)local_60 + -0x10);
    local_68 = (int *)(iVar4 + 0x10);
    pcVar1 = *(code **)(*(int *)pCVar7 + 0x68);
    local_8 = 2;
    guard_check_icall(local_68,*(undefined4 *)(iVar4 + 4),&local_24,0x8010);
    (*pcVar1)();
    FUN_00406b10();
  }
  else {
    FUN_007c2378(local_60,&local_24,0x11);
  }
LAB_00874d82:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCOutlookBarPaneButton[48] */
/* 00874d8a  FUN_00874d8a  13 bytes, 0 callers */

void FUN_00874d8a(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x34) = param_1;
  return;
}




/* vtable slots: CMFCOutlookBarPaneButton[5], CMFCToolBarButton[5], CMFCToolBarColorButton[5], CTasksPaneNavigateButton[5] */
/* 00880ee9  FUN_00880ee9  135 bytes, 6 callers */

void FUN_00880ee9(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  in_ECX[8] = *(int *)(param_1 + 0x20);
  in_ECX[0xf] = *(int *)(param_1 + 0x3c);
  in_ECX[1] = *(int *)(param_1 + 4);
  in_ECX[9] = *(int *)(param_1 + 0x24);
  pcVar1 = *(code **)(*in_ECX + 0xc0);
  if (*(int *)(param_1 + 4) == 0) {
    uVar3 = *(undefined4 *)(param_1 + 0x34);
  }
  else {
    uVar3 = *(undefined4 *)(param_1 + 0x38);
  }
  guard_check_icall(uVar3);
  (*pcVar1)();
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0xb),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x2c));
  in_ECX[2] = *(int *)(param_1 + 8);
  in_ECX[3] = *(int *)(param_1 + 0xc);
  in_ECX[4] = *(int *)(param_1 + 0x10);
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0xc),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x30));
  in_ECX[0x14] = *(int *)(param_1 + 0x50);
  iVar2 = *(int *)(param_1 + 0x28);
  in_ECX[7] = 0;
  in_ECX[10] = iVar2;
  return;
}




/* vtable slots: CMFCOutlookBarPaneButton[27], CMFCToolBarButton[27], CMFCToolBarColorButton[27], CMFCToolBarMenuButtonsButton[27], CTasksPaneNavigateButton[27] */
/* 008822bb  FUN_008822bb  1114 bytes, 4 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_008822bb(int *param_1,int *param_2,int param_3)

{
  double dVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar5;
  int in_ECX;
  code *pcVar6;
  int iVar7;
  int iVar8;
  int local_6c;
  int local_64;
  int local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  code *local_54;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int *local_3c;
  int *local_38;
  code *local_34;
  int local_30;
  int *local_2c;
  int local_28;
  int iStack_24;
  int local_20;
  int iStack_1c;
  int local_18;
  int local_14;
  int local_10;
  int iStack_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_34 = (code *)&DAT_00a12880;
  local_2c = param_1;
  local_5c = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 8) = 0;
  local_3c = param_2;
  if (*(int *)(in_ECX + 4) == 0) {
    if (DAT_00a12ab4 == DAT_00a12884) {
      local_34 = (code *)&DAT_00a12ab0;
    }
  }
  else {
    local_34 = DAT_00a127a0;
  }
  local_4c = 0;
  local_30 = in_ECX;
  if ((DAT_00a13bac != 0) && (*(int *)(in_ECX + 4) == 0)) {
    local_4c = FUN_008524f8(*(undefined4 *)(in_ECX + 0x20));
  }
  FUN_007fe1cf(&local_48);
  local_6c = *param_2;
  local_40 = local_48 + 6;
  iVar8 = param_2[1];
  local_64 = param_2[2];
  local_60 = param_2[3];
  if (param_3 != 0) {
    piVar3 = (int *)FUN_007c2574();
    pcVar2 = *(code **)(*piVar3 + 0x98);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if (iVar4 == 0) {
      if (*(int *)(local_30 + 4) == 0) {
        iVar4 = *(int *)(local_30 + 0x34);
      }
      else {
        iVar4 = *(int *)(local_30 + 0x38);
      }
      if ((-1 < iVar4) && (local_34 != (code *)0x0)) {
        local_6c = local_6c + local_40;
        local_18 = *local_3c;
        local_14 = local_3c[1];
        iStack_c = local_3c[3];
        local_10 = local_6c;
        local_38 = (int *)FUN_007c2574();
        pcVar2 = *(code **)(*local_38 + 0x84);
        guard_check_icall(local_2c,local_30,local_18,local_14,local_10,iStack_c,2);
        (*pcVar2)();
        local_38 = (int *)FUN_007c2574();
        pcVar2 = *(code **)(*local_38 + 0x88);
        guard_check_icall(local_2c,local_30,local_18,local_14,local_10,iStack_c,2);
        (*pcVar2)();
      }
    }
  }
  local_38 = (int *)FUN_007c2574();
  local_54 = *(code **)(*local_38 + 0x138);
  guard_check_icall(local_2c,local_6c,iVar8,local_64,local_60,param_3);
  local_60 = (*local_54)();
  piVar3 = local_2c;
  iVar8 = local_30;
  pcVar2 = local_34;
  iStack_24 = local_3c[1];
  local_20 = local_3c[2];
  iStack_1c = local_3c[3];
  local_28 = *local_3c + 10 + local_48;
  if (*(int *)(local_30 + 4) == 0) {
    iVar4 = *(int *)(local_30 + 0x34);
  }
  else {
    iVar4 = *(int *)(local_30 + 0x38);
  }
  if ((iVar4 < 0) || (local_34 == (code *)0x0)) goto LAB_00882669;
  if (local_4c != 0) {
    local_18 = *local_3c;
    local_14 = local_3c[1];
    iStack_c = local_3c[3];
    local_10 = local_18 + local_40;
    FUN_00880677(local_2c,&local_18);
    iVar8 = local_30;
    goto LAB_00882669;
  }
  if ((param_3 == 0) && (iVar4 = FUN_007c2574(), *(int *)(iVar4 + 0x5c) != 0)) {
    local_30 = 1;
LAB_008824c8:
    local_38 = (int *)0x0;
  }
  else {
    local_30 = 0;
    if ((param_3 == 0) || (iVar4 = FUN_007c2574(), *(int *)(iVar4 + 0x54) == 0)) goto LAB_008824c8;
    this = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar4 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
    if (iVar4 != 0) goto LAB_008824c8;
    local_38 = (int *)0x1;
  }
  local_4c = 0;
  local_34 = (code *)0x0;
  iVar4 = FUN_007c2511();
  if (*(int *)(iVar4 + 0x1e8) == 0) {
    dVar1 = 1.0;
  }
  else {
    dVar1 = *(double *)(iVar4 + 0x1e0);
  }
  iVar4 = local_48;
  pcVar6 = (code *)local_44;
  if (((dVar1 == 1.0) || (DAT_00a12790 != 0)) &&
     ((*(int *)(iVar8 + 4) == 0 ||
      ((local_48 == *(int *)(pcVar2 + 0x54) && (local_44 == *(int *)(pcVar2 + 0x58))))))) {
    iVar4 = local_4c;
    pcVar6 = local_34;
  }
  FUN_007eb6ca(&local_14,iVar4,pcVar6,local_30);
  local_34 = (code *)(*local_3c + 3);
  local_3c = (int *)(local_3c[1] + 3);
  iVar4 = FUN_007c2511();
  if (*(int *)(iVar4 + 0x1e8) == 0) {
    dVar1 = 1.0;
  }
  else {
    dVar1 = *(double *)(iVar4 + 0x1e0);
  }
  piVar3 = local_3c;
  pcVar6 = local_34;
  if ((dVar1 != 1.0) && (DAT_00a12790 != 0)) {
    iVar4 = (local_48 - *(int *)(pcVar2 + 0x54)) / 2;
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    local_54 = *(code **)(pcVar2 + 0x58);
    if ((local_44 - (int)local_54) / 2 < 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = (local_44 - (int)local_54) / 2;
    }
    piVar3 = (int *)((int)local_3c + iVar7);
    pcVar6 = local_34 + iVar4;
  }
  if (local_38 != (int *)0x0) {
    local_54 = pcVar6 + 1;
    local_38 = (int *)((int)piVar3 + 1);
    if (*(int *)(iVar8 + 4) == 0) {
      uVar5 = *(undefined4 *)(iVar8 + 0x34);
    }
    else {
      uVar5 = *(undefined4 *)(iVar8 + 0x38);
    }
    FUN_007e8cae(local_2c,local_54,local_38,uVar5,0,0,0,1,0,0xff);
    pcVar6 = local_54 + -2;
    piVar3 = (int *)((int)local_38 + -2);
  }
  if (*(int *)(iVar8 + 4) == 0) {
    uVar5 = *(undefined4 *)(iVar8 + 0x34);
  }
  else {
    uVar5 = *(undefined4 *)(iVar8 + 0x38);
  }
  FUN_007e8cae(local_2c,pcVar6,piVar3,uVar5,0,0,0,0,local_30,0xff);
  FUN_007e98b8(&local_14);
  piVar3 = local_2c;
LAB_00882669:
  if (*(int *)(*(int *)(iVar8 + 0x2c) + -0xc) != 0) {
    pcVar2 = *(code **)(*piVar3 + 0x30);
    guard_check_icall(local_60);
    uVar5 = (*pcVar2)();
    FUN_0079f0b8(1);
    FUN_007c2378(iVar8 + 0x2c,&local_28,0x24);
    pcVar2 = *(code **)(*local_2c + 0x30);
    guard_check_icall(uVar5);
    (*pcVar2)();
    iVar4 = local_20 - local_28;
    piVar3 = (int *)FUN_00566800(&local_64,iVar8 + 0x2c);
    if (iVar4 < *piVar3) {
      local_20 = local_20 - local_28;
    }
    else {
      piVar3 = (int *)FUN_00566800(local_58,iVar8 + 0x2c);
      local_20 = *piVar3;
    }
    local_40 = local_40 + local_20;
  }
  *(undefined4 *)(iVar8 + 8) = local_5c;
  return local_40;
}




/* vtable slots: CMFCOutlookBarPaneButton[2], CMFCToolBarButton[2], CMFCToolBarColorButton[2], CTasksPaneNavigateButton[2] */
/* 008829ae  FUN_008829ae  247 bytes, 5 callers */

void FUN_008829ae(CArchive *param_1)

{
  long *plVar1;
  code *pcVar2;
  int iVar3;
  int *in_ECX;
  int *local_8;
  
  plVar1 = in_ECX + 1;
  if (((byte)param_1[0x18] & 1) == 0) {
    CArchive::operator<<(param_1,in_ECX[8]);
    CArchive::operator<<(param_1,in_ECX[9]);
    if (*plVar1 == 0) {
      iVar3 = in_ECX[0xd];
    }
    else {
      iVar3 = in_ECX[0xe];
    }
    CArchive::operator<<(param_1,iVar3);
    CArchive::operator<<<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_>
              (param_1,(CStringT<wchar_t,StrTraitMFC<wchar_t,ATL::ChTraitsCRT<wchar_t>_>_> *)
                       (in_ECX + 0xb));
    CArchive::operator<<(param_1,*plVar1);
    CArchive::operator<<(param_1,in_ECX[7]);
    CArchive::operator<<(param_1,in_ECX[2]);
    CArchive::operator<<(param_1,in_ECX[3]);
    CArchive::operator<<(param_1,in_ECX[0x14]);
  }
  else {
    local_8 = in_ECX;
    CArchive::operator>>(param_1,in_ECX + 8);
    CArchive::operator>>(param_1,in_ECX + 9);
    CArchive::operator>>(param_1,(long *)&local_8);
    FUN_0047fc90(in_ECX + 0xb);
    CArchive::operator>>(param_1,plVar1);
    CArchive::operator>>(param_1,in_ECX + 7);
    CArchive::operator>>(param_1,in_ECX + 2);
    CArchive::operator>>(param_1,in_ECX + 3);
    CArchive::operator>>(param_1,in_ECX + 0x14);
    pcVar2 = *(code **)(*in_ECX + 0xc0);
    guard_check_icall(local_8);
    (*pcVar2)();
  }
  return;
}



