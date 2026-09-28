/* CSen2Dialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSen2Dialog[1] */
/* 005bad70  FUN_005bad70  68 bytes, 0 callers */

undefined4 FUN_005bad70(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005bad30();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x490);
    }
  }
  return in_ECX;
}




/* vtable slots: CSen2Dialog[24] */
/* 005baea0  FUN_005baea0  29 bytes, 0 callers */

void FUN_005baea0(void)

{
  FUN_005bb0d0();
  FUN_00792313();
  return;
}




/* vtable slots: CSen2Dialog[64] */
/* 005baec0  FUN_005baec0  159 bytes, 0 callers */

void FUN_005baec0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0xe0);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x410);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0xd8);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0xdc);
  FUN_0078fb9c(param_1,0x585,in_ECX + 0x2c8);
  FUN_00797f20(5);
  return;
}




/* vtable slots: CSen2Dialog[10] */
/* 005baf60  FUN_005baf60  16 bytes, 0 callers */

void FUN_005baf60(void)

{
  FUN_005bb0c0();
  return;
}




/* vtable slots: CSen2Dialog[94] */
/* 005bb250  FUN_005bb250  109 bytes, 0 callers */

undefined4 FUN_005bb250(void)

{
  int in_ECX;
  
  FUN_00798993();
  if ((*(int *)(in_ECX + 0xd8) == 0) && (*(int *)(in_ECX + 0xdc) == 0)) {
    FUN_007979e8();
  }
  else {
    FUN_007979e8();
  }
  FUN_005bb380(*(undefined8 *)(in_ECX + 0xd0));
  return 1;
}



