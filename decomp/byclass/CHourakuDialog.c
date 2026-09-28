/* CHourakuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CHourakuDialog[1] */
/* 004c8a00  FUN_004c8a00  68 bytes, 0 callers */

undefined4 FUN_004c8a00(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004c8960();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x5e8);
    }
  }
  return in_ECX;
}




/* vtable slots: CHourakuDialog[24] */
/* 004c8c30  FUN_004c8c30  27 bytes, 0 callers */

void FUN_004c8c30(void)

{
  FUN_004c9450();
  FUN_00792313();
  return;
}




/* vtable slots: CHourakuDialog[64] */
/* 004c8c50  FUN_004c8c50  451 bytes, 0 callers */

void FUN_004c8c50(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x53b,in_ECX + 200);
  FUN_0078fb9c(param_1,0x53c,in_ECX + 0x148);
  FUN_0078fb9c(param_1,0x53a,in_ECX + 0x1c8);
  FUN_0078fb9c(param_1,0x53d,in_ECX + 0x248);
  FUN_0078fb9c(param_1,0x54d,in_ECX + 0x2c8);
  FUN_0078fb9c(param_1,0x548,in_ECX + 0x348);
  FUN_0078fb9c(param_1,0x549,in_ECX + 0x3c8);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x448);
  FUN_0078fb9c(param_1,0x733,in_ECX + 0x4c8);
  FUN_0078fb9c(param_1,0x52d,in_ECX + 0x548);
  FUN_0078f6f8(param_1,0x53d,in_ECX + 0x5c8);
  FUN_0078f6f8(param_1,0x53a,in_ECX + 0x5cc);
  FUN_0078f6f8(param_1,0x53c,in_ECX + 0x5d0);
  FUN_0078f6f8(param_1,0x53b,in_ECX + 0x5d4);
  FUN_0078f6f8(param_1,0x54d,in_ECX + 0x5d8);
  FUN_0078f6f8(param_1,0x548,in_ECX + 0x5dc);
  FUN_0078f6f8(param_1,0x549,in_ECX + 0x5e0);
  FUN_0078f6f8(param_1,0x52d,in_ECX + 0x5e4);
  return;
}




/* vtable slots: CHourakuDialog[10] */
/* 004c8e20  FUN_004c8e20  16 bytes, 0 callers */

void FUN_004c8e20(void)

{
  FUN_004c8e30();
  return;
}




/* vtable slots: CHourakuDialog[94] */
/* 004c92f0  FUN_004c92f0  349 bytes, 0 callers */

undefined4 FUN_004c92f0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x5c8) = 0;
  *(undefined4 *)(in_ECX + 0x5cc) = 0;
  *(undefined4 *)(in_ECX + 0x5d0) = 0;
  *(undefined4 *)(in_ECX + 0x5d4) = 0;
  *(undefined4 *)(in_ECX + 0x5d8) = 0;
  if ((DAT_00a0c7e0 & 1) != 0) {
    *(undefined4 *)(in_ECX + 0x5cc) = 1;
  }
  if ((DAT_00a0c7e0 & 2) != 0) {
    *(undefined4 *)(in_ECX + 0x5d4) = 1;
  }
  if ((DAT_00a0c7e0 & 4) != 0) {
    *(undefined4 *)(in_ECX + 0x5d0) = 1;
  }
  if ((DAT_00a0c7e0 & 8) != 0) {
    *(undefined4 *)(in_ECX + 0x5c8) = 1;
  }
  if ((DAT_00a0c7e0 & 0x10) != 0) {
    *(undefined4 *)(in_ECX + 0x5d8) = 1;
  }
  if ((((*(int *)(in_ECX + 0x5c8) == 0) && (*(int *)(in_ECX + 0x5cc) == 0)) &&
      (*(int *)(in_ECX + 0x5d0) == 0)) && (*(int *)(in_ECX + 0x5d4) == 0)) {
    *(undefined4 *)(in_ECX + 0x5cc) = 1;
  }
  FUN_00798993();
  FUN_00797f20(0);
  FUN_00797f20(0);
  FUN_00797f20(0);
  FUN_00797f20(0);
  FUN_00797f20(0);
  return 1;
}




/* vtable slots: CHourakuDialog[104], PAU1::PAU_ITEMIDLIST::?$CList[8] */
/* 00650065  FUN_00650065  1 bytes, 0 callers */

void FUN_00650065(void)

{
  return;
}



