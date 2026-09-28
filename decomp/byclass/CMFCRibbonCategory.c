/* CMFCRibbonCategory -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonCategory[1] */
/* 00871777  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonCategory::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonCategory::_scalar_deleting_destructor_(CMFCRibbonCategory *this,uint param_1)

{
  FUN_0087160e();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x7c8);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonCategory[53] */
/* 00871a66  FUN_00871a66  512 bytes, 0 callers */

void FUN_00871a66(int param_1)

{
  undefined4 *puVar1;
  code *pcVar2;
  int *piVar3;
  int in_ECX;
  int local_c;
  
  ATL::CSimpleStringT<wchar_t,0>::operator=
            ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x8c),
             (CSimpleStringT<wchar_t,0> *)(param_1 + 0x8c));
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x68);
  local_c = 0;
  if (0 < *(int *)(param_1 + 0x564)) {
    do {
      piVar3 = (int *)FUN_00799cf8(local_c);
      puVar1 = (undefined4 *)*piVar3;
      pcVar2 = *(code **)*puVar1;
      guard_check_icall();
      (*pcVar2)();
      piVar3 = (int *)FUN_0079d90c();
      pcVar2 = *(code **)(*piVar3 + 0xb0);
      guard_check_icall(puVar1);
      (*pcVar2)();
      pcVar2 = *(code **)(piVar3[0xb8] + 0x168);
      guard_check_icall(puVar1 + 0xb8);
      (*pcVar2)();
      pcVar2 = *(code **)(piVar3[0xb8] + 0x170);
      guard_check_icall(puVar1 + 0xb8);
      (*pcVar2)();
      FUN_0079c90d(*(undefined4 *)(in_ECX + 0x564),piVar3);
      local_c = local_c + 1;
    } while (local_c < *(int *)(param_1 + 0x564));
  }
  *(undefined4 *)(in_ECX + 0x53c) = *(undefined4 *)(param_1 + 0x53c);
  *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(param_1 + 0x88);
  pcVar2 = *(code **)(*(int *)(in_ECX + 0x90) + 0x168);
  guard_check_icall(param_1 + 0x90);
  (*pcVar2)();
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(in_ECX + 0x540) = *(undefined4 *)(param_1 + 0x540);
  FUN_007e8118(in_ECX + 0x578);
  FUN_007e8118(in_ECX + 0x690);
  FUN_0042fb40(0,0xffffffff);
  CArray<int,int>::Copy((CArray<int,int> *)(in_ECX + 0x548),(CArray<int,int> *)(param_1 + 0x548));
  pcVar2 = *(code **)(*(int *)(in_ECX + 0x1a8) + 0x168);
  guard_check_icall(param_1 + 0x1a8);
  (*pcVar2)();
  *(int *)(in_ECX + 0x230) = in_ECX;
  pcVar2 = *(code **)(*(int *)(in_ECX + 0x370) + 0x168);
  guard_check_icall(param_1 + 0x370);
  (*pcVar2)();
  *(int *)(in_ECX + 0x3f8) = in_ECX;
  *(undefined4 *)(in_ECX + 0x7bc) = *(undefined4 *)(param_1 + 0x7bc);
  *(undefined4 *)(in_ECX + 0x7c0) = *(undefined4 *)(param_1 + 0x7c0);
  return;
}




/* vtable slots: CMFCRibbonCategory[41] */
/* 00872546  FUN_00872546  7 bytes, 0 callers */

undefined4 FUN_00872546(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x53c);
}




/* vtable slots: CMFCRibbonCategory[0] */
/* 0087254d  FUN_0087254d  6 bytes, 0 callers */

undefined ** FUN_0087254d(void)

{
  return &PTR_s_CMFCRibbonCategory_009992fc;
}




/* vtable slots: CMFCRibbonCategory[51] */
/* 008727c9  FUN_008727c9  106 bytes, 0 callers */

undefined4 FUN_008727c9(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x564)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0xfc);
      guard_check_icall(param_1,param_2,param_3,param_4);
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x564));
  }
  return 0;
}




/* vtable slots: CMFCRibbonCategory[46] */
/* 008728da  OnCancelMode  50 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonCategory::OnCancelMode(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCRibbonCategory::OnCancelMode(CMFCRibbonCategory *this)

{
  int iVar1;
  
  iVar1 = 0;
  *(undefined4 *)(this + 0x60) = 0;
  if (0 < *(int *)(this + 0x564)) {
    do {
      FUN_00799cf8(iVar1);
      FUN_0086a411();
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(this + 0x564));
  }
  return;
}




/* vtable slots: CMFCRibbonCategory[45] */
/* 00872929  FUN_00872929  411 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00872929(undefined4 param_1)

{
  RECT *lprc;
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  HRGN pHVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined **local_3c;
  undefined4 local_38;
  int *local_34;
  code *local_30;
  int local_2c;
  undefined4 local_28;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x30;
  local_8 = 0x872935;
  lprc = (RECT *)(in_ECX + 0x7c);
  local_28 = param_1;
  local_2c = in_ECX;
  BVar3 = IsRectEmpty(lprc);
  if (BVar3 != 0) goto LAB_00872abc;
  local_34 = (int *)FUN_007c2574();
  iVar2 = local_2c;
  local_30 = *(code **)(*local_34 + 0x214);
  guard_check_icall(local_28,local_2c,lprc->left,*(undefined4 *)(in_ECX + 0x80),
                    *(undefined4 *)(in_ECX + 0x84),*(undefined4 *)(in_ECX + 0x88));
  (*local_30)();
  local_3c = CRgn::vftable;
  local_34 = (int *)0x0;
  local_38 = 0;
  local_8 = 0;
  local_24.left = *(LONG *)(iVar2 + 0x21c);
  local_24.top = *(LONG *)(iVar2 + 0x220);
  local_24.right = *(LONG *)(iVar2 + 0x224);
  local_24.bottom = *(LONG *)(iVar2 + 0x228);
  BVar3 = IsRectEmpty(&local_24);
  if (BVar3 == 0) {
LAB_008729d1:
    local_24.left = lprc->left + 2;
    local_24.top = *(int *)(in_ECX + 0x80) + 3;
    local_24.right = *(int *)(in_ECX + 0x84) + -2;
    local_24.bottom = *(int *)(in_ECX + 0x88) + -4;
    pHVar4 = CreateRectRgnIndirect(&local_24);
    Attach(pHVar4);
    FUN_0079eeb5(&local_3c);
    local_34 = (int *)0x1;
  }
  else {
    local_24.left = *(int *)(local_2c + 0x3e4);
    local_24.top = *(int *)(local_2c + 1000);
    local_24.right = *(int *)(local_2c + 0x3ec);
    local_24.bottom = *(int *)(local_2c + 0x3f0);
    BVar3 = IsRectEmpty(&local_24);
    if (BVar3 == 0) goto LAB_008729d1;
  }
  local_30 = (code *)0x0;
  if (0 < *(int *)(local_2c + 0x564)) {
    do {
      puVar5 = (undefined4 *)FUN_00799cf8(local_30);
      pcVar1 = *(code **)(*(int *)*puVar5 + 0xe8);
      guard_check_icall(local_28);
      (*pcVar1)();
      local_30 = (code *)((int)local_30 + 1);
    } while ((int)local_30 < *(int *)(local_2c + 0x564));
  }
  iVar2 = local_2c;
  if (local_34 != (int *)0x0) {
    FUN_0079eeb5(0);
  }
  pcVar1 = *(code **)(*(int *)(iVar2 + 0x1a8) + 0x17c);
  guard_check_icall(local_28);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(local_2c + 0x370) + 0x17c);
  guard_check_icall(local_28);
  (*pcVar1)();
  local_3c = CRgn::vftable;
  FUN_00416100();
LAB_00872abc:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonCategory[52] */
/* 00872c37  FUN_00872c37  235 bytes, 0 callers */

undefined4
FUN_00872c37(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int *param_6,
            int param_7,int param_8,int param_9)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  CMFCToolBarImages *this;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 local_24 [12];
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_18 = param_1;
  local_8 = param_6;
  this = (CMFCToolBarImages *)((-(uint)(param_7 != 0) & 0x118) + 0x578 + in_ECX);
  if (param_8 < *(int *)(this + 4)) {
    local_c = param_3;
    FUN_008721a4(&local_14,param_7);
    if (param_9 != 0) {
      local_c = ((param_5 - param_3) - local_10) / 2;
      if (local_c < 0) {
        local_c = 0;
      }
      iVar3 = ((param_4 - param_2) - local_14) / 2;
      if (iVar3 < 0) {
        iVar3 = 0;
      }
      param_2 = param_2 + iVar3;
      local_c = param_3 + local_c;
    }
    iVar3 = FUN_007c2511();
    CMFCToolBarImages::SetTransparentColor(this,*(ulong *)(iVar3 + 0x1c));
    FUN_007eb6ca(local_24,local_14,local_10,0);
    uVar7 = 0xff;
    uVar6 = 0;
    uVar5 = 0;
    uVar4 = 0;
    pcVar1 = *(code **)(*local_8 + 0xdc);
    guard_check_icall(0,0,0,0xff);
    uVar2 = (*pcVar1)();
    FUN_007e8cae(local_18,param_2,local_c,param_8,0,uVar2,uVar4,uVar5,uVar6,uVar7);
    FUN_007e98b8(local_24);
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCRibbonCategory[58] */
/* 00872d22  FUN_00872d22  682 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00872d22(CMFCRibbonBaseElement *param_1)

{
  code *pcVar1;
  CMFCRibbonBaseElement *pCVar2;
  int *piVar3;
  int iVar4;
  BOOL BVar5;
  BOOL BVar6;
  CMFCRibbonBaseElement *pCVar7;
  CMFCRibbonCategory *in_ECX;
  undefined **local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  undefined4 local_38;
  CMFCRibbonBaseElement *local_34;
  uint local_30;
  CMFCRibbonBaseElement *local_2c;
  CMFCRibbonCategory *local_28;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x872d2e;
  local_34 = param_1;
  if (param_1 != (CMFCRibbonBaseElement *)0x9) {
    if ((param_1 == (CMFCRibbonBaseElement *)0xd) || (param_1 == (CMFCRibbonBaseElement *)0x20)) {
      pCVar7 = CMFCRibbonCategory::GetFocused(in_ECX);
      if (pCVar7 != (CMFCRibbonBaseElement *)0x0) {
        pcVar1 = *(code **)(*(int *)pCVar7 + 0x1dc);
        guard_check_icall(0);
        (*pcVar1)();
      }
      goto LAB_00872fc4;
    }
    if ((((param_1 != (CMFCRibbonBaseElement *)0x25) && (param_1 != (CMFCRibbonBaseElement *)0x26))
        && (param_1 != (CMFCRibbonBaseElement *)0x27)) && (param_1 != (CMFCRibbonBaseElement *)0x28)
       ) goto LAB_00872fc4;
  }
  local_44 = 0;
  local_48 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
  local_38 = 0;
  local_3c = 0;
  local_40 = 0;
  local_8 = 0;
  local_28 = in_ECX;
  CMFCRibbonCategory::GetVisibleElements
            (in_ECX,(CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*> *)&local_48);
  if (local_40 == 0) {
    local_48 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    if (local_44 != 0) {
      thunk_FUN_008f43b0(local_44);
    }
  }
  else {
    local_2c = CMFCRibbonCategory::GetFocused(in_ECX);
    if (local_2c == (CMFCRibbonBaseElement *)0x0) {
      local_30 = 0;
      pCVar7 = (CMFCRibbonBaseElement *)0x0;
      if (0 < local_40) {
        do {
          piVar3 = (int *)FUN_00799cf8(local_30);
          pCVar7 = (CMFCRibbonBaseElement *)*piVar3;
          pcVar1 = *(code **)(*(int *)pCVar7 + 0x11c);
          local_34 = pCVar7;
          guard_check_icall();
          iVar4 = (*pcVar1)();
          if (iVar4 != 0) {
            local_24.left = *(LONG *)(pCVar7 + 0x74);
            local_24.top = *(LONG *)(pCVar7 + 0x78);
            local_24.right = *(LONG *)(pCVar7 + 0x7c);
            local_24.bottom = *(LONG *)(pCVar7 + 0x80);
            BVar5 = IsRectEmpty(&local_24);
            pCVar7 = local_34;
            in_ECX = local_28;
            if (BVar5 == 0) break;
          }
          local_30 = local_30 + 1;
          pCVar7 = (CMFCRibbonBaseElement *)0x0;
          in_ECX = local_28;
        } while ((int)local_30 < local_40);
      }
    }
    else {
      local_30 = 0;
      local_24.left = *(LONG *)(in_ECX + 0x21c);
      local_24.top = *(LONG *)(in_ECX + 0x220);
      local_24.right = *(LONG *)(in_ECX + 0x224);
      local_24.bottom = *(LONG *)(in_ECX + 0x228);
      BVar5 = IsRectEmpty(&local_24);
      local_24.left = *(LONG *)(local_28 + 0x3e4);
      local_24.top = *(LONG *)(local_28 + 1000);
      local_24.right = *(LONG *)(local_28 + 0x3ec);
      local_24.bottom = *(LONG *)(local_28 + 0x3f0);
      BVar6 = IsRectEmpty(&local_24);
      pCVar7 = (CMFCRibbonBaseElement *)
               FUN_008b2f04(local_34,&local_48,*(int *)(local_28 + 0x7c),*(int *)(local_28 + 0x80),
                            *(int *)(local_28 + 0x84),*(int *)(local_28 + 0x88),local_2c,BVar5 == 0,
                            BVar6 == 0,&local_30);
      in_ECX = local_28;
      if (local_30 != 0) {
        if (local_30 == 0xfffffffe) {
          pCVar7 = (CMFCRibbonBaseElement *)FUN_00872107();
        }
        else if ((local_30 == 0xffffffff) || (local_30 == 1)) {
          pcVar1 = *(code **)(*(int *)local_28 + 0xe0);
          guard_check_icall(local_30 >> 0x1f,0);
          (*pcVar1)();
          in_ECX = local_28;
        }
        else if (local_30 == 2) {
          pCVar7 = (CMFCRibbonBaseElement *)FUN_008722e9();
        }
      }
    }
    pCVar2 = local_2c;
    local_8 = 0xffffffff;
    local_48 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    if (local_44 != 0) {
      thunk_FUN_008f43b0(local_44);
    }
    if ((pCVar7 != pCVar2) && (pCVar7 != (CMFCRibbonBaseElement *)0x0)) {
      if (*(int *)(in_ECX + 0x53c) != 0) {
        FUN_008b2abe(0);
      }
      if (pCVar2 != (CMFCRibbonBaseElement *)0x0) {
        *(int *)(pCVar2 + 0xcc) = 0;
        *(int *)(pCVar2 + 200) = 0;
        pcVar1 = *(code **)(*(int *)pCVar2 + 0x224);
        guard_check_icall(0);
        (*pcVar1)();
        pcVar1 = *(code **)(*(int *)pCVar2 + 0x1b8);
        guard_check_icall();
        (*pcVar1)();
      }
      *(int *)(pCVar7 + 0xcc) = 1;
      pcVar1 = *(code **)(*(int *)pCVar7 + 0x224);
      guard_check_icall(1);
      (*pcVar1)();
      pcVar1 = *(code **)(*(int *)pCVar7 + 0x1b8);
      guard_check_icall();
      (*pcVar1)();
    }
  }
LAB_00872fc4:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonCategory[47] */
/* 00873107  FUN_00873107  129 bytes, 0 callers */

int * FUN_00873107(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int *piVar3;
  CMFCRibbonPanel *pCVar4;
  int in_ECX;
  
  piVar2 = (int *)FUN_00872747(param_1,param_2);
  if (piVar2 == (int *)0x0) {
    pCVar4 = CMFCRibbonCategory::GetPanelFromPoint();
    if (pCVar4 != (CMFCRibbonPanel *)0x0) {
      *(undefined4 *)(in_ECX + 0x60) = 1;
      pcVar1 = *(code **)(*(int *)pCVar4 + 0x118);
      guard_check_icall(param_1,param_2);
      piVar2 = (int *)(*pcVar1)();
      return piVar2;
    }
  }
  else {
    pcVar1 = *(code **)(*piVar2 + 0x150);
    guard_check_icall();
    (*pcVar1)();
    piVar3 = (int *)FUN_00872747(param_1,param_2);
    if (piVar3 == piVar2) {
      return piVar2;
    }
  }
  return (int *)0x0;
}




/* vtable slots: CMFCRibbonCategory[48] */
/* 008731b2  FUN_008731b2  74 bytes, 0 callers */

void FUN_008731b2(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  CMFCRibbonPanel *pCVar2;
  CMFCRibbonCategory *in_ECX;
  
  *(undefined4 *)(in_ECX + 0x270) = 0;
  *(undefined4 *)(in_ECX + 0x438) = 0;
  pCVar2 = CMFCRibbonCategory::GetPanelFromPoint(in_ECX,param_1,param_2);
  if (pCVar2 != (CMFCRibbonPanel *)0x0) {
    *(undefined4 *)(in_ECX + 0x60) = 0;
    pcVar1 = *(code **)(*(int *)pCVar2 + 0x11c);
    guard_check_icall(param_1,param_2);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCRibbonCategory[49] */
/* 008731fc  FUN_008731fc  162 bytes, 0 callers */

void FUN_008731fc(undefined4 param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  CMFCRibbonPanel *pCVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x1a8) + 0x218);
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x370) + 0x218);
  uVar4 = param_1;
  uVar5 = param_2;
  guard_check_icall(param_1,param_2);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x1a8) + 0xd0);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*(int *)(in_ECX + 0x370) + 0xd0);
    guard_check_icall(uVar4,uVar5);
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pCVar3 = CMFCRibbonCategory::GetPanelFromPoint();
      FUN_00872608(pCVar3,param_1,param_2);
    }
  }
  return;
}




/* vtable slots: CMFCRibbonCategory[55] */
/* 0087331b  FUN_0087331b  167 bytes, 0 callers */

void FUN_0087331b(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0;
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x564)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x110);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x564));
  }
  if (0 < *(int *)(in_ECX + 0x7b0)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_c);
      pcVar1 = *(code **)(*(int *)*puVar2 + 500);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_c = local_c + 1;
    } while (local_c < *(int *)(in_ECX + 0x7b0));
  }
  *(undefined4 *)(in_ECX + 0x70) = 0xffffffff;
  return;
}




/* vtable slots: CMFCRibbonCategory[56] */
/* 008733c2  FUN_008733c2  253 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_008733c2(int param_1,int param_2)

{
  code *pcVar1;
  CFont *pCVar2;
  undefined4 uVar3;
  CWnd *pCVar4;
  int *in_ECX;
  int iVar5;
  int iVar6;
  bool bVar7;
  RECT *lprcUpdate;
  undefined1 local_30 [20];
  int local_1c;
  int *local_18;
  CWnd *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x20;
  local_8 = 0x8733ce;
  local_1c = in_ECX[0x14e];
  if (param_2 == 0) {
    param_2 = 0x32;
  }
  if (param_1 != 0) {
    param_2 = -param_2;
  }
  param_2 = local_1c + param_2;
  in_ECX[0x14e] = param_2;
  iVar6 = param_2;
  if (param_2 < 0) {
    iVar6 = 0;
  }
  iVar5 = in_ECX[0x151] - (in_ECX[0x21] - in_ECX[0x1f]);
  if ((iVar6 <= iVar5) && (iVar5 = param_2, param_2 < 0)) {
    iVar5 = 0;
  }
  pCVar4 = (CWnd *)in_ECX[0x14f];
  in_ECX[0x14e] = iVar5;
  local_18 = in_ECX;
  local_14 = pCVar4;
  FUN_0079dea2(pCVar4);
  local_8 = 0;
  pCVar2 = CWnd::GetFont(pCVar4);
  uVar3 = FUN_0079efbc(pCVar2);
  pcVar1 = *(code **)(*in_ECX + 0xe4);
  guard_check_icall(local_30);
  (*pcVar1)();
  FUN_0079efbc(uVar3);
  FUN_00873fc2();
  if ((CWnd *)in_ECX[0x150] == (CWnd *)0x0) {
    lprcUpdate = (RECT *)(in_ECX + 0x1f);
    pCVar4 = local_14;
  }
  else {
    lprcUpdate = (RECT *)0x0;
    pCVar4 = (CWnd *)in_ECX[0x150];
  }
  RedrawWindow(*(HWND *)(pCVar4 + 0x20),lprcUpdate,(HRGN)0x0,0x105);
  bVar7 = local_1c != local_18[0x14e];
  FUN_0079dfff();
  return bVar7;
}




/* vtable slots: CMFCRibbonCategory[42] */
/* 008734bf  FUN_008734bf  87 bytes, 0 callers */

undefined4 FUN_008734bf(int param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  
  FUN_007ed2e1();
  param_1 = param_1 + -1;
  if ((param_1 < 0) || (*(int *)(in_ECX + 0x564) <= param_1)) {
    uVar3 = 0;
  }
  else {
    puVar2 = (undefined4 *)FUN_00799cf8(param_1);
    pcVar1 = *(code **)(*(int *)*puVar2 + 0xac);
    guard_check_icall(*(undefined4 *)(in_ECX + 0x53c),in_ECX + 0x20);
    uVar3 = (*pcVar1)();
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonCategory[50] */
/* 00873516  FUN_00873516  93 bytes, 0 callers */

void FUN_00873516(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x564)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0xf8);
      guard_check_icall(param_1,param_2,param_3);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x564));
  }
  return;
}




/* vtable slots: CMFCRibbonCategory[44] */
/* 00873573  FUN_00873573  907 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00873573(CDC *param_1)

{
  RECT *lprc;
  uint uVar1;
  code *pcVar2;
  bool bVar3;
  BOOL BVar4;
  int iVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  CMFCRibbonCategory *in_ECX;
  int iVar10;
  int iVar11;
  int local_24;
  int local_20;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  lprc = (RECT *)(in_ECX + 0x7c);
  BVar4 = IsRectEmpty(lprc);
  if (BVar4 == 0) {
    if (*(int *)(in_ECX + 0x540) != 0) {
      CMFCRibbonCategory::CleanUpSizes(in_ECX);
    }
    FUN_008738fe(param_1);
    if (*(int *)(in_ECX + 0x564) != 0) {
      bVar3 = false;
      uVar1 = *(uint *)(*(int *)(in_ECX + 0x53c) + 0x330);
      if (*(int *)(in_ECX + 0x544) < 0) {
        iVar5 = CMFCRibbonCategory::GetMinWidth(in_ECX,param_1);
        *(int *)(in_ECX + 0x544) = iVar5;
      }
      if (((uVar1 & 3) == 0) || (*(int *)(in_ECX + 0x540) != 0)) {
        iVar5 = *(int *)(in_ECX + 0x84) - lprc->left;
        if ((*(int *)(in_ECX + 0x70) != iVar5) ||
           (*(int *)(in_ECX + 0x74) != *(int *)(in_ECX + 0x80))) {
          *(int *)(in_ECX + 0x70) = iVar5;
          *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 0x80);
          local_18.left = lprc->left;
          local_18.top = *(LONG *)(in_ECX + 0x80);
          local_18.right = *(LONG *)(in_ECX + 0x84);
          local_18.bottom = *(LONG *)(in_ECX + 0x88);
          iVar5 = local_18.left + 4;
          iVar11 = local_18.right + -4;
          CMFCRibbonCategory::ResetPanelsLayout(in_ECX);
          bVar3 = true;
          if (*(int *)(in_ECX + 0x544) < iVar11 - iVar5) {
            if (0 < *(int *)(in_ECX + 0x550)) {
              iVar10 = 0;
              while( true ) {
                iVar8 = FUN_00873ea8(iVar11 - iVar5);
                if (iVar8 != 0) goto LAB_00873869;
                if (iVar10 == *(int *)(in_ECX + 0x550)) break;
                piVar7 = (int *)FUN_005db5d0(iVar10);
                iVar8 = *piVar7;
                if ((iVar8 < 0) || (*(int *)(in_ECX + 0x564) <= iVar8)) break;
                piVar7 = (int *)FUN_00799cf8(iVar8);
                iVar8 = *piVar7;
                if (iVar10 < *(int *)(in_ECX + 0x550) + -1) {
                  piVar7 = (int *)FUN_005db5d0(iVar10 + 1);
                  if (*piVar7 != -1) goto LAB_008737b3;
                  *(undefined4 *)(iVar8 + 100) = 1;
                  iVar9 = *(int *)(iVar8 + 0x4d0) + -1;
                  iVar10 = iVar10 + 1;
LAB_008737c7:
                  *(int *)(iVar8 + 0xa4) = iVar9;
                }
                else {
LAB_008737b3:
                  if (*(int *)(iVar8 + 0xa4) < *(int *)(iVar8 + 0x4d0) + -1) {
                    iVar9 = *(int *)(iVar8 + 0xa4) + 1;
                    goto LAB_008737c7;
                  }
                }
                iVar10 = iVar10 + 1;
                if (*(int *)(in_ECX + 0x550) < iVar10) break;
              }
              CMFCRibbonCategory::ResetPanelsLayout(in_ECX);
            }
            iVar10 = FUN_00873ea8(iVar11 - iVar5);
            while (local_24 = 1, iVar10 == 0) {
              iVar10 = -1;
              iVar8 = 0;
              if (*(int *)(in_ECX + 0x564) < 1) break;
              do {
                piVar7 = (int *)FUN_00799cf8(iVar8);
                iVar9 = *(int *)(*piVar7 + 0x4d0) - *(int *)(*piVar7 + 0xa4);
                if (local_24 < iVar9) {
                  local_24 = iVar9 + -1;
                  iVar10 = iVar8;
                }
                iVar8 = iVar8 + 1;
              } while (iVar8 < *(int *)(in_ECX + 0x564));
              if (iVar10 < 0) break;
              piVar7 = (int *)FUN_00799cf8(iVar10);
              *(int *)(*piVar7 + 0xa4) = *(int *)(*piVar7 + 0xa4) + 1;
              iVar10 = FUN_00873ea8(iVar11 - iVar5);
            }
          }
          else {
            iVar5 = 0;
            if (0 < *(int *)(in_ECX + 0x564)) {
              do {
                piVar7 = (int *)FUN_00799cf8(iVar5);
                iVar11 = *piVar7;
                *(undefined4 *)(iVar11 + 100) = 1;
                *(int *)(iVar11 + 0xa4) = *(int *)(iVar11 + 0x4d0) + -1;
                iVar5 = iVar5 + 1;
              } while (iVar5 < *(int *)(in_ECX + 0x564));
            }
          }
LAB_00873869:
          pcVar2 = *(code **)(*(int *)in_ECX + 0xe4);
          guard_check_icall(param_1);
          (*pcVar2)();
        }
      }
      else {
        local_20 = 0;
        if (0 < *(int *)(in_ECX + 0x564)) {
          do {
            puVar6 = (undefined4 *)FUN_00799cf8(local_20);
            local_18.left = 0;
            piVar7 = (int *)*puVar6;
            local_18.top = 0;
            local_18.right = 0;
            local_18.bottom = 0;
            pcVar2 = *(code **)(*piVar7 + 0xec);
            guard_check_icall(param_1,&local_18);
            (*pcVar2)();
            pcVar2 = *(code **)(*piVar7 + 0x104);
            guard_check_icall(0);
            (*pcVar2)();
            local_20 = local_20 + 1;
          } while (local_20 < *(int *)(in_ECX + 0x564));
        }
        *(undefined4 *)(in_ECX + 0x70) = 0xffffffff;
        *(undefined4 *)(in_ECX + 0x544) = 0xffffffff;
      }
      FUN_00873fc2();
      if (((bVar3) && (*(int *)(in_ECX + 0x53c) != 0)) &&
         (*(int *)(*(int *)(in_ECX + 0x53c) + 0x20) != 0)) {
        local_18.left = *(LONG *)(in_ECX + 0x21c);
        local_18.top = *(LONG *)(in_ECX + 0x220);
        local_18.right = *(LONG *)(in_ECX + 0x224);
        local_18.bottom = *(LONG *)(in_ECX + 0x228);
        BVar4 = IsRectEmpty(&local_18);
        if (BVar4 != 0) {
          local_18.left = *(LONG *)(in_ECX + 0x3e4);
          local_18.top = *(LONG *)(in_ECX + 1000);
          local_18.right = *(LONG *)(in_ECX + 0x3ec);
          local_18.bottom = *(LONG *)(in_ECX + 0x3f0);
          BVar4 = IsRectEmpty(&local_18);
          if (BVar4 != 0) {
            return;
          }
        }
        RedrawWindow(*(HWND *)(*(int *)(in_ECX + 0x53c) + 0x20),(RECT *)(in_ECX + 0x7c),(HRGN)0x0,
                     0x105);
      }
    }
  }
  return;
}




/* vtable slots: CMFCRibbonCategory[57] */
/* 008739ef  FUN_008739ef  386 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008739ef(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int in_ECX;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int local_20;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = *(int *)(in_ECX + 0x7c);
  local_18.top = *(int *)(in_ECX + 0x80);
  iVar1 = *(int *)(in_ECX + 0x84);
  local_18.bottom = *(int *)(in_ECX + 0x88);
  iVar8 = local_18.top + 3;
  iVar9 = local_18.bottom + -4;
  iVar2 = *(int *)(in_ECX + 0x544);
  iVar11 = (iVar1 + -4) - (local_18.left + 4);
  iVar10 = 0;
  local_20 = (local_18.left + 4) - *(int *)(in_ECX + 0x538);
  if (0 < *(int *)(in_ECX + 0x564)) {
    iVar4 = local_18.left + 8;
    local_18.right = iVar1;
    do {
      piVar5 = (int *)FUN_00799cf8(iVar10);
      piVar5 = (int *)*piVar5;
      if (iVar2 < iVar11) {
        iVar6 = piVar5[0x29];
      }
      else {
        iVar6 = piVar5[0x134] + -1;
        piVar5[0x19] = 1;
        piVar5[0x29] = iVar6;
      }
      piVar7 = (int *)FUN_005db5d0(iVar6);
      local_18.right = *piVar7 + piVar5[0x2c] * 2 + local_20;
      local_18.left = local_20;
      pcVar3 = *(code **)(*piVar5 + 0xec);
      local_18.top = iVar8;
      local_18.bottom = iVar9;
      guard_check_icall(param_1,&local_18);
      (*pcVar3)();
      local_20 = piVar5[0x35] + 2;
      if ((local_18.right <= iVar4) || (iVar1 + -8 <= local_18.left)) {
        SetRectEmpty(&local_18);
        pcVar3 = *(code **)(*piVar5 + 0xec);
        guard_check_icall(param_1,&local_18);
        (*pcVar3)();
      }
      if (iVar11 <= iVar2) {
        piVar5[0x19] = 1;
      }
      pcVar3 = *(code **)(*piVar5 + 0x100);
      guard_check_icall(param_1);
      (*pcVar3)();
      iVar10 = iVar10 + 1;
    } while (iVar10 < *(int *)(in_ECX + 0x564));
  }
  return;
}




/* vtable slots: CMFCRibbonCategory[43] */
/* 00873bb0  FUN_00873bb0  108 bytes, 0 callers */

undefined4 FUN_00873bb0(undefined4 param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  int iVar1;
  int in_ECX;
  
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_2,(CSimpleStringT<wchar_t,0> *)(in_ECX + 0x8c));
  *(undefined4 *)(param_2 + 0x18) = 0x16;
  iVar1 = FUN_008f899d(L"Group");
  ATL::CSimpleStringT<wchar_t,0>::SetString(param_2 + 4,L"Group",iVar1);
  *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(in_ECX + 0x7c);
  *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(in_ECX + 0x80);
  *(undefined4 *)(param_2 + 0x2c) = *(undefined4 *)(in_ECX + 0x84);
  *(undefined4 *)(param_2 + 0x30) = *(undefined4 *)(in_ECX + 0x88);
  if ((*(int *)(in_ECX + 0x53c) != 0) && (*(int *)(*(int *)(in_ECX + 0x53c) + 0x20) != 0)) {
    FUN_0079e8b8(param_2 + 0x24);
  }
  *(undefined4 *)(param_2 + 0x1c) = 0;
  return 1;
}




/* vtable slots: CMFCRibbonCategory[37] */
/* 008740cf  FUN_008740cf  225 bytes, 0 callers */

undefined4 FUN_008740cf(LONG param_1,LONG param_2,undefined2 *param_3)

{
  code *pcVar1;
  POINT pt;
  undefined4 uVar2;
  int *piVar3;
  BOOL BVar4;
  int in_ECX;
  int iVar5;
  tagPOINT local_14;
  IDispatch *local_c;
  CCmdTarget *local_8;
  
  if (param_3 == (undefined2 *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    if ((*(int *)(in_ECX + 0x53c) != 0) && (*(int *)(*(int *)(in_ECX + 0x53c) + 0x20) != 0)) {
      *param_3 = 3;
      iVar5 = 0;
      *(undefined4 *)(param_3 + 4) = 0;
      local_14.x = param_1;
      local_14.y = param_2;
      ScreenToClient(*(HWND *)(*(int *)(in_ECX + 0x53c) + 0x20),&local_14);
      if (0 < *(int *)(in_ECX + 0x564)) {
        do {
          piVar3 = (int *)FUN_00799cf8(iVar5);
          local_8 = (CCmdTarget *)*piVar3;
          if (((local_8 != (CCmdTarget *)0x0) &&
              (pt.y = local_14.y, pt.x = local_14.x, BVar4 = PtInRect((RECT *)(local_8 + 0xcc),pt),
              BVar4 != 0)) &&
             (local_c = CCmdTarget::GetIDispatch(local_8,1), local_c != (IDispatch *)0x0)) {
            pcVar1 = *(code **)(*(int *)local_8 + 0xac);
            guard_check_icall(*(undefined4 *)(in_ECX + 0x53c),in_ECX + 0x20);
            (*pcVar1)();
            *param_3 = 9;
            *(IDispatch **)(param_3 + 4) = local_c;
            return 0;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(in_ECX + 0x564));
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMFCRibbonCategory[35] */
/* 008741d1  FUN_008741d1  237 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_008741d1(int *param_1,int *param_2,int *param_3,int *param_4,short param_5,undefined4 param_6,
            int param_7)

{
  code *pcVar1;
  int *in_ECX;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) || (param_3 == (int *)0x0)) ||
     (param_4 == (int *)0x0)) {
    return 0x80070057;
  }
  if (param_5 == 3) {
    if (param_7 == 0) {
      if (in_ECX[0x14f] == 0) {
        return 0;
      }
      if (*(int *)(in_ECX[0x14f] + 0x20) == 0) {
        return 0;
      }
      local_18 = in_ECX[0x1f];
      local_14 = in_ECX[0x20];
      local_10 = in_ECX[0x21];
      local_c = in_ECX[0x22];
      FUN_0079e8b8(&local_18);
      *param_1 = local_18;
      *param_2 = local_14;
      *param_3 = local_10 - local_18;
      local_c = local_c - local_14;
    }
    else {
      if (param_7 < 1) {
        return 0;
      }
      pcVar1 = *(code **)(*in_ECX + 0xa8);
      guard_check_icall(param_7);
      (*pcVar1)();
      *param_1 = in_ECX[0x11];
      *param_2 = in_ECX[0x12];
      *param_3 = in_ECX[0x13] - in_ECX[0x11];
      local_c = in_ECX[0x14] - in_ECX[0x12];
    }
    *param_4 = local_c;
  }
  return 0;
}




/* vtable slots: CMFCRibbonCategory[36] */
/* 00874372  FUN_00874372  225 bytes, 0 callers */

undefined4
FUN_00874372(int param_1,short param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined2 *param_6)

{
  int iVar1;
  undefined4 *puVar2;
  IDispatch *pIVar3;
  int in_ECX;
  CCmdTarget *this;
  
  *param_6 = 0;
  if (param_2 != 3) {
    return 0x80070057;
  }
  if (param_1 != 3) {
    if ((param_1 == 4) || (param_1 == 5)) {
      if (param_4 == 0) {
        return 1;
      }
      *param_6 = 3;
      *(int *)(param_6 + 4) = param_4 + 1;
      if (param_4 + 1 <= *(int *)(in_ECX + 0x564)) {
        return 0;
      }
      goto LAB_008743ff;
    }
    if (param_1 != 6) {
      if (param_1 == 7) {
        if (param_4 != 0) {
          return 1;
        }
        *param_6 = 3;
        *(undefined4 *)(param_6 + 4) = 1;
        return 0;
      }
      if (param_1 != 8) {
        return 1;
      }
      if (param_4 != 0) {
        return 1;
      }
      *param_6 = 3;
      pIVar3 = *(IDispatch **)(in_ECX + 0x564);
      goto LAB_008743bc;
    }
  }
  if (param_4 == 0) {
    iVar1 = *(int *)(in_ECX + 0x53c);
    if (iVar1 == 0) {
      return 1;
    }
    if (*(int *)(iVar1 + 0x20) == 0) {
      return 1;
    }
    if (*(int *)(iVar1 + 0x454) < 1) {
      this = (CCmdTarget *)(iVar1 + 0x1250);
    }
    else {
      puVar2 = (undefined4 *)FUN_00799cf8(*(int *)(iVar1 + 0x454) + -1);
      this = (CCmdTarget *)*puVar2;
    }
    if (this == (CCmdTarget *)0x0) {
      return 1;
    }
    *param_6 = 9;
    pIVar3 = CCmdTarget::GetIDispatch(this,1);
LAB_008743bc:
    *(IDispatch **)(param_6 + 4) = pIVar3;
    return 0;
  }
  *param_6 = 3;
  *(int *)(param_6 + 4) = param_4 + -1;
  if (0 < param_4 + -1) {
    return 0;
  }
LAB_008743ff:
  *param_6 = 0;
  return 1;
}




/* vtable slots: CMFCRibbonCategory[22] */
/* 00874502  get_accChild  72 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCRibbonCategory::get_accChild(struct tagVARIANT,struct
   IDispatch * *)
   
   Library: Visual Studio 2015 Release */

long __thiscall
CMFCRibbonCategory::get_accChild(CMFCRibbonCategory *this,tagVARIANT param_1,IDispatch **param_2)

{
  long lVar1;
  undefined4 *puVar2;
  IDispatch *pIVar3;
  
  if (param_2 == (IDispatch **)0x0) {
    lVar1 = -0x7ff8ffa9;
  }
  else {
    if (param_1.n1.n2.vt == 3) {
      puVar2 = (undefined4 *)FUN_00799cf8(param_1.n1._8_4_ + -1);
      if ((CCmdTarget *)*puVar2 != (CCmdTarget *)0x0) {
        pIVar3 = CCmdTarget::GetIDispatch((CCmdTarget *)*puVar2,1);
        *param_2 = pIVar3;
        if (pIVar3 != (IDispatch *)0x0) {
          return 0;
        }
      }
    }
    lVar1 = 1;
  }
  return lVar1;
}




/* vtable slots: CMFCRibbonCategory[21] */
/* 0087454a  FUN_0087454a  31 bytes, 0 callers */

undefined4 FUN_0087454a(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 == (undefined4 *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_1 = *(undefined4 *)(in_ECX + 0x564);
    uVar1 = 0;
  }
  return uVar1;
}




/* vtable slots: CMFCRibbonCategory[20] */
/* 008745cb  get_accParent  60 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual long __thiscall CMFCRibbonCategory::get_accParent(struct IDispatch * *)
   
   Library: Visual Studio 2015 Release */

long __thiscall CMFCRibbonCategory::get_accParent(CMFCRibbonCategory *this,IDispatch **param_1)

{
  long lVar1;
  IDispatch *pIVar2;
  
  if (param_1 == (IDispatch **)0x0) {
    lVar1 = -0x7ff8ffa9;
  }
  else {
    *param_1 = (IDispatch *)0x0;
    if ((*(int *)(this + 0x53c) == 0) || (*(int *)(*(int *)(this + 0x53c) + 0x20) == 0)) {
      lVar1 = 1;
    }
    else {
      pIVar2 = (IDispatch *)FUN_008b33a1();
      if (pIVar2 != (IDispatch *)0x0) {
        *param_1 = pIVar2;
      }
      lVar1 = 0;
    }
  }
  return lVar1;
}



