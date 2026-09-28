/* CSenDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSenDialog[1] */
/* 005bd450  FUN_005bd450  68 bytes, 0 callers */

undefined4 FUN_005bd450(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005bd050();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x13e0);
    }
  }
  return in_ECX;
}




/* vtable slots: CSenDialog[24] */
/* 005bd520  FUN_005bd520  19 bytes, 0 callers */

void FUN_005bd520(void)

{
  FUN_00792313();
  return;
}




/* vtable slots: CSenDialog[64] */
/* 005bd540  FUN_005bd540  1387 bytes, 0 callers */

void FUN_005bd540(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x9f9,in_ECX + 0x738);
  FUN_0078fb9c(param_1,0x9f8,in_ECX + 0x7b8);
  FUN_0078fb9c(param_1,0x537,in_ECX + 0x858);
  FUN_0078fb9c(param_1,0x536,in_ECX + 0x8d8);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x958);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0xaa0);
  FUN_0078fb9c(param_1,0x585,in_ECX + 0xbe8);
  FUN_0078fb9c(param_1,0x538,in_ECX + 0xdd0);
  FUN_0078fb9c(param_1,0x544,in_ECX + 0xe50);
  FUN_0078fb9c(param_1,0x72c,in_ECX + 0xed0);
  FUN_0078fb9c(param_1,0x545,in_ECX + 0xf50);
  FUN_0078fb9c(param_1,0x72d,in_ECX + 0xfd0);
  FUN_0078fb9c(param_1,0x546,in_ECX + 0x1050);
  FUN_0078fb9c(param_1,0x547,in_ECX + 0x10d0);
  FUN_0078fb9c(param_1,0x78f,in_ECX + 0x1150);
  FUN_0078fb9c(param_1,0x589,in_ECX + 0x11d0);
  FUN_0078f6f8(param_1,0x534,in_ECX + 0x13b8);
  FUN_0078f6f8(param_1,0x535,in_ECX + 0x13bc);
  FUN_0078f6f8(param_1,0x538,in_ECX + 0x13c0);
  FUN_0078f6f8(param_1,0x544,in_ECX + 0x13c4);
  FUN_0078f6f8(param_1,0x545,in_ECX + 0x13c8);
  FUN_0078f6f8(param_1,0x546,in_ECX + 0x13cc);
  FUN_0078f6f8(param_1,0x547,in_ECX + 0x13d0);
  FUN_0078f6f8(param_1,0x536,in_ECX + 0x13d4);
  FUN_0078f6f8(param_1,0x537,in_ECX + 0x13d8);
  FUN_0078f6f8(param_1,0x9f9,in_ECX + 0x13dc);
  if (*(int *)(in_ECX + 0x13b8) == 0) {
    FUN_00797f20(5);
    FUN_00797f20(0);
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_007979e8(*(undefined4 *)(in_ECX + 0x13c4));
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_007979e8(*(undefined4 *)(in_ECX + 0x13c8));
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_005bec50();
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
  }
  else {
    FUN_00797f20(5);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(0);
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_00797f20(5);
    FUN_00797f20(5);
    if (*(int *)(in_ECX + 0x13d4) == 0) {
      FUN_00797f20(1);
      FUN_00797f20(1);
      FUN_00797f20(0);
      FUN_00797f20(0);
      FUN_00797f20(0);
    }
    else {
      FUN_00797f20(0);
      FUN_00797f20(0);
      FUN_00797f20(1);
      FUN_00797f20(1);
      FUN_00797f20(1);
    }
  }
  return;
}




/* vtable slots: CSenDialog[10] */
/* 005bdb20  FUN_005bdb20  16 bytes, 0 callers */

void FUN_005bdb20(void)

{
  FUN_005bde30();
  return;
}




/* vtable slots: CSenDialog[94] */
/* 005be420  FUN_005be420  1260 bytes, 0 callers */

undefined4 FUN_005be420(void)

{
  int in_ECX;
  
  if (DAT_00a0cb24 != 0) {
    *(undefined4 *)(in_ECX + 0x13c4) = 0;
    *(undefined4 *)(in_ECX + 0x13c8) = 0;
    *(undefined4 *)(in_ECX + 0x13cc) = 0;
    *(undefined4 *)(in_ECX + 0x13d0) = 0;
  }
  FUN_00798993();
  (**(code **)(*(int *)(in_ECX + 0x958) + 0x180))(in_ECX + 600,10);
  (**(code **)(*(int *)(in_ECX + 0x958) + 0x188))(0);
  (**(code **)(*(int *)(in_ECX + 0xaa0) + 0x180))(in_ECX + 200,10);
  if (DAT_00a0cc38 == 0) {
    (**(code **)(*(int *)(in_ECX + 0xaa0) + 0x188))(0);
  }
  else {
    (**(code **)(*(int *)(in_ECX + 0xaa0) + 0x188))
              (*(undefined8 *)(*(int *)(in_ECX + 0xb8) + 0x83f0));
  }
  if (*(int *)(in_ECX + 0xc4) == 0) {
    FUN_0058b040();
    FUN_005beb70(*(undefined8 *)(*(int *)(in_ECX + 0xb8) + 0x83f8),
                 *(undefined8 *)(*(int *)(in_ECX + 0xb8) + 0x8400));
  }
  else {
    *(undefined4 *)(in_ECX + 0xc4) = 0;
    FUN_0058aec0();
  }
  if (*(int *)(in_ECX + 0x13b8) == 0) {
    *(undefined4 *)(in_ECX + 0x13bc) = *(undefined4 *)(in_ECX + 0x730);
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_007979e8();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_007979e8();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_005bec50();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
  }
  else {
    *(undefined4 *)(in_ECX + 0x13bc) = *(undefined4 *)(in_ECX + 0x734);
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    FUN_00797f20();
    if (*(int *)(in_ECX + 0x13d4) == 0) {
      FUN_00797f20();
      FUN_00797f20();
      FUN_00797f20();
      FUN_00797f20();
      FUN_00797f20();
    }
    else {
      FUN_00797f20();
      FUN_00797f20();
      FUN_00797f20();
      FUN_00797f20();
      FUN_00797f20();
    }
  }
  if (*(int *)(*(int *)(in_ECX + 0xb8) + 0x5e18) == 0) {
    *(undefined4 *)(in_ECX + 0x13dc) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0x13dc) = 1;
  }
  return 1;
}



