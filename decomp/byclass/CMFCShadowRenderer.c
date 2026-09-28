/* CMFCShadowRenderer -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMFCShadowRenderer[1] */
/* 0089b9b9  `scalar_deleting_destructor'  57 bytes, 0 callers */

/* Library Function - Single Match
    public: virtual void * __thiscall CMFCShadowRenderer::`scalar deleting destructor'(unsigned int)
   
   Library: Visual Studio 2015 Release */

void * __thiscall
CMFCShadowRenderer::_scalar_deleting_destructor_(CMFCShadowRenderer *this,uint param_1)

{
  *(undefined ***)this = vftable;
  FUN_0089b8c5();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      thunk_FUN_008f43b0(this);
    }
    else {
      _Adl_verify_range<>(this,0x178);
    }
  }
  return this;
}




/* vtable slots: CMFCShadowRenderer[11] */
/* 0089bc6b  FUN_0089bc6b  316 bytes, 0 callers */

bool FUN_0089bc6b(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  HGDIOBJ ho;
  int *in_ECX;
  int iVar4;
  bool bVar5;
  
  pcVar3 = *(code **)(*in_ECX + 0x28);
  guard_check_icall();
  (*pcVar3)();
  ho = (HGDIOBJ)FUN_00818a43(param_1,param_2,param_3,param_4);
  bVar5 = false;
  if (ho != (HGDIOBJ)0x0) {
    iVar4 = 3;
    if (2 < param_1) {
      iVar4 = param_1;
    }
    iVar2 = iVar4 * 2 + 1;
    in_ECX[0x4a] = 0;
    in_ECX[0x4b] = 0;
    in_ECX[0x4c] = iVar2;
    in_ECX[0x4d] = iVar2;
    in_ECX[0x4e] = iVar4;
    in_ECX[0x4f] = iVar4;
    in_ECX[0x50] = iVar4;
    in_ECX[0x51] = iVar4;
    in_ECX[0x52] = iVar4;
    in_ECX[0x53] = iVar4;
    in_ECX[0x54] = iVar4;
    in_ECX[0x55] = iVar4;
    iVar4 = in_ECX[0x4a];
    piVar1 = in_ECX + 0x56;
    *piVar1 = 0;
    in_ECX[0x57] = 0;
    in_ECX[0x58] = in_ECX[0x4c] - iVar4;
    in_ECX[0x59] = in_ECX[0x4d] - in_ECX[0x4b];
    *piVar1 = *piVar1 + in_ECX[0x4e];
    in_ECX[0x57] = in_ECX[0x57] + in_ECX[0x4f];
    in_ECX[0x58] = in_ECX[0x58] - in_ECX[0x50];
    in_ECX[0x59] = in_ECX[0x59] - in_ECX[0x51];
    in_ECX[0x17] = in_ECX[0x4c] - iVar4;
    in_ECX[0x18] = in_ECX[0x4d] - in_ECX[0x4b];
    in_ECX[0xf] = 0;
    in_ECX[0x11] = in_ECX[0x5b];
    FUN_007e79a6(ho,1);
    DeleteObject(ho);
    bVar5 = in_ECX[3] == 1;
  }
  return bVar5;
}




/* vtable slots: CMFCShadowRenderer[4] */
/* 0089be99  FUN_0089be99  177 bytes, 0 callers */

void FUN_0089be99(undefined4 param_1,int param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int local_18;
  int local_10;
  
  if (DAT_00a12708 == 0) {
    local_10 = param_4 - in_ECX[0x54];
    local_18 = local_10 - in_ECX[0x54];
  }
  else {
    local_18 = param_2 + in_ECX[0x52];
    local_10 = local_18 + in_ECX[0x52];
  }
  iVar1 = *in_ECX;
  iVar2 = param_5 - in_ECX[0x55];
  guard_check_icall(param_1,local_18,iVar2 - in_ECX[0x55],local_10,iVar2,param_6,param_7);
  (**(code **)(iVar1 + 0x1c))();
  iVar1 = *in_ECX;
  guard_check_icall(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  (**(code **)(iVar1 + 0x14))();
  return;
}




/* vtable slots: CMFCShadowRenderer[5] */
/* 0089c475  FUN_0089c475  838 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0089c475(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 undefined4 param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  LONG LVar7;
  int in_ECX;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  tagRECT local_18;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_2c = param_1;
  local_18.left = *(int *)(in_ECX + 0x128);
  local_18.top = *(int *)(in_ECX + 300);
  local_18.right = *(int *)(in_ECX + 0x130);
  local_18.bottom = *(int *)(in_ECX + 0x134);
  if (*(int *)(in_ECX + 0xc) == 1) {
    local_30 = in_ECX;
    OffsetRect(&local_18,0,(*(int *)(in_ECX + 0x134) - *(int *)(in_ECX + 300)) * param_6);
    param_6 = 0;
    in_ECX = local_30;
  }
  iVar2 = DAT_00a12708;
  local_40 = *(int *)(in_ECX + 0x138);
  local_3c = *(int *)(in_ECX + 0x13c);
  local_38 = *(int *)(in_ECX + 0x140);
  local_34 = *(int *)(in_ECX + 0x144);
  iVar3 = *(int *)(in_ECX + 0x138) + param_2;
  iVar10 = *(int *)(in_ECX + 0x148);
  local_44 = param_3 + local_3c;
  iVar6 = *(int *)(in_ECX + 0x150);
  iVar1 = *(int *)(in_ECX + 0x154);
  iVar4 = param_4 - *(int *)(in_ECX + 0x140);
  local_1c = param_5 - local_34;
  if (iVar4 - iVar3 < 1) {
    iVar5 = local_1c - local_44;
    if (iVar5 < 1) {
      return;
    }
  }
  else {
    iVar5 = local_1c - local_44;
  }
  if (0 < iVar5) {
    if (DAT_00a12708 == 0) {
      if (0 < iVar6) {
        local_50 = local_44;
        local_4c = param_4;
        local_54 = param_4 - iVar6;
        local_48 = local_1c;
        LVar7 = local_18.right - iVar6;
        local_28 = LVar7;
        local_24 = local_18.top + local_3c;
        iVar6 = local_18.bottom - local_34;
        local_20 = local_18.right;
        local_1c = iVar6;
        uVar9 = 2;
        piVar8 = &local_54;
        iVar10 = local_18.right;
        goto LAB_0089c5df;
      }
    }
    else if (0 < iVar10) {
      local_20 = iVar10 + param_2;
      local_50 = local_18.top + local_3c;
      local_28 = param_2;
      local_4c = iVar10 + local_18.left;
      iVar6 = local_18.bottom - local_34;
      local_24 = local_44;
      local_54 = local_18.left;
      local_48 = iVar6;
      uVar9 = 0;
      piVar8 = &local_28;
      LVar7 = local_18.left;
      iVar10 = iVar10 + local_18.left;
LAB_0089c5df:
      FUN_007e94b8(local_2c,*piVar8,piVar8[1],piVar8[2],piVar8[3],param_6,uVar9,3,LVar7,
                   local_18.top + local_3c,iVar10,iVar6,param_7);
    }
  }
  if ((0 < iVar4 - iVar3) && (0 < iVar1)) {
    local_48 = param_5;
    local_50 = param_5 - iVar1;
    local_28 = local_18.left + local_40;
    local_24 = local_18.bottom - iVar1;
    local_20 = local_18.right - local_38;
    local_1c = local_18.bottom;
    local_54 = iVar3;
    local_4c = iVar4;
    FUN_007e94b8(local_2c,iVar3,local_50,iVar4,param_5,param_6,3,2,local_28,local_24,local_20,
                 local_18.bottom,param_7);
  }
  if (iVar2 == 0) {
    if ((0 < local_38) && (0 < local_3c)) {
      local_28 = local_18.right - local_38;
      local_20 = local_28 + local_38;
      uVar9 = 2;
LAB_0089c6d4:
      local_24 = local_18.top;
      local_1c = local_18.top + local_3c;
      FUN_007e94b8(local_2c,param_2,param_3,param_4,param_5,param_6,uVar9,0,local_28,local_18.top,
                   local_20,local_1c,param_7);
    }
  }
  else {
    if (local_40 < 1) goto LAB_0089c755;
    if (0 < local_3c) {
      local_28 = local_18.left;
      local_20 = local_18.left + local_40;
      uVar9 = 0;
      goto LAB_0089c6d4;
    }
  }
  if ((0 < local_40) && (0 < local_34)) {
    local_28 = local_18.left;
    local_24 = local_18.bottom - local_34;
    local_20 = local_18.left + local_40;
    local_1c = local_24 + local_34;
    FUN_007e94b8(local_2c,param_2,param_3,param_4,param_5,param_6,0,2,local_18.left,local_24,
                 local_20,local_1c,param_7);
  }
LAB_0089c755:
  if ((0 < local_38) && (0 < local_34)) {
    local_28 = local_18.right - local_38;
    local_20 = local_28 + local_38;
    local_24 = local_18.bottom - local_34;
    local_1c = local_24 + local_34;
    FUN_007e94b8(local_2c,param_2,param_3,param_4,param_5,param_6,2,2,local_28,local_24,local_20,
                 local_1c,param_7);
  }
  return;
}




/* vtable slots: CMFCShadowRenderer[0] */
/* 0089c8ea  FUN_0089c8ea  6 bytes, 0 callers */

undefined ** FUN_0089c8ea(void)

{
  return &PTR_s_CMFCShadowRenderer_0099dff4;
}



