/* CTateguDialog -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CTateguDialog[1] */
/* 005f6060  FUN_005f6060  68 bytes, 0 callers */

undefined4 FUN_005f6060(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_005f5f30();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xf78);
    }
  }
  return in_ECX;
}




/* vtable slots: CTateguDialog[64] */
/* 005f6470  FUN_005f6470  569 bytes, 0 callers */

void FUN_005f6470(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00405880(param_1);
  FUN_0078fb9c(param_1,0x6ca,in_ECX + 0xe8);
  FUN_0078fb9c(param_1,0x6cb,in_ECX + 0x168);
  FUN_0078fb9c(param_1,0x6cd,in_ECX + 0x1e8);
  FUN_0078fb9c(param_1,0x6ce,in_ECX + 0x268);
  FUN_0078fb9c(param_1,0x6cc,in_ECX + 0x2e8);
  FUN_0078fb9c(param_1,0x6c9,in_ECX + 0x368);
  FUN_0078fb9c(param_1,0x52d,in_ECX + 1000);
  FUN_0078fb9c(param_1,0x52c,in_ECX + 0x468);
  FUN_0078fb9c(param_1,0x52b,in_ECX + 0x4e8);
  FUN_0078fb9c(param_1,0x429,in_ECX + 0x568);
  FUN_0078fb9c(param_1,0x428,in_ECX + 0x5e8);
  FUN_0078fb9c(param_1,0x595,in_ECX + 0xb98);
  FUN_0078fb9c(param_1,0x591,in_ECX + 0x7b0);
  FUN_0078fb9c(param_1,0x592,in_ECX + 0x8f8);
  FUN_0078fb9c(param_1,0x594,in_ECX + 0xa40);
  FUN_0078fb9c(param_1,0x593,in_ECX + 0xcf0);
  FUN_0078fb9c(param_1,0x590,in_ECX + 0x668);
  FUN_0078f6f8(param_1,0x52b,in_ECX + 0xe48);
  FUN_0078f6f8(param_1,0x52c,in_ECX + 0xe4c);
  FUN_0078f6f8(param_1,0x52d,in_ECX + 0xe50);
  FUN_0078fb9c(param_1,0x990,in_ECX + 0xe58);
  FUN_0078fb9c(param_1,0xb31,in_ECX + 0xef0);
  FUN_0078f6f8(param_1,0xb31,in_ECX + 0xf70);
  return;
}




/* vtable slots: CTateguDialog[10] */
/* 005f66b0  FUN_005f66b0  16 bytes, 0 callers */

void FUN_005f66b0(void)

{
  FUN_005f6750();
  return;
}




/* vtable slots: CTateguDialog[94] */
/* 005f69c0  FUN_005f69c0  550 bytes, 0 callers */

undefined4 FUN_005f69c0(void)

{
  int in_ECX;
  
  FUN_00798993();
  (**(code **)(*(int *)(in_ECX + 0x668) + 0x17c))();
  (**(code **)(*(int *)(in_ECX + 0x7b0) + 0x17c))();
  (**(code **)(*(int *)(in_ECX + 0x8f8) + 0x17c))();
  (**(code **)(*(int *)(in_ECX + 0xa40) + 0x17c))();
  (**(code **)(*(int *)(in_ECX + 0xb98) + 0x17c))();
  (**(code **)(*(int *)(in_ECX + 0xcf0) + 0x17c))();
  *(undefined8 *)(in_ECX + 200) = DAT_00a0bc98;
  *(undefined8 *)(in_ECX + 0xc0) = DAT_00a0bc90;
  if (0 < DAT_00a0bc88) {
    (**(code **)(*(int *)(in_ECX + 0x668) + 0x188))(DAT_00a0bcb0);
    (**(code **)(*(int *)(in_ECX + 0x7b0) + 0x188))(DAT_00a0bcb8);
  }
  if (*(int *)(in_ECX + 0xb8) == 0) {
    (**(code **)(*(int *)(in_ECX + 0x8f8) + 0x188))(*(undefined8 *)(in_ECX + 0xc0));
  }
  else {
    (**(code **)(*(int *)(in_ECX + 0x8f8) + 0x188))(*(undefined8 *)(in_ECX + 200));
  }
  (**(code **)(*(int *)(in_ECX + 0xcf0) + 0x188))(*(undefined8 *)(in_ECX + 0xd0));
  (**(code **)(*(int *)(in_ECX + 0xa40) + 0x188))(*(undefined8 *)(in_ECX + 0xd8));
  (**(code **)(*(int *)(in_ECX + 0xb98) + 0x188))(*(undefined8 *)(in_ECX + 0xe0));
  return 1;
}




/* vtable slots: CTateguDialog[72] */
/* 005f6bf0  FUN_005f6bf0  19 bytes, 0 callers */

void FUN_005f6bf0(void)

{
  guard_check_icall();
  return;
}




/* vtable slots: CTateguDialog[100] */
/* 005f6c10  FUN_005f6c10  311 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_005f6c10(void)

{
  undefined4 uVar1;
  int in_ECX;
  double local_ec;
  undefined1 local_d8 [208];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (*(int *)(in_ECX + 0xb8) == 0) {
    local_ec = *(double *)(in_ECX + 0xc0);
  }
  else {
    local_ec = *(double *)(in_ECX + 200);
  }
  if (0.0 < local_ec) {
    (**(code **)(*(int *)(in_ECX + 0x8f8) + 0x188))(local_ec);
  }
  else {
    FUN_005977f0();
    uVar1 = FUN_00404920();
    FUN_005cf710(local_d8,uVar1);
    FUN_00404770();
    FUN_00797ece();
  }
  (**(code **)(*(int *)(in_ECX + 0x668) + 0x184))();
  (**(code **)(*(int *)(in_ECX + 0x7b0) + 0x184))();
  return;
}



