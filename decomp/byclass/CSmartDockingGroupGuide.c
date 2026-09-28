/* CSmartDockingGroupGuide -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSmartDockingGroupGuide[1] */
/* 008c2b6b  `scalar_deleting_destructor'  51 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CSmartDockingGroupGuide::`scalar deleting destructor'(unsigned
   int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CSmartDockingGroupGuide::_scalar_deleting_destructor_(CSmartDockingGroupGuide *this,uint param_1)

{
  ~CSmartDockingGroupGuide(this);
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x318);
    }
  }
  return this;
}




/* vtable slots: CSmartDockingGroupGuide[10] */
/* 008c2e2f  FUN_008c2e2f  400 bytes, 0 callers */

void FUN_008c2e2f(int param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  HPEN pHVar5;
  int iVar6;
  undefined4 uVar7;
  int *in_ECX;
  undefined1 local_c [4];
  int *local_8;
  
  in_ECX[1] = param_1;
  in_ECX[0xbc] = param_2;
  pcVar1 = *(code **)(*in_ECX + 0x24);
  local_8 = in_ECX;
  guard_check_icall(&DAT_00a13b48);
  (*pcVar1)();
  if (in_ECX[0xba] != 0) {
    iVar3 = FUN_008c39e3();
    if (iVar3 == 1) {
      DAT_00a13b54 = 9;
      DAT_00a13b4c = 0x58;
      DAT_00a13b50 = DAT_00a13b4c;
    }
    else if (iVar3 == 2) {
      DAT_00a13b54 = 5;
      DAT_00a13b4c = 0x6e;
      DAT_00a13b50 = DAT_00a13b4c;
    }
  }
  piVar4 = (int *)FUN_007c2574();
  pcVar1 = *(code **)(*piVar4 + 0x1d0);
  guard_check_icall(local_c,in_ECX + 0xbd);
  (*pcVar1)();
  pHVar5 = CreatePen(0,1,in_ECX[0xbd]);
  Attach(pHVar5);
  pHVar5 = CreatePen(0,1,0xca7041);
  Attach(pHVar5);
  iVar2 = DAT_00a13b50;
  iVar3 = local_8[1];
  iVar6 = local_8[0x3d];
  if (iVar3 == 4) {
    local_8[0xc2] = 0;
  }
  else {
    if (iVar3 == 5) {
      iVar6 = DAT_00a13b4c - iVar6;
    }
    else {
      if (iVar3 == 6) {
        iVar6 = DAT_00a13b4c - iVar6;
        local_8[0xc3] = 0;
        local_8[0xc2] = iVar6 / 2;
        goto LAB_008c2f83;
      }
      if (iVar3 == 7) {
        iVar3 = DAT_00a13b50 - local_8[0x3e];
        local_8[0xc2] = (DAT_00a13b4c - iVar6) / 2;
        local_8[0xc3] = iVar3;
        goto LAB_008c2f83;
      }
      if (iVar3 != 8) goto LAB_008c2f83;
      iVar6 = (DAT_00a13b4c - iVar6) / 2;
    }
    local_8[0xc2] = iVar6;
  }
  local_8[0xc3] = (iVar2 - local_8[0x3e]) / 2;
LAB_008c2f83:
  uVar7 = FUN_007e8b71(local_8[0x4b],DAT_00a13b58);
  Attach(uVar7);
  OffsetRgn((HRGN)local_8[0xb5],local_8[0xc2],local_8[0xc3]);
  return;
}




/* vtable slots: CSmartDockingGroupGuide[11] */
/* 008c34cd  FUN_008c34cd  11 bytes, 0 callers */

void FUN_008c34cd(void)

{
  int in_ECX;
  
  CGdiObject::DeleteObject((CGdiObject *)(in_ECX + 0x2d0));
  return;
}




/* vtable slots: CSmartDockingGroupGuide[12] */
/* 008c34d8  FUN_008c34d8  689 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008c34d8(CDC *param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  LONG LVar3;
  int local_34;
  int local_30;
  int local_2c;
  undefined1 local_28 [4];
  int local_24;
  undefined4 local_20;
  CDC *local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = param_1;
  local_18.left = *(int *)(in_ECX + 0x2e0);
  if (((local_18.left == 0) && (*(int *)(in_ECX + 0x2e8) == 0)) && (*(int *)(in_ECX + 0x244) == 0))
  {
    uVar2 = 1;
    local_20 = 1;
LAB_008c352c:
    local_24 = 0xa0;
  }
  else {
    uVar2 = 0;
    local_20 = 0;
    if ((local_18.left == 0) || (local_24 = 0x1b8, *(int *)(in_ECX + 0x244) == 0))
    goto LAB_008c352c;
  }
  local_24 = local_24 + in_ECX;
  if ((param_2 != 0) && (local_18.left == 0)) {
    local_34 = *(int *)(in_ECX + 0x30c);
    local_30 = *(int *)(in_ECX + 0x308) + *(int *)(local_24 + 0x54);
    local_2c = local_34 + *(int *)(local_24 + 0x58);
    local_18.top = local_18.left;
    local_18.right = local_18.left;
    local_18.bottom = local_18.left;
    FUN_007e94b8(param_1,*(int *)(in_ECX + 0x308),local_34,local_30,local_2c,0,0,0,0,0,0,0,0xc0);
    return;
  }
  FUN_007eb6ca(&local_34,0,0,uVar2);
  FUN_007e8cae(param_1,*(undefined4 *)(in_ECX + 0x308),*(undefined4 *)(in_ECX + 0x30c),0,0,0,0,0,
               local_20,0xff);
  FUN_007e98b8(&local_34);
  if (*(int *)(in_ECX + 0x2e8) == 0) {
    return;
  }
  iVar1 = FUN_008c39e3();
  if (iVar1 == 2) {
    return;
  }
  local_18.left = 0;
  local_18.top = 0;
  local_18.right = 0;
  local_18.bottom = 0;
  GetRgnBox(*(HRGN *)(in_ECX + 0x2d4),&local_18);
  local_20 = FUN_0079efbc((uint)(*(int *)(in_ECX + 0x2e0) != 0) * 8 + 0x2f8 + in_ECX);
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 == 4) {
    local_18.right = local_18.right + -7;
    FUN_0079ec58(local_28,local_18.right,local_18.top);
    CDC::LineTo(param_1,local_18.left,local_18.top);
    CDC::LineTo(param_1,local_18.left,local_18.bottom);
    LVar3 = local_18.right;
LAB_008c3751:
    CDC::LineTo(param_1,LVar3,local_18.bottom);
    uVar2 = 0;
  }
  else {
    if (iVar1 == 5) {
      local_18.left = local_18.left + 7;
      FUN_0079ec58(local_28,local_18.left,local_18.top);
      CDC::LineTo(param_1,local_18.right + -1,local_18.top);
      CDC::LineTo(param_1,local_18.right + -1,local_18.bottom);
      LVar3 = local_18.left;
      goto LAB_008c3751;
    }
    if (iVar1 == 6) {
      local_18.bottom = local_18.bottom + -7;
      FUN_0079ec58(local_28,local_18.left,local_18.bottom);
      CDC::LineTo(param_1,local_18.left,local_18.top);
      CDC::LineTo(param_1,local_18.right,local_18.top);
      LVar3 = local_18.bottom;
    }
    else {
      if (iVar1 != 7) goto LAB_008c376f;
      local_18.top = local_18.top + 7;
      FUN_0079ec58(local_28,local_18.left,local_18.top);
      CDC::LineTo(param_1,local_18.left,local_18.bottom + -1);
      CDC::LineTo(param_1,local_18.right,local_18.bottom + -1);
      LVar3 = local_18.top;
    }
    CDC::LineTo(param_1,local_18.right,LVar3);
    uVar2 = 1;
  }
  ShadeRect(local_1c,local_18.left,local_18.top,local_18.right,local_18.bottom,uVar2);
LAB_008c376f:
  FUN_0079efbc(local_20);
  return;
}




/* vtable slots: CSmartDockingGroupGuide[0], CSmartDockingStandaloneGuide[0] */
/* 008c39dd  FUN_008c39dd  6 bytes, 0 callers */

undefined ** FUN_008c39dd(void)

{
  return &PTR_s_CSmartDockingStandaloneGuide_009a3a88;
}




/* vtable slots: CSmartDockingGroupGuide[7] */
/* 008c3a45  Highlight  38 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CSmartDockingGroupGuide::Highlight(int)
   
   Library: Visual Studio 2015 Release */

void __thiscall CSmartDockingGroupGuide::Highlight(CSmartDockingGroupGuide *this,int param_1)

{
  if (*(int *)(this + 0x2e0) != param_1) {
    *(int *)(this + 0x2e0) = param_1;
    CSmartDockingGroupGuidesWnd::Update((CSmartDockingGroupGuidesWnd *)(*(int *)(this + 0x2f0) + 8))
    ;
  }
  return;
}




/* vtable slots: CSmartDockingGroupGuide[9], CSmartDockingStandaloneGuide[9] */
/* 008c3b11  FUN_008c3b11  515 bytes, 0 callers */

void FUN_008c3b11(int param_1)

{
  code *pcVar1;
  HWND hwnd;
  int iVar2;
  int *piVar3;
  HBITMAP__ *pHVar4;
  int in_ECX;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  uint local_10;
  uint *local_c;
  uint *local_8;
  
  FUN_007e7dd4();
  *(undefined4 *)(in_ECX + 0xb0) = 0xffffffff;
  FUN_007e7dd4();
  switch(*(undefined4 *)(in_ECX + 4)) {
  case 0:
  case 4:
    iVar2 = 0x24;
    iVar7 = 0x38;
    local_8 = (uint *)&DAT_00a00ce4;
    puVar6 = (uint *)&DAT_00a00cd0;
    local_c = (uint *)&DAT_00a00cf8;
    break;
  case 1:
  case 5:
    iVar2 = 0x28;
    iVar7 = 0x3c;
    local_8 = (uint *)&DAT_00a00ce8;
    puVar6 = (uint *)&DAT_00a00cd4;
    local_c = (uint *)&DAT_00a00cfc;
    break;
  case 2:
  case 6:
    iVar2 = 0x2c;
    iVar7 = 0x40;
    local_8 = (uint *)&DAT_00a00cec;
    puVar6 = (uint *)&DAT_00a00cd8;
    local_c = (uint *)&DAT_00a00d00;
    break;
  case 3:
  case 7:
    iVar2 = 0x30;
    iVar7 = 0x44;
    local_8 = (uint *)&DAT_00a00cf0;
    puVar6 = (uint *)&DAT_00a00cdc;
    local_c = (uint *)&DAT_00a00d04;
    break;
  case 8:
    iVar2 = 0x34;
    iVar7 = 0x48;
    local_8 = &DAT_00a00cf4;
    puVar6 = &DAT_00a00ce0;
    local_c = &DAT_00a00d08;
    break;
  default:
    goto switchD_008c3b44_default;
  }
  uVar5 = *(uint *)(iVar2 + param_1);
  local_10 = *(uint *)(iVar7 + param_1);
  *(uint *)(in_ECX + 0x2e8) = (uint)(uVar5 == 0);
  if (uVar5 == 0) {
    iVar2 = FUN_008c39e3();
    if (iVar2 == 1) {
      uVar5 = *puVar6;
    }
    else if (iVar2 == 2) {
      uVar5 = *local_8;
      local_10 = *local_c;
    }
  }
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  *(uint *)(in_ECX + 0xd8) = (uint)(local_10 == 0);
  CMFCToolBarImages::Load((CMFCToolBarImages *)(in_ECX + 0xa0),uVar5,(HINSTANCE__ *)0x0,0);
  FUN_007eb999();
  CMFCToolBarImages::SetTransparentColor
            ((CMFCToolBarImages *)(in_ECX + 0xa0),*(ulong *)(param_1 + 0x10));
  if (local_10 != 0) {
    *(undefined4 *)(in_ECX + 0x1ec) = 0;
    CMFCToolBarImages::Load((CMFCToolBarImages *)(in_ECX + 0x1b8),local_10,(HINSTANCE__ *)0x0,0);
    FUN_007eb999();
    CMFCToolBarImages::SetTransparentColor
              ((CMFCToolBarImages *)(in_ECX + 0x1b8),*(ulong *)(param_1 + 0x10));
  }
  if (*(int *)(in_ECX + 0x2e8) == 0) {
    iVar2 = *(int *)(param_1 + 0x14);
LAB_008c3cb4:
    if ((iVar2 != -1) && (*(int *)(param_1 + 0x18) != -1)) {
      FUN_007e72c0(iVar2,*(undefined4 *)(param_1 + 0x18));
    }
  }
  else {
    iVar2 = -1;
    if (*(int *)(param_1 + 0x18) != -1) goto LAB_008c3cb4;
    piVar3 = (int *)FUN_007c2574();
    pcVar1 = *(code **)(*piVar3 + 0x1d4);
    guard_check_icall();
    (*pcVar1)();
  }
  if (((CSmartDockingStandaloneGuideWnd *)(in_ECX + 8) != (CSmartDockingStandaloneGuideWnd *)0x0) &&
     (hwnd = *(HWND *)(in_ECX + 0x28), hwnd != (HWND)0x0)) {
    pHVar4 = *(HBITMAP__ **)(in_ECX + 0x130);
    if (pHVar4 == (HBITMAP__ *)0x0) {
      pHVar4 = *(HBITMAP__ **)(in_ECX + 300);
    }
    CSmartDockingStandaloneGuideWnd::Assign
              ((CSmartDockingStandaloneGuideWnd *)(in_ECX + 8),pHVar4,0);
    if ((*(int *)(param_1 + 0x54) == 0) && (iVar2 = FUN_008c39e3(), iVar2 != 2)) {
      SetLayeredWindowAttributes(hwnd,*(COLORREF *)(param_1 + 0x10),'\0',1);
    }
  }
switchD_008c3b44_default:
  return;
}




/* vtable slots: CSmartDockingGroupGuide[8] */
/* 008c3d39  IsPtIn  61 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual int __thiscall CSmartDockingGroupGuide::IsPtIn(class CPoint)const 
   
   Library: Visual Studio 2015 Release */

int __thiscall
CSmartDockingGroupGuide::IsPtIn(CSmartDockingGroupGuide *this,int param_2,int param_3)

{
  int iVar1;
  
  if (*(int *)(this + 0x310) == 0) {
    iVar1 = 0;
  }
  else {
    ScreenToClient(*(HWND *)(*(int *)(this + 0x2f0) + 0x28),(LPPOINT)&param_2);
    iVar1 = PtInRegion(*(HRGN *)(this + 0x2d4),param_2,param_3);
  }
  return iVar1;
}



