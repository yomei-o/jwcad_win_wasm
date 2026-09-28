/* CPrintKeishikiDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPrintKeishikiDialog[1] */
/* 005afb70  FUN_005afb70  68 bytes, 0 callers */

undefined4 FUN_005afb70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005afa70();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x600);
    }
  }
  return in_ECX;
}




/* vtable slots: CPrintKeishikiDialog[24] */
/* 005aff90  FUN_005aff90  114 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005aff90(void)

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
    FUN_00517510(&DAT_00a0c18c,local_18,local_14,local_10,local_c);
  }
  FUN_00792313();
  return;
}




/* vtable slots: CPrintKeishikiDialog[64] */
/* 005b0010  FUN_005b0010  546 bytes, 0 callers */

void FUN_005b0010(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x532,in_ECX + 0xc0);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x140);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x1c0);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x240);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x2c0);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0x2c4);
  FUN_0078f6f8(param_1,0x52d,in_ECX + 0x2c8);
  FUN_0078f6f8(param_1,0x52e,in_ECX + 0x2cc);
  FUN_0078f6f8(param_1,0x531,in_ECX + 0x2d0);
  FUN_0078f6f8(param_1,0x52f,in_ECX + 0x2d4);
  FUN_0078f6f8(param_1,0x530,in_ECX + 0x2d8);
  FUN_0078f6f8(param_1,0x841,in_ECX + 0x2dc);
  FUN_0078f6f8(param_1,0x842,in_ECX + 0x2e0);
  FUN_0078fb9c(param_1,0x52d,in_ECX + 0x2e8);
  FUN_0078fb9c(param_1,0x530,in_ECX + 0x368);
  FUN_0078fb9c(param_1,0x841,in_ECX + 1000);
  FUN_0078fb9c(param_1,0x842,in_ECX + 0x468);
  FUN_0078f6f8(param_1,0x532,in_ECX + 0x4e8);
  FUN_0078fb9c(param_1,0x533,in_ECX + 0x4f0);
  FUN_0078f6f8(param_1,0x533,in_ECX + 0x570);
  FUN_0078fb9c(param_1,0x535,in_ECX + 0x578);
  FUN_0078f6f8(param_1,0x535,in_ECX + 0x5f8);
  return;
}




/* vtable slots: CPrintKeishikiDialog[10] */
/* 005b0240  FUN_005b0240  16 bytes, 0 callers */

void FUN_005b0240(void)

{
  FUN_005b0250();
  return;
}




/* vtable slots: CPrintKeishikiDialog[94] */
/* 005b04c0  FUN_005b04c0  168 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_005b04c0(void)

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
  iVar1 = FUN_00517b40(DAT_00a0c18c,DAT_00a0c190,local_18,local_14,local_10,local_c,&local_24);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  FUN_005afbc0(0);
  return 1;
}



