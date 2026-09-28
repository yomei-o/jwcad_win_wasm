/* CMFCRibbonQuickAccessToolBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonQuickAccessToolBar[1] */
/* 008b1993  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonQuickAccessToolBar::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonQuickAccessToolBar::_scalar_deleting_destructor_
          (CMFCRibbonQuickAccessToolBar *this,uint param_1)

{
  ~CMFCRibbonQuickAccessToolBar(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x4a0);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonQuickAccessToolBar[62] */
/* 008b1c70  FUN_008b1c70  153 bytes, 0 callers */

int * FUN_008b1c70(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  CMFCRibbonBar *this;
  
  FUN_008c50a3(param_1,param_2);
  this = *(CMFCRibbonBar **)(in_ECX + 0x84);
  iVar2 = CMFCRibbonBar::IsQuickAccessToolbarOnTop(this);
  if ((iVar2 != 0) && (1 < *(int *)(in_ECX + 0x114))) {
    piVar3 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar3 + 0x254);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    iVar2 = 6;
    if (5 < iVar4) {
      piVar3 = (int *)FUN_007c2574();
      pcVar1 = *(code **)(*piVar3 + 0x254);
      guard_check_icall();
      iVar2 = (*pcVar1)();
    }
    *param_1 = *param_1 + iVar2;
    this = *(CMFCRibbonBar **)(in_ECX + 0x84);
  }
  iVar2 = CMFCRibbonBar::IsQuickAccessToolbarOnTop(this);
  param_1[1] = param_1[1] + (-(uint)(iVar2 != 0) & 0xfffffffe) + 3;
  return param_1;
}




/* vtable slots: CMFCRibbonQuickAccessToolBar[0] */
/* 008b1d0f  FUN_008b1d0f  6 bytes, 0 callers */

undefined ** FUN_008b1d0f(void)

{
  return &PTR_s_CMFCRibbonQuickAccessToolBar_009a0c60;
}




/* vtable slots: CMFCRibbonQuickAccessToolBar[73] */
/* 008b1d79  FUN_008b1d79  308 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b1d79(undefined4 param_1)

{
  CMFCRibbonBar *this;
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_008c522a(param_1);
  FUN_008b2282();
  *(undefined4 *)(in_ECX + 0x490) = *(undefined4 *)(in_ECX + 0x74);
  *(undefined4 *)(in_ECX + 0x494) = *(undefined4 *)(in_ECX + 0x78);
  *(undefined4 *)(in_ECX + 0x498) = *(undefined4 *)(in_ECX + 0x7c);
  *(undefined4 *)(in_ECX + 0x49c) = *(undefined4 *)(in_ECX + 0x80);
  if (0 < *(int *)(in_ECX + 0x114)) {
    puVar2 = (undefined4 *)FUN_00799cf8(*(int *)(in_ECX + 0x114) + -1);
    pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonQuickAccessCustomizeBu_009a0ee4,
                                (CObject *)*puVar2);
    local_18.left = *(LONG *)(pCVar3 + 0x74);
    local_18.top = *(LONG *)(pCVar3 + 0x78);
    local_18.right = *(LONG *)(pCVar3 + 0x7c);
    local_18.bottom = *(LONG *)(pCVar3 + 0x80);
    *(LONG *)(in_ECX + 0x498) = local_18.left;
    if (1 < *(int *)(in_ECX + 0x114)) {
      this = *(CMFCRibbonBar **)(in_ECX + 0x84);
      iVar4 = CMFCRibbonBar::IsQuickAccessToolbarOnTop(this);
      if (iVar4 == 0) {
        OffsetRect(&local_18,6,0);
        local_18.bottom = local_18.bottom + 1;
      }
      else {
        if (*(int *)(this + 0x16b8) == 0) {
          piVar5 = (int *)FUN_007c2574();
          pcVar1 = *(code **)(*piVar5 + 0x254);
          guard_check_icall();
          iVar4 = (*pcVar1)();
          OffsetRect(&local_18,iVar4,0);
        }
        piVar5 = (int *)FUN_007c2574();
        pcVar1 = *(code **)(*piVar5 + 600);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (0 < iVar4) {
          local_18.top = local_18.top + -2;
          local_18.bottom = local_18.bottom + -1;
        }
      }
    }
    *(LONG *)(pCVar3 + 0x74) = local_18.left;
    *(LONG *)(pCVar3 + 0x78) = local_18.top;
    *(LONG *)(pCVar3 + 0x7c) = local_18.right;
    *(LONG *)(pCVar3 + 0x80) = local_18.bottom;
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x124);
    guard_check_icall(param_1);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCRibbonQuickAccessToolBar[42] */
/* 008b21a1  FUN_008b21a1  192 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008b21a1(int param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 uVar3;
  undefined **local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x8b21ad;
  FUN_007ed2e1();
  if ((in_ECX[0x21] == 0) || (*(int *)(in_ECX[0x21] + 0x20) == 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0;
    local_14 = param_1 + -1;
    local_28 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    local_24 = 0;
    local_18 = 0;
    local_1c = 0;
    local_20 = 0;
    local_8 = 0;
    pcVar1 = *(code **)(*in_ECX + 0x1f0);
    guard_check_icall(&local_28);
    (*pcVar1)();
    if ((-1 < local_14) && (local_14 < local_20)) {
      puVar2 = (undefined4 *)FUN_00799cf8(local_14);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0xac);
      guard_check_icall(in_ECX[0x21],in_ECX + 8);
      uVar3 = (*pcVar1)();
    }
    local_28 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    if (local_24 != 0) {
      thunk_FUN_008f43b0(local_24);
    }
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonQuickAccessToolBar[43] */
/* 008b2414  FUN_008b2414  86 bytes, 0 callers */

undefined4 FUN_008b2414(undefined4 param_1,CSimpleStringT<wchar_t,0> *param_2)

{
  int iVar1;
  int in_ECX;
  wchar_t *pwVar2;
  
  FUN_0086470d(param_1,param_2);
  pwVar2 = *(wchar_t **)(in_ECX + 0x60);
  if (*(int *)(pwVar2 + -6) == 0) {
    pwVar2 = L"Quick Access Toolbar";
  }
  else if (pwVar2 == (wchar_t *)0x0) {
    iVar1 = 0;
    goto LAB_008b243c;
  }
  iVar1 = FUN_008f899d(pwVar2);
LAB_008b243c:
  ATL::CSimpleStringT<wchar_t,0>::SetString(param_2,pwVar2,iVar1);
  ATL::CSimpleStringT<wchar_t,0>::operator=(param_2 + 4,param_2);
  *(undefined4 *)(param_2 + 0x1c) = 0;
  *(undefined4 *)(param_2 + 0x18) = 0x16;
  return 1;
}




/* vtable slots: CMFCRibbonQuickAccessToolBar[38] */
/* 008b246a  FUN_008b246a  201 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008b246a(short param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 uVar3;
  undefined **local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  if (param_1 != 3) {
    return 0x80070057;
  }
  if (param_3 == 0) {
LAB_008b2509:
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
    local_28 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    local_24 = 0;
    local_18 = 0;
    local_1c = 0;
    local_20 = 0;
    local_8 = 0;
    pcVar1 = *(code **)(*in_ECX + 0x1f0);
    guard_check_icall(&local_28);
    (*pcVar1)();
    param_3 = param_3 + -1;
    if ((param_3 < 0) || (local_20 <= param_3)) {
      uVar3 = 0x80070057;
    }
    else {
      piVar2 = (int *)FUN_00799cf8(param_3);
      if ((int *)*piVar2 == (int *)0x0) {
        local_28 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
        if (local_24 != 0) {
          thunk_FUN_008f43b0(local_24);
        }
        goto LAB_008b2509;
      }
      pcVar1 = *(code **)(*(int *)*piVar2 + 0x15c);
      guard_check_icall();
      (*pcVar1)();
    }
    local_28 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    if (local_24 != 0) {
      thunk_FUN_008f43b0(local_24);
    }
  }
  return uVar3;
}




/* vtable slots: CMFCRibbonQuickAccessToolBar[37] */
/* 008b2533  FUN_008b2533  285 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008b2533(LONG param_1,LONG param_2,undefined2 *param_3)

{
  code *pcVar1;
  POINT pt;
  int *piVar2;
  BOOL BVar3;
  int *in_ECX;
  int iVar4;
  undefined **local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  tagPOINT local_2c;
  RECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x8b253f;
  if (((param_3 != (undefined2 *)0x0) && (in_ECX[0x21] != 0)) &&
     (*(int *)(in_ECX[0x21] + 0x20) != 0)) {
    *param_3 = 3;
    iVar4 = 0;
    *(undefined4 *)(param_3 + 4) = 0;
    local_2c.x = param_1;
    local_2c.y = param_2;
    ScreenToClient(*(HWND *)(in_ECX[0x21] + 0x20),&local_2c);
    local_40 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    local_3c = 0;
    local_30 = 0;
    local_34 = 0;
    local_38 = 0;
    local_8 = 0;
    pcVar1 = *(code **)(*in_ECX + 0x1f0);
    guard_check_icall(&local_40);
    (*pcVar1)();
    if (0 < local_38) {
      do {
        piVar2 = (int *)FUN_00799cf8(iVar4);
        iVar4 = iVar4 + 1;
        piVar2 = (int *)*piVar2;
        local_24.left = piVar2[0x1d];
        local_24.top = piVar2[0x1e];
        local_24.right = piVar2[0x1f];
        local_24.bottom = piVar2[0x20];
        pt.y = local_2c.y;
        pt.x = local_2c.x;
        BVar3 = PtInRect(&local_24,pt);
        if (BVar3 != 0) {
          *(int *)(param_3 + 4) = iVar4;
          pcVar1 = *(code **)(*piVar2 + 0xac);
          guard_check_icall(in_ECX[0x21],in_ECX + 8);
          (*pcVar1)();
          break;
        }
      } while (iVar4 < local_38);
    }
    local_40 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    if (local_3c != 0) {
      thunk_FUN_008f43b0(local_3c);
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonQuickAccessToolBar[35] */
/* 008b2650  FUN_008b2650  237 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_008b2650(int *param_1,int *param_2,int *param_3,int *param_4,short param_5,undefined4 param_6,
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
      if (in_ECX[0x21] == 0) {
        return 0;
      }
      if (*(int *)(in_ECX[0x21] + 0x20) == 0) {
        return 0;
      }
      local_18 = in_ECX[0x1d];
      local_14 = in_ECX[0x1e];
      local_10 = in_ECX[0x1f];
      local_c = in_ECX[0x20];
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




/* vtable slots: CMFCRibbonQuickAccessToolBar[36] */
/* 008b273d  FUN_008b273d  442 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4
FUN_008b273d(int param_1,short param_2,undefined4 param_3,int param_4,undefined4 param_5,
            undefined2 *param_6)

{
  code *pcVar1;
  IDispatch *pIVar2;
  int *in_ECX;
  CCmdTarget *pCVar3;
  undefined4 uVar4;
  undefined **local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28;
  int *local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  *param_6 = 0;
  if (param_2 != 3) {
    return 0x80070057;
  }
  uVar4 = 0;
  local_3c = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
  local_38 = 0;
  local_2c = 0;
  local_30 = 0;
  local_34 = 0;
  local_8 = 0;
  pcVar1 = *(code **)(*in_ECX + 0x1f0);
  local_14 = in_ECX;
  guard_check_icall(&local_3c);
  (*pcVar1)();
  if (param_1 == 3) {
LAB_008b28b0:
    if (param_4 != 0) {
      *param_6 = 3;
      *(int *)(param_6 + 4) = param_4 + -1;
      if (0 < param_4 + -1) goto LAB_008b27ff;
      goto LAB_008b27f7;
    }
    pCVar3 = *(CCmdTarget **)(local_14[0x21] + 0x334);
    if (pCVar3 != (CCmdTarget *)0x0) {
      *param_6 = 9;
      pIVar2 = CCmdTarget::GetIDispatch(pCVar3,1);
      *(IDispatch **)(param_6 + 4) = pIVar2;
      goto LAB_008b27ff;
    }
  }
  else {
    if ((param_1 != 4) && (param_1 != 5)) {
      if (param_1 == 6) goto LAB_008b28b0;
      if (param_1 == 7) {
        if (param_4 != 0) goto LAB_008b27fc;
        *(undefined4 *)(param_6 + 4) = 1;
      }
      else {
        if ((param_1 != 8) || (param_4 != 0)) goto LAB_008b27fc;
        *(int *)(param_6 + 4) = local_34;
      }
      *param_6 = 3;
      goto LAB_008b27ff;
    }
    if (param_4 == 0) {
      local_28 = CArray<CMFCRibbonContextCaption*,CMFCRibbonContextCaption*>::vftable;
      local_24 = (int *)0x0;
      local_18 = 0;
      local_1c = 0;
      local_20 = 0;
      local_8 = CONCAT31(local_8._1_3_,1);
      CMFCRibbonBar::GetVisibleContextCaptions
                ((CMFCRibbonBar *)local_14[0x21],
                 (CArray<CMFCRibbonContextCaption*,CMFCRibbonContextCaption*> *)&local_28);
      if (((0 < local_20) && (pCVar3 = (CCmdTarget *)*local_24, pCVar3 != (CCmdTarget *)0x0)) ||
         (pCVar3 = (CCmdTarget *)(local_14[0x21] + 0x1250), pCVar3 != (CCmdTarget *)0x0)) {
        *param_6 = 9;
        pIVar2 = CCmdTarget::GetIDispatch(pCVar3,1);
        *(IDispatch **)(param_6 + 4) = pIVar2;
        local_28 = CArray<CMFCRibbonContextCaption*,CMFCRibbonContextCaption*>::vftable;
        if (local_24 != (int *)0x0) {
          thunk_FUN_008f43b0(local_24);
        }
        goto LAB_008b27ff;
      }
      local_28 = CArray<CMFCRibbonContextCaption*,CMFCRibbonContextCaption*>::vftable;
      if (local_24 != (int *)0x0) {
        thunk_FUN_008f43b0(local_24);
      }
      goto LAB_008b27fc;
    }
    *param_6 = 3;
    *(int *)(param_6 + 4) = param_4 + 1;
    if (param_4 + 1 <= local_34) goto LAB_008b27ff;
LAB_008b27f7:
    *param_6 = 0;
  }
LAB_008b27fc:
  uVar4 = 1;
LAB_008b27ff:
  local_3c = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
  if (local_38 != 0) {
    thunk_FUN_008f43b0(local_38);
  }
  return uVar4;
}




/* vtable slots: CMFCRibbonQuickAccessToolBar[21] */
/* 008b28f7  FUN_008b28f7  113 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008b28f7(undefined4 *param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined **local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  if (param_1 == (undefined4 *)0x0) {
    uVar2 = 0x80070057;
  }
  else {
    local_24 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    local_20 = 0;
    local_14 = 0;
    local_18 = 0;
    local_1c = 0;
    local_8 = 0;
    pcVar1 = *(code **)(*in_ECX + 0x1f0);
    guard_check_icall(&local_24);
    (*pcVar1)();
    *param_1 = local_1c;
    local_24 = CArray<CMFCRibbonBaseElement*,CMFCRibbonBaseElement*>::vftable;
    if (local_20 != 0) {
      thunk_FUN_008f43b0(local_20);
    }
    uVar2 = 0;
  }
  return uVar2;
}




/* vtable slots: CMFCRibbonQuickAccessToolBar[20] */
/* 008b2968  get_accParent  60 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual long __thiscall CMFCRibbonApplicationButton::get_accParent(struct IDispatch *
   *)
    protected: virtual long __thiscall CMFCRibbonContextCaption::get_accParent(struct IDispatch * *)
    protected: virtual long __thiscall CMFCRibbonQuickAccessToolBar::get_accParent(struct IDispatch
   * *)
    protected: virtual long __thiscall CMFCRibbonTabsGroup::get_accParent(struct IDispatch * *)
   
   Library: Visual Studio 2015 Release */

undefined4 get_accParent(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  if (param_1 == (int *)0x0) {
    uVar1 = 0x80070057;
  }
  else {
    *param_1 = 0;
    if ((*(int *)(in_ECX + 0x84) == 0) || (*(int *)(*(int *)(in_ECX + 0x84) + 0x20) == 0)) {
      uVar1 = 1;
    }
    else {
      iVar2 = FUN_008b33a1();
      if (iVar2 != 0) {
        *param_1 = iVar2;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}



