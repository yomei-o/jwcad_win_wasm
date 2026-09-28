/* CSunpoDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSunpoDialog[1] */
/* 005d9300  FUN_005d9300  68 bytes, 0 callers */

undefined4 FUN_005d9300(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005d90b0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xb98);
    }
  }
  return in_ECX;
}




/* vtable slots: CSunpoDialog[64] */
/* 005d9970  FUN_005d9970  404 bytes, 0 callers */

void FUN_005d9970(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x6de,in_ECX + 0x278);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x2f8);
  FUN_0078fb9c(param_1,0x423,in_ECX + 0x450);
  FUN_0078fb9c(param_1,0x424,in_ECX + 0x4d0);
  FUN_0078fb9c(param_1,0x425,in_ECX + 0x8e8);
  FUN_0078fb9c(param_1,0x426,in_ECX + 0x980);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x568);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x5e8);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x668);
  FUN_0078fb9c(param_1,0x42b,in_ECX + 0x6e8);
  FUN_0078fb9c(param_1,0x42c,in_ECX + 0x768);
  FUN_0078fb9c(param_1,0x42d,in_ECX + 0x7e8);
  FUN_0078fb9c(param_1,0x42e,in_ECX + 0x868);
  FUN_0078fb9c(param_1,0x42f,in_ECX + 0xa18);
  FUN_0078fb9c(param_1,0x430,in_ECX + 0xa98);
  FUN_0078fb9c(param_1,0x460,in_ECX + 0xb18);
  return;
}




/* vtable slots: CSunpoDialog[10] */
/* 005d9b10  FUN_005d9b10  16 bytes, 0 callers */

void FUN_005d9b10(void)

{
  FUN_005d9b20();
  return;
}




/* vtable slots: CSunpoDialog[94] */
/* 005da080  FUN_005da080  174 bytes, 0 callers */

undefined4 FUN_005da080(void)

{
  int in_ECX;
  
  FUN_00798993();
  *(undefined4 *)(in_ECX + 0x26c) = 0;
  (**(code **)(*(int *)(in_ECX + 0x2f8) + 0x180))(in_ECX + 0xb8,10);
  (**(code **)(*(int *)(in_ECX + 0x2f8) + 0x188))(0);
  *(undefined4 *)(in_ECX + 600) = 0;
  *(undefined4 *)(in_ECX + 0x25c) = 0xffffffff;
  FUN_005d9450(0);
  FUN_005da520(0);
  FUN_005da2a0();
  FUN_005da370();
  return 1;
}



