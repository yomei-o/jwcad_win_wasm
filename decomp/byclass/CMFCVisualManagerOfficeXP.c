/* CMFCVisualManagerOfficeXP -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCVisualManagerOfficeXP[1] */
/* 008a3b37  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCVisualManagerOfficeXP::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCVisualManagerOfficeXP::_scalar_deleting_destructor_
          (CMFCVisualManagerOfficeXP *this,uint param_1)

{
  ~CMFCVisualManagerOfficeXP(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x158);
    }
  }
  return this;
}




/* vtable slots: CMFCVisualManagerOfficeXP[99] */
/* 008a3e56  GetPropertyGridGroupColor  75 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual unsigned long __thiscall
   CMFCVisualManagerOfficeXP::GetPropertyGridGroupColor(class CMFCPropertyGridCtrl *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOfficeXP::GetPropertyGridGroupColor
          (CMFCVisualManagerOfficeXP *this,CMFCPropertyGridCtrl *param_1)

{
  int iVar1;
  ulong uVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_007c2511();
  if (*(int *)(iVar1 + 0x1ac) < 9) {
    uVar2 = CMFCVisualManager::GetPropertyGridGroupColor((CMFCVisualManager *)this,param_1);
  }
  else {
    if (*(int *)(param_1 + 0x394) == 0) {
      iVar1 = FUN_007c2511();
      uVar3 = *(undefined4 *)(iVar1 + 0x1c);
    }
    else {
      iVar1 = FUN_007c2511();
      uVar3 = *(undefined4 *)(iVar1 + 0x54);
    }
    uVar2 = FUN_008188f6(uVar3,0x5e);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOfficeXP[100] */
/* 008a3ea1  FUN_008a3ea1  37 bytes, 0 callers */

undefined4 FUN_008a3ea1(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_1 + 0x394) == 0) {
    iVar1 = FUN_007c2511();
    uVar2 = *(undefined4 *)(iVar1 + 0x20);
  }
  else {
    iVar1 = FUN_007c2511();
    uVar2 = *(undefined4 *)(iVar1 + 0x58);
  }
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOfficeXP[0] */
/* 008a3f2d  FUN_008a3f2d  6 bytes, 0 callers */

undefined ** FUN_008a3f2d(void)

{
  return &PTR_s_CMFCVisualManagerOfficeXP_0099fc08;
}




/* vtable slots: CMFCVisualManagerOfficeXP[116] */
/* 008a3f33  FUN_008a3f33  29 bytes, 0 callers */

void FUN_008a3f33(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xb8);
  *param_2 = *(undefined4 *)(in_ECX + 0xe4);
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[196] */
/* 008a400e  FUN_008a400e  9 bytes, 0 callers */

undefined4 FUN_008a400e(void)

{
  int iVar1;
  
  iVar1 = FUN_007c2511();
  return *(undefined4 *)(iVar1 + 0x6c);
}




/* vtable slots: CMFCVisualManagerOfficeXP[17] */
/* 008a4017  FUN_008a4017  841 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_008a4017(int *param_1,int param_2,int param_3,int param_4,int param_5,uint param_6,
                 int param_7)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  HBRUSH hbr;
  undefined4 uVar5;
  wchar_t *pwVar6;
  CSimpleStringT<wchar_t,0> *pCVar7;
  int *in_ECX;
  int *piVar8;
  int dy;
  int local_8c;
  int *local_88;
  code *local_84;
  int local_80;
  int local_7c;
  uint local_78;
  int *local_74;
  tagTEXTMETRICW local_70;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  int local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x84;
  local_8 = 0x8a4026;
  local_78 = param_6;
  local_8c = param_7;
  if ((param_7 != 0) && (*(int *)(param_7 + 0x8c) != 0)) {
    FUN_007f39fd(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    goto LAB_008a4358;
  }
  local_88 = in_ECX + 0x3b;
  local_74 = in_ECX;
  if ((local_88 == (int *)0x0) || (in_ECX[0x3c] == 0)) {
    pcVar1 = *(code **)(*in_ECX + 0x308);
    guard_check_icall();
    (*pcVar1)();
  }
  if ((param_7 == 0) || (iVar2 = FUN_0079d98a(&PTR_s_CDockablePane_00a00b9c), iVar2 == 0)) {
    local_7c = 0;
    if (param_7 != 0) goto LAB_008a40b5;
LAB_008a40ce:
    local_80 = 0;
  }
  else {
    local_7c = 1;
LAB_008a40b5:
    iVar2 = FUN_0079d98a(&PTR_s_CMFCMenuBar_00a00b00);
    if (iVar2 == 0) goto LAB_008a40ce;
    local_80 = 1;
  }
  local_24.left = param_2;
  local_24.top = param_3;
  local_24.right = param_4;
  local_24.bottom = param_5;
  if (local_7c == 0) {
    if (local_78 == 0) {
      local_24.bottom = (param_5 + param_3) / 2;
      dy = 0;
      iVar2 = -5;
      local_24.top = local_24.bottom + -1;
      local_24.bottom = local_24.bottom + 2;
    }
    else {
      local_24.right = (param_4 + param_2) / 2;
      dy = -5;
      iVar2 = 0;
      local_24.left = local_24.right + -1;
      local_24.right = local_24.right + 2;
    }
    InflateRect(&local_24,iVar2,dy);
  }
  else {
    InflateRect(&local_24,-4,0);
    local_78 = (uint)(local_78 == 0);
  }
  pcVar1 = *(code **)(*param_1 + 0x30);
  guard_check_icall(local_74[0x36]);
  uVar3 = (*pcVar1)();
  local_84 = *(code **)(*param_1 + 0x2c);
  if ((local_7c == 0) && (local_80 == 0)) {
    iVar2 = local_74[0x2e];
  }
  else {
    iVar2 = FUN_007c2511();
    iVar2 = *(int *)(iVar2 + 0x54);
  }
  guard_check_icall(iVar2);
  uVar4 = (*local_84)();
  piVar8 = local_88;
  if (local_78 == 0) {
    piVar8 = local_74 + 0x3d;
  }
  hbr = (HBRUSH)0x0;
  if (piVar8 != (int *)0x0) {
    hbr = (HBRUSH)piVar8[1];
  }
  FillRect((HDC)param_1[1],&local_24,hbr);
  if (local_7c != 0) {
    local_80 = FUN_0079f0b8(2);
    pcVar1 = *(code **)(*param_1 + 0x30);
    iVar2 = FUN_007c2511();
    guard_check_icall(*(undefined4 *)(iVar2 + 0x68));
    (*pcVar1)();
    uVar5 = FUN_008881a4(local_78);
    pcVar1 = *(code **)(*param_1 + 0x28);
    guard_check_icall(uVar5);
    local_84 = (code *)(*pcVar1)();
    CStringT<>();
    local_8 = 0;
    FUN_00792c64(&local_74);
    pwVar6 = (wchar_t *)
             ATL::operator+((wchar_t *)&local_88,
                            (CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                             *)&DAT_0095b620);
    local_8._0_1_ = 1;
    pCVar7 = (CSimpleStringT<wchar_t,0> *)
             ATL::operator+((CStringT<wchar_t,class_StrTraitMFC<wchar_t,class_ATL::ChTraitsOS<wchar_t>_>_>
                             *)&local_8c,pwVar6);
    local_8._0_1_ = 2;
    ATL::CSimpleStringT<wchar_t,0>::operator=((CSimpleStringT<wchar_t,0> *)&local_74,pCVar7);
    FUN_00406b10();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00406b10();
    local_34 = param_2;
    local_30 = param_3;
    local_2c = param_4;
    local_28 = param_5;
    GetTextMetricsW((HDC)param_1[2],&local_70);
    if (local_78 == 0) {
      local_34 = local_2c - (((param_4 - param_2) - local_70.tmHeight) + 1) / 2;
      local_30 = param_3;
      uVar5 = 0x100;
      local_28 = param_3;
    }
    else {
      local_30 = local_30 + (((param_5 - param_3) - local_70.tmHeight) + -1) / 2;
      uVar5 = 0;
    }
    FUN_007c2378(&local_74,&local_34,uVar5);
    pcVar1 = *(code **)(*param_1 + 0x28);
    guard_check_icall(local_84);
    (*pcVar1)();
    FUN_0079f0b8(local_80);
    local_8 = 0xffffffff;
    FUN_00406b10();
  }
  pcVar1 = *(code **)(*param_1 + 0x30);
  guard_check_icall(uVar3);
  (*pcVar1)();
  pcVar1 = *(code **)(*param_1 + 0x2c);
  guard_check_icall(uVar4);
  (*pcVar1)();
LAB_008a4358:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[111] */
/* 008a4360  FUN_008a4360  263 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_008a4360(CDC *param_1,LONG param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7)

{
  code *pcVar1;
  int iVar2;
  HBRUSH pHVar3;
  tagRECT *ptVar4;
  int in_ECX;
  ulong uVar5;
  ulong uVar6;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.top = param_3 + -1;
  local_18.left = param_2;
  local_18.right = param_4 + 1;
  local_18.bottom = param_5 + 1;
  if (param_7 == 1) {
    if (in_ECX == -0x124) {
      pHVar3 = (HBRUSH)0x0;
    }
    else {
      pHVar3 = *(HBRUSH *)(in_ECX + 0x128);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,pHVar3);
    CDC::Draw3dRect(param_1,&local_18,*(ulong *)(in_ECX + 0xe8),*(ulong *)(in_ECX + 0xe8));
    pcVar1 = *(code **)(*(int *)param_1 + 0x30);
    iVar2 = FUN_007c2511();
    guard_check_icall(*(undefined4 *)(iVar2 + 0x6c));
    (*pcVar1)();
  }
  else {
    if (param_7 == 2) {
      if (in_ECX == -0x11c) {
        pHVar3 = (HBRUSH)0x0;
      }
      else {
        pHVar3 = *(HBRUSH *)(in_ECX + 0x120);
      }
      FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,pHVar3);
      uVar5 = *(ulong *)(in_ECX + 0xe8);
      ptVar4 = &local_18;
      uVar6 = uVar5;
    }
    else {
      iVar2 = FUN_007c2511();
      pHVar3 = (HBRUSH)0x0;
      if (iVar2 != -0x98) {
        pHVar3 = *(HBRUSH *)(iVar2 + 0x9c);
      }
      FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,pHVar3);
      iVar2 = FUN_007c2511();
      uVar6 = *(ulong *)(iVar2 + 0x5c);
      iVar2 = FUN_007c2511();
      uVar5 = *(ulong *)(iVar2 + 0x5c);
      ptVar4 = (tagRECT *)&param_2;
    }
    CDC::Draw3dRect(param_1,ptVar4,uVar5,uVar6);
  }
  return 1;
}




/* vtable slots: CMFCVisualManagerOfficeXP[34] */
/* 008a4467  FUN_008a4467  565 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008a4467(CDC *param_1,CObject *param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  CObject *pCVar4;
  int iVar5;
  uint uVar6;
  BOOL BVar7;
  uint uVar8;
  AFX_GLOBAL_DATA *this;
  int *in_ECX;
  ulong uVar9;
  int *piVar10;
  CDrawingManager local_24 [4];
  uint local_20;
  int *local_1c;
  ulong local_18;
  uint local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  iVar3 = param_7;
  uStack_4 = 0x20;
  local_8 = 0x8a4473;
  if ((param_7 == 1) || (param_7 == 2)) {
    uVar9 = in_ECX[0x3a];
    local_1c = in_ECX;
    local_18 = uVar9;
    pCVar4 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,param_2);
    local_20 = (uint)(pCVar4 != (CObject *)0x0);
    if ((pCVar4 == (CObject *)0x0) ||
       ((*(int *)(pCVar4 + 0x6c) == 0 ||
        (iVar5 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938), iVar5 == 0)))) {
      uVar6 = 0;
    }
    else {
      uVar6 = 1;
    }
    local_14 = uVar6 ^ 1;
    piVar10 = local_1c;
    if ((local_20 != 0) && (uVar6 == 0)) {
      pcVar1 = *(code **)(*(int *)pCVar4 + 0x70);
      guard_check_icall();
      iVar5 = (*pcVar1)();
      uVar9 = local_18;
      piVar10 = local_1c;
      if (iVar5 != 0) {
        uVar2 = *(uint *)(pCVar4 + 0x8c);
        local_14 = 0;
        local_20 = uVar2;
        if ((uVar2 != 0) &&
           ((BVar7 = IsWindowVisible(*(HWND *)(uVar2 + 0x20)), BVar7 != 0 ||
            (uVar9 = local_18, piVar10 = local_1c, *(int *)(uVar2 + 0xf48) != 0)))) {
          local_18 = local_1c[0x39];
          pcVar1 = *(code **)(*local_1c + 0x30c);
          guard_check_icall(pCVar4,&param_3);
          piVar10 = local_1c;
          (*pcVar1)();
          uVar2 = local_20;
          uVar8 = FUN_00797acc();
          uVar9 = local_18;
          if ((piVar10[0x54] != 0) &&
             (((((uVar8 & 0x400000) == 0 && (DAT_00a00b24 != 0)) && (DAT_00a127ac == 0)) &&
              (iVar5 = FUN_007c2511(), uVar9 = local_18, 8 < *(int *)(iVar5 + 0x1ac))))) {
            this = (AFX_GLOBAL_DATA *)FUN_007c2511();
            iVar5 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
            uVar9 = local_18;
            if ((iVar5 == 0) && (*(int *)(uVar2 + 0xf44) == 0)) {
              CDrawingManager::CDrawingManager(local_24,param_1);
              local_8 = 0;
              FUN_00816e2b(param_3,param_4,param_5,param_6,piVar10[0x1f],100,0x4b,0,0,piVar10[0x2a],
                           1);
              local_8 = 0xffffffff;
              FUN_0081510b();
              uVar9 = local_18;
              piVar10 = local_1c;
            }
          }
        }
      }
    }
    if (iVar3 == 1) {
      if (((local_14 != 0) && (piVar10[0x35] != 0xffffffff)) &&
         (((*(uint *)(param_2 + 0x24) & 0x10000) == 0 &&
          ((5 < param_5 - param_3 && (5 < param_6 - param_4)))))) {
        uVar9 = piVar10[0x35];
      }
    }
    else if (iVar3 != 2) {
      return;
    }
    if ((uVar6 != 0) && ((*(uint *)(param_2 + 0x24) & 0x10000) != 0)) {
      if ((*(uint *)(param_2 + 0x24) & 0x800000) != 0) {
        uVar9 = piVar10[0x35];
      }
      param_6 = param_6 + 1;
    }
    CDC::Draw3dRect(param_1,(tagRECT *)&param_3,uVar9,uVar9);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[28] */
/* 008a49ec  OnDrawComboBorder  61 bytes, 1 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCVisualManagerOfficeXP::OnDrawComboBorder(class CDC
   *,class CRect,int,int,int,class CMFCToolBarComboBoxButton *)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOfficeXP::OnDrawComboBorder(CMFCVisualManagerOfficeXP *this,CDC *param_1)

{
  int in_stack_0000001c;
  int in_stack_00000020;
  
  if ((in_stack_00000020 != 0) || (in_stack_0000001c != 0)) {
    InflateRect((LPRECT)&stack0x00000008,-1,-1);
    CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(this + 0xe8),
                    *(ulong *)(this + 0xe8));
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[27] */
/* 008a4a29  FUN_008a4a29  447 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008a4a29(CDC *param_1,int param_2,LONG param_3,LONG param_4,int param_5,int param_6,
                 int param_7,int param_8)

{
  ulong uVar1;
  code *pcVar2;
  COLORREF CVar3;
  int iVar4;
  HBRUSH hbr;
  undefined4 uVar5;
  int *in_ECX;
  CDC *pCVar6;
  undefined4 local_24;
  CDC *local_20;
  COLORREF local_1c;
  CDrawingManager local_18 [4];
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x8a4a35;
  local_20 = param_1;
  local_14 = in_ECX;
  CVar3 = GetTextColor(*(HDC *)(param_1 + 8));
  pCVar6 = local_20;
  local_1c = CVar3;
  if ((param_7 == 0) && (param_8 == 0)) {
    iVar4 = FUN_007c2511();
    hbr = (HBRUSH)0x0;
    if (iVar4 != -0xd0) {
      hbr = *(HBRUSH *)(iVar4 + 0xd4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
    pCVar6 = param_1;
    if (DAT_00a12704 == 0) {
      iVar4 = FUN_007c2511();
      uVar1 = *(ulong *)(iVar4 + 0x50);
      iVar4 = FUN_007c2511();
      CDC::Draw3dRect(param_1,(tagRECT *)&param_2,*(ulong *)(iVar4 + 0x50),uVar1);
    }
    else {
      CDrawingManager::CDrawingManager(local_18,param_1);
      local_8 = 1;
      iVar4 = FUN_007c2511();
      FUN_00816b6a(&param_2,0xffffffff,*(undefined4 *)(iVar4 + 0x6c));
      local_8 = 0xffffffff;
      FUN_0081510b();
    }
  }
  else {
    pcVar2 = *(code **)(*in_ECX + 0x314);
    guard_check_icall(local_20,param_2,param_3,param_4,param_5,
                      in_ECX + (uint)(param_7 != 0) * 2 + 0x47,0);
    (*pcVar2)();
    if (DAT_00a12704 == 0) {
      iVar4 = FUN_0079efbc(local_14 + 0x51);
      if (iVar4 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      FUN_0079ec58(local_18,param_2,param_3);
      CDC::LineTo(pCVar6,param_2,param_5);
      FUN_0079efbc(iVar4);
      CVar3 = local_1c;
    }
    else {
      CDrawingManager::CDrawingManager(local_18,pCVar6);
      local_8 = 0;
      FUN_008168e5(param_2,param_3,param_2,param_5,local_14[0x3a]);
      local_8 = 0xffffffff;
      FUN_0081510b();
      CVar3 = local_1c;
    }
  }
  local_24 = 0;
  local_20 = (CDC *)0x0;
  if (param_6 == 0) {
    if ((param_7 == 0) || (param_8 == 0)) {
      uVar5 = 0;
    }
    else {
      uVar5 = 3;
    }
  }
  else {
    uVar5 = 1;
  }
  FUN_00814d1c(pCVar6,0,&param_2,uVar5,&local_24);
  pcVar2 = *(code **)(*(int *)pCVar6 + 0x30);
  guard_check_icall(CVar3);
  (*pcVar2)();
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[15] */
/* 008a4e85  FUN_008a4e85  915 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a4e85(CDC *param_1,CWnd *param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  code *pcVar2;
  uint uVar3;
  HBRUSH pHVar4;
  int iVar5;
  int iVar6;
  BOOL BVar7;
  int in_ECX;
  int iVar8;
  int yTop;
  int local_54;
  int local_4c;
  RECT local_48;
  tagRECT local_38;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar3 = FUN_00797acc();
  CDC::Draw3dRect(param_1,(tagRECT *)&param_3,*(ulong *)(in_ECX + 0xe4),*(ulong *)(in_ECX + 0xe4));
  InflateRect((LPRECT)&param_3,-1,-1);
  CDC::Draw3dRect(param_1,(tagRECT *)&param_3,*(ulong *)(in_ECX + 0xc0),*(ulong *)(in_ECX + 0xc0));
  local_48.right = 2;
  local_48.left = 1;
  local_48.top = 1;
  local_48.bottom = param_6 + -1;
  pHVar4 = (HBRUSH)0x0;
  if (in_ECX != -0xfc) {
    pHVar4 = *(HBRUSH *)(in_ECX + 0x100);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_48,pHVar4);
  iVar5 = FUN_0081d529();
  if ((((iVar5 != 0) && (*(int *)(iVar5 + 0x1160) != 0)) && ((uVar3 & 0x400000) == 0)) &&
     ((*(int *)(param_2 + 0x158) != 0 && (*(int *)(*(int *)(param_2 + 0x158) + 0xb4) != 0)))) {
    iVar5 = FUN_0081d529();
    local_28.left = 0;
    local_28.top = 0;
    local_28.right = 0;
    local_28.bottom = 0;
    GetWindowRect(*(HWND *)(iVar5 + 0x20),&local_28);
    local_38.left = 0;
    local_38.top = 0;
    local_38.right = 0;
    local_38.bottom = 0;
    GetWindowRect(*(HWND *)(param_2 + 0x20),&local_38);
    iVar6 = FUN_0081d46f(0);
    iVar5 = *(int *)(iVar6 + 0x58);
    iVar6 = *(int *)(iVar6 + 0x60);
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    SetRectEmpty(&local_18);
    iVar8 = param_3;
    if (local_38.left < local_28.left) {
      iVar8 = param_5;
    }
    yTop = param_4;
    if (local_38.top < local_28.top) {
      yTop = (iVar5 - iVar6) + param_6;
      iVar6 = param_6;
    }
    SetRect(&local_18,iVar8 + -1,yTop,iVar8 + 1,iVar6);
    BVar7 = IsRectEmpty(&local_18);
    if (BVar7 == 0) {
      pHVar4 = (HBRUSH)0x0;
      if (in_ECX != -0xfc) {
        pHVar4 = *(HBRUSH *)(in_ECX + 0x100);
      }
      FillRect(*(HDC *)(param_1 + 4),&local_18,pHVar4);
    }
  }
  if (DAT_00a127ac != 0) {
    return;
  }
  if (*(int *)(in_ECX + 0x14c) == 0) {
    return;
  }
  piVar1 = *(int **)(param_2 + 0x158);
  if (piVar1 == (int *)0x0) {
    return;
  }
  iVar5 = FUN_0081d529();
  if (iVar5 != 0) {
    return;
  }
  pcVar2 = *(code **)(*piVar1 + 0xe4);
  guard_check_icall();
  iVar5 = (*pcVar2)();
  if (iVar5 == 0) {
    return;
  }
  local_28.left = 0;
  local_28.top = 0;
  local_28.right = 0;
  local_28.bottom = 0;
  SetRectEmpty(&local_28);
  local_18.left = piVar1[0x15];
  local_18.top = piVar1[0x16];
  local_18.right = piVar1[0x17];
  local_18.bottom = piVar1[0x18];
  FUN_0079e8b8(&local_18);
  CWnd::ScreenToClient(param_2,&local_18);
  iVar5 = *(int *)(param_2 + 0xf30);
  if (iVar5 == 1) {
    local_4c = param_4;
    local_54 = param_4 + -1;
  }
  else {
    if (iVar5 != 2) {
      if (iVar5 == 3) {
        local_28.top = local_18.top + 1;
        local_28.left = param_3 + -1;
        local_28.bottom = local_18.bottom + -1;
        local_28.right = param_3;
        if ((param_6 - param_4) + 2 < local_28.bottom - local_28.top) {
          return;
        }
      }
      else if (iVar5 == 4) {
        local_28.top = local_18.top + 1;
        local_28.right = param_5 + 1;
        local_28.bottom = local_18.bottom + -1;
        local_28.left = param_5;
        if ((param_6 - param_4) + 2 < local_28.bottom - local_28.top) {
          return;
        }
      }
      goto LAB_008a51a6;
    }
    local_54 = param_6;
    local_4c = param_6 + 1;
  }
  local_28.left = local_18.left + 1;
  local_28.right = local_18.right + -1;
  local_28.top = local_54;
  local_28.bottom = local_4c;
  if ((param_5 - param_3) + 2 < local_28.right - local_28.left) {
    return;
  }
LAB_008a51a6:
  pHVar4 = (HBRUSH)0x0;
  local_38.left = param_3;
  local_38.top = param_4;
  local_38.right = param_5;
  local_38.bottom = param_6;
  InflateRect(&local_38,1,1);
  IntersectRect(&local_28,&local_28,&local_38);
  InflateRect(&local_18,1,1);
  IntersectRect(&local_28,&local_28,&local_18);
  if (in_ECX != -0xfc) {
    pHVar4 = *(HBRUSH *)(in_ECX + 0x100);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_28,pHVar4);
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[14] */
/* 008a599a  FUN_008a599a  313 bytes, 1 callers */

void FUN_008a599a(int *param_1,int *param_2,int *param_3)

{
  code *pcVar1;
  uint uVar2;
  COLORREF CVar3;
  int iVar4;
  
  if (param_2[0x23] == 0) {
    pcVar1 = *(code **)(*param_2 + 0x1c0);
    guard_check_icall();
    uVar2 = (*pcVar1)();
    if ((uVar2 & 0xf00) != 0) {
      CVar3 = GetBkColor((HDC)param_1[2]);
      if ((uVar2 & 0x100) != 0) {
        iVar4 = FUN_007c2511();
        FUN_007a500d(0,0,1,(param_3[3] - param_3[1]) + -1,*(undefined4 *)(iVar4 + 0x54));
      }
      if ((uVar2 & 0x200) != 0) {
        iVar4 = FUN_007c2511();
        FUN_007a500d(0,0,(param_3[2] - *param_3) + -1,1,*(undefined4 *)(iVar4 + 0x54));
      }
      if ((uVar2 & 0x400) != 0) {
        iVar4 = FUN_007c2511();
        FUN_007a500d(param_3[2],0,0xffffffff,param_3[3] - param_3[1],*(undefined4 *)(iVar4 + 0x54));
      }
      if ((uVar2 & 0x800) != 0) {
        iVar4 = FUN_007c2511();
        FUN_007a500d(0,param_3[3],(param_3[2] - *param_3) + -1,0xffffffff,
                     *(undefined4 *)(iVar4 + 0x54));
      }
      if ((uVar2 & 0x100) != 0) {
        *param_3 = *param_3 + 1;
      }
      if ((uVar2 & 0x200) != 0) {
        param_3[1] = param_3[1] + 1;
      }
      if ((uVar2 & 0x400) != 0) {
        param_3[2] = param_3[2] + -1;
      }
      if ((uVar2 & 0x800) != 0) {
        param_3[3] = param_3[3] + -1;
      }
      pcVar1 = *(code **)(*param_1 + 0x2c);
      guard_check_icall(CVar3);
      (*pcVar1)();
    }
  }
  else {
    FUN_007f4c2e(param_1,param_2,param_3);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[20] */
/* 008a5ad3  FUN_008a5ad3  193 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

undefined4 FUN_008a5ad3(CDC *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined **local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x10;
  local_8 = 0x8a5adf;
  iVar1 = FUN_007c2511();
  if (param_3 == 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x58);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 100);
  }
  FUN_0079df60(0,1,uVar2);
  local_8 = 0;
  local_18 = FUN_0079efbc(local_20);
  iVar1 = FUN_007c2511();
  if (param_3 == 0) {
    iVar1 = iVar1 + 0xd0;
  }
  else {
    iVar1 = iVar1 + 0xb8;
  }
  local_14 = FUN_0079efbc(iVar1);
  if (param_3 != 0) {
    InflateRect((LPRECT)&stack0x00000010,1,1);
  }
  CDC::RoundRect(param_1,(tagRECT *)&stack0x00000010,(tagPOINT)0x200000002);
  FUN_0079efbc(local_14);
  FUN_0079efbc(local_18);
  iVar1 = FUN_007c2511();
  if (param_3 == 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0x68);
  }
  else {
    uVar2 = *(undefined4 *)(iVar1 + 0x74);
  }
  local_20[0] = CPen::vftable;
  FUN_00416100();
  return uVar2;
}




/* vtable slots: CMFCVisualManagerOfficeXP[120] */
/* 008a5b94  OnDrawPopupWindowBorder  68 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCVisualManagerOfficeXP::OnDrawPopupWindowBorder(class CDC
   *,class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOfficeXP::OnDrawPopupWindowBorder(CMFCVisualManagerOfficeXP *this,CDC *param_1)

{
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(this + 0xe4),
                  *(ulong *)(this + 0xe4));
  InflateRect((LPRECT)&stack0x00000008,-1,-1);
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(this + 0xc0),
                  *(ulong *)(this + 0xc0));
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[121] */
/* 008a5c13  OnDrawPopupWindowCaption  45 bytes, 1 callers */

/* Library Function - Single Match
    protected: virtual unsigned long __thiscall
   CMFCVisualManagerOfficeXP::OnDrawPopupWindowCaption(class CDC *,class CRect,class
   CMFCDesktopAlertWnd *)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

ulong __thiscall
CMFCVisualManagerOfficeXP::OnDrawPopupWindowCaption(CMFCVisualManagerOfficeXP *this,int param_1)

{
  HBRUSH hbr;
  int iVar1;
  
  hbr = (HBRUSH)0x0;
  if (this != (CMFCVisualManagerOfficeXP *)0xfffffee4) {
    hbr = *(HBRUSH *)(this + 0x120);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  iVar1 = FUN_007c2511();
  return *(ulong *)(iVar1 + 0x68);
}




/* vtable slots: CMFCVisualManagerOfficeXP[171] */
/* 008a62bf  FUN_008a62bf  164 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008a62bf(CDC *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5,
                 int param_6)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  CDrawingManager local_24 [8];
  undefined1 local_1c [4];
  undefined4 local_18;
  int local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x14;
  local_8 = 0x8a62cb;
  local_18 = param_4;
  local_14 = param_6 + -1;
  iVar2 = (param_5 + param_3) / 2;
  if (DAT_00a12704 == 0) {
    iVar1 = FUN_0079efbc(in_ECX + 0x13c);
    if (iVar1 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    FUN_0079ec58(local_1c,iVar2,local_18);
    CDC::LineTo(param_1,iVar2,local_14);
    FUN_0079efbc(iVar1);
  }
  else {
    CDrawingManager::CDrawingManager(local_24,param_1);
    local_8 = 0;
    FUN_008168e5(iVar2,local_18,iVar2,local_14,*(undefined4 *)(in_ECX + 0xdc));
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[163] */
/* 008a63d8  FUN_008a63d8  301 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008a63d8(CDC *param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  code *pcVar4;
  code *pcVar5;
  ulong uVar6;
  int iVar7;
  int iVar8;
  AFX_GLOBAL_DATA *this;
  undefined4 uVar9;
  int *in_ECX;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar8 = param_3[0x1d];
  iVar1 = param_3[0x1e];
  iVar2 = param_3[0x1f];
  iVar3 = param_3[0x20];
  pcVar4 = *(code **)(*param_3 + 0xd0);
  guard_check_icall();
  iVar7 = (*pcVar4)();
  if (iVar7 != 0) {
    local_28.left = iVar8;
    local_28.top = iVar1;
    local_28.right = iVar2;
    local_28.bottom = iVar3;
    InflateRect(&local_28,-1,-1);
    pcVar4 = *(code **)(*in_ECX + 0x314);
    pcVar5 = *(code **)(*param_3 + 0xd8);
    guard_check_icall();
    iVar7 = (*pcVar5)();
    guard_check_icall(param_1,local_28.left,local_28.top,local_28.right,local_28.bottom,
                      (-(uint)(iVar7 != 0) & 8) + 0x11c + (int)in_ECX,0);
    (*pcVar4)();
    CDC::Draw3dRect(param_1,&local_28,in_ECX[0x3a],in_ECX[0x3a]);
  }
  local_18.left = iVar8;
  local_18.top = iVar1;
  local_18.right = iVar2;
  local_18.bottom = iVar3;
  InflateRect(&local_18,0,-2);
  local_18.left = local_18.right + -1;
  iVar8 = FUN_007c2511();
  uVar6 = *(ulong *)(iVar8 + 0x58);
  iVar8 = FUN_007c2511();
  CDC::Draw3dRect(param_1,&local_18,*(ulong *)(iVar8 + 0x58),uVar6);
  this = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar8 = AFX_GLOBAL_DATA::IsHighContrastMode(this);
  if (iVar8 == 0) {
    uVar9 = 0xffffffff;
  }
  else {
    iVar8 = FUN_007c2511();
    uVar9 = *(undefined4 *)(iVar8 + 0x68);
  }
  return uVar9;
}




/* vtable slots: CMFCVisualManagerOfficeXP[95] */
/* 008a6505  FUN_008a6505  173 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a6505(CDC *param_1,tagRECT *param_2,int param_3,undefined4 param_4,int param_5)

{
  tagRECT *ptVar1;
  int iVar2;
  HBRUSH pHVar3;
  undefined4 local_24;
  int local_20;
  tagRECT *local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = param_2;
  local_18.left = param_2->left;
  local_18.right = param_2->right;
  local_18.bottom = param_2->bottom;
  local_18.top = param_2->top - param_3;
  iVar2 = FUN_007c2511();
  pHVar3 = (HBRUSH)0x0;
  if (iVar2 != -200) {
    pHVar3 = *(HBRUSH *)(iVar2 + 0xcc);
  }
  FillRect(*(HDC *)(param_1 + 4),&local_18,pHVar3);
  ptVar1 = local_1c;
  if (param_5 != 0) {
    pHVar3 = (HBRUSH)0x0;
    if (local_20 != -0x11c) {
      pHVar3 = *(HBRUSH *)(local_20 + 0x120);
    }
    FillRect(*(HDC *)(param_1 + 4),local_1c,pHVar3);
    CDC::Draw3dRect(param_1,ptVar1,*(ulong *)(local_20 + 0xe8),*(ulong *)(local_20 + 0xe8));
  }
  local_24 = 0;
  local_20 = 0;
  FUN_00814d1c(param_1,param_4,ptVar1,0,&local_24);
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[18] */
/* 008a65b2  FUN_008a65b2  502 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a65b2(CDC *param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
                 int param_7)

{
  code *pcVar1;
  CDC *this;
  uint uVar2;
  int iVar3;
  int *piVar4;
  HWND pHVar5;
  CWnd *pCVar6;
  int iVar7;
  int *in_ECX;
  uint uVar8;
  undefined1 local_34 [8];
  int local_2c;
  CDC *local_28;
  int *local_24;
  uint local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_28 = param_1;
  if (*(int *)(param_2 + 0x8c) == 0) {
    local_24 = in_ECX;
    local_2c = FUN_0079efbc(in_ECX + 0x4f);
    if (local_2c == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_0078e714();
    }
    if (param_7 == 0) {
      local_1c = (param_6 + param_4) / 2;
      local_20 = param_5;
      uVar2 = FUN_0079d98a(&PTR_s_CMFCRibbonPanelMenuBar_009a1a6c);
      uVar8 = 0;
      if (uVar2 != 0) {
        uVar8 = uVar2 & ~-(uint)(*(int *)(param_2 + 0xddc) != 0);
      }
      iVar3 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938);
      param_4 = local_1c;
      iVar7 = local_1c;
      uVar2 = param_3;
      if (((iVar3 != 0) && (uVar8 == 0)) &&
         (iVar3 = FUN_0079d98a(&PTR_s_CMFCColorBar_00a007bc), param_4 = local_1c, iVar7 = local_1c,
         iVar3 == 0)) {
        iVar7 = *local_24;
        piVar4 = (int *)FUN_007fe1cf(local_34);
        pcVar1 = *(code **)(iVar7 + 0x2dc);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        iVar7 = *piVar4;
        local_18.left = 0;
        local_18.top = 0;
        local_18.right = 0;
        local_18.bottom = 0;
        GetClientRect(*(HWND *)(param_2 + 0x20),&local_18);
        if ((int)(local_18.right - local_20) < 0x32) {
          local_20 = local_18.right;
        }
        uVar2 = ~-(uint)(*(int *)(param_2 + 0xd40) != 0) & param_3 + 1 + iVar3 + iVar7;
        iVar3 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938);
        param_4 = local_1c;
        iVar7 = local_1c;
        if (iVar3 != 0) {
          pHVar5 = GetParent(*(HWND *)(param_2 + 0x20));
          pCVar6 = CWnd::FromHandle(pHVar5);
          param_4 = local_1c;
          iVar7 = local_1c;
          if (((pCVar6 != (CWnd *)0x0) &&
              (iVar3 = FUN_0079d98a(&PTR_s_CMFCPopupMenu_00a00790), param_4 = local_1c,
              iVar7 = local_1c, iVar3 != 0)) && (*(int *)(pCVar6 + 0x1168) == 0)) {
            pcVar1 = *(code **)(*local_24 + 0x2dc);
            guard_check_icall();
            iVar7 = (*pcVar1)();
            piVar4 = (int *)FUN_007fe1cf(local_34);
            uVar2 = iVar7 * 3 + (*piVar4 + 1) * 2 + param_3;
            param_4 = local_1c;
            iVar7 = local_1c;
          }
        }
      }
    }
    else {
      local_20 = (int)(param_5 + param_3) / 2;
      iVar7 = param_6 + -1;
      uVar2 = local_20;
    }
    this = local_28;
    FUN_0079ec58(local_34,uVar2,param_4);
    CDC::LineTo(this,local_20,iVar7);
    FUN_0079efbc(local_2c);
  }
  else {
    FUN_007f6e6e(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[23] */
/* 008a6a82  OnDrawStatusBarPaneBorder  121 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: virtual void __thiscall CMFCVisualManagerOfficeXP::OnDrawStatusBarPaneBorder(class
   CDC *,class CMFCStatusBar *,class CRect,unsigned int,unsigned int)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOfficeXP::OnDrawStatusBarPaneBorder
          (CMFCVisualManagerOfficeXP *this,CDC *param_1,undefined4 param_2,LONG param_4,LONG param_5
          ,LONG param_6,LONG param_7,undefined4 param_8,uint param_9)

{
  CDrawingManager local_1c [8];
  CMFCVisualManagerOfficeXP *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xc;
  local_8 = 0x8a6a8e;
  if ((param_9 & 0x100) == 0) {
    local_14 = this;
    if ((param_9 & 0x200) != 0) {
      CDrawingManager::CDrawingManager(local_1c,param_1);
      local_8 = 0;
      FUN_00818045(param_4,param_5,param_6,param_7,0xffffffff,0xffffffff,0,0xffffffff);
      local_8 = 0xffffffff;
      FUN_0081510b();
    }
    CDC::Draw3dRect(param_1,(tagRECT *)&param_4,*(ulong *)(local_14 + 0xe0),
                    *(ulong *)(local_14 + 0xe0));
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[61] */
/* 008a6afb  FUN_008a6afb  971 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_008a6afb(CDC *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 int param_7,int *param_8)

{
  code *pcVar1;
  int iVar2;
  int *in_ECX;
  int local_60;
  int local_5c;
  undefined **local_58 [2];
  undefined **local_50 [2];
  undefined **local_48 [2];
  undefined **local_40 [2];
  undefined1 local_38 [4];
  undefined1 local_34 [4];
  undefined1 local_30 [4];
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int *local_14;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x58;
  local_8 = 0x8a6b07;
  pcVar1 = *(code **)(*param_8 + 0x280);
  local_14 = in_ECX;
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    pcVar1 = *(code **)(*param_8 + 0x288);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*param_8 + 0x2a8);
      guard_check_icall();
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        pcVar1 = *(code **)(*param_8 + 0x28c);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        if (iVar2 == 0) {
          pcVar1 = *(code **)(*param_8 + 0x290);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          if (iVar2 == 0) {
            local_18 = 0;
            local_1c = 0;
            pcVar1 = *(code **)(*in_ECX + 0x10c);
            guard_check_icall(param_8,&local_20,&local_24,&local_28,local_38,local_34,local_30,
                              &local_18,&local_1c);
            (*pcVar1)();
            FUN_0079df60(0,1,local_20);
            local_8 = 0;
            FUN_0079df60(0,1,local_24);
            local_8._0_1_ = 1;
            FUN_0079df60(0,1,local_28);
            local_8 = CONCAT31(local_8._1_3_,2);
            local_2c = FUN_0079efbc(local_50);
            if (local_2c != 0) {
              pcVar1 = *(code **)(*param_8 + 0x20c);
              guard_check_icall();
              iVar2 = (*pcVar1)();
              if (param_6 != iVar2 + -1) {
                pcVar1 = *(code **)(*param_8 + 0x1a4);
                guard_check_icall();
                iVar2 = (*pcVar1)();
                if ((param_6 < iVar2 + -1) || (in_ECX[0x55] != 0)) {
                  FUN_0079ec58(local_58,param_4,param_3 + 3);
                  CDC::LineTo(param_1,param_4,param_5 + -3);
                }
              }
              if (param_7 != 0) {
                if (param_8[0x24] == 0) {
                  local_60 = param_4;
                  local_5c = param_5;
                  pcVar1 = *(code **)(*local_14 + 0xf8);
                  guard_check_icall(param_1,param_2,param_3 + -1,param_4,param_5,local_18,param_6,
                                    param_7,param_8);
                  (*pcVar1)();
                  FUN_0079efbc(local_48);
                  FUN_0079ec58(local_58,param_4,param_3);
                  CDC::LineTo(param_1,param_4,param_5);
                  CDC::LineTo(param_1,param_2,param_5);
                  FUN_0079efbc(local_40);
                  CDC::LineTo(param_1,param_2,param_3 + -2);
                  in_ECX = local_14;
                }
                else {
                  FUN_0079df60(0,1,in_ECX[0x30]);
                  local_5c = param_5 + 1;
                  local_8._0_1_ = 3;
                  local_60 = param_4;
                  pcVar1 = *(code **)(*local_14 + 0xf8);
                  guard_check_icall(param_1,param_2 + 1,param_3,param_4,local_5c,local_18,param_6,
                                    param_7,param_8);
                  (*pcVar1)();
                  FUN_0079efbc(local_48);
                  FUN_0079ec58(&local_60,param_4,param_5);
                  CDC::LineTo(param_1,param_4,param_3);
                  FUN_0079efbc(local_40);
                  CDC::LineTo(param_1,param_4,param_3);
                  CDC::LineTo(param_1,param_2,param_3);
                  CDC::LineTo(param_1,param_2,param_5);
                  local_8 = CONCAT31(local_8._1_3_,2);
                  local_58[0] = CPen::vftable;
                  FUN_00416100();
                  in_ECX = local_14;
                }
              }
              FUN_0079efbc(local_2c);
              if (param_8[0x4d] == 0) {
                if (param_7 == 0) {
                  iVar2 = in_ECX[0x31];
                }
                else {
                  iVar2 = FUN_007c2511();
                  iVar2 = *(int *)(iVar2 + 0x68);
                }
              }
              else {
                iVar2 = FUN_007c2511();
                iVar2 = *(int *)(iVar2 + 0x28);
              }
              pcVar1 = *(code **)(*in_ECX + 0xfc);
              guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,
                                iVar2);
              (*pcVar1)();
              local_40[0] = CPen::vftable;
              FUN_00416100();
              local_48[0] = CPen::vftable;
              FUN_00416100();
              local_50[0] = CPen::vftable;
              FUN_00416100();
              return;
            }
                    /* WARNING: Subroutine does not return */
            FUN_0078e714();
          }
        }
      }
    }
  }
  FUN_007f74b7(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[66] */
/* 008a6f50  FUN_008a6f50  139 bytes, 0 callers */

void FUN_008a6f50(CDC *param_1,tagRECT *param_2,CMFCButton *param_3,undefined4 param_4,int *param_5)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  ulong uVar3;
  ulong uVar4;
  
  pcVar1 = *(code **)(*param_5 + 0x280);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  if (iVar2 == 0) {
    if ((*(int *)(param_3 + 0xac) == 0) && (*(int *)(param_3 + 0xb4) == 0)) {
      return;
    }
    iVar2 = CMFCButton::IsPressed(param_3);
    if (iVar2 == 0) {
      iVar2 = FUN_007c2511();
      uVar3 = *(ulong *)(in_ECX + 0xd8);
      uVar4 = *(ulong *)(iVar2 + 0x60);
    }
    else {
      uVar4 = *(ulong *)(in_ECX + 0xd8);
      iVar2 = FUN_007c2511();
      uVar3 = *(ulong *)(iVar2 + 0x60);
    }
  }
  else {
    if ((*(int *)(param_3 + 0xac) == 0) && (*(int *)(param_3 + 0xb4) == 0)) {
      return;
    }
    iVar2 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar2 + 0x60);
    uVar4 = uVar3;
  }
  CDC::Draw3dRect(param_1,param_2,uVar3,uVar4);
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[94] */
/* 008a6fdb  FUN_008a6fdb  759 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* WARNING: Type propagation algorithm not settling */

void FUN_008a6fdb(CDC *param_1,code *param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  code *pcVar3;
  CDC *pCVar4;
  undefined1 local_48 [4];
  COLORREF local_44;
  undefined4 local_40;
  int local_3c [3];
  CDC *local_30;
  code *local_2c;
  code *local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x38;
  local_8 = 0x8a6fe7;
  local_3c[2] = param_3;
  local_2c = param_2;
  local_30 = param_1;
  if ((param_2 == (code *)0x0) || (param_3 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  local_24 = *(int *)(param_2 + 0xc);
  local_20 = *(int *)(param_2 + 0x10);
  local_1c = *(int *)(param_2 + 0x14);
  local_18 = *(int *)(param_2 + 0x18);
  if (*(int *)(param_2 + 0x3c) != 0) {
    iVar1 = FUN_007c2511();
    pCVar4 = local_30;
    uVar2 = FUN_0079efbc(iVar1 + 0xe8);
    FUN_0079ec58(local_48,local_24,(local_20 + local_18) / 2);
    CDC::LineTo(pCVar4,local_1c,(local_20 + local_18) / 2);
    FUN_0079efbc(uVar2);
    goto LAB_008a7072;
  }
  local_3c[0] = 0;
  local_3c[1] = 0;
  FUN_007fa90e(*(undefined4 *)(param_3 + 4),local_3c,local_3c + 1);
  pCVar4 = local_30;
  if ((-1 < *(int *)(param_2 + 0x1c)) && (0 < local_3c[0])) {
    if (local_30 == (CDC *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(local_30 + 4);
    }
    FUN_0079cf15(*(undefined4 *)(local_3c[2] + 4),*(undefined4 *)(param_2 + 0x1c),iVar1,local_24,
                 local_20,1);
  }
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 8) + 0x3c8);
  if (iVar1 == -1) {
    iVar1 = *(int *)(local_28 + 0x9c);
  }
  local_24 = local_24 + local_3c[0] + iVar1;
  local_3c[2] = *(int *)(param_2 + 0x24);
  local_44 = GetTextColor(*(HDC *)(pCVar4 + 8));
  if (local_3c[2] == 0) {
    local_28 = *(code **)(*(int *)pCVar4 + 0x28);
    if (*(int *)(param_2 + 0x40) == 0) {
      iVar1 = FUN_007c2511();
      iVar1 = iVar1 + 0x11c;
    }
    else {
      iVar1 = FUN_007c2511();
      iVar1 = iVar1 + 300;
    }
    guard_check_icall(iVar1);
    local_28 = (code *)(*local_28)();
    local_2c = *(code **)(*(int *)pCVar4 + 0x30);
    iVar1 = *(int *)(param_2 + 0x44);
    if (iVar1 == -1) {
      iVar1 = FUN_007c2511();
      iVar1 = *(int *)(iVar1 + 0x70);
    }
    guard_check_icall(iVar1);
    (*local_2c)();
  }
  else {
    if (*(int *)(param_2 + 0x38) == 0) {
      pcVar3 = *(code **)(*(int *)pCVar4 + 0x30);
      iVar1 = FUN_007c2511();
      iVar1 = *(int *)(iVar1 + 0x38);
LAB_008a71ca:
      guard_check_icall(iVar1);
      (*pcVar3)();
      pcVar3 = *(code **)(*(int *)pCVar4 + 0x28);
      iVar1 = FUN_007c2511();
      iVar1 = iVar1 + 0x11c;
    }
    else {
      local_28 = *(code **)(*(int *)pCVar4 + 0x30);
      if (param_4 == 0) {
        iVar1 = *(int *)(param_2 + 0x44);
        pcVar3 = local_28;
        if (iVar1 == -1) {
          iVar1 = FUN_007c2511();
          iVar1 = *(int *)(iVar1 + 0x70);
          pcVar3 = local_28;
        }
        goto LAB_008a71ca;
      }
      iVar1 = *(int *)(param_2 + 0x48);
      if (iVar1 == -1) {
        iVar1 = FUN_007c2511();
        iVar1 = *(int *)(iVar1 + 0x44);
      }
      pcVar3 = local_28;
      guard_check_icall(iVar1);
      (*pcVar3)();
      pcVar3 = *(code **)(*(int *)pCVar4 + 0x28);
      iVar1 = FUN_007c2511();
      iVar1 = iVar1 + 0x13c;
    }
    guard_check_icall(iVar1);
    local_28 = (code *)(*pcVar3)();
    param_2 = local_2c;
  }
  local_40 = FUN_0079f0b8(1);
  iVar1 = *(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 8);
  if (local_3c[2] == 0) {
    iVar1 = *(int *)(iVar1 + 0x388);
  }
  else {
    iVar1 = *(int *)(iVar1 + 900);
  }
  if (iVar1 == 0) {
    iVar1 = FUN_004054a0(*(int *)(param_2 + 8) + -0x10);
    local_2c = (code *)(iVar1 + 0x10);
    local_8 = 0;
    FUN_007fa476(10);
    FUN_007fa476(0xd);
    pcVar3 = *(code **)(*(int *)pCVar4 + 0x68);
    guard_check_icall(local_2c,*(undefined4 *)(local_2c + -0xc),&local_24,0x8024);
    (*pcVar3)();
    local_8 = 0xffffffff;
    FUN_00406b10();
    pCVar4 = local_30;
  }
  else {
    FUN_007c2378(param_2 + 8,&local_24,0x10);
  }
  FUN_0079f0b8(local_40);
  pcVar3 = *(code **)(*(int *)pCVar4 + 0x28);
  guard_check_icall(local_28);
  (*pcVar3)();
  pcVar3 = *(code **)(*(int *)pCVar4 + 0x30);
  guard_check_icall(local_44);
  (*pcVar3)();
LAB_008a7072:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[93] */
/* 008a72d3  FUN_008a72d3  3 bytes, 0 callers */

void FUN_008a72d3(void)

{
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[90] */
/* 008a72d6  FUN_008a72d6  751 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a72d6(int *param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  COLORREF CVar10;
  int *in_ECX;
  code *pcVar11;
  int local_48;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int *local_30;
  int *local_2c;
  int local_28;
  int local_24;
  int local_20;
  int iStack_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_2c = param_1;
  local_34 = param_2;
  if ((param_2 != 0) && (*(int *)(param_2 + 4) != 0)) {
    iVar8 = *(int *)(param_2 + 0x34);
    iVar2 = *(int *)(param_2 + 0x38);
    iVar3 = *(int *)(param_2 + 0x3c);
    iVar4 = *(int *)(param_2 + 0x40);
    local_30 = in_ECX;
    if ((*(int *)(param_2 + 0x5c) == 0) ||
       (((iVar2 - iVar4) - iVar8) + iVar3 <= *(int *)(param_2 + 0x54))) {
      bVar5 = false;
    }
    else {
      bVar5 = true;
      pcVar11 = *(code **)(*in_ECX + 0x16c);
      guard_check_icall(param_1,param_2,5,param_3,param_4,param_5);
      in_ECX = local_30;
      (*pcVar11)();
    }
    pcVar11 = *(code **)(*param_1 + 0x28);
    iVar6 = FUN_007c2511();
    guard_check_icall(iVar6 + 300);
    local_44 = (*pcVar11)();
    GetTextColor((HDC)param_1[2]);
    if ((param_5 == 0) || (param_3 == 0)) {
      pcVar11 = *(code **)(*param_1 + 0x30);
      iVar6 = *(int *)(local_34 + 0x60);
    }
    else {
      pcVar11 = *(code **)(*param_1 + 0x30);
      iVar6 = *(int *)(local_34 + 100);
    }
    if (iVar6 == -1) {
      iVar6 = FUN_007c2511();
      iVar6 = *(int *)(iVar6 + 0x70);
    }
    guard_check_icall(iVar6);
    uVar7 = (*pcVar11)();
    local_3c = FUN_0079f0b8(1);
    iVar6 = *(int *)(*(int *)(local_34 + 4) + 8);
    local_38 = *(int *)(iVar6 + 0x3bc);
    local_24 = *(int *)(iVar6 + 0x3c0);
    if (local_38 == -1) {
      local_38 = in_ECX[0x24];
    }
    local_28 = local_38;
    if (bVar5) {
      local_28 = *(int *)(local_34 + 0x54) + 5;
    }
    local_28 = local_28 + iVar8;
    if (local_24 == -1) {
      local_24 = local_30[0x25];
    }
    local_24 = iVar2 + local_24;
    iVar6 = local_38;
    if (param_5 != 0) {
      iVar6 = iVar4 - iVar2;
    }
    local_20 = local_28;
    if (local_28 <= iVar3 - iVar6) {
      local_20 = local_38;
      if (param_5 != 0) {
        local_20 = iVar4 - iVar2;
      }
      local_20 = iVar3 - local_20;
    }
    piVar1 = (int *)(local_34 + 8);
    iStack_1c = iVar4;
    FUN_007c2378(piVar1,&local_28,0x24);
    FUN_0079f0b8(local_3c);
    pcVar11 = *(code **)(*param_1 + 0x28);
    guard_check_icall(local_44);
    (*pcVar11)();
    pcVar11 = *(code **)(*param_1 + 0x30);
    guard_check_icall(uVar7);
    (*pcVar11)();
    if ((param_5 != 0) && (*(int *)(*piVar1 + -0xc) != 0)) {
      FUN_0081507c(&local_48);
      if (iVar8 <= iVar3 - local_48) {
        iVar8 = iVar3 - local_48;
      }
      local_14 = iVar2;
      if (iVar2 <= iVar4 - local_44) {
        local_14 = iVar4 - local_44;
      }
      if ((local_48 <= iVar3 - iVar8) && (local_44 <= iVar4 - local_14)) {
        local_18 = iVar8;
        local_10 = iVar3;
        local_c = iVar4;
        if (param_3 != 0) {
          iVar8 = FUN_007c2511();
          uVar7 = FUN_0079efbc(iVar8 + 0xd8);
          piVar1 = local_2c;
          uVar9 = FUN_0079efbc(local_30 + 0x47);
          CVar10 = GetBkColor((HDC)piVar1[2]);
          Rectangle((HDC)local_2c[1],local_18,local_14,local_10,local_c);
          pcVar11 = *(code **)(*local_2c + 0x2c);
          guard_check_icall(CVar10);
          (*pcVar11)();
          param_1 = local_2c;
          FUN_0079efbc(uVar7);
          FUN_0079efbc(uVar9);
        }
        local_40 = 0;
        local_3c = 0;
        if (*(int *)(local_34 + 0x30) == 0) {
          uVar7 = 7;
        }
        else {
          uVar7 = 0;
        }
        FUN_00814c80(param_1,uVar7,&local_18,0,&local_40);
      }
    }
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCVisualManagerOfficeXP[30] */
/* 008a75c6  FUN_008a75c6  466 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a75c6(CDC *param_1,int param_2,LONG param_3,int param_4,LONG param_5,int param_6)

{
  code *pcVar1;
  code *pcVar2;
  ulong uVar3;
  HBRUSH pHVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int *in_ECX;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined1 local_24 [4];
  int *local_20;
  code *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (in_ECX == (int *)0xfffffef4) {
    pHVar4 = (HBRUSH)0x0;
  }
  else {
    pHVar4 = (HBRUSH)in_ECX[0x44];
  }
  local_1c = (code *)in_ECX;
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,pHVar4);
  InflateRect((LPRECT)&param_2,-1,-1);
  pcVar1 = *(code **)(*in_ECX + 0x314);
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,
                    (int)in_ECX + (-(uint)(param_6 != 0) & 0x20) + 0xfc,0);
  (*pcVar1)();
  piVar5 = (int *)FUN_007fe1cf(local_2c);
  iVar8 = 0x14;
  if (0x13 < *piVar5 * 2) {
    piVar5 = (int *)FUN_007fe1cf(local_24);
    iVar8 = *piVar5 * 2;
  }
  local_18.left = param_2;
  local_18.top = param_3;
  local_18.right = param_4;
  local_18.bottom = param_5;
  InflateRect(&local_18,-(((param_4 - param_2) - iVar8) / 2),-1);
  pcVar1 = local_1c;
  local_20 = (int *)((int)local_1c + 0xec);
  if ((local_20 == (int *)0x0) || (*(int *)((int)local_1c + 0xf0) == 0)) {
    pcVar2 = *(code **)(*(int *)local_1c + 0x308);
    guard_check_icall();
    (*pcVar2)();
  }
  iVar8 = param_6;
  local_1c = *(code **)(*(int *)param_1 + 0x30);
  iVar6 = FUN_007c2511();
  if (iVar8 == 0) {
    uVar7 = *(undefined4 *)(iVar6 + 0x58);
  }
  else {
    uVar7 = *(undefined4 *)(iVar6 + 0x60);
  }
  guard_check_icall(uVar7);
  local_28 = (*local_1c)();
  local_1c = *(code **)(*(int *)param_1 + 0x2c);
  if (iVar8 == 0) {
    iVar6 = *(int *)((int)pcVar1 + 0xb8);
  }
  else {
    iVar6 = *(int *)((int)pcVar1 + 200);
  }
  guard_check_icall(iVar6);
  uVar7 = (*local_1c)();
  if (iVar8 != 0) {
    InflateRect(&local_18,0,-1);
  }
  pHVar4 = (HBRUSH)0x0;
  if (local_20 != (int *)0x0) {
    pHVar4 = (HBRUSH)local_20[1];
  }
  FillRect(*(HDC *)(param_1 + 4),&local_18,pHVar4);
  pcVar1 = *(code **)(*(int *)param_1 + 0x30);
  guard_check_icall(local_28);
  (*pcVar1)();
  pcVar1 = *(code **)(*(int *)param_1 + 0x2c);
  guard_check_icall(uVar7);
  (*pcVar1)();
  if (param_6 != 0) {
    iVar8 = FUN_007c2511();
    uVar3 = *(ulong *)(iVar8 + 0x60);
    iVar8 = FUN_007c2511();
    CDC::Draw3dRect(param_1,(tagRECT *)&param_2,*(ulong *)(iVar8 + 0x60),uVar3);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[122] */
/* 008a7798  FUN_008a7798  276 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a7798(int param_1)

{
  code *pcVar1;
  CMFCButton *pCVar2;
  int iVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  int *in_ECX;
  CMFCButton *in_stack_00000018;
  HBRUSH local_28;
  HBRUSH local_20;
  tagRECT local_18;
  uint local_8;
  
  pCVar2 = in_stack_00000018;
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  iVar3 = CMFCButton::IsPressed(in_stack_00000018);
  if (iVar3 == 0) {
    if ((*(int *)(pCVar2 + 0xb4) == 0) && (*(int *)(pCVar2 + 0xac) == 0)) {
      local_18.left = 0;
      local_18.top = 0;
      local_18.right = 0;
      local_18.bottom = 0;
      pHVar4 = GetParent(*(HWND *)(pCVar2 + 0x20));
      pCVar5 = CWnd::FromHandle(pHVar4);
      GetClientRect(*(HWND *)(pCVar5 + 0x20),&local_18);
      pHVar4 = GetParent(*(HWND *)(pCVar2 + 0x20));
      pCVar5 = CWnd::FromHandle(pHVar4);
      MapWindowPoints(*(HWND *)(pCVar5 + 0x20),*(HWND *)(pCVar2 + 0x20),(LPPOINT)&local_18,2);
      pcVar1 = *(code **)(*in_ECX + 0x1dc);
      guard_check_icall(param_1,local_18.left,local_18.top,local_18.right,local_18.bottom);
      (*pcVar1)();
      return;
    }
    FUN_0079de5e(in_ECX[0x32]);
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,local_28);
  }
  else {
    FUN_0079de5e(in_ECX[0x33]);
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,local_20);
  }
  FUN_00416100();
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[60] */
/* 008a78ac  FUN_008a78ac  120 bytes, 1 callers */

void FUN_008a78ac(int param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int *param_6)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  HBRUSH hbr;
  
  piVar2 = param_6;
  pcVar1 = *(code **)(*param_6 + 0x280);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
    hbr = (HBRUSH)0x0;
    if (piVar2[0x4d] == 0) {
      iVar3 = in_ECX + 0x114;
    }
    else {
      iVar3 = FUN_007c2511();
      iVar3 = iVar3 + 0x98;
    }
    if (iVar3 != 0) {
      hbr = *(HBRUSH *)(iVar3 + 4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  }
  else {
    FUN_007f9665(param_1,param_2,param_3,param_4,param_5,piVar2);
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[65] */
/* 008a7924  FUN_008a7924  220 bytes, 1 callers */

void FUN_008a7924(int param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,
                 CMFCButton *param_6,int *param_7)

{
  code *pcVar1;
  CMFCButton *pCVar2;
  int iVar3;
  HBRUSH pHVar4;
  int *in_ECX;
  int *piVar5;
  
  piVar5 = param_7;
  pcVar1 = *(code **)(*param_7 + 0x280);
  guard_check_icall();
  iVar3 = (*pcVar1)();
  pCVar2 = param_6;
  if (iVar3 == 0) {
    pHVar4 = (HBRUSH)0x0;
    if (piVar5[0x4d] == 0) {
      if (in_ECX != (int *)0xfffffeec) {
        pHVar4 = (HBRUSH)in_ECX[0x46];
      }
    }
    else {
      iVar3 = FUN_007c2511();
      if (iVar3 != -0x98) {
        pHVar4 = *(HBRUSH *)(iVar3 + 0x9c);
      }
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,pHVar4);
  }
  else {
    iVar3 = CMFCButton::IsPressed(param_6);
    if (iVar3 == 0) {
      if (*(int *)(pCVar2 + 0xb4) == 0) {
        iVar3 = FUN_007c2511();
        piVar5 = (int *)(iVar3 + 0xd0);
      }
      else {
        piVar5 = in_ECX + 0x47;
      }
    }
    else {
      piVar5 = in_ECX + 0x49;
    }
    pHVar4 = (HBRUSH)0x0;
    if (piVar5 != (int *)0x0) {
      pHVar4 = (HBRUSH)piVar5[1];
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,pHVar4);
    pcVar1 = *(code **)(*in_ECX + 0x314);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,piVar5,0);
    (*pcVar1)();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[13] */
/* 008a7a00  FUN_008a7a00  622 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a7a00(int param_1,CObject *param_2,int param_3,LONG param_4,LONG param_5,LONG param_6,
                 int param_7,LONG param_8,LONG param_9,LONG param_10)

{
  code *pcVar1;
  CObject *pCVar2;
  HWND pHVar3;
  CWnd *pCVar4;
  BOOL BVar5;
  int iVar6;
  int *piVar7;
  RECT *lprc;
  HBRUSH hbr;
  int *in_ECX;
  HBRUSH hbr_00;
  bool bVar8;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CReBar_0098511c,param_2);
  if (pCVar2 != (CObject *)0x0) {
LAB_008a7c3a:
    iVar6 = *in_ECX;
    guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6);
    (**(code **)(iVar6 + 0x1c))();
    return;
  }
  pHVar3 = GetParent(*(HWND *)(param_2 + 0x20));
  pCVar4 = CWnd::FromHandle(pHVar3);
  pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CReBar_0098511c,(CObject *)pCVar4);
  if (pCVar2 != (CObject *)0x0) goto LAB_008a7c3a;
  BVar5 = IsRectEmpty((RECT *)&param_7);
  if (BVar5 != 0) {
    param_7 = param_3;
    param_8 = param_4;
    param_9 = param_5;
    param_10 = param_6;
  }
  pcVar1 = (code *)**(undefined4 **)param_2;
  guard_check_icall();
  iVar6 = (*pcVar1)();
  if ((iVar6 == 0) || (iVar6 = FUN_0079d960(&PTR_s_CMFCMenuBar_00a00b00), iVar6 != 0)) {
LAB_008a7c29:
    FUN_007f970e(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10,0)
    ;
    return;
  }
  iVar6 = FUN_0079d960(&PTR_s_CMFCOutlookBarPane_00a006a0);
  hbr_00 = (HBRUSH)0x0;
  if ((iVar6 != 0) &&
     (pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCOutlookBarPane_00a006a0,param_2),
     *(int *)(pCVar2 + 0xd54) != 0)) goto LAB_008a7c29;
  iVar6 = FUN_0079d960(&PTR_s_CMFCColorBar_00a007bc);
  if (iVar6 == 0) {
    iVar6 = FUN_0079d960(&PTR_s_CMFCPopupMenuBar_00a00938);
    if (iVar6 != 0) {
      hbr = (HBRUSH)0x0;
      if (in_ECX != (int *)0xfffffef4) {
        hbr = (HBRUSH)in_ECX[0x44];
      }
      FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_7,hbr);
      pCVar2 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCPopupMenuBar_00a00938,param_2);
      if (*(int *)(pCVar2 + 0xd40) != 0) {
        return;
      }
      local_18.left = param_3;
      local_18.top = param_4;
      local_18.right = param_5;
      local_18.bottom = param_6;
      local_18.right = FUN_0085358c();
      local_18.right = local_18.right + local_18.left;
      InflateRect(&local_18,0,-1);
      if (in_ECX != (int *)0xffffff04) {
        hbr_00 = (HBRUSH)in_ECX[0x40];
      }
      lprc = &local_18;
      goto LAB_008a7b20;
    }
    iVar6 = FUN_0079d960(&PTR_s_CMFCToolBar_00a005c4);
    if (iVar6 == 0) {
      iVar6 = FUN_0079d960(&PTR_s_CAutoHideDockSite_009a2e90);
      if (iVar6 == 0) goto LAB_008a7c29;
      piVar7 = in_ECX + 0x45;
      bVar8 = piVar7 == (int *)0x0;
    }
    else {
      if (*(int *)(param_2 + 0x8c) != 0) goto LAB_008a7c29;
      piVar7 = in_ECX + 0x3f;
      bVar8 = piVar7 == (int *)0x0;
    }
  }
  else {
    if (*(int *)(param_2 + 0x8c) != 0) goto LAB_008a7c29;
    piVar7 = (int *)((-(uint)(*(int *)(param_2 + 0xdf8) != 0) & 0xfffffff0) + 0x10c + (int)in_ECX);
    bVar8 = piVar7 == (int *)0x0;
  }
  if (!bVar8) {
    hbr_00 = (HBRUSH)piVar7[1];
  }
  lprc = (RECT *)&param_7;
LAB_008a7b20:
  FillRect(*(HDC *)(param_1 + 4),lprc,hbr_00);
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[33] */
/* 008a7c6e  FUN_008a7c6e  381 bytes, 1 callers */

void FUN_008a7c6e(undefined4 param_1,CObject *param_2,LONG param_3,LONG param_4,LONG param_5,
                 LONG param_6,int param_7)

{
  code *pcVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  CObject *pCVar5;
  int iVar6;
  uint uVar7;
  int *in_ECX;
  int *piVar8;
  
  iVar4 = param_7;
  bVar2 = true;
  bVar3 = true;
  if (((param_7 == 1) || (param_7 == 2)) &&
     ((DAT_00a127ac == 0 || ((DAT_00a127b0 != 0 || (*(int *)(param_2 + 0x3c) != 0)))))) {
    pCVar5 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBarMenuButton_00a00a14,param_2);
    if ((pCVar5 == (CObject *)0x0) ||
       ((*(int *)(pCVar5 + 0x6c) == 0 ||
        (iVar6 = FUN_0079d98a(&PTR_s_CMFCPopupMenuBar_00a00938), iVar6 == 0)))) {
      bVar2 = false;
      bVar3 = false;
      if (in_ECX[0x18] == 0) {
        return;
      }
    }
    if (((*(uint *)(param_2 + 0x24) & 0x20000) == 0) || (iVar6 = 0x124, bVar2)) {
      iVar6 = 0x11c;
    }
    piVar8 = (int *)(iVar6 + (int)in_ECX);
    if ((pCVar5 != (CObject *)0x0) && (!bVar3)) {
      pcVar1 = *(code **)(*(int *)pCVar5 + 0x70);
      guard_check_icall();
      iVar6 = (*pcVar1)();
      if (iVar6 != 0) {
        pcVar1 = *(code **)(*in_ECX + 0x30c);
        guard_check_icall(pCVar5,&param_3);
        (*pcVar1)();
        piVar8 = in_ECX + 0x3f;
      }
    }
    uVar7 = *(uint *)(param_2 + 0x24) & 0x10000;
    if (uVar7 != 0) {
      piVar8 = in_ECX + (uint)(iVar4 != 2) * 2 + 0x49;
    }
    if ((pCVar5 != (CObject *)0x0) && ((*(uint *)(param_2 + 0x24) & 0x40000) != 0)) {
      piVar8 = in_ECX + 0x43;
    }
    if ((iVar4 == 1) || (iVar4 == 2)) {
      if (uVar7 == 0) {
        InflateRect((LPRECT)&param_3,-1,-1);
      }
      pcVar1 = *(code **)(*in_ECX + 0x314);
      guard_check_icall(param_1,param_3,param_4,param_5,param_6,piVar8,param_2);
      (*pcVar1)();
    }
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[78] */
/* 008a7ec6  FUN_008a7ec6  308 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_008a7ec6(CDC *param_1,uint param_2,LONG param_3,LONG param_4,LONG param_5,int param_6)

{
  code *pcVar1;
  int *piVar2;
  HBRUSH hbr;
  int iVar3;
  int *in_ECX;
  undefined4 uVar4;
  HBRUSH hbr_00;
  undefined1 local_28 [4];
  int local_24;
  int *local_20;
  CDC *local_1c;
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = param_1;
  local_20 = in_ECX;
  FUN_007c2511();
  iVar3 = *in_ECX;
  piVar2 = (int *)FUN_007fe1cf(local_28);
  pcVar1 = *(code **)(iVar3 + 0x2dc);
  guard_check_icall();
  local_24 = (*pcVar1)();
  local_24 = local_24 + *piVar2;
  if (param_6 == 0) {
    hbr_00 = (HBRUSH)0x0;
    if (in_ECX == (int *)0xfffffef4) {
      hbr = (HBRUSH)0x0;
    }
    else {
      hbr = (HBRUSH)in_ECX[0x44];
    }
    FillRect(*(HDC *)(local_1c + 4),(RECT *)&param_2,hbr);
    local_18.right = param_2 + 2 + local_24;
    local_18.left = param_2;
    local_18.top = param_3;
    local_18.bottom = param_5;
    if (local_20 != (int *)0xffffff04) {
      hbr_00 = (HBRUSH)local_20[0x40];
    }
    FillRect(*(HDC *)(local_1c + 4),&local_18,hbr_00);
    iVar3 = FUN_007c2511();
    uVar4 = *(undefined4 *)(iVar3 + 0x68);
  }
  else {
    uVar4 = 0;
    param_2 = param_2 & ~-(uint)(in_ECX[0x18] != 0);
    pcVar1 = *(code **)(*in_ECX + 0x314);
    guard_check_icall(local_1c,param_2,param_3,param_4,param_5,local_20 + 0x47,0);
    (*pcVar1)();
    CDC::Draw3dRect(local_1c,(tagRECT *)&param_2,local_20[0x3a],local_20[0x3a]);
    if (((*(byte *)(local_20 + 0x32) < 0x81) || (*(byte *)((int)local_20 + 0xc9) < 0x81)) ||
       (*(byte *)((int)local_20 + 0xca) < 0x81)) {
      uVar4 = 0xffffff;
    }
  }
  return uVar4;
}




/* vtable slots: CMFCVisualManagerOfficeXP[197] */
/* 008a7ffa  OnFillHighlightedArea  111 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    protected: virtual void __thiscall CMFCVisualManagerOfficeXP::OnFillHighlightedArea(class CDC
   *,class CRect,class CBrush *,class CMFCToolBarButton *)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCVisualManagerOfficeXP::OnFillHighlightedArea(undefined4 param_1_00,CDC *param_1)

{
  HBRUSH hbr;
  int in_stack_00000018;
  CDrawingManager local_28 [8];
  undefined1 local_20 [4];
  undefined4 local_1c;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x18;
  local_8 = 0x8a8006;
  if (DAT_00a12704 == 0) {
    hbr = (HBRUSH)0x0;
    if (in_stack_00000018 != 0) {
      hbr = *(HBRUSH *)(in_stack_00000018 + 4);
    }
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  }
  else {
    GetObjectW(*(HANDLE *)(in_stack_00000018 + 4),0xc,local_20);
    CDrawingManager::CDrawingManager(local_28,param_1);
    local_8 = 0;
    FUN_00816b6a(&stack0x00000008,local_1c,0xffffffff);
    FUN_0081510b();
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[119] */
/* 008a811f  OnFillPopupWindowBackground  37 bytes, 1 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCVisualManagerOfficeXP::OnFillPopupWindowBackground(class
   CDC *,class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOfficeXP::OnFillPopupWindowBackground(CMFCVisualManagerOfficeXP *this,int param_1)

{
  HBRUSH hbr;
  
  hbr = (HBRUSH)0x0;
  if (this != (CMFCVisualManagerOfficeXP *)0xfffffef4) {
    hbr = *(HBRUSH *)(this + 0x110);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x00000008,hbr);
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[62] */
/* 008a86c8  FUN_008a86c8  275 bytes, 1 callers */

void FUN_008a86c8(int param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,int param_6,
                 undefined4 param_7,int param_8,int *param_9)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  HBRUSH hbr;
  undefined4 uVar6;
  HBRUSH local_14;
  
  piVar3 = param_9;
  uVar5 = param_7;
  iVar2 = param_6;
  pcVar1 = *(code **)(*param_9 + 0x1dc);
  uVar6 = param_7;
  guard_check_icall(param_7);
  iVar4 = (*pcVar1)();
  if ((iVar4 == -1) || (param_8 != 0)) {
    pcVar1 = *(code **)(*piVar3 + 0x288);
    guard_check_icall(uVar6);
    iVar4 = (*pcVar1)();
    if (iVar4 == 0) {
      pcVar1 = *(code **)(*piVar3 + 0x28c);
      guard_check_icall(uVar6);
      iVar4 = (*pcVar1)();
      if (iVar4 == 0) {
        pcVar1 = *(code **)(*piVar3 + 0x290);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        if (iVar4 == 0) {
          if (param_8 == 0) {
            return;
          }
          hbr = (HBRUSH)0x0;
          if (iVar2 != 0) {
            hbr = *(HBRUSH *)(iVar2 + 4);
          }
          FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
          return;
        }
      }
    }
    FUN_007fa014(param_1,param_2,param_3,param_4,param_5,iVar2,uVar5,param_8,piVar3);
  }
  else {
    pcVar1 = *(code **)(*piVar3 + 0x1dc);
    guard_check_icall(uVar5);
    uVar5 = (*pcVar1)();
    FUN_0079de5e(uVar5);
    FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,local_14);
    FUN_00416100();
  }
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[92] */
/* 008a87db  FUN_008a87db  73 bytes, 1 callers */

void FUN_008a87db(CDC *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_c [8];
  
  iVar1 = FUN_007c2511();
  uVar2 = FUN_0079efbc(iVar1 + 0xe8);
  FUN_0079ec58(local_c,param_2,param_3);
  CDC::LineTo(param_1,param_4,param_3);
  FUN_0079efbc(uVar2);
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[192] */
/* 008a88bf  OnHighlightQuickCustomizeMenuButton  62 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall
   CMFCVisualManagerOfficeXP::OnHighlightQuickCustomizeMenuButton(class CDC *,class
   CMFCToolBarMenuButton *,class CRect)
   
   Library: Visual Studio 2015 Release */

void __thiscall
CMFCVisualManagerOfficeXP::OnHighlightQuickCustomizeMenuButton
          (CMFCVisualManagerOfficeXP *this,CDC *param_1)

{
  HBRUSH hbr;
  
  hbr = (HBRUSH)0x0;
  if (this != (CMFCVisualManagerOfficeXP *)0xffffff04) {
    hbr = *(HBRUSH *)(this + 0x100);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&stack0x0000000c,hbr);
  CDC::Draw3dRect(param_1,(tagRECT *)&stack0x0000000c,*(ulong *)(this + 0xe4),
                  *(ulong *)(this + 0xe4));
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[40] */
/* 008a88fd  FUN_008a88fd  98 bytes, 1 callers */

void FUN_008a88fd(int param_1,int param_2,undefined4 param_3,int param_4)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  HBRUSH hbr;
  int *in_ECX;
  undefined1 local_c [8];
  
  param_2 = param_2 + -1;
  pcVar1 = *(code **)(*in_ECX + 0x2dc);
  guard_check_icall();
  iVar2 = (*pcVar1)();
  piVar3 = (int *)FUN_007fe1cf(local_c);
  param_4 = *piVar3 + 2 + param_2 + iVar2 * 2;
  hbr = (HBRUSH)0x0;
  if (in_ECX != (int *)0xfffffefc) {
    hbr = (HBRUSH)in_ECX[0x42];
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_2,hbr);
  return;
}




/* vtable slots: CMFCVisualManagerOfficeXP[12] */
/* 008a895f  FUN_008a895f  1641 bytes, 1 callers */

void FUN_008a895f(void)

{
  code *pcVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  int iVar5;
  AFX_GLOBAL_DATA *pAVar6;
  uint uVar7;
  COLORREF color;
  HBRUSH pHVar8;
  HPEN pHVar9;
  int *in_ECX;
  uint uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  undefined4 uVar14;
  undefined8 uVar13;
  undefined8 local_3c;
  double local_34;
  double local_2c;
  uint local_24;
  uint local_20;
  uint local_1c;
  COLORREF local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  guard_check_icall();
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x3f));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x41));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x43));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x47));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x49));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x4b));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x4d));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x4f));
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x45));
  iVar5 = FUN_007c2511();
  if (8 < *(int *)(iVar5 + 0x1ac)) {
    pAVar6 = (AFX_GLOBAL_DATA *)FUN_007c2511();
    iVar5 = AFX_GLOBAL_DATA::IsHighContrastMode(pAVar6);
    if (iVar5 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x310);
      guard_check_icall();
      uVar7 = (*pcVar1)();
      iVar5 = FUN_007c2511();
      local_20 = uVar7 >> 0x10 & 0xff;
      uVar10 = *(uint *)(iVar5 + 0x54);
      local_1c = uVar10 >> 0x10 & 0xff;
      local_c = (uVar7 & 0xffff) >> 8;
      local_10 = uVar10 & 0xff;
      local_8 = (uVar10 & 0xffff) >> 8;
      local_24 = uVar7 & 0xff;
      in_ECX[0x30] = (((local_1c * 0x24 + local_20 * 0xdb) / 0xff & 0xff) << 8 |
                     (local_8 * 0x24 + local_c * 0xdb) / 0xff & 0xff) << 8 |
                     (local_24 * 0xdb + local_10 * 0x24) / 0xff & 0xff;
      local_14 = uVar10;
      FUN_00818cce(uVar10,&local_3c,&local_34,&local_2c);
      if (0.1 <= local_34) {
        dVar4 = local_2c * 0.5 + 0.5;
        if (1.0 < dVar4) {
          dVar4 = 1.0;
        }
        dVar2 = 1.0;
        dVar3 = local_34 + local_34;
        if (1.0 < dVar3) {
LAB_008a8b12:
          dVar3 = dVar2;
        }
      }
      else {
        dVar4 = (1.0 - local_2c) * 0.5 + local_2c;
        if (1.0 < dVar4) {
          dVar4 = 1.0;
        }
        dVar3 = 0.0;
        if (local_34 != 0.0) {
          dVar2 = local_34 + 0.1;
          dVar3 = 1.0;
          if (dVar2 <= 1.0) goto LAB_008a8b12;
        }
      }
      local_18 = FUN_00817d46(local_3c,dVar4,dVar3);
      uVar7 = (((local_1c * 0xd7 + local_20 * 0x28) / 0xff & 0xff) << 8 |
              (local_8 * 0xd7 + local_c * 0x28) / 0xff & 0xff) << 8 |
              (local_10 * 0xd7 + local_24 * 0x28) / 0xff & 0xff;
      in_ECX[0x2e] = uVar7;
      iVar5 = FUN_008188f6(uVar7,0x5e);
      in_ECX[0x2f] = iVar5;
      iVar5 = FUN_008188f6(uVar10,0x37);
      in_ECX[0x31] = iVar5;
      iVar5 = FUN_007c2511();
      uVar10 = *(uint *)(iVar5 + 0x3c);
      FUN_00818cce(uVar10,&local_3c,&local_34,&local_2c);
      uVar7 = uVar10 >> 0x10 & 0xff;
      local_20 = (uVar10 & 0xffff) >> 8;
      local_10 = uVar10 & 0xff;
      uVar10 = (((uint)*(byte *)((int)in_ECX + 0xc1) * 0xb2 + local_20 * 0x4d) / 0xff & 0xff |
               (((uint)*(byte *)((int)in_ECX + 0xc2) * 0xb2 + uVar7 * 0x4d) / 0xff & 0xff) << 8) <<
               8 | ((uint)*(byte *)(in_ECX + 0x30) * 0xb2 + local_10 * 0x4d) / 0xff & 0xff;
      local_24 = uVar7;
      if (local_2c <= 0.8) {
        iVar5 = FUN_008188f6(uVar10,0x66);
        in_ECX[0x32] = iVar5;
        iVar5 = FUN_008188f6(iVar5,0x57);
        in_ECX[0x33] = iVar5;
        iVar5 = FUN_007c2511();
        iVar5 = *(int *)(iVar5 + 0x3c);
      }
      else {
        iVar5 = FUN_008188f6(uVar10,0x5b);
        in_ECX[0x32] = iVar5;
        iVar5 = FUN_008188f6(uVar10,0x62);
        in_ECX[0x33] = iVar5;
        uVar14 = 0x54;
        iVar5 = FUN_007c2511();
        iVar5 = FUN_008188f6(*(undefined4 *)(iVar5 + 0x3c),uVar14);
      }
      in_ECX[0x3a] = iVar5;
      iVar5 = FUN_008188f6((((uint)*(byte *)((int)in_ECX + 0xc1) * 5 + local_20) / 6 & 0xff |
                           (((uint)*(byte *)((int)in_ECX + 0xc2) * 5 + uVar7) / 6 & 0xff) << 8) << 8
                           | ((uint)*(byte *)(in_ECX + 0x30) * 5 + local_10) / 6 & 0xff,100);
      in_ECX[0x34] = iVar5;
      uVar13 = 0x3feb851eb851eb85;
      uVar12 = 0x3feb851eb851eb85;
      uVar11 = 0x3feb851eb851eb85;
      iVar5 = FUN_007c2511(0x3feb851eb851eb85,0x3feb851eb851eb85,0x3feb851eb851eb85);
      iVar5 = FUN_008189e7(*(undefined4 *)(iVar5 + 0x54),uVar11,uVar12,uVar13);
      in_ECX[0x37] = iVar5;
      iVar5 = FUN_007c2511();
      in_ECX[0x38] = *(int *)(iVar5 + 0x58);
      iVar5 = FUN_008188f6(local_14,0x37);
      in_ECX[0x39] = iVar5;
      uVar13 = 0x3feb333333333333;
      uVar12 = 0x3feb333333333333;
      uVar11 = 0x3feb333333333333;
      iVar5 = FUN_007c2511(0x3feb333333333333,0x3feb333333333333,0x3feb333333333333);
      color = FUN_008189e7(*(undefined4 *)(iVar5 + 0x58),uVar11,uVar12,uVar13);
      uVar14 = 0x6e;
      iVar5 = FUN_007c2511();
      iVar5 = FUN_008188f6(*(undefined4 *)(iVar5 + 0x58),uVar14);
      in_ECX[0x36] = iVar5;
      goto LAB_008a8ec4;
    }
  }
  iVar5 = FUN_007c2511();
  in_ECX[0x30] = *(int *)(iVar5 + 0x6c);
  iVar5 = FUN_007c2511();
  in_ECX[0x2e] = *(int *)(iVar5 + 0x1c);
  iVar5 = FUN_007c2511();
  if (*(int *)(iVar5 + 0x184) == 0) {
    iVar5 = FUN_007c2511();
    iVar5 = *(int *)(iVar5 + 0x1c);
    in_ECX[0x32] = iVar5;
    in_ECX[0x33] = iVar5;
    iVar5 = FUN_007c2511();
    in_ECX[0x34] = *(int *)(iVar5 + 0x6c);
    iVar5 = FUN_007c2511();
    iVar5 = *(int *)(iVar5 + 100);
  }
  else {
    iVar5 = FUN_007c2511();
    iVar5 = *(int *)(iVar5 + 0x3c);
    in_ECX[0x32] = iVar5;
    in_ECX[0x33] = iVar5;
    in_ECX[0x34] = iVar5;
    iVar5 = FUN_007c2511();
    iVar5 = *(int *)(iVar5 + 0x1c);
  }
  in_ECX[0x2f] = iVar5;
  iVar5 = FUN_007c2511();
  local_18 = *(COLORREF *)(iVar5 + 0x1c);
  iVar5 = FUN_007c2511();
  in_ECX[0x31] = *(int *)(iVar5 + 0x30);
  iVar5 = FUN_007c2511();
  in_ECX[0x37] = *(int *)(iVar5 + 0x20);
  iVar5 = FUN_007c2511();
  in_ECX[0x36] = *(int *)(iVar5 + 0x20);
  iVar5 = FUN_007c2511();
  in_ECX[0x38] = *(int *)(iVar5 + 0x20);
  iVar5 = FUN_007c2511();
  in_ECX[0x39] = *(int *)(iVar5 + 0x30);
  iVar5 = FUN_007c2511();
  color = *(COLORREF *)(iVar5 + 0x20);
  pAVar6 = (AFX_GLOBAL_DATA *)FUN_007c2511();
  iVar5 = AFX_GLOBAL_DATA::IsHighContrastMode(pAVar6);
  if (iVar5 == 0) {
    iVar5 = FUN_007c2511();
    iVar5 = *(int *)(iVar5 + 0x3c);
  }
  else {
    iVar5 = FUN_007c2511();
    iVar5 = *(int *)(iVar5 + 0x30);
  }
  in_ECX[0x3a] = iVar5;
LAB_008a8ec4:
  pHVar8 = CreateSolidBrush(in_ECX[0x2e]);
  Attach(pHVar8);
  pHVar8 = CreateSolidBrush(in_ECX[0x2f]);
  Attach(pHVar8);
  pHVar8 = CreateSolidBrush(in_ECX[0x30]);
  Attach(pHVar8);
  pHVar8 = CreateSolidBrush(in_ECX[0x32]);
  Attach(pHVar8);
  pHVar8 = CreateSolidBrush(in_ECX[0x33]);
  Attach(pHVar8);
  pHVar8 = CreateSolidBrush(in_ECX[0x34]);
  Attach(pHVar8);
  pHVar8 = CreateSolidBrush(local_18);
  Attach(pHVar8);
  pHVar9 = CreatePen(0,1,in_ECX[0x37]);
  Attach(pHVar9);
  pHVar8 = CreateSolidBrush(color);
  Attach(pHVar8);
  in_ECX[0x35] = -1;
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x51));
  pHVar9 = CreatePen(0,1,in_ECX[0x3a]);
  Attach(pHVar9);
  return;
}



