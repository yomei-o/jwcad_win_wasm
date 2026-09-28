/* CToolBarDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CToolBarDialog[1] */
/* 005f0bf0  FUN_005f0bf0  68 bytes, 0 callers */

undefined4 FUN_005f0bf0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005f0ae0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x350);
    }
  }
  return in_ECX;
}




/* vtable slots: CToolBarDialog[64] */
/* 005f0c40  FUN_005f0c40  1090 bytes, 0 callers */

void FUN_005f0c40(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078f6f8(param_1,0x5b9,in_ECX + 0xa8);
  FUN_0078f6f8(param_1,0x5d4,in_ECX + 0xac);
  FUN_0078f6f8(param_1,0x5f0,in_ECX + 0xb0);
  FUN_0078f6f8(param_1,0x6c1,in_ECX + 0xb4);
  FUN_0078f6f8(param_1,0x6c3,in_ECX + 0xb8);
  FUN_0078f6f8(param_1,0x6c4,in_ECX + 0xbc);
  FUN_0078f6f8(param_1,0x6c6,in_ECX + 0xc0);
  FUN_0078f6f8(param_1,0x6c5,in_ECX + 0xc4);
  FUN_0078f6f8(param_1,0x5e6,in_ECX + 200);
  FUN_0078f6f8(param_1,0x5e5,in_ECX + 0xcc);
  FUN_0078f6f8(param_1,0x6c2,in_ECX + 0xd0);
  FUN_0078f6f8(param_1,0x703,in_ECX + 0xd4);
  FUN_0078f6f8(param_1,0x790,in_ECX + 0xd8);
  FUN_0078f6f8(param_1,0x6c8,in_ECX + 0xdc);
  FUN_0078f6f8(param_1,0x6c9,in_ECX + 0xe0);
  FUN_0078f6f8(param_1,0x6ca,in_ECX + 0xe4);
  FUN_0078f6f8(param_1,0x6cb,in_ECX + 0xe8);
  FUN_0078f6f8(param_1,0x704,in_ECX + 0xec);
  FUN_0078f6f8(param_1,0x705,in_ECX + 0xf0);
  FUN_0078f6f8(param_1,0x706,in_ECX + 0xf4);
  FUN_0078f6f8(param_1,0x707,in_ECX + 0xf8);
  FUN_0078f6f8(param_1,0x708,in_ECX + 0xfc);
  FUN_0078f6f8(param_1,0x709,in_ECX + 0x100);
  FUN_0078fb9c(param_1,0x791,in_ECX + 0x2d0);
  FUN_0078f6f8(param_1,0x791,in_ECX + 0x104);
  FUN_0078fb9c(param_1,0x790,in_ECX + 0x188);
  if (*(int *)(in_ECX + 0x184) == 0) {
    FUN_00797b67(in_ECX + 0x208,99);
    *(undefined4 *)(in_ECX + 0x10c) = *(undefined4 *)(in_ECX + 0xa8);
    *(undefined4 *)(in_ECX + 0x110) = *(undefined4 *)(in_ECX + 0xac);
    *(undefined4 *)(in_ECX + 0x114) = *(undefined4 *)(in_ECX + 0xb0);
    *(undefined4 *)(in_ECX + 0x118) = *(undefined4 *)(in_ECX + 0xb4);
    *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(in_ECX + 0xb8);
    *(undefined4 *)(in_ECX + 0x120) = *(undefined4 *)(in_ECX + 0xbc);
    *(undefined4 *)(in_ECX + 0x124) = *(undefined4 *)(in_ECX + 0xc0);
    *(undefined4 *)(in_ECX + 0x140) = *(undefined4 *)(in_ECX + 0xdc);
    *(undefined4 *)(in_ECX + 0x144) = *(undefined4 *)(in_ECX + 0xe0);
    *(undefined4 *)(in_ECX + 0x148) = *(undefined4 *)(in_ECX + 0xe4);
    *(undefined4 *)(in_ECX + 0x14c) = *(undefined4 *)(in_ECX + 0xe8);
    *(undefined4 *)(in_ECX + 0x128) = *(undefined4 *)(in_ECX + 0xc4);
    *(undefined4 *)(in_ECX + 300) = *(undefined4 *)(in_ECX + 200);
    *(undefined4 *)(in_ECX + 0x130) = *(undefined4 *)(in_ECX + 0xcc);
    *(undefined4 *)(in_ECX + 0x134) = *(undefined4 *)(in_ECX + 0xd0);
    *(undefined4 *)(in_ECX + 0x138) = *(undefined4 *)(in_ECX + 0xd4);
    *(undefined4 *)(in_ECX + 0x150) = *(undefined4 *)(in_ECX + 0xec);
    *(undefined4 *)(in_ECX + 0x154) = *(undefined4 *)(in_ECX + 0xf0);
    *(undefined4 *)(in_ECX + 0x158) = *(undefined4 *)(in_ECX + 0xf4);
    *(undefined4 *)(in_ECX + 0x15c) = *(undefined4 *)(in_ECX + 0xf8);
    *(undefined4 *)(in_ECX + 0x160) = *(undefined4 *)(in_ECX + 0xfc);
    *(undefined4 *)(in_ECX + 0x164) = *(undefined4 *)(in_ECX + 0x100);
    *(undefined4 *)(in_ECX + 0x184) = 1;
  }
  return;
}




/* vtable slots: CToolBarDialog[10] */
/* 005f1090  FUN_005f1090  16 bytes, 0 callers */

void FUN_005f1090(void)

{
  FUN_005f10a0();
  return;
}



