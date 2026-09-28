/* CSentakuDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CSentakuDialog[1] */
/* 005c80d0  FUN_005c80d0  68 bytes, 0 callers */

undefined4 FUN_005c80d0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005c7fc0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xad0);
    }
  }
  return in_ECX;
}




/* vtable slots: CSentakuDialog[64] */
/* 005c9920  FUN_005c9920  451 bytes, 0 callers */

void FUN_005c9920(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x540,in_ECX + 0xe8);
  FUN_0078fb9c(param_1,0x536,in_ECX + 0x168);
  FUN_0078f6f8(param_1,0x540,in_ECX + 0x1e8);
  FUN_0078f6f8(param_1,0x536,in_ECX + 0x1ec);
  FUN_0078fb9c(param_1,0x58a,in_ECX + 0x1f0);
  FUN_0078fb9c(param_1,0x45b,in_ECX + 0xa50);
  FUN_0078fb9c(param_1,0x462,in_ECX + 0x3d8);
  FUN_0078fb9c(param_1,0x461,in_ECX + 0x458);
  FUN_0078fb9c(param_1,0x460,in_ECX + 0x4d8);
  FUN_0078fb9c(param_1,0x430,in_ECX + 0x570);
  FUN_0078fb9c(param_1,0x42f,in_ECX + 0x5f0);
  FUN_0078fb9c(param_1,0x42e,in_ECX + 0x708);
  FUN_0078fb9c(param_1,0x42d,in_ECX + 0x670);
  FUN_0078fb9c(param_1,0x42c,in_ECX + 0x7a0);
  FUN_0078fb9c(param_1,0x42b,in_ECX + 0x820);
  FUN_0078fb9c(param_1,0x42a,in_ECX + 0x8a0);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x938);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x9d0);
  return;
}




/* vtable slots: CSentakuDialog[10] */
/* 005c9af0  FUN_005c9af0  16 bytes, 0 callers */

void FUN_005c9af0(void)

{
  FUN_005c9b00();
  return;
}




/* vtable slots: CSentakuDialog[94] */
/* 005ca900  FUN_005ca900  62 bytes, 0 callers */

undefined4 FUN_005ca900(void)

{
  int in_ECX;
  
  FUN_00798993();
  *(undefined4 *)(in_ECX + 0x1e8) = 0;
  *(undefined4 *)(in_ECX + 0x1ec) = 0;
  FUN_005c8ef0(0,0);
  return 1;
}




/* vtable slots: CSentakuDialog[101] */
/* 005ca940  FUN_005ca940  71 bytes, 0 callers */

void FUN_005ca940(void)

{
  int iVar1;
  
  iVar1 = FUN_004e10f0();
  if (iVar1 == 0) {
    iVar1 = FUN_005c9b10();
    if (iVar1 != 0) {
      FUN_005ca990(1,0);
    }
  }
  else {
    iVar1 = FUN_005c9b40();
    if (iVar1 != 0) {
      FUN_005ca190();
    }
  }
  return;
}




/* vtable slots: CSentakuDialog[67] */
/* 005caaf0  FUN_005caaf0  97 bytes, 0 callers */

undefined4 FUN_005caaf0(int param_1)

{
  undefined4 uVar1;
  
  if ((*(int *)(param_1 + 4) == 0x100) && (*(int *)(param_1 + 8) == 0xd)) {
    FUN_007955d2(1);
    FUN_00404c80();
    FUN_00799e17();
    FUN_00406bc0(0x1500,0,0);
    uVar1 = 1;
  }
  else {
    uVar1 = FUN_0058d4f0(param_1);
  }
  return uVar1;
}



