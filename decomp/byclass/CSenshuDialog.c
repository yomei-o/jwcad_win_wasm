/* CSenshuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSenshuDialog[1] */
/* 005c4b80  FUN_005c4b80  68 bytes, 0 callers */

undefined4 FUN_005c4b80(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005c48b0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1a50);
    }
  }
  return in_ECX;
}




/* vtable slots: CSenshuDialog[24], CSenshuDialog2[24] */
/* 005c4bd0  FUN_005c4bd0  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005c4bd0(void)

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
    FUN_00517510(&DAT_00a0c0ec,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CSenshuDialog[64] */
/* 005c5160  FUN_005c5160  1343 bytes, 0 callers */

void FUN_005c5160(undefined4 param_1)

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
  FUN_0078fb9c(param_1,0x8b1,local_14 + 200);
  FUN_0078fb9c(param_1,0x8b0,local_14 + 0x148);
  FUN_0078fb9c(param_1,0x479,local_14 + 0x1c8);
  FUN_0078fb9c(param_1,0x999,local_14 + 0x270);
  FUN_0078fb9c(param_1,0x998,local_14 + 0x318);
  FUN_0078fb9c(param_1,0x997,local_14 + 0x3c0);
  FUN_0078fb9c(param_1,0x996,local_14 + 0x468);
  FUN_0078fb9c(param_1,0x995,local_14 + 0x510);
  FUN_0078fb9c(param_1,0x994,local_14 + 0x5b8);
  FUN_0078fb9c(param_1,0x993,local_14 + 0x660);
  FUN_0078fb9c(param_1,0x992,local_14 + 0x708);
  FUN_0078fb9c(param_1,0x991,local_14 + 0x7b0);
  FUN_0078fb9c(param_1,0x581,local_14 + 0x858);
  FUN_0078fb9c(param_1,0x580,local_14 + 0x900);
  FUN_0078fb9c(param_1,0x57f,local_14 + 0x9a8);
  FUN_0078fb9c(param_1,0x57e,local_14 + 0xa50);
  FUN_0078fb9c(param_1,0x57d,local_14 + 0xaf8);
  FUN_0078fb9c(param_1,0x57c,local_14 + 0xba0);
  FUN_0078fb9c(param_1,0x57b,local_14 + 0xc48);
  FUN_0078fb9c(param_1,0x57a,local_14 + 0xcf0);
  FUN_0078fb9c(param_1,0x579,local_14 + 0xd98);
  FUN_0078fb9c(param_1,1,local_14 + 0xe40);
  FUN_0078f801(param_1,0x8b0,local_14 + 0xec0);
  FUN_0078f6f8(param_1,0x908,local_14 + 0xec4);
  if (DAT_00a0ca90 == 0) {
    FUN_00797f20(0);
    FUN_00797f20(0);
  }
  else {
    FUN_00797f20(5);
    FUN_00797f20(5);
    CStringT<>();
    local_8 = 0;
    uVar2 = *(undefined4 *)(*(int *)(local_14 + 0xb8) + 0x63b4 + DAT_00a0b428 * 4);
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
  FUN_0078fb9c(param_1,0xb1a,local_14 + 0xf80);
  FUN_0078fb9c(param_1,0xb1b,local_14 + 0x1000);
  FUN_0078fb9c(param_1,0xb1c,local_14 + 0x1080);
  FUN_0078fb9c(param_1,0xb1d,local_14 + 0x1100);
  FUN_0078fb9c(param_1,0xb1e,local_14 + 0x1180);
  FUN_0078fb9c(param_1,0xb1f,local_14 + 0x1200);
  FUN_0078fb9c(param_1,0xb20,local_14 + 0x1280);
  FUN_0078fb9c(param_1,0xb21,local_14 + 0x1300);
  FUN_0078fb9c(param_1,0xb22,local_14 + 0x1380);
  FUN_0078fb9c(param_1,0xb23,local_14 + 0x1400);
  FUN_0078fb9c(param_1,0xb24,local_14 + 0x1480);
  FUN_0078fb9c(param_1,0xb25,local_14 + 0x1500);
  FUN_0078fb9c(param_1,0xb26,local_14 + 0x1580);
  FUN_0078fb9c(param_1,0xb27,local_14 + 0x1600);
  FUN_0078fb9c(param_1,0xb28,local_14 + 0x1680);
  FUN_0078fb9c(param_1,0xb29,local_14 + 0x1700);
  FUN_0078fb9c(param_1,0xb2a,local_14 + 0x1780);
  FUN_0078fb9c(param_1,0xb2b,local_14 + 0x1800);
  FUN_0078fb9c(param_1,2,local_14 + 0x18d0);
  FUN_0078fb9c(param_1,0xa12,local_14 + 0x1950);
  FUN_0078fb9c(param_1,0x908,local_14 + 0x19d0);
  ExceptionList = local_10;
  return;
}




/* vtable slots: CSenshuDialog[10] */
/* 005c5cf0  FUN_005c5cf0  16 bytes, 0 callers */

void FUN_005c5cf0(void)

{
  FUN_005c5d10();
  return;
}




/* vtable slots: CSenshuDialog[94] */
/* 005c6190  FUN_005c6190  769 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005c6190(void)

{
  int iVar1;
  int iVar2;
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
  if (DAT_00a0b428 < 10) {
    *(int *)(local_1c + 0xf7c) = DAT_00a0b428;
  }
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_18);
  iVar1 = FUN_00517b40(DAT_00a0c0ec,DAT_00a0c0f0,local_18,local_14,local_10,local_c,&local_2c);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_2c,local_28,0,0,5);
  }
  if ((0 < DAT_00a0d620) || (*(int *)(local_1c + 0xb0) != 0)) {
    iVar1 = FUN_004f74b0(0x122);
    iVar1 = iVar1 + local_28;
    iVar2 = FUN_004f72f0(0x91);
    FUN_004dbab0(iVar2 + local_2c,iVar1);
  }
  for (local_20 = 1; local_20 < 10; local_20 = local_20 + 1) {
    FUN_007a5607();
    FUN_007a5607();
  }
  if (*(int *)(local_1c + 0xb0) == 0) {
    FUN_00797f20(5);
    FUN_00797f20(0);
    FUN_00797f20(5);
  }
  else {
    FUN_00797f20(0);
    FUN_00797f20(5);
    FUN_00797f20(0);
  }
  local_24 = 0;
  *(undefined4 *)(local_1c + 0xbc) = 1000;
  for (local_20 = 1; local_20 < 9; local_20 = local_20 + 1) {
    if (*(int *)(*(int *)(local_1c + 0xb8) + 0x63b4 + local_20 * 4) < 1) {
      *(undefined4 *)(*(int *)(local_1c + 0xb8) + 0x63b4 + local_20 * 4) = 1;
    }
    if (*(int *)(*(int *)(local_1c + 0xb8) + 0x63b4 + local_20 * 4) < *(int *)(local_1c + 0xbc)) {
      *(undefined4 *)(local_1c + 0xbc) =
           *(undefined4 *)(*(int *)(local_1c + 0xb8) + 0x63b4 + local_20 * 4);
    }
    if (local_24 < *(int *)(*(int *)(local_1c + 0xb8) + 0x63b4 + local_20 * 4)) {
      local_24 = *(int *)(*(int *)(local_1c + 0xb8) + 0x63b4 + local_20 * 4);
    }
  }
  if (0 < *(int *)(local_1c + 0xbc)) {
    *(int *)(local_1c + 0xbc) = *(int *)(local_1c + 0xbc) + -1;
  }
  *(undefined8 *)(local_1c + 0xc0) = 0x3ff0000000000000;
  if (0xf < local_24 - *(int *)(local_1c + 0xbc)) {
    *(double *)(local_1c + 0xc0) = 15.0 / (double)(local_24 - *(int *)(local_1c + 0xbc));
  }
  FUN_005c7c50(1);
  *(undefined4 *)(local_1c + 0xec4) = DAT_00a0eef0;
  FUN_007955d2(0);
  return 1;
}




/* vtable slots: CSenshuDialog[67] */
/* 005c7270  FUN_005c7270  223 bytes, 0 callers */

void FUN_005c7270(tagMSG *param_1)

{
  CDialog *in_ECX;
  
  if ((*(int *)(in_ECX + 0xf78) == 0) && (param_1->message == 0x100)) {
    switch(param_1->wParam) {
    case 0x31:
    case 0x4a:
    case 0x61:
      DAT_00a0b418 = 0xb;
      break;
    case 0x32:
    case 0x4b:
    case 0x62:
      DAT_00a0b418 = 0xc;
      break;
    case 0x33:
    case 0x4c:
    case 99:
      DAT_00a0b418 = 0xd;
      break;
    case 0x34:
    case 0x55:
    case 100:
      DAT_00a0b418 = 0xe;
      break;
    case 0x35:
    case 0x49:
    case 0x65:
      DAT_00a0b418 = 0xf;
      break;
    case 0x36:
    case 0x4f:
    case 0x66:
      DAT_00a0b418 = 0x10;
      break;
    case 0x37:
    case 0x67:
      DAT_00a0b418 = 0x11;
      break;
    case 0x38:
    case 0x68:
      DAT_00a0b418 = 0x12;
      break;
    case 0x39:
    case 0x69:
      DAT_00a0b418 = 0x13;
    }
    FUN_005c7c50(0);
  }
  CDialog::PreTranslateMessage(in_ECX,param_1);
  return;
}



