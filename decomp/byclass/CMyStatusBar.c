/* CMyStatusBar -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyStatusBar[1] */
/* 00596bf0  FUN_00596bf0  68 bytes, 0 callers */

undefined4 FUN_00596bf0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00596bd0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xe0);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyStatusBar[10] */
/* 00596c80  FUN_00596c80  16 bytes, 0 callers */

void FUN_00596c80(void)

{
  FUN_00596c90();
  return;
}




/* vtable slots: CMyStatusBar[89], CStatusBar[89] */
/* 007be84c  FUN_007be84c  256 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 * FUN_007be84c(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  HGDIOBJ h;
  int iVar2;
  int *in_ECX;
  HGDIOBJ h_00;
  int iVar3;
  HDC local_70;
  HDC local_6c;
  tagTEXTMETRICW local_60;
  tagRECT local_24;
  undefined1 local_14 [4];
  int local_10;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  h_00 = (HGDIOBJ)0x0;
  FUN_0079dea2(0);
  h = (HGDIOBJ)SendMessageW((HWND)in_ECX[8],0x31,0,0);
  if (h != (HGDIOBJ)0x0) {
    h_00 = SelectObject(local_70,h);
  }
  GetTextMetricsW(local_6c,&local_60);
  if (h_00 != (HGDIOBJ)0x0) {
    SelectObject(local_70,h_00);
  }
  FUN_0079dfff();
  local_24.left = 0;
  local_24.top = 0;
  local_24.right = 0;
  local_24.bottom = 0;
  SetRectEmpty(&local_24);
  pcVar1 = *(code **)(*in_ECX + 0x170);
  guard_check_icall(&local_24,param_3);
  (*pcVar1)();
  pcVar1 = *(code **)(*in_ECX + 0x11c);
  guard_check_icall(0x407,0,local_14);
  (*pcVar1)();
  param_1[1] = 0;
  iVar3 = local_24.bottom - local_24.top;
  *param_1 = 0x7fff;
  iVar2 = GetSystemMetrics(6);
  iVar2 = local_60.tmHeight + -1 + (((iVar2 + local_10) * 2 - iVar3) - local_60.tmInternalLeading);
  param_1[1] = iVar2;
  if (iVar2 < in_ECX[0x32]) {
    param_1[1] = in_ECX[0x32];
  }
  return param_1;
}




/* vtable slots: CMyStatusBar[92], CStatusBar[92] */
/* 007be94c  FUN_007be94c  143 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007be94c(int param_1,undefined4 param_2)

{
  code *pcVar1;
  uint uVar2;
  HWND hWnd;
  BOOL BVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  int local_14 [3];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_007abf22(param_1,param_2);
  uVar2 = FUN_00797b3d();
  if ((uVar2 & 0x100) != 0) {
    hWnd = GetParent((HWND)in_ECX[8]);
    BVar3 = IsZoomed(hWnd);
    if (BVar3 == 0) {
      pcVar1 = *(code **)(*in_ECX + 0x11c);
      guard_check_icall(0x407,0,local_14);
      (*pcVar1)();
      iVar4 = GetSystemMetrics(5);
      iVar5 = GetSystemMetrics(2);
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) - (iVar5 + iVar4 * 2 + local_14[0]);
    }
  }
  return;
}




/* vtable slots: CMyStatusBar[105], CStatusBar[105] */
/* 007bea08  FUN_007bea08  44 bytes, 0 callers */

void FUN_007bea08(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int *in_ECX;
  
  pcVar1 = *(code **)(*in_ECX + 0x1a8);
  guard_check_icall(param_1,0,param_2,param_3);
  (*pcVar1)();
  return;
}




/* vtable slots: CMyStatusBar[106], CStatusBar[106] */
/* 007bea34  FUN_007bea34  155 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007bea34(undefined4 param_1,uint param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  int in_ECX;
  uint uVar2;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  *(uint *)(in_ECX + 0xb0) = param_3 & 0x40ffff;
  uVar2 = param_3 & 0xffbf004e | 0x4e;
  uVar1 = FUN_00797b3d();
  if ((uVar1 & 0x40000) != 0) {
    uVar2 = param_3 & 0xffbf004e | 0x14e;
  }
  FUN_00790c5e(0x1000);
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  SetRectEmpty(&local_18);
  FUN_00791f4f(L"msctls_statusbar32",0,param_2 | uVar2,&local_18,param_1,param_4,0);
  return;
}




/* vtable slots: CMyStatusBar[0], CStatusBar[0] */
/* 007beb99  FUN_007beb99  6 bytes, 0 callers */

undefined ** FUN_007beb99(void)

{
  return &PTR_s_CStatusBar_009821b0;
}




/* vtable slots: CMyStatusBar[103], CStatusBar[103] */
/* 007beb9f  OnBarStyleChange  39 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CStatusBar::OnBarStyleChange(unsigned long,unsigned long)
   
   Libraries: Visual Studio 2012 Release, Visual Studio 2015 Release */

void __thiscall CStatusBar::OnBarStyleChange(CStatusBar *this,ulong param_1,ulong param_2)

{
  if ((*(int *)(this + 0x20) != 0) && (((param_1 ^ param_2) & 0xf00) != 0)) {
    FUN_00797e71(0,0,0,0,0,0x33);
  }
  return;
}




/* vtable slots: CMyStatusBar[73], CStatusBar[73] */
/* 007bebc6  FUN_007bebc6  64 bytes, 0 callers */

int FUN_007bebc6(uint param_1,uint param_2,long param_3,long *param_4)

{
  code *pcVar1;
  int iVar2;
  CWnd *in_ECX;
  
  if (param_1 == 0x2b) {
    pcVar1 = *(code **)(*(int *)in_ECX + 0x1ac);
    guard_check_icall(param_3);
    (*pcVar1)();
    iVar2 = 1;
  }
  else {
    iVar2 = CWnd::OnChildNotify(in_ECX,param_1,param_2,param_3,param_4);
  }
  return iVar2;
}




/* vtable slots: CMyStatusBar[91], CStatusBar[91] */
/* 007bed76  FUN_007bed76  122 bytes, 0 callers */

void FUN_007bed76(CCmdTarget *param_1,int param_2)

{
  int iVar1;
  CWnd *in_ECX;
  undefined **local_2c;
  undefined4 local_28;
  uint local_24;
  uint local_c;
  
  CCmdUI::CCmdUI((CCmdUI *)&local_2c);
  local_c = *(uint *)(in_ECX + 0xa0);
  local_2c = CStatusCmdUI::vftable;
  local_24 = 0;
  if (local_c != 0) {
    do {
      local_28 = *(undefined4 *)(local_24 * 0x14 + *(int *)(in_ECX + 0xa4));
      iVar1 = FUN_007900e9(local_28,0xffffffff,&local_2c,0);
      if (iVar1 == 0) {
        FUN_0078ff63(param_1,0);
      }
      local_24 = local_24 + 1;
    } while (local_24 < local_c);
  }
  CWnd::UpdateDialogControls(in_ECX,param_1,param_2);
  return;
}




/* vtable slots: CMyStatusBar[25], CStatusBar[25] */
/* 007bedf0  FUN_007bedf0  41 bytes, 0 callers */

void FUN_007bedf0(void)

{
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0xb0) & 0xff00) == 0x8200) {
    *(uint *)(in_ECX + 0xb0) = *(uint *)(in_ECX + 0xb0) & 0xfffff07f;
  }
  FUN_007ad074();
  return;
}



