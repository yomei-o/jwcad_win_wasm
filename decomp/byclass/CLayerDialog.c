/* CLayerDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CLayerDialog[1] */
/* 0055f520  FUN_0055f520  68 bytes, 0 callers */

undefined4 FUN_0055f520(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0055f290();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x19b0);
    }
  }
  return in_ECX;
}




/* vtable slots: CLayerDialog[24] */
/* 0055f570  FUN_0055f570  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0055f570(void)

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
    FUN_00517510(&DAT_00a0c10c,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CLayerDialog[64] */
/* 0055f5f0  FUN_0055f5f0  1137 bytes, 0 callers */

void FUN_0055f5f0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x478,in_ECX + 0x148);
  FUN_0078fb9c(param_1,0x43f,in_ECX + 0x2c8);
  FUN_0078fb9c(param_1,0x72e,in_ECX + 0x1c8);
  FUN_0078fb9c(param_1,0x72f,in_ECX + 0x248);
  FUN_0078fb9c(param_1,0x6ed,in_ECX + 0x380);
  FUN_0078fb9c(param_1,0x475,in_ECX + 0x400);
  FUN_0078fb9c(param_1,0x427,in_ECX + 0x498);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x550);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x608);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x6c0);
  FUN_0078fb9c(param_1,0x42b,in_ECX + 0x778);
  FUN_0078fb9c(param_1,0x42c,in_ECX + 0x830);
  FUN_0078fb9c(param_1,0x42d,in_ECX + 0x8e8);
  FUN_0078fb9c(param_1,0x42e,in_ECX + 0x9a0);
  FUN_0078fb9c(param_1,0x42f,in_ECX + 0xa58);
  FUN_0078fb9c(param_1,0x430,in_ECX + 0xb10);
  FUN_0078fb9c(param_1,0x45b,in_ECX + 0xbc8);
  FUN_0078fb9c(param_1,0x45c,in_ECX + 0xc80);
  FUN_0078fb9c(param_1,0x45d,in_ECX + 0xd38);
  FUN_0078fb9c(param_1,0x45e,in_ECX + 0xdf0);
  FUN_0078fb9c(param_1,0x45f,in_ECX + 0xea8);
  FUN_0078fb9c(param_1,0x476,in_ECX + 0xf60);
  FUN_0078fb9c(param_1,0x7b7,in_ECX + 0x1018);
  FUN_0078fb9c(param_1,0x7b8,in_ECX + 0x1098);
  FUN_0078fb9c(param_1,0x7b9,in_ECX + 0x1118);
  FUN_0078fb9c(param_1,0x7ba,in_ECX + 0x1198);
  FUN_0078fb9c(param_1,0x7bb,in_ECX + 0x1218);
  FUN_0078fb9c(param_1,0x7bc,in_ECX + 0x1298);
  FUN_0078fb9c(param_1,0x7bd,in_ECX + 0x1318);
  FUN_0078fb9c(param_1,0x7be,in_ECX + 0x1398);
  FUN_0078fb9c(param_1,0x7bf,in_ECX + 0x1418);
  FUN_0078fb9c(param_1,0x7c0,in_ECX + 0x1498);
  FUN_0078fb9c(param_1,0x7c1,in_ECX + 0x1518);
  FUN_0078fb9c(param_1,0x7c2,in_ECX + 0x1598);
  FUN_0078fb9c(param_1,0x7c3,in_ECX + 0x1618);
  FUN_0078fb9c(param_1,0x7c4,in_ECX + 0x1698);
  FUN_0078fb9c(param_1,0x7c5,in_ECX + 0x1718);
  FUN_0078fb9c(param_1,0x7c6,in_ECX + 0x1798);
  FUN_0078fb9c(param_1,2000,in_ECX + 0x1818);
  FUN_0078fb9c(param_1,0x431,in_ECX + 0x1898);
  FUN_0078fb9c(param_1,0x7d1,in_ECX + 0x1918);
  FUN_0078f6f8(param_1,0x5f4,in_ECX + 0x1998);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x199c);
  FUN_0078f643(param_1,0x72e,in_ECX + 0x19a0);
  FUN_0078f500(param_1,in_ECX + 0x19a0,0xfa);
  FUN_0078f643(param_1,0x72f,in_ECX + 0x19a4);
  FUN_0078f500(param_1,in_ECX + 0x19a4,0xfa);
  return;
}




/* vtable slots: CLayerDialog[10] */
/* 0055faa0  FUN_0055faa0  16 bytes, 0 callers */

void FUN_0055faa0(void)

{
  FUN_0055fab0();
  return;
}




/* vtable slots: CLayerDialog[94] */
/* 00560230  FUN_00560230  2771 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00560230(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined1 local_5c [16];
  undefined4 local_4c;
  int local_48;
  int local_44;
  undefined4 local_40 [3];
  undefined *local_34;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00798993();
  local_24 = *(int *)(*(int *)(local_1c + 0x19a8) + 0x24e4);
  *(undefined4 *)(local_1c + 0xac) = *(undefined4 *)(*(int *)(local_1c + 0x19a8) + 0x24e4);
  FUN_005622a0();
  for (local_20 = 0; local_20 < 0x10; local_20 = local_20 + 1) {
    *(int *)(*(int *)(local_1c + 0xbc + local_20 * 4) + 0xb4) = local_20;
    FUN_00557ba0(*(undefined4 *)
                  (*(int *)(local_1c + 0x19a8) + 0x17a4 + local_24 * 0x40 + local_20 * 4));
    FUN_00557960();
    iVar1 = (**(code **)(**(int **)(local_1c + 0x19a8) + 0x10))(local_24,local_20);
    if (iVar1 != 0) {
      FUN_005579c0();
    }
    iVar1 = (**(code **)(**(int **)(local_1c + 0x19a8) + 0x14))(local_24,local_20);
    if (iVar1 != 0) {
      FUN_005579a0();
    }
    FUN_00551e00();
    FUN_00557980(*(undefined4 *)
                  (*(int *)(local_1c + 0x19a8) + 0x25f4 + local_24 * 0x40 + local_20 * 4));
  }
  FUN_00557980(*(undefined4 *)(*(int *)(local_1c + 0x19a8) + 0x29f4 + local_24 * 4));
  *(undefined4 *)(*(int *)(local_1c + 0xfc) + 0xb4) = 0x10;
  FUN_00557ba0(3);
  FUN_00557960();
  iVar1 = (**(code **)(**(int **)(local_1c + 0x19a8) + 8))(local_24);
  if (iVar1 != 0) {
    FUN_005579c0();
  }
  iVar1 = (**(code **)(**(int **)(local_1c + 0x19a8) + 0xc))(local_24);
  if (iVar1 != 0) {
    FUN_005579a0();
  }
  FUN_00551e00();
  local_40[0] = 1;
  local_34 = &DAT_0095f180;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x29f4) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x29f4) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(0,local_40);
  local_34 = &DAT_0095bcec;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x29f8) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x29f8) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(1,local_40);
  local_34 = &DAT_0095bcf0;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x29fc) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x29fc) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(2,local_40);
  local_34 = &DAT_0095bd18;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a00) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a00) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(3,local_40);
  local_34 = &DAT_0095bd1c;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a04) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a04) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(4,local_40);
  local_34 = &DAT_0095bd20;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a08) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a08) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(5,local_40);
  local_34 = &DAT_0095bd24;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a0c) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a0c) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(6,local_40);
  local_34 = &DAT_0095bd28;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a10) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a10) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(7,local_40);
  local_34 = &DAT_0095bd2c;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a14) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a14) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(8,local_40);
  local_34 = &DAT_0095bd30;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a18) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a18) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(9,local_40);
  local_34 = &DAT_0095c6a4;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a1c) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a1c) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(10,local_40);
  local_34 = &DAT_00955190;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a20) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a20) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(0xb,local_40);
  local_34 = &DAT_0095c6a8;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a24) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a24) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(0xc,local_40);
  local_34 = &DAT_0095518c;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a28) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a28) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(0xd,local_40);
  local_34 = &DAT_0095bd50;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a2c) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a2c) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(0xe,local_40);
  local_34 = &DAT_0095bd40;
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a30) == 1) {
    local_34 = &DAT_009679d8;
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x2a30) == 2) {
    local_34 = &DAT_00969d00;
  }
  FUN_0055fe40(0xf,local_40);
  uVar2 = FUN_004f74b0(0x10);
  uVar3 = FUN_004f72f0(0x20);
  puVar4 = (undefined4 *)FUN_0041c8d0(uVar3,uVar2);
  FUN_00562040(local_5c,*puVar4,puVar4[1]);
  FUN_00562010(local_24);
  FUN_005621b0();
  if (DAT_00a0cbd8 != 0) {
    FUN_00406bf0(DAT_00a0cbd8,1);
    FUN_00406bf0(DAT_00a0cbd8,1);
  }
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_4c = *(undefined4 *)(*(int *)(local_1c + 0x19a8) + 0x2464 + local_24 * 4);
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  FUN_007955d2(1);
  if (*(int *)(local_1c + 0xb0) != 0) {
    FUN_00797f20(0);
    FUN_00797f20(0);
  }
  if (*(int *)(*(int *)(local_1c + 0x19a8) + 0x17a0) == 0) {
    FUN_007979e8(0);
  }
  else {
    FUN_007979e8(1);
  }
  *(undefined4 *)(local_1c + 0x1998) = 0;
  if (DAT_00a0c7dc != 0) {
    *(undefined4 *)(local_1c + 0x1998) = 1;
  }
  *(undefined4 *)(local_1c + 0x199c) = 0;
  if (DAT_00a0ef58 != 0) {
    *(undefined4 *)(local_1c + 0x199c) = 1;
  }
  FUN_007955d2(0);
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_18);
  iVar1 = FUN_00517b40(DAT_00a0c10c,DAT_00a0c110,local_18,local_14,local_10,local_c,&local_48);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_48,local_44,0,0,5);
  }
  if (0 < DAT_00a0d620) {
    iVar1 = FUN_004f74b0(0x172);
    iVar1 = iVar1 + local_44;
    iVar5 = FUN_004f72f0(0x8c);
    FUN_004dbab0(iVar5 + local_48,iVar1);
  }
  return 1;
}




/* vtable slots: CLayerDialog[96] */
/* 005610e0  FUN_005610e0  83 bytes, 0 callers */

void FUN_005610e0(void)

{
  int in_ECX;
  
  FUN_00798a09();
  DAT_00a0c7dc = (uint)(*(int *)(in_ECX + 0x1998) != 0);
  DAT_00a0ef58 = (uint)(*(int *)(in_ECX + 0x199c) != 0);
  return;
}



