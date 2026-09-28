/* CMFCMenuButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCMenuButton[1] */
/* 007dab2d  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCMenuButton::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCMenuButton::_scalar_deleting_destructor_(CMFCMenuButton *this,uint param_1)

{
  *(undefined ***)this = vftable;
  FUN_007d369b();
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




/* vtable slots: CMFCMenuButton[10] */
/* 007dab66  FUN_007dab66  6 bytes, 0 callers */

undefined ** FUN_007dab66(void)

{
  return &PTR_FUN_00988d48;
}




/* vtable slots: CMFCMenuButton[0] */
/* 007dab6c  FUN_007dab6c  6 bytes, 0 callers */

undefined ** FUN_007dab6c(void)

{
  return &PTR_s_CMFCMenuButton_00988ab8;
}




/* vtable slots: CMFCMenuButton[97] */
/* 007dab72  FUN_007dab72  267 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007dab72(CDC *param_1,undefined4 *param_2,uint param_3)

{
  ulong uVar1;
  int iVar2;
  int local_48 [2];
  int local_40;
  CDC *local_3c;
  int local_38;
  int iStack_34;
  undefined4 uStack_30;
  LONG LStack_2c;
  undefined4 local_28;
  undefined4 uStack_24;
  int local_20;
  undefined4 uStack_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_3c = param_1;
  FUN_0081507c(local_48);
  local_28 = *param_2;
  uStack_24 = param_2[1];
  uStack_1c = param_2[3];
  local_20 = param_2[2] + (-10 - local_48[0]);
  FUN_007d3e15(local_3c,&local_28,param_3);
  iStack_34 = param_2[1];
  uStack_30 = param_2[2];
  LStack_2c = param_2[3];
  local_38 = local_20;
  local_18.right = 0;
  local_18.bottom = 0;
  FUN_00814d1c(local_3c,(*(int *)(local_40 + 0x7a8) != 0) + '\r',&local_38,param_3 >> 2 & 1,
               &local_18.right);
  if (*(int *)(local_40 + 0x7bc) != 0) {
    local_18.right = local_38 + 2;
    local_18.left = local_38;
    local_18.top = iStack_34;
    local_18.bottom = LStack_2c;
    InflateRect(&local_18,0,-2);
    if ((DAT_00a124d8 == 0) || (*(int *)(local_40 + 0xa4) != 0)) {
      local_18.left = local_18.left + *(int *)(local_40 + 0xe8);
      local_18.top = local_18.top + *(int *)(local_40 + 0xec);
    }
    iVar2 = FUN_007c2511();
    uVar1 = *(ulong *)(iVar2 + 0x24);
    iVar2 = FUN_007c2511();
    CDC::Draw3dRect(local_3c,&local_18,*(ulong *)(iVar2 + 0x30),uVar1);
  }
  return;
}




/* vtable slots: CMFCMenuButton[102] */
/* 007daf94  FUN_007daf94  371 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007daf94(void)

{
  code *pcVar1;
  LPARAM lParam;
  undefined4 uVar2;
  BOOL BVar3;
  HWND pHVar4;
  CWnd *pCVar5;
  uint uVar6;
  int in_ECX;
  LONG x;
  LONG y;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(in_ECX + 0x7ac) != 0) && (*(int *)(in_ECX + 0x7c0) == 0)) {
    local_18.left = 0;
    local_18.top = 0;
    local_18.right = 0;
    local_18.bottom = 0;
    GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_18);
    x = local_18.left;
    y = local_18.bottom;
    if (*(int *)(in_ECX + 0x7a8) != 0) {
      x = local_18.right;
      y = local_18.top;
    }
    if (*(int *)(in_ECX + 0x7b4) != 0) {
      *(undefined4 *)(in_ECX + 0xac) = 1;
      *(undefined4 *)(in_ECX + 0xb4) = 1;
    }
    *(undefined4 *)(in_ECX + 0x7c0) = 1;
    InvalidateRect(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,1);
    if ((*(int *)(in_ECX + 0x7b8) == 0) && (DAT_00a13a20 != (int *)0x0)) {
      pcVar1 = *(code **)(*DAT_00a13a20 + 0x14);
      guard_check_icall(*(undefined4 *)(in_ECX + 0x7ac),x,y);
      uVar2 = (*pcVar1)();
      *(undefined4 *)(in_ECX + 0x7b0) = uVar2;
      FUN_00797df8();
    }
    else {
      BVar3 = TrackPopupMenu(*(HMENU *)(in_ECX + 0x7ac),0x180,x,y,0,*(HWND *)(in_ECX + 0x20),
                             (RECT *)0x0);
      *(BOOL *)(in_ECX + 0x7b0) = BVar3;
    }
    pHVar4 = GetParent(*(HWND *)(in_ECX + 0x20));
    pCVar5 = CWnd::FromHandle(pHVar4);
    if ((*(int *)(in_ECX + 0x7b0) != 0) && (pCVar5 != (CWnd *)0x0)) {
      lParam = *(LPARAM *)(in_ECX + 0x20);
      uVar6 = FUN_00797a2b();
      SendMessageW(*(HWND *)(pCVar5 + 0x20),0x111,uVar6 & 0xffff,lParam);
    }
    *(undefined4 *)(in_ECX + 0xac) = 0;
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    *(undefined4 *)(in_ECX + 0x7c0) = 0;
    InvalidateRect(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,1);
    UpdateWindow(*(HWND *)(in_ECX + 0x20));
    if (*(int *)(in_ECX + 0xb8) != 0) {
      ReleaseCapture();
      *(undefined4 *)(in_ECX + 0xb8) = 0;
    }
  }
  return;
}




/* vtable slots: CMFCMenuButton[67] */
/* 007db107  FUN_007db107  81 bytes, 0 callers */

undefined4 FUN_007db107(int param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (((*(int *)(param_1 + 4) == 0x100) && (*(int *)(param_1 + 8) == 0xd)) && (DAT_00a139c8 == 0)) {
    in_ECX[0x1f1] = 1;
    pcVar1 = *(code **)(*in_ECX + 0x198);
    guard_check_icall();
    (*pcVar1)();
    uVar2 = 1;
  }
  else {
    uVar2 = FUN_007d4f8f(param_1);
  }
  return uVar2;
}



