/* CMFCControlRenderer -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCControlRenderer[1] */
/* 0089b986  FUN_0089b986  51 bytes, 0 callers */

void FUN_0089b986(byte param_1)

{
  FUN_0089b8c5();
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




/* vtable slots: CMFCControlRenderer[10], CMFCShadowRenderer[10] */
/* 0089b9f2  CleanUp  83 bytes, 1 callers */

/* WARNING: Function: __EH_prolog3_GS replaced with injection: EH_prolog3 */
/* Library Function - Single Match
    public: virtual void __thiscall CMFCControlRenderer::CleanUp(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCControlRenderer::CleanUp(CMFCControlRenderer *this)

{
  undefined1 local_64 [92];
  undefined4 local_8;
  undefined4 uStack_4;
  
  uStack_4 = 0x54;
  local_8 = 0x89b9fe;
  FUN_007e7dd4();
  CMFCToolBarImages::SetTransparentColor((CMFCToolBarImages *)(this + 8),0xffffffff);
  FUN_0089b85b();
  local_8 = 0;
  FUN_0089b929(local_64);
  *(undefined4 *)(this + 0x170) = 0;
  FUN_00406b10();
  FUN_008d9b68();
  return;
}




/* vtable slots: CMFCControlRenderer[3] */
/* 0089ba8b  FUN_0089ba8b  480 bytes, 0 callers */

undefined4 FUN_0089ba8b(undefined4 param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int *in_ECX;
  undefined1 local_24 [18];
  short sStack_12;
  int *local_c;
  int *local_8;
  
  pcVar2 = *(code **)(*in_ECX + 0x28);
  local_8 = in_ECX;
  guard_check_icall();
  (*pcVar2)();
  FUN_0089b929(param_1);
  iVar3 = FUN_0089c8d7();
  if (iVar3 != 0) {
    in_ECX[0x17] = in_ECX[0x4c] - in_ECX[0x4a];
    in_ECX[0x18] = in_ECX[0x4d] - in_ECX[0x4b];
    in_ECX[0x11] = in_ECX[0x5b];
    in_ECX[0xf] = 0;
    FUN_007ea7e7(iVar3,0,0);
    if (param_2 != 0) {
      CMFCToolBarImages::MirrorVert((CMFCToolBarImages *)(in_ECX + 2));
    }
    if (in_ECX[0x5a] != 0xff000000) {
      CMFCToolBarImages::SetTransparentColor((CMFCToolBarImages *)(in_ECX + 2),in_ECX[0x5a]);
    }
    if (((DAT_00a12708 != 0) && ((HANDLE)in_ECX[0x25] != (HANDLE)0x0)) &&
       (in_ECX[0x5a] == -0x1000000)) {
      iVar3 = GetObjectW((HANDLE)in_ECX[0x25],0x18,local_24);
      if ((iVar3 != 0) && (sStack_12 == 0x20)) {
        pcVar2 = *(code **)(*in_ECX + 0x24);
        guard_check_icall();
        (*pcVar2)();
      }
    }
    local_c = in_ECX + 0x52;
    iVar3 = FUN_0079a141();
    if (iVar3 != 0) {
      *local_c = in_ECX[0x4e];
      local_c[1] = in_ECX[0x4f];
      local_c[2] = in_ECX[0x50];
      local_c[3] = in_ECX[0x51];
      in_ECX = local_8;
    }
    iVar3 = FUN_0079a141();
    if (iVar3 != 0) {
      piVar1 = in_ECX + 0x56;
      *piVar1 = 0;
      in_ECX[0x57] = 0;
      in_ECX[0x58] = in_ECX[0x4c] - in_ECX[0x4a];
      in_ECX[0x59] = in_ECX[0x4d] - in_ECX[0x4b];
      *piVar1 = *piVar1 + local_8[0x4e];
      local_8[0x57] = local_8[0x57] + local_8[0x4f];
      local_8[0x58] = local_8[0x58] - local_8[0x50];
      local_8[0x59] = local_8[0x59] - local_8[0x51];
      in_ECX = local_8;
    }
    if (param_2 != 0) {
      iVar3 = in_ECX[0x4f];
      in_ECX[0x4f] = in_ECX[0x51];
      in_ECX[0x51] = iVar3;
      iVar3 = in_ECX[0x53];
      in_ECX[0x53] = in_ECX[0x55];
      in_ECX[0x55] = iVar3;
      iVar3 = in_ECX[0x57];
      in_ECX[0x57] = (in_ECX[0x4d] - in_ECX[0x4b]) - in_ECX[0x59];
      in_ECX[0x59] = (in_ECX[0x4d] - in_ECX[0x4b]) - iVar3;
    }
  }
  return 1;
}




/* vtable slots: CMFCControlRenderer[4] */
/* 0089be07  FUN_0089be07  146 bytes, 0 callers */

void FUN_0089be07(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  guard_check_icall(param_1,in_ECX[0x52] + param_2,param_3 + in_ECX[0x53],param_4 - in_ECX[0x54],
                    param_5 - in_ECX[0x55],param_6,param_7);
  (**(code **)(iVar1 + 0x1c))();
  iVar1 = *in_ECX;
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(iVar1 + 0x14))();
  return;
}




/* vtable slots: CMFCControlRenderer[5] */
/* 0089bf4a  FUN_0089bf4a  1323 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0089bf4a(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int in_ECX;
  int iVar13;
  int local_64;
  int local_60;
  int local_5c;
  int local_28;
  int local_24;
  int local_20;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_18.left = *(int *)(in_ECX + 0x128);
  local_18.top = *(int *)(in_ECX + 300);
  local_18.right = *(int *)(in_ECX + 0x130);
  local_18.bottom = *(int *)(in_ECX + 0x134);
  if (*(int *)(in_ECX + 0xc) == 1) {
    OffsetRect(&local_18,0,(*(int *)(in_ECX + 0x134) - *(int *)(in_ECX + 300)) * param_6);
    param_6 = 0;
  }
  iVar1 = *(int *)(in_ECX + 0x138);
  iVar2 = *(int *)(in_ECX + 0x13c);
  iVar3 = *(int *)(in_ECX + 0x140);
  iVar4 = *(int *)(in_ECX + 0x144);
  iVar9 = iVar1 + param_2;
  iVar5 = *(int *)(in_ECX + 0x148);
  iVar10 = param_4 - iVar3;
  iVar6 = *(int *)(in_ECX + 0x14c);
  iVar7 = *(int *)(in_ECX + 0x150);
  iVar8 = *(int *)(in_ECX + 0x154);
  iVar13 = param_5 - iVar4;
  iVar12 = param_3 + iVar2;
  if (iVar10 == iVar9 || iVar10 - iVar9 < 0) {
    iVar11 = iVar13 - iVar12;
    if (iVar11 < 1) {
      return;
    }
  }
  else {
    iVar11 = iVar13 - iVar12;
  }
  if (0 < iVar11) {
    if (0 < iVar5) {
      if (*(int *)(in_ECX + 0x170) == 0) {
        local_5c = iVar5 + local_18.left;
        local_64 = local_18.left;
      }
      else {
        local_64 = local_18.right - iVar5;
        local_5c = local_18.right;
      }
      local_60 = local_18.top + iVar2;
      FUN_007e94b8(param_1,param_2,iVar12,iVar5 + param_2,iVar13,param_6,0,3,local_64,local_60,
                   local_5c,local_18.bottom - iVar4,param_7);
    }
    if (0 < iVar7) {
      if (*(int *)(in_ECX + 0x170) == 0) {
        local_28 = local_18.right - iVar7;
        local_20 = local_18.right;
      }
      else {
        local_20 = iVar7 + local_18.left;
        local_28 = local_18.left;
      }
      local_24 = local_18.top + iVar2;
      FUN_007e94b8(param_1,param_4 - iVar7,iVar12,param_4,iVar13,param_6,2,3,local_28,local_24,
                   local_20,local_18.bottom - iVar4,param_7);
    }
  }
  if (iVar10 != iVar9 && -1 < iVar10 - iVar9) {
    if (0 < iVar6) {
      iVar12 = iVar3;
      local_28 = iVar1;
      if (*(int *)(in_ECX + 0x170) != 0) {
        iVar12 = iVar1;
        local_28 = iVar3;
      }
      local_28 = local_18.left + local_28;
      FUN_007e94b8(param_1,iVar9,param_3,iVar10,param_3 + iVar6,param_6,3,0,local_28,local_18.top,
                   local_18.right - iVar12,iVar6 + local_18.top,param_7);
    }
    if (0 < iVar8) {
      iVar12 = iVar3;
      local_28 = iVar1;
      if (*(int *)(in_ECX + 0x170) != 0) {
        iVar12 = iVar1;
        local_28 = iVar3;
      }
      local_24 = local_18.bottom - iVar8;
      local_28 = local_18.left + local_28;
      FUN_007e94b8(param_1,iVar9,param_5 - iVar8,iVar10,param_5,param_6,3,2,local_28,local_24,
                   local_18.right - iVar12,local_18.bottom,param_7);
    }
  }
  if ((0 < iVar1) && (0 < iVar2)) {
    iVar12 = local_18.left;
    if (*(int *)(in_ECX + 0x170) != 0) {
      iVar12 = local_18.right - iVar1;
    }
    FUN_007e94b8(param_1,param_2,param_3,param_4,param_5,param_6,0,0,iVar12,local_18.top,
                 iVar12 + iVar1,local_18.top + iVar2,param_7);
  }
  if ((0 < iVar3) && (0 < iVar2)) {
    iVar12 = local_18.left;
    if (*(int *)(in_ECX + 0x170) == 0) {
      iVar12 = local_18.right - iVar3;
    }
    FUN_007e94b8(param_1,param_2,param_3,param_4,param_5,param_6,2,0,iVar12,local_18.top,
                 iVar12 + iVar3,local_18.top + iVar2,param_7);
  }
  if ((0 < iVar1) && (0 < iVar4)) {
    iVar12 = local_18.left;
    if (*(int *)(in_ECX + 0x170) != 0) {
      iVar12 = local_18.right - iVar1;
    }
    FUN_007e94b8(param_1,param_2,param_3,param_4,param_5,param_6,0,2,iVar12,local_18.bottom - iVar4,
                 iVar12 + iVar1,(local_18.bottom - iVar4) + iVar4,param_7);
  }
  if ((0 < iVar3) && (0 < iVar4)) {
    iVar12 = local_18.left;
    if (*(int *)(in_ECX + 0x170) == 0) {
      iVar12 = local_18.right - iVar3;
    }
    FUN_007e94b8(param_1,param_2,param_3,param_4,param_5,param_6,2,2,iVar12,local_18.bottom - iVar4,
                 iVar12 + iVar3,(local_18.bottom - iVar4) + iVar4,param_7);
  }
  return;
}




/* vtable slots: CMFCControlRenderer[7], CMFCShadowRenderer[7] */
/* 0089c7bb  FUN_0089c7bb  61 bytes, 0 callers */

void FUN_0089c7bb(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,3,3,param_6,param_7);
  (**(code **)(iVar1 + 0x18))();
  return;
}




/* vtable slots: CMFCControlRenderer[6], CMFCShadowRenderer[6] */
/* 0089c7f8  FUN_0089c7f8  223 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0089c7f8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,int param_8,
                 undefined4 param_9)

{
  BOOL BVar1;
  int in_ECX;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  BVar1 = IsRectEmpty((RECT *)(in_ECX + 0x158));
  if (BVar1 == 0) {
    local_18.left = ((RECT *)(in_ECX + 0x158))->left;
    local_18.top = *(LONG *)(in_ECX + 0x15c);
    local_18.right = *(int *)(in_ECX + 0x160);
    local_18.bottom = *(LONG *)(in_ECX + 0x164);
    if (*(int *)(in_ECX + 0x170) != 0) {
      local_18.left =
           (*(int *)(in_ECX + 0x130) - *(int *)(in_ECX + 0x160)) - *(int *)(in_ECX + 0x128);
      local_18.right = (*(int *)(in_ECX + 0x160) - *(int *)(in_ECX + 0x158)) + local_18.left;
    }
    OffsetRect(&local_18,*(int *)(in_ECX + 0x128),*(int *)(in_ECX + 300));
    if (*(int *)(in_ECX + 0xc) == 1) {
      OffsetRect(&local_18,0,(*(int *)(in_ECX + 0x134) - *(int *)(in_ECX + 300)) * param_8);
      param_8 = 0;
    }
    FUN_007e94b8(param_1,param_2,param_3,param_4,param_5,param_8,param_6,param_7,local_18.left,
                 local_18.top,local_18.right,local_18.bottom,param_9);
  }
  return;
}




/* vtable slots: CMFCControlRenderer[0] */
/* 0089c8e4  FUN_0089c8e4  6 bytes, 0 callers */

undefined ** FUN_0089c8e4(void)

{
  return &PTR_s_CMFCControlRenderer_0099dfa8;
}




/* vtable slots: CMFCControlRenderer[9], CMFCShadowRenderer[9] */
/* 0089c8f0  Mirror  34 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void __thiscall CMFCControlRenderer::Mirror(void)
   
   Library: Visual Studio 2015 Release */

void __thiscall CMFCControlRenderer::Mirror(CMFCControlRenderer *this)

{
  int iVar1;
  
  iVar1 = CMFCToolBarImages::Mirror((CMFCToolBarImages *)(this + 8));
  if (iVar1 != 0) {
    *(uint *)(this + 0x170) = (uint)(*(int *)(this + 0x170) == 0);
  }
  return;
}




/* vtable slots: CMFCControlRenderer[8] */
/* 0089c912  FUN_0089c912  18 bytes, 0 callers */

void FUN_0089c912(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x94) != 0) {
    FUN_007eb3bb();
    return;
  }
  return;
}



