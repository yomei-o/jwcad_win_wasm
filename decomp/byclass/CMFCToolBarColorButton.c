/* CMFCToolBarColorButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarColorButton[1] */
/* 008226cd  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarColorButton::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarColorButton::_scalar_deleting_destructor_(CMFCToolBarColorButton *this,uint param_1)

{
  CMFCToolBarButton::~CMFCToolBarButton((CMFCToolBarButton *)this);
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




/* vtable slots: CMFCToolBarColorButton[0] */
/* 008232c6  FUN_008232c6  6 bytes, 0 callers */

undefined ** FUN_008232c6(void)

{
  return &PTR_s_CMFCToolBarColorButton_00a007d8;
}




/* vtable slots: CMFCToolBarColorButton[10] */
/* 008234d3  OnChangeParentWnd  40 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarColorButton::OnChangeParentWnd(class CWnd *)
   
   Libraries: Visual Studio 2010 Release, Visual Studio 2012 Release */

void __thiscall
CMFCToolBarColorButton::OnChangeParentWnd(CMFCToolBarColorButton *this,CWnd *param_1)

{
  CObject *pCVar1;
  
  FUN_00881617(param_1);
  pCVar1 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCColorBar_00a007bc,(CObject *)param_1);
  *(CObject **)(this + 0x8c) = pCVar1;
  return;
}




/* vtable slots: CMFCToolBarColorButton[6] */
/* 00823608  FUN_00823608  1268 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00823608(CDC *param_1,int *param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  uint uVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  CDC *pCVar6;
  ulong uVar7;
  int *piVar8;
  CPalette *local_6c;
  undefined **local_68;
  code *local_64;
  uint local_60;
  undefined **local_5c;
  code *local_58;
  undefined **local_54;
  code *local_50;
  int *local_4c;
  CDC *local_48;
  int local_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0x823614;
  local_6c = (CPalette *)0x0;
  local_48 = param_1;
  local_50 = (code *)param_2;
  local_4c = in_ECX;
  if (in_ECX[0x23] != 0) {
    local_6c = (CPalette *)FUN_0082481a(param_1);
  }
  uVar1 = in_ECX[9];
  if (in_ECX[0x1d] != 0) {
    in_ECX[9] = uVar1 | 0x10000;
  }
  if ((param_6 == 0) || (in_ECX[0x20] != 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  local_60 = uVar1 & 0x40000;
  FUN_0088114d(local_48,local_50,uVar3,0);
  if (((uVar1 & 0x40000) == 0) && (in_ECX[0x20] == 0)) {
    pcVar2 = *(code **)(*in_ECX + 0x54);
    guard_check_icall();
    iVar4 = (*pcVar2)();
    if ((iVar4 != 0) && ((param_7 != 0 && (param_5 == 0)))) {
      if ((in_ECX[9] & 0x30000U) == 0) {
        if ((param_6 != 0) && ((in_ECX[9] & 0x110000U) == 0)) {
          local_64 = (code *)FUN_007c2574();
          local_58 = *(code **)(*(int *)local_64 + 0x88);
          guard_check_icall(local_48,local_4c,*(int *)local_50,*(int *)((int)local_50 + 4),
                            *(int *)((int)local_50 + 8),*(int *)((int)local_50 + 0xc),2);
          (*local_58)();
        }
      }
      else {
        local_58 = (code *)FUN_007c2574();
        local_64 = *(code **)(*(int *)local_58 + 0x88);
        guard_check_icall(local_48,local_4c,*(int *)local_50,*(int *)((int)local_50 + 4),
                          *(int *)((int)local_50 + 8),*(int *)((int)local_50 + 0xc),1);
        (*local_64)();
      }
    }
  }
  local_34.left = *(LONG *)local_50;
  local_34.top = *(int *)((int)local_50 + 4);
  local_34.right = *(int *)((int)local_50 + 8);
  local_34.bottom = *(int *)((int)local_50 + 0xc);
  InflateRect(&local_34,-DAT_00a12218,-DAT_00a1221c);
  piVar8 = local_4c;
  if (((local_4c[0x1f] == 0) && (local_4c[0x1e] == 0)) &&
     (local_58 = (code *)(local_4c + 0x20), *(int *)local_58 == 0)) {
    if (local_60 == 0) {
      FUN_0079de5e(((*(byte *)((int)local_4c + 0x72) | 0x200) << 8 |
                   (uint)*(byte *)((int)local_4c + 0x71)) << 8 | (uint)*(byte *)(local_4c + 0x1c));
      local_8 = 2;
      uVar3 = FUN_0079efbc(&local_54);
      iVar4 = FUN_007c2511();
      uVar5 = FUN_0079efbc(iVar4 + 0xe8);
      local_34.right = local_34.right + -1;
      local_34.bottom = local_34.bottom + -1;
      Rectangle(*(HDC *)(local_48 + 4),local_34.left,local_34.top,local_34.right,local_34.bottom);
      FUN_0079efbc(uVar5);
      FUN_0079efbc(uVar3);
      local_8 = 0xffffffff;
      local_54 = CBrush::vftable;
      FUN_00416100();
      piVar8 = local_4c;
    }
  }
  else {
    local_44 = *(int *)local_50;
    iStack_40 = *(int *)((int)local_50 + 4);
    iStack_3c = *(int *)((int)local_50 + 8);
    iStack_38 = *(int *)((int)local_50 + 0xc);
    if ((local_4c[0x1e] != 0) && (local_4c[0x1c] != -1)) {
      local_24.left = local_34.left;
      local_24.top = local_34.top;
      local_24.right = local_34.right;
      local_24.bottom = local_34.bottom;
      InflateRect(&local_24,-(DAT_00a12218 + 1),-(DAT_00a1221c + 1));
      local_24.right = local_24.left + (local_24.bottom - local_24.top);
      if (local_60 == 0) {
        FUN_0079de5e(((*(byte *)((int)local_4c + 0x72) | 0x200) << 8 |
                     (uint)*(byte *)((int)local_4c + 0x71)) << 8 | (uint)*(byte *)(local_4c + 0x1c))
        ;
        local_8 = 0;
        iVar4 = FUN_007c2511();
        FUN_0079df60(0,1,*(undefined4 *)(iVar4 + 0x58));
        local_8 = CONCAT31(local_8._1_3_,1);
        uVar3 = FUN_0079efbc(&local_5c);
        uVar5 = FUN_0079efbc(&local_68);
        Rectangle(*(HDC *)(local_48 + 4),local_24.left,local_24.top,local_24.right,local_24.bottom);
        FUN_0079efbc(uVar5);
        FUN_0079efbc(uVar3);
        local_68 = CPen::vftable;
        FUN_00416100();
        local_8 = 0xffffffff;
        local_5c = CBrush::vftable;
        FUN_00416100();
      }
      else {
        iVar4 = FUN_007c2511();
        uVar7 = *(ulong *)(iVar4 + 0x58);
        iVar4 = FUN_007c2511();
        CDC::Draw3dRect(local_48,&local_24,*(ulong *)(iVar4 + 0x5c),uVar7);
        OffsetRect(&local_24,1,1);
        iVar4 = FUN_007c2511();
        uVar7 = *(ulong *)(iVar4 + 0x5c);
        iVar4 = FUN_007c2511();
        CDC::Draw3dRect(local_48,&local_24,*(ulong *)(iVar4 + 0x58),uVar7);
      }
      local_44 = DAT_00a12218 + local_24.right;
      piVar8 = local_4c;
    }
    pCVar6 = local_48;
    local_50 = *(code **)(*(int *)local_48 + 0x30);
    if (((piVar8[9] & 0x40000U) == 0) || (local_58 = (code *)(piVar8 + 0x20), *(int *)local_58 != 0)
       ) {
      iVar4 = FUN_007c2511();
      uVar3 = *(undefined4 *)(iVar4 + 0x68);
      local_58 = (code *)(piVar8 + 0x20);
    }
    else {
      iVar4 = FUN_007c2511();
      uVar3 = *(undefined4 *)(iVar4 + 0x38);
    }
    guard_check_icall(uVar3);
    (*local_50)();
    local_50 = (code *)0x0;
    local_64 = (code *)(0x8025 - (uint)(*(int *)local_58 != 0));
    if (param_4 == 0) {
      pcVar2 = *(code **)(*(int *)pCVar6 + 0x28);
      iVar4 = FUN_007c2511();
      guard_check_icall(iVar4 + 0x11c);
      local_50 = (code *)(*pcVar2)();
      pCVar6 = local_48;
      if (local_50 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
    }
    FUN_007c2378(piVar8 + 0xb,&local_44,local_64);
    if (local_50 != (code *)0x0) {
      pcVar2 = *(code **)(*(int *)pCVar6 + 0x28);
      guard_check_icall(local_50);
      (*pcVar2)();
    }
  }
  pCVar6 = local_48;
  if ((piVar8[0x1f] == 0) && (*(int *)local_58 == 0)) {
    if (local_60 == 0) {
      iVar4 = FUN_007c2511();
      uVar7 = *(ulong *)(iVar4 + 0x58);
    }
    else {
      iVar4 = FUN_007c2511();
      uVar7 = *(ulong *)(iVar4 + 0x58);
      iVar4 = FUN_007c2511();
      CDC::Draw3dRect(local_48,&local_34,*(ulong *)(iVar4 + 0x5c),uVar7);
      OffsetRect(&local_34,1,1);
      iVar4 = FUN_007c2511();
      uVar7 = *(ulong *)(iVar4 + 0x5c);
    }
    iVar4 = FUN_007c2511();
    pCVar6 = local_48;
    CDC::Draw3dRect(local_48,&local_34,*(ulong *)(iVar4 + 0x58),uVar7);
  }
  if (local_6c != (CPalette *)0x0) {
    CDC::SelectPalette(pCVar6,local_6c,0);
  }
  piVar8[9] = uVar1;
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCToolBarColorButton[31] */
/* 0082411d  FUN_0082411d  205 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

bool FUN_0082411d(undefined4 param_1,int param_2)

{
  LPCWSTR lpString2;
  int iVar1;
  LPWSTR lpString1;
  int in_ECX;
  bool bVar2;
  LPCWSTR local_14 [3];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 4;
  local_8 = 0x824129;
  if ((((*(uint *)(in_ECX + 0x24) & 0x40000) == 0) && (DAT_00a005ec != 0)) && (param_2 != 0)) {
    iVar1 = FUN_004054a0(*(int *)(in_ECX + 0x2c) + -0x10);
    local_14[0] = (LPCWSTR)(iVar1 + 0x10);
    local_8 = 0;
    if (((*(int *)(in_ECX + 0x78) == 0) && (*(int *)(in_ECX + 0x7c) == 0)) &&
       ((*(int *)(in_ECX + 0x80) == 0 &&
        (iVar1 = Lookup(*(undefined4 *)(in_ECX + 0x70),local_14), iVar1 == 0)))) {
      FUN_004059f0(local_14,L"Hex={%02X,%02X,%02X}",*(undefined1 *)(in_ECX + 0x70),
                   *(undefined1 *)(in_ECX + 0x71),*(undefined1 *)(in_ECX + 0x72));
    }
    lpString2 = local_14[0];
    lpString1 = (LPWSTR)FUN_00905194(*(int *)(local_14[0] + -6) + 1,2);
    *(LPWSTR *)(param_2 + 0x24) = lpString1;
    bVar2 = lpString1 != (LPWSTR)0x0;
    if (bVar2) {
      lstrcpyW(lpString1,lpString2);
    }
    FUN_00406b10();
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}



