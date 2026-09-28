/* CMyComboBox -- Ghidra decompilation, machine output.
   Slot numbers come from the class vtable in .rdata. */

/* vtable slots: CMyComboBox[1] */
/* 0058bd50  FUN_0058bd50  68 bytes, 0 callers */

undefined4 FUN_0058bd50(uint param_1)

{
  undefined4 in_ECX;
  
  FUN_0058bd30();
  if ((param_1 & 1) != 0) {
    if ((param_1 & 4) == 0) {
      FUN_00404790(in_ECX);
    }
    else {
      _Adl_verify_range<>(in_ECX,0x148);
    }
  }
  return in_ECX;
}




/* vtable slots: CMyComboBox[10] */
/* 0058bda0  FUN_0058bda0  16 bytes, 0 callers */

void FUN_0058bda0(void)

{
  FUN_0058be60();
  return;
}




/* vtable slots: CMyComboBox[94] */
/* 0058bdb0  FUN_0058bdb0  170 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_0058bdb0(int param_1)

{
  double local_84;
  int local_7c;
  int local_74;
  int local_70;
  undefined1 local_6c [100];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  local_7c = FUN_004b0eb0();
  local_70 = 0;
  for (local_74 = 0; local_74 < local_7c; local_74 = local_74 + 1) {
    FUN_00588bf0(local_74,local_6c);
    local_84 = 0.0;
    FUN_00417110(local_6c,&DAT_0095590c,&local_84);
    if (local_84 != 0.0) {
      *(double *)(param_1 + local_70 * 8) = local_84;
      local_70 = local_70 + 1;
    }
  }
  return local_70;
}




/* vtable slots: CMyComboBox[98] */
/* 0058c7f0  FUN_0058c7f0  118 bytes, 0 callers */

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_0058c7f0(undefined8 param_1)

{
  int *in_ECX;
  undefined1 local_44 [60];
  uint local_8;
  
  local_8 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  if (DAT_00a0cbd8 != 0) {
    FUN_00406bf0(DAT_00a0cbd8,1);
  }
  FUN_00589c10(local_44,L"%.10lg",param_1);
  FUN_00797ece();
  (**(code **)(*in_ECX + 0x18c))();
  return;
}




/* vtable slots: CMyComboBox[96] */
/* 0058c870  FUN_0058c870  344 bytes, 0 callers */

void FUN_0058c870(int param_1,int param_2)

{
  uint uVar1;
  int local_1c;
  undefined1 local_18 [4];
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f2e5;
  local_10 = ExceptionList;
  uVar1 = DAT_00a00fa4 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (DAT_00a0cbd8 != 0) {
    FUN_00406bf0(DAT_00a0cbd8,1);
  }
  if (param_2 != 0) {
    if (0xb < param_2) {
      param_2 = 0xb;
    }
    CStringT<>(uVar1);
    local_8 = 0;
    FUN_00792c64();
    FUN_004b10f0();
    FUN_00404920();
    FUN_00797ece();
    FUN_005977f0();
    local_8._0_1_ = 1;
    FUN_00404920();
    FUN_004142b0();
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
    for (local_1c = 0; local_1c < param_2; local_1c = local_1c + 1) {
      FUN_004059f0(local_18,L"%.10lg",*(undefined8 *)(param_1 + local_1c * 8));
      FUN_00404920();
      FUN_004142b0();
    }
    (**(code **)(*local_14 + 0x188))(*(undefined8 *)(local_14 + 0x4c));
    local_8 = 0xffffffff;
    FUN_00404540();
  }
  ExceptionList = local_10;
  return;
}




/* vtable slots: CMyComboBox[99] */
/* 0058c9d0  FUN_0058c9d0  678 bytes, 0 callers */

void FUN_0058c9d0(void)

{
  int iVar1;
  undefined4 uVar2;
  float10 fVar3;
  double local_4c;
  double local_44;
  double local_3c;
  double local_34;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined1 local_18 [4];
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092f325;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  CStringT<>(DAT_00a00fa4 ^ (uint)&stack0xfffffffc);
  local_8 = 0;
  fVar3 = (float10)FUN_0058cc80();
  local_34 = (double)fVar3;
  iVar1 = FUN_004b0eb0();
  if (iVar1 == 0) {
    local_28 = FUN_005977f0();
    local_8._0_1_ = 1;
    local_24 = local_28;
    uVar2 = FUN_00404920();
    FUN_0057e1c0(0,uVar2);
    local_8 = (uint)local_8._1_3_ << 8;
    FUN_00404770();
  }
  if (local_34 == 0.0) {
    FUN_004b1140();
  }
  else {
    if (local_14[0x4f] == 0) {
      FUN_004059f0(local_18,L"%.10lg",local_34);
    }
    else {
      if ((0.0 < local_34) || (local_14[0x4f] == 2)) {
        if (local_34 <= 0.0) {
          local_3c = -local_34;
        }
        else {
          local_3c = local_34;
        }
        local_20 = (int)(local_3c + 0.5);
      }
      else {
        if (local_34 <= 0.0) {
          local_44 = -local_34;
        }
        else {
          local_44 = local_34;
        }
        local_20 = -(int)(local_44 + 0.5);
      }
      FUN_004059f0(local_18,&DAT_0095703c,local_20);
    }
    uVar2 = FUN_00404920(&DAT_0095590c,&local_34);
    FUN_00417110(uVar2);
    uVar2 = FUN_00404920();
    FUN_0057e1c0(1,uVar2);
    local_1c = 2;
    while( true ) {
      iVar1 = FUN_004b0eb0();
      if (iVar1 <= local_1c) break;
      GetLBText(local_1c,local_18);
      uVar2 = FUN_00404920();
      FUN_00417110(uVar2);
      if (local_4c == local_34) {
        FUN_0054bc60();
        break;
      }
      local_1c = local_1c + 1;
    }
    FUN_004b1140();
  }
  iVar1 = FUN_004b0eb0();
  if (0xb < iVar1) {
    FUN_004b0eb0();
    FUN_0054bc60();
  }
  if (local_34 == 0.0) {
    FUN_00797ece();
  }
  iVar1 = (**(code **)(*local_14 + 0x178))();
  local_14[0x4a] = iVar1;
  local_8 = 0xffffffff;
  FUN_00404540();
  ExceptionList = local_10;
  return;
}



