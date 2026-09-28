/* CMFCDropDownFrame -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCDropDownFrame[1] */
/* 0088a189  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCDropDownFrame::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCDropDownFrame::_scalar_deleting_destructor_(CMFCDropDownFrame *this,uint param_1)

{
  FUN_0088a0da();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0xe90);
    }
  }
  return this;
}




/* vtable slots: CMFCDropDownFrame[114] */
/* 0088a260  FUN_0088a260  329 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

bool FUN_0088a260(CWnd *param_1,int param_2,int param_3,undefined4 param_4)

{
  HCURSOR pHVar1;
  wchar_t *pwVar2;
  uint uVar3;
  CWnd *pCVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (param_1 == (CWnd *)0x0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  FUN_00886f80(2);
  uVar8 = 0;
  uVar7 = 0x10;
  pHVar1 = LoadCursorW((HINSTANCE)0x0,(LPCWSTR)0x7f00);
  pwVar2 = (wchar_t *)AfxRegisterWndClass(0x800,pHVar1,uVar7,uVar8);
  if (pwVar2 == (wchar_t *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_008f899d(pwVar2);
  }
  ATL::CSimpleStringT<wchar_t,0>::SetString((CSimpleStringT<wchar_t,0> *)&DAT_00a13c34,pwVar2,iVar5)
  ;
  *(undefined4 *)(in_ECX + 0xe78) = param_4;
  iVar5 = param_2;
  iVar6 = param_3;
  if ((param_2 == -1) && (param_3 == -1)) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetClientRect(*(HWND *)(param_1 + 0x20),&local_18);
    FUN_0079e8b8(&local_18);
    iVar5 = local_18.left + 5;
    iVar6 = local_18.top + 5;
  }
  local_2c = 0;
  *(int *)(in_ECX + 0xe7c) = iVar5;
  *(int *)(in_ECX + 0xe80) = iVar6;
  if ((*(int *)(param_1 + 0x20) != 0) && (uVar3 = FUN_00797acc(), (uVar3 & 0x400000) != 0)) {
    local_2c = 0x400000;
  }
  local_28 = param_2;
  local_24 = param_3;
  local_20 = param_2;
  local_1c = param_3;
  pCVar4 = CWnd::GetOwner(param_1);
  if (pCVar4 != (CWnd *)0x0) {
    param_1 = CWnd::GetOwner(param_1);
  }
  iVar5 = FUN_007d105c(local_2c,DAT_00a13c34,*(undefined4 *)(in_ECX + 0xe88),0x80000000,&local_28,
                       param_1,0);
  if (iVar5 != 0) {
    FUN_00797f20(4);
  }
  return iVar5 != 0;
}




/* vtable slots: CMFCDropDownFrame[10] */
/* 0088a65c  FUN_0088a65c  6 bytes, 0 callers */

undefined ** FUN_0088a65c(void)

{
  return &PTR_FUN_0099bc40;
}




/* vtable slots: CMFCDropDownFrame[0] */
/* 0088a668  FUN_0088a668  6 bytes, 0 callers */

undefined ** FUN_0088a668(void)

{
  return &PTR_s_CMFCDropDownFrame_00a00b60;
}




/* vtable slots: CMFCDropDownFrame[72] */
/* 0088b694  FUN_0088b694  42 bytes, 0 callers */

void FUN_0088b694(void)

{
  code *pcVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x134) != (int *)0x0) {
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x134) + 0x58);
    guard_check_icall();
    (*pcVar1)();
  }
  FUN_0079c41b();
  return;
}




/* vtable slots: CMFCDropDownFrame[94] */
/* 0088b6be  FUN_0088b6be  478 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0088b6be(void)

{
  code *pcVar1;
  BOOL BVar2;
  CObject *pCVar3;
  undefined4 uVar4;
  HMONITOR hMonitor;
  int iVar5;
  int in_ECX;
  int iVar6;
  tagMONITORINFO *lpmi;
  int local_58;
  int local_54;
  tagMONITORINFO local_50;
  tagRECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  BVar2 = IsWindow(*(HWND *)(in_ECX + 0x20));
  if (BVar2 == 0) {
    return;
  }
  BVar2 = IsWindow(*(HWND *)(in_ECX + 0x158));
  if (BVar2 == 0) {
    return;
  }
  if ((*(int *)(in_ECX + 0x134) == 0) ||
     (pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,
                                  *(CObject **)(*(int *)(in_ECX + 0x134) + 0x6c)),
     pCVar3 == (CObject *)0x0)) {
    uVar4 = 1;
  }
  else {
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x164);
    guard_check_icall();
    uVar4 = (*pcVar1)();
  }
  pcVar1 = *(code **)(*(int *)(in_ECX + 0x138) + 0x2a4);
  guard_check_icall(&local_58,uVar4);
  (*pcVar1)();
  local_58 = local_58 + 6;
  lpmi = &local_50;
  local_54 = local_54 + 6;
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  local_50.cbSize = 0x28;
  hMonitor = MonitorFromPoint(*(POINT *)(in_ECX + 0xe7c),2);
  BVar2 = GetMonitorInfoW(hMonitor,lpmi);
  if (BVar2 == 0) {
    SystemParametersInfoW(0x30,0,&local_18,0);
  }
  else {
    CopyRect(&local_18,&local_50.rcWork);
  }
  iVar5 = *(int *)(in_ECX + 0xe7c);
  if (iVar5 + local_58 <= local_18.right) goto LAB_0088b830;
  if ((*(int *)(in_ECX + 0x134) == 0) ||
     (pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCToolBar_00a005c4,
                                  *(CObject **)(*(int *)(in_ECX + 0x134) + 0x6c)),
     pCVar3 == (CObject *)0x0)) {
LAB_0088b822:
    iVar5 = ((local_18.right - local_18.left) - local_58) + -1;
  }
  else {
    pcVar1 = *(code **)(*(int *)pCVar3 + 0x164);
    guard_check_icall();
    iVar5 = (*pcVar1)();
    if (iVar5 != 0) goto LAB_0088b822;
    local_28.left = iVar5;
    local_28.top = iVar5;
    local_28.right = iVar5;
    local_28.bottom = iVar5;
    GetWindowRect(*(HWND *)(pCVar3 + 0x20),&local_28);
    iVar5 = local_28.left - local_58;
  }
  *(int *)(in_ECX + 0xe7c) = iVar5;
LAB_0088b830:
  iVar6 = *(int *)(in_ECX + 0xe80);
  if (local_18.bottom < iVar6 + local_54) {
    iVar6 = iVar6 - local_54;
    *(int *)(in_ECX + 0xe80) = iVar6;
    if (*(int *)(in_ECX + 0x134) == 0) {
      if (iVar6 < 0) {
        *(undefined4 *)(in_ECX + 0xe80) = 0;
        iVar6 = 0;
      }
    }
    else {
      iVar6 = iVar6 + -4 +
              (*(int *)(*(int *)(in_ECX + 0x134) + 0x58) - *(int *)(*(int *)(in_ECX + 0x134) + 0x60)
              );
      *(int *)(in_ECX + 0xe80) = iVar6;
    }
  }
  FUN_00797e71(0,iVar5,iVar6,local_58,local_54,0x14);
  return;
}



