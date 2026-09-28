/* CKageDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CKageDialog[1] */
/* 0054b730  FUN_0054b730  68 bytes, 0 callers */

undefined4 FUN_0054b730(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0054b5b0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xce8);
    }
  }
  return in_ECX;
}




/* vtable slots: CKageDialog[64] */
/* 0054bc90  FUN_0054bc90  849 bytes, 0 callers */

void FUN_0054bc90(undefined4 param_1)

{
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00925c7d;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_00405880();
  FUN_0078fb9c(param_1,0x428,local_14 + 0xe8);
  FUN_0078fb9c(param_1,0x429,local_14 + 0x168);
  FUN_0078fb9c(param_1,0x42a,local_14 + 0x1e8);
  FUN_0078fb9c(param_1,0x42b,local_14 + 0x268);
  FUN_0078fb9c(param_1,0x42c,local_14 + 0x2e8);
  FUN_0078fb9c(param_1,0x42d,local_14 + 0x368);
  FUN_0078fb9c(param_1,0x791,local_14 + 1000);
  FUN_0078fb9c(param_1,0x5d3,local_14 + 0x468);
  DDX_Text(param_1,0x5d3,local_14 + 0x4e8);
  FUN_0078fb9c(param_1,0x792,local_14 + 0x4f0);
  FUN_0078fb9c(param_1,0x5d4,local_14 + 0x570);
  DDX_Text(param_1,0x5d4,local_14 + 0x5f0);
  FUN_0078fb9c(param_1,0x793,local_14 + 0x5f8);
  FUN_0078fb9c(param_1,0x5d5,local_14 + 0x678);
  DDX_Text(param_1,0x5d5,local_14 + 0x6f8);
  FUN_0078fb9c(param_1,0x795,local_14 + 0x700);
  FUN_0078fb9c(param_1,0x984,local_14 + 0x780);
  FUN_0078fb9c(param_1,0x52b,local_14 + 0xc60);
  FUN_0078f6f8(param_1,0x52b,local_14 + 0xce0);
  FUN_0078fb9c(param_1,0x461,local_14 + 0x800);
  FUN_0078fb9c(param_1,0x463,local_14 + 0x880);
  FUN_0078fb9c(param_1,0x464,local_14 + 0x918);
  FUN_0078fb9c(param_1,0x465,local_14 + 0x9b0);
  FUN_0078fb9c(param_1,0x466,local_14 + 0xa48);
  FUN_0078fb9c(param_1,0x469,local_14 + 0xae0);
  FUN_0078fb9c(param_1,0x43c,local_14 + 0xb60);
  FUN_0078fb9c(param_1,0x43d,local_14 + 0xbe0);
  if (*(int *)(local_14 + 0xd0) == 3) {
    FUN_0054bc60();
    CStringT<>();
    local_8 = 0;
    FUN_004059f0(local_18,&DAT_0095590c,*(undefined8 *)(local_14 + 0xd8));
    FUN_00404920();
    FUN_004142b0();
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  FUN_004b1140();
  ExceptionList = local_10;
  return;
}




/* vtable slots: CKageDialog[10] */
/* 0054bff0  FUN_0054bff0  16 bytes, 0 callers */

void FUN_0054bff0(void)

{
  FUN_0054c000();
  return;
}




/* vtable slots: CKageDialog[67] */
/* 0054cae0  FUN_0054cae0  354 bytes, 0 callers */

undefined4 FUN_0054cae0(int param_1)

{
  uint uVar1;
  float10 fVar2;
  double dVar3;
  undefined1 local_1c [4];
  undefined4 local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092bd4d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = FUN_0058d4f0(param_1);
  if (*(int *)(param_1 + 4) == 0x100) {
    if ((*(int *)(param_1 + 8) == 0xd) && (*(int *)(local_14 + 0xbc) == 0)) {
      FUN_0054d140(local_1c);
      local_8 = 0;
      fVar2 = (float10)FUN_0054d070(uVar1);
      dVar3 = (double)fVar2;
      fVar2 = (float10)FUN_0054cfa0();
      local_8 = 0xffffffff;
      FUN_00404540(uVar1,(double)fVar2,dVar3);
    }
    if ((*(int *)(local_14 + 0xbc) == 4) && ((DAT_00a0cc74 != 0 || (DAT_00a0d864 == 0)))) {
      if (*(int *)(param_1 + 8) == 0x21) {
        FUN_0054c1f0();
        local_18 = 1;
      }
      if (*(int *)(param_1 + 8) == 0x22) {
        FUN_0054c290();
        local_18 = 1;
      }
      if (*(int *)(param_1 + 8) == 0x25) {
        FUN_0054c070();
        local_18 = 1;
      }
      if (*(int *)(param_1 + 8) == 0x27) {
        FUN_0054c130();
        local_18 = 1;
      }
      if (*(int *)(param_1 + 8) == 0x26) {
        FUN_0054c1f0();
        local_18 = 1;
      }
      if (*(int *)(param_1 + 8) == 0x28) {
        FUN_0054c290();
        local_18 = 1;
      }
    }
  }
  ExceptionList = local_10;
  return local_18;
}



