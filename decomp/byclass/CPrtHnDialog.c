/* CPrtHnDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CPrtHnDialog[1] */
/* 005add90  FUN_005add90  68 bytes, 0 callers */

undefined4 FUN_005add90(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005add10();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x478);
    }
  }
  return in_ECX;
}




/* vtable slots: CPrtHnDialog[64] */
/* 005ae630  FUN_005ae630  238 bytes, 0 callers */

void FUN_005ae630(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0xd8);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x158);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x1d8);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 600);
  FUN_0078f6f8(param_1,0x53f,in_ECX + 0x2e0);
  FUN_0078fb9c(param_1,0x42c,in_ECX + 0x2e8);
  FUN_0078fb9c(param_1,0x42d,in_ECX + 0x368);
  FUN_0078fb9c(param_1,0x42e,in_ECX + 1000);
  FUN_004b1140(*(undefined4 *)(in_ECX + 0x468));
  return;
}




/* vtable slots: CPrtHnDialog[10] */
/* 005ae720  FUN_005ae720  16 bytes, 0 callers */

void FUN_005ae720(void)

{
  FUN_005ae800();
  return;
}




/* vtable slots: CPrtHnDialog[94] */
/* 005af570  FUN_005af570  189 bytes, 0 callers */

undefined4 FUN_005af570(void)

{
  int in_ECX;
  
  FUN_00798993();
  if (*(int *)(*(int *)(in_ECX + 0xb8) + 0x8288) == 0) {
    *(undefined4 *)(in_ECX + 0x2e0) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2e0) = 1;
  }
  FUN_00797f20(5);
  FUN_00797f20(5);
  *(undefined4 *)(in_ECX + 0x2d8) = *(undefined4 *)(*(int *)(in_ECX + 0xb8) + 0x3048);
  FUN_00550370();
  *(undefined4 *)(in_ECX + 0xbc) = 0xffffffff;
  FUN_005ae8a0();
  FUN_005adde0();
  FUN_005ae250(0);
  FUN_007955d2(0);
  return 1;
}



