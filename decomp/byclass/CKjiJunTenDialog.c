/* CKjiJunTenDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CKjiJunTenDialog[1] */
/* 005507e0  FUN_005507e0  68 bytes, 0 callers */

undefined4 FUN_005507e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00550710();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x708);
    }
  }
  return in_ECX;
}




/* vtable slots: CKjiJunTenDialog[24] */
/* 00550970  FUN_00550970  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00550970(void)

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
    FUN_00517510(&DAT_00a0c0fc,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CKjiJunTenDialog[64] */
/* 005509f0  FUN_005509f0  921 bytes, 0 callers */

void FUN_005509f0(CDataExchange *param_1)

{
  int in_ECX;
  
  FUN_00405880();
  FUN_0078f75d();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  DDX_Text(param_1,0x7d4,(double *)(in_ECX + 0x3c0));
  FUN_0079f95a(param_1,in_ECX + 0x3c0,0xc08f400000000000,0x408f400000000000);
  DDX_Text(param_1,0x7d5,(double *)(in_ECX + 0x3c8));
  FUN_0079f95a(param_1,in_ECX + 0x3c8,0xc08f400000000000,0x408f400000000000);
  DDX_Text(param_1,0x7d6,(double *)(in_ECX + 0x3d0));
  FUN_0079f95a(param_1,in_ECX + 0x3d0,0xc08f400000000000,0x408f400000000000);
  DDX_Text(param_1,0x7d7,(double *)(in_ECX + 0x3d8));
  FUN_0079f95a(param_1,in_ECX + 0x3d8,0xc08f400000000000,0x408f400000000000);
  DDX_Text(param_1,0x7d8,(double *)(in_ECX + 0x3e0));
  FUN_0079f95a(param_1,in_ECX + 0x3e0,0xc08f400000000000,0x408f400000000000);
  DDX_Text(param_1,0x7d9,(double *)(in_ECX + 1000));
  FUN_0079f95a(param_1,in_ECX + 1000,0xc08f400000000000,0x408f400000000000);
  return;
}




/* vtable slots: CKjiJunTenDialog[10] */
/* 00550d90  FUN_00550d90  16 bytes, 0 callers */

void FUN_00550d90(void)

{
  FUN_00550da0();
  return;
}




/* vtable slots: CKjiJunTenDialog[94] */
/* 00550db0  FUN_00550db0  447 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00550db0(void)

{
  int iVar1;
  int in_ECX;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0xa8) != 0) {
    if (*(int *)(in_ECX + 0xac) == 0) {
      if (DAT_00a0bdb0 == 1) {
        *(undefined4 *)(in_ECX + 0x6f0) = 1;
      }
      else if (DAT_00a0bdb0 == 2) {
        *(undefined4 *)(in_ECX + 0x6f4) = 1;
      }
      else if (DAT_00a0bdb0 == 3) {
        *(undefined4 *)(in_ECX + 0x6f4) = 1;
        *(undefined4 *)(in_ECX + 0x6f0) = 1;
      }
    }
    else if (DAT_00a0be44 == 1) {
      *(undefined4 *)(in_ECX + 0x6f0) = 1;
    }
    else if (DAT_00a0be44 == 2) {
      *(undefined4 *)(in_ECX + 0x6f4) = 1;
    }
    else if (DAT_00a0be44 == 3) {
      *(undefined4 *)(in_ECX + 0x6f4) = 1;
      *(undefined4 *)(in_ECX + 0x6f0) = 1;
    }
  }
  local_1c = in_ECX;
  FUN_00798993();
  *(undefined4 *)(local_1c + 0xb8) = 0;
  if (DAT_00a0b9c8 == 0) {
    FUN_00550830(0);
  }
  else {
    *(undefined4 *)(local_1c + 0xb8) = 1;
    FUN_00550830(1);
  }
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_18);
  iVar1 = FUN_00517b40(DAT_00a0c0fc,DAT_00a0c100,local_18,local_14,local_10,local_c,&local_24);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    FUN_004dbab0(local_24 + 0x80,local_20 + 0x50);
  }
  return 1;
}




/* vtable slots: CKjiJunTenDialog[96] */
/* 00550f70  FUN_00550f70  375 bytes, 0 callers */

void FUN_00550f70(void)

{
  int in_ECX;
  
  FUN_007955d2(1);
  DAT_00a0b9c8 = (uint)(*(int *)(in_ECX + 0xb8) != 0);
  DAT_00a0b9d0 = *(undefined8 *)(in_ECX + 0x3c0);
  DAT_00a0b9d8 = *(undefined8 *)(in_ECX + 0x3c8);
  DAT_00a0b9e0 = *(undefined8 *)(in_ECX + 0x3d0);
  DAT_00a0ba20 = *(undefined8 *)(in_ECX + 0x3d8);
  DAT_00a0ba28 = *(undefined8 *)(in_ECX + 0x3e0);
  DAT_00a0ba30 = *(undefined8 *)(in_ECX + 1000);
  if (*(int *)(in_ECX + 0xa8) != 0) {
    if (*(int *)(in_ECX + 0xac) == 0) {
      DAT_00a0bdb0 = (uint)(*(int *)(in_ECX + 0x6f0) != 0);
      if (*(int *)(in_ECX + 0x6f4) != 0) {
        DAT_00a0bdb0 = DAT_00a0bdb0 + 2;
      }
    }
    else {
      DAT_00a0be44 = (uint)(*(int *)(in_ECX + 0x6f0) != 0);
      if (*(int *)(in_ECX + 0x6f4) != 0) {
        DAT_00a0be44 = DAT_00a0be44 + 2;
      }
    }
  }
  FUN_00798a09();
  return;
}




/* vtable slots: CKjiJunTenDialog[67] */
/* 00551160  FUN_00551160  25 bytes, 0 callers */

void FUN_00551160(tagMSG *param_1)

{
  CDialog *in_ECX;
  
  CDialog::PreTranslateMessage(in_ECX,param_1);
  return;
}



