/* CMFCRibbonColorButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCRibbonColorButton[168], CMFCVisualManager[183], CMFCVisualManager[186], CMFCVisualManagerOfficeXP[186] */
/* 007f31d8  FUN_007f31d8  4 bytes, 0 callers */

undefined4 FUN_007f31d8(void)

{
  return 2;
}




/* vtable slots: CMFCRibbonColorButton[1] */
/* 008a03dc  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCRibbonColorButton::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCRibbonColorButton::_scalar_deleting_destructor_(CMFCRibbonColorButton *this,uint param_1)

{
  ~CMFCRibbonColorButton(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x400);
    }
  }
  return this;
}




/* vtable slots: CMFCRibbonColorButton[99], CMFCRibbonGallery[99], CMFCRibbonUndoButton[99] */
/* 008a040f  FUN_008a040f  20 bytes, 0 callers */

undefined4 FUN_008a040f(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if ((*(int *)(in_ECX + 0x350) == 0) && (*(int *)(in_ECX + 0x370) == 0)) {
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CMFCRibbonColorButton[90] */
/* 008a04a7  FUN_008a04a7  512 bytes, 0 callers */

void FUN_008a04a7(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  
  FUN_008af26e(param_1);
  iVar2 = FUN_0079d98a(&PTR_s_CMFCRibbonColorButton_0099edf0);
  if (iVar2 != 0) {
    *(undefined4 *)(in_ECX + 0x378) = *(undefined4 *)(param_1 + 0x378);
    iVar2 = 0;
    *(undefined4 *)(in_ECX + 0x380) = *(undefined4 *)(param_1 + 0x380);
    FUN_0079ca8b(0,0xffffffff);
    FUN_0079ca8b(0,0xffffffff);
    FUN_0079ca8b(0,0xffffffff);
    if (0 < *(int *)(param_1 + 0x38c)) {
      iVar4 = 0;
      do {
        puVar3 = (undefined4 *)FUN_00799cf8(iVar4);
        FUN_0079c90d(*(undefined4 *)(in_ECX + 0x38c),*puVar3);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x38c));
    }
    if (0 < *(int *)(param_1 + 0x3a0)) {
      iVar4 = 0;
      do {
        puVar3 = (undefined4 *)FUN_00799cf8(iVar4);
        FUN_0079c90d(*(undefined4 *)(in_ECX + 0x3a0),*puVar3);
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(param_1 + 0x3a0));
    }
    if (0 < *(int *)(param_1 + 0x3b4)) {
      do {
        puVar3 = (undefined4 *)FUN_00799cf8(iVar2);
        FUN_0079c90d(*(undefined4 *)(in_ECX + 0x3b4),*puVar3);
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(param_1 + 0x3b4));
    }
    *(undefined4 *)(in_ECX + 0x3c0) = *(undefined4 *)(param_1 + 0x3c0);
    *(undefined4 *)(in_ECX + 0x3c4) = *(undefined4 *)(param_1 + 0x3c4);
    *(undefined4 *)(in_ECX + 0x3c8) = *(undefined4 *)(param_1 + 0x3c8);
    *(undefined4 *)(in_ECX + 0x3cc) = *(undefined4 *)(param_1 + 0x3cc);
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x3d8),
               (CSimpleStringT<wchar_t,0> *)(param_1 + 0x3d8));
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x3dc),
               (CSimpleStringT<wchar_t,0> *)(param_1 + 0x3dc));
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x3e0),
               (CSimpleStringT<wchar_t,0> *)(param_1 + 0x3e0));
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(in_ECX + 0x3e4),
               (CSimpleStringT<wchar_t,0> *)(param_1 + 0x3e4));
    ATL::CSimpleStringT<wchar_t,0>::operator=
              ((CSimpleStringT<wchar_t,0> *)(in_ECX + 1000),
               (CSimpleStringT<wchar_t,0> *)(param_1 + 1000));
    *(undefined4 *)(in_ECX + 0x3d0) = *(undefined4 *)(param_1 + 0x3d0);
    uVar1 = *(undefined4 *)(param_1 + 0x3f8);
    *(undefined4 *)(in_ECX + 0x3f4) = *(undefined4 *)(param_1 + 0x3f4);
    *(undefined4 *)(in_ECX + 0x3f8) = uVar1;
    *(undefined4 *)(in_ECX + 0x3d4) = *(undefined4 *)(param_1 + 0x3d4);
    uVar1 = *(undefined4 *)(param_1 + 600);
    *(undefined4 *)(in_ECX + 0x254) = *(undefined4 *)(param_1 + 0x254);
    *(undefined4 *)(in_ECX + 600) = uVar1;
  }
  return;
}




/* vtable slots: CMFCRibbonColorButton[72] */
/* 008a0755  FUN_008a0755  452 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a0755(CDC *param_1,undefined4 param_2,int param_3,LONG param_4,int param_5,int param_6)

{
  double dVar1;
  code *pcVar2;
  CDC *this;
  int iVar3;
  int iVar4;
  int *in_ECX;
  ulong uVar5;
  CDrawingManager local_38 [8];
  undefined **local_30;
  HBRUSH local_2c;
  CDC *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x28;
  local_8 = 0x8a0761;
  local_28 = param_1;
  if (in_ECX[0xf5] == 0) {
    local_24.left = param_3;
    local_24.top = param_4;
    local_24.right = param_5;
    local_24.bottom = param_6;
    iVar4 = 5;
    iVar3 = FUN_007c2511();
    if (*(int *)(iVar3 + 0x1e8) == 0) {
      dVar1 = 1.0;
    }
    else {
      dVar1 = *(double *)(iVar3 + 0x1e0);
    }
    if (dVar1 != 1.0) {
      FUN_007c2511();
      iVar4 = thunk_FUN_008d99f0();
    }
    local_24.top = (local_24.bottom - iVar4) + 1;
    if ((in_ECX[0x1f] - in_ECX[0x1d] & 1U) == 0) {
      local_24.left = local_24.left + 1;
      local_24.right = local_24.right + 1;
    }
    OffsetRect((LPRECT)&param_3,0,-1);
    this = local_28;
    FUN_008668ce(local_28,param_2,param_3,param_4,param_5,param_6);
    pcVar2 = *(code **)(*in_ECX + 0xdc);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if (iVar4 == 0) {
      local_28 = (CDC *)in_ECX[0xde];
      if (local_28 == (CDC *)0xffffffff) {
        local_28 = (CDC *)in_ECX[0xe0];
      }
    }
    else {
      iVar4 = FUN_007c2511();
      local_28 = *(CDC **)(iVar4 + 0x58);
    }
    uVar5 = 0xffffffff;
    if ((in_ECX[0xf2] != 0) && (in_ECX[0xde] == -1)) {
      uVar5 = 0xc5c5c5;
    }
    if (DAT_00a12704 == 0) {
      FUN_0079de5e((((uint)local_28 >> 0x10 & 0xff | 0x200) << 8 | ((uint)local_28 & 0xffff) >> 8)
                   << 8 | (uint)local_28 & 0xff);
      local_8 = 1;
      FillRect(*(HDC *)(this + 4),&local_24,local_2c);
      if (uVar5 != 0xffffffff) {
        CDC::Draw3dRect(this,&local_24,uVar5,uVar5);
      }
      local_30 = CBrush::vftable;
      FUN_00416100();
    }
    else {
      CDrawingManager::CDrawingManager(local_38,this);
      local_8 = 0;
      InflateRect(&local_24,-1,-1);
      FUN_00816b6a(&local_24,local_28,uVar5);
      FUN_0081510b();
    }
  }
  else {
    FUN_008668ce(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonColorButton[164] */
/* 008a0956  FUN_008a0956  157 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

int * FUN_008a0956(int *param_1,int param_2)

{
  ulong uVar1;
  int iVar2;
  CMFCRibbonColorButton *in_ECX;
  int local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x8a0962;
  uVar1 = CMFCRibbonColorButton::GetColorByIndex(in_ECX,*(int *)(param_2 + 0x1c8));
  if (uVar1 == 0xffffffff) {
    FUN_008af815(param_1,param_2);
  }
  else {
    CStringT<>();
    local_8 = 0;
    iVar2 = Lookup(uVar1,local_14);
    if (iVar2 == 0) {
      FUN_004059f0(local_14,L"Hex={%02X,%02X,%02X}",uVar1 & 0xff,(uVar1 & 0xffff) >> 8,
                   uVar1 >> 0x10 & 0xff);
    }
    iVar2 = FUN_004054a0(local_14[0] + -0x10);
    *param_1 = iVar2 + 0x10;
    FUN_00406b10();
  }
  return param_1;
}




/* vtable slots: CMFCRibbonColorButton[82], CMFCRibbonGallery[82], CMFCRibbonUndoButton[82] */
/* 008a09f3  GetNotifyID  35 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual unsigned int __thiscall CMFCRibbonGallery::GetNotifyID(void)
   
   Library: Visual Studio 2015 Release */

uint __thiscall CMFCRibbonGallery::GetNotifyID(CMFCRibbonGallery *this)

{
  if (*(int *)(this + 0x354) != 0) {
    SetNotifyParentID(this,0);
    return *(uint *)(this + 0x32c);
  }
  return *(uint *)(this + 0xa4);
}




/* vtable slots: CMFCRibbonColorButton[0] */
/* 008a0a16  FUN_008a0a16  6 bytes, 0 callers */

undefined ** FUN_008a0a16(void)

{
  return &PTR_s_CMFCRibbonColorButton_0099edf0;
}




/* vtable slots: CMFCRibbonColorButton[65], CMFCRibbonGallery[65], CMFCRibbonUndoButton[65] */
/* 008a0a22  FUN_008a0a22  27 bytes, 0 callers */

undefined4 FUN_008a0a22(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x350) != 0) && (iVar1 = FUN_00865fb0(), iVar1 == 0)) {
    return 0;
  }
  return 1;
}




/* vtable slots: CMFCRibbonColorButton[170] */
/* 008a0a3d  FUN_008a0a3d  7 bytes, 0 callers */

undefined4 FUN_008a0a3d(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3d4);
}




/* vtable slots: CMFCRibbonColorButton[128] */
/* 008a0a44  NotifyHighlightListItem  35 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCRibbonColorButton::NotifyHighlightListItem(int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CMFCRibbonColorButton::NotifyHighlightListItem(CMFCRibbonColorButton *this,int param_1)

{
  ulong uVar1;
  
  uVar1 = GetColorByIndex(this,param_1);
  *(ulong *)(this + 0x37c) = uVar1;
  CMFCRibbonBaseElement::NotifyHighlightListItem((CMFCRibbonBaseElement *)this,param_1);
  return;
}




/* vtable slots: CMFCRibbonColorButton[162] */
/* 008a0a67  OnClickPaletteIcon  48 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCRibbonColorButton::OnClickPaletteIcon(class
   CMFCRibbonGalleryIcon *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall
CMFCRibbonColorButton::OnClickPaletteIcon
          (CMFCRibbonColorButton *this,CMFCRibbonGalleryIcon *param_1)

{
  ulong uVar1;
  
  uVar1 = GetColorByIndex(this,*(int *)(param_1 + 0x1c8));
  if (uVar1 != 0xffffffff) {
    FUN_008a13a4(uVar1);
  }
  FUN_008b025c(param_1);
  return;
}




/* vtable slots: CMFCRibbonColorButton[166] */
/* 008a0a97  FUN_008a0a97  201 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a0a97(int param_1)

{
  code *pcVar1;
  CMFCRibbonBar *pCVar2;
  int iVar3;
  CMFCRibbonBaseElement *in_ECX;
  CMFCColorDialog local_a04 [228];
  undefined4 local_920;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x9f4;
  local_8 = 0x8a0aa6;
  if ((*(int *)(param_1 + 0x8c) == *(int *)(in_ECX + 0x3ec)) && (*(int *)(in_ECX + 0x3ec) != 0)) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x198);
    guard_check_icall();
    (*pcVar1)();
    pCVar2 = CMFCRibbonBaseElement::GetTopLevelRibbonBar(in_ECX);
    CMFCColorDialog::CMFCColorDialog
              (local_a04,*(ulong *)(in_ECX + 0x378),0,(CWnd *)pCVar2,(HPALETTE__ *)0x0);
    local_8 = 0;
    iVar3 = FUN_0079850d();
    if (iVar3 == 1) {
      FUN_008a13a4(local_920);
      FUN_00863dc7(0);
    }
    FUN_0089f663();
  }
  else if ((*(int *)(param_1 + 0x8c) == *(int *)(in_ECX + 0x3f0)) && (*(int *)(in_ECX + 0x3f0) != 0)
          ) {
    FUN_008a13a4(0xffffffff);
    FUN_00863dc7(1);
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCRibbonColorButton[169] */
/* 008a0e08  FUN_008a0e08  384 bytes, 0 callers */

void FUN_008a0e08(undefined4 param_1,LONG param_2,int param_3,LONG param_4,int param_5,int param_6,
                 int *param_7)

{
  ushort uVar1;
  code *pcVar2;
  int *piVar3;
  ushort *puVar4;
  int iVar5;
  int *piVar6;
  CMFCRibbonColorButton *in_ECX;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  ulong local_24;
  undefined4 local_18;
  int local_c;
  int local_8;
  
  piVar3 = param_7;
  local_18 = 0;
  bVar8 = true;
  bVar9 = true;
  local_8 = 0;
  if (*(int *)(in_ECX + 0x3b4) < 1) {
    local_8 = 2;
  }
  if (param_7 == (int *)0x0) {
    local_24 = *(ulong *)(in_ECX + 0x380);
    bVar7 = *(int *)(in_ECX + 0x378) == -1;
    local_8 = 2;
  }
  else {
    local_24 = CMFCRibbonColorButton::GetColorByIndex(in_ECX,param_6);
    bVar7 = *(ulong *)(in_ECX + 0x378) == local_24;
    pcVar2 = *(code **)(*piVar3 + 0xd0);
    guard_check_icall();
    local_18 = (*pcVar2)();
    if (param_6 < *(int *)(in_ECX + 0x38c)) {
      local_c = 0;
      if (0 < *(int *)(in_ECX + 0x3b4)) {
        do {
          puVar4 = (ushort *)FUN_00799cf8(local_c);
          uVar1 = *puVar4;
          iVar5 = FUN_00799cf8(local_c);
          if (((int)(uint)uVar1 <= param_6) && (param_6 <= (int)(uint)*(ushort *)(iVar5 + 2))) {
            local_8 = 0;
            if (piVar3[0x75] != 0) {
              param_3 = param_3 + 1;
            }
            bVar8 = piVar3[0x75] != 0;
            if (piVar3[0x76] != 0) {
              param_5 = param_5 + -1;
            }
            bVar9 = piVar3[0x76] != 0;
            goto LAB_008a0ef8;
          }
          local_c = local_c + 1;
        } while (local_c < *(int *)(in_ECX + 0x3b4));
      }
    }
    if (0 < *(int *)(in_ECX + 0x3b4)) {
      param_5 = param_5 + -1;
    }
  }
LAB_008a0ef8:
  InflateRect((LPRECT)&param_2,-2,-local_8);
  piVar6 = (int *)FUN_007c2574();
  pcVar2 = *(code **)(*piVar6 + 0x2c8);
  guard_check_icall(param_1,in_ECX,piVar3,local_24,param_2,param_3,param_4,param_5,bVar8,bVar9,
                    local_18,bVar7,0);
  (*pcVar2)();
  return;
}




/* vtable slots: CMFCRibbonColorButton[79] */
/* 008a0f88  FUN_008a0f88  553 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008a0f88(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  CObject *pCVar3;
  int iVar4;
  int *piVar5;
  CMFCRibbonBaseElement *in_ECX;
  int iVar6;
  
  *(undefined4 *)(in_ECX + 0x37c) = 0xffffffff;
  CMFCRibbonBaseElement::OnShowPopupMenu(in_ECX);
  iVar6 = 0;
  if (0 < *(int *)(in_ECX + 0x1b8)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar6);
      pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonColorMenuButton_0099f0cc,
                                  (CObject *)*puVar2);
      if (pCVar3 == (CObject *)0x0) {
        iVar6 = iVar6 + 1;
      }
      else {
        pcVar1 = *(code **)(*(int *)pCVar3 + 4);
        guard_check_icall(1);
        (*pcVar1)();
        FUN_0080a5b1(iVar6,1);
      }
    } while (iVar6 < *(int *)(in_ECX + 0x1b8));
  }
  if (*(int *)(in_ECX + 0x3d0) == 0) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x280);
    guard_check_icall();
    (*pcVar1)();
    AddGroup(&DAT_00956338,*(undefined4 *)(in_ECX + 0x38c));
  }
  iVar6 = *(int *)(in_ECX + 0x3a0);
  if (0 < iVar6) {
    AddGroup(*(undefined4 *)(in_ECX + 1000),iVar6);
  }
  if (*(int *)(in_ECX + 0x3cc) != 0) {
    iVar4 = FUN_0078e624(0x1cc);
    if (iVar4 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_008a02dc(2,in_ECX,*(undefined4 *)(in_ECX + 0x3e0),0);
    }
    *(int **)(in_ECX + 0x3ec) = piVar5;
    pcVar1 = *(code **)(*piVar5 + 200);
    guard_check_icall(*(undefined4 *)(in_ECX + 0x3e4));
    (*pcVar1)();
    FUN_008af15c(*(undefined4 *)(in_ECX + 0x3ec),0,0);
  }
  if (*(int *)(in_ECX + 0x3c0) != 0) {
    iVar4 = FUN_0078e624(0x1cc);
    if (iVar4 == 0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_008a02dc(1,in_ECX,*(undefined4 *)(in_ECX + 0x3d8),
                                   *(int *)(in_ECX + 0x378) == -1);
    }
    *(int **)(in_ECX + 0x3f0) = piVar5;
    pcVar1 = *(code **)(*piVar5 + 200);
    guard_check_icall(*(undefined4 *)(in_ECX + 0x3dc));
    (*pcVar1)();
    FUN_008af15c(*(undefined4 *)(in_ECX + 0x3f0),0,*(undefined4 *)(in_ECX + 0x3c4));
  }
  if ((*(int *)(in_ECX + 0x3d0) == 0) || (*(int *)(in_ECX + 0x3b4) < 1)) {
    iVar4 = *(int *)(in_ECX + 0x3f8);
  }
  else {
    iVar4 = *(int *)(in_ECX + 0x3f8) + -3;
  }
  *(int *)(in_ECX + 600) = iVar4;
  *(undefined4 *)(in_ECX + 0x254) = *(undefined4 *)(in_ECX + 0x3f4);
  FUN_008b0950();
  if (0 < iVar6) {
    FUN_007bf642(*(int *)(in_ECX + 0x1e0) + -1,1);
    FUN_0080a5b1(*(int *)(in_ECX + 500) + -1,1);
    *(int *)(in_ECX + 0x34c) = *(int *)(in_ECX + 0x34c) - iVar6;
  }
  return;
}




/* vtable slots: CMFCRibbonColorButton[43] */
/* 008a11b1  FUN_008a11b1  113 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008a11b1(CWnd *param_1,CAccessibilityData *param_2)

{
  CMFCRibbonGallery *in_ECX;
  CSimpleStringT<wchar_t,0> local_14 [12];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x8a11bd;
  CMFCRibbonGallery::SetACCData(in_ECX,param_1,param_2);
  CStringT<>();
  local_8 = 0;
  FUN_004059f0(local_14,L"RGB(%d, %d, %d)",in_ECX[0x378],in_ECX[0x379],in_ECX[0x37a]);
  ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)(param_2 + 4),local_14);
  FUN_00406b10();
  return 1;
}




/* vtable slots: CMFCRibbonColorButton[68], CMFCRibbonGallery[68], CMFCRibbonUndoButton[68] */
/* 008a131c  FUN_008a131c  36 bytes, 0 callers */

void FUN_008a131c(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00864b39(param_1);
  *(undefined4 *)(in_ECX + 0x370) = 0;
  *(undefined4 *)(in_ECX + 0x374) = 1;
  return;
}




/* vtable slots: CMFCRibbonColorButton[100], CMFCRibbonGallery[100], CMFCRibbonUndoButton[100] */
/* 008a137d  FUN_008a137d  39 bytes, 0 callers */

void FUN_008a137d(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x358) == 0) && (3 < *(int *)(in_ECX + 0x334))) {
    *(int *)(in_ECX + 0x334) = *(int *)(in_ECX + 0x334) + -1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x370) = 1;
  return;
}




/* vtable slots: CMFCRibbonColorButton[160], CMFCRibbonGallery[160], CMFCRibbonUndoButton[160] */
/* 008af178  Clear  114 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonGallery::Clear(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCRibbonGallery::Clear(CMFCRibbonGallery *this)

{
  int iVar1;
  
  iVar1 = *(int *)(this + 0x32c);
  if (iVar1 == 0) {
    iVar1 = *(int *)(this + 0xa4);
  }
  FUN_0082be73(iVar1);
  FUN_008b0e77();
  FUN_007bf7c0(0,0xffffffff);
  FUN_0042fb40(0,0xffffffff);
  FUN_007bf7c0(0,0xffffffff);
  FUN_007e7dd4();
  *(undefined4 *)(this + 0x33c) = 0;
  *(undefined4 *)(this + 0x340) = 0;
  *(undefined4 *)(this + 0x34c) = 0;
  return;
}




/* vtable slots: CMFCRibbonColorButton[63], CMFCRibbonGallery[63], CMFCRibbonUndoButton[63] */
/* 008af6ae  GetCompactSize  43 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual class CSize __thiscall CMFCRibbonGallery::GetCompactSize(class CDC *)
   
   Library: Visual Studio 2015 Release */

CDC * __thiscall CMFCRibbonGallery::GetCompactSize(CMFCRibbonGallery *this,CDC *param_1)

{
  int iVar1;
  undefined4 in_stack_00000008;
  
  iVar1 = IsButtonLook(this);
  if (iVar1 == 0) {
    FUN_00867aa7(param_1,in_stack_00000008);
  }
  else {
    FUN_0086715f(param_1,in_stack_00000008);
  }
  return param_1;
}




/* vtable slots: CMFCRibbonColorButton[113], CMFCRibbonGallery[113], CMFCRibbonUndoButton[113] */
/* 008af705  FUN_008af705  69 bytes, 0 callers */

int * FUN_008af705(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  if (0 < *(int *)(in_ECX + 0x1cc)) {
    puVar2 = (undefined4 *)FUN_00799cf8(*(int *)(in_ECX + 0x1cc) + -1);
    piVar4 = (int *)*puVar2;
    pcVar1 = *(code **)(*piVar4 + 0xe4);
    guard_check_icall();
    iVar3 = (*pcVar1)();
    if (iVar3 != 0) {
      return piVar4;
    }
  }
  piVar4 = (int *)FUN_0086371c();
  return piVar4;
}




/* vtable slots: CMFCRibbonColorButton[114], CMFCRibbonGallery[114], CMFCRibbonUndoButton[114] */
/* 008af74a  FUN_008af74a  106 bytes, 0 callers */

int FUN_008af74a(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  CMFCRibbonGallery *in_ECX;
  int local_8;
  
  iVar2 = CMFCRibbonGallery::IsButtonLook(in_ECX);
  if (iVar2 == 0) {
    local_8 = 0;
    if (0 < *(int *)(in_ECX + 0x1cc)) {
      do {
        puVar3 = (undefined4 *)FUN_00799cf8(local_8);
        pcVar1 = *(code **)(*(int *)*puVar3 + 0x1c8);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 != 0) {
          return iVar2;
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)(in_ECX + 0x1cc));
    }
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_008637c2();
  }
  return iVar2;
}




/* vtable slots: CMFCRibbonColorButton[165], CMFCRibbonGallery[165], CMFCRibbonUndoButton[165] */
/* 008af7b4  FUN_008af7b4  70 bytes, 0 callers */

int * FUN_008af7b4(int *param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(param_2 + 0x1c8);
  if (((iVar1 == -3) || (iVar1 == -2)) || (iVar1 == -1)) {
    iVar1 = FUN_004054a0(*(int *)(in_ECX + 0x70) + -0x10);
    *param_1 = iVar1 + 0x10;
  }
  else {
    CStringT<>(&DAT_00956338);
  }
  return param_1;
}




/* vtable slots: CMFCRibbonColorButton[163], CMFCRibbonGallery[163] */
/* 008af7fa  FUN_008af7fa  27 bytes, 0 callers */

void FUN_008af7fa(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 600);
  *param_1 = *(undefined4 *)(in_ECX + 0x254);
  param_1[1] = uVar1;
  return;
}




/* vtable slots: CMFCRibbonColorButton[118], CMFCRibbonGallery[118], CMFCRibbonUndoButton[118] */
/* 008af91d  FUN_008af91d  323 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int * FUN_008af91d(int *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  BOOL BVar3;
  undefined4 *puVar4;
  CObject *pCVar5;
  CMFCRibbonGallery *in_ECX;
  int local_38;
  int local_34;
  int local_24;
  int local_20;
  int local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar2 = CMFCRibbonGallery::IsButtonLook(in_ECX);
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x1d4);
    guard_check_icall(&local_24,param_2);
    (*pcVar1)();
    if (((local_24 == 0) && (local_20 == 0)) ||
       (BVar3 = IsRectEmpty((RECT *)(in_ECX + 0x74)), BVar3 != 0)) {
      *param_1 = 0;
      param_1[1] = 0;
      param_1[2] = 0;
      param_1[3] = 0;
    }
    else {
      local_38 = *(int *)(in_ECX + 0x7c) - local_24 / 2;
      local_34 = *(int *)(in_ECX + 0x80) - local_20 / 2;
      local_1c = local_34;
      if (0 < *(int *)(in_ECX + 0x1cc)) {
        puVar4 = (undefined4 *)FUN_00799cf8(*(int *)(in_ECX + 0x1cc) + -1);
        pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,
                                    (CObject *)*puVar4);
        if (pCVar5 != (CObject *)0x0) {
          local_18.left = *(LONG *)(pCVar5 + 0x74);
          local_18.top = *(LONG *)(pCVar5 + 0x78);
          local_18.right = *(LONG *)(pCVar5 + 0x7c);
          local_18.bottom = *(LONG *)(pCVar5 + 0x80);
          if ((*(int *)(pCVar5 + 0x1c8) == -3) && (BVar3 = IsRectEmpty(&local_18), BVar3 == 0)) {
            local_34 = local_18.bottom + -3;
            local_38 = (local_18.right + local_18.left) / 2;
            local_1c = local_34;
          }
        }
      }
      *param_1 = local_38;
      param_1[1] = local_34;
      param_1[2] = local_24 + local_38;
      param_1[3] = local_20 + local_1c;
    }
  }
  else {
    FUN_008677b0(param_1,param_2,param_3);
  }
  return param_1;
}




/* vtable slots: CMFCRibbonColorButton[112], CMFCRibbonGallery[112], CMFCRibbonUndoButton[112] */
/* 008afb62  FUN_008afb62  87 bytes, 0 callers */

int FUN_008afb62(void)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar4 = 0;
  if (0 < *(int *)(in_ECX + 0x1cc)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(iVar4);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x1c0);
      guard_check_icall();
      iVar3 = (*pcVar1)();
      if (iVar3 != 0) {
        return iVar3;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < *(int *)(in_ECX + 0x1cc));
  }
  return 0;
}




/* vtable slots: CMFCRibbonColorButton[62], CMFCRibbonGallery[62], CMFCRibbonUndoButton[62] */
/* 008afbd1  FUN_008afbd1  347 bytes, 0 callers */

int * FUN_008afbd1(int *param_1,undefined4 param_2)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  CMFCRibbonGallery *in_ECX;
  uint uVar5;
  int iVar6;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  pcVar1 = *(code **)(*(int *)in_ECX + 0x28c);
  guard_check_icall(&local_14);
  (*pcVar1)();
  iVar3 = 0x10;
  if (*(int *)(in_ECX + 0x88) != 0) {
    piVar2 = (int *)FUN_008721a4(&local_c,0);
    local_c = *piVar2;
    iVar3 = piVar2[1];
  }
  iVar6 = local_10;
  iVar4 = 3;
  uVar5 = (uint)(local_10 <= (iVar3 * 3) / 2);
  *(uint *)(in_ECX + 0x358) = uVar5;
  if ((*(int *)(in_ECX + 0x374) != 0) && (uVar5 == 0)) {
    *(undefined4 *)(in_ECX + 0x334) = 6;
    if ((*(int *)(in_ECX + 0x94) != 0) && (*(int *)(*(int *)(in_ECX + 0x94) + 0xeb4) == 0)) {
      *(undefined4 *)(in_ECX + 0x334) = 3;
    }
  }
  *(undefined4 *)(in_ECX + 0x374) = 0;
  iVar3 = CMFCRibbonGallery::IsButtonLook(in_ECX);
  if (iVar3 == 0) {
    if (*(int *)(in_ECX + 0x1cc) == 0) {
      FUN_008af44e();
      iVar6 = local_10;
    }
    piVar2 = &local_c;
    if (*(int *)(in_ECX + 0x88) == 0) {
      local_c = 0;
      local_8 = 0;
      local_10 = iVar6;
    }
    else {
      piVar2 = (int *)FUN_008721a4(piVar2,1);
    }
    if (*(int *)(in_ECX + 0x358) == 0) {
      iVar3 = local_10 + 0x12;
      local_14 = local_14 + 8;
    }
    else {
      if ((((*piVar2 != 0) || (piVar2[1] != 0)) && (local_10 != 0)) &&
         (iVar3 = (piVar2[1] * 2) / local_10, 2 < iVar3)) {
        iVar4 = iVar3;
      }
      iVar3 = iVar4 * local_10 + 6;
    }
    local_8 = *(int *)(in_ECX + 0x334) * local_14;
    pcVar1 = *(code **)(*(int *)in_ECX + 0x240);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    *param_1 = local_8 + 0xc + iVar4;
    param_1[1] = iVar3;
  }
  else {
    FUN_00867aa7(param_1,param_2);
  }
  return param_1;
}




/* vtable slots: CMFCRibbonColorButton[75], CMFCRibbonGallery[75], CMFCRibbonUndoButton[75] */
/* 008afdb5  FUN_008afdb5  189 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008afdb5(LONG param_1,LONG param_2)

{
  code *pcVar1;
  POINT pt;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  BOOL BVar5;
  undefined4 *puVar6;
  CMFCRibbonGallery *in_ECX;
  int local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pcVar1 = *(code **)(*(int *)in_ECX + 0xdc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    iVar2 = CMFCRibbonGallery::IsButtonLook(in_ECX);
    if (iVar2 != 0) {
      uVar3 = FUN_00863d1b(param_1,param_2);
      return uVar3;
    }
    local_1c = 0;
    if (0 < *(int *)(in_ECX + 0x1cc)) {
      do {
        piVar4 = (int *)FUN_00799cf8(local_1c);
        iVar2 = *piVar4;
        local_18.left = *(LONG *)(iVar2 + 0x74);
        local_18.top = *(LONG *)(iVar2 + 0x78);
        local_18.right = *(LONG *)(iVar2 + 0x7c);
        local_18.bottom = *(LONG *)(iVar2 + 0x80);
        pt.y = param_2;
        pt.x = param_1;
        BVar5 = PtInRect(&local_18,pt);
        if (BVar5 != 0) {
          puVar6 = (undefined4 *)FUN_00799cf8(local_1c);
          return *puVar6;
        }
        local_1c = local_1c + 1;
      } while (local_1c < *(int *)(in_ECX + 0x1cc));
    }
  }
  return 0;
}




/* vtable slots: CMFCRibbonColorButton[73], CMFCRibbonGallery[73], CMFCRibbonUndoButton[73] */
/* 008aff34  FUN_008aff34  516 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

CMFCRibbonGallery * FUN_008aff34(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  CObject *pCVar5;
  CMFCRibbonGallery *pCVar6;
  CMFCRibbonGallery *in_ECX;
  int iVar7;
  int iVar8;
  int *piVar9;
  int local_38;
  int local_34;
  int local_30;
  CMFCRibbonGallery *local_2c;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00867fa4(param_1);
  piVar9 = &local_38;
  *(undefined4 *)(in_ECX + 0x340) = 0;
  pcVar1 = *(code **)(*(int *)in_ECX + 0x28c);
  *(undefined4 *)(in_ECX + 0x33c) = 0;
  guard_check_icall(piVar9);
  (*pcVar1)();
  if (((local_38 == 0) || (local_34 == 0)) ||
     (iVar2 = CMFCRibbonGallery::IsButtonLook(in_ECX), iVar2 != 0)) {
    *(undefined4 *)(in_ECX + 0x330) = 0;
    *(undefined4 *)(in_ECX + 0x338) = 0;
    pCVar6 = (CMFCRibbonGallery *)FUN_008b0b9a();
  }
  else {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x240);
    guard_check_icall(piVar9);
    iVar2 = (*pcVar1)();
    local_2c = (CMFCRibbonGallery *)(iVar2 + 6);
    local_28.left = *(LONG *)(in_ECX + 0x74);
    local_28.top = *(LONG *)(in_ECX + 0x78);
    local_28.right = *(LONG *)(in_ECX + 0x7c);
    local_28.bottom = *(LONG *)(in_ECX + 0x80);
    iVar2 = *(int *)(in_ECX + 0x358);
    InflateRect(&local_28,0,(-(uint)(iVar2 != 0) & 4) - 4);
    local_28.right = local_28.right - (int)local_2c;
    iVar8 = (-(uint)(iVar2 != 0) & 0xfffffff8) + 8;
    iVar2 = (local_28.right - local_28.left) / (local_38 + iVar8);
    iVar8 = (local_28.bottom - local_28.top) / (local_34 + iVar8);
    *(int *)(in_ECX + 0x330) = iVar2;
    *(int *)(in_ECX + 0x338) = iVar8;
    if (iVar2 == 0) {
      *(undefined4 *)(in_ECX + 0x340) = 0;
    }
    else {
      iVar8 = *(int *)(in_ECX + 0x34c) / iVar2 - iVar8;
      *(int *)(in_ECX + 0x340) = iVar8;
      if (*(int *)(in_ECX + 0x34c) % iVar2 != 0) {
        *(int *)(in_ECX + 0x340) = iVar8 + 1;
      }
    }
    FUN_008b0b9a();
    local_18.left = *(LONG *)(in_ECX + 0x74);
    local_18.top = *(LONG *)(in_ECX + 0x78);
    local_18.right = *(LONG *)(in_ECX + 0x7c);
    local_18.bottom = *(LONG *)(in_ECX + 0x80);
    InflateRect(&local_18,-1,-3);
    pCVar6 = local_2c;
    iVar8 = local_18.right + -2;
    iVar3 = local_18.bottom - local_18.top;
    local_30 = iVar8 - (int)local_2c;
    local_2c = (CMFCRibbonGallery *)0x0;
    iVar2 = local_18.top;
    local_18.right = iVar8;
    if (0 < *(int *)(in_ECX + 0x1cc)) {
      do {
        pCVar6 = local_2c;
        puVar4 = (undefined4 *)FUN_00799cf8(local_2c);
        pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,
                                    (CObject *)*puVar4);
        iVar7 = iVar2;
        if ((pCVar5 != (CObject *)0x0) && (*(int *)(pCVar5 + 0x1c8) < 0)) {
          iVar7 = iVar3 / 3 + iVar2;
          if (pCVar6 == (CMFCRibbonGallery *)(*(int *)(in_ECX + 0x1cc) + -1)) {
            iVar7 = local_18.bottom;
          }
          *(int *)(pCVar5 + 0x74) = local_30;
          *(int *)(pCVar5 + 0x78) = iVar2;
          *(int *)(pCVar5 + 0x7c) = iVar8;
          *(int *)(pCVar5 + 0x80) = iVar7;
          pCVar6 = local_2c;
        }
        local_2c = (CMFCRibbonGallery *)((int)pCVar6 + 1);
        pCVar6 = in_ECX + 0x1c4;
        iVar2 = iVar7;
      } while ((int)local_2c < *(int *)(in_ECX + 0x1cc));
    }
  }
  return pCVar6;
}




/* vtable slots: CMFCRibbonColorButton[95], CMFCRibbonGallery[95], CMFCRibbonUndoButton[95] */
/* 008b03b2  FUN_008b03b2  314 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008b03b2(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 *puVar3;
  CMFCRibbonGallery *in_ECX;
  CMFCRibbonGallery *pCVar4;
  undefined1 local_38 [12];
  undefined4 local_2c;
  undefined4 local_28;
  CMFCRibbonGallery *local_24;
  undefined4 local_20;
  int *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_20 = param_1;
  local_24 = in_ECX;
  iVar2 = CMFCRibbonGallery::IsButtonLook(in_ECX);
  if (iVar2 == 0) {
    local_18.left = *(LONG *)(in_ECX + 0x74);
    local_18.top = *(LONG *)(in_ECX + 0x78);
    local_18.right = *(LONG *)(in_ECX + 0x7c);
    local_18.bottom = *(LONG *)(in_ECX + 0x80);
    InflateRect(&local_18,-1,-3);
    local_18.right = local_18.right + -2;
    local_1c = (int *)FUN_007c2574();
    pCVar4 = local_24;
    pcVar1 = *(code **)(*local_1c + 0x280);
    guard_check_icall(local_20,local_24,local_18.left,local_18.top,local_18.right,local_18.bottom);
    (*pcVar1)();
    pcVar1 = *(code **)(*(int *)pCVar4 + 0x28c);
    guard_check_icall(&local_2c);
    (*pcVar1)();
    if (0 < *(int *)(pCVar4 + 0x204)) {
      iVar2 = FUN_007c2511();
      CMFCToolBarImages::SetTransparentColor
                ((CMFCToolBarImages *)(pCVar4 + 0x200),*(ulong *)(iVar2 + 0x1c));
      FUN_007eb6ca(local_38,local_2c,local_28,0);
    }
    local_1c = (int *)0x0;
    if (0 < *(int *)(pCVar4 + 0x1cc)) {
      do {
        puVar3 = (undefined4 *)FUN_00799cf8(local_1c);
        pcVar1 = *(code **)(*(int *)*puVar3 + 0x17c);
        guard_check_icall(local_20);
        (*pcVar1)();
        local_1c = (int *)((int)local_1c + 1);
        pCVar4 = local_24;
      } while ((int)local_1c < *(int *)(local_24 + 0x1cc));
    }
    if (0 < *(int *)(pCVar4 + 0x204)) {
      FUN_007e98b8(local_38);
    }
  }
  else {
    FUN_00868468(param_1);
  }
  return;
}




/* vtable slots: CMFCRibbonColorButton[142], CMFCRibbonGallery[142], CMFCRibbonUndoButton[142] */
/* 008b0721  OnEnable  70 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCRibbonGallery::OnEnable(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCRibbonGallery::OnEnable(CMFCRibbonGallery *this,int param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(this + 0x1cc)) {
    do {
      piVar1 = (int *)FUN_00799cf8(iVar2);
      iVar2 = iVar2 + 1;
      *(uint *)(*piVar1 + 0xd4) = (uint)(param_1 == 0);
    } while (iVar2 < *(int *)(this + 0x1cc));
  }
  return;
}




/* vtable slots: CMFCRibbonColorButton[119], CMFCRibbonGallery[119], CMFCRibbonUndoButton[119] */
/* 008b0872  FUN_008b0872  10 bytes, 0 callers */

void FUN_008b0872(void)

{
  FUN_00869530(1);
  return;
}




/* vtable slots: CMFCRibbonColorButton[125], CMFCRibbonGallery[125], CMFCRibbonUndoButton[125] */
/* 008b08db  FUN_008b08db  14 bytes, 0 callers */

void FUN_008b08db(void)

{
  int in_ECX;
  
  CMFCToolBarImages::Mirror((CMFCToolBarImages *)(in_ECX + 0x200));
  return;
}




/* vtable slots: CMFCRibbonColorButton[137], CMFCRibbonGallery[137], CMFCRibbonUndoButton[137] */
/* 008b08e9  FUN_008b08e9  103 bytes, 0 callers */

void FUN_008b08e9(undefined4 param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 *puVar3;
  CObject *pCVar4;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1cc);
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      return;
    }
    puVar3 = (undefined4 *)FUN_00799cf8(iVar1);
    pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCRibbonGalleryIcon_009a0628,
                                (CObject *)*puVar3);
  } while ((pCVar4 == (CObject *)0x0) || (*(int *)(pCVar4 + 0x1c8) != -3));
  *(undefined4 *)(pCVar4 + 0xcc) = param_1;
  pcVar2 = *(code **)(*(int *)pCVar4 + 0x1b8);
  guard_check_icall();
  (*pcVar2)();
  return;
}




/* vtable slots: CMFCRibbonColorButton[89], CMFCRibbonGallery[89], CMFCRibbonUndoButton[89] */
/* 008b1168  FUN_008b1168  95 bytes, 0 callers */

void FUN_008b1168(undefined4 param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 local_8;
  
  FUN_00869e57(param_1);
  local_8 = 0;
  if (0 < *(int *)(in_ECX + 0x1cc)) {
    do {
      puVar2 = (undefined4 *)FUN_00799cf8(local_8);
      pcVar1 = *(code **)(*(int *)*puVar2 + 0x164);
      guard_check_icall(param_1);
      (*pcVar1)();
      local_8 = local_8 + 1;
    } while (local_8 < *(int *)(in_ECX + 0x1cc));
  }
  return;
}



