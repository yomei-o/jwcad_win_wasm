/* CMojiSeiriDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMojiSeiriDialog[1] */
/* 0057d310  FUN_0057d310  68 bytes, 0 callers */

undefined4 FUN_0057d310(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0057d260();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x458);
    }
  }
  return in_ECX;
}




/* vtable slots: CMojiSeiriDialog[24] */
/* 0057d360  FUN_0057d360  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0057d360(void)

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
    FUN_00517510(&DAT_00a0c174,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CMojiSeiriDialog[64] */
/* 0057d3e0  FUN_0057d3e0  431 bytes, 0 callers */

void FUN_0057d3e0(CDataExchange *param_1)

{
  int in_ECX;
  
  FUN_00405880();
  DDX_Text(param_1,0x5d3,(double *)(in_ECX + 0xa8));
  FUN_0079f95a(param_1,in_ECX + 0xa8,0x3ff0000000000000,0x4024000000000000);
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078fb9c();
  DDX_Text();
  DDX_Text();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078fb9c();
  FUN_0078f75d();
  return;
}




/* vtable slots: CMojiSeiriDialog[10] */
/* 0057d590  FUN_0057d590  16 bytes, 0 callers */

void FUN_0057d590(void)

{
  FUN_0057d5a0();
  return;
}




/* vtable slots: CMojiSeiriDialog[94] */
/* 0057d670  FUN_0057d670  319 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_0057d670(void)

{
  undefined4 uVar1;
  int iVar2;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  uVar1 = FUN_00798993();
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_18);
  iVar2 = FUN_00517b40(DAT_00a0c174,DAT_00a0c178,local_18,local_14,local_10,local_c,&local_24);
  if (iVar2 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    FUN_004dbab0(local_24 + 0x12a,local_20 + 0x2a);
  }
  if (*(int *)(local_1c + 0xb4) == 0) {
    FUN_007979e8(0);
    FUN_007979e8(0);
  }
  else {
    FUN_007979e8(1);
    FUN_007979e8(1);
  }
  if (*(int *)(local_1c + 0x1c0) == 0) {
    FUN_007979e8(1);
  }
  else {
    FUN_007979e8(0);
  }
  return uVar1;
}




/* vtable slots: CMojiSeiriDialog[96] */
/* 0057d7b0  FUN_0057d7b0  354 bytes, 0 callers */

void FUN_0057d7b0(void)

{
  char cVar1;
  int in_ECX;
  
  FUN_007955d2(1);
  if ((1.0 <= *(double *)(in_ECX + 0xa8)) && (*(double *)(in_ECX + 0xa8) <= 10.0)) {
    DAT_00a0cb78 = (int)*(double *)(in_ECX + 0xa8);
  }
  DAT_00a0cb88 = (uint)(*(int *)(in_ECX + 0xb0) != 0);
  DAT_00a0cb8c = (uint)(*(int *)(in_ECX + 0xb4) != 0);
  DAT_00a0cb80 = (uint)(*(int *)(in_ECX + 0x138) != 0);
  DAT_00a0cb84 = (uint)(*(int *)(in_ECX + 0x1c0) != 0);
  cVar1 = FUN_00408cb0(&DAT_00955918,in_ECX + 0x2c8);
  if (cVar1 != '\0') {
    FUN_00404860(in_ECX + 0x2c8);
  }
  cVar1 = FUN_00408cb0(&DAT_00955918,in_ECX + 0x2cc);
  if (cVar1 != '\0') {
    FUN_00404860(in_ECX + 0x2cc);
  }
  if ((-1 < *(int *)(in_ECX + 0x450)) && (*(int *)(in_ECX + 0x450) < 3)) {
    DAT_00a0cb7c = *(undefined4 *)(in_ECX + 0x450);
  }
  FUN_00798a09();
  return;
}



