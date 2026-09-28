/* CMy2ComboBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMy2ComboBox[1] */
/* 0058a420  FUN_0058a420  68 bytes, 0 callers */

undefined4 FUN_0058a420(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0058a3b0();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x1e8);
    }
  }
  return in_ECX;
}




/* vtable slots: CMy2ComboBox[10], CMy2ComboBox1[10] */
/* 0058a470  FUN_0058a470  16 bytes, 0 callers */

void FUN_0058a470(void)

{
  FUN_0058a480();
  return;
}




/* vtable slots: CMy2ComboBox[67], CMy2ComboBox1[67] */
/* 0058abc0  FUN_0058abc0  318 bytes, 0 callers */

undefined4 FUN_0058abc0(int param_1)

{
  undefined4 uVar1;
  int local_10;
  int local_c;
  
  uVar1 = FUN_007949fb(param_1);
  if (*(int *)(param_1 + 4) == 0x100) {
    if ((DAT_00a0d864 != 0) &&
       (((((*(int *)(param_1 + 8) == 0x28 || (*(int *)(param_1 + 8) == 0x26)) ||
          (*(int *)(param_1 + 8) == 0x27)) ||
         ((*(int *)(param_1 + 8) == 0x25 || (*(int *)(param_1 + 8) == 0x22)))) ||
        ((*(int *)(param_1 + 8) == 0x21 || (*(int *)(param_1 + 8) == 0x24)))))) {
      if (DAT_00a0cc74 != 0) {
        return uVar1;
      }
      return 1;
    }
    if (*(int *)(param_1 + 8) == 0xd) {
      FUN_0058b070();
    }
  }
  if ((*(int *)(param_1 + 4) == 0x20a) || (*(int *)(param_1 + 4) == 0xce11)) {
    if (DAT_00a0d8a0 < 1) {
      local_c = -DAT_00a0d8a0;
    }
    else {
      local_c = DAT_00a0d8a0;
    }
    if (local_c != 1) {
      if (DAT_00a0d8a0 < 1) {
        local_10 = -DAT_00a0d8a0;
      }
      else {
        local_10 = DAT_00a0d8a0;
      }
      if (local_10 != 3) {
        return uVar1;
      }
    }
    uVar1 = 1;
  }
  return uVar1;
}




/* vtable slots: CMy2ComboBox[94] */
/* 0058b520  FUN_0058b520  347 bytes, 0 callers */

float10 FUN_0058b520(void)

{
  int iVar1;
  undefined4 uVar2;
  double *pdStack_6c;
  double *pdStack_68;
  double *pdStack_64;
  undefined8 local_60;
  undefined8 local_58;
  uint uStack_50;
  double local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  double local_34;
  double local_2c;
  undefined1 *local_24;
  int local_20;
  int local_1c;
  undefined1 local_18 [4];
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f26d;
  local_10 = ExceptionList;
  uStack_50 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_34 = 0.0;
  local_44 = 0x3ff0000000000000;
  local_2c = 0.0;
  local_3c = 0x3ff0000000000000;
  local_58 = CONCAT44(0x58b57a,(undefined4)local_58);
  CStringT<>();
  local_8 = 0;
  local_58 = CONCAT44(0x58b589,(undefined4)local_58);
  iVar1 = FUN_004b0eb0();
  if (1 < iVar1) {
    local_58 = CONCAT44(local_18,1);
    local_60 = CONCAT44(0x58b59c,(undefined4)local_60);
    GetLBText();
    local_58 = CONCAT44(&local_3c,&local_44);
    local_60._4_4_ = L"%lg,%lg";
    local_60._0_4_ = 0x58b5b1;
    uVar2 = FUN_00404920();
    local_60 = CONCAT44(local_60._4_4_,uVar2);
    pdStack_64 = (double *)0x58b5b7;
    FUN_00417110();
  }
  local_58 = CONCAT44(local_18,0x58b5c6);
  FUN_00792c64();
  local_58 = local_3c;
  local_60 = local_44;
  pdStack_6c = &local_2c;
  pdStack_68 = &local_34;
  local_24 = (undefined1 *)&pdStack_6c;
  pdStack_64 = pdStack_6c;
  FUN_00403dd0(local_18);
  local_20 = FUN_004f19f0();
  if (local_20 < 2) {
    if (*(int *)(local_14 + 0x1d4) == 0) {
      local_2c = local_34;
    }
    else {
      local_2c = 0.0;
    }
  }
  *(double *)(local_14 + 0x1d8) = local_34;
  *(double *)(local_14 + 0x1e0) = local_2c;
  local_4c = local_2c;
  local_8 = 0xffffffff;
  local_58 = CONCAT44(0x58b669,(undefined4)local_58);
  local_1c = local_20;
  FUN_00404540();
  ExceptionList = local_10;
  return (float10)local_4c;
}



