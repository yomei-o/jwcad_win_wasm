/* CSenshuDialog2 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSenshuDialog2[1] */
/* 005c4b30  FUN_005c4b30  68 bytes, 0 callers */

undefined4 FUN_005c4b30(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005c4640();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1c88);
    }
  }
  return in_ECX;
}




/* vtable slots: CSenshuDialog2[64] */
/* 005c4c50  FUN_005c4c50  1284 bytes, 0 callers */

void FUN_005c4c50(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920ed5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x47e,local_14 + 0xc0);
  FUN_0078fb9c(param_1,0x8dc,local_14 + 0x168);
  FUN_0078fb9c(param_1,0x8dd,local_14 + 0x210);
  FUN_0078fb9c(param_1,0x8de,local_14 + 0x2b8);
  FUN_0078fb9c(param_1,0x8df,local_14 + 0x360);
  FUN_0078fb9c(param_1,0x8e0,local_14 + 0x408);
  FUN_0078fb9c(param_1,0x8e1,local_14 + 0x4b0);
  FUN_0078fb9c(param_1,0x8e2,local_14 + 0x558);
  FUN_0078fb9c(param_1,0x8e3,local_14 + 0x600);
  FUN_0078fb9c(param_1,0x8e4,local_14 + 0x6a8);
  FUN_0078fb9c(param_1,0x8e5,local_14 + 0x750);
  FUN_0078fb9c(param_1,0x8e6,local_14 + 0x7f8);
  FUN_0078fb9c(param_1,0x8e7,local_14 + 0x8a0);
  FUN_0078fb9c(param_1,0x8e8,local_14 + 0x948);
  FUN_0078fb9c(param_1,0x8e9,local_14 + 0x9f0);
  FUN_0078fb9c(param_1,0x8ea,local_14 + 0xa98);
  FUN_0078fb9c(param_1,0x8eb,local_14 + 0xb40);
  FUN_0078fb9c(param_1,0x8b1,local_14 + 0xbe8);
  FUN_0078fb9c(param_1,0x8b0,local_14 + 0xc68);
  FUN_0078fb9c(param_1,0x479,local_14 + 0xce8);
  FUN_0078fb9c(param_1,0x99f,local_14 + 0xe38);
  FUN_0078fb9c(param_1,0x99e,local_14 + 0xee0);
  FUN_0078fb9c(param_1,0x99d,local_14 + 0xf88);
  FUN_0078fb9c(param_1,0x99c,local_14 + 0x1030);
  FUN_0078fb9c(param_1,0x99b,local_14 + 0x10d8);
  FUN_0078fb9c(param_1,0x99a,local_14 + 0x1180);
  FUN_0078fb9c(param_1,0x999,local_14 + 0x1228);
  FUN_0078fb9c(param_1,0x998,local_14 + 0x12d0);
  FUN_0078fb9c(param_1,0x997,local_14 + 0x1378);
  FUN_0078fb9c(param_1,0x996,local_14 + 0x1420);
  FUN_0078fb9c(param_1,0x995,local_14 + 0x14c8);
  FUN_0078fb9c(param_1,0x994,local_14 + 0x1570);
  FUN_0078fb9c(param_1,0x993,local_14 + 0x1618);
  FUN_0078fb9c(param_1,0x992,local_14 + 0x16c0);
  FUN_0078fb9c(param_1,0x991,local_14 + 0x1768);
  FUN_0078fb9c(param_1,0x582,local_14 + 0x1810);
  FUN_0078fb9c(param_1,0x9a1,local_14 + 0x18b8);
  FUN_0078fb9c(param_1,1,local_14 + 0x1960);
  FUN_0078f801(param_1,0x8b0,local_14 + 0x19e0);
  FUN_0078f6f8(param_1,0x908,local_14 + 0x19e4);
  FUN_0078f643(param_1,0x906,local_14 + 0x19e8);
  FUN_0078f643(param_1,0x907,local_14 + 0x19ec);
  if ((DAT_00a0ca90 == 0) && (DAT_00a0eef0 == 0)) {
    FUN_00797f20(0);
    FUN_00797f20(0);
  }
  else {
    FUN_00797f20(5);
    FUN_00797f20(5);
    CStringT<>();
    local_8 = 0;
    uVar2 = *(undefined4 *)(*(int *)(local_14 + 0xb0) + 0x63b4 + DAT_00a0b428 * 4);
    puVar1 = (undefined4 *)FUN_005977f0(0x2795);
    local_8._0_1_ = 1;
    FUN_004059f0(local_18,L"%s(%d)",*puVar1,uVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
    uVar2 = FUN_00404920();
    FUN_00797ece(uVar2);
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CSenshuDialog2[10] */
/* 005c5ce0  FUN_005c5ce0  16 bytes, 0 callers */

void FUN_005c5ce0(void)

{
  FUN_005c5d00();
  return;
}




/* vtable slots: CSenshuDialog2[94] */
/* 005c5ef0  FUN_005c5ef0  664 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005c5ef0(void)

{
  int iVar1;
  int local_2c;
  int local_28;
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
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_18);
  iVar1 = FUN_00517b40(DAT_00a0c0ec,DAT_00a0c0f0,local_18,local_14,local_10,local_c,&local_2c);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_2c,local_28,0,0,5);
  }
  if (0 < DAT_00a0d620) {
    FUN_004dbab0(local_2c + 0x7d,local_28 + 0xff);
  }
  for (local_1c = 0x14; local_1c < 0x2e; local_1c = local_1c + 1) {
    if (local_1c == 0x15) {
      local_1c = 0x1f;
    }
    FUN_007a5607();
  }
  for (local_1c = 10; local_1c < 0x75; local_1c = local_1c + 1) {
    if (local_1c == 0xb) {
      local_1c = 0x65;
    }
    FUN_007a5607();
  }
  local_24 = 0;
  *(undefined4 *)(local_20 + 0xb4) = 1000;
  for (local_1c = 10; local_1c < 0x75; local_1c = local_1c + 1) {
    if (local_1c == 0xb) {
      local_1c = 0x65;
    }
    if (*(int *)(*(int *)(local_20 + 0xb0) + 0x63b4 + local_1c * 4) < 1) {
      *(undefined4 *)(*(int *)(local_20 + 0xb0) + 0x63b4 + local_1c * 4) = 1;
    }
    if (*(int *)(*(int *)(local_20 + 0xb0) + 0x63b4 + local_1c * 4) < *(int *)(local_20 + 0xb4)) {
      *(undefined4 *)(local_20 + 0xb4) =
           *(undefined4 *)(*(int *)(local_20 + 0xb0) + 0x63b4 + local_1c * 4);
    }
    if (local_24 < *(int *)(*(int *)(local_20 + 0xb0) + 0x63b4 + local_1c * 4)) {
      local_24 = *(int *)(*(int *)(local_20 + 0xb0) + 0x63b4 + local_1c * 4);
    }
  }
  if (0 < *(int *)(local_20 + 0xb4)) {
    *(int *)(local_20 + 0xb4) = *(int *)(local_20 + 0xb4) + -1;
  }
  *(undefined8 *)(local_20 + 0xb8) = 0x3ff0000000000000;
  if (0xf < local_24 - *(int *)(local_20 + 0xb4)) {
    *(double *)(local_20 + 0xb8) = 15.0 / (double)(local_24 - *(int *)(local_20 + 0xb4));
  }
  FUN_005c73c0(1);
  *(undefined4 *)(local_20 + 0x19e4) = DAT_00a0eef0;
  FUN_007955d2(0);
  return 1;
}



