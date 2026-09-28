/* CEnkoDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CEnkoDialog[1] */
/* 004aaf30  FUN_004aaf30  68 bytes, 0 callers */

undefined4 FUN_004aaf30(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004aacf0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xd60);
    }
  }
  return in_ECX;
}




/* vtable slots: CEnkoDialog[24] */
/* 004ab2f0  FUN_004ab2f0  107 bytes, 0 callers */

void FUN_004ab2f0(void)

{
  int in_ECX;
  float10 fVar1;
  
  if (*(int *)(in_ECX + 0xce0) != 0) {
    (**(code **)(*(int *)(in_ECX + 0xcc0) + 0x60))();
  }
  *(undefined4 *)(in_ECX + 0x260) = *(undefined4 *)(in_ECX + 0xaf0);
  *(undefined4 *)(in_ECX + 0x264) = *(undefined4 *)(in_ECX + 0xaf4);
  fVar1 = (float10)FUN_004ac890();
  *(double *)(in_ECX + 0x268) = (double)fVar1;
  FUN_00792313();
  return;
}




/* vtable slots: CEnkoDialog[64] */
/* 004ab360  FUN_004ab360  451 bytes, 0 callers */

void FUN_004ab360(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x526,in_ECX + 0x278);
  FUN_0078fb9c(param_1,0x527,in_ECX + 0x2f8);
  FUN_0078fb9c(param_1,0x585,in_ECX + 0x378);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0x4c0);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x608);
  FUN_0078fb9c(param_1,0x6d3,in_ECX + 0x968);
  FUN_0078fb9c(param_1,0x6d4,in_ECX + 0x9e8);
  FUN_0078fb9c(param_1,0x6d5,in_ECX + 0xa68);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x750);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x7e8);
  FUN_0078fb9c(param_1,0x528,in_ECX + 0x868);
  FUN_0078fb9c(param_1,0x529,in_ECX + 0x8e8);
  FUN_0078fb9c(param_1,0x6d7,in_ECX + 0xaf8);
  FUN_0078fb9c(param_1,0x589,in_ECX + 0xb78);
  FUN_0078f6f8(param_1,0x526,in_ECX + 0xae8);
  FUN_0078f6f8(param_1,0x527,in_ECX + 0xaec);
  FUN_0078f6f8(param_1,0x528,in_ECX + 0xaf0);
  FUN_0078f6f8(param_1,0x529,in_ECX + 0xaf4);
  return;
}




/* vtable slots: CEnkoDialog[10] */
/* 004abbc0  FUN_004abbc0  16 bytes, 0 callers */

void FUN_004abbc0(void)

{
  FUN_004abbd0();
  return;
}




/* vtable slots: CEnkoDialog[94] */
/* 004ac130  FUN_004ac130  395 bytes, 0 callers */

undefined4 FUN_004ac130(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  FUN_00798993();
  *(undefined4 *)(in_ECX + 0x254) = 0xffffffff;
  *(undefined4 *)(in_ECX + 600) = 0;
  *(undefined4 *)(in_ECX + 0x25c) = *(undefined4 *)(in_ECX + 600);
  *(undefined4 *)(in_ECX + 0x270) = 0;
  if (DAT_00a0caac != 0) {
    *(undefined4 *)(in_ECX + 0x270) = 1;
  }
  (**(code **)(*(int *)(in_ECX + 0xcc0) + 0x164))(in_ECX,0);
  FUN_004aaf80(1);
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = 0x14b6;
  uVar1 = FUN_00797a56(0x583);
  FUN_007af37e(uVar1,uVar2,uVar3,uVar4);
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = 0x14b7;
  uVar1 = FUN_00797a56(0x526);
  FUN_007af37e(uVar1,uVar2,uVar3,uVar4);
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = 0x14bc;
  uVar1 = FUN_00797a56(0x584);
  FUN_007af37e(uVar1,uVar2,uVar3,uVar4);
  uVar4 = 0;
  uVar3 = 0;
  uVar2 = 0x14c1;
  uVar1 = FUN_00797a56(0x585);
  FUN_007af37e(uVar1,uVar2,uVar3,uVar4);
  (**(code **)(*(int *)(in_ECX + 0x608) + 0x180))(in_ECX + 0xb8,10);
  (**(code **)(*(int *)(in_ECX + 0x608) + 0x188))(*(undefined8 *)(in_ECX + 0x248));
  FUN_00797df8();
  return 1;
}




/* vtable slots: CEnkoDialog[67] */
/* 004ac6c0  FUN_004ac6c0  25 bytes, 0 callers */

void FUN_004ac6c0(undefined4 param_1)

{
  FUN_0058d4f0(param_1);
  return;
}



