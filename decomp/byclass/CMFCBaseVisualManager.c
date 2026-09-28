/* CMFCBaseVisualManager -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCBaseVisualManager[1] */
/* 007f2732  `scalar_deleting_destructor'  54 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCBaseVisualManager::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCBaseVisualManager::_scalar_deleting_destructor_(CMFCBaseVisualManager *this,uint param_1)

{
  *(undefined ***)this = vftable;
  CleanUpThemes(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x50);
    }
  }
  return this;
}




/* vtable slots: CMFCBaseVisualManager[8], CMFCVisualManager[8], CMFCVisualManagerOffice2003[8], CMFCVisualManagerOffice2007[8], CMFCVisualManagerOfficeXP[8] */
/* 007f2afc  FUN_007f2afc  195 bytes, 0 callers */

undefined4 FUN_007f2afc(int param_1)

{
  int in_ECX;
  HDC hdc;
  int iVar1;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  int iStateId;
  
  if (*(HTHEME *)(in_ECX + 0x10) == (HTHEME)0x0) {
    return 0;
  }
  iVar1 = 2;
  if (in_stack_0000001c < 0) {
    iVar1 = 0;
  }
  else if ((in_stack_0000001c < 3) && (iVar1 = in_stack_0000001c, in_stack_0000001c == 1)) {
    iStateId = 5;
    goto LAB_007f2b30;
  }
  iStateId = (uint)(iVar1 == 2) * 8 + 1;
LAB_007f2b30:
  if (in_stack_00000020 == 0) {
    if (iVar1 == 1) {
      iStateId = 8;
    }
    else {
      iStateId = (uint)(iVar1 == 2) * 8 + 4;
    }
  }
  else if (in_stack_00000024 == 0) {
    if (in_stack_00000018 != 0) {
      if (iVar1 == 1) {
        iStateId = 6;
      }
      else {
        iStateId = (uint)(iVar1 == 2) * 8 + 2;
      }
    }
  }
  else if (iVar1 == 1) {
    iStateId = 7;
  }
  else {
    iStateId = (uint)(iVar1 == 2) * 8 + 3;
  }
  if (param_1 == 0) {
    hdc = (HDC)0x0;
  }
  else {
    hdc = *(HDC *)(param_1 + 4);
  }
  DrawThemeBackground(*(HTHEME *)(in_ECX + 0x10),hdc,3,iStateId,(LPCRECT)&stack0x00000008,
                      (LPCRECT)0x0);
  return 1;
}




/* vtable slots: CMFCBaseVisualManager[6], CMFCVisualManager[6], CMFCVisualManagerOffice2003[6], CMFCVisualManagerOffice2007[6], CMFCVisualManagerOfficeXP[6] */
/* 007f2bbf  FUN_007f2bbf  82 bytes, 0 callers */

undefined4 FUN_007f2bbf(CDC *param_1)

{
  ulong uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int in_stack_0000001c;
  int in_stack_00000020;
  
  if (*(int *)(in_ECX + 4) == 0) {
    uVar2 = 0;
  }
  else {
    if ((in_stack_00000020 != 0) || (in_stack_0000001c != 0)) {
      InflateRect((LPRECT)&stack0x00000008,-1,-1);
      iVar3 = FUN_007c2511();
      uVar1 = *(ulong *)(iVar3 + 0x3c);
      iVar3 = FUN_007c2511();
      CDC::Draw3dRect(param_1,(tagRECT *)&stack0x00000008,*(ulong *)(iVar3 + 0x3c),uVar1);
    }
    uVar2 = 1;
  }
  return uVar2;
}




/* vtable slots: CMFCBaseVisualManager[5], CMFCVisualManager[5], CMFCVisualManagerOffice2003[5], CMFCVisualManagerOffice2007[5], CMFCVisualManagerOfficeXP[5] */
/* 007f2c16  DrawComboDropButton  84 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseVisualManager::DrawComboDropButton(class CDC *,class
   CRect,int,int,int)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

int __thiscall CMFCBaseVisualManager::DrawComboDropButton(CMFCBaseVisualManager *this,int param_1)

{
  int iVar1;
  HDC hdc;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  
  if (*(HTHEME *)(this + 0x18) == (HTHEME)0x0) {
    iVar1 = 0;
  }
  else {
    if (in_stack_00000018 == 0) {
      if (in_stack_0000001c == 0) {
        iVar1 = (in_stack_00000020 != 0) + 1;
      }
      else {
        iVar1 = 3;
      }
    }
    else {
      iVar1 = 4;
    }
    if (param_1 == 0) {
      hdc = (HDC)0x0;
    }
    else {
      hdc = *(HDC *)(param_1 + 4);
    }
    DrawThemeBackground(*(HTHEME *)(this + 0x18),hdc,1,iVar1,(LPCRECT)&stack0x00000008,(LPCRECT)0x0)
    ;
    iVar1 = 1;
  }
  return iVar1;
}




/* vtable slots: CMFCBaseVisualManager[3], CMFCVisualManager[3], CMFCVisualManagerOffice2003[3], CMFCVisualManagerOffice2007[3], CMFCVisualManagerOfficeXP[3] */
/* 007f2c6a  FUN_007f2c6a  225 bytes, 0 callers */

undefined4
FUN_007f2c6a(int param_1,LONG param_2,LONG param_3,LONG param_4,LONG param_5,CMFCButton *param_6)

{
  code *pcVar1;
  CMFCButton *this;
  int iVar2;
  LRESULT LVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  HDC hdc;
  int in_ECX;
  int local_8;
  
  this = param_6;
  if (*(int *)(in_ECX + 0x10) != 0) {
    local_8 = 1;
    iVar2 = FUN_00797c32();
    if (iVar2 == 0) {
      local_8 = 4;
    }
    else {
      iVar2 = CMFCButton::IsPressed(this);
      if ((iVar2 == 0) && (LVar3 = SendMessageW(*(HWND *)(this + 0x20),0xf0,0,0), LVar3 == 0)) {
        if (*(int *)(this + 0xb4) == 0) {
          pHVar4 = GetFocus();
          pCVar5 = CWnd::FromHandle(pHVar4);
          if (pCVar5 == (CWnd *)this) {
            local_8 = 5;
          }
        }
        else {
          local_8 = 2;
        }
      }
      else {
        local_8 = 3;
      }
    }
    pcVar1 = *(code **)(*(int *)this + 0x174);
    guard_check_icall(param_1,param_2,param_3,param_4,param_5);
    (*pcVar1)();
    if (param_1 == 0) {
      hdc = (HDC)0x0;
    }
    else {
      hdc = *(HDC *)(param_1 + 4);
    }
    DrawThemeBackground(*(HTHEME *)(in_ECX + 0x10),hdc,1,local_8,(LPCRECT)&param_2,(LPCRECT)0x0);
    return 1;
  }
  return 0;
}




/* vtable slots: CMFCBaseVisualManager[9], CMFCVisualManager[9], CMFCVisualManagerOffice2003[9], CMFCVisualManagerOffice2007[9], CMFCVisualManagerOfficeXP[9] */
/* 007f2d50  DrawRadioButton  131 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCBaseVisualManager::DrawRadioButton(class CDC *,class
   CRect,int,int,int,int)
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCBaseVisualManager::DrawRadioButton(CMFCBaseVisualManager *this,int param_1)

{
  int iVar1;
  HDC hdc;
  int in_stack_00000018;
  int in_stack_0000001c;
  int in_stack_00000020;
  int in_stack_00000024;
  
  iVar1 = 0;
  if (*(HTHEME *)(this + 0x10) != (HTHEME)0x0) {
    iVar1 = (uint)(in_stack_0000001c != 0) * 4 + 1;
    if (in_stack_00000020 == 0) {
      iVar1 = (uint)(in_stack_0000001c != 0) * 4 + 4;
    }
    else if (in_stack_00000024 == 0) {
      if (in_stack_00000018 != 0) {
        iVar1 = (uint)(in_stack_0000001c != 0) * 4 + 2;
      }
    }
    else {
      iVar1 = (uint)(in_stack_0000001c != 0) * 4 + 3;
    }
    if (param_1 == 0) {
      hdc = (HDC)0x0;
    }
    else {
      hdc = *(HDC *)(param_1 + 4);
    }
    DrawThemeBackground(*(HTHEME *)(this + 0x10),hdc,2,iVar1,(LPCRECT)&stack0x00000008,(LPCRECT)0x0)
    ;
    iVar1 = 1;
  }
  return iVar1;
}




/* vtable slots: CMFCBaseVisualManager[4], CMFCVisualManager[4], CMFCVisualManagerOffice2003[4], CMFCVisualManagerOffice2007[4], CMFCVisualManagerOfficeXP[4] */
/* 007f2e00  FUN_007f2e00  304 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f2e00(int *param_1,undefined4 param_2,int param_3,LONG param_4,int param_5,LONG param_6,
                 int param_7,int param_8)

{
  code *pcVar1;
  HDC pHVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int in_stack_00000030;
  int local_2c;
  int *local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x1c;
  local_8 = 0x7f2e0c;
  local_28 = param_1;
  if (*(int *)(in_ECX + 0x1c) != 0) {
    if (param_1 == (int *)0x0) {
      pHVar2 = (HDC)0x0;
    }
    else {
      pHVar2 = (HDC)param_1[1];
    }
    local_2c = in_ECX;
    DrawThemeBackground(*(HTHEME *)(in_ECX + 0x1c),pHVar2,1,0,(LPCRECT)&param_3,(LPCRECT)0x0);
    if (param_7 != 0) {
      local_24.left = param_3;
      local_24.top = param_4;
      local_24.right = param_5;
      local_24.bottom = param_6;
      InflateRect(&local_24,-3,-3);
      iVar3 = param_8;
      local_24.right = ((local_24.right - local_24.left) * param_8) / param_7 + local_24.left;
      if (param_1 == (int *)0x0) {
        pHVar2 = (HDC)0x0;
      }
      else {
        pHVar2 = (HDC)param_1[1];
      }
      DrawThemeBackground(*(HTHEME *)(local_2c + 0x1c),pHVar2,3,0,&local_24,(LPCRECT)0x0);
      if (in_stack_00000030 != 0) {
        CStringT<>();
        local_8 = 0;
        FUN_004059f0(&local_2c,L"%d%%",(iVar3 * 100) / param_7);
        pcVar1 = *(code **)(*param_1 + 0x30);
        iVar3 = FUN_007c2511();
        guard_check_icall(*(undefined4 *)(iVar3 + 0x28));
        uVar4 = (*pcVar1)();
        iVar3 = *local_28;
        guard_check_icall(local_2c,*(undefined4 *)(local_2c + -0xc),&param_3,0x25);
        (**(code **)(iVar3 + 0x68))();
        pcVar1 = *(code **)(*local_28 + 0x30);
        guard_check_icall(uVar4);
        (*pcVar1)();
        FUN_00406b10();
      }
    }
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCBaseVisualManager[7], CMFCVisualManager[7], CMFCVisualManagerOffice2003[7], CMFCVisualManagerOffice2007[7], CMFCVisualManagerOfficeXP[7] */
/* 007f2fda  FUN_007f2fda  379 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007f2fda(int param_1,CWnd *param_2,LONG param_3,LONG param_4,int param_5,int param_6)

{
  code *pcVar1;
  int iVar2;
  CWnd *pCVar3;
  HWND pHVar4;
  HDC hdc;
  int in_ECX;
  HBRUSH hbr;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  hbr = (HBRUSH)0x0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    pCVar3 = (CWnd *)FUN_007e5618(param_2);
    if ((pCVar3 == (CWnd *)0x0) || (*(int *)(pCVar3 + 0x20) == 0)) {
      pHVar4 = GetParent(*(HWND *)(param_2 + 0x20));
      pCVar3 = CWnd::FromHandle(pHVar4);
    }
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(pCVar3 + 0x20),&local_18);
    CWnd::ScreenToClient(param_2,&local_18);
    if (param_5 <= local_18.right) {
      param_5 = local_18.right;
    }
    if (param_6 <= local_18.bottom) {
      param_6 = local_18.bottom;
    }
    pcVar1 = *(code **)(*(int *)param_2 + 0x170);
    guard_check_icall();
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      pcVar1 = *(code **)(*(int *)param_2 + 0x228);
      guard_check_icall(0);
      iVar2 = (*pcVar1)();
      if (iVar2 == 0) {
        param_3 = local_18.left;
        param_4 = local_18.top;
        iVar2 = FUN_0079d98a(&PTR_s_CDockSite_00997564);
        if ((iVar2 == 0) &&
           (((iVar2 = DAT_00a13a1c, DAT_00a13a1c != 0 || (iVar2 = FUN_00792b4c(), iVar2 != 0)) &&
            (*(int *)(iVar2 + 0x20) != 0)))) {
          local_28.left = 0;
          local_28.top = 0;
          local_28.right = 0;
          local_28.bottom = 0;
          GetClientRect(*(HWND *)(iVar2 + 0x20),&local_28);
          MapWindowPoints(*(HWND *)(iVar2 + 0x20),*(HWND *)(param_2 + 0x20),(LPPOINT)&local_28,2);
          param_4 = local_28.top;
        }
      }
    }
    if (param_1 == 0) {
      hdc = (HDC)0x0;
    }
    else {
      hdc = *(HDC *)(param_1 + 4);
    }
    DrawThemeBackground(*(HTHEME *)(in_ECX + 0xc),hdc,0,0,(LPCRECT)&param_3,(LPCRECT)0x0);
    return;
  }
  iVar2 = FUN_007c2511();
  if (iVar2 != -0xd0) {
    hbr = *(HBRUSH *)(iVar2 + 0xd4);
  }
  FillRect(*(HDC *)(param_1 + 4),(RECT *)&param_3,hbr);
  return;
}




/* vtable slots: CMFCBaseVisualManager[10], CMFCVisualManager[10], CMFCVisualManagerOffice2003[10], CMFCVisualManagerOffice2007[10], CMFCVisualManagerOfficeXP[10] */
/* 007f33ab  FUN_007f33ab  490 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007f33ab(void)

{
  HRESULT HVar1;
  int iVar2;
  int in_ECX;
  wchar_t *local_620;
  wchar_t *local_61c;
  COLORREF local_618;
  wchar_t local_614 [256];
  WCHAR local_414 [256];
  WCHAR local_214 [262];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x610;
  local_8 = 0x7f33ba;
  _memset(local_214,0,0x200);
  _memset(local_414,0,0x200);
  HVar1 = GetCurrentThemeName(local_214,0xff,local_414,0xff,(LPWSTR)0x0,0);
  if (HVar1 != 0) goto LAB_007f358f;
  CStringT<>(local_214);
  local_8 = 0;
  CStringT<>(local_414);
  local_8 = CONCAT31(local_8._1_3_,1);
  __wsplitpath_s(local_61c,(wchar_t *)0x0,0,(wchar_t *)0x0,0,local_614,0x100,(wchar_t *)0x0,0);
  iVar2 = FUN_008f899d(local_614);
  ATL::CSimpleStringT<wchar_t,0>::SetString((CSimpleStringT<wchar_t,0> *)&local_61c,local_614,iVar2)
  ;
  iVar2 = __wcsicmp(local_61c,L"Luna");
  if ((iVar2 == 0) || (iVar2 = __wcsicmp(local_61c,L"Aero"), iVar2 == 0)) {
    if (*(int *)(in_ECX + 0x10) != 0) {
      local_618 = 0;
      HVar1 = GetThemeColor(*(HTHEME *)(in_ECX + 0x10),1,0,0xeef,&local_618);
      if ((HVar1 != 0) || (local_618 == 1)) goto LAB_007f3571;
    }
    iVar2 = __wcsicmp(local_620,L"normalcolor");
    if ((iVar2 != 0) &&
       ((iVar2 = __wcsicmp(local_620,L"homestead"), iVar2 != 0 &&
        (iVar2 = __wcsicmp(local_620,L"metallic"), iVar2 == 0)))) {
      CStringT<>(local_214);
      local_8 = CONCAT31(local_8._1_3_,2);
      FUN_0048b0e0();
      FUN_00429b90(L"royale",0);
      FUN_00406b10();
    }
  }
LAB_007f3571:
  FUN_00406b10();
  FUN_00406b10();
LAB_007f358f:
  FUN_008d9b68();
  return;
}



