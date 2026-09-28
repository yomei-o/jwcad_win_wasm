/* CSunpoSetteiDialg -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSunpoSetteiDialg[1] */
/* 005d2a20  FUN_005d2a20  68 bytes, 0 callers */

undefined4 FUN_005d2a20(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005d28f0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xa40);
    }
  }
  return in_ECX;
}




/* vtable slots: CSunpoSetteiDialg[24] */
/* 005d2a70  FUN_005d2a70  184 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005d2a70(void)

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
    FUN_00517510(&DAT_00a0c124,local_18,local_14,local_10,local_c);
  }
  if (*(int *)(in_ECX + 0xac) != 0) {
    if (*(int **)(in_ECX + 0xac) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0xac) + 4))(1);
    }
    *(undefined4 *)(in_ECX + 0xac) = 0;
  }
  FUN_00792313();
  return;
}




/* vtable slots: CSunpoSetteiDialg[64] */
/* 005d2b30  FUN_005d2b30  1553 bytes, 0 callers */

void FUN_005d2b30(CDataExchange *param_1)

{
  int in_ECX;
  
  FUN_00405880();
  FUN_0078fb9c();
  DDX_Text(param_1,0x5d0,(double *)(in_ECX + 0x1e0));
  FUN_0078fb9c();
  FUN_0078f643();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  DDX_Text(param_1,0x5d1,(double *)(in_ECX + 0x268));
  DDX_Text(param_1,0x823,(double *)(in_ECX + 0x270));
  FUN_0078fb9c();
  DDX_Text(param_1,0x5c1,(double *)(in_ECX + 0x2f8));
  FUN_0078fb9c();
  DDX_Text(param_1,0x5c3,(double *)(in_ECX + 0x380));
  FUN_0078fb9c();
  DDX_Text(param_1,0x5c7,(double *)(in_ECX + 0x408));
  FUN_0078fb9c();
  DDX_Text(param_1,0x5c5,(double *)(in_ECX + 0x490));
  FUN_0078fb9c();
  DDX_Text(param_1,0x5c9,(double *)(in_ECX + 0x518));
  FUN_0078fb9c();
  DDX_Text(param_1,0x820,(double *)(in_ECX + 0x5a0));
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f75d();
  FUN_0078fb9c();
  FUN_0078f75d();
  FUN_0078f75d();
  FUN_0078f75d();
  FUN_0078f75d();
  FUN_0078f75d();
  FUN_0078f75d();
  FUN_0078f75d();
  FUN_0078fb9c();
  DDX_Text(param_1,0x824,(double *)(in_ECX + 0x6e8));
  FUN_0079f95a(param_1,in_ECX + 0x6e8,0,0x4018000000000000);
  FUN_0078fb9c();
  DDX_Text(param_1,0x5ca,(double *)(in_ECX + 0x7f8));
  FUN_0078fb9c();
  DDX_Text(param_1,0x5cb,(double *)(in_ECX + 0x880));
  FUN_0078fb9c();
  DDX_Text(param_1,0x5cc,(double *)(in_ECX + 0x908));
  FUN_0078fb9c();
  DDX_Text(param_1,0x5cd,(double *)(in_ECX + 0x990));
  FUN_0078fb9c();
  DDX_Text(param_1,0x5ce,(double *)(in_ECX + 0xa18));
  FUN_0078f6f8();
  DDX_Text(param_1,0x822,(double *)(in_ECX + 0xa28));
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078f6f8();
  FUN_0078fb9c();
  FUN_0078f6f8();
  if (*(int *)(in_ECX + 0xa8) != 0) {
    *(undefined4 *)(in_ECX + 0xa8) = 0;
    if (*(int *)(in_ECX + 0x658) == 1) {
      FUN_007979e8();
      FUN_007979e8();
    }
    else {
      FUN_007979e8();
      FUN_007979e8();
    }
    FUN_00797f20();
    FUN_00797df8();
  }
  return;
}




/* vtable slots: CSunpoSetteiDialg[10] */
/* 005d3150  FUN_005d3150  16 bytes, 0 callers */

void FUN_005d3150(void)

{
  FUN_005d3160();
  return;
}




/* vtable slots: CSunpoSetteiDialg[94] */
/* 005d3240  FUN_005d3240  379 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005d3240(void)

{
  undefined4 uVar1;
  LPCWSTR pszFaceName;
  int iVar2;
  int local_38;
  int local_34;
  undefined4 local_30;
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
  puStack_c = &LAB_0092e18f;
  local_10 = ExceptionList;
  local_14 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_00798993(local_14);
  uVar1 = FUN_00404920();
  FUN_00797ece(uVar1);
  local_2c = FUN_004121b0(8);
  local_8 = 0;
  if (local_2c == 0) {
    local_30 = 0;
  }
  else {
    local_30 = FUN_00480c40();
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(local_28 + 0xac) = local_30;
  pszFaceName = (LPCWSTR)FUN_00404920();
  FID_conflict_CreateFontW(0,0,0,0,400,0,0,0,0x80,4,0x20,0,5,pszFaceName);
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_24);
  iVar2 = FUN_00517b40(DAT_00a0c124,DAT_00a0c128,local_24,local_20,local_1c,local_18,&local_38);
  if (iVar2 != 0) {
    FUN_00797e71(0,local_38,local_34,0,0,5);
  }
  if (1 < DAT_00a0d620) {
    FUN_004dbab0(local_38 + 0xf0,local_34 + 0x23);
  }
  ExceptionList = local_10;
  return 1;
}




/* vtable slots: CSunpoSetteiDialg[96] */
/* 005d34b0  FUN_005d34b0  2082 bytes, 0 callers */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d34b0(void)

{
  int in_ECX;
  double local_1c;
  int local_10;
  int local_c;
  
  FUN_007955d2(1);
  FUN_00404860(in_ECX + 0x150);
  DAT_00a0bda8 = (uint)(*(int *)(in_ECX + 0x1d8) != 0);
  DAT_00a0bdac = (uint)(*(int *)(in_ECX + 0x1dc) != 0);
  if (*(double *)(in_ECX + 0x1e0) <= -10.0 && *(double *)(in_ECX + 0x1e0) != -10.0) {
    *(undefined8 *)(in_ECX + 0x1e0) = 0xc024000000000000;
  }
  if (*(double *)(in_ECX + 0x1e0) == 0.0) {
    *(undefined8 *)(in_ECX + 0x1e0) = 0x3ff0000000000000;
  }
  if (10.0 < *(double *)(in_ECX + 0x1e0)) {
    *(undefined8 *)(in_ECX + 0x1e0) = 0x4024000000000000;
  }
  if (*(double *)(in_ECX + 0x1e0) <= 0.0) {
    if (*(double *)(in_ECX + 0x1e0) <= 0.0) {
      local_1c = -*(double *)(in_ECX + 0x1e0);
    }
    else {
      local_1c = *(double *)(in_ECX + 0x1e0);
    }
    DAT_00a0bcd0 = -(int)(local_1c + 0.5);
  }
  else {
    DAT_00a0bcd0 = (int)(*(double *)(in_ECX + 0x1e0) + 0.5);
  }
  if (DAT_00a0bcd0 == 0) {
    DAT_00a0bcd0 = 1;
  }
  if (DAT_00a0bcd0 < -10) {
    DAT_00a0bcd0 = -10;
  }
  if (10 < DAT_00a0bcd0) {
    DAT_00a0bcd0 = 10;
  }
  local_10 = (int)(*(double *)(in_ECX + 0x268) + 0.5);
  local_c = local_10 % 10;
  local_10 = local_10 / 10;
  if (local_c < 1) {
    local_c = 1;
  }
  if (9 < local_c) {
    local_c = 9;
  }
  _DAT_00a0bcd4 = local_c;
  if (local_10 < 1) {
    local_10 = 1;
  }
  if (9 < local_10) {
    local_10 = 9;
  }
  DAT_00a0bcd8 = local_10;
  local_10 = (int)(*(double *)(in_ECX + 0x270) + 0.5);
  local_c = local_10 % 10;
  local_10 = local_10 / 10;
  if (local_c < 1) {
    local_c = 1;
  }
  if (9 < local_c) {
    local_c = 9;
  }
  _DAT_00a0bcdc = local_c;
  if (local_10 < 1) {
    local_10 = 1;
  }
  if (9 < local_10) {
    local_10 = 9;
  }
  DAT_00a0bce0 = local_10;
  local_10 = (int)(*(double *)(in_ECX + 0x2f8) + 0.5);
  local_c = local_10 % 10;
  local_10 = local_10 / 10;
  if (local_c < 1) {
    local_c = 1;
  }
  if (9 < local_c) {
    local_c = 9;
  }
  _DAT_00a0bce4 = local_c;
  if (local_10 < 1) {
    local_10 = 1;
  }
  if (9 < local_10) {
    local_10 = 9;
  }
  DAT_00a0bce8 = local_10;
  DAT_00a0bcf0 = *(undefined8 *)(in_ECX + 0x380);
  DAT_00a0bcf8 = *(undefined8 *)(in_ECX + 0x408);
  DAT_00a0bd00 = *(undefined8 *)(in_ECX + 0x490);
  DAT_00a0bd08 = *(undefined8 *)(in_ECX + 0x518);
  DAT_00a0bd10 = (uint)(*(int *)(in_ECX + 0x628) != 0);
  DAT_00a0bd18 = *(undefined8 *)(in_ECX + 0x5a0);
  DAT_00a0bd20 = (uint)(*(int *)(in_ECX + 0x62c) != 0);
  DAT_00a0bd24 = (uint)(*(int *)(in_ECX + 0x630) != 0);
  DAT_00a0bd28 = (uint)(*(int *)(in_ECX + 0x634) != 0);
  DAT_00a0bd2c = (uint)(*(int *)(in_ECX + 0x638) != 0);
  DAT_00a0bd30 = (uint)(*(int *)(in_ECX + 0x63c) != 0);
  DAT_00a0bd34 = *(undefined4 *)(in_ECX + 0x648);
  DAT_00a0bd38 = *(undefined4 *)(in_ECX + 0x64c);
  DAT_00a0bd3c = *(undefined4 *)(in_ECX + 0x650);
  DAT_00a0bd40 = *(undefined4 *)(in_ECX + 0x654);
  DAT_00a0bd44 = *(undefined4 *)(in_ECX + 0x65c);
  DAT_00a0bcc8 = *(undefined4 *)(in_ECX + 0x640);
  DAT_00a0bcc4 = *(undefined4 *)(in_ECX + 0x644);
  if (*(int *)(in_ECX + 0x658) == 0) {
    DAT_00a0bd5c = 0;
    if (*(int *)(in_ECX + 0x660) != 0) {
      DAT_00a0bd5c = 2;
    }
  }
  else {
    DAT_00a0bd5c = 1;
  }
  DAT_00a0bd9c = (int)*(double *)(in_ECX + 0x6e8);
  if (*(double *)(in_ECX + 0x7f8) <= -100.0 && *(double *)(in_ECX + 0x7f8) != -100.0) {
    *(undefined8 *)(in_ECX + 0x7f8) = 0xc059000000000000;
  }
  if (200.0 < *(double *)(in_ECX + 0x7f8)) {
    *(undefined8 *)(in_ECX + 0x7f8) = 0x4069000000000000;
  }
  DAT_00a0bd60 = *(undefined8 *)(in_ECX + 0x7f8);
  if (*(double *)(in_ECX + 0x880) <= -100.0 && *(double *)(in_ECX + 0x880) != -100.0) {
    *(undefined8 *)(in_ECX + 0x880) = 0xc059000000000000;
  }
  if (100.0 < *(double *)(in_ECX + 0x880)) {
    *(undefined8 *)(in_ECX + 0x880) = 0x4069000000000000;
  }
  DAT_00a0bd68 = *(undefined8 *)(in_ECX + 0x880);
  if (*(double *)(in_ECX + 0x908) <= -100.0 && *(double *)(in_ECX + 0x908) != -100.0) {
    *(undefined8 *)(in_ECX + 0x908) = 0xc059000000000000;
  }
  if (200.0 < *(double *)(in_ECX + 0x908)) {
    *(undefined8 *)(in_ECX + 0x908) = 0x4069000000000000;
  }
  DAT_00a0bd70 = *(undefined8 *)(in_ECX + 0x908);
  if (*(double *)(in_ECX + 0x990) <= -100.0 && *(double *)(in_ECX + 0x990) != -100.0) {
    *(undefined8 *)(in_ECX + 0x990) = 0xc059000000000000;
  }
  if (200.0 < *(double *)(in_ECX + 0x990)) {
    *(undefined8 *)(in_ECX + 0x990) = 0x4069000000000000;
  }
  DAT_00a0bd78 = *(undefined8 *)(in_ECX + 0x990);
  if (*(double *)(in_ECX + 0xa18) <= 0.0 && *(double *)(in_ECX + 0xa18) != 0.0) {
    *(undefined8 *)(in_ECX + 0xa18) = 0;
  }
  if (200.0 < *(double *)(in_ECX + 0xa18)) {
    *(undefined8 *)(in_ECX + 0xa18) = 0x4069000000000000;
  }
  DAT_00a0bd80 = *(undefined8 *)(in_ECX + 0xa18);
  DAT_00a0bd48 = (uint)(*(int *)(in_ECX + 0xa20) != 0);
  if (*(double *)(in_ECX + 0xa28) <= 0.1 && *(double *)(in_ECX + 0xa28) != 0.1) {
    *(undefined8 *)(in_ECX + 0xa28) = 0x3fb999999999999a;
  }
  if (100.0 < *(double *)(in_ECX + 0xa28)) {
    *(undefined8 *)(in_ECX + 0xa28) = 0x4059000000000000;
  }
  DAT_00a0bd50 = *(undefined8 *)(in_ECX + 0xa28);
  DAT_00a0bd58 = (uint)(*(int *)(in_ECX + 0xa30) != 0);
  DAT_00a0bd88 = (uint)(*(int *)(in_ECX + 0x770) != 0);
  DAT_00a0bd8c = (uint)(*(int *)(in_ECX + 0x774) != 0);
  DAT_00a0bda0 = (uint)(*(int *)(in_ECX + 0xa34) != 0);
  DAT_00a0bdb8 = (uint)(*(int *)(in_ECX + 0xa38) != 0);
  FUN_00517a30();
  FUN_00798a09();
  return;
}



