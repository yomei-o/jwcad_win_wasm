/* CMy2ComboBox1 -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMy2ComboBox1[1] */
/* 0058a3d0  FUN_0058a3d0  68 bytes, 0 callers */

undefined4 FUN_0058a3d0(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0058a390();
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




/* vtable slots: CMy2ComboBox1[94] */
/* 0058b3e0  FUN_0058b3e0  309 bytes, 0 callers */

float10 FUN_0058b3e0(void)

{
  int iVar1;
  undefined4 uVar2;
  double *pdStack_6c;
  undefined8 *puStack_68;
  double *pdStack_64;
  undefined8 local_60;
  undefined8 local_58;
  uint uStack_50;
  double local_4c;
  undefined8 local_44;
  undefined8 local_3c;
  undefined8 local_34;
  double local_2c;
  undefined4 local_24;
  undefined1 *local_20;
  undefined4 local_1c;
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
  local_44 = 0;
  local_3c = 0x3ff0000000000000;
  local_2c = 0.0;
  local_34 = 0x3ff0000000000000;
  local_58 = CONCAT44(0x58b43a,(undefined4)local_58);
  CStringT<>();
  local_8 = 0;
  local_58 = CONCAT44(0x58b449,(undefined4)local_58);
  iVar1 = FUN_004b0eb0();
  if (1 < iVar1) {
    local_58 = CONCAT44(local_18,1);
    local_60 = CONCAT44(0x58b45c,(undefined4)local_60);
    GetLBText();
    local_58 = CONCAT44(&local_34,&local_3c);
    local_60._4_4_ = L"%lg,%lg";
    local_60._0_4_ = 0x58b471;
    uVar2 = FUN_00404920();
    local_60 = CONCAT44(local_60._4_4_,uVar2);
    pdStack_64 = (double *)0x58b477;
    FUN_00417110();
  }
  local_58 = CONCAT44(local_18,0x58b486);
  FUN_00792c64();
  local_58 = local_34;
  local_60 = local_3c;
  pdStack_6c = &local_2c;
  puStack_68 = &local_44;
  local_20 = (undefined1 *)&pdStack_6c;
  pdStack_64 = pdStack_6c;
  FUN_00403dd0(local_18);
  local_24 = FUN_004f19f0();
  *(undefined8 *)(local_14 + 0x1d8) = local_44;
  *(double *)(local_14 + 0x1e0) = local_2c;
  local_4c = local_2c;
  local_8 = 0xffffffff;
  local_58 = CONCAT44(0x58b503,(undefined4)local_58);
  local_1c = local_24;
  FUN_00404540();
  ExceptionList = local_10;
  return (float10)local_4c;
}



