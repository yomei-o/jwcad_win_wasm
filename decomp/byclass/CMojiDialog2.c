/* CMojiDialog2 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMojiDialog2[1] */
/* 0057dc70  FUN_0057dc70  68 bytes, 0 callers */

undefined4 FUN_0057dc70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0057db70();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x528);
    }
  }
  return in_ECX;
}




/* vtable slots: CMojiDialog2[24] */
/* 0057ded0  FUN_0057ded0  397 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0057ded0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined1 local_4c [8];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  int *local_20;
  int local_1c;
  allocator<char> local_18 [16];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_1c = in_ECX;
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_004146a0(&DAT_00a0c0d4);
    FUN_00413f30();
    FUN_004146a0(local_18);
    puVar1 = (undefined4 *)std::allocator<char>::allocator<char>(local_18);
    uVar3 = puVar1[1];
    *(undefined4 *)(local_1c + 0x520) = *puVar1;
    *(undefined4 *)(local_1c + 0x524) = uVar3;
    puVar1 = (undefined4 *)std::allocator<char>::allocator<char>((allocator<char> *)&DAT_00a0c0d4);
    uVar3 = *puVar1;
    uVar4 = puVar1[1];
    puVar2 = local_4c;
    local_34 = uVar3;
    local_30 = uVar4;
    std::allocator<char>::allocator<char>(local_18);
    puVar1 = (undefined4 *)FID_conflict_operator_(puVar2,uVar3,uVar4);
    local_3c = *puVar1;
    local_38 = puVar1[1];
    FUN_004470a0(local_3c,local_38);
    DAT_00a0c184 = local_44;
    DAT_00a0c188 = local_40;
  }
  if (*(int *)(local_1c + 0x51c) != 0) {
    local_20 = *(int **)(local_1c + 0x51c);
    if (local_20 == (int *)0x0) {
      local_28 = 0;
    }
    else {
      local_28 = (**(code **)(*local_20 + 4))(1);
    }
    *(undefined4 *)(local_1c + 0x51c) = 0;
  }
  if (*(int *)(local_1c + 0xd8) != 0) {
    local_24 = *(int *)(local_1c + 0xd8);
    if (local_24 == 0) {
      local_2c = 0;
    }
    else {
      local_2c = FUN_0057dcc0(1);
    }
    *(undefined4 *)(local_1c + 0xd8) = 0;
    *(undefined4 *)(local_1c + 0xe0) = 0xffffffff;
    *(undefined4 *)(local_1c + 0xdc) = 0xffffffff;
    *(undefined4 *)(local_1c + 0xe8) = 0;
    *(undefined4 *)(local_1c + 0xe4) = 0;
  }
  FUN_00792313();
  return;
}




/* vtable slots: CMojiDialog2[64] */
/* 0057e060  DoDataExchange  262 bytes, 0 callers */

/* Library Function - Single Match
    protected: virtual void __thiscall CMFCToolBarsToolsPropertyPage::DoDataExchange(class
   CDataExchange *)
   
   Library: Visual Studio 2010 Debug */

void __thiscall
CMFCToolBarsToolsPropertyPage::DoDataExchange
          (CMFCToolBarsToolsPropertyPage *this,CDataExchange *param_1)

{
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x8d6,this + 0xf0);
  FUN_0078fb9c(param_1,0x8d9,this + 0x170);
  FUN_0078fb9c(param_1,0x8d8,this + 0x1f0);
  FUN_0078fb9c(param_1,0x8d5,this + 0x270);
  FUN_0078fb9c(param_1,0x8d7,this + 0x2f0);
  FUN_0078fb9c(param_1,0x58f,this + 0x370);
  FUN_0078fb9c(param_1,0x58e,this + 0x410);
  FUN_0078f643(param_1,0x58e,this + 0x490);
  FUN_0078fb9c(param_1,0x53e,this + 0x498);
  FUN_0078f6f8(param_1,0x53e,this + 0x518);
  return;
}




/* vtable slots: CMojiDialog2[10] */
/* 0057e1a0  FUN_0057e1a0  16 bytes, 0 callers */

void FUN_0057e1a0(void)

{
  FUN_0057e1b0();
  return;
}




/* vtable slots: CMojiDialog2[94] */
/* 0057e840  FUN_0057e840  1793 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0057e840(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  LPCWSTR pszFaceName;
  int in_ECX;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 local_58;
  undefined4 local_50;
  int local_44;
  int local_40;
  int local_3c;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092e37f;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00798993(uVar1);
  FUN_004146a0(&local_24);
  FUN_00416570(&local_34);
  iVar2 = (local_1c - local_24) - (local_2c - local_34);
  iVar7 = (local_18 - local_20) - (local_28 - local_30);
  if (*(int *)(in_ECX + 0xc0) != 0) {
    if (*(int *)(in_ECX + 0xb8) < 1) {
      local_40 = -*(int *)(in_ECX + 0xb8);
    }
    else {
      local_40 = *(int *)(in_ECX + 0xb8);
    }
    local_3c = (local_40 + -0xdf) - iVar2;
    if (*(int *)(in_ECX + 0xbc) == 0) {
      if (*(int *)(in_ECX + 0xc0) == 2) {
        local_3c = local_3c + 0x7b;
      }
      else if (*(int *)(in_ECX + 0xc0) == 3) {
        local_3c = local_3c + 0x5a;
      }
      else if (*(int *)(in_ECX + 0xc0) == 4) {
        local_3c = local_3c + 0xd5;
      }
    }
    else {
      local_3c = local_3c + 0x5a;
    }
    if (*(int *)(in_ECX + 0xc4) != 0) {
      if (*(int *)(in_ECX + 0xb8) < 1) {
        local_44 = -*(int *)(in_ECX + 0xb8);
      }
      else {
        local_44 = *(int *)(in_ECX + 0xb8);
      }
      local_3c = (local_44 + -0xd9) - iVar2;
    }
    uVar8 = 1;
    uVar3 = FUN_004f74b0(0xf4);
    uVar4 = FUN_004f72f0(local_3c);
    FUN_00797ce1(3,1,uVar4,uVar3,uVar8);
    if (*(int *)(in_ECX + 0xbc) == 0) {
      if (*(int *)(in_ECX + 0xc0) == 1) {
        FUN_00797f20(5);
        uVar9 = 1;
        uVar3 = FUN_004f74b0(0xf4);
        uVar4 = FUN_004f72f0(0x78);
        uVar8 = FUN_004f74b0(3);
        uVar5 = FUN_004f72f0(local_3c + 10);
        FUN_00797ce1(uVar5,uVar8,uVar4,uVar3,uVar9);
        FUN_00797f20(5);
        uVar9 = 1;
        uVar3 = FUN_004f74b0(0x14);
        uVar4 = FUN_004f72f0(0x5a);
        uVar8 = FUN_004f74b0(3);
        uVar5 = FUN_004f72f0(local_3c + 0x87);
        FUN_00797ce1(uVar5,uVar8,uVar4,uVar3,uVar9);
      }
      else if (*(int *)(in_ECX + 0xc0) == 2) {
        FUN_00797f20(0);
        FUN_00797f20(5);
        uVar9 = 1;
        uVar3 = FUN_004f74b0(0x14);
        uVar4 = FUN_004f72f0(0x5a);
        uVar8 = FUN_004f74b0(3);
        uVar5 = FUN_004f72f0(local_3c + 10);
        FUN_00797ce1(uVar5,uVar8,uVar4,uVar3,uVar9);
      }
      else if (*(int *)(in_ECX + 0xc0) == 3) {
        FUN_00797f20(5);
        uVar9 = 1;
        uVar3 = FUN_004f74b0(0xf4);
        uVar4 = FUN_004f72f0(0x78);
        uVar8 = FUN_004f74b0(3);
        uVar5 = FUN_004f72f0(local_3c + 10);
        FUN_00797ce1(uVar5,uVar8,uVar4,uVar3,uVar9);
        FUN_00797f20(0);
      }
      else {
        FUN_00797f20(0);
        FUN_00797f20(0);
      }
    }
    else {
      FUN_00797f20(5);
      uVar9 = 1;
      uVar3 = FUN_004f74b0(0xf4);
      uVar4 = FUN_004f72f0(0x78);
      uVar8 = FUN_004f74b0(3);
      uVar5 = FUN_004f72f0(local_3c + 10);
      FUN_00797ce1(uVar5,uVar8,uVar4,uVar3,uVar9);
      FUN_00797f20(0);
    }
    if (*(int *)(in_ECX + 0xc4) == 0) {
      FUN_00797f20(0);
      FUN_00797f20(0);
      FUN_00797f20(0);
      FUN_00797f20(0);
    }
    else {
      FUN_00797f20(0);
      FUN_00797f20(0);
      uVar9 = 1;
      uVar3 = FUN_004f74b0(0x18);
      uVar4 = FUN_004f72f0(0x1c);
      uVar5 = 2;
      uVar8 = FUN_004f72f0(local_3c + 7);
      FUN_00797ce1(uVar8,uVar5,uVar4,uVar3,uVar9);
      uVar9 = 1;
      uVar3 = FUN_004f74b0(0x18);
      uVar4 = FUN_004f72f0(0x1c);
      uVar5 = 2;
      uVar8 = FUN_004f72f0(local_3c + 0x23);
      FUN_00797ce1(uVar8,uVar5,uVar4,uVar3,uVar9);
      uVar9 = 1;
      uVar3 = FUN_004f74b0(0x18);
      uVar4 = FUN_004f72f0(0x1c);
      uVar5 = 2;
      uVar8 = FUN_004f72f0(local_3c + 0x3f);
      FUN_00797ce1(uVar8,uVar5,uVar4,uVar3,uVar9);
      uVar9 = 1;
      uVar3 = FUN_004f74b0(0x18);
      uVar4 = FUN_004f72f0(0x1c);
      uVar5 = 2;
      uVar8 = FUN_004f72f0(local_3c + 0x5b);
      FUN_00797ce1(uVar8,uVar5,uVar4,uVar3,uVar9);
      uVar9 = 1;
      uVar3 = FUN_004f74b0(0x18);
      uVar4 = FUN_004f72f0(0x55);
      uVar5 = 2;
      uVar8 = FUN_004f72f0(local_3c + 0x7f);
      FUN_00797ce1(uVar8,uVar5,uVar4,uVar3,uVar9);
      FUN_00797f20(5);
      FUN_00797f20(5);
      FUN_00797f20(5);
      FUN_00797f20(5);
      FUN_00797f20(5);
      if (*(int *)(in_ECX + 0xd8) == 0) {
        iVar2 = FUN_0078e624(0x35b8c);
        if (iVar2 == 0) {
          local_50 = 0;
        }
        else {
          local_50 = FUN_0057db10();
        }
        *(undefined4 *)(in_ECX + 0xd8) = local_50;
        FUN_0057f280();
      }
    }
  }
  iVar2 = FUN_004f74b0(0x12);
  iVar6 = FUN_004121b0(8);
  local_8 = 0;
  if (iVar6 == 0) {
    local_58 = 0;
  }
  else {
    local_58 = FUN_00480c40(uVar1,iVar7);
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x51c) = local_58;
  pszFaceName = (LPCWSTR)FUN_00404920();
  FID_conflict_CreateFontW(iVar2,0,0,0,400,0,0,0,0x80,4,0x20,0,5,pszFaceName);
  FUN_00406bf0(*(undefined4 *)(in_ECX + 0x51c),1);
  ExceptionList = local_10;
  return 1;
}




/* vtable slots: CMojiDialog2[67] */
/* 0057f630  FUN_0057f630  485 bytes, 0 callers */

undefined4 FUN_0057f630(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int iStack_1c;
  undefined1 *local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((*(int *)(param_1 + 4) == 0x20a) || (*(int *)(param_1 + 4) == 0xce11)) {
    if (DAT_00a0d8a0 < 1) {
      local_c = -DAT_00a0d8a0;
    }
    else {
      local_c = DAT_00a0d8a0;
    }
    if (local_c != 1) {
      if (DAT_00a0d8a0 < 1) {
        local_10 = -DAT_00a0d8a0;
      }
      else {
        local_10 = DAT_00a0d8a0;
      }
      if (local_10 != 3) goto LAB_0057f6d9;
    }
    uVar1 = 1;
  }
  else {
LAB_0057f6d9:
    if (*(int *)(param_1 + 4) == 0x100) {
      if (*(int *)(param_1 + 8) == 0xd) {
        iStack_1c = 1;
        FUN_007955d2();
        FUN_00404c80();
        local_14 = FUN_00799e17();
        FUN_00406bc0(0x1500,0,0);
        if (DAT_00a0cc64 == 0) {
          FUN_00797df8();
        }
        FUN_00404c80();
        FUN_0056d7d0();
        return 1;
      }
      local_8 = in_ECX;
      if ((*(int *)(param_1 + 8) == 0x25) || (*(int *)(param_1 + 8) == 0x27)) {
        iStack_1c = 0x57f760;
        FUN_00404c80();
        iStack_1c = 0x57f767;
        FUN_0056d7d0();
      }
      if ((*(int *)(param_1 + 8) == 0x26) || (*(int *)(param_1 + 8) == 0x28)) {
        local_18 = (undefined1 *)&iStack_1c;
        iStack_1c = param_1;
        FUN_00403dd0(local_8 + 0x490);
        FUN_0057dd00();
      }
    }
    if (*(int *)(param_1 + 4) == 0x101) {
      if (*(int *)(param_1 + 8) == 0x10) {
        DAT_00a0cc6c = 0;
      }
      if (*(int *)(param_1 + 8) == 0x11) {
        DAT_00a0cc74 = 0;
      }
      if ((*(int *)(param_1 + 8) == 0x25) || (*(int *)(param_1 + 8) == 0x27)) {
        iStack_1c = 0x57f7de;
        FUN_00404c80();
        iStack_1c = 0x57f7e5;
        FUN_0056d7d0();
      }
      if ((*(int *)(param_1 + 8) == 0x26) || (*(int *)(param_1 + 8) == 0x28)) {
        iStack_1c = 0x57f7fc;
        FUN_00404c80();
        iStack_1c = 0x57f803;
        FUN_0056d7d0();
      }
    }
    iStack_1c = param_1;
    uVar1 = FUN_0058d4f0();
  }
  return uVar1;
}



