/* CSuuchiHyouDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSuuchiHyouDialog[1] */
/* 005d52b0  FUN_005d52b0  68 bytes, 0 callers */

undefined4 FUN_005d52b0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005d4d80();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x3c88);
    }
  }
  return in_ECX;
}




/* vtable slots: CSuuchiHyouDialog[24] */
/* 005d6250  FUN_005d6250  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005d6250(void)

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
    FUN_00517510(&DAT_00a0c134,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CSuuchiHyouDialog[64] */
/* 005d62d0  FUN_005d62d0  2508 bytes, 0 callers */

void FUN_005d62d0(undefined4 param_1)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00920ed5;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00405880();
  FUN_0078f6f8(param_1,0x9de,in_ECX + 0x7c8);
  FUN_0078fb9c(param_1,0x9de,in_ECX + 2000);
  FUN_0078fb9c(param_1,0x81c,in_ECX + 0x850);
  FUN_0078fb9c(param_1,0x81d,in_ECX + 0x8d0);
  FUN_0078fb9c(param_1,0x81e,in_ECX + 0x950);
  FUN_0078fb9c(param_1,0x81f,in_ECX + 0x9d0);
  FUN_0078fb9c(param_1,0x6e4,in_ECX + 0xa50);
  FUN_0078fb9c(param_1,0x6e5,in_ECX + 0xad0);
  FUN_0078fb9c(param_1,0x494,in_ECX + 0xb50);
  FUN_0078fb9c(param_1,0x495,in_ECX + 0xbe8);
  FUN_0078fb9c(param_1,0x496,in_ECX + 0xc80);
  FUN_0078fb9c(param_1,0x6e7,in_ECX + 0xd18);
  FUN_0078fb9c(param_1,0x4c9,in_ECX + 0xd98);
  FUN_0078fb9c(param_1,0x6e8,in_ECX + 0xe30);
  FUN_0078fb9c(param_1,0x4ca,in_ECX + 0xeb0);
  FUN_0078fb9c(param_1,0x6e9,in_ECX + 0xf48);
  FUN_0078fb9c(param_1,0x4cb,in_ECX + 0xfc8);
  FUN_0078fb9c(param_1,0x81b,in_ECX + 0x1060);
  FUN_0078fb9c(param_1,0x6ea,in_ECX + 0x10e0);
  FUN_0078fb9c(param_1,0x6ec,in_ECX + 0x1160);
  FUN_0078fb9c(param_1,0x6eb,in_ECX + 0x11e0);
  FUN_0078fb9c(param_1,0x498,in_ECX + 0x1260);
  FUN_0078fb9c(param_1,0x4a5,in_ECX + 0x12f8);
  FUN_0078fb9c(param_1,0x4a6,in_ECX + 0x1390);
  FUN_0078fb9c(param_1,0x4a7,in_ECX + 0x1428);
  FUN_0078fb9c(param_1,0x4a8,in_ECX + 0x14c0);
  FUN_0078fb9c(param_1,0x4a9,in_ECX + 0x1558);
  FUN_0078fb9c(param_1,0x4aa,in_ECX + 0x15f0);
  FUN_0078fb9c(param_1,0x4ab,in_ECX + 0x1688);
  FUN_0078fb9c(param_1,0x4ac,in_ECX + 0x1720);
  FUN_0078fb9c(param_1,0x4ad,in_ECX + 0x17b8);
  FUN_0078fb9c(param_1,0x497,in_ECX + 0x1850);
  FUN_0078fb9c(param_1,0x49c,in_ECX + 0x18e8);
  FUN_0078fb9c(param_1,0x49d,in_ECX + 0x1980);
  FUN_0078fb9c(param_1,0x49e,in_ECX + 0x1a18);
  FUN_0078fb9c(param_1,0x49f,in_ECX + 0x1ab0);
  FUN_0078fb9c(param_1,0x4a0,in_ECX + 0x1b48);
  FUN_0078fb9c(param_1,0x4a1,in_ECX + 0x1be0);
  FUN_0078fb9c(param_1,0x4a2,in_ECX + 0x1c78);
  FUN_0078fb9c(param_1,0x4a3,in_ECX + 0x1d10);
  FUN_0078fb9c(param_1,0x4a4,in_ECX + 0x1da8);
  FUN_0078fb9c(param_1,0x480,in_ECX + 0x1e40);
  FUN_0078fb9c(param_1,0x481,in_ECX + 0x1ed8);
  FUN_0078fb9c(param_1,0x482,in_ECX + 0x1f70);
  FUN_0078fb9c(param_1,0x483,in_ECX + 0x2008);
  FUN_0078fb9c(param_1,0x484,in_ECX + 0x20a0);
  FUN_0078fb9c(param_1,0x485,in_ECX + 0x2138);
  FUN_0078fb9c(param_1,0x486,in_ECX + 0x21d0);
  FUN_0078fb9c(param_1,0x487,in_ECX + 0x2268);
  FUN_0078fb9c(param_1,0x488,in_ECX + 0x2300);
  FUN_0078fb9c(param_1,0x489,in_ECX + 0x2398);
  FUN_0078fb9c(param_1,0x48a,in_ECX + 0x2430);
  FUN_0078fb9c(param_1,0x48b,in_ECX + 0x24c8);
  FUN_0078fb9c(param_1,0x48c,in_ECX + 0x2560);
  FUN_0078fb9c(param_1,0x48d,in_ECX + 0x25f8);
  FUN_0078fb9c(param_1,0x48e,in_ECX + 0x2690);
  FUN_0078fb9c(param_1,0x48f,in_ECX + 0x2728);
  FUN_0078fb9c(param_1,0x490,in_ECX + 0x27c0);
  FUN_0078fb9c(param_1,0x491,in_ECX + 0x2858);
  FUN_0078fb9c(param_1,0x492,in_ECX + 0x28f0);
  FUN_0078fb9c(param_1,0x493,in_ECX + 0x2988);
  FUN_0078fb9c(param_1,0x499,in_ECX + 0x2a20);
  FUN_0078fb9c(param_1,0x4ae,in_ECX + 0x2ab8);
  FUN_0078fb9c(param_1,0x4af,in_ECX + 0x2b50);
  FUN_0078fb9c(param_1,0x4b0,in_ECX + 0x2be8);
  FUN_0078fb9c(param_1,0x4b1,in_ECX + 0x2c80);
  FUN_0078fb9c(param_1,0x4b2,in_ECX + 0x2d18);
  FUN_0078fb9c(param_1,0x4b3,in_ECX + 0x2db0);
  FUN_0078fb9c(param_1,0x4b4,in_ECX + 0x2e48);
  FUN_0078fb9c(param_1,0x4b5,in_ECX + 12000);
  FUN_0078fb9c(param_1,0x4b6,in_ECX + 0x2f78);
  FUN_0078fb9c(param_1,0x49a,in_ECX + 0x3010);
  FUN_0078fb9c(param_1,0x4b7,in_ECX + 0x30a8);
  FUN_0078fb9c(param_1,0x4b8,in_ECX + 0x3140);
  FUN_0078fb9c(param_1,0x4b9,in_ECX + 0x31d8);
  FUN_0078fb9c(param_1,0x4ba,in_ECX + 0x3270);
  FUN_0078fb9c(param_1,0x4bb,in_ECX + 0x3308);
  FUN_0078fb9c(param_1,0x4bc,in_ECX + 0x33a0);
  FUN_0078fb9c(param_1,0x4bd,in_ECX + 0x3438);
  FUN_0078fb9c(param_1,0x4be,in_ECX + 0x34d0);
  FUN_0078fb9c(param_1,0x4bf,in_ECX + 0x3568);
  FUN_0078fb9c(param_1,0x49b,in_ECX + 0x3600);
  FUN_0078fb9c(param_1,0x4c0,in_ECX + 0x3698);
  FUN_0078fb9c(param_1,0x4c1,in_ECX + 0x3730);
  FUN_0078fb9c(param_1,0x4c2,in_ECX + 0x37c8);
  FUN_0078fb9c(param_1,0x4c3,in_ECX + 0x3860);
  FUN_0078fb9c(param_1,0x4c4,in_ECX + 0x38f8);
  FUN_0078fb9c(param_1,0x4c5,in_ECX + 0x3990);
  FUN_0078fb9c(param_1,0x4c6,in_ECX + 0x3a28);
  FUN_0078fb9c(param_1,0x4c7,in_ECX + 0x3ac0);
  FUN_0078fb9c(param_1,0x4c8,in_ECX + 0x3b58);
  FUN_0078fb9c(param_1,0x5ab,in_ECX + 0x3bf0);
  if (*(int *)(in_ECX + 0xc4) != 0) {
    *(undefined4 *)(in_ECX + 0xc4) = 0;
    FUN_00403dd0();
    local_8 = 0;
    FUN_005977f0();
    local_8._0_1_ = 1;
    FUN_00404950();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
    FUN_00404920();
    FUN_00797ece();
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  FUN_005d5300();
  if (*(int *)(in_ECX + 0x150) != 0) {
    *(undefined4 *)(in_ECX + 0x150) = 0;
    *(undefined8 *)(in_ECX + 0x158) = *(undefined8 *)(in_ECX + 200);
    FUN_005d8730(in_ECX + 0xa8,*(undefined8 *)(in_ECX + 0x158));
    FUN_00404920();
    FUN_00797ece();
    FUN_005d5bb0();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CSuuchiHyouDialog[10] */
/* 005d6ca0  FUN_005d6ca0  16 bytes, 0 callers */

void FUN_005d6ca0(void)

{
  FUN_005d6cb0();
  return;
}




/* vtable slots: CSuuchiHyouDialog[94] */
/* 005d7990  FUN_005d7990  194 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005d7990(void)

{
  int iVar1;
  int local_24;
  int local_20;
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
  iVar1 = FUN_00517b40(DAT_00a0c134,DAT_00a0c138,local_18,local_14,local_10,local_c,&local_24);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    FUN_004dbab0(local_24 + 0xaf,local_20 + 0x23);
  }
  return 1;
}




/* vtable slots: CSuuchiHyouDialog[96] */
/* 005d7ae0  FUN_005d7ae0  132 bytes, 0 callers */

void FUN_005d7ae0(void)

{
  int in_ECX;
  
  FUN_007955d2(1);
  DAT_00a0d62c = (uint)(*(int *)(in_ECX + 0x7c8) != 0);
  if (9e+40 <= *(double *)(in_ECX + 0xd0)) {
    if (*(int *)(in_ECX + 0xb8) == 0) {
      *(undefined8 *)(in_ECX + 0xd0) = *(undefined8 *)(in_ECX + 200);
    }
    else {
      *(undefined8 *)(in_ECX + 0xd0) = 0;
    }
  }
  FUN_00798a09();
  return;
}



