/* CScaleDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CScaleDialog[1] */
/* 005b97d0  FUN_005b97d0  68 bytes, 0 callers */

undefined4 FUN_005b97d0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005b96a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa68);
    }
  }
  return in_ECX;
}




/* vtable slots: CScaleDialog[24] */
/* 005b9820  FUN_005b9820  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005b9820(void)

{
  int in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_00413f30();
    FUN_004146a0(&local_18);
    FUN_00517510(&DAT_00a0c12c,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CScaleDialog[64] */
/* 005b98a0  FUN_005b98a0  719 bytes, 0 callers */

void FUN_005b98a0(CDataExchange *param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078f6f8(param_1,0x7a2,in_ECX + 0xa8);
  FUN_0078fb9c(param_1,0x5bf,in_ECX + 0xb0);
  FUN_0078fb9c(param_1,0x5be,in_ECX + 0x130);
  DDX_Text(param_1,0x5be,(double *)(in_ECX + 0x1b0));
  DDX_Text(param_1,0x5bf,(double *)(in_ECX + 0x1b8));
  FUN_0078f75d(param_1,0x6a8,in_ECX + 0x1c0);
  FUN_0078f6f8(param_1,0x7a3,in_ECX + 0x1c4);
  FUN_0078fb9c(param_1,0x7a3,in_ECX + 0x1c8);
  FUN_0078f6f8(param_1,0x9c4,in_ECX + 0x248);
  FUN_0078f6f8(param_1,0x9c5,in_ECX + 0x24c);
  FUN_0078fb9c(param_1,0x7a7,in_ECX + 0x250);
  FUN_0078fb9c(param_1,0x7a8,in_ECX + 0x2d0);
  FUN_0078fb9c(param_1,0x7a9,in_ECX + 0x350);
  FUN_0078fb9c(param_1,0x7aa,in_ECX + 0x3d0);
  FUN_0078fb9c(param_1,0x7ab,in_ECX + 0x450);
  FUN_0078fb9c(param_1,0x7ac,in_ECX + 0x4d0);
  FUN_0078fb9c(param_1,0x7ad,in_ECX + 0x550);
  FUN_0078fb9c(param_1,0x7ae,in_ECX + 0x5d0);
  FUN_0078fb9c(param_1,0x7af,in_ECX + 0x650);
  FUN_0078fb9c(param_1,0x7b0,in_ECX + 0x6d0);
  FUN_0078fb9c(param_1,0x7b1,in_ECX + 0x750);
  FUN_0078fb9c(param_1,0x7b2,in_ECX + 2000);
  FUN_0078fb9c(param_1,0x7b3,in_ECX + 0x850);
  FUN_0078fb9c(param_1,0x7b4,in_ECX + 0x8d0);
  FUN_0078fb9c(param_1,0x7b5,in_ECX + 0x950);
  FUN_0078fb9c(param_1,0x7b6,in_ECX + 0x9d0);
  FUN_0078f6f8(param_1,0x7a4,in_ECX + 0xa50);
  if (DAT_00a0cbd8 != 0) {
    FUN_00406bf0(DAT_00a0cbd8,1);
    FUN_00406bf0(DAT_00a0cbd8,1);
  }
  return;
}




/* vtable slots: CScaleDialog[10] */
/* 005b9b70  FUN_005b9b70  16 bytes, 0 callers */

void FUN_005b9b70(void)

{
  FUN_005b9b80();
  return;
}




/* vtable slots: CScaleDialog[94] */
/* 005b9b90  FUN_005b9b90  2022 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005b9b90(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_e8 [4];
  undefined4 local_e4;
  undefined4 local_e0;
  undefined1 local_dc [4];
  undefined4 local_d8;
  undefined4 local_d4;
  undefined1 local_d0 [4];
  undefined4 local_cc;
  undefined4 local_c8;
  undefined1 local_c4 [4];
  undefined4 local_c0;
  undefined4 local_bc;
  undefined1 local_b8 [4];
  undefined4 local_b4;
  undefined4 local_b0;
  undefined1 local_ac [4];
  undefined4 local_a8;
  undefined4 local_a4;
  undefined1 local_a0 [4];
  undefined4 local_9c;
  undefined4 local_98;
  undefined1 local_94 [4];
  undefined4 local_90;
  undefined4 local_8c;
  undefined1 local_88 [4];
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7c [4];
  undefined4 local_78;
  undefined4 local_74;
  undefined1 local_70 [4];
  undefined4 local_6c;
  undefined4 local_68;
  undefined1 local_64 [4];
  undefined4 local_60;
  undefined4 local_5c;
  undefined1 local_58 [4];
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c [4];
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [4];
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34 [4];
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009321f0;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
  FUN_00798993(uVar1);
  if (*(int *)(local_28 + 0x1c0) == 0) {
    FUN_007979e8(1);
  }
  else {
    FUN_007979e8(0);
  }
  local_c0 = FUN_005ba720(local_34,0);
  local_8 = 0;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_3c = FUN_005ba720(local_40,1);
  local_8 = 1;
  local_38 = local_3c;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_48 = FUN_005ba720(local_4c,2);
  local_8 = 2;
  local_44 = local_48;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_54 = FUN_005ba720(local_58,3);
  local_8 = 3;
  local_50 = local_54;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_60 = FUN_005ba720(local_64,4);
  local_8 = 4;
  local_5c = local_60;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_6c = FUN_005ba720(local_70,5);
  local_8 = 5;
  local_68 = local_6c;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_78 = FUN_005ba720(local_7c,6);
  local_8 = 6;
  local_74 = local_78;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_84 = FUN_005ba720(local_88,7);
  local_8 = 7;
  local_80 = local_84;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_90 = FUN_005ba720(local_94,8);
  local_8 = 8;
  local_8c = local_90;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_9c = FUN_005ba720(local_a0,9);
  local_8 = 9;
  local_98 = local_9c;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_a8 = FUN_005ba720(local_ac,10);
  local_8 = 10;
  local_a4 = local_a8;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_b4 = FUN_005ba720(local_b8,0xb);
  local_8 = 0xb;
  local_b0 = local_b4;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_d8 = FUN_005ba720(local_c4,0xc);
  local_8 = 0xc;
  local_bc = local_d8;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_cc = FUN_005ba720(local_d0,0xd);
  local_8 = 0xd;
  local_c8 = local_cc;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_d4 = FUN_005ba720(local_dc,0xe);
  local_8 = 0xe;
  uVar2 = FUN_00404920(uVar1,local_d4);
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  local_e4 = FUN_005ba720(local_e8,0xf);
  local_8 = 0xf;
  local_e0 = local_e4;
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  iVar3 = FUN_005ba810(0);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(1);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(2);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(3);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(4);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(5);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(6);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(7);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(8);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(9);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(10);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(0xb);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(0xc);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(0xd);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(0xe);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  iVar3 = FUN_005ba810(0xf);
  if (iVar3 != 0) {
    FUN_007979e8(0);
  }
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_24);
  iVar3 = FUN_00517b40(DAT_00a0c12c,DAT_00a0c130,local_24,local_20,local_1c,local_18,&local_30);
  if (iVar3 != 0) {
    FUN_00797e71(0,local_30,local_2c,0,0,5);
  }
  if (0 < DAT_00a0d620) {
    FUN_004dbab0(local_30 + 0x1a9,local_2c + 0x50);
  }
  FUN_00797df8();
  ExceptionList = local_10;
  return 1;
}




/* vtable slots: CScaleDialog[96] */
/* 005ba3c0  FUN_005ba3c0  852 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005ba3c0(void)

{
  double dVar1;
  double dVar2;
  bool bVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float10 fVar6;
  int local_63f8;
  int local_63f4;
  CWaitCursor local_63ed;
  int local_63ec;
  int local_63e8;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093223b;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007955d2(1,local_14);
  FUN_00446aa0();
  local_8 = 0;
  CWaitCursor::CWaitCursor(&local_63ed);
  local_8 = CONCAT31(local_8._1_3_,1);
  if (*(int *)(local_63e8 + 0xa8) == 0) {
    local_63f4 = *(int *)(local_63e8 + 0xa58);
    local_63f8 = *(int *)(local_63e8 + 0xa58);
  }
  else {
    local_63f4 = 0;
    local_63f8 = 0xf;
  }
  fVar6 = (float10)FUN_005ba880();
  uVar5 = DAT_00a0cb5c;
  uVar4 = DAT_00a0cb58;
  dVar2 = (double)fVar6;
  DAT_00a0b44c = *(undefined4 *)(local_63e8 + 0x1c0);
  DAT_00a0b45c = (uint)(*(int *)(local_63e8 + 0x1c4) != 0);
  DAT_00a0cb58 = *(undefined4 *)(local_63e8 + 0x1c4);
  DAT_00a0cb5c = *(undefined4 *)(local_63e8 + 0xa50);
  bVar3 = false;
  for (local_63ec = local_63f4; local_63ec <= local_63f8; local_63ec = local_63ec + 1) {
    if (((*(int *)(*(int *)(local_63e8 + 0xa54) + 0x2a7c + local_63ec * 4) == 0) &&
        (*(int *)(*(int *)(local_63e8 + 0xa54) + 0x242c + local_63ec * 4) != 0)) &&
       (*(int *)(*(int *)(local_63e8 + 0xa54) + 0x242c + local_63ec * 4) != 1)) {
      dVar1 = *(double *)(*(int *)(local_63e8 + 0xa54) + 0x2578 + local_63ec * 8);
      if ((*(int *)(local_63e8 + 0x1c0) == 0) && (dVar2 != dVar1)) {
        FUN_00449b30(*(undefined4 *)(local_63e8 + 0xa54),local_63ec,dVar1,dVar2);
      }
      else {
        *(double *)(*(int *)(local_63e8 + 0xa54) + 0x2578 + local_63ec * 8) = dVar2;
      }
      if (dVar2 != dVar1) {
        bVar3 = true;
      }
    }
  }
  if (bVar3) {
    FUN_00517a30();
  }
  DAT_00a0c7e4 = (uint)(*(int *)(local_63e8 + 0x248) != 0);
  DAT_00a0c7e8 = (uint)(*(int *)(local_63e8 + 0x24c) != 0);
  DAT_00a0cb58 = uVar4;
  DAT_00a0cb5c = uVar5;
  FUN_00798a09();
  local_8 = local_8 & 0xffffff00;
  FUN_00408b00();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



