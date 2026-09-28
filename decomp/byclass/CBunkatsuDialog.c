/* CBunkatsuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CBunkatsuDialog[1] */
/* 004175f0  FUN_004175f0  68 bytes, 0 callers */

undefined4 FUN_004175f0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_00417510();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x978);
    }
  }
  return in_ECX;
}




/* vtable slots: CBunkatsuDialog[64] */
/* 00417ea0  FUN_00417ea0  498 bytes, 0 callers */

void FUN_00417ea0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0xd0);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x218);
  FUN_0078fb9c(param_1,0x6f9,in_ECX + 0x360);
  FUN_0078fb9c(param_1,0x41a,in_ECX + 0x3e0);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0x460);
  FUN_0078fb9c(param_1,0x52c,in_ECX + 0x4e0);
  FUN_0078fb9c(param_1,0x52d,in_ECX + 0x560);
  FUN_0078fb9c(param_1,0x52e,in_ECX + 0x5e0);
  FUN_0078fb9c(param_1,0x52f,in_ECX + 0x660);
  FUN_0078fb9c(param_1,0x699,in_ECX + 0x6e0);
  FUN_0078fb9c(param_1,0x69a,in_ECX + 0x760);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x7e0);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x860);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x8e0);
  FUN_0078f75d(param_1,0x699,in_ECX + 0x960);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x964);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0x968);
  FUN_0078f6f8(param_1,0x52d,in_ECX + 0x96c);
  FUN_0078f6f8(param_1,0x52e,in_ECX + 0x970);
  FUN_0078f6f8(param_1,0x52f,in_ECX + 0x974);
  return;
}




/* vtable slots: CBunkatsuDialog[10] */
/* 004180a0  FUN_004180a0  16 bytes, 0 callers */

void FUN_004180a0(void)

{
  FUN_004180b0();
  return;
}




/* vtable slots: CBunkatsuDialog[94] */
/* 00418290  FUN_00418290  101 bytes, 0 callers */

undefined4 FUN_00418290(void)

{
  int in_ECX;
  
  FUN_00798993();
  (**(code **)(*(int *)(in_ECX + 0xd0) + 0x17c))();
  (**(code **)(*(int *)(in_ECX + 0x218) + 0x17c))();
  *(undefined4 *)(in_ECX + 0x964) = DAT_00a0be48;
  FUN_007955d2(0);
  return 1;
}



