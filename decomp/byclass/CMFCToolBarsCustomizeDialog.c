/* CMFCToolBarsCustomizeDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCToolBarsCustomizeDialog[67], CMyPropertySheet[67], CPropertySheet[67] */
/* 007a1270  FUN_007a1270  214 bytes, 1 callers */

undefined4 FUN_007a1270(int param_1)

{
  code *pcVar1;
  SHORT SVar2;
  int iVar3;
  HANDLE pvVar4;
  int *piVar5;
  LRESULT LVar6;
  undefined4 uVar7;
  int *in_ECX;
  
  iVar3 = FUN_007949fb(param_1);
  if (iVar3 == 0) {
    pvVar4 = GetPropW((HWND)in_ECX[8],(LPCWSTR)PTR_u_AfxClosePending_00a0036c);
    piVar5 = GlobalLock(pvVar4);
    if (piVar5 != (int *)0x0) {
      if (*piVar5 == 1) {
        LVar6 = SendMessageW((HWND)in_ECX[8],0x476,0,0);
        if (LVar6 == 0) {
          GlobalUnlock(pvVar4);
          pvVar4 = RemovePropW((HWND)in_ECX[8],(LPCWSTR)PTR_u_AfxClosePending_00a0036c);
          if (pvVar4 != (HANDLE)0x0) {
            GlobalFree(pvVar4);
          }
          pcVar1 = *(code **)(*in_ECX + 0x60);
          guard_check_icall();
          (*pcVar1)();
          goto LAB_007a12ee;
        }
      }
      GlobalUnlock(pvVar4);
    }
    if (*(int *)(param_1 + 4) == 0x100) {
      SVar2 = GetAsyncKeyState(0x11);
      if ((SVar2 < 0) &&
         (((*(int *)(param_1 + 8) == 9 || (*(int *)(param_1 + 8) == 0x21)) ||
          (*(int *)(param_1 + 8) == 0x22)))) {
        LVar6 = SendMessageW((HWND)in_ECX[8],0x475,0,param_1);
        if (LVar6 != 0) goto LAB_007a12ee;
      }
    }
    uVar7 = FUN_007949cc(param_1);
  }
  else {
LAB_007a12ee:
    uVar7 = 1;
  }
  return uVar7;
}




/* vtable slots: CMFCToolBarsCustomizeDialog[1] */
/* 00884a48  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCToolBarsCustomizeDialog::`scalar deleting
   destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCToolBarsCustomizeDialog::_scalar_deleting_destructor_
          (CMFCToolBarsCustomizeDialog *this,uint param_1)

{
  FUN_00884738();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x918);
    }
  }
  return this;
}




/* vtable slots: CMFCToolBarsCustomizeDialog[102] */
/* 008853ce  Create  67 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CMFCToolBarsCustomizeDialog::Create(void)
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCToolBarsCustomizeDialog::Create(CMFCToolBarsCustomizeDialog *this)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (*(int *)(this + 0x154) != 0) {
    uVar1 = FUN_00797acc();
    if ((uVar1 & 0x400000) != 0) {
      uVar3 = 0x400000;
    }
  }
  iVar2 = FUN_007a02d8(*(undefined4 *)(this + 0x154),0xffffffff,uVar3);
  if (iVar2 != 0) {
    FUN_00885c50(1);
  }
  return (uint)(iVar2 != 0);
}




/* vtable slots: CMFCToolBarsCustomizeDialog[95] */
/* 00885411  FUN_00885411  141 bytes, 0 callers */

void FUN_00885411(int param_1)

{
  int iVar1;
  int *piVar2;
  int lParam;
  WPARAM wParam;
  int in_ECX;
  int local_8;
  
  local_8 = in_ECX;
  SendMessageW(*(HWND *)(param_1 + 0x20),0x184,0,0);
  iVar1 = Lookup(*(undefined4 *)(in_ECX + 0x150),&local_8);
  if (iVar1 != 0) {
    local_8 = *(int *)(local_8 + 4);
    while (local_8 != 0) {
      piVar2 = (int *)FUN_0044f2d0(&local_8);
      iVar1 = *piVar2;
      lParam = *(int *)(iVar1 + 0x30);
      if (*(int *)(lParam + -0xc) == 0) {
        lParam = *(LPARAM *)(iVar1 + 0x2c);
      }
      wParam = SendMessageW(*(HWND *)(param_1 + 0x20),0x180,0,lParam);
      SendMessageW(*(HWND *)(param_1 + 0x20),0x19a,wParam,*(LPARAM *)(iVar1 + 0x20));
    }
  }
  return;
}




/* vtable slots: CMFCToolBarsCustomizeDialog[10] */
/* 00885787  FUN_00885787  6 bytes, 0 callers */

undefined ** FUN_00885787(void)

{
  return &PTR_FUN_0099ab90;
}




/* vtable slots: CMFCToolBarsCustomizeDialog[0] */
/* 0088578d  FUN_0088578d  6 bytes, 0 callers */

undefined ** FUN_0088578d(void)

{
  return &PTR_s_CMFCToolBarsCustomizeDialog_0099a930;
}




/* vtable slots: CMFCToolBarsCustomizeDialog[61] */
/* 008857eb  FUN_008857eb  169 bytes, 0 callers */

undefined4 FUN_008857eb(uint param_1,undefined4 param_2)

{
  code *pcVar1;
  CPropertyPage *pCVar2;
  undefined4 uVar3;
  WPARAM wParam;
  int iVar4;
  CPropertyPage *pCVar5;
  CPropertySheet *in_ECX;
  
  if ((param_1 & 0xffff) == 2) {
    if ((DAT_00a13bac != 0) && (*(int *)(in_ECX + 0x130) != 0)) {
      pcVar1 = *(code **)(*(int *)in_ECX + 0x18c);
      guard_check_icall(DAT_00a13bac + 4);
      iVar4 = (*pcVar1)();
      if (iVar4 == 0) {
        pCVar2 = *(CPropertyPage **)(in_ECX + 0x130);
        pCVar5 = CPropertySheet::GetActivePage(in_ECX);
        if (pCVar5 == pCVar2) {
          return 1;
        }
        FUN_007a1374(pCVar2);
        return 1;
      }
    }
    pcVar1 = *(code **)(*(int *)in_ECX + 0x60);
    guard_check_icall();
    (*pcVar1)();
  }
  else {
    if ((param_1 & 0xffff) != 9) {
      uVar3 = FUN_007a09cd(param_1,param_2);
      return uVar3;
    }
    iVar4 = *(int *)(in_ECX + 0x154);
    wParam = CPropertySheet::GetActiveIndex(in_ECX);
    SendMessageW(*(HWND *)(iVar4 + 0x20),DAT_00a127cc,wParam,(LPARAM)in_ECX);
  }
  return 1;
}




/* vtable slots: CMFCToolBarsCustomizeDialog[103] */
/* 008858ca  FUN_008858ca  133 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_008858ca(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  CMFCImageEditorDialog local_1f34 [7968];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094ee93;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_008c8de2(param_2,param_1,param_3);
  local_8 = 0;
  iVar2 = FUN_0079850d(uVar1);
  CMFCImageEditorDialog::~CMFCImageEditorDialog(local_1f34);
  ExceptionList = local_10;
  return iVar2 == 1;
}




/* vtable slots: CMFCToolBarsCustomizeDialog[91] */
/* 00885977  FUN_00885977  677 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_00885977(void)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  AFX_GLOBAL_DATA *this;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  UINT in_stack_ffffff8c;
  LPSTR in_stack_ffffff90;
  int in_stack_ffffff94;
  undefined4 local_64;
  int local_60;
  undefined4 local_5c;
  undefined4 local_58;
  tagRECT local_54;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x885983;
  local_5c = FUN_007a0b0c();
  local_54.left = 0;
  local_54.top = 0;
  local_54.right = 0;
  local_54.bottom = 0;
  GetClientRect(*(HWND *)(in_ECX + 0x20),&local_54);
  iVar2 = FUN_00797a56(2);
  if (iVar2 == 0) goto LAB_00885c11;
  FUN_00797f20(5);
  FUN_007979e8(1);
  local_34.left = 0;
  local_34.top = 0;
  local_34.right = 0;
  local_34.bottom = 0;
  GetClientRect(*(HWND *)(iVar2 + 0x20),&local_34);
  MapWindowPoints(*(HWND *)(iVar2 + 0x20),*(HWND *)(in_ECX + 0x20),(LPPOINT)&local_34,2);
  local_44.left = 0;
  local_44.top = 0;
  local_44.right = 0;
  local_44.bottom = 0;
  GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_44);
  FUN_00797e71(0,0,0,local_44.right - local_44.left,
               (local_44.bottom - local_44.top) + (local_34.bottom - local_34.top) + 0x10,0x16);
  FUN_00797e71(0,(local_54.right - (local_34.right - local_34.left)) + -8,local_34.top + 4,0,0,0x15)
  ;
  iVar2 = FUN_00797a56(1);
  if (iVar2 != 0) {
    FUN_00797c5d(1,0,0);
  }
  FUN_00797c5d(0,1,0);
  CStringT<>();
  local_8 = 0;
  iVar2 = FID_conflict_LoadStringA
                    ((HINSTANCE)0x3ee9,in_stack_ffffff8c,in_stack_ffffff90,in_stack_ffffff94);
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  FUN_00797ece(local_58);
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_24);
  local_60 = GetSystemMetrics(0);
  iVar2 = GetSystemMetrics(0x3e);
  iVar3 = GetSystemMetrics(1);
  iVar4 = GetSystemMetrics(0x3e);
  iVar4 = iVar4 + (iVar2 - iVar3);
  iVar2 = local_24.top;
  iVar3 = local_24.left;
  if (local_24.left < 0) {
    if (local_24.top < 0) goto LAB_00885b31;
LAB_00885b33:
    if (local_24.left < 0) {
      iVar3 = 0;
    }
LAB_00885b43:
    FUN_00797e71(0,iVar3,iVar2,0,0,1);
  }
  else {
    if (local_24.top < 0) {
LAB_00885b31:
      iVar2 = 0;
      goto LAB_00885b33;
    }
    if ((local_60 < local_24.right) || (iVar4 < local_24.bottom)) {
      if (iVar4 < local_24.bottom) {
        iVar2 = (local_24.top - local_24.bottom) + iVar4;
      }
      if (local_60 < local_24.right) {
        iVar3 = (local_24.left - local_24.right) + local_60;
      }
      goto LAB_00885b43;
    }
  }
  iVar2 = FUN_00797a56(9);
  if (iVar2 != 0) {
    if ((*(byte *)(in_ECX + 0x15c) & 8) == 0) {
      FUN_007954d8(*(undefined4 *)(iVar2 + 0x20));
      FUN_00797f20(5);
      FUN_007979e8(1);
      uVar6 = 0;
      uVar5 = 0;
      this = (AFX_GLOBAL_DATA *)FUN_007c2511();
      iVar2 = AFX_GLOBAL_DATA::Is32BitIcons(this);
      CMFCButton::SetImage
                ((CMFCButton *)(in_ECX + 0x168),(-(uint)(iVar2 != 0) & 0x3a8) + 0x3f03,uVar5,uVar6);
      FUN_00797ece(&DAT_00956338);
      pcVar1 = *(code **)(*(int *)(in_ECX + 0x168) + 0x170);
      guard_check_icall(&local_64,1);
      (*pcVar1)();
      FUN_00797e71(0,local_54.left + 8,local_34.top,local_64,local_60,0x14);
    }
    else {
      FUN_00797f20(0);
      FUN_007979e8(0);
    }
  }
  FUN_00406b10();
LAB_00885c11:
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCToolBarsCustomizeDialog[72] */
/* 00885c1d  FUN_00885c1d  51 bytes, 0 callers */

void FUN_00885c1d(void)

{
  code *pcVar1;
  int *in_ECX;
  
  DAT_00a13bf4 = 0;
  FUN_00885c50(0);
  guard_check_icall();
  if (in_ECX != (int *)0x0) {
    pcVar1 = *(code **)(*in_ECX + 4);
    guard_check_icall(1);
    (*pcVar1)();
  }
  return;
}



