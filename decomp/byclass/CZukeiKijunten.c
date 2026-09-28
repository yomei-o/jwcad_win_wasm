/* CZukeiKijunten -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CZukeiKijunten[1] */
/* 006b2170  FUN_006b2170  68 bytes, 0 callers */

undefined4 FUN_006b2170(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_004fa960();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0xb0);
    }
  }
  return in_ECX;
}




/* vtable slots: CZukeiKijunten[6] */
/* 006b21c0  FUN_006b21c0  48 bytes, 0 callers */

void FUN_006b21c0(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x8560) = 1;
  FUN_004efbb0(0x14c2,0,0);
  return;
}




/* vtable slots: CZukeiKijunten[16] */
/* 006b21f0  FUN_006b21f0  42 bytes, 0 callers */

undefined4 FUN_006b21f0(void)

{
  int *in_ECX;
  
  in_ECX[0x2a] = 1;
  (**(code **)(*in_ECX + 0xc))();
  return 1;
}




/* vtable slots: CZukeiKijunten[0] */
/* 006b2220  FUN_006b2220  16 bytes, 0 callers */

undefined ** FUN_006b2220(void)

{
  return &PTR_s_CZukeiKijunten_00979850;
}




/* vtable slots: CZukeiKijunten[25] */
/* 006b2230  FUN_006b2230  46 bytes, 0 callers */

void FUN_006b2230(void)

{
  int *in_ECX;
  
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  (**(code **)(*in_ECX + 0xc))();
  return;
}




/* vtable slots: CZukeiKijunten[4] */
/* 006b2260  FUN_006b2260  170 bytes, 0 callers */

void FUN_006b2260(void)

{
  uint uVar1;
  int in_ECX;
  undefined1 local_28 [20];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093069d;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(*(int *)(in_ECX + 4) + 0x9060) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x9060) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x7a0c) = *(undefined4 *)(in_ECX + 0xac);
    local_14 = in_ECX;
    FUN_0079dea2(*(undefined4 *)(in_ECX + 4));
    local_8 = 0;
    (**(code **)(**(int **)(local_14 + 4) + 0x19c))(local_28,uVar1);
    local_8 = 0xffffffff;
    FUN_0079dfff();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CZukeiKijunten[3] */
/* 006b2310  FUN_006b2310  610 bytes, 0 callers */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_006b2310(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined1 local_641c [20];
  int local_6408;
  undefined1 local_34 [16];
  undefined1 local_24 [16];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00937a1b;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_6408 = in_ECX;
  local_14 = uVar1;
  if (*(int *)(in_ECX + 0xa8) == 0) {
    if (*(int *)(*(int *)(in_ECX + 4) + 0x9060) == 0) {
      FUN_00517640(*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24),
                   *(undefined4 *)(in_ECX + 0x28),*(undefined4 *)(in_ECX + 0x2c));
    }
    else {
      FUN_004988c0(local_24,*(undefined4 *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24),
                   *(undefined4 *)(in_ECX + 0x28),*(undefined4 *)(in_ECX + 0x2c));
    }
  }
  FUN_00446aa0(uVar1);
  local_8 = 0;
  FUN_0079dea2(*(undefined4 *)(local_6408 + 4));
  local_8 = CONCAT31(local_8._1_3_,1);
  if (*(int *)(*(int *)(local_6408 + 4) + 0x9060) == 0) {
    FUN_0044de00(local_641c,*(undefined4 *)(local_6408 + 4));
    uVar3 = 0;
    puVar2 = (undefined4 *)FUN_004b75a0(local_34);
    FUN_004508b0(0x10,local_641c,*(undefined4 *)(local_6408 + 4),*puVar2,puVar2[1],puVar2[2],
                 puVar2[3],uVar3);
  }
  else {
    *(undefined4 *)(*(int *)(local_6408 + 4) + 0x7a0c) = *(undefined4 *)(local_6408 + 0xac);
    (**(code **)(**(int **)(local_6408 + 4) + 0x19c))(local_641c);
  }
  *(undefined4 *)(*(int *)(local_6408 + 4) + 0x9060) = 0;
  *(undefined4 *)(*(int *)(local_6408 + 4) + 0x85a8) = 0;
  *(undefined4 *)(*(int *)(local_6408 + 4) + 0x85ac) = 0;
  *(undefined4 *)(*(int *)(local_6408 + 4) + 0x85b0) = 0;
  *(undefined4 *)(*(int *)(local_6408 + 4) + 0x85b4) = 0;
  *(undefined4 *)(*(int *)(local_6408 + 4) + 0x85b8) = 1;
  local_8 = local_8 & 0xffffff00;
  FUN_0079dfff();
  local_8 = 0xffffffff;
  FUN_00447100();
  ExceptionList = local_10;
  return;
}



