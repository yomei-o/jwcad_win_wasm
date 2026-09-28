/* CMFCLinkCtrl -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCLinkCtrl[1] */
/* 007d8389  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCLinkCtrl::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCLinkCtrl::_scalar_deleting_destructor_(CMFCLinkCtrl *this,uint param_1)

{
  ~CMFCLinkCtrl(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x7c0);
    }
  }
  return this;
}




/* vtable slots: CMFCLinkCtrl[10] */
/* 007d83bc  FUN_007d83bc  6 bytes, 0 callers */

undefined ** FUN_007d83bc(void)

{
  return &PTR_FUN_00988648;
}




/* vtable slots: CMFCLinkCtrl[0] */
/* 007d83c2  FUN_007d83c2  6 bytes, 0 callers */

undefined ** FUN_007d83c2(void)

{
  return &PTR_s_CMFCLinkCtrl_00988430;
}




/* vtable slots: CMFCLinkCtrl[97] */
/* 007d84b7  FUN_007d84b7  276 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007d84b7(int *param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x24;
  local_8 = 0x7d84c3;
  if ((*(int *)(in_ECX + 0x7ac) == 0) && (*(int *)(in_ECX + 0xbc) == 0)) {
    iVar2 = FUN_007d50e9(param_1);
  }
  else {
    pcVar1 = *(code **)(*param_1 + 0x28);
    iVar2 = FUN_007c2511();
    guard_check_icall(iVar2 + 0x144);
    iVar2 = (*pcVar1)();
  }
  if (iVar2 != 0) {
    pcVar1 = *(code **)(*param_1 + 0x30);
    if (*(int *)(in_ECX + 0xbc) == 0) {
      if (*(int *)(in_ECX + 0x7b4) == 0) {
        iVar3 = FUN_007c2511();
        uVar4 = *(undefined4 *)(iVar3 + 0x44);
      }
      else {
        iVar3 = FUN_007c2511();
        uVar4 = *(undefined4 *)(iVar3 + 0x4c);
      }
    }
    else {
      iVar3 = FUN_007c2511();
      uVar4 = *(undefined4 *)(iVar3 + 0x48);
    }
    guard_check_icall(uVar4);
    (*pcVar1)();
    FUN_0079f0b8(1);
    CStringT<>();
    local_8 = 0;
    FUN_00792c64(local_28);
    local_24 = *param_2;
    uStack_20 = param_2[1];
    uStack_1c = param_2[2];
    uStack_18 = param_2[3];
    FUN_007c2378(local_28,&local_24,(-(uint)(*(int *)(in_ECX + 0x7a8) != 0) & 0xfffffff0) + 0x20);
    pcVar1 = *(code **)(*param_1 + 0x28);
    guard_check_icall(iVar2);
    (*pcVar1)();
    FUN_00406b10();
    FUN_008d9b68();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCLinkCtrl[96] */
/* 007d85cc  FUN_007d85cc  60 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d85cc(int param_1,LONG *param_2)

{
  RECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = *param_2;
  local_18.top = param_2[1];
  local_18.right = param_2[2];
  local_18.bottom = param_2[3];
  DrawFocusRect(*(HDC *)(param_1 + 4),&local_18);
  return;
}




/* vtable slots: CMFCLinkCtrl[67] */
/* 007d8757  PreTranslateMessage  65 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual int __thiscall CMFCLinkCtrl::PreTranslateMessage(struct tagMSG *)
   
   Library: Visual Studio 2015 Release */

int __thiscall CMFCLinkCtrl::PreTranslateMessage(CMFCLinkCtrl *this,tagMSG *param_1)

{
  int iVar1;
  
  if (param_1->message == 0x100) {
    if (param_1->wParam == 0x20) {
      return 1;
    }
    if (param_1->wParam == 0xd) {
      return 1;
    }
  }
  else if (param_1->message == 0x101) {
    if (param_1->wParam != 0x20) {
      if (param_1->wParam != 0xd) goto LAB_007d8790;
      OnClicked(this);
    }
    return 1;
  }
LAB_007d8790:
  iVar1 = FUN_007d4f8f(param_1);
  return iVar1;
}




/* vtable slots: CMFCLinkCtrl[102] */
/* 007d87f9  FUN_007d87f9  439 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007d87f9(int *param_1,int param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  int in_ECX;
  int iVar6;
  undefined4 uVar7;
  int local_54;
  int local_38;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x44;
  local_8 = 0x7d8805;
  iVar2 = FUN_004208d0(0,0);
  if (iVar2 != 0) {
    FUN_007d569c(param_1,0);
LAB_007d8829:
    FUN_008d9b68();
    return;
  }
  if ((in_ECX != 0) && (*(int *)(in_ECX + 0x20) != 0)) {
    FUN_0079dea2(in_ECX);
    local_8 = 0;
    iVar2 = FUN_007c2511();
    iVar2 = FUN_0079efbc(iVar2 + 0x144);
    if (iVar2 != 0) {
      CStringT<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_00792c64(&local_38);
      local_34.left = 0;
      local_34.top = 0;
      local_34.right = 0;
      local_34.bottom = 0;
      GetClientRect(*(HWND *)(in_ECX + 0x20),&local_34);
      local_24.left = local_34.left;
      local_24.top = local_34.top;
      local_24.right = local_34.right;
      local_24.bottom = local_34.bottom;
      pcVar1 = *(code **)(local_54 + 0x68);
      guard_check_icall(local_38,*(undefined4 *)(local_38 + -0xc),&local_24,0x420);
      (*pcVar1)();
      InflateRect(&local_24,3,3);
      if ((param_2 == 0) && (param_3 == 0)) {
        iVar6 = -1;
        iVar3 = -1;
        uVar7 = 0x16;
      }
      else {
        pHVar4 = GetParent(*(HWND *)(in_ECX + 0x20));
        pCVar5 = CWnd::FromHandle(pHVar4);
        pHVar4 = (HWND)0x0;
        if (pCVar5 != (CWnd *)0x0) {
          pHVar4 = *(HWND *)(pCVar5 + 0x20);
        }
        MapWindowPoints(*(HWND *)(in_ECX + 0x20),pHVar4,(LPPOINT)&local_34,2);
        if (param_3 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = (((local_34.right - local_24.right) - local_34.left) + local_24.left) / 2;
        }
        if (param_2 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = (((local_24.top - local_24.bottom) - local_34.top) + local_34.bottom) / 2;
        }
        iVar6 = local_34.left + iVar6;
        iVar3 = iVar3 + local_34.top;
        uVar7 = 0x14;
      }
      FUN_00797e71(0,iVar6,iVar3,local_24.right - local_24.left,local_24.bottom - local_24.top,uVar7
                  );
      FUN_0079efbc(iVar2);
      *param_1 = local_24.right - local_24.left;
      param_1[1] = local_24.bottom - local_24.top;
      FUN_00406b10();
      FUN_0079dfff();
      goto LAB_007d8829;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}



