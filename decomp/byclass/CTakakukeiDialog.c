/* CTakakukeiDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTakakukeiDialog[1] */
/* 005eabd0  FUN_005eabd0  68 bytes, 0 callers */

undefined4 FUN_005eabd0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005eaa70();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x10a8);
    }
  }
  return in_ECX;
}




/* vtable slots: CTakakukeiDialog[64] */
/* 005eb2c0  FUN_005eb2c0  1021 bytes, 0 callers */

void FUN_005eb2c0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00935135;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x699,in_ECX + 0x100);
  FUN_0078fb9c(param_1,0x69a,in_ECX + 0x180);
  FUN_0078fb9c(param_1,0x69b,in_ECX + 0x200);
  FUN_0078fb9c(param_1,0x69c,in_ECX + 0x280);
  FUN_0078fb9c(param_1,0x9d4,in_ECX + 0x300);
  FUN_0078fb9c(param_1,0x583,in_ECX + 0x380);
  FUN_0078fb9c(param_1,0x584,in_ECX + 0x4c8);
  FUN_0078fb9c(param_1,0x6e1,in_ECX + 0x6b0);
  FUN_0078fb9c(param_1,0x585,in_ECX + 0x730);
  FUN_0078fb9c(param_1,0x6d8,in_ECX + 0x878);
  FUN_0078fb9c(param_1,0x586,in_ECX + 0x8f8);
  FUN_0078fb9c(param_1,0x42c,in_ECX + 0xa50);
  FUN_0078f75d(param_1,0x699,in_ECX + 0xad0);
  FUN_0078fb9c(param_1,0x42d,in_ECX + 0xad8);
  FUN_0078fb9c(param_1,0x42e,in_ECX + 0xb58);
  FUN_0078fb9c(param_1,0x42f,in_ECX + 0xbd8);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0xcf0);
  FUN_0078fb9c(param_1,0x52c,in_ECX + 0xd70);
  FUN_0078fb9c(param_1,0x52d,in_ECX + 0xdf0);
  FUN_0078fb9c(param_1,0x52e,in_ECX + 0xe70);
  FUN_0078fb9c(param_1,0x52f,in_ECX + 0xef0);
  FUN_0078fb9c(param_1,0x530,in_ECX + 0xf70);
  FUN_0078fb9c(param_1,0x9f8,in_ECX + 0xff0);
  FUN_0078fb9c(param_1,0x43b,in_ECX + 0xc58);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0x1090);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0x1094);
  FUN_0078f6f8(param_1,0x52d,in_ECX + 0x1098);
  FUN_0078f6f8(param_1,0x52e,in_ECX + 0x109c);
  FUN_0078f6f8(param_1,0x52f,in_ECX + 0x10a0);
  FUN_0078f6f8(param_1,0x530,in_ECX + 0x10a4);
  CStringT<>();
  local_8 = 0;
  iVar1 = *(int *)(in_ECX + 0xf8);
  if (iVar1 == 0) {
    uVar2 = FUN_005977f0(0x155d);
    local_8._0_1_ = 1;
    FUN_00404860(uVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
  }
  else if (iVar1 == 1) {
    uVar2 = FUN_005977f0(0x155e);
    local_8._0_1_ = 2;
    FUN_00404860(uVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
  }
  else if (iVar1 == 2) {
    uVar2 = FUN_005977f0(0x155f);
    local_8._0_1_ = 3;
    FUN_00404860(uVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
  }
  uVar2 = FUN_00404920();
  FUN_00797ece(uVar2);
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CTakakukeiDialog[10] */
/* 005eb6c0  FUN_005eb6c0  16 bytes, 0 callers */

void FUN_005eb6c0(void)

{
  FUN_005eb6d0();
  return;
}




/* vtable slots: CTakakukeiDialog[94] */
/* 005ec2d0  FUN_005ec2d0  494 bytes, 0 callers */

undefined4 FUN_005ec2d0(void)

{
  int in_ECX;
  
  FUN_00798993();
  (**(code **)(*(int *)(in_ECX + 0x380) + 0x188))(*(undefined8 *)(in_ECX + 0xd0));
  FUN_0058b040();
  FUN_0058ae50(*(undefined8 *)(in_ECX + 0xd8),*(undefined8 *)(in_ECX + 0xe0));
  FUN_005ec750((double)*(int *)(in_ECX + 0xe8));
  FUN_005ec7a0(*(undefined8 *)(in_ECX + 0xf0));
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = 0;
  if (*(int *)(*(int *)(in_ECX + 0xb8) + 0x5e18) == 0) {
    *(undefined4 *)(in_ECX + 0x1094) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1094) = 1;
  }
  if (*(int *)(in_ECX + 0xad0) == 0) {
    FUN_00797f20();
    FUN_00797f20();
  }
  else {
    FUN_00797f20();
    FUN_00797f20();
  }
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  if (DAT_00a0cac0 == 0) {
    *(undefined4 *)(in_ECX + 0x1098) = 0;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1098) = 1;
  }
  FUN_007955d2();
  FUN_004fb9f0();
  if (DAT_00a0cac4 != 0) {
    FUN_005168b0(0x1619,*(undefined4 *)(*(int *)(in_ECX + 0xb8) + 0x8f24),
                 *(undefined4 *)(*(int *)(in_ECX + 0xb8) + 0x8f28),0,0);
  }
  *(undefined4 *)(in_ECX + 0xc4) = 0;
  *(undefined4 *)(in_ECX + 200) = 0;
  return 1;
}



