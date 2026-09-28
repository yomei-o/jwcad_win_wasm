/* CIkktuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CIkktuDialog[1] */
/* 004c9c60  FUN_004c9c60  68 bytes, 0 callers */

undefined4 FUN_004c9c60(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004c9b80();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xb40);
    }
  }
  return in_ECX;
}




/* vtable slots: CIkktuDialog[64] */
/* 004ca470  FUN_004ca470  427 bytes, 0 callers */

void FUN_004ca470(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x180);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x200);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x280);
  FUN_0078fb9c(param_1,0x42b,in_ECX + 0x318);
  FUN_0078fb9c(param_1,0x42c,in_ECX + 0x3b0);
  FUN_0078fb9c(param_1,0x6dd,in_ECX + 0x430);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x4b0);
  FUN_0078fb9c(param_1,0x830,in_ECX + 0x608);
  FUN_0078fb9c(param_1,0x7cd,in_ECX + 0x690);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0x710);
  FUN_0078fb9c(param_1,0x9d6,in_ECX + 0x858);
  FUN_0078fb9c(param_1,0x585,in_ECX + 0x8d8);
  FUN_0078f6f8(param_1,0x830,in_ECX + 0x688);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0xa30);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0xab0);
  FUN_0078fb9c(param_1,0x52c,in_ECX + 0xab8);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0xb38);
  return;
}




/* vtable slots: CIkktuDialog[10] */
/* 004ca620  FUN_004ca620  16 bytes, 0 callers */

void FUN_004ca620(void)

{
  FUN_004ca630();
  return;
}




/* vtable slots: CIkktuDialog[94] */
/* 004ca640  FUN_004ca640  416 bytes, 0 callers */

undefined4 FUN_004ca640(void)

{
  int in_ECX;
  undefined4 local_c;
  
  FUN_00798993();
  if (DAT_00a0cc40 == 0) {
    *(undefined4 *)(in_ECX + 0xb38) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0xb38) = 1;
  }
  *(undefined4 *)(in_ECX + 0xc0) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xbc) = 0xffffffff;
  FUN_004c9cb0();
  (**(code **)(*(int *)(in_ECX + 0x4b0) + 0x184))();
  (**(code **)(*(int *)(in_ECX + 0x4b0) + 0x188))(DAT_00a0cc58);
  if (DAT_00a0cc60 == 0) {
    *(undefined4 *)(in_ECX + 0x688) = 0;
    *(undefined4 *)(in_ECX + 0x5fc) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x688) = 1;
    *(undefined4 *)(in_ECX + 0x5fc) = 0;
  }
  for (local_c = 0x14; 0 < local_c; local_c = local_c + -1) {
    (**(code **)(*(int *)(in_ECX + 0x8d8) + 0x188))(*(undefined8 *)(in_ECX + 200 + local_c * 8));
  }
  (**(code **)(*(int *)(in_ECX + 0x8d8) + 0x188))(DAT_00a0cc48);
  (**(code **)(*(int *)(in_ECX + 0x8d8) + 0x188))(0);
  if (DAT_00a0cc50 != 0) {
    *(undefined4 *)(in_ECX + 0xab0) = 1;
  }
  FUN_007955d2(0);
  return 1;
}



