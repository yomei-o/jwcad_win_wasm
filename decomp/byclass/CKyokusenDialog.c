/* CKyokusenDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CKyokusenDialog[1] */
/* 005512e0  FUN_005512e0  68 bytes, 0 callers */

undefined4 FUN_005512e0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00551290();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x398);
    }
  }
  return in_ECX;
}




/* vtable slots: CKyokusenDialog[64] */
/* 00551330  FUN_00551330  167 bytes, 0 callers */

void FUN_00551330(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078f75d(param_1,0x699,in_ECX + 0xc4);
  FUN_0078fb9c(param_1,0x583,in_ECX + 200);
  FUN_0078fb9c(param_1,0x708,in_ECX + 0x210);
  FUN_0078fb9c(param_1,0x42c,in_ECX + 0x290);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0x310);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x394);
  return;
}




/* vtable slots: CKyokusenDialog[10] */
/* 005513e0  FUN_005513e0  16 bytes, 0 callers */

void FUN_005513e0(void)

{
  FUN_005513f0();
  return;
}




/* vtable slots: CKyokusenDialog[94] */
/* 00551430  FUN_00551430  197 bytes, 0 callers */

undefined4 FUN_00551430(void)

{
  int in_ECX;
  
  FUN_00798993();
  FUN_00797f20();
  if (*(int *)(in_ECX + 0xc4) == 2) {
    FUN_00797f20();
  }
  else {
    FUN_00797f20();
  }
  if (*(int *)(in_ECX + 0xc4) == 2) {
    FUN_00797f20();
  }
  else {
    FUN_00797f20();
  }
  *(undefined4 *)(in_ECX + 0xc0) = 1;
  *(undefined4 *)(in_ECX + 0xbc) = 1;
  FUN_00551760(0,0);
  FUN_00551710((double)*(int *)(in_ECX + 0xb8));
  return 1;
}



