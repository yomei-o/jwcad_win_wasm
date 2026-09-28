/* CMFCColorButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCColorButton[1] */
/* 007d5d0f  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCColorButton::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall CMFCColorButton::_scalar_deleting_destructor_(CMFCColorButton *this,uint param_1)

{
  FUN_007d5bbb();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x808);
    }
  }
  return this;
}




/* vtable slots: CMFCColorButton[10] */
/* 007d5e96  FUN_007d5e96  6 bytes, 0 callers */

undefined ** FUN_007d5e96(void)

{
  return &PTR_FUN_00987d00;
}




/* vtable slots: CMFCColorButton[0] */
/* 007d5e9c  FUN_007d5e9c  6 bytes, 0 callers */

undefined ** FUN_007d5e9c(void)

{
  return &PTR_s_CMFCColorButton_0098786c;
}




/* vtable slots: CMFCColorButton[97] */
/* 007d5f0c  FUN_007d5f0c  809 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d5f0c(CDC *param_1,int *param_2,uint param_3)

{
  code *pcVar1;
  ulong uVar2;
  CPalette *pCVar3;
  int iVar4;
  UINT UVar5;
  HBRUSH hbr;
  int *in_ECX;
  int *piVar6;
  CDC *pCVar7;
  int local_74 [2];
  undefined **local_6c;
  HBRUSH local_68;
  CPalette *local_64;
  undefined4 local_60;
  int *local_5c;
  int *local_58;
  int *local_54;
  code *local_50;
  CDC *local_4c;
  tagRECT local_48;
  code *local_38;
  int iStack_34;
  code *local_30;
  int iStack_2c;
  RECT local_28;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_58 = param_2;
  pCVar3 = (CPalette *)in_ECX[0x200];
  local_4c = param_1;
  local_54 = in_ECX;
  if (pCVar3 == (CPalette *)0x0) {
    FUN_007d6704(0);
    pCVar3 = (CPalette *)in_ECX[0x200];
  }
  local_64 = CDC::SelectPalette(param_1,pCVar3,0);
  RealizePalette(*(HDC *)(param_1 + 4));
  FUN_0081507c(local_74);
  pCVar7 = local_4c;
  local_18.left = *local_58;
  local_18.top = local_58[1];
  local_18.bottom = local_58[3];
  local_50 = (code *)((local_58[2] - local_74[0]) + -8);
  local_28.top = local_58[1];
  local_28.right = local_58[2];
  local_28.bottom = local_58[3];
  piVar6 = (int *)local_54[0x1ec];
  local_28.left = (LONG)local_50;
  local_18.right = (LONG)local_50;
  if (local_54[0x1ec] == 0xffffffff) {
    local_5c = local_54 + 0x1fe;
    piVar6 = (int *)local_54[0x1ed];
    if (*(int *)(*local_5c + -0xc) != 0) {
      local_38 = (code *)((local_18.bottom - local_18.top) + local_18.left);
      iStack_34 = local_58[1];
      iStack_2c = local_58[3];
      pcVar1 = *(code **)(*local_54 + 0x18c);
      local_58 = (int *)local_54[0x1ed];
      local_30 = local_50;
      local_18.right = (LONG)local_38;
      guard_check_icall(local_4c);
      local_50 = (code *)(*pcVar1)();
      if (local_50 == (code *)0x0) {
                    /* WARNING: Subroutine does not return */
        FUN_0078e714();
      }
      FUN_0079f0b8(1);
      pcVar1 = *(code **)(*(int *)pCVar7 + 0x30);
      iVar4 = FUN_007c2511();
      guard_check_icall(*(undefined4 *)(iVar4 + 0x28));
      (*pcVar1)();
      FUN_007c2378(local_5c,&local_38,0x8025);
      pcVar1 = *(code **)(*(int *)pCVar7 + 0x28);
      guard_check_icall(local_50);
      (*pcVar1)();
      piVar6 = local_58;
    }
  }
  local_58 = piVar6;
  InflateRect(&local_18,-2,-2);
  iVar4 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar4 + 0x24);
  iVar4 = FUN_007c2511();
  CDC::Draw3dRect(pCVar7,&local_18,*(ulong *)(iVar4 + 0x24),uVar2);
  InflateRect(&local_18,-1,-1);
  iVar4 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar4 + 0x30);
  iVar4 = FUN_007c2511();
  CDC::Draw3dRect(pCVar7,&local_18,*(ulong *)(iVar4 + 0x30),uVar2);
  InflateRect(&local_18,-1,-1);
  piVar6 = local_58;
  if ((local_58 != (int *)0xffffffff) && ((param_3 & 4) == 0)) {
    iVar4 = FUN_007c2511();
    if (*(int *)(iVar4 + 0x1ac) == 8) {
      UVar5 = GetNearestPaletteIndex(*(HPALETTE *)(local_54[0x200] + 4),(COLORREF)piVar6);
      piVar6 = (int *)(UVar5 & 0xffff | 0x1000000);
    }
    FUN_0079de5e(piVar6);
    FillRect(*(HDC *)(pCVar7 + 4),&local_18,local_68);
    local_6c = CBrush::vftable;
    FUN_00416100();
  }
  local_48.left = local_28.left;
  local_48.top = local_28.top;
  local_48.right = local_28.right;
  local_48.bottom = local_28.bottom;
  InflateRect(&local_48,-2,-2);
  pCVar7 = local_4c;
  if (DAT_00a124d8 != 0) {
    local_5c = (int *)FUN_007c2574();
    pCVar7 = local_4c;
    local_50 = *(code **)(*local_5c + 0x1c8);
    guard_check_icall(local_4c,local_48.left,local_48.top,local_48.right,local_48.bottom,param_3 & 4
                      ,local_54[0x2b],local_54[0x2d]);
    iVar4 = (*local_50)();
    if (iVar4 != 0) goto LAB_007d620f;
  }
  iVar4 = FUN_007c2511();
  hbr = (HBRUSH)0x0;
  if (iVar4 != -0x98) {
    hbr = *(HBRUSH *)(iVar4 + 0x9c);
  }
  FillRect(*(HDC *)(pCVar7 + 4),&local_28,hbr);
  local_60 = 0;
  local_5c = (int *)0x0;
  FUN_00814d1c(pCVar7,0xd,&local_28,param_3 >> 2 & 1,&local_60);
  iVar4 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar4 + 0x30);
  iVar4 = FUN_007c2511();
  CDC::Draw3dRect(pCVar7,&local_28,*(ulong *)(iVar4 + 0x34),uVar2);
  InflateRect(&local_28,-1,-1);
  iVar4 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar4 + 0x20);
  iVar4 = FUN_007c2511();
  CDC::Draw3dRect(pCVar7,&local_28,*(ulong *)(iVar4 + 0x24),uVar2);
LAB_007d620f:
  if (local_64 != (CPalette *)0x0) {
    CDC::SelectPalette(pCVar7,local_64,0);
  }
  return;
}




/* vtable slots: CMFCColorButton[95] */
/* 007d6236  FUN_007d6236  191 bytes, 0 callers */

void FUN_007d6236(CDC *param_1,tagRECT *param_2)

{
  code *pcVar1;
  ulong uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  
  if (DAT_00a124d8 != 0) {
    piVar3 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar3 + 0x1cc);
    iVar4 = FUN_00797c32();
    guard_check_icall(param_1,param_2->left,param_2->top,param_2->right,param_2->bottom,iVar4 == 0,0
                      ,1);
    iVar4 = (*pcVar1)();
    if (iVar4 != 0) {
      return;
    }
  }
  iVar4 = FUN_007c2511();
  uVar2 = *(ulong *)(iVar4 + 0x24);
  iVar4 = FUN_007c2511();
  CDC::Draw3dRect(param_1,param_2,*(ulong *)(iVar4 + 0x30),uVar2);
  InflateRect(param_2,-1,-1);
  if ((*(int *)(in_ECX + 0x80) == 0) || (*(int *)(in_ECX + 0xb4) != 0)) {
    iVar4 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar4 + 0x34);
    iVar4 = FUN_007c2511();
    CDC::Draw3dRect(param_1,param_2,*(ulong *)(iVar4 + 0x20),uVar2);
  }
  return;
}




/* vtable slots: CMFCColorButton[96] */
/* 007d62f5  FUN_007d62f5  83 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d62f5(undefined4 param_1,undefined4 *param_2)

{
  int local_24 [3];
  undefined4 local_18;
  undefined4 uStack_14;
  int local_10;
  undefined4 uStack_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_0081507c(local_24);
  local_18 = *param_2;
  uStack_14 = param_2[1];
  uStack_c = param_2[3];
  local_10 = param_2[2] + (-8 - local_24[0]);
  FUN_007d434e(param_1,&local_18);
  return;
}




/* vtable slots: CMFCColorButton[94] */
/* 007d6348  FUN_007d6348  66 bytes, 0 callers */

void FUN_007d6348(int param_1,RECT *param_2)

{
  int iVar1;
  HBRUSH hbr;
  
  iVar1 = FUN_007d5ec8();
  if (iVar1 == 0) {
    FUN_007d4493(param_1,param_2);
  }
  else {
    iVar1 = FUN_007c2511();
    hbr = (HBRUSH)0x0;
    if (iVar1 != -200) {
      hbr = *(HBRUSH *)(iVar1 + 0xcc);
    }
    FillRect(*(HDC *)(param_1 + 4),param_2,hbr);
  }
  return;
}




/* vtable slots: CMFCColorButton[103] */
/* 007d6521  FUN_007d6521  442 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007d6521(void)

{
  code *pcVar1;
  int iVar2;
  CObject *pCVar3;
  int in_ECX;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x2c;
  local_8 = 0x7d652d;
  if (*(int *)(in_ECX + 0x7ec) == 0) {
    if (*(int *)(in_ECX + 0x7c0) == 0) {
      FUN_0082330d(0,in_ECX + 0x7b8);
    }
    iVar2 = FUN_0078e624(0x1fe8);
    local_8 = 0;
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = CMFCColorPopupMenu(in_ECX,in_ECX + 0x7b8,*(undefined4 *)(in_ECX + 0x7b0),
                                 *(undefined4 *)(in_ECX + 0x7f8),*(undefined4 *)(in_ECX + 0x7f0),
                                 *(undefined4 *)(in_ECX + 0x7f4),in_ECX + 0x7cc,
                                 *(undefined4 *)(in_ECX + 0x7e8),*(undefined4 *)(in_ECX + 0x7b4));
    }
    local_8 = 0xffffffff;
    *(int *)(in_ECX + 0x7ec) = iVar2;
    *(undefined4 *)(iVar2 + 0x1fe0) = *(undefined4 *)(in_ECX + 0x7a8);
    local_24.left = 0;
    local_24.top = 0;
    local_24.right = 0;
    local_24.bottom = 0;
    GetWindowRect(*(HWND *)(in_ECX + 0x20),&local_24);
    pcVar1 = *(code **)(**(int **)(in_ECX + 0x7ec) + 0x210);
    guard_check_icall(in_ECX,local_24.left,local_24.bottom,0,*(undefined4 *)(in_ECX + 0x7a8),0);
    iVar2 = (*pcVar1)();
    if (iVar2 == 0) {
      *(undefined4 *)(in_ECX + 0x7ec) = 0;
    }
    else {
      if (*(int *)(in_ECX + 0x7a8) != 0) {
        pcVar1 = *(code **)(**(int **)(in_ECX + 0x7ec) + 0x1c8);
        guard_check_icall();
        pCVar3 = (CObject *)(*pcVar1)();
        pCVar3 = AfxDynamicDownCast((CRuntimeClass *)&PTR_s_CMFCColorBar_00a007bc,pCVar3);
        if (pCVar3 != (CObject *)0x0) {
          *(undefined4 *)(pCVar3 + 0xe00) = 1;
        }
      }
      local_34.left = 0;
      local_34.top = 0;
      local_34.right = 0;
      local_34.bottom = 0;
      GetWindowRect(*(HWND *)(*(int *)(in_ECX + 0x7ec) + 0x20),&local_34);
      FUN_008218a9(&local_34);
      if (*(int *)(in_ECX + 0x7ac) != 0) {
        pcVar1 = *(code **)(**(int **)(in_ECX + 0x7ec) + 0x1c8);
        guard_check_icall();
        (*pcVar1)();
        FUN_00797df8();
      }
    }
    if (*(int *)(in_ECX + 0xb8) != 0) {
      ReleaseCapture();
      *(undefined4 *)(in_ECX + 0xb8) = 0;
    }
  }
  else {
    SendMessageW(*(HWND *)(*(int *)(in_ECX + 0x7ec) + 0x20),0x10,0,0);
    *(undefined4 *)(in_ECX + 0x7ec) = 0;
  }
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCColorButton[92], CMFCMenuButton[92] */
/* 007d6824  FUN_007d6824  68 bytes, 0 callers */

int * FUN_007d6824(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_c [8];
  
  FUN_007d569c(param_1,0);
  piVar3 = (int *)FUN_0081507c(local_c);
  iVar1 = *piVar3;
  iVar2 = *param_1;
  *param_1 = iVar1 + iVar2;
  if (param_2 == 0) {
    FUN_00797e71(0,0xffffffff,0xffffffff,iVar1 + iVar2,param_1[1],0x16);
  }
  return param_1;
}




/* vtable slots: CMFCColorButton[102] */
/* 007d6868  UpdateColor  73 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCColorButton::UpdateColor(unsigned long)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCColorButton::UpdateColor(CMFCColorButton *this,ulong param_1)

{
  LPARAM lParam;
  HWND pHVar1;
  CWnd *pCVar2;
  uint uVar3;
  
  SetColor(this,param_1);
  pHVar1 = GetParent(*(HWND *)(this + 0x20));
  pCVar2 = CWnd::FromHandle(pHVar1);
  if (pCVar2 != (CWnd *)0x0) {
    lParam = *(LPARAM *)(this + 0x20);
    uVar3 = FUN_00797a2b();
    SendMessageW(*(HWND *)(pCVar2 + 0x20),0x111,uVar3 & 0xffff,lParam);
  }
  return;
}



