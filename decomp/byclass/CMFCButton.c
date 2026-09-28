/* CMFCButton -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCButton[1], CMFCOutlookBarScrollButton[1], CMFCTabButton[1] */
/* 007d3735  FUN_007d3735  51 bytes, 0 callers */

void FUN_007d3735(byte param_1)

{
  FUN_007d369b();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0();
    }
    else {
      _Adl_verify_range<>();
    }
  }
  return;
}




/* vtable slots: CMFCButton[91], CMFCColorButton[91], CMFCLinkCtrl[91], CMFCMenuButton[91], CMFCOutlookBarScrollButton[91], CMFCTabButton[91] */
/* 007d3908  CleanUp  98 bytes, 1 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCButton::CleanUp(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCButton::CleanUp(CMFCButton *this)

{
  *(undefined4 *)(this + 0x780) = 0xffffffff;
  *(undefined4 *)(this + 0x784) = 0xffffffff;
  *(undefined4 *)(this + 0xe0) = 0;
  *(undefined4 *)(this + 0xe4) = 0;
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  FUN_007e7dd4();
  return;
}




/* vtable slots: CMFCButton[90], CMFCColorButton[90], CMFCLinkCtrl[90], CMFCMenuButton[90], CMFCOutlookBarScrollButton[90], CMFCTabButton[90] */
/* 007d3bd2  FUN_007d3bd2  233 bytes, 0 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007d3bd2(int *param_1)

{
  code *pcVar1;
  CDC *pCVar2;
  int *in_ECX;
  undefined1 *puVar3;
  undefined1 *local_5c;
  int local_58;
  undefined1 local_50 [44];
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x7d3bde;
  if ((param_1 != (int *)0x0) && (*param_1 == 4)) {
    pCVar2 = CDC::FromHandle((HDC__ *)param_1[6]);
    FUN_007e522a(pCVar2,in_ECX);
    local_8 = 0;
    puVar3 = local_50;
    if (local_58 == 0) {
      puVar3 = local_5c;
    }
    CopyRect(&local_24,(RECT *)(param_1 + 7));
    pcVar1 = *(code **)(*in_ECX + 0x178);
    guard_check_icall(puVar3,&local_24);
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x17c);
    guard_check_icall(puVar3,&local_24,param_1[4]);
    (*pcVar1)();
    pcVar1 = *(code **)(*in_ECX + 0x184);
    guard_check_icall(puVar3,&local_24,param_1[4]);
    (*pcVar1)();
    if (((*(byte *)(param_1 + 4) & 0x10) != 0) && (in_ECX[0x25] != 0)) {
      pcVar1 = *(code **)(*in_ECX + 0x180);
      guard_check_icall(puVar3,&local_24);
      (*pcVar1)();
    }
    FUN_007e54da();
    FUN_008d9b68();
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCButton[100], CMFCColorButton[100], CMFCLinkCtrl[100], CMFCMenuButton[100], CMFCOutlookBarScrollButton[100], CMFCTabButton[100] */
/* 007d3cd2  FUN_007d3cd2  4 bytes, 0 callers */

undefined4 FUN_007d3cd2(void)

{
  return 10;
}




/* vtable slots: CMFCButton[10], CMFCOutlookBarScrollButton[10], CMFCTabButton[10] */
/* 007d3cd6  FUN_007d3cd6  6 bytes, 0 callers */

undefined ** FUN_007d3cd6(void)

{
  return &PTR_FUN_009876b8;
}




/* vtable slots: CMFCButton[0], CMFCOutlookBarScrollButton[0], CMFCTabButton[0] */
/* 007d3cdc  FUN_007d3cdc  6 bytes, 0 callers */

undefined ** FUN_007d3cdc(void)

{
  return &PTR_s_CMFCButton_009872f8;
}




/* vtable slots: CMFCButton[101], CMFCColorButton[101], CMFCLinkCtrl[101], CMFCMenuButton[101], CMFCOutlookBarScrollButton[101], CMFCTabButton[101] */
/* 007d3ce2  FUN_007d3ce2  4 bytes, 0 callers */

undefined4 FUN_007d3ce2(void)

{
  return 5;
}




/* vtable slots: CMFCButton[97], CMFCOutlookBarScrollButton[97], CMFCTabButton[97] */
/* 007d3e15  FUN_007d3e15  1327 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007d3e15(int *param_1,int *param_2,uint param_3)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  BOOL BVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  int *in_ECX;
  int *piVar10;
  undefined1 local_6c [4];
  undefined1 local_68 [4];
  int *local_64;
  int local_60;
  undefined1 local_5c [4];
  undefined4 local_58;
  int *local_54;
  uint local_50;
  int local_4c;
  int local_48;
  tagRECT local_44;
  tagRECT local_34;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x60;
  local_8 = 0x7d3e21;
  local_64 = param_1;
  local_34.left = *param_2;
  local_34.top = param_2[1];
  local_34.right = param_2[2];
  local_34.bottom = param_2[3];
  local_24.left = *param_2;
  local_24.top = param_2[1];
  local_24.right = param_2[2];
  local_24.bottom = param_2[3];
  CStringT<>();
  local_8 = 0;
  FUN_00792c64(&local_48);
  if (in_ECX[0x38] == 0) {
    SetRectEmpty(&local_24);
  }
  else {
    if (*(int *)(local_48 + -0xc) != 0) {
      if (in_ECX[0x23] == 0) {
        pcVar1 = *(code **)(*in_ECX + 400);
        if (in_ECX[0x22] == 0) {
          guard_check_icall();
          iVar3 = (*pcVar1)();
          local_34.left = local_34.left + in_ECX[0x38] + iVar3 / 2;
          pcVar1 = *(code **)(*in_ECX + 400);
          guard_check_icall();
          iVar3 = (*pcVar1)();
          local_24.left = local_24.left + iVar3 / 2;
          local_24.right = local_34.left;
        }
        else {
          guard_check_icall();
          iVar3 = (*pcVar1)();
          local_34.right = local_34.right + (-in_ECX[0x38] - iVar3 / 2);
          pcVar1 = *(code **)(*in_ECX + 400);
          local_24.left = local_34.right;
          guard_check_icall();
          iVar3 = (*pcVar1)();
          local_24.right = local_24.right - iVar3 / 2;
        }
      }
      else {
        pcVar1 = *(code **)(*in_ECX + 0x194);
        guard_check_icall();
        iVar3 = (*pcVar1)();
        local_34.top = iVar3 + in_ECX[0x39] + local_24.top;
        pcVar1 = *(code **)(*in_ECX + 0x194);
        local_24.bottom = local_34.top;
        guard_check_icall();
        iVar3 = (*pcVar1)();
        local_34.bottom = local_34.bottom - iVar3;
      }
    }
    iVar3 = (local_24.bottom - in_ECX[0x39]) - local_24.top;
    if (iVar3 / 2 < 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = -(iVar3 / 2);
    }
    InflateRect(&local_24,-(((local_24.right - in_ECX[0x38]) - local_24.left) / 2),iVar3);
  }
  piVar10 = local_64;
  pcVar1 = *(code **)(*in_ECX + 0x18c);
  guard_check_icall(local_64);
  iVar3 = (*pcVar1)();
  if (iVar3 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_0078e714();
  }
  FUN_0079f0b8(1);
  local_4c = in_ECX[0x1e6];
  if (local_4c == -1) {
    iVar4 = FUN_007c2511();
    local_4c = *(int *)(iVar4 + 0x28);
  }
  if ((in_ECX[0x2d] != 0) && (in_ECX[0x1e7] != -1)) {
    local_4c = in_ECX[0x1e7];
  }
  local_60 = 0;
  local_50 = 0x8000;
  iVar4 = FUN_0044e690(10,0);
  if (iVar4 < 0) {
    uVar5 = 0x8024;
    local_60 = 1;
    local_50 = 0x8024;
  }
  else {
    pcVar1 = *(code **)(*in_ECX + 0x194);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    InflateRect(&local_34,0,-(iVar4 / 2));
    uVar5 = 0x8000;
  }
  iVar4 = in_ECX[0x21];
  if (iVar4 == 0) {
    pcVar1 = *(code **)(*in_ECX + 400);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    local_34.left = local_34.left + iVar4 / 2;
  }
  else if (iVar4 == 1) {
    local_50 = uVar5 | 2;
    pcVar1 = *(code **)(*in_ECX + 400);
    guard_check_icall();
    iVar4 = (*pcVar1)();
    local_34.right = local_34.right - iVar4 / 2;
  }
  else if (iVar4 == 2) {
    local_50 = uVar5 | 1;
  }
  uVar5 = FUN_00797acc();
  if ((uVar5 & 0x400000) != 0) {
    local_50 = local_50 | 0x20000;
  }
  local_54 = (int *)(param_3 & 4);
  if ((local_54 != (int *)0x0) && (in_ECX[0x27] != 0)) {
    pcVar1 = *(code **)(*piVar10 + 0x30);
    iVar4 = FUN_007c2511();
    guard_check_icall(*(undefined4 *)(iVar4 + 0x24));
    (*pcVar1)();
    local_44.left = local_34.left;
    local_44.top = local_34.top;
    local_44.right = local_34.right;
    local_44.bottom = local_34.bottom;
    OffsetRect(&local_44,1,1);
    piVar10 = local_64;
    pcVar1 = *(code **)(*in_ECX + 0x188);
    guard_check_icall(local_64,&local_44,&local_48,local_50,param_3);
    (*pcVar1)();
    iVar4 = FUN_007c2511();
    local_4c = *(int *)(iVar4 + 0x38);
  }
  pcVar1 = *(code **)(*piVar10 + 0x30);
  guard_check_icall(local_4c);
  (*pcVar1)();
  if (in_ECX[0x36] != 0) {
    iVar4 = local_34.right - local_34.left;
    piVar6 = (int *)FUN_00566800(local_68,&local_48);
    if ((*piVar6 <= iVar4) || (local_60 == 0)) {
      local_48 = 0;
    }
    FUN_007d55d4(local_48);
    in_ECX[0x36] = 0;
  }
  pcVar1 = *(code **)(*in_ECX + 0x188);
  guard_check_icall(piVar10,&local_34,&local_48,local_50,param_3);
  (*pcVar1)();
  BVar7 = IsRectEmpty(&local_24);
  if (BVar7 != 0) goto LAB_007d4318;
  iVar4 = in_ECX[0x1e0];
  if (iVar4 != -1) {
    if (((local_54 != (int *)0x0) && (in_ECX[0x27] != 0)) && (in_ECX[0x1e1] != 0)) {
      iVar4 = in_ECX[0x1e1];
    }
    local_58 = 0;
    local_54 = (int *)0x0;
    FUN_00814c80(piVar10,iVar4,&local_24,in_ECX[0x1e2],&local_58);
    goto LAB_007d4318;
  }
  if ((local_54 == (int *)0x0) || (in_ECX[0x27] == 0)) {
    bVar2 = false;
LAB_007d4226:
    if ((in_ECX[0x2d] == 0) || (iVar4 = 0x550, in_ECX[0x155] == 0)) {
      iVar4 = 0x438;
    }
    local_54 = (int *)(iVar4 + (int)in_ECX);
    if (bVar2) goto LAB_007d4249;
LAB_007d4258:
    if ((in_ECX[0x2d] == 0) || (local_4c = 0x208, in_ECX[0x83] == 0)) {
      local_4c = 0xf0;
    }
  }
  else {
    bVar2 = true;
    if (in_ECX[0x19b] == 0) goto LAB_007d4226;
    local_54 = in_ECX + 0x19a;
LAB_007d4249:
    if (in_ECX[0xc9] == 0) goto LAB_007d4258;
    local_4c = 800;
  }
  if ((in_ECX[0x30] == 0) || (local_54[1] == 0)) {
    if (*(int *)((int)in_ECX + local_4c + 4) == 0) goto LAB_007d4318;
    FUN_007eb6ca(local_5c,0,0,0);
    if ((bVar2) && (in_ECX[0xc9] == 0)) {
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
    FUN_007e8cae(piVar10,local_24.left,local_24.top,0,0,uVar8,0,0,0,0xff);
    puVar9 = local_5c;
  }
  else {
    FUN_007eb6ca(local_6c,0,0,0);
    if ((bVar2) && (in_ECX[0x19b] == 0)) {
      uVar8 = 1;
    }
    else {
      uVar8 = 0;
    }
    FUN_007e8cae(piVar10,local_24.left,local_24.top,0,0,uVar8,0,0,0,0xff);
    puVar9 = local_6c;
  }
  FUN_007e98b8(puVar9);
LAB_007d4318:
  pcVar1 = *(code **)(*piVar10 + 0x28);
  guard_check_icall(iVar3);
  (*pcVar1)();
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCButton[95], CMFCLinkCtrl[95], CMFCMenuButton[95] */
/* 007d4345  FUN_007d4345  9 bytes, 0 callers */

void FUN_007d4345(void)

{
  FUN_007d3a0a();
  return;
}




/* vtable slots: CMFCButton[96], CMFCMenuButton[96], CMFCOutlookBarScrollButton[96], CMFCTabButton[96] */
/* 007d434e  FUN_007d434e  147 bytes, 1 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d434e(CDC *param_1,LONG *param_2)

{
  int iVar1;
  int in_ECX;
  ulong uVar2;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = *param_2;
  local_18.top = param_2[1];
  local_18.right = param_2[2];
  local_18.bottom = param_2[3];
  InflateRect(&local_18,-1,-1);
  uVar2 = *(ulong *)(in_ECX + 0x7a0);
  if (uVar2 == 0xffffffff) {
    iVar1 = FUN_007c2511();
    uVar2 = *(ulong *)(iVar1 + 0x1c);
  }
  if ((DAT_00a124d8 == 0) || (*(int *)(in_ECX + 0xa4) != 0)) {
    InflateRect(&local_18,-1,-1);
    CDC::Draw3dRect(param_1,&local_18,uVar2,uVar2);
  }
  DrawFocusRect(*(HDC *)(param_1 + 4),&local_18);
  return;
}




/* vtable slots: CMFCButton[93], CMFCColorButton[93], CMFCLinkCtrl[93], CMFCMenuButton[93], CMFCOutlookBarScrollButton[93], CMFCTabButton[93] */
/* 007d43e1  FUN_007d43e1  34 bytes, 0 callers */

void FUN_007d43e1(undefined4 param_1)

{
  undefined4 in_ECX;
  
  FUN_007c2511();
  FUN_007e58d9(in_ECX,param_1,&stack0x00000008);
  return;
}




/* vtable slots: CMFCButton[98], CMFCColorButton[98], CMFCLinkCtrl[98], CMFCMenuButton[98], CMFCOutlookBarScrollButton[98], CMFCTabButton[98] */
/* 007d4403  FUN_007d4403  63 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007d4403(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18 = *param_2;
  uStack_14 = param_2[1];
  uStack_10 = param_2[2];
  uStack_c = param_2[3];
  FUN_007c2378(param_3,&local_18,param_4);
  return;
}




/* vtable slots: CMFCButton[94], CMFCLinkCtrl[94], CMFCMenuButton[94] */
/* 007d4493  FUN_007d4493  193 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */

void FUN_007d4493(CDC *param_1,RECT *param_2)

{
  int iVar1;
  HBRUSH hbr;
  int in_ECX;
  CDrawingManager local_18 [16];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 8;
  local_8 = 0x7d449f;
  if (*(int *)(in_ECX + 0x90) == 0) {
    if (*(int *)(in_ECX + 0x7a0) == -1) {
      iVar1 = FUN_007c2511();
      if (iVar1 == -0x98) {
        hbr = (HBRUSH)0x0;
      }
      else {
        hbr = *(HBRUSH *)(iVar1 + 0x9c);
      }
      FillRect(*(HDC *)(param_1 + 4),param_2,hbr);
    }
    else {
      FUN_007a506d(param_2,*(int *)(in_ECX + 0x7a0));
    }
  }
  else {
    FUN_007c2511();
    FUN_007e58d9(in_ECX,param_1,0);
  }
  if (((*(int *)(in_ECX + 0xc0) != 0) && (*(int *)(in_ECX + 0x98) != 0)) &&
     ((*(int *)(in_ECX + 0xac) == 0 || (*(int *)(in_ECX + 0xb4) == 0)))) {
    CDrawingManager::CDrawingManager(local_18,param_1);
    local_8 = 0;
    FUN_00818045(param_2->left,param_2->top,param_2->right,param_2->bottom,0xffffffff,0xffffffff,0,
                 0xffffffff);
    FUN_0081510b();
  }
  return;
}




/* vtable slots: CMFCButton[25], CMFCColorButton[25], CMFCLinkCtrl[25], CMFCMenuButton[25], CMFCOutlookBarScrollButton[25], CMFCTabButton[25] */
/* 007d4f3e  PreCreateWindow  44 bytes, 0 callers */

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual int __thiscall CMFCButton::PreCreateWindow(struct tagCREATESTRUCTA &)
    protected: virtual int __thiscall CMFCButton::PreCreateWindow(struct tagCREATESTRUCTW &)
   
   Library: Visual Studio 2015 Release */

void PreCreateWindow(int param_1)

{
  CMFCButton *in_ECX;
  
  CMFCButton::InitStyle(in_ECX,*(ulong *)(param_1 + 0x20));
  *(uint *)(param_1 + 0x20) = *(uint *)(param_1 + 0x20) & 0xfffffffe | 10;
  PreCreateWindow(param_1);
  return;
}




/* vtable slots: CMFCButton[20], CMFCColorButton[20], CMFCLinkCtrl[20], CMFCMenuButton[20], CMFCOutlookBarScrollButton[20], CMFCTabButton[20] */
/* 007d4f6a  PreSubclassWindow  37 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCButton::PreSubclassWindow(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCButton::PreSubclassWindow(CMFCButton *this)

{
  ulong uVar1;
  
  uVar1 = FUN_00797b3d();
  InitStyle(this,uVar1);
  FUN_00797c5d(1,0xb,0);
  guard_check_icall();
  return;
}




/* vtable slots: CMFCButton[67], CMFCColorButton[67], CMFCOutlookBarScrollButton[67], CMFCTabButton[67] */
/* 007d4f8f  FUN_007d4f8f  346 bytes, 2 callers */

undefined4 FUN_007d4f8f(int param_1)

{
  HWND pHVar1;
  CWnd *pCVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  HWND hWnd;
  undefined4 uVar5;
  
  hWnd = (HWND)0x0;
  iVar4 = *(int *)(in_ECX + 0x78c);
  if (((iVar4 != 0) && (*(int *)(iVar4 + 0x20) != 0)) &&
     ((*(int *)(param_1 + 4) == 0x201 ||
      ((*(int *)(param_1 + 4) == 0x202 || (*(int *)(param_1 + 4) == 0x200)))))) {
    SendMessageW(*(HWND *)(iVar4 + 0x20),0x407,0,param_1);
  }
  if (*(int *)(param_1 + 4) == 0x100) {
    if ((*(int *)(param_1 + 8) == 0xd) && (DAT_00a139c8 == 0)) {
      pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
      pCVar2 = CWnd::FromHandle(pHVar1);
      if (pCVar2 != (CWnd *)0x0) {
        pHVar1 = *(HWND *)(in_ECX + 0x20);
        uVar3 = FUN_00797a2b();
        hWnd = *(HWND *)(pCVar2 + 0x20);
        goto LAB_007d5022;
      }
    }
    if ((*(int *)(param_1 + 4) == 0x100) && (*(int *)(in_ECX + 0xcc) != 0)) {
      pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
      pCVar2 = CWnd::FromHandle(pHVar1);
      if (pCVar2 != (CWnd *)0x0) {
        iVar4 = *(int *)(param_1 + 8);
        if (iVar4 == 0x20) {
          if (*(int *)(in_ECX + 0xc4) != 0) {
            *(uint *)(in_ECX + 0xc0) = (uint)(*(int *)(in_ECX + 0xc0) == 0);
            RedrawWindow(*(HWND *)(in_ECX + 0x20),(RECT *)0x0,(HRGN)0x0,0x105);
            pHVar1 = GetParent(*(HWND *)(in_ECX + 0x20));
            pCVar2 = CWnd::FromHandle(pHVar1);
            pHVar1 = *(HWND *)(in_ECX + 0x20);
            uVar3 = GetWindowLongW(pHVar1,-0xc);
            if (pCVar2 != (CWnd *)0x0) {
              hWnd = *(HWND *)(pCVar2 + 0x20);
            }
LAB_007d5022:
            SendMessageW(hWnd,0x111,uVar3 & 0xffff,(LPARAM)pHVar1);
            return 1;
          }
        }
        else {
          if ((iVar4 == 0x25) || (iVar4 == 0x26)) {
            uVar5 = 0;
          }
          else {
            if ((iVar4 != 0x27) && (iVar4 != 0x28)) goto LAB_007d507d;
            uVar5 = 1;
          }
          iVar4 = FUN_007d37eb(uVar5);
          if (iVar4 != 0) {
            return 1;
          }
        }
      }
    }
  }
LAB_007d507d:
  uVar5 = FUN_007949fb(param_1);
  return uVar5;
}




/* vtable slots: CMFCButton[99], CMFCColorButton[99], CMFCLinkCtrl[99], CMFCMenuButton[99], CMFCOutlookBarScrollButton[99], CMFCTabButton[99] */
/* 007d50e9  FUN_007d50e9  105 bytes, 1 callers */

void FUN_007d50e9(int *param_1)

{
  DWORD DVar1;
  int iVar2;
  CGdiObject *pCVar3;
  int in_ECX;
  
  if (*(HGDIOBJ *)(in_ECX + 0x790) != (HGDIOBJ)0x0) {
    DVar1 = GetObjectType(*(HGDIOBJ *)(in_ECX + 0x790));
    if (DVar1 != 6) {
      *(undefined4 *)(in_ECX + 0x790) = 0;
    }
  }
  iVar2 = *param_1;
  if (*(void **)(in_ECX + 0x790) == (void *)0x0) {
    guard_check_icall(0x11);
    iVar2 = (**(code **)(iVar2 + 0x24))();
  }
  else {
    pCVar3 = CGdiObject::FromHandle(*(void **)(in_ECX + 0x790));
    guard_check_icall(pCVar3);
    iVar2 = (**(code **)(iVar2 + 0x28))();
  }
  if (iVar2 != 0) {
    return;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCButton[92], CMFCLinkCtrl[92], CMFCOutlookBarScrollButton[92], CMFCTabButton[92] */
/* 007d569c  FUN_007d569c  599 bytes, 2 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */

void FUN_007d569c(int *param_1,int param_2)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  int local_4c [5];
  int *local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  tagRECT local_24;
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x3c;
  local_8 = 0x7d56a8;
  local_38 = param_1;
  if ((in_ECX != (int *)0x0) && (in_ECX[8] != 0)) {
    FUN_0079dea2(in_ECX);
    local_8 = 0;
    pcVar1 = *(code **)(*in_ECX + 0x18c);
    guard_check_icall(local_4c);
    local_34 = (*pcVar1)();
    if (local_34 != 0) {
      CStringT<>();
      local_8 = CONCAT31(local_8._1_3_,1);
      FUN_00792c64(&local_30);
      iVar2 = FUN_0044e690(10,0);
      if (iVar2 < 0) {
        piVar3 = (int *)FUN_00566800(&local_24.right,&local_30);
        local_28 = *piVar3;
        local_2c = piVar3[1];
      }
      else {
        local_24.left = 0;
        local_24.top = 0;
        local_24.right = 0;
        local_24.bottom = 0;
        GetClientRect((HWND)in_ECX[8],&local_24);
        pcVar1 = *(code **)(local_4c[0] + 0x68);
        guard_check_icall(local_30,*(undefined4 *)(local_30 + -0xc),&local_24,0x400);
        (*pcVar1)();
        local_28 = local_24.right - local_24.left;
        local_2c = local_24.bottom - local_24.top;
      }
      if (in_ECX[0x23] == 0) {
        pcVar1 = *(code **)(*in_ECX + 400);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        iVar2 = iVar2 + in_ECX[0x38] + local_28;
        if (0 < local_28) {
          pcVar1 = *(code **)(*in_ECX + 400);
          guard_check_icall();
          iVar4 = (*pcVar1)();
          iVar2 = iVar2 + iVar4;
        }
        if (local_2c <= in_ECX[0x39]) {
          local_2c = in_ECX[0x39];
        }
        pcVar1 = *(code **)(*in_ECX + 0x194);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        iVar4 = local_2c + iVar4 * 2;
      }
      else {
        local_24.bottom = in_ECX[0x38];
        if (local_24.bottom < local_28) {
          local_24.bottom = local_28;
        }
        pcVar1 = *(code **)(*in_ECX + 400);
        guard_check_icall();
        iVar2 = (*pcVar1)();
        iVar2 = iVar2 + local_24.bottom;
        local_24.bottom = iVar2;
        if (0 < local_28) {
          pcVar1 = *(code **)(*in_ECX + 400);
          guard_check_icall();
          local_24.bottom = (*pcVar1)();
          local_24.bottom = iVar2 + local_24.bottom;
        }
        iVar2 = in_ECX[0x39];
        pcVar1 = *(code **)(*in_ECX + 0x194);
        guard_check_icall();
        iVar4 = (*pcVar1)();
        local_28 = iVar2 + iVar4 + local_2c;
        if (0 < iVar2) {
          pcVar1 = *(code **)(*in_ECX + 0x194);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          local_28 = local_28 + iVar2;
        }
        iVar4 = local_28;
        iVar2 = local_24.bottom;
        if (0 < local_2c) {
          pcVar1 = *(code **)(*in_ECX + 0x194);
          guard_check_icall();
          iVar2 = (*pcVar1)();
          iVar4 = local_28 + iVar2;
          iVar2 = local_24.bottom;
        }
      }
      if (param_2 == 0) {
        FUN_00797e71(0,0xffffffff,0xffffffff,iVar2,iVar4,0x16);
      }
      FUN_0079efbc(local_34);
      *local_38 = iVar2;
      local_38[1] = iVar4;
      FUN_00406b10();
      FUN_0079dfff();
      FUN_008d9b68();
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0078e714();
}




/* vtable slots: CMFCButton[45], CMFCColorButton[45], CMFCLinkCtrl[45], CMFCMenuButton[45], CMFCOutlookBarScrollButton[45], CMFCTabButton[45] */
/* 007d59e6  FUN_007d59e6  92 bytes, 0 callers */

int FUN_007d59e6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  iVar1 = FUN_00796da3(param_1,param_2,param_3,param_4,param_5);
  if (-1 < iVar1) {
    if (*(int *)(in_ECX + 0xb4) != 0) {
      *(uint *)(param_5 + 8) = *(uint *)(param_5 + 8) | 0x80;
    }
    if (*(int *)(in_ECX + 0xc0) != 0) {
      if (*(int *)(in_ECX + 200) == 0) {
        uVar2 = *(uint *)(param_5 + 8) | 0x10;
      }
      else {
        uVar2 = *(uint *)(param_5 + 8) | 2;
      }
      *(uint *)(param_5 + 8) = uVar2;
    }
  }
  return iVar1;
}



