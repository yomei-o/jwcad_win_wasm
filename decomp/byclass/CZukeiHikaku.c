/* CZukeiHikaku -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiHikaku[1] */
/* 0067c3c0  FUN_0067c3c0  68 bytes, 0 callers */

undefined4 FUN_0067c3c0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0067c3a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xd0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiHikaku[6] */
/* 0067c780  FUN_0067c780  625 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x0067c823) */

void FUN_0067c780(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined2 local_33c [404];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a6b6;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8ebc) = 0;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8._0_1_ = 1;
  FUN_0040c0e0();
  local_33c[0] = 0;
  if ((*(int *)(in_ECX + 0xb0) < 1) && (*(int *)(in_ECX + 0xb4) < 1)) {
    if (*(int *)(in_ECX + 0xb8) != 0) {
      FUN_005977f0(0x1634);
      uVar1 = FUN_00404920();
      FUN_0053e560(local_33c,uVar1);
      FUN_00404770();
    }
    FUN_004efbb0(0x151b,local_33c,0);
  }
  else {
    uVar1 = *(undefined4 *)(in_ECX + 0xac);
    uVar3 = *(undefined4 *)(in_ECX + 0xb4);
    FUN_005977f0(0x1632);
    local_8._0_1_ = 2;
    uVar2 = FUN_00404920(uVar3,uVar1);
    uVar1 = *(undefined4 *)(in_ECX + 0xa8);
    uVar3 = *(undefined4 *)(in_ECX + 0xb0);
    FUN_005977f0(0x1631);
    uVar1 = FUN_00404920(uVar3,uVar1,uVar2);
    FUN_0053e560(local_33c,L"  ( %s %ld/%ld   %s %ld/%ld )",uVar1);
    FUN_00404770();
    local_8._0_1_ = 1;
    FUN_00404770();
    if (*(int *)(in_ECX + 0xb4) < 1) {
      FUN_004efbb0(0x14b4,local_33c,0);
    }
    else {
      FUN_004efbb0(0x17fa,local_33c,0);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikaku[16] */
/* 0067ca00  FUN_0067ca00  551 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0067ca00(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined1 local_6418 [20];
  undefined4 local_6404;
  int local_6400;
  int local_63fc;
  int local_63f8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092cf8b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0xb4) < 1) {
    local_6404 = 0;
  }
  else {
    local_63f8 = in_ECX;
    FUN_00446aa0(local_14);
    local_8 = 0;
    FUN_0079dea2();
    local_8._0_1_ = 1;
    FUN_0044de00(local_6418,*(undefined4 *)(local_63f8 + 4));
    FUN_0044c990(*(undefined4 *)(local_63f8 + 4),local_6418);
    FUN_00449d60();
    local_63fc = *(int *)(local_63f8 + 4);
    if (local_63fc == 0) {
      local_6400 = 0;
    }
    else {
      local_6400 = local_63fc + 0x88;
    }
    FUN_00454890();
    FUN_0044dd20(local_6418,*(undefined4 *)(local_63f8 + 4));
    puVar1 = (undefined4 *)FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
    FUN_00517640(*puVar1,puVar1[1],puVar1[2],puVar1[3]);
    *(undefined4 *)(local_63f8 + 0xac) = 0;
    *(undefined4 *)(local_63f8 + 0xa8) = 0;
    *(undefined4 *)(local_63f8 + 0xb4) = 0;
    *(undefined4 *)(local_63f8 + 0xb0) = 0;
    *(undefined4 *)(local_63f8 + 0xb8) = 0;
    FUN_0067c410();
    local_6404 = 1;
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_0079dfff();
    local_8 = 0xffffffff;
    FUN_00447100();
  }
  ExceptionList = local_10;
  return local_6404;
}




/* vtable slots: CZukeiHikaku[0] */
/* 0067cc30  FUN_0067cc30  16 bytes, 0 callers */

undefined ** FUN_0067cc30(void)

{
  return &PTR_s_CZukeiHikaku_00978aa4;
}




/* vtable slots: CZukeiHikaku[46], CZukeiTenkuu[46] */
/* 0067cc60  FUN_0067cc60  120 bytes, 0 callers */

void FUN_0067cc60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  if (DAT_00a0c7c0 == 0) {
    FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  else {
    FUN_0076c9c0(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  }
  return;
}




/* vtable slots: CZukeiHikaku[25] */
/* 0067cce0  FUN_0067cce0  203 bytes, 0 callers */

void FUN_0067cce0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_1c [4];
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a6f5;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_14 + 4) + 0x8618)) {
    FUN_00403dd0(&DAT_00a0b378);
    local_8 = 0;
    FUN_00403dd0(&DAT_00a0b37c);
    local_8._0_1_ = 1;
    uVar3 = FUN_0040c0e0();
    FUN_0067cc40(uVar1,uVar3);
    FUN_00404860(local_1c);
    FUN_00404860(local_18);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404540();
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikaku[26] */
/* 0067cdb0  FUN_0067cdb0  293 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067cdb0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929a10;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8618)) {
    *(undefined4 *)(in_ECX + 0xac) = 0;
    *(undefined4 *)(in_ECX + 0xa8) = 0;
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    *(undefined4 *)(in_ECX + 0xb0) = 0;
    *(undefined4 *)(in_ECX + 0xb8) = 0;
    FUN_005b0590(*(undefined4 *)(in_ECX + 4),100,0);
    local_8 = 0;
    FUN_005b0bf0();
    FUN_00404c80(uVar1);
    FUN_0056d7d0();
    DAT_00a0cc74 = 0;
    DAT_00a0cc6c = 0;
    local_8 = 0xffffffff;
    FUN_005b08d0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikaku[27] */
/* 0067cee0  FUN_0067cee0  293 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067cee0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929a10;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(uVar1);
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(in_ECX + 4) + 0x8618)) {
    *(undefined4 *)(in_ECX + 0xac) = 0;
    *(undefined4 *)(in_ECX + 0xa8) = 0;
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    *(undefined4 *)(in_ECX + 0xb0) = 0;
    *(undefined4 *)(in_ECX + 0xb8) = 0;
    FUN_005b0590(*(undefined4 *)(in_ECX + 4),0x6e,0);
    local_8 = 0;
    FUN_005b0bf0();
    FUN_00404c80(uVar1);
    FUN_0056d7d0();
    DAT_00a0cc74 = 0;
    DAT_00a0cc6c = 0;
    local_8 = 0xffffffff;
    FUN_005b08d0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikaku[28] */
/* 0067d010  FUN_0067d010  382 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067d010(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929a10;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(uVar2);
  iVar3 = FUN_004fca20();
  if (*(int *)(iVar3 + 0x1a0) == *(int *)(in_ECX[1] + 0x8618)) {
    FUN_00404c80(uVar2);
    iVar3 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar3 + 0x1a0) + 300) == 0) {
      in_ECX[0x2b] = 0;
      in_ECX[0x2a] = 0;
      in_ECX[0x2d] = 0;
      in_ECX[0x2c] = 0;
      in_ECX[0x2e] = 0;
      FUN_005b0590(in_ECX[1],0x46,0);
      local_8 = 0;
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      uVar1 = *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xd4);
      FUN_005b0bf0();
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xd4) = uVar1;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = 0xffffffff;
      FUN_005b08d0();
    }
    else {
      (**(code **)(*in_ECX + 0x68))();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikaku[29] */
/* 0067d190  FUN_0067d190  382 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067d190(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929a10;
  local_10 = ExceptionList;
  uVar2 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80(uVar2);
  iVar3 = FUN_004fca20();
  if (*(int *)(iVar3 + 0x1a0) == *(int *)(in_ECX[1] + 0x8618)) {
    FUN_00404c80(uVar2);
    iVar3 = FUN_004fca20();
    if (*(int *)(*(int *)(iVar3 + 0x1a0) + 0x134) == 0) {
      in_ECX[0x2b] = 0;
      in_ECX[0x2a] = 0;
      in_ECX[0x2d] = 0;
      in_ECX[0x2c] = 0;
      in_ECX[0x2e] = 0;
      FUN_005b0590(in_ECX[1],0x50,0);
      local_8 = 0;
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      uVar1 = *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xd8);
      FUN_005b0bf0();
      FUN_00404c80();
      iVar3 = FUN_004fca20();
      *(undefined4 *)(*(int *)(iVar3 + 0x1a0) + 0xd8) = uVar1;
      FUN_00404c80();
      FUN_0056d7d0();
      local_8 = 0xffffffff;
      FUN_005b08d0();
    }
    else {
      (**(code **)(*in_ECX + 0x6c))();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikaku[30] */
/* 0067d310  FUN_0067d310  2187 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067d310(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_dccc [20];
  undefined4 local_dcb8;
  undefined4 local_dcb4;
  undefined1 *local_dcb0;
  undefined4 local_dcac;
  undefined1 *local_dca8;
  undefined4 local_dca4;
  undefined1 *local_dca0;
  undefined4 local_dc9c;
  undefined1 *local_dc98;
  undefined4 local_dc94;
  undefined4 local_dc90;
  undefined4 local_dc8c;
  undefined1 local_dc88 [24];
  undefined4 local_dc70;
  int local_dc6c;
  int local_dc68;
  undefined1 local_dc64 [4];
  int *local_dc60;
  int local_dc58;
  int local_dc54;
  undefined1 local_dc50 [4];
  undefined1 local_dc4c [4];
  undefined1 local_dc48 [4];
  undefined1 local_dc44 [4];
  undefined1 local_dc40 [6];
  CWaitCursor local_dc3a;
  CWaitCursor local_dc39;
  int local_dc38;
  int local_13e0;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a7e0;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00404c80();
  iVar2 = FUN_004fca20();
  if (*(int *)(iVar2 + 0x1a0) == *(int *)(*(int *)(local_dc38 + 4) + 0x8618)) {
    *(undefined4 *)(local_dc38 + 0xac) = 0;
    *(undefined4 *)(local_dc38 + 0xa8) = 0;
    *(undefined4 *)(local_dc38 + 0xb4) = 0;
    *(undefined4 *)(local_dc38 + 0xb0) = 0;
    *(undefined4 *)(local_dc38 + 0xb8) = 0;
    FUN_00446aa0();
    local_8 = 0;
    FUN_0079dea2();
    local_8._0_1_ = 1;
    FUN_0044de00(local_dc88);
    FUN_0044c990(*(undefined4 *)(local_dc38 + 4));
    FUN_00449d60();
    local_dc54 = *(int *)(local_dc38 + 4);
    if (local_dc54 == 0) {
      local_dc58 = 0;
    }
    else {
      local_dc58 = local_dc54 + 0x88;
    }
    FUN_00454890();
    FUN_0044dd20(local_dc88);
    puVar3 = (undefined4 *)FUN_00408a30(0x54b075823b6c498a,0x54b075823b6c498a);
    FUN_00517640(*puVar3,puVar3[1],puVar3[2]);
    FUN_0040c0e0();
    FUN_0044f310();
    FUN_00403dd0();
    local_8._0_1_ = 2;
    local_dc98 = &stack0xffff22d0;
    FUN_00403dd0(local_dc44);
    local_dc9c = FUN_0044f150(local_dc50);
    local_8._0_1_ = 3;
    local_dca0 = &stack0xffff22d0;
    FUN_00403dd0(local_dc44);
    local_dca4 = FUN_0044ef10(local_dc4c);
    local_8._0_1_ = 4;
    cVar1 = FUN_00447350(&DAT_00956338);
    if ((cVar1 == '\0') && (cVar1 = FUN_00447350(L".DXF"), cVar1 == '\0')) {
      FUN_004fb910();
      local_dc68 = 0;
      FUN_005b0590();
      local_8._0_1_ = 5;
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      local_13e0 = *(int *)(*(int *)(iVar2 + 0x1a0) + 0xdc);
      if (local_13e0 == 2) {
        local_13e0 = 0;
      }
      if (local_13e0 == 3) {
        local_13e0 = 0;
      }
      if (local_13e0 == 4) {
        local_13e0 = 0;
      }
      local_dc6c = FUN_005b0bf0();
      FUN_00404c80();
      iVar2 = FUN_004fca20();
      *(int *)(*(int *)(iVar2 + 0x1a0) + 0xdc) = local_13e0;
      if (local_dc6c == 1) {
        FUN_0067c410();
        FUN_00403dd0();
        local_8._0_1_ = 6;
        local_dca8 = &stack0xffff22d0;
        FUN_00403dd0(local_dc48);
        local_dcac = FUN_0044f150(local_dc64);
        local_8._0_1_ = 7;
        local_dcb0 = &stack0xffff22d0;
        FUN_00403dd0(local_dc48);
        local_dcb4 = FUN_0044ef10(local_dc40);
        local_8._0_1_ = 8;
        cVar1 = FUN_004640c0(L".JWW");
        if ((((cVar1 != '\0') && (cVar1 = FUN_004640c0(L".jww"), cVar1 != '\0')) &&
            (cVar1 = FUN_004640c0(L".JWC"), cVar1 != '\0')) &&
           (cVar1 = FUN_004640c0(L".jwc"), cVar1 != '\0')) {
          local_dc90 = FUN_005977f0();
          local_8._0_1_ = 9;
          local_dc8c = local_dc90;
          FUN_00403dd0();
          local_8._0_1_ = 0xb;
          FUN_00404770();
          FUN_00404920(0);
          FUN_004f6110();
          local_8._0_1_ = 8;
          FUN_00404540();
          local_8._0_1_ = 7;
          FUN_00404540();
          local_8._0_1_ = 6;
          FUN_00404540();
          local_8._0_1_ = 5;
          FUN_00404540();
          local_8._0_1_ = 4;
          FUN_005b08d0();
          local_8._0_1_ = 3;
          FUN_00404540();
          local_8._0_1_ = 2;
          FUN_00404540();
          local_8._0_1_ = 1;
          FUN_00404540();
          local_8 = (uint)local_8._1_3_ << 8;
          FUN_0079dfff();
          local_8 = 0xffffffff;
          FUN_00447100();
          ExceptionList = local_10;
          return;
        }
        FUN_004efc30();
        DAT_00a101a8 = 1;
        DAT_00a0ef7c = 1;
        FUN_007a70b2();
        local_8._0_1_ = 0xc;
        CFileException();
        local_8._0_1_ = 0xd;
        FUN_00404920(0);
        iVar2 = FUN_007a7cf7();
        if (iVar2 != 0) {
          FUN_00446aa0();
          local_8._0_1_ = 0xe;
          CWaitCursor::CWaitCursor(&local_dc3a);
          local_8._0_1_ = 0xf;
          FUN_0044e0d0();
          local_dc94 = DAT_00a0cab4;
          local_dc70 = DAT_00a0cab0;
          DAT_00a0cab4 = 0;
          DAT_00a0cab0 = 0;
          FUN_007a6256(local_dccc,1,0x1000);
          local_8._0_1_ = 0x10;
          local_dc60 = (int *)FUN_0040c0e0();
          (**(code **)(*local_dc60 + 8))();
          DAT_00a0cab4 = local_dc94;
          DAT_00a0cab0 = local_dc70;
          FUN_0044e3b0(*(undefined4 *)(local_dc38 + 4));
          local_dc68 = 1;
          local_8._0_1_ = 0xf;
          FUN_007a6389();
          local_8._0_1_ = 0xe;
          FUN_00408b00();
          local_8._0_1_ = 0xd;
          FUN_00447100();
        }
        DAT_00a0ef7c = 0;
        DAT_00a101a8 = 0;
        local_8._0_1_ = 0xc;
        FUN_004472c0();
        local_8._0_1_ = 8;
        FUN_007a70db();
        local_8._0_1_ = 7;
        FUN_00404540();
        local_8._0_1_ = 6;
        FUN_00404540();
        local_8._0_1_ = 5;
        FUN_00404540();
      }
      local_8._0_1_ = 4;
      FUN_005b08d0();
      FUN_004f0bc0();
      if (local_dc68 != 0) {
        CWaitCursor::CWaitCursor(&local_dc39);
        local_8._0_1_ = 0x11;
        (**(code **)(**(int **)(local_dc38 + 4) + 0x19c))();
        local_dcb8 = FUN_0067df60();
        local_8._0_1_ = 4;
        FUN_00408b00();
      }
      FUN_0067c410();
      local_8._0_1_ = 3;
      FUN_00404540();
      local_8._0_1_ = 2;
      FUN_00404540();
      local_8._0_1_ = 1;
      FUN_00404540();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
    else {
      local_8._0_1_ = 3;
      FUN_00404540();
      local_8._0_1_ = 2;
      FUN_00404540();
      local_8._0_1_ = 1;
      FUN_00404540();
      local_8 = (uint)local_8._1_3_ << 8;
      FUN_0079dfff();
      local_8 = 0xffffffff;
      FUN_00447100();
    }
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikaku[32] */
/* 0067dba0  FUN_0067dba0  436 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067dba0(void)

{
  int iVar1;
  undefined1 local_6404 [20];
  undefined4 local_63f0;
  int local_63ec;
  int local_63e8;
  undefined4 local_ec;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093711b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  local_63f0 = FUN_0040c0e0();
  FUN_0044dd20(local_6404,*(undefined4 *)(local_63e8 + 4));
  while( true ) {
    iVar1 = FUN_004146c0();
    if (iVar1 != 0) break;
    local_63ec = FUN_00414c00();
    *(ushort *)(local_63ec + 0x44) = *(ushort *)(local_63ec + 0x44) & 0xfffd;
    FUN_00447670(local_6404,*(undefined4 *)(local_63e8 + 4),local_63ec,1,1);
    local_ec = 1;
  }
  local_ec = 0;
  *(undefined4 *)(local_63e8 + 0xac) = 0;
  *(undefined4 *)(local_63e8 + 0xa8) = 0;
  *(undefined4 *)(local_63e8 + 0xb4) = 0;
  *(undefined4 *)(local_63e8 + 0xb0) = 0;
  *(undefined4 *)(local_63e8 + 0xb8) = 0;
  FUN_0067c410();
  FUN_00404c80();
  FUN_0056d7d0();
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikaku[4] */
/* 0067dd60  FUN_0067dd60  331 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067dd60(void)

{
  undefined1 local_6404 [20];
  int local_63f0;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093711b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00446aa0(local_14);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_63e8 + 4));
  local_8._0_1_ = 1;
  FUN_0044de00(local_6404,*(undefined4 *)(local_63e8 + 4));
  FUN_0044c830(local_6404,*(undefined4 *)(local_63e8 + 4));
  FUN_0044dd90(local_6404,*(undefined4 *)(local_63e8 + 4));
  local_63ec = *(int *)(local_63e8 + 4);
  if (local_63ec == 0) {
    local_63f0 = 0;
  }
  else {
    local_63f0 = local_63ec + 0x88;
  }
  FUN_00454890(local_63f0);
  FUN_00454830(*(undefined4 *)(local_63e8 + 4));
  local_8 = (uint)local_8._1_3_ << 8;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiHikaku[3] */
/* 0067deb0  FUN_0067deb0  166 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0067deb0(void)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093a820;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
  local_8 = 0;
  FUN_0040c0e0(uVar1);
  FUN_00446aa0();
  FUN_00447100();
  local_8 = 0xffffffff;
  FUN_0079dfff();
  ExceptionList = local_10;
  return;
}



