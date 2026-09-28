/* CBlockEditDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CBlockEditDialog[1] */
/* 00414d70  FUN_00414d70  68 bytes, 0 callers */

undefined4 FUN_00414d70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00414d20();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x240);
    }
  }
  return in_ECX;
}




/* vtable slots: CBlockEditDialog[24] */
/* 00414dc0  FUN_00414dc0  129 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_00414dc0(void)

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
    FUN_00517510(in_ECX + 0x238,local_18,local_14,local_10,local_c);
  }
  DAT_00a0cc8c = 0;
  FUN_00792313();
  return;
}




/* vtable slots: CBlockEditDialog[64] */
/* 00414e50  FUN_00414e50  188 bytes, 0 callers */

void FUN_00414e50(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,3,in_ECX + 0xa8);
  FUN_0078fb9c(param_1,0x96b,in_ECX + 0x128);
  FUN_0078fb9c(param_1,0x96a,in_ECX + 0x1a8);
  FUN_0078f6f8(param_1,0x96a,in_ECX + 0x228);
  FUN_0078f6f8(param_1,0x96b,in_ECX + 0x22c);
  DDX_Text(param_1,0x937,in_ECX + 0x230);
  FUN_0078f500(param_1,in_ECX + 0x230,0xfa);
  return;
}




/* vtable slots: CBlockEditDialog[12] */
/* 00414f10  FUN_00414f10  16 bytes, 0 callers */

undefined ** FUN_00414f10(void)

{
  return &PTR_DAT_00956858;
}




/* vtable slots: CBlockEditDialog[14] */
/* 00414f20  FUN_00414f20  16 bytes, 0 callers */

undefined ** FUN_00414f20(void)

{
  return &PTR_PTR_00956868;
}




/* vtable slots: CBlockEditDialog[10] */
/* 00414f30  FUN_00414f30  16 bytes, 0 callers */

void FUN_00414f30(void)

{
  FUN_00414f40();
  return;
}




/* vtable slots: CBlockEditDialog[97] */
/* 00414f50  FUN_00414f50  32 bytes, 0 callers */

void FUN_00414f50(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x234) = 0;
  FUN_00798826();
  return;
}




/* vtable slots: CBlockEditDialog[4] */
/* 00415070  FUN_00415070  19 bytes, 0 callers */

void FUN_00415070(void)

{
  FUN_00793593();
  return;
}




/* vtable slots: CBlockEditDialog[94] */
/* 00415090  FUN_00415090  162 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_00415090(void)

{
  int iVar1;
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
  FUN_004044d0();
  FUN_00413f30();
  FUN_004146a0(&local_18);
  iVar1 = FUN_00517b40(*(undefined4 *)(local_1c + 0x238),*(undefined4 *)(local_1c + 0x23c),local_18,
                       local_14,local_10,local_c,&local_24);
  if (iVar1 != 0) {
    FUN_00797e71(0,local_24,local_20,0,0,5);
  }
  return 1;
}




/* vtable slots: CBlockEditDialog[96] */
/* 00415140  FUN_00415140  32 bytes, 0 callers */

void FUN_00415140(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x234) = 0;
  FUN_00798a09();
  return;
}



