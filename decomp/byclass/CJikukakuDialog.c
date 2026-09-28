/* CJikukakuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CJikukakuDialog[1] */
/* 004d01f0  FUN_004d01f0  68 bytes, 0 callers */

undefined4 FUN_004d01f0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004d01a0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x5e8);
    }
  }
  return in_ECX;
}




/* vtable slots: CJikukakuDialog[24] */
/* 004d0240  FUN_004d0240  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_004d0240(void)

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
    FUN_00517510(&DAT_00a0c114,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CJikukakuDialog[64] */
/* 004d02c0  FUN_004d02c0  454 bytes, 0 callers */

void FUN_004d02c0(CDataExchange *param_1)

{
  int in_ECX;
  
  FUN_00405880();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078f6f8();
  DDX_Text(param_1,0x726,(double *)(in_ECX + 0x470));
  FUN_0079f95a(param_1,in_ECX + 0x470,0x4014000000000000,0x4059000000000000);
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  return;
}




/* vtable slots: CJikukakuDialog[10] */
/* 004d0490  FUN_004d0490  16 bytes, 0 callers */

void FUN_004d0490(void)

{
  FUN_004d04a0();
  return;
}




/* vtable slots: CJikukakuDialog[97], COffsetDialog[97], CPrtFileWnd[97] */
/* 004d0680  FUN_004d0680  19 bytes, 0 callers */

void FUN_004d0680(void)

{
  FUN_00798826();
  return;
}




/* vtable slots: CJikukakuDialog[94] */
/* 004d09b0  FUN_004d09b0  1351 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_004d09b0(void)

{
  double *pdVar1;
  int iVar2;
  double local_2c;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  FUN_00798993();
  if (*(double *)(*(int *)(local_1c + 0xa8) + 0x17c0) <= 0.0) {
    local_2c = -*(double *)(*(int *)(local_1c + 0xa8) + 0x17c0);
  }
  else {
    local_2c = *(double *)(*(int *)(local_1c + 0xa8) + 0x17c0);
  }
  if (local_2c <= 1e-07) {
    *(undefined4 *)(local_1c + 0x208) = 0;
  }
  else {
    *(undefined4 *)(local_1c + 0x208) = 1;
  }
  (**(code **)(*(int *)(local_1c + 0xc0) + 0x17c))();
  (**(code **)(*(int *)(local_1c + 0xc0) + 0x188))(*(undefined8 *)(local_1c + 0x5c0));
  *(undefined4 *)(local_1c + 0x5e0) = 0;
  pdVar1 = (double *)(*(int *)(local_1c + 0xa8) + 0x7a28);
  if (*pdVar1 <= 0.001 && *pdVar1 != 0.001) {
    *(undefined8 *)(*(int *)(local_1c + 0xa8) + 0x7a28) = 0x3f50624dd2f1a9fc;
  }
  pdVar1 = (double *)(*(int *)(local_1c + 0xa8) + 0x7a30);
  if (*pdVar1 <= 0.001 && *pdVar1 != 0.001) {
    *(undefined8 *)(*(int *)(local_1c + 0xa8) + 0x7a30) = 0x3f50624dd2f1a9fc;
  }
  FUN_004d04b0();
  *(undefined8 *)(local_1c + 0xb0) =
       *(undefined8 *)
        (*(int *)(local_1c + 0xa8) + 0x2578 + *(int *)(*(int *)(local_1c + 0xa8) + 0x256c) * 8);
  if (*(int *)(*(int *)(local_1c + 0xa8) + 0x7a14) == 0) {
    *(undefined4 *)(local_1c + 0x468) = 0;
    *(undefined8 *)(local_1c + 0x5d0) = *(undefined8 *)(*(int *)(local_1c + 0xa8) + 0x7a28);
    *(undefined8 *)(local_1c + 0x5d8) = *(undefined8 *)(*(int *)(local_1c + 0xa8) + 0x7a30);
  }
  else {
    *(undefined4 *)(local_1c + 0x468) = 1;
    if (DAT_00a0d62c == 0) {
      *(double *)(local_1c + 0x5d0) =
           *(double *)(*(int *)(local_1c + 0xa8) + 0x7a28) * *(double *)(local_1c + 0xb0);
      *(double *)(local_1c + 0x5d8) =
           *(double *)(*(int *)(local_1c + 0xa8) + 0x7a30) * *(double *)(local_1c + 0xb0);
    }
    else {
      *(double *)(local_1c + 0x5d0) =
           (*(double *)(*(int *)(local_1c + 0xa8) + 0x7a28) * *(double *)(local_1c + 0xb0)) /
           DAT_00a0d630;
      *(double *)(local_1c + 0x5d8) =
           (*(double *)(*(int *)(local_1c + 0xa8) + 0x7a30) * *(double *)(local_1c + 0xb0)) /
           DAT_00a0d630;
    }
  }
  FUN_005895a0(*(undefined8 *)(local_1c + 0x5d0),*(undefined8 *)(local_1c + 0x5d8));
  *(undefined8 *)(local_1c + 0x470) = *(undefined8 *)(*(int *)(local_1c + 0xa8) + 0x7a18);
  *(undefined4 *)(local_1c + 0x4f8) = 0;
  *(undefined4 *)(local_1c + 0x4fc) = 0;
  *(undefined4 *)(local_1c + 0x500) = 0;
  *(undefined4 *)(local_1c + 0x504) = 0;
  *(undefined4 *)(local_1c + 0x508) = 0;
  *(undefined4 *)(local_1c + 0x50c) = 0;
  *(undefined4 *)(local_1c + 0x510) = 0;
  if (*(int *)(*(int *)(local_1c + 0xa8) + 0x7a0c) == 0) {
    *(undefined4 *)(local_1c + 0x4f8) = 1;
  }
  if (*(int *)(*(int *)(local_1c + 0xa8) + 0x7a10) != 0) {
    *(undefined4 *)(local_1c + 0x4fc) = 1;
  }
  if (*(int *)(*(int *)(local_1c + 0xa8) + 0x7a0c) == 1) {
    *(undefined4 *)(local_1c + 0x500) = 1;
  }
  if (*(int *)(*(int *)(local_1c + 0xa8) + 0x7a0c) == 2) {
    *(undefined4 *)(local_1c + 0x504) = 1;
  }
  if (*(int *)(*(int *)(local_1c + 0xa8) + 0x7a0c) == 3) {
    *(undefined4 *)(local_1c + 0x508) = 1;
  }
  if (*(int *)(*(int *)(local_1c + 0xa8) + 0x7a0c) == 4) {
    *(undefined4 *)(local_1c + 0x50c) = 1;
  }
  if (*(int *)(*(int *)(local_1c + 0xa8) + 0x7a0c) == 5) {
    *(undefined4 *)(local_1c + 0x510) = 1;
  }
  *(undefined8 *)(local_1c + 0xb0) = 0x3ff0000000000000;
  *(undefined4 *)(local_1c + 0x514) = 0;
  *(undefined4 *)(local_1c + 0x518) = 0;
  if (*(int *)(*(int *)(local_1c + 0xa8) + 0x8f20) == 2) {
    *(undefined4 *)(local_1c + 0x514) = 1;
  }
  if (*(int *)(*(int *)(local_1c + 0xa8) + 0x8f20) == 1) {
    *(undefined4 *)(local_1c + 0x518) = 1;
  }
  FUN_007955d2();
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_18);
  iVar2 = FUN_00517b40(DAT_00a0c114,DAT_00a0c118,local_18,local_14,local_10,local_c,&local_24);
  if (iVar2 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  if (0 < DAT_00a0d620) {
    FUN_004dbab0();
  }
  return 1;
}




/* vtable slots: CJikukakuDialog[96] */
/* 004d1230  FUN_004d1230  635 bytes, 0 callers */

void FUN_004d1230(void)

{
  double *pdVar1;
  int in_ECX;
  float10 fVar2;
  
  FUN_007955d2(1);
  fVar2 = (float10)FUN_0058cc80();
  *(double *)(in_ECX + 0x5c0) = (double)fVar2;
  *(undefined8 *)(*(int *)(in_ECX + 0xa8) + 0x17d0) = *(undefined8 *)(in_ECX + 0x5c0);
  *(undefined8 *)(*(int *)(in_ECX + 0xa8) + 0x17c8) = *(undefined8 *)(in_ECX + 0x5c0);
  *(undefined8 *)(in_ECX + 0xb0) =
       *(undefined8 *)
        (*(int *)(in_ECX + 0xa8) + 0x2578 + *(int *)(*(int *)(in_ECX + 0xa8) + 0x256c) * 8);
  if (*(int *)(*(int *)(in_ECX + 0xa8) + 0x7a14) == 0) {
    fVar2 = (float10)FUN_005899b0();
    *(double *)(*(int *)(in_ECX + 0xa8) + 0x7a28) = (double)fVar2;
    fVar2 = (float10)(**(code **)(*(int *)(in_ECX + 0x290) + 0x178))();
    *(double *)(*(int *)(in_ECX + 0xa8) + 0x7a30) = (double)fVar2;
  }
  else if (DAT_00a0d62c == 0) {
    fVar2 = (float10)FUN_005899b0();
    *(double *)(*(int *)(in_ECX + 0xa8) + 0x7a28) = (double)fVar2 / *(double *)(in_ECX + 0xb0);
    fVar2 = (float10)(**(code **)(*(int *)(in_ECX + 0x290) + 0x178))();
    *(double *)(*(int *)(in_ECX + 0xa8) + 0x7a30) = (double)fVar2 / *(double *)(in_ECX + 0xb0);
  }
  else {
    fVar2 = (float10)FUN_005899b0();
    *(double *)(*(int *)(in_ECX + 0xa8) + 0x7a28) =
         ((double)fVar2 / *(double *)(in_ECX + 0xb0)) * DAT_00a0d630;
    fVar2 = (float10)(**(code **)(*(int *)(in_ECX + 0x290) + 0x178))();
    *(double *)(*(int *)(in_ECX + 0xa8) + 0x7a30) =
         ((double)fVar2 / *(double *)(in_ECX + 0xb0)) * DAT_00a0d630;
  }
  pdVar1 = (double *)(*(int *)(in_ECX + 0xa8) + 0x7a28);
  if (*pdVar1 <= 0.001 && *pdVar1 != 0.001) {
    *(undefined8 *)(*(int *)(in_ECX + 0xa8) + 0x7a28) = 0x3f50624dd2f1a9fc;
  }
  pdVar1 = (double *)(*(int *)(in_ECX + 0xa8) + 0x7a30);
  if (*pdVar1 <= 0.001 && *pdVar1 != 0.001) {
    *(undefined8 *)(*(int *)(in_ECX + 0xa8) + 0x7a30) = 0x3f50624dd2f1a9fc;
  }
  *(undefined8 *)(*(int *)(in_ECX + 0xa8) + 0x7a18) = *(undefined8 *)(in_ECX + 0x470);
  FUN_00798a09();
  return;
}



