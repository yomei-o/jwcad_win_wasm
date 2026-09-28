/* CGazouDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CGazouDialog[1] */
/* 004c53b0  FUN_004c53b0  68 bytes, 0 callers */

undefined4 FUN_004c53b0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004c5300();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x660);
    }
  }
  return in_ECX;
}




/* vtable slots: CGazouDialog[64] */
/* 004c5400  FUN_004c5400  427 bytes, 0 callers */

void FUN_004c5400(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x9fe,in_ECX + 0x140);
  FUN_0078fb9c(param_1,0x542,in_ECX + 0x1c0);
  FUN_0078fb9c(param_1,0x539,in_ECX + 0x240);
  FUN_0078fb9c(param_1,0x541,in_ECX + 0x2c0);
  FUN_0078fb9c(param_1,0x538,in_ECX + 0x340);
  FUN_0078fb9c(param_1,0x537,in_ECX + 0x3c0);
  FUN_0078f6f8(param_1,0x537,in_ECX + 0x440);
  FUN_0078f6f8(param_1,0x541,in_ECX + 0x444);
  FUN_0078f6f8(param_1,0x538,in_ECX + 0x448);
  FUN_0078f6f8(param_1,0x539,in_ECX + 0x44c);
  FUN_0078f6f8(param_1,0x542,in_ECX + 0x450);
  FUN_0078f6f8(param_1,0x53b,in_ECX + 0x454);
  FUN_0078f6f8(param_1,0x53a,in_ECX + 0x458);
  FUN_0078fb9c(param_1,0x53a,in_ECX + 0x460);
  FUN_0078fb9c(param_1,0x9ff,in_ECX + 0x4e0);
  FUN_0078fb9c(param_1,0xa01,in_ECX + 0x560);
  FUN_0078fb9c(param_1,0x53b,in_ECX + 0x5e0);
  return;
}




/* vtable slots: CGazouDialog[10] */
/* 004c55b0  FUN_004c55b0  16 bytes, 0 callers */

void FUN_004c55b0(void)

{
  FUN_004c55c0();
  return;
}




/* vtable slots: CGazouDialog[94] */
/* 004c5a60  FUN_004c5a60  75 bytes, 0 callers */

undefined4 FUN_004c5a60(void)

{
  int in_ECX;
  
  FUN_00798993();
  if (0.0 <= DAT_00a0ba78) {
    *(undefined4 *)(in_ECX + 0x458) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0x458) = 1;
  }
  FUN_007955d2(0);
  return 1;
}



