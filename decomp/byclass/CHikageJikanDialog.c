/* CHikageJikanDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CHikageJikanDialog[1] */
/* 0054feb0  FUN_0054feb0  68 bytes, 0 callers */

undefined4 FUN_0054feb0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0054fe40();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x308);
    }
  }
  return in_ECX;
}




/* vtable slots: CHikageJikanDialog[24] */
/* 0054ff00  FUN_0054ff00  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0054ff00(void)

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
    FUN_00517510(&DAT_00a0c16c,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CHikageJikanDialog[64] */
/* 0054ff80  FUN_0054ff80  258 bytes, 0 callers */

void FUN_0054ff80(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  FUN_00405880();
  FUN_0078fb9c(param_1,0x9db,in_ECX + 0x208);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0xc0);
  FUN_0078fb9c(param_1,0x9dc,in_ECX + 0x288);
  if (*(int *)(in_ECX + 0xb8) != 0) {
    cVar1 = FUN_00408cb0(&DAT_0095590a,in_ECX + 0xa8);
    if (cVar1 != '\0') {
      FUN_00404920();
      FUN_00797ece();
    }
    FUN_00404920();
    FUN_00797ece();
    (**(code **)(*(int *)(in_ECX + 0xc0) + 0x188))(*(undefined8 *)(in_ECX + 0xb0));
    *(undefined4 *)(in_ECX + 0xb8) = 0;
  }
  return;
}




/* vtable slots: CHikageJikanDialog[10] */
/* 00550090  FUN_00550090  16 bytes, 0 callers */

void FUN_00550090(void)

{
  FUN_005500a0();
  return;
}




/* vtable slots: CHikageJikanDialog[94] */
/* 005500b0  FUN_005500b0  158 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005500b0(void)

{
  int iVar1;
  undefined4 local_24;
  undefined4 local_20;
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
  iVar1 = FUN_00517b40(DAT_00a0c16c,DAT_00a0c170,local_18,local_14,local_10,local_c,&local_24);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  return 1;
}




/* vtable slots: CHikageJikanDialog[96] */
/* 00550150  FUN_00550150  46 bytes, 0 callers */

void FUN_00550150(void)

{
  int in_ECX;
  float10 fVar1;
  
  FUN_007955d2(1);
  fVar1 = (float10)FUN_00550180();
  *(double *)(in_ECX + 0xb0) = (double)fVar1;
  FUN_00798a09();
  return;
}



