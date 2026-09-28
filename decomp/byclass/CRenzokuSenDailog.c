/* CRenzokuSenDailog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CRenzokuSenDailog[1] */
/* 005b7be0  FUN_005b7be0  68 bytes, 0 callers */

undefined4 FUN_005b7be0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005b7b30();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x808);
    }
  }
  return in_ECX;
}




/* vtable slots: CRenzokuSenDailog[64] */
/* 005b7f10  FUN_005b7f10  356 bytes, 0 callers */

void FUN_005b7f10(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078f6f8(param_1,0x9bc,in_ECX + 0xe0);
  FUN_0078fb9c(param_1,0x9bc,in_ECX + 0xe8);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x168);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x1e8);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x268);
  FUN_0078fb9c(param_1,0x42b,in_ECX + 0x2e8);
  FUN_0078fb9c(param_1,0x6db,in_ECX + 0x368);
  FUN_0078fb9c(param_1,0x583,in_ECX + 1000);
  FUN_0078fb9c(param_1,0x6dc,in_ECX + 0x530);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0x5b0);
  FUN_0078fb9c(param_1,0x830,in_ECX + 0x700);
  FUN_0078f6f8(param_1,0x830,in_ECX + 0x6f8);
  FUN_0078fb9c(param_1,0x6ee,in_ECX + 0x788);
  FUN_0078f6f8(param_1,0x6ee,in_ECX + 0x780);
  return;
}




/* vtable slots: CRenzokuSenDailog[10] */
/* 005b8080  FUN_005b8080  16 bytes, 0 callers */

void FUN_005b8080(void)

{
  FUN_005b8090();
  return;
}




/* vtable slots: CRenzokuSenDailog[94] */
/* 005b81d0  FUN_005b81d0  111 bytes, 0 callers */

undefined4 FUN_005b81d0(void)

{
  int in_ECX;
  
  FUN_00798993();
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  FUN_005b7c30();
  if (*(int *)(in_ECX + 0x6f8) == 0) {
    *(undefined4 *)(in_ECX + 0x528) = 1;
    *(undefined4 *)(in_ECX + 0x6f0) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x528) = 0;
    *(undefined4 *)(in_ECX + 0x6f0) = 0;
  }
  return 1;
}



