/* CMentoriDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMentoriDialog[1] */
/* 0056f920  FUN_0056f920  68 bytes, 0 callers */

undefined4 FUN_0056f920(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0056f8e0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x550);
    }
  }
  return in_ECX;
}




/* vtable slots: CMentoriDialog[24] */
/* 0056f970  FUN_0056f970  34 bytes, 0 callers */

void FUN_0056f970(void)

{
  int in_ECX;
  
  DAT_00a0b480 = *(undefined4 *)(in_ECX + 0x548);
  FUN_00792313();
  return;
}




/* vtable slots: CMentoriDialog[64] */
/* 0056f9a0  FUN_0056f9a0  157 bytes, 0 callers */

void FUN_0056f9a0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x585,in_ECX + 0xc0);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0x218);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x400);
  FUN_0078f75d(param_1,0x699,in_ECX + 0x548);
  FUN_0078f6f8(param_1,0x830,in_ECX + 0xbc);
  *(undefined4 *)(in_ECX + 0xb8) = DAT_00a0b410;
  return;
}




/* vtable slots: CMentoriDialog[10] */
/* 0056fa40  FUN_0056fa40  16 bytes, 0 callers */

void FUN_0056fa40(void)

{
  FUN_0056fa50();
  return;
}




/* vtable slots: CMentoriDialog[94] */
/* 0056fa60  FUN_0056fa60  276 bytes, 0 callers */

undefined4 FUN_0056fa60(void)

{
  int in_ECX;
  
  FUN_00798993();
  if ((-1 < DAT_00a0b480) && (DAT_00a0b480 < 5)) {
    *(int *)(in_ECX + 0x548) = DAT_00a0b480;
  }
  if (*(int *)(in_ECX + 0x548) == 3) {
    FUN_00797f20();
    FUN_00797f20();
  }
  else {
    FUN_00797f20();
    FUN_00797f20();
  }
  (**(code **)(*(int *)(in_ECX + 0xc0) + 0x184))();
  (**(code **)(*(int *)(in_ECX + 0xc0) + 0x188))(DAT_00a0cc58);
  if (DAT_00a0cc60 == 0) {
    *(undefined4 *)(in_ECX + 0xbc) = 0;
    *(undefined4 *)(in_ECX + 0x20c) = 1;
  }
  else {
    *(undefined4 *)(in_ECX + 0xbc) = 1;
    *(undefined4 *)(in_ECX + 0x20c) = 0;
  }
  FUN_007955d2(0);
  return 1;
}



